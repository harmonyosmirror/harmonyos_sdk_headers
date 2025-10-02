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
 * @brief The LowPowerAudioSink sub module provides variables, properties, and functions
 * for lowpower audio sink.
 *
 * @since 20
 */

/**
 * @file lowpower_audio_sink.h
 *
 * @brief Declare the Native API used for lowpower audio sink.
 *
 * @library liblowpower_avsink.so
 * @kit MediaKit
 * @syscap SystemCapability.Multimedia.Media.LowPowerAVSink
 * @since 20
 */

#ifndef NATIVE_LOWPOWER_AUDIO_SINK_H
#define NATIVE_LOWPOWER_AUDIO_SINK_H

#include <stdint.h>
#include <stdio.h>
#include "native_averrors.h"
#include "native_avformat.h"
#include "lowpower_audio_sink_base.h"
#include "ohaudio/native_audiostream_base.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Creates a lowpower audio sink instance from the mime type, which is recommended in most cases.
 *
 * @param {const char*} mime mime type description string, refer to {@link AVCODEC_MIME_TYPE}
 * @return Returns a Pointer to an LowPowerAudioSink instance.
 * Return nullptr if memory ran out or the mime type is not supported.
 * @since 20
 */
OH_LowPowerAudioSink* OH_LowPowerAudioSink_CreateByMime(const char* mime);

/**
 * @brief To configure the lowpower audio sink, typically, you need to configure the description information of the
 * decoded audio track, which can be extracted from the OH_AVSource. This interface must be called before Prepare
 * is called.
 *
 * @param {OH_LowPowerAudioSink*} sink Pointer to an OH_LowPowerAudioSinkinstance
 * @param {OH_AVFormat*} format A pointer to an OH_AVFormat to give the description of the audio track to be decoded
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_UNSUPPORT} unsupported format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSink_Configure(OH_LowPowerAudioSink* sink, const OH_AVFormat* format);

/**
 * @brief Set dynamic parameters to the lowpower audio sink.
 * Note: This interface can only be called after the decoder is started.
 * At the same time, incorrect parameter settings may cause audio sink failure.
 *
 * @param {OH_LowPowerAudioSink*} sink Pointer to an OH_LowPowerAudioSink instance
 * @param {OH_AVFormat*} format pointer to an OH_AVFormat instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_UNSUPPORT} unsupported format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSink_SetParameter(OH_LowPowerAudioSink* sink, const OH_AVFormat* format);

/**
 * @brief Get parameter of current lowpower audio sink.
 *
 * @param {OH_LowPowerAudioSink*} sink Pointer to an OH_LowPowerAudioSink instance
 * @param {OH_AVFormat*} format pointer to an OH_AVFormat instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSink_GetParameter(OH_LowPowerAudioSink* sink, OH_AVFormat* format);

/**
 * @brief To prepare the internal resources of the lowpower audio sink, the Configure interface must be called before
 * calling this interface.
 *
 * @param {OH_LowPowerAudioSink*} sink Pointer to an OH_LowPowerAudioSink instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_UNSUPPORT} unsupported format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSink_Prepare(OH_LowPowerAudioSink* sink);

/**
 * @brief Start the lowpower audio sink, this interface must be called after the Prepare is successful.
 * After being successfully started, the lowpower audio sink will start reporting DataNeeded events.
 *
 * @param {OH_LowPowerAudioSink*} sink Pointer to an OH_LowPowerAudioSink instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_UNSUPPORT} unsupported format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSink_Start(OH_LowPowerAudioSink* sink);

/**
 * @brief Pause the lowpower audio sink, this interface must be called after the Start or Resume is successful.
 * After being successfully paused, the lowpower audio sink will pause reporting DataNeeded events..
 *
 * @param {OH_LowPowerAudioSink*} sink Pointer to an OH_LowPowerAudioSink instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSink_Pause(OH_LowPowerAudioSink* sink);

/**
 * @brief Resume the lowpower audio sink, this interface must be called after the Pause is successful.
 * After being successfully resumed, the lowpower audio sink will resume reporting DataNeeded events.
 *
 * @param {OH_LowPowerAudioSink*} sink Pointer to an OH_LowPowerAudioSink instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSink_Resume(OH_LowPowerAudioSink* sink);

/**
 * @brief Clear cache data in the lowpower audio sink, this interface is suggested to not be called after the Start
 * or Resume. It should be noted that need to re-enter if the codec has been input before Codec-Specific-Data.
 *
 * @param {OH_LowPowerAudioSink*} sink Pointer to an OH_LowPowerAudioSink instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSink_Flush(OH_LowPowerAudioSink* sink);

/**
 * @brief Stop the lowpower audio sink.
 *
 * @param {OH_LowPowerAudioSink*} sink Pointer to an OH_LowPowerAudioSink instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSink_Stop(OH_LowPowerAudioSink* sink);

/**
 * @brief Reset the lowpower audio sink. Too reuse this instance, you need to call the Configure.
 *
 * @param {OH_LowPowerAudioSink*} sink Pointer to an OH_LowPowerAudioSink instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSink_Reset(OH_LowPowerAudioSink* sink);

/**
 * @brief Clear the internal resources of the lowpower audio sink and destroy the lowpower audio sink instance.
 *
 * @param {OH_LowPowerAudioSink*} sink Pointer to an OH_LowPowerAudioSink instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSink_Destroy(OH_LowPowerAudioSink* sink);

/**
 * @brief Set volume of current lowpower audio sink.
 *
 * @param {OH_LowPowerAudioSink*} sink Pointer to an OH_LowPowerAudioSink instance
 * @param {const float} volume Volume to set which changes from 0.0 to 1.0
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSink_SetVolume(OH_LowPowerAudioSink* sink, const float volume);

/**
 * @brief Set playback speed for the lowpower audio sink.
 *
 * @param {OH_LowPowerAudioSink*} sink Pointer to an OH_LowPowerAudioSink instance
 * @param {const float} speed The playback speed value needs to be specified, the valid value is 0.1-4.0
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSink_SetPlaybackSpeed(OH_LowPowerAudioSink* sink, const float speed);

/**
 * @brief Return frame packet buffer to lowpower audio sink.
 *
 * @param {OH_LowPowerAudioSink*} sink Pointer to an OH_LowPowerAudioSink instance
 * @param {OH_AVSamplesBuffer*} samples Pointer to an OH_AVSamplesBuffer instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSink_ReturnSamples(OH_LowPowerAudioSink* sink, OH_AVSamplesBuffer* samples);

/**
 * @brief Regsister callback instance for lowpower audio sink.
 *
 * @param {OH_LowPowerAudioSink*} sink Pointer to an OH_LowPowerAudioSink instance
 * @param {OH_LowPowerAudioSinkCallback*} callback Pointer to an OH_LowPowerAudioSinkCallback instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSink_RegisterCallback(OH_LowPowerAudioSink* sink, OH_LowPowerAudioSinkCallback* callback);

/**
 * @brief Creates a lowpower audio sink callback instance.
 *
 * @return Returns a Pointer to an OH_LowPowerAudioSinkCallback instance.
 * Return nullptr if memory ran out.
 * @since 20
 */
OH_LowPowerAudioSinkCallback* OH_LowPowerAudioSinkCallback_Create(void);

/**
 * @brief Destroy the lowpower audio sink callback instance.
 *
 * @param {OH_LowPowerAudioSinkCallback*} callback Pointer to an OH_LowPowerAudioSinkCallback instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the callback is nullptr or invalid.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSinkCallback_Destroy(OH_LowPowerAudioSinkCallback* callback);

/**
 * @brief Add onPositionUpdated listener to the lowpower audio sink callback instance.
 *
 * @param {OH_LowPowerAudioSinkCallback*} callback Pointer to an OH_LowPowerAudioSinkCallback instance
 * @param {OH_LowPowerAudioSink_OnPositionUpdated} onPositionUpdated OH_LowPowerAudioSink_OnPositionUpdated function,
 * refer to {@link OH_LowPowerAudioSink_OnPositionUpdated}
 * @param userData User specific data
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the callback is nullptr or invalid.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSinkCallback_SetPositionUpdateListener(
    OH_LowPowerAudioSinkCallback* callback,
    OH_LowPowerAudioSink_OnPositionUpdated onPositionUpdated,
    void* userData);

/**
 * @brief Add onDataNeeded listener to the lowpower audio sink callback instance.
 *
 * @param {OH_LowPowerAudioSinkCallback*} callback Pointer to an OH_LowPowerAudioSinkCallback instance
 * @param {OH_LowPowerAudioSink_OnDataNeeded} onDataNeeded OH_LowPowerAudioSink_OnDataNeeded function,
 * refer to {@link OH_LowPowerAudioSink_OnDataNeeded}
 * @param {void*} userData User specific data
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the callback is nullptr or invalid.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSinkCallback_SetDataNeededListener(
    OH_LowPowerAudioSinkCallback* callback,
    OH_LowPowerAudioSink_OnDataNeeded onDataNeeded,
    void* userData);

/**
 * @brief Add onError listener to the lowpower audio sink callback instance.
 *
 * @param {OH_LowPowerAudioSinkCallback*} callback Pointer to an OH_LowPowerAudioSinkCallback instance
 * @param {OH_LowPowerAudioSink_OnError} onError OH_LowPowerAudioSink_OnError function,
 * refer to {@link OH_LowPowerAudioSink_OnError}
 * @param {void*} userData User specific data
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the callback is nullptr or invalid.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSinkCallback_SetErrorListener(
    OH_LowPowerAudioSinkCallback* callback,
    OH_LowPowerAudioSink_OnError onError,
    void* userData);

/**
 * @brief Add onInterrupted listener to the lowpower audio sink callback instance.
 *
 * @param {OH_LowPowerAudioSinkCallback*} callback Pointer to an OH_LowPowerAudioSinkCallback instance
 * @param {OH_LowPowerAudioSink_OnInterrupted} onInterrupted OH_LowPowerAudioSink_OnInterrupted function,
 * refer to {@link OH_LowPowerAudioSink_OnInterrupted}
 * @param {void*} userData User specific data
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the callback is nullptr or invalid.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSinkCallback_SetInterruptListener(
    OH_LowPowerAudioSinkCallback* callback,
    OH_LowPowerAudioSink_OnInterrupted onInterrupted,
    void* userData);

/**
 * @brief Add onDeviceChanged listener to the lowpower audio sink callback instance.
 *
 * @param {OH_LowPowerAudioSinkCallback*} callback Pointer to an OH_LowPowerAudioSink Callback instance
 * @param {OH_LowPowerAudioSink_OnDeviceChanged} onDeviceChanged OH_LowPowerAudioSink_OnDeviceChanged function,
 * refer to {@link OH_LowPowerAudioSink_OnDeviceChanged}
 * @param {void*} userData User specific data
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the callback is nullptr or invalid.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSinkCallback_SetDeviceChangeListener(
    OH_LowPowerAudioSinkCallback* callback,
    OH_LowPowerAudioSink_OnDeviceChanged onDeviceChanged,
    void* userData);

/**
 * @brief Add onEos listener to the lowpower audio sink callback instance.
 *
 * @param {OH_LowPowerAudioSinkCallback*} callback Pointer to an OH_LowPowerAudioSinkCallback instance
 * @param {OH_LowPowerAudioSink_OnEos} onEos OH_LowPowerAudioSink_OnEos function,
 * refer to {@link OH_LowPowerAudioSink_OnEos}
 * @param {void*} userData User specific data
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the callback is nullptr or invalid.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerAudioSinkCallback_SetEosListener(
    OH_LowPowerAudioSinkCallback *callback,
    OH_LowPowerAudioSink_OnEos onEos,
    void* userData);

#ifdef __cplusplus
}
#endif

#endif // NATIVE_LOWPOWER_AUDIO_SINK_H

/** @} */