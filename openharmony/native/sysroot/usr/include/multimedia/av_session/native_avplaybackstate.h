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
 * @file native_avplaybackstate.h
 *
 * @brief Declare playbackState interfaces.
 *
 * @library libohavsession.so
 * @syscap SystemCapability.Multimedia.AVSession.Core
 * @kit AVSessionKit
 * @since 23
 * @version 1.0
 */

#ifndef NATIVE_AVPLAYBACKSTATE_H
#define NATIVE_AVPLAYBACKSTATE_H

#include "info/application_target_sdk_version.h"
#include <stdint.h>
#include "native_avsession_base.h"
#include "native_avsession_errors.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief AVSession playbackstate object.
 *
 * @since 23
 * @version 1.0
 */
typedef struct OH_AVSession_AVPlaybackState OH_AVSession_AVPlaybackState;

/**
 * @brief Defines the playback position.
 *
 * @since 13
 */
typedef struct AVSession_PlaybackPosition {
    /**
     * @brief Elapsed time(position) of this media set by the app.
     */
    int64_t elapsedTime;

    /**
     * @brief Record the system time when elapsedTime is set.
     */
    int64_t updateTime;
} AVSession_PlaybackPosition;

/**
 * @brief Get State of PlayBackState.
 *
 * @param playbackState reference returned by {@link OH_AVSession_AVPlaybackState}
 * @param state the pointer {@link AVSession_PlaybackState} variable that will be set play state value.
 * @return {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 * or {@link AV_SESSION_ERR_INVALID_PARAMETER} if parameter valiation fails
 *                1.The param of playbackState is nullptr;
 *                2.The param of state is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVSession_GetPlaybackState(OH_AVSession_AVPlaybackState* playbackState,
    AVSession_PlaybackState* state)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get position of PlaybackState.
 *
 * @param playbackState reference returned by {@link OH_AVSession_AVPlaybackState}
 * @param position the pointer {@link AVSession_PlaybackPosition} variable that will be set playback position value.
 * @return {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 * or {@link AV_SESSION_ERR_INVALID_PARAMETER} if parameter valiation fails
 *                1.The param of playbackState is nullptr;
 *                2.The param of position is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVSession_GetPlaybackPosition(OH_AVSession_AVPlaybackState* playbackState,
    AVSession_PlaybackPosition* position)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get speed of PlaybackState.
 *
 * @param playbackState reference returned by {@link OH_AVSession_AVPlaybackState}
 * @param speed the pointer variable that will be set the speed.
 * @return {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 * or {@link AV_SESSION_ERR_INVALID_PARAMETER} if parameter valiation fails
 *                1.The param of playbackState is nullptr;
 *                2.The param of speed is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVSession_GetPlaybackSpeed(OH_AVSession_AVPlaybackState* playbackState,
    int32_t* speed)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get volume of PlaybackState.
 *
 * @param playbackState reference returned by {@link OH_AVSession_AVPlaybackState}
 * @param volume the pointer variable that will be set the volume.
 * @return {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 * or {@link AV_SESSION_ERR_INVALID_PARAMETER} if parameter valiation fails
 *                1.The param of playbackState is nullptr;
 *                2.The param of volume is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVSession_GetPlaybackVolume(OH_AVSession_AVPlaybackState* playbackState, int32_t* volume)
__attribute__((__availability__(ohos, introduced=23.0.0)));
#ifdef __cplusplus
}
#endif

#endif /* NATIVE_AVPLAYBACKSTATE_H */
/** @} */