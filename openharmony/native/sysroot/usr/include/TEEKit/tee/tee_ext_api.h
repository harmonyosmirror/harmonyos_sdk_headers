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
 * @file tee_ext_api.h
 *
 * @brief Provides extended interfaces.
 *
 * @library NA
 * @kit TEEKit
 * @syscap SystemCapability.Tee.TeeClient
 * @since 20
 */

#ifndef TEE_EXT_API_H
#define TEE_EXT_API_H

#include "tee_defines.h"
#include "tee_hw_ext_api.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines the value of invalid user ID.
 *
 * @since 20
 */
#define INVALID_USERID 0xFFFFFFFFU

/**
 * @brief Defines the SMC from user mode.
 *
 * @since 20
 */
#define TEE_SMC_FROM_USR 0

/**
 * @brief Defines the SMC from kernel mode.
 *
 * @since 20
 */
#define TEE_SMC_FROM_KERNEL 1

/**
 * @brief Defines the szie of reserved buffer.
 *
 * @since 20
 */
#define RESERVED_BUF_SIZE 32

/**
 * @brief Defines the caller information.
 *
 * @since 20
 */
typedef struct ta_caller_info {
    /** The session type. */
    uint32_t session_type;
    union {
        struct {
            /** The caller's UUID. */
            TEE_UUID caller_uuid;
            /** The caller's group ID. */
            uint32_t group_id;
        };
        /** The buffer used to store CA information. */
        uint8_t ca_info[RESERVED_BUF_SIZE];
    } caller_identity;
    /** Indicates whether the SMC is sent from kernel mode. */
    uint8_t smc_from_kernel_mode;
    /** Reserved buffer. */
    uint8_t reserved[RESERVED_BUF_SIZE - 1];
} caller_info;

/**
 * @brief Get caller info of current session, refer caller_info struct for more details.
 *
 * @param caller_info_data A pointer to a buffer where the caller_info struct will be stored.
 * @param length The size of the buffer pointed to by caller_info_data.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 * @return Returns other information otherwise.
 *
 * @since 20
 */
TEE_Result tee_ext_get_caller_info(caller_info *caller_info_data, uint32_t length);

/**
 * @brief Get user ID of current CA.
 *
 * @param user_id Indicates the user ID to be returned.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 * @return Returns other information otherwise.
 *
 * @since 20
 */
TEE_Result tee_ext_get_caller_userid(uint32_t *user_id);

/**
 * @brief Adds information about a caller that can invoke this TA.
 * This API applies to the client applications (CAs) in the native CA and HAP format.
 *
 * @param cainfo_hash Indicates the hash value of the CA caller information.
 * @param length Indicates the length of the hash value.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 * @return Returns other information otherwise.
 *
 * @since 20
 */
TEE_Result AddCaller_CA(const uint8_t *cainfo_hash, uint32_t length);

/**
 * @brief TA call this API allow others TA open session with itself.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 * @return Returns other information otherwise.
  *
 * @since 20
 */
TEE_Result AddCaller_TA_all(void);

/**
 * @brief Defines the session caller from CA.
 *
 * @since 20
 */
#define SESSION_FROM_CA   0

/**
 * @brief Defines the session caller from TA.
 *
 * @since 20
 */
#define SESSION_FROM_TA   1

/**
 * @brief Defines the TA task is not found, for example, from TA sub thread.
 *
 * @since 20
 */
#define SESSION_FROM_NOT_SUPPORTED   0xFE

/**
 * @brief Defines the TA caller is not found.
 *
 * @since 20
 */
#define SESSION_FROM_UNKNOWN   0xFF

/**
 * @brief Obtains the session type.
 *
 * @return Returns the session type obtained.
 *
 * @since 20
 */
uint32_t tee_get_session_type(void);

/**
 * @brief Derive key from platform key.
 *
 * @param object             [IN/OUT] input data in ObjectInfo->keytype, output keys in Attributes.
 * @param key_size           [IN] key size in bits, it desides the ecc curve type too.
 * @param params             [IN] unused.
 * @param param_count        [IN] unused.
 * @param exinfo             [IN] user info as dervice salt.
 * @param exinfo_size        [IN] size of user info, Max is 64 bytes, must bigger than 0.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 * @return Returns other information otherwise.
 *
 * @since 20
 */
TEE_Result tee_ext_derive_ta_platfrom_keys(TEE_ObjectHandle object, uint32_t key_size, const TEE_Attribute *params,
    uint32_t param_count, const uint8_t *exinfo, uint32_t exinfo_size);

#ifdef __cplusplus
}
#endif

#endif
/** @} */