/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

/**
 * @addtogroup XEngine
 * @{
 *
 * @brief Provides APIs related to XEngine graphics capabilities.
 *
 * @syscap SystemCapability.Graphic.XEngine
 * @since 6.0.0(20)
 */

/**
 * @file xeg_vulkan_rt_reflection.h
 * @kit XEngineKit
 * @library libxengine.so
 *
 * @brief APIs for the RT Reflection feature of XEngine. Before using the APIs in this header file, you need to call
 * {@link HMS_XEG_EnumerateDeviceExtensionProperties} to query whether the
 * {@link XEG_RT_REFLECTION_EXTENSION_NAME} extension is available.
 * @syscap SystemCapability.Graphic.XEngine
 * @since 6.0.0(20)
 */
#ifndef XEG_VULKAN_RT_REFLECTION_H
#define XEG_VULKAN_RT_REFLECTION_H

#include <stdbool.h>
#include <vulkan/vulkan.h>
#include "xeg_vulkan_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Handle to {@link XEG_RTReflection}.
 *
 * @since 6.0.0(20)
 */
VK_DEFINE_HANDLE(XEG_RTReflection)

/**
* @brief This structure describes the information for creating an {@link XEG_RTReflection} object. When the information
* in the structure changes, a new {@link XEG_RTReflection} object needs to be created.
*
* @since 6.0.0(20)
*/
typedef struct XEG_RTReflectionCreateInfo {
    /**
     * Identifies the {@link XEG_StructureType} value of this structure,
     * which must be XEG_STRUCTURE_TYPE_RT_REFLECTION_CREATE_INFO.
     */
    XEG_StructureType sType;
    /** Pointer to the extended structure. */
    const void* pNext;
    /** Size of the input image. */
    VkExtent2D renderSize;
    /**
     * Whether to enable the fast intersection mode. The fast intersection mode has better performance than the common
     * intersection mode. The value true indicates that the fast intersection mode is enabled, and false indicates
     * that the common intersection mode is used.
     */
    bool enableFastTrace;
} XEG_RTReflectionCreateInfo;

/**
* @brief This structure describes the input information for sending a ray intersection command.
*
* @since 6.0.0(20)
*/
typedef struct XEG_RTReflectionDescription {
    /**
     * Identifies the {@link XEG_StructureType} value of this structure, which must be
     * XEG_STRUCTURE_TYPE_RT_REFLECTION_DESCRIPTION.
     */
    XEG_StructureType sType;
    /** Pointer to the extended structure. */
    const void* pNext;
    /**
     * Ray origin image, which cannot be empty. The format must be the float type of at least three channels.
     * The RGB channels store the x, y, and z coordinates of the origin respectively.
     */
    VkImageView inputRayOriginImage;
    /**
     * Ray direction image, which cannot be empty. The format must be the float type of at least three channels.
     * The RGB channels store the x, y, and z coordinates of the direction respectively.
     * If the format is signed float, no special processing is required. If the format is unsigned float,
     * the direction information needs to be quantized in the following manner: direction = (direction + 1.0) / 2.0.
     */
    VkImageView inputRayDirectionImage;
    /**
     * Intersection result of the output reflected rays. The format must be R32G32B32A32_UINT.
     * The intersection result packs the latest hit information of ray tracing into 128 bits.
     * The parsing method is as follows:
     *   uint raymiss = outputReflectionInfoImage.x & 1;
     *   uint primitiveId = (outputReflectionInfoImage.x >> 1) & (0x3ffff);
     *   uint instanceId = outputReflectionInfoImage.x >> 19;
     *   vec2 barycentrics = unpackHalf2x16(outputReflectionInfoImage.z);
     *   float hitT = uintBitsToFloat(outputReflectionInfoImage.w);
     *   uint sbtOffest = (outputReflectionInfoImage.y >> 16);
     *   uint geomtryIndex = (outputReflectionInfoImage.y) & 0xffff;
     */
    VkImageView outputReflectionInfoImage;
    /** Ray-traced acceleration structure of the scene. */
    VkAccelerationStructureKHR accelerationStructure;
    /**
     * Minimum distance between the start point of a light ray and the nearest possible intersection point.
     * The value must be non-negative and less than or equal to rayMax.
     */
    float rayMin;
    /**
     * Maximum distance between the start point of a light ray and the farthest possible intersection point.
     * Any intersection beyond this range will be ignored.
     */
    float rayMax;
    /**
     * Configures the rayFlags and cullMask parameters in the rayQueryInitializeEXT function.
     * The upper 24 bits indicate rayFlags, and the lower 8 bits indicate cullMask.
	 */
    uint32_t reflectionCullMask;
}  XEG_RTReflectionDescription;

/**
 * @brief Defines the function pointer for creating an {@link XEG_RTReflection} object.
 *
 * @param device VkDevice that is currently in use.
 * @param pCreateInfo Pointer to the structure containing the information needed for creating a reflection
 * instance handle. Currently, only pointers of the {@link XEG_RTReflectionCreateInfo} type are supported.
 * The value cannot be null.
 * @param pRtReflection Pointer to the reflection instance handle.
 * The created {@link XEG_RTReflection} is returned in this handle.
 * @return Returns an error code of the VkResult type. VK_SUCCESS indicates successful execution.
 * @since 6.0.0(20)
 */
typedef VkResult (VKAPI_ATTR *PFN_HMS_XEG_CreateRTReflection)(
    VkDevice device, const void* pCreateInfo, XEG_RTReflection* pRtReflection
);

/**
 * @brief Defines the function pointer for recording the command for calculating the RT reflection hit
 * information.
 *
 * @param commandBuffer Vulkan command buffer object, which must be of the primary type.
 * @param rtReflection Created {@link XegAdaptiveVRS} object.
 * @param pDescription Pointer to the reflection rendering input information structure {@link
 * XEG_RTReflectionDescription}. The value cannot be null.
 * @since 6.0.0(20)
 */
typedef VkResult (VKAPI_ATTR *PFN_HMS_XEG_CmdRenderRTReflection)(
    VkCommandBuffer commandBuffer, XEG_RTReflection rtReflection, const void* pDescription
);

/**
 * @brief Defines the function pointer for destroying an {@link XEG_RTReflection} object.
 *
 * @param rtReflection {@link XEG_RTReflection} object to be destroyed.
 * @since 6.0.0(20)
 */
typedef void (VKAPI_ATTR *PFN_HMS_XEG_DestroyRTReflection)(XEG_RTReflection rtReflection);

#ifndef XEG_NO_PROTOTYPES

/**
 * @brief Creates an {@link XEG_RTReflection} object.
 *
 * @param device VkDevice that is currently in use.
 * @param pCreateInfo Pointer to the structure containing the information needed for creating a reflection instance
 * handle. Currently, only pointers of the {@link XEG_RTReflectionCreateInfo} type are supported.
 * The value cannot be null.
 * @param pRtReflection Pointer to the reflection instance handle.
 * The created {@link XEG_RTReflection} is returned in this handle.
 * @return Returns an error code of the VkResult type. VK_SUCCESS indicates successful execution.
 * @since 6.0.0(20)
 */
VKAPI_ATTR VkResult VKAPI_CALL HMS_XEG_CreateRTReflection(
    VkDevice          device,
    const void*       pCreateInfo,
    XEG_RTReflection* pRtReflection
);

/**
 * @brief Records the command for calculating the RT reflection hit information.
 *
 * @param commandBuffer Vulkan command buffer object, which must be of the primary type.
 * @param rtReflection Created {@link XegAdaptiveVRS} object.
 * @param pDescription Pointer to the reflection rendering input information structure
 * {@link XEG_RTReflectionDescription}. The value cannot be null.
 * @since 6.0.0(20)
 */
VKAPI_ATTR VkResult VKAPI_CALL HMS_XEG_CmdRenderRTReflection(
    VkCommandBuffer  commandBuffer,
    XEG_RTReflection rtReflection,
    const void*      pDescription
);

/**
 * @brief Destroys an {@link XEG_RTReflection} object.
 *
 * @param rtReflection {@link XEG_RTReflection} object to be destroyed.
 * @since 6.0.0(20)
 */
VKAPI_ATTR void VKAPI_CALL HMS_XEG_DestroyRTReflection(
    XEG_RTReflection rtReflection
);

#endif /* XEG_NO_PROTOTYPES */

#ifdef __cplusplus
}
#endif

#endif  // XEG_VULKAN_RT_REFLECTION_H
/** @} */
