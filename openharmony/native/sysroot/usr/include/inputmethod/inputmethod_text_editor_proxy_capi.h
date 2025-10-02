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
 * @file inputmethod_text_editor_proxy_capi.h
 *
 * @brief Provides functions for getting requests and notifications from input method.
 *
 * @library libohinputmethod.so
 * @kit IMEKit
 * @syscap SystemCapability.MiscServices.InputMethodFramework
 * @since 12
 * @version 1.0
 */
#ifndef OHOS_INPUTMETHOD_TEXT_EDITOR_PROXY_CAPI_H
#define OHOS_INPUTMETHOD_TEXT_EDITOR_PROXY_CAPI_H
#include <stddef.h>

#include "inputmethod_private_command_capi.h"
#include "inputmethod_text_config_capi.h"
#include "inputmethod_types_capi.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/**
 * @brief Define the InputMethod_TextEditorProxy structure type.
 *
 * Provides methods for getting requests and notifications from input method.\n
 * When input method sends request or notification to editor, the methods will be called.\n
 *
 * @since 12
 */
typedef struct InputMethod_TextEditorProxy InputMethod_TextEditorProxy;

/**
 * @brief Defines the function called when input method getting text config.
 *
 * You need to implement this function, set it to {@link InputMethod_TextEditorProxy} through {@link
 * OH_TextEditorProxy_SetGetTextConfigFunc}, and use {@link OH_InputMethodController_Attach} to complete the
 * registration.\n
 *
 * @param textEditorProxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance.
 * @param config Represents a pointer to an {@link InputMethod_TextConfig} instance.
 * @since 12
 */
typedef void (*OH_TextEditorProxy_GetTextConfigFunc)(
    InputMethod_TextEditorProxy *textEditorProxy, InputMethod_TextConfig *config);
/**
 * @brief Defines the function called when input method inserting text.
 *
 * You need to implement this function, set it to {@link InputMethod_TextEditorProxy} through {@link
 * OH_TextEditorProxy_SetInsertTextFunc}, and use {@link OH_InputMethodController_Attach} to complete the
 * registration.\n
 *
 * @param textEditorProxy Represents a pointer to the {@link InputMethod_TextEditorProxy} instance which will be set
 * in.
 * @param text Represents a pointer to the text to be inserted.
 * @param length Represents the length of the text to be inserted.
 * @since 12
 */
typedef void (*OH_TextEditorProxy_InsertTextFunc)(
    InputMethod_TextEditorProxy *textEditorProxy, const char16_t *text, size_t length);
/**
 * @brief Defines the function called when input method deleting text forward.
 *
 * You need to implement this function, set it to {@link InputMethod_TextEditorProxy} through {@link
 * OH_TextEditorProxy_SetDeleteForwardFunc}, and use {@link OH_InputMethodController_Attach} to complete the
 * registration.\n
 *
 * @param textEditorProxy Represents a pointer to the {@link InputMethod_TextEditorProxy} instance which will be set
 * in.
 * @param length Represents the length of the text to be deleted.
 * @since 12
 */
typedef void (*OH_TextEditorProxy_DeleteForwardFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t length);
/**
 * @brief Defines the function called when input method deleting text backward.
 *
 * You need to implement this function, set it to {@link InputMethod_TextEditorProxy} through {@link
 * OH_TextEditorProxy_SetDeleteForwardFunc}, and use {@link OH_InputMethodController_Attach} to complete the
 * registration.\n
 *
 * @param textEditorProxy Represents a pointer to the {@link InputMethod_TextEditorProxy} instance which will be set
 * in.
 * @param length Represents the length of the text to be deleted.
 * @since 12
 */
typedef void (*OH_TextEditorProxy_DeleteBackwardFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t length);
/**
 * @brief Called when input method notifying keyboard status.
 *
 * You need to implement this function, set it to {@link InputMethod_TextEditorProxy} through {@link
 * OH_TextEditorProxy_SetSendKeyboardStatusFunc}, and use {@link OH_InputMethodController_Attach} to complete the
 * registration.\n
 *
 * @param textEditorProxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set in.
 * @param keyboardStatus Keyboard status, which is defined in {@link InputMethod_KeyboardStatus}.
 * @since 12
 */
typedef void (*OH_TextEditorProxy_SendKeyboardStatusFunc)(
    InputMethod_TextEditorProxy *textEditorProxy, InputMethod_KeyboardStatus keyboardStatus);
/**
 * @brief Called when input method sending enter key.
 *
 * You need to implement this function, set it to {@link InputMethod_TextEditorProxy} through {@link
 * OH_TextEditorProxy_SetSendEnterKeyFunc}, and use {@link OH_InputMethodController_Attach} to complete the
 * registration.\n
 *
 * @param textEditorProxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set in.
 * @param enterKeyType Enter key type, which is defined in {@link InputMethod_EnterKeyType}.
 * @since 12
 */
typedef void (*OH_TextEditorProxy_SendEnterKeyFunc)(
    InputMethod_TextEditorProxy *textEditorProxy, InputMethod_EnterKeyType enterKeyType);
/**
 * @brief Called when input method requesting to move cursor.
 *
 * You need to implement this function, set it to {@link InputMethod_TextEditorProxy} through {@link
 * OH_TextEditorProxy_SetMoveCursorFunc}, and use {@link OH_InputMethodController_Attach} to complete the
 * registration.\n
 *
 * @param textEditorProxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set in.
 * @param direction Represents the direction of the cursor movement, which is defined in {@link InputMethod_Direction}.
 * @since 12
 */
typedef void (*OH_TextEditorProxy_MoveCursorFunc)(
    InputMethod_TextEditorProxy *textEditorProxy, InputMethod_Direction direction);
/**
 * @brief Called when input method requesting to set selection.
 *
 * You need to implement this function, set it to {@link InputMethod_TextEditorProxy} through {@link
 * OH_TextEditorProxy_SetHandleSetSelectionFunc}, and use {@link OH_InputMethodController_Attach} to complete the
 * registration.\n
 *
 * @param textEditorProxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set in.
 * @param start Represents the start position of the selection.
 * @param end Represents the end position of the selection.
 * @since 12
 */
typedef void (*OH_TextEditorProxy_HandleSetSelectionFunc)(
    InputMethod_TextEditorProxy *textEditorProxy, int32_t start, int32_t end);
/**
 * @brief Called when input method sending extend action.
 *
 * You need to implement this function, set it to {@link InputMethod_TextEditorProxy} through {@link
 * OH_TextEditorProxy_SetHandleExtendActionFunc}, and use {@link OH_InputMethodController_Attach} to complete the
 * registration.\n
 *
 * @param textEditorProxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set in.
 * @param action Represents the extend action, which is defined in {@link InputMethod_ExtendAction}.
 * @since 12
 */
typedef void (*OH_TextEditorProxy_HandleExtendActionFunc)(
    InputMethod_TextEditorProxy *textEditorProxy, InputMethod_ExtendAction action);
/**
 * @brief Called when input method requesting to get left text of cursor.
 *
 * You need to implement this function, set it to {@link InputMethod_TextEditorProxy} through {@link
 * OH_TextEditorProxy_SetGetLeftTextOfCursorFunc}, and use {@link OH_InputMethodController_Attach} to complete the
 * registration.\n
 *
 * @param textEditorProxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set in.
 * @param number Represents the number of characters to be get.
 * @param text Represents the left text of cursor, you need to assing this parameter.
 * @param length Represents the length of the left text of cursor, you need to assing this parameter.
 * @since 12
 */
typedef void (*OH_TextEditorProxy_GetLeftTextOfCursorFunc)(
    InputMethod_TextEditorProxy *textEditorProxy, int32_t number, char16_t text[], size_t *length);
/**
 * @brief Called when input method requesting to get right text of cursor.
 *
 * You need to implement this function, set it to {@link InputMethod_TextEditorProxy} through {@link
 * OH_TextEditorProxy_SetGetRightTextOfCursorFunc}, and use {@link OH_InputMethodController_Attach} to complete the
 * registration.\n
 *
 * @param textEditorProxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set in.
 * @param number Represents the number of characters to be get.
 * @param text Represents the right text of cursor, you need to assing this parameter.
 * @param length Represents the length of the right text of cursor.
 * @since 12
 */
typedef void (*OH_TextEditorProxy_GetRightTextOfCursorFunc)(
    InputMethod_TextEditorProxy *textEditorProxy, int32_t number, char16_t text[], size_t *length);
/**
 * @brief Called when input method requesting to get text index at cursor.
 *
 * You need to implement this function, set it to {@link InputMethod_TextEditorProxy} through {@link
 * OH_TextEditorProxy_SetGetTextIndexAtCursorFunc}, and use {@link OH_InputMethodController_Attach} to complete the
 * registration.\n
 *
 * @param textEditorProxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set in.
 * @return Returns the index of text at cursor.
 * @since 12
 */
typedef int32_t (*OH_TextEditorProxy_GetTextIndexAtCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy);
/**
 * @brief Called when input method sending private command.
 *
 * You need to implement this function, set it to {@link InputMethod_TextEditorProxy} through {@link
 * OH_TextEditorProxy_SetReceivePrivateCommandFunc}, and use {@link OH_InputMethodController_Attach} to complete the
 * registration.\n
 *
 * @param textEditorProxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set in.
 * @param privateCommand Private command from input method.
 * @param size Size of private command.
 * @return Returns the result of handling private command.
 * @since 12
 */
typedef int32_t (*OH_TextEditorProxy_ReceivePrivateCommandFunc)(
    InputMethod_TextEditorProxy *textEditorProxy, InputMethod_PrivateCommand *privateCommand[], size_t size);
/**
 * @brief Called when input method setting preview text.
 *
 * You need to implement this function, set it to {@link InputMethod_TextEditorProxy} through {@link
 * OH_TextEditorProxy_SetReceivePrivateCommandFunc}, and use {@link OH_InputMethodController_Attach} to complete the
 * registration.\n
 *
 * @param textEditorProxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set in.
 * @param text Represents text to be previewd.
 * @param length Length of preview text.
 * @param start Start position of preview text.
 * @param end End position of preview text.
 * @return Returns the result of setting preview text.
 * @since 12
 */
typedef int32_t (*OH_TextEditorProxy_SetPreviewTextFunc)(
    InputMethod_TextEditorProxy *textEditorProxy, const char16_t text[], size_t length, int32_t start, int32_t end);
/**
 * @brief Called when input method finishing preview text.
 *
 * You need to implement this function, set it to {@link InputMethod_TextEditorProxy} through {@link
 * OH_TextEditorProxy_SetReceivePrivateCommandFunc}, and use {@link OH_InputMethodController_Attach} to complete the
 * registration.\n
 *
 * @param textEditorProxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set in.
 * @since 12
 */
typedef void (*OH_TextEditorProxy_FinishTextPreviewFunc)(InputMethod_TextEditorProxy *textEditorProxy);

/**
 * @brief Create a new {@link InputMethod_TextEditorProxy} instance.
 *
 * @return If the creation succeeds, a pointer to the newly created {@link InputMethod_TextEditorProxy}
 * instance is returned. If the creation fails, NULL is returned, possible cause is insufficient memory.
 * @since 12
 */
InputMethod_TextEditorProxy *OH_TextEditorProxy_Create(void);
/**
 * @brief Destroy a {@link InputMethod_TextEditorProxy} instance.
 *
 * @param proxy The {@link InputMethod_TextEditorProxy} instance to be destroyed.
 * @since 12
 */
void OH_TextEditorProxy_Destroy(InputMethod_TextEditorProxy *proxy);
/**
 * @brief Set function {@link OH_TextEditorProxy_GetTextConfigFunc} into {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set function in.
 * @param getTextConfigFunc Represents function {@link OH_TextEditorProxy_GetTextConfigFunc} which will be set.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_SetGetTextConfigFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextConfigFunc getTextConfigFunc);
/**
 * @brief Set function {@link OH_TextEditorProxy_InsertTextFunc} into {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set function in.
 * @param insertTextFunc Represents function {@link OH_TextEditorProxy_InsertTextFunc} which will be set.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_SetInsertTextFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_InsertTextFunc insertTextFunc);
/**
 * @brief Set function {@link OH_TextEditorProxy_SetDeleteForwardFunc} into {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set function in.
 * @param deleteForwardFunc Represents function {@link OH_TextEditorProxy_DeleteForwardFunc} which will be set.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_SetDeleteForwardFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteForwardFunc deleteForwardFunc);
/**
 * @brief Set function {@link OH_TextEditorProxy_DeleteBackwardFunc} into {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set function in.
 * @param deleteBackwardFunc Represents function {@link OH_TextEditorProxy_DeleteBackwardFunc} which will be set.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_SetDeleteBackwardFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteBackwardFunc deleteBackwardFunc);
/**
 * @brief Set function {@link OH_TextEditorProxy_SendKeyboardStatusFunc} into {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set function in.
 * @param sendKeyboardStatusFunc Represents function {@link OH_TextEditorProxy_SendKeyboardStatusFunc} which will be
 * set.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_SetSendKeyboardStatusFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendKeyboardStatusFunc sendKeyboardStatusFunc);
/**
 * @brief Set function {@link OH_TextEditorProxy_SendEnterKeyFunc} into {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set function in.
 * @param sendEnterKeyFunc Represents function {@link OH_TextEditorProxy_SendEnterKeyFunc} which will be set.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_SetSendEnterKeyFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendEnterKeyFunc sendEnterKeyFunc);
/**
 * @brief Set function {@link OH_TextEditorProxy_MoveCursorFunc} into {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set function in.
 * @param moveCursorFunc Represents function {@link OH_TextEditorProxy_MoveCursorFunc} which will be set.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_SetMoveCursorFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_MoveCursorFunc moveCursorFunc);
/**
 * @brief Set function {@link OH_TextEditorProxy_HandleSetSelectionFunc} into {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set function in.
 * @param handleSetSelectionFunc Represents function {@link OH_TextEditorProxy_HandleSetSelectionFunc} which will be
 * set.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_SetHandleSetSelectionFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleSetSelectionFunc handleSetSelectionFunc);
/**
 * @brief Set function {@link OH_TextEditorProxy_HandleExtendActionFunc} into {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set function in.
 * @param handleExtendActionFunc Represents function {@link OH_TextEditorProxy_HandleExtendActionFunc} which will be
 * set.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_SetHandleExtendActionFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleExtendActionFunc handleExtendActionFunc);
/**
 * @brief Set function {@link OH_TextEditorProxy_GetLeftTextOfCursorFunc} into {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set function in.
 * @param getLeftTextOfCursorFunc Represents function {@link OH_TextEditorProxy_GetLeftTextOfCursorFunc} which will
 * be set.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_SetGetLeftTextOfCursorFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetLeftTextOfCursorFunc getLeftTextOfCursorFunc);
/**
 * @brief Set function {@link OH_TextEditorProxy_GetRightTextOfCursorFunc} into {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set function in.
 * @param getRightTextOfCursorFunc Represents function {@link OH_TextEditorProxy_GetRightTextOfCursorFunc} which
 * will be set.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_SetGetRightTextOfCursorFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetRightTextOfCursorFunc getRightTextOfCursorFunc);
/**
 * @brief Set function {@link OH_TextEditorProxy_GetTextIndexAtCursorFunc} into {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set function in.
 * @param getTextIndexAtCursorFunc Represents function {@link OH_TextEditorProxy_GetTextIndexAtCursorFunc} which
 * will be set.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_SetGetTextIndexAtCursorFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextIndexAtCursorFunc getTextIndexAtCursorFunc);
/**
 * @brief Set function {@link OH_TextEditorProxy_ReceivePrivateCommandFunc} into {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set function in.
 * @param receivePrivateCommandFunc Represents function {@link OH_TextEditorProxy_ReceivePrivateCommandFunc} which
 * will be set.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_SetReceivePrivateCommandFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_ReceivePrivateCommandFunc receivePrivateCommandFunc);
/**
 * @brief Set function {@link OH_TextEditorProxy_SetPreviewTextFunc} into {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set function in.
 * @param setPreviewTextFunc Represents function {@link OH_TextEditorProxy_SetPreviewTextFunc} which will be set.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_SetSetPreviewTextFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SetPreviewTextFunc setPreviewTextFunc);
/**
 * @brief Set function {@link OH_TextEditorProxy_FinishTextPreviewFunc} into {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be set function in.
 * @param finishTextPreviewFunc Represents function {@link OH_TextEditorProxy_FinishTextPreviewFunc} which will be
 * set.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_SetFinishTextPreviewFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_FinishTextPreviewFunc finishTextPreviewFunc);

/**
 * @brief Get function {@link OH_TextEditorProxy_GetTextConfigFunc} from {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be get function
 * from.
 * @param getTextConfigFunc Represents function {@link OH_TextEditorProxy_GetTextConfigFunc} which will be get.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_GetGetTextConfigFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextConfigFunc *getTextConfigFunc);
/**
 * @brief Get function {@link OH_TextEditorProxy_InsertTextFunc} from {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be get function
 * from.
 * @param insertTextFunc Represents function {@link OH_TextEditorProxy_InsertTextFunc} which will be get.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_GetInsertTextFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_InsertTextFunc *insertTextFunc);
/**
 * @brief Get function {@link OH_TextEditorProxy_DeleteForwardFunc} from {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be get function
 * from.
 * @param deleteForwardFunc Represents function {@link OH_TextEditorProxy_DeleteForwardFunc} which will be get.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_GetDeleteForwardFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteForwardFunc *deleteForwardFunc);
/**
 * @brief Get function {@link OH_TextEditorProxy_DeleteBackwardFunc} from {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be get function
 * from.
 * @param deleteBackwardFunc Represents function {@link OH_TextEditorProxy_DeleteBackwardFunc} which will be get.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_GetDeleteBackwardFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteBackwardFunc *deleteBackwardFunc);
/**
 * @brief Get function {@link OH_TextEditorProxy_SendKeyboardStatusFunc} from {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be get function
 * from.
 * @param sendKeyboardStatusFunc Represents function {@link OH_TextEditorProxy_SendKeyboardStatusFunc} which will be
 * get.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_GetSendKeyboardStatusFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendKeyboardStatusFunc *sendKeyboardStatusFunc);
/**
 * @brief Get function {@link OH_TextEditorProxy_SendEnterKeyFunc} from {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be get function
 * from.
 * @param sendEnterKeyFunc Represents function {@link OH_TextEditorProxy_SendEnterKeyFunc} which will be get.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_GetSendEnterKeyFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendEnterKeyFunc *sendEnterKeyFunc);
/**
 * @brief Get function {@link OH_TextEditorProxy_MoveCursorFunc} from {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be get function
 * from.
 * @param moveCursorFunc Represents function {@link OH_TextEditorProxy_MoveCursorFunc} which will be get.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_GetMoveCursorFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_MoveCursorFunc *moveCursorFunc);
/**
 * @brief Get function {@link OH_TextEditorProxy_HandleSetSelectionFunc} from {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be get function
 * from.
 * @param handleSetSelectionFunc Represents function {@link OH_TextEditorProxy_HandleSetSelectionFunc} which will be
 * get.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_GetHandleSetSelectionFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleSetSelectionFunc *handleSetSelectionFunc);
/**
 * @brief Get function {@link OH_TextEditorProxy_HandleExtendActionFunc} from {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be get function
 * from.
 * @param handleExtendActionFunc Represents function {@link OH_TextEditorProxy_HandleExtendActionFunc} which will be
 * get.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_GetHandleExtendActionFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleExtendActionFunc *handleExtendActionFunc);
/**
 * @brief Get function {@link OH_TextEditorProxy_GetLeftTextOfCursorFunc} from {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be get function
 * from.
 * @param getLeftTextOfCursorFunc Represents function {@link OH_TextEditorProxy_GetLeftTextOfCursorFunc} which will
 * be get.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_GetGetLeftTextOfCursorFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetLeftTextOfCursorFunc *getLeftTextOfCursorFunc);
/**
 * @brief Get function {@link OH_TextEditorProxy_GetRightTextOfCursorFunc} from {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be get function
 * from.
 * @param getRightTextOfCursorFunc Represents function {@link OH_TextEditorProxy_GetRightTextOfCursorFunc} which
 * will be get.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_GetGetRightTextOfCursorFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetRightTextOfCursorFunc *getRightTextOfCursorFunc);
/**
 * @brief Get function {@link OH_TextEditorProxy_GetTextIndexAtCursorFunc} from {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be get function
 * from.
 * @param getTextIndexAtCursorFunc Represents function {@link OH_TextEditorProxy_GetTextIndexAtCursorFunc} which
 * will be get.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_GetGetTextIndexAtCursorFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextIndexAtCursorFunc *getTextIndexAtCursorFunc);
/**
 * @brief Get function {@link OH_TextEditorProxy_ReceivePrivateCommandFunc} from {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be get function
 * from.
 * @param receivePrivateCommandFunc Represents function {@link OH_TextEditorProxy_ReceivePrivateCommandFunc} which
 * will be get.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_GetReceivePrivateCommandFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_ReceivePrivateCommandFunc *receivePrivateCommandFunc);
/**
 * @brief Get function {@link OH_TextEditorProxy_SetPreviewTextFunc} from {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be get function
 * from.
 * @param setPreviewTextFunc Represents function {@link OH_TextEditorProxy_SetPreviewTextFunc} which will be get.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_GetSetPreviewTextFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SetPreviewTextFunc *setPreviewTextFunc);
/**
 * @brief Get function {@link OH_TextEditorProxy_FinishTextPreviewFunc} from {@link InputMethod_TextEditorProxy}.
 *
 * @param proxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance which will be get function
 * from.
 * @param finishTextPreviewFunc Represents function {@link OH_TextEditorProxy_FinishTextPreviewFunc} which will be
 * get.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextEditorProxy_GetFinishTextPreviewFunc(
    InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_FinishTextPreviewFunc *finishTextPreviewFunc);
#ifdef __cplusplus
}
#endif /* __cplusplus */
/** @} */
#endif // OHOS_INPUTMETHOD_TEXT_EDITOR_PROXY_CAP_H