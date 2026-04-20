/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
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
 * @since 10
 * @version 1.0
 */

/**
 * @file native_audiorenderer.h
 *
 * @brief Declare audio stream related interfaces for output type.
 *
 * @library libohaudio.so
 * @syscap SystemCapability.Multimedia.Audio.Core
 * @kit AudioKit
 * @since 10
 * @version 1.0
 */

#ifndef NATIVE_AUDIORENDERER_H
#define NATIVE_AUDIORENDERER_H

#include "info/application_target_sdk_version.h"
#include <stdbool.h>
#include <time.h>
#include "native_audiostream_base.h"
#include "native_audio_device_base.h"
#include "multimedia/native_audio_channel_layout.h"
#ifdef __cplusplus
extern "C" {
#endif
/**
 * Request to release the renderer stream.
 *
 * @since 10
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 *         {@link AUDIOSTREAM_ERROR_ILLEGAL_STATE} Execution status exception.
 */
OH_AudioStream_Result OH_AudioRenderer_Release(OH_AudioRenderer* renderer)
__attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Request to start the renderer stream.
 *
 * @since 10
 *
 * @param renderer reference created by OH_AudioStreamBuilder
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 *         {@link AUDIOSTREAM_ERROR_ILLEGAL_STATE} Execution status exception.
 */
OH_AudioStream_Result OH_AudioRenderer_Start(OH_AudioRenderer* renderer)
__attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Request to pause the renderer stream.
 *
 * @since 10
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 *         {@link AUDIOSTREAM_ERROR_ILLEGAL_STATE} Execution status exception.
 */
OH_AudioStream_Result OH_AudioRenderer_Pause(OH_AudioRenderer* renderer)
__attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Request to stop renderer stream.
 *
 * @since 10
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 *         {@link AUDIOSTREAM_ERROR_ILLEGAL_STATE} Execution status exception.
 */
OH_AudioStream_Result OH_AudioRenderer_Stop(OH_AudioRenderer* renderer)
__attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Request to flush the renderer stream.
 *
 * @since 10
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 *         {@link AUDIOSTREAM_ERROR_ILLEGAL_STATE} Execution status exception.
 */
OH_AudioStream_Result OH_AudioRenderer_Flush(OH_AudioRenderer* renderer)
__attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Query the current state of the renderer client.
 *
 * This function will return the renderer state without updating the state.
 *
 * @since 10
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param state Pointer to a variable that will be set for the state value.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 */
OH_AudioStream_Result OH_AudioRenderer_GetCurrentState(OH_AudioRenderer* renderer,
    OH_AudioStream_State* state)
    __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Query the sample rate value of the renderer client
 *
 * This function will return the renderer sample rate value without updating the state.
 *
 * @since 10
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param rate The state value to be updated
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 */
OH_AudioStream_Result OH_AudioRenderer_GetSamplingRate(OH_AudioRenderer* renderer, int32_t* rate)
__attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Query the stream id of the renderer client.
 *
 * @since 10
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param streamId Pointer to a variable that will be set for the stream id.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 */
OH_AudioStream_Result OH_AudioRenderer_GetStreamId(OH_AudioRenderer* renderer, uint32_t* streamId)
__attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Query the channel count of the renderer client.
 *
 * @since 10
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param channelCount Pointer to a variable that will be set for the channel count.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 */
OH_AudioStream_Result OH_AudioRenderer_GetChannelCount(OH_AudioRenderer* renderer, int32_t* channelCount)
__attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Query the sample format of the renderer client.
 *
 * @since 10
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param sampleFormat Pointer to a variable that will be set for the sample format.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 */
OH_AudioStream_Result OH_AudioRenderer_GetSampleFormat(OH_AudioRenderer* renderer,
    OH_AudioStream_SampleFormat* sampleFormat)
    __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Query the latency mode of the renderer client.
 *
 * @since 10
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param latencyMode Pointer to a variable that will be set for the latency mode.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 */
OH_AudioStream_Result OH_AudioRenderer_GetLatencyMode(OH_AudioRenderer* renderer,
    OH_AudioStream_LatencyMode* latencyMode)
    __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Query the renderer info of the renderer client.
 *
 * The rendere info includes {@link OH_AudioStream_Usage} value.
 *
 * @since 10
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param usage Pointer to a variable that will be set for the stream usage.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 */
OH_AudioStream_Result OH_AudioRenderer_GetRendererInfo(OH_AudioRenderer* renderer,
    OH_AudioStream_Usage* usage)
    __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Query the encoding type of the renderer client.
 *
 * @since 10
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param encodingType Pointer to a variable that will be set for the encoding type.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 */
OH_AudioStream_Result OH_AudioRenderer_GetEncodingType(OH_AudioRenderer* renderer,
    OH_AudioStream_EncodingType* encodingType)
    __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Query the the number of frames that have been written since the stream was created.
 *
 * @since 10
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param frames Pointer to a variable that will be set for the frame count number.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 */
OH_AudioStream_Result OH_AudioRenderer_GetFramesWritten(OH_AudioRenderer* renderer, int64_t* frames)
__attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Query the the time at which a particular frame was presented.
 *
 * It is recommended to use new api {@link OH_AudioRenderer_GetAudioTimestampInfo}
 * because it adapts to playback speed change, but current api does not. The
 * increasing speed for position will not change when speed become fast.
 *
 * @since 10
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param clockId {@link #CLOCK_MONOTONIC}
 * @param framePosition Pointer to a variable to receive the position
 * @param timestamp Pointer to a variable to receive the timestamp
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of renderer is nullptr;
 *                                                 2.The param of clockId invalid.
 *         {@link AUDIOSTREAM_ERROR_ILLEGAL_STATE} Execution status exception.
 */
OH_AudioStream_Result OH_AudioRenderer_GetTimestamp(OH_AudioRenderer* renderer,
    clockid_t clockId, int64_t* framePosition, int64_t* timestamp)
    __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Query the frame size in callback, it is a fixed length that the stream want to be filled for each callback.
 *
 * @since 10
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param frameSize Pointer to a variable that will be set for the frame size.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 */
OH_AudioStream_Result OH_AudioRenderer_GetFrameSizeInCallback(OH_AudioRenderer* renderer, int32_t* frameSize)
__attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Query the playback speed of the stream client
 *
 * @since 11
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param speed Pointer to a variable to receive the playback speed.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 */
OH_AudioStream_Result OH_AudioRenderer_GetSpeed(OH_AudioRenderer* renderer, float* speed)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * Set the playback speed of the stream client
 *
 * @since 11
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param speed The playback speed, form 0.25 to 4.0.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 */
OH_AudioStream_Result OH_AudioRenderer_SetSpeed(OH_AudioRenderer* renderer, float speed)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * Set volume of current renderer.
 *
 * @since 12
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param volume Volume to set which changes from 0.0 to 1.0.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of renderer is nullptr;
 *                                                 2.The param of volume invalid.
 *         {@link AUDIOSTREAM_ERROR_ILLEGAL_STATE} Execution status exception.
 *         {@link AUDIOSTREAM_ERROR_SYSTEM} An system error has occurred.
 */
OH_AudioStream_Result OH_AudioRenderer_SetVolume(OH_AudioRenderer* renderer, float volume)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * Changes the volume with ramp for a duration.
 *
 * @since 12
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param volume Volume to set which changes from 0.0 to 1.0.
 * @param durationMs Duration for volume ramp, in millisecond.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of renderer is nullptr;
 *                                                 2.The param of volume invalid.
 *         {@link AUDIOSTREAM_ERROR_ILLEGAL_STATE} Execution status exception.
 *         {@link AUDIOSTREAM_ERROR_SYSTEM} An system error has occurred.
 */
OH_AudioStream_Result OH_AudioRenderer_SetVolumeWithRamp(OH_AudioRenderer* renderer, float volume, int32_t durationMs)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * Get Volume of current renderer.
 *
 * @since 12
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param volume Pointer to a variable to receive the volume.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of renderer is nullptr;
 *                                                 2.The param of volume is nullptr.
 */
OH_AudioStream_Result OH_AudioRenderer_GetVolume(OH_AudioRenderer* renderer, float* volume)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set mark position on current renderer. Calling this function will overwrite the mark postion which has already
 * set.
 *
 * @since 12
 *
 * @param renderer Renderer generated by OH_AudioStreamBuilder_GenerateRenderer()
 * @param samplePos Mark position in samples.
 * @param callback Callback used when the samplePos has reached.
 * @param userData User data which is passed by user.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of renderer is nullptr;
 *                                                 2.The param of samplePos invalid.
 *         {@link AUDIOSTREAM_ERROR_ILLEGAL_STATE} Execution status exception.
 *         {@link AUDIOSTREAM_ERROR_SYSTEM} An system error has occurred.
 */
OH_AudioStream_Result OH_AudioRenderer_SetMarkPosition(OH_AudioRenderer* renderer, uint32_t samplePos,
    OH_AudioRenderer_OnMarkReachedCallback callback, void* userData)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Cancel mark which has set by {@link #OH_AudioRenderer_SetMarkPosition}.
 *
 * @since 12
 *
 * @param renderer Renderer generated by OH_AudioStreamBuilder_GenerateRenderer()
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 */
OH_AudioStream_Result OH_AudioRenderer_CancelMark(OH_AudioRenderer* renderer)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Gets the underflow count on this stream.
 *
 * @since 12
 *
 * @param renderer Renderer generated by OH_AudioStreamBuilder_GenerateRenderer()
 * @param count Pointer to a variable to receive the underflow count number.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of renderer is nullptr;
 *                                                 2.The param of count is nullptr.
 */
OH_AudioStream_Result OH_AudioRenderer_GetUnderflowCount(OH_AudioRenderer* renderer, uint32_t* count)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Query the channel layout of the renderer client.
 *
 * @since 12
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param channelLayout Pointer to a variable to receive the channel layout
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 */
OH_AudioStream_Result OH_AudioRenderer_GetChannelLayout(OH_AudioRenderer* renderer,
    OH_AudioChannelLayout* channelLayout)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Query current audio effect mode.
 *
 * @since 12
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param effectMode Pointer to a variable to receive current audio effect mode
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 */
OH_AudioStream_Result OH_AudioRenderer_GetEffectMode(OH_AudioRenderer* renderer,
    OH_AudioStream_AudioEffectMode* effectMode)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set current audio effect mode.
 *
 * @since 12
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param effectMode Audio effect mode that will be set for the stream
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 */
OH_AudioStream_Result OH_AudioRenderer_SetEffectMode(OH_AudioRenderer* renderer,
    OH_AudioStream_AudioEffectMode effectMode)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get the privacy of this stream.
 *
 * @since 12
 *
 * @param renderer Renderer generated by OH_AudioStreamBuilder_GenerateRenderer()
 * @param privacy Pointer to a variable which receives the results.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of renderer is nullptr.
 */
OH_AudioStream_Result OH_AudioRenderer_GetRendererPrivacy(OH_AudioRenderer* renderer,
    OH_AudioStream_PrivacyType* privacy)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set silent and mix with other streams for this stream.
 *
 * @param renderer Renderer generated by OH_AudioStreamBuilder_GenerateRenderer()
 * @param on The silent and mix with other streams mode.
 *     true: set the slient mode and mix with other streams.
 *     false: unset the slient mode, current stream will trigger the audio focus internally.
 * @return result code for this function.
 *     {@link #AUDIOSTREAM_SUCCESS} succeed in setting to the silent and mix with other streams.
 *     {@link #AUDIOSTREAM_ERROR_ILLEGAL_STATE} this stream is not allowed to set/unset the silent mode.
 * @since 12
 */
OH_AudioStream_Result OH_AudioRenderer_SetSilentModeAndMixWithOthers(
    OH_AudioRenderer* renderer, bool on)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Query silent and mix with other streams status for this stream.
 *
 * @param renderer Renderer generated by OH_AudioStreamBuilder_GenerateRenderer()
 * @param on Pointer to the silent and mix with other streams status.
 * @return result code for this function.
 *     {@link #AUDIOSTREAM_SUCCESS} succeed in getting silent and mix with other streams status
 *     {@link #AUDIOSTREAM_ERROR_SYSTEM} system error when calling this function.
 * @since 12
 */
OH_AudioStream_Result OH_AudioRenderer_GetSilentModeAndMixWithOthers(
    OH_AudioRenderer* renderer, bool* on)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Temporarily changes the current audio device
 *        This function applys on audiorenderers whose StreamUsage are
 *        STREAM_USAGE_VOICE_COMMUNICATIN/STREAM_USAGE_VIDEO_COMMUNICATION/STREAM_USAGE_VOICE_MESSAGE.
 *        Setting the device will only takes effect if no other accessory such as headphones are in use.
 *
 * @param renderer Renderer generated by OH_AudioStreamBuilder_GenerateRenderer()
 * @param deviceType The target device. The available deviceTypes are:
 *                                             EARPIECE: Built-in earpiece
 *                                             SPEAKER: Built-in speaker
 *                                             DEFAULT: System default output device
 * @return result code for this function.
 *         {@link #AUDIOSTREAM_SUCCESS} succeed in setting the default output device
 *         {@link #AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of renderer is nullptr;
 *                                                 2.The param of deviceType is not valid
 *         {@link #AUDIOSTREAM_ERROR_ILLEGAL_STATE} This audiorenderer can not reset the output device
 *         {@link #AUDIOSTREAM_ERROR_SYSTEM} system error when calling this function.
 * @since 12
 */
OH_AudioStream_Result OH_AudioRenderer_SetDefaultOutputDevice(
    OH_AudioRenderer* renderer, OH_AudioDevice_Type deviceType)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Query the timestamp at which a particular frame was presented in clock monotonic timebase,
 *        the frame at the returned position was just committed to hardware. This is often used in
 *        video synchronization and recording stream alignment.
 *
 *        Position is 0 and timestamp is fixed until stream really runs and frame is committed. Position
 *        will also be reset while flush function is called. When a audio route change happens, like in
 *        device or output type change situations, the position may also be reset but timestamp remains
 *        monotonically increasing.
 *        So it is better to use the values until they becomes regularly after the change.
 *        This interface also adapts to playback speed change. For example, the increseing speed for
 *        position will be double for 2x speed playback.
 *
 *        For video synchronization usage, there is a best practice document for developer to refer
 *        **AV Synchronization**.
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param framePosition Pointer to a variable to receive the position
 * @param timestamp Pointer to a variable to receive the timestamp
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                         1.The param of renderer is nullptr;
 *                                         2.The param of framePosition or timestamp is nullptr;
 *         {@link AUDIOSTREAM_ERROR_ILLEGAL_STATE}:
 *                                         1.Only running state is legal for getting audio timestamp.
 *         {@link AUDIOSTREAM_ERROR_SYSTEM}:
 *                                         1.Crash or blocking occurs in system process.
 *                                         2.Other unexpected error from internal system.
 * @since 15
 */
OH_AudioStream_Result OH_AudioRenderer_GetAudioTimestampInfo(OH_AudioRenderer* renderer,
    int64_t* framePosition, int64_t* timestamp)
    __attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Called when an interrupt event occurs in an AudioRenderer instance.
 * This function is similar to OH_AudioRenderer_Callbacks_Struct.OH_AudioRenderer_OnInterruptEvent.
 *
 * @param renderer Pointer to the AudioRenderer instance that triggers the callback.
 * @param userData Pointer to the user data passed when setting the callback via
 * OH_AudioStreamBuilder_SetRendererInterruptCallback.
 * @param type Type of force that causes the interrupt event.
 * @param hint Hint provided along with the interrupt event.
 * @see OH_AudioRenderer_Callbacks_Struct.OH_AudioRenderer_OnInterruptEvent.
 * @since 20
 */
typedef void (*OH_AudioRenderer_OnInterruptCallback)(OH_AudioRenderer* renderer, void* userData,
    OH_AudioInterrupt_ForceType type, OH_AudioInterrupt_Hint hint);

/**
 * @brief Called when an error event occurs in an AudioRenderer instance.
 * This function is similar to OH_AudioRenderer_Callbacks_Struct.OH_AudioRenderer_OnError.
 *
 * @param renderer Pointer to the AudioRenderer instance that triggers the callback.
 * @param userData Pointer to the user data passed when setting the callback via
 * OH_AudioStreamBuilder_SetRendererErrorCallback.
 * @param error Specific error information.
 * @see OH_AudioRenderer_Callbacks_Struct.OH_AudioRenderer_OnError
 * @since 20
 */
typedef void (*OH_AudioRenderer_OnErrorCallback)(OH_AudioRenderer* renderer, void* userData,
    OH_AudioStream_Result error);

/**
 * @brief Gets audio renderer running status, check if it works in fast status.
 *
 * @param renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer.
 * @param status Pointer to a variable to receive the status.
 * @return
 *     {@link AUDIOSTREAM_SUCCESS} if the execution is successful.
 *     {@link AUDIOSTREAM_ERROR_INVALID_PARAM} the param of renderer is nullptr.
 *     {@link AUDIOSTREAM_ERROR_ILLEGAL_STATE} function called in invalid state, only available before release state.
 * @since 20
 */
OH_AudioStream_Result OH_AudioRenderer_GetFastStatus(OH_AudioRenderer* renderer,
    OH_AudioStream_FastStatus* status)
    __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Callback function of fast status change event for audio renderer.
 *
 * @param renderer Pointer to an audio renderer instance for which this callback occurs.
 * @param userData Userdata which is passed by register.
 * @param status Current fast status.
 * @since 20
 */
typedef void (*OH_AudioRenderer_OnFastStatusChange)(
    OH_AudioRenderer* renderer,
    void* userData,
    OH_AudioStream_FastStatus status
);

/**
 * @brief Sets the loudness gain of current renderer.
 * The default loudness gain is 0.0dB. The stream usage of the audio renderer must be
 * {@link OH_AudioStream_Usage#AUDIOSTREAM_USAGE_MUSIC}, {@link OH_AudioStream_Usage#AUDIOSTREAM_USAGE_MOVIE}
 * or {@link OH_AudioStream_Usage#AUDIOSTREAM_USAGE_AUDIOBOOK}.
 * The latency mode of the audio renderer must be {@link OH_AudioStream_LatencyMode#AUDIOSTREAM_LATENCY_MODE_NORMAL}.
 * If AudioRenderer is played through the high-resolution pipe, this operation is not supported.
 *
 * @param renderer AudioRender created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param loudnessGain Loudness gain to set which changes from -90.0 to 24.0, expressing in dB.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of renderer is nullptr or not supported to set gain;
 *                                                 2.The param of loudnessGain is invalid.
 * @since 20
 */
OH_AudioStream_Result OH_AudioRenderer_SetLoudnessGain(OH_AudioRenderer* renderer, float loudnessGain)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Get the loudness gain of current renderer.
 *
 * @param renderer AudioRender created by OH_AudioStreamBuilder_GenerateRenderer()
 * @param loudnessGain Pointer to a variable to receive the loudness gain.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of renderer is nullptr;
 *                                                 2.The param of loudnessGain is nullptr.
 * @since 20
 */
OH_AudioStream_Result OH_AudioRenderer_GetLoudnessGain(OH_AudioRenderer* renderer, float* loudnessGain)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Callback function of write data on Render.
 *
 * Different with OH_AudioRenderer_OnWriteDataCallback, this function allows the caller to write partial data which
 * ranges from 0 to the callback buffer size. If 0 is returned, the callback thread will sleep for a while. Otherwise,
 * the system may callback again immediately.
 *
 * @param renderer AudioRenderer where this callback occurs.
 * @param userData User data which is passed by user.
 * @param audioData Audio data pointer, where user should fill in audio data.
 * @param audioDataSize Size of audio data that user should fill in.
 * @return Length of the valid data that has written into audioData buffer. The return value must be in range of
 * [0, audioDataSize]. If the return value is less than 0, the system changes it to 0. And, if the return value is
 * greater than audioDataSize, the system changes it to audioDataSize. Note that the length of the returned buffer
 * must be an integer multiple of the length of the single sample data. For example, for 2 channels and S16 format
 * audio data, it must be an integer multiple of 4(2*16/8). Otherwise, it may cause noise during playback.
 * @see OH_AudioRenderer_OnWriteDataCallback
 * @since 20
 */
typedef int32_t (*OH_AudioRenderer_OnWriteDataCallbackAdvanced)(OH_AudioRenderer* renderer, void* userData,
    void* audioData, int32_t audioDataSize);

/**
 * @brief Gets the estimated audio latency in milliseconds for current audio route. For wireless connection
 * audio devices cases, the latency result may not be very accurate, system just provides it for reference only.
 * The real-time buffer status is also not taken into consideration, so it is recommended to get it only at the
 * beginning of audio playback, and do not call th function very frequently because it may be blocked by route
 * change.
 * Applications should still use {@link #OH_AudioRenderer_GetAudioTimestampInfo} to handle A/V sync after audio
 * data has been output to hardware.
 *
 * @param renderer AudioRenderer created by OH_AudioStreamBuilder_GenerateRenderer().
 * @param type Type of audio latency to get.
 * @param latencyMs Pointer to a variable to receive the latency in milliseconds.
 * @return Function result code:
 *         {@link #AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link #AUDIOSTREAM_ERROR_INVALID_PARAM}
 *             1.The param of renderer is nullptr.
 *             2.The param of latencyMs is nullptr.
 *             3.The param of type is invalid value.
 *         {@link #AUDIOSTREAM_ERROR_SYSTEM} System internal error, like audio service error.
 * @since 23
 */
OH_AudioStream_Result OH_AudioRenderer_GetLatency(OH_AudioRenderer* renderer,
    OH_AudioStream_LatencyType type, int32_t* latencyMs)
    __attribute__((__availability__(ohos, introduced=23.0.0)));
#ifdef __cplusplus
}
#endif

#endif // NATIVE_AUDIORENDERER_H
/** @} */