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
 * @file content_embed_document.h
 *
 * @brief Defines the content embed document APIs.
 *
 * @library libcontent_embed_ndk.so
 * @kit ContentEmbedKit
 * @syscap SystemCapability.ContentEmbed.ObjectEditor
 * @since 24
 */

#ifndef OHOS_CONTENT_EMBED_DOCUMENT_H
#define OHOS_CONTENT_EMBED_DOCUMENT_H

#include "info/application_target_sdk_version.h"
#include <stdint.h>
#include <stdlib.h>
#include <cstdio>
#include "content_embed_common.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @brief The maximum length of a file path.
 *
 * @since 24
 */
#define MAX_PATH_LENGTH (4 * 1024)

/**
 * @brief Define the ContentEmbed_Document structure type.
 *
 * Provides methods for Content Embed Kit.
 *
 * @since 24
 */
typedef struct ContentEmbed_Document ContentEmbed_Document;

/**
 * @brief Define the ContentEmbed_Storage structure type.
 *
 * Provides methods for Content Embed Kit.
 *
 * @since 24
 */
typedef struct ContentEmbed_Storage ContentEmbed_Storage;

/**
 * @brief Define the ContentEmbed_StorageElement structure type.
 *
 * Provides methods for Content Embed Kit.
 *
 * @since 24
 */
typedef struct ContentEmbed_StorageElement ContentEmbed_StorageElement;

/**
 * @brief Define the ContentEmbed_StorageElements structure type.
 *
 * Provides methods for Content Embed Kit.
 *
 * @since 24
 */
typedef struct ContentEmbed_StorageElements ContentEmbed_StorageElements;

/**
 * @brief Define the ContentEmbed_Stream structure type.
 *
 * Provides methods for Content Embed Kit.
 *
 * @since 24
 */
typedef struct ContentEmbed_Stream ContentEmbed_Stream;

/**
 * @brief Create a new {@link ContentEmbed_Document} instance using the provided oeid.
 * The caller is responsible for destroying the instance by calling
 * {@link OH_ContentEmbed_DestroyDocument} to avoid memory leaks.
 *
 * @param oeid Represents oeid value.
 * @param document Represents a pointer to an {@link ContentEmbed_Document} instance which will be created.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_CreateDocumentByOEid(
    const char *oeid, ContentEmbed_Document **document)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Create a new {@link ContentEmbed_Document} instance from the source file.
 * The caller is responsible for destroying the instance by calling
 * {@link OH_ContentEmbed_DestroyDocument} to avoid memory leaks.
 *
 * @param srcFilePath Represents source file path.
 * @param length Represents source file path length.
 * @param isLinking Represents whether the source file is linked to the document.
 * @param document Represents a pointer to an {@link ContentEmbed_Document} instance which will be created.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 *     {@link CE_ERR_INVALID_LINKING_PATH} - linking file is in application sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_CreateDocumentByFile(
    const char *srcFilePath, size_t length, bool isLinking, ContentEmbed_Document **document)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Load an instance of {@link ContentEmbed_Document} from the source file.
 * The caller is responsible for destroying the instance by calling
 * {@link OH_ContentEmbed_DestroyDocument} to avoid memory leaks.
 *
 * @param srcFilePath Represents source file path.
 * @param length Represents source file path length.
 * @param document Represents a pointer to an {@link ContentEmbed_Document} instance which will be loaded.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_LoadDocumentFromFile(
    const char *srcFilePath, size_t length, ContentEmbed_Document **document)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Reads a compound document from {@link ContentEmbed_Document} instance.
 *
 * @param buffer Represents the buffer data read from an {@link ContentEmbed_Document} instance.
 * @param length Represents the length of the buffer data.
 * @param document Represents a pointer to an {@link ContentEmbed_Document} instance.
 * @param offset Represents pointer position of reading.
 * @param readSize Represents the length of the data actually read.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_STORAGE_OPERATION_FAILED} - the storage operation failed.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Document_Read(
    uint8_t *buffer, size_t length, ContentEmbed_Document *document, size_t offset, size_t *readSize)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get oeid from {@link ContentEmbed_Document} instance.
 *
 * @param document Represents a pointer to an {@link ContentEmbed_Document} instance.
 * @param oeid Output parameter represents the oeid value.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Document_GetOEid(
    const ContentEmbed_Document *document, char *oeid)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief whether the source file is linked to the {@link ContentEmbed_Document} instance.
 *
 * @param document Represents a pointer to an {@link ContentEmbed_Document} instance.
 * @param isLinking Output parameter represents whether the source file is linked to the document.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Document_IsLinking(
    const ContentEmbed_Document *document, bool *isLinking)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get native file path from {@link ContentEmbed_Document} instance.
 *
 * @param document Represents a pointer to an {@link ContentEmbed_Document} instance.
 * @param nativeFilePath Output parameter represents the path of the source file within
 *                       the {@link ContentEmbed_Document} on disk.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Document_GetNativeFilePath(
    const ContentEmbed_Document *document, char *nativeFilePath)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the {@link ContentEmbed_Storage} from a {@link ContentEmbed_Document} instance.
 * The caller is responsible for destroying the storage by calling
 * {@link OH_ContentEmbed_DestroyStorage} to avoid memory leaks.
 *
 * @param document Represents a pointer to an {@link ContentEmbed_Document} instance.
 * @param storage Output parameter represents a pointer to an {@link ContentEmbed_Storage} instance.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Document_GetRootStorage(
    ContentEmbed_Document *document, ContentEmbed_Storage **storage)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Flushes the content of the {@link ContentEmbed_Document} instance.
 *
 * @param document Represents a pointer to an {@link ContentEmbed_Document} instance.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_FILE_OPERATION_FAILED} - the file operation failed.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Document_Flush(const ContentEmbed_Document *document)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Create a new {@link ContentEmbed_Storage} instance.
 * The caller is responsible for destroying the storage by calling
 * {@link OH_ContentEmbed_DestroyStorage} to avoid memory leaks.
 *
 * @param parentStorage Represents a pointer to an {@link ContentEmbed_Storage} instance.
 *                      when an entry is to be deleted from the parent storage, invoke either
 *                      {@link OH_ContentEmbed_Storage_DeleteEntry} for a specific entry or
 *                      {@link OH_ContentEmbed_Storage_DeleteAllEntry} to remove all entries,
 *                      depending on the required operation.
 * @param name Represents the name of an {@link ContentEmbed_Storage} instance which will be created.
 * @param childStorage Output parameter represents a pointer to an {@link ContentEmbed_Storage} instance.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_STORAGE_OPERATION_FAILED} - the storage operation failed.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Storage_CreateStorage(
    const ContentEmbed_Storage *parentStorage, const char *name, ContentEmbed_Storage **childStorage)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Obtain the child storage instance from its parent instance.
 * The caller is responsible for destroying the child storage by calling
 * {@link OH_ContentEmbed_DestroyStorage} to avoid memory leaks.
 *
 * @param parentStorage Represents a pointer to an {@link ContentEmbed_Storage} instance.
 * @param name Represents the name of an {@link ContentEmbed_Storage} instance which will be obtained.
 * @param childStorage Output parameter represents a pointer to an {@link ContentEmbed_Storage} instance.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_STORAGE_OPERATION_FAILED} - the storage operation failed.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Storage_GetStorage(
    const ContentEmbed_Storage *parentStorage, const char *name, ContentEmbed_Storage **childStorage)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Create a new {@link ContentEmbed_Stream} instance.
 * The caller is responsible for destroying the stream by calling
 * {@link OH_ContentEmbed_DestroyStream} to avoid memory leaks.
 *
 * @param parentStorage Represents a pointer to an {@link ContentEmbed_Storage} instance.
 *                      when an entry is to be deleted from the parent storage, invoke either
 *                      {@link OH_ContentEmbed_Storage_DeleteEntry} for a specific entry or
 *                      {@link OH_ContentEmbed_Storage_DeleteAllEntry} to remove all entries,
 *                      depending on the required operation.
 * @param name Represents the name of an {@link ContentEmbed_Stream} instance which will be created.
 * @param childStream Output parameter represents a pointer to an {@link ContentEmbed_Stream} instance.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_STORAGE_OPERATION_FAILED} - the storage operation failed.
 *     {@link CE_ERR_STREAM_OPERATION_FAILED} - the stream operation failed.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Storage_CreateStream(
    ContentEmbed_Storage *parentStorage, const char *name, ContentEmbed_Stream **childStream)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Obtain the child stream instance from the parent storage instance.
 * The caller is responsible for destroying the child stream by calling
 * {@link OH_ContentEmbed_DestroyStream} to avoid memory leaks.
 *
 * @param parentStorage Represents a pointer to an {@link ContentEmbed_Storage} instance.
 * @param name Represents the name of an {@link ContentEmbed_Stream} instance which will be obtained.
 * @param childStream Output parameter represents a pointer to an {@link ContentEmbed_Stream} instance.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_STORAGE_OPERATION_FAILED} - the storage operation failed.
 *     {@link CE_ERR_STREAM_OPERATION_FAILED} - the stream operation failed.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Storage_GetStream(
    ContentEmbed_Storage *parentStorage, const char *name, ContentEmbed_Stream **childStream)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Delete a specific storage or stream directory entry in directory tree.
 *
 * @param parentStorage Represents a pointer to an {@link ContentEmbed_Storage} instance.
 * @param name Represents the name of a storage or stream which will be delete.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_STORAGE_OPERATION_FAILED} - the storage operation failed.
 *     {@link CE_ERR_FILE_OPERATION_FAILED} - the file operation failed.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Storage_DeleteEntry(
    ContentEmbed_Storage *parentStorage, const char *name)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Delete all entries of the storage from the directory tree to clear the storage.
 *
 * @param storage Represents a pointer to an {@link ContentEmbed_Storage} instance.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_STORAGE_OPERATION_FAILED} - the storage operation failed.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Storage_DeleteAllEntry(ContentEmbed_Storage *storage)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroy an {@link ContentEmbed_Storage} instance and reclaims the memory occupied by the instance.
 *
 * @param storage Represents a pointer to an {@link ContentEmbed_Storage} instance.
 * After this call, the pointer becomes invalid and must not be used.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_DestroyStorage(ContentEmbed_Storage *storage)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Read the buffer data from an {@link ContentEmbed_Stream} instance.
 * The caller is responsible for destroying the buffer to avoid memory leaks.
 *
 * @param stream Represents a pointer to an {@link ContentEmbed_Stream} instance.
 * @param buffer Output parameter represents the buffer data read from an {@link ContentEmbed_Stream} instance.
 * @param length Represents the length of the buffer data.
 * @param num Output parameter represents the num of the buffer data that has been read.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_STREAM_OPERATION_FAILED} - the stream operation failed.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Stream_Read(
    ContentEmbed_Stream *stream, unsigned char **buffer, size_t length, size_t *num)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Write the buffer data to an {@link ContentEmbed_Stream} instance.
 *
 * @param stream Represents a pointer to an {@link ContentEmbed_Stream} instance.
 * @param data Represents the data write to an {@link ContentEmbed_Stream} instance.
 * @param length Represents the length of the data.
 * @param num Output parameter represents the num of the data that has been written.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_STREAM_OPERATION_FAILED} - the stream operation failed.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Stream_Write(
    ContentEmbed_Stream *stream, const unsigned char *data, size_t length, size_t *num)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the current read position of the stream to the specified offset.
 *
 * @param stream Represents a pointer to an {@link ContentEmbed_Stream} instance that will be modified.
 * @param position The offset in bytes from the beginning of the stream to which the position should be set.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_STREAM_OPERATION_FAILED} - the stream operation failed.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Stream_Seek(ContentEmbed_Stream *stream, size_t position)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Retrieves the current position in the stream.
 *
 * @param stream Represents a pointer to the {@link ContentEmbed_Stream} instance.
 * @param position Represents a pointer to a size_t variable where the current position will be stored.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_STREAM_OPERATION_FAILED} - the stream operation failed.
 *     {@link CE_ERR_FILE_OPERATION_FAILED} - the file operation failed.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Stream_GetPosition(ContentEmbed_Stream *stream, size_t *position)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Retrieves the size of the data in the stream.
 *
 * This function attempts to determine the total size of the data available in the provided stream.
 * If successful, the size is written to the memory location pointed to by the `size` parameter.
 *
 * @param stream Represents a pointer to the {@link ContentEmbed_Stream} instance from which
 *               the size is to be retrieved.
 * @param size Represents a pointer to a size_t variable where the size of the stream will be stored.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_STREAM_OPERATION_FAILED} - the stream operation failed.
 *     {@link CE_ERR_FILE_OPERATION_FAILED} - the file operation failed.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Stream_GetSize(ContentEmbed_Stream *stream, size_t *size)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroy an {@link ContentEmbed_Stream} instance and reclaims the memory occupied by the instance.
 *
 * @param stream Represents a pointer to an {@link ContentEmbed_Stream} instance.
 * After this call, the pointer becomes invalid and must not be used.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_DestroyStream(ContentEmbed_Stream *stream)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroy an {@link ContentEmbed_Document} instance and reclaims the memory occupied by the instance.
 *
 * @param document Represents a pointer to an {@link ContentEmbed_Document} instance.
 * After this call, the pointer becomes invalid and must not be used.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_DestroyDocument(ContentEmbed_Document *document)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the oeid of the {@link ContentEmbed_Storage}.
 *
 * @param storage Represents a pointer to an {@link ContentEmbed_Storage} instance.
 * @param oeid Output parameter represents a pointer to a char array where the oeid will be stored.
 * @param oeidSize Represents the size of the oeid buffer.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_STORAGE_OPERATION_FAILED} - the storage operation failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Storage_GetOEid(ContentEmbed_Storage *storage,
    char *oeid, size_t oeidSize)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the oeid of the {@link ContentEmbed_Storage}.
 *
 * @param storage Represents a pointer to an {@link ContentEmbed_Storage} instance.
 * @param oeid Input parameter represents a pointer to a char array containing the oeid to be set.
 * @param oeidSize Represents the size of the oeid buffer.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_STORAGE_OPERATION_FAILED} - the storage operation failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Storage_SetOEid(ContentEmbed_Storage *storage,
    char *oeid, size_t oeidSize)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Creates an {@link ContentEmbed_StorageElements} instance and initializes it.
 *
 * @param storageElements Output parameter represents a pointer to a pointer
 *     to an {@link ContentEmbed_StorageElements} instance.
 * After this call, the pointer to the instance is stored in the 'storageElements' parameter.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_StorageElements_Create(ContentEmbed_StorageElements **storageElements)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroys an {@link ContentEmbed_StorageElements} instance and reclaims the memory occupied by it.
 *
 * @param storageElements Represents a pointer to a pointer to an {@link ContentEmbed_StorageElements} instance.
 * After this call, the pointer to the instance becomes invalid and must not be used.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_StorageElements_Destroy(ContentEmbed_StorageElements *storageElements)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the {@link ContentEmbed_StorageElements} of the {@link ContentEmbed_Storage}.
 *
 * @param storage Represents a pointer to an {@link ContentEmbed_Storage} instance.
 * @param storageElements Output parameter represents a pointer to an {@link ContentEmbed_StorageElements} instance.
 * After this call, the pointer to the instance is stored in the 'storageElements' parameter.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_STORAGE_OPERATION_FAILED} - the storage operation failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Storage_GetElements(const ContentEmbed_Storage *storage,
    ContentEmbed_StorageElements *storageElements)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the count of elements in the {@link ContentEmbed_StorageElements}.
 *
 * @param storageElements Represents a pointer to an {@link ContentEmbed_StorageElements} instance.
 * @param count Output parameter represents a pointer to a size_t variable where the count will be stored.
 * After this call, the count of elements in the 'storageElements' instance is stored in the 'count' parameter.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_StorageElements_GetCount(const ContentEmbed_StorageElements *storageElements,
    size_t *count)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the element at the specified index in the {@link ContentEmbed_StorageElements}.
 *
 * @param storageElements Represents a pointer to an {@link ContentEmbed_StorageElements} instance.
 * @param index Represents the index of the element to be retrieved.
 * @param storageElement Output parameter represents a pointer to an {@link ContentEmbed_StorageElement} instance.
 * After this call, the pointer to the instance is stored in the 'storageElement' parameter.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_StorageElements_GetElement(const ContentEmbed_StorageElements *storageElements,
    size_t index, ContentEmbed_StorageElement **storageElement)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the name of the {@link ContentEmbed_StorageElement}.
 *
 * @param storageElement Represents a pointer to an {@link ContentEmbed_StorageElement} instance.
 * @param name Output parameter represents a pointer to a character array where the name will be stored.
 * After this call, the name of the 'storageElement' instance is stored in the 'name' parameter.
 * @param nameSize Represents the size of the 'name' buffer.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_StorageElement_GetName(const ContentEmbed_StorageElement *storageElement,
    char *name, size_t nameSize)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get element create time.
 *
 * @param element Represents a pointer to an {@link ContentEmbed_StorageElement} instance.
 * @param ctime Out param, represents the create time of element.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_StorageElement_GetCTime(
    const ContentEmbed_StorageElement *element, uint64_t *ctime)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get element modify time.
 *
 * @param element Represents a pointer to an {@link ContentEmbed_StorageElement} instance.
 * @param mtime Out param, represents the modify time of element.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_StorageElement_GetMTime(
    const ContentEmbed_StorageElement *element, uint64_t *mtime)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Checks whether the {@link ContentEmbed_StorageElement} is a storage.
 *
 * @param storageElement Represents a pointer to an {@link ContentEmbed_StorageElement} instance.
 * @param isStorage Output parameter represents a pointer to a boolean variable where the result will be stored.
 * After this call, the result of the check is stored in the 'isStorage' parameter.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_StorageElement_IsStorage(const ContentEmbed_StorageElement *storageElement,
    bool *isStorage)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Determine if an element is a stream type.
 *
 * @param element Represents a pointer to an {@link ContentEmbed_StorageElement} instance.
 * @param isStream Out param, represents it is true if the element is a stream type.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_StorageElement_IsStream(
    const ContentEmbed_StorageElement *element, bool *isStream)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Copies the content of the source {@link ContentEmbed_Storage} to the destination {@link ContentEmbed_Storage}.
 *
 * @param srcStorage Represents a pointer to the source {@link ContentEmbed_Storage} instance.
 * @param destStorage Represents a pointer to the destination {@link ContentEmbed_Storage} instance.
 * @return Returns a specific error code.
 *     {@link CE_ERR_OK} - success.
 *     {@link CE_ERR_PARAM_INVALID} - parameter check failed.
 *     {@link CE_ERR_NULL_POINTER} - unexpected null pointer.
 *     {@link CE_ERR_STORAGE_OPERATION_FAILED} - the storage operation failed.
 *     {@link CE_ERR_DEVICE_NOT_SUPPORTED} - the device is not supported.
 *     {@link CE_ERR_IN_DLP_SANDBOX} - application is in dlp sandbox.
 * Specific error codes can be referenced {@link ContentEmbed_ErrorCode}.
 * @since 24
 */
ContentEmbed_ErrorCode OH_ContentEmbed_Storage_CopyTo(ContentEmbed_Storage *srcStorage,
    ContentEmbed_Storage *destStorage)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

#ifdef __cplusplus
}
#endif /* __cplusplus */
/** @} */
#endif // OHOS_CONTENT_EMBED_DOCUMENT_H
