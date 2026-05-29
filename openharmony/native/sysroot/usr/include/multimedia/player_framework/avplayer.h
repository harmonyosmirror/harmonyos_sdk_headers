/*
 * Copyright (C) 2023 Huawei Device Co., Ltd.
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
 * @addtogroup AVPlayer
 * @{
 *
 * @brief Provides APIs of Playback capability for Media Source.
 *
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 11
 * @version 1.0
 */

/**
 * @file avplayer.h
 *
 * @brief Defines the avplayer APIs. Uses the Native APIs provided by Media AVPlayer
 *        to play the media source.
 *
 * @kit MediaKit
 * @library libavplayer.so
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 11
 * @version 1.0
 */

#ifndef MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVPLAYER_H
#define MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVPLAYER_H

#include "info/application_target_sdk_version.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "native_averrors.h"
#include "avplayer_base.h"
#include "native_window/external_window.h"
#include "ohaudio/native_audiostream_base.h"
#include "native_avcodec_base.h"
#include "avmedia_source.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief MediaKeySession field.
 * @since 12
 * @version 1.0
 */
typedef struct MediaKeySession MediaKeySession;
/**
 * @brief DRM_MediaKeySystemInfo field.
 * @since 12
 * @version 1.0
 */
typedef struct DRM_MediaKeySystemInfo DRM_MediaKeySystemInfo;

/**
 * @brief Call back will be invoked when updating DRM information.
 * @param player Player instance.
 * @param mediaKeySystemInfo DRM information.
 * @return void
 * @since 12
 * @version 1.0
 */
typedef void (*Player_MediaKeySystemInfoCallback)(OH_AVPlayer *player, DRM_MediaKeySystemInfo* mediaKeySystemInfo);

/**
 * @brief Create a player
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @return Returns a pointer to an OH_AVPlayer instance for success, nullptr for failure
 * Possible failure causes: 1. failed to PlayerFactory::CreatePlayer. 2. failed to new PlayerObject.
 * @since 11
 * @version 1.0
*/
OH_AVPlayer *OH_AVPlayer_Create(void) __attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Sets the playback source for the player. The corresponding source can be http url
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param url Indicates the playback source.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr, url is null or player setUrlSource failed.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_SetURLSource(OH_AVPlayer *player, const char *url)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Sets the playback media file descriptor source for the player.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param fd Indicates the file descriptor of media source.
 * @param offset Indicates the offset of media source in file descriptor.
 * @param size Indicates the size of media source.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or player setFdSource failed.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_SetFDSource(OH_AVPlayer *player, int32_t fd, int64_t offset, int64_t size)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Prepares the playback environment and buffers media data asynchronous.
 *
 * This function must be called after {@link SetSource}.
 *
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or player Prepare failed.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_Prepare(OH_AVPlayer *player) __attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Start playback.
 *
 * This function must be called after {@link Prepare}. If the player state is <b>Prepared</b>,
 * this function is called to start playback.
 *
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or player Play failed.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_Play(OH_AVPlayer *player) __attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Pauses playback.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or player Pause failed.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_Pause(OH_AVPlayer *player) __attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Stop playback.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or player Stop failed.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_Stop(OH_AVPlayer *player) __attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Restores the player to the initial state.
 *
 * After the function is called, add a playback source by calling {@link SetSource},
 * call {@link Play} to start playback again after {@link Prepare} is called.
 *
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or player Reset failed.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_Reset(OH_AVPlayer *player) __attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Releases player resources async
 *
 *  Asynchronous release guarantees the performance
 *  but cannot ensure whether the surfacebuffer is released.
 *  The caller needs to ensure the life cycle security of the surface
 *
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or player Release failed.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_Release(OH_AVPlayer *player) __attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Releases player resources sync
 *
 * Synchronous release ensures effective release of surfacebuffer
 * but this interface will take a long time (when the engine is not idle state)
 * requiring the caller to design an asynchronous mechanism by itself
 *
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or player ReleaseSync failed.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_ReleaseSync(OH_AVPlayer *player) __attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Sets the volume of the player.
 *
 * This function can be used during playback or pause. The value <b>0</b> indicates no sound,
 * and <b>1</b> indicates the original volume. If no audio device is started or no audio
 * stream exists, the value <b>-1</b> is returned.
 *
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param leftVolume Indicates the target volume of the left audio channel to set,
 *        ranging from 0 to 1. each step is 0.01.
 * @param rightVolume Indicates the target volume of the right audio channel to set,
 *        ranging from 0 to 1. each step is 0.01.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or player SetVolume failed.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_SetVolume(OH_AVPlayer *player, float leftVolume, float rightVolume)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Changes the playback position.
 *
 * This function can be used during play or pause.
 *
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param mSeconds Indicates the target playback position, accurate to milliseconds.
 * @param mode Indicates the player seek mode. For details, see {@link AVPlayerSeekMode}.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or player Seek failed.
 * @since 11
 * @version 1.0
*/
OH_AVErrCode OH_AVPlayer_Seek(OH_AVPlayer *player, int32_t mSeconds, AVPlayerSeekMode mode)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Obtains the playback position, accurate to millisecond.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param currentTime Indicates the playback position.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or player GetCurrentTime failed.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_GetCurrentTime(OH_AVPlayer *player, int32_t *currentTime)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief get the video width.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param videoWidth The video width
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_GetVideoWidth(OH_AVPlayer *player, int32_t *videoWidth)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief get the video height.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param videoHeight The video height
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_GetVideoHeight(OH_AVPlayer *player, int32_t *videoHeight)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief set the player playback rate
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param speed the rate mode {@link AVPlaybackSpeed} which can set.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or player SetPlaybackSpeed failed.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_SetPlaybackSpeed(OH_AVPlayer *player, AVPlaybackSpeed speed)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Sets playback rate.
 * Supported states: prepared/playing/paused/completed.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to OH_AVPlayer instance
 * @param rate Playback rate, valid range is 0.125 ~ 4.
 * @return OH_AVErrCode Operation result code
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if called in unsupported state or during live streaming.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr, or rate is out of range.
 * @since 20
 */
OH_AVErrCode OH_AVPlayer_SetPlaybackRate(OH_AVPlayer *player, float rate)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief get the current player playback rate
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param speed the rate mode {@link AVPlaybackSpeed} which can get.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or player GetPlaybackSpeed failed.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_GetPlaybackSpeed(OH_AVPlayer *player, AVPlaybackSpeed *speed)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief get the current player playback rate
 * @param player Pointer to an OH_AVPlayer instance
 * @param rate the playback rate which can get.
 * @return Returns {@link AV_ERR_OK} if the current player playback rate is get; returns an error code defined
 * in {@link native_averrors.h} otherwise.
 * @since 23
 */
OH_AVErrCode OH_AVPlayer_GetPlaybackRate(OH_AVPlayer *player, float *rate)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set the renderer information of the player's audio renderer
 * @param player Pointer to an OH_AVPlayer instance
 * @param streamUsage The value {@link OH_AudioStream_Usage} used for the stream usage of the player audio render.
 * @return Function result code.
 *     {@link AV_ERR_OK} if the execution is successful.
 *     {@link AV_ERR_INVALID_VAL} if input player is nullptr or streamUsage value is invalid.
 * @since 12
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_SetAudioRendererInfo(OH_AVPlayer *player, OH_AudioStream_Usage streamUsage)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the interruption mode of the player's audio stream
 * @param player Pointer to an OH_AVPlayer instance
 * @param interruptMode The value {@link OH_AudioInterrupt_Mode} used for the interruption mode of
 *                      the player audio stream.
 * @return Function result code.
 *     {@link AV_ERR_OK} if the execution is successful.
 *     {@link AV_ERR_INVALID_VAL} if input player is nullptr or interruptMode value is invalid.
 * @since 12
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_SetAudioInterruptMode(OH_AVPlayer *player, OH_AudioInterrupt_Mode interruptMode)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the effect mode of the player's audio stream
 * @param player Pointer to an OH_AVPlayer instance
 * @param effectMode The value {@link OH_AudioStream_AudioEffectMode} used for the effect mode of
 *                   the player audio stream.
 * @return Function result code.
 *     {@link AV_ERR_OK} if the execution is successful.
 *     {@link AV_ERR_INVALID_VAL} if input player is nullptr or effectMode value is invalid.
 * @since 12
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_SetAudioEffectMode(OH_AVPlayer *player, OH_AudioStream_AudioEffectMode effectMode)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief set the bit rate use for hls player
 *
 * the playback bitrate expressed in bits per second, expressed in bits per second,
 * which is only valid for HLS protocol network flow. By default,
 * the player will select the appropriate bit rate and speed according to the network connection.
 * report the effective bit rate linked list by "INFO_TYPE_BITRATE_COLLECT"
 * set and select the specified bit rate, and select the bit rate that is less than and closest
 * to the specified bit rate for playback. When ready, read it to query the currently selected bit rate.
 *
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param bitRate the bit rate, The unit is bps.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or player SelectBitRate failed.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_SelectBitRate(OH_AVPlayer *player, uint32_t bitRate)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Method to set the surface.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param window A pointer to a OHNativeWindow instance, see {@link OHNativeWindow}
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr, input window is nullptr,
 *          or player SetVideoSurface failed.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode  OH_AVPlayer_SetVideoSurface(OH_AVPlayer *player, OHNativeWindow *window)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Obtains the total duration of media files, accurate to milliseconds.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param duration Indicates the total duration of media files.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or player GetDuration failed.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_GetDuration(OH_AVPlayer *player, int32_t *duration)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief get current playback state.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param state the current playback state
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_GetState(OH_AVPlayer *player, AVPlayerState *state)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Checks whether the player is playing.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @return Returns true if the playback is playing; Return false if not or input player is nullptr.
 * @since 11
 * @version 1.0
 */
bool OH_AVPlayer_IsPlaying(OH_AVPlayer *player) __attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Returns the value whether single looping is enabled or not .
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @return Returns true if the playback is single looping; Return false if not or input player is nullptr.
 * @since 11
 * @version 1.0
 */
bool OH_AVPlayer_IsLooping(OH_AVPlayer *player) __attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Enables single looping of the media playback.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param loop The switch to set loop
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or player SetLooping failed.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_SetLooping(OH_AVPlayer *player, bool loop)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Method to set player callback.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param callback object pointer.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr, callback.onInfo or callback.onError is null,
 *         or player SetPlayerCallback failed.
 * @since 11
 * @deprecated since 12
 * @useinstead {@link OH_AVPlayer_SetPlayerOnInfoCallback} {@link OH_AVPlayer_SetPlayerOnErrorCallback}
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_SetPlayerCallback(OH_AVPlayer *player, AVPlayerCallback callback)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Select audio or subtitle track.
 *
 * By default, the first audio stream with data is played, and the subtitle track is not played.
 * After the settings take effect, the original track will become invalid. Please set subtitles
 * in prepared/playing/paused/completed state and set audio tracks in prepared state.
 *
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param index Track index
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or player SelectTrack failed.
 * @since 11
 * @version 1.0
*/
OH_AVErrCode OH_AVPlayer_SelectTrack(OH_AVPlayer *player, int32_t index)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Deselect the current audio or subtitle track.
 *
 * After audio is deselected, the default track will be played, and after subtitles are deselected,
 * they will not be played. Please set subtitles in prepared/playing/paused/completed state and set
 * audio tracks in prepared state.
 *
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param index Track index
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or player DeselectTrack failed.
 * @since 11
 * @version 1.0
*/
OH_AVErrCode OH_AVPlayer_DeselectTrack(OH_AVPlayer *player, int32_t index)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Obtain the currently effective track index.
 *
 * Please get it in the prepared/playing/paused/completed state.
 *
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param trackType Media type.
 * @param index Track index
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or player GetCurrentTrack failed.
 * @since 11
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_GetCurrentTrack(OH_AVPlayer *player, int32_t trackType, int32_t *index)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Method to set player media key system info callback.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param callback object pointer.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr, MediaKeySystemInfoCallback is null
 *         player SetDrmSystemInfoCallback failed, SetDrmSystemInfoCallback failed or SetDrmSystemInfoCallback failed.
 * @since 12
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_SetMediaKeySystemInfoCallback(OH_AVPlayer *player,
    Player_MediaKeySystemInfoCallback callback)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains media key system info to create media key session.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param mediaKeySystemInfo Media key system info.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or no memory.
 * @since 12
 * @version 1.0
 */
OH_AVErrCode OH_AVPlayer_GetMediaKeySystemInfo(OH_AVPlayer *player, DRM_MediaKeySystemInfo *mediaKeySystemInfo)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set decryption info.
 *
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance
 * @param mediaKeySession A media key session instance with decryption function.
 * @param secureVideoPath Require secure decoder or not.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or player SetDecryptConfig failed.
 * @since 12
 * @version 1.0
*/
OH_AVErrCode OH_AVPlayer_SetDecryptionConfig(OH_AVPlayer *player, MediaKeySession *mediaKeySession,
    bool secureVideoPath)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Method to set player information notify callback.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance.
 * @param callback Pointer to callback function, nullptr indicates unregister callback.
 * @param userData Pointer to user specific data.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is null or player SetOnInfoCallback failed.
 * @since 12
 */
OH_AVErrCode OH_AVPlayer_SetOnInfoCallback(OH_AVPlayer *player, OH_AVPlayerOnInfoCallback callback, void *userData)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Method to set player error callback.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player Pointer to an OH_AVPlayer instance.
 * @param callback Pointer to callback function, nullptr indicates unregister callback.
 * @param userData Pointer to user specific data.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is null or player SetOnErrorCallback failed.
 * @since 12
 */
OH_AVErrCode OH_AVPlayer_SetOnErrorCallback(OH_AVPlayer *player, OH_AVPlayerOnErrorCallback callback, void *userData)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets the volume mode of the AVPlayer.
 * @param player Pointer to an <b>OH_AVPlayer</b> instance.
 * @param volumeMode Volume mode, which is defined in {@link OH_AudioStream_VolumeMode}.
 * @return Result code.
 *     {@link AV_ERR_OK}: The execution is successful.
 *     {@link AV_ERR_INVALID_VAL}: The value of <b>player</b> is a null pointer or
 *         the value of <b>volumeMode</b> is invalid.
 *     {@link AV_ERR_INVALID_STATE}: The function is called in an incorrect state.
 *         This function should be called prior to <b>prepare</b>.
 *     {@link AV_ERR_SERVICE_DIED}: System errors such as media service breakdown.
 * @since 19
 */
OH_AVErrCode OH_AVPlayer_SetVolumeMode(OH_AVPlayer *player, OH_AudioStream_VolumeMode volumeMode)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Sets the loudness gain of current media. The default gain is 0.0 dB.
 * This API can be called only when the AVPlayer is in the prepared, playing, paused completed or stopped state.
 * The default loudness gain is 0.0dB. The stream usage of the player must be
 * {@link OH_AudioStream_Usage#AUDIOSTREAM_USAGE_MUSIC}, {@link OH_AudioStream_Usage#AUDIOSTREAM_USAGE_MOVIE}
 * or {@link OH_AudioStream_Usage#AUDIOSTREAM_USAGE_AUDIOBOOK}.
 * The latency mode of the audio renderer must be {@link OH_AudioStream_LatencyMode#AUDIOSTREAM_LATENCY_MODE_NORMAL}.
 * If AudioRenderer is played through the high-resolution pipe, this operation is not supported.
 *
 * @param player Pointer to an <b>OH_AVPlayer</b> instance.
 * @param loudnessGain Loudness gain to set which changes from -90.0 to 24.0, expressing in dB.
 * @return Function result code:
 *         {@link AV_ERR_OK} If the execution is successful.
 *         {@link AV_ERR_INVALID_VAL}:The value of <b>player</b> is a null pointer or
 *                                    the value of <b>loudnessGain</b> is invalid.
 *         {@link AV_ERR_INVALID_STATE}: The function is called in an incorrect state. or the stream usage of
 *                                      audioRendererInfo is not one of {@link OH_AudioStream_Usage#AUDIOSTREAM_USAGE_MUSIC},
 *                                 {@link OH_AudioStream_Usage#AUDIOSTREAM_USAGE_MOVIE} or {@link OH_AudioStream_Usage#AUDIOSTREAM_USAGE_AUDIOBOOK}.
 *         {@link AV_ERR_SERVICE_DIED}:  System errors such as media service breakdown.
 * @since 21
 */
OH_AVErrCode OH_AVPlayer_SetLoudnessGain(OH_AVPlayer *player, float loudnessGain)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Set the media source of the player. The data of this media source is provided by the application.
 * @param {OH_AVPlayer*} player Pointer to an OH_AVPlayer instance
 * @param {OH_AVDataSourceExt*} datasrc Pointer to an OH_AVDataSourceExt instance
 * @param {void*} userData The handle passed in by the user is used to pass in the callback
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr or datasrc is nullptr.
 * @since 21
 */
OH_AVErrCode OH_AVPlayer_SetDataSource(OH_AVPlayer *player, OH_AVDataSourceExt* datasrc, void* userData)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Get the player media source info.
 *
 * This function can be used after media source is set and player is in
 * initialized/prepared/playing/paused/completed/stopped state.
 * It should be noted that the life cycle of the OH_AVFormat instance pointed to by the return value * needs
 * to be manually released by the caller.
 *
 * @param player Pointer to an OH_AVPlayer instance
 * @return Returns the player's source media info if the execution is successful, otherwise returns nullptr.
 * Possible failure causes:
 *   1. player is invaild.
 *   2. player's media source is invalid.
 * @since 22
 */
OH_AVFormat *OH_AVPlayer_GetMediaDescription(OH_AVPlayer *player)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Get the track info of player media source by the index.
 *
 * This function can be used after media source is set and player is in
 * initialized/prepared/playing/paused/completed/stopped state.
 * It should be noted that the life cycle of the OH_AVFormat instance pointed to by the return value * needs
 * to be manually released by the caller.
 *
 * @param player Pointer to an OH_AVPlayer instance
 * @param index Indicates tracks array index.
 * @return Returns one track info of player media source by the index if the execution is successful,
 * otherwise returns nullptr.
 * Possible failure causes:
 *   1. player is invaild.
 *   2. player's media source is invalid.
 *   3. index is out of tracks array's bounds.
 * @since 22
 */
OH_AVFormat *OH_AVPlayer_GetTrackDescription(OH_AVPlayer *player, uint32_t index)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Get the statistic metrics info of current player.
 *     This API can be called only when the AVPlayer is in the prepared, playing, paused, completed, or stopped state.
 *     It should be noted that the life cycle of the OH_AVFormat instance pointed to by the return value * needs
 *     to be manually released by the caller.
 * @param {OH_AVPlayer*} player Pointer to an OH_AVPlayer instance
 * @return Returns the player's statistic metrics info.
 *     if the execution is successful, otherwise returns nullptr. Possible failure causes:
 *     1. player is invalid.
 * @since 23
 */
OH_AVFormat *OH_AVPlayer_GetPlaybackStatisticMetrics(OH_AVPlayer *player)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Add subtitle resource represented by FD to the player. Currently, the external subtitle must be set after
 *     fdSrc of the video resource is set in an AVPlayer instance.
 * @param {OH_AVPlayer} player Pointer to an OH_AVPlayer instance
 * @param {int32_t} fd Indicates the file descriptor of subtitle source.
 * @param {int64_t} offset Indicates the offset of media source in file descriptor.
 * @param {int64_t} size Indicates the size of media source.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr.
 * @since 23
 */
OH_AVErrCode OH_AVPlayer_AddFdSubtitleSource(OH_AVPlayer *player, int32_t fd, int64_t offset, int64_t size)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Add subtitle resource represented by url to the player. The external subtitle must be set after
 * url is set in an AVPlayer instance.
 * @param player Pointer to an OH_AVPlayer instance
 * @param url Indicates the url of subtitle source.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr.
 * @since 23
 */
OH_AVErrCode OH_AVPlayer_AddUrlSubtitleSource(OH_AVPlayer *player, const char *url)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set playback start position and end position. After the setting, only the content in the specified range of
 * the audio or video file is played. It can be used in the initialized, prepared, paused, stopped, or completed state.
 * @param player Pointer to an OH_AVPlayer instance
 * @param mSecondsStart Playback start position, should be in [0, duration),
 *        -1 means that the start position is not set, and the playback will start from 0.
 * @param mSecondsEnd Playback end position, which should usually be in (startTimeMs, duration],
 *        -1 means that the end position is not set, and the playback will be ended at the end of the stream.
 * @param closestRange Use closest seek policy or not.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if operation not allowed.
 * @since 23
 */
OH_AVErrCode OH_AVPlayer_SetPlaybackRange(OH_AVPlayer *player, int32_t mSecondsStart, int32_t mSecondsEnd,
    bool closestRange)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * Mute the media stream. This API can be called only when the AVPlayer is in the prepared, playing,
 * paused, or completed state.
 * @param player Pointer to an OH_AVPlayer instance
 * @param mediaType Specified media type, see {@link OH_MediaType} in {@link native_avcodec_base.h}
 * @param muted true for mute, false for unmute.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input parameter is invalid.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if operation not allowed.
 * @since 23
 */
OH_AVErrCode OH_AVPlayer_SetMediaMuted(OH_AVPlayer *player, OH_MediaType mediaType, bool muted)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get the playback position, accurate to millisecond. This API can be called only when the AVPlayer is in
 * the prepared, playing, paused, or completed state.
 * @param player Pointer to an OH_AVPlayer instance
 * @return Returns the playback position in milliseconds.
 *         Return -1 if the player is nullptr or invalid.
 * @since 23
 */
int32_t OH_AVPlayer_GetPlaybackPosition(OH_AVPlayer *player) __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Checks whether the media source supports continuous seek.
 *     The actual value is returned when this API is called in the prepared, playing, paused, or completed state.
 *     The value **false** is returned if it is called in other states. For devices that do not support the seek
 *     operation in {@link AV_SEEK_CONTINUOUS} mode, false is returned.
 * @param player Pointer to an OH_AVPlayer instance.
 * @return true - seek continuous is supported.
 *         false - seek continuous is not supported or the support status is uncertain.
 * @since 23
 */
bool OH_AVPlayer_IsSeekContinuousSupported(OH_AVPlayer *player)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Select track with switch mode when playing a resource with multiple audio and video tracks.
 * @param player Pointer to an OH_AVPlayer instance
 * @param index The selected track index.
 * @param mode The switch mode.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input parameter is invalid.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if operation not allowed.
 * @since 23
 */
OH_AVErrCode OH_AVPlayer_SelectTrackWithMode(OH_AVPlayer *player, int32_t index, AVPlayerTrackSwitchMode mode)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Subscribes to update events of the maximum audio level value, which is periodically reported when audio
 * resources are played.
 * @param player Pointer to an OH_AVPlayer instance
 * @param callback Pointer to callback function, nullptr indicates unregister callback.
 * @param userData Pointer to user specific data.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr.
 * @since 23
 */
OH_AVErrCode OH_AVPlayer_SetAmplitudeUpdateCallback(OH_AVPlayer *player, OH_AVPlayerOnAmplitudeUpdateCallback callback,
    void *userData)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Subscribes to events indicating that a Supplemental Enhancement Information (SEI) message is received. This
 *     applies only to HTTP-FLV live streaming and is triggered when SEI messages are present in the video stream.
 *     You must initiate the subscription before calling prepare.
 * @param player Pointer to an OH_AVPlayer instance
 * @param payloadTypes playload types
 * @param typeNum The size of the playload types array.
 * @param callback Pointer to callback function, nullptr indicates unregister callback.
 * @param userData Pointer to user specific data
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr.
 * @since 23
 */
OH_AVErrCode OH_AVPlayer_SetSeiReceivedCallback(OH_AVPlayer *player, const int32_t *payloadTypes, uint32_t typeNum,
    OH_AVPlayerOnSeiMessageReceivedCallback callback, void *userData)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get the number of message items in SEI message array.
 * @param message Pointer to an OH_AVSeiMessageArray instance
 * @return The number of message items in SEI message array
 * @since 23
 */
uint32_t OH_AVSeiMessage_GetSeiCount(OH_AVSeiMessageArray *message)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get SEI of the message item by index in SEI message array.
 * @param message Pointer to an OH_AVSeiMessageArray instance
 * @param index The index of the message item
 * @return The SEI of the message item
 * @since 23
 */
OH_AVFormat *OH_AVSeiMessage_GetSei(OH_AVSeiMessageArray *message, uint32_t index)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set video window size for super-resolution. This API can be called when the AVPlayer is in the initialized,
 *     prepared, playing, paused, completed, or stopped state.The input parameter values must be in the range
 *     of 320 x 320 to 1920 x 1080 (in px).
 * @param player Pointer to an OH_AVPlayer instance
 * @param width Width of the window. The value range is [320 - 1920], in px.
 * @param height Height of the window. The value range is [320 - 1080], in px.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr, or Parameter errord.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if Operation not allowed.
 *         {@link AV_ERR_SUPER_RESOLUTION_UNSUPPORTED} if Super resolution is not supported.
 *         {@link AV_ERR_SUPER_RESOLUTION_NOT_ENABLED} if Missing enable super resolution feature in{@link
 *          OH_AVPlaybackStrategy}.
 * @since 23
 */
OH_AVErrCode OH_AVPlayer_SetTargetVideoWindowSize(OH_AVPlayer *player, int32_t width, int32_t height)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Enable or disable super-resolution dynamically. This API can be called when the AVPlayer is in the
 * initialized, prepared, playing, paused, completed, or stopped state.
 * Must enable super-resolution feature in {@link OH_AVPlaybackStrategy} before calling prepare.
 * @param player Pointer to an OH_AVPlayer instance.
 * @param enabled true: super-resolution enabled; false: super-resolution disabled.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr, or Parameter error.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if Operation not allowed.
 *         {@link AV_ERR_SUPER_RESOLUTION_UNSUPPORTED} if Super resolution is not supported.
 *         {@link AV_ERR_SUPER_RESOLUTION_NOT_ENABLED} if Missing enable super resolution feature in{@link
 *          OH_AVPlaybackStrategy}.
 * @since 23
 */
OH_AVErrCode OH_AVPlayer_SetVideoSuperResolutionEnable(OH_AVPlayer *player, bool enabled)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Create a playback strategy instance
 * @return a playback strategy instance, nullptr if fails.
 * @since 23
 */
OH_AVPlaybackStrategy *OH_AVPlaybackStrategy_Create(void) __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Release a playback strategy instance
 * @param strategy The OH_AVPlaybackStrategy instance.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input strategy is nullptr.
 * @since 23
 */
OH_AVErrCode OH_AVPlaybackStrategy_Destroy(OH_AVPlaybackStrategy *strategy)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Choose a stream width close to it.
 * @param strategy The OH_AVPlaybackStrategy used by avplayer.
 * @param width the preferred width chosen to play by avplayer at start.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input strategy is nullptr.
 * @since 23
 */
OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredWidth(OH_AVPlaybackStrategy *strategy, int32_t width)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Choose a stream height close to it.
 * @param strategy The OH_AVPlaybackStrategy used by avplayer.
 * @param height The preferred width chosen to play by avplayer at start.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input strategy is nullptr.
 * @since 23
 */
OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredHeight(OH_AVPlaybackStrategy *strategy, int32_t height)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Choose a preferred buffer duration close to it.
 * @param strategy The OH_AVPlaybackStrategy used by avplayer.
 * @param ms The preferred buffer duration chosen to play by avplayer at start.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input strategy is nullptr.
 * @since 23
 */
OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredBufferDuration(OH_AVPlaybackStrategy *strategy, int32_t ms)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Enable or disable preferred HDR mode.
 *
 * @param strategy Pointer to OH_AVPlaybackStrategy.
 * @param enabled true to enable HDR, false to disable.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input strategy is nullptr.
 * @since 23
 */
OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredHdr(OH_AVPlaybackStrategy *strategy, bool enabled)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set preferred subtitle language.
 *
 * @param strategy Pointer to OH_AVPlaybackStrategy.
 * @param lang Subtitle language code (e.g., "zh").
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input strategy is nullptr.
 * @since 23
 */
OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredSubtitleLanguage(OH_AVPlaybackStrategy *strategy, const char *lang)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set preferred audio language.
 *
 * @param strategy Pointer to OH_AVPlaybackStrategy.
 * @param lang Audio language code (e.g., "en").
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input strategy is nullptr.
 * @since 23
 */
OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredAudioLanguage(OH_AVPlaybackStrategy *strategy, const char *lang)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set muted media type for playback.
 *
 * @param strategy Pointer to OH_AVPlaybackStrategy.
 * @param mediaType Media type to mute.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input strategy is nullptr.
 * @since 23
 */
OH_AVErrCode OH_AVPlaybackStrategy_SetMutedMediaType(OH_AVPlaybackStrategy *strategy, OH_MediaType mediaType)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set whether to show the first frame on prepare.
 *
 * @param strategy Pointer to OH_AVPlaybackStrategy.
 * @param enabled true to show, false otherwise.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input strategy is nullptr.
 * @since 23
 */
OH_AVErrCode OH_AVPlaybackStrategy_SetShowFirstFrameOnPrepare(OH_AVPlaybackStrategy *strategy, bool enabled)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set the threshold for auto quick play.
 *
 * @param strategy Pointer to OH_AVPlaybackStrategy.
 * @param seconds Threshold value.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input strategy is nullptr.
 * @since 23
 */
OH_AVErrCode OH_AVPlaybackStrategy_SetThresholdForAutoQuickPlay(OH_AVPlaybackStrategy *strategy, double seconds)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Enable or disable super resolution.
 *
 * @param strategy Pointer to OH_AVPlaybackStrategy.
 * @param enabled true to enable, false to disable.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input strategy is nullptr.
 * @since 23
 */
OH_AVErrCode OH_AVPlaybackStrategy_SetSuperResolutionEnable(OH_AVPlaybackStrategy *strategy, bool enabled)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set preferred buffer duration for playing in seconds (double).
 *
 * @param strategy Pointer to OH_AVPlaybackStrategy.
 * @param seconds Buffer duration in seconds.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input strategy is nullptr.
 * @since 23
 */
OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredBufferDurationForPlaying(OH_AVPlaybackStrategy *strategy,
    double seconds)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set whether to keep decoding when muted.
 *
 * @param strategy Pointer to OH_AVPlaybackStrategy.
 * @param enabled true to keep decoding, false to pause decoding when muted.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input strategy is nullptr.
 * @since 23
 */
OH_AVErrCode OH_AVPlaybackStrategy_SetKeepDecodingOnMute(OH_AVPlaybackStrategy *strategy, bool enabled)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Set playback strategy to avplayer. This API can be called only when the avplayer is in the initialized state.
 * @param player Pointer to an OH_AVPlayer instance
 * @param strategy The playback strategy instance.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if operation not allowed.
 * @since 23
 */
OH_AVErrCode OH_AVPlayer_SetPlaybackStrategy(OH_AVPlayer *player, OH_AVPlaybackStrategy *strategy)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get statistic info of current player. This API can be called only when the avplayer is in the prepared,
 *     playing, or paused state.
 * @param {OH_AVPlayer*} player Pointer to an OH_AVPlayer instance
 * @return Returns a pointer to an OH_AVFormat instance.
 *         Return nullptr if the player is nullptr or invalid.
 * @since 23
 */
OH_AVFormat* OH_AVPlayer_GetPlaybackInfo(OH_AVPlayer *player) __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Sets an OH_AVMediaSource to the player.
 * @param player Pointer to an OH_AVPlayer instance.
 * @param source Indicates the media source.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input player is nullptr, source is null or player setUrlSource failed.
 * @since 23
 */
OH_AVErrCode OH_AVPlayer_SetMediaSource(OH_AVPlayer *player, OH_AVMediaSource *source)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get the track count of player media source.
 * @param player Pointer to an OH_AVPlayer instance
 * @return Returns the track count.
 * @since 23
 */
uint32_t OH_AVPlayer_GetTrackCount(OH_AVPlayer *player) __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get the player track info by the index.
 * @param player Pointer to an OH_AVPlayer instance
 * @param trackIndex Indicates tracks array index.
 * @return Returns a pointer to an OH_AVFormat instance.
 *         Return nullptr if the player is nullptr or invalid.
 *         Return nullptr if the trackIndex is invalid.
 * @since 23
 */
OH_AVFormat *OH_AVPlayer_GetTrackFormat(OH_AVPlayer *player, uint32_t trackIndex)
__attribute__((__availability__(ohos, introduced=23.0.0)));

#ifdef __cplusplus
}
#endif

#endif // MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVPLAYER_H
/** @} */