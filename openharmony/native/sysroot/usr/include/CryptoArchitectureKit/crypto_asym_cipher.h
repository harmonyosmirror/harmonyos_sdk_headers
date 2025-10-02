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
 * @addtogroup CryptoAsymCipherApi
 * @{
 *
 * @brief Describes the asymmetric encryption and decryption algorithm interface provided to applications.
 *
 * @since 20
 */

/**
 * @file crypto_asym_cipher.h
 *
 * @brief Defines the asymmetric cipher APIs.
 *
 * @library libohcrypto.so
 * @kit CryptoArchitectureKit
 * @syscap SystemCapability.Security.CryptoFramework
 * @since 20
 */

#ifndef CRYPTO_ASYM_CIPHER_H
#define CRYPTO_ASYM_CIPHER_H

#include "crypto_common.h"
#include "crypto_asym_key.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines the asymmetric cipher structure.
 *
 * @since 20
 */
typedef struct OH_CryptoAsymCipher OH_CryptoAsymCipher;

/**
 * @brief Creates an asymmetric cipher context according to the given algorithm name.
 *
 * @param algoName Indicates the algorithm name used to generate the asymmetric cipher context. e.g. "RSA|PKCS1",
 * "RSA|PKCS1_OAEP|SHA384|MGF1_SHA384", "SM2|SM3".
 * @param ctx Indicates the pointer to the asymmetric cipher context.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoAsymCipher_Create(const char *algoName, OH_CryptoAsymCipher **ctx);

/**
 * @brief Initializes the asymmetric cipher context with the given crypto mode, key and parameters.
 *
 * @param ctx Indicates the asymmetric cipher context.
 * @param mode Indicates the crypto mode is encryption or decryption.
 * @param key Indicates the asymmetric key.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @see OH_CryptoAsymCipher_Final
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoAsymCipher_Init(OH_CryptoAsymCipher *ctx, Crypto_CipherMode mode, OH_CryptoKeyPair *key);

/**
 * @brief Finalizes the encryption or decryption operation.
 *
 * @param ctx Indicates the asymmetric cipher context.
 * @param in Indicates the input data to be encrypted or decrypted.
 * @param out Indicates the result of encryption or decryption.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @see OH_CryptoAsymCipher_Init
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoAsymCipher_Final(OH_CryptoAsymCipher *ctx, const Crypto_DataBlob *in,
    Crypto_DataBlob *out);

/**
 * @brief Destroys the asymmetric cipher context.
 *
 * @param ctx Indicates the asymmetric cipher context.
 * @since 20
 */
void OH_CryptoAsymCipher_Destroy(OH_CryptoAsymCipher *ctx);

/**
 * @brief Defines the SM2 ciphertext spec structure.
 *
 * @since 20
 */
typedef struct OH_CryptoSm2CiphertextSpec OH_CryptoSm2CiphertextSpec;

/**
 * @brief Defines the SM2 ciphertext spec item type.
 *
 * @since 20
 */
typedef enum {
    /** Public key x, also known as C1x. */
    CRYPTO_SM2_CIPHERTEXT_C1_X = 0,
    /** Public key y, also known as C1y. */
    CRYPTO_SM2_CIPHERTEXT_C1_Y = 1,
    /** Hash, also known as C2. */
    CRYPTO_SM2_CIPHERTEXT_C2 = 2,
    /** Ciphertext data, also known as C3. */
    CRYPTO_SM2_CIPHERTEXT_C3 = 3,
} CryptoSm2CiphertextSpec_item;

/**
 * @brief Creates a SM2 ciphertext spec.
 *
 * @param sm2Ciphertext Indicates the SM2 ciphertext in DER format, if sm2Ciphertext param is NULL,
 * an empty SM2 ciphertext spec will be created.
 * @param spec Indicates the output SM2 ciphertext spec.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_Create(Crypto_DataBlob *sm2Ciphertext, OH_CryptoSm2CiphertextSpec **spec);

/**
 * @brief Gets the specified item of the SM2 ciphertext.
 *
 * @param spec Indicates the SM2 ciphertext spec.
 * @param item Indicates the SM2 ciphertext spec item.
 * @param out Indicates the output data.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_GetItem(OH_CryptoSm2CiphertextSpec *spec,
    CryptoSm2CiphertextSpec_item item, Crypto_DataBlob *out);

/**
 * @brief Sets the specified item to the SM2 ciphertext spec.
 *
 * @param spec Indicates the SM2 ciphertext spec.
 * @param item Indicates the SM2 ciphertext spec item.
 * @param in Indicates the input data.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_SetItem(OH_CryptoSm2CiphertextSpec *spec,
    CryptoSm2CiphertextSpec_item item, Crypto_DataBlob *in);

/**
 * @brief Encodes the SM2 ciphertext spec to ciphertext in DER format.
 *
 * @param spec Indicates the SM2 ciphertext spec.
 * @param out Indicates the output data.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_Encode(OH_CryptoSm2CiphertextSpec *spec, Crypto_DataBlob *out);

/**
 * @brief Destroys the SM2 ciphertext spec.
 *
 * @param spec Indicates the SM2 ciphertext spec.
 * @since 20
 */
void OH_CryptoSm2CiphertextSpec_Destroy(OH_CryptoSm2CiphertextSpec *spec);

#ifdef __cplusplus
}
#endif

#endif /* CRYPTO_ASYM_CIPHER_H */
/** @} */
