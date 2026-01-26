/*
 * Copyright (c) 2025 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License"),
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
 * @file cm_native_type.h
 *
 * @brief Defines the structure and enumeration.
 *
 * @library libohcert_manager.so
 * @kit DeviceCertificateKit
 * @syscap SystemCapability.Security.CertificateManager
 * @since 22
 */

/**
 * @addtogroup CertManagerType
 * @{
 *
 * @brief Defines the macros, enumerated values, data structures,
 *    and error codes used by OpenHarmony Certificate Manager APIs.
 *
 * @since 22
 */

#ifndef CM_NATIVE_TYPE_H
#define CM_NATIVE_TYPE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define OH_CM_MAX_LEN_CERTIFICATE_CHAIN   24588
#define OH_CM_MAX_LEN_URI              256
#define OH_CM_MAX_LEN_CERT_ALIAS       129
#define OH_CM_MAX_LEN_TYPE_NAME       1025

/**
 * @brief Enumerates the error codes.
 *
 * @since 22
 */
typedef enum {
    /**
     * The operation is successful.
     */
    OH_CM_SUCCESS = 0,
    /**
     *  Indicates that the application has no permission to call the API.
     */
    OH_CM_HAS_NO_PERMISSION = 201,
    /**
     * Capability not supported.
     */
    OH_CM_CAPABILITY_NOT_SUPPORTED = 801,
    /**
     * Indicates that internal error. Possible causes: 1. IPC communication failed;
     * 2. Memory operation error; 3. File operation error.
     */
    OH_CM_INNER_FAILURE = 17500001,
    /**
     * Indicates that the certificate does not exist.
     */
    OH_CM_NOT_FOUND = 17500002,
    /**
     * Indicates that the keystore is in an invalid format or the keystore password is incorrect.
     */
    OH_CM_INVALID_CERT_FORMAT = 17500003,
    /**
     * Indicates that the number of certificates or credentials reaches the maximum allowed.
     */
    OH_CM_MAX_CERT_COUNT_REACHED = 17500004,
    /**
     *  Indicates that the application is not authorized by the user.
     */
    OH_CM_NO_AUTHORIZATION = 17500005,
    /**
     * Indicates that the device enters advanced security mode.
     */
    OH_CM_DEVICE_ENTER_ADVSECMODE = 17500007,
    /**
     * Indicates that the device does not support the specified certificate store path.
     */
    OH_CM_STORE_PATH_NOT_SUPPORTED = 17500009,
    /**
     * Indicates that access USB key service failed.
     */
    OH_CM_ACCESS_UKEY_SERVICE_FAILED = 17500010,
    /**
     * Indicates that the input parameters validation failed.
     * for example, the parameter format is incorrect or the value range is invalid.
     */
    OH_CM_PARAMETER_VALIDATION_FAILED = 17500011
} OH_CM_ErrorCode;

/**
 * @brief Enumerates the certificate purpose.
 *
 * @since 22
 */
typedef enum {
    /**
     * Indicates the default purpose.
     */
    OH_CM_CERT_PURPOSE_DEFAULT = 0,
    /**
     * Indicates all certificate purpose, used for query certificates function.
     */
    OH_CM_CERT_PURPOSE_ALL = 1,
    /**
     * Indicates certificate for signature.
     */
    OH_CM_CERT_PURPOSE_SIGN = 2,
    /**
     *  Indicates certificate for encrypt.
     */
    OH_CM_CERT_PURPOSE_ENCRYPT = 3
} OH_CM_CertificatePurpose;

/**
 * @brief Defines the structure for storing data.
 *
 * @since 22
 */
typedef struct {
    /**
     * Data size.
     */
    uint32_t size;
    /**
     * Pointer to the memory in which the data is stored.
     */
    uint8_t *data;
} OH_CM_Blob;

/**
 * @brief Defines the structure for certificate detail of credential .
 *
 * @since 22
 */
typedef struct {
    /**
     * Indicates whether the credential contains certificate data.
     */
    uint32_t isExist;
    /**
     * Indicates the type of Credential. The value include the terminator('\0')  char.
     */
    char type[OH_CM_MAX_LEN_TYPE_NAME];
    /**
     * Indicates the alias of Credential. The value include the terminator('\0')  char.
     */
    char alias[OH_CM_MAX_LEN_CERT_ALIAS];
    /**
     * Indicates the uri of Credential.
     */
    char keyUri[OH_CM_MAX_LEN_URI];
    /**
     * Indicates the number of certificates included in the credential.
     */
    uint32_t certNum;
    /**
     * Indicates the number of key included in the credential.
     */
    uint32_t keyNum;
    /**
     * Indicates the certificate binary data which max length is defined by OH_CM_MAX_LEN_CERTIFICATE_CHAIN.
     */
    OH_CM_Blob credData;
    /**
     * Indicates the certificate purpose.
     */
    OH_CM_CertificatePurpose certPurpose;
} OH_CM_Credential;

/**
 * @brief Defines credential detail list .
 *
 * @since 22
 */
typedef struct {
    /**
     * Indicates the credential count.
     */
    uint32_t credentialCount;
    /**
     * Indicates the credential data.
     */
    OH_CM_Credential *credential;
} OH_CM_CredentialDetailList;

/**
 * @brief Defines the USB key certificate attribute information.
 *
 * @since 22
 */
typedef struct {
    /**
     * Indicates the purpose of certificate.
     */
    OH_CM_CertificatePurpose certPurpose;
} OH_CM_UkeyInfo;

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* CM_NATIVE_TYPE_H */