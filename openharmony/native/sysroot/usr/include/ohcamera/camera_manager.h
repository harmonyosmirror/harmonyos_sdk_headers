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
 * @file camera_manager.h
 *
 * @brief Declare the camera manager concepts.
 *
 * @library libohcamera.so
 * @kit CameraKit
 * @syscap SystemCapability.Multimedia.Camera.Core
 * @since 11
 * @version 1.0
 */

#ifndef NATIVE_INCLUDE_CAMERA_CAMERA_MANAGER_H
#define NATIVE_INCLUDE_CAMERA_CAMERA_MANAGER_H

#include <stdint.h>
#include <stdio.h>
#include "camera.h"
#include "camera_input.h"
#include "capture_session.h"
#include "preview_output.h"
#include "video_output.h"
#include "photo_output.h"
#include "metadata_output.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Camera manager status callback to be called in {@link CameraManager_Callbacks}.
 *
 * @param cameraManager the {@link Camera_Manager} which deliver the callback.
 * @param status the {@link Camera_StatusInfo} of each camera device.
 * @since 11
 */
typedef void (*OH_CameraManager_StatusCallback)(Camera_Manager* cameraManager, Camera_StatusInfo* status);

/**
 * @brief Camera manager torch status callback.
 *
 * @param cameraManager the {@link Camera_Manager} which deliver the callback.
 * @param status the {@link Camera_TorchStatusInfo} of the torch.
 * @since 12
 */
typedef void (*OH_CameraManager_TorchStatusCallback)(Camera_Manager* cameraManager, Camera_TorchStatusInfo* status);

/**
 * @brief A listener for camera devices status.
 *
 * @see OH_CameraManager_RegisterCallback
 * @since 11
 * @version 1.0
 */
typedef struct CameraManager_Callbacks {
    /**
     * Camera status change event.
     */
    OH_CameraManager_StatusCallback onCameraStatus;
} CameraManager_Callbacks;

/**
 * @brief Register camera status change event callback.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param callback the {@link CameraManager_Callbacks} to be registered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 11
 */
Camera_ErrorCode OH_CameraManager_RegisterCallback(Camera_Manager* cameraManager, CameraManager_Callbacks* callback);

/**
 * @brief Unregister camera status change event callback.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param callback the {@link CameraManager_Callbacks} to be unregistered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 11
 */
Camera_ErrorCode OH_CameraManager_UnregisterCallback(Camera_Manager* cameraManager, CameraManager_Callbacks* callback);

/**
 * @brief Register torch status change event callback.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param torchStatusCallback the {@link OH_CameraManager_TorchStatusCallback} to be registered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_CameraManager_RegisterTorchStatusCallback(Camera_Manager* cameraManager,
    OH_CameraManager_TorchStatusCallback torchStatusCallback);

/**
 * @brief Unregister torch status change event callback.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param torchStatusCallback the {@link OH_CameraManager_TorchStatusCallback} to be unregistered.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_CameraManager_UnregisterTorchStatusCallback(Camera_Manager* cameraManager,
    OH_CameraManager_TorchStatusCallback torchStatusCallback);

/**
 * @brief Gets supported camera descriptions.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param cameras the supported {@link Camera_Device} list will be filled
 *        if the method call succeeds.
 * @param size the size of supported {@link Camera_Device} list will be filled
 *        if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 11
 */
Camera_ErrorCode OH_CameraManager_GetSupportedCameras(Camera_Manager* cameraManager,
    Camera_Device** cameras, uint32_t* size);

/**
 * @brief Delete supported camera.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param cameras the {@link Camera_Device} list to be deleted.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 11
 */
Camera_ErrorCode OH_CameraManager_DeleteSupportedCameras(Camera_Manager* cameraManager,
    Camera_Device* cameras, uint32_t size);

/**
 * @brief Gets the supported output capability for the specific camera and specific mode.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param cameras the {@link Camera_Device} to be queryed.
 * @param cameraOutputCapability the supported {@link Camera_OutputCapability} will be filled
 *        if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 11
 */
Camera_ErrorCode OH_CameraManager_GetSupportedCameraOutputCapability(Camera_Manager* cameraManager,
    const Camera_Device* camera, Camera_OutputCapability** cameraOutputCapability);

/**
 * @brief Gets supported output capability for specific camera and specific sceneMode.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param camera the {@link Camera_Device} to be queryed.
 * @param sceneMode the {@link Camera_SceneMode} to be queryed.
 * @param cameraOutputCapability the supported {@link Camera_OutputCapability} will be filled
 *        if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 12
 */
Camera_ErrorCode OH_CameraManager_GetSupportedCameraOutputCapabilityWithSceneMode(Camera_Manager* cameraManager,
    const Camera_Device* camera, Camera_SceneMode sceneMode, Camera_OutputCapability** cameraOutputCapability);

/**
 * @brief Delete the supported output capability.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param cameraOutputCapability the {@link Camera_OutputCapability} to be deleted.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 11
 */
Camera_ErrorCode OH_CameraManager_DeleteSupportedCameraOutputCapability(Camera_Manager* cameraManager,
    Camera_OutputCapability* cameraOutputCapability);

/**
 * @brief Determine whether camera is muted.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param isCameraMuted whether camera is muted will be filled if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 11
 */
Camera_ErrorCode OH_CameraManager_IsCameraMuted(Camera_Manager* cameraManager, bool* isCameraMuted);

/**
 * @brief Create a capture session instance.The default session mode is photo session.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param captureSession the {@link Camera_CaptureSession} will be created
 *        if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 11
 */
Camera_ErrorCode OH_CameraManager_CreateCaptureSession(Camera_Manager* cameraManager,
    Camera_CaptureSession** captureSession);

/**
 * @brief Create a camera input instance.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param camera the {@link Camera_Device} which use to create {@link Camera_Input}.
 * @param cameraInput the {@link Camera_Input} will be created if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @permission ohos.permission.CAMERA
 * @since 11
 */
Camera_ErrorCode OH_CameraManager_CreateCameraInput(Camera_Manager* cameraManager,
    const Camera_Device* camera, Camera_Input** cameraInput);

/**
 * @brief Create a camera input instance.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param position the {@link Camera_Position} which use to create {@link Camera_Input}.
 * @param type the {@link Camera_Type} which use to create {@link Camera_Input}.
 * @param cameraInput the {@link Camera_Input} will be created if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @permission ohos.permission.CAMERA
 * @since 11
 */
Camera_ErrorCode OH_CameraManager_CreateCameraInput_WithPositionAndType(Camera_Manager* cameraManager,
    Camera_Position position, Camera_Type type, Camera_Input** cameraInput);

/**
 * @brief Create a preview output instance.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param profile the {@link Camera_Profile} to create {@link Camera_PreviewOutput}.
 * @param surfaceId the which use to create {@link Camera_PreviewOutput}.
 * @param previewOutput the {@link Camera_PreviewOutput} will be created if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 11
 */
Camera_ErrorCode OH_CameraManager_CreatePreviewOutput(Camera_Manager* cameraManager, const Camera_Profile* profile,
    const char* surfaceId, Camera_PreviewOutput** previewOutput);

/**
 * @brief Create a preview output instance used in preconfig.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param surfaceId the which use to create {@link Camera_PreviewOutput}.
 * @param previewOutput the {@link Camera_PreviewOutput} will be created if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 12
 */
Camera_ErrorCode OH_CameraManager_CreatePreviewOutputUsedInPreconfig(Camera_Manager* cameraManager,
    const char* surfaceId, Camera_PreviewOutput** previewOutput);

/**
 * @brief Create a photo output instance.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param profile the {@link Camera_Profile} to create {@link Camera_PhotoOutput}.
 * @param surfaceId the which use to create {@link Camera_PhotoOutput}.
 * @param photoOutput the {@link Camera_PhotoOutput} will be created if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 11
 */
Camera_ErrorCode OH_CameraManager_CreatePhotoOutput(Camera_Manager* cameraManager, const Camera_Profile* profile,
    const char* surfaceId, Camera_PhotoOutput** photoOutput);

/**
 * @brief Create a photo output instance used in preconfig.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param surfaceId the which use to create {@link Camera_PhotoOutput}.
 * @param photoOutput the {@link Camera_PhotoOutput} will be created if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 12
 */
Camera_ErrorCode OH_CameraManager_CreatePhotoOutputUsedInPreconfig(Camera_Manager* cameraManager,
    const char* surfaceId, Camera_PhotoOutput** photoOutput);

/**
 * @brief Create a photo output instance without surfaceId.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param profile the {@link Camera_Profile} to create {@link Camera_PhotoOutput}.
 * @param photoOutput the {@link Camera_PhotoOutput} will be created if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 12
 */
Camera_ErrorCode OH_CameraManager_CreatePhotoOutputWithoutSurface(Camera_Manager *cameraManager,
    const Camera_Profile *profile, Camera_PhotoOutput **photoOutput);

/**
 * @brief Create a video output instance.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param profile the {@link Camera_VideoProfile} to create {@link Camera_VideoOutput}.
 * @param surfaceId the which use to create {@link Camera_VideoOutput}.
 * @param videoOutput the {@link Camera_VideoOutput} will be created if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 11
 */
Camera_ErrorCode OH_CameraManager_CreateVideoOutput(Camera_Manager* cameraManager, const Camera_VideoProfile* profile,
    const char* surfaceId, Camera_VideoOutput** videoOutput);

/**
 * @brief Create a video output instance used in preconfig.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param surfaceId the which use to create {@link Camera_VideoOutput}.
 * @param videoOutput the {@link Camera_VideoOutput} will be created if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 12
 */
Camera_ErrorCode OH_CameraManager_CreateVideoOutputUsedInPreconfig(Camera_Manager* cameraManager,
    const char* surfaceId, Camera_VideoOutput** videoOutput);

/**
 * @brief Create a metadata output instance.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param profile the {@link Camera_MetadataObjectType} to create {@link Camera_MetadataOutput}.
 * @param metadataOutput the {@link Camera_MetadataOutput} will be created if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 11
 */
Camera_ErrorCode OH_CameraManager_CreateMetadataOutput(Camera_Manager* cameraManager,
    const Camera_MetadataObjectType* profile, Camera_MetadataOutput** metadataOutput);

/**
 * @brief Gets supported scene mode for specific camera.
 *
 * @param camera the {@link Camera_Device} to be queryed.
 * @param sceneModes the supported {@link Camera_SceneMode} will be filled if the method call succeeds.
 * @param size the size of supported {@link Camera_SceneMode} list will be filled if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 12
 */
Camera_ErrorCode OH_CameraManager_GetSupportedSceneModes(Camera_Device* camera,
    Camera_SceneMode** sceneModes, uint32_t* size);

/**
 * @brief Delete the scene mode.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param sceneModes the {@link Camera_SceneMode} to be deleted.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_CameraManager_DeleteSceneModes(Camera_Manager* cameraManager, Camera_SceneMode* sceneModes);

/**
 * @brief Check if the device supports torch.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param isTorchSupported whether the device supports torch.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 */
Camera_ErrorCode OH_CameraManager_IsTorchSupported(Camera_Manager* cameraManager,
    bool* isTorchSupported);

/**
 * @brief Check whether the device supports the torch with the specified torch mode.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param torchMode the {@link Camera_TorchMode} to be checked.
 * @param isTorchSupported whether device supports the torch mode.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 12
 */
Camera_ErrorCode OH_CameraManager_IsTorchSupportedByTorchMode(Camera_Manager* cameraManager,
    Camera_TorchMode torchMode, bool* isTorchSupported);

/**
 * @brief Set camera torch mode.
 *
 * @param cameraManager the {@link Camera_Manager} instance.
 * @param torchMode the {@link Camera_TorchMode} to be set.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 12
 */
Camera_ErrorCode OH_CameraManager_SetTorchMode(Camera_Manager* cameraManager,
    Camera_TorchMode torchMode);

#ifdef __cplusplus
}
#endif

#endif // NATIVE_INCLUDE_CAMERA_CAMERA_MANAGER_H
/** @} */