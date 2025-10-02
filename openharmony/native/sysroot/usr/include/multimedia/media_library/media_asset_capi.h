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
 * @file media_asset_capi.h
 *
 * @brief Defines APIs related to media asset.
 *
 * Provides the ability to obtain image or video information.
 *
 * @kit MediaLibraryKit
 * @syscap SystemCapability.FileManagement.PhotoAccessHelper.Core
 * @library libmedia_asset_manager.so
 * @since 12
 */

#ifndef MULTIMEDIA_MEDIA_LIBRARY_NATIVE_MEDIA_ASSET_H
#define MULTIMEDIA_MEDIA_LIBRARY_NATIVE_MEDIA_ASSET_H

#include "media_asset_base_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get the uri of the media asset.
 *
 * @param mediaAsset the {@link OH_MediaAsset} instance.
 * @param uri the uri of the media asset.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetUri(OH_MediaAsset* mediaAsset, const char** uri);

/**
 * @brief Get the media file type of the media asset.
 *
 * @param mediaAsset the {@link OH_MediaAsset} instance.
 * @param mediaType the media file type of the media asset.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 13
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetMediaType(OH_MediaAsset* mediaAsset, MediaLibrary_MediaType* mediaType);

/**
 * @brief Get the subtype of the media asset.
 *
 * @param mediaAsset the {@link OH_MediaAsset} instance.
 * @param mediaSubType the subtype of the media asset.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 13
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetMediaSubType(OH_MediaAsset* mediaAsset,
    MediaLibrary_MediaSubType* mediaSubType);

/**
 * @brief Get the display name of the media asset.
 *
 * @param mediaAsset the {@link OH_MediaAsset} instance.
 * @param displayName the display name of the media asset.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetDisplayName(OH_MediaAsset* mediaAsset, const char** displayName);

/**
 * @brief Get the file size of the media asset
 *
 * @param mediaAsset the {@link OH_MediaAsset} instance.
 * @param size the file size(in bytes) of the media asset.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetSize(OH_MediaAsset* mediaAsset, uint32_t* size);

/**
 * @brief Get the date of asset creation.
 *
 * @param mediaAsset the {@link OH_MediaAsset} instance.
 * @param dateAdded the creation date of the asset.
 *        The value is the number of seconds elapsed since the Epoch time (00:00:00 UTC on January 1, 1970).
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 13
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetDateAdded(OH_MediaAsset* mediaAsset, uint32_t* dateAdded);

/**
 * @brief Get the modified date of the asset.
 *
 * @param mediaAsset the {@link OH_MediaAsset} instance.
 * @param dateModified the modified date of the asset.
 *        The value is the number of seconds elapsed since the Epoch time.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 13
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetDateModified(OH_MediaAsset* mediaAsset, uint32_t* dateModified);

/**
 * @brief Get the date taken of the asset.
 *
 * @param mediaAsset the {@link OH_MediaAsset} instance.
 * @param dateTaken the date taken of the asset.
 *        The value is the number of seconds elapsed since the Epoch time.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 13
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetDateTaken(OH_MediaAsset* mediaAsset, uint32_t* dateTaken);

/**
 * @brief Get the creation time of the asset in milliseconds.
 *
 * @param mediaAsset the {@link OH_MediaAsset} instance.
 * @param dateAddedMs the creation time of the asset in milliseconds.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 13
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetDateAddedMs(OH_MediaAsset* mediaAsset, uint32_t* dateAddedMs);

/**
 * @brief Get the modified time of the asset in milliseconds.
 *
 * @param mediaAsset the {@link OH_MediaAsset} instance.
 * @param dateModifiedMs the modified time of the asset in milliseconds.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetDateModifiedMs(OH_MediaAsset* mediaAsset, uint32_t* dateModifiedMs);

/**
 * @brief Get the duration of the media asset in milliseconds.
 *
 * @param mediaAsset the {@link OH_MediaAsset} instance.
 * @param duration the duration of the media asset in milliseconds.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 13
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetDuration(OH_MediaAsset* mediaAsset, uint32_t* duration);

/**
 * @brief Get the image width(in pixels) of the media asset.
 *
 * @param mediaAsset the {@link OH_MediaAsset} instance.
 * @param width the image width(in pixels) of the media asset.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetWidth(OH_MediaAsset* mediaAsset, uint32_t* width);

/**
 * @brief Get the image height(in pixels) of the media asset.
 *
 * @param mediaAsset the {@link OH_MediaAsset} instance.
 * @param height the image height(in pixels) of the media asset.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetHeight(OH_MediaAsset* mediaAsset, uint32_t* height);

/**
 * @brief Get the orientation of the image.
 *
 * @param mediaAsset the {@link OH_MediaAsset} instance.
 * @param orientation the orientation of the image.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetOrientation(OH_MediaAsset* mediaAsset, uint32_t* orientation);

/**
 * @brief Get the favorite state of the asset.
 *
 * @param mediaAsset the {@link OH_MediaAsset} instance.
 * @param favorite the favorite state of the media asset.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 13
*/
MediaLibrary_ErrorCode OH_MediaAsset_IsFavorite(OH_MediaAsset* mediaAsset, uint32_t* favorite);

/**
 * @brief Get the title of the media asset.
 *
 * @param mediaAsset the {@link OH_MediaAsset} instance.
 * @param title the title of the media asset.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 13
*/
MediaLibrary_ErrorCode OH_MediaAsset_GetTitle(OH_MediaAsset* mediaAsset, const char** title);

/**
 * @brief Release the media asset
 *
 * @param mediaAsset the {@link OH_MediaAsset} instance.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAsset_Release(OH_MediaAsset* mediaAsset);

#ifdef __cplusplus
}
#endif

#endif // MULTIMEDIA_MEDIA_LIBRARY_NATIVE_MEDIA_ASSET_H
/** @} */