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
 * @addtogroup AVMetadataExtractor
 * @{
 *
 * @brief Provides APIs of metadata capability for Media Source.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */

/**
 * @file avmetadata_extractor.h
 *
 * @brief Defines the avmetadata extractor APIs. Uses the Native APIs provided by Media AVMetadataExtractor
 *        to get metadata from the media source.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @kit MediaKit
 * @library libavmetadata_extractor.so
 * @since 18
 */

#ifndef MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVMETADATA_EXTRACTOR_H
#define MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVMETADATA_EXTRACTOR_H

#include "info/application_target_sdk_version.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "native_averrors.h"
#include "avmetadata_extractor_base.h"
#include "native_avcodec_base.h"
#include "native_avformat.h"
#include "multimedia/image_framework/image/pixelmap_native.h"
#include "avmedia_source.h"
#include "avmedia_base.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Define OH_AVMetadataExtractor field.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
typedef struct OH_AVMetadataExtractor OH_AVMetadataExtractor;

/**
 * @brief Create an OH_AVMetadataExtractor_OutputParam instance
 *
 * @return The new OH_AVMetadataExtractor_OutputParam instance.
 * @since 23
 */
OH_AVMetadataExtractor_OutputParam* OH_AVMetadataExtractor_OutputParam_Create()
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Release an OH_AVMetadataExtractor_OutputParam instance
 *
 * @param outputParam - Pointer to an OH_AVMetadataExtractor_OutputParam instance.
 * @since 23
 */
void OH_AVMetadataExtractor_OutputParam_Destroy(OH_AVMetadataExtractor_OutputParam* outputParam)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set an OH_AVMetadataExtractor_OutputParam instance's size attribute
 * If the width or height is negative, use the original video width or height;
 * If the width or height is zero, keep the aspect ratio and scale image.
 * If width and height both are positive, scale image with input width and height parameter.
 * @param outputParam - Pointer to an OH_AVMetadataExtractor_OutputParam instance.
 * @param width - The width of output image, scaled if necessary.
 * @param height - The height of output image, scaled if necessary.
 * @return The return value is TRUE for success, FALSE for failure.
 *     Possible failure causes: outputParam is nullptr.
 * @since 23
 */
bool OH_AVMetadataExtractor_OutputParam_SetSize(OH_AVMetadataExtractor_OutputParam* outputParam,
    int32_t width, int32_t height)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Fetch an image at the specific time from a video resource.
 *     This function must be called after source set.
 *
 * @param extractor - Pointer to an OH_AVMetadataExtractor instance.
 * @param timeUs - The time expected to fetch picture from the video resource. The unit is microsecond(us).
 * @param seekMode - The seek option about the relationship between the given timeUs and a key frame,
 *                see {@link OH_AVMedia_SeekMode}.
 * @param outputParam - The output format of the image, e.g. height or width of the image.
 *                see {@link OH_AVMetadataExtractor_OutputParam}.
 *                If nullptr, the fetched frame uses video original size
 * @param pixelMap The fetched output image from the video source. For details, see {@link OH_PixelmapNative}.
 *                Note: user need release pixelMap by {@link OH_PixelmapNative_Destroy} after use.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if the input param is invalid.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if operation not allowed.
 *         {@link AV_ERR_UNSUPPORTED_FORMAT} if format is unsupported.
 *         {@link AV_ERR_SERVICE_DIED} if the service died.
 *         {@link AV_ERR_IO_CLEARTEXT_NOT_PERMITTED} if http cleartext traffic is not permitted.
 * @since 23
 */
OH_AVErrCode OH_AVMetadataExtractor_FetchFrameByTime(OH_AVMetadataExtractor *extractor, int64_t timeUs,
    OH_AVMedia_SeekMode seekMode, const OH_AVMetadataExtractor_OutputParam* outputParam,
    OH_PixelmapNative** pixelMap)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Defines the callback function for frames fetched by AVMetadataExtractor
 *     Note: frameInfo will be released automatically after callback, but user should release
 *     frameInfo.image manually by {@link OH_PixelmapNative_Destroy} to avoid memory leaks.
 * @since 23
 */
typedef void (*OH_AVMetadataExtractor_OnFrameFetched)(OH_AVMetadataExtractor *extractor,
    const OH_AVMetadataExtractor_FrameInfo* frameInfo, OH_AVErrCode code, void *userData);

/**
 * @brief Batch fetch images at the specific times from a video resource.
 *     This function must be called after source set.
 *
 * @param extractor - Pointer to an OH_AVMetadataExtractor instance.
 * @param timesUs - The times array expected to fetch picture from the video resource. The unit is microsecond(us).
 * @param timesUsSize - The length of input times array.
 * @param seekMode - The seek option about the relationship between the given timeUs and a key frame,
 *                see {@link OH_AVMedia_SeekMode}.
 * @param outputParam - The output format of the image, e.g. height or width of the image.
 *                see {@link OH_AVMetadataExtractor_OutputParam}.
 *                If nullptr, the fetched frame uses video original size
 * @param onFrameInfoCallback - The callback function when a frame is fetched or failed to fetch.
 * @param userData - The user custom data for callback function.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if the input param is invalid.
 *         {@link AV_ERR_SERVICE_DIED} if the service died.
 *         {@link AV_ERR_IO_CLEARTEXT_NOT_PERMITTED} if http cleartext traffic is not permitted.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if operation not allowed. Returned by onFrameInfoCallback.
 *         {@link AV_ERR_UNSUPPORTED_FORMAT} if format is unsupported. Returned by onFrameInfoCallback.
 *         {@link AV_ERR_TIMEOUT} if the execution is times out. Returned by onFrameInfoCallback.
 * @since 23
 */
OH_AVErrCode OH_AVMetadataExtractor_FetchFramesByTimes(OH_AVMetadataExtractor *extractor, int64_t timesUs[],
    uint16_t timesUsSize, OH_AVMedia_SeekMode seekMode, const OH_AVMetadataExtractor_OutputParam* outputParam,
    OH_AVMetadataExtractor_OnFrameFetched onFrameInfoCallback, void* userData)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Cancel the batch fetch images operation (initiated by {@link OH_AVMetadataExtractor_FetchFramesByTimes}).
 * The pending fetches are cancelled and marked with CANCELLED result
 * in {@link OH_AVMetadataExtractor_OnFrameFetched} callback
 *
 * @param extractor - Pointer to an OH_AVMetadataExtractor instance.
 * @since 23
 */
void OH_AVMetadataExtractor_CancelAllFetchFrames(OH_AVMetadataExtractor *extractor)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get the track description information from the media source.
 *        This function must be called after source set.
 * @param extractor Pointer to an OH_AVMetadataExtractor instance.
 * @param index The index of the track description to retrieve.
 * @return Returns a pointer to an OH_AVFormat instance containing track description for success, nullptr for failure.
 *         Possible failure causes: extractor is nullptr, no source set, or format is unsupported.
 *         Note: User need release OH_AVFormat by {@link OH_AVFormat_Destroy} after use.
 * @since 23
 */
OH_AVFormat *OH_AVMetadataExtractor_GetTrackDescription(OH_AVMetadataExtractor *extractor, uint32_t index)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get the custom information from the media source.
 *        This function must be called after source set.
 * @param extractor Pointer to an OH_AVMetadataExtractor instance.
 * @return Returns a pointer to an OH_AVFormat instance containing custom metadata for success, nullptr for failure.
 *         Possible failure causes: extractor is nullptr, no source set, or custom info not found.
 *         Note: User need release OH_AVFormat by {@link OH_AVFormat_Destroy} after use.
 * @since 23
 */
OH_AVFormat *OH_AVMetadataExtractor_GetCustomInfo(OH_AVMetadataExtractor *extractor)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set media source to the extractor
 * @param extractor Pointer to an OH_AVMetadataExtractor instance.
 * @param source The media source to set to the extractor.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input extractor is nullptr or input source is invalid.
 * @since 23
 */
OH_AVErrCode OH_AVMetadataExtractor_SetMediaSource(OH_AVMetadataExtractor *extractor, OH_AVMediaSource *source)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Create a metadata extractor.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @return Returns a pointer to an OH_AVMetadataExtractor instance for success, nullptr for failure
 * Possible failure causes: failed to HstEngineFactory::CreateAVMetadataHelperEngine.
 * @since 18
 */
OH_AVMetadataExtractor* OH_AVMetadataExtractor_Create(void) __attribute__((__availability__(ohos, introduced=18.0.0)));

/**
 * @brief Sets the media file descriptor source for the metadata extractor.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @param extractor Pointer to an OH_AVMetadataExtractor instance.
 * @param fd Indicates the file descriptor of media source.
 * @param offset Indicates the offset of media source in file descriptor.
 * @param size Indicates the size of media source.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input extractor is nullptr or input param is invalid.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if operation not allowed.
 *         {@link AV_ERR_NO_MEMORY} if internal memory allocation failed.
 * @since 18
 */
OH_AVErrCode OH_AVMetadataExtractor_SetFDSource(OH_AVMetadataExtractor* extractor,
    int32_t fd, int64_t offset, int64_t size)
    __attribute__((__availability__(ohos, introduced=18.0.0)));

/**
 * @brief Extract metadata info from the media source.
 *        This function must be called after {@link SetFDSource}.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @param extractor Pointer to an OH_AVMetadataExtractor instance.
 * @param avMetadata Pointer to an {@link OH_AVFormat} instance, its content contains the fetched metadata info.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input extractor is nullptr or input param is invalid.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if operation not allowed.
 *         {@link AV_ERR_UNSUPPORTED_FORMAT} if format is unsupported.
 *         {@link AV_ERR_NO_MEMORY} if internal memory allocation failed.
 *         {@link AV_ERR_IO_CLEARTEXT_NOT_PERMITTED} if http cleartext traffic is not permitted. Add since api 23.
 * @since 18
 */
OH_AVErrCode OH_AVMetadataExtractor_FetchMetadata(OH_AVMetadataExtractor* extractor, OH_AVFormat* avMetadata)
__attribute__((__availability__(ohos, introduced=18.0.0)));

/**
 * @brief Fetch album cover from the audio source.
 *        This function must be called after {@link SetFDSource}.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @param extractor Pointer to an OH_AVMetadataExtractor instance.
 * @param pixelMap The fetched album cover from the audio source. For details, see {@link OH_PixelmapNative}.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input extractor is nullptr or input param is invalid.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if operation not allowed.
 *         {@link AV_ERR_UNSUPPORTED_FORMAT} if format is unsupported.
 *         {@link AV_ERR_NO_MEMORY} if internal memory allocation failed.
 * @since 18
 */
OH_AVErrCode OH_AVMetadataExtractor_FetchAlbumCover(OH_AVMetadataExtractor* extractor, OH_PixelmapNative** pixelMap)
__attribute__((__availability__(ohos, introduced=18.0.0)));

/**
 * @brief Release the resource used for AVMetadataExtractor.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @param extractor Pointer to an OH_AVMetadataExtractor instance.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input extractor is nullptr or input param is invalid.
 * @since 18
 */
OH_AVErrCode OH_AVMetadataExtractor_Release(OH_AVMetadataExtractor* extractor)
__attribute__((__availability__(ohos, introduced=18.0.0)));

#ifdef __cplusplus
}
#endif

#endif // MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVMETADATA_EXTRACTOR_H
/** @} */
