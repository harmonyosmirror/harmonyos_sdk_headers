/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

/**
 * @addtogroup GraphicsAccelerate
 * @{
 *
 * @brief Provides APIs for graphics accelerate capability.
 *
 * @Syscap SystemCapability.GraphicsGame.RenderAccelerate
 * @since 5.0.0(12)
 */

/**
 * @file frame_generation_gles.h
 * @kit GraphicsAccelerateKit
 *
 * @brief Defines the APIs of Frame Generation dedicated to the OpenGL ES API platform.
 *
 * Allows you to create Frame Generaion context on OpenGL ES platform, configure context attributes,
 * activate context, deactivate context, draw predicted frames with dispatch Info and destroy context instance.
 *
 * @library libframegeneration.so
 * @syscap SystemCapability.GraphicsGame.RenderAccelerate
 * @since 5.0.0(12)
 */

#ifndef FRAME_GENERATION_GLES_H
#define FRAME_GENERATION_GLES_H

#include <stdbool.h>
#include "frame_generation_base.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Frame Generation context on OpenGL ES platform.
 * @since 5.0.0(12)
 */
struct FG_Context_GLES;
typedef struct FG_Context_GLES FG_Context_GLES;

/**
 * @brief Defines Frame Generation dispatch info struct which specifies the required attributes to predict frames,
 * only for OpenGL ES platform.
 * @since 5.0.0(12)
 */
typedef struct FG_DispatchDescription_GLES {
    /** GL handle for texture with opaque scene color information. */
    uint32_t inputColor;
    /** GL handle for depth/stencil texture with scene information. */
    uint32_t inputDepthStencil;
    /**
     * Composite view-projection matrix which was used for rendering opaque scene.
     * Corresponding to transformation from world-space coordinates to clip-space coordinates.
     */
    FG_Mat4x4 viewProj;
    /**
     * Inverse matrix from {@link viewProj}.
     * Corresponds to transformation from clip-space coordinates to world-space coordinates.
     */
    FG_Mat4x4 invViewProj;
    /** GL handle of the resource which will hold predicted frame. */
    uint32_t outputColor;
} FG_DispatchDescription_GLES;

/**
 * @brief Defines image format of input scene color and final predicted frame.
 * @since 5.0.0(12)
 */
typedef enum FG_ImageFormat_GLES {
    /** GL_RGBA8 image format. */
    FG_FORMAT_R8G8B8A8_UNORM = 0,
    /** GL_R11F_G11F_B10F image format. */
    FG_FORMAT_R11G11B10_SFLOAT = 1,
    /** GL_RGBA16F image format. */
    FG_FORMAT_R16G16B16A16_SFLOAT = 2
} FG_ImageFormat_GLES;

/**
 * @brief Creates the frame generation context instance on OpenGL ES platform. The context structure is the main object
 * used to interact with Frame Generation APIs, and is reponsible for the management of the internal resources used by
 * the Frame Generation algorithm.
 *
 * @return Returns the pointer to a {@link FG_Context_GLES} context instance.
 * @since 5.0.0(12)
 */
FG_Context_GLES* HMS_FG_CreateContext_GLES(void);

/**
 * @brief Provide the selection of the prediction mode and motion vector estimation mode of Frame Generation.
 *
 * @param [in] context Pointer to the {@link FG_Context_GLES} instance. The value can not be null. Otherwise, an error
 * code is returned.
 * @param [in] predictionModeInfo Pointer to the {@link FG_AlgorithmModeInfo} instance. The object specifies prediction
 * mode and motion vector estimation mode. The value can not be null. Otherwise, an error code is returned.
 * @return Execution result of the function. If the operation is successful, <b>FG_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_SetAlgorithmMode_GLES(FG_Context_GLES* context, const FG_AlgorithmModeInfo* predictionModeInfo);

/**
 * @brief Provide the resolution in pixels of frame generation input and output images.
 *
 * @param [in] context Pointer to the {@link FG_Context_GLES} instance. The value can not be null. Otherwise, an error
 * code is returned.
 * @param [in] resolutionInfo Pointer to the {@link FG_ResolutionInfo} instance. The object specifies the resolution
 * in pixels of frame generation input and output images. The value can't be null. Otherwise, an error code is returned.
 * @return Execution result of the function. If the operation is successful, <b>FG_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_SetResolution_GLES(FG_Context_GLES* context, const FG_ResolutionInfo* resolutionInfo);

/**
 * @brief Provide the Z range semantic of projection matrix used by application.
 *
 * @param [in] context Pointer to the {@link FG_Context_GLES} instance. The value can not be null. Otherwise, an error
 * code is returned.
 * @param [in] semantic One of the enumeration values.
 * @return Execution result of the function. If the operation is successful, <b>FG_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_SetCvvZSemantic_GLES(FG_Context_GLES* context, FG_CvvZSemantic semantic);

/**
 * @brief Provide frame generation input scene color format.
 *
 * @param [in] context Pointer to the {@link FG_Context_GLES} instance. The value can not be null. Otherwise, an error
 * code is returned.
 * @param [in] format One of the scene color format values, the same with final predicted frame.
 * @return Execution result of the function. If the operation is successful, <b>FG_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_SetImageFormat_GLES(FG_Context_GLES* context, FG_ImageFormat_GLES format);

/**
 * @brief This should be called when color buffer is Y axis inverted relative to Depth/Stencil buffer.
 *
 * @param [in] context Pointer to the {@link FG_Context_GLES} instance. The value can not be null. Otherwise, an error
 * code is returned.
 * @param [in] inverted The value is 'true' when color buffer is Y axis inverted relative to Depth/Stencil buffer.
 * @return Execution result of the function. If the operation is successful, <b>FG_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_SetDepthStencilYDirectionInverted_GLES(FG_Context_GLES* context, bool inverted);

/**
 * @brief Activate Frame Generation instance on OpenGL ES platform. An "activated" instance is ready to draw frames.
 * In order to activate it, some set functions must be called. In case of any errors,
 * the instance is considered to be inactive.
 *
 * @param [in] context Pointer to the {@link FG_Context_GLES} instance. The value cannot be null.
 * Otherwise, an error code is returned.
 * @return Execution result of the function. If the operation is successful, <b>FG_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_Activate_GLES(FG_Context_GLES* context);

/**
 * @brief Deactivate Frame Generation instance on OpenGL ES platform.
 *
 * @param [in] context  Pointer to the {@link FG_Context_GLES} instance. The value cannot be null.
 * Otherwise, an error code is returned.
 * @return Execution result of the function. If the operation is successful, <b>FG_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_Deactivate_GLES(FG_Context_GLES* context);

/**
 * @brief Query if the frame generation instance is currently activated.
 *
 * @param [in]  context Pointer to the {@link FG_Context_GLES} instance.
 * @param [out] isActive Active status of {@link FG_Context_GLES} instance.
 * 'true' : instance is activated;
 * 'false' : instance is deactivated.
 * @return Execution result of the function. If the operation is successful, <b>FG_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_IsActive_GLES(FG_Context_GLES* context, bool* isActive);

/**
 * @brief Provide the extended camera information in cases where the translation component of view-projection
 * matrices may be very large, in order to get more precise predicted effects.
 *
 * @param [in] context Pointer to the {@link FG_Context_GLES} instance.
 * @param [in] info Pointer to the {@link FG_PerFrameExtendedCameraInfo} instance.
 * @return Execution result of the function. If the operation is successful, <b>FG_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_SetExtendedCameraInfo_GLES(FG_Context_GLES* context, const FG_PerFrameExtendedCameraInfo* info);

/**
 * @brief Sets all required data for prediction of a frame to draw predicted frames on OpenGL ES platform.
 *
 * @param [in] context Pointer to the {@link FG_Context_GLES} instance. The value can not be null.
 * @param [in] desc Pointer to the {@link FG_DispatchDescription_GLES}. The object specifies the dispatch attributes
 * used by executing frame prediction. The value can not be null.
 * @return Function execution result. If the operation is successful, FG_SUCCESS is returned. If the operation fails,
 * an error code is returned. For details about the error codes, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_Dispatch_GLES(FG_Context_GLES* context, const FG_DispatchDescription_GLES* desc);

/**
 * @brief Destroy Frame Generation instance and memory resource reclamation on OpenGL ES platform.
 *
 * @param [in] context Level-2 pointer to the {@link FG_Context_GLES} instance to destroy.
 * @return Execution result of the function. If the operation is successful, <b>FG_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_DestroyContext_GLES(FG_Context_GLES** context);

#ifdef __cplusplus
};
#endif // __cplusplus

/** @} */
#endif // FRAME_GENERATION_GLES_H