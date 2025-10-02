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
 * @addtogroup WindowManager
 * @{
 *
 * @brief Provides abilities of window on the native side.
 * @since 15
 */

/**
 * @file oh_window.h
 *
 * @brief Declares APIs for window
 *
 * @library libnative_window_manager.so
 * @kit ArkUI
 * @syscap SystemCapability.Window.SessionManager
 * @since 15
 */
#ifndef OH_WINDOW_H
#define OH_WINDOW_H

#include "stdbool.h"
#include "stdint.h"

#include "oh_window_comm.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Set whether to show status bar.
 *
 * @param windowId WindowId when window is created.
 * @param enabled If true, the status bar is displayed. If false, the status bar is hidden.
 * @param enableAnimation If true, the status bar is displayed and hidden with animation.
 *                        If false, the status bar is displayed and hidden with no animation.
 * @return Returns the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INVALID_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 15
 */
int32_t OH_WindowManager_SetWindowStatusBarEnabled(int32_t windowId, bool enabled, bool enableAnimation);

/**
 * @brief Set status bar content color.
 *
 * @param windowId WindowId when window is created.
 * @param color The color value to set, the format is ARGB.
 * @return Returns the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INVALID_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 15
 */
int32_t OH_WindowManager_SetWindowStatusBarColor(int32_t windowId, int32_t color);

/**
 * @brief Set whether to show navigation bar.
 *
 * @param windowId WindowId when window is created.
 * @param enabled If true, the navigation bar is displayed. If false, the navigation bar is hidden.
 * @param enableAnimation If true, the navigation bar is displayed and hidden with animation.
 *                        If false, the navigation bar is displayed and hidden with no animation.
 * @return Returns the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INVALID_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 15
 */
int32_t OH_WindowManager_SetWindowNavigationBarEnabled(int32_t windowId, bool enabled, bool enableAnimation);

/**
 * @brief Get the avoid area
 *
 * @param windowId WindowId when window is created.
 * @param type Type of the avoid area.
 * @param avoidArea Indicates the pointer to a WindowManager_AvoidArea object.
 * @return Returns the result code.
 *         {@link OK} the function call is successful, return avoid area ptr in avoidArea.
 *         {@link WINDOW_MANAGER_ERRORCODE_INVALID_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 15
 */
int32_t OH_WindowManager_GetWindowAvoidArea(
    int32_t windowId, WindowManager_AvoidAreaType type, WindowManager_AvoidArea* avoidArea);

/**
 * @brief Checks whether the window is displayed.
 *
 * @param windowId WindowId when window is created.
 * @param isShow Whether the window is displayed. The value true means that the window is displayed, and false means the opposite.
 * @return Returns the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INVALID_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 * @since 15
 */
int32_t OH_WindowManager_IsWindowShown(int32_t windowId, bool* isShow);

/**
 * @brief Show window.
 *
 * @param windowId WindowId when window is created.
 * @return Returns the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INVALID_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 15
 */
int32_t OH_WindowManager_ShowWindow(int32_t windowId);

/**
 * @brief Set window touchable
 *
 * @param windowId WindowId when window is created.
 * @param isTouchable Indicates whether the specified window can be touched.
 * @return Returns the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INVALID_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 15
 */
int32_t OH_WindowManager_SetWindowTouchable(int32_t windowId, bool isTouchable);

/**
 * @brief Set focusable property of window.
 *
 * @param windowId WindowId when window is created.
 * @param isFocusable Window can be focused or not.
 * @return Returns the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INVALID_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 15
 */
int32_t OH_WindowManager_SetWindowFocusable(int32_t windowId, bool isFocusable);

/**
 * @brief Sets the background color of window.
 *
 * @param windowId WindowId when window is created.
 * @param color the specified color.
 * @return Returns the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INVALID_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 * @since 15
 */
int32_t OH_WindowManager_SetWindowBackgroundColor(int32_t windowId, const char* color);

/**
 * @brief Sets the brightness of window.
 *
 * @param windowId WindowId when window is created.
 * @param brightness the specified brightness value.
 * @return Returns the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INVALID_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 15
 */
int32_t OH_WindowManager_SetWindowBrightness(int32_t windowId, float brightness);

/**
 * @brief Sets whether keep screen on or not.
 *
 * @param windowId WindowId when window is created.
 * @param isKeepScreenOn keep screen on if true, or not if false.
 * @return Returns the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INVALID_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 15
 */
int32_t OH_WindowManager_SetWindowKeepScreenOn(int32_t windowId, bool isKeepScreenOn);

/**
 * @brief Sets whether is private mode or not.
 *
 * @permission {@code ohos.permission.PRIVACY_WINDOW}
 * @param windowId WindowId when window is created.
 * @param isPrivacy In private mode if true, or not if false.
 * @return Returns the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INVALID_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 *         {@link WINDOW_MANAGER_ERRORCODE_NO_PERMISSION} permission verification failed.
 * @since 15
 */
int32_t OH_WindowManager_SetWindowPrivacyMode(int32_t windowId, bool isPrivacy);

/**
 * @brief Get the properties of current window.
 *
 * @param windowId WindowId when window is created.
 * @param windowProperties Properties of current window.
 * @return Returns the result code.
 *         {@link OK} the function call is successful, return window properties ptr in windowProperties.
 *         {@link WINDOW_MANAGER_ERRORCODE_INVALID_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 * @since 15
 */
int32_t OH_WindowManager_GetWindowProperties(
    int32_t windowId, WindowManager_WindowProperties* windowProperties);

/**
 * @brief Obtains snapshot of window.
 *
 * @param windowId windowId when window is created.
 * @param pixelMap snapshot of window.
 * @return Returns the result code.
 *         {@link OK} the function call is successful, return pixel map ptr in pixelMap.
 *         {@link WINDOW_MANAGER_ERRORCODE_INVALID_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 15
 */
int32_t OH_WindowManager_Snapshot(int32_t windowId, OH_PixelmapNative* pixelMap);

/**
 * @brief Get layout info of all windows on the selected display.
 *
 * @param displayId Indicate the id of display.
 * @param windowLayoutInfoList Pointer to the layout information of the visible windows on the specified screen.
 * @param windowLayoutInfoSize Pointer to the size of the array of layout information of the visible windows on the
 * specified screen.
 * @return Returns the result code.
 *         {@link OK} the function call is successful, return Window layout info list.
 *         {@link WINDOW_MANAGER_ERRORCODE_INVALID_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 17
 */
int32_t OH_WindowManager_GetAllWindowLayoutInfoList(int64_t displayId,
    WindowManager_Rect** windowLayoutInfoList, size_t* windowLayoutInfoSize);

/**
 * @brief Release the memory of window layout info list.
 *
 * @param windowLayoutInfoList Pointer to the layout information of the visible windows on the specified screen.
 * @since 17
 */
void OH_WindowManager_ReleaseAllWindowLayoutInfoList(WindowManager_Rect* windowLayoutInfoList);

#ifdef __cplusplus
}
#endif

#endif // OH_WINDOW_H
/** @} */