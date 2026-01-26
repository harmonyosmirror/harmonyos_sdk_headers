/*
 * Copyright (c) 2025 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @addtogroup handwrite function
 * @{
 *
 * @brief Defines the functions of handwrite.
 *
 * @since 6.0.0(20)
 */

/**
 * @file native_handwrite_api.h
 * @kit Penkit
 *
 * @brief Defines the functions of handwrite.
 *
 * @library libhandwrite_ndk.z.so
 * @syscap SystemCapability.Stylus.Handwrite
 * @since 6.0.0(20)
 */

#ifndef NATIVE_HANDWRITE_API_H
#define NATIVE_HANDWRITE_API_H

#include "info/application_target_sdk_version.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines handwrite error code.
 * @since 6.0.0(20)
 */
typedef enum {
    /** @error Execution successful. */
    E_NO_ERROR = 0,
    /** @error Invalid input parameter. */
    E_PARAMS = 401,
    /** @error System inner error. */
    E_INNER_ERROR = 1010400001,
} Handwrite_ErrCode;

/**
 * @brief Defines the structure for the historical point information.
 * @since 6.0.0(20)
 */
typedef struct {
    /** X coordinate of the historical touch point relative to the left edge of the element to touch. */
    float x;
    /** Y coordinate of the historical touch point relative to the upper edge of the element to touch. */
    float y;
    /** Timestamp of the current historical touch event. */
    int64_t timeStamp;
    /** Pressure of the current historical touch event. */
    float force;
} HandWrite_HistoricalPoint;

/**
 * @brief Start get predict point.
 *
 * This API is used to get predict point.
 *
 * @param event Indicates the historical event points.
 * @param size Indicates the historical event points size.
 * @param predictPointX Indicates the predict point X.
 * @param predictPointY Indicates the predict point Y.
 * @return Returns if the operation is successful.
 * {@link E_NO_ERROR} 0 - Execution successful.
 * {@link E_PARAMS} 401 - Invalid input parameter.
 * {@link E_INNER_ERROR} 1010400001 - System inner error.
 * @since 6.0.0(20)
 */
int32_t HMS_HandWrite_GetPredictPoint(
    const HandWrite_HistoricalPoint* event, int32_t size, float *predictPointX, float *predictPointY)
    __attribute__((__availability__(ohos, introduced=20.0.0)));

#ifdef __cplusplus
}
#endif

#endif // NATIVE_HANDWRITE_API_H
/** @} */
