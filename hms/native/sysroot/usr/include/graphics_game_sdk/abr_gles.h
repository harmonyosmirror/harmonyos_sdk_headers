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
 * @file abr_gles.h
 *
 * @brief  Defines the APIs of ABR dedicated to the OpenGL ES platform.
 *
 * @kit GraphicsAccelerateKit
 * @library libabr.so
 * @Syscap SystemCapability.GraphicsGame.RenderAccelerate
 * @since 5.0.0(12)
 */
#ifndef ABR_GLES_H
#define ABR_GLES_H

#include <stdbool.h>
#include "abr_base.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Mark GLES Buffer for ABR context instance.
 *
 * This method is used to mark the binded GLES Buffer, and needs to be invoked before buffer rendering.
 *
 * @param [in] context Pointer to {@link ABR_Context}. The value cannot be null.
 * @return Function execution result. Returns ABR_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link ABR_ErrorCode}.
 * @since 5.0.0(12)
 */
ABR_ErrorCode HMS_ABR_MarkFrameBuffer_GLES(ABR_Context* context);

/**
 * @brief Get ABR scaled texture corresponding to the original texture for ABR context instance.
 *
 * This method is used to get ABR scaled texture corresponding to the original texture.
 *
 * @param [in] context Pointer to {@link ABR_Context}. The value cannot be null.
 * @param [in] originTexture   The original texture.
 * @param [out] scaledTexture  The ABR scaled texture corresponding to the original texture.
 * @return Function execution result. Returns ABR_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link ABR_ErrorCode}.
 * @since 5.0.0(12)
 */
ABR_ErrorCode HMS_ABR_GetScaledTexture_GLES(ABR_Context* context, uint32_t originTexture, uint32_t* scaledTexture);

#ifdef __cplusplus
}
#endif

/** @} */
#endif // ABR_GLES_H