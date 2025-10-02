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
 * @file dstb_api.h
 *
 * @brief Provides the API about Distributed TEE service.
 *
 * @library NA
 * @kit TEEKit
 * @syscap SystemCapability.Tee.TeeClient
 * @since 20
 */

#ifndef DSTB_API_H
#define DSTB_API_H

#include <stdint.h>
#include <tee_defines.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates device ID types.
 *
 * @since 20
 */
enum devid_type {
    /** Network ID */
    DEVID_NETID = 0,
    /** Device ID */
    DEVID_UDID = 1,
};

/**
 * @brief Defines device information.
 *
 * @since 20
 */
struct device_info {
    /** Enumerated variable for device ID type */
    enum devid_type devid_type;
    /** Device ID value */
    char *devid;
};

/**
 * @brief Enumerates the negotiation conditions.
 *
 * @since 20
 */
enum nego_condition {
    /** check whether local has record of peer. If no, start negatiation. */
    CHECK_LOCAL = 0,
    /** check local and peer have records of each other. If no, start negotiation. */
    CHECK_BOTH = 1,
    /** start negotiation with no condition. */
    NO_CHECK = 2,
};

/**
 * @brief Generate share key by distributed TEE.
 *
 * @param devid_info [OUT]The peer devid, can be networkid or deviceid.
 * @param salt [IN]The salt should be random, same as peer if caller want to generate same share key.
 * @param salt_len [IN]The length of the salt buffer.
 * @param info [IN]The entra information for generate share key, same as peer if caller want to generate same share key.
 * @param info_len [IN]The length of the information buffer.
 * @param key [OUT]The result key.
 * @param key_len [IN]The length of the result key.
 *
 * @return Returns {@code TEE_SUCCESS} if the operation is successful.
 *         Returns other information otherwise.
  *
 * @since 20
 */
TEE_Result tee_dstb_gen_sharekey(struct device_info *devid_info, const uint8_t *salt, uint32_t salt_len,
    const uint8_t *info, uint32_t info_len, uint8_t *key, uint32_t key_len);

/**
 * @brief The pre-negotiation interface about distributed TEE service .
 *
 * @param devid_info [OUT]The peer devid, can be networkid or deviceid.
 * @param cond [IN]Pre-negotiation conditions.
 *
 * @return Returns {@code TEE_SUCCESS} if the operation is successful.
 *         Returns other information otherwise.
  *
 * @since 20
 */
TEE_Result tee_dstb_pre_attestation(struct device_info *devid_info, enum nego_condition cond);

#ifdef __cplusplus
}
#endif

#endif
/** @} */