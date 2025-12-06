/*
 * Copyright (c) 2025 Huawei Device Co., Ltd.
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
 * @addtogroup Native_Bundle
 * @{
 *
 * @brief Describe the functions of AbilityResourceInfo.
 *
 * @since 21
 */

/**
 * @file ability_resource_info.h
 *
 * @brief Defines the OH_NativeBundle_AbilityResourceInfo APIs.
 *
 * @library libbundle_ndk.z.so
 * @kit AbilityKit
 * @syscap SystemCapability.BundleManager.BundleFramework.Core
 * @since 21
 */

#ifndef ABILITY_RESOURCE_INFO_H
#define ABILITY_RESOURCE_INFO_H

#include <stdbool.h>
#include <stddef.h>
#include "bundle_manager_common.h"
#include "../arkui/drawable_descriptor.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Indicates ability resource info.
 *
 * @since 21
 */
struct OH_NativeBundle_AbilityResourceInfo;
typedef struct OH_NativeBundle_AbilityResourceInfo OH_NativeBundle_AbilityResourceInfo;

/**
* @brief Get the bundle name of the abilityResourceInfo.
 *
 * @param abilityResourceInfo The ability resource info that has been obtained.
 * @param bundleName The bundle name obtained from abilityResourceInfo.
 * @return The error code.
 *         {@link BUNDLE_MANAGER_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link BUNDLE_MANAGER_ERROR_CODE_PARAM_INVALID} if the abilityResourceInfo is invalid.
 * @since 21
 */
BundleManager_ErrorCode OH_NativeBundle_GetBundleName(
    OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, char** bundleName);

/**
* @brief Get the module name of the abilityResourceInfo.
 *
 * @param abilityResourceInfo The ability resource info that has been obtained.
 * @param moduleName The module name obtained from abilityResourceInfo.
 * @return The error code.
 *         {@link BUNDLE_MANAGER_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link BUNDLE_MANAGER_ERROR_CODE_PARAM_INVALID} if the abilityResourceInfo is invalid.
 * @since 21
 */
BundleManager_ErrorCode OH_NativeBundle_GetModuleName(
    OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, char** moduleName);

/**
* @brief Get the ability name of the abilityResourceInfo.
 *
 * @param abilityResourceInfo The ability resource info that has been obtained.
 * @param abilityName The ability name obtained from abilityResourceInfo.
 * @return The error code.
 *         {@link BUNDLE_MANAGER_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link BUNDLE_MANAGER_ERROR_CODE_PARAM_INVALID} if the abilityResourceInfo is invalid.
 * @since 21
 */
BundleManager_ErrorCode OH_NativeBundle_GetAbilityName(
    OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, char** abilityName);

/**
* @brief Get the label of the abilityResourceInfo.
 *
 * @param abilityResourceInfo The ability resource info that has been obtained.
 * @param label The label obtained from abilityResourceInfo.
 * @return The error code.
 *         {@link BUNDLE_MANAGER_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link BUNDLE_MANAGER_ERROR_CODE_PARAM_INVALID} if the abilityResourceInfo is invalid.
 * @since 21
 */
BundleManager_ErrorCode OH_NativeBundle_GetLabel(
    OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, char** label);

/**
* @brief Get the appIndex of the abilityResourceInfo.
 *
 * @param abilityResourceInfo The ability resource info that has been obtained.
 * @param appIndex The appIndex obtained from abilityResourceInfo.
 * @return The error code.
 *         {@link BUNDLE_MANAGER_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link BUNDLE_MANAGER_ERROR_CODE_PARAM_INVALID} if the abilityResourceInfo is invalid.
 * @since 21
 */
BundleManager_ErrorCode OH_NativeBundle_GetAppIndex(
    OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, int* appIndex);

/**
* @brief Check whether abilityResourceInfo is the default application.
 *
 * @param abilityResourceInfo The ability resource info that has been obtained.
 * @param isDefault Check whether abilityResourceInfo is the default application.
 * @return The error code.
 *         {@link BUNDLE_MANAGER_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link BUNDLE_MANAGER_ERROR_CODE_PARAM_INVALID} if the abilityResourceInfo is invalid.
 * @since 21
 */
BundleManager_ErrorCode OH_NativeBundle_CheckDefaultApp(
    OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, bool* isDefault);

/**
* @brief Destroy the ability resource info.
 *
 * @param abilityResourceInfo The ability resource info to be deleted.
 * @param count Indicates the ability resource array size.
 * @return The error code.
 *         {@link BUNDLE_MANAGER_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link BUNDLE_MANAGER_ERROR_CODE_PARAM_INVALID} if the abilityResourceInfo is invalid.
 * @since 21
 */
BundleManager_ErrorCode OH_AbilityResourceInfo_Destroy(
    OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, size_t count);

/**
* @brief Get the size of ability resource info.
 *
 * @return The size of ability resource info.
 *
 * @since 21
 */
int OH_NativeBundle_GetSize();

/**
* @brief Get the drawable descriptor of the abilityResourceInfo.
 *
 * @param abilityResourceInfo The ability resource info that has been obtained.
 * @param drawableIcon The drawable descriptor obtained from abilityResourceInfo.
 * @return The error code.
 *         {@link BUNDLE_MANAGER_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link BUNDLE_MANAGER_ERROR_CODE_PARAM_INVALID} if the abilityResourceInfo is invalid.
 * @since 21
 */
BundleManager_ErrorCode OH_NativeBundle_GetDrawableDescriptor(
    OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, ArkUI_DrawableDescriptor** drawableIcon);
#ifdef __cplusplus
} // extern "C"
#endif

/** @} */
#endif // ABILITY_RESOURCE_INFO_H
