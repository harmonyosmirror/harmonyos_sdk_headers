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
 * @addtogroup AVMediaBase
 * @{
 *
 * @brief Defines the avmetakeys.
 *
 * @syscap SystemCapability.Multimedia.Media.Core
 * @since 23
 */

/**
 * @file avmetakeys.h
 *
 * @brief Defines the avmetakeys.
 *
 * @kit MediaKit
 * @library libavmedia_base.so
 * @syscap SystemCapability.Multimedia.Media.Core
 * @since 23
 */

#ifndef MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVMETAKEYS_H
#define MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVMETAKEYS_H

#include "info/application_target_sdk_version.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Key for track index, value type is int32_t.
 * @since 23
 */
extern const char* OH_AVMETA_KEY_TRACK_INDEX __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key for track type, value type is int32_t
 * @since 23
 */
extern const char* OH_AVMETA_KEY_TRACK_TYPE __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key for codec mime type, value type is string.
 * @since 23
 */
extern const char* OH_AVMETA_KEY_MIME_TYPE __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key for duration, value type is int64_t.
 * @since 23
 */
extern const char* OH_AVMETA_KEY_DURATION __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key for bitrate, value type is int64_t.
 * @since 23
 */
extern const char* OH_AVMETA_KEY_BITRATE __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key for video frame rate (frame count in 100s), value type is double.
 * @since 23
 */
extern const char* OH_AVMETA_KEY_FRAME_RATE __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key for video width, value type is int32_t.
 * @since 23
 */
extern const char* OH_AVMETA_KEY_WIDTH __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key for video height, value type is int32_t.
 * @since 23
 */
extern const char* OH_AVMETA_KEY_HEIGHT __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key for audio channel count, value type is int32_t.
 * @since 23
 */
extern const char* OH_AVMETA_KEY_CHANNEL_COUNT __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key for audio sample rate (Hz), value type is int32_t.
 * @since 23
 */
extern const char* OH_AVMETA_KEY_SAMPLE_RATE __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key for audio bit depth, value type is int32_t.
 * @since 23
 */
extern const char* OH_AVMETA_KEY_SAMPLE_DEPTH __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key for language, value type is string.
 * @since 23
 */
extern const char* OH_AVMETA_KEY_LANGUAGE __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key for track name, value type is string.
 * @since 23
 */
extern const char* OH_AVMETA_KEY_TRACK_NAME __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key for hdr type, value type is int32_t.
 * @since 23
 */
extern const char* OH_AVMETA_KEY_HDR_TYPE __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key for original width, value type is int32_t.
 * @since 23
 */
extern const char* OH_AVMETA_KEY_ORIGINAL_WIDTH __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key for original height, value type is int32_t.
 * @since 23
 */
extern const char* OH_AVMETA_KEY_ORIGINAL_HEIGHT __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key to get the list of referenced track IDs. Only used by metadata extractor.
 * @since 23
 */
extern const char* OH_AVMETA_KEY_REF_TRACK_IDS __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key to get the track reference type. Only used by metadata extractor.
 * @since 23
 */
extern const char* OH_AVMETA_KEY_TRACK_REF_TYPE __attribute__((__availability__(ohos, introduced=23.0.0)));

#ifdef __cplusplus
}
#endif

#endif // MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVMETAKEYS_H
/** @} */
