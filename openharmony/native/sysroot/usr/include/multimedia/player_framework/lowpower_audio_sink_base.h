/*
 * Copyright (c) 2025 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License"),
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
 * @addtogroup LowPowerAudioSink
 * @{
 *
 * @brief The LowPowerAudioSink sub module provides variables, properties,
 * and functions for lowpower audio sink.
 *
 * @since 20
 */

/**
 * @file lowpower_audio_sink_base.h
 *
 * @brief Declare the Native API used for lowpower audio sink.
 *
 * @library liblowpower_avsink.so
 * @kit MediaKit
 * @syscap SystemCapability.Multimedia.Media.LowPowerAVSink
 * @since 20
 */

#ifndef NATIVE_LOWPOWER_AUDIO_SINK_BASE_H
#define NATIVE_LOWPOWER_AUDIO_SINK_BASE_H

#include <stdint.h>
#include "lowpower_avsink_base.h"
#include "ohaudio/native_audiostream_base.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Forward declaration of OH_LowPowerAudioSink.
 *
 * @since 20
 */
typedef struct OH_LowPowerAudioSink OH_LowPowerAudioSink;

/**
 * @brief Forward declaration of OH_LowPowerAudioSinkCallback.
 *
 * @since 20
 */
typedef struct OH_LowPowerAudioSinkCallback OH_LowPowerAudioSinkCallback;

/**
 * @brief When an error occurs in the running of the OH_LowPowerAudioSink instance, the function pointer will be called
 * to report specific error information.
 *
 * @param {OH_LowPowerAudioSink*} sink OH_LowPowerAudioSink instance
 * @param {OH_AVErrCode} errorCode Error code when an error occurs
 * @param {const char*} errorMsg Error description information
 * @param {void*} userData User specific data
 * @since 20
 */
typedef void (*OH_LowPowerAudioSink_OnError)(
    OH_LowPowerAudioSink* sink,
    OH_AVErrCode errCode,
    const char* errorMsg,
    void* userData);

/**
 * @brief When the OH_LowPowerAudioSink instance report current play position, the function pointer will be called
 * to report position information.
 *
 * @param {OH_LowPowerAudioSink*} sink OH_LowPowerAudioSink instance
 * @param {int64_t} currentPosition Returns the current playback progress value of the service
 * @param {void*} userData User specific data
 * @since 20
 */
typedef void (*OH_LowPowerAudioSink_OnPositionUpdated)(
    OH_LowPowerAudioSink* sink,
    int64_t currentPosition,
    void* userData);

/**
 * @brief When the OH_LowPowerAudioSink instance report to need data, the function pointer will be called
 * to request data.
 *
 * @param {OH_LowPowerAudioSink*} sink OH_LowPowerAudioSink instance
 * @param {OH_AVSamplesBuffer*} samples OH_AVSamplesBuffer instance that will be written in
 * @param {void*} userData User specific data
 * @since 20
 */
typedef void (*OH_LowPowerAudioSink_OnDataNeeded)(
    OH_LowPowerAudioSink* sink,
    OH_AVSamplesBuffer* samples,
    void* userData);

/**
 * @brief This function pointer will point to the callback function that
 * is used to handle audio interrupt events.
 *
 * @param {OH_LowPowerAudioSink*} sink OH_LowPowerAudioSink instance
 * @param {OH_AudioInterrupt_ForceType} type The audio interrupt type,
 * please refer to {@link OH_AudioInterrupt_ForceType}
 * @param {OH_AudioInterrupt_Hint} hint The audio interrupt hint type, please refer to {@link OH_AudioInterrupt_Hint}
 * @param {void*} userData User specific data
 * @since 20
 */
typedef void (*OH_LowPowerAudioSink_OnInterrupted)(
    OH_LowPowerAudioSink* sink,
    OH_AudioInterrupt_ForceType type,
    OH_AudioInterrupt_Hint hint,
    void* userData);

/**
 * @brief When the output device of an audio renderer changed, the function pointer will be called
 * to report device change reason.
 *
 * @param {OH_LowPowerAudioSink*} sink OH_LowPowerAudioSink instance
 * @param {OH_AudioStream_DeviceChangeReason} reason Indicates that why does the output device changes,
 * please refer to {@link OH_AudioStream_DeviceChangeReason}
 * @param {void*} userData User specific data
 * @since 20
 */
typedef void (*OH_LowPowerAudioSink_OnDeviceChanged)(
    OH_LowPowerAudioSink* sink,
    OH_AudioStream_DeviceChangeReason reason,
    void* userData);

/**
 * @brief When the lowpower audio sink play to end of stream, the function pointer will be called
 * to report play completed event.
 *
 * @param {OH_LowPowerAudioSink*} sink OH_LowPowerAudioSinkinstance
 * @param {void*} userData User specific data
 * @since 20
 */
typedef void (*OH_LowPowerAudioSink_OnEos)(OH_LowPowerAudioSink* sink, void* userData);

#ifdef __cplusplus
}
#endif
#endif // NATIVE_LOWERPOWER_AUDIOSINK_BASH_H

/** @} */
