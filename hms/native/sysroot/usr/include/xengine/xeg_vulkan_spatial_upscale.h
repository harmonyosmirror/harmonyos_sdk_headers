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
 * @file xeg_vulkan_spatial_upscale.h
 * @kit XEngineKit
 * @library libxengine.so
 *
 * @brief Vulkan APIs for the GPU spatial upscaling of XEngine.
 * Before using APIs in this header file, you need to call the {@link HMS_XEG_EnumerateDeviceExtensionProperties} API
 * to verify that extension {@link XEG_SPATIAL_UPSCALE_EXTENSION_NAME} is available.
 * @syscap SystemCapability.Graphic.XEngine
 * @since 5.0.0(12)
 */

#ifndef XEG_VULKAN_SPATIAL_UPSCALE_H
#define XEG_VULKAN_SPATIAL_UPSCALE_H

#include <vulkan/vulkan.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Handle to {@link XEG_SpatialUpscale}.
 *
 * @since 5.0.0(12)
 */
VK_DEFINE_HANDLE(XEG_SpatialUpscale)

/**
 * @brief This structure describes the information for creating an {@link XEG_SpatialUpscale} object.
 * When the information in the structure changes, a new XEG_SpatialUpscale object needs to be created.
 *
 * @since 5.0.0(12)
 */
typedef struct XEG_SpatialUpscaleCreateInfo {
    /** Size of the upscaling image. The size must be the same as that of VkimageView of the image to be upscaled.
    * Otherwise, undefined problems may occur, such as upscaling failure and program crash.
    */
    VkExtent2D inputSize;
    
    /** Sampling region of the upscaling image.
    * The value of this parameter must be greater than 0 and less or equal than the image size.
    * Otherwise, the rendering fails or the rendering effect is unexpected.
    * This parameter has two structures: VkOffset2D offset and VkExtent2D extent.
    * offset defines the x and y coordinates of the upper left corner of the image region,
    * and extent defines the width and height of the image region.
    */
    VkRect2D inputRegion;
    
    /** Size of the upscaled image. The size must be the same as that of VkimageView of the upscaled image.
    * Otherwise, undefined problems may occur, such as upscaling failure and program crash.
    */
    VkExtent2D outputSize;
    
    /** Drawing region of the upscaling image.
    * The value of this parameter must be greater than 0 and less or equal than the image size.
    * Otherwise, the rendering fails or the rendering effect is unexpected.
    * This parameter has two structures: VkOffset2D offset and VkExtent2D extent.
    * offset defines the x and y coordinates of the upper left corner of the image region,
    * and extent defines the width and height of the image region.
    */
    VkRect2D outputRegion;
    
    /** Format of the upscaled image. */
    VkFormat format;
    
    /** Sharpness for upscaling. The recommended value range is [0, 1].
    * The sharpness needs to be adjusted for images of different styles.
    * Otherwise, over-sharpening will occur, for example, the image has a lot of noises.
    */
    float sharpness;
} XEG_SpatialUpscaleCreateInfo;

/**
 * @brief This structure describes the image information
 * required for delivering the GPU spatial upscaling rendering command.
 *
 * @since 5.0.0(12)
 */
typedef struct XEG_SpatialUpscaleDescription {
    /** The VkImageView for upscaling must be valid.
    * Otherwise, undefined behavior may occur, for example, rendering fails or the program crashes.
    */
    VkImageView inputImage;
    /** The upscaled VkImageView must be valid.
    * Otherwise, undefined behavior may occur, for example, rendering fails or the program crashes.
    */
    VkImageView outputImage;
} XEG_SpatialUpscaleDescription;

/**
* @brief Defines the function pointer for creating an {@link XEG_SpatialUpscale} object.
*
* @param device Must be the VkDevice in use.
* @param pXegSpatialUpscaleCreateInfo Pointer to the structure {@link XEG_SpatialUpscaleCreateInfo}.
* Its value cannot be null.
* @param pXegSpatialUpscale Pointer to the handle. The created {@link XEG_SpatialUpscale} is returned in this handle.
*
* @return Returns an error code of the VkResult type. VK_SUCCESS indicates successful execution.
* @since 5.0.0(12)
*/
typedef VkResult (VKAPI_PTR *PFN_HMS_XEG_CreateSpatialUpscale)(VkDevice device,
    const XEG_SpatialUpscaleCreateInfo* pXegSpatialUpscaleCreateInfo, XEG_SpatialUpscale* pXegSpatialUpscale);

/**
* @brief Defines the function pointer for executing the GPU spatial upscaling rendering command.
*
* @param commandBuffer VkCommandBuffer of the current command,
* which must be submitted to vkQueueSubmit before being executed.
* @param xegSpatialUpscale The {@link XEG_SpatialUpscale} object that has been created.
* @param pXegSpatialUpscaleDescription Pointer to the parameter structure {@link XEG_SpatialUpscaleDescription} of
* the rendering command.
* Its value cannot be null.
*
* @since 5.0.0(12)
*/
typedef void (VKAPI_PTR *PFN_HMS_XEG_CmdRenderSpatialUpscale)(VkCommandBuffer commandBuffer,
    XEG_SpatialUpscale xegSpatialUpscale, XEG_SpatialUpscaleDescription*  pXegSpatialUpscaleDescription);

/**
* @brief Defines the function pointer for destroying an {@link XEG_SpatialUpscale} object.
*
* @param xegSpatialUpscale The {@link XEG_SpatialUpscale} object that has been created.
*
* @since 5.0.0(12)
*/
typedef void (VKAPI_PTR *PFN_HMS_XEG_DestroySpatialUpscale)(XEG_SpatialUpscale  xegSpatialUpscale);

#ifndef XEG_NO_PROTOTYPES

/**
* @brief Creates an {@link XEG_SpatialUpscale} object.
*
* @param device Must be the VkDevice in use.
* @param pXegSpatialUpscaleCreateInfo Pointer to the structure {@link XEG_SpatialUpscaleCreateInfo}.
* Its value cannot be null.
* @param pXegSpatialUpscale Pointer to the handle.
* The created {@link XEG_SpatialUpscale} is returned in this handle.
*
* @return Returns an error code of the VkResult type. VK_SUCCESS indicates successful execution.
* @since 5.0.0(12)
*/
VKAPI_ATTR VkResult VKAPI_CALL HMS_XEG_CreateSpatialUpscale(
    VkDevice                              device,
    const XEG_SpatialUpscaleCreateInfo*   pXegSpatialUpscaleCreateInfo,
    XEG_SpatialUpscale*                   pXegSpatialUpscale
);

/**
* @brief Executes the GPU spatial upscaling rendering command.
*
* @param commandBuffer VkCommandBuffer of the current command,
* which must be submitted to vkQueueSubmit before being executed.
* @param xegSpatialUpscale The {@link XEG_SpatialUpscale} object that has been created.
* @param pXegSpatialUpscaleDescription Pointer to the parameter structure
* {@link XEG_SpatialUpscaleDescription} of the rendering command.
* Its value cannot be null.
*
* @since 5.0.0(12)
*/
VKAPI_ATTR void VKAPI_CALL HMS_XEG_CmdRenderSpatialUpscale(
    VkCommandBuffer                 commandBuffer,
    XEG_SpatialUpscale              xegSpatialUpscale,
    XEG_SpatialUpscaleDescription*  pXegSpatialUpscaleDescription
);

/**
* @brief Destroys an {@link XEG_SpatialUpscale} object.
*
* @param xegSpatialUpscale The {@link XEG_SpatialUpscale} object that has been created.
*
* @since 5.0.0(12)
*/
VKAPI_ATTR void VKAPI_CALL HMS_XEG_DestroySpatialUpscale(
    XEG_SpatialUpscale    xegSpatialUpscale
);

#endif /* XEG_NO_PROTOTYPES */

#ifdef __cplusplus
}
#endif

/** @} */
#endif // XEG_VULKAN_SPATIAL_UPSCALE_H
