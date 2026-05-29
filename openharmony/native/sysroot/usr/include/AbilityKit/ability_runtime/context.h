/*
 * Copyright (c) 2026 Huawei Device Co., Ltd.
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
 * @brief Provide the definition of the C interface for the context AbilityRuntime
 *
 * @since 24
 */

/**
 * @file context.h
 *
 * @brief Declare the common types for the context AbilityRuntime.
 *
 * @library libability_runtime.so
 * @kit AbilityKit
 * @syscap SystemCapability.Ability.AbilityRuntime.Core
 * @since 24
 */

#ifndef ABILITY_RUNTIME_CONTEXT_H
#define ABILITY_RUNTIME_CONTEXT_H

#include "info/application_target_sdk_version.h"
#include <stdint.h>
#include "ability_runtime_common.h"
#include "context_constant.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Define the AbilityRuntime_Context structure type.
 *
 * @since 24
 */
struct AbilityRuntime_Context;

/**
 * @brief Defines the pointer to AbilityRuntime_Context.
 *
 * @since 24
 */
typedef struct AbilityRuntime_Context* AbilityRuntime_ContextHandle;

/**
 * @brief Obtain the cache directory of the context.
 *
 * @param context The context to get cache directory from.
 * @param buffer A pointer to a buffer that receives the cache directory of the context.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the context does not exist.
 * @since 24
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetCacheDir(
    AbilityRuntime_ContextHandle context, char* buffer, int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Obtain the temp directory of the context.
 *
 * @param context The context to get temp directory from.
 * @param buffer A pointer to a buffer that receives the temp directory of the context.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the context does not exist.
 * @since 24
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetTempDir(
    AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Obtain the files directory of the context.
 *
 * @param context The context to get files directory from.
 * @param buffer A pointer to a buffer that receives the files directory of the context.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the context does not exist.
 * @since 24
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetFilesDir(
    AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Obtain the database directory of the context.
 *
 * @param context The context to get database directory from.
 * @param buffer A pointer to a buffer that receives the database directory of the context.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the context does not exist.
 * @since 24
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetDatabaseDir(
    AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Obtain the preferences directory of the context.
 *
 * @param context The context to get preferences directory from.
 * @param buffer A pointer to a buffer that receives the preferences directory of the context.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the context does not exist.
 * @since 24
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetPreferencesDir(
    AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Obtain the bundle code directory of the context.
 *
 * @param context The context to get bundle code directory from.
 * @param buffer A pointer to a buffer that receives the bundle code directory of the context.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the context does not exist.
 * @since 24
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetBundleCodeDir(
    AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Obtain the distributed files directory of the context.
 *
 * @param context The context to get distributed files directory from.
 * @param buffer A pointer to a buffer that receives the distributed files directory of the context.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the context does not exist.
 * @since 24
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetDistributedFilesDir(
    AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Obtain the resource directory of the context.
 *
 * @param context The context to get resource directory from.
 * @param buffer A pointer to a buffer that receives the resource directory of the context.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the context does not exist.
 * @since 24
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetResourceDir(AbilityRuntime_ContextHandle context,
    char* buffer, const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Obtain the cloud file directory of the context.
 *
 * @param context The context to get cloud file directory from.
 * @param buffer A pointer to a buffer that receives the cloud file directory of the context.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the context does not exist.
 * @since 24
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetCloudFileDir(
    AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Obtain the area mode of the context.
 *
 * @param context The context to get the area mode from.
 * @param areaMode A pointer to the area mode.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the areaMode is null.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the context does not exist.
 * @since 24
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetAreaMode(
    AbilityRuntime_ContextHandle context, AbilityRuntime_AreaMode* areaMode)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set the area mode of the context.
 *
 * @param context The context to set the area mode for.
 * @param areaMode The area mode.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the areaMode is null.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the context does not exist.
 * @since 24
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_SetAreaMode(
    AbilityRuntime_ContextHandle context, AbilityRuntime_AreaMode areaMode)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Obtain the log file directory of the context.
 *
 * @param context The context to get log file directory from.
 * @param buffer A pointer to a buffer that receives the log file directory of the context.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the context does not exist.
 * @since 24
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetLogFileDir(
    AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Obtain the process name.
 *
 * @param context The context to get the process name from.
 * @param buffer A pointer to a buffer that receives the process name.
 * @param bufferSize The length of the buffer.
 * @param writeLength The string length actually written to the buffer,
 *                    when returning {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR}.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the buffer or writeLength is null,
 *         or the buffer size is less than the minimum buffer size.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST} if the context does not exist.
 * @since 24
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetProcessName(
    AbilityRuntime_ContextHandle context, char* buffer, int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

#ifdef __cplusplus
}
#endif

/** @} */
#endif // ABILITY_RUNTIME_CONTEXT_H