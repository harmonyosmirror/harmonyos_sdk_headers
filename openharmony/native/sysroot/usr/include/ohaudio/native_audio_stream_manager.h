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
 * @since 19
 */

/**
 * @file native_audio_stream_manager.h
 *
 * @brief Declare audio stream manager related interfaces.
 *
 * This file interface is used for the creation of audioStreamManager
 * as well as the audio stream settings and management.
 *
 * @library libohaudio.so
 * @syscap SystemCapability.Multimedia.Audio.Core
 * @kit AudioKit
 * @since 19
 */

#ifndef NATIVE_AUDIO_STREAM_MANAGER_H
#define NATIVE_AUDIO_STREAM_MANAGER_H

#include "native_audio_common.h"
#include "native_audiostream_base.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Declare the audio stream manager.
 * Audio stream manager provides many functions about audio streams, like monitoring audio streams status,
 * getting different stream types supported information and so on.
 *
 * @since 19
 */
typedef struct OH_AudioStreamManager OH_AudioStreamManager;

/**
 * @brief Fetch the audio streammanager handle, which is a singleton.
 *
 * @param streamManager output parameter to get the {@link #OH_AudioStreamManager}.
 * @return
 *         {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 *         {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} if system state error
 * @since 19
 */
OH_AudioCommon_Result OH_AudioManager_GetAudioStreamManager(OH_AudioStreamManager **streamManager);

/**
 * @brief Gets the mode of direct playback available for a given audio format with current active device.
 *
 * @param audioStreamManager the {@link OH_AudioStreamManager} handle provided by
 * {@link OH_AudioManager_GetAudioStreamManager}.
 * @param streamInfo the {@link OH_AudioStreamInfo}.
 * @param usage the {@link OH_AudioStream_Usage}.
 * @param directPlaybackMode the {@link OH_AudioStream_DirectPlaybackMode} pointer to a variable which receives the
 * result.
 * @return Function result code:
 *         {@link AUDIOCOMMON_RESULT_SUCCESS} If the execution is successful.
 *         {@link AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM}:
 *                                                        1.The param of audioStreamManager is nullptr;
 *                                                        2.The param of streamInfo is nullptr;
 *                                                        3.The param of usage invalid;
 *                                                        4.The param of directPlaybackMode is nullptr.
 * @since 19
 */
OH_AudioCommon_Result OH_AudioStreamManager_GetDirectPlaybackSupport(
    OH_AudioStreamManager *audioStreamManager, OH_AudioStreamInfo *streamInfo,
    OH_AudioStream_Usage usage, OH_AudioStream_DirectPlaybackMode *directPlaybackMode);

#ifdef __cplusplus
}
#endif

#endif // NATIVE_AUDIO_STREAM_MANAGER_H
/** @} */
