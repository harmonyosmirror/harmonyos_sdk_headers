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
 * @addtogroup AVImageGenerator
 * @{
 *
 * @brief Provides APIs for generating an image at the specific time from a video resource.
 *
 * @syscap SystemCapability.Multimedia.Media.AVImageGenerator
 * @since 18
 */

/**
 * @file avimage_generator_base.h
 *
 * @brief Defines the structure and enumeration for AVImageGenerator.
 *
 * @syscap SystemCapability.Multimedia.Media.AVImageGenerator
 * @kit MediaKit
 * @library libavimage_generator.so
 * @since 18
 */

#ifndef MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVIMAGE_GENERATOR_BASE_H
#define MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVIMAGE_GENERATOR_BASE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates the image query options about the relationship between the given timeUs and a key frame.
 *
 * @syscap SystemCapability.Multimedia.Media.AVImageGenerator
 * @since 18
 */
typedef enum OH_AVImageGenerator_QueryOptions {
    /**
     * This option is used to fetch a key frame from the given media
     * resource that is located right after or at the given time.
     */
    OH_AVIMAGE_GENERATOR_QUERY_NEXT_SYNC = 0,
    /**
     * This option is used to fetch a key frame from the given media
     * resource that is located right before or at the given time.
     */
    OH_AVIMAGE_GENERATOR_QUERY_PREVIOUS_SYNC = 1,
    /**
     * This option is used to fetch a key frame from the given media
     * resource that is located closest to or at the given time.
     */
    OH_AVIMAGE_GENERATOR_QUERY_CLOSEST_SYNC = 2,
    /**
     * This option is used to fetch a frame (maybe not keyframe) from
     * the given media resource that is located closest to or at the given time.
     */
    OH_AVIMAGE_GENERATOR_QUERY_CLOSEST = 3,
} OH_AVImageGenerator_QueryOptions;

#ifdef __cplusplus
}
#endif
#endif // MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVMETADATA_EXTRACTOR_BASE_H
/** @} */
