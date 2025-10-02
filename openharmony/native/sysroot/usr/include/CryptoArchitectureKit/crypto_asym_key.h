/*
 * Copyright (C) 2024-2025 Huawei Device Co., Ltd.
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
 * @brief Define the public key structure.
 *
 * @since 12
 */
typedef struct OH_CryptoPubKey OH_CryptoPubKey;

/**
 * @brief Defines the private key structure.
 *
 * @since 20
 */
typedef struct OH_CryptoPrivKey OH_CryptoPrivKey;

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
 * @brief Gets the private key of the key pair.
 *
 * @param keyCtx Indicates the keyPair context.
 * @return Return the private key context from the key pair.
 * @since 20
 */
OH_CryptoPrivKey *OH_CryptoKeyPair_GetPrivKey(OH_CryptoKeyPair *keyCtx);

/**
 * @brief Encode the public key.
 *
 * @param key Indicates the public key.
 * @param type Indicates the pubkey type.
 * @param encodingStandard Indicates the encoding standard.
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

/**
 * @brief Sets the password to the asymmetric key generator context.
 *
 * Call this method to set the password if you need to convert encrypted private key data to a key pair using
 * {@link OH_CryptoAsymKeyGenerator_Convert}.\n
 *
 * @param ctx Indicates the asymmetric key generator context.
 * @param password Indicates the password.
 * @param passwordLen Indicates the password length.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_SetPassword(OH_CryptoAsymKeyGenerator *ctx, const unsigned char *password,
    uint32_t passwordLen);

/**
 * @brief Defines the private key encoding params structure.
 *
 * @since 20
 */
typedef struct OH_CryptoPrivKeyEncodingParams OH_CryptoPrivKeyEncodingParams;

/**
 * @brief Defines the private key encoding param type.
 *
 * @since 20
 */
typedef enum {
    /** Indicates the password string. */
    CRYPTO_PRIVATE_KEY_ENCODING_PASSWORD_STR = 0,

    /** Indicates the symmetric cipher string. */
    CRYPTO_PRIVATE_KEY_ENCODING_SYMMETRIC_CIPHER_STR = 1,
} CryptoPrivKeyEncoding_ParamType;

/**
 * @brief Creates private key encoding params.
 *
 * @param ctx Indicates the private key encoding params.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoPrivKeyEncodingParams_Create(OH_CryptoPrivKeyEncodingParams **ctx);

/**
 * @brief Sets the private key encoding params.
 *
 * @param ctx Indicates the private key encoding params.
 * @param type Indicates the private key encoding param type.
 * @param value Indicates the private key encoding params value.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoPrivKeyEncodingParams_SetParam(OH_CryptoPrivKeyEncodingParams *ctx,
    CryptoPrivKeyEncoding_ParamType type, Crypto_DataBlob *value);

/**
 * @brief Destroys the private key encoding params.
 *
 * @param ctx Indicates the private key encoding params.
 * @since 20
 */
void OH_CryptoPrivKeyEncodingParams_Destroy(OH_CryptoPrivKeyEncodingParams *ctx);

/**
 * @brief Encodes the private key.
 *
 * @param key Indicates the private key.
 * @param type Indicates the private encoding type.
 * @param encodingStandard Indicates the encoding standard, such as "PKCS8".
 * @param params Indicates the private key encoding params, it can be NULL, and if you want encypt the private key,
 * you should set this param.
 * @param out Indicates the encoded result.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoPrivKey_Encode(OH_CryptoPrivKey *key, Crypto_EncodingType type,
    const char *encodingStandard, OH_CryptoPrivKeyEncodingParams *params, Crypto_DataBlob *out);

/**
 * @brief Gets the specified param of the private key.
 *
 * @param key Indicates the private key.
 * @param item Indicates the asymmetric key param type.
 * @param value Indicates the output data.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoPrivKey_GetParam(OH_CryptoPrivKey *key, CryptoAsymKey_ParamType item,
    Crypto_DataBlob *value);

/**
 * @brief Defines the asymmetric key spec structure.
 *
 * @since 20
 */
typedef struct OH_CryptoAsymKeySpec OH_CryptoAsymKeySpec;

/**
 * @brief Defines the asymmetric key spec type.
 *
 * @since 20
 */
typedef enum {
    /** Common parameters spec. */
    CRYPTO_ASYM_KEY_COMMON_PARAMS_SPEC = 0,
    /** Private key spec. */
    CRYPTO_ASYM_KEY_PRIVATE_KEY_SPEC = 1,
    /** Public key spec. */
    CRYPTO_ASYM_KEY_PUBLIC_KEY_SPEC = 2,
    /** Key pair spec. */
    CRYPTO_ASYM_KEY_KEY_PAIR_SPEC = 3,
} CryptoAsymKeySpec_Type;

/**
 * @brief Generates an EC common parameters spec.
 *
 * @param curveName Indicates the ECC curve name.
 * @param spec Indicates the pointer to the EC common parameters spec.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GenEcCommonParamsSpec(const char *curveName, OH_CryptoAsymKeySpec **spec);

/**
 * @brief Generates a DH common parameters spec.
 *
 * @param pLen Indicates the byte length of the prime p.
 * @param skLen Indicates the byte length of the private key.
 * @param spec Indicates the pointer to the DH common parameters spec.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GenDhCommonParamsSpec(int pLen, int skLen, OH_CryptoAsymKeySpec **spec);

/**
 * @brief Creates an asymmetric key spec according to the given algorithm name and spec type.
 *
 * @param algoName Indicates the algorithm name for generating the spec. Example RSA.
 * @param type Indicates the asymmetric key spec type.
 * @param spec Indicates the pointer to the asymmetric key spec.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_Create(const char *algoName, CryptoAsymKeySpec_Type type,
    OH_CryptoAsymKeySpec **spec);

/**
 * @brief Sets the specified parameter to the asymmetric key spec.
 *
 * @param spec Indicates the asymmetric key spec.
 * @param type Indicates the asymmetric key param type.
 * @param value Indicates the input data.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_SetParam(OH_CryptoAsymKeySpec *spec, CryptoAsymKey_ParamType type,
    Crypto_DataBlob *value);

/**
 * @brief Sets the common parameters spec to the asymmetric key spec.
 *
 * @param spec Indicates the asymmetric key spec.
 * @param commonParamsSpec Indicates the common parameters spec.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_SetCommonParamsSpec(OH_CryptoAsymKeySpec *spec,
    OH_CryptoAsymKeySpec *commonParamsSpec);

/**
 * @brief Gets the specified parameter from the asymmetric key spec.
 *
 * @param spec Indicates the asymmetric key spec.
 * @param type Indicates the asymmetric key param type.
 * @param value Indicates the output data.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GetParam(OH_CryptoAsymKeySpec *spec, CryptoAsymKey_ParamType type,
    Crypto_DataBlob *value);

/**
 * @brief Destroys the asymmetric key spec.
 *
 * @param spec Indicates the asymmetric key spec.
 * @since 20
 */
void OH_CryptoAsymKeySpec_Destroy(OH_CryptoAsymKeySpec *spec);

/**
 * @brief Defines the asymmetric key generator with spec.
 *
 * @since 20
 */
typedef struct OH_CryptoAsymKeyGeneratorWithSpec OH_CryptoAsymKeyGeneratorWithSpec;

/**
 * @brief Creates an asymmetric key generator with spec.
 *
 * @param keySpec Indicates the asymmetric key spec.
 * @param generator Indicates the asymmetric key generator with spec.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoAsymKeyGeneratorWithSpec_Create(OH_CryptoAsymKeySpec *keySpec,
    OH_CryptoAsymKeyGeneratorWithSpec **generator);

/**
 * @brief Generates a key pair according to the asymmetric key spec.
 *
 * @param generator Indicates the asymmetric key generator with spec.
 * @param keyPair Indicates the pointer to the key pair.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair(OH_CryptoAsymKeyGeneratorWithSpec *generator,
    OH_CryptoKeyPair **keyPair);

/**
 * @brief Destroys the asymmetric key generator with spec.
 *
 * @param generator Indicates the asymmetric key generator with spec.
 * @since 20
 */
void OH_CryptoAsymKeyGeneratorWithSpec_Destroy(OH_CryptoAsymKeyGeneratorWithSpec *generator);

/**
 * @brief Defines the EC point structure.
 *
 * @since 20
 */
typedef struct OH_CryptoEcPoint OH_CryptoEcPoint;

/**
 * @brief Creates an EC point.
 *
 * @param curveName Indicates the curve name.
 * @param ecKeyData Indicates the EC point data, supports "04 || x || y", "02 || x" or "03 || x" format.
 * If ecKeyData param is NULL, an empty EC point spec will be created.
 * @param point Indicates the pointer to the EC point.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoEcPoint_Create(const char *curveName, Crypto_DataBlob *ecKeyData, OH_CryptoEcPoint **point);

/**
 * @brief Gets the x and y coordinate of the EC point.
 *
 * @param point Indicates the EC point.
 * @param x Indicates the x coordinate of the EC point, it can be NULL.
 * @param y Indicates the y coordinate of the EC point, it can be NULL.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoEcPoint_GetCoordinate(OH_CryptoEcPoint *point, Crypto_DataBlob *x, Crypto_DataBlob *y);

/**
 * @brief Sets the x and y coordinate to the EC point.
 *
 * @param point Indicates the EC point.
 * @param x Indicates the x coordinate of the EC point.
 * @param y Indicates the y coordinate of the EC point.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoEcPoint_SetCoordinate(OH_CryptoEcPoint *point, Crypto_DataBlob *x, Crypto_DataBlob *y);

/**
 * @brief Encodes the EC point to the specified format.
 *
 * @param point Indicates the EC point.
 * @param format Indicates the encoding format, supports "UNCOMPRESSED" and "COMPRESSED".
 * @param out Indicates the encoded ec point data.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_PARAMETER_CHECK_FAILED} 17620003 - If parameter check failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto operation failed.
 * @since 20
 */
OH_Crypto_ErrCode OH_CryptoEcPoint_Encode(OH_CryptoEcPoint *point, const char *format, Crypto_DataBlob *out);

/**
 * @brief Destroys the EC point.
 *
 * @param point Indicates the EC point.
 * @since 20
 */
void OH_CryptoEcPoint_Destroy(OH_CryptoEcPoint *point);

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* CRYPTO_ASYM_KEY_H */
