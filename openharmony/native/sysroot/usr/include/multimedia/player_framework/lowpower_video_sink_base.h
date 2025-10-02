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
 * @brief The LowPowerVideoSink submodule provides variables, properties, and functions
 * for lowpower video sink.
 *
 * @since 20
 */

/**
 * @file lowpower_video_sink_base.h
 *
 * @brief Declare the Native API used for lowpower video sink.
 *
 * @library liblowpower_avsink.so
 * @kit MediaKit
 * @syscap SystemCapability.Multimedia.Media.LowPowerAVSink
 * @since 20
 */

#ifndef NATIVE_LOWPOWER_VIDEO_SINK_BASE_H
#define NATIVE_LOWPOWER_VIDEO_SINK_BASE_H

#include <stdint.h>
#include <stdbool.h>
#include "native_avformat.h"
#include "lowpower_avsink_base.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Forward declaration of OH_LowPowerVideoSink.
 *
 * @since 20
 */
typedef struct OH_LowPowerVideoSink OH_LowPowerVideoSink;

/**
 * @brief Forward declaration of OH_LowPowerVideoSinkCallback.
 *
 * @since 20
 */
typedef struct OH_LowPowerVideoSinkCallback OH_LowPowerVideoSinkCallback;

/**
 * @brief When the OH_LowPowerVideoSink instance report to need data, the function pointer will be called
 * to request data.
 *
 * @param {OH_LowPowerVideoSink*} sink OH_LowPowerVideoSink instance
 * @param {OH_AVSamplesBuffer*} buffer OH_AVSamplesBuffer instance that will be written in
 * @param {void*} userData User specific data
 * @since 20
 */
typedef void (*OH_LowPowerVideoSink_OnDataNeeded)(
    OH_LowPowerVideoSink* sink,
    OH_AVSamplesBuffer* buffer,
    void *userData);

/**
 * @brief When an error occurs in the running of the OH_LowPowerVideoSink instance, the function pointer will be called
 * to report specific error information.
 *
 * @param {OH_LowPowerVideoSink*} sink OH_LowPowerVideoSink instance
 * @param {OH_AVErrCode} errorCode The error code returned when an error occurs during service operation.
 * See the definition of {@OH_AVErrCode}
 * @param {const char*} errorMsg string of Error description information returned when an error occurs
 * during service operation
 * @param {void*} userData User specific data
 * @since 20
 */
typedef void (*OH_LowPowerVideoSink_OnError)(
    OH_LowPowerVideoSink* sink,
    OH_AVErrCode errCode,
    const char* errMsg,
    void* userData);

/**
 * @brief When the OH_LowPowerVideoSink instance report target video frame arrived, the function pointer will be called.
 *
 * @param {OH_LowPowerVideoSink*} sink OH_LowPowerVideoSink instance
 * @param {const int64_t} targetPts Target pts of renderred frame
 * @param {const bool} isTimeout If wait target pts timeout, it is false
 * @param {void*} userData User specific data
 * @since 20
 */
typedef void (*OH_LowPowerVideoSink_OnTargetArrived)(
    OH_LowPowerVideoSink* sink,
    const int64_t targetPts,
    const bool isTimeout,
    void* userData);

/**
 * @brief When the OH_LowPowerVideoSink instance report first frame renderred, the function pointer will be called.
 *
 * @param {OH_LowPowerVideoSink*} sink OH_LowPowerVideoSink instance
 * @param {void*} userData User specific data
 * @since 20
 */
typedef void (*OH_LowPowerVideoSink_OnRenderStarted)(OH_LowPowerVideoSink* sink, void* userData);

/**
 * @brief When the OH_LowPowerVideoSink instance reports that the parameters of the video stream have changed,
 * the application is notified through this function
 *
 * @param {OH_LowPowerVideoSink*} sink OH_LowPowerVideoSink instance
 * @param {OH_AVFormat*} format Carrying changing parameters and corresponding values
 * @param {void*} userData User specific data
 * @since 20
 */
typedef void (*OH_LowPowerVideoSink_OnStreamChanged)(OH_LowPowerVideoSink* sink, OH_AVFormat* format, void* userData);

/**
 * @brief When the first frame of the OH_LowPowerVideoSink instance is decoded successfully, this function pointer will
 * be called.
 *
 * @param {OH_LowPowerVideoSink*} sink OH_LowPowerVideoSink instance
 * @param {void*} userData User specific data
 * @since 20
 */
typedef void (*OH_LowPowerVideoSink_OnFirstFrameDecoded)(OH_LowPowerVideoSink* sink, void* userData);

/**
 * @brief When the OH_LowPowerVideoSinkinstance play to end of stream, the function pointer will be called
 * to report play completed event.
 *
 * @param {OH_LowPowerVideoSink*} sink OH_LowPowerVideoSink instance
 * @param {void*} userData User specific data
 * @since 20
 */
typedef void (*OH_LowPowerVideoSink_OnEos)(OH_LowPowerVideoSink* sink, void* userData);

#ifdef __cplusplus
}
#endif
#endif // NATIVE_LOWPOWER_VIDEOSINK_BASH_H

/** @} */
