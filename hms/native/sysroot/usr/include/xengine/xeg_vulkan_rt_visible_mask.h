/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
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
 * @file xeg_vulkan_rt_visible_mask.h
 * @kit XEngineKit
 * @library libxengine.so
 *
 * @brief APIs for the RT VisibleMask feature of XEngine.
 * Before using the APIs in this header file, you need to call {@link HMS_XEG_EnumerateDeviceExtensionProperties} to
 * check whether the {@link XEG_RT_SHADOW_AO_EXTENSION_NAME} extension is available.
 * @syscap SystemCapability.Graphic.XEngine
 * @since 6.0.0(20)
 */

#ifndef XEG_VULKAN_RT_VISIBLEMASK_H
#define XEG_VULKAN_RT_VISIBLEMASK_H

#include "info/application_target_sdk_version.h"
#include <stdbool.h>
#include <vulkan/vulkan.h>
#include "xeg_vulkan_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Handle to {@link XEG_RTVisibleMask}, indicating the ray-traced VisibleMask feature instance.
 * The shadow and ambient occlusion effects are supported.
 *
 * @since 6.0.0(20)
 */
VK_DEFINE_HANDLE(XEG_RTVisibleMask)

 /**
 * @brief Enumerates denoising quality modes.
 *
 * @since 6.0.0(20)
 */
typedef enum XEG_DenoiseQualityMode {
    /** No denoising is performed. */
    XEG_DENOISE_QUALITY_MODE_NONE = 0,
    /** Generates high-quality noise-free results. The speed may be slow. */
    XEG_DENOISE_QUALITY_MODE_QUALITY = 1,
    /** Generates high-quality noise-free results at a moderate speed. */
    XEG_DENOISE_QUALITY_MODE_BALANCED = 2,
    /** Generates noise-free results with high performance. */
    XEG_DENOISE_QUALITY_MODE_PERFORMANCES = 3
} XEG_DenoiseQualityMode;

/**
 * @brief Enumerates traversal modes.
 *
 * @since 6.0.0(20)
 */
typedef enum XEG_TraversalMode {
    /** Traverses ray tracing scenarios pixel by pixel. */
    XEG_TRAVERSAL_MODE_DEFAULT = 0,
    /** Traverses scenarios using algorithms,
    * which provides better performance but may have slight differences in image quality.
    */
    XEG_TRAVERSAL_MODE_PERFORMANCES = 1
} XEG_TraversalMode;

/**
 * @brief This structure describes the initialization information for creating an {@link XEG_RTVisibleMask} instance
 * that supports the Ray-Traced Shadow and Ambient Occlusion effects. When the information in the structure changes,
 * a new {@link XEG_RTVisibleMask} object needs to be created.
 *
 * @since 6.0.0(20)
 */
struct XEG_RTShadowAOCreateInfo {
    /** Identifies the {@link XEG_StructureType} value of this structure, which must be
    * XEG_STRUCTURE_TYPE_RT_SHADOWAO_CREATE_INFO.
    */
    XEG_StructureType sType;
    /** Pointer to the extended structure. */
    const void* pNext;
    /** Dimensions of the input GBuffer depth and normal images.
    * The dimensions of the depth and normal images must be the same.
    */
    VkExtent2D rtInputGbufferSize;
    /** Dimensions of the output shadow and ambient occlusion images, which must be in the same proportion as
    * rtInputGbufferSize.
    */
    VkExtent2D rtShadowAOSize;
    /** Whether to enable the Ray-Traced Shadow effect (true) or not (false). At least one of the shadow and
    * ambient occlusion effects must be enabled.
    */
    bool enableRTShadow;
    /** Whether to enable the Ray-Traced Ambient Occlusion effect (true) or not (false).
    * At least one of the shadow and ambient occlusion effects must be enabled.
    */
    bool enableRTAO;
    /** Traversal mode. Ray-Traced Shadow and Ambient Occlusion use the same traversal mode. */
    XEG_TraversalMode traversalMode;
    /** Denoising quality mode. Ray-Traced Shadow and Ambient Occlusion use the same quality mode. */
    XEG_DenoiseQualityMode denoiseMode;
    /** This parameter takes effect only when the Ray-Traced Shadow effect is enabled. If this parameter is set
    * to true, only the ambient occlusion value of pixels in the shadow area is calculated.
    * If this parameter is set to false, the ambient occlusion value of all pixels is calculated. */
    bool aoOnlyInShadow;
    /** Whether depth flipping is enabled. If depth flipping is enabled, the depth at the far plane is 0.
    * Depth flipping can help obtain a higher-precision depth value. It is recommended that it be enabled.
    * The value true indicates that it is enabled, and the value false indicates that it is disabled.
    */
    bool reverseZ;
};

/**
 * @brief Ray-Traced Shadow algorithm parameters.
 *
 * @since 6.0.0(20)
 */
struct XEG_RTShadowParameters {
	/** tMax value of the Shadow rays. */
	float rayTMax;
	/** tMin value of the Shadow rays. */
    float rayTMin;
    /** Direction of the directional light. */
    float sunDirection[3];
    /** Angle range for shadow sampling along the light source direction. A larger value results in a larger
    * half-shadow area. The value of this parameter is clamped within the [0.0, 90.0] range. The default value is 0.0.
    */
    float raySourceAngleInDegree = 0.0f;
    /** Configures the rayFlags and cullMask parameters in the rayQueryInitializeEXT function.
    * The upper 24 bits indicate rayFlags, and the lower 8 bits indicate cullMask.
    * The default value is 0x5FF, that is, ((gl_RayFlagsOpaqueEXT | gl_RayFlagsTerminateOnFirstHitEXT) << 8) | 0xFF.
    */
	uint32_t shadowCullMask = 0x5FF;
	/** World space distance for shadow removal. Shadows are not calculated when the pixel distance in the scene
    * exceeds this distance. The value must be greater than 0. */
    float shadowCullDistance;
    /** Number of samples per pixel. Currently, only 1 SPP is supported. The default value is 1. */
    uint32_t rayPerPixel = 1;
};

/**
 * @brief Ray-Traced Ambient Occlusion algorithm parameters.
 *
 * @since 6.0.0(20)
 */
struct XEG_RTAOParameters {
	/** tMax value of the AO rays. */
    float rayTMax;
	/** tMin value of the AO rays. */
    float rayTMin;
    /** AO strength. A larger value results in a stronger AO effect.
    * The value of this parameter is clamped within the [0.5, 1.0] range. The default value is 1.0.
    */
    float aoIntensity = 1.0f;
	/** Bias distance from the shading point along the normal direction. This parameter is used to solve the
    * self-occlusion error caused by precision issues when the depth value is converted to the world coordinate.
    * The default value is 1.0.
    */
    float aoNormalBias = 1.0f;
    /** Configures the rayFlags and cullMask parameters in the rayQueryInitializeEXT function.
    * The upper 24 bits indicate rayFlags, and the lower 8 bits indicate cullMask.
    * The default value is 0x5FF, that is, ((gl_RayFlagsOpaqueEXT | gl_RayFlagsTerminateOnFirstHitEXT) << 8) | 0xFF.
    */
    uint32_t aoCullMask = 0x5FF;
    /** World space distance for ambient occlusion removal. Ambient occlusion is not calculated when the pixel distance
    * in the scene exceeds this distance. The value must be greater than 0.
    */
    float aoCullDistance;
    /** Number of samples per pixel. Currently, only 1 SPP is supported. The default value is 1. */
    uint32_t rayPerPixel = 1;
};

/**
 * @brief Denoising parameter for the Ray-Traced Shadow and Ambient Occlusion algorithms.
 *
 * @since 6.0.0(20)
 */
struct XEG_RTShadowAODenoiserParameters {
    /** Weighting coefficient for mixing the current frame and historical frames during time-domain filtering.
    * After the consistency check is passed, more information about the current frame is used if the weighting value is
    * is greater. The value of this parameter is clamped within the [0.01, 1.0] range. The default value is 0.075.
    */
    float temporalBlendFactor = 0.075f;
    /** Threshold for consistency check based on the world space distance in time-domain filtering. The value must be
    * greater than or equal to 0. If a negative value is passed, the value will be set to 0. The default value is 1.0.
    */
    float positionConstantDistance = 1.0f;
    /** Number of times that the spatial filter is executed. A larger number reduces noise in the shadow and ambient
    * occlusion results but may blur the output image. The value of this parameter is clamped within the [0, 5] range.
    * The default value is 2.
    */
    uint32_t spatialDenoiseTimes = 2;
    /** Ghosting issues introduced by controlling moving objects during time-domain filtering.
    * If the value is set to 0, the ghosting issues caused by moving objects are not resolved. A larger value results
    * in better ghosting issue resolution, but slightly weaker noise reduction effect. The value of this parameter is
    * clamped within the [0.0, 1.0] range. The default value is 0.0.
    */
    float ghostingAlpha = 0.0f;
    /** Normal weight used by the spatial domain filter. A larger value results in a higher normal weight and sharper
    * image quality. The value of this parameter is clamped within the [0.0, 1.0] range. The default value is 1.0.
    */
    float spatialNormalWeight = 1.0f;
    /** Sampling step of the space domain filter. A larger value results in a larger sampling range. The value of this
    * parameter is clamped within the [0, 4] range. The default value is 0.
    */
    uint32_t spatialMaxKernelStep = 0;
};

/**
 * @brief This structure describes the input information of the rendering command for the Ray-Traced Shadow and
 * Ambient Occlusion algorithms.
 *
 * @since 6.0.0(20)
 */
struct XEG_RTShadowAODescription {
    /** Identifies the {@link XEG_StructureType} value of this structure,
    * which must be XEG_STRUCTURE_TYPE_RT_SHADOWAO_DESCRIPTION.
    */
    XEG_StructureType sType;
    /** Pointer to the extended structure. */
    const void* pNext;
    /** Depth image, which cannot be null. */
    VkImageView inputDepthImage;
    /** Normal image, which cannot be null. The value must be in unsigned floating-point format and contain more than
    * three channels, for example, VK_FORMAT_R8G8B8_UNORM. XEngine parses the normal vector using the
    * formula: Normal=textureLod(inputNormalImage).xyz*2.0–1.0.
    */
    VkImageView inputNormalImage;
    /** Motion vector image, which can be null. The motion vector is computed by subtracting the X and Y values of the
    * NDC coordinates of the previous frame from those of the current rendered pixel. The image format must be
    * VK_FORMAT_R16G16_SFLOAT or higher.
    */
    VkImageView inputMotionVectorImage;
    /** Output shadow and ambient occlusion image, which cannot be null. The format must be VK_FORMAT_R8G8_UNORM. The
    * shadow value is written to the R channel, and the ambient occlusion value is written to the G channel.
    */
    VkImageView outputShadowAOImage;
    /** Top-level Acceleration Structure of the scene. */
    VkAccelerationStructureKHR accelerationStructure;
    /** Indicates whether the ray tracing acceleration structure is built in the translated world space.
    * The value true indicates it is built in the translated world space, and false indicates it is built in the
    * absolute world space. The default value is false.
    */
    bool isAsInTranslatedSpace = false;
    /** Camera translated view matrix, which must be a 4 x 4 matrix in column-major order.
    * It can be left unassigned when the value of isAsInTranslatedSpace is false.
    */
    float translatedViewMatrix[16];
    /** Camera view matrix, which must be a 4 x 4 matrix in column-major order. */
    float viewMatrix[16];
    /** Camera projection matrix, which must be a 4 x 4 matrix in column-major order. */
    float projectionMatrix[16];
    /** Position coordinates of the camera in the world space. */
    float worldCameraOrigin[3];
    /** Indicates whether there is a Y-axis flip relationship between the NDC space and the world space.
    * The value true indicates a flip, and false indicates no flip. The default value is false.
    */
    bool ndcFlipY = false;
    /** Ray-Traced Shadow algorithm parameter, which cannot be null when the XEG_RTShadowAOCreateInfo::enableRTShadow
    * value is true.
    */
    const XEG_RTShadowParameters* pRtShadowParameters;
    /** Ray-Traced Ambient Occlusion algorithm parameter, which cannot be null when the
    * XEG_RTShadowAOCreateInfo::enableRTAO value is true.
    */
    const XEG_RTAOParameters* pRtAOParameters;
    /** Denoising parameter, which cannot be null. Ray-Traced Shadow and Ambient Occlusion use the same
    * denoising parameter.
    */
    const XEG_RTShadowAODenoiserParameters* pRtShadowAODenoiserParameters;
};

/**
 * @brief Defines the function pointer for creating an {@link XEG_RTVisibleMask} object.
 *
 * @param device VkDevice that is currently in use.
 * @param pCreateInfo Pointer to the structure of the description information required for creating a
 * VisibleMask instance handle. Currently, only pointers of the {@link XEG_RTShadowAOCreateInfo} type are supported.
 * The value cannot be null.
 * @param pRTVisibleMask Pointer to the VisibleMask instance handle. The created {@link XEG_RTVisibleMask} is returned
 * in this handle.
 * @return Error code of the VkResult type. If the value is VK_SUCCESS, the creation is successful.
 * @since 6.0.0(20)
 */
typedef VkResult (VKAPI_PTR *PFN_HMS_XEG_CreateRTVisibleMask)(
    VkDevice           device,
    const void*        pCreateInfo,
    XEG_RTVisibleMask* pRTVisibleMask
);

/**
 * @brief Defines the function pointer for recording the ray-traced VisibleMask rendering command.
 *
 * @param commandBuffer Vulkan command buffer object.
 * @param rtVisibleMask Created {@link XEG_RTVisibleMask} object.
 * @param pDescription Pointer to the input parameter structure for executing the rendering command. Only pointers of
 * the {@link XEG_RTShadowAODescription} type are supported. The value cannot be null.
 * @return Error code of the VkResult type. If the value is VK_SUCCESS, the execution is successful.
 * @since 6.0.0(20)
 */
typedef VkResult (VKAPI_PTR *PFN_HMS_XEG_CmdRenderRTVisibleMask)(
    VkCommandBuffer    commandBuffer,
    XEG_RTVisibleMask  rtVisibleMask,
    const void*        pDescription
);

/**
 * @brief Defines the function pointer for destroying an {@link XEG_RTVisibleMask} object.
 *
 * @param rtVisibleMask {@link XEG_RTVisibleMask} object to be destroyed.
 * @since 6.0.0(20)
 */
typedef void (VKAPI_PTR *PFN_HMS_XEG_DestroyRTVisibleMask)(XEG_RTVisibleMask rtVisibleMask);

#ifndef XEG_NO_PROTOTYPES

/**
 * @brief Creates an {@link XEG_RTVisibleMask} object.
 *
 * @param device VkDevice that is currently in use.
 * @param pCreateInfo Pointer to the structure of the description information required for creating a
 * VisibleMask instance handle. Currently, only pointers of the {@link XEG_RTShadowAOCreateInfo} type are supported.
 * The value cannot be null.
 * @param pRTVisibleMask Pointer to the VisibleMask instance handle. The created {@link XEG_RTVisibleMask} is returned
 * in this handle.
 * @return Error code of the VkResult type. If the value is VK_SUCCESS, the creation is successful.
 * @since 6.0.0(20)
 */
VKAPI_ATTR VkResult VKAPI_CALL HMS_XEG_CreateRTVisibleMask(
    VkDevice           device,
    const void*        pCreateInfo,
    XEG_RTVisibleMask* pRTVisibleMask
)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Records the ray-traced VisibleMask rendering command.
 *
 * @param commandBuffer Vulkan command buffer object.
 * @param rtVisibleMask Created {@link XEG_RTVisibleMask} object.
 * @param pDescription Pointer to the input parameter structure for executing the rendering command. Only pointers of
 * the {@link XEG_RTShadowAODescription} type are supported. The value cannot be null.
 * @return Error code of the VkResult type. If the value is VK_SUCCESS, the execution is successful.
 * @since 6.0.0(20)
 */
VKAPI_ATTR VkResult VKAPI_CALL HMS_XEG_CmdRenderRTVisibleMask(
    VkCommandBuffer    commandBuffer,
    XEG_RTVisibleMask  rtVisibleMask,
    const void*        pDescription
)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Destroys an {@link XEG_RTVisibleMask} object.
 *
 * @param rtVisibleMask {@link XEG_RTVisibleMask} object to be destroyed.
 * @since 6.0.0(20)
 */
VKAPI_ATTR void VKAPI_CALL HMS_XEG_DestroyRTVisibleMask(
    XEG_RTVisibleMask rtVisibleMask
)
__attribute__((__availability__(ohos, introduced=20.0.0)));

#endif /* XEG_NO_PROTOTYPES */

#ifdef __cplusplus
}
#endif

#endif // XEG_VULKAN_RT_VISIBLEMASK_H
/** @} */
