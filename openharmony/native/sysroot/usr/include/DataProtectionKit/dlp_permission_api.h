/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
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
 * @addtogroup DlpPermissionApi
 * @{
 *
 * @brief Provides the capability to access the data loss prevention (DLP) files.
 *
 * @since 14
 */

/**
 * @file dlp_permission_api.h
 *
 * @brief Declares the APIs for accessing the data loss prevention (DLP) files.
 *
 * @library libohdlp_permission.so
 * @kit DataProtectionKit
 * @syscap SystemCapability.Security.DataLossPrevention
 * @since 14
 */

#ifndef DLP_PERMISSION_API_H
#define DLP_PERMISSION_API_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates the error codes.
 *
 * @since 14
 */
typedef enum {
    /** @error The operation is successful. */
    ERR_OH_SUCCESS = 0,
    /** @error Invalid parameter value. */
    ERR_OH_INVALID_PARAMETER = 19100001,
    /** @error No permission to call this API, which is available only for DLP sandbox applications. */
    ERR_OH_API_ONLY_FOR_SANDBOX = 19100006,
    /** @error No permission to call this API, which is available only for non-DLP sandbox applications. */
    ERR_OH_API_NOT_FOR_SANDBOX = 19100007,
    /** @error The system ability works abnormally. */
    ERR_OH_SYSTEM_SERVICE_EXCEPTION = 19100011,
    /** @error Indicates the memory error. */
    ERR_OH_OUT_OF_MEMORY = 19100012,
    /** @error DisplayName missing in want. */
    ERR_OH_APPLICATION_NOT_AUTHORIZED = 19100018
} DLP_ErrCode;

/**
 * @brief Enumerates the access permissions for a DLP file.
 *
 * @since 14
 */
typedef enum {
    /** No permission. */
    NO_PERMISSION = 0,
    /** Read-only. */
    READ_ONLY = 1,
    /** Edit. */
    CONTENT_EDIT = 2,
    /** Full control. */
    FULL_CONTROL = 3
} DLP_FileAccess;

/**
 * @brief Obtains the permission info of this DLP file.
 *
 * @param dlpFileAccess - Indicates the access permission for the DLP file.
 * @param flags - Indicates the actions allowed for the DLP file.
 *              0x00000000 - No file permissions.
 *              0x00000001 - File view permission.
 *              0x00000002 - File save permission.
 *              0x00000004 - File save-as permission.
 *              0x00000008 - File edit permission.
 *              0x00000010 - File screenshot permission.
 *              0x00000020 - File screen-sharing permission.
 *              0x00000040 - File screen-recording permission.
 *              0x00000080 - File copy permission.
 *              0x00000100 - File print permission.
 *              0x00000200 - File export permission.
 *              0x00000400 - File permission modification permission.
 * @return {@link DLP_ErrCode#ERR_OH_SUCCESS} 0 - If the operation is successful.
 *         {@link DLP_ErrCode#ERR_OH_INVALID_PARAMETER} 19100001 - If the parameter value is invalid.
 *         {@link DLP_ErrCode#ERR_OH_API_ONLY_FOR_SANDBOX} 19100006 - If no permission to
 *             call this API, which is available only for DLP sandbox applications.
 *         {@link DLP_ErrCode#ERR_OH_SYSTEM_SERVICE_EXCEPTION} 19100011 - If the system ability
 *             works abnormally.
 *         {@link DLP_ErrCode#ERR_OH_OUT_OF_MEMORY} 19100012 - If the memory error.
 * @since 14
 */
DLP_ErrCode OH_DLP_GetDlpPermissionInfo(DLP_FileAccess *dlpFileAccess, uint32_t *flags);

/**
 * @brief Obtains the original file name from a DLP file name.
 *        This method removes the DLP file name extension from the DLP file name.
 *
 * @param fileName - Indicates the DLP file name.
 * @param originalFileName - Indicates the original file name obtained.
 * @return {@link DLP_ErrCode#ERR_OH_SUCCESS} 0 - If the operation is successful.
 *         {@link DLP_ErrCode#ERR_OH_INVALID_PARAMS} 19100001 - If the parameter value is invalid.
 *         {@link DLP_ErrCode#ERR_OH_OUT_OF_MEMORY} 19100012 - If the memory error.
 * @since 14
 */
DLP_ErrCode OH_DLP_GetOriginalFileName(const char *fileName, char **originalFileName);

/**
 * @brief Checks whether current application is in the DLP sandbox.
 *
 * @param isInSandbox - Indicates output parameter,
 *                      {@code true} if current application is in a DLP sandbox, {@code false} otherwise.
 * @return {@link DLP_ErrCode#ERR_OH_SUCCESS} 0 - If the operation is successful.
 *         {@link DLP_ErrCode#ERR_OH_SYSTEM_SERVICE_EXCEPTION} 19100011 - If the system ability
 *             works abnormally.
 *         {@link DLP_ErrCode#ERR_OH_OUT_OF_MEMORY} 19100012 - If the memory error.
 * @since 14
 */
DLP_ErrCode OH_DLP_IsInSandbox(bool *isInSandbox);

/**
 * @brief Sets sandbox application configuration.
 *
 * @param configInfo - Configuration of the sandbox application.
 * @return {@link DLP_ErrCode#ERR_OH_SUCCESS} 0 - If the operation is successful.
 *         {@link DLP_ErrCode#ERR_OH_INVALID_PARAMETER} 19100001 - If the parameter value is invalid.
 *         {@link DLP_ErrCode#ERR_OH_API_NOT_FOR_SANDBOX} 19100007 - If no permission to
 *             call this API, which is available only for non-DLP sandbox applications.
 *         {@link DLP_ErrCode#ERR_OH_SYSTEM_SERVICE_EXCEPTION} 19100011 - If the system ability
 *             works abnormally.
 *         {@link DLP_ErrCode#ERR_OH_APPLICATION_NOT_AUTHORIZED} 19100018 - If the application is not authorized.
 * @since 14
 */
DLP_ErrCode OH_DLP_SetSandboxAppConfig(const char *configInfo);

/**
 * @brief Obtains sandbox application configuration.
 *
 * @param configInfo - Configuration of the sandbox application.
 * @return {@link DLP_ErrCode#ERR_OH_SUCCESS} 0 - If the operation is successful.
 *         {@link DLP_ErrCode#ERR_OH_SYSTEM_SERVICE_EXCEPTION} 19100011 - If the system ability
 *             works abnormally.
 *         {@link DLP_ErrCode#ERR_OH_OUT_OF_MEMORY} 19100012 - If the memory error.
 *         {@link DLP_ErrCode#ERR_OH_APPLICATION_NOT_AUTHORIZED} 19100018 - If the application is not authorized.
 * @since 14
 */
DLP_ErrCode OH_DLP_GetSandboxAppConfig(char **configInfo);

/**
 * @brief Cleans sandbox application configuration.
 *
 * @return {@link DLP_ErrCode#ERR_OH_SUCCESS} 0 - If the operation is successful.
 *         {@link DLP_ErrCode#ERR_OH_API_NOT_FOR_SANDBOX} 19100007 - If no permission to
 *             call this API, which is available only for non-DLP sandbox applications.
 *         {@link DLP_ErrCode#ERR_OH_SYSTEM_SERVICE_EXCEPTION} 19100011 - If the system ability
 *             works abnormally.
 *         {@link DLP_ErrCode#ERR_OH_APPLICATION_NOT_AUTHORIZED} 19100018 - If the application is not authorized.
 * @since 14
 */
DLP_ErrCode OH_DLP_CleanSandboxAppConfig();

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* DLP_PERMISSION_API_H */