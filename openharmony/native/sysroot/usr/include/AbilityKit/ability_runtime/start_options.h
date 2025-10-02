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
 * @addtogroup AbilityRuntime
 * @{
 *
 * @brief Describe the functions provided by the start options.
 *
 * @syscap SystemCapability.Ability.AbilityRuntime.Core
 * @since 17
 */

/**
 * @file start_options.h
 *
 * @brief Defines the start options APIs.
 *
 * @library libability_runtime.so
 * @kit AbilityKit
 * @syscap SystemCapability.Ability.AbilityRuntime.Core
 * @since 17
 */

#ifndef ABILITY_RUNTIME_START_OPTIONS_H
#define ABILITY_RUNTIME_START_OPTIONS_H

#include <stdint.h>
#include <stddef.h>
#include "ability_runtime_common.h"
#include "context_constant.h"
#include "multimedia/image_framework/image/pixelmap_native.h"

#ifdef __cplusplus
extern "C" {
#endif

struct AbilityRuntime_StartOptions;
typedef struct AbilityRuntime_StartOptions AbilityRuntime_StartOptions;

/**
 * @brief Create start options.
 *
 * @return Returns the newly created AbilityRuntime_StartOptions object.
 *
 * @since 17
 */
AbilityRuntime_StartOptions* OH_AbilityRuntime_CreateStartOptions(void);

/**
 * @brief Destroy input start options.
 *
 * @param startOptions The options to be deleted.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_DestroyStartOptions(AbilityRuntime_StartOptions **startOptions);

/**
 * @brief Set window mode for start options.
 *
 * @param startOptions The options to set window mode for.
 * @param windowMode The window mode.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions or windowMode is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowMode(AbilityRuntime_StartOptions *startOptions,
    AbilityRuntime_WindowMode windowMode);

/**
 * @brief Get window mode from start options.
 *
 * @param startOptions The options to get window mode from.
 * @param windowMode The obtained window mode.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowMode(AbilityRuntime_StartOptions *startOptions,
    AbilityRuntime_WindowMode &windowMode);

/**
 * @brief Set display id for start options.
 *
 * @param startOptions The options to set display id for.
 * @param displayId The display id.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsDisplayId(AbilityRuntime_StartOptions *startOptions,
    int32_t displayId);

/**
 * @brief Get display id from start options.
 *
 * @param startOptions The options to get display id from.
 * @param displayId The obtained display id.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsDisplayId(AbilityRuntime_StartOptions *startOptions,
    int32_t &displayId);

/**
 * @brief Set with animation flag for start options.
 *
 * @param startOptions The options to set with animation for.
 * @param withAnimation The with animation.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWithAnimation(AbilityRuntime_StartOptions *startOptions,
    bool withAnimation);

/**
 * @brief Get with animation from start options.
 *
 * @param startOptions The options to get with animation from.
 * @param withAnimation The obtained with animation.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWithAnimation(AbilityRuntime_StartOptions *startOptions,
    bool &withAnimation);

/**
 * @brief Set window left for start options.
 *
 * @param startOptions The options to set window left for.
 * @param windowLeft The window left.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowLeft(AbilityRuntime_StartOptions *startOptions,
    int32_t windowLeft);

/**
 * @brief Get window left from start options.
 *
 * @param startOptions The options to get window left from.
 * @param windowLeft The obtained window left.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowLeft(AbilityRuntime_StartOptions *startOptions,
    int32_t &windowLeft);

/**
 * @brief Set window top for start options.
 *
 * @param startOptions The options to set window top for.
 * @param windowTop The window top.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowTop(AbilityRuntime_StartOptions *startOptions,
    int32_t windowTop);

/**
 * @brief Get window top from start options.
 *
 * @param startOptions The options to get window top from.
 * @param windowTop The obtained window top.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowTop(AbilityRuntime_StartOptions *startOptions,
    int32_t &windowTop);

/**
 * @brief Set window height for start options.
 *
 * @param startOptions The options to set window height for.
 * @param windowHeight The window height.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowHeight(AbilityRuntime_StartOptions *startOptions,
    int32_t windowHeight);

/**
 * @brief Get window height from start options.
 *
 * @param startOptions The options to get window height from.
 * @param windowHeight The obtained window height.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowHeight(AbilityRuntime_StartOptions *startOptions,
    int32_t &windowHeight);

/**
 * @brief Set window width for start options.
 *
 * @param startOptions The options to set window width for.
 * @param windowWidth The window width.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowWidth(AbilityRuntime_StartOptions *startOptions,
    int32_t windowWidth);

/**
 * @brief Get window width from start options.
 *
 * @param startOptions The options to get window width from.
 * @param windowWidth The obtained window width.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowWidth(AbilityRuntime_StartOptions *startOptions,
    int32_t &windowWidth);

/**
 * @brief Set start visibility for start options.
 *
 * @param startOptions The options to set start visibility for.
 * @param startVisibility The start visibility.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsStartVisibility(AbilityRuntime_StartOptions *startOptions,
    AbilityRuntime_StartVisibility startVisibility);

/**
 * @brief Get start visibility from start options.
 *
 * @param startOptions The options to get start visibility from.
 * @param startVisibility The obtained start visibility.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsStartVisibility(AbilityRuntime_StartOptions *startOptions,
    AbilityRuntime_StartVisibility &startVisibility);

/**
 * @brief Set start window icon for start options.
 *
 * @param startOptions The options to set start window icon for.
 * @param startWindowIcon The start window icon.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid
 *              or startWindowIcon is nullptr.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsStartWindowIcon(AbilityRuntime_StartOptions *startOptions,
    OH_PixelmapNative *startWindowIcon);

/**
 * @brief Get start window icon from start options.
 *
 * @param startOptions The options to get start window icon from.
 * @param startWindowIcon The obtained start window icon.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid
 *              or startWindowIcon is NOT nullptr.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsStartWindowIcon(AbilityRuntime_StartOptions *startOptions,
    OH_PixelmapNative **startWindowIcon);

/**
 * @brief Set start window background color for start options.
 *
 * @param startOptions The options to set start window background color for.
 * @param startWindowBackgroundColor The start window background color.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid
 *              or startWindowBackgroundColor is nullptr.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsStartWindowBackgroundColor(
    AbilityRuntime_StartOptions *startOptions, const char *startWindowBackgroundColor);

/**
 * @brief Get start window background color from start options.
 *
 * @param startOptions The options to get start window background color from.
 * @param startWindowBackgroundColor The obtained start window background color.
 * @param size The size of start window background color.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid
 *              or startWindowBackgroundColor is NOT nullptr.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_INTERNAL} if error occurred in malloc.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsStartWindowBackgroundColor(
    AbilityRuntime_StartOptions *startOptions, char **startWindowBackgroundColor, size_t &size);

/**
 * @brief Set start window modes for start options.
 *
 * @param startOptions The options to set start window modes for.
 * @param supportedWindowModes The start window modes.
 * @param size The size of start window modes.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions or supportWindowMode
 *              or size is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsSupportedWindowModes(
    AbilityRuntime_StartOptions *startOptions, AbilityRuntime_SupportedWindowMode *supportedWindowModes,
    size_t size);

/**
 * @brief Get start window modes from start options.
 *
 * @param startOptions The options to get start window modes from.
 * @param supportedWindowModes The obtained start window modes.
 * @param size The size of the returned start window modes.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invallid
 *              or supportWindowMode is NOT nullptr
 *         {@link ABILITY_RUNTIME_ERROR_CODE_INTERNAL} if error occurred in malloc.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsSupportedWindowModes(
    AbilityRuntime_StartOptions *startOptions, AbilityRuntime_SupportedWindowMode **supportedWindowModes,
    size_t &size);

/**
 * @brief Set min window width for start options.
 *
 * @param startOptions The options to set min window width for.
 * @param minWindowWidth The min window width.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsMinWindowWidth(
    AbilityRuntime_StartOptions *startOptions, int32_t minWindowWidth);

/**
 * @brief Get min window width from start options.
 *
 * @param startOptions The options to get min window width from.
 * @param minWindowWidth The obtained min window width.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsMinWindowWidth(
    AbilityRuntime_StartOptions *startOptions, int32_t &minWindowWidth);

/**
 * @brief Set max window width for start options.
 *
 * @param startOptions The options to set max window width for.
 * @param maxWindowWidth The max window width.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsMaxWindowWidth(
    AbilityRuntime_StartOptions *startOptions, int32_t maxWindowWidth);

/**
 * @brief Get max window width from start options.
 *
 * @param startOptions The options to get max window width from.
 * @param maxWindowWidth The obtained max window width.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsMaxWindowWidth(
    AbilityRuntime_StartOptions *startOptions, int32_t &maxWindowWidth);

/**
 * @brief Set min window height for start options.
 *
 * @param startOptions The options to set min window height for.
 * @param minWindowHeight The min window height.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsMinWindowHeight(
    AbilityRuntime_StartOptions *startOptions, int32_t minWindowHeight);

/**
 * @brief Get min window height from start options.
 *
 * @param startOptions The options to get min window height from.
 * @param minWindowHeight The obtained min window height.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsMinWindowHeight(
    AbilityRuntime_StartOptions *startOptions, int32_t &minWindowHeight);

/**
 * @brief Set max window height for start options.
 *
 * @param startOptions The options to set max window height for.
 * @param maxWindowHeight The max window height.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsMaxWindowHeight(
    AbilityRuntime_StartOptions *startOptions, int32_t maxWindowHeight);

/**
 * @brief Get max window height from start options.
 *
 * @param startOptions The options to get max window height from.
 * @param maxWindowHeight The obtained max window height.
 * @return The error code.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID} if the startOptions is invalid.
 * @since 17
 */
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsMaxWindowHeight(
    AbilityRuntime_StartOptions *startOptions, int32_t &maxWindowHeight);

#ifdef __cplusplus
} // extern "C"
#endif

/** @} */
#endif // ABILITY_RUNTIME_START_OPTIONS_H