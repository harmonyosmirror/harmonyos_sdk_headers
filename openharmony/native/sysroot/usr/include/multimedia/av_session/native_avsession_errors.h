/*
 * Copyright (C) 2024 Huawei Device Co., Ltd.
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

/**
 * @addtogroup OHAVSession
 * @{
 *
 * @brief Provide the definition of the C interface for the avsession module.
 * @since 13
 */

/**
 * @file native_avsession_errors.h
 *
 * @brief Declare avsession related error.
 *
 * @library libohavsession.so
 * @syscap SystemCapability.Multimedia.AVSession.Core
 * @kit AVSessionKit
 * @since 13
 */

#ifndef NATIVE_AVSESSION_ERRORS_H
#define NATIVE_AVSESSION_ERRORS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief AVSession error code
 *
 * @since 13
 * @version 1.0
 */
typedef enum {
    /**
     * @error The operation completed successfully.
     */
    AV_SESSION_ERR_SUCCESS = 0,

    /**
     * @error Invalid parameter。
     */
    AV_SESSION_ERR_INVALID_PARAMETER = 401,

    /**
     * @error Service exception.
     */
    AV_SESSION_ERR_SERVICE_EXCEPTION = 6600101,

    /**
     * @error The session does not exist.
     */
    AV_SESSION_ERR_CODE_SESSION_NOT_EXIST = 6600102,

    /**
     * @error Invalid session command.
     */
    AV_SESSION_ERR_CODE_COMMAND_INVALID = 6600105,

    /**
     * @error The session is not activated.
     */
    AV_SESSION_ERR_CODE_SESSION_INACTIVE = 6600106,

    /**
     * @error Too many commands or events.
     */
    AV_SESSION_ERR_CODE_MESSAGE_OVERLOAD = 6600107,
} AVSession_ErrCode;

#ifdef __cplusplus
}
#endif

#endif // NATIVE_AVSESSION_ERRORS_H
/** @} */