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
 * @file photo_output.h
 *
 * @brief Declare the photo output concepts.
 *
 * @library libohcamera.so
 * @kit CameraKit
 * @syscap SystemCapability.Multimedia.Camera.Core
 * @since 11
 * @version 1.0
 */

#ifndef NATIVE_INCLUDE_CAMERA_PHOTOOUTPUT_H
#define NATIVE_INCLUDE_CAMERA_PHOTOOUTPUT_H

#include <stdint.h>
#include <stdio.h>
#include "camera.h"
#include "photo_native.h"
#include "multimedia/media_library/media_asset_base_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Photo output object
 *
 * A pointer can be created using {@link Camera_PhotoOutput} method.
 *
 * @since 11
 * @version 1.0
 */
typedef struct Camera_PhotoOutput Camera_PhotoOutput;

/**
 * @brief Photo output frame start callback to be called in {@link PhotoOutput_Callbacks}.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} which deliver the callback.
 * @since 11
 */
typedef void (*OH_PhotoOutput_OnFrameStart)(Camera_PhotoOutput* photoOutput);

/**
 * @brief Photo output frame shutter callback to be called in {@link PhotoOutput_Callbacks}.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} which deliver the callback.
 * @param info the {@link Camera_FrameShutterInfo} which delivered by the callback.
 * @since 11
 */
typedef void (*OH_PhotoOutput_OnFrameShutter)(Camera_PhotoOutput* photoOutput, Camera_FrameShutterInfo* info);

/**
 * @brief Photo output frame end callback to be called in {@link PhotoOutput_Callbacks}.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} which deliver the callback.
 * @param frameCount the frame count which delivered by the callback.
 * @since 11
 */
typedef void (*OH_PhotoOutput_OnFrameEnd)(Camera_PhotoOutput* photoOutput, int32_t frameCount);

/**
 * @brief Photo output error callback to be called in {@link PhotoOutput_Callbacks}.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} which deliver the callback.
 * @param errorCode the {@link Camera_ErrorCode} of the photo output.
 *
 * @see CAMERA_SERVICE_FATAL_ERROR
 * @since 11
 */
typedef void (*OH_PhotoOutput_OnError)(Camera_PhotoOutput* photoOutput, Camera_ErrorCode errorCode);

/**
 * @brief Photo output capture end callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} which deliver the callback.
 * @param frameCount the frameCount which is delivered by the callback.
 * @since 12
 */
typedef void (*OH_PhotoOutput_CaptureEnd) (Camera_PhotoOutput* photoOutput, int32_t frameCount);

/**
 * @brief Photo output capture start with infomation callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} which deliver the callback.
 * @param Info the {@link Camera_CaptureStartInfo} which is delivered by the callback..
 * @since 12
 */
typedef void (*OH_PhotoOutput_CaptureStartWithInfo) (Camera_PhotoOutput* photoOutput, Camera_CaptureStartInfo* Info);

/**
 * @brief Photo output eframe shutter end callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} which deliver the callback.
 * @param Info the {@link Camera_CaptureStartInfo} which is delivered by the callback.
 * @since 12
 */
typedef void (*OH_PhotoOutput_OnFrameShutterEnd) (Camera_PhotoOutput* photoOutput, Camera_FrameShutterInfo* Info);

/**
 * @brief Photo output capture ready callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} which deliver the callback.
 * @since 12
 */
typedef void (*OH_PhotoOutput_CaptureReady) (Camera_PhotoOutput* photoOutput);

/**
 * @brief Photo output estimated capture duration callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} which deliver the callback.
 * @param duration the duration which is delivered by the callback.
 * @since 12
 */
typedef void (*OH_PhotoOutput_EstimatedCaptureDuration) (Camera_PhotoOutput* photoOutput, int64_t duration);

/**
 * @brief Photo output available high-resolution images callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} which deliver the callback.
 * @param photo the {@link OH_PhotoNative} which delivered by the callback.
 * @since 12
 */
typedef void (*OH_PhotoOutput_PhotoAvailable)(Camera_PhotoOutput* photoOutput, OH_PhotoNative* photo);

/**
 * @brief Photo output photo asset available callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} which deliver the callback.
 * @param photoAsset the {@link OH_MediaAsset} which delivered by the callback.
 * @since 12
 */
typedef void (*OH_PhotoOutput_PhotoAssetAvailable)(Camera_PhotoOutput* photoOutput, OH_MediaAsset* photoAsset);

/**
 * @brief A listener for photo output.
 *
 * @see OH_PhotoOutput_RegisterCallback
 * @since 11
 * @version 1.0
 */
typedef struct PhotoOutput_Callbacks {
    /**
     * Photo output frame start event.
     */
    OH_PhotoOutput_OnFrameStart onFrameStart;

    /**
     * Photo output frame shutter event.
     */
    OH_PhotoOutput_OnFrameShutter onFrameShutter;

    /**
     * Photo output frame end event.
     */
    OH_PhotoOutput_OnFrameEnd onFrameEnd;

    /**
     * Photo output error event.
     */
    OH_PhotoOutput_OnError onError;
} PhotoOutput_Callbacks;

/**
 * @brief Register photo output change event callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance.
 * @param callback the {@link PhotoOutput_Callbacks} to be registered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 11
 */
Camera_ErrorCode OH_PhotoOutput_RegisterCallback(Camera_PhotoOutput* photoOutput, PhotoOutput_Callbacks* callback);

/**
 * @brief Unregister photo output change event callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance.
 * @param callback the {@link PhotoOutput_Callbacks} to be unregistered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 11
 */
Camera_ErrorCode OH_PhotoOutput_UnregisterCallback(Camera_PhotoOutput* photoOutput, PhotoOutput_Callbacks* callback);

/**
 * @brief Register capture start event callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance.
 * @param callback the {@link OH_PhotoOutput_CaptureStartWithInfo} to be registered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_PhotoOutput_RegisterCaptureStartWithInfoCallback(Camera_PhotoOutput* photoOutput,
    OH_PhotoOutput_CaptureStartWithInfo callback);

/**
 * @brief Gets the photo rotation angle.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance which used to get the photo rotation angle.
 * @param deviceDegree the current device rotation degree.
 * @param imageRotation the {@link Camera_ImageRotation} result of photo rotation angle.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 12
 */
Camera_ErrorCode OH_PhotoOutput_GetPhotoRotation(Camera_PhotoOutput* photoOutput, int deviceDegree,
    Camera_ImageRotation* imageRotation);

/**
 * @brief Unregister capture start event callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance.
 * @param callback the {@link OH_PhotoOutput_CaptureStartWithInfo} to be unregistered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_PhotoOutput_UnregisterCaptureStartWithInfoCallback(Camera_PhotoOutput* photoOutput,
    OH_PhotoOutput_CaptureStartWithInfo callback);

/**
 * @brief Register capture end event callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance.
 * @param callback the {@link OH_PhotoOutput_CaptureEnd} to be registered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_PhotoOutput_RegisterCaptureEndCallback(Camera_PhotoOutput* photoOutput,
    OH_PhotoOutput_CaptureEnd callback);

/**
 * @brief Unregister capture end event callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance.
 * @param callback the {@link OH_PhotoOutput_CaptureEnd} to be unregistered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_PhotoOutput_UnregisterCaptureEndCallback(Camera_PhotoOutput* photoOutput,
    OH_PhotoOutput_CaptureEnd callback);

/**
 * @brief Register frame shutter end event callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance.
 * @param callback the {@link OH_PhotoOutput_OnFrameShutterEnd} to be registered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_PhotoOutput_RegisterFrameShutterEndCallback(Camera_PhotoOutput* photoOutput,
    OH_PhotoOutput_OnFrameShutterEnd callback);

/**
 * @brief Unregister frame shutter end event callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance.
 * @param callback the {@link OH_PhotoOutput_OnFrameShutterEnd} to be unregistered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_PhotoOutput_UnregisterFrameShutterEndCallback(Camera_PhotoOutput* photoOutput,
    OH_PhotoOutput_OnFrameShutterEnd callback);

/**
 * @brief Register capture ready event callback. After receiving the callback, can proceed to the next capture.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance.
 * @param callback the {@link OH_PhotoOutput_CaptureReady} to be registered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_PhotoOutput_RegisterCaptureReadyCallback(Camera_PhotoOutput* photoOutput,
    OH_PhotoOutput_CaptureReady callback);

/**
 * @brief Unregister capture ready event callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance.
 * @param callback the {@link OH_PhotoOutput_CaptureReady} to be unregistered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_PhotoOutput_UnregisterCaptureReadyCallback(Camera_PhotoOutput* photoOutput,
    OH_PhotoOutput_CaptureReady callback);

/**
 * @brief Register estimated capture duration event callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance.
 * @param callback the {@link OH_PhotoOutput_EstimatedCaptureDuration} to be registered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_PhotoOutput_RegisterEstimatedCaptureDurationCallback(Camera_PhotoOutput* photoOutput,
    OH_PhotoOutput_EstimatedCaptureDuration callback);

/**
 * @brief Unregister estimated capture duration event callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance.
 * @param callback the {@link OH_PhotoOutput_EstimatedCaptureDuration} to be unregistered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_PhotoOutput_UnregisterEstimatedCaptureDurationCallback(Camera_PhotoOutput* photoOutput,
    OH_PhotoOutput_EstimatedCaptureDuration callback);

/**
 * @brief Register photo output photo available callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance.
 * @param callback the {@link OH_PhotoOutput_PhotoAvailable} to be registered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_PhotoOutput_RegisterPhotoAvailableCallback(Camera_PhotoOutput* photoOutput,
    OH_PhotoOutput_PhotoAvailable callback);

/**
 * @brief Unregister photo output photo available callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance.
 * @param callback the {@link PhotoOutput_Callbacks} to be unregistered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_PhotoOutput_UnregisterPhotoAvailableCallback(Camera_PhotoOutput* photoOutput,
    OH_PhotoOutput_PhotoAvailable callback);

/**
 * @brief Register photo output photo asset available callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance.
 * @param callback the {@link OH_PhotoOutput_PhotoAssetAvailable} to be registered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_PhotoOutput_RegisterPhotoAssetAvailableCallback(Camera_PhotoOutput* photoOutput,
    OH_PhotoOutput_PhotoAssetAvailable callback);

/**
 * @brief Unregister photo output photo asset available callback.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance.
 * @param callback the {@link OH_PhotoOutput_PhotoAssetAvailable} to be unregistered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_PhotoOutput_UnregisterPhotoAssetAvailableCallback(Camera_PhotoOutput* photoOutput,
    OH_PhotoOutput_PhotoAssetAvailable callback);

/**
 * @brief Capture photo.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance which used to capture photo.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SESSION_NOT_RUNNING} if the capture session not running.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 11
 */
Camera_ErrorCode OH_PhotoOutput_Capture(Camera_PhotoOutput* photoOutput);

/**
 * @brief Capture photo with capture setting.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance which used to capture photo.
 * @param setting the {@link Camera_PhotoCaptureSetting} to used to capture photo.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SESSION_NOT_RUNNING} if the capture session not running.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 11
 */
Camera_ErrorCode OH_PhotoOutput_Capture_WithCaptureSetting(Camera_PhotoOutput* photoOutput,
    Camera_PhotoCaptureSetting setting);

/**
 * @brief Release photo output.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance to released.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 11
 */
Camera_ErrorCode OH_PhotoOutput_Release(Camera_PhotoOutput* photoOutput);

/**
 * @brief Check whether to support mirror photo.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance which used to check whether mirror supported.
 * @param isSupported the result of whether mirror supported.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 11
 */
Camera_ErrorCode OH_PhotoOutput_IsMirrorSupported(Camera_PhotoOutput* photoOutput, bool* isSupported);

/**
 * @brief Get active photo output profile.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance to deliver active profile.
 * @param profile the active {@link Camera_Profile} to be filled if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 12
 */
Camera_ErrorCode OH_PhotoOutput_GetActiveProfile(Camera_PhotoOutput* photoOutput, Camera_Profile** profile);

/**
 * @brief Delete photo profile instance.
 *
 * @param profile the {@link Camera_Profile} instance to deleted.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_PhotoOutput_DeleteProfile(Camera_Profile* profile);

/**
 * @brief Check whether to support moving photo.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance which used to check whether moving photo supported.
 * @param isSupported the result of whether moving photo supported.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 12
 */
Camera_ErrorCode OH_PhotoOutput_IsMovingPhotoSupported(Camera_PhotoOutput* photoOutput, bool* isSupported);

/**
 * @brief Enable moving photo or not.
 *
 * @param photoOutput the {@link Camera_PhotoOutput} instance which used to enable moving photo or not.
 * @param enabled the flag of enable moving photo or not.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 12
 */
Camera_ErrorCode OH_PhotoOutput_EnableMovingPhoto(Camera_PhotoOutput* photoOutput, bool enabled);

#ifdef __cplusplus
}
#endif

#endif // NATIVE_INCLUDE_CAMERA_PHOTOOUTPUT_H
/** @} */