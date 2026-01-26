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

#include "info/application_target_sdk_version.h"
#include <cstddef>
#include "stdbool.h"
#include "stdint.h"

#include "oh_window_comm.h"
#include "multimodalinput/oh_input_manager.h"

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
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 15
 */
int32_t OH_WindowManager_SetWindowStatusBarEnabled(int32_t windowId, bool enabled, bool enableAnimation)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Set status bar content color.
 *
 * @param windowId WindowId when window is created.
 * @param color The color value to set, the format is ARGB.
 * @return Returns the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 15
 */
int32_t OH_WindowManager_SetWindowStatusBarColor(int32_t windowId, int32_t color)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Set whether to show navigation bar.
 *
 * @param windowId WindowId when window is created.
 * @param enabled If true, the navigation bar is displayed. If false, the navigation bar is hidden.
 * @param enableAnimation If true, the navigation bar is displayed and hidden with animation.
 *                        If false, the navigation bar is displayed and hidden with no animation.
 * @return Returns the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 15
 */
int32_t OH_WindowManager_SetWindowNavigationBarEnabled(int32_t windowId, bool enabled, bool enableAnimation)
__attribute__((__availability__(ohos, introduced=15.0.0)));

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
    int32_t windowId, WindowManager_AvoidAreaType type, WindowManager_AvoidArea* avoidArea)
    __attribute__((__availability__(ohos, introduced=15.0.0)));

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
int32_t OH_WindowManager_IsWindowShown(int32_t windowId, bool* isShow)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Show window.
 *
 * @param windowId WindowId when window is created.
 * @return Returns the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 15
 */
int32_t OH_WindowManager_ShowWindow(int32_t windowId) __attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Set window touchable
 *
 * @param windowId WindowId when window is created.
 * @param isTouchable Indicates whether the specified window can be touched.
 * @return Returns the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 15
 */
int32_t OH_WindowManager_SetWindowTouchable(int32_t windowId, bool isTouchable)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Set focusable property of window.
 *
 * @param windowId WindowId when window is created.
 * @param isFocusable Window can be focused or not.
 * @return Returns the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 15
 */
int32_t OH_WindowManager_SetWindowFocusable(int32_t windowId, bool isFocusable)
__attribute__((__availability__(ohos, introduced=15.0.0)));

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
int32_t OH_WindowManager_SetWindowBackgroundColor(int32_t windowId, const char* color)
__attribute__((__availability__(ohos, introduced=15.0.0)));

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
int32_t OH_WindowManager_SetWindowBrightness(int32_t windowId, float brightness)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Sets whether keep screen on or not.
 *
 * @param windowId WindowId when window is created.
 * @param isKeepScreenOn keep screen on if true, or not if false.
 * @return Returns the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 15
 */
int32_t OH_WindowManager_SetWindowKeepScreenOn(int32_t windowId, bool isKeepScreenOn)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Sets whether is private mode or not.
 *
 * @permission {@code ohos.permission.PRIVACY_WINDOW}
 * @param windowId WindowId when window is created.
 * @param isPrivacy In private mode if true, or not if false.
 * @return Returns the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 *         {@link WINDOW_MANAGER_ERRORCODE_NO_PERMISSION} permission verification failed.
 * @since 15
 */
int32_t OH_WindowManager_SetWindowPrivacyMode(int32_t windowId, bool isPrivacy)
__attribute__((__availability__(ohos, introduced=15.0.0)));

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
    int32_t windowId, WindowManager_WindowProperties* windowProperties)
    __attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Obtains snapshot of window.
 *
 * @param windowId windowId when window is created.
 * @param pixelMap snapshot of window.
 * @return Returns the result code.
 *         {@link OK} the function call is successful, return pixel map ptr in pixelMap.
 *         {@link WINDOW_MANAGER_ERRORCODE_INVALID_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 15
 */
int32_t OH_WindowManager_Snapshot(int32_t windowId, OH_PixelmapNative* pixelMap)
__attribute__((__availability__(ohos, introduced=15.0.0)));

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
    WindowManager_Rect** windowLayoutInfoList, size_t* windowLayoutInfoSize)
    __attribute__((__availability__(ohos, introduced=17.0.0)));

/**
 * @brief Release the memory of window layout info list.
 *
 * @param windowLayoutInfoList Pointer to the layout information of the visible windows on the specified screen.
 * @since 17
 */
void OH_WindowManager_ReleaseAllWindowLayoutInfoList(WindowManager_Rect* windowLayoutInfoList)
__attribute__((__availability__(ohos, introduced=17.0.0)));

/**
 * @brief app can inject a touchEvent to target window without Focus and zOrder changed, just send to ArkUI.
 *
 * @param windowId windowId when window is created.
 * @param touchEvent multimodal touchEvent.
 * @param windowX The position of the event relative to the abscissa of the window.
 * @param windowY The position of the event relative to the ordinate of the window.
 * @return Returns the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 20
 */
int32_t OH_WindowManager_InjectTouchEvent(
    int32_t windowId, Input_TouchEvent* touchEvent, int32_t windowX, int32_t windowY)
    __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Get all main window info on device.
 *
 * @permission ohos.permission.CUSTOM_SCREEN_CAPTURE
 * @param infoList Indicates the pointer to a main window info list.
 * @param mainWindowInfoSize The size of main window info list.
 * @return Returns the status code of the execution.
 *         {@link WS_OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_NO_PERMISSION} permission verification failed.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 21
 */
int32_t OH_WindowManager_GetAllMainWindowInfo(
    WindowManager_MainWindowInfo** infoList, size_t* mainWindowInfoSize)
    __attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Release all main window info list.
 *
 * @param infoList Pointer to the main window info list.
 * @since 21
 */
void OH_WindowManager_ReleaseAllMainWindowInfo(WindowManager_MainWindowInfo* infoList)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Callback interface for getting main windows' snapshot.
 *
 * @param snapshotPixelMapList List of windows' snapshot
 * @param snapshotListSize Size of snapshotPixelMapList
 * @since 21
 */
typedef void (*OH_WindowManager_WindowSnapshotCallback)(const OH_PixelmapNative** snapshotPixelMapList,
    size_t snapshotListSize);

/**
 * @brief Get snapshot of  the specified windows.
 *
 * @permission ohos.permission.CUSTOM_SCREEN_CAPTURE
 * @param windowIdList Main window id list for getting snapshot.
 * @param windowIdListSize Size of main window id list.
 * @param config Configuration for getting snapshot.
 * @param callback Snapshot callback object.
 * @return Returns the status code of the execution.
 *         {@link WS_OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_NO_PERMISSION} permission verification failed.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 21
 */
int32_t OH_WindowManager_GetMainWindowSnapshot(int32_t* windowIdList, size_t windowIdListSize,
    WindowManager_WindowSnapshotConfig config, OH_WindowManager_WindowSnapshotCallback callback)
    __attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Release main window snapshot list.
 *
 * @param snapshotPixelMapList Indicates the pointer of a windows' snapshot list.
 * @since 21
 */
void OH_WindowManager_ReleaseMainWindowSnapshot(const OH_PixelmapNative* snapshotPixelMapList)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Lock the mouse cursor restricting it to a specified window area, and also control whether the cursor follows
 *        movement. Only supported by the focus window; the lock is automatically released when the window loses focus.
 *
 * @permission ohos.permission.LOCK_WINDOW_CURSOR
 * @param windowId WindowId when window is created.
 * @param isCursorFollowMovement Set mouse cursor lock mode.
 *        If true:the cursor follow the mouse movement.
 *        If false:the cursor does not follow the mouse.
 * @return Returns the status code of the execution.
 *         {@link WS_OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_NO_PERMISSION} permission verification failed.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 22
 */
int32_t OH_WindowManager_LockCursor(int32_t windowId, bool isCursorFollowMovement)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Clear the window mouse cursor status. Revert to mouse cursor free movement mode.
 *
 * @permission ohos.permission.LOCK_WINDOW_CURSOR
 * @param windowId WindowId when window is created.
 * @return Returns the status code of the execution.
 *         {@link WS_OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_NO_PERMISSION} permission verification failed.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL} this window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL} the window manager service works abnormally.
 * @since 22
 */
int32_t OH_WindowManager_UnlockCursor(int32_t windowId) __attribute__((__availability__(ohos, introduced=22.0.0)));

#ifdef __cplusplus
}
#endif

#endif // OH_WINDOW_H
/** @} */
