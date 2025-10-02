/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

/**
 * @addtogroup XEngine
 * @{
 *
 * @brief Provides graphics APIs of XEngine.
 *
 * @syscap SystemCapability.Graphic.XEngine
 * @since 5.0.0(12)
 */

/**
 * @file xeg_vulkan_temporal_upscale.h
 * @kit XEngineKit
 * @library libxengine.so
 *
 * @brief AI temporal upscaling APIs of XEngine. The recommended upscaling multiple range is [1.25, 2.0].
 * Before using APIs in this header file, you need to call the {@link HMS_XEG_EnumerateDeviceExtensionProperties} API
 * to verify that extension {@link XEG_TEMPORAL_UPSCALE_EXTENSION_NAME} is available.
 * @syscap SystemCapability.Graphic.XEngine
 * @since 5.0.0(12)
 */
#ifndef XEG_VULKAN_TEMPORAL_UPSCALE_H
#define XEG_VULKAN_TEMPORAL_UPSCALE_H

#include <stdbool.h>
#include <vulkan/vulkan.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Handle to {@link XEG_TemporalUpscale}.
 *
 * @since 5.0.0(12)
 */
VK_DEFINE_HANDLE(XEG_TemporalUpscale)


/**
 * @brief This structure describes the information for creating an {@link XEG_TemporalUpscale} object. When the
 * information in the structure changes, a new {@link XEG_TemporalUpscale} object needs to be created.
 *
 * @since 5.0.0(12)
 */
typedef struct XEG_TemporalUpscaleCreateInfo {
    /** Size of the input image. The maximum size supported is 2048 * 1024.*/
    VkExtent2D inputSize;
    /** Size of the output image. */
    VkExtent2D outputSize;
    /** Output image region of upscaling. */
    VkRect2D   outputRegion;
    /** Format of the output image. */
    VkFormat   outputFormat;
    /** Number of camera jitter cycles. The value range is [4, 16]. The recommended value is 8. */
    int        jitterNum;
    /** Indicates whether depth reversion exists. If 0.0 is used to indicate the farthest depth, set this parameter
    * to true. Otherwise, set this parameter to false. */
    bool       isDepthReversed;
} XEG_TemporalUpscaleCreateInfo;

/**
 * @brief This structure describes the input information for delivering AI temporal upscaling rendering command.
 *
 * @since 5.0.0(12)
 */
typedef struct XEG_TemporalUpscaleDescription {
    /** Input image. */
    VkImageView inputImage;
    /** Depth image. */
    VkImageView depthImage;
    /** Motion vector image. The motion vector is computed by subtracting the X and Y values of the NDC coordinates of
    * the previous frame from those of the current rendered pixel. The image format must be `VK_FORMAT_R16G16_SFLOAT`
    * or higher.
    */
    VkImageView motionVectorImage;
    /** Dynamic mask image. The format must be `VK_FORMAT_R8_UNORM` or its compatible format. */
    VkImageView dynamicMaskImage;
    /** Output image. */
    VkImageView outputImage;
    /** Camera jitter in the X direction. */
    float       jitterX;
    /** Camera jitter in the Y direction. */
    float       jitterY;
    /** Indicates whether to reset historical frame data. true: reset; false: not reset. The value true is recommended
    * if upscaling is not used for historical frames but is used for the current frame.
    */
    bool        resetHistory;
    /** Indicates whether the picture is biased towards the current frame (less ghosting but more flickering) or
    * historical frames (more ghosting but more stable) The value range is [0.0, 1.0]. A larger value indicates a
    * larger bias towards historical frames. */
    float       steadyLevel;
} XEG_TemporalUpscaleDescription;

/**
 * @brief Defines the function pointer for creating an {@link XEG_TemporalUpscale} object.
 *
 * @param device Must be the VkDevice in use.
 * @param pTemporalUpscaleInfo Pointer to the upscaling creation information structure
 * {@link XEG_TemporalUpscaleCreateInfo}. Its value cannot be null.
 * @param pTemporalUpscale Pointer to the handle. The created {@link XEG_TemporalUpscale} is returned in this handle.
 * @return Returns an error code of the VkResult type. VK_SUCCESS indicates successful execution.
 * @since 5.0.0(12)
 */
typedef VkResult (VKAPI_ATTR *PFN_HMS_XEG_CreateTemporalUpscale)(VkDevice device,
    XEG_TemporalUpscaleCreateInfo* pTemporalUpscaleInfo, XEG_TemporalUpscale* pTemporalUpscale);

/**
 * @brief Defines the function pointer for recording the AI temporal upscaling rendering command.
 *
 * @param commandBuffer Vulkan command buffer object, which must be of the primary type.
 * @param temporalUpscale The {@link XEG_TemporalUpscale} object that has been created.
 * @param pDescription Pointer to the upscaling rendering input information structure
 * {@link XEG_TemporalUpscaleDescription}. Its value cannot be null.
 * @since 5.0.0(12)
 */
typedef void (VKAPI_ATTR *PFN_HMS_XEG_CmdRenderTemporalUpscale)(VkCommandBuffer commandBuffer,
    XEG_TemporalUpscale temporalUpscale, XEG_TemporalUpscaleDescription* pDescription);

/**
 * @brief Defines the function pointer for destroying an {@link XEG_TemporalUpscale} object.
 *
 * @param temporalUpscale The {@link XEG_TemporalUpscale} object to destroy.
 * @since 5.0.0(12)
 */
typedef void (VKAPI_ATTR *PFN_HMS_XEG_DestroyTemporalUpscale)(XEG_TemporalUpscale temporalUpscale);

#ifndef XEG_NO_PROTOTYPES

/**
 * @brief Creates an {@link XEG_TemporalUpscale} object.
 *
 * @param device Must be the VkDevice in use.
 * @param pTemporalUpscaleInfo Pointer to the upscaling creation information structure
 * {@link XEG_TemporalUpscaleCreateInfo}. Its value cannot be null.
 * @param pTemporalUpscale Pointer to the handle. The created {@link XEG_TemporalUpscale} is returned in this handle.
 * @return Returns an error code of the VkResult type. VK_SUCCESS indicates successful execution.
 * @since 5.0.0(12)
 */
VKAPI_ATTR VkResult VKAPI_CALL HMS_XEG_CreateTemporalUpscale(
    VkDevice                        device,
    XEG_TemporalUpscaleCreateInfo*  pTemporalUpscaleInfo,
    XEG_TemporalUpscale*            pTemporalUpscale
);

/**
 * @brief Records the AI temporal upscaling rendering command.
 *
 * @param commandBuffer Vulkan command buffer object, which must be of the primary type.
 * @param temporalUpscale The {@link XEG_TemporalUpscale} object that has been created.
 * @param pDescription Pointer to the upscaling rendering input information structure
 * {@link XEG_TemporalUpscaleDescription}. Its value cannot be null.
 * @since 5.0.0(12)
 */
VKAPI_ATTR void VKAPI_CALL HMS_XEG_CmdRenderTemporalUpscale(
    VkCommandBuffer                  commandBuffer,
    XEG_TemporalUpscale              temporalUpscale,
    XEG_TemporalUpscaleDescription*  pDescription
);

/**
 * @brief Destroys an {@link XEG_TemporalUpscale} object.
 *
 * @param temporalUpscale The {@link XEG_TemporalUpscale} object to destroy.
 * @since 5.0.0(12)
 */
VKAPI_ATTR void VKAPI_CALL HMS_XEG_DestroyTemporalUpscale(
    XEG_TemporalUpscale temporalUpscale
);

#endif /* XEG_NO_PROTOTYPES */

#ifdef __cplusplus
}
#endif
/** @} */
#endif // XEG_VULKAN_TEMPORAL_UPSCALE_H
