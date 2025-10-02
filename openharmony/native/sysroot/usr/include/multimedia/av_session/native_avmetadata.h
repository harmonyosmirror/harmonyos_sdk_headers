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

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief AVMetadata error code
 *
 * @since 13
 * @version 1.0
 */
typedef enum {
    /**
     * @error The call was successful.
     */
    AVMETADATA_SUCCESS = 0,

    /**
     * @error This means that the function was executed with an invalid input parameter.
     */
    AVMETADATA_ERROR_INVALID_PARAM = 1,

    /**
     * @error This means there is no memory left.
     */
    AVMETADATA_ERROR_NO_MEMORY = 2,
} AVMetadata_Result;

/**
 * @brief Defines the skip interval when fastforward or rewind.
 *
 * @since 13
 * @version 1.0
 */
typedef enum {
    /**
     * @brief 10 seconds
     */
    SECONDS_10 = 10,

    /**
     * @brief 15 seconds
     */
    SECONDS_15 = 15,

    /**
     * @brief 30 seconds
     */
    SECONDS_30 = 30,
} AVMetadata_SkipIntervals;

/**
 * @brief Display tag
 *
 * @since 13
 * @version 1.0
 */
typedef enum {
    /**
     * @brief Indicate the audio vivid property.
     */
    AVSESSION_DISPLAYTAG_AUDIO_VIVID = 1,
} AVMetadata_DisplayTag;

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
AVMetadata_Result OH_AVMetadataBuilder_Create(OH_AVMetadataBuilder** builder);

/**
 * @brief Destroy a bulder.
 *
 * @param builder The metadata builder instance pointer
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM} The param of builder is nullptr.
 * @since 13
 */
AVMetadata_Result OH_AVMetadataBuilder_Destroy(OH_AVMetadataBuilder* builder);

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
AVMetadata_Result OH_AVMetadataBuilder_SetAssetId(OH_AVMetadataBuilder* builder, const char* assetId);

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
AVMetadata_Result OH_AVMetadataBuilder_SetTitle(OH_AVMetadataBuilder* builder, const char* title);

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
AVMetadata_Result OH_AVMetadataBuilder_SetArtist(OH_AVMetadataBuilder* builder, const char* artist);

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
AVMetadata_Result OH_AVMetadataBuilder_SetAuthor(OH_AVMetadataBuilder* builder, const char* author);

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
AVMetadata_Result OH_AVMetadataBuilder_SetAlbum(OH_AVMetadataBuilder* builder, const char* album);

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
AVMetadata_Result OH_AVMetadataBuilder_SetWriter(OH_AVMetadataBuilder* builder, const char* writer);

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
AVMetadata_Result OH_AVMetadataBuilder_SetComposer(OH_AVMetadataBuilder* builder, const char* composer);

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
AVMetadata_Result OH_AVMetadataBuilder_SetDuration(OH_AVMetadataBuilder* builder, int64_t duration);

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
AVMetadata_Result OH_AVMetadataBuilder_SetMediaImageUri(OH_AVMetadataBuilder* builder, const char* mediaImageUri);

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
AVMetadata_Result OH_AVMetadataBuilder_SetSubtitle(OH_AVMetadataBuilder* builder, const char* subtitle);

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
AVMetadata_Result OH_AVMetadataBuilder_SetDescription(OH_AVMetadataBuilder* builder, const char* description);

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
AVMetadata_Result OH_AVMetadataBuilder_SetLyric(OH_AVMetadataBuilder* builder, const char* lyric);

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
    AVMetadata_SkipIntervals intervals);

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
AVMetadata_Result OH_AVMetadataBuilder_SetDisplayTags(OH_AVMetadataBuilder* builder, int32_t tags);

/**
 * @brief Create the avmetadta.
 *
 * @param builder The metadata builder instance pointer
 * @param avMetadata Pointer to a viriable to receive the avMetadata object.
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_NO_MEMORY} No memory to allocate a new instance.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of avMetadata is nullptr.
 * @since 13
 */
AVMetadata_Result OH_AVMetadataBuilder_GenerateAVMetadata(OH_AVMetadataBuilder* builder,
    OH_AVMetadata** avMetadata);

/**
 * @brief Request to release the avmetadta.
 *
 * @param avMetadata Pointer to a viriable to receive the avMetadata object.
 * @return Function result code:
 *         {@link AVMETADATA_SUCCESS} If the execution is successful.
 *         {@link AVMETADATA_ERROR_INVALID_PARAM} The param of avMetadata is nullptr.
 * @since 13
 */
AVMetadata_Result OH_AVMetadata_Destroy(OH_AVMetadata* avMetadata);

#ifdef __cplusplus
}
#endif

#endif // NATIVE_AVMETADATA_H
/** @} */