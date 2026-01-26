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
 * @file cm_native_api.h
 *
 * @brief Defines the Certificate Manager APIs.
 *
 * @library libohcert_manager.so
 * @kit DeviceCertificateKit
 * @syscap SystemCapability.Security.CertificateManager
 * @since 22
 */

/**
 * @addtogroup CertManager
 * @{
 *
 * @brief Describes the OpenHarmony Certificate Manager capabilities, including certificate and credential management
 *    operations, provided for applications.
 *
 * @since 22
 */

#ifndef CM_NATIVE_API_H
#define CM_NATIVE_API_H

#include "info/application_target_sdk_version.h"
#include "cm_native_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get the detail of USB key certificate.
 *
 * @param keyUri Indicates the USB key certificate uri.
 * @param ukeyInfo Indicates USB key certificate attribute information.
 * @param certificateList Indicates the detail information of USB key certificate.
 * @return {@link OH_CM_ErrorCode#OH_CM_SUCCESS} 0 - The operation is successful.
 *         {@link OH_CM_ErrorCode#OH_CM_HAS_NO_PERMISSION} 201 - Permission verification failed.
 *         {@link OH_CM_ErrorCode#OH_CM_CAPABILITY_NOT_SUPPORTED} 801 - Capability not supported.
 *         {@link OH_CM_ErrorCode#OH_CM_PARAMETER_VALIDATION_FAILED} 17500011 - Indicates that the
 *    input parameters validation failed. for example, the parameter format is incorrect or the value range is invalid.
 *         {@link OH_CM_ErrorCode#OH_CM_INNER_FAILURE} 17500001 - Internal error. Possible causes:
 *    1. IPC communication failed; 2. Memory operation error; 3. File operation error.
 *         {@link OH_CM_ErrorCode#OH_CM_NOT_FOUND} 17500002 - Indicates that the certificate does not exist.
 *         {@link OH_CM_ErrorCode#OH_CM_ACCESS_UKEY_SERVICE_FAILED} 17500010 - Indicates that
 *    access USB key service failed.
 * @permission ohos.permission.ACCESS_CERT_MANAGER
 * @since 22
 */
int32_t OH_CertManager_GetUkeyCertificate(const OH_CM_Blob *keyUri,
    const OH_CM_UkeyInfo *ukeyInfo, OH_CM_CredentialDetailList *certificateList)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Get the detail of application private certificate.
 *
 * @param keyUri Indicates the private certificate uri.
 * @param certificate Indicates the detail information of private certificate.
 * @return {@link OH_CM_ErrorCode#OH_CM_SUCCESS} 0 - The operation is successful.
 *         {@link OH_CM_ErrorCode#OH_CM_HAS_NO_PERMISSION} 201 - Permission verification failed.
 *         {@link OH_CM_ErrorCode#OH_CM_PARAMETER_VALIDATION_FAILED} 17500011 - Indicates that the input
 *    parameters validation failed. for example, the parameter format is incorrect or the value range is invalid.
 *         {@link OH_CM_ErrorCode#OH_CM_INNER_FAILURE} 17500001 - Internal error. Possible causes:
 *    1. IPC communication failed; 2. Memory operation error; 3. File operation error.
 *         {@link OH_CM_ErrorCode#OH_CM_NOT_FOUND} 17500002 - Indicates that the certificate does not exist.
 * @permission ohos.permission.ACCESS_CERT_MANAGER
 * @since 22
 */
int32_t OH_CertManager_GetPrivateCertificate(const OH_CM_Blob *keyUri, OH_CM_Credential *certificate)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Get the detail of user public certificate.
 *
 * @param keyUri Indicates the private certificate uri.
 * @param certificate Indicates the detail information of public certificate.
 * @return {@link OH_CM_ErrorCode#OH_CM_SUCCESS} 0 - The operation is successful.
 *         {@link OH_CM_ErrorCode#OH_CM_HAS_NO_PERMISSION} 201 - Permission verification failed.
 *         {@link OH_CM_ErrorCode#OH_CM_PARAMETER_VALIDATION_FAILED} 17500011 - Indicates that the input
 *    parameters validation failed. for example, the parameter format is incorrect or the value range is invalid.
 *         {@link OH_CM_ErrorCode#OH_CM_INNER_FAILURE} 17500001 - Internal error. Possible causes:
 *    1. IPC communication failed; 2. Memory operation error; 3. File operation error.
 *         {@link OH_CM_ErrorCode#OH_CM_NOT_FOUND} 17500002 - Indicates that the certificate does not exist.
 *         {@link OH_CM_ErrorCode#OH_CM_NO_AUTHORIZATION} 17500005 - The application is not authorized by the user.
 * @permission ohos.permission.ACCESS_CERT_MANAGER
 * @since 22
 */
int32_t OH_CertManager_GetPublicCertificate(const OH_CM_Blob *keyUri, OH_CM_Credential *certificate)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Destroys a credential detail list.
 *
 * @param certificateList Indicates the pointer to the credential detail list to destroy.
 * @since 22
 */
void OH_CertManager_FreeUkeyCertificate(OH_CM_CredentialDetailList *certificateList)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Destroys a credential detail.
 *
 * @param certificate Indicates the pointer to the credential detail to destroy.
 * @since 22
 */
void OH_CertManager_FreeCredential(OH_CM_Credential *certificate)
__attribute__((__availability__(ohos, introduced=22.0.0)));

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* CM_NATIVE_API_H */