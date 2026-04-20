/*
 * Copyright (C) 2023-2025 Huawei Device Co., Ltd.
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
 * @file avplayer_base.h
 *
 * @brief Defines the structure and enumeration for Media AVPlayer.
 *
 * @kit MediaKit
 * @library libavplayer.so
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 11
 * @version 1.0
 */

#ifndef MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVPLAYER_BASH_H
#define MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVPLAYER_BASH_H

#include "info/application_target_sdk_version.h"
#include <stdint.h>

#include "native_avformat.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OH_AVPlayer OH_AVPlayer;

/**
 * @brief OH_AVSeiMessageArray field.
 * @since 23
 */
typedef struct OH_AVSeiMessageArray OH_AVSeiMessageArray;

/**
 * @brief OH_AVPlaybackStrategy field.
 * @since 23
 */
typedef struct OH_AVPlaybackStrategy OH_AVPlaybackStrategy;

/**
 * @brief Player States
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 11
 * @version 1.0
 */
typedef enum AVPlayerState {
    /* idle states */
    AV_IDLE = 0,
    /* initialized states */
    AV_INITIALIZED = 1,
    /* prepared states */
    AV_PREPARED = 2,
    /* playing states */
    AV_PLAYING = 3,
    /* paused states */
    AV_PAUSED = 4,
    /* stopped states */
    AV_STOPPED = 5,
    /* Play to the end states */
    AV_COMPLETED = 6,
    /* released states */
    AV_RELEASED = 7,
    /* error states */
    AV_ERROR = 8,
} AVPlayerState;

/**
 * @brief Player Seek Mode
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 11
 * @version 1.0
 */
typedef enum AVPlayerSeekMode {
    /* sync to keyframes after the time point. */
    AV_SEEK_NEXT_SYNC = 0,
    /* sync to keyframes before the time point. */
    AV_SEEK_PREVIOUS_SYNC,
    /**
     * @brief Sync to frames closest to the time point.
     * @syscap SystemCapability.Multimedia.Media.AVPlayer
     * @since 12
     */
    AV_SEEK_CLOSEST = 2,
    /**
     * Seek in continuous mode, which can provide a smoother dragging experience, but the device needs to support
     * the current stream to execute seek continuous. Before calling seek continuous,
     * check whether it is supported, see {@link #OH_AVPlayer_IsSeekContinuousSupported}.
     * @since 23
     */
    AV_SEEK_CONTINUOUS = 3,
} AVPlayerSeekMode;

/**
 * @brief Playback Speed
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 11
 * @version 1.0
 */
typedef enum AVPlaybackSpeed {
    /* Video playback at 0.75x normal speed */
    AV_SPEED_FORWARD_0_75_X,
    /* Video playback at normal speed */
    AV_SPEED_FORWARD_1_00_X,
    /* Video playback at 1.25x normal speed */
    AV_SPEED_FORWARD_1_25_X,
    /* Video playback at 1.75x normal speed */
    AV_SPEED_FORWARD_1_75_X,
    /* Video playback at 2.0x normal speed */
    AV_SPEED_FORWARD_2_00_X,
    /**
     * @brief Video playback at 0.5x normal speed.
     * @syscap SystemCapability.Multimedia.Media.AVPlayer
     * @since 12
     */
    AV_SPEED_FORWARD_0_50_X,
    /**
     * @brief Video playback at 1.5x normal speed.
     * @syscap SystemCapability.Multimedia.Media.AVPlayer
     * @since 12
     */
    AV_SPEED_FORWARD_1_50_X,
    /**
     * @brief Video playback at 3.0x normal speed.
     * @syscap SystemCapability.Multimedia.Media.AVPlayer
     * @since 13
    */
    AV_SPEED_FORWARD_3_00_X,
    /**
     * @brief Video playback at 0.25x normal speed.
     * @syscap SystemCapability.Multimedia.Media.AVPlayer
     * @since 13
    */
    AV_SPEED_FORWARD_0_25_X,
    /**
     * @brief Video playback at 0.125x normal speed.
     * @syscap SystemCapability.Multimedia.Media.AVPlayer
     * @since 13
    */
    AV_SPEED_FORWARD_0_125_X,
} AVPlaybackSpeed;

/**
 * @brief Player OnInfo Type
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 11
 * @version 1.0
 */
typedef enum AVPlayerOnInfoType {
    /* return the message when seeking done. */
    AV_INFO_TYPE_SEEKDONE = 0,
    /* return the message when speeding done. */
    AV_INFO_TYPE_SPEEDDONE = 1,
    /* return the message when select bitrate done */
    AV_INFO_TYPE_BITRATEDONE = 2,
    /* return the message when playback is end of steam. */
    AV_INFO_TYPE_EOS = 3,
    /* return the message when PlayerStates changed. */
    AV_INFO_TYPE_STATE_CHANGE = 4,
    /* return the current posion of playback automatically. */
    AV_INFO_TYPE_POSITION_UPDATE = 5,
    /* return the playback message. */
    AV_INFO_TYPE_MESSAGE = 6,
    /* return the message when volume changed. */
    AV_INFO_TYPE_VOLUME_CHANGE = 7,
    /* return the message when video size is first known or updated. */
    AV_INFO_TYPE_RESOLUTION_CHANGE = 8,
    /* return multiqueue buffering time. */
    AV_INFO_TYPE_BUFFERING_UPDATE = 9,
    /* return hls bitrate.
       Bitrate is to convert data into uint8_t array storage,
       which needs to be forcibly converted to uint32_t through offset access. */
    AV_INFO_TYPE_BITRATE_COLLECT = 10,
    /* return the message when audio focus changed. */
    AV_INFO_TYPE_INTERRUPT_EVENT = 11,
    /* return the duration of playback. */
    AV_INFO_TYPE_DURATION_UPDATE = 12,
    /* return the playback is live stream. */
    AV_INFO_TYPE_IS_LIVE_STREAM = 13,
    /* return the message when track changes. */
    AV_INFO_TYPE_TRACKCHANGE = 14,
    /* return the message when subtitle track info updated. */
    AV_INFO_TYPE_TRACK_INFO_UPDATE = 15,
    /* return the subtitle of playback. */
    AV_INFO_TYPE_SUBTITLE_UPDATE = 16,
    /** Return the reason when the audio output device changes. When this info is reported, the extra param of
     * {@link OH_AVPlayerOnInfo} is the same as {@OH_AudioStream_DeviceChangeReason} in audio framework.
     */
    AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE = 17,
    /**
     * @brief Event type indicating playback rate configuration completed.
     *
     * Triggered when playback rate are successfully applied,
     * notifying the application of the actual effective value.
     * Use defined key {@link OH_PLAYER_PLAYBACK_RATE} to retrieve value from the event data.
     * @since 20
     */
    AV_INFO_TYPE_PLAYBACK_RATE_DONE = 18,

    /**
     * @brief Super-resolution changed info type. 
     *
     * @since 23
     */
    AV_INFO_TYPE_SUPER_RESOLUTION_CHANGED = 19,
} AVPlayerOnInfoType;

/**
 * @brief Player Buffering Type
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 12
 * @version 1.0
 */
typedef enum AVPlayerBufferingType {
    /** Indicates the buffer to start buffering. */
    AVPLAYER_BUFFERING_START = 1,

    /** Indicates the buffer to end buffering and start playback. */
    AVPLAYER_BUFFERING_END,

    /** Indicates the current buffering percentage of the buffer. */
    AVPLAYER_BUFFERING_PERCENT,

    /** Indicates how long the buffer cache data can be played. */
    AVPLAYER_BUFFERING_CACHED_DURATION,
} AVPlayerBufferingType;

/**
 * @brief Enumerates the track switch mode
 * @since 23
 */
typedef enum AVPlayerTrackSwitchMode {
    /** Switch track smoothly */
    AV_TRACK_SWITCH_MODE_SMOOTH = 0,
    /** Switch track segment */
    AV_TRACK_SWITCH_MODE_SEGMENT = 1,
    /** Switch track closest */
    AV_TRACK_SWITCH_MODE_CLOSEST = 2,
} AVPlayerTrackSwitchMode;

/**
 * @brief Key to get state, value type is int32_t.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 12
 * @version 1.0
 */
extern const char* OH_PLAYER_STATE __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Key to get state change reason, value type is int32_t.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 12
 * @version 1.0
 */
extern const char* OH_PLAYER_STATE_CHANGE_REASON __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Key to get volume, value type is float.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 12
 * @version 1.0
 */
extern const char* OH_PLAYER_VOLUME __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Key to get bitrate count, value type is uint32_t array.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 12
 * @version 1.0
 */
extern const char* OH_PLAYER_BITRATE_ARRAY __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Key to get audio interrupt type, value type is int32_t.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 12
 * @version 1.0
 */
extern const char* OH_PLAYER_AUDIO_INTERRUPT_TYPE __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Key to get audio interrupt force, value type is int32_t.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 12
 * @version 1.0
 */
extern const char* OH_PLAYER_AUDIO_INTERRUPT_FORCE __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Key to get audio interrupt hint, value type is int32_t.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 12
 * @version 1.0
 */
extern const char* OH_PLAYER_AUDIO_INTERRUPT_HINT __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Key to get audio device change reason, value type is int32_t.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 12
 * @version 1.0
 */
extern const char* OH_PLAYER_AUDIO_DEVICE_CHANGE_REASON __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Key to get buffering type, value type is AVPlayerBufferingType.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 12
 * @version 1.0
 */
extern const char* OH_PLAYER_BUFFERING_TYPE __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Key to get buffering value, value type is int32_t.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 12
 * @version 1.0
 */
extern const char* OH_PLAYER_BUFFERING_VALUE __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Key to get seek position, value type is int32_t.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 12
 */
extern const char* OH_PLAYER_SEEK_POSITION __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Key to get playback speed, value type is AVPlaybackSpeed.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 12
 */
extern const char* OH_PLAYER_PLAYBACK_SPEED __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Key for retrieving effective playback rate, the value type is float.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 20
 */
extern const char* OH_PLAYER_PLAYBACK_RATE __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Key to get bitrate, value type is uint32_t.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 12
 */
extern const char* OH_PLAYER_BITRATE __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Key to get current position, value type is int32_t.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 12
 */
extern const char* OH_PLAYER_CURRENT_POSITION __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Key to get duration, value type is int64_t.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 12
 */
extern const char* OH_PLAYER_DURATION __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Key to get video width, value type is int32_t.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 12
 */
extern const char* OH_PLAYER_VIDEO_WIDTH __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Key to get video height, value type is int32_t.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 12
 */
extern const char* OH_PLAYER_VIDEO_HEIGHT __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Key to get message type, value type is int32_t.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 12
 */
extern const char* OH_PLAYER_MESSAGE_TYPE __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Key to get is live stream, value type is int32_t.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @since 12
 */
extern const char* OH_PLAYER_IS_LIVE_STREAM __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Key to get the value whether the media resource contains video content,
 *        value type is int32_t. 1 means true and 0 means false.
 *        Media description key, see {@link OH_AVPlayer_GetMediaDescription}
 * @since 22
 */
extern const char* OH_PLAYER_MD_KEY_HAS_VIDEO __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Key to get the value whether the media resource contains audio content,
 *        value type is int32_t. 1 means true and 0 means false.
 *        Media description key, see {@link OH_AVPlayer_GetMediaDescription}
 * @since 22
 */
extern const char* OH_PLAYER_MD_KEY_HAS_AUDIO __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Key to get the value whether the media resource contains subtitle content,
 *        value type is int32_t. 1 means true and 0 means false.
 *        Media description key, see {@link OH_AVPlayer_GetMediaDescription}
 * @since 22
 */
extern const char* OH_PLAYER_MD_KEY_HAS_SUBTITLE __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Key to get is track index, value type is int32_t.
 *        Track description key, see {@link OH_AVPlayer_GetTrackDescription}
 * @since 22
 */
extern const char* OH_PLAYER_MD_KEY_TRACK_INDEX __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * Sei message key for payload type.
 * @since 23
 */
extern const char* OH_PLAYER_SEI_PAYLOAD_TYPE __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * Sei message key for payload content.
 * @since 23
 */
extern const char* OH_PLAYER_SEI_PAYLOAD_CONTENT __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key to get whether the super resolution feature is enabled,
 *        value type is int32_t. The value is 1 when enabled, otherwise 0.
 *        Used in the info callback when super resolution state changes.
 * @since 23
 */
extern const char* OH_PLAYER_SUPER_RESOLUTION_ENABLE_STATE __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Track change info key for track info, its value is int32_t type.
 * @since 23
 */
extern const char* OH_PLAYER_TRACH_CHANGE_INFO_TRACK_INDEX __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Track change info key for track selected flag, its value is int32_t type.
 * @since 23
 */
extern const char* OH_PLAYER_TRACH_CHANGE_INFO_TRACK_SELECTED __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Subtitle update info key for duration, its value is int32_t type.
 * @since 23
 */
extern const char* OH_PLAYER_SUBTITLE_UPDATE_INFO_DURATION __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Subtitle update info key for start time, its value is int32_t type.
 * @since 23
 */
extern const char* OH_PLAYER_SUBTITLE_UPDATE_INFO_START_TIME __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Subtitle update info key for subtitle text, its value is string type.
 * @since 23
 */
extern const char* OH_PLAYER_SUBTITLE_UPDATE_INFO_TEXT __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * Playback info key for server ip address.
 * @since 23
 */
extern const char* OH_PLAYER_SERVER_IP_ADDRESS __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * Playback info key for downloading state.
 * @since 23
 */
extern const char* OH_PLAYER_IS_DOWNLOADING __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * Playback info key for buffer duration.
 * @since 23
 */
extern const char* OH_PLAYER_BUFFER_DURATION __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * Playback info key for download rate.
 * @since 23
 */
extern const char* OH_PLAYER_DOWNLOAD_RATE __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * Playback info key for average download rate.
 * @since 23
 */
extern const char* OH_PLAYER_AVG_DOWNLOAD_RATE __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Called when a player message or alarm is received.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player The pointer to an OH_AVPlayer instance.
 * @param type Indicates the information type. For details, see {@link AVPlayerOnInfoType}.
 * @param extra Indicates other information, for example, the start time position of a playing file.
 * @since 11
 * @deprecated since 12
 * @useinstead {@link OH_AVPlayerOnInfoCallback}
 * @version 1.0
 */
typedef void (*OH_AVPlayerOnInfo)(OH_AVPlayer *player, AVPlayerOnInfoType type, int32_t extra);

/**
 * @brief Called when a player info event is received.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player The pointer to an OH_AVPlayer instance.
 * @param type Indicates the information type. For details, see {@link AVPlayerOnInfoType}.
 * @param infoBody Indicates the information parameters, only valid in callback function.
 * @param userData Pointer to user specific data.
 * @since 12
 */
typedef void (*OH_AVPlayerOnInfoCallback)(OH_AVPlayer *player, AVPlayerOnInfoType type, OH_AVFormat* infoBody,
    void *userData);

/**
 * @brief Called when an error occurred for versions above api9
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player The pointer to an OH_AVPlayer instance.
 * @param errorCode Error code.
 * @param errorMsg Error message.
 * @since 11
 * @deprecated since 12
 * @useinstead {@link OH_AVPlayerOnInfoCallback} {@link OH_AVPlayerOnError}
 * @version 1.0
 */
typedef void (*OH_AVPlayerOnError)(OH_AVPlayer *player, int32_t errorCode, const char *errorMsg);

/**
 * @brief Called when an error occurred.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param player The pointer to an OH_AVPlayer instance.
 * @param errorCode Error code.
 * @param errorMsg Error message, only valid in callback function.
 * @param userData Pointer to user specific data.
 * @since 12
 */
typedef void (*OH_AVPlayerOnErrorCallback)(OH_AVPlayer *player, int32_t errorCode, const char *errorMsg,
    void *userData);

/**
 * @brief Called when the maximum audio level values are calculated.
 * @param player Pointer to an OH_AVPlayer instance.
 * @param amplitudes The pointer to the maximum audio level values array.
 *        Note: the amplitudes array will be released after callback automatically.
 *        If necessary, user need copy the data for the further use.
 * @param size The size of the maximum audio level values array.
 * @param userData Pointer to user specific data.
 * @since 23
 */
typedef void (*OH_AVPlayerOnAmplitudeUpdateCallback)(OH_AVPlayer *player, double *amplitudes, uint32_t size,
    void *userData);

/**
 * @brief Describes the handle used to obtain SEI messages. This is used when in subscriptions to SEI message events.
 * and the callback returns detailed SEI information.
 * @param player Pointer to an OH_AVPlayer instance
 * @param message SEI message array. 
 *        Note: the message array will be released after callback automatically.
 *        If necessary, user need copy the data for the further use.
 * @param playbackPosition playback position
 * @param userData Pointer to user specific data
 * @since 23
 */
typedef void (*OH_AVPlayerOnSeiMessageReceivedCallback)(OH_AVPlayer *player, OH_AVSeiMessageArray *message,
    int32_t playbackPosition, void *userData);

/**
 * @brief A collection of all callback function pointers in OH_AVPlayer. Register an instance of this
 * structure to the OH_AVPlayer instance, and process the information reported through the callback to ensure the
 * normal operation of OH_AVPlayer.
 * @syscap SystemCapability.Multimedia.Media.AVPlayer
 * @param onInfo Monitor OH_AVPlayer operation information, refer to {@link OH_AVPlayerOnInfo}
 * @param onError Monitor OH_AVPlayer operation errors, refer to {@link OH_AVPlayerOnError}
 * @since 11
 * @deprecated since 12
 * @useinstead {@link OH_AVPlayerOnInfoCallback} {@link OH_AVPlayerOnErrorCallback}
 * @version 1.0
 */
typedef struct AVPlayerCallback {
    OH_AVPlayerOnInfo onInfo;
    OH_AVPlayerOnError onError;
} AVPlayerCallback;

/**
 * @brief Key to get prepare duration value in statistic metrics info,
 *     value type is uint32_t, in milliseconds.
 * @since 23
 */
extern const char* OH_MEDIA_EVENT_INFO_PREPARE_DURATION __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key to get resource link establishment time in statistic metrics info,
 *     value type is uint32_t, in milliseconds.
 * @since 23
 */
extern const char* OH_MEDIA_EVENT_INFO_RESOURCE_CONNECTION_DURATION
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key to get decapsulation time of the first sample in statistic metrics info,
 *     value type is uint32_t, in milliseconds.
 * @since 23
 */
extern const char* OH_MEDIA_EVENT_INFO_FIRST_FRAME_DECAPSULATION_DURATION
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key to get cumulative playback time in statistic metrics info,
 *     value type is uint32_t, in milliseconds.
 * @since 23
 */
extern const char* OH_MEDIA_EVENT_INFO_TOTAL_PLAYING_TIME __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key to get cumulative times of media resource loading request in statistic metrics info,
 *     value type is uint32_t.
 * @since 23
 */
extern const char* OH_MEDIA_EVENT_INFO_DOWNLOAD_REQUEST_COUNT __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key to get the total time spent loading the media resource in statistic metrics info,
 *     value type is uint32_t, in milliseconds.
 * @since 23
 */
extern const char* OH_MEDIA_EVENT_INFO_DOWNLOAD_TOTAL_TIME __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key to get size of loaded media resources in statistic metrics info,
 *     value type is int64_t.
 * @since 23
 */
extern const char* OH_MEDIA_EVENT_INFO_DOWNLOAD_TOTAL_SIZE __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key to get cumulative stalling count in statistic metrics info,
 *     value type is uint32_t.
 * @since 23
 */
extern const char* OH_MEDIA_EVENT_INFO_STALLING_COUNT __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key to get the cumulative stalling time in statistic metrics info,
 *     value type is uint32_t,in milliseconds.
 * @since 23
 */
extern const char* OH_MEDIA_EVENT_INFO_TOTAL_STALLING_TIME __attribute__((__availability__(ohos, introduced=23.0.0)));

#ifdef __cplusplus
}
#endif
#endif // MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVPLAYER_BASH_H
/** @} */