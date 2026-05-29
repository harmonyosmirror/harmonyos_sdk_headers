/*
 * Copyright (c) 2024-2025 Huawei Device Co., Ltd.
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

#include "info/application_target_sdk_version.h"
#include <stdint.h>
#include <stddef.h>
#include <AbilityKit/ability_base/want.h>
#include "ability_runtime_common.h"
#include "context_constant.h"
#include "start_options.h"

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
    char* buffer, int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

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
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetAreaMode(AbilityRuntime_AreaMode* areaMode)
__attribute__((__availability__(ohos, introduced=13.0.0)));

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
    char* buffer, int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Obtain the temp directory of the application.
 *
 * @param buffer A pointer to a buffer that receives the temp directory of the application.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the application context does not exist.
 * @since 16
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetTempDir(
    char* buffer, const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=16.0.0)));

/**
 * @brief Obtain the files directory of the application.
 *
 * @param buffer A pointer to a buffer that receives the files directory of the application.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the application context does not exist.
 * @since 16
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetFilesDir(
    char* buffer, const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=16.0.0)));

/**
 * @brief Obtain the database directory of the application.
 *
 * @param buffer A pointer to a buffer that receives the database directory of the application.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the application context does not exist.
 * @since 16
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetDatabaseDir(
    char* buffer, const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=16.0.0)));

/**
 * @brief Obtain the preferences directory of the application.
 *
 * @param buffer A pointer to a buffer that receives the preferences directory of the application.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the application context does not exist.
 * @since 16
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetPreferencesDir(
    char* buffer, const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=16.0.0)));

/**
 * @brief Obtain the bundle code directory of the application.
 *
 * @param buffer A pointer to a buffer that receives the bundle code directory of the application.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the application context does not exist.
 * @since 16
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetBundleCodeDir(
    char* buffer, const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=16.0.0)));

/**
 * @brief Obtain the distributed files directory of the application.
 *
 * @param buffer A pointer to a buffer that receives the distributed files directory of the application.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the application context does not exist.
 * @since 16
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetDistributedFilesDir(
    char* buffer, const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=16.0.0)));

/**
 * @brief Obtain the cloud file directory of the application.
 *
 * @param buffer A pointer to a buffer that receives the cloud file directory of the application.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the application context does not exist.
 * @since 16
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetCloudFileDir(
    char* buffer, const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=16.0.0)));

/**
 * @brief Obtain the resource directory of the target module.
 *
 * @param moduleName The module name.
 * @param buffer A pointer to a buffer that receives the resource directory of the target module.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the application context does not exist.
 * @since 20
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetResourceDir(const char* moduleName,
    char* buffer, const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Starts the UIAbility of the current application.
 *
 * @permission ohos.permission.NDK_START_SELF_UI_ABILITY
 * @param want Pointer to the Want information required for starting the UIAbility.
 * @return **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.
 *      **ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED**: Permission verification for the caller fails.
 *      **ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: Parameter verification for the caller fails.
 *      **ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED**: The device type is not supported.
 *      **ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY**: The specified ability name does not exist.
 *      **ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE**: The ability type is incorrect.
 *      **ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED**: The crowdtesting application expires.
 *      **ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE**: The ability is started or stopped in Wukong mode.
 *      **ABILITY_RUNTIME_ERROR_CODE_CONTROLLED**: The application is under control.
 *      **ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED**: The application is under control by EDM.
 *      **ABILITY_RUNTIME_ERROR_CODE_CROSS_APP**: Redirecting to third-party applications is not allowed in API versions
 *      later than 11.
 *      **ABILITY_RUNTIME_ERROR_CODE_INTERNAL**: An internal error occurs.
 *      **ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY**: The application is not a top one.
 *      **ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED** (available since API version 17): The number of instances has
 *      reached the upper limit.
 *      **ABILITY_RUNTIME_ERROR_CODE_APP_INSTANCE_KEY_NOT_SUPPORTED** (available since API version 17): Setting **
 *      APP_INSTANCE_KEY** is not supported.
 *      For details, see **AbilityRuntime_ErrorCode**.
 * @since 15
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_StartSelfUIAbility(AbilityBase_Want *want)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Obtain the launch parameter of starting UIAbility.
 *
 * @param buffer A pointer to a buffer that receives the launch parameter of starting UIAbility.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the application context does not exist.
 * @since 21
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetLaunchParameter(
    char* buffer, const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Obtain the latest parameter of starting UIAbility.
 *
 * @param buffer A pointer to a buffer that receives the latest parameter of starting UIAbility.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the application context does not exist.
 * @since 21
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetLatestParameter(
    char* buffer, const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Starts the UIAbility of the current application using **StartOptions**.
 *
 * @permission ohos.permission.NDK_START_SELF_UI_ABILITY
 * @param want Pointer to the Want information required for starting the UIAbility.
 * @param options Pointer to **StartOptions** required for starting the UIAbility.
 *      If the value of {@link startVisibility}
 *      is not null, ensure that the current application has been added to the status bar.
 *      Otherwise, the {@link ABILITY_RUNTIME_ERROR_VISIBILITY_SETTING_DISABLED} error code is returned.
 * @return <ul><li>**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.</li>
 *      <li>**ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED**: Permission verification for the caller fails.</li>
 *      <li>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: Parameter verification for the caller fails.</li>
 *      <li>**ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED**: The device type is not supported.</li>
 *      <li>**ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY**: The specified ability name does not exist.</li>
 *      <li>**ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE**: The ability type is incorrect.</li>
 *      <li>**ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED**: The crowdtesting application expires.</li>
 *      <li>**ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE**: The ability is started or stopped in Wukong mode.</li>
 *      <li>**ABILITY_RUNTIME_ERROR_CODE_CONTROLLED**: The application is under control.</li>
 *      <li>**ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED**: The application is under control by EDM.</li>
 *      <li>**ABILITY_RUNTIME_ERROR_CODE_CROSS_APP**: Redirecting to third-party applications
 *      is not allowed in API versions later than 11.</li>
 *      <li>**ABILITY_RUNTIME_ERROR_CODE_INTERNAL**: An internal error occurs.</li>
 *      <li>**ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY**: The application is not a top one.</li>
 *      <li>**ABILITY_RUNTIME_ERROR_VISIBILITY_SETTING_DISABLED**:
 *      Setting the window visibility during startup is not allowed.</li>
 *      <li>**ABILITY_RUNTIME_ERROR_CODE_MULTI_APP_NOT_SUPPORTED**:
 *      The application does not support clone or multi-instance mode.</li>
 *      <li>**ABILITY_RUNTIME_ERROR_CODE_INVALID_APP_INSTANCE_KEY**: The multi-instance key is invalid.</li>
 *      <li>**ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED**: The number of instances has reached the upper limit.</li>
 *      <li>**ABILITY_RUNTIME_ERROR_MULTI_INSTANCE_NOT_SUPPORTED**: The application does not support multi-instance mode.</li>
 *      <li>**ABILITY_RUNTIME_ERROR_CODE_APP_INSTANCE_KEY_NOT_SUPPORTED**: Setting **APP_INSTANCE_KEY** is not supported.
 *      For details, see **AbilityRuntime_ErrorCode**.</li></ul>
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_StartSelfUIAbilityWithStartOptions(AbilityBase_Want *want,
    AbilityRuntime_StartOptions *options)
    __attribute__((__availability__(ohos, introduced=17.0.0)));

    /**
 * @brief Obtain the version code of the application.
 *
 * @param versionCode The version code of the application.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the versionCode is null.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the application context does not exist.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_GET_APPLICATION_INFO_FAILED} if the application info does not exist.
 * @since 21
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetVersionCode(int64_t* versionCode)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Starts self UIAbility with start options and receives the process ID.
 *
 * @permission ohos.permission.NDK_START_SELF_UI_ABILITY
 * @param want The arguments passed to start self UIAbility.
 * For details, see {@link AbilityBase_Want}.
 * @param options The start options passed to start self UIAbility.
 * For details, see {@link AbilityRuntime_StartOptions}.
 * @param targetPid The process ID of the started UIAbility.
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
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_INTERNAL} if internal error occurs. such as connect system service failed.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY} if the caller is not foreground process.
 * Returns {@link ABILITY_RUNTIME_ERROR_VISIBILITY_SETTING_DISABLED} if setting visibility is disabled.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_MULTI_APP_NOT_SUPPORTED}
 *          if the app clone or multi-instance is not supported.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_INVALID_APP_INSTANCE_KEY} if the app instance key is invalid.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED} if the number of app instances reached the limit.
 * Returns {@link ABILITY_RUNTIME_ERROR_MULTI_INSTANCE_NOT_SUPPORTED} if the multi-instance is not supported.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_APP_INSTANCE_KEY_NOT_SUPPORTED}
 *          if the APP_INSTANCE_KEY cannot be specified.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_START_TIMEOUT} if starting UIAbility time out.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_MAIN_THREAD_NOT_SUPPORTED}
 *          if the API is called in the main thread of the app.
 * For details, see {@link AbilityRuntime_ErrorCode}.
 * @since 21
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_StartSelfUIAbilityWithPidResult(AbilityBase_Want *want,
    AbilityRuntime_StartOptions *options, int32_t *targetPid)
    __attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Obtain the log file directory of the application.
 *
 * @param buffer A pointer to a buffer that receives the log file directory of the application.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the application context does not exist.
 * @since 22
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetLogFileDir(
    char* buffer, const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Notify page changed.
 *
 * @param targetPageName The target page name.
 * @param targetPageNameLength The target page name length.
 * @param windowId The window identifier associated with the target page.
 *
 * @return Returns {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if targetPageName is null or windowId is invalid.
 * Returns {@link ABILITY_RUNTIME_ERROR_CODE_INTERNAL} 
 *           if internal error occurs, such as failed to access dependency module.
 * @since 23
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextNotifyPageChanged(
    const char* targetPageName, int32_t targetPageNameLength, int32_t windowId)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

#ifdef __cplusplus
} // extern "C"
#endif

/** @} */
#endif // ABILITY_RUNTIME_APPLICATION_CONTEXT_H
