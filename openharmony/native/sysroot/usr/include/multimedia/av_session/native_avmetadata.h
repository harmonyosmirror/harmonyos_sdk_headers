/*
 * Copyright (c) 2024-2025 Huawei Device Co., Ltd.
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
 * @addtogroup OHAVSession
 * @{
 *
 * @brief Provide the definition of the C interface for the avsession module.
 *
 * @syscap SystemCapability.Multimedia.AVSession.Core
 *
 * @since 13
 * @version 1.0
 */

/**
 * @file native_avmetadata.h
 *
 * @brief Declare avmetadata builder related interfaces.
 *
 * @library libohavsession.so
 * @syscap SystemCapability.Multimedia.AVSession.Core
 * @kit AVSessionKit
 * @since 13
 * @version 1.0
 */

#ifndef NATIVE_AVMETADATA_H
#define NATIVE_AVMETADATA_H

#include "info/application_target_sdk_version.h"
#include <stdint.h>
#include "native_avsession_errors.h"
#include "native_avsession_base.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Declaring the avmetadata builder.
 * The instance of builder is used for creating avmetadata.
 *
 * @since 13
 * @version 1.0
 */
typedef struct OH_AVMetadataBuilderStruct OH_AVMetadataBuilder;

/**
 * @brief Declaring the avmetadata.
 * The instance of avmetadata set by application for current resource.
 *
 * @since 13
 * @version 1.0
 */
typedef struct OH_AVMetadataStruct OH_AVMetadata;

/**
 * @brief Creates an AVMetadataBuilder instance.
 *
 * @param builder The builder reference to the created result.
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM} The param of builder is nullptr.
 *         {@link AVMETADATA_ERROR_NO_MEMORY} No memory to allocate a new instance.
 * @since 13
 */
AVMetadata_Result OH_AVMetadataBuilder_Create(OH_AVMetadataBuilder** builder)
__attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Destroy a builder.
 *
 * @param builder The metadata builder instance pointer
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM} The param of builder is nullptr.
 * @since 13
 */
AVMetadata_Result OH_AVMetadataBuilder_Destroy(OH_AVMetadataBuilder* builder)
__attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Set current asset id of the resource
 *
 * @param builder The metadata builder instance pointer
 * @param assetId The current assetId of resource.
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of assetId is nullptr.
 * @since 13
 */
AVMetadata_Result OH_AVMetadataBuilder_SetAssetId(OH_AVMetadataBuilder* builder, const char* assetId)
__attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Set the title of the resource
 *
 * @param builder The metadata builder instance pointer
 * @param title The title of resource.
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of title is nullptr.
 * @since 13
 */
AVMetadata_Result OH_AVMetadataBuilder_SetTitle(OH_AVMetadataBuilder* builder, const char* title)
__attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Set the artist of the resource
 *
 * @param builder The metadata builder instance pointer
 * @param artist The artist of resource.
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of artist is nullptr.
 * @since 13
 */
AVMetadata_Result OH_AVMetadataBuilder_SetArtist(OH_AVMetadataBuilder* builder, const char* artist)
__attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Set the author of the resource
 *
 * @param builder The metadata builder instance pointer
 * @param author The author of resource.
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of author is nullptr.
 * @since 13
 */
AVMetadata_Result OH_AVMetadataBuilder_SetAuthor(OH_AVMetadataBuilder* builder, const char* author)
__attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Set the album information
 *
 * @param builder The metadata builder instance pointer
 * @param album The album name
 * @return Return code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM}:
 *                                                 1. The param of builder is nullptr.
 *                                                 2. The param of album is nullptr.
 * @since 13
 */
AVMetadata_Result OH_AVMetadataBuilder_SetAlbum(OH_AVMetadataBuilder* builder, const char* album)
__attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Set the writer of the resource
 *
 * @param builder The metadata builder instance pointer
 * @param writer The writer of resource.
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM}:
 *                                                 1. The param of builder is nullptr.
 *                                                 2. The param of writer is nullptr.
 * @since 13
 */
AVMetadata_Result OH_AVMetadataBuilder_SetWriter(OH_AVMetadataBuilder* builder, const char* writer)
__attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Set the composer of the resource
 *
 * @param builder The metadata builder instance pointer
 * @param composer The composer of resource.
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM}:
 *                                                 1. The param of builder is nullptr.
 *                                                 2. The param of composer is nullptr.
 * @since 13
 */
AVMetadata_Result OH_AVMetadataBuilder_SetComposer(OH_AVMetadataBuilder* builder, const char* composer)
__attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Set the duration of the resource
 *
 * @param builder The metadata builder instance pointer
 * @param duration The duration of resource, in miliseconds
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM} The param of builder is nullptr.
 * @since 13
 */
AVMetadata_Result OH_AVMetadataBuilder_SetDuration(OH_AVMetadataBuilder* builder, int64_t duration)
__attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Set the media image uri of the resource
 *
 * @param builder The metadata builder instance pointer
 * @param mediaImageUri The mediaImageUri of resource.
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of mediaImageUri nullptr.
 * @since 13
 */
AVMetadata_Result OH_AVMetadataBuilder_SetMediaImageUri(OH_AVMetadataBuilder* builder, const char* mediaImageUri)
__attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Set the subtitle of the resource
 *
 * @param builder The metadata builder instance pointer
 * @param subtitle The subtitle of resource.
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of subtitle nullptr.
 * @since 13
 */
AVMetadata_Result OH_AVMetadataBuilder_SetSubtitle(OH_AVMetadataBuilder* builder, const char* subtitle)
__attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Set the media description of the resource
 *
 * @param builder The metadata builder instance pointer
 * @param description The description of resource.
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of description nullptr.
 * @since 13
 */
AVMetadata_Result OH_AVMetadataBuilder_SetDescription(OH_AVMetadataBuilder* builder, const char* description)
__attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Set the media lyric content of the resource
 *
 * @param builder The metadata builder instance pointer
 * @param lyric The lyric of resource.
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of lyric nullptr.
 * @since 13
 */
AVMetadata_Result OH_AVMetadataBuilder_SetLyric(OH_AVMetadataBuilder* builder, const char* lyric)
__attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Set the skip intervals of the resource
 *
 * @param builder The metadata builder instance pointer
 * @param intervals The intervals of resource, only can be set : 10, 15, 30
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of intervals is invalid.
 * @since 13
 */
AVMetadata_Result OH_AVMetadataBuilder_SetSkipIntervals(OH_AVMetadataBuilder* builder,
    AVMetadata_SkipIntervals intervals)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Set the display tags of the resource
 *
 * @param builder The metadata builder instance pointer
 * @param tags The display tags of resource which are supported by this app to be displayed on the media center
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM} The param of builder is nullptr.
 * @since 13
 */
AVMetadata_Result OH_AVMetadataBuilder_SetDisplayTags(OH_AVMetadataBuilder* builder, int32_t tags)
__attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Set the protocols supported
 *
 * @param builder The metadata builder instance pointer
 * @param filter The protocols supported by this session,if not set, the default is {@link TYPE_CAST_PLUS_STREAM}
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of filter is invalid.
 * @since 23
 */
AVMetadata_Result OH_AVMetadataBuilder_SetFilter(OH_AVMetadataBuilder* builder, uint32_t filter)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Create the avmetadata.
 *
 * @param builder The metadata builder instance pointer
 * @param avMetadata Pointer to a variable to receive the avMetadata object.
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_NO_MEMORY} No memory to allocate a new instance.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of avMetadata is nullptr.
 * @since 13
 */
AVMetadata_Result OH_AVMetadataBuilder_GenerateAVMetadata(OH_AVMetadataBuilder* builder,
    OH_AVMetadata** avMetadata)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Request to release the avmetadata.
 *
 * @param avMetadata Pointer to a variable to receive the avMetadata object.
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM} The param of avMetadata is nullptr.
 * @since 13
 */
AVMetadata_Result OH_AVMetadata_Destroy(OH_AVMetadata* avMetadata)
__attribute__((__availability__(ohos, introduced=13.0.0)));

#ifdef __cplusplus
}
#endif

#endif // NATIVE_AVMETADATA_H
/** @} */