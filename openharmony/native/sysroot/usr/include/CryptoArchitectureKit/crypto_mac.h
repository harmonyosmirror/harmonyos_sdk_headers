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
 * @addtogroup CryptoMacApi
 * @{
 *
 * @brief Describes the MAC algorithm interface provided to applications.
 *
 * @since 20
 */

/**
 * @file crypto_mac.h
 *
 * @brief Defines the MAC algorithm APIs.
 *
 * @library libohcrypto.so
 * @kit CryptoArchitectureKit
 * @syscap SystemCapability.Security.CryptoFramework
 * @since 20
 */

#ifndef CRYPTO_MAC_H
#define CRYPTO_MAC_H

#include "crypto_common.h"
#include "crypto_sym_key.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines the MAC structure.
 *
 * @since 20
 */
typedef struct OH_CryptoMac OH_CryptoMac;

/**
 * @brief Defines the MAC algorithm parameter type.
 *
 * @since 20
 */
typedef enum {
    /** Indicates the algorithm name of the message digest function for HMAC. e.g. "SHA256".*/
    CRYPTO_MAC_DIGEST_NAME_STR = 0,

    /** Indicates the algorithm name of the symmetric cipher function for CMAC. e.g. "AES256".*/
    CRYPTO_MAC_CIPHER_NAME_STR = 1,
} CryptoMac_ParamType;

/**
 * @brief Creates a MAC context according to the given algorithm name.
 *
 * @param algoName Indicates the algorithm name for generating the MAC context. e.g. "HMAC", "CMAC".
 * @param ctx Indicates the pointer to the MAC context.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoMac_Create(const char *algoName, OH_CryptoMac **ctx);

/**
 * @brief Sets the specified parameter to the MAC context.
 *
 * @param ctx Indicates the MAC context.
 * @param type Indicates the MAC parameter type.
 * @param value Indicates the parameter value.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoMac_SetParam(OH_CryptoMac *ctx, CryptoMac_ParamType type, const Crypto_DataBlob *value);

/**
 * @brief Initializes the MAC context with a symmetric key.
 *
 * @param ctx Indicates the MAC context.
 * @param key Indicates the symmetric key.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @see OH_CryptoMac_Update
 * @see OH_CryptoMac_Final
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoMac_Init(OH_CryptoMac *ctx, const OH_CryptoSymKey *key);

/**
 * @brief Updates the MAC context with data.
 *
 * @param ctx Indicates the MAC context.
 * @param in Indicates the data to update.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @see OH_CryptoMac_Init
 * @see OH_CryptoMac_Final
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoMac_Update(OH_CryptoMac *ctx, const Crypto_DataBlob *in);

/**
 * @brief Finalizes the MAC operation.
 *
 * @param ctx Indicates the MAC context.
 * @param out Indicates the MAC result.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @see OH_CryptoMac_Init
 * @see OH_CryptoMac_Update
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoMac_Final(OH_CryptoMac *ctx, Crypto_DataBlob *out);

/**
 * @brief Gets the length of the MAC.
 *
 * @param ctx Indicates the MAC context.
 * @param length Indicates the MAC length.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoMac_GetLength(OH_CryptoMac *ctx, uint32_t *length);

/**
 * @brief Destroys the MAC context.
 *
 * @param ctx Indicates the MAC context.
 * @since 20
 */
void OH_CryptoMac_Destroy(OH_CryptoMac *ctx);

#ifdef __cplusplus
}
#endif

#endif /* CRYPTO_MAC_H */
/** @} */
