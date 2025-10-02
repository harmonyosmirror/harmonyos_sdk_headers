/*
 * Copyright (C) 2024 Huawei Device Co., Ltd.
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
 * @addtogroup AVRecorder
 * @{
 *
 * @brief Provides APIs of request capability for Recorder.
 *
 * @syscap SystemCapability.Multimedia.Media.AVRecorder
 * @since 18
 * @}
 */

 /**
 * @file avrecorder.h
 *
 * @brief Defines the avrecorder APIs. Uses the Native APIs provided by Media AVRecorder
 *        to record media data.
 *
 * @kit MediaKit
 * @library libavrecorder.so
 * @syscap SystemCapability.Multimedia.Media.AVRecorder
 * @since 18
 */

#ifndef MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVRECORDER_H
#define MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVRECORDER_H

#include <memory>
#include <stdint.h>
#include <stdio.h>
#include "avrecorder_base.h"
#include "native_averrors.h"
#include "native_window/external_window.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Create a recorder
 * @syscap SystemCapability.Multimedia.Media.AVRecorder
 * @return Returns a pointer to an OH_AVRecorder instance for success, nullptr for failure
 * @since 18
*/
OH_AVRecorder *OH_AVRecorder_Create(void);

/**
 * @brief Prepare for recording with some parameters.
 * @syscap SystemCapability.Multimedia.Media.AVRecorder
 * @param recorder Pointer to an OH_AVRecorder instance
 * @param config Pointer to an OH_AVRecorder_Config instance, see {@link OH_AVRecorder_Config}
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input recorder is nullptr or recorder Prepare failed.
 * @since 18
 */
OH_AVErrCode OH_AVRecorder_Prepare(OH_AVRecorder *recorder, OH_AVRecorder_Config *config);

/**
 * @brief Get current recording parameters, it must be called after prepare.
 * @syscap SystemCapability.Multimedia.Media.AVRecorder
 * @param recorder Pointer to an OH_AVRecorder instance
 * @param config Pointer to an OH_AVRecorder_Config instance, see {@link OH_AVRecorder_Config}
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input recorder is nullptr or config is null.
 *         {@link AV_ERR_NO_MEMORY} failed to malloc memory.
 * @since 18
 */
OH_AVErrCode OH_AVRecorder_GetAVRecorderConfig(OH_AVRecorder *recorder, OH_AVRecorder_Config **config);

/**
 * @brief Get input surface, it must be called between prepare completed and start.
 * @syscap SystemCapability.Multimedia.Media.AVRecorder
 * @param recorder Pointer to an OH_AVRecorder instance
 * @param window Pointer to an OHNativeWindow instance, see {@link OHNativeWindow}
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input recorder is nullptr.
 * @since 18
 */
OH_AVErrCode OH_AVRecorder_GetInputSurface(OH_AVRecorder *recorder, OHNativeWindow **window);

/**
 * @brief Update the video orientation before recorder start.
 * @syscap SystemCapability.Multimedia.Media.AVRecorder
 * @param recorder Pointer to an OH_AVRecorder instance
 * @param rotation angle, should be [0, 90, 180, 270]
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input recorder is nullptr or update rotation failed.
 * @since 18
 */
OH_AVErrCode OH_AVRecorder_UpdateRotation(OH_AVRecorder *recorder, int32_t rotation);

/**
 * @brief Start AVRecorder.
 * @syscap SystemCapability.Multimedia.Media.AVRecorder
 * @param recorder Pointer to an OH_AVRecorder instance
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input recorder is nullptr or recorder start failed.
 * @since 18
 */
OH_AVErrCode OH_AVRecorder_Start(OH_AVRecorder *recorder);

/**
 * @brief Pause AVRecorder.
 * @syscap SystemCapability.Multimedia.Media.AVRecorder
 * @param recorder Pointer to an OH_AVRecorder instance
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input recorder is nullptr or recorder pause failed.
 * @since 18
 */
OH_AVErrCode OH_AVRecorder_Pause(OH_AVRecorder *recorder);

/**
 * @brief Resume AVRecorder.
 * @syscap SystemCapability.Multimedia.Media.AVRecorder
 * @param recorder Pointer to an OH_AVRecorder instance
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input recorder is nullptr or recorder resume failed.
 * @since 18
 */
OH_AVErrCode OH_AVRecorder_Resume(OH_AVRecorder *recorder);

/**
 * @brief Stop AVRecorder.
 * @syscap SystemCapability.Multimedia.Media.AVRecorder
 * @param recorder Pointer to an OH_AVRecorder instance
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input recorder is nullptr or recorder stop failed.
 * @since 18
 */
OH_AVErrCode OH_AVRecorder_Stop(OH_AVRecorder *recorder);

/**
 * @brief Reset AVRecorder.
 * @syscap SystemCapability.Multimedia.Media.AVRecorder
 * @param recorder Pointer to an OH_AVRecorder instance
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input recorder is nullptr or recorder reset failed.
 * @since 18
 */
OH_AVErrCode OH_AVRecorder_Reset(OH_AVRecorder *recorder);

/**
 * @brief Release AVRecorder.
 * @syscap SystemCapability.Multimedia.Media.AVRecorder
 * @param recorder Pointer to an OH_AVRecorder instance
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input recorder is nullptr or recorder release failed.
 * @since 18
 */
OH_AVErrCode OH_AVRecorder_Release(OH_AVRecorder *recorder);

/**
 * @brief Get available encoder and encoder info for AVRecorder.
 * @syscap SystemCapability.Multimedia.Media.AVRecorder
 * @param recorder Pointer to an OH_AVRecorder instance
 * @param info Pointer to an OH_AVRecorder_EncoderInfo instance, see {@link OH_AVRecorder_EncoderInfo}
 * @param length Length of available encoders
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input recorder is nullptr.
 *         {@link AV_ERR_NO_MEMORY} failed to malloc memory.
 * @since 18
 */
OH_AVErrCode OH_AVRecorder_GetAvailableEncoder(OH_AVRecorder *recorder, OH_AVRecorder_EncoderInfo **info,
    int32_t *length);

/**
 * @brief Set the state callback function so that your application can respond to the
 * state change events generated by the av recorder. This interface must be called before Start is called.
 * @syscap SystemCapability.Multimedia.Media.AVRecorder
 * @param recorder Pointer to an OH_AVRecorder instance
 * @param callback State callback function, see {@link OH_AVRecorder_OnStateChange}
 * @param userData Pointer to user specific data
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input recorder is nullptr or input callback is nullptr.
 * @since 18
 */
OH_AVErrCode OH_AVRecorder_SetStateCallback(
    OH_AVRecorder *recorder, OH_AVRecorder_OnStateChange callback, void *userData);

/**
 * @brief Set the error callback function so that your application can respond to the
 * error events generated by the av recorder. This interface must be called before Start is called.
 * @syscap SystemCapability.Multimedia.Media.AVRecorder
 * @param recorder Pointer to an OH_AVRecorder instance
 * @param callback Error callback function, see {@link OH_AVRecorder_OnError}
 * @param userData Pointer to user specific data
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input recorder is nullptr or input callback is nullptr.
 * @since 18
 */
OH_AVErrCode OH_AVRecorder_SetErrorCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnError callback, void *userData);

/**
 * @brief Set the URI callback function so that your application can respond to the
 * URI events generated by the av recorder. This interface must be called before Start is called.
 * @syscap SystemCapability.Multimedia.Media.AVRecorder
 * @param recorder Pointer to an OH_AVRecorder instance
 * @param callback Uri callback function, see {@link OH_AVRecorder_OnUri}
 * @param userData Pointer to user specific data
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input recorder is nullptr or input callback is nullptr.
 * @since 18
 */
OH_AVErrCode OH_AVRecorder_SetUriCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnUri callback, void *userData);

#ifdef __cplusplus
}
#endif

#endif // MULTIMEDIA_PLAYER_FRAMEWORK_NATIVE_AVRECORDER_H
