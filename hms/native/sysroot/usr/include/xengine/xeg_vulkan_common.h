/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */

/**
 * @addtogroup XEngine
 * @{
 *
 * @brief Provides graphics APIs of XEngine.
 *
 * @syscap SystemCapability.Graphic.XEngine
 * @since 6.0.0(20)
 */

/**
 * @file xeg_vulkan_common.h
 * @kit XEngineKit
 * @library libxengine.so
 *
 * @brief Contains the common type definitions related to Vulkan in XEngine.
 * @syscap SystemCapability.Graphic.XEngine
 * @since 6.0.0(20)
 */

#ifndef XEG_VULKAN_COMMON_H
#define XEG_VULKAN_COMMON_H

#include <vulkan/vulkan.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enum for the XEngine structure types.
 * @since 6.0.0(20)
 */
typedef enum XEG_StructureType {
	/** Type of the structure {@link XEG_RTShadowAOCreateInfo}. */
    XEG_STRUCTURE_TYPE_RT_SHADOWAO_CREATE_INFO = 0,

	/** Type of the structure {@link XEG_RTShadowAODescription}. */
    XEG_STRUCTURE_TYPE_RT_SHADOWAO_DESCRIPTION = 1,

	/** Type of the structure {@link XEG_RTReflectionCreateInfo}. */
    XEG_STRUCTURE_TYPE_RT_REFLECTION_CREATE_INFO = 2,

	/** Type of the structure {@link XEG_RTReflectionDescription}. */
    XEG_STRUCTURE_TYPE_RT_REFLECTION_DESCRIPTION = 3,

	/** Type of the structure {@link XEG_NNGICreateInfo}. */
    XEG_STRUCTURE_TYPE_NNGI_CREATE_INFO = 4,

	/** Type of the structure {@link XEG_NNGIDescription}. */
    XEG_STRUCTURE_TYPE_NNGI_DESCRIPTION = 5,

	/** Type of the structure {@link XEG_DDGICreateInfo}. */
    XEG_STRUCTURE_TYPE_DDGI_CREATE_INFO = 6,

    /** Type of the structure {@link XEG_DDGIDescription}. */
    XEG_STRUCTURE_TYPE_DDGI_DESCRIPTION = 7,

    /** Type of the structure {@link XEG_HPSCreateInfo}. */
    XEG_STRUCTURE_TYPE_HPS_CREATE_INFO = 1001,

    /** Type of the structure {@link XEG_HPSRadixSort}. */
    XEG_STRUCTURE_TYPE_HPS_RADIX_SORT = 1002,

    /** Type of the structure {@link XEG_HPSRadixSortDescription}. */
    XEG_STRUCTURE_TYPE_HPS_RADIX_SORT_DESCRIPTION = 1003,
} XEG_StructureType;

/**
 * @brief Defines the function pointer for setting synchronization signals and waiting for
 * the rendering result to be written to a specified image. When the RTGI feature is used,
 * it is the GI rendering result that needs to be waited for before being written to a specified image.
 *
 * @param commandBuffer VkCommandBuffer of the current command,
 * which must be submitted to vkQueueSubmit before being executed.
 * @param xegHandle Created handle object. When the RTGI feature is used,
 * the object is the created {@link XEG_RTGI} object.
 * @return Returns an error code of the VkResult type. VK_SUCCESS indicates successful execution.
 * @since 6.0.0(20)
 */
typedef VkResult (VKAPI_PTR *PFN_HMS_XEG_CmdSetSynchronization)(VkCommandBuffer commandBuffer,
    const void* xegHandle);

#ifndef XEG_NO_PROTOTYPES

/**
 * @brief Sets synchronization signals and waits for the rendering result to be written to a specified image.
 * When the RTGI feature is used, it is the GI rendering result that needs to be waited for
 * before being written to a specified image.
 *
 * @param commandBuffer VkCommandBuffer of the current command,
 * which must be submitted to vkQueueSubmit before being executed.
 * @param xegHandle Created handle object. When the RTGI feature is used,
 * the object is the created {@link XEG_RTGI} object.
 * @return Returns an error code of the VkResult type. VK_SUCCESS indicates successful execution.
 * @since 6.0.0(20)
 */
VKAPI_ATTR VkResult VKAPI_CALL HMS_XEG_CmdSetSynchronization(
    VkCommandBuffer   commandBuffer,
    const void*       xegHandle
);

#endif /* XEG_NO_PROTOTYPES */

#ifdef __cplusplus
}
#endif
#endif // XEG_VULKAN_COMMON_H

/** @} */
