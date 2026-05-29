/*
 * Copyright (c) 2026-2026 Huawei Device Co., Ltd.
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
 * @addtogroup ContentEmbed
 * @{
 *
 * @file content_embed_common.h
 *
 * @brief Declare the common types for the native ContentEmbed.
 *
 * @library libcontent_embed_ndk.so
 * @kit ContentEmbedKit
 * @syscap SystemCapability.ContentEmbed.ObjectEditor
 * @since 24
 */

#ifndef OHOS_CONTENT_EMBED_COMMON_H
#define OHOS_CONTENT_EMBED_COMMON_H

#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @brief The maximum length of an oeid.
 *
 * @since 24
 */
#define MAX_OEID_LENGTH (1 * 40)

/**
 * @brief The value type of command data.
 *
 * @since 24
 */
typedef enum ContentEmbed_ErrorCode {
    /**
     * @brief The error code in the correct case.
     * @since 24
     */
    CE_ERR_OK = 0,
    /**
     * @error The error code when permission verification failed.
     * @since 24
     */
    CE_PERMISSION_DENIED = 201,
    /**
     * @brief The error code when parameter check failed.
     * @since 24
     */
    CE_ERR_PARAM_INVALID = 401,
    /**
     * @brief The error code when the device is not supported.
     * @since 24
     */
    CE_ERR_DEVICE_NOT_SUPPORTED = 801,
    /**
     * @brief The error code when unexpected null pointer.
     * @since 24
     */
    CE_ERR_NULL_POINTER = 35300001,
    /**
     * @brief The error code when the client callback is not registered.
     * @since 24
     */
    CE_ERR_CLIENT_CALLBACK_NOT_REGISTERED = 35300002,
    /**
     * @brief The error code when an error occurred in the extension application.
     * @since 24
     */
    CE_ERR_EXTENSION_ERROR = 35300003,
    /**
     * @brief The error code when the system service works abnormally.
     * @since 24
     */
    CE_ERR_SYSTEM_ABNORMAL = 35300004,
    /**
     * @brief The error code when the storage operation failed.
     * @since 24
     */
    CE_ERR_STORAGE_OPERATION_FAILED = 35300005,
    /**
     * @brief The error code when the stream operation failed.
     * @since 24
     */
    CE_ERR_STREAM_OPERATION_FAILED = 35300006,
    /**
     * @brief The error code when the file operation failed.
     * @since 24
     */
    CE_ERR_FILE_OPERATION_FAILED = 35300007,
    /**
     * @brief The error code when application is in dlp sandbox.
     * @since 24
     */
    CE_ERR_IN_DLP_SANDBOX = 35300008,
    /**
     * @brief The error code when the image packer operation failed.
     * @since 24
     */
    CE_ERR_IMAGE_PACKER_OPERATION_FAILED = 35300009,
    /**
     * @brief The error code is returned when the client callback fails.
     * @since 24
     */
    CE_ERR_CLIENT_CALLBACK_FAILED = 35300010,
    /**
     * @brief The error code is returned when the extension abnormal exit.
     * @since 24
     */
    CE_ERR_EXTENSION_ABNORMAL_EXIT = 35300011,
    /**
     * @brief The error code when linking file is in application sandbox.
     * @since 24
     */
    CE_ERR_INVALID_LINKING_PATH = 35300012,
    /**
    * @brief The error code when the number of OE Extension connections exceeds the limit.
    * @since 24
    */
    CE_ERR_CONNECT_LIMIT_EXCEED = 35300013,
    /**
    * @brief The error code when the file is not authorized.
    * @since 24
    */
    CE_ERR_FILE_NOT_GRANT = 35300014,
    /**
    * @brief The error code when the disk is full.
    * @since 24
    */
    CE_ERR_DISK_FULL = 35300015,
    /**
    * @brief The error code when the capability is not supported by OE Extension.
    * @since 24
    */
    CE_ERR_EXTENSION_NOT_SUPPORT = 35300016,
} ContentEmbed_ErrorCode;

/**
 * @brief The value type of capability code.
 *
 * @since 24
 */
typedef enum ContentEmbed_CapabilityCode {
    /**
     * @brief The code means application supports document snapshot capture.
     */
    CE_CAPABILITY_SUPPORT_SNAPSHOT = 1 << 0,
    /**
     * @brief The code means application supports document editing.
     */
    CE_CAPABILITY_SUPPORT_DO_EDIT = 1 << 1,
} ContentEmbed_CapabilityCode;

#ifdef __cplusplus
}
#endif /* __cplusplus */
/** @} */
#endif // OHOS_CONTENT_EMBED_COMMON_H