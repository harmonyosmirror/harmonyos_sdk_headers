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
 * @file content_embed_proxy.h
 *
 * @brief Defines the content embed proxy APIs.
 *
 * @library libcontent_embed_ndk.so
 * @kit ContentEmbedKit
 * @syscap SystemCapability.ContentEmbed.ObjectEditor
 * @since 24
 */

#ifndef OHOS_CONTENT_EMBED_PROXY_H
#define OHOS_CONTENT_EMBED_PROXY_H

#include "info/application_target_sdk_version.h"
#include <stdint.h>
#include <stdlib.h>
#include <multimedia/image_framework/image/pixelmap_native.h>
#include "content_embed_common.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @brief The maximum length of a name.
 *
 * @since 24
 */
#define MAX_NAME_LENGTH (1 * 1024)

/**
 * @brief The maximum length of a description.
 *
 * @since 24
 */
#define MAX_DESCRIPTION_LENGTH (1 * 1024)

/**
 * @brief Define the ContentEmbed_Info structure type.
 *
 * Provides methods for Content Embed Kit.
 *
 * @since 24
 */
typedef struct ContentEmbed_Info ContentEmbed_Info;

/**
 * @brief Define the ContentEmbed_Format structure type.
 *
 * Provides methods for Content Embed Kit.
 *
 * @since 24
 */
typedef struct ContentEmbed_Format ContentEmbed_Format;

/**
 * @brief Create a new {@link ContentEmbed_Info} instance.
 * The caller is responsible for destroying the instance by calling
 * {@link OH_ContentEmbed_DestroyContentEmbedInfo} to avoid memory leaks.
 *
 * @param info Represents a pointer to an {@link ContentEmbed_Info} instance which will be created.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_CreateContentEmbedInfo(ContentEmbed_Info **info)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroy an {@link ContentEmbed_Info} instance and reclaims the memory occupied by the instance.
 *
 * @param info Represents a pointer to an {@link ContentEmbed_Info} instance.
 * After this call, the pointer becomes invalid and must not be used.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_DestroyContentEmbedInfo(ContentEmbed_Info *info)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get an {@link ContentEmbed_Info} instance based on the locale.
 *
 * @permission ohos.permission.CONNECT_OBJECTEDITOR_EXTENSION
 * @param locale Represents locale value.
 * @param info Represents a pointer to an {@link ContentEmbed_Info} instance.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_PERMISSION_DENIED} - permission verification failed.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_SYSTEM_ABNORMAL} - the system service works abnormally.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_GetContentEmbedInfo(const char *locale, ContentEmbed_Info *info)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get format count from an {@link ContentEmbed_Info} instance.
 *
 * @param info Represents a pointer to an {@link ContentEmbed_Info} instance.
 * @param count Output parameter indicating the number of {@link ContentEmbed_Format} instances
 *              in the {@link ContentEmbed_Info} instance.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_GetFormatCountFromInfo(const ContentEmbed_Info *info, uint32_t *count)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get {@link ContentEmbed_Format} instance from an {@link ContentEmbed_Info} instance using an index.
 *
 * @param info Represents a pointer to an {@link ContentEmbed_Info} instance.
 * @param index Represents the index of the internal array within the {@link ContentEmbed_Info} instance.
 * @param format Output parameter represents a pointer to an {@link ContentEmbed_Format} instance.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_GetFormatFromInfo(const ContentEmbed_Info *info, uint32_t index,
                                                         ContentEmbed_Format **format)
                                                         __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Create a new {@link ContentEmbed_Format} instance.
 * The caller is responsible for destroying the instance by calling
 * {@link OH_ContentEmbed_DestroyContentEmbedFormat} to avoid memory leaks.
 *
 * @param format Represents a pointer to an {@link ContentEmbed_Format} instance which will be created.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_CreateContentEmbedFormat(ContentEmbed_Format **format)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroy an {@link ContentEmbed_Format} instance and reclaims the memory occupied by the instance.
 *
 * @param format Represents a pointer to an {@link ContentEmbed_Format} instance.
 * After this call, the pointer becomes invalid and must not be used.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_DestroyContentEmbedFormat(ContentEmbed_Format *format)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get a {@link ContentEmbed_Format} instance using oeid and locale.
 *
 * @permission ohos.permission.CONNECT_OBJECTEDITOR_EXTENSION
 * @param oeid Represents the oeid value.
 * @param locale Represents the locale value.
 * @param format Output parameter represents a pointer to an {@link ContentEmbed_Format} instance.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_PERMISSION_DENIED} - permission verification failed.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_SYSTEM_ABNORMAL} - the system service works abnormally.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_GetContentEmbedFormatByOEidAndLocale(const char *oeid,
                                                                            const char *locale,
                                                                            ContentEmbed_Format *format)
                                                                            __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get oeid from {@link ContentEmbed_Format} instance.
 *
 * @param format Represents a pointer to an {@link ContentEmbed_Format} instance.
 * @param oeid Output parameter represents the oeid value.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_GetOEidFromFormat(const ContentEmbed_Format *format, char *oeid)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get name and description from {@link ContentEmbed_Format} instance.
 *
 * @param format Represents a pointer to an {@link ContentEmbed_Format} instance.
 * @param name Output parameter represents the name value.
 * @param description Output parameter represents the description value.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_GetNameAndDescriptionFromFormat(const ContentEmbed_Format *format,
                                                                       char *name, char *description)
                                                                       __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get icon from {@link ContentEmbed_Format} instance.
 * The caller is responsible for destroying the icon by calling
 * {@link OH_PixelmapNative_Destroy} to avoid memory leaks.
 *
 * @param format Represents a pointer to an {@link ContentEmbed_Format} instance.
 * @param icon The output pixel map of the application.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_GetIconFromFormat(const ContentEmbed_Format *format, OH_PixelmapNative **icon)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get all file name extensions in the {@link ContentEmbed_Format} data.
 *
 * @param format Represents a pointer to an instance of {@link ContentEmbed_Format}.
 * @param count Represents the file name extensions count that is a output param.
 * @return Returns string array that in {@link ContentEmbed_Format} when input parameters valid,
 *         otherwise return nullptr.
 * @since 24
 */
char** OH_ContentEmbed_GetFileNameExtensionsFromFormat(const ContentEmbed_Format *format, unsigned int *count)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Define the ContentEmbed_ExtensionProxy structure type.
 *
 * Provides methods for Content Embed Kit.
 *
 * @since 24
 */
typedef struct ContentEmbed_ExtensionProxy ContentEmbed_ExtensionProxy;

/**
 * @brief Define the ContentEmbed_Document structure type.
 *
 * Provides methods for Content Embed Kit.
 *
 * @since 24
 */
typedef struct ContentEmbed_Document ContentEmbed_Document;

/**
 * @brief Define the ContentEmbed_Capability structure type.
 *
 * Provides methods for Content Embed Kit.
 *
 * @since 24
 */
typedef struct ContentEmbed_Capability ContentEmbed_Capability;

/**
 * @brief Create a new {@link ContentEmbed_ExtensionProxy} instance through {@link ContentEmbed_Document} object.
 * The caller is responsible for destroying the instance by calling
 * {@link OH_ContentEmbed_DestroyExtensionProxy} to avoid memory leaks.
 *
 * @param document Represents a pointer to an {@link ContentEmbed_Document} instance.
 * @param proxy Represents a pointer to an {@link ContentEmbed_ExtensionProxy} instance which will be created.
 * @param contextPtr Represents a pointer to an context instance.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_CreateExtensionProxy(ContentEmbed_Document *document,
                                                            ContentEmbed_ExtensionProxy **proxy,
                                                            void *contextPtr)
                                                            __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroy an {@link ContentEmbed_ExtensionProxy} instance and reclaims the memory occupied by the instance.
 *
 * @param proxy Represents a pointer to an {@link ContentEmbed_ExtensionProxy} instance.
 * After this call, the pointer becomes invalid and must not be used.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_DestroyExtensionProxy(ContentEmbed_ExtensionProxy *proxy)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Called when the server notifies the client to update the content embed document.
 *
 * You need to implement this function, set it to {@link ContentEmbed_ExtensionProxy} through {@link
 * OH_ContentEmbed_Proxy_RegisterOnUpdateFunc} to complete the registration.
 *
 * @param proxy Represents a pointer to an
 *              {@link ContentEmbed_ExtensionProxy} instance which will be set in.
 * @since 24
 */
typedef void (*OH_ContentEmbed_ClientCallbackOnUpdateFunc)(
    ContentEmbed_ExtensionProxy *proxy);

/**
 * @brief Called when the server notifies the client that an error has occurred.
 *
 * You need to implement this function, set it to {@link ContentEmbed_ExtensionProxy} through {@link
 * OH_ContentEmbed_Proxy_RegisterOnErrorFunc} to complete the registration.
 *
 * @param proxy Represents a pointer to an
 *              {@link ContentEmbed_ExtensionProxy} instance which will be set in.
 * @param error Indicates that the Specific error codes.
 * @since 24
 */
typedef void (*OH_ContentEmbed_ClientCallbackOnErrorFunc)(
    ContentEmbed_ExtensionProxy *proxy, ContentEmbed_ErrorCode error);

/**
 * @brief Called when content embed document editing is completed.
 *
 * You need to implement this function, set it to {@link ContentEmbed_ExtensionProxy} through {@link
 * OH_ContentEmbed_Proxy_RegisterOnEditingFinishedFunc} to complete the registration.
 *
 * @param proxy Represents a pointer to an
 *              {@link ContentEmbed_ExtensionProxy} instance which will be set in.
 * @param dataModified Indicates whether the data has been modified.
 * @since 24
 */
typedef void (*OH_ContentEmbed_ClientCallbackOnEditingFinishedFunc)(
    ContentEmbed_ExtensionProxy *proxy, bool dataModified);

/**
 * @brief Called when the content embed document extension is stopped.
 *
 * You need to implement this function, set it to {@link ContentEmbed_ExtensionProxy} through {@link
 * OH_ContentEmbed_Proxy_RegisterOnExtensionStoppedFunc} to complete the registration.
 *
 * @param proxy Represents a pointer to an
 *              {@link ContentEmbed_ExtensionProxy} instance which will be set in.
 * @since 24
 */
typedef void (*OH_ContentEmbed_ClientCallbackOnExtensionStoppedFunc)(
    ContentEmbed_ExtensionProxy *proxy);

/**
 * @brief Register function {@link OH_ContentEmbed_ClientCallbackOnUpdateFunc} into {@link ContentEmbed_ExtensionProxy}.
 *
 * @param proxy Represents a pointer to an {@link ContentEmbed_ExtensionProxy} instance which will be set function in.
 * @param onUpdateFunc Represents function {@link OH_ContentEmbed_ClientCallbackOnUpdateFunc} which will be set in.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Proxy_RegisterOnUpdateFunc(
    ContentEmbed_ExtensionProxy *proxy, OH_ContentEmbed_ClientCallbackOnUpdateFunc onUpdateFunc)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Register function {@link OH_ContentEmbed_ClientCallbackOnErrorFunc} into {@link ContentEmbed_ExtensionProxy}.
 *
 * @param proxy Represents a pointer to an {@link ContentEmbed_ExtensionProxy} instance which will be set function in.
 * @param onErrorFunc Represents function {@link OH_ContentEmbed_ClientCallbackOnErrorFunc} which will be set in.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Proxy_RegisterOnErrorFunc(
    ContentEmbed_ExtensionProxy *proxy, OH_ContentEmbed_ClientCallbackOnErrorFunc onErrorFunc)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Register function {@link OH_ContentEmbed_ClientCallbackOnEditingFinishedFunc} into
 *        {@link ContentEmbed_ExtensionProxy}.
 *
 * @param proxy Represents a pointer to an {@link ContentEmbed_ExtensionProxy} instance which will be set function in.
 * @param onEditingFinishedFunc Represents function {@link OH_ContentEmbed_ClientCallbackOnEditingFinishedFunc}
 *                              which will be set in.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Proxy_RegisterOnEditingFinishedFunc(
    ContentEmbed_ExtensionProxy *proxy, OH_ContentEmbed_ClientCallbackOnEditingFinishedFunc onEditingFinishedFunc)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Register function {@link OH_ContentEmbed_ClientCallbackOnExtensionStoppedFunc} into
 *        {@link ContentEmbed_ExtensionProxy}.
 *
 * @param proxy Represents a pointer to an {@link ContentEmbed_ExtensionProxy} instance which will be set function in.
 * @param onExtensionStoppedFunc Represents function {@link OH_ContentEmbed_ClientCallbackOnExtensionStoppedFunc}
 *                              which will be set in.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Proxy_RegisterOnExtensionStoppedFunc(
    ContentEmbed_ExtensionProxy *proxy, OH_ContentEmbed_ClientCallbackOnExtensionStoppedFunc onExtensionStoppedFunc)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Start the server application.
 *
 * @permission ohos.permission.CONNECT_OBJECTEDITOR_EXTENSION
 * @param proxy Represents a pointer to an {@link ContentEmbed_ExtensionProxy} instance.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_PERMISSION_DENIED} - permission verification failed.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_CLIENT_CALLBACK_NOT_REGISTERED} - the client callback is not registered.
 *     {@link CE_ERR_SYSTEM_ABNORMAL} - the system service works abnormally.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 *     {@link CE_ERR_CONNECT_LIMIT_EXCEED} - connections exceeds the limit.
 *     {@link CE_ERR_FILE_NOT_GRANT} - file is not authorized.
 *     {@link CE_ERR_DISK_FULL} - the disk is full.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Proxy_StartWork(ContentEmbed_ExtensionProxy *proxy)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Stop the server application.
 *
 * @permission ohos.permission.CONNECT_OBJECTEDITOR_EXTENSION
 * @param proxy Represents a pointer to an {@link ContentEmbed_ExtensionProxy} instance.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_PERMISSION_DENIED} - permission verification failed.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_SYSTEM_ABNORMAL} - the system service works abnormally.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Proxy_StopWork(ContentEmbed_ExtensionProxy *proxy)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the document snapshot from the server application.
 *
 * @param proxy Represents a pointer to an {@link ContentEmbed_ExtensionProxy} instance.
 * @param snapshot The output document snapshot of the document.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_EXTENSION_ERROR} - an error occurred in the extension application.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 *     {@link CE_ERR_EXTENSION_NOT_SUPPORT} - the capability is not supported by OE Extension.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Proxy_GetSnapshot(ContentEmbed_ExtensionProxy *proxy,
                                                         OH_PixelmapNative **snapshot)
                                                         __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Client notifies the server to edit the document.
 *
 * @param proxy Represents a pointer to an {@link ContentEmbed_ExtensionProxy} instance.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_EXTENSION_ERROR} - an error occurred in the extension application.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 *     {@link CE_ERR_EXTENSION_NOT_SUPPORT} - the capability is not supported by OE Extension.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Proxy_DoEdit(ContentEmbed_ExtensionProxy *proxy)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Client retrieves document editing status from the server.
 *
 * @param proxy Represents a pointer to an {@link ContentEmbed_ExtensionProxy} instance.
 * @param isEditing Output parameter indicating that the content embed document is being edited.
 * @param isModified Output parameter indicating that the content embed document has been modified.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_EXTENSION_ERROR} - an error occurred in the extension application.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Proxy_GetEditStatus(ContentEmbed_ExtensionProxy *proxy,
                                                           bool *isEditing, bool *isModified)
                                                           __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Client obtains server capabilities.
 *
 * @param proxy Represents a pointer to an {@link ContentEmbed_ExtensionProxy} instance.
 * @param bitmask Output parameter indicating the capabilities of a content embed extension instance.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_EXTENSION_ERROR} - an error occurred in the extension application.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Proxy_GetCapability(ContentEmbed_ExtensionProxy *proxy,
                                                           uint32_t *bitmask)
                                                           __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the document from the {@link ContentEmbed_ExtensionProxy} instance.
 * The document can be created by calling {@link OH_ContentEmbed_CreateDocumentByOEid},
 * {@link OH_ContentEmbed_CreateDocumentByFile}, or {@link OH_ContentEmbed_LoadDocumentFromFile}.
 * The document should be destroyed by calling
 * {@link OH_ContentEmbed_DestroyDocument} when it is no longer needed.
 *
 * @param proxy Represents a pointer to an {@link ContentEmbed_ExtensionProxy} instance.
 * @param ceDocument Represents a pointer to an {@link ContentEmbed_Document} that is a output param.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Proxy_GetDocument(ContentEmbed_ExtensionProxy *proxy,
                                                         ContentEmbed_Document **ceDocument)
                                                         __attribute__((__availability__(ohos, introduced=24.0.0)));

#ifdef __cplusplus
}
#endif /* __cplusplus */
/** @} */
#endif // OHOS_CONTENT_EMBED_PROXY_H
