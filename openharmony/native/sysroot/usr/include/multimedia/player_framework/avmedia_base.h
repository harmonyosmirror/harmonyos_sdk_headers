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
 * @brief Defines the structure and enumeration for AVMedia.
 *
 * @syscap SystemCapability.Multimedia.Media.Core
 * @since 23
 */

/**
 * @file avmedia_base.h
 *
 * @brief Defines the structure and enumeration for AVMedia.
 *
 * @kit MediaKit
 * @library libavmedia_base.so
 * @syscap SystemCapability.Multimedia.Media.Core
 * @since 23
 */

#ifndef MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVMEDIA_BASE_H
#define MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVMEDIA_BASE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates the seek mode by the given time and the key frame.
 *
 * @since 23
 */
 typedef enum OH_AVMedia_SeekMode {
    /** Seek to keyframe after the time point. */
    OH_AVMEDIA_SEEK_NEXT_SYNC = 0,

    /** Seek to keyframe before the time point. */
    OH_AVMEDIA_SEEK_PREVIOUS_SYNC = 1,

    /** Seek to closest keyframe near the time point. */
    OH_AVMEDIA_SEEK_CLOSEST_SYNC = 2,

    /** Seek to the time point */
    OH_AVMEDIA_SEEK_CLOSEST = 3,
} OH_AVMedia_SeekMode;

#ifdef __cplusplus
}
#endif
#endif // MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVMEDIA_BASE_H
/** @} */
