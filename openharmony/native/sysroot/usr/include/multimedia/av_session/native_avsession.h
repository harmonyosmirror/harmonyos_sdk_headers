/*
 * Copyright (c) 2024-2026 Huawei Device Co., Ltd.
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

#include "info/application_target_sdk_version.h"
#include <stdint.h>
#include "native_avsession_errors.h"
#include "native_avsession_base.h"
#include "native_avmetadata.h"
#include "native_avplaybackstate.h"
#include "native_deviceinfo.h"

#ifdef __cplusplus
extern "C" {
#endif

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
 * @brief OH_AVCastController object
 *
 * A pointer can be created using the {@link OH_AVSession_CreateAVCastController} method.
 *
 * @since 23
 * @version 1.0
 */
typedef struct OH_AVCastController OH_AVCastController;

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
 * @brief Declaring the callback struct for output device change
 *
 * @since 23
 * @version 1.0
 */
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OutputDeviceChange)(OH_AVSession* session,
    AVSession_ConnectionState state, AVSession_OutputDeviceInfo* outputDeviceInfo);

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
    const char* bundleName, const char* abilityName, OH_AVSession** avsession)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Request to destroy the avsession.
 *
 * @param avsession The avsession instance pointer
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER} The param of avsession is nullptr.
 * @since 13
 */
AVSession_ErrCode OH_AVSession_Destroy(OH_AVSession* avsession)
__attribute__((__availability__(ohos, introduced=13.0.0)));

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
AVSession_ErrCode OH_AVSession_Activate(OH_AVSession* avsession)
__attribute__((__availability__(ohos, introduced=13.0.0)));

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
AVSession_ErrCode OH_AVSession_Deactivate(OH_AVSession* avsession)
__attribute__((__availability__(ohos, introduced=13.0.0)));

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
AVSession_ErrCode OH_AVSession_GetSessionType(OH_AVSession* avsession, AVSession_Type* sessionType)
__attribute__((__availability__(ohos, introduced=13.0.0)));

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
AVSession_ErrCode OH_AVSession_GetSessionId(OH_AVSession* avsession, const char** sessionId)
__attribute__((__availability__(ohos, introduced=13.0.0)));

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
AVSession_ErrCode OH_AVSession_SetAVMetadata(OH_AVSession* avsession, OH_AVMetadata* avmetadata)
__attribute__((__availability__(ohos, introduced=13.0.0)));

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
    AVSession_PlaybackState playbackState)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

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
    AVSession_PlaybackPosition* playbackPosition)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

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
AVSession_ErrCode OH_AVSession_SetFavorite(OH_AVSession* avsession, bool favorite)
__attribute__((__availability__(ohos, introduced=13.0.0)));

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
AVSession_ErrCode OH_AVSession_SetLoopMode(OH_AVSession* avsession, AVSession_LoopMode loopMode)
__attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Request to enable remote cast.
 *
 * @param avsession The avsession instance pointer
 * @param enabled enable or disable remote cast
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_CODE_SESSION_NOT_EXIST} session does not exist.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVSession_SetRemoteCastEnabled(OH_AVSession* avsession, bool enabled)
__attribute__((__availability__(ohos, introduced=23.0.0)));

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
    AVSession_ControlCommand command, OH_AVSessionCallback_OnCommand callback, void* userData)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

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
    AVSession_ControlCommand command, OH_AVSessionCallback_OnCommand callback)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

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
    OH_AVSessionCallback_OnFastForward callback, void* userData)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

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
    OH_AVSessionCallback_OnFastForward callback)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

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
    OH_AVSessionCallback_OnRewind callback, void* userData)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

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
    OH_AVSessionCallback_OnRewind callback)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

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
    OH_AVSessionCallback_OnSeek callback, void* userData)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

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
    OH_AVSessionCallback_OnSeek callback)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

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
    OH_AVSessionCallback_OnSetLoopMode callback, void* userData)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

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
    OH_AVSessionCallback_OnSetLoopMode callback)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

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
    OH_AVSessionCallback_OnToggleFavorite callback, void* userData)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

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
    OH_AVSessionCallback_OnToggleFavorite callback)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Request to register output device change callback.
 *
 * @param avsession The avsession instance pointer
 * @param callback the {@link OH_AVSessionCallback_OutputDeviceChange} to be registered.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVSession_RegisterOutputDeviceChangeCallback(OH_AVSession* avsession,
    OH_AVSessionCallback_OutputDeviceChange callback)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to unregister output device change callback.
 *
 * @param avsession The avsession instance pointer
 * @param callback the {@link OH_AVSessionCallback_OutputDeviceChange} to be unregistered.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVSession_UnregisterOutputDeviceChangeCallback(OH_AVSession* avsession,
    OH_AVSessionCallback_OutputDeviceChange callback)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to acquire an AVSession instance if already created.
 * Call {@link OH_AVSession_Destroy} to release the OH_AVSession when it is not used anymore.
 *
 * @param sessionTag The session tag set by the application
 * @param bundleName The bundle name to set
 * @param abilityName The abilityName name to set
 * @param avsession Pointer to a viriable to receive the OH_AVSession
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_CODE_SESSION_NOT_EXIST} If session is not existed.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}:
 *                                                 1. The param of sessionTag is invalid.
 *                                                 2. The param of bundleName is nullptr.
 *                                                 3. The param of abilityName is nullptr.
 *                                                 4. The param of avsession is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVSession_AcquireSession(const char* sessionTag, const char* bundleName, const char* abilityName,
    OH_AVSession** avsession)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Create an AVCastController object.
 * Call {@link OH_AVCastController_Destroy} to release the OH_AVCastController when it is not used anymore.
 *
 * @param avsession The avsession instance pointer
 * @param avcastcontroller {@link OH_AVCastController} Pointer to a variable to receive the avcastcontroller
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_CODE_SESSION_NOT_EXIST} The session does not exist.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of avcastcontroller is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVSession_CreateAVCastController(OH_AVSession* avsession, OH_AVCastController** avcastcontroller)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to stop current cast and disconnect device connection.
 *
 * @param avsession The avsession instance pointer
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_CODE_SESSION_NOT_EXIST} The session does not exist.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVSession_StopCasting(OH_AVSession* avsession)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Acquire current output device.
 *
 * @param avsession The avsession instance pointer
 * @param outputDeviceInfo Pointer {@link AVSession_OutputDeviceInfo} to a variable to receive the OutputDeviceInfo
 *     Do not release the outputDeviceInfo pointer separately, instead call {@link OH_AVSession_ReleaseOutputDevice}
 *     to release the outputDeviceInfo when it is not used anymore.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_CODE_SESSION_NOT_EXIST} The session does not exist.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avsession is nullptr.
 *                                                 2. The param of outputDeviceInfo is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVSession_AcquireOutputDevice(OH_AVSession* avsession,
    AVSession_OutputDeviceInfo** outputDeviceInfo)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Release outputDeviceInfo object.
 *
 * @param avsession The avsession instance pointer
 * @param outputDeviceInfo outputdeivce should be released.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1.The param of avsession is nullptr;
 *                                                 2.The param of outputDeviceInfo is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVSession_ReleaseOutputDevice(OH_AVSession* avsession,
    AVSession_OutputDeviceInfo *outputDeviceInfo)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

#ifdef __cplusplus
}
#endif

#endif // NATIVE_AVSESSION_H
/** @} */