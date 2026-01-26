/*
 * Copyright (c) 2025 Huawei Device Co., Ltd.
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
 * @addtogroup i18n
 * @{
 *
 * @brief Provides internationalization APIs for application localization, and relies on libohi18n.z.so when used.
 * @since 22
 */

/**
 * @file errorcode.h
 *
 * @brief The error code in i18n.
 *
 * @library libohi18n.so
 * @kit LocalizationKit
 * @syscap SystemCapability.Global.I18n
 * @since 22
 */

#ifndef GLOBAL_I18N_ERRORCODE_H
#define GLOBAL_I18N_ERRORCODE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief error codes of i18n
 * @since 22
 */
typedef enum I18n_ErrorCode {
    /** @error Success*/
    SUCCESS = 0,

    /** @error Invalid input parameter */
    ERROR_INVALID_PARAMETER = 8900001,

    /** @error Unexpected error, such as memory error. */
    UNEXPECTED_ERROR = 8900050,
} I18n_ErrorCode;

#ifdef __cplusplus
};
#endif
#endif // GLOBAL_I18N_ERRORCODE_H

/** @} */