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
 * @file xeg_vulkan_adaptive_vrs.h
 * @kit XEngineKit
 * @library libxengine.so
 *
 * @brief Vulkan APIs for the adaptive VRS of XEngine. Before using APIs in this header file,
 * you need to call the {@link HMS_XEG_EnumerateDeviceExtensionProperties} API to verify that
 * extension {@link XEG_ADAPTIVE_VRS_EXTENSION_NAME} is available.
 * @syscap SystemCapability.Graphic.XEngine
 * @since 5.0.0(12)
 */

#ifndef XEG_VULKAN_ADAPTIVE_VRS_H
#define XEG_VULKAN_ADAPTIVE_VRS_H

#include "info/application_target_sdk_version.h"
#include <stdbool.h>
#include <vulkan/vulkan.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief {@link XEG_AdaptiveVRS} handle.
 *
 * @since 5.0.0(12)
 */
VK_DEFINE_HANDLE(XEG_AdaptiveVRS)

/**
 * @brief This structure describes the parameter information for creating an {@link XEG_AdaptiveVRS} object. When the
 * information in the structure changes, a new {@link XEG_AdaptiveVRS} object needs to be created.
 *
 * @since 5.0.0(12)
 */
typedef struct XEG_AdaptiveVRSCreateInfo {
    /** Image size finally rendered by the rendering pipeline of the previous frame. */
    VkExtent2D inputSize;
    
    /** Image region finally rendered by the rendering pipeline of the previous frame. This parameter has two
    * structures: VkOffset2D offset and VkExtent2D extent. offset defines the x and y coordinates of the upper left
    * corner of the rendered image region, and extent defines the width and height of the rendered image region.
    */
    VkRect2D inputRegion;

    /** Tile size for adaptive VRS rendering. A larger tile size indicates better performance but deteriorated image
    * quality. Currently, XEngine Adaptive VRS supports only two TileSize specifications: 16 and 8.
    */
    int32_t adaptiveTileSize;
    
    /** Threshold for generating the final shading rate texture result. A larger value indicates a smaller average
    * shading rate, that is, the performance is better but the image quality deteriorates. The recommended value range
    * is [0, 1].
    */
    float errorSensitivity;
    
    /** Indicates whether to flip an image. true: flip; false: not flip. */
    bool flip;
} XEG_AdaptiveVRSCreateInfo;

/**
 * @brief This structure describes the parameter information required for delivering the command for drawing the
 * shading rate texture. The information needs to be updated for each frame.
 *
 * @since 5.0.0(12)
 */
typedef struct XEG_AdaptiveVRSDescription {
    /**
    * The parameter is optional. If the parameter is not empty, the rendering result is better. Pointer to the
    * reprojection matrix. The computation formula is as follows: (Projection matrix of the previous frame x
    * Observation matrix of the previous frame) x (Inverse matrix of (Projection matrix of the current frame x
    * Observation matrix of the current frame)). The matrix must be a 4 x 4 column major-order matrix.
    */
    float* reprojectionMatrix;
    
    /** VkImageView of the color attachment containing the final rendering result of the rendering pipeline of the
    * previous frame.
    */
    VkImageView    inputColorImage;
    
    /** VkImageView of the depth attachment containing the rendering result of the rendering pipeline of the
    * current frame.
    */
    VkImageView    inputDepthImage;
    
    /** VkImageView for generating the shading rate image information. The VkImageView needs to be created and entered
    * by the user.
    */
    VkImageView    outputShadingRateImage;
} XEG_AdaptiveVRSDescription;

/**
* @brief Defines the function pointer for creating an {@link XEG_AdaptiveVRS} object.
*
* @param device Must be the VkDevice in use.
* @param pXegAdaptiveVRSCreateInfo Pointer to the structure {@link XEG_AdaptiveVRSCreateInfo}.
* Its value cannot be null.
* @param pXegAdaptiveVRS Pointer to the handle. The created {@link XEG_AdaptiveVRS} is returned in this handle.
*
* @return Returns an error code of the VkResult type. VK_SUCCESS indicates successful execution.
* @since 5.0.0(12)
*/
typedef VkResult (VKAPI_PTR *PFN_HMS_XEG_CreateAdaptiveVRS)(VkDevice device,
    const XEG_AdaptiveVRSCreateInfo* pXegAdaptiveVRSCreateInfo, XEG_AdaptiveVRS* pXegAdaptiveVRS);

/**
* @brief Defines the function pointer for computing the adaptive VRS command.
*
* @param commandBuffer VkCommandBuffer of the current command, which must be submitted to vkQueueSubmit before being
* executed.
* @param xegAdaptiveVRS The {@link XEG_AdaptiveVRS} object that has been created.
* @param pXegAdaptiveVRSDescription Pointer to the parameter structure {@link XEG_AdaptiveVRSDescription} of the
* delivering command.
* Its value cannot be null.
*
* @since 5.0.0(12)
*/
typedef void (VKAPI_PTR *PFN_HMS_XEG_CmdDispatchAdaptiveVRS)(VkCommandBuffer commandBuffer,
    XEG_AdaptiveVRS xegAdaptiveVRS, XEG_AdaptiveVRSDescription* pXegAdaptiveVRSDescription);

/**
* @brief Defines the function pointer for destroying an {@link XEG_AdaptiveVRS} object.
*
* @param xegAdaptiveVRS The {@link XEG_AdaptiveVRS} object that has been created.
*
* @since 5.0.0(12)
*/
typedef void (VKAPI_PTR *PFN_HMS_XEG_DestroyAdaptiveVRS)(XEG_AdaptiveVRS xegAdaptiveVRS);

#ifndef XEG_NO_PROTOTYPES
/**
* @brief Creates an {@link XEG_AdaptiveVRS} object.
*
* @param device Must be the VkDevice in use.
* @param pXegAdaptiveVRSCreateInfo Pointer to the structure {@link XEG_AdaptiveVRSCreateInfo}. Its value cannot be null.
* @param pXegAdaptiveVRS Pointer to the handle. The created {@link XEG_AdaptiveVRS} is returned in this handle.
*
* @return Returns an error code of the VkResult type. VK_SUCCESS indicates successful execution.
* @since 5.0.0(12)
*/
VKAPI_ATTR VkResult VKAPI_CALL HMS_XEG_CreateAdaptiveVRS(
    VkDevice                     device,
    XEG_AdaptiveVRSCreateInfo*   pXegAdaptiveVRSCreateInfo,
    XEG_AdaptiveVRS*             pXegAdaptiveVRS
)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Executes the command for computing the adaptive VRS.
*
* @param commandBuffer VkCommandBuffer of the current command, which must be submitted to vkQueueSubmit before being
* executed.
* @param xegAdaptiveVRS The {@link XEG_AdaptiveVRS} object that has been created.
* @param pXegAdaptiveVRSDescription Pointer to the parameter structure {@link XEG_AdaptiveVRSDescription} of the
* delivering command. Its value cannot be null.
*
* @since 5.0.0(12)
*/
VKAPI_ATTR void VKAPI_CALL HMS_XEG_CmdDispatchAdaptiveVRS(
    VkCommandBuffer                commandBuffer,
    XEG_AdaptiveVRS                xegAdaptiveVRS,
    XEG_AdaptiveVRSDescription*    pXegAdaptiveVRSDescription
)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Destroys an {@link XEG_AdaptiveVRS} object.
*
* @param xegAdaptiveVRS The {@link XEG_AdaptiveVRS} object that has been created.
*
* @since 5.0.0(12)
*/
VKAPI_ATTR void VKAPI_CALL HMS_XEG_DestroyAdaptiveVRS(
    XEG_AdaptiveVRS  xegAdaptiveVRS
)
__attribute__((__availability__(ohos, introduced=12.0.0)));

#endif /* XEG_NO_PROTOTYPES */

#ifdef __cplusplus
}
#endif

/** @} */
#endif // XEG_VULKAN_ADAPTIVE_VRS_H
