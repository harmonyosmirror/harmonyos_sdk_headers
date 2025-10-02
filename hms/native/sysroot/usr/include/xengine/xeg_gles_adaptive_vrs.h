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
 * @file xeg_gles_adaptive_vrs.h
 * @kit XEngineKit
 * @library libxengine.so
 *
 * @brief VRS APIs of XEngine.
 * Before using APIs in this header file, you need to call the {@link HMS_XEG_GetString} API to
 * verify that extension {@link XEG_ADAPTIVE_VRS_EXTENSION_NAME} is available.
 *
 * @syscap SystemCapability.Graphic.XEngine
 * @since 5.0.0(12)
 */

#ifndef XEG_GLES_ADAPTIVE_VRS_H
#define XEG_GLES_ADAPTIVE_VRS_H

#include <GLES3/gl3.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Sets the INPUT_SIZE parameter of the {@link HMS_XEG_AdaptiveVRSParameter} API, indicating the image width and
 * height finally rendered by the rendering pipeline of the previous frame.
 *
 * When this macro is used to set the INPUT_SIZE parameter through the {@link HMS_XEG_AdaptiveVRSParameter} API,
 * `param` passed to the API must be a GLsizei array whose length is 2. Otherwise, undefined behavior will occur,
 * for example, the rendering effect is incorrect or the program crashes.
 * This parameter is mandatory and must have the same width and height as inputColorImage of
 * {@link HMS_XEG_DispatchAdaptiveVRS}.
 *
 * @since 5.0.0(12)
 */
#define XEG_ADAPTIVE_VRS_INPUT_SIZE 0x1U

/**
 * @brief Sets the INPUT_REGION parameter of the {@link HMS_XEG_AdaptiveVRSParameter} API, indicating the image region
 * finally rendered by the rendering pipeline of the previous frame.
 *
 * When this macro is used to set the INPUT_REGION parameter through the {@link HMS_XEG_AdaptiveVRSParameter} API,
 * `param` passed to the API must be a GLuint array whose length is 4, which indicates the coordinates of the lower
 * left corner and the width and height of the rendered image area, respectively. Otherwise, undefined behavior will
 * occur, for example, the rendering effect is incorrect or the program crashes.
 * This parameter is optional, and the default value is [0, 0, INPUT_SIZE[0], INPUT_SIZE[1]].
 *
 * @since 5.0.0(12)
 */
#define XEG_ADAPTIVE_VRS_INPUT_REGION 0x2U

/**
 * @brief Sets the TEXEL_SIZE parameter of the {@link HMS_XEG_AdaptiveVRSParameter} API.
 *
 * When this macro is used to set the TEXEL_SIZE parameter through the {@link HMS_XEG_AdaptiveVRSParameter} API,
 * `param` passed to the API must be a GLsizei array whose length is 2, which indicates TEXEL_WIDTH and
 * TEXEL_HEIGHT, respectively. Otherwise, undefined behavior will occur, for example, the rendering effect is
 * incorrect or the program crashes.
 * This parameter is optional, and the value can be [8, 8] or [16, 16]. The default value is [8, 8].
 *
 * @since 5.0.0(12)
 */
#define XEG_ADAPTIVE_VRS_TEXEL_SIZE 0x3U

/**
 * @brief Sets the ERROR_SENSITIVITY parameter of the {@link HMS_XEG_AdaptiveVRSParameter} API, indicating the
 * threshold for controlling the generation of the shading rate image. A larger value indicates a smaller average
 * shading rate, that is, the performance is better but the image quality deteriorates. The recommended value range is
 * [0, 1].
 *
 * When this macro is used to set the ERROR_SENSITIVITY parameter through the {@link HMS_XEG_AdaptiveVRSParameter} API,
 * `param` passed to the API must be a GLfloat pointer. Otherwise, undefined behavior will occur, for example, the
 * rendering effect is incorrect or the program crashes.
 * This parameter is optional, and the default value is 0.5.
 *
 * @since 5.0.0(12)
 */
#define XEG_ADAPTIVE_VRS_ERROR_SENSITIVITY 0x4U

/**
 * @brief Sets the FLIP parameter of the {@link HMS_XEG_AdaptiveVRSParameter} API, indicating whether to flip the
 * image vertically.
 *
 * When this macro is used to set the FLIP parameter through the {@link HMS_XEG_AdaptiveVRSParameter} API, `param`
 * passed to the API must be a GLboolean pointer. Otherwise, undefined behavior will occur, for example, the rendering
 * effect is incorrect or the program crashes.
 * This parameter is optional, and the default value is false. The value true indicates to flip the image vertically,
 * and the value false indicates not to flip the image vertically.
 *
 * @since 5.0.0(12)
 */
#define XEG_ADAPTIVE_VRS_FLIP 0x5U

/**
 * @brief Defines the function pointer for setting the input parameter of the adaptive variable rate shading (VRS).
 *
 * @param pname Enumerated name of the input parameter. The value can be
 * {@link XEG_ADAPTIVE_VRS_INPUT_SIZE}, {@link XEG_ADAPTIVE_VRS_INPUT_REGION}, {@link XEG_ADAPTIVE_VRS_TEXEL_SIZE},
 * {@link XEG_ADAPTIVE_VRS_ERROR_SENSITIVITY}, or {@link XEG_ADAPTIVE_VRS_FLIP}.
 * @param param Input parameter value. For details, see the description of the enumerated names of the input parameters.
 *
 * @since 5.0.0(12)
 */
typedef void (GL_APIENTRYP PFN_HMS_XEG_ADAPTIVEVRSPARAMETER)(
    GLenum pname,
    GLvoid *param
);

/**
 * @brief Defines the function pointer for computing the shading rate image.
 *
 * @param reprojectionMatrix Pointer to the result matrix of the computation between the current frame and the
 * previous frame. The computation formula is as follows: (Projection matrix of the previous frame x Observation matrix
 * of the previous frame) x (Inverse matrix of (Projection matrix of the current frame x Observation matrix of the
 * current frame)). The matrix must be a 4 x 4 column major-order matrix. This parameter is optional, the image quality
 * is better when it is not empty.
 * @param inputColorImage Texture ID of the color attachment containing the final rendering result of the rendering
 * pipeline of the previous frame.
 * @param inputDepthImage Texture ID of the depth attachment containing the rendering result of the rendering pipeline
 * of the current frame.
 * @param shadingRateImage Texture ID used to generate the shading rate image information, which needs to be created
 * and entered by the user.
 *
 * @since 5.0.0(12)
 */
typedef void (GL_APIENTRYP PFN_HMS_XEG_DISPATCHADAPTIVEVRS)(
    GLfloat *reprojectionMatrix,
    GLuint inputColorImage,
    GLuint inputDepthImage,
    GLuint shadingRateImage
);

/**
 * @brief Defines the function pointer for applying the shading rate image to the render target.
 *
 * @param shadingRateImage Shading rate image obtained after computation and 0 means disables adaptive VRS.
 *
 * @since 5.0.0(12)
 */
typedef void (GL_APIENTRYP PFN_HMS_XEG_APPLYADAPTIVEVRS)(
    GLuint shadingRateImage
);

/**
 * @brief Sets parameters of the adaptive VRS.
 *
 * @param pname Enumerated name of the input parameter. The value can be {@link XEG_ADAPTIVE_VRS_INPUT_SIZE},
 * {@link XEG_ADAPTIVE_VRS_INPUT_REGION}, {@link XEG_ADAPTIVE_VRS_TEXEL_SIZE},
 * {@link XEG_ADAPTIVE_VRS_ERROR_SENSITIVITY}, or {@link XEG_ADAPTIVE_VRS_FLIP}.
 * @param param Input parameter value. For details, see the description of the enumerated names of the input parameters.
 *
 * @since 5.0.0(12)
 */
GL_APICALL void GL_APIENTRY HMS_XEG_AdaptiveVRSParameter(GLenum pname, GLvoid *param);

/**
 * @brief Computes the shading rate image.
 *
 * @param reprojectionMatrix Pointer to the result matrix of the computation between the current frame and the previous
 * frame. The computation formula is as follows: (Projection matrix of the previous frame x Observation matrix of the
 * previous frame) x (Inverse matrix of (Projection matrix of the current frame x Observation matrix of the current
 * frame)). The matrix must be a 4 x 4 column major-order matrix. This parameter is optional, the image quality is
 * better when it is not empty.
 * @param inputColorImage Texture ID of the color attachment containing the final rendering result of the rendering
 * pipeline of the previous frame.
 * @param inputDepthImage Texture ID of the depth attachment containing the rendering result of the rendering pipeline
 * of the current frame.
 * @param shadingRateImage Texture ID used to generate the shading rate image information, which needs to be created
 * and entered by the user.
 *
 * @since 5.0.0(12)
 */
GL_APICALL void GL_APIENTRY HMS_XEG_DispatchAdaptiveVRS(GLfloat *reprojectionMatrix, GLuint inputColorImage,
    GLuint inputDepthImage, GLuint shadingRateImage);

/**
 * @brief Applies the shading rate image to the render target.
 *
 * @param shadingRateImage Shading rate image obtained after computation and 0 means disables adaptive VRS.
 *
 * @since 5.0.0(12)
 */
GL_APICALL void GL_APIENTRY HMS_XEG_ApplyAdaptiveVRS(GLuint shadingRateImage);

#ifdef __cplusplus
}
#endif
/** @} */
#endif // XEG_GLES_ADAPTIVE_VRS_H
