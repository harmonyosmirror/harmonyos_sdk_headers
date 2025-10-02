/*
 * Copyright (C) 2024 Huawei Device Co., Ltd.
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
 * @addtogroup CryptoSymCipherApi
 * @{
 *
 * @brief Describe the functions provided by the openHarmony symmetric key encryption
 *  and decryption interface for applications.
 *
 * @since 12
 */

/**
 * @file crypto_sym_cipher.h
 *
 * @brief Defines the symmetric key cipher APIs.
 *
 * @library libohcrypto.so
 * @kit CryptoArchitectureKit
 * @syscap SystemCapability.Security.CryptoFramework
 * @since 12
 */

#ifndef CRYPTO_SYM_CIPHER_H
#define CRYPTO_SYM_CIPHER_H

#include "crypto_common.h"
#include "crypto_sym_key.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Define the cipher param type.
 *
 * @since 12
 */
typedef enum {
    /** Indicates the parameters such as iv. */
    CRYPTO_IV_DATABLOB = 100,
    /** Indicates the additional Authenticated Data in GCM mode. */
    CRYPTO_AAD_DATABLOB = 101,
    /** Indicates the output tag from the encryption operation. The tag is used for integrity check. */
    CRYPTO_TAG_DATABLOB = 102,
} CryptoSymCipher_ParamsType;

/**
 * @brief Define the symmetric key cipher structure.
 *
 * @since 12
 */
typedef struct OH_CryptoSymCipher OH_CryptoSymCipher;

/**
 * @brief Define the symmetric key cipher params structure.
 *
 * @since 12
 */
typedef struct OH_CryptoSymCipherParams OH_CryptoSymCipherParams;

/**
 * @brief Create a symmetric key cipher params.
 *
 * @param params Indicates the pointer to the cipher params context.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoSymCipherParams_Create(OH_CryptoSymCipherParams **params);

/**
 * @brief Set a parameter to the cipher params context.
 *
 * @param params Indicates the parameters context.
 * @param paramsType Set cipher parameters.
 * @param value Indicates the setParam result.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoSymCipherParams_SetParam(OH_CryptoSymCipherParams *params,
    CryptoSymCipher_ParamsType paramsType, Crypto_DataBlob *value);

/**
 * @brief Destroy the cipher params context.
 *
 * @param params Indicates the parameters context.
 * @since 12
 */
void OH_CryptoSymCipherParams_Destroy(OH_CryptoSymCipherParams *params);

/**
 * @brief Create a symmetric key cipher context according to the given algorithm name.
 *
 * @param algoName Indicates the algorithm name used to generate the symmetric key cipher context.
 *  Example AES128|GCM|PKCS7.
 * @param ctx Indicates the pointer to the symmetric key cipher context.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoSymCipher_Create(const char *algoName, OH_CryptoSymCipher **ctx);

/**
 * @brief Init the crypto operation with the given crypto mode, key and parameters.
 *
 * @param ctx Indicates the symmetric key cipher context.
 * @param mod Indicates the crypto mode is encryption or decryption.
 * @param key Indicates the symmetric key or the asymmetric key.
 * @param params Indicates the algorithm parameters such as IV.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @see OH_CryptoSymCipher_Update
 * @see OH_CryptoSymCipher_Final
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoSymCipher_Init(OH_CryptoSymCipher *ctx, Crypto_CipherMode mod,
    OH_CryptoSymKey *key, OH_CryptoSymCipherParams *params);

/**
 * @brief Update the crypto operation with the input data, and feed back the encrypted or decrypted data.
 *
 * @param ctx Indicates the symmetric key cipher context.
 * @param in Indicates the data to be encrypted or decrypted.
 * @param out Indicates the data to be update encrypted or decrypted.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @see OH_CryptoSymCipher_Init
 * @see OH_CryptoSymCipher_Final
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoSymCipher_Update(OH_CryptoSymCipher *ctx, Crypto_DataBlob *in, Crypto_DataBlob *out);

/**
 * @brief Finish the crypto operation, encrypt or decrypt the input data, and then feed back the output data.
 *
 * @param ctx Indicates the symmetric key cipher context.
 * @param in Indicates the data to be encrypted or decrypted.
 * @param out Indicates the data to be finally encrypted or decrypted.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @see OH_CryptoSymCipher_Init
 * @see OH_CryptoSymCipher_Update
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoSymCipher_Final(OH_CryptoSymCipher *ctx, Crypto_DataBlob *in, Crypto_DataBlob *out);

/**
 * @brief Get the algorithm name of the symmetric key cipher context.
 *
 * @param ctx Indicates the symmetric key context.
 * @return Return symmetric key cipher algorithm name.
 * @since 12
 */
const char *OH_CryptoSymCipher_GetAlgoName(OH_CryptoSymCipher *ctx);

/**
 * @brief Destroy the symmetric key cipher context.
 *
 * @param ctx Indicates the symmetric key context.
 * @since 12
 */
void OH_CryptoSymCipher_Destroy(OH_CryptoSymCipher *ctx);


#ifdef __cplusplus
}
#endif

/** @} */
#endif /* CRYPTO_SYM_CIPHER_H */
