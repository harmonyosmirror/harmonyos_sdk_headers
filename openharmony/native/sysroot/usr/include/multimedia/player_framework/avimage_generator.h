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
 * @file avimage_generator.h
 *
 * @brief Defines the avimage generator APIs. Uses the Native APIs provided by Media AVImageGenerator
 *        to get an image at the specific time from a video resource.
 *
 * @syscap SystemCapability.Multimedia.Media.AVImageGenerator
 * @kit MediaKit
 * @library libavimage_generator.so
 * @since 18
 */

#ifndef MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVIMAGE_GENERATOR_H
#define MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVIMAGE_GENERATOR_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "native_averrors.h"
#include "avimage_generator_base.h"
#include "multimedia/image_framework/image/pixelmap_native.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Define OH_AVImageGenerator field.
 *
 * @syscap SystemCapability.Multimedia.Media.AVImageGenerator
 * @since 18
 */
typedef struct OH_AVImageGenerator OH_AVImageGenerator;

/**
 * @brief Create an image generator.
 *
 * @syscap SystemCapability.Multimedia.Media.AVImageGenerator
 * @return Returns a pointer to an OH_AVImageGenerator instance for success, nullptr for failure.
 *         Possible failure causes: HstEngineFactory failed to CreateAVMetadataHelperEngine.
 * @since 18
 */
OH_AVImageGenerator* OH_AVImageGenerator_Create(void);

/**
 * @brief Sets the media file descriptor source for the image generator.
 *
 * @syscap SystemCapability.Multimedia.Media.AVImageGenerator
 * @param generator Pointer to an OH_AVImageGenerator instance.
 * @param fd Indicates the file descriptor of media source.
 * @param offset Indicates the offset of media source in file descriptor.
 * @param size Indicates the size of media source.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input generator is nullptr or input param is invalid.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if operation not allowed.
 *         {@link AV_ERR_NO_MEMORY} if internal memory allocation failed.
 * @since 18
 */
OH_AVErrCode OH_AVImageGenerator_SetFDSource(OH_AVImageGenerator* generator,
    int32_t fd, int64_t offset, int64_t size);

/**
 * @brief Fetch an image at the specific time from a video resource.
 *
 * This function must be called after {@link SetFDSource}.
 *
 * @syscap SystemCapability.Multimedia.Media.AVImageGenerator
 * @param generator Pointer to an OH_AVImageGenerator instance.
 * @param timeUs The time expected to fetch picture from the video resource. The unit is microsecond(us).
 * @param options The time options about the relationship between the given timeUs and a key frame,
 *                see {@link OH_AVImageGenerator_QueryOptions}.
 * @param pixelMap The fetched output image from the video source. For details, see {@link OH_PixelmapNative}.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input generator is nullptr or input param is invalid.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if operation not allowed.
 *         {@link AV_ERR_UNSUPPORTED_FORMAT} if format is unsupported.
 *         {@link AV_ERR_NO_MEMORY} if internal memory allocation failed.
 * @since 18
 */
OH_AVErrCode OH_AVImageGenerator_FetchFrameByTime(OH_AVImageGenerator* generator,
    int64_t timeUs, OH_AVImageGenerator_QueryOptions options, OH_PixelmapNative** pixelMap);

/**
 * @brief Release the resource used for AVImageGenerator.
 *
 * @syscap SystemCapability.Multimedia.Media.AVImageGenerator
 * @param generator Pointer to an OH_AVImageGenerator instance.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input generator is nullptr or input param is invalid.
 * @since 18
 */
OH_AVErrCode OH_AVImageGenerator_Release(OH_AVImageGenerator* generator);

#ifdef __cplusplus
}
#endif

#endif // MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVIMAGE_GENERATOR_H
/** @} */
