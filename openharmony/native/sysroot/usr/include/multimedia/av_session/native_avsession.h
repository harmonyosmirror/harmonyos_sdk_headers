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
 * @file native_avsession.h
 *
 * @brief Declare avsession interface.
 *
 * @library libohavsession.so
 * @syscap SystemCapability.Multimedia.AVSession.Core
 * @kit AVSessionKit
 * @since 13
 * @version 1.0
 */

#ifndef NATIVE_AVSESSION_H
#define NATIVE_AVSESSION_H

#include <stdint.h>
#include "native_avsession_errors.h"
#include "native_avmetadata.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enum for avsession type.
 *
 * @since 13
 * @version 1.0
 */
typedef enum {
    /**
     * @brief audio session type.
     */
    SESSION_TYPE_AUDIO = 0,

    /**
     * @brief video session type.
     */
    SESSION_TYPE_VIDEO = 1,

    /**
     * @brief voice call session type.
     */
    SESSION_TYPE_VOICE_CALL = 2,

    /**
     * @brief video call session type.
     */
    SESSION_TYPE_VIDEO_CALL = 3
} AVSession_Type;

/**
 * @brief Enum for playback state.
 *
 * @since 13
 * @version 1.0
 */
typedef enum {
    /**
     * @brief Initial state.
     */
    PLAYBACK_STATE_INITIAL = 0,

    /**
     * @brief Preparing state. Indicates that the media file is not ready to play.
     */
    PLAYBACK_STATE_PREPARING = 1,

    /**
     * @brief Playing state.
     */
    PLAYBACK_STATE_PLAYING = 2,

    /**
     * @brief Pause state.
     */
    PLAYBACK_STATE_PAUSED = 3,

    /**
     * @brief Fast forward state.
     */
    PLAYBACK_STATE_FAST_FORWARDING = 4,

    /**
     * @brief Rewind state.
     */
    PLAYBACK_STATE_REWINDED = 5,

    /**
     * @brief Stopped state.
     */
    PLAYBACK_STATE_STOPPED = 6,

    /**
     * @brief Complete state.
     */
    PLAYBACK_STATE_COMPLETED = 7,

    /**
     * @brief Release state.
     */
    PLAYBACK_STATE_RELEASED = 8,

    /**
     * @brief Error state.
     */
    PLAYBACK_STATE_ERROR = 9,

    /**
     * @brief Idle state.
     */
    PLAYBACK_STATE_IDLE = 10,

    /**
     * @brief Buffering state.
     */
    PLAYBACK_STATE_BUFFERING = 11,

    /**
     * @brief Max state.
     */
    PLAYBACK_STATE_MAX = 12,
} AVSession_PlaybackState;

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
 * @brief Defines the playback mode.
 *
 * @since 13
 */
typedef enum {
    /**
     * @brief sequential playback mode
     */
    LOOP_MODE_SEQUENCE = 0,

    /**
     * @brief single playback mode
     */
    LOOP_MODE_SINGLE = 1,

    /**
     * @brief list playback mode
     */
    LOOP_MODE_LIST = 2,

    /**
     * @brief shuffle playback mode
     */
    LOOP_MODE_SHUFFLE = 3,

    /**
     * @brief custom playback mode
     */
    LOOP_MODE_CUSTOM = 4,
} AVSession_LoopMode;

/**
 * @brief Enum for different control command.
 *
 * @since 13
 * @version 1.0
 */
typedef enum AVSession_ControlCommand {
    /**
     * @brief invalid control command
     */
    CONTROL_CMD_INVALID = -1,

    /**
     * @brief play command
     */
    CONTROL_CMD_PLAY = 0,

    /**
     * @brief pause command
     */
    CONTROL_CMD_PAUSE = 1,

    /**
     * @brief stop command
     */
    CONTROL_CMD_STOP = 2,

    /**
     * @brief playnext command
     */
    CONTROL_CMD_PLAY_NEXT = 3,

    /**
     * @brief playprevious command
     */
    CONTROL_CMD_PLAY_PREVIOUS = 4,
} AVSession_ControlCommand;

/**
 * @brief Defines enumeration of avsession callback result.
 *
 * @since 13
 */
typedef enum {
    /**
     * @brief Result of avsession callabck is success.
     */
    AVSESSION_CALLBACK_RESULT_SUCCESS = 0,

    /**
     * @brief Result of avsession callabck failed.
     */
    AVSESSION_CALLBACK_RESULT_FAILURE = -1,
} AVSessionCallback_Result;

/**
 * @brief AVSession object
 *
 * A pointer can be created using {@link OH_AVSession_Create} method.
 *
 * @since 13
 * @version 1.0
 */
typedef struct OH_AVSession OH_AVSession;

/**
 * @brief Declaring the callback struct for playback command
 *
 * @since 13
 * @version 1.0
 */
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnCommand)(OH_AVSession* session,
    AVSession_ControlCommand command, void* userData);

/**
 * @brief Declaring the callback struct for forward command
 *
 * @since 13
 * @version 1.0
 */
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnFastForward)(OH_AVSession* session,
    uint32_t seekTime, void* userData);

/**
 * @brief Declaring the callback struct for rewind command
 *
 * @since 13
 * @version 1.0
 */
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnRewind)(OH_AVSession* session,
    uint32_t seekTime, void* userData);

/**
 * @brief Declaring the callback struct for seek command
 *
 * @since 13
 * @version 1.0
 */
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnSeek)(OH_AVSession* session,
    uint64_t seekTime, void* userData);

/**
 * @brief Declaring the callback struct for set loop mode command
 *
 * @since 13
 * @version 1.0
 */
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnSetLoopMode)(OH_AVSession* session,
    AVSession_LoopMode curLoopMode, void* userData);

/**
 * @brief Declaring the callback struct for toggle favorite command
 *
 * @since 13
 * @version 1.0
 */
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnToggleFavorite)(OH_AVSession* session,
    const char* assetId, void* userData);

/**
 * @brief Request to create the avsession.
 *
 * @param sessionType The session type to set
 * @param sessionTag The session tag set by the application
 * @param bundleName The bundle name to set
 * @param abilityName The abilityName name to set
 * @param avsession Pointer to a viriable to receive the OH_AVSession
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} If session already existed or internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}:
 *                                                 1. The param of sessionType is invalid.
 *                                                 2. The param of sessionTag is nullptr.
 *                                                 3. The param of bundleName is nullptr.
 *                                                 4. The param of abilityName is nullptr.
 *                                                 5. The param of avsession is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_Create(AVSession_Type sessionType, const char* sessionTag,
    const char* bundleName, const char* abilityName, OH_AVSession** avsession);

/**
 * @brief Request to destory the avsession.
 *
 * @param avsession The avsession instance pointer
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER} The param of avsession is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_Destroy(OH_AVSession* avsession);

/**
 * @brief Activate the avsession.
 *
 * @param avsession The avsession instance pointer
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER} The param of avsession is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_Activate(OH_AVSession* avsession);

/**
 * @brief Deactivate the avsession.
 *
 * @param avsession The avsession instance pointer
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER} The param of avsession is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_Deactivate(OH_AVSession* avsession);

/**
 * @brief Get session type.
 *
 * @param avsession The avsession instance pointer
 * @param sessionType The returned session type
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is invalid.
 *                                                 2. The param of sessionType is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_GetSessionType(OH_AVSession* avsession, AVSession_Type* sessionType);

/**
 * @brief Get session id.
 *
 * @param avsession The avsession instance pointer
 * @param sessionId The returned session id
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of sessionId is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_GetSessionId(OH_AVSession* avsession, const char** sessionId);

/**
 * @brief Request to set av metadata.
 *
 * @param avsession The avsession instance pointer
 * @param avmetadata The metadata to set
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of avmetadata is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_SetAVMetadata(OH_AVSession* avsession, OH_AVMetadata* avmetadata);

/**
 * @brief Request to set av playbackstate.
 *
 * @param avsession The avsession instance pointer
 * @param playbackState The playbackState to set
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of playbackState is invalid.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_SetPlaybackState(OH_AVSession* avsession,
    AVSession_PlaybackState playbackState);

/**
 * @brief Request to set playback position.
 *
 * @param avsession The avsession instance pointer
 * @param playbackPosition The playbackPosition to set
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of playbackPosition is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_SetPlaybackPosition(OH_AVSession* avsession,
    AVSession_PlaybackPosition* playbackPosition);

/**
 * @brief Request to set favorite state.
 *
 * @param avsession The avsession instance pointer
 * @param favorite true means making the resource to be liked, false means dislike.
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER} The param of avsession is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_SetFavorite(OH_AVSession* avsession, bool favorite);

/**
 * @brief Request to set loop mode.
 *
 * @param avsession The avsession instance pointer
 * @param loopMode The loopmode to be set for playback.
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of loopMode is invalid.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_SetLoopMode(OH_AVSession* avsession, AVSession_LoopMode loopMode);

/**
 * @brief Request to register command callback.
 *
 * @param avsession The avsession instance pointer
 * @param command The control command type to be registered.
 * @param callback the {@link OH_AVSessionCallback_OnCommand} to be registered.
 * @param userData User data which is passed by user.
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_CODE_COMMAND_INVALID} The command is invalid.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_RegisterCommandCallback(OH_AVSession* avsession,
    AVSession_ControlCommand command, OH_AVSessionCallback_OnCommand callback, void* userData);

/**
 * @brief Request to unregister command callback.
 *
 * @param avsession The avsession instance pointer
 * @param command The control command type to be unregistered.
 * @param callback the {@link OH_AVSessionCallback_OnCommand} to be unregistered.
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_CODE_COMMAND_INVALID} The command is invalid.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_UnregisterCommandCallback(OH_AVSession* avsession,
    AVSession_ControlCommand command, OH_AVSessionCallback_OnCommand callback);

/**
 * @brief Request to register fastforward callback.
 *
 * @param avsession The avsession instance pointer
 * @param callback the {@link OH_AVSessionCallback_OnFastForward} to be registered.
 * @param userData User data which is passed by user.
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_RegisterForwardCallback(OH_AVSession* avsession,
    OH_AVSessionCallback_OnFastForward callback, void* userData);

/**
 * @brief Request to unregister fastforward callback.
 *
 * @param avsession The avsession instance pointer
 * @param callback the {@link OH_AVSessionCallback_OnFastForward} to be unregistered.
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_UnregisterForwardCallback(OH_AVSession* avsession,
    OH_AVSessionCallback_OnFastForward callback);

/**
 * @brief Request to register rewind callback.
 *
 * @param avsession The avsession instance pointer
 * @param callback the {@link OH_AVSessionCallback_OnRewind} to be registered.
 * @param userData User data which is passed by user.
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_RegisterRewindCallback(OH_AVSession* avsession,
    OH_AVSessionCallback_OnRewind callback, void* userData);

/**
 * @brief Request to unregister rewind callback.
 *
 * @param avsession The avsession instance pointer
 * @param callback the {@link OH_AVSessionCallback_OnRewind} to be unregistered.
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_UnregisterRewindCallback(OH_AVSession* avsession,
    OH_AVSessionCallback_OnRewind callback);

/**
 * @brief Request to register seek callback.
 *
 * @param avsession The avsession instance pointer
 * @param callback the {@link OH_AVSessionCallback_OnSeek} to be registered.
 * @param userData User data which is passed by user.
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_RegisterSeekCallback(OH_AVSession* avsession,
    OH_AVSessionCallback_OnSeek callback, void* userData);

/**
 * @brief Request to unregister seek callback.
 *
 * @param avsession The avsession instance pointer
 * @param callback the {@link OH_AVSessionCallback_OnSeek} to be unregistered.
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_UnregisterSeekCallback(OH_AVSession* avsession,
    OH_AVSessionCallback_OnSeek callback);

/**
 * @brief Request to register set loopmode callback.
 *
 * @param avsession The avsession instance pointer
 * @param callback the {@link OH_AVSessionCallback_OnSetLoopMode} to be registered.
 * @param userData User data which is passed by user.
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_RegisterSetLoopModeCallback(OH_AVSession* avsession,
    OH_AVSessionCallback_OnSetLoopMode callback, void* userData);

/**
 * @brief Request to unregister set loopmode callback.
 *
 * @param avsession The avsession instance pointer
 * @param callback the {@link OH_AVSessionCallback_OnSetLoopMode} to be unregistered.
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_UnregisterSetLoopModeCallback(OH_AVSession* avsession,
    OH_AVSessionCallback_OnSetLoopMode callback);

/**
 * @brief Request to register toggle favorite callback.
 *
 * @param avsession The avsession instance pointer
 * @param callback the {@link OH_AVSessionCallback_OnToggleFavorite} to be registered.
 * @param userData User data which is passed by user.
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_RegisterToggleFavoriteCallback(OH_AVSession* avsession,
    OH_AVSessionCallback_OnToggleFavorite callback, void* userData);

/**
 * @brief Request to unregister toggle favorite callback.
 *
 * @param avsession The avsession instance pointer
 * @param callback the {@link OH_AVSessionCallback_OnToggleFavorite} to be unregistered.
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_UnregisterToggleFavoriteCallback(OH_AVSession* avsession,
    OH_AVSessionCallback_OnToggleFavorite callback);

#ifdef __cplusplus
}
#endif

#endif // NATIVE_AVSESSION_H
/** @} */