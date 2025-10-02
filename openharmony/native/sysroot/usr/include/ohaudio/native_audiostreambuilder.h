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
 * @file native_audiostreambuilder.h
 *
 * @brief Declare audio stream builder related interfaces.
 *
 * @library libohaudio.so
 * @syscap SystemCapability.Multimedia.Audio.Core
 * @kit AudioKit
 * @since 10
 * @version 1.0
 */

#ifndef NATIVE_AUDIOSTREAM_BUILDER_H
#define NATIVE_AUDIOSTREAM_BUILDER_H

#include "native_audiostream_base.h"
#include "native_audiorenderer.h"
#include "native_audiocapturer.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a stremBuilder can be used to open a renderer or capturer client.
 *
 * OH_AudioStreamBuilder_Destroy() must be called when you are done using the builder.
 *
 * @since 10
 *
 * @param builder The builder reference to the created result.
 * @param type The stream type to be created. {@link #AUDIOSTREAM_TYPE_RENDERER} or {@link #AUDIOSTREAM_TYPE_CAPTURER}
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 */
OH_AudioStream_Result OH_AudioStreamBuilder_Create(OH_AudioStreamBuilder** builder, OH_AudioStream_Type type);

/**
 * Destroy a streamBulder.
 *
 * This function must be called when you are done using the builder.
 *
 * @since 10
 *
 * @param builder Reference provided by OH_AudioStreamBuilder_Create()
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of builder is nullptr.
 *         {@link AUDIOSTREAM_ERROR_ILLEGAL_STATE} Execution status exception.
 */
OH_AudioStream_Result OH_AudioStreamBuilder_Destroy(OH_AudioStreamBuilder* builder);

/**
 * Set the channel count of the capturer client
 *
 * @since 10
 *
 * @param builder Reference created by OH_AudioStreamBuilder
 * @param rate Pointer to a variable that will be set for the channel count.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of rate invalid.
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetSamplingRate(OH_AudioStreamBuilder* builder, int32_t rate);

/**
 * Set the channel count of the stream client
 *
 * @since 10
 *
 * @param builder Reference provided by OH_AudioStreamBuilder_Create()
 * @param channelCount The channel count.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of channelCount invalid.
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetChannelCount(OH_AudioStreamBuilder* builder, int32_t channelCount);

/**
 * Set the sample format of the stream client
 *
 * @since 10
 *
 * @param builder Reference provided by OH_AudioStreamBuilder_Create()
 * @param format Sample data format.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of builder is nullptr.
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetSampleFormat(OH_AudioStreamBuilder* builder,
    OH_AudioStream_SampleFormat format);

/**
 * Set the encoding type of the stream client
 *
 * @since 10
 *
 * @param builder Reference provided by OH_AudioStreamBuilder_Create()
 * @param encodingType Encoding type for the stream client, {@link #AUDIOSTREAM_ENCODING_PCM}
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of builder is nullptr.
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetEncodingType(OH_AudioStreamBuilder* builder,
    OH_AudioStream_EncodingType encodingType);

/**
 * Set the latency mode of the stream client
 *
 * @since 10
 *
 * @param builder Reference provided by OH_AudioStreamBuilder_Create()
 * @param latencyMode Latency mode for the stream client.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of builder is nullptr.
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetLatencyMode(OH_AudioStreamBuilder* builder,
    OH_AudioStream_LatencyMode latencyMode);

/**
 * @brief Set the channel layout to the stream client
 *
 * @since 12
 *
 * @param builder Reference provided by OH_AudioStreamBuilder_Create()
 * @param channelLayout is the layout of the speaker.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of builder is nullptr.
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetChannelLayout(OH_AudioStreamBuilder* builder,
    OH_AudioChannelLayout channelLayout);

/**
 * Set the renderer information of the stream client
 *
 * @since 10
 *
 * @param builder Reference provided by OH_AudioStreamBuilder_Create()
 * @param usage Set the stream usage for the renderer client.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of usage invalid.
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInfo(OH_AudioStreamBuilder* builder,
    OH_AudioStream_Usage usage);

/**
 * Set the capturer information of the stream client
 *
 * @since 10
 *
 * @param builder Reference provided by OH_AudioStreamBuilder_Create()
 * @param sourceType Set the source type for the capturer client.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of sourceType invalid.
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerInfo(OH_AudioStreamBuilder* builder,
    OH_AudioStream_SourceType sourceType);

/**
 * Set the callbacks for the renderer client
 *
 * @deprecated since 20
 * @useinstead Set the callback functions separately using OH_AudioStreamBuilder_SetRendererWriteDataCallback,
 * OH_AudioStreamBuilder_SetRendererInterruptCallback, OH_AudioStreamBuilder_SetRendererOutputDeviceChangeCallback
 * and OH_AudioStreamBuilder_SetRendererErrorCallback.
 * @since 10
 *
 * @param builder Reference provided by OH_AudioStreamBuilder_Create()
 * @param callbacks Callbacks to the functions that will process renderer stream.
 * @param userData Pointer to an application data structure that will be passed to the callback functions.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.StreamType invalid.
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererCallback(OH_AudioStreamBuilder* builder,
    OH_AudioRenderer_Callbacks callbacks, void* userData);

/**
 * @brief Set the callback when the output device of an audio renderer changed.
 *
 * @since 11
 *
 * @param builder Reference provided by OH_AudioStreamBuilder_Create()
 * @param callback Callback to the function that will process this device change event.
 * @param userData Pointer to an application data structure that will be passed to the callback functions.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.StreamType invalid.
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererOutputDeviceChangeCallback(OH_AudioStreamBuilder* builder,
    OH_AudioRenderer_OutputDeviceChangeCallback callback, void* userData);

/**
 * @brief Set the privacy of audio render.
 *
 * @since 12
 *
 * @param builder Builder provided by OH_AudioStreamBuilder_Create()
 * @param privacy Privacy type.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.StreamType invalid.
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererPrivacy(OH_AudioStreamBuilder* builder,
    OH_AudioStream_PrivacyType privacy);

/**
 * Set the callbacks for the capturer client
 *
 * @deprecated since 20
 * @useinstead Set the callback functions separately using OH_AudioStreamBuilder_SetCapturerReadDataCallback,
 * OH_AudioStreamBuilder_SetCapturerDeviceChangeCallback, OH_AudioStreamBuilder_SetCapturerInterruptCallback
 * and OH_AudioStreamBuilder_SetCapturerErrorCallback.
 * @since 10
 *
 * @param builder Reference provided by OH_AudioStreamBuilder_Create()
 * @param callbacks Callbacks to the functions that will process capturer stream.
 * @param userData Pointer to an application data structure that will be passed to the callback functions.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.StreamType invalid.
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerCallback(OH_AudioStreamBuilder* builder,
    OH_AudioCapturer_Callbacks callbacks, void* userData);

/**
 * Create the audio renderer client.
 *
 * The AudioRenderer instance is used to play streaming audio data.
 * When using AudioRenderer apis, there are many instructions for application
 * to achieve better performance and lower power consumption:
 * In music or audiobook background playback situation, you can have low power
 * consumption by following this best practices document **Low-Power Rules in Music Playback Scenarios**.
 * And for navigation situation, you can follow **Low-Power Rules in Navigation and Positioning Scenarios**.
 *
 * Application developer should also be careful when app goes to background, please check if your audio playback
 * is still needed, see **Audio Resources** in best practices document.
 * And avoiding to send silence audio data continuously to waste system resources, otherwise system will take
 * control measures when this behavior is detected, see **Audio Playback** in best practices document.
 *
 * If you want to use AudioRenderer api to implement a music playback application, there are also many interactive
 * scenes to consider, see **Developing an Audio Application** in best practices document.
 *
 * @since 10
 *
 * @param builder Reference provided by OH_AudioStreamBuilder_Create()
 * @param audioRenderer Pointer to a viriable to receive the stream client.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.StreamType invalid;
 *                                                 3.Create OHAudioRenderer failed.
 */
OH_AudioStream_Result OH_AudioStreamBuilder_GenerateRenderer(OH_AudioStreamBuilder* builder,
    OH_AudioRenderer** audioRenderer);

/**
 * Create the audio capturer client.
 *
 * @since 10
 *
 * @param builder Reference provided by OH_AudioStreamBuilder_Create()
 * @param audioCapturer Pointer to a viriable to receive the stream client.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.StreamType invalid;
 *                                                 3.Create OHAudioCapturer failed.
 */
OH_AudioStream_Result OH_AudioStreamBuilder_GenerateCapturer(OH_AudioStreamBuilder* builder,
    OH_AudioCapturer** audioCapturer);

/**
 * Set the data frame size for each callback, use this function if the application requires a specific number
 * of frames for processing.
 * The frame size should be at least the size device process at one time, and less than half the internal
 * buffer capacity.
 *
 * @since 11
 *
 * @param builder Reference provided by OH_AudioStreamBuilder_Create()
 * @param frameSize  The data frame size for each callback.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM} The param of builder is nullptr.
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetFrameSizeInCallback(OH_AudioStreamBuilder* builder,
    int32_t frameSize);

/**
 * @brief Set the callback of writing metadata to the renderer client
 *
 * @since 12
 *
 * @param builder Reference provided by OH_AudioStreamBuilder_Create()
 * @param callback Callback to the functions that will write audio data with metadata to the renderer.
 * @param userData Pointer to an application data structure that will be passed to the callback functions.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.StreamType invalid.
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetWriteDataWithMetadataCallback(OH_AudioStreamBuilder* builder,
    OH_AudioRenderer_WriteDataWithMetadataCallback callback, void* userData);

/**
 * @brief Set the interrupt mode of the stream client
 *
 * @since 12
 *
 * @param builder Reference provided by OH_AudioStreamBuilder_Create()
 * @param mode The audio interrupt mode
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of mode invalid;
 *                                                 3.StreamType invalid.
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInterruptMode(OH_AudioStreamBuilder* builder,
    OH_AudioInterrupt_Mode mode);

/**
 * @brief Set the callback of writing data to renderer client.
 *
 * This function is similar with {@link OH_AudioStreamBuilder_SetRendererCallback}. Only the last callback set by
 * OH_AudioStreamBuilder_SetRendererCallback or this function will become effective.
 *
 * @param builder Builder provided by OH_AudioStreamBuilder_Create()
 * @param callback Callback to functions that will write audio data to renderer client.
 * @param userData Pointer to an application data structure that will be passed to the callback functions.
 * @return Result code.
 *     {@link AUDIOSTREAM_SUCCESS} Success.
 *     {@link AUDIOSTREAM_ERROR_INVALID_PARAM} Parameter is invalid, e.g. builder is nullptr, e.t.c.
 * @since 12
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererWriteDataCallback(OH_AudioStreamBuilder* builder,
    OH_AudioRenderer_OnWriteDataCallback callback, void* userData);

/**
 * @brief Set the callback of writing data to renderer client.
 *
 * This function is similar with {@link OH_AudioStreamBuilder_SetRendererWriteDataCallback}. Only the last callback set
 * by OH_AudioStreamBuilder_SetRendererWriteDataCallback or this function will become effective. Different with
 * OH_AudioStreamBuilder_SetRendererWriteDataCallback, the callback in this function can return audio data of any
 * length.
 *
 * @param builder Builder provided by OH_AudioStreamBuilder_Create()
 * @param callback Callback to functions that will write audio data to renderer client.
 * @param userData Pointer to an application data structure that will be passed to the callback functions.
 * @return Result code.
 *     {@link AUDIOSTREAM_SUCCESS} Success.
 *     {@link AUDIOSTREAM_ERROR_INVALID_PARAM} Parameter is invalid, e.g. builder is nullptr, e.t.c.
 * @since 20
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererWriteDataCallbackAdvanced(OH_AudioStreamBuilder* builder,
    OH_AudioRenderer_OnWriteDataCallbackAdvanced callback, void* userData);

/**
 * Set the renderer volume mode of the stream client
 *
 * @param builder Reference provided by OH_AudioStreamBuilder_Create()
 * @param volumeMode Set the volume mode for the renderer client.
 * @return Function result code:
 *         {@link AUDIOSTREAM_SUCCESS} If the execution is successful.
 *         {@link AUDIOSTREAM_ERROR_INVALID_PARAM}:
 *                                                 1.The param of builder is nullptr;
 *                                                 2.The param of volumeMode invalid.
 * @since 19
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetVolumeMode(OH_AudioStreamBuilder* builder,
    OH_AudioStream_VolumeMode volumeMode);

/**
 * @brief Sets a callback to handle interrupt events for an AudioRenderer instance. This function is similar to
 * {@link OH_AudioStreamBuilder_SetRendererCallback}. If both OH_AudioStreamBuilder_SetRendererCallback and this
 * function are called, the most recently set callback takes effect.
 *
 * @param builder Builder instance, which is generated by OH_AudioStreamBuilder_Create().
 * @param callback Callback used to handle the interrupt events.
 * @param userData Pointer to user-defined data, which will be passed back to the application in the callback.
 * @return Result code.
 *     {@link AUDIOSTREAM_SUCCESS} is returned if the operation is successful.
 *     {@link AUDIOSTREAM_ERROR_INVALID_PARAM} is returned if a parameter is invalid, for example, if builder
 * is nullptr.
 * @since 20
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInterruptCallback(OH_AudioStreamBuilder* builder,
    OH_AudioRenderer_OnInterruptCallback callback, void* userData);

/**
 * @brief Sets a callback to handle error events for an AudioRenderer instance.
 * This function is similar to {@link OH_AudioStreamBuilder_SetRendererCallback}. If both
 * OH_AudioStreamBuilder_SetRendererCallback and this function are called, the most recently set callback takes
 * effect.
 *
 * @param builder Builder instance, which is generated by OH_AudioStreamBuilder_Create().
 * @param callback Callback used to handle the error events.
 * @param userData Pointer to user-defined data, which will be passed back to the application in the callback.
 * @return Result code.
 *     {@link AUDIOSTREAM_SUCCESS} is returned if the operation is successful.
 *     {@link AUDIOSTREAM_ERROR_INVALID_PARAM} is returned if a parameter is invalid, for example, if builder
 * is nullptr.
 * @since 20
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererErrorCallback(OH_AudioStreamBuilder* builder,
    OH_AudioRenderer_OnErrorCallback callback, void* userData);

/**
 * @brief Sets a callback to handle audio data read events for an AudioCapturer instance. This function is
 * similar to {@link OH_AudioStreamBuilder_SetCapturerCallback}. If both {@link
 * OH_AudioStreamBuilder_SetCapturerCallback} and this function are called, the most recently set callback takes
 * effect.
 *
 * @param builder Builder instance, which is generated by OH_AudioStreamBuilder_Create().
 * @param callback Callback used to handle incoming audio data.
 * @param userData Pointer to user-defined data, which will be passed back to the application in the callback.
 * @return Result code.
 *     {@link AUDIOSTREAM_SUCCESS} is returned if the operation is successful.
 *     {@link AUDIOSTREAM_ERROR_INVALID_PARAM} is returned if a parameter is invalid, for example, if builder
 * is nullptr.
 * @since 20
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerReadDataCallback(OH_AudioStreamBuilder* builder,
    OH_AudioCapturer_OnReadDataCallback callback, void* userData);

/**
 * @brief Sets a callback to handle device change events for an AudioCapturer instance. This function is
 * similar to {@link OH_AudioStreamBuilder_SetCapturerCallback}. If both OH_AudioStreamBuilder_SetCapturerCallback
 * and this function are called, the most recently set callback takes effect.
 *
 * @param builder Builder instance, which is generated by OH_AudioStreamBuilder_Create().
 * @param callback Callback used to handle the device change events.
 * @param userData Pointer to user-defined data, which will be passed back to the application in the callback.
 * @return Result code.
 *     {@link AUDIOSTREAM_SUCCESS} is returned if the operation is successful.
 *     {@link AUDIOSTREAM_ERROR_INVALID_PARAM} is returned if a parameter is invalid, for example, if builder
 * is nullptr.
 * @since 20
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerDeviceChangeCallback(OH_AudioStreamBuilder* builder,
    OH_AudioCapturer_OnDeviceChangeCallback callback, void* userData);

/**
 * @brief Sets a callback to handle interrupt events for an AudioCapturer instance.
 * This function is similar to {@link OH_AudioStreamBuilder_SetCapturerCallback}. If both
 * OH_AudioStreamBuilder_SetCapturerCallback and this function are called, the most recently set callback takes
 * effect.
 *
 * @param builder Builder instance, which is generated by OH_AudioStreamBuilder_Create().
 * @param callback Callback used to handle the interrupt events.
 * @param userData Pointer to user-defined data, which will be passed back to the application in the callback.
 * @return Result code.
 *     {@link AUDIOSTREAM_SUCCESS} is returned if the operation is successful.
 *     {@link AUDIOSTREAM_ERROR_INVALID_PARAM} is returned if a parameter is invalid, for example, if builder
 * is nullptr.
 * @since 20
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerInterruptCallback(OH_AudioStreamBuilder* builder,
    OH_AudioCapturer_OnInterruptCallback callback, void* userData);

/**
 * @brief Sets a callback to handle error events for an AudioCapturer instance. This function is similar to
 * {@link OH_AudioStreamBuilder_SetCapturerCallback}. If both OH_AudioStreamBuilder_SetCapturerCallback and this
 * function are called, the most recently set callback takes effect.
 *
 * @param builder Builder instance, which is generated by OH_AudioStreamBuilder_Create().
 * @param callback Callback used to handle the error events.
 * @param userData Pointer to user-defined data, which will be passed back to the application in the callback.
 * @return Result code.
 *     {@link AUDIOSTREAM_SUCCESS} is returned if the operation is successful.
 *     {@link AUDIOSTREAM_ERROR_INVALID_PARAM} is returned if a parameter is invalid, for example, if builder
 * is nullptr.
 * @since 20
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerErrorCallback(OH_AudioStreamBuilder* builder,
    OH_AudioCapturer_OnErrorCallback callback, void* userData);

/**
 * @brief Set audio capturer configuration, if app want its recorder only to be muted instead of interrupted.
 *
 * @param builder reference provided by OH_AudioStreamBuilder_Create()
 * @param muteWhenInterrupted use {@code true} if application want to be muted instead of interrupted.
 * @return function result code:
 *     {@link AUDIOSTREAM_SUCCESS} if the execution is successful.
 *     {@link AUDIOSTREAM_ERROR_INVALID_PARAM} the param of builder is nullptr.
 * @since 20
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerWillMuteWhenInterrupted(OH_AudioStreamBuilder* builder,
    bool muteWhenInterrupted);

/**
 * @brief Set the callback of fast status change event for audio renderer.
 *
 * @param builder Builder provided by OH_AudioStreamBuilder_Create()
 * @param callback Callback function that will recevie the fast status change event.
 * @param userData Pointer to an application data structure that will be passed to the callback functions.
 * @return
 *     {@link AUDIOSTREAM_SUCCESS} if the execution is successful.
 *     {@link AUDIOSTREAM_ERROR_INVALID_PARAM} the param of builder or callback is nullptr.
 * @since 20
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererFastStatusChangeCallback(OH_AudioStreamBuilder* builder,
    OH_AudioRenderer_OnFastStatusChange callback, void* userData);

/**
 * @brief Set the callback of fast status change event for audio capturer.
 *
 * @param builder Builder provided by OH_AudioStreamBuilder_Create()
 * @param callback Callback function that will recevie the fast status change event.
 * @param userData Pointer to an application data structure that will be passed to the callback functions.
 * @return
 *     {@link AUDIOSTREAM_SUCCESS} if the execution is successful.
 *     {@link AUDIOSTREAM_ERROR_INVALID_PARAM} the param of builder or callback is nullptr.
 * @since 20
 */
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerFastStatusChangeCallback(OH_AudioStreamBuilder* builder,
    OH_AudioCapturer_OnFastStatusChange callback, void* userData);


#ifdef __cplusplus
}
#endif

#endif // NATIVE_AUDIOSTREAM_BUILDER_H
/** @} */