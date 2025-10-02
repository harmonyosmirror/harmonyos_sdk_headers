/*
 * Copyright (c) 2025 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @addtogroup CryptoKdfApi
 * @{
 *
 * @brief Describes the KDF algorithm interface provided to applications.
 *
 * @since 20
 */

/**
 * @file crypto_kdf.h
 *
 * @brief Defines the KDF APIs.
 *
 * @library libohcrypto.so
 * @kit CryptoArchitectureKit
 * @syscap SystemCapability.Security.CryptoFramework
 * @since 20
 */

#ifndef CRYPTO_KDF_H
#define CRYPTO_KDF_H

#include "crypto_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines the KDF structure.
 *
 * @since 20
 */
typedef struct OH_CryptoKdf OH_CryptoKdf;

/**
 * @brief Defines the KDF params structure.
 *
 * @since 20
 */
typedef struct OH_CryptoKdfParams OH_CryptoKdfParams;

/**
 * @brief Defines the KDF param type.
 *
 * @since 20
 */
typedef enum {
    /** Indicates the key or password for KDF. */
    CRYPTO_KDF_KEY_DATABLOB = 0,

    /** Indicates the salt for KDF. */
    CRYPTO_KDF_SALT_DATABLOB = 1,

    /** Indicates the info for KDF. */
    CRYPTO_KDF_INFO_DATABLOB = 2,

    /** Indicates the iteration count for PBKDF2. */
    CRYPTO_KDF_ITER_COUNT_INT = 3,

    /** Indicates the n for SCRYPT KDF. */
    CRYPTO_KDF_SCRYPT_N_UINT64 = 4,

    /** Indicates the r for SCRYPT KDF. */
    CRYPTO_KDF_SCRYPT_R_UINT64 = 5,

    /** Indicates the p for SCRYPT KDF. */
    CRYPTO_KDF_SCRYPT_P_UINT64 = 6,

    /** Indicates the max memory for SCRYPT KDF. */
    CRYPTO_KDF_SCRYPT_MAX_MEM_UINT64 = 7,
} CryptoKdf_ParamType;

/**
 * @brief Creates KDF params.
 *
 * @param algoName Indicates the KDF algorithm name. e.g. "HKDF", "PBKDF2", "SCRYPT".
 * @param params Indicates the KDF params.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoKdfParams_Create(const char *algoName, OH_CryptoKdfParams **params);

/**
 * @brief Sets a parameter to the KDF parameters.
 *
 * @param params Indicates the KDF parameters.
 * @param type Indicates the KDF parameter type.
 * @param value Indicates the KDF parameter value.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoKdfParams_SetParam(OH_CryptoKdfParams *params, CryptoKdf_ParamType type,
    Crypto_DataBlob *value);

/**
 * @brief Destroys the KDF params.
 *
 * @param params Indicates the KDF parameters.
 * @since 20
 */
void OH_CryptoKdfParams_Destroy(OH_CryptoKdfParams *params);

/**
 * @brief Creates a KDF context.
 *
 * @param algoName Indicates the KDF algorithm name. e.g. "HKDF|SHA384|EXTRACT_AND_EXPAND", "PBKDF2|SHA384", "SCRYPT".
 * @param ctx Indicates the KDF context.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoKdf_Create(const char *algoName, OH_CryptoKdf **ctx);

/**
 * @brief Derives a key.
 *
 * @param ctx The KDF context.
 * @param params Indicates the KDF parameters.
 * @param keyLen Indicates the key derivation length.
 * @param key Indicates the derived key.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoKdf_Derive(OH_CryptoKdf *ctx, const OH_CryptoKdfParams *params, int keyLen,
    Crypto_DataBlob *key);

/**
 * @brief Destroys the KDF context.
 *
 * @param ctx The KDF context.
 * @since 20
 */
void OH_CryptoKdf_Destroy(OH_CryptoKdf *ctx);


#ifdef __cplusplus
}
#endif

#endif /* CRYPTO_KDF_H */
/** @} */
