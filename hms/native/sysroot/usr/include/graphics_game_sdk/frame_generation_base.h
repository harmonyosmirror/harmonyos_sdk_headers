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
 * @file frame_generation_base.h
 * @kit GraphicsAccelerateKit
 *
 * @brief Defines the graphic-platform-insensitive APIs for Frame Generation.
 *
 * Defines the graphic-platform-insensitive structure and enumration for Frame Generation.
 *
 * @library libframegeneration.so
 * @syscap SystemCapability.GraphicsGame.RenderAccelerate
 * @since 5.0.0(12)
 */

#ifndef FRAME_GENERATION_BASE_H
#define FRAME_GENERATION_BASE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines the column-major 4x4 matrices.
 * @since 5.0.0(12)
 */
typedef struct FG_Mat4x4 {
    /**
     * The raw data of 4x4 matrices are mapped to the C++ memory the following way:
     *     |a11 a12 a13 a14|
     * A = |a21 a22 a23 a24|
     *     |a31 a32 a33 a34|
     *     |a41 a42 a43 a44|
     * data[16] = {a11, a21, a31, a41, a12, a22, a32, a42, a13, a23, a33, a43, a14, a24, a34, a44};
     */
    float data[16U];
} FG_Mat4x4;

/**
 * @brief Defines the Vector3 struct for Frame Generation.
 * @since 5.0.0(12)
 */
typedef struct FG_Vec3D {
    /** The x-axis coordinate of a 3D vector. */
    float x;
    /** The y-axis coordinate of a 3D vector. */
    float y;
    /** The z-axis coordinate of a 3D vector. */
    float z;
} FG_Vec3D;

/**
 * @brief Defines prediction algorithm mode of frame generation including Interpolation and Extrapolation modes.
 * @since 5.0.0(12)
 */
typedef enum FG_PredictionMode {
    /**
     * Frame interpolation prediction mode, which predicts from several past and one future frame into the past frame.
     * It is suitable for games which prefer better rendering effect, such as RPG and Racing Games.
     */
    FG_PREDICTION_MODE_INTERPOLATION = 0,
    /**
     * Frame extrapolation prediction mode, which predicts from several past frames into the future frame.
     * It is suitable for games which prefer less touch lantency, such as Action, FPS and Skill Games.
     */
    FG_PREDICTION_MODE_EXTRAPOLATION = 1
} FG_PredictionMode;

/**
 * @brief Defines motion vector estimation algorithm mode of frame generation including Basic and Enhanced modes.
 * @since 5.0.0(12)
 */
typedef enum FG_MeMode {
    /**
     * Basic motion estimation algorithm which calcuate MVs with Scene Color, Depth Stencil, viewProj and invViewProj
     * matrix.
     */
    FG_ME_MODE_BASIC = 0,
    /**
     * Enhanced motion estimation algorithm which calcuates MVs with not only inputs of {@link FG_ME_MODE_BASIC},
     * but vertex data in the game scene. This mode could achieve better frame generation effects.
     * Before choosing this mode, you are required to do additional marking in order to record vertex.
     */
    FG_ME_MODE_ENHANCED = 1
} FG_MeMode;

/**
 * @brief Defines Frame Generation algorithm mode information.
 * @since 5.0.0(12)
 */
typedef struct FG_AlgorithmModeInfo {
    /** Prediction algorithm mode of Frame Generation. */
    FG_PredictionMode predictionMode;
    /** Motion vector estimation algorithm mode of Frame Generation. */
    FG_MeMode meMode;
} FG_AlgorithmModeInfo;

/**
 * @brief Defines error codes for Frame Generation APIs.
 * @since 5.0.0(12)
 */
typedef enum FG_ErrorCode {
    /** The operation is successful. */
    FG_SUCCESS = 0,
    /** Invalid parameter. */
    FG_INVALID_PARAMETER = 401,
    /** The context is not configured when activate. */
    FG_CONTEXT_NOT_CONFIG = 1009500001,
    /** The context is not active when dispatch. */
    FG_CONTEXT_NOT_ACTIVE = 1009500002,
    /**
     * Predicted frame will begin to draw after third supplied frames, which called warm up period.
     * Before expected number of frames are supplied, {@link HMS_FG_Dispatch_GLES} function returns
     * {@link FG_COLLECTING_PREVIOUS_FRAMES} instead of {@link FG_SUCCESS}.
     * In this case, outputColor texture can not be updated, which should not be used for display.
     */
    FG_COLLECTING_PREVIOUS_FRAMES = 1009500003
} FG_ErrorCode;

/**
 * @brief Defines projection matrix outputs Z/W range and depth test compasion function.
 * @since 5.0.0(12)
 */
typedef enum FG_CvvZSemantic {
    /**
     * Projection matrix outputs Z/W are in [-1..1] range without any adjusting.
     * This is useful if projection matrix is assuming GL-like clip space.
     * Depth test is done with "less [or equal]" comparison function.
     */
    FG_CVV_Z_SEMANTIC_MINUS_ONE_TO_ONE_FORWARD_Z = 0,

    /**
     * Projection matrix outputs Z/W are in [0..1] range and then
     * manually adjusted to [-1..1] NDC range required by GL.
     * This is useful if projection matrix is assuming DirectX-like clip space.
     * Depth test is done with "greater [or equal]" comparison function.
     */
    FG_CVV_Z_SEMANTIC_ZERO_TO_ONE_REVERSE_Z = 1,

    /**
     * Same as FG_CVV_Z_SEMANTIC_MINUS_ONE_TO_ONE_FORWARD_Z, but depth
     * test is done with "greater [or equal]" comparison function.
     */
    FG_CVV_Z_SEMANTIC_MINUS_ONE_TO_ONE_REVERSE_Z = 2,

    /**
     * Same as FG_CVV_Z_SEMANTIC_ZERO_TO_ONE_REVERSE_Z, but depth
     * test is done with "less [or equal]" comparison function.
     */
    FG_CVV_Z_SEMANTIC_ZERO_TO_ONE_FORWARD_Z = 3
} FG_CvvZSemantic;

/**
 * @brief Defines the resolution in pixels of an image.
 * @since 5.0.0(12)
 */
typedef struct FG_Dimension2D {
    /** Width in pixels of an image. */
    uint32_t width;
    /** Height in pixels of an image. */
    uint32_t height;
} FG_Dimension2D;

/**
 * @brief Defines the resolution in pixels of frame generation input and output images.
 * @since 5.0.0(12)
 */
typedef struct FG_ResolutionInfo {
    /** Resolution in pixels of opaque scene color information. */
    FG_Dimension2D inputColorResolution;
    /**
     * Resolution in pixels of depth/stencil texture with scene information.
     * Can be set to zero if not used, or when same as {@link inputColorResolution}.
     */
    FG_Dimension2D inputDepthStencilResolution;
    /**
     * Resolution in pixels of the final predicted frame.
     * Can be set to zero when same as {@link inputColorResolution}.
     */
    FG_Dimension2D outputColorResolution;
} FG_ResolutionInfo;

/**
 * @brief Defines the extended camera information. In cases where the translation component of view-projection
 * matrices may be very large, more detailed camera information can be provided to get more precise predicted
 * effects.
 * @since 5.0.0(12)
 */
typedef struct FG_PerFrameExtendedCameraInfo {
    /**
     * Projection matrix corresponds to transformation from view-space coordinates to clip-space coordinates.
     */
    FG_Mat4x4 proj;
    /**
     * Inverse matrix from {@link translatedViewProj}.
     * Corresponds to transformation from clip-space coordinates to camera-centered world-space coordinates.
     */
    FG_Mat4x4 translatedInvViewProj;
    /**
     * Translated view matrix. See {@link translatedViewProj}.
     * Corresponds to transformation from camera-centered world-space coordinates to view-space coordinates.
     */
    FG_Mat4x4 translatedView;
    /**
     * Translated view-projection matrix.
     * Corresponds to transformation from camera-centered world-space coordinates to clip-space coordinates.
     */
    FG_Mat4x4 translatedViewProj;
    /** Translation of the camera relative to origin of world coordinates. */
    FG_Vec3D worldPosition;
} FG_PerFrameExtendedCameraInfo;

#ifdef __cplusplus
}
#endif  // __cplusplus

/** @} */
#endif  // FRAME_GENERATION_BASE_H