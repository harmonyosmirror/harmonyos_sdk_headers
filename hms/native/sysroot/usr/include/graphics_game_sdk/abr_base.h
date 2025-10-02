/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

/**
 * @addtogroup GraphicsAccelerate
 * @{
 *
 * @brief Provides APIs for Graphics Accelerate capability.
 *
 * @Syscap SystemCapability.GraphicsGame.RenderAccelerate
 * @since 5.0.0(12)
 */

/**
 * @file abr_base.h
 *
 * @brief Defines the graphic-platform-insensitive APIs for ABR (Adaptive Buffer Resolution).
 *
 * Allows you to create ABR context, configure context attributes, activate context,
 * deactivate context, query context activated status and destroy context instance.
 *
 * @kit GraphicsAccelerateKit
 * @library libabr.so
 * @Syscap SystemCapability.GraphicsGame.RenderAccelerate
 * @since 5.0.0(12)
 */

#ifndef ABR_BASE_H
#define ABR_BASE_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief ABR context.
 * @since 5.0.0(12)
 */
struct ABR_Context;
typedef struct ABR_Context ABR_Context;

/**
 * @brief Defines graphics API types.
 * @since 5.0.0(12)
 */
typedef enum ABR_RenderAPI_Type {
    /** OpenGL ES API */
    RENDER_API_GLES = 0
} ABR_RenderAPI_Type;

/**
 * @brief Defines the Vector3 struct for ABR
 * @since 5.0.0(12)
 */
typedef struct ABR_Vector3 {
    /** The x-axis coordinate of a 3D vector. */
    float x;
    /** The y-axis coordinate of a 3D vector. */
    float y;
    /** The z-axis coordinate of a 3D vector. */
    float z;
} ABR_Vector3;

/**
 * @brief Defines the Camera motion data of game used by ABR to dynamically calculate scale factor
 * @since 5.0.0(12)
 */
typedef struct ABR_CameraData {
    /** Camera rotation Euler angles per frame. The Euler angle value range is [0, 360] */
    ABR_Vector3 rotation;
    /** Camera position per frame. */
    ABR_Vector3 position;
} ABR_CameraData;

/**
 * @brief Defines error codes for ABR APIs.
 * @since 5.0.0(12)
 */
typedef enum ABR_ErrorCode {
    /** The operation is successful. */
    ABR_SUCCESS = 0,
    /** Invalid parameter. */
    ABR_INVALID_PARAMETER = 401,
    /** The context is configured on activation status. */
    ABR_CONTEXT_CONFIG_AFTER_ACTIVE = 1009501001,
    /** The context is not configured when activate. */
    ABR_CONTEXT_NOT_CONFIG = 1009501002,
    /** The ABR context instance is not activated when render. */
    ABR_CONTEXT_NOT_ACTIVE = 1009501003,
    /** The metadata for ABR is invalid. */
    ABR_METADATA_INVALID = 1009501004,
    /** The framebuffer marked for ABR is invalid. */
    ABR_FRAMEBUFFER_INVALID = 1009501005
} ABR_ErrorCode;

/**
 * @brief Creates a ABR context instance. The context structure is the main object used to interact with
 * ABR APIs, and is reponsible for the management of the internal resources used by the ABR.
 *
 * This method is used to create a ABR context instance. If {@link ABR_Context} not been used,
 * call {@link HMS_ABR_DestroyContext} to release the pointer. Otherwise, memory leak may occur.
 *
 * @param [@link ABR_RenderAPI_Type] Render API type.
 * @return Returns the pointer to {@link ABR_Context} if the operation is successful; returns a null pointer otherwise.
 * @see HMS_ABR_DestroyContext
 * @since 5.0.0(12)
 */
ABR_Context* HMS_ABR_CreateContext(ABR_RenderAPI_Type type);

/**
 * @brief Configures target framerate of ABR context instance for initialing.
 *
 *  This method is used to configure target framerate for ABR context instance.
 *
 * @param [in] context Pointer to {@link ABR_Context}. The value cannot be null.
 * @param [in] targetFps  Target framerate of the ABR context instance. The value range is [30, 120].
 * @return Function execution result. Returns ABR_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link ABR_ErrorCode}.
 * @since 5.0.0(12)
 */
ABR_ErrorCode HMS_ABR_SetTargetFps(ABR_Context* context, const uint32_t targetFps);

/**
 * @brief Configures scale factor range of ABR context instance for initialing.
 *
 *  This method is used to configure scale factor range for ABR context instance.
 *  Only one set of scale factor range can be set in the lifecycle of ABR context.
 *
 * @param [in] context Pointer to {@link ABR_Context}. The value cannot be null.
 * @param [in] minValue  Minimum scale factor of the ABR context instance. The value range is [0.5, 1.0].
 * @param [in] maxValue  Maximum scale factor of the ABR context instance. The value range is [0.5, 1.0].
 * @return Function execution result. Returns ABR_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link ABR_ErrorCode}.
 * @since 5.0.0(12)
 */
ABR_ErrorCode HMS_ABR_SetScaleRange(ABR_Context* context, const float minValue, const float maxValue);

/**
 * @brief Activates ABR context instance.
 *
 * This method is used to activate ABR context instance. In order to activate it, {@link HMS_ABR_SetTargetFps}
 * and {@link HMS_ABR_SetScaleRange} must be called. In case of any errors, the instance is considered to be inactive.
 *
 * @param [in] context Pointer to {@link ABR_Context}. The value cannot be null.
 * @return Function execution result. Returns ABR_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link ABR_ErrorCode}.
 * @since 5.0.0(12)
 */
ABR_ErrorCode HMS_ABR_Activate(ABR_Context* context);

/**
 * @brief Checks whether ABR context instance is activated.
 *
 * This method is used to check whether ABR context instance is activated.
 *
 * @param [in]  context   Pointer to {@link ABR_Context}. The value cannot be null.
 * @param [out] isActive  Returns true if ABR context instance is active; returns false otherwise.
 * @return Function execution result. Returns ABR_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link ABR_ErrorCode}.
 * @since 5.0.0(12)
 */
ABR_ErrorCode HMS_ABR_IsActive(ABR_Context* context, bool* isActive);

/**
 * @brief Deactivates ABR context instance.
 *
 * This method is used to deactivate ABR context instance.
 *
 * @param [in] context Pointer to {@link ABR_Context}. The value cannot be null.
 * @return Function execution result. Returns ABR_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link ABR_ErrorCode}.
 * @since 5.0.0(12)
 */
ABR_ErrorCode HMS_ABR_Deactivate(ABR_Context* context);

/**
 * @brief Updates camera motion data for ABR context instance.
 *
 * This method is used to update camera motion data of game for ABR context instance.
 * Camera motion data of game is used by ABR to dynamically calculate scale factor.
 *
 * @param [in] context Pointer to {@link ABR_Context}. The value cannot be null.
 * @param [in] data    Camera motion data {@link ABR_CameraData} of per frame. If the value is null, ABR
 * cannot use the camera motion data of the current frame to calculate the scaling factor.
 * @return Function execution result. Returns ABR_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link ABR_ErrorCode}.
 * @since 5.0.0(12)
 */
ABR_ErrorCode HMS_ABR_UpdateCameraData(ABR_Context* context, ABR_CameraData* data);

/**
 * @brief Gets latest scale factor of ABR context instance.
 *
 * This method is used to get latest scale factor used by ABR context instance.
 *
 * @param [in] context Pointer to {@link ABR_Context}. The value cannot be null.
 * @param [out] scale  The latest scale factor used by ABR context instance.
 * @return Function execution result. Returns ABR_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link ABR_ErrorCode}.
 * @since 5.0.0(12)
 */
ABR_ErrorCode HMS_ABR_GetScale(ABR_Context* context, float* scale);

/**
 * @brief Gets scale factor of next frame of ABR context instance.
 *
 * This method is used to get scale factor of next frame used by ABR context instance.
 *
 * @param [in] context Pointer to {@link ABR_Context}. The value cannot be null.
 * @param [out] scale  The scale factor of next frame used by ABR context instance.
 * @return Function execution result. Returns ABR_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link ABR_ErrorCode}.
 * @since 5.0.0(12)
 */
ABR_ErrorCode HMS_ABR_GetNextScale(ABR_Context* context, float* scale);

/**
 * @brief Releases the ABR context instance.
 *
 * This method is used to release {@link ABR_Context} created by using {@link HMS_ABR_CreateContext}.
 *
 * @param [in] context Pointer to {@link ABR_Context}. The value cannot be null.
 * @return Function execution result. Returns ABR_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link ABR_ErrorCode}.
 * @since 5.0.0(12)
 */
ABR_ErrorCode HMS_ABR_DestroyContext(ABR_Context** context);

#ifdef __cplusplus
}
#endif

/** @} */
#endif // ABR_BASE_H