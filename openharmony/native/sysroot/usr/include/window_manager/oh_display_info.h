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

#ifndef OH_NATIVE_DISPLAY_INFO_H
#define OH_NATIVE_DISPLAY_INFO_H

/**
 * @addtogroup OH_DisplayInfo
 * @{
 *
 * @brief Defines the data structures for the C APIs of the display module.
 *
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 * @version 1.0
 */

/**
 * @file oh_display_info.h
 *
 * @brief Defines the data structures for the C APIs of the display module.
 *
 * @kit ArkUI
 * @library libnative_display_manager.so
 * @syscap SystemCapability.WindowManager.WindowManager.Core
 * @since 12
 * @version 1.0
 */

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates rotations.
 *
 * @since 12
 * @version 1.0
 */
typedef enum {
    /** device rotation 0 degree */
    DISPLAY_MANAGER_ROTATION_0,

    /** device rotation 90 degrees */
    DISPLAY_MANAGER_ROTATION_90,

    /** device rotation 180 degrees */
    DISPLAY_MANAGER_ROTATION_180,

    /** device rotation 270 degree */
    DISPLAY_MANAGER_ROTATION_270,
} NativeDisplayManager_Rotation;

/**
 * @brief Enumerates orientations.
 *
 * @since 12
 * @version 1.0
 */
typedef enum {
    /** device portrait show */
    DISPLAY_MANAGER_PORTRAIT = 0,

    /** device landscape show */
    DISPLAY_MANAGER_LANDSCAPE = 1,

    /** device portrait inverted show */
    DISPLAY_MANAGER_PORTRAIT_INVERTED = 2,

    /** device landscape inverted show */
    DISPLAY_MANAGER_LANDSCAPE_INVERTED = 3,

    /** device unknow show */
    DISPLAY_MANAGER_UNKNOWN,
} NativeDisplayManager_Orientation;

/**
 * @brief Enumerates the result types of the display manager interface.
 *
 * @since 12
 * @version 1.0
 */
typedef enum {
    /** @error Operation is successful */
    DISPLAY_MANAGER_OK = 0,

    /** @error Operation no permission */
    DISPLAY_MANAGER_ERROR_NO_PERMISSION = 201,

    /** @error Operation not system app */
    DISPLAY_MANAGER_ERROR_NOT_SYSTEM_APP = 202,

    /** @error Operation invalid param */
    DISPLAY_MANAGER_ERROR_INVALID_PARAM = 401,

    /** @error Operation device not supported */
    DISPLAY_MANAGER_ERROR_DEVICE_NOT_SUPPORTED = 801,

    /** @error Operation screen invalid */
    DISPLAY_MANAGER_ERROR_INVALID_SCREEN = 1400001,

    /** @error Operation invalid call */
    DISPLAY_MANAGER_ERROR_INVALID_CALL = 1400002,

    /** @error Operation system abnormal */
    DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL = 1400003,
} NativeDisplayManager_ErrorCode;

/**
 * @brief Enumerates the fold display mode.
 *
 * @since 12
 * @version 1.0
 */
typedef enum {
    /** display mode unknown */
    DISPLAY_MANAGER_FOLD_DISPLAY_MODE_UNKNOWN = 0,

    /** display mode full */
    DISPLAY_MANAGER_FOLD_DISPLAY_MODE_FULL = 1,

    /** display mode main */
    DISPLAY_MANAGER_FOLD_DISPLAY_MODE_MAIN = 2,

    /** display mode sub */
    DISPLAY_MANAGER_FOLD_DISPLAY_MODE_SUB = 3,

    /** display mode coordination */
    DISPLAY_MANAGER_FOLD_DISPLAY_MODE_COORDINATION = 4,
} NativeDisplayManager_FoldDisplayMode;

/**
 * @brief Defines the display rect data structure.
 *
 * @since 12
 * @version 1.0
 */
typedef struct {
    /* rect left */
    int32_t left;
    /* rect top */
    int32_t top;
    /* rect width */
    uint32_t width;
    /* rect height */
    uint32_t height;
} NativeDisplayManager_Rect;

/**
 * @brief Defines the display waterfallDisplayAreaRects data structure.
 *
 * @since 12
 * @version 1.0
 */
typedef struct {
    /* waterfall left rect */
    NativeDisplayManager_Rect left;

    /* waterfall top rect */
    NativeDisplayManager_Rect top;

    /* waterfall right rect */
    NativeDisplayManager_Rect right;

    /* waterfall bottom rect */
    NativeDisplayManager_Rect bottom;
} NativeDisplayManager_WaterfallDisplayAreaRects;

/**
 * @brief Defines the display cutout info data structure.
 *
 * @since 12
 * @version 1.0
 */
typedef struct {
    /* boundingRects length */
    int32_t boundingRectsLength;

    /* boundingRects info pointer */
    NativeDisplayManager_Rect *boundingRects;

    /* waterfallDisplayAreaRects info */
    NativeDisplayManager_WaterfallDisplayAreaRects waterfallDisplayAreaRects;
} NativeDisplayManager_CutoutInfo;

#ifdef __cplusplus
}
#endif
/** @} */
#endif // OH_NATIVE_DISPLAY_INFO_H