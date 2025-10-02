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
 * @addtogroup CryptoSignatureApi
 * @{
 *
 * @brief Describe openHarmony signature verification interfaces provide for applications.
 *
 * @since 12
 */

/**
 * @file crypto_signature.h
 *
 * @brief Defines the Signature APIs.
 *
 * @library libohcrypto.so
 * @kit CryptoArchitectureKit
 * @syscap SystemCapability.Security.CryptoFramework
 * @since 12
 */

#ifndef CRYPTO_SIGNATURE_H
#define CRYPTO_SIGNATURE_H

#include "crypto_common.h"
#include "crypto_asym_key.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Define the signature param type.
 *
 * @since 12
 */
typedef enum {
    /** Indicates the algorithm name of the message digest function.*/
    CRYPTO_PSS_MD_NAME_STR = 100,
    /** Indicates the algorithm name for the mask generation function. */
    CRYPTO_PSS_MGF_NAME_STR = 101,
    /** Indicates the message digest parameter for the MGF1 mask generation function. */
    CRYPTO_PSS_MGF1_NAME_STR = 102,
    /** Indicates the salt length in bits. */
    CRYPTO_PSS_SALT_LEN_INT = 103,
    /** Indicates the value for the trailer field. */
    CRYPTO_PSS_TRAILER_FIELD_INT = 104,
    /** Indicates the value for user id. */
    CRYPTO_SM2_USER_ID_DATABLOB = 105,
} CryptoSignature_ParamType;

/**
 * @brief Define the verify structure.
 *
 * @since 12
 */
typedef struct OH_CryptoVerify OH_CryptoVerify;

/**
 * @brief Create a verify context according to the given algorithm name.
 *
 * @param algoName Indicates the algorithm name for generating the verify context. Example RSA1024|PKCS1|SHA256.
 * @param ctx Indicates the pointer to the verify context.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoVerify_Create(const char *algoName, OH_CryptoVerify **verify);

/**
 * @brief Init verify context with given public Key.
 *
 * @param ctx Indicates the verify context.
 * @param pubKey indicates the public Key
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @see OH_CryptoVerify_Update
 * @see OH_CryptoVerify_Final
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoVerify_Init(OH_CryptoVerify *ctx, OH_CryptoPubKey *pubKey);

/**
 * @brief Used to append the message that needs to be verified.
 *
 * @param ctx Indicates the verify context.
 * @param in Indicates the data need to be verified.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @see OH_CryptoVerify_Init
 * @see OH_CryptoVerify_Final
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoVerify_Update(OH_CryptoVerify *ctx, Crypto_DataBlob *in);

/**
 * @brief Used to verify the message.
 *
 * @param ctx Indicates the verify context.
 * @param in Indicates the data need to be verified.
 * @param signData Indicates the signature data.
 * @return Return result use bool value.
 * @see OH_CryptoVerify_Init
 * @see OH_CryptoVerify_Update
 * @since 12
 */
bool OH_CryptoVerify_Final(OH_CryptoVerify *ctx, Crypto_DataBlob *in, Crypto_DataBlob *signData);

/**
 * @brief Used to recover signed data.
 *
 * @param ctx Indicates the verify context.
 * @param signData Indicates the signature data.
 * @param rawSignData Indicates the raw sign data.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoVerify_Recover(OH_CryptoVerify *ctx, Crypto_DataBlob *signData,
    Crypto_DataBlob *rawSignData);

/**
 * @brief Get the algorithm name of the verify context.
 *
 * @param ctx Indicates the verify context.
 * @return Return verify algorithm name.
 * @since 12
 */
const char *OH_CryptoVerify_GetAlgoName(OH_CryptoVerify *ctx);

/**
 * @brief Set the specified parameter to the verify context.
 *
 * @param ctx Indicates the verify context.
 * @param type Indicates the verify signature_paramType.
 * @param value Indicates the verify result.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoVerify_SetParam(OH_CryptoVerify *ctx, CryptoSignature_ParamType type,
    Crypto_DataBlob *value);

/**
 * @brief Get the specified parameter from the verify context.
 *
 * @param ctx Indicates the verify context.
 * @param type Indicates the verify signature_paramType.
 * @param value Indicates the verify result.
 * @return {@link OH_Crypto_ErrCode#CRYPTO_SUCCESS} 0 - If the operation is successful.
 *         {@link OH_Crypto_ErrCode#CRYPTO_INVALID_PARAMS} 401 - If parameter is invalid.
 *         {@link OH_Crypto_ErrCode#CRYPTO_NOT_SUPPORTED} 801 - If the operation is not supported.
 *         {@link OH_Crypto_ErrCode#CRYPTO_MEMORY_ERROR} 17620001 - If memory operation failed.
 *         {@link OH_Crypto_ErrCode#CRYPTO_OPERTION_ERROR} 17630001 - If crypto opertion failed.
 * @since 12
 */
OH_Crypto_ErrCode OH_CryptoVerify_GetParam(OH_CryptoVerify *ctx, CryptoSignature_ParamType type,
    Crypto_DataBlob *value);

/**
 * @brief Destroy the verify context.
 *
 * @param ctx Indicates the verify context.
 * @since 12
 */
void OH_CryptoVerify_Destroy(OH_CryptoVerify *ctx);

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* CRYPTO_SIGNATURE_H */
