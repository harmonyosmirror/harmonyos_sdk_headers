/*
 * Copyright (c) 2026 Huawei Device Co., Ltd.
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
 * @since 23
 * @version 1.0
 */

/**
 * @file native_avqueueitem.h
 *
 * @brief Declare avqueueitem related interfaces.
 *
 * @library libohavsession.so
 * @syscap SystemCapability.Multimedia.AVSession.Core
 * @kit AVSessionKit
 * @since 23
 * @version 1.0
 */

#ifndef NATIVE_AVQUEUEITEM_H
#define NATIVE_AVQUEUEITEM_H

#include "info/application_target_sdk_version.h"
#include <stdint.h>
#include "native_avsession_errors.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Declaring the AVMediaDescription.
 * The instance of AVMediaDescription set by application for current resource.
 *
 * @since 23
 * @version 1.0
 */
typedef struct OH_AVSession_AVMediaDescription OH_AVSession_AVMediaDescription;

/**
 * @brief Declaring the avqueue item.
 * The instance of AVQueueItem.
 *
 * @since 23
 * @version 1.0
 */
typedef struct OH_AVSession_AVQueueItem {
    /**
     * @brief itemId.
     */
    uint32_t itemId;

    /**
     * @brief media item info.
     */
    OH_AVSession_AVMediaDescription *description;
} OH_AVSession_AVQueueItem;

/**
 * @brief Declaring the AVMediaDescription builder.
 * The instance of builder is used for creating AVMediaDescription.
 *
 * @since 23
 * @version 1.0
 */
typedef struct OH_AVSession_AVMediaDescriptionBuilder OH_AVSession_AVMediaDescriptionBuilder;

/**
 * @brief Creates an OH_AVSession_AVMediaDescriptionBuilder instance.
 * Call {@link OH_AVSession_AVMediaDescriptionBuilder_Destroy} to release the builder object
 * when it is not used anymore.
 * 
 * @param builder The builder reference to the created result.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM} The param of builder is nullptr.
 *         {@link AVQUEUEITEM_ERROR_NO_MEMORY} No memory to allocate a new instance.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescriptionBuilder_Create(OH_AVSession_AVMediaDescriptionBuilder** builder)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Destroy a builder.
 *
 * @param builder The AVMediaDescription builder instance pointer
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM} The param of builder is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescriptionBuilder_Destroy(OH_AVSession_AVMediaDescriptionBuilder* builder)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set current asset id of the resource
 *
 * @param builder The AVMediaDescription builder instance pointer
 * @param assetId The current assetId of resource.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of assetId is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescriptionBuilder_SetAssetId(OH_AVSession_AVMediaDescriptionBuilder* builder,
    const char* assetId)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set the title of the resource
 *
 * @param builder The AVMediaDescription builder instance pointer
 * @param title The title of resource.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of title is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescriptionBuilder_SetTitle(OH_AVSession_AVMediaDescriptionBuilder* builder,
    const char* title)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set the subtitle of the resource
 *
 * @param builder The AVMediaDescription builder instance pointer
 * @param subtitle The subtitle of resource.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of subtitle is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescriptionBuilder_SetSubTitle(OH_AVSession_AVMediaDescriptionBuilder* builder,
    const char* subtitle)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set the artist of the resource
 *
 * @param builder The AVMediaDescription builder instance pointer
 * @param artist The artist of resource.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of artist is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescriptionBuilder_SetArtist(OH_AVSession_AVMediaDescriptionBuilder* builder,
    const char* artist)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set the media image url of the resource
 *
 * @param builder The AVMediaDescription builder instance pointer
 * @param albumCoverUri The image url of resource use to display in media center.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of albumCoverUri is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescriptionBuilder_SetAlbumCoverUri(
    OH_AVSession_AVMediaDescriptionBuilder* builder, const char* albumCoverUri)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set the media type of the resource
 *
 * @param builder The AVMediaDescription builder instance pointer
 * @param mediaType The type of this  resource, such as VIDEO or AUDIO, which is capital.
 * @return Return code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                 1. The param of builder is nullptr.
 *                                                 2. The param of mediaType is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescriptionBuilder_SetMediaType(OH_AVSession_AVMediaDescriptionBuilder* builder,
    const char* mediaType)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set the lyric content of the resource
 *
 * @param builder The AVMediaDescription builder instance pointer
 * @param lyricContent The lyricContent of resource, it should be lrc format.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                 1. The param of builder is nullptr.
 *                                                 2. The param of lyricContent is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescriptionBuilder_SetLyricContent(
    OH_AVSession_AVMediaDescriptionBuilder* builder, const char* lyricContent)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set the duration of the resource
 *
 * @param builder The AVMediaDescription builder instance pointer
 * @param duration The duration of resource, in miliseconds
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                 1. The param of builder is nullptr.
 *                                                 2. The param of duration is invalid.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescriptionBuilder_SetDuration(OH_AVSession_AVMediaDescriptionBuilder* builder,
    const int32_t duration)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set the media uri of the resource
 *
 * @param builder The AVMediaDescription builder instance pointer
 * @param mediaUri The media uri of the resource.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of mediaUri nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescriptionBuilder_SetMediaUri(OH_AVSession_AVMediaDescriptionBuilder* builder,
    const char* mediaUri)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set the start position of the resource
 *
 * @param builder The AVMediaDescription builder instance pointer
 * @param startPosition The start position of resource.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of startPosition is invalid.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescriptionBuilder_SetStartPosition(
    OH_AVSession_AVMediaDescriptionBuilder* builder, const int32_t startPosition)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set the size of the resource
 *
 * @param builder The AVMediaDescription builder instance pointer
 * @param mediaSize The size of the resource.
 * @return Return code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                 1. The param of builder is nullptr.
 *                                                 2. The param of mediaSize is invalid.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescriptionBuilder_SetMediaSize(OH_AVSession_AVMediaDescriptionBuilder* builder,
    const int32_t mediaSize)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set the album title of the resource
 *
 * @param builder The AVMediaDescription builder instance pointer
 * @param albumTitle The album title of resource.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr.
 *                                                 2.The param of albumTitle is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescriptionBuilder_SetAlbumTitle(OH_AVSession_AVMediaDescriptionBuilder* builder,
    const char* albumTitle)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set the app name of the resource
 *
 * @param builder The AVMediaDescription builder instance pointer
 * @param appName The app name of resource.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr.
 *                                                 2.The param of title is appName.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescriptionBuilder_SetAppName(OH_AVSession_AVMediaDescriptionBuilder* builder,
    const char* appName)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

 /**
 * @brief Get current asset id of the resource
 *
 * @param description The AVMediaDescription instance pointer
 * @param assetId Pointer variable that will be set assetId.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                1.The param of description is nullptr.
 *                                                2.The param of assetId is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescription_GetAssetId(OH_AVSession_AVMediaDescription* description,
    char** assetId)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get the title of the resource
 *
 * @param description The AVMediaDescription instance pointer
 * @param title Pointer variable that will be set title.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                1.The param of description is nullptr.
 *                                                2.The param of title is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescription_GetTitle(OH_AVSession_AVMediaDescription* description,
    char** title)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get the subtitle of the resource
 *
 * @param description The AVMediaDescription instance pointer
 * @param subtitle Pointer variable that will be set subtitle.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                1.The param of description is nullptr.
 *                                                2.The param of subtitle is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescription_GetSubtitle(OH_AVSession_AVMediaDescription* description,
    char** subtitle)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get the artist of the resource
 *
 * @param description The AVMediaDescription instance pointer
 * @param artist Pointer variable that will be set artist.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                1.The param of description is nullptr.
 *                                                2.The param of artist is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescription_GetArtist(OH_AVSession_AVMediaDescription* description,
    char** artist)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get the media image url of the resource
 *
 * @param description The AVMediaDescription instance pointer
 * @param albumCoverUri Pointer variable that will be set to media image url.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                1.The param of description is nullptr.
 *                                                2.The param of albumCoverUri is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescription_GetAlbumCoverUri(OH_AVSession_AVMediaDescription* description,
    char** albumCoverUri)
    __attribute__((__availability__(ohos, introduced=23.0.0)));
/**
 * @brief Get the media type information
 *
 * @param description The AVMediaDescription instance pointer
 * @param mediaType Pointer variable that will be set media type.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                1.The param of description is nullptr.
 *                                                2.The param of mediaType is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescription_GetMediaType(OH_AVSession_AVMediaDescription* description,
    char** mediaType)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get the lyric content of the resource
 *
 * @param description The AVMediaDescription instance pointer
 * @param lyricContent Pointer variable that will be set lyric content.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                1.The param of description is nullptr.
 *                                                2.The param of lyricContent is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescription_GetLyricContent(OH_AVSession_AVMediaDescription* description,
    char** lyricContent)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get the duration of the resource
 *
 * @param description The AVMediaDescription instance pointer
 * @param duration Pointer variable that will be set duration of the resource.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}
 *                                                1. The param of builder is nullptr.
 *                                                2. The param of duration is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescription_GetDuration(OH_AVSession_AVMediaDescription* description,
    int32_t* duration)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get the media uri of the resource
 *
 * @param description The AVMediaDescription instance pointer
 * @param mediaUri Pointer variable that will be set media uri.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                1.The param of description is nullptr.
 *                                                2.The param of mediaUri is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescription_GetMediaUri(OH_AVSession_AVMediaDescription* description,
    char** mediaUri)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get start position of the resource
 *
 * @param description The AVMediaDescription instance pointer
 * @param startPosition Pointer variable that will be set start position of resource.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}
 *                                                1. The param of description is nullptr.
 *                                                2. The param of startPosition is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescription_GetStartPosition(OH_AVSession_AVMediaDescription* description,
    int32_t* startPosition)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get media size of the resource
 *
 * @param description The AVMediaDescription instance pointer
 * @param mediaSize Pointer variable that will be set media size of resource.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}
 *                                                1. The param of description is nullptr.
 *                                                2. The param of mediaSize is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescription_GetMediaSize(OH_AVSession_AVMediaDescription* description,
    int32_t* mediaSize)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get the album title of the resource
 *
 * @param description The AVMediaDescription instance pointer
 * @param albumTitle Pointer variable that will be set album title of resource.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                1.The param of description is nullptr.
 *                                                2.The param of albumTitle is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescription_GetAlbumTitle(OH_AVSession_AVMediaDescription* description,
    char** albumTitle)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get the app name of the resource
 *
 * @param description The AVMediaDescription instance pointer
 * @param appName Pointer variable that will be set to app name of resource.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                1.The param of description is nullptr.
 *                                                2.The param of appName is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescription_GetAppName(OH_AVSession_AVMediaDescription* description,
    char** appName)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Create the avMediaDescription.
 * Call {@link OH_AVSession_AVMediaDescription_Destroy} to release the avMediaDescription object
 * when it is not used anymore.
 *
 * @param builder The AVMediaDescription builder instance pointer
 * @param avMediaDescription Pointer to a variable to receive the avMediaDescription object.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_NO_MEMORY} No memory to allocate a new instance.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of avMediaDescription is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescriptionBuilder_GenerateAVMediaDescription(
    OH_AVSession_AVMediaDescriptionBuilder* builder, OH_AVSession_AVMediaDescription** avMediaDescription)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to release the avMediaDescription.
 *
 * @param avMediaDescription Pointer to a viriable to receive the avMediaDescription object.
 * @return Function result code:
 *         {@link AVQUEUEITEM_SUCCESS} If the execution is successful.
 *         {@link AVQUEUEITEM_ERROR_INVALID_PARAM} The param of avMediaDescription is nullptr.
 * @since 23
 */
AVQueueItem_Result OH_AVSession_AVMediaDescription_Destroy(OH_AVSession_AVMediaDescription* avMediaDescription)
__attribute__((__availability__(ohos, introduced=23.0.0)));

#ifdef __cplusplus
}
#endif

#endif // NATIVE_AVQUEUEITEM_H
/** @} */