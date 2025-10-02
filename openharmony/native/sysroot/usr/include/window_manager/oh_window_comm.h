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
 *
 * @brief Provides abilities of windowManager on the native side, such as key event
 * filtration.
 *
 * @since 12
 */

/**
 * @file oh_window_comm.h
 *
 * @brief Provides the comm type definitions of windowManager on the native side.
 *
 * @syscap SystemCapability.Window.SessionManager
 * @library libnative_window_manager.so
 * @kit ArkUI
 * @since 12
 */
#ifndef OH_WINDOW_COMM_H
#define OH_WINDOW_COMM_H

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief The native pixel map information defined by Image Kit.
 *
 * @since 15
 */
typedef struct OH_PixelmapNative;

/**
 * @brief Enumerates the result types of the wm interface
 *
 * @since 12
 */
typedef enum {
    /** succ. */
    OK = 0,
    /**
     * @error No permission.
     *
     * @since 15
     */
    WINDOW_MANAGER_ERRORCODE_NO_PERMISSION = 201,
    /**
     * @error Param is invalid.
     *
     * @since 15
     */
    WINDOW_MANAGER_ERRORCODE_INVALID_PARAM = 401,
    /**
     * @error Device not support.
     *
     * @since 15
     */
    WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED = 801,
    /** window id is invaild. */
    INVAILD_WINDOW_ID = 1000,
    /** failed. */
    SERVICE_ERROR = 2000,
    /**
     * @error Window state is abnormal.
     *
     * @since 15
     */
    WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL = 1300002,
    /**
     * @error Window manager service works abnormally.
     *
     * @since 15
     */
    WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL = 1300003,
} WindowManager_ErrorCode;

/**
 * @brief Enumerates the avoid area types.
 *
 * @since 15
 */
typedef enum {
    /** System. */
    WINDOW_MANAGER_AVOID_AREA_TYPE_SYSTEM = 0,
    /** Cutout. */
    WINDOW_MANAGER_AVOID_AREA_TYPE_CUTOUT = 1,
    /** System gesture. */
    WINDOW_MANAGER_AVOID_AREA_TYPE_SYSTEM_GESTURE = 2,
    /** Keyboard. */
    WINDOW_MANAGER_AVOID_AREA_TYPE_KEYBOARD = 3,
    /** Navigation indicator. */
    WINDOW_MANAGER_AVOID_AREA_TYPE_NAVIGATION_INDICATOR = 4,
} WindowManager_AvoidAreaType;

/**
 * @brief The type of a window
 *
 * @since 15
 */
typedef enum {
    /** Sub window. */
    WINDOW_MANAGER_WINDOW_TYPE_APP = 0,
    /** Main window. */
    WINDOW_MANAGER_WINDOW_TYPE_MAIN = 1,
    /** Float. */
    WINDOW_MANAGER_WINDOW_TYPE_FLOAT = 8,
    /** Dialog. */
    WINDOW_MANAGER_WINDOW_TYPE_DIALOG = 16,
} WindowManager_WindowType;

/**
 * @brief Defines the window rect data structure.
 *
 * @since 15
 */
typedef struct {
    /** X-axis of the window. */
    int32_t posX;
    /** Y-axis of the window. */
    int32_t posY;
    /** Width of the window. */
    uint32_t width;
    /** Height of the window. */
    uint32_t height;
} WindowManager_Rect;

/**
 * @brief Properties of window
 *
 * @since 15
*/
typedef struct {
    /** The position and size of the window. */
    WindowManager_Rect windowRect;
    /** The position relative to the window and size of drawable area. */
    WindowManager_Rect drawableRect;
    /** Window type. */
    WindowManager_WindowType type;
    /** Whether the window is displayed in full screen mode. The default value is false. */
    bool isFullScreen;
    /** Whether the window layout is full screen mode. The default value is false. */
    bool isLayoutFullScreen;
    /** Whether the window can gain focus. The default value is true. */
    bool focusable;
    /** Whether the window is touchable. The default value is false. */
    bool touchable;
    /** Brightness value of window. */
    float brightness;
    /** Whether keep screen on. */
    bool isKeepScreenOn;
    /** Whether make window in privacy mode or not. */
    bool isPrivacyMode;
    /** Whether is transparent or not. */
    bool isTransparent;
    /** Window id. */
    uint32_t id;
    /** Display id. */
    uint32_t displayId;
} WindowManager_WindowProperties;

/**
 * @brief Defines the avoid area data structure.
 *
 * @since 15
 */
typedef struct {
    /** Top rect of the avoid area. */
    WindowManager_Rect topRect;
    /** Left rect of the avoid area. */
    WindowManager_Rect leftRect;
    /** Right rect of the avoid area. */
    WindowManager_Rect rightRect;
    /** Bottom rect of the avoid area. */
    WindowManager_Rect bottomRect;
} WindowManager_AvoidArea;

#ifdef __cplusplus
}
#endif

#endif // OH_WINDOW_COMM_H
/** @} */