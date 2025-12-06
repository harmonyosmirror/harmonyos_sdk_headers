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
#include "native_audiostream_base.h"
#include "native_audio_device_base.h"
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
 * @brief Declare the audio session scene.
 *
 * @since 20
 */
typedef enum {
    /**
     * @brief scene for media
     */
    AUDIO_SESSION_SCENE_MEDIA = 0,

    /**
     * @brief scene for game
     */
    AUDIO_SESSION_SCENE_GAME = 1,

    /**
     * @brief scene for voice communication
     */
    AUDIO_SESSION_SCENE_VOICE_COMMUNICATION = 2,
} OH_AudioSession_Scene;

/**
 * @brief Declare the audio session state change hints.
 *
 * @since 20
 */
typedef enum {
    /**
     * @brief Resume the playback
     */
    AUDIO_SESSION_STATE_CHANGE_HINT_RESUME = 0,

    /**
     * @brief paused/pause the playback
     */
    AUDIO_SESSION_STATE_CHANGE_HINT_PAUSE = 1,

    /**
     * @brief stopped/stop the playback.
     */
    AUDIO_SESSION_STATE_CHANGE_HINT_STOP = 2,

    /**
     * @brief stopped/stop the playback due to no audio stream for a long time.
     */
    AUDIO_SESSION_STATE_CHANGE_HINT_TIME_OUT_STOP = 3,

    /**
     * @brief Ducked the playback. (In ducking, the audio volume is reduced, but not silenced.)
     */
    AUDIO_SESSION_STATE_CHANGE_HINT_DUCK = 4,

    /**
     * @brief Unducked the playback.
     */
    AUDIO_SESSION_STATE_CHANGE_HINT_UNDUCK = 5,
} OH_AudioSession_StateChangeHint;

/**
 * @brief Declare the recommend action when device change.
 *
 * @since 20
 */
typedef enum {
    /**
     * @brief Recommend to continue the playback.
     */
    DEVICE_CHANGE_RECOMMEND_TO_CONTINUE = 0,

    /**
     * @brief recommend to stop the playback.
     */
    DEVICE_CHANGE_RECOMMEND_TO_STOP = 1,
} OH_AudioSession_OutputDeviceChangeRecommendedAction;

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
 * @brief Enumerates the categories application prefer to use
 * when recording with bluetooth and nearlink.
 *
 * @since 21
 */
typedef enum {
    /**
     * @brief Not prefer to use bluetooth and nearlink record.
     */
    PREFERRED_NONE = 0,

    /**
     * @brief Prefer to use bluetooth and nearlink record.
     * However, whether to use low latency or high quality recording
     * depends on system.
     */
    PREFERRED_DEFAULT = 1,

    /**
     * @brief Prefer to use bluetooth and nearlink low latency mode to record.
     */
    PREFERRED_LOW_LATENCY = 2,

    /**
     * @brief Prefer to use bluetooth and nearlink high quality mode to record.
     */
    PREFERRED_HIGH_QUALITY = 3,
} OH_AudioSession_BluetoothAndNearlinkPreferredRecordCategory;

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
 * @brief declare the audio session state change event
 *
 * @since 20
 */
typedef struct OH_AudioSession_StateChangedEvent {
    /**
     * @brief audio session state change hints.
     */
    OH_AudioSession_StateChangeHint stateChangeHint;
} OH_AudioSession_StateChangedEvent;

/**
 * @brief This function pointer will point to the callback function that
 * is used to return the audio session state change event.
 *
 * @param event the {@link #OH_AudioSession_StateChangedEvent} state change triggering event.
 * @since 20
 */
typedef void (*OH_AudioSession_StateChangedCallback) (
    OH_AudioSession_StateChangedEvent event);

/**
 * @brief This function pointer will point to the callback function that
 *     is used to return the changing audio device descriptors.
 *     There may be more than one audio device descriptor returned.
 *
 * @param type the {@link OH_AudioDevice_ChangeType} is connect or disconnect.
 * @param audioDeviceDescriptorArray the {@link OH_AudioDeviceDescriptorArray}
 *     pointer variable which will be set the audio device descriptors value.
 *     Do not release the audioDeviceDescriptorArray pointer separately
 *     instead call {@link OH_AudioSessionManager_ReleaseDevices} to release the DeviceDescriptor array
 *     when it is no use anymore.
 * @since 21
 */
typedef void (*OH_AudioSession_AvailableDeviceChangedCallback) (
    OH_AudioDevice_ChangeType type,
    OH_AudioDeviceDescriptorArray *audioDeviceDescriptorArray);

/**
 * @brief This function pointer will point to the callback function that
 *     is used to return the audio session input device change event.
 *
 * @param audioDeviceDescriptorArray the {@link OH_AudioDeviceDescriptorArray}
 *     pointer variable which will be set the audio input device descriptors value.
 *     Do not release the audioDeviceDescriptorArray pointer separately
 *     instead call {@link OH_AudioSessionManager_ReleaseDevices}
 *     to release the DeviceDescriptor array when it is no use anymore.
 * @param changeReason the {@link #OH_AudioStream_DeviceChangeReason} indicates
 *     that why does the input device changes.
 * @since 21
 */
typedef void (*OH_AudioSession_CurrentInputDeviceChangedCallback) (
    OH_AudioDeviceDescriptorArray *devices,
    OH_AudioStream_DeviceChangeReason changeReason);

/**
 * @brief This function pointer will point to the callback function that
 * is used to return the audio session device change event.
 *
 * @param audioDeviceDescriptorArray the {@link OH_AudioDeviceDescriptorArray}
 * pointer variable which will be set the audio device descriptors value.
 * Do not release the audioDeviceDescriptorArray pointer separately
 * instead call {@link OH_AudioSessionManager_ReleaseDevices}
 * to release the DeviceDescriptor array when it is no use anymore.
 * @param changeReason the {@link #OH_AudioStream_DeviceChangeReason} indicates that why does the device changes.
 * @param recommendedAction the {@link #OH_AudioSession_OutputDeviceChangeRecommendedAction}
 * recommend action when device change.
 * @since 20
 */
typedef void (*OH_AudioSession_CurrentOutputDeviceChangedCallback) (
    OH_AudioDeviceDescriptorArray *devices,
    OH_AudioStream_DeviceChangeReason changeReason,
    OH_AudioSession_OutputDeviceChangeRecommendedAction recommendedAction);

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
 * If {@link #OH_AudioSessionManager_SetScene} is called, it will take focus when calling this method.
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

/**
 * @brief Set scene for audio session.
 *
 * @param audioSessionManager the {@link #OH_AudioSessionManager}
 * returned by the {@link #OH_AudioManager_GetAudioSessionManager}
 * @param scene the {@link #OH_AudioSession_Scene}
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 * or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails
 * or {@link #AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE} if system illegal state
 * or {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} if system state error
 * @since 20
 */
OH_AudioCommon_Result OH_AudioSessionManager_SetScene(
    OH_AudioSessionManager *audioSessionManager, OH_AudioSession_Scene scene);

/**
 * @brief Register the audio session state change event callback.
 *
 * @param audioSessionManager the {@link #OH_AudioSessionManager}
 * returned by the {@link #OH_AudioManager_GetAudioSessionManager}
 * @param callback the {@link #OH_AudioSession_StateChangedCallback} which is used
 * to receive the state change event
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 * or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails
 * or {@link AUDIOCOMMON_RESULT_ERROR_NO_MEMORY} No memory error
 * or {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} if system state error
 * @since 20
 */
OH_AudioCommon_Result OH_AudioSessionManager_RegisterStateChangeCallback(
    OH_AudioSessionManager *audioSessionManager, OH_AudioSession_StateChangedCallback callback);

/**
 * @brief Unregister the audio session state change event callback.
 *
 * @param audioSessionManager the {@link #OH_AudioSessionManager}
 * returned by the {@link #OH_AudioManager_GetAudioSessionManager}
 * @param callback the {@link #OH_AudioSession_StateChangedCallback} which is used
 * to receive the state change event
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 * or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails
 * or {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} if system state error
 * @since 20
 */
OH_AudioCommon_Result OH_AudioSessionManager_UnregisterStateChangeCallback(
    OH_AudioSessionManager *audioSessionManager, OH_AudioSession_StateChangedCallback callback);

/**
 * @brief Sets the default output device.
 * This function applys on audiorenderers whose StreamUsage are
 * STREAM_USAGE_VOICE_COMMUNICATION/STREAM_USAGE_VIDEO_COMMUNICATION/STREAM_USAGE_VOICE_MESSAGE.
 * Setting the device will only takes effect if no other accessory such as headphones are in use
 * @param audioSessionManager the {@link #OH_AudioSessionManager}
 * returned by the {@link #OH_AudioManager_GetAudioSessionManager}
 * @param deviceType The target device. The available deviceTypes are:
 *                                          EARPIECE: Built-in earpiece
 *                                          SPEAKER: Built-in speaker
 *                                          DEFAULT: System default output device
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 * or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails
 * or {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} if system state error
 * @since 20
 */
OH_AudioCommon_Result OH_AudioSessionManager_SetDefaultOutputDevice(
    OH_AudioSessionManager *audioSessionManager, OH_AudioDevice_Type deviceType);

/**
 * @brief Gets the default output device.
 *
 * @param audioSessionManager the {@link #OH_AudioSessionManager}
 * returned by the {@link #OH_AudioManager_GetAudioSessionManager}
 * @param deviceType The target device.The available deviceTypes are:
 *                                          EARPIECE: Built-in earpiece
 *                                          SPEAKER: Built-in speaker
 *                                          DEFAULT: System default output device
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 * or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails
 * or {@link #AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE} if system illegal state
 * @since 20
 */
OH_AudioCommon_Result OH_AudioSessionManager_GetDefaultOutputDevice(
    OH_AudioSessionManager *audioSessionManager, OH_AudioDevice_Type *deviceType);

/**
 * @brief Release the audio device descriptor array object.
 *
 * @param audioSessionManager the {@link OH_AudioSessionManager}
 * returned by the {@link #OH_AudioManager_GetAudioSessionManager}
 * @param audioDeviceDescriptorArray Audio device descriptors should be released.
 * @return {@link AUDIOCOMMON_RESULT_SUCCESS} If the execution is successful.
 * or {@link AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails
 *              1.The param of audioSessionManager is nullptr;
 *              2.The param of audioDeviceDescriptorArray is nullptr.
 * @since 20
 */
OH_AudioCommon_Result OH_AudioSessionManager_ReleaseDevices(
    OH_AudioSessionManager *audioSessionManager,
    OH_AudioDeviceDescriptorArray *audioDeviceDescriptorArray);

/**
 * @brief Register the audio session device change event callback.
 *
 * @param audioSessionManager the {@link #OH_AudioSessionManager}
 * returned by the {@link #OH_AudioManager_GetAudioSessionManager}
 * @param callback the {@link #OH_AudioSession_CurrentOutputDeviceChangedCallback} which is used
 * to receive the device change event
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 * or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails
 * or {@link AUDIOCOMMON_RESULT_ERROR_NO_MEMORY} No memory error
 * or {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} if system state error
 * @since 20
 */
OH_AudioCommon_Result OH_AudioSessionManager_RegisterCurrentOutputDeviceChangeCallback(
    OH_AudioSessionManager *audioSessionManager,
    OH_AudioSession_CurrentOutputDeviceChangedCallback callback);

/**
 * @brief Unregister the audio session device change event callback.
 *
 * @param audioSessionManager the {@link #OH_AudioSessionManager}
 * returned by the {@link #OH_AudioManager_GetAudioSessionManager}
 * @param callback the {@link #OH_AudioSession_CurrentOutputDeviceChangedCallback} which is used
 * to receive the device change event
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 * or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails
 * or {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} if system state error
 * @since 20
 */
OH_AudioCommon_Result OH_AudioSessionManager_UnregisterCurrentOutputDeviceChangeCallback(
    OH_AudioSessionManager *audioSessionManager,
    OH_AudioSession_CurrentOutputDeviceChangedCallback callback);

/**
 * @brief Get available devices by device usage.
 *
 * @param audioSessionManager the {@link OH_AudioSessionManager} handle returned
 *     by {@link OH_AudioManager_GetAudioSessionManager}.
 * @param deviceUsage the {@link OH_AudioDevice_Usage} which is used as
 *     the filter parameter for get the available devices.
 * @param audioDeviceDescriptorArray the {@link OH_AudioDeviceDescriptorArray}
 *     pointer variable which will be set the audio device descriptors value
 *     Do not release the audioDeviceDescriptorArray pointer separately
 *     instead call {@link OH_AudioSessionManager_ReleaseDevices} to release the DeviceDescriptor array
 *     when it is no use anymore.
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} Audio client call audio service error, System error.
 * @since 21
 */
OH_AudioCommon_Result OH_AudioSessionManager_GetAvailableDevices(
    OH_AudioSessionManager *audioSessionManager,
    OH_AudioDevice_Usage deviceUsage, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray);

/**
 * @brief Register available device change event callback.
 *
 * @param audioSessionManager the {@link #OH_AudioSessionManager}
 *     returned by the {@link #OH_AudioManager_GetAudioSessionManager}
 * @param deviceUsage the {@link OH_AudioDevice_Usage} which is used as
 *     the filter parameter for register the available devices change event.
 * @param callback the {@link #OH_AudioSession_AvailableDeviceChangedCallback} which is used
 *     to receive available device change event.
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} Audio client call audio service error, System error.
 * @since 21
 */
OH_AudioCommon_Result OH_AudioSessionManager_RegisterAvailableDevicesChangeCallback(
    OH_AudioSessionManager *audioSessionManager, OH_AudioDevice_Usage deviceUsage,
    OH_AudioSession_AvailableDeviceChangedCallback callback);

/**
 * @brief Unregister available device change event callback.
 *
 * @param audioSessionManager the {@link #OH_AudioSessionManager}
 *     returned by the {@link #OH_AudioManager_GetAudioSessionManager}.
 * @param callback the {@link #OH_AudioSession_AvailableDeviceChangedCallback} which is used
 *     to receive the device change event.
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} Audio client call audio service error, System error.
 * @since 21
 */
OH_AudioCommon_Result OH_AudioSessionManager_UnregisterAvailableDevicesChangeCallback(
    OH_AudioSessionManager *audioSessionManager,
    OH_AudioSession_AvailableDeviceChangedCallback callback);

/**
 * @brief Sets the media input device.
 *     This function is not valid for call recording, whose SourceType is
 *     SOURCE_TYPE_VOICE_CALL or SOURCE_TYPE_VOICE_COMMUNICATION.
 *     In scenarios where there are concurrent recording streams with higher priority,
 *     the actual input device used by the application may differ from the selected one.
 *     The application can use {@link OH_AudioSessionManager_RegisterCurrentInputDeviceChangeCallback}
 *     to register a callback to listen for the actual input device.
 *
 * @param audioSessionManager the {@link OH_AudioSessionManager} handle returned
 *     by {@link OH_AudioManager_GetAudioSessionManager}.
 * @param deviceDescriptor The target device. The available device must be in the array returned
 *     by {@link OH_AudioSessionManager_GetAvailableDevices}.
 *     When the nullptr is passed, system will clear the last selection.
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} Audio client call audio service error, System error.
 * @since 21
 */
OH_AudioCommon_Result OH_AudioSessionManager_SelectMediaInputDevice(
    OH_AudioSessionManager *audioSessionManager, OH_AudioDeviceDescriptor *deviceDescriptor);

/**
 * @brief Gets the selected media input device.
 *
 * @param audioSessionManager the {@link #OH_AudioSessionManager}
 *     returned by the {@link #OH_AudioManager_GetAudioSessionManager}.
 * @param audioDeviceDescriptor The target device set by
 *     {@link OH_AudioSessionManager_SelectMediaInputDevice} or
 *     device with AUDIO_DEVICE_TYPE_INVALID if not set yet.
 *     Do not release the audioDeviceDescriptor pointer separately,
 *     instead call {@link OH_AudioSessionManager_ReleaseDevice} to release it
 *     when it is no use anymore.
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} Audio client call audio service error, System error.
 * @since 21
 */
OH_AudioCommon_Result OH_AudioSessionManager_GetSelectedMediaInputDevice(
    OH_AudioSessionManager *audioSessionManager, OH_AudioDeviceDescriptor **audioDeviceDescriptor);

/**
 * @brief Sets the prefered record category with bluetooth and nearlink device.
 *     The application can set this category before bluetooth and nearlink connected, and the system will
 *     prefer to use bluetooth and nearlink to record when the device connected.
 *     In scenarios where there are concurrent recording streams with higher priority,
 *     the actual input device used by the application may differ from the prefered one.
 *     The application can use {@link OH_AudioSessionManager_RegisterCurrentInputDeviceChangeCallback}
 *     to register a callback to listen for the actual input device.
 *
 * @param audioSessionManager the {@link OH_AudioSessionManager} handle returned
 *     by {@link OH_AudioManager_GetAudioSessionManager}.
 * @param category The category application prefer to use when recording with bluetooth and nearlink.
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} Audio client call audio service error, System error.
 * @since 21
 */
OH_AudioCommon_Result OH_AudioSessionManager_SetBluetoothAndNearlinkPreferredRecordCategory(
    OH_AudioSessionManager *audioSessionManager,
    OH_AudioSession_BluetoothAndNearlinkPreferredRecordCategory category);

/**
 * @brief Gets the prefered record category with bluetooth and nearlink device.
 *
 * @param audioSessionManager the {@link OH_AudioSessionManager} handle returned
 *     by {@link OH_AudioManager_GetAudioSessionManager}.
 * @param category The category application prefer to use when recording with bluetooth and nearlink.
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} Audio client call audio service error, System error.
 * @since 21
 */
OH_AudioCommon_Result OH_AudioSessionManager_GetBluetoothAndNearlinkPreferredRecordCategory(
    OH_AudioSessionManager *audioSessionManager,
    OH_AudioSession_BluetoothAndNearlinkPreferredRecordCategory *category);

/**
 * @brief Register the audio session input device change event callback.
 *
 * @param audioSessionManager the {@link #OH_AudioSessionManager}
 *     returned by the {@link #OH_AudioManager_GetAudioSessionManager}.
 * @param callback the {@link #OH_AudioSession_CurrentInputDeviceChangedCallback} which is used
 *     to receive the input device change event.
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails.
 *     or {@link AUDIOCOMMON_RESULT_ERROR_NO_MEMORY} No memory error.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} Audio client call audio service error, System error.
 * @since 21
 */
OH_AudioCommon_Result OH_AudioSessionManager_RegisterCurrentInputDeviceChangeCallback(
    OH_AudioSessionManager *audioSessionManager,
    OH_AudioSession_CurrentInputDeviceChangedCallback callback);

/**
 * @brief Unregister the audio session input device change event callback.
 *
 * @param audioSessionManager the {@link #OH_AudioSessionManager}
 *     returned by the {@link #OH_AudioManager_GetAudioSessionManager}.
 * @param callback the {@link #OH_AudioSession_CurrentInputDeviceChangedCallback} which is used
 *     to receive the input device change event.
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} Audio client call audio service error, System error.
 * @since 21
 */
OH_AudioCommon_Result OH_AudioSessionManager_UnregisterCurrentInputDeviceChangeCallback(
    OH_AudioSessionManager *audioSessionManager,
    OH_AudioSession_CurrentInputDeviceChangedCallback callback);

/**
 * @brief Release the audio device descriptor object.
 *
 * @param audioSessionManager the {@link OH_AudioSessionManager}
 *     returned by the {@link #OH_AudioManager_GetAudioSessionManager}
 * @param audioDeviceDescriptor Audio device descriptor to release.
 * @return {@link AUDIOCOMMON_RESULT_SUCCESS} If the execution is successful.
 *     or {@link AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails
 * @since 21
 */
OH_AudioCommon_Result OH_AudioSessionManager_ReleaseDevice(
    OH_AudioSessionManager *audioSessionManager,
    OH_AudioDeviceDescriptor *audioDeviceDescriptor);

#ifdef __cplusplus
}
#endif

#endif // NATIVE_AUDIO_SESSION_MANAGER_H
/** @} */