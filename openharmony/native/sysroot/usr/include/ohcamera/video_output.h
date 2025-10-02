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
 * @addtogroup OH_Camera
 * @{
 *
 * @brief Provide the definition of the C interface for the camera module.
 *
 * @syscap SystemCapability.Multimedia.Camera.Core
 *
 * @since 11
 * @version 1.0
 */

/**
 * @file video_output.h
 *
 * @brief Declare the video output concepts.
 *
 * @library libohcamera.so
 * @kit CameraKit
 * @syscap SystemCapability.Multimedia.Camera.Core
 * @since 11
 * @version 1.0
 */

#ifndef NATIVE_INCLUDE_CAMERA_VIDEOOUTPUT_H
#define NATIVE_INCLUDE_CAMERA_VIDEOOUTPUT_H

#include <stdint.h>
#include <stdio.h>
#include "camera.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Video output object
 *
 * A pointer can be created using {@link Camera_VideoOutput} method.
 *
 * @since 11
 * @version 1.0
 */
typedef struct Camera_VideoOutput Camera_VideoOutput;

/**
 * @brief Video output frame start callback to be called in {@link VideoOutput_Callbacks}.
 *
 * @param videoOutput the {@link Camera_VideoOutput} which deliver the callback.
 * @since 11
 */
typedef void (*OH_VideoOutput_OnFrameStart)(Camera_VideoOutput* videoOutput);

/**
 * @brief Video output frame end callback to be called in {@link VideoOutput_Callbacks}.
 *
 * @param videoOutput the {@link Camera_VideoOutput} which deliver the callback.
 * @param frameCount the frame count which delivered by the callback.
 * @since 11
 */
typedef void (*OH_VideoOutput_OnFrameEnd)(Camera_VideoOutput* videoOutput, int32_t frameCount);

/**
 * @brief Video output error callback to be called in {@link VideoOutput_Callbacks}.
 *
 * @param videoOutput the {@link Camera_VideoOutput} which deliver the callback.
 * @param errorCode the {@link Camera_ErrorCode} of the video output.
 *
 * @see CAMERA_SERVICE_FATAL_ERROR
 * @since 11
 */
typedef void (*OH_VideoOutput_OnError)(Camera_VideoOutput* videoOutput, Camera_ErrorCode errorCode);

/**
 * @brief A listener for video output.
 *
 * @see OH_VideoOutput_RegisterCallback
 * @since 11
 * @version 1.0
 */
typedef struct VideoOutput_Callbacks {
    /**
     * Video output frame start event.
     */
    OH_VideoOutput_OnFrameStart onFrameStart;

    /**
     * Video output frame end event.
     */
    OH_VideoOutput_OnFrameEnd onFrameEnd;

    /**
     * Video output error event.
     */
    OH_VideoOutput_OnError onError;
} VideoOutput_Callbacks;

/**
 * @brief Register video output change event callback.
 *
 * @param videoOutput the {@link Camera_VideoOutput} instance.
 * @param callback the {@link VideoOutput_Callbacks} to be registered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 11
 */
Camera_ErrorCode OH_VideoOutput_RegisterCallback(Camera_VideoOutput* videoOutput, VideoOutput_Callbacks* callback);

/**
 * @brief Unregister video output change event callback.
 *
 * @param videoOutput the {@link Camera_VideoOutput} instance.
 * @param callback the {@link VideoOutput_Callbacks} to be unregistered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 11
 */
Camera_ErrorCode OH_VideoOutput_UnregisterCallback(Camera_VideoOutput* videoOutput, VideoOutput_Callbacks* callback);

/**
 * @brief Start video output.
 *
 * @param videoOutput the {@link Camera_VideoOutput} instance to be started.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SESSION_NOT_CONFIG} if the capture session not config.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 11
 */
Camera_ErrorCode OH_VideoOutput_Start(Camera_VideoOutput* videoOutput);

/**
 * @brief Stop video output.
 *
 * @param videoOutput the {@link Camera_VideoOutput} instance to be stoped.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 11
 */
Camera_ErrorCode OH_VideoOutput_Stop(Camera_VideoOutput* videoOutput);

/**
 * @brief Release video output.
 *
 * @param videoOutput the {@link Camera_VideoOutput} instance to be released.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 11
 */
Camera_ErrorCode OH_VideoOutput_Release(Camera_VideoOutput* videoOutput);

/**
 * @brief Get active video output profile.
 *
 * @param videoOutput the {@link Camera_VideoOutput} instance to deliver active video profile.
 * @param profile the active {@link Camera_VideoProfile} to be filled if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 12
 */
Camera_ErrorCode OH_VideoOutput_GetActiveProfile(Camera_VideoOutput* videoOutput, Camera_VideoProfile** profile);

/**
 * @brief Delete video profile instance.
 *
 * @param profile the {@link Camera_VideoProfile} instance to deleted.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_VideoOutput_DeleteProfile(Camera_VideoProfile* profile);

/**
 * @brief Gets the video rotation angle.
 *
 * @param videoOutput the {@link Camera_VideoOutput} instance which used to get the video rotation angle.
 * @param deviceDegree the current device rotation degree.
 * @param imageRotation the {@link Camera_ImageRotation} result of video rotation angle.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 12
 */
Camera_ErrorCode  OH_VideoOutput_GetVideoRotation(Camera_VideoOutput* videoOutput, int deviceDegree,
    Camera_ImageRotation* imageRotation);

/**
 * @brief Get supported video output frame rate list.
 *
 * @param videoOutput the {@link Camera_VideoOutput} instance to deliver supported frame rate list.
 * @param frameRateRange the supported {@link Camera_FrameRateRange} list to be filled if the method call succeeds.
 * @param size the size of supported {@link Camera_FrameRateRange} list will be filled.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 12
 */
Camera_ErrorCode OH_VideoOutput_GetSupportedFrameRates(Camera_VideoOutput* videoOutput,
    Camera_FrameRateRange** frameRateRange, uint32_t* size);

/**
 * @brief Delete frame rate list.
 *
 * @param videoOutput the {@link Camera_VideoOutput} instance to deliver supported frame rate list.
 * @param frameRateRange the {@link Camera_FrameRateRange} list to be deleted.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_VideoOutput_DeleteFrameRates(Camera_VideoOutput* videoOutput,
    Camera_FrameRateRange* frameRateRange);

/**
 * @brief Set video output frame rate.
 *
 * @param videoOutput the {@link Camera_VideoOutput} instance to be set frame rate.
 * @param minFps the minimum to be set.
 * @param maxFps the maximum to be set.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_VideoOutput_SetFrameRate(Camera_VideoOutput* videoOutput,
    int32_t minFps, int32_t maxFps);

/**
 * @brief Get active video output frame rate.
 *
 * @param videoOutput the {@link Camera_VideoOutput} instance to deliver the active frame rate.
 * @param frameRateRange the active {@link Camera_FrameRateRange} to be filled if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 12
 */
Camera_ErrorCode OH_VideoOutput_GetActiveFrameRate(Camera_VideoOutput* videoOutput,
    Camera_FrameRateRange* frameRateRange);

#ifdef __cplusplus
}
#endif

#endif // NATIVE_INCLUDE_CAMERA_VIDEOOUTPUT_H
/** @} */