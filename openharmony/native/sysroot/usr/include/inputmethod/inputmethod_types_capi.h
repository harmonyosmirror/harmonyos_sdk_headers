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
 * @addtogroup InputMethod
 * @{
 *
 * @brief InputMethod provides functions to use input methods and develop input methods.
 *
 * @since 12
 */

/**
 * @file inputmethod_types_capi.h
 *
 * @brief Provides the input method types.
 *
 * @library libohinputmethod.so
 * @kit IMEKit
 * @syscap SystemCapability.MiscServices.InputMethodFramework
 * @since 12
 * @version 1.0
 */
#ifndef OHOS_INPUTMETHOD_TYPES_CAPI_H
#define OHOS_INPUTMETHOD_TYPES_CAPI_H
#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */
/**
 * @brief Keyboard status.
 *
 * @since 12
 */
typedef enum InputMethod_KeyboardStatus {
    /**
     * The keyboard status is none.
     */
    IME_KEYBOARD_STATUS_NONE = 0,
    /**
     * The keyboard status is hide.
     */
    IME_KEYBOARD_STATUS_HIDE = 1,
    /**
     * The keyboard status is show.
     */
    IME_KEYBOARD_STATUS_SHOW = 2,
} InputMethod_KeyboardStatus;

/**
 * @brief Enter key type.
 *
 * @since 12
 */
typedef enum InputMethod_EnterKeyType {
    /**
     * The enter key type is UNSPECIFIED.
     */
    IME_ENTER_KEY_UNSPECIFIED = 0,
    /**
     * The enter key type is NONE.
     */
    IME_ENTER_KEY_NONE = 1,
    /**
     * The enter key type is GO.
     */
    IME_ENTER_KEY_GO = 2,
    /**
     * The enter key type is SEARCH.
     */
    IME_ENTER_KEY_SEARCH = 3,
    /**
     * The enter key type is SEND.
     */
    IME_ENTER_KEY_SEND = 4,
    /**
     * The enter key type is NEXT.
     */
    IME_ENTER_KEY_NEXT = 5,
    /**
     * The enter key type is DONE.
     */
    IME_ENTER_KEY_DONE = 6,
    /**
     * The enter key type is PREVIOUS.
     */
    IME_ENTER_KEY_PREVIOUS = 7,
    /**
     * The enter key type is NEWLINE.
     */
    IME_ENTER_KEY_NEWLINE = 8,
} InputMethod_EnterKeyType;

/**
 * @brief Direction.
 *
 * @since 12
 */
typedef enum InputMethod_Direction {
    /**
     * The direction is NONE.
     */
    IME_DIRECTION_NONE = 0,
    /**
     * The direction is UP.
     */
    IME_DIRECTION_UP = 1,
    /**
     * The direction is DOWN.
     */
    IME_DIRECTION_DOWN = 2,
    /**
     * The direction is LEFT.
     */
    IME_DIRECTION_LEFT = 3,
    /**
     * The direction is RIGHT.
     */
    IME_DIRECTION_RIGHT = 4,
} InputMethod_Direction;

/**
 * @brief The extend action.
 *
 * @since 12
 */
typedef enum InputMethod_ExtendAction {
    /**
     * Select all text.
     */
    IME_EXTEND_ACTION_SELECT_ALL = 0,
    /**
     * Cut selected text.
     */
    IME_EXTEND_ACTION_CUT = 3,
    /**
     * Copy selected text.
     */
    IME_EXTEND_ACTION_COPY = 4,
    /**
     * Paste from paste board.
     */
    IME_EXTEND_ACTION_PASTE = 5,
} InputMethod_ExtendAction;

/**
 * @brief The text input type.
 *
 * @since 12
 */
typedef enum InputMethod_TextInputType {
    /**
     * The text input type is NONE.
     */
    IME_TEXT_INPUT_TYPE_NONE = -1,
    /**
     * The text input type is TEXT.
     */
    IME_TEXT_INPUT_TYPE_TEXT = 0,
    /**
     * The text input type is MULTILINE.
     */
    IME_TEXT_INPUT_TYPE_MULTILINE = 1,
    /**
     * The text input type is NUMBER.
     */
    IME_TEXT_INPUT_TYPE_NUMBER = 2,
    /**
     * The text input type is PHONE.
     */
    IME_TEXT_INPUT_TYPE_PHONE = 3,
    /**
     * The text input type is DATETIME.
     */
    IME_TEXT_INPUT_TYPE_DATETIME = 4,
    /**
     * The text input type is EMAIL ADDRESS.
     */
    IME_TEXT_INPUT_TYPE_EMAIL_ADDRESS = 5,
    /**
     * The text input type is URL.
     */
    IME_TEXT_INPUT_TYPE_URL = 6,
    /**
     * The text input type is VISIBLE PASSWORD.
     */
    IME_TEXT_INPUT_TYPE_VISIBLE_PASSWORD = 7,
    /**
     * The text input type is NUMBER PASSWORD.
     */
    IME_TEXT_INPUT_TYPE_NUMBER_PASSWORD = 8,
    /**
     * The text input type is SCREEN LOCK PASSWORD.
     */
    IME_TEXT_INPUT_TYPE_SCREEN_LOCK_PASSWORD = 9,
    /**
     * The text input type is USER NAME.
     */
    IME_TEXT_INPUT_TYPE_USER_NAME = 10,
    /**
     * The text input type is NEW PASSWORD.
     */
    IME_TEXT_INPUT_TYPE_NEW_PASSWORD = 11,
    /**
     * The text input type is NUMBER DECIMAL.
     */
    IME_TEXT_INPUT_TYPE_NUMBER_DECIMAL = 12,
} InputMethod_TextInputType;

/**
 * @brief The value type of command data.
 *
 * @since 12
 */
typedef enum InputMethod_CommandValueType {
    /**
     * Value type is NONE.
     */
    IME_COMMAND_VALUE_TYPE_NONE = 0,
    /**
     * Value type is STRING.
     */
    IME_COMMAND_VALUE_TYPE_STRING = 1,
    /**
     * Value type is BOOL.
     */
    IME_COMMAND_VALUE_TYPE_BOOL = 2,
    /**
     * Value type is INT32.
     */
    IME_COMMAND_VALUE_TYPE_INT32 = 3,
} InputMethod_CommandValueType;

/**
 * @brief The value type of command data.
 *
 * @since 12
 */
typedef enum InputMethod_ErrorCode {
    /**
     * @error The error code in the correct case.
     */
    IME_ERR_OK = 0,

    /**
     * @error The error code when error is undefined.
     */
    IME_ERR_UNDEFINED = 1,
    /**
     * @error The error code when parameter check failed.
     */
    IME_ERR_PARAMCHECK = 401,
    /**
     * @error The error code when the package manager error.
     */
    IME_ERR_PACKAGEMANAGER = 12800001,
    /**
     * @error The error code when input method engine error.
     */
    IME_ERR_IMENGINE = 12800002,
    /**
     * @error The error code when input method client error.
     */
    IME_ERR_IMCLIENT = 12800003,
    /**
     * @error The error code when configuration persisting error.
     */
    IME_ERR_CONFIG_PERSIST = 12800005,
    /**
     * @error The error code when input method controller error.
     */
    IME_ERR_CONTROLLER = 12800006,
    /**
     * @error The error code when input method setting error.
     */
    IME_ERR_SETTINGS = 12800007,
    /**
     * @error The error code when input method manager service error.
     */
    IME_ERR_IMMS = 12800008,
    /**
     * @error The error code when input method client is detached.
     */
    IME_ERR_DETACHED = 12800009,
    /**
     * @error The error code when unexpected null pointer.
     */
    IME_ERR_NULL_POINTER = 12802000,
    /**
     * @error The error code when query failed.
     */
    IME_ERR_QUERY_FAILED = 12802001,
} InputMethod_ErrorCode;
#ifdef __cplusplus
}
#endif /* __cplusplus */
/** @} */
#endif // OHOS_INPUTMETHOD_TYPES_CAPI_H