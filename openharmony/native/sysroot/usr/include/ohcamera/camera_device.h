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

/**
 * @brief Gets the equivalent focal lengths of a camera device.
 *
 * @param camera Pointer to the Camera_Device used to retrieve attributes.
 * @param equivalentFocalLengths Output parameter, returns equivalent focal lengths array.
 * @param size Output parameter, returns array size.
 * @return {@link #CAMERA_OK} if successful
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or type incorrect
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error
 * @since 24
 */
Camera_ErrorCode OH_CameraDevice_GetLensEquivalentFocalLengths(const Camera_Device* camera,
    uint32_t** equivalentFocalLengths, uint32_t* size)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Checks if a camera device is a logical camera.
 *
 * @param camera Pointer to the Camera_Device used to retrieve attributes.
 * @param isLogicalCamera Output parameter, returns boolean indicating if it's a logical camera.
 * @return {@link #CAMERA_OK} if successful
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or type incorrect
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error
 * @since 24
 */
Camera_ErrorCode OH_CameraDevice_IsLogicalCamera(const Camera_Device* camera, bool* isLogicalCamera)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the constituent camera devices of a logical camera.
 * Release resources of the constituent cameras by calling {@link OH_CameraDevice_DeleteConstituentCameraDevices} .
 *
 * @param logicalCamera Pointer to the logical Camera_Device.
 * @param constituentCameras returns array of constituent camera devices.
 * @param size the size of constituentCameras.
 * @return {@link #CAMERA_OK} if successful
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or type incorrect
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error
 * @since 24
 */
Camera_ErrorCode OH_CameraDevice_GetLogicalCameraConstituentCameraDevices(
    const Camera_Device* logicalCamera, Camera_Device** constituentCameras, uint32_t* size)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief delete the constituent cameras of logicalCamera.
 *
 * @param logicalCamera Pointer to the logical Camera_Device.
 * @param constituentCameras the constituent cameras to be released.
 * @param size The size of the constituent cameras array.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 24
 */
Camera_ErrorCode OH_CameraDevice_DeleteConstituentCameraDevices(
    const Camera_Device* logicalCamera, Camera_Device* constituentCameras, uint32_t size)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the focal length of a camera lens.
 *
 * @param camera Pointer to the Camera_Device used to retrieve attributes.
 * @param lensFocalLength Output parameter, returns lens focal length value.
 * @return {@link #CAMERA_OK} if successful
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter missing or type incorrect
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fatal error
 * @since 24
 */
Camera_ErrorCode OH_CameraDevice_GetLensFocalLength(const Camera_Device* camera, float* lensFocalLength)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the minimum focus distance of a camera device.
 *
 * @param camera Pointer to the Camera_Device used to retrieve attributes.
 * @param minimumFocusDistance Output parameter, returns the minimum focus distance.
 * @return {@link #CAMERA_OK} if the operation succeeds
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter is missing or invalid
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fails
 * @since 24
 */
Camera_ErrorCode OH_CameraDevice_GetMinimumFocusDistance(const Camera_Device* camera, float* minimumFocusDistance)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the lens distortion parameters of a camera device.
 *
 * @param camera Pointer to the Camera_Device used to retrieve attributes.
 * @param lens Output parameter, returns the lens distortion parameters array.
 * @param size Output parameter, returns the size of the array.
 * @return {@link #CAMERA_OK} if the operation succeeds
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter is missing or invalid
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fails
 * @since 24
 */
Camera_ErrorCode OH_CameraDevice_GetLensDistortion(const Camera_Device* camera, float** lens, uint32_t* size)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the intrinsic calibration parameters of a camera device.
 *
 * @param camera Pointer to the Camera_Device used to retrieve attributes.
 * @param intrinsicCalibration Output parameter, returns the intrinsic calibration parameters array.
 * @param size Output parameter, returns the size of the array.
 * @return {@link #CAMERA_OK} if the operation succeeds
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter is missing or invalid
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fails
 * @since 24
 */
Camera_ErrorCode OH_CameraDevice_GetIntrinsicCalibration(const Camera_Device* camera, float** intrinsicCalibration,
    uint32_t* size)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the physical size of a camera sensor.
 *
 * @param camera Pointer to the Camera_Device used to retrieve attributes.
 * @param width Output parameter, returns the sensor width in millimeters.
 * @param height Output parameter, returns the sensor height in millimeters.
 * @return {@link #CAMERA_OK} if the operation succeeds
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter is missing or invalid
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fails
 * @since 24
 */
Camera_ErrorCode OH_CameraDevice_GetSensorPhysicalSize(const Camera_Device* camera, float* width, float* height)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the pixel array size of a camera sensor.
 *
 * @param camera Pointer to the Camera_Device used to retrieve attributes.
 * @param width Output parameter, returns the pixel array width in pixels.
 * @param height Output parameter, returns the pixel array height in pixels.
 * @return {@link #CAMERA_OK} if the operation succeeds
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter is missing or invalid
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fails
 * @since 24
 */
Camera_ErrorCode OH_CameraDevice_GetSensorPixelArraySize(const Camera_Device* camera,
    uint32_t* width, uint32_t* height)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the color filter arrangement of a camera sensor.
 *
 * @param camera Pointer to the Camera_Device used to retrieve attributes.
 * @param sensorCFA Output parameter, returns the sensor color filter arrangement enum value.
 * @return {@link #CAMERA_OK} if the operation succeeds
 *         {@link #CAMERA_INVALID_ARGUMENT} if parameter is missing or invalid
 *         {@link #CAMERA_SERVICE_FATAL_ERROR} if camera service fails
 * @since 24
 */
Camera_ErrorCode OH_CameraDevice_GetSensorColorFilterArrangement(const Camera_Device* camera,
    OH_Camera_SensorColorFilterArrangement* sensorCFA)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
#ifdef __cplusplus
}
#endif

#endif // NATIVE_INCLUDE_CAMERA_CAMERADEVICE_H
/** @} */