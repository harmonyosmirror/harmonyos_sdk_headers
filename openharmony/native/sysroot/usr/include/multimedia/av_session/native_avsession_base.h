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
 * @brief Provide the defination of the C interface for the avsession module.
 *
 * @since 23
 * @version 1.0
 */

/**
 * @file native_avsession_base.h
 *
 * @brief Declare avsession base info.
 *
 * @library libohavsession.so
 * @syscap SystemCapability.Multimedia.AVSession.Core
 * @kit AVSessionKit
 * @since 23
 * @version 1.0
 */

#ifndef NATIVE_AVSESSION_BASE_H
#define NATIVE_AVSESSION_BASE_H

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
    SESSION_TYPE_VIDEO_CALL = 3,

    /**
     * @brief photo session type.
     */
    SESSION_TYPE_PHOTO = 4
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
 * @brief Defines the skip interval when fastforward or rewind.
 *
 * @since 13
 * @version 1.0
 */
typedef enum {
    /**
     * @brief 10 seconds
     */
    SECONDS_10 = 10,

    /**
     * @brief 15 seconds
     */
    SECONDS_15 = 15,

    /**
     * @brief 30 seconds
     */
    SECONDS_30 = 30,
} AVMetadata_SkipIntervals;

/**
 * @brief Display tag
 *
 * @since 13
 * @version 1.0
 */
typedef enum {
    /**
     * @brief Indicate the audio vivid property.
     */
    AVSESSION_DISPLAYTAG_AUDIO_VIVID = 1,
} AVMetadata_DisplayTag;

/**
 * @brief Enum for device connection state.
 *
 * @since 23
 * @version 1.0
 */
typedef enum AVSession_ConnectionState {
    /**
     * @brief A connection state indicating the device is in the process of connecting.
     * @since 23
     */
    STATE_CONNECTING = 0,

    /**
     * @brief A connection state indicating the device is connected.
     * @since 23
     */
    STATE_CONNECTED = 1,

    /**
     * @brief The default connection state indicating the device is disconnected.
     * @since 23
     */
    STATE_DISCONNECTED = 6,
} AVSession_ConnectionState;

/**
 * @brief Enum for cast category indicating different playback scenes.
 *
 * @since 23
 * @version 1.0
 */
typedef enum AVSession_AVCastCategory {
    /**
     * @brief The default cast type "local", media can be routed on the same device,
     * including internal speakers or audio jack on the device itself, A2DP devices.
     */
    CATEGORY_LOCAL = 0,

    /**
     * @brief The remote category indicating the media is presenting on a remote device,
     * the application needs to get an AVCastController to control remote playback.
     */
    CATEGORY_REMOTE = 1,
} AVSession_AVCastCategory;

/**
 * @brief Enum for Device type .
 *
 * @since 23
 * @version 1.0
 */
typedef enum AVSession_DeviceType {
    /**
     * @brief A device type indicating the route is on internal speakers or audio jack on the device itself.
     * @since 23
     */
    DEVICE_TYPE_LOCAL = 0,

    /**
     * @brief A device type indicating the route is on a TV.
     * @since 23
     */
    DEVICE_TYPE_TV = 2,

    /**
     * @brief A device type indicating the route is on a smart speaker.
     * @since 23
     */
    DEVICE_TYPE_SMART_SPEAKER = 3,

    /**
     * @brief A device type indicating the route is on a bluetooth device.
     * @since 23
     */
    DEVICE_TYPE_BLUETOOTH = 10,
} AVSession_DeviceType;

/**
 * @brief Enum for Protocol type .
 *
 * @since 23
 * @version 1.0
 */
typedef enum AVSession_ProtocolType {
    /**
     * @brief The default cast type "local", media can be routed on the same device,
     * including internal speakers or audio jack on the device itself, A2DP devices.
     * @since 23
     */
    TYPE_LOCAL = 0,

    /**
     * @brief The Cast+ Stream indicating the media is presenting on a different device
     * the application need get an AVCastController to control remote playback.
     * @since 23
     */
    TYPE_CAST_PLUS_STREAM = 2,

    /**
     * @brief The DLNA type indicates the device supports DLNA protocol,
	 * the application needs to get an AVCastController to control remote playback.
     * @since 23
     */
    TYPE_DLNA = 4,

    /**
     * @brief This type indicates the device supports audio casting with high defination to get a better sound quality.
     * @since 23
     */
    TYPE_CAST_PLUS_AUDIO = 8,
} AVSession_ProtocolType;

/**
 * @brief Enum for command type.
 *
 * @since 23
 * @version 1.0
 */
typedef enum AVSession_AVCastControlCommandType {
    /**
     * @brief Play Command
     * @since 23
     */
    CAST_CONTROL_CMD_PLAY = 0,
    /**
     * @brief Pause Command
     * @since 23
     */
    CAST_CONTROL_CMD_PAUSE = 1,
    /**
     * @brief Stop Command
     * @since 23
     */
    CAST_CONTROL_CMD_STOP = 2,
    /**
     * @brief Play next Command
     * @since 23
     */
    CAST_CONTROL_CMD_PLAY_NEXT = 3,
    /**
     * @brief Play previous Command
     * @since 23
     */
    CAST_CONTROL_CMD_PLAY_PREVIOUS = 4,
    /**
     * @brief Fast forward Command
     * @since 23
     */
    CAST_CONTROL_CMD_FAST_FORWARD = 5,
    /**
     * @brief Rewind Command
     * @since 23
     */
    CAST_CONTROL_CMD_REWIND = 6,
    /**
     * @brief Seek Command
     * @since 23
     */
    CAST_CONTROL_CMD_SEEK = 7,
    /**
     * @brief Set volume Command
     * @since 23
     */
    CAST_CONTROL_CMD_SET_VOLUME = 8,
    /**
     * @brief Set speed Command
     * @since 23
     */
    CAST_CONTROL_CMD_SET_SPEED = 9
} AVSession_AVCastControlCommandType;

/**
 * @brief Enum for playback speed type.
 *
 * @since 23
 * @version 1.0
 */
typedef enum AVSession_PlaybackSpeed {
    /**
     * @brief Video playback at 0.75x normal speed.
     * @since 23
     */
    SPEED_FORWARD_0_75_X = 0,
    /**
     * @brief Video playback at 1.00x normal speed.
     * @since 23
     */
    SPEED_FORWARD_1_00_X = 1,

    /**
     * @brief Video playback at 1.25x normal speed.
     * @since 23
     */
    SPEED_FORWARD_1_25_X = 2,

    /**
     * @brief Video playback at 1.75x normal speed.
     * @since 23
     */
    SPEED_FORWARD_1_75_X = 3,

    /**
     * @brief Video playback at 2.00x normal speed.
     * @since 23
     */
    SPEED_FORWARD_2_00_X = 4,

    /**
     * @brief Video playback at 0.50x normal speed.
     * @since 23
     */
    SPEED_FORWARD_0_50_X = 5,
    
    /**
     * @brief Video playback at 1.50x normal speed.
     * @since 23
     */
    SPEED_FORWARD_1_50_X = 6,
} AVSession_PlaybackSpeed;

/**
 * @brief Enum for playbackstate filter.
 *
 * @since 23
 * @version 1.0
 */
typedef enum AVSession_PlaybackFilter {
    /**
     * @brief filter state
     * @since 23
     */
    FILTER_STATE = 1 << 0,
    /**
     * @brief filter position
     * @since 23
     */
    FILTER_POSITION = 1 << 1,
    /**
     * @brief filter Speed
     * @since 23
     */
    FILTER_SPEED = 1 << 2,
    /**
     * @brief filter volume
     * @since 23
     */
    FILTER_VOLUME = 1 << 3
} AVSession_PlaybackFilter;

#ifdef __cplusplus
}
#endif

#endif // NATIVE_AVSESSION_BASE_H
/** @} */