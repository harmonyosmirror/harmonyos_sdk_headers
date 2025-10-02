/*
 * Copyright (c) 2025 Huawei Device Co., Ltd.
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
 * @since 20
 */

/**
 * @file native_audio_volume_manager.h
 *
 * @brief Declare audio volume manager related interfaces.
 *
 * This file interfaces are used for the creation of AudioVolumeManager.
 *
 * @library libohaudio.so
 * @syscap SystemCapability.Multimedia.Audio.Core
 * @kit AudioKit
 * @since 20
 */

#ifndef NATIVE_AUDIO_VOLUME_MANAGER_H
#define NATIVE_AUDIO_VOLUME_MANAGER_H

#include "native_audio_common.h"
#include "native_audiostream_base.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Declare the audio volume manager.
 *     Audio volume manager provides many functions for developer to get the information about system volume.
 *
 * @since 20
 */
typedef struct OH_AudioVolumeManager OH_AudioVolumeManager;

/**
 * @brief Prototype for the volume change function that is passed to
 *     {@link OH_AudioVolumeManager_RegisterStreamVolumeChangeCallback}.
 *
 * @param userData userdata which is passed by register.
 * @param usage the stream usage type for which volume changed.
 * @param volumeLevel the latest volume level.
 * @param updateUi whether to show the volume change in UI.
 *
 * @since 20
 */
typedef void (*OH_AudioVolumeManager_OnStreamVolumeChangeCallback)(
    void *userData,
    OH_AudioStream_Usage usage,
    int32_t volumeLevel,
    bool updateUi
);

/**
 * @brief Prototype for the volume change function that is passed to
 *     {@link OH_AudioVolumeManager_RegisterStreamVolumeChangeCallback}.
 *
 * @param userData userdata which is passed by register.
 * @param ringerMode the latest ringer mode.
 *
 * @since 20
 */
typedef void (*OH_AudioVolumeManager_OnRingerModeChangeCallback)(
    void *userData,
    OH_AudioRingerMode ringerMode
);

/**
 * @brief Fetch the audio volume manager handle, which is a singleton.
 *
 * @param volumeManager output parameter to get {@link OH_AudioVolumeManager} instance.
 * @return
 *     {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 *     {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if input param is nullptr
 *
 * @since 20
 */
OH_AudioCommon_Result OH_AudioManager_GetAudioVolumeManager(
    OH_AudioVolumeManager **volumeManager);

/**
 * @brief Obtains the maximum volume level for a specific stream usage type.
 *
 * @param volumeManager {@link OH_AudioVolumeManager} handle
 *     provided by {@link OH_AudioManager_GetAudioVolumeManager}.
 * @param usage the stream usage type used to map a specific volume type.
 * @param maxVolumeLevel output parameter to get maximum volume level.
 * @return
 *     {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 *     {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if input param is nullptr or invalid
 *     {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} system process error occurs
 *
 * @since 20
 */
OH_AudioCommon_Result OH_AudioVolumeManager_GetMaxVolumeByUsage(OH_AudioVolumeManager *volumeManager,
    OH_AudioStream_Usage usage, int32_t *maxVolumeLevel);

/**
 * @brief Obtains the minimum volume level for a specific stream usage type.
 *
 * @param volumeManager {@link OH_AudioVolumeManager} handle
 *     provided by {@link OH_AudioManager_GetAudioVolumeManager}.
 * @param usage the stream usage type used to map a specific volume type.
 * @param minVolumeLevel output parameter to get minimum volume level.
 * @return
 *     {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 *     {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if input param is nullptr or invalid
 *     {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} system process error occurs
 *
 * @since 20
 */
OH_AudioCommon_Result OH_AudioVolumeManager_GetMinVolumeByUsage(OH_AudioVolumeManager *volumeManager,
    OH_AudioStream_Usage usage, int32_t *minVolumeLevel);

/**
 * @brief Obtains the system volume level for a specific stream usage type.
 *
 * @param volumeManager {@link OH_AudioVolumeManager} handle
 *     provided by {@link OH_AudioManager_GetAudioVolumeManager}.
 * @param usage the stream usage type used to map a specific volume type.
 * @param volumeLevel output parameter to get system volume level.
 * @return
 *     {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 *     {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if input param is nullptr or invalid
 *     {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} system process error occurs
 *
 * @since 20
 */
OH_AudioCommon_Result OH_AudioVolumeManager_GetVolumeByUsage(OH_AudioVolumeManager *volumeManager,
    OH_AudioStream_Usage usage, int32_t *volumeLevel);

/**
 * @brief Checks whether a stream is muted for a specific stream usage type.
 *
 * @param volumeManager {@link OH_AudioVolumeManager} handle
 *     provided by {@link OH_AudioManager_GetAudioVolumeManager}.
 * @param usage the stream usage type used to map a specific volume type.
 * @param muted output parameter to get whether the stream of this usage is muted.
 * @return
 *     {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 *     {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if input param is nullptr or invalid
 *     {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} system process error occurs
 *
 * @since 20
 */
OH_AudioCommon_Result OH_AudioVolumeManager_IsMuteByUsage(OH_AudioVolumeManager *volumeManager,
    OH_AudioStream_Usage usage, bool *muted);

/**
 * @brief Register callback to receive stream volume changed events.
 *
 * @param volumeManager {@link OH_AudioVolumeManager} handle
 *     provided by {@link OH_AudioManager_GetAudioVolumeManager}.
 * @param usage the stream usage type used to map a specific volume type which caller want to listen.
 * @param callback callback function which will be called when stream volume changed.
 * @param userData pointer to a data structure that will be passed to the callback functions.
 * @return
 *     {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 *     {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if input param is nullptr or invalid
 *     {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} system process error occurs
 *
 * @since 20
 */
OH_AudioCommon_Result OH_AudioVolumeManager_RegisterStreamVolumeChangeCallback(
    OH_AudioVolumeManager *volumeManager, OH_AudioStream_Usage usage,
    OH_AudioVolumeManager_OnStreamVolumeChangeCallback callback, void *userData);

/**
 * @brief Unregister stream volume change callback.
 *
 * @param volumeManager {@link OH_AudioVolumeManager} handle
 *     provided by {@link OH_AudioManager_GetAudioVolumeManager}.
 * @param callback callback function which registered in
 *     {@link OH_AudioVolumeManager_RegisterStreamVolumeChangeCallback}.
 * @return
 *     {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 *     {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if input param is nullptr
 *     {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} system process error occurs
 *
 * @since 20
 */
OH_AudioCommon_Result OH_AudioVolumeManager_UnregisterStreamVolumeChangeCallback(
    OH_AudioVolumeManager *volumeManager,
    OH_AudioVolumeManager_OnStreamVolumeChangeCallback callback);

/**
 * @brief Get current ringer mode.
 *
 * @param volumeManager {@link OH_AudioVolumeManager} handle
 *     provided by {@link OH_AudioManager_GetAudioVolumeManager}.
 * @param ringerMode output parameter to get the ringer mode.
 * @return
 *     {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 *     {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if input param is nullptr
 *     {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} system process error occurs
 *
 * @since 20
 */
OH_AudioCommon_Result OH_AudioVolumeManager_GetRingerMode(OH_AudioVolumeManager *volumeManager,
    OH_AudioRingerMode *ringerMode);

/**
 * @brief Register callback to receive ringer mode changed events.
 *
 * @param volumeManager {@link OH_AudioVolumeManager} handle
 *     provided by {@link OH_AudioManager_GetAudioVolumeManager}.
 * @param callback callback function which will be called when ringer mode changed.
 * @param userData pointer to a data structure that will be passed to the callback functions.
 * @return
 *     {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 *     {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if input param is nullptr
 *     {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} system process error occurs
 *
 * @since 20
 */
OH_AudioCommon_Result OH_AudioVolumeManager_RegisterRingerModeChangeCallback(
    OH_AudioVolumeManager *volumeManager,
    OH_AudioVolumeManager_OnRingerModeChangeCallback callback, void *userData);

/**
 * @brief Unregister ringer mode change callback.
 *
 * @param volumeManager {@link OH_AudioVolumeManager} handle
 *     provided by {@link OH_AudioManager_GetAudioVolumeManager}.
 * @param callback callback function which registered in
 *     {@link OH_AudioVolumeManager_RegisterRingerModeChangeCallback}.
 * @return
 *     {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 *     {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if input param is nullptr
 *     {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} system process error occurs
 *
 * @since 20
 */
OH_AudioCommon_Result OH_AudioVolumeManager_UnregisterRingerModeChangeCallback(
    OH_AudioVolumeManager *volumeManager,
    OH_AudioVolumeManager_OnRingerModeChangeCallback callback);

#ifdef __cplusplus
}
#endif

#endif // NATIVE_AUDIO_ROUTING_MANAGER_H
/** @} */