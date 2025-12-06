/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
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
 * @brief Provides  abilities of windowManager on the native side, such as key event
 * filtration.
 *
 * @since 12
 */

/**
 * @file oh_window_event_filter.h
 *
 * @brief Declares APIs for window event filter
 *
 * @syscap SystemCapability.Window.SessionManager
 * @library libnative_window_manager.so
 * @kit ArkUI
 * @since 12
 */

#ifndef INCLUDE_OH_WINDOW_EVENT_FILTER_H
#define INCLUDE_OH_WINDOW_EVENT_FILTER_H

#include "stdbool.h"
#include "stdint.h"
#include "oh_window_comm.h"
#include "multimodalinput/oh_input_manager.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines a function for filtering multimodal key events
 * @param keyEvent multimodal keyEvent
 * @since 12
 */
typedef bool (*OH_NativeWindowManager_KeyEventFilter)(Input_KeyEvent* keyEvent);

/**
 * @brief Registers a function for filtering multimodal key events
 *
 * @param windowId windowId when window is created
 * @param keyEventFilter key event callback ,called when the window is dispatched
 * to the event
 * @return Returns the status code of the execution.
 * @since 12
 */
WindowManager_ErrorCode OH_NativeWindowManager_RegisterKeyEventFilter(int32_t windowId,
    OH_NativeWindowManager_KeyEventFilter keyEventFilter);

/**
 * @brief Unregisters a function for filtering multimodal key events
 *
 * @param windowId windowId when window is created
 * @return Returns the status code of the execution.
 * @since 12
 */
WindowManager_ErrorCode OH_NativeWindowManager_UnregisterKeyEventFilter(int32_t windowId);

/**
 * @brief Defines a function for filtering multimodal mouse events
 * @param mouseEvent multimodal mouseEvent
 * @since 15
 */
typedef bool (*OH_NativeWindowManager_MouseEventFilter)(Input_MouseEvent* mouseEvent);

/**
 * @brief Registers a function for filtering multimodal mouse events
 *
 * @param windowId windowId when window is created
 * @param mouseEventFilter mouse event callback, called when the window is dispatched
 * to the event
 * @return Returns the status code of the execution.
 *         Returns {@link OK} if the operation is successful.
 *         Returns {@link INVAILD_WINDOW_ID} if the window id is invalid.
 *         Returns {@link SERVICE_ERROR} if the window manager service error occurs.
 * @since 15
 */
WindowManager_ErrorCode OH_NativeWindowManager_RegisterMouseEventFilter(int32_t windowId,
    OH_NativeWindowManager_MouseEventFilter mouseEventFilter);

/**
 * @brief Unregisters a function for filtering multimodal mouse events
 *
 * @param windowId windowId when window is created
 * @return Returns the status code of the execution.
 *         Returns {@link OK} if the operation is successful.
 *         Returns {@link INVAILD_WINDOW_ID} if the window id is invalid.
 *         Returns {@link SERVICE_ERROR} if the window manager service error occurs.
 * @since 15
 */
WindowManager_ErrorCode OH_NativeWindowManager_UnregisterMouseEventFilter(int32_t windowId);

/**
 * @brief Defines a function for filtering multimodal touch events
 * @param touchEvent multimodal touchEvent
 * @since 15
 */
typedef bool (*OH_NativeWindowManager_TouchEventFilter)(Input_TouchEvent* touchEvent);

/**
 * @brief Registers a function for filtering multimodal touch events
 *
 * @param windowId windowId when window is created
 * @param touchEventFilter touch event callback, called when the window is dispatched
 * to the event
 * @return Returns the status code of the execution.
 *         Returns {@link OK} if the operation is successful.
 *         Returns {@link INVAILD_WINDOW_ID} if the window id is invalid.
 *         Returns {@link SERVICE_ERROR} if the window manager service error occurs.
 * @since 15
 */
WindowManager_ErrorCode OH_NativeWindowManager_RegisterTouchEventFilter(int32_t windowId,
    OH_NativeWindowManager_TouchEventFilter touchEventFilter);

/**
 * @brief Unregisters a function for filtering multimodal touch events
 *
 * @param windowId windowId when window is created
 * @return Returns the status code of the execution.
 *         Returns {@link OK} if the operation is successful.
 *         Returns {@link INVAILD_WINDOW_ID} if the window id is invalid.
 *         Returns {@link SERVICE_ERROR} if the window manager service error occurs.
 * @since 15
 */
WindowManager_ErrorCode OH_NativeWindowManager_UnregisterTouchEventFilter(int32_t windowId);

#ifdef __cplusplus
}
#endif

#endif // INCLUDE_OH_WINDOW_EVENT_FILTER_H
/** @} */