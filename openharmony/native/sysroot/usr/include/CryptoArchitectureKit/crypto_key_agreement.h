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
 * @addtogroup CryptoKeyAgreementApi
 * @{
 *
 * @brief Describes key agreement algorithm interface provided to applications.
 *
 * @since 20
 */

/**
 * @file crypto_key_agreement.h
 *
 * @brief Defines the key agreement APIs.
 *
 * @library libohcrypto.so
 * @kit CryptoArchitectureKit
 * @syscap SystemCapability.Security.CryptoFramework
 * @since 20
 */

#ifndef CRYPTO_KEY_AGREEMENT_H
#define CRYPTO_KEY_AGREEMENT_H

#include "crypto_common.h"
#include "crypto_asym_key.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines the key agreement structure.
 *
 * @since 20
 */
typedef struct OH_CryptoKeyAgreement OH_CryptoKeyAgreement;

/**
 * @brief Creates a key agreement context according to the given algorithm name.
 *
 * @param algoName Indicates the algorithm name used to generate a key agreement context. e.g. "ECC", "X25519".
 * @param ctx Indicates the key agreement context.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoKeyAgreement_Create(const char *algoName, OH_CryptoKeyAgreement **ctx);

/**
 * @brief Generates a secret value.
 *
 * @param ctx Indicates the key agreement context.
 * @param privkey Indicates the private key.
 * @param pubkey Indicates the public key.
 * @param secret Indicates the secret value.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoKeyAgreement_GenerateSecret(OH_CryptoKeyAgreement *ctx, OH_CryptoPrivKey *privkey,
    OH_CryptoPubKey *pubkey, Crypto_DataBlob *secret);

/**
 * @brief Destroys the key agreement context.
 *
 * @param ctx Indicates the key agreement context.
 * @since 20
 */
void OH_CryptoKeyAgreement_Destroy(OH_CryptoKeyAgreement *ctx);

#ifdef __cplusplus
}
#endif

#endif /* CRYPTO_KEY_AGREEMENT_H */
/** @} */
