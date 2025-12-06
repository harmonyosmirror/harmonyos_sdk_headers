/*
 * Copyright (c) 2025 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
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
 * @addtogroup CryptoRandApi
 * @{
 *
 * @brief Describes the random number generation interface provided to applications.
 *
 * @since 20
 */
/**
 * @file crypto_rand.h
 *
 * @brief Defines the random number generator APIs.
 *
 * @library libohcrypto.so
 * @kit CryptoArchitectureKit
 * @syscap SystemCapability.Security.CryptoFramework
 * @since 20
 */
#ifndef CRYPTO_RAND_H
#define CRYPTO_RAND_H

#include "crypto_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines the random number generator structure.
 *
 * @since 20
 */
typedef struct OH_CryptoRand OH_CryptoRand;

/**
 * @brief Creates a random number generator context.
 *
 * @param ctx Indicates the random number generator context.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoRand_Create(OH_CryptoRand **ctx);

/**
 * @brief Generates random numbers.
 *
 * @param ctx Indicates the random number generator context.
 * @param len Indicates the byte length of the random number.
 * @param out Indicates the output data.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoRand_GenerateRandom(OH_CryptoRand *ctx, int len, Crypto_DataBlob *out);

/**
 * @brief Gets the algorithm name of the random number generator context.
 *
 * @param ctx Indicates the pointer to the random number generator context.
 * @return Return the algorithm name of the random number generator context.
 * @since 20
 */
const char *OH_CryptoRand_GetAlgoName(OH_CryptoRand *ctx);

/**
 * @brief Sets the seed to the random number generator context.
 *
 * @param ctx Indicates the random number generator context.
 * @param seed Indicates the seed.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoRand_SetSeed(OH_CryptoRand *ctx, Crypto_DataBlob *seed);

/**
 * @brief Enables the hardware entropy source.
 *
 * @param ctx Indicates the random number generator context.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 21
 */
OH_Crypto_ErrCode OH_CryptoRand_EnableHardwareEntropy(OH_CryptoRand *ctx);

/**
 * @brief Destroys the random number generator context.
 *
 * @param ctx Indicates the random number generator context.
 * @since 20
 */
void OH_CryptoRand_Destroy(OH_CryptoRand *ctx);

#ifdef __cplusplus
}
#endif

#endif /* CRYPTO_RAND_H */
/** @} */
