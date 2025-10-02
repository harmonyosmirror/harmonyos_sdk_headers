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
 * @addtogroup MediaAssetManager
 * @{
 *
 * @brief Provides APIs of request capability for Media Source.
 *
 * @since 13
 */

/**
 * @file moving_photo_capi.h
 *
 * @brief Defines APIs related to moving photo.
 *
 * Provides the ability to obtain moving photo information.
 *
 * @kit MediaLibraryKit
 * @syscap SystemCapability.FileManagement.PhotoAccessHelper.Core
 * @library libmedia_asset_manager.so
 * @since 13
 */

#ifndef MULTIMEDIA_MEDIA_LIBRARY_NATIVE_MOVING_PHOTO_H
#define MULTIMEDIA_MEDIA_LIBRARY_NATIVE_MOVING_PHOTO_H

#include "media_asset_base_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get uri of the moving photo.
 *
 * @param movingPhoto the {@link OH_MovingPhoto} instance.
 * @param uri the uri of the moving photo.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 13
*/
MediaLibrary_ErrorCode OH_MovingPhoto_GetUri(OH_MovingPhoto* movingPhoto, const char** uri);

/**
 * @brief Request the image and video content of the moving photo and write to destination uri.
 *
 * @permission ohos.permission.READ_IMAGEVIDEO
 * @param movingPhoto the {@link OH_MovingPhoto} instance.
 * @param imageUri the destination file uri to save the image data.
 * @param videoUri the destination file uri to save the video data.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_PERMISSION_DENIED} if permission is denied.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 13
*/
MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithUris(OH_MovingPhoto* movingPhoto, char* imageUri,
    char* videoUri);

/**
 * @brief Request the image or video content of the moving photo and write to destination uri.
 *
 * @permission ohos.permission.READ_IMAGEVIDEO
 * @param movingPhoto the {@link OH_MovingPhoto} instance.
 * @param resourceType the {@link MediaLibrary_ResourceType} of the moving photo content to request.
 * @param uri the destination file uri to save the data.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_PERMISSION_DENIED} if permission is denied.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 13
*/
MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithUri(OH_MovingPhoto* movingPhoto,
    MediaLibrary_ResourceType resourceType, char* uri);

/**
 * @brief Request data of the moving photo.
 *
 * @permission ohos.permission.READ_IMAGEVIDEO
 * @param movingPhoto the {@link OH_MovingPhoto} instance.
 * @param resourceType the {@link MediaLibrary_ResourceType} of the moving photo content to request.
 * @param buffer the buffer of the content.
 * @param size the size of the buffer.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_PERMISSION_DENIED} if permission is denied.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 13
*/
MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithBuffer(OH_MovingPhoto* movingPhoto,
    MediaLibrary_ResourceType resourceType, const uint8_t** buffer, uint32_t* size);

/**
 * @brief Release the {@link OH_MovingPhoto} instance.
 *
 * @param movingPhoto the {@link OH_MovingPhoto} instance.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 * @since 13
*/
MediaLibrary_ErrorCode OH_MovingPhoto_Release(OH_MovingPhoto* movingPhoto);

#ifdef __cplusplus
}
#endif

#endif // MULTIMEDIA_MEDIA_LIBRARY_NATIVE_MOVING_PHOTO_H
/** @} */