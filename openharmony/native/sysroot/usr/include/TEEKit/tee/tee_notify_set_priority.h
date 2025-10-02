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
 * @file tee_notify_set_priority.h
 *
 * @brief Provides API for setting shadow threads' priority.
 *
 * @library NA
 * @kit TEEKit
 * @syscap SystemCapability.Tee.TeeClient
 * @since 20
 */

#ifndef TEE_NOTIFY_SET_PRIORITY_H
#define TEE_NOTIFY_SET_PRIORITY_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Support setting the priority of the shadow thread
 *
 * @param priority_ree [IN] priority of the shadow thread
 *
 * @return <b>0</b> success
 * @return <b>TEE_ERROR_ACCESS_DENIED</b> do NOT have access right (thread without shadow-thread flag)
 * @return <b>TEE_ERROR_BAD_PARAMETERS</b> invalid value of priority_ree
 * @return <b>-1</b> set priority fail
 *
 * @since 20
 */
int spi_notify_set_shadow_priority(uint32_t priority_ree);

#ifdef __cplusplus
}
#endif

#endif
/** @} */