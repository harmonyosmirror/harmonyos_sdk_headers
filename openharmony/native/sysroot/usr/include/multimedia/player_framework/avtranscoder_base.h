/*
 * Copyright (c) 2025 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License"),
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
 * @addtogroup AVTranscoder
 * @{
 *
 * @brief Provides APIs of request capability for Transcoder.
 *
 * @syscap SystemCapability.Multimedia.Media.AVTranscoder
 * @since 20
 * @}
 */
 
/**
 * @file avtranscoder_base.h
 *
 * @brief Defines the structure and enumeration for Media AVTranscoder.
 *
 * @kit MediaKit
 * @library libavtranscoder.so
 * @syscap SystemCapability.Multimedia.Media.AVTranscoder
 * @since 20
 */
 
#ifndef MULTIMEDIA_PLAYER_FRAMEWORK_AVTRANSCODER_BASE_H
#define MULTIMEDIA_PLAYER_FRAMEWORK_AVTRANSCODER_BASE_H

#include <string>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief definiton of avtranscoder
 * @since 20
*/
typedef struct OH_AVTranscoder OH_AVTranscoder;

/**
 * @brief definiton of avtranscoder config
 * @since 20
 */
typedef struct OH_AVTranscoder_Config OH_AVTranscoder_Config;

/**
 * @brief Transcoder States
 * @since 20
 */
typedef enum OH_AVTranscoder_State {
    /** prepared states */
    AVTRANSCODER_PREPARED = 1,
    /** started states */
    AVTRANSCODER_STARTED = 2,
    /** paused states */
    AVTRANSCODER_PAUSED = 3,
    /** cancelled states */
    AVTRANSCODER_CANCELLED = 4,
    /** completed states */
    AVTRANSCODER_COMPLETED = 5
} OH_AVTranscoder_State;

/**
 * @brief Called when the state changed of current transcoding.
 * @param {OH_AVTranscoder*} transcoder The pointer to an OH_AVTranscoder instance.
 * @param {OH_AVTranscoder_State} state Indicates the transcoder state. For details, see {@link OH_AVTranscoder_State}.
 * @param {void*} userData Pointer to user specific data.
 * @since 20
 */
typedef void (*OH_AVTranscoder_OnStateChange)(OH_AVTranscoder *transcoder, OH_AVTranscoder_State state, void *userData);

/**
 * @brief Called when an error occurred during transcoding
 * @param {OH_AVTranscoder*} transcoder Pointer to an OH_AVTranscoder instance.
 * @param {int32_t} errorCode Error code.
 *         {@link AV_ERR_NO_MEMORY} if memory is insufficient.
 *         {@link AV_ERR_IO} if IO access failed.
 *         {@link AV_ERR_INVALID_STATE} if the current state does not support this operation.
 *         {@link AV_ERR_UNSUPPORT} if unsurpport function.
 *         {@link AV_ERR_INVALID_VAL} if the parameter check failed.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if operation not allowed.
 * @param {const char*} errorMsg Error message.
 * @param {void*} userData Pointer to user specific data.
 * @since 20
 */
typedef void (*OH_AVTranscoder_OnError)(OH_AVTranscoder *transcoder, int32_t errorCode, const char *errorMsg,
    void *userData);

/**
 * @brief Progress indicator function definition, called when transcoding progress is updated
 * @param {OH_AVTranscoder*} transcoder Pointer to an OH_AVTranscoder instance.
 * @param {int32_t} progress Transcoding progress.
 * @param {void*} userData Pointer to user specific data.
 * @since 20
 */
typedef void (*OH_AVTranscoder_OnProgressUpdate)(OH_AVTranscoder *transcoder, int32_t progress, void *userData);

#ifdef __cplusplus
}
#endif

#endif // MULTIMEDIA_PLAYER_FRAMEWORK_AVTRANSCODER_BASE_H