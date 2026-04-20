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
 * @file native_avcastcontroller.h
 *
 * @brief Declare avcastcontroller interface.
 *
 * @library libohavsession.so
 * @syscap SystemCapability.Multimedia.AVSession.Core
 * @kit AVSessionKit
 * @since 23
 * @version 1.0
 */

#ifndef NATIVE_AVCASTCONTROLLER_H
#define NATIVE_AVCASTCONTROLLER_H

#include "info/application_target_sdk_version.h"
#include <stdint.h>
#include "native_avsession_errors.h"
#include "native_avsession.h"
#include "native_avqueueitem.h"
#include "native_avplaybackstate.h"

#ifdef __cplusplus
extern "C" {
#endif

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
 * @brief Declaring the callback struct for playback state change
 *
 * @since 23
 * @version 1.0
 */
typedef AVSessionCallback_Result(*OH_AVCastControllerCallback_PlaybackStateChanged)(
    OH_AVCastController* avcastcontroller, OH_AVSession_AVPlaybackState* playbackState, void* userData);

/**
 * @brief Declaring the callback struct for media item change
 *
 * @since 23
 * @version 1.0
 */
typedef AVSessionCallback_Result(*OH_AVCastControllerCallback_MediaItemChange)(OH_AVCastController* avcastcontroller,
    OH_AVSession_AVQueueItem* avQueueItem, void* userData);

/**
 * @brief Declaring the callback struct for Play Next
 *
 * @since 23
 * @version 1.0
 */
typedef AVSessionCallback_Result(*OH_AVCastControllerCallback_PlayNext)(OH_AVCastController* avcastcontroller,
    void* userData);

/**
 * @brief Declaring the callback struct for Play Previous
 *
 * @since 23
 * @version 1.0
 */
typedef AVSessionCallback_Result(*OH_AVCastControllerCallback_PlayPrevious)(OH_AVCastController* avcastcontroller,
    void* userData);

/**
 * @brief Declaring the callback struct for seekDone
 *
 * @since 23
 * @version 1.0
 */
typedef AVSessionCallback_Result(*OH_AVCastControllerCallback_SeekDone)(OH_AVCastController* avcastcontroller,
    int32_t position, void* userData);

/**
 * @brief Declaring the callback struct for EndOfStream
 *
 * @since 23
 * @version 1.0
 */
typedef AVSessionCallback_Result(*OH_AVCastControllerCallback_EndOfStream)(OH_AVCastController* avcastcontroller,
    void* userData);

/**
 * @brief Declaring the callback struct for cast play error
 *
 * @since 23
 * @version 1.0
 */
typedef AVSessionCallback_Result(*OH_AVCastControllerCallback_Error)(OH_AVCastController* avcastcontroller,
    void* userData, AVSession_ErrCode error);

/**
 * @brief Request to destory the avcastcontroller.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER} The param of avcastcontroller is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_Destroy(OH_AVCastController* avcastcontroller)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get the playback status of the current player.
 * Do not release the playbackState pointer separately.
 * It will be destroyed when {@link OH_AVCastController_Destroy} is called.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param playbackState The returned playbackState
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avcastcontroller is nullptr.
 *                                                 2. The param of playbackState is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_GetPlaybackState(OH_AVCastController* avcastcontroller,
    OH_AVSession_AVPlaybackState** playbackState)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to register playback state changed callback.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param filter The filter {@link AVSession_PlaybackFilter} of playback state determines
 *               which param are included in callback.
 * @param callback The callback {@link OH_AVCastControllerCallback_PlaybackStateChanged} to be registered.
 * @param userData User data which is passed by user.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avcastcontroller is nullptr.
 *                                                 2. The param of callback is nullptr.
 *                                                 3. filter is invalid 
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_RegisterPlaybackStateChangedCallback(OH_AVCastController* avcastcontroller,
    int32_t filter, OH_AVCastControllerCallback_PlaybackStateChanged callback, void* userData)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to unregister playback state changed callback.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param callback the {@link OH_AVCastControllerCallback_PlaybackStateChanged} to be unregistered.
 * @return Function result code：
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avcastcontroller is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_UnregisterPlaybackStateChangedCallback(OH_AVCastController* avcastcontroller,
    OH_AVCastControllerCallback_PlaybackStateChanged callback)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to register current media changed callback.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param callback the {@link OH_AVCastControllerCallback_MediaItemChange} to be registered.
 * @param userData User data which is passed by user.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avcastcontroller is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_RegisterMediaItemChangedCallback(OH_AVCastController* avcastcontroller,
    OH_AVCastControllerCallback_MediaItemChange callback, void* userData)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to unregister current media item changed callback.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param callback the {@link OH_AVCastControllerCallback_MediaItemChange} to be unregistered.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avcastcontroller is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_UnregisterMediaItemChangedCallback(OH_AVCastController* avcastcontroller,
    OH_AVCastControllerCallback_MediaItemChange callback)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to register playnext callback send by remote side or media center.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param callback the {@link OH_AVCastControllerCallback_PlayNext} to be registered.
 * @param userData User data which is passed by user.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avcastcontroller is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_RegisterPlayNextCallback(OH_AVCastController* avcastcontroller,
    OH_AVCastControllerCallback_PlayNext callback, void* userData)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to unregister playnext callback send by remote side or media center.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param callback the {@link OH_AVCastControllerCallback_PlayNext} to be unregistered.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avcastcontroller is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_UnregisterPlayNextCallback(OH_AVCastController* avcastcontroller,
    OH_AVCastControllerCallback_PlayNext callback)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to register playprevious command callback send by remote side or media center.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param callback the {@link OH_AVCastControllerCallback_PlayPrevious} to be registered.
 * @param userData User data which is passed by user.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avcastcontroller is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_RegisterPlayPreviousCallback(OH_AVCastController* avcastcontroller,
    OH_AVCastControllerCallback_PlayPrevious callback, void* userData)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to unregister playprevious command callback send by remote side or media center.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param callback the {@link OH_AVCastControllerCallback_PlayPrevious} to be unregistered.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avcastcontroller is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_UnregisterPlayPreviousCallback(OH_AVCastController* avcastcontroller,
    OH_AVCastControllerCallback_PlayPrevious callback)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to register seek done callback.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param callback the {@link OH_AVCastControllerCallback_SeekDone} to be registered.
 * @param userData User data which is passed by user.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avcastcontroller is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_RegisterSeekDoneCallback(OH_AVCastController* avcastcontroller,
    OH_AVCastControllerCallback_SeekDone callback, void* userData)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to unregister seek done callback.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param callback the {@link OH_AVCastControllerCallback_SeekDone} to be unregistered.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avcastcontroller is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_UnregisterSeekDoneCallback(OH_AVCastController* avcastcontroller,
    OH_AVCastControllerCallback_SeekDone callback)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to register end of stream callback.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param callback the {@link OH_AVCastControllerCallback_EndOfStream} to be registered.
 * @param userData User data which is passed by user.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avcastcontroller is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_RegisterEndOfStreamCallback(OH_AVCastController* avcastcontroller,
    OH_AVCastControllerCallback_EndOfStream callback, void* userData)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to unregister end of stream callback.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param callback the {@link OH_AVCastControllerCallback_EndOfStream} to be unregistered.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avcastcontroller is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_UnregisterEndOfStreamCallback(OH_AVCastController* avcastcontroller,
    OH_AVCastControllerCallback_EndOfStream callback)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to register listener for playback error events.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param callback the {@link OH_AVCastControllerCallback_Error} to be registered.
 * @param userData User data which is passed by user.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avcastcontroller is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_RegisterErrorCallback(OH_AVCastController* avcastcontroller,
    OH_AVCastControllerCallback_Error callback, void* userData)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to unregister listener for playback error events.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param callback the {@link OH_AVCastControllerCallback_Error} to be unregistered.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avcastcontroller is nullptr.
 *                                                 2. The param of callback is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_UnregisterErrorCallback(OH_AVCastController* avcastcontroller,
    OH_AVCastControllerCallback_Error callback)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to send common command to Remote, only support to send play pause stop playnext playprevious command.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param avCastControlcommand control command {@link AVSession_AVCastControlCommandType}.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER} The param of avcastcontroller is nullptr.
 *         {@link AV_SESSION_ERR_CODE_COMMAND_INVALID} The param of avCastControlcommand is invalid.
 *         {@link AV_SESSION_ERR_CODE_REMOTE_CONNECTION_NOT_EXIST} The remote connection is not established.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_SendCommonCommand(OH_AVCastController* avcastcontroller,
    AVSession_AVCastControlCommandType* avCastControlcommand)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to send seek command to Remote.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param seekTimeMS seek time, the unit of time is milliseconds.
 * @return Function result code:
 *        {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *        {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *        {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                               1. The param of avcastcontroller is nullptr.
 *                                               2. seekTimeMS invalid.
 *        {@link AV_SESSION_ERR_CODE_REMOTE_CONNECTION_NOT_EXIST} The remote connection is not established.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_SendSeekCommand(OH_AVCastController* avcastcontroller, int32_t seekTimeMS)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to send forward command to Remote.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param forwardTimeS forward time, the unit of time is seconds.
 * @return Function result code:
 *        {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *        {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *        {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                1. The param of avcastcontroller is nullptr.
 *                                                2. forwardTimeS invalid.
 *        {@link AV_SESSION_ERR_CODE_REMOTE_CONNECTION_NOT_EXIST} The remote connection is not established.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_SendFastForwardCommand(OH_AVCastController* avcastcontroller,
    int32_t forwardTimeS)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to send rewind command to Remote.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param rewindTimeS rewind time, the unit of time is seconds.
 * @return Function result code:
 *        {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *        {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *        {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                1. The param of avcastcontroller is nullptr.
 *                                                2. rewindTimeS invalid.
 *        {@link AV_SESSION_ERR_CODE_REMOTE_CONNECTION_NOT_EXIST} The remote connection is not established.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_SendRewindCommand(OH_AVCastController* avcastcontroller, int32_t rewindTimeS)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to send set speed command to Remote.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param speed control command {@link AVSession_PlaybackSpeed}.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avcastcontroller is nullptr.
 *                                                 2. speed invalid.
 *         {@link AV_SESSION_ERR_CODE_REMOTE_CONNECTION_NOT_EXIST} The remote connection is not established.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_SendSetSpeedCommand(OH_AVCastController* avcastcontroller,
    AVSession_PlaybackSpeed speed)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to send volume command to Remote.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param volume volume.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avcastcontroller is nullptr.
 *                                                 2. volume invalid.
 *         {@link AV_SESSION_ERR_CODE_REMOTE_CONNECTION_NOT_EXIST} The remote connection is not established.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_SendVolumeCommand(OH_AVCastController* avcastcontroller, int32_t volume)
__attribute__((__availability__(ohos, introduced=23.0.0)));
    
/**
 * @brief Request to prepare the current player item, this is needed for sink media information displaying.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param avqueueItem  media item info {@link OH_AVSession_AVQueueItem}.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avcastcontroller is nullptr.
 *                                                 2. The param of avqueueItem is nullptr.
 *         {@link AV_SESSION_ERR_CODE_REMOTE_CONNECTION_NOT_EXIST} The remote connection is not established.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_Prepare(OH_AVCastController* avcastcontroller,
    OH_AVSession_AVQueueItem *avqueueItem)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Request to Play the current item, should contain media uri otherwise the playback will fail.
 *
 * @param avcastcontroller The avcastcontroller instance pointer
 * @param avqueueItem  media item info {@link OH_AVSession_AVQueueItem}.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_SERVICE_EXCEPTION} Internal server error.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1. The param of avcastcontroller is nullptr.
 *                                                 2. The param of avqueueItem is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_AVCastController_Start(OH_AVCastController* avcastcontroller,
    OH_AVSession_AVQueueItem *avqueueItem)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

#ifdef __cplusplus
}
#endif

#endif // NATIVE_AVCASTCONTROLLER_H
/** @} */