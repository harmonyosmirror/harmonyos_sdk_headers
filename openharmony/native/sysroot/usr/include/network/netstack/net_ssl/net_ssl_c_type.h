/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
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

#ifndef NET_SSL_C_TYPE_H
#define NET_SSL_C_TYPE_H

/**
 * @addtogroup netstack
 * @{
 *
 * @brief Provides C APIs for the SSL/TLS certificate chain verification module.
 *
 * @since 11
 * @version 1.0
 */

/**
 * @file net_ssl_c_type.h
 * @brief Defines the data structures for the C APIs of the SSL/TLS certificate chain verification module.
 *
 * @library libnet_ssl.so
 * @kit NetworkKit
 * @syscap SystemCapability.Communication.NetStack
 * @since 11
 * @version 1.0
 */

#include <stdint.h>
#include <cstddef>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates certificate types.
 *
 * @since 11
 * @version 1.0
 */
enum NetStack_CertType {
    /** PEM certificate */
    NETSTACK_CERT_TYPE_PEM = 0,
    /** DER certificate */
    NETSTACK_CERT_TYPE_DER = 1,
    /** Invalid certificate */
    NETSTACK_CERT_TYPE_INVALID
};

/**
 * @brief Defines the certificate data structure.
 *
 * @since 11
 * @version 1.0
 */
struct NetStack_CertBlob {
    /** Certificate type */
    enum NetStack_CertType type;
    /** Certificate content length */
    uint32_t size;
    /** Certificate content */
    uint8_t *data;
};

/**
 * @brief Defines the certificate lock type.
 *
 * @since 12
 * @version 1.0
 */
typedef enum NetStack_CertificatePinningKind {
    /** Public key pinning */
    PUBLIC_KEY,
} NetStack_CertificatePinningKind;

/**
 * @brief Defines the hash algorithm.
 *
 * @since 12
 * @version 1.0
 */
typedef enum NetStack_HashAlgorithm {
    /** Sha256 */
    SHA_256,
} NetStack_HashAlgorithm;

/**
 * @brief Defines the certificate lock information.
 *
 * @since 12
 * @version 1.0
 */
typedef struct NetStack_CertificatePinning {
    /** Certificate lock type */
    NetStack_CertificatePinningKind kind;
    /** Hash algorithm */
    NetStack_HashAlgorithm hashAlgorithm;
    /** Hash value */
    union {
        char *publicKeyHash;
    };
} NetStack_CertificatePinning;

/**
 * @brief Defines the certificate information.
 *
 * @since 12
 * @version 1.0
 */
typedef struct NetStack_Certificates {
    /** PEM content of the certificates */
    char **content;
    /** Number of certificates */
    size_t length;
} NetStack_Certificates;

#ifdef __cplusplus
}
#endif

#endif // NET_SSL_C_TYPE_H
