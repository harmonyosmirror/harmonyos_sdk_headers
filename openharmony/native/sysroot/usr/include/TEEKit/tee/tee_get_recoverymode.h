/*
 * Copyright (c) 2025 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License"),
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
 * @addtogroup TeeTrusted
 * @{
 *
 * @brief TEE(Trusted Excution Environment) API.
 * Provides security capability APIs such as trusted storage, encryption and decryption,
 * and trusted time for trusted application development.
 *
 * @since 20
 */

/**
 * @file tee_get_recoverymode.h
 *
 * @brief Provides APIs for getting boot mode.
 *
 * @library NA
 * @kit TEEKit
 * @syscap SystemCapability.Tee.TeeClient
 * @since 20
 */

#ifndef TEE_GET_RECOVERYMODE_H
#define TEE_GET_RECOVERYMODE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief  Enumerates the supported boot modes of the system.
 *
 * @since 20
 */
typedef enum {
    /** System is powered off or shutting down. */
    BOOT_MODE_SHUTDOWN = 0,
    /** Normal boot mode */
    BOOT_MODE_NORMAL,
    /** Fastboot boot mode. */
    BOOT_MODE_FASTBOOT,
    /** Recovery boot mode. */
    BOOT_MODE_RECOVERY,
    /** eRecovery mode. */
    BOOT_MODE_RECOVERY2,
    /** Maximum number of supported boot modes. */
    BOOT_MODE_CNT_MAX
} boot_modes;

/**
 * @brief Get current boot mode.
 *
 * @param recoverymode [OUT] Indicates current boot mode.
 *
 * @return Returns {@code TEE_SUCCESS} if the operation is successful.
 *         Returns {@code TEE_ERROR_BAD_PARAMETERS} if input parameter is incorrect.
 *
 * @since 20
 */
int32_t tee_ext_get_recoverymode(enum boot_modes *recoverymode);

#ifdef __cplusplus
}
#endif

#endif
/** @} */