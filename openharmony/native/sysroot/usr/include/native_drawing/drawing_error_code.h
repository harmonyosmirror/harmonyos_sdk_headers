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
 * @addtogroup Drawing
 * @{
 *
 * @brief Provides functions such as 2D graphics rendering, text drawing, and image display.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 *
 * @since 8
 * @version 1.0
 */

/**
 * @file drawing_error_code.h
 *
 * @brief Declares functions related to the error code in the drawing module.
 *
 * @kit ArkGraphics2D
 * @library libnative_drawing.so
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @since 12
 * @version 1.0
 */

#ifndef C_INCLUDE_DRAWING_ERROR_CODE_H
#define C_INCLUDE_DRAWING_ERROR_CODE_H

#include "info/application_target_sdk_version.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates error codes of drawing.
 * @since 12
 */
typedef enum {
    /**
     * @error Operation completed successfully.
     */
    OH_DRAWING_SUCCESS = 0,
    /**
     * @error Permission verification failed.
     */
    OH_DRAWING_ERROR_NO_PERMISSION = 201,
    /**
     * @error Invalid input parameter. For example, the pointer in the parameter is a nullptr.
     */
    OH_DRAWING_ERROR_INVALID_PARAMETER = 401,
    /**
     * @error The parameter is not in the valid range.
     */
    OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE = 26200001,
    /**
     * @error mem allocate failed.
     * @since 13
     */
    OH_DRAWING_ERROR_ALLOCATION_FAILED = 26200002,
    /**
     * @error The attribute id is not recognized or supported.
     * @since 21
     */
    OH_DRAWING_ERROR_ATTRIBUTE_ID_MISMATCH = 26200003,
    /**
     * @error incorrect input parameter. The possible cause is that the provided pointer is null.
     * @since 22
     */
    OH_DRAWING_ERROR_INCORRECT_PARAMETER = 26200004,
    /**
     * @error File not found. The specified file does not exist or the path is incorrect..
     * @since 23
     */
    OH_DRAWING_ERROR_FILE_NOT_FOUND = 26200005,
    /**
    * @error Failed to open the file. The file cannot be opened due to permission or I/O issues.
    * @since 23
    */
    OH_DRAWING_ERROR_OPEN_FILE_FAILED = 26200006,
    /**
    * @error File seek failed. The system failed to reposition the file read pointer..
    * @since 23
    */
    OH_DRAWING_ERROR_FILE_SEEK_FAILED = 26200007,
    /**
    * @error Failed to get the file size. The system was unable to obtain the file size information.
    * @since 23
    */
    OH_DRAWING_ERROR_GET_FILE_SIZE_FAILED = 26200008,
    /**
    * @error Failed to read the file. The file could not be read completely or contains unreadable data.
    * @since 23
    */
    OH_DRAWING_ERROR_READ_FILE_FAILED = 26200009,
    /**
    * @error Empty file. The specified file is empty and contains no valid data.
    * @since 23
    */
    OH_DRAWING_ERROR_EMPTY_FILE = 26200010,
    /**
    * @error Corrupted file. The file content is invalid or damaged and cannot be parsed.
    * @since 23
    */
    OH_DRAWING_ERROR_FILE_CORRUPTED = 26200011,
} OH_Drawing_ErrorCode;

/**
 * @brief Obtains the error code of the drawing module.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @return Returns the error code.
 * @since 12
 * @version 1.0
 */
OH_Drawing_ErrorCode OH_Drawing_ErrorCodeGet() __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Resets the error code of the drawing module to OH_DRAWING_SUCCESS.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @since 18
 * @version 1.0
 */
void OH_Drawing_ErrorCodeReset(void) __attribute__((__availability__(ohos, introduced=18.0.0)));
#ifdef __cplusplus
}
#endif
/** @} */
#endif