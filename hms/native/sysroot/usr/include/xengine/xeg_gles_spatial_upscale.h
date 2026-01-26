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
 * @file xeg_gles_spatial_upscale.h
 * @kit XEngineKit
 * @library libxengine.so
 *
 * @brief GLES APIs for the GPU spatial upscaling feature of XEngine.
 * Before using APIs in this header file, you need to call the {@link HMS_XEG_GetString} API
 * to verify that extension {@link XEG_SPATIAL_UPSCALE_EXTENSION_NAME} is available.
 * @syscap SystemCapability.Graphic.XEngine
 * @since 5.0.0(12)
 */

#ifndef XEG_GLES_SPATIAL_UPSCALE_H
#define XEG_GLES_SPATIAL_UPSCALE_H

#include "info/application_target_sdk_version.h"
#include <GLES3/gl3.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief Sets the SCISSOR parameter of the {@link HMS_XEG_SpatialUpscaleParameter} API.
*
* When this macro is used to set the SCISSOR parameter through the {@link HMS_XEG_SpatialUpscaleParameter} API,
* the value of `param` passed to the API must be a pointer pointing to an unsigned integer array whose length is 4.
* Otherwise, undefined behavior will occur, for example, the rendering effect is incorrect or the program crashes.
* The four values of SCISSOR are the x and y coordinates of the lower left corner
* and the width and height of the cropping window in sequence.
*
* @since 5.0.0(12)
*/
#define XEG_SPATIAL_UPSCALE_SCISSOR 0x1U

/**
* @brief Sets the SHARPNESS parameter of the {@link HMS_XEG_SpatialUpscaleParameter} API.
*
* When this macro is used to set the SHARPNESS parameter through the {@link HMS_XEG_SpatialUpscaleParameter} API,
* the value of `param` passed to the API must be a pointer pointing to the float type.
* It is recommended that the value ranges from 0 to 1.
* Otherwise, undefined behavior will occur, for example, the rendering effect is incorrect or the program crashes.
* A larger value of SHARPNESS indicates a stronger sharpening effect.
* The sharpness needs to be adjusted for images of different styles.
* Otherwise, over-sharpening will occur, for example, the image has a lot of noises.
*
* @since 5.0.0(12)
*/
#define XEG_SPATIAL_UPSCALE_SHARPNESS 0x2U

/**
* @brief Defines the function pointer for setting the GPU spatial upscaling input parameter.
*
* @param pname Enumerated name of the input parameter.
* The value can be {@link XEG_SPATIAL_UPSCALE_SCISSOR} or {@link XEG_SPATIAL_UPSCALE_SHARPNESS}.
* @param param Input parameter value. For details, see the description of the enumerated names of the input parameters.
* @since 5.0.0(12)
*/
typedef void (GL_APIENTRYP PFN_HMS_XEG_SPATIALUPSCALEPARAMETER)(GLenum pname, GLvoid *param);

/**
* @brief Defines the function pointer for executing the GPU spatial upscaling rendering command.
*
* @param inputTexture Input texture. The texture type must be GL_TEXTURE_2D, and there is only 1 mipLevel. The texture
* must be created before this API is called. Otherwise, the rendering will fail, for example, a black screen occurs.
* @since 5.0.0(12)
*/
typedef void (GL_APIENTRYP PFN_HMS_XEG_RENDERSPATIALUPSCALE)(GLuint inputTexture);

/**
* @brief Sets the GPU spatial upscaling input parameter.
*
* @param pname Enumerated name of the input parameter.
* The value can be {@link XEG_SPATIAL_UPSCALE_SCISSOR} or {@link XEG_SPATIAL_UPSCALE_SHARPNESS}.
* @param param Input parameter value. For details, see the description of the enumerated names of the input parameters.
* @since 5.0.0(12)
*/
GL_APICALL void GL_APIENTRY HMS_XEG_SpatialUpscaleParameter(GLenum pname, GLvoid *param)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Executes the GPU spatial upscaling rendering command.
*
* @param inputTexture Input texture. The texture type must be GL_TEXTURE_2D, and there is only 1 mipLevel. The texture
* must be created before this API is called. Otherwise, the rendering will fail, for example, a black screen occurs.
* @since 5.0.0(12)
*/
GL_APICALL void GL_APIENTRY HMS_XEG_RenderSpatialUpscale(GLuint inputTexture)
__attribute__((__availability__(ohos, introduced=12.0.0)));

#ifdef __cplusplus
}
#endif

/** @} */
#endif // XEG_GLES_SPATIAL_UPSCALE_H
