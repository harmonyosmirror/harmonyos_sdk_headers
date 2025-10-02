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
 * @addtogroup CryptoAsymKeyApi
 * @{
 *
 * @brief Describe the features provided by the openHarmony asymmetric key related interface for applications.
 *
 * @since 12
 */

/**
 * @file crypto_asym_key.h
 *
 * @brief Defines the AsymKey APIs.
 *
 * @library libohcrypto.so
 * @kit CryptoArchitectureKit
 * @syscap SystemCapability.Security.CryptoFramework
 * @since 12
 */

#ifndef CRYPTO_ASYM_KEY_H
#define CRYPTO_ASYM_KEY_H

#include "crypto_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Define the key pair structure.
 *
 * @since 12
 */
typedef struct OH_CryptoKeyPair OH_CryptoKeyPair;

/**
 * @brief Define the public Key structure.
 *
 * @since 12
 */
typedef struct OH_CryptoPubKey OH_CryptoPubKey;

/**
 * @brief Define the asymmetric key parameter types.
 *
 * @since 12
 */
typedef enum {
    /** Indicates the DSA prime p. */
    CRYPTO_DSA_P_DATABLOB = 101,
    /** Indicates the DSA sub-prime q. */
    CRYPTO_DSA_Q_DATABLOB = 102,
    /** Indicates the DSA base g. */
    CRYPTO_DSA_G_DATABLOB = 103,
    /** Indicates the DSA private key. */
    CRYPTO_DSA_SK_DATABLOB = 104,
    /** Indicates the DSA public key. */
    CRYPTO_DSA_PK_DATABLOB = 105,

    /** Indicates the prime p of an elliptic curve (EC) prime finite field. */
    CRYPTO_ECC_FP_P_DATABLOB = 201,
    /** Indicates the first coefficient a of this elliptic curve. */
    CRYPTO_ECC_A_DATABLOB = 202,
    /** Indicates the second coefficient b of this elliptic curve. */
    CRYPTO_ECC_B_DATABLOB = 203,
    /** Indicates the affine x-coordinate of base point g. */
    CRYPTO_ECC_G_X_DATABLOB = 204,
    /** Indicates the affine y-coordinate of base point g. */
    CRYPTO_ECC_G_Y_DATABLOB = 205,
    /** Indicates the order of the base point g. */
    CRYPTO_ECC_N_DATABLOB = 206,
    /** Indicates the cofactor of the elliptic curve. */
    CRYPTO_ECC_H_INT = 207,
    /** Indicates the private value of the ECC private key. */
    CRYPTO_ECC_SK_DATABLOB = 208,
    /** Indicates the affine x-coordinate of a point, which is the public point of an ECC public key. */
    CRYPTO_ECC_PK_X_DATABLOB = 209,
    /** Indicates the affine y-coordinate of a point, which is the public point of an ECC public key. */
    CRYPTO_ECC_PK_Y_DATABLOB = 210,
    /** Indicates an elliptic curve finite field type. */
    CRYPTO_ECC_FIELD_TYPE_STR = 211,
    /** Indicates the field size in bits. */
    CRYPTO_ECC_FIELD_SIZE_INT = 212,
    /** Indicates the curve name according to SECG (Standards for Efficient Cryptography Group). */
    CRYPTO_ECC_CURVE_NAME_STR = 213,

    /** Indicates the modulus n of RSA algorithm. */
    CRYPTO_RSA_N_DATABLOB = 301,
    /** Indicates the private exponent d of RSA algorithm. */
    CRYPTO_RSA_D_DATABLOB = 302,
    /** Indicates the public exponent e of RSA algorithm. */
    CRYPTO_RSA_E_DATABLOB = 303,

    /** Indicates the prime p of DH algorithm. */
    CRYPTO_DH_P_DATABLOB = 401,
    /** Indicates the generator g of DH algorithm. */
    CRYPTO_DH_G_DATABLOB = 402,
    /** Indicates the number of bits of the private key length used in the DH algorithm. */
    CRYPTO_DH_L_INT = 403,
    /** Indicates the private value of the DH private key. */
    CRYPTO_DH_SK_DATABLOB = 404,
    /** Indicates the public value of the DH public key. */
    CRYPTO_DH_PK_DATABLOB = 405,

    /** Indicates the private value of the ED25519 private key. */
    CRYPTO_ED25519_SK_DATABLOB = 501,
    /** Indicates the public value of the ED25519 public key. */
    CRYPTO_ED25519_PK_DATABLOB = 502,
    /** Indicates the private value of the X25519 private key. */
    CRYPTO_X25519_SK_DATABLOB = 601,
    /** Indicates the public value of the X25519 public key. */
    CRYPTO_X25519_PK_DATABLOB = 602,
} CryptoAsymKey_ParamType;

/**
 * @brief Define the encoding type.
 *
 * @since 12
 */
typedef enum {
    /** PEM format */
    CRYPTO_PEM = 0,
    /** DER format */
    CRYPTO_DER = 1,
} Crypto_EncodingType;

/**
 * @brief Define the asymmetric key generator structure.
 *
 * @since 12
 */
typedef struct OH_CryptoAsymKeyGenerator OH_CryptoAsymKeyGenerator;

/**
 * @brief Create an asymmetric key generator according to the given algorithm name.
 *
 * @param algoName Indicates the algorithm name for generating the generator. Example RSA1024|PRIMES_2.
 * @param ctx Indicates the pointer to asymmetric key generator context.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Create(const char *algoName, OH_CryptoAsymKeyGenerator **ctx);

/**
 * @brief Generate an asymmetric key(a key pair).
 *
 * @param ctx Indicates the asymmetric key generator context.
 * @param keyCtx Indicates the pointer to the asyKey context.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Generate(OH_CryptoAsymKeyGenerator *ctx, OH_CryptoKeyPair **keyCtx);

/**
 * @brief Convert the asymmetric key data to a key pair.
 *
 * @param ctx Indicates the asymmetric key generator context.
 * @param type Indicates the encryption encoding type.
 * @param pubKeyData Indicates the public key data.
 * @param priKeyData Indicates the private key data.
 * @param keyCtx Indicates the pointer to the keyPair instance.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Convert(OH_CryptoAsymKeyGenerator *ctx, Crypto_EncodingType type,
    Crypto_DataBlob *pubKeyData, Crypto_DataBlob *priKeyData, OH_CryptoKeyPair **keyCtx);

/**
 * @brief Get the algorithm name of the asymmetric key generator.
 *
 * @param ctx Indicates the asymmetric key generator context.
 * @return Returns the asymmetric key algorithm name.
 * @since 12
 */
const char *OH_CryptoAsymKeyGenerator_GetAlgoName(OH_CryptoAsymKeyGenerator *ctx);

/**
 * @brief Destroy the asymmetric key generator.
 *
 * @param ctx Indicates the asymmetric key generator context.
 * @since 12
 */
void OH_CryptoAsymKeyGenerator_Destroy(OH_CryptoAsymKeyGenerator *ctx);

/**
 * @brief Destroy the key pair.
 *
 * @param keyCtx Indicates the keyPair context.
 * @since 12
 */
void OH_CryptoKeyPair_Destroy(OH_CryptoKeyPair *keyCtx);

/**
 * @brief Get the public key of the key pair.
 *
 * @param keyCtx Indicates the keyPair context.
 * @return Return the public key context from the key pair.
 * @since 12
 */
OH_CryptoPubKey *OH_CryptoKeyPair_GetPubKey(OH_CryptoKeyPair *keyCtx);

/**
 * @brief Encode the public key.
 *
 * @param key Indicates the public key.
 * @param type Indicates the pubkey type.
 * @param encodingStandard Indicates the encoding standard .
 * @param out Indicates the encoded result.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoPubKey_Encode(OH_CryptoPubKey *key, Crypto_EncodingType type,
    const char *encodingStandard, Crypto_DataBlob *out);

/**
 * @brief Get the specified param of the public key.
 *
 * @param key Indicates the public key.
 * @param item Indicates the asymmetric key param type.
 * @param value Indicates the output data.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoPubKey_GetParam(OH_CryptoPubKey *key, CryptoAsymKey_ParamType item, Crypto_DataBlob *value);

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* CRYPTO_ASYM_KEY_H */
