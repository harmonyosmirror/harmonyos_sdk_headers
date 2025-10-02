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
 * @file xeg_gles_neural_upscale.h
 * @kit XEngineKit
 * @library libxengine.so
 *
 * @brief AI spatial upscaling APIs of XEngine. Before using APIs in this header file, you need to call the
 * {@link HMS_XEG_GetString} API to verify that extension {@link XEG_NEURAL_UPSCALE_EXTENSION_NAME} is available.
 * @syscap SystemCapability.Graphic.XEngine
 * @since 5.0.0(12)
 */
#ifndef XEG_GLES_NEURAL_UPSCALE_H
#define XEG_GLES_NEURAL_UPSCALE_H

#include <GLES3/gl3.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Sets the cropping window parameter for upscaling through the {@link HMS_XEG_NeuralUpscaleParameter} API.
 * The cropping window is used to determine the area for sampling the input image.
 *
 * When this macro is used to set cropping window parameters, the value of `param` passed to the API must be an
 * unsigned integer array with a length of 4. Otherwise, undefined behavior will occur, for example, the rendering
 * effect is incorrect or the program crashes. The values in the array are x, y, width, and height in sequence,
 * where x and y determine the lower left corner of the cropping window, and width and height respectively determine
 * the width and height of the cropping window.
 * This parameter is optional, and the default value (0, 0, width of the input texture, height of the input texture)
 * will be used if cropping window parameters are not set.
 *
 * @since 5.0.0(12)
 */
#define XEG_NEURAL_UPSCALE_SCISSOR 0x1U

 /**
 * @brief Sets the sharpness parameter for upscaling through the {@link HMS_XEG_NeuralUpscaleParameter} API.
 * The recommended value range of sharpness is [0, 1].
 *
 * When this macro is used to set the sharpness parameter of upscaling, the value of `param` passed to the API must be
 * a valid pointer pointing to a float value. Otherwise, undefined behavior will occur, for example, the rendering
 * effect is incorrect or the program crashes.
 * This parameter is optional, and the default value 0.2 will be used if the sharpness parameter is not set.
 *
 * @since 5.0.0(12)
 */
#define XEG_NEURAL_UPSCALE_SHARPNESS 0x2U

 /**
 * @brief Sets the OH_NativeBuffer handle associated with the upscaling input texture through the
 * {@link HMS_XEG_NeuralUpscaleParameter} API.
 *
 * When this macro is used to set the upscaling input parameter, the value of `param` passed to the API must be a valid
 * OH_NativeBuffer handle corresponding to the inputTexture parameter passed to the {@link HMS_XEG_RenderNeuralUpscale}
 * API. Otherwise, undefined behavior will occur, for example, the rendering effect is incorrect or the program
 * crashes.
 * This parameter is mandatory.
 *
 * @since 5.0.0(12)
 */
#define XEG_NEURAL_UPSCALE_INPUT_HANDLE 0x4U

 /**
 * @brief Defines the function pointer for setting the AI spatial upscaling input parameter.
 *
 * @param pname Enumerated name of the input parameter. The value can be {@link XEG_NEURAL_UPSCALE_SCISSOR},
 * {@link XEG_NEURAL_UPSCALE_SHARPNESS}, or {@link XEG_NEURAL_UPSCALE_INPUT_HANDLE}.
 * @param param Input parameter value. For details, see the description of the enumerated names of the input
 * parameters.
 * @since 5.0.0(12)
 */
typedef void (GL_APIENTRYP PFN_HMS_XEG_NEURALUPSCALEPARAMETER)(GLenum pname, GLvoid *param);

/**
 * @brief Defines the function pointer for executing the AI spatial upscaling rendering command.
 *
 * @param inputTexture The input texture.
 * The texture type must be GL_TEXTURE_2D, and there is only 1 mipLevel. The valid value range of the input image
 * width is [448, 1728], Otherwise, the AI inference result may be incorrect. The input texture must be created by
 * OH_NativeBuffer. Before calling this API, you need to set the handle corresponding to OH_NativeBuffer as the
 * upscaling input parameter. For details, see the {@link HMS_XEG_NeuralUpscaleParameter} API.
 * @since 5.0.0(12)
 */
typedef void (GL_APIENTRYP PFN_HMS_XEG_RENDERNEURALUPSCALE)(GLuint inputTexture);

 /**
 * @brief Sets the AI spatial upscaling input parameter.
 *
 * @param pname Enumerated name of the input parameter. The value can be {@link XEG_NEURAL_UPSCALE_SCISSOR},
 * {@link XEG_NEURAL_UPSCALE_SHARPNESS}, or {@link XEG_NEURAL_UPSCALE_INPUT_HANDLE}.
 * @param param Input parameter value. For details, see the description of the enumerated names of the input
 * parameters.
 * @since 5.0.0(12)
 */
GL_APICALL void GL_APIENTRY HMS_XEG_NeuralUpscaleParameter(GLenum pname, GLvoid *param);

/**
 * @brief Executes the AI spatial upscaling rendering command.
 *
 * @param inputTexture The input texture.
 * The texture type must be GL_TEXTURE_2D, and there is only 1 mipLevel. The valid value range of the input image
 * width is [448, 1728], Otherwise, the AI inference result may be incorrect. The input texture must be created by
 * OH_NativeBuffer. Before calling this API, you need to set the handle corresponding to OH_NativeBuffer as the
 * upscaling input parameter. For details, see the {@link HMS_XEG_NeuralUpscaleParameter} API.
 * @since 5.0.0(12)
 */
GL_APICALL void GL_APIENTRY HMS_XEG_RenderNeuralUpscale(GLuint inputTexture);


#ifdef __cplusplus
}
#endif
/** @} */
#endif // XEG_GLES_NEURAL_UPSCALE_H
