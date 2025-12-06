/*
* Copyright (C) 2025 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @addtogroup Native_Bundle
 * @{
 *
 * @brief Describes the Native Bundle.
 *
 * @since 21
 * @version 1.0
 */

/**
 * @file bundle_manager_common.h
 *
 * @brief Declare the common types for the native BundleManager.
 *
 * @library libbundle_ndk.z.so
 * @kit AbilityKit
 * @syscap SystemCapability.BundleManager.BundleFramework.Core
 * @since 21
 */

#ifndef BUNDLE_MANAGER_COMMON_H
#define BUNDLE_MANAGER_COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates the error codes.
 *
 * @since 21
 */
typedef enum {
    /**
     * @error No error.
     * @since 21
     */
    BUNDLE_MANAGER_ERROR_CODE_NO_ERROR = 0,
    /**
     * @error permission denied.
     * @since 21
     */
    BUNDLE_MANAGER_ERROR_CODE_PERMISSION_DENIED = 201,
    /**
     * @error param invalid.
     * @since 21
     */
    BUNDLE_MANAGER_ERROR_CODE_PARAM_INVALID = 401,
} BundleManager_ErrorCode;

#ifdef __cplusplus
}
#endif

/** @} */
#endif // BUNDLE_MANAGER_COMMON_H
