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

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "native_averrors.h"
#include "avmetadata_extractor_base.h"
#include "native_avcodec_base.h"
#include "native_avformat.h"
#include "multimedia/image_framework/image/pixelmap_native.h"

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
 * @brief Create a metadata extractor.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @return Returns a pointer to an OH_AVMetadataExtractor instance for success, nullptr for failure
 * Possible failure causes: failed to HstEngineFactory::CreateAVMetadataHelperEngine.
 * @since 18
 */
OH_AVMetadataExtractor* OH_AVMetadataExtractor_Create(void);

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
    int32_t fd, int64_t offset, int64_t size);

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
 * @since 18
 */
OH_AVErrCode OH_AVMetadataExtractor_FetchMetadata(OH_AVMetadataExtractor* extractor, OH_AVFormat* avMetadata);

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
OH_AVErrCode OH_AVMetadataExtractor_FetchAlbumCover(OH_AVMetadataExtractor* extractor, OH_PixelmapNative** pixelMap);

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
OH_AVErrCode OH_AVMetadataExtractor_Release(OH_AVMetadataExtractor* extractor);

#ifdef __cplusplus
}
#endif

#endif // MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVMETADATA_EXTRACTOR_H
/** @} */
