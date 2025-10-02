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
 * @addtogroup OHAudio
 * @{
 *
 * @brief Provide the definition of the C interface for the audio module.
 *
 * @syscap SystemCapability.Multimedia.Audio.Core
 *
 * @since 12
 * @version 1.0
 */

/**
 * @file native_audio_session_manager.h
 *
 * @brief Declare audio session manager related interfaces.
 *
 * This file interfaces are used for the creation of audioSessionManager
 * as well as activating/deactivating the audio session
 * as well as checking and listening the audio session decativated events.
 *
 * @library libohaudio.so
 * @syscap SystemCapability.Multimedia.Audio.Core
 * @kit AudioKit
 * @since 12
 * @version 1.0
 */

#ifndef NATIVE_AUDIO_SESSION_MANAGER_H
#define NATIVE_AUDIO_SESSION_MANAGER_H

#include "native_audio_common.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Declare the audio session manager.
 * The handle of audio session manager is used for audio session related functions.
 *
 * @since 12
 */
typedef struct OH_AudioSessionManager OH_AudioSessionManager;

/**
 * @brief Declare the audio concurrency modes.
 *
 * @since 12
 */
typedef enum {
    /**
     * @brief default mode
     */
    CONCURRENCY_DEFAULT = 0,

    /**
     * @brief mix with others mode
     */
    CONCURRENCY_MIX_WITH_OTHERS = 1,

    /**
     * @brief duck others mode
     */
    CONCURRENCY_DUCK_OTHERS = 2,

    /**
     * @brief pause others mode
     */
    CONCURRENCY_PAUSE_OTHERS = 3,
} OH_AudioSession_ConcurrencyMode;

/**
 * @brief Declare the audio deactivated reasons.
 *
 * @since 12
 */
typedef enum {
    /**
     * @brief deactivated because of lower priority
     */
    DEACTIVATED_LOWER_PRIORITY = 0,

    /**
     * @brief deactivated because of timing out
     */
    DEACTIVATED_TIMEOUT = 1,
} OH_AudioSession_DeactivatedReason;

/**
 * @brief declare the audio session strategy
 *
 * @since 12
 */
typedef struct OH_AudioSession_Strategy {
    /**
     * @brief audio session concurrency mode
     */
    OH_AudioSession_ConcurrencyMode concurrencyMode;
} OH_AudioSession_Strategy;

/**
 * @brief declare the audio session deactivated event
 *
 * @since 12
 */
typedef struct OH_AudioSession_DeactivatedEvent {
    /**
     * @brief audio session deactivated reason
     */
    OH_AudioSession_DeactivatedReason reason;
} OH_AudioSession_DeactivatedEvent;

/**
 * @brief This function pointer will point to the callback function that
 * is used to return the audio session deactivated event.
 *
 * @param event the {@link #OH_AudioSession_DeactivatedEvent} deactivated triggering event.
 * @since 12
 */
typedef int32_t (*OH_AudioSession_DeactivatedCallback) (
    OH_AudioSession_DeactivatedEvent event);

/**
 * @brief Fetch the audio session manager handle.
 * The audio session manager handle should be the first parameter in audio session related functions
 *
 * @param audioSessionManager the {@link #OH_AudioSessionManager}
 * which will be returned as the output parameter
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 * or {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} if system state error
 * @since 12
 */
OH_AudioCommon_Result OH_AudioManager_GetAudioSessionManager(
    OH_AudioSessionManager **audioSessionManager);

/**
 * @brief Activate the audio session for the current pid application.
 *
 * @param audioSessionManager the {@link #OH_AudioSessionManager}
 * returned by the {@link #OH_AudioManager_GetAudioSessionManager}
 * @param strategy pointer of {@link #OH_AudioSession_Strategy}
 * which is used for setting audio session strategy
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 * or {@link #AUDIOCOMMON_REULT_INVALID_PARAM} if parameter validation fails
 * or {@link #AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE} if system illegal state
 * @since 12
 */
OH_AudioCommon_Result OH_AudioSessionManager_ActivateAudioSession(
    OH_AudioSessionManager *audioSessionManager, const OH_AudioSession_Strategy *strategy);

/**
 * @brief Deactivate the audio session for the current pid application.
 *
 * @param audioSessionManager the {@link #OH_AudioSessionManager}
 * returned by the {@link #OH_AudioManager_GetAudioSessionManager}
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 * or {@link #AUDIOCOMMON_REULT_INVALID_PARAM} if parameter validation fails
 * or {@link #AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE} if system illegal state
 * @since 12
 */
OH_AudioCommon_Result OH_AudioSessionManager_DeactivateAudioSession(
    OH_AudioSessionManager *audioSessionManager);

/**
 * @brief Querying whether the current pid application has an activated audio session.
 *
 * @param audioSessionManager the {@link #OH_AudioSessionManager}
 * returned by the {@link #OH_AudioManager_GetAudioSessionManager}
 * @return True when the current pid application has an activated audio session
 * False when it does not
 * @since 12
 */
bool OH_AudioSessionManager_IsAudioSessionActivated(
    OH_AudioSessionManager *audioSessionManager);

/**
 * @brief Register the audio session deactivated event callback.
 *
 * @param audioSessionManager the {@link #OH_AudioSessionManager}
 * returned by the {@link #OH_AudioManager_GetAudioSessionManager}
 * @param callback the {@link #OH_AudioSession_DeactivatedCallback} which is used
 * to receive the deactivated event
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 * or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails
 * @since 12
 */
OH_AudioCommon_Result OH_AudioSessionManager_RegisterSessionDeactivatedCallback(
    OH_AudioSessionManager *audioSessionManager, OH_AudioSession_DeactivatedCallback callback);

/**
 * @brief Unregister the audio session deactivated event callback.
 *
 * @param audioSessionManager the {@link #OH_AudioSessionManager}
 * returned by the {@link #OH_AudioManager_GetAudioSessionManager}
 * @param callback the {@link #OH_AudioSession_DeactivatedCallback} which is used
 * to receive the deactivated event
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 * or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails
 * @since 12
 */
OH_AudioCommon_Result OH_AudioSessionManager_UnregisterSessionDeactivatedCallback(
    OH_AudioSessionManager *audioSessionManager, OH_AudioSession_DeactivatedCallback callback);
#ifdef __cplusplus
}
#endif
/** @} */
#endif // NATIVE_AUDIO_ROUTING_MANAGER_H