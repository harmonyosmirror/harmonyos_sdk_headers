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
 * @file photo_native.h
 *
 * @brief Declare the camera photo concepts.
 *
 * @library libohcamera.so
 * @syscap SystemCapability.Multimedia.Camera.Core
 * @since 12
 * @version 1.0
 */

#ifndef NATIVE_INCLUDE_PHOTO_NATIVE_H
#define NATIVE_INCLUDE_PHOTO_NATIVE_H

#include <stdint.h>
#include <stdio.h>
#include "camera.h"
#include "multimedia/image_framework/image/image_native.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Camera photo object
 *
 * A pointer can be created using {@link OH_PhotoNative} method.
 *
 * @since 12
 * @version 1.0
 */
typedef struct OH_PhotoNative OH_PhotoNative;

/**
 * @brief Get main image.
 *
 * @param photo the {@link OH_PhotoNative} instance.
 * @param mainImage the {@link OH_ImageNative} which use to get main image.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 * @version 1.0
 */
Camera_ErrorCode OH_PhotoNative_GetMainImage(OH_PhotoNative* photo, OH_ImageNative** mainImage);

/**
 * @brief Release camera photo.
 *
 * @param photo the {@link OH_PhotoNative} instance to released.
 * @return {@link #CAMERA_OK} if the method call succeeds.
 *         {@link #INVALID_ARGUMENT} if parameter missing or parameter type incorrect.
 * @since 12
 * @version 1.0
 */
Camera_ErrorCode OH_PhotoNative_Release(OH_PhotoNative* photo);

#ifdef __cplusplus
}
#endif

#endif // NATIVE_INCLUDE_PHOTO_NATIVE_H
/** @} */