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
 * @addtogroup LowPowerVideoSink
 * @{
 *
 * @brief The LowPowerVideoSink sub module provides variables, properties, and functions
 * for lowpower video sink.
 *
 * @since 20
 */

/**
 * @file lowpower_video_sink.h
 *
 * @brief Declare the Native API used for lowpower video sink.
 *
 * @library liblowpower_avsink.so
 * @kit MediaKit
 * @syscap SystemCapability.Multimedia.Media.LowPowerAVSink
 * @since 20
 */

#ifndef NATIVE_LOWPOWER_VIDEO_SINK_H
#define NATIVE_LOWPOWER_VIDEO_SINK_H

#include <stdint.h>
#include "native_averrors.h"
#include "native_avformat.h"
#include "lowpower_avsink_base.h"
#include "lowpower_video_sink_base.h"
#include "lowpower_audio_sink_base.h"
#include "native_window/external_window.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Creates a lowpower video sink instance from the mime type, which is recommended in most cases.
 *
 * @param {const char*} mime mime type description string, refer to {@link AVCODEC_MIME_TYPE}
 * @return Returns a Pointer to an OH_LowPowerVideoSink instance.
 * Return nullptr if memory ran out or the mime type is not supported.
 * @since 20
 */
OH_LowPowerVideoSink* OH_LowPowerVideoSink_CreateByMime(const char* mime);

/**
 * @brief To configure the lowpower video sink, typically, you need to configure the description information of the
 * decoded video track, which can be extracted from the OH_AVSource. This interface must be called before Prepare
 * is called.
 *
 * @param {OH_LowPowerVideoSink*} sink Pointer to an OH_LowPowerVideoSink instance
 * @param {OH_AVFormat*} format A pointer to an OH_AVFormat to give the description of the video track to be decoded,
 * key of format refer to lowpower_avsink_base.h
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_UNSUPPORT} unsupported format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSink_Configure(OH_LowPowerVideoSink* sink, const OH_AVFormat* format);

/**
 * @brief Set dynamic parameters to the lowpower video sink.
 * Note: This interface can only be called after the decoder is started.
 * At the same time, incorrect parameter settings may cause video sink failure.
 *
 * @param {OH_LowPowerVideoSink*} sink Pointer to an OH_LowPowerVideoSink instance
 * @param {OH_AVFormat*} format pointer to an OH_AVFormat instance, key of format refer to lowpower_avsink_base.h
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_UNSUPPORT} unsupported format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSink_SetParameter(OH_LowPowerVideoSink* sink, const OH_AVFormat* format);

/**
 * @brief Get parameter of current lowpower video sink.
 *
 * @param {OH_LowPowerVideoSink*} sink Pointer to an OH_LowPowerVideoSink instance
 * @param {OH_AVFormat*} format pointer to an OH_AVFormat instance, key of format refer to lowpower_avsink_base.h
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSink_GetParameter(OH_LowPowerVideoSink* sink, OH_AVFormat* format);

/**
 * @brief Specify the output Surface to provide decoded lowpower video sink,
 * this interface must be called before Prepare is called. In the executing state, it can be called directly.
 *
 * @param {OH_LowPowerVideoSink*} sink Pointer to an OH_LowPowerVideoSink instance
 * @param {OHNativeWindow*} surface A pointer to a OHNativeWindow instance, see {@link OHNativeWindow}
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSink_SetVideoSurface(OH_LowPowerVideoSink* sink, const OHNativeWindow* surface);

/**
 * @brief To prepare the internal resources of the lowpower video sink, the Configure interface must be called before
 * calling this interface.
 *
 * @param {OH_LowPowerVideoSink*} sink Pointer to an OH_LowPowerVideoSink instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_UNSUPPORT} unsupported format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSink_Prepare(OH_LowPowerVideoSink* sink);

/**
 * @brief Start decoder of the lowpower video sink, this interface must be called after the Prepare is successful.
 * After being successfully started, the lowpower audio sink will start reporting DataNeeded events.
 *
 * @param {OH_LowPowerVideoSink*} sink Pointer to an OH_LowPowerVideoSink instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_UNSUPPORT} unsupported format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSink_StartDecoder(OH_LowPowerVideoSink* sink);

/**
 * @brief Render first frame of video sink, this interface must be called after the StartDecode is successful and
 * onFirstFrameDecoded is called.
 *
 * @param {OH_LowPowerVideoSink*} sink Pointer to an OH_LowPowerVideoSink instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSink_RenderFirstFrame(OH_LowPowerVideoSink* sink);

/**
 * @brief Start renderer of the lowpower video sink, this interface must be called after the StartDecode is successful.
 *
 * @param {OH_LowPowerVideoSink*} sink Pointer to an OH_LowPowerVideoSink instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_UNSUPPORT} unsupported format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSink_StartRenderer(OH_LowPowerVideoSink* sink);

/**
 * @brief Pause the lowpower video sink, this interface must be called after the StartRender or Resume is successful.
 * After being successfully paused, the lowpower video sink will pause reporting DataNeeded events..
 *
 * @param {OH_LowPowerVideoSink*} sink Pointer to an OH_LowPowerVideoSink instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSink_Pause(OH_LowPowerVideoSink* sink);

/**
 * @brief Resume the lowpower video sink, this interface must be called after the Pause is successful.
 * After being successfully resumed, the lowpower video sink will resume reporting DataNeeded events.
 *
 * @param {OH_LowPowerVideoSink*} sink Pointer to an OH_LowPowerVideoSinkinstance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSink_Resume(OH_LowPowerVideoSink* sink);

/**
 * @brief Clear cache data in the lowpower video sink, this interface is suggested to not be called after the Start
 * or Resume. It should be noted that need to re-enter if the codec has been input before Codec-Specific-Data.
 *
 * @param {OH_LowPowerVideoSink*} sink Pointer to an OH_LowPowerVideoSink instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSink_Flush(OH_LowPowerVideoSink* sink);

/**
 * @brief Stop the lowpower video sink.
 *
 * @param {OH_LowPowerVideoSink*} sink Pointer to an OH_LowPowerVideoSink instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSink_Stop(OH_LowPowerVideoSink* sink);

/**
 * @brief Reset the lowpower video sink. Too reuse this instance, you need to call the Configure.
 *
 * @param {OH_LowPowerVideoSink*} sink Pointer to an OH_LowPowerVideoSink instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSink_Reset(OH_LowPowerVideoSink* sink);

/**
 * @brief Clear the internal resources of the lowpower video sink and destroy the lowpower video sink instance.
 *
 * @param {OH_LowPowerVideoSink*} sink Pointer to an OH_LowPowerVideoSink instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSink_Destroy(OH_LowPowerVideoSink* sink);

/**
 * @brief Set the lowpower audio sink instance to the lowpower video sink instance for audio video sync.
 *
 * @param {OH_LowPowerVideoSink*} videoSink Pointer to an OH_LowPowerVideoSink instance
 * @param {OH_LowPowerAudioSink*} audioSink Pointer to an OH_LowPowerAudioSink instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSink_SetSyncAudioSink(
    OH_LowPowerVideoSink* videoSink, OH_LowPowerAudioSink* audioSink);

/**
 * @brief Set target start frame pts, and the video frame will be renderred from the target pts.
 *
 * @param {OH_LowPowerVideoSink*} sink Pointer to an OH_LowPowerVideoSink instance
 * @param {const int64_t} framePts target video frame pts
 * @param {OH_LowPowerVideoSink_OnTargetArrived*} onTargetArrived OH_LowPowerVideoSink_OnTargetArrived func,
 * will be called once, refer to {@link OH_LowPowerVideoSink_OnTargetArrived}
 * @param {const int64_t} timeoutMs if wait first frame over timeoutMs, onTargetArrived will be called directly.
 * @param {void *} userData User specific data
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSink_SetTargetStartFrame(
    OH_LowPowerVideoSink* sink,
    const int64_t framePts,
    OH_LowPowerVideoSink_OnTargetArrived onTargetArrived,
    const int64_t timeoutMs,
    void* userData);

/**
 * @brief Set playback speed for the lowpower video sink
 * @param {OH_LowPowerVideoSink*} sink Pointer to an OH_LowPowerVideoSink instance
 * @param {const float} speed Indicates the value of the playback rate.
 * The current version is valid in the range of 0.1-4.0
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSink_SetPlaybackSpeed(OH_LowPowerVideoSink* sink, const float speed);

/**
 * @brief Return frame packet buffer to lowpower video sink.
 *
 * @param {OH_LowPowerVideoSink*} sink Pointer to an OH_LowPowerVideoSink instance
 * @param {OH_AVSamplesBuffer*} samples Pointer to an OH_AVSamplesBuffer instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSink_ReturnSamples(OH_LowPowerVideoSink* sink, OH_AVSamplesBuffer* samples);

/**
 * @brief Regsister callback instance for lowpower video sink.
 *
 * @param {OH_LowPowerVideoSink*} sink Pointer to an OH_LowPowerVideoSink instance
 * @param {OH_LowPowerVideoSinkCallback*} callback Pointer to an OH_LowPowerVideoSinkCallback instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the sink or format is nullptr or invalid. Invalid param in format.
 * {@link AV_ERR_SERVICE_DIED} media service is died.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSink_RegisterCallback(OH_LowPowerVideoSink* sink, OH_LowPowerVideoSinkCallback* callback);

/**
 * @brief Creates a lowpower video sink callback instance.
 *
 * @return Returns a Pointer to an OH_LowPowerVideoSinkCallback instance.
 * Return nullptr if memory ran out.
 * @since 20
 */
OH_LowPowerVideoSinkCallback* OH_LowPowerVideoSinkCallback_Create(void);

/**
 * @brief Destroy the lowpower video sink callback instance.
 *
 * @param {OH_LowPowerVideoSinkCallback*} callback Pointer to an OH_LowPowerVideoSinkCallback instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the callback is nullptr or invalid.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSinkCallback_Destroy(OH_LowPowerVideoSinkCallback* callback);

/**
 * @brief Add onDataNeeded listener to the lowpower video sink callback instance.
 *
 * @param {OH_LowPowerVideoSinkCallback*} callback Pointer to an OH_LowPowerVideoSinkCallback instance
 * @param {OH_LowPowerVideoSink_OnDataNeeded} onDataNeeded OH_LowPowerVideoSink_OnDataNeeded function,
 * refer to {@link OH_LowPowerVideoSink_OnDataNeeded}
 * @param {void*} userData User specific data
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the callback is nullptr or invalid.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSinkCallback_SetDataNeededListener(
    OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnDataNeeded onDataNeeded,void* userData);

/**
 * @brief Add onError listener to the lowpower video sink callback instance.
 *
 * @param {OH_LowPowerVideoSinkCallback*} callback Pointer to an OH_LowPowerVideoSinkCallback instance
 * @param {OH_LowPowerVideoSink_OnError} onError OH_LowPowerVideoSink_OnError function,
 * refer to {@link OH_LowPowerVideoSink_OnError}
 * @param {void*} userData User specific data
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the callback is nullptr or invalid.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSinkCallback_SetErrorListener(
    OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnError onError, void* userData);

/**
 * @brief Add onRenderStarted listener to the lowpower video sink callback instance.
 *
 * @param {OH_LowPowerVideoSinkCallback*} callback Pointer to an OH_LowPowerVideoSinkCallback instance
 * @param {OH_LowPowerVideoSink_OnRenderStarted} onRenderStarted OH_LowPowerVideoSink_OnRenderStarted function,
 * refer to {@link OH_LowPowerVideoSink_OnRenderStarted}
 * @param {void*} userData User specific data
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the callback is nullptr or invalid.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSinkCallback_SetRenderStartListener(
    OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnRenderStarted onRenderStarted, void* userData);

/**
 * @brief Add onStreamChanged listener to the lowpower video sink callback instance.
 *
 * @param {OH_LowPowerVideoSinkCallback*} callback Pointer to an OH_LowPowerVideoSinkCallback instance
 * @param {OH_LowPowerVideoSink_OnStreamChanged} onStreamChanged OH_LowPowerVideoSink_OnStreamChanged function,
 * refer to {@link OH_LowPowerVideoSink_OnStreamChanged}
 * @param {void*} userData User specific data
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the callback is nullptr or invalid.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSinkCallback_SetStreamChangedListener(
    OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnStreamChanged onStreamChanged, void* userData);

/**
 * @brief Add onRenderStarted listener to the lowpower video sink callback instance.
 *
 * @param {OH_LowPowerVideoSinkCallback*} callback Pointer to an OH_LowPowerVideoSinkCallback instance
 * @param {OH_LowPowerVideoSink_OnFirstFrameDecoded} onFirstFrameDecoded OH_LowPowerVideoSink_OnFirstFrameDecoded
 * function,
 * refer to {@link OH_LowPowerVideoSink_OnFirstFrameDecoded}
 * @param {void*} userData User specific data
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the callback is nullptr or invalid.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSinkCallback_SetFirstFrameDecodedListener(
    OH_LowPowerVideoSinkCallback* callback,
    OH_LowPowerVideoSink_OnFirstFrameDecoded onFirstFrameDecoded,
    void* userData);

/**
 * @brief Add onEos listener to the lowpower video sink callback instance.
 *
 * @param {OH_LowPowerVideoSinkCallback*} callback Pointer to an OH_LowPowerVideoSinkCallback instance
 * @param {OH_LowPowerVideoSink_OnEos} onEos OH_LowPowerVideoSink_OnEos function,
 * refer to {@link OH_LowPowerVideoSink_OnEos}
 * @param {void*} userData User specific data
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * {@link AV_ERR_INVALID_VAL} the callback is nullptr or invalid.
 * {@link AV_ERR_OPERATE_NOT_PERMIT} operation not permitted.
 * @since 20
 */
OH_AVErrCode OH_LowPowerVideoSinkCallback_SetEosListener(OH_LowPowerVideoSinkCallback* callback,
    OH_LowPowerVideoSink_OnEos onEos, void* userData);

#ifdef __cplusplus
}
#endif

#endif // NATIVE_LOWPOWER_VIDEO_SINK_H

/** @} */