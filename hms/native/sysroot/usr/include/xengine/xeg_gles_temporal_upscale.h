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
 * @file xeg_gles_temporal_upscale.h
 * @kit XEngineKit
 * @library libxengine.so
 *
 * @brief OpenGL ES APIs for AI temporal upscaling of XEngine. The recommended upscaling factor is [1.25, 2.0].
 * Before using the APIs in this header file, you need to call {@link HMS_XEG_GetString} to query whether
 * the {@link XEG_TEMPORAL_UPSCALE_EXTENSION_NAME} extension is available.
 * @syscap SystemCapability.Graphic.XEngine
 * @since 6.0.0(20)
 */

#ifndef XEG_GLES_TEMPORAL_UPSCALE_H
#define XEG_GLES_TEMPORAL_UPSCALE_H

#include "info/application_target_sdk_version.h"
#include <GLES3/gl3.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Sets the actual width and height of the upscaling input texture by calling {@link
 * HMS_XEG_TemporalUpscaleParameter}.
 *
 * When this macro is used to set the input width and height, the param value passed to the API must be an unsigned
 * integer array whose length is 2. Otherwise, undefined behavior may occur, for example, the rendering effect is
 * incorrect or the program crashes. The values in the array are width and height in sequence, which determine the width
 * and height of the input texture, respectively. This parameter is mandatory.
 *
 * @since 6.0.0(20)
 */
#define XEG_TEMPORAL_UPSCALE_INPUT_SIZE 0x1U

/**
 * @brief Sets the number of camera jitter periods by calling {@link HMS_XEG_TemporalUpscaleParameter}. The value range
 * is [4, 16]. The recommended value is 8.
 *
 * When this macro is used to set the number of camera jitter periods, the param value passed to the API must be a valid
 * pointer to a GLuint value. Otherwise, undefined behavior may occur, for example, the rendering effect is incorrect or
 * the program crashes. This parameter is mandatory.
 *
 * @since 6.0.0(20)
 */
#define XEG_TEMPORAL_UPSCALE_JITTER_NUM 0x2U

/**
 * @brief Sets whether depth reversion exists by calling {@link HMS_XEG_TemporalUpscaleParameter}. The value true
 * indicates that depth reversion exists, and the value false indicates that depth reversion does not exist.
 *
 * When this macro is used to define whether depth inversion exists, the param value passed to the API must be a valid
 * pointer to a GLboolean value. Otherwise, undefined behavior may occur, for example, the rendering effect is incorrect
 * or the program crashes. This parameter is mandatory.
 *
 * @since 6.0.0(20)
 */
#define XEG_TEMPORAL_UPSCALE_DEPTH_REVERSED 0x3U

/**
 * @brief Sets whether to reset historical frame data (true) or not (false). The value true is recommended if upscaling
 * is not used for historical frames but is used for the current frame.
 *
 * When this macro is used to define whether to reset historical frame data, the param value passed to the API must be a
 * valid pointer to a GLboolean value. Otherwise, undefined behavior may occur, for example, the rendering effect is
 * incorrect or the program crashes. This parameter is mandatory.
 *
 * @since 6.0.0(20)
 */
#define XEG_TEMPORAL_UPSCALE_RESET_HISTORY 0x4U

/**
 * @brief Sets images' degree of bias towards the current frame (less ghosting but more flickering) or historical frames
 * (more ghosting but more stable) by calling {@link HMS_XEG_TemporalUpscaleParameter}. The value range is [0.0, 1.0]. A
 * larger value indicates a larger bias towards historical frames.
 *
 * When this macro is used to set the degree of bias, the param value passed to the API must be a valid pointer to a
 * GLfloat value. Otherwise, undefined behavior may occur, for example, the rendering effect is incorrect or the program
 * crashes. This parameter is optional. The default value is 0.5.
 *
 * @since 6.0.0(20)
 */
#define XEG_TEMPORAL_UPSCALE_STEADY_LEVEL 0x5U

#ifndef XEG_NO_PROTOTYPES
/**
 * @brief Sets input parameters for AI temporal upscaling.
 *
 * @param pname Enumerated names of input parameters. The values can be {@link XEG_TEMPORAL_UPSCALE_INPUT_SIZE}, {@link
 * XEG_TEMPORAL_UPSCALE_JITTER_NUM}, {@link XEG_TEMPORAL_UPSCALE_DEPTH_REVERSED}, {@link
 * XEG_TEMPORAL_UPSCALE_RESET_HISTORY}, and {@link XEG_TEMPORAL_UPSCALE_STEADY_LEVEL}.
 * @param param Values of input parameters. For details about the values, see the description of the enumerated names of
 * input parameters.
 * @since 6.0.0(20)
 */
GL_APICALL void GL_APIENTRY HMS_XEG_TemporalUpscaleParameter(GLenum pname, const GLvoid *param)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Executes the rendering command for AI temporal upscaling.
 *
 * @param inputTexture Upscaling input texture. The input texture is of the GL_TEXTURE_2D type, mipLevels is 1, and the
 * maximum dimensions supported are 2048 x 1024.
 * @param depthTexture Depth texture.
 * @param motionVectorTexture Motion vector image. The motion vector is computed by subtracting the X and Y values of
 * the NDC coordinates of the previous frame from those of the current rendered pixel.
 * @param dynamicMaskTexture Dynamic mask image of an object. The format must be GL_RED or its compatible format. The
 * valid value of the R channel is 0.0, 0.2, or 1.0, where 0.0 indicates static objects, 0.2 indicates moving objects
 * such as people, and 1.0 indicates special effects or translucent objects.
 * @param jitterX Camera jitter in the X direction.
 * @param jitterY Camera jitter in the Y direction.
 *
 * @since 6.0.0(20)
 */
GL_APICALL void GL_APIENTRY HMS_XEG_RenderTemporalUpscale(GLuint inputTexture, GLuint depthTexture,
    GLuint motionVectorTexture, GLuint dynamicMaskTexture, GLfloat jitterX, GLfloat jitterY)
    __attribute__((__availability__(ohos, introduced=20.0.0)));
#endif /* XEG_NO_PROTOTYPES */

/**
 * @brief Defines the function pointer for setting the input parameters for AI temporal upscaling.
 *
 * @param pname Enumerated names of input parameters. The values can be {@link XEG_TEMPORAL_UPSCALE_INPUT_SIZE}, {@link
 * XEG_TEMPORAL_UPSCALE_JITTER_NUM}, {@link XEG_TEMPORAL_UPSCALE_DEPTH_REVERSED}, {@link
 * XEG_TEMPORAL_UPSCALE_RESET_HISTORY}, and {@link XEG_TEMPORAL_UPSCALE_STEADY_LEVEL}.
 *
 * @param param Values of input parameters. For details about the values, see the description of the enumerated names of
 * input parameters.
 *
 * @since 6.0.0(20)
 */
typedef void(GL_APIENTRYP PFN_HMS_XEG_TemporalUpscaleParameter)(GLenum pname, GLvoid *param);

/**
 * @brief Defines the function pointer for executing the rendering command for AI temporal upscaling.
 *
 * @param inputTexture Upscaling input texture. The input texture is of the GL_TEXTURE_2D type, mipLevels is 1, and the
 * maximum dimensions supported are 2048 x 1024.
 * @param depthTexture Depth texture.
 * @param motionVectorTexture Motion vector image. The motion vector is computed by subtracting the X and Y values of
 * the NDC coordinates of the previous frame from those of the current rendered pixel.
 * @param dynamicMaskTexture Dynamic mask image of an object. The format must be GL_RED or its compatible format. The
 * valid value of the R channel is 0.0, 0.2, or 1.0, where 0.0 indicates static objects, 0.2 indicates moving objects
 * such as people, and 1.0 indicates special effects or translucent objects.
 * @param jitterX Camera jitter in the X direction.
 * @param jitterY Camera jitter in the Y direction.
 *
 * @since 6.0.0(20)
 */
typedef void(GL_APIENTRYP PFN_HMS_XEG_RenderTemporalUpscale)(GLuint inputTexture, GLuint depthTexture,
    GLuint motionVectorTexture, GLuint dynamicMaskTexture, GLfloat jitterX, GLfloat jitterY);

#ifdef __cplusplus
}
#endif

#endif  // XEG_GLES_TEMPORAL_UPSCALE_H
/** @} */
