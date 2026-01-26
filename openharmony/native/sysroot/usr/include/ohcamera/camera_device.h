/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
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
 * @since 12
 * @version 1.0
 */

/**
 * @file camera_device.h
 *
 * @brief Declare the camera device concepts.
 *
 * @library libohcamera.so
 * @kit CameraKit
 * @syscap SystemCapability.Multimedia.Camera.Core
 * @since 12
 * @version 1.0
 */

#ifndef NATIVE_INCLUDE_CAMERA_CAMERADEVICE_H
#define NATIVE_INCLUDE_CAMERA_CAMERADEVICE_H

#include "info/application_target_sdk_version.h"
#include <stdint.h>
#include <stdio.h>
#include "camera.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Gets the sensor orientation attribute for a camera device.
 *
 * @param camera the {@link Camera_Device} which use to get attributes.
 * @param orientation the sensor orientation attribute if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 12
 */
Camera_ErrorCode OH_CameraDevice_GetCameraOrientation(Camera_Device* camera, uint32_t* orientation)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Gets remote device name attribute for a camera device.
 *
 * @param camera the {@link Camera_Device} which use to get attributes.
 * @param hostDeviceName the remote device name attribute if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 15
 */
Camera_ErrorCode OH_CameraDevice_GetHostDeviceName(Camera_Device* camera, char** hostDeviceName)
__attribute__((__availability__(ohos, introduced=15.0.0)));


/**
 * @brief Gets the remote device type attribute for a camera device.
 *
 * @param camera the {@link Camera_Device} which use to get attributes.
 * @param hostDeviceType the {@link Camera_HostDeviceType} which remote device type attribute
          if the method call succeeds.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error.
 * @since 15
 */
Camera_ErrorCode OH_CameraDevice_GetHostDeviceType(Camera_Device* camera, Camera_HostDeviceType* hostDeviceType)
__attribute__((__availability__(ohos, introduced=15.0.0)));

#ifdef __cplusplus
}
#endif

#endif // NATIVE_INCLUDE_CAMERA_CAMERADEVICE_H
/** @} */