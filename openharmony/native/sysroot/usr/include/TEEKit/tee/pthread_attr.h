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
 * @file pthread_attr.h
 *
 * @brief Provides the attr about TA multi-thread.
 *
 * @library NA
 * @kit TEEKit
 * @syscap SystemCapability.Tee.TeeClient
 * @since 20
 */

#ifndef PTHREAD_ATTR_H
#define PTHREAD_ATTR_H

#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines that the thread attribute of ca is not explicitly set (wildcard/default state).
 *
 * @since 20
 */
#define TEESMP_THREAD_ATTR_CA_WILDCARD 0

/**
 * @brief Defines that the thread attribute of ca inherit from the parent thread.
 *
 * @since 20
 */
#define TEESMP_THREAD_ATTR_CA_INHERIT (-1U)

/**
 * @brief Defines that the task ID attribute inherit from the parent task/thread.
 *
 * @since 20
 */
#define TEESMP_THREAD_ATTR_TASK_ID_INHERIT (-1U)

/**
 * @brief Defines that the thread attribute has a shadow.
 *
 * @since 20
 */
#define TEESMP_THREAD_ATTR_HAS_SHADOW 0x1

/**
 * @brief Defines that the thread attribute does not have a shadow.
 *
 * @since 20
 */
#define TEESMP_THREAD_ATTR_NO_SHADOW 0x0

/**
 * @brief Sets thread attributes for CA, task ID, and shadow settings.
 *
 * @param a Pointer to the thread attribute object to be modified.
 * @param ca Specifies the CA attribute value (e.g., TEESMP_THREAD_ATTR_CA_INHERIT for inheritance).
 * @param task_id Specifies the task ID attribute value (e.g., TEESMP_THREAD_ATTR_TASK_ID_INHERIT for inheritance).
 * @param shadow Indicates whether to enable shadow settings (TEESMP_THREAD_ATTR_NO_SHADOW 0x0 for no shadow,
 *              TEESMP_THREAD_ATTR_HAS_SHADOW 0x1 for has shadow).
 *
 * @return always return 0.
 *
 * @since 20
 */
int pthread_attr_settee(pthread_attr_t *a, int ca, int task_id, int shadow);

#ifdef __cplusplus
}
#endif

#endif
/** @} */