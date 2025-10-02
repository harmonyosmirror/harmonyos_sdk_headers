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
 * @file tee_agent.h
 *
 * @brief Provides the API about TA agent.
 *
 * @library NA
 * @kit TEEKit
 * @syscap SystemCapability.Tee.TeeClient
 * @since 20
 */

#ifndef TEE_AGENT_H
#define TEE_AGENT_H

#include <stdint.h>
#include <tee_defines.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief The TA sends a message to the gtask to lock the agent.
 *
 * @param agent_id ID of the agent that requests to be locked.
 *
 * @return Returns {@code TEE_SUCCESS} if the operation is successful.
 *         Returns other information otherwise.
  *
 * @since 20
 */
TEE_Result tee_agent_lock(uint32_t agent_id);

/**
 * @brief Unlock the agent.
 *
 * @param agent_id ID of the agent that requests to be unlocked.
 *
 * @return Returns {@code TEE_SUCCESS} if the operation is successful.
 *         Returns other information otherwise.
  *
 * @since 20
 */
TEE_Result tee_agent_unlock(uint32_t agent_id);

/**
 * @brief Send agent cmd to gtask.
 *
 * @param agent_id The agent ID.
 *
 * @return Returns {@code TEE_SUCCESS} if the operation is successful.
 *         Returns other information otherwise.
  *
 * @since 20
 */
TEE_Result tee_send_agent_cmd(uint32_t agent_id);

/**
 * @brief Receive messgage in get agent buffer.
 *
 * @param agent_id The agent ID.
 * @param buffer The agent buffer.
 * @param length The length of the agent buffer.
 *
 * @return Returns {@code TEE_SUCCESS} if the operation is successful.
 *         Returns other information otherwise.
  *
 * @since 20
 */
TEE_Result tee_get_agent_buffer(uint32_t agent_id, void **buffer, uint32_t *length);

#ifdef __cplusplus
}
#endif

#endif
/** @} */