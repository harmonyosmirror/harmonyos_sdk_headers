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
 * @addtogroup CryptoSymKeyApi
 * @{
 *
 * @brief Describe openHarmony symmetric key related features interfaces provide for applications.
 *
 * @since 12
 */

/**
 * @file crypto_sym_key.h
 *
 * @brief Defines the symmetric key APIs.
 *
 * @library libohcrypto.so
 * @kit CryptoArchitectureKit
 * @syscap SystemCapability.Security.CryptoFramework
 * @since 12
 */

#ifndef CRYPTO_SYM_KEY_H
#define CRYPTO_SYM_KEY_H

#include "crypto_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Define the symmetric key structure.
 *
 * @since 12
 */
typedef struct OH_CryptoSymKey OH_CryptoSymKey;

/**
 * @brief Define the symmetric key generator structure.
 *
 * @since 12
 */
typedef struct OH_CryptoSymKeyGenerator OH_CryptoSymKeyGenerator;

/**
 * @brief Create a symmetric key generator according to the given algorithm name. Example AES256.
 *
 * @param algoName Indicates the algorithm name for generating the generator.
 * @param ctx Indicates the pointer to the symmetric key generator context.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Create(const char *algoName, OH_CryptoSymKeyGenerator **ctx);

/**
 * @brief Generate a symmetric key.
 *
 * @param ctx Indicates the Symmetric key generator context.
 * @param keyCtx Indicates the pointer to the symmetric key context.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Generate(OH_CryptoSymKeyGenerator *ctx, OH_CryptoSymKey **keyCtx);

/**
 * @brief Convert the symmetric key data to a key.
 *
 * @param ctx Indicates the symmetric key generator context.
 * @param keyData Indicates the data to generate the Symkey.
 * @param keyCtx Indicates the pointer to the symmetric key context.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Convert(OH_CryptoSymKeyGenerator *ctx,
    const Crypto_DataBlob *keyData, OH_CryptoSymKey **keyCtx);

/**
 * @brief Get the algorithm name of the symmetric key generator.
 *
 * @param ctx Indicates the symmetric key generator context.
 * @return Return symmetric key algorithm name.
 * @since 12
 */
const char *OH_CryptoSymKeyGenerator_GetAlgoName(OH_CryptoSymKeyGenerator *ctx);

/**
 * @brief Destroy the symmetric key generator.
 *
 * @param ctx Indicates the symmetric key generator context.
 * @since 12
 */
void OH_CryptoSymKeyGenerator_Destroy(OH_CryptoSymKeyGenerator *ctx);

/**
 * @brief Get the symmetric key algorithm name from a symmetric key.
 *
 * @param keyCtx Indicates the symmetric key context.
 * @return Return algorithm name.
 * @since 12
 */
const char *OH_CryptoSymKey_GetAlgoName(OH_CryptoSymKey *keyCtx);

/**
 * @brief Get the symmetric key data from a symmetric key.
 *
 * @param keyCtx Indicates the symmetric key context.
 * @param out Indicate to obtain the result.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoSymKey_GetKeyData(OH_CryptoSymKey *keyCtx, Crypto_DataBlob *out);

/**
 * @brief Destroy the symmetric key.
 *
 * @param keyCtx Indicates the symmetric key context.
 * @since 12
 */
void OH_CryptoSymKey_Destroy(OH_CryptoSymKey *keyCtx);

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* CRYPTO_SYM_KEY_H */
