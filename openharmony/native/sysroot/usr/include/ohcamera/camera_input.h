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
 * @file camera_input.h
 *
 * @brief Declare the camera input concepts.
 *
 * @library libohcamera.so
 * @kit CameraKit
 * @syscap SystemCapability.Multimedia.Camera.Core
 * @since 11
 * @version 1.0
 */

#ifndef NATIVE_INCLUDE_CAMERA_CAMERA_INPUT_H
#define NATIVE_INCLUDE_CAMERA_CAMERA_INPUT_H

#include "info/application_target_sdk_version.h"
#include <stdint.h>
#include <stdio.h>
#include "camera.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Camera input object.
 *
 * A pointer can be created using {@link OH_CameraManager_CreateCameraInput} method.
 *
 * @since 11
 * @version 1.0
 */
typedef struct Camera_Input Camera_Input;

/**
 * @brief Camera input error callback to be called in {@link CameraInput_Callbacks}.
 *
 * @param cameraInput the {@link Camera_Input} which deliver the callback.
 * @param errorCode the {@link Camera_ErrorCode} of the camera input.
 *
 * @see CAMERA_CONFLICT_CAMERA
 * @see CAMERA_DEVICE_DISABLED
 * @see CAMERA_DEVICE_PREEMPTED
 * @see CAMERA_SERVICE_FATAL_ERROR
 * @since 11
 */
typedef void (*OH_CameraInput_OnError)(const Camera_Input* cameraInput, Camera_ErrorCode errorCode);

/**
 * @brief A listener for camera input error events.
 *
 * @see OH_CameraInput_RegisterCallback
 * @since 11
 * @version 1.0
 */
typedef struct CameraInput_Callbacks {
    /**
     * Camera input error event.
     */
    OH_CameraInput_OnError onError;
} CameraInput_Callbacks;

/**
 * @brief Register camera input change event callback.
 *
 * @param cameraInput the {@link Camera_Input} instance.
 * @param callback the {@link CameraInput_Callbacks} to be registered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 11
 */
Camera_ErrorCode OH_CameraInput_RegisterCallback(Camera_Input* cameraInput, CameraInput_Callbacks* callback)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Unregister camera input change event callback.
 *
 * @param cameraInput the {@link Camera_Input} instance.
 * @param callback the {@link CameraInput_Callbacks} to be unregistered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 11
 */
Camera_ErrorCode OH_CameraInput_UnregisterCallback(Camera_Input* cameraInput, CameraInput_Callbacks* callback)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Open camera.
 *
 * @param cameraInput the {@link Camera_Input} instance to be opened.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_CONFLICT_CAMERA} if can not use camera cause of conflict.
 *         {@link #CAMERA_DEVICE_DISABLED} if camera disabled cause of security reason.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 11
 */
Camera_ErrorCode OH_CameraInput_Open(Camera_Input* cameraInput)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Open camera.
 *
 * @param cameraInput the {@link Camera_Input} instance to be opened.
 * @param secureSeqId which indicates SequenceId that secure camera is on.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_CONFLICT_CAMERA} if can not use camera cause of conflict.
 *         {@link #CAMERA_DEVICE_DISABLED} if camera disabled cause of security reason.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 12
 */
Camera_ErrorCode OH_CameraInput_OpenSecureCamera(Camera_Input* cameraInput, uint64_t* secureSeqId)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Open camera with specified concurrent type.
 *
 * @param cameraInput the {@link Camera_Input} instance to be opened.
 * @param type the {@link Camera_ConcurrentType} instance.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_CONFLICT_CAMERA} if can not use camera cause of conflict.
 *         {@link #CAMERA_DEVICE_DISABLED} if camera disabled cause of security reason.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 18
 */
Camera_ErrorCode OH_CameraInput_OpenConcurrentCameras(Camera_Input* cameraInput, Camera_ConcurrentType type)
__attribute__((__availability__(ohos, introduced=18.0.0)));

/**
 * @brief Close camera.
 *
 * @param cameraInput the {@link Camera_Input} instance to be closed.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 11
 */
Camera_ErrorCode OH_CameraInput_Close(Camera_Input* cameraInput)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Release camera input instance.
 *
 * @param cameraInput the {@link Camera_Input} instance to be released.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 11
 */
Camera_ErrorCode OH_CameraInput_Release(Camera_Input* cameraInput)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Query whether physical camera orientation is variable under different fold status.
 *
 * @param {CameraInput} cameraInput the {@link Camera_Input} instance.
 * @param {bool} isVariable the result of whether physical camera orientation is variable.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 22
 */
Camera_ErrorCode OH_CameraInput_IsPhysicalCameraOrientationVariable(Camera_Input* cameraInput, bool* isVariable)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Get physical camera orientation under current fold status.
 *
 * @param cameraInput the {@link Camera_Input} instance.
 * @param orientation the physical camera orientation of current fold status.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 22
 */
Camera_ErrorCode OH_CameraInput_GetPhysicalCameraOrientation(Camera_Input* cameraInput, uint32_t* orientation)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Choose whether to use the physical camera orientation.
 *
 * @param cameraInput the {@link Camera_Input} instance.
 * @param isUsed the flag of whether to use physical camera orientation.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_OPERATION_NOT_ALLOWED} if operation not allowed.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 22
 */
Camera_ErrorCode OH_CameraInput_UsePhysicalCameraOrientation(Camera_Input* cameraInput, bool isUsed)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Camera input occlusion detection result callback.
 *
 * @param cameraInput the {@link Camera_Input} which deliver the callback.
 * @param occlusionDetectionResult the {@link Camera_OcclusionDetectionResult} of the camera.
 * @since 23
 */
typedef void (*OH_CameraInput_OnOcclusionDetectionCallback)(const Camera_Input* cameraInput,
    Camera_OcclusionDetectionResult occlusionDetectionResult);

/**
 * @brief Subscribes to occlusion detection callback.
 *
 * @param cameraInput the {@link Camera_Input} instance.
 * @param occlusionDetectionCallback callback used for subscription.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 23
 */
Camera_ErrorCode OH_CameraInput_RegisterOcclusionDetectionCallback(Camera_Input* cameraInput,
    OH_CameraInput_OnOcclusionDetectionCallback occlusionDetectionCallback)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Unsubscribes from occlusion detection callback.
 *
 * @param cameraInput the {@link Camera_Input} instance.
 * @param occlusionDetectionCallback callback used for unsubscription.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 23
 */
Camera_ErrorCode OH_CameraInput_UnregisterOcclusionDetectionCallback(Camera_Input* cameraInput,
    OH_CameraInput_OnOcclusionDetectionCallback occlusionDetectionCallback)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

#ifdef __cplusplus
}
#endif

#endif // NATIVE_INCLUDE_CAMERA_CAMERA_INPUT_H
/** @} */