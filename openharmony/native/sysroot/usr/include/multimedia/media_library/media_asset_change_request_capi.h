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
 * @since 12
 */

/**
 * @file media_asset_change_request_capi.h
 *
 * @brief Defines APIs related to media asset change request.
 *
 * Provides the ability to change assets.
 *
 * @kit MediaLibraryKit
 * @syscap SystemCapability.FileManagement.PhotoAccessHelper.Core
 * @library libmedia_asset_manager.so
 * @since 12
 */

#ifndef MULTIMEDIA_MEDIA_LIBRARY_NATIVE_MEDIA_ASSET_CHANGE_REQUEST_H
#define MULTIMEDIA_MEDIA_LIBRARY_NATIVE_MEDIA_ASSET_CHANGE_REQUEST_H

#include "media_asset_base_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Create a {@link OH_MediaAssetChangeRequest} instance.
 *
 * @param mediaAsset the {@link OH_MediaAsset} instance.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 12
*/
OH_MediaAssetChangeRequest* OH_MediaAssetChangeRequest_Create(OH_MediaAsset* mediaAsset);

/**
 * @brief Add resource of the asset using file uri.
 *
 * @param changeRequest the {@link OH_MediaAssetChangeRequest} instance.
 * @param resourceType the {@link MediaLibrary_ResourceType} of the resource to add.
 * @param fileUri the file uri.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_NO_SUCH_FILE} if file does not exist.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 *         {@link #MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED} if operation is not supported.
 * @since 13
*/
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_AddResourceWithUri(OH_MediaAssetChangeRequest* changeRequest,
    MediaLibrary_ResourceType resourceType, char* fileUri);

/**
 * @brief Add resource of the asset using ArrayBuffer.
 *
 * @param changeRequest the {@link OH_MediaAssetChangeRequest} instance.
 * @param resourceType the {@link MediaLibrary_ResourceType} of the resource to add.
 * @param buffer the data buffer to add.
 * @param length the length of the data buffer.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 *         {@link #MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED} if operation is not supported.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_AddResourceWithBuffer(OH_MediaAssetChangeRequest* changeRequest,
    MediaLibrary_ResourceType resourceType, uint8_t* buffer, uint32_t length);

/**
 * @brief Get write cache handler.
 *
 * @permission ohos.permission.WRITE_IMAGEVIDEO
 * @param changeRequest the {@link OH_MediaAssetChangeRequest} instance.
 * @param fd the write cache handler.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 *         {@link #MEDIA_LIBRARY_PERMISSION_DENIED} if permission is denied.
 *         {@link #MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED} if operation is not supported.
 * @since 13
*/
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_GetWriteCacheHandler(OH_MediaAssetChangeRequest* changeRequest,
    int32_t* fd);

/**
 * @brief Save the photo asset captured by camera.
 *
 * @param changeRequest the {@link OH_MediaAssetChangeRequest} instance.
 * @param imageFileType The {@link MediaLibrary_ImageFileType} of photo to be saved.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 *         {@link #MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED} if operation is not supported.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_SaveCameraPhoto(OH_MediaAssetChangeRequest* changeRequest,
    MediaLibrary_ImageFileType imageFileType);

/**
 * @brief Discard the photo asset captured by camera.
 *
 * @param changeRequest the {@link OH_MediaAssetChangeRequest} instance.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 *         {@link #MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED} if operation is not supported.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_DiscardCameraPhoto(OH_MediaAssetChangeRequest* changeRequest);

/**
 * @brief Release the {@link OH_MediaAssetChangeRequest} instance.
 *
 * @param changeRequest the {@link OH_MediaAssetChangeRequest} instance.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_Release(OH_MediaAssetChangeRequest* changeRequest);

#ifdef __cplusplus
}
#endif

#endif // MULTIMEDIA_MEDIA_LIBRARY_NATIVE_MEDIA_ASSET_CHANGE_REQUEST_H
/** @} */
