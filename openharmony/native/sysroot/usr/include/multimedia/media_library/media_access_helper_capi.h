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
 * @addtogroup MediaAccessHelper
 * @{
 *
 * @brief Provides APIs of request capability for Media Source.
 *
 * @since 12
 */

/**
 * @file media_access_helper_capi.h
 *
 * @brief Defines APIs related to media assess helper.
 *
 * Provides the ability to create photo albums, as well as access and modify media data information in the albums.
 *
 * @kit MediaLibraryKit
 * @syscap SystemCapability.FileManagement.PhotoAccessHelper.Core
 * @library libmedia_asset_manager.so
 * @since 12
 */

#ifndef MULTIMEDIA_MEDIA_LIBRARY_NATIVE_MEDIA_ACCESS_HELPER_H
#define MULTIMEDIA_MEDIA_LIBRARY_NATIVE_MEDIA_ACCESS_HELPER_H

#include "media_asset_base_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Apply the change request of asset or album.
 *
 * @permission ohos.permission.WRITE_IMAGEVIDEO
 * @param changeRequest the {@link OH_MediaAssetChangeRequest} instance to be applied.
 * @return {@link #MEDIA_LIBRARY_OK} if the method call succeeds.
 *         {@link #MEDIA_LIBRARY_PARAMETER_ERROR} Parameter error. Possible causes:
 *                                                1. Mandatory parameters are left unspecified.
 *                                                2. Incorrect parameter types.
 *                                                3. Parameter verification failed.
 *         {@link #MEDIA_LIBRARY_PERMISSION_DENIED} Permission is denied.
 *         {@link #MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR} if internal system error.
 * @since 12
*/
MediaLibrary_ErrorCode OH_MediaAccessHelper_ApplyChanges(OH_MediaAssetChangeRequest* changeRequest);

#ifdef __cplusplus
}
#endif

#endif // MULTIMEDIA_MEDIA_LIBRARY_NATIVE_MEDIA_ACCESS_HELPER_H
/** @} */