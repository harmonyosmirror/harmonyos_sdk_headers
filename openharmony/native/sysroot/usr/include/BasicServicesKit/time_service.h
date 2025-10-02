/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TIME_SERVICE_H
#define TIME_SERVICE_H

/**
 * @addtogroup TimeService
 * @{
 *
 * @brief Declares the time zone capabilities provided by TimeService to an application.
 * @since 12
 */
/**
 * @file time_service.h
 *
 * @brief Declares the APIs for obtaining the time zone information.
 * @library libtime_service_ndk.so
 * @syscap SystemCapability.MiscServices.Time
 * @since 12
 */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates the error codes.
 *
 * @since 12
 */
typedef enum TimeService_ErrCode {
    /** @error Success.*/
    TIMESERVICE_ERR_OK = 0,

    /** @error Failed to obtain system parameters.*/
    TIMESERVICE_ERR_INTERNAL_ERROR = 13000001,

    /** @error Invalid parameter.*/
    TIMESERVICE_ERR_INVALID_PARAMETER = 13000002,
} TimeService_ErrCode;

/**
 * @brief Obtains the current system time zone.
 *
 * @param timeZone Pointer to an array of characters indicating the time zone ID. On success, the string indicates the
 *        current system time zone ID. On failure, the string is empty. The string is terminated using '\0'.
 * @param len Size of the memory allocated for the time zone ID character array. There is no upper limit for the length
 *        of the time zone ID. It is recommended to allocate sufficient memory, at least not less than 31 bytes.
 * @return Returns {@link TIMESERVICE_ERR_OK} if the operation is successful.
 *         Returns {@link TIMESERVICE_ERR_INTERNAL_ERROR} if obtaining the system parameters fails.
 *         Returns {@link TIMESERVICE_ERR_INVALID_PARAMETER} if <b>timeZone</b> is a null pointer or the length of the
 *         time zone ID (excluding the terminating character ('\0')) is greater than or equal to <b>len</b>.
 * @syscap SystemCapability.MiscServices.Time
 * @since 12
 */
TimeService_ErrCode OH_TimeService_GetTimeZone(char *timeZone, uint32_t len);

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* TIME_SERVICE_H */