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

#ifndef OH_NATIVE_DISPLAY_MANAGER_H
#define OH_NATIVE_DISPLAY_MANAGER_H

/**
 * @addtogroup OH_DisplayManager
 * @{
 *
 * @brief Defines the data structures for the C APIs of the display module.
 *
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 * @version 1.0
 */

/**
 * @file oh_display_manager.h
 *
 * @brief Defines the data structures for the C APIs of the display module.
 *
 * @kit ArkUI
 * @library libnative_display_manager.so.
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 * @version 1.0
 */

#include "oh_display_info.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Obtain the default display Id.
 *
 * @param { *displayId } Indicates the pointer to an <b>uint64_t</b> object.
 * @return { @link DISPLAY_MANAGER_OK } If the operation is successful
 *         { @link DISPLAY_MANAGER_ERROR_INVALID_PARAM } If Parameter error.
 *         { @link DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL } If display manager service works abnormally.
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 */
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayId(uint64_t *displayId);

/**
 * @brief Obtain the default display width.
 *
 * @param { *displayWidth } Indicates the pointer to an <b>int32_t</b> object.
 * @return { @link DISPLAY_MANAGER_OK } If the operation is successful
 *         { @link DISPLAY_MANAGER_ERROR_INVALID_PARAM } If Parameter error.
 *         { @link DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL } If display manager service works abnormally.
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 */
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayWidth(int32_t *displayWidth);

/**
 * @brief Obtain the default display height.
 *
 * @param { *displayHeight } Indicates the pointer to an <b>int32_t</b> object.
 * @return { @link DISPLAY_MANAGER_OK } If the operation is successful
 *         { @link DISPLAY_MANAGER_ERROR_INVALID_PARAM } If Parameter error.
 *         { @link DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL } If display manager service works abnormally.
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 */
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayHeight(int32_t *displayHeight);

/**
 * @brief Obtain the default display rotation.
 *
 * @param { *displayRotation } Indicates the pointer to an <b>NativeDisplayManager_Rotation</b> object.
 * @return { @link DISPLAY_MANAGER_OK } If the operation is successful
 *         { @link DISPLAY_MANAGER_ERROR_INVALID_PARAM } If Parameter error.
 *         { @link DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL } If display manager service works abnormally.
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 */
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayRotation(
    NativeDisplayManager_Rotation *displayRotation);

/**
 * @brief Obtain the default display orientation.
 *
 * @param { *displayOrientation } Indicates the pointer to an <b>NativeDisplayManager_Orientation</b> object.
 * @return { @link DISPLAY_MANAGER_OK } If the operation is successful
 *         { @link DISPLAY_MANAGER_ERROR_INVALID_PARAM } If Parameter error.
 *         { @link DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL } If display manager service works abnormally.
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 */
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayOrientation(
    NativeDisplayManager_Orientation *displayOrientation);

/**
 * @brief Obtain the default display virtualPixels.
 *
 * @param { *virtualPixels } Indicates the pointer to an <b>float</b> object.
 * @return { @link DISPLAY_MANAGER_OK } If the operation is successful
 *         { @link DISPLAY_MANAGER_ERROR_INVALID_PARAM } If Parameter error.
 *         { @link DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL } If display manager service works abnormally.
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 */
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayVirtualPixelRatio(float *virtualPixels);

/**
 * @brief Obtain the default display refreshRate.
 *
 * @param { *refreshRate } Indicates the pointer to an <b>uint32_t</b> object.
 * @return { @link DISPLAY_MANAGER_OK } If the operation is successful
 *         { @link DISPLAY_MANAGER_ERROR_INVALID_PARAM } If Parameter error.
 *         { @link DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL } If display manager service works abnormally.
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 */
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayRefreshRate(uint32_t *refreshRate);

/**
 * @brief Obtain the default display densityDpi.
 *
 * @param { *densityDpi } Indicates the pointer to an <b>int32_t</b> object.
 * @return { @link DISPLAY_MANAGER_OK } If the operation is successful
 *         { @link DISPLAY_MANAGER_ERROR_INVALID_PARAM } If Parameter error.
 *         { @link DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL } If display manager service works abnormally.
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 */
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayDensityDpi(int32_t *densityDpi);

/**
 * @brief Obtain the default display densityPixels.
 *
 * @param { *densityPixels } Indicates the pointer to an <b>float</b> object.
 * @return { @link DISPLAY_MANAGER_OK } If the operation is successful
 *         { @link DISPLAY_MANAGER_ERROR_INVALID_PARAM } If Parameter error.
 *         { @link DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL } If display manager service works abnormally.
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 */
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayDensityPixels(float *densityPixels);

/**
 * @brief Obtain the default display scaledDensity.
 *
 * @param { *scaledDensity } Indicates the pointer to an <b>float</b> object.
 * @return { @link DISPLAY_MANAGER_OK } If the operation is successful
 *         { @link DISPLAY_MANAGER_ERROR_INVALID_PARAM } If Parameter error.
 *         { @link DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL } If display manager service works abnormally.
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 */
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayScaledDensity(float *scaledDensity);

/**
 * @brief Obtain the default display xDpi.
 *
 * @param { *xDpi } Indicates the pointer to an <b>float</b> object.
 * @return { @link DISPLAY_MANAGER_OK } If the operation is successful
 *         { @link DISPLAY_MANAGER_ERROR_INVALID_PARAM } If Parameter error.
 *         { @link DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL } If display manager service works abnormally.
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 */
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayDensityXdpi(float *xDpi);

/**
 * @brief Obtain the default display yDpi.
 *
 * @param { *yDpi } Indicates the pointer to an <b>float</b> object.
 * @return { @link DISPLAY_MANAGER_OK } If the operation is successful
 *         { @link DISPLAY_MANAGER_ERROR_INVALID_PARAM } If Parameter error.
 *         { @link DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL } If display manager service works abnormally.
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 */
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayDensityYdpi(float *yDpi);

/**
 * @brief Create the cutout info of the device.
 *
 * @param { **cutoutInfo } Indicates the pointer to an <b>NativeDisplayManager_CutoutInfo</b> object.
 * @return { @link DISPLAY_MANAGER_OK } If the operation is successful
 *         { @link DISPLAY_MANAGER_ERROR_INVALID_PARAM } If Parameter error.
 *         { @link DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL } If display manager service works abnormally.
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 */
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo(
    NativeDisplayManager_CutoutInfo **cutoutInfo);

/**
 * @brief Destroy an <b>NativeDisplayManager_CutoutInfo</b> object and reclaims the memory occupied by the object.
 *
 * @param { **cutoutInfo } Indicates the pointer to an <b>NativeDisplayManager_CutoutInfo</b> object.
 * @return { @link DISPLAY_MANAGER_OK } If the operation is successful
 *         { @link DISPLAY_MANAGER_ERROR_INVALID_PARAM } If Parameter error.
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 */
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_DestroyDefaultDisplayCutoutInfo(
    NativeDisplayManager_CutoutInfo *cutoutInfo);

/**
 * @brief Check whether the device is foldable.
 *
 * @return { bool } true means the device is foldable.
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 */
bool OH_NativeDisplayManager_IsFoldable();

/**
 * @brief Get the display mode of the foldable device.
 *
 * @param { *displayMode } Indicates the pointer to an <b>NativeDisplayManager_FoldDisplayMode</b> object.
 * @return { @link DISPLAY_MANAGER_OK } If the operation is successful
 *         { @link DISPLAY_MANAGER_ERROR_INVALID_PARAM } If Parameter error.
 *         { @link DISPLAY_MANAGER_ERROR_DEVICE_NOT_SUPPORTED } device not support.
 * @syscap SystemCapability.Window.SessionManager
 * @since 12
 */
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetFoldDisplayMode(
    NativeDisplayManager_FoldDisplayMode *displayMode);

/**
 * @brief the callback function type when display change.
 *
 * @param { *displayId } change display id.
 * @syscap SystemCapability.Window.SessionManager
 * @since 12
 */
typedef void (*OH_NativeDisplayManager_DisplayChangeCallback)(uint64_t displayId);

/**
 * @brief Register the callback for display change listener.
 *
 * @param { displayChangeCallback } display change callback.
 * @param { *listenerIndex } Indicates the pointer to an <b>uint32_t</b> object. used in unregister call.
 * @return { @link DISPLAY_MANAGER_OK } If the operation is successful
 *         { @link DISPLAY_MANAGER_ERROR_INVALID_PARAM } If Parameter error.
 *         { @link DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL } If display manager service works abnormally.
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 */
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_RegisterDisplayChangeListener(
    OH_NativeDisplayManager_DisplayChangeCallback displayChangeCallback, uint32_t *listenerIndex);

/**
 * @brief Unregister the callback for display changes listener.
 *
 * @param { listenerIndex } display changed listener index.
 * @return { @link DISPLAY_MANAGER_OK } If the operation is successful
 *         { @link DISPLAY_MANAGER_ERROR_INVALID_PARAM } If Parameter error.
 *         { @link DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL } If display manager service works abnormally.
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 */
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_UnregisterDisplayChangeListener(uint32_t listenerIndex);

/**
 * @brief the callback function type when display fold change.
 *
 * @param { displayMode } current fold display mode.
 * @syscap SystemCapability.Window.SessionManager
 * @since 12
 */
typedef void (*OH_NativeDisplayManager_FoldDisplayModeChangeCallback)(
    NativeDisplayManager_FoldDisplayMode displayMode);

/**
 * @brief Register the callback for display mode change listener.
 *
 * @param { displayModeChangeCallback } display mode change callback.
 * @param { *listenerIndex } Indicates the pointer to an <b>uint32_t</b> object. used in unregister call.
 * @return { @link DISPLAY_MANAGER_OK } If the operation is successful
 *         { @link DISPLAY_MANAGER_ERROR_INVALID_PARAM } If Parameter error.
 *         { @link DISPLAY_MANAGER_ERROR_DEVICE_NOT_SUPPORTED } device not support.
 *         { @link DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL } If display manager service works abnormally.
 * @syscap SystemCapability.Window.SessionManager
 * @since 12
 */
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener(
    OH_NativeDisplayManager_FoldDisplayModeChangeCallback displayModeChangeCallback, uint32_t *listenerIndex);

/**
 * @brief Unregister the callback for display mode change listener.
 *
 * @param { listenerIndex } display mode change listener index.
 * @return { @link DISPLAY_MANAGER_OK } If the operation is successful
 *         { @link DISPLAY_MANAGER_ERROR_INVALID_PARAM } If Parameter error.
 *         { @link DISPLAY_MANAGER_ERROR_DEVICE_NOT_SUPPORTED } device not support.
 *         { @link DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL } If display manager service works abnormally.
 * @syscap SystemCapability.Window.SessionManager
 * @since 12
 */
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener(uint32_t listenerIndex);

#ifdef __cplusplus
}
#endif
/** @} */
#endif // OH_NATIVE_DISPLAY_MANAGER_H
