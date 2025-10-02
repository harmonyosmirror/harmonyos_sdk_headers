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
 * @file tee_hw_ext_api.h
 *
 * @brief Provides extended interfaces.
 *
 * @library NA
 * @kit TEEKit
 * @syscap SystemCapability.Tee.TeeClient
 * @since 20
 */

#ifndef TEE_HW_EXT_API_H
#define TEE_HW_EXT_API_H

#include "tee_defines.h"
#include "tee_crypto_api.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Obtains the unique device ID from the TEE.
 *
 * @param device_unique_id Indicates the pointer to the buffer for storing the device ID.
 * @param length Indicates the pointer to the buffer length.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 * @return Returns other information otherwise.
 *
 * @since 20
 */
TEE_Result tee_ext_get_device_unique_id(uint8_t *device_unique_id, uint32_t *length);

/**
 * @brief Defines the memory information.
 *
 * @since 20
 */
struct meminfo_t {
    /** Pointer to the memory buffer. */
    uint64_t buffer;
    /** The size of the memory. */
    uint32_t size;
};

/**
 * @brief Derive key from device rootkey and UUID of the current task for iteration.
 *
 * @param salt [IN] Indicates the data for salt.
 * @param key [OUT] Indicates the pointer where key is saved.
 * @param outer_iter_num [IN] Indicates the iteration times in huk service.
 * @param inner_iter_num [IN] Indicates the iteration times in platform driver.
 *
 * @return Returns {@code TEE_SUCCESS} if the operation is successful.
 *         Returns {@code TEE_ERROR_BAD_PARAMETERS} if input parameter is incorrect.
 *         Returns {@code TEE_ERROR_GENERIC} if the processing failed.
 *
 * @since 20
 */
TEE_Result tee_ext_derive_key_iter(const struct meminfo_t *salt, struct meminfo_t *key,
    uint32_t outer_iter_num, uint32_t inner_iter_num);

/**
 * @brief Derive key from device rootkey and UUID of the current task for iteration by huk2 encryption.
 *
 * @param salt [IN] Indicates the data for salt.
 * @param key [OUT] Indicates the pointer where key is saved.
 * @param outer_iter_num [IN] Indicates the iteration times in huk service.
 * @param inner_iter_num [IN] Indicates the iteration times in platform driver.
 *
 * @return Returns {@code TEE_SUCCESS} if the operation is successful.
 *         Returns {@code TEE_ERROR_BAD_PARAMETERS} if input parameter is incorrect.
 *         Returns {@code TEE_ERROR_GENERIC} if the processing failed.
 *
 * @since 20
 */
TEE_Result tee_ext_derive_key_iter_by_huk2(const struct meminfo_t *salt, struct meminfo_t *key,
    uint32_t outer_iter_num, uint32_t inner_iter_num);

/**
 * @brief Derive key from device root key by HUK2.
 * @attention If the device does not support HUK2, the key is derived by HUK.
 *
 * @param salt [IN] Indicates the data for salt.
 * @param size [IN] Indicates the length of salt.
 * @param key [OUT] Indicates the pointer where key is saved.
 * @param key_size [IN] Indicates the size of the key, which must be integer times of 16.
 *
 * @return Returns {@code TEE_SUCCESS} if the operation is successful.
 *         Returns {@code TEE_ERROR_BAD_PARAMETERS} if input parameter is incorrect.
 *         Returns {@code TEE_ERROR_GENERIC} if the processing failed.
 *
 * @since 20
 */
TEE_Result tee_ext_derive_ta_root_key_by_huk2(const uint8_t *salt, uint32_t size, uint8_t *key, uint32_t key_size);

/**
 * @brief derive key from device rootkey and UUID of the current task for iteration using huk2 enhance
 *
 * @param salt [IN] data for salt
 * @param key [OUT] pointer where key is saved
 * @param outer_iter_num [IN] iteration times in huk service
 * @param inner_iter_num  [IN] iteration times in platdrv
 *
 * @return Returns {@code TEE_SUCCESS} if the operation is successful.
 *         Returns {@code TEE_ERROR_BAD_PARAMETERS} if input parameter is illegal.
 *         Returns {@code TEE_ERROR_GENERIC} if the processing failed.
 *
 * @since 20
 */
TEE_Result tee_ext_derive_key_iter_by_huk2_enhance(const struct meminfo_t *salt, struct meminfo_t *key,
    uint32_t outer_iter_num, uint32_t inner_iter_num);

#ifdef __cplusplus
}
#endif

#endif
/** @} */