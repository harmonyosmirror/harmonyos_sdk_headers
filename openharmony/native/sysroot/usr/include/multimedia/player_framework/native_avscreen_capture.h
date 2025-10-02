/*
 * Copyright (C) 2023 Huawei Device Co., Ltd.
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
 * @addtogroup AVScreenCapture
 * @{
 *
 * @brief Provides APIs of request capability for Screen Capture.
 * @since 10
 */

/**
 * @file native_avscreen_capture.h
 *
 * @brief Declare screen capture related interfaces.
 *
 * @library libnative_avscreen_capture.so
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @kit MediaKit
 * @since 10
 */

#ifndef NATIVE_AVSCREEN_CAPTURE_H
#define NATIVE_AVSCREEN_CAPTURE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "native_avscreen_capture_errors.h"
#include "native_avscreen_capture_base.h"
#include "native_window/external_window.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Create a screen capture
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @return Returns a pointer to an OH_AVScreenCapture instance
 * @since 10
 * @version 1.0
 */
struct OH_AVScreenCapture *OH_AVScreenCapture_Create(void);

/**
 * @brief To init the screen capture, typically, you need to configure the description information of the audio
 * and video, which can be extracted from the container. This interface must be called before StartAVScreenCapture
 * called.
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param capture Pointer to an OH_AVScreenCapture instance
 * @param config Information describing the audio and video config
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted, init config failed.
 * @since 10
 * @version 1.0
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Init(struct OH_AVScreenCapture *capture,
    OH_AVScreenCaptureConfig config);

/**
 * @brief Start the av screen capture
 * @param {struct OH_AVScreenCapture*} capture Pointer to an OH_AVScreenCapture instance
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_UNSUPPORT} device doesn't support certain configurations. add since api20.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted, set privacy authority enabled
 *         failed or start ScreenCapture failed.
 * @since 10
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenCapture(struct OH_AVScreenCapture *capture);

/**
 * @brief Stop the av screen capture
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param capture Pointer to an OH_AVScreenCapture instance
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted, stop ScreenCapture failed.
 * @since 10
 * @version 1.0
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenCapture(struct OH_AVScreenCapture *capture);

/**
 * @brief Start av screen record use to start save screen record file.
 * @param {struct OH_AVScreenCapture*} capture Pointer to an OH_AVScreenCapture instance
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_UNSUPPORT} device doesn't support certain configurations. add since api20.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted, set privacy authority enabled
 *         failed or start ScreenRecording failed.
 * @since 10
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenRecording(struct OH_AVScreenCapture *capture);

/**
 * @brief Start av screen record use to stop save screen record file.
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param capture Pointer to an OH_AVScreenCapture instance
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted, stop ScreenRecording failed.
 * @since 10
 * @version 1.0
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenRecording(struct OH_AVScreenCapture *capture);

/**
 * @brief Acquire the audio buffer for the av screen capture
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param capture Pointer to an OH_AVScreenCapture instance
 * @param audiobuffer Information describing the audio buffer of the capture
 * @param type Information describing the audio source type
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr or input **audiobuffer is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_NO_MEMORY} no memory, audiobuffer allocate failed.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted, not permit for has set
 *         DataCallback or acquire AudioBuffer failed.
 * @since 10
 * @version 1.0
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_AcquireAudioBuffer(struct OH_AVScreenCapture *capture,
    OH_AudioBuffer **audiobuffer, OH_AudioCaptureSourceType type);

/**
 * @brief Acquire the video buffer for the av screen capture
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param capture Pointer to an OH_AVScreenCapture instance
 * @param fence A processing state of display buffer
 * @param timestamp Information about the video buffer
 * @param region Information about the video buffer
 * @return Returns a pointer to an OH_NativeBuffer instance
 * @since 10
 * @version 1.0
 */
OH_NativeBuffer* OH_AVScreenCapture_AcquireVideoBuffer(struct OH_AVScreenCapture *capture,
    int32_t *fence, int64_t *timestamp, struct OH_Rect *region);

/**
 * @brief Release the audio buffer for the av screen capture
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param capture Pointer to an OH_AVScreenCapture instance
 * @param type Information describing the audio source type
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted, not permit for has set
 *         DataCallback or Release AudioBuffer failed.
 * @since 10
 * @version 1.0
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseAudioBuffer(struct OH_AVScreenCapture *capture,
    OH_AudioCaptureSourceType type);

/**
 * @brief Release the video buffer for the av screen capture
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param capture Pointer to an OH_AVScreenCapture instance
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted, not permit for has set
 *         DataCallback or Release VideoBuffer failed.
 * @since 10
 * @version 1.0
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseVideoBuffer(struct OH_AVScreenCapture *capture);

/**
 * @brief Set the callback function so that your application
 * can respond to the events generated by the av screen capture. This interface must be called before Init is called.
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param capture Pointer to an OH_AVScreenCapture instance
 * @param callback A collection of all callback functions, see {@link OH_AVScreenCaptureCallback}
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr or input callback is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted, set callback failed.
 * @since 10
 * @version 1.0
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCallback(struct OH_AVScreenCapture *capture,
    struct OH_AVScreenCaptureCallback callback);

/**
 * @brief Release the av screen capture
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param capture Pointer to an OH_AVScreenCapture instance
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted, screen capture release failed.
 * @since 10
 * @version 1.0
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Release(struct OH_AVScreenCapture *capture);

/**
 * @brief Controls the switch of the microphone, which is turned on by default
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param capture Pointer to an OH_AVScreenCapture instance
 * @param isMicrophone The switch of the microphone
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted, set microphone enable failed.
 * @since 10
 * @version 1.0
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetMicrophoneEnabled(struct OH_AVScreenCapture *capture,
    bool isMicrophone);

/**
 * @brief Set the state callback function so that your application can respond to the
 * state change events generated by the av screen capture. This interface must be called before Start is called.
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param capture Pointer to an OH_AVScreenCapture instance
 * @param callback State callback function, see {@link OH_AVScreenCapture_OnStateChange}
 * @param userData Pointer to user specific data
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr or input callback is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_NO_MEMORY} no memory, mem allocate failed.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted, set StateCallback failed.
 * @since 12
 * @version 1.0
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetStateCallback(struct OH_AVScreenCapture *capture,
    OH_AVScreenCapture_OnStateChange callback, void *userData);

/**
 * @brief Set the data callback function so that your application can respond to the
 * data available events generated by the av screen capture. This interface must be called before Start is called.
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param capture Pointer to an OH_AVScreenCapture instance
 * @param callback Data callback function, see {@link OH_AVScreenCapture_OnBufferAvailable}
 * @param userData Pointer to user specific data
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr or input callback is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_NO_MEMORY} no memory, mem allocate failed.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted, set DataCallback failed.
 * @since 12
 * @version 1.0
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetDataCallback(struct OH_AVScreenCapture *capture,
    OH_AVScreenCapture_OnBufferAvailable callback, void *userData);

/**
 * @brief Set the error callback function so that your application can respond to the
 * error events generated by the av screen capture. This interface must be called before Start is called.
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param capture Pointer to an OH_AVScreenCapture instance
 * @param callback Error callback function, see {@link OH_AVScreenCapture_OnError}
 * @param userData Pointer to user specific data
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr or input callback is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_NO_MEMORY} no memory, mem allocate failed.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted, set ErrorCallback failed.
 * @since 12
 * @version 1.0
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetErrorCallback(struct OH_AVScreenCapture *capture,
    OH_AVScreenCapture_OnError callback, void *userData);

/**
 * @brief Start the av screen capture, video data provided by OHNativeWindow.
 * @param {struct OH_AVScreenCapture*} capture Pointer to an OH_AVScreenCapture instance.
 * @param {OHNativeWindow*} window Pointer to an OHNativeWindow instance.
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr or input window is nullptr or
 *         input windowSurface is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_UNSUPPORT} device doesn't support certain configurations. add since api20.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted, set privacy authority enabled
 *         failed or start ScreenCaptureWithSurface failed.
 * @since 12
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenCaptureWithSurface(struct OH_AVScreenCapture *capture,
    OHNativeWindow *window);

/**
 * @brief Set canvas rotation when capturing screen
 * @param {struct OH_AVScreenCapture*} capture Pointer to an OH_AVScreenCapture instance
 * @param {bool} canvasRotation whether to rotate the canvas
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_UNSUPPORT} device doesn't support current interface. add since api20.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted, set CanvasRotation failed.
 * @since 12
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCanvasRotation(struct OH_AVScreenCapture *capture,
    bool canvasRotation);

/**
 * @brief Create a screen capture content filter
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @return Returns a pointer to an OH_AVScreenCapture_ContentFilter instance
 * @since 12
 * @version 1.0
 */
struct OH_AVScreenCapture_ContentFilter *OH_AVScreenCapture_CreateContentFilter(void);

/**
 * @brief Release the screen capture content filter
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param filter Pointer to an OH_AVScreenCapture_ContentFilter instance
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input filter is nullptr.
 * @since 12
 * @version 1.0
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseContentFilter(struct OH_AVScreenCapture_ContentFilter *filter);

/**
 * @brief Add content to the screen capture content filter
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param filter Pointer to an OH_AVScreenCapture_ContentFilter instance
 * @param content content to be added
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input filter is nullptr or input content invalid.
 * @since 12
 * @version 1.0
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ContentFilter_AddAudioContent(
    struct OH_AVScreenCapture_ContentFilter *filter, OH_AVScreenCaptureFilterableAudioContent content);

/**
 * @brief Set content filter to screen capture
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param capture Pointer to an OH_AVScreenCapture instance
 * @param filter Pointer to an OH_AVScreenCapture_ContentFilter instance
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr or input filter is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_UNSUPPORT} not support, for STREAM, should call AudioCapturer interface to make
 *         effect when start, for CAPTURE FILE, should call Recorder interface to make effect when start.
 * @since 12
 * @version 1.0
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ExcludeContent(struct OH_AVScreenCapture *capture,
    struct OH_AVScreenCapture_ContentFilter *filter);

/**
 * @brief Add Window content to the screen capture content filter
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param filter Pointer to an OH_AVScreenCapture_ContentFilter instance
 * @param windowIDs Pointer to windowIDs to be added
 * @param windowCount length of windowID list
 * @return Returns AV_SCREEN_CAPTURE_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVSCREEN_CAPTURE_ErrCode}
 * @since 12
 * @version 1.0
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ContentFilter_AddWindowContent(
    struct OH_AVScreenCapture_ContentFilter *filter, int32_t *windowIDs, int32_t windowCount);

/**
 * @brief Resize the Resolution of the Screen
 * @param {struct OH_AVScreenCapture*} capture Pointer to an OH_AVScreenCapture instance
 * @param {int32_t} width Video frame width of avscreeencapture
 * @param {int32_t} height Video frame height of avscreeencapture
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_UNSUPPORT} device doesn't support current interface. add since api20.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted.
 * @since 12
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ResizeCanvas(struct OH_AVScreenCapture *capture,
    int32_t width, int32_t height);

/**
 * @brief skip some windows' privacy mode of current app during the screen recording
 * @param {struct OH_AVScreenCapture*} capture Pointer to an OH_AVScreenCapture instance
 * @param {int32_t*} windowIDs Pointer of windowID list
 * @param {int32_t} windowCount length of windowID list
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr or input windowIDs are not belong current
 *         app.
 *         {@link AV_SCREEN_CAPTURE_ERR_UNSUPPORT} device doesn't support current interface. add since api20.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted.
 * @since 12
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SkipPrivacyMode(struct OH_AVScreenCapture *capture,
    int32_t *windowIDs, int32_t windowCount);

/**
 * @brief set up the max number of video frame per second
 * @param {struct OH_AVScreenCapture*} capture Pointer to an OH_AVScreenCapture instance
 * @param {int32_t} frameRate max frame rate of video
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr or frameRate is not support.
 *         {@link AV_SCREEN_CAPTURE_ERR_UNSUPPORT} device doesn't support current interface. add since api20.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted.
 * @since 14
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetMaxVideoFrameRate(struct OH_AVScreenCapture *capture,
    int32_t frameRate);

/**
 * @brief determines whether the cursor is visible in the session
 * @param {struct OH_AVScreenCapture* } capture Pointer to an OH_AVScreenCapture instance
 * @param {bool} showCursor The switch of the cursor
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_UNSUPPORT} device doesn't support current interface. add since api20.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted, show cursor failed.
 * @since 15
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ShowCursor(struct OH_AVScreenCapture *capture,
    bool showCursor);

/**
 * @brief Set the display device selection callback function so that your application can respond to the
 * display device selected event generated by the av screen capture.
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param capture Pointer to an OH_AVScreenCapture instance
 * @param callback display device selection callback function, see {@link OH_AVScreenCapture_OnDisplaySelected}
 * @param userData Pointer to user specific data
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr or input callback is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_NO_MEMORY} no memory, mem allocate failed.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_STATE} This interface should be called before Start is called.
 * @since 15
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetDisplayCallback(struct OH_AVScreenCapture *capture,
    OH_AVScreenCapture_OnDisplaySelected callback, void *userData);

/**
 * @brief Create a screen capture Strategy object
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @return Returns a pointer to the screen capture strategy object, or null if failure
 * @since 20
 */
OH_AVScreenCapture_CaptureStrategy* OH_AVScreenCapture_CreateCaptureStrategy(void);

/**
 * @brief Release the screen capture Strategy object
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param {OH_AVScreenCapture_CaptureStrategy*} strategy Pointer to an OH_AVScreenCapture_CaptureStrategy instance
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input strategy is nullptr.
 * @since 20
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseCaptureStrategy(OH_AVScreenCapture_CaptureStrategy* strategy);

/**
 * @brief set the screen capture strategy for the specified screen capture
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param {OH_AVScreenCapture*} capture Pointer to an OH_AVScreenCapture which need to be setted.
 * @param {OH_AVScreenCapture_CaptureStrategy*} strategy Pointer to an OH_AVScreenCapture_CaptureStrategy which want to
 * set.
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} capture or strategyvalue is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_STATE} This interface should be called before Start is called.
 * @since 20
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCaptureStrategy(
    struct OH_AVScreenCapture *capture, OH_AVScreenCapture_CaptureStrategy *strategy);

/**
 * @brief Call Settings Policy value for whether to allow screen capture during cellular calls
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param {OH_AVScreenCapture_CaptureStrategy*} strategy Pointer to an OH_AVScreenCapture_CaptureStrategy instance
 * @param {bool} value The default value is false, which means that screen recording is not allowed during cellular
 * calls.
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} strategy value is nullptr.
 * @since 20
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StrategyForKeepCaptureDuringCall(
    OH_AVScreenCapture_CaptureStrategy *strategy, bool value);

/**
 * @brief Set the Capture Content Changed callback function so that your application can
 * customize event handler generated by the screen capture. This interface must be called before Start is called.
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param capture Pointer to an OH_AVScreenCapture instance
 * @param callback contentchanged callback function, see {@link OH_AVScreenCapture_OnCaptureContentChanged}
 * @param userData Pointer to user specific data
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr or input callback is nullptr.
 *         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT} opertation not be permitted, set ErrorCallback failed.
 * @since 20
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCaptureContentChangedCallback(struct OH_AVScreenCapture *capture,
    OH_AVScreenCapture_OnCaptureContentChanged callback, void *userData);

/**
 * @brief Set or update the captureArea
 * @param {struct OH_AVScreenCapture*} capture capture Pointer to an OH_AVScreenCapture instance
 * @param {uint64_t} displayId Indicates the screen index for setting area recording
 * @param {OH_Rect*} area Pointer to an object describing the location and size of the region
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr or displayid not exist or area is
 *         invalid.
 * @since 20
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCaptureArea(struct OH_AVScreenCapture *capture,
    uint64_t displayId, OH_Rect* area);

/**
 * @brief Set the fill mode for screen capture when a privacy window exists
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param {OH_AVScreenCapture_CaptureStrategy*} strategy Pointer to an OH_AVScreenCapture_CaptureStrategy instance
 * @param {int32_t} value
 * If set to 0, it means that when there is a privacy window interface, the output screen image is completely black.
 * If set to 1, it means that when there is a privacy window interface, only the privacy window area of the output
 * screen becomes black, and other values returns an error.
 * @return Function result code.
 * {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 * {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} strategy is nullptr or value is invalid.
 * @since 20
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StrategyForPrivacyMaskMode(
    OH_AVScreenCapture_CaptureStrategy *strategy, int32_t value);

/**
 * @brief Set the canvas to rotate with the screen when capturing the screen
 * @param {OH_AVScreenCapture_CaptureStrategy*} strategy Pointer to an OH_AVScreenCapture_CaptureStrategy instance
 * @param {bool} value The default value is False, which means that the width and height of the VirtualDisplay
 * remain the initial settings. If set to True, it means that the width and height of the VirtualDisplay rotates
 * with the rotation of the screen..
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} strategy value is nullptr.
 * @since 20
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StrategyForCanvasFollowRotation(
    OH_AVScreenCapture_CaptureStrategy *strategy, bool value);

/**
 * @brief Register user selection notification callback function
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param {OH_AVScreenCapture*} capture Pointer to OH_AVScreenCapture which want to handle user selection info
 * @param {OH_AVScreenCapture_OnUserSelected} callback user selection callback function, see
 *        {@link OH_AVScreenCapture_OnUserSelected}
 * @param {void*} userData The control block pointer passed by the application is carried to the application when it
 *        is returned
 * @return Function result code.
 *          {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *          {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} input capture is nullptr.
 * @since 20
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetSelectionCallback(struct OH_AVScreenCapture *capture,
    OH_AVScreenCapture_OnUserSelected callback, void *userData);

/**
 * @brief Get the recording content type selected by the user in the confirmation interface
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param {OH_AVScreenCapture_UserSelectionInfo*} selection Pointer to an OH_AVScreenCapture_UserSelectionInfo instance
 * @param {int32_t*} type The capture object type selected by the user, 0: represents the screen, 1: represents the
 *        window.
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} if selections is nullptr.
 * @since 20
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_GetCaptureTypeSelected(OH_AVScreenCapture_UserSelectionInfo *selection,
    int32_t* type);

/**
 * @brief Get the Display ID of user selections in the confirmation interface
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param {OH_AVScreenCapture_UserSelectionInfo*} selection Pointer to an OH_AVScreenCapture_UserSelectionInfo instance
 * @param {uint64_t*} displayId Returns the screen ID value selected by the user
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} if selections is nullptr.
 * @since 20
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_GetDisplayIdSelected(OH_AVScreenCapture_UserSelectionInfo *selection,
    uint64_t* displayId);

/**
 * @brief Indicates whether to enable B-frame encoding, which is used to reduce the size of the recorded file.
 * @syscap SystemCapability.Multimedia.Media.AVScreenCapture
 * @param {OH_AVScreenCapture_CaptureStrategy*} strategy Pointer to an OH_AVScreenCapture_CaptureStrategy instance
 * @param {bool} value The default value is false, which means B frames  encoding are disabled.
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} strategy is nullptr.
 * @since 20
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StrategyForBFramesEncoding(
    OH_AVScreenCapture_CaptureStrategy *strategy, bool value);

/**
 * @brief set whether to pop up the screen capture Picker
 * @param {OH_AVScreenCapture_CaptureStrategy*} strategy Pointer to an OH_AVScreenCapture_CaptureStrategy instance
 * @param {bool} value
 *          If set to false, it means that the APP don’t need to pop up the Picker after screen capture starts;
 *          if set to True, the Picker will pop up uniformly after screen capture starts;
 *          If not set, it means using the system recommended behavior.
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} strategy value is nullptr.
 * @since 20
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StrategyForPickerPopUp(
    OH_AVScreenCapture_CaptureStrategy *strategy, bool value);

/**
 * @brief Set the fill mode of the captured image in the target area
 * @param {OH_AVScreenCapture_CaptureStrategy*} strategy Pointer to an OH_AVScreenCapture_CaptureStrategy instance
 * @param {OH_AVScreenCapture_FillMode} mode Value of the captured image fill mode
 * @return Function result code.
 *         {@link AV_SCREEN_CAPTURE_ERR_OK} if the execution is successful.
 *         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} strategy value is nullptr.
 * @since 20
 */
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StrategyForFillMode(
    OH_AVScreenCapture_CaptureStrategy *strategy, OH_AVScreenCapture_FillMode mode);
#ifdef __cplusplus
}
#endif

#endif // NATIVE_AVSCREEN_CAPTURE_H
/** @} */