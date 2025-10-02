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
 * @file avmetadata_extractor_base.h
 *
 * @brief Defines the structure and enumeration for AVMetadataExtractor.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @kit MediaKit
 * @library libavmetadata_extractor.so
 * @since 18
 */

#ifndef MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVMETADATA_EXTRACTOR_BASE_H
#define MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVMETADATA_EXTRACTOR_BASE_H

#include <stdint.h>

#include "native_avformat.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief Key to get the album title of the media source, value type is const char*.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_ALBUM = "album";

/**
 * @brief Key to get the album performer or artist associated, value type is const char*.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_ALBUM_ARTIST = "albumArtist";

/**
 * @brief Key to get the artist name, value type is const char*.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_ARTIST = "artist";

/**
 * @brief Key to get the author name, value type is const char*.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_AUTHOR = "author";

/**
 * @brief Key to get the created time of the media source, value type is const char*.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_DATE_TIME = "dateTime";

/**
 * @brief Key to get the created or modified time with the specific date format, value type is const char*.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_DATE_TIME_FORMAT = "dateTimeFormat";

/**
 * @brief Key to get the composer of the media source, value type is const char*.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_COMPOSER = "composer";

/**
 * @brief Key to get the playback duration of the media source, value type is int64_t, value unit is millisecond (ms).
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_DURATION = "duration";

/**
 * @brief Key to get the content type or genre, value type is const char*.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_GENRE = "genre";

/**
 * @brief Key to get the value whether the media resource contains audio content,
 *        value type is int32_t. 1 means true and 0 means false.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_HAS_AUDIO = "hasAudio";

/**
 * @brief Key to get the value whether the media resource contains video content,
 *        value type is int32_t. 1 means true and 0 means false.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_HAS_VIDEO = "hasVideo";

/**
 * @brief Key to get the mime type of the media source, value type is const char*.
 *        Some example mime types include: "video/mp4", "audio/mp4", "audio/amr-wb".
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_MIME_TYPE = "mimeType";

/**
 * @brief Key to get the number of tracks, value type is int32_t.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_TRACK_COUNT = "trackCount";

/**
 * @brief Key to get the audio sample rate, value type is int32_t.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_SAMPLE_RATE = "sampleRate";

/**
 * @brief Key to get the media source title, value type is const char*.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_TITLE = "title";

/**
 * @brief Key to get the video height if the media contains video, value type is int32_t.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_VIDEO_HEIGHT = "videoHeight";

/**
 * @brief Key to get the video width if the media contains video, value type is int32_t.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_VIDEO_WIDTH = "videoWidth";

/**
 * @brief Key to get the video rotation angle, value type is int32_t.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_VIDEO_ORIENTATION = "videoOrientation";

/**
 * @brief Key to get the information whether the video is HDR video, value type is int32_t.
 *        For details of the value, see {@link OH_Core_HdrType} defined in {@link media_types.h}.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_VIDEO_IS_HDR_VIVID = "hdrType";

/**
 * @brief Key to get the latitude value in the geographical location, value type is float.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_LOCATION_LATITUDE = "latitude";

/**
 * @brief Key to get the longitude value in the geographical location, value type is float.
 *
 * @syscap SystemCapability.Multimedia.Media.AVMetadataExtractor
 * @since 18
 */
static const char* OH_AVMETADATA_EXTRACTOR_LOCATION_LONGITUDE = "longitude";

#ifdef __cplusplus
}
#endif
#endif // MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVMETADATA_EXTRACTOR_BASE_H
/** @} */
