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
 * @addtogroup AbilityRuntime
 * @{
 *
 * @brief Describe the functions provided by the application context.
 *
 * @syscap SystemCapability.Ability.AbilityRuntime.Core
 * @since 13
 */

/**
 * @file application_context.h
 *
 * @brief Defines the application context APIs.
 *
 * @library libability_runtime.so
 * @kit AbilityKit
 * @syscap SystemCapability.Ability.AbilityRuntime.Core
 * @since 13
 */

#ifndef ABILITY_RUNTIME_APPLICATION_CONTEXT_H
#define ABILITY_RUNTIME_APPLICATION_CONTEXT_H

#include <stdint.h>
#include <stddef.h>
#include <AbilityKit/ability_base/want.h>
#include "ability_runtime_common.h"
#include "context_constant.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Obtain the cache directory of the application.
 *
 * @param buffer A pointer to a buffer that receives the cache directory of the application.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the application context does not exist.
 * @since 13
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetCacheDir(
    char* buffer, int32_t bufferSize, int32_t* writeLength);

/**
 * @brief Obtain the area mode of the application.
 *
 * @param areaMode A pointer to the area mode.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the areaMode is null.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the application context does not exist.
 * @since 13
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetAreaMode(AbilityRuntime_AreaMode* areaMode);

/**
 * @brief Obtain the bundle name.
 *
 * @param buffer A pointer to a buffer that receives the bundle name.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
  *                   when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the application context does not exist.
 * @since 13
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetBundleName(
    char* buffer, int32_t bufferSize, int32_t* writeLength);

/**
 * @brief Starts self UIAbility.
 *
 * @permission {@code ohos.permission.NDK_START_SELF_UI_ABILITY}
 * @param want The arguments passed to start self UIAbility.
 * For details, see {@link AbilityBase_Want}.
 * @return Returns {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the call is successful.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED} if the caller has no correct permission.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the arguments provided is invalid.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED} if the device does not support starting self uiability.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY} if the target ability does not exist.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE} if the ability type is incorrect.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED} if the crowdtesting application expires.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE} if the ability cannot be started in Wukong mode.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_CONTROLLED} if the app is controlled.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED} if the app is controlled by EDM.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_CROSS_APP} if the caller tries to start a different application.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_INTERNAL} if internal error occurs.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY} if the caller is not top ability.
 * For details, see {@link AbilityRuntime_ErrorCode}.
 * @since 15
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_StartSelfUIAbility(AbilityBase_Want *want);

#ifdef __cplusplus
} // extern "C"
#endif

/** @} */
#endif // ABILITY_RUNTIME_APPLICATION_CONTEXT_H
