/*
 * Copyright (C) 2025 Huawei Device Co., Ltd.
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
 * @addtogroup avmedia_source
 * @{
 *
 * @brief Defines APIs for AVMediaSource.
 *
 * @syscap SystemCapability.Multimedia.Media.Core
 * @since 23
 */

/**
 * @file avmedia_source.h
 *
 * @brief Defines the structure and enumeration for AVMediaSource.
 *
 * @syscap SystemCapability.Multimedia.Media.Core
 * @kit MediaKit
 * @library libavmedia_source.so
 * @since 23
 */

#ifndef MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVMEDIA_SOURCE_H
#define MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVMEDIA_SOURCE_H

#include "info/application_target_sdk_version.h"
#include <stdint.h>
#include <stdio.h>
#include "native_averrors.h"
#include "native_avcodec_base.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Declares the http header type.
 * @since 23
 */
typedef struct OH_AVHttpHeader OH_AVHttpHeader;

/**
 * @brief Declares media source type.
 * @since 23
 */
typedef struct OH_AVMediaSource OH_AVMediaSource;

/**
 * @brief Loading Request object. Application obtains the requested resource location through this object
 * @since 23
 */
typedef struct OH_AVMediaSourceLoadingRequest OH_AVMediaSourceLoadingRequest;

/**
 * @brief Declares media data loader type, which is implemented by applications.
 * @since 23
 */
typedef struct OH_AVMediaSourceLoader OH_AVMediaSourceLoader;

/**
 * @brief The enum of the error code of network loading request.
 * @since 23
 */
typedef enum AVLoadingRequestError {
    /** Resouce is loaded successfully */
    AV_LOADING_ERROR_SUCCESS = 0,

    /** Resource is not ready for access */
    AV_LOADING_ERROR_NOT_READY = 1,

    /** Resource url does not exist */
    AV_LOADING_ERROR_NO_RESOURCE = 2,

    /** The uuid of resource handle is valid */
    AV_LOADING_ERROR_INVALID_HANDLE = 3,

    /** The client has no right to request the resource */
    AV_LOADING_ERROR_ACCESS_DENIED = 4,

    /** Access time out */
    AV_LOADING_ERROR_ACCESS_TIMEOUT = 5,

    /** Authorization failed */
    AV_LOADING_ERROR_AUTHORIZE_FAILED = 6,
} AVLoadingRequestError;

/**
 * @brief Create an http header instance
 * @return Returns a pointer to an OH_AVHttpHeader instance for success, nullptr for failure
 * @since 23
 */
OH_AVHttpHeader *OH_AVHttpHeader_Create(void) __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Releases an http header instance
 * @param header Pointer to an OH_AVHttpHeader instance
 * @return Function result code.
 *     (@link AV_ERR_OK) if the execution is successful.
 *     (@link AV_ERR_INVALID_VAL) if input header is nullptr or player release failed.
 * @since 23
 */
OH_AVErrCode OH_AVHttpHeader_Destroy(OH_AVHttpHeader *header) __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get the record count in the http header instance
 * @param header Pointer to an OH_AVHttpHeader instance
 * @param count The output record item count in the header instance
 * @return Function result code.
 *     (@link AV_ERR_OK) if the execution is successful.
 *     (@link AV_ERR_INVALID_VAL) if input header is nullptr.
 * @since 23
 */
OH_AVErrCode OH_AVHttpHeader_GetCount(OH_AVHttpHeader *header, uint32_t *count)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief add a key-value pair record to the http header instance
 * @param header Pointer to an OH_AVHttpHeader instance
 * @param key The key name of the record
 * @param value The value of the record
 * @return Function result code.
 *     (@link AV_ERR_OK) if the execution is successful.
 *     (@link AV_ERR_INVALID_VAL) if one of the parameters is nullptr.
 * @since 23
 */
OH_AVErrCode OH_AVHttpHeader_AddRecord(OH_AVHttpHeader *header, const char *key, const char *value)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief get the key-value pair record of the http header instance by the index
 * @param header Pointer to an OH_AVHttpHeader instance
 * @param index the position of the record in the header
 * @param key The output key name of the record
 * @param value The output value of the record
 * @return Function result code.
 *     (@link AV_ERR_OK) if the execution is successful.
 *     (@link AV_ERR_INVALID_VAL) if header is nullptr or index out of bound.
 * @since 23
 */
OH_AVErrCode OH_AVHttpHeader_GetRecord(OH_AVHttpHeader *header, uint32_t index, const char **key, const char **value)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Creates a media source from url.
 * @param url Url of the media source. The following streaming media formats are supported: HLS,
 *     HTTP-FLV, DASH, and HTTPS.
 * @param header Http headers attached to network request.
 * @return Returns a pointer to an OH_AVMediaSource instance for success, nullptr for failure
 * @since 23
 */
OH_AVMediaSource *OH_AVMediaSource_CreateWithUrl(const char *url, OH_AVHttpHeader *header)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Creates a media source from OH_AVDataSource.
 * @param dataSource Pointer to a OH_AVDataSource
 * @return Returns a pointer to an OH_AVMediaSource instance for success, nullptr for failure
 * @since 23
 */
OH_AVMediaSource *OH_AVMediaSource_CreateWithDataSource(OH_AVDataSource *dataSource)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Creates a media source from the FileDescriptor.
 * @param fd The fileDescriptor of data source.
 * @param offset The offset into the file to start reading.
 * @param size The file size in bytes.
 * @return Returns a pointer to an OH_AVMediaSource instance for success, nullptr for failure
 * @details Possible failure causes:
 * 1. fd is invalid.
 * 2. offset is invalid.
 * 3. size error.
 * 4. resource is invalid.
 * 5. file format is not supported.
 * @since 23
 */
OH_AVMediaSource *OH_AVMediaSource_CreateWithFd(int32_t fd, int64_t offset, int64_t size)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Release media source instance
 * @param source Pointer to an OH_AVMediaSource instance
 * @return Function result code.
 *     (@link AV_ERR_OK) if the execution is successful.
 *     (@link AV_ERR_INVALID_VAL) if source is nullptr or release failed.
 * @since 23
 */
OH_AVErrCode OH_AVMediaSource_Destroy(OH_AVMediaSource *source)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set media mime type to handle extended media source.
 * @param source Pointer to a OH_AVMediaSource.

 * @param mimetype Source's mime type. (@link AV_MimeTypes).
 * @return Function result code.
 *     (@link AV_ERR_OK) if the execution is successful.
 *     (@link AV_ERR_INVALID_VAL) if source or mimetype is nullptr.
 *     (@link AV_ERR_UNSUPPORTED_FORMAT) if mimetype is not supported.
 * @since 23
 */
OH_AVErrCode OH_AVMediaSource_SetMimeType(OH_AVMediaSource *source, const char *mimetype)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get the request url.
 * @param request the OH_AVMediaSourceLoadingRequest instance.
 * @param url the output url string.
 * @return Function result code.
 *     (@link AV_ERR_OK) if the execution is successful.
 *     (@link AV_ERR_INVALID_VAL) if request is nullptr or there is no url.
 * @since 23
 */
OH_AVErrCode OH_AVMediaSourceLoadingRequest_GetUrl(OH_AVMediaSourceLoadingRequest *request, const char **url)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get the request http header.
 * @param request the OH_AVMediaSourceLoadingRequest instance.
 * @param header the http header need to use in the http request.
 * @return Function result code.
 *     (@link AV_ERR_OK) if the execution is successful.
 *     (@link AV_ERR_INVALID_VAL) if request is nullptr.
 * @since 23
 */
OH_AVErrCode OH_AVMediaSourceLoadingRequest_GetHttpHeader(OH_AVMediaSourceLoadingRequest *request,
    OH_AVHttpHeader **header)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief The interface for application used to send requested data to AVPlayer.
 * @param request Parameters for the resource open request.
 * @param uuid ID for the resource handle.
 * @param offset Offset of the current media data relative to the start of the resource.
 * @param data Media data sent to the player.
 * @param dataSize - data length sent to player.
 * @return Accepted bytes for current read. The value less than zero means failed.
 *     -2, Means player needs current data any more, the client should stop current read process.
 *     -3, means player buffer is full, the client should wait for next read.
 * @since 23
 */
int32_t OH_AVMediaSourceLoadingRequest_RespondData(
    OH_AVMediaSourceLoadingRequest *request, int64_t uuid, int64_t offset, const uint8_t *data, uint64_t dataSize)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief The interface for application used to send respond header to AVPlayer
 * should be called before calling the (@link OH_AVMediaSourceLoadingRequest_RespondData()) for the first time.
 * @param request Parameters for the resource open request.
 * @param uuid ID for the resource handle.
 * @param header Header info in the http response.
 *     The application can intersect the header fields with the fields supported by the underlying layer for
 *     parsing or directly pass in all corresponding header information.
 * @param redirectUrl Redirect url from the http response if exist.
 * @since 23
 */
void OH_AVMediaSourceLoadingRequest_RespondHeader(
    OH_AVMediaSourceLoadingRequest *request, int64_t uuid, OH_AVHttpHeader *header, const char *redirectUrl)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Notifies the player of the current request status. After pushing all the data for a single resource, the
 * application should send the *LOADING_ERROR_SUCCESS* state to notify the player that the resource push is
 * complete.
 * @param request Parameters for the resource open request.
 * @param uuid ID for the resource handle.
 * @param error Error state.
 * @since 23
 */
void OH_AVMediaSourceLoadingRequest_FinishLoading(
    OH_AVMediaSourceLoadingRequest *request, int64_t uuid, AVLoadingRequestError error)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Create a OH_AVMediaSourceLoader instance.
 * @return OH_AVMediaSourceLoader pointer if success, else return NULL.
 * @since 23
 */
OH_AVMediaSourceLoader *OH_AVMediaSourceLoader_Create(void) __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Releases the OH_AVMediaSourceLoader instance.
 * @param loader The OH_AVMediaSourceLoader instance which to be released.
 * @return Function result code.
 *     (@link AV_ERR_OK) if the execution is successful.
 *     (@link AV_ERR_INVALID_VAL) if loader is nullptr or release failed.
 * @since 23
 */
OH_AVErrCode OH_AVMediaSourceLoader_Destroy(OH_AVMediaSourceLoader *loader)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set a source loader to a media source instance.
 * @param source the OH_AVMediaSource which need network delegation.
 * @param loader The OH_AVMediaSourceLoader instance
 * @return Function result code.
 *     (@link AV_ERR_OK) if the execution is successful.
 *     (@link AV_ERR_INVALID_VAL) if sourcer or loader is nullptr or release failed.
 * @since 23
 */
OH_AVErrCode OH_AVMediaSource_SetMediaSourceLoader(OH_AVMediaSource *source, OH_AVMediaSourceLoader *loader)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Defines the SourceOpenCallback function which is called by the service.
 * client should process the incoming request
 * and return the unique handle to the open resource.
 * The client must return the handle immediately after processing the request.
 * @param request Parameters for the resource open request,
 * including detailed information about the requested resource and the data push method.
 * @param userData The data set by user in OH_AVMediaSourceLoader_SetSourceOpenCallback
 * @return The handler of current resource open request, the handler for the request object is unique.
 *     A value greater than 0 means the request is successful.
 *     A value less than or equal to 0 means it fails.
 * @since 23
 */
typedef int64_t (*OH_AVMediaSourceLoaderOnSourceOpenedCallback)(OH_AVMediaSourceLoadingRequest *request,
    void *userData);

/**
 * @brief Defines the SourceReadCallback function which is called by the service. Client should record the read requests
 * and push the data through the (@link OH_AVMediaSourceLoadingRequest_RespondData) and
 * (@link OH_AVMediaSourceLoadingRequest_RespondHeader)
 * method of the request object when there is sufficient data.
 * The client must return the handle immediately after processing the request.
 * @param uuid ID for the resource handle.
 * @param requestedOffset Offset of the current media data relative to the start of the resource.
 * @param requestedLength Length of the current request.
 *     -1 means reaching the end of the resource, need to inform the player of the end of
 *     the push through the (@link OH_AVMediaSourceLoadingRequest_FinishLoading) method.
 * @param userData The data set by user in OH_AVMediaSourceLoader_SetSourceReadCallback
 * @since 23
 */
typedef void (*OH_AVMediaSourceLoaderOnSourceReadCallback)(int64_t uuid, int64_t requestedOffset,
    int64_t requestedLength, void *userData);

/**
 * @brief Defines the SourceCloseCallback function which is called by the service.
 * Client should release related resources.
 * The client must return the handle immediately after processing the request.
 * @param uuid ID for the resource handle.
 * @param userData The data set by user in OH_AVMediaSourceLoader_SetSourceCloseCallback
 * @since 23
 */
typedef void (*OH_AVMediaSourceLoaderOnSourceClosedCallback)(int64_t uuid, void *userData);

/**
 * @brief Set open callback function to the OH_AVMediaSourceLoader
 * @param loader The OH_AVMediaSourceLoader callback function interface set.
 * @param callback The open callback function to set.
 * @param userData The user defined data used in callback function.
 * @return Function result code.
 *     (@link AV_ERR_OK) if the execution is successful.
 *     (@link AV_ERR_INVALID_VAL) if loader is nullptr or release failed.
 * @since 23
 */
OH_AVErrCode OH_AVMediaSourceLoader_SetSourceOpenCallback(OH_AVMediaSourceLoader *loader,
    OH_AVMediaSourceLoaderOnSourceOpenedCallback callback, void *userData)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set read callback function to the OH_AVMediaSourceLoader
 * @param loader The OH_AVMediaSourceLoader callback function interface set.
 * @param callback The read callback function to set.
 * @param userData The user defined data used in callback function.
 * @return Function result code.
 *     (@link AV_ERR_OK) if the execution is successful.
 *     (@link AV_ERR_INVALID_VAL) if loader is nullptr or release failed.
 * @since 23
 */
OH_AVErrCode OH_AVMediaSourceLoader_SetSourceReadCallback(OH_AVMediaSourceLoader *loader,
    OH_AVMediaSourceLoaderOnSourceReadCallback callback, void *userData)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set close callback function to the OH_AVMediaSourceLoader
 * @param loader The OH_AVMediaSourceLoader callback function interface set.
 * @param callback The close callback function to set.
 * @param userData The user defined data used in callback function.
 * @return Function result code.
 *     (@link AV_ERR_OK) if the execution is successful.
 *     (@link AV_ERR_INVALID_VAL) if loader is nullptr or release failed.
 * @since 23
 */
OH_AVErrCode OH_AVMediaSourceLoader_SetSourceCloseCallback(OH_AVMediaSourceLoader *loader,
    OH_AVMediaSourceLoaderOnSourceClosedCallback callback, void *userData)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

#ifdef __cplusplus
}
#endif

#endif // MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVMEDIA_SOURCE_H
/** @} */
