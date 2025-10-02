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
 * @addtogroup CryptoCommonApi
 * @{
 *
 * @brief Describe openHarmony crypto common interfaces provide for applications.
 *
 * @since 12
 */

/**
 * @file crypto_common.h
 *
 * @brief Defines the crypto common APIs.
 *
 * @library libohcrypto.so
 * @kit CryptoArchitectureKit
 * @syscap SystemCapability.Security.CryptoFramework
 * @since 12
 */

#ifndef CRYPTO_COMMON_H
#define CRYPTO_COMMON_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Crypto data struct.
 *
 * @since 12
 */
typedef struct Crypto_DataBlob {
    /** Data buffer. */
    uint8_t *data;
    /** Data length. */
    size_t len;
} Crypto_DataBlob;

/**
 * @brief Enumerates the error codes.
 *
 * @since 12
 */
typedef enum {
    /** Indicates that crypto operation success. */
    CRYPTO_SUCCESS = 0,
    /** Indicates that input parameters is invalid. */
    CRYPTO_INVALID_PARAMS = 401,
    /** Indicates that function or algorithm is not supported. */
    CRYPTO_NOT_SUPPORTED = 801,
    /** Indicates the memory error. */
    CRYPTO_MEMORY_ERROR = 17620001,
    /** Indicates that crypto operation error. */
    CRYPTO_OPERTION_ERROR = 17630001,
} OH_Crypto_ErrCode;

/**
 * @brief Define crypto cipher mode.
 *
 * @since 12
 */
typedef enum {
    /** Indicates encryption operation. */
    CRYPTO_ENCRYPT_MODE = 0,
    /** Indicates decryption operation. */
    CRYPTO_DECRYPT_MODE = 1,
} Crypto_CipherMode;

/**
 * @brief Free the data of dataBlob.
 *
 * @param dataBlob Indicates the data blob.
 * @since 12
 */
void OH_Crypto_FreeDataBlob(Crypto_DataBlob *dataBlob);

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* CRYPTO_COMMON_H */