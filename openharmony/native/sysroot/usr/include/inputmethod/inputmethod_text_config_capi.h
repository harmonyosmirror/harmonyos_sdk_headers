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
 * @file inputmethod_text_config_capi.h
 *
 * @brief Provides functions to manage the text configuration.
 *
 * @library libohinputmethod.so
 * @kit IMEKit
 * @syscap SystemCapability.MiscServices.InputMethodFramework
 * @since 12
 * @version 1.0
 */
#ifndef OHOS_INPUTMETHOD_TEXT_CONFIG_CAPI_H
#define OHOS_INPUTMETHOD_TEXT_CONFIG_CAPI_H
#include <stdint.h>
#include <stddef.h>

#include "inputmethod_cursor_info_capi.h"
#include "inputmethod_text_avoid_info_capi.h"
#include "inputmethod_types_capi.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/**
 * @brief Define the InputMethod_TextConfig structure type.
 *
 * The configuration of the text editor.
 *
 * @since 12
 */
typedef struct InputMethod_TextConfig InputMethod_TextConfig;

/**
 * @brief Create a new {@link InputMethod_TextConfig} instance.
 *
 * @return If the creation succeeds, a pointer to the newly created {@link InputMethod_TextConfig}
 * instance is returned. If the creation fails, NULL is returned, possible cause is insufficient memory.
 * @since 12
 */
InputMethod_TextConfig *OH_TextConfig_Create(void);
/**
 * @brief Destroy a {@link InputMethod_TextConfig} instance.
 *
 * @param config Represents a pointer to an {@link InputMethod_TextConfig} instance which will be destroyed.
 * @since 12
 */
void OH_TextConfig_Destroy(InputMethod_TextConfig *config);

/**
 * @brief Set input type into TextConfig.
 *
 * @param config Represents a pointer to an {@link InputMethod_TextConfig} instance which will be set.
 * @param inputType The text input type of text Editor, which is defined in {@link InputMethod_TextInputType}.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextConfig_SetInputType(InputMethod_TextConfig *config, InputMethod_TextInputType inputType);
/**
 * @brief Set enter key type into TextConfig.
 *
 * @param config Represents a pointer to an {@link InputMethod_TextConfig} instance which will be set.
 * @param enterKeyType The enter key type of text Editor, which is defined in {@link InputMethod_EnterKeyType}.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextConfig_SetEnterKeyType(
    InputMethod_TextConfig *config, InputMethod_EnterKeyType enterKeyType);
/**
 * @brief Set preview text support into TextConfig.
 *
 * @param config Represents a pointer to an {@link InputMethod_TextConfig} instance which will be set.
 * @param supported Indicates whether the preview text is supported.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextConfig_SetPreviewTextSupport(InputMethod_TextConfig *config, bool supported);
/**
 * @brief Set selection into TextConfig.
 *
 * @param config Represents a pointer to an {@link InputMethod_TextConfig} instance which will be set.
 * @param start The start position of selection.
 * @param end The end position of selection.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextConfig_SetSelection(InputMethod_TextConfig *config, int32_t start, int32_t end);
/**
 * @brief Set window id into TextConfig.
 *
 * @param config Represents a pointer to an {@link InputMethod_TextConfig} instance which will be set.
 * @param windowId The window ID of the application currently bound to the input method.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextConfig_SetWindowId(InputMethod_TextConfig *config, int32_t windowId);

/**
 * @brief Sets the placeholder text of an InputMethod_TextConfig instance.
 *
 * @param config Pointer to the InputMethod_TextConfig instance.
 * @param placeholder Pointer to a UTF-16 encoded double-byte string. If a null pointer is passed, the placeholder text
 *     is an empty string.
 * @param length Number of elements in the memory to which <b>placeholder</b> points, including the null character of
 *     the double-byte string.
 *      1) If <b>length</b> is <b>0</b>, the placeholder text is an empty string.
 *      2) The maximum number of UTF-16 encoded characters is 256, and the last element must be a null character.
 *      3) If the <b>length</b> exceeds 256, the placeholder text will be truncated.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 20
 */
InputMethod_ErrorCode OH_TextConfig_SetPlaceholder(InputMethod_TextConfig *config, const char16_t *placeholder,
    size_t length);

/**
 * @brief Sets the ability name of an InputMethod_TextConfig instance.
 *
 * @param config Pointer to the InputMethod_TextConfig instance.
 * @param abilityName Pointer to a UTF-16 encoded double-byte string. If a null pointer is passed, the ability name is
 *     an empty string.
 * @param length Number of elements in the memory to which <b>abilityName</b> points, including the null character of
*      the double-byte string.
 *     1) If <b>length</b> is <b>0</b>, the ability name is an empty string.
 *     2) The maximum number of UTF-16 encoded characters is 128, and the last element must be a null character.
 *     3) If the <b>length</b> exceeds 128, the placeholder text will be truncated.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 20
 */
InputMethod_ErrorCode OH_TextConfig_SetAbilityName(InputMethod_TextConfig *config, const char16_t *abilityName,
    size_t length);

/**
 * @brief Get input type from TextConfig
 *
 * @param config Represents a pointer to an {@link InputMethod_TextConfig} instance which will be get from.
 * @param inputType Represents a pointer to an {@link InputMethod_TextInputType} instance.
 *     The text input type of text Editor
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextConfig_GetInputType(InputMethod_TextConfig *config, InputMethod_TextInputType *inputType);
/**
 * @brief Get enter key type from TextConfig
 *
 * @param config Represents a pointer to an {@link InputMethod_TextConfig} instance which will be get from.
 * @param enterKeyType Represents a pointer to an {@link InputMethod_EnterKeyType} instance.
 *     Indicates the enter key type of text Editor
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextConfig_GetEnterKeyType(
    InputMethod_TextConfig *config, InputMethod_EnterKeyType *enterKeyType);
/**
 * @brief Get is preview text supported from TextConfig.
 *
 * @param config Represents a pointer to an {@link InputMethod_TextConfig} instance which will be get from.
 * @param supported Indicates whether the preview text is supported.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextConfig_IsPreviewTextSupported(InputMethod_TextConfig *config, bool *supported);
/**
 * @brief Get cursor info from TextConfig.
 *
 * @param config Represents a pointer to an {@link InputMethod_TextConfig} instance which will be get from.
 * @param cursorInfo Represents a pointer to an {@link InputMethod_CursorInfo} instance.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextConfig_GetCursorInfo(InputMethod_TextConfig *config, InputMethod_CursorInfo **cursorInfo);

/**
 * @brief Get text avoid information from text configuration.
 *
 * @param config Indicates the text configuration.
 * @param avoidInfo Indicates the text avoid information.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 *@since 12
 */
InputMethod_ErrorCode OH_TextConfig_GetTextAvoidInfo(
    InputMethod_TextConfig *config, InputMethod_TextAvoidInfo **avoidInfo);

/**
 * @brief Get selection from TextConfig.
 *
 * @param config Represents a pointer to an {@link InputMethod_TextConfig} instance which will be get from.
 * @param start Represents selection start position.
 * @param end Represents selection end position.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextConfig_GetSelection(InputMethod_TextConfig *config, int32_t *start, int32_t *end);
/**
 * @brief Get window id from TextConfig.
 *
 * @param config Represents a pointer to an {@link InputMethod_TextConfig} instance which will be get from.
 * @param windowId The window ID of the application currently bound to the input method.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextConfig_GetWindowId(InputMethod_TextConfig *config, int32_t *windowId);

/**
 * @brief Obtains the placeholder text of an InputMethod_TextConfig instance.
 *
 * @param config Pointer to the InputMethod_TextConfig instance.
 * @param placeholder Pointer to the placeholder text. The memory of this pointer is maintained by the caller.
 * @param length Pointer to the length of the placeholder text, in double bytes. The length includes the null character
 *     of the string.
 *     1) As an input parameter, <b>length</b> indicates the available length of the memory to which <b>placeholder</b>
 *        points. As an output parameter, it indicates the actual length of the placeholder text.
 *     2) If <b>placeholder</b> is a null pointer and <b>length</b> points to valid memory, <b>length</b> will be set to
 *        the actual length of the placeholder text, and an error will be return.
 *     3) If both <b>placeholder</b> and <b>length</b> point to valid memory, but the value of <b>length</b> is less
 *        than the actual length of the placeholder text, <b>length</b> will be set to the actual length of the
 *        placeholder text, and an error will be return.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_PARAMCHECK} - parameter check failed.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 20
 */
InputMethod_ErrorCode OH_TextConfig_GetPlaceholder(InputMethod_TextConfig *config, char16_t *placeholder,
    size_t *length);

/**
 * @brief Obtains the ability name of an InputMethod_TextConfig instance.
 *
 * @param config Pointer to the InputMethod_TextConfig instance.
 * @param abilityName Pointer to the ability name. The memory of this pointer is maintained by the caller.
 * @param length Pointer to the length of the ability name, in double bytes. The length includes the null character of
 *     the string.
 *     1) As an input parameter, <b>length</b> indicates the available length of the memory to which <b>abilityName</b>
 *        points. As an output parameter, it indicates the actual length of the ability name.
 *     2) If <b>abilityName</b> is a null pointer and <b>length</b> points to valid memory, <b>length</b> will be set to
 *        the actual length of the ability name, and an error will be return.
 *     3) If both <b>abilityName</b> and <b>length</b> point to valid memory, but the value of <b>length</b> is less
 *        than the actual length of the ability name, <b>length</b> will be set to the actual length of the ability
 *        name, and an error will be return.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_PARAMCHECK} - parameter check failed.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 20
 */
InputMethod_ErrorCode OH_TextConfig_GetAbilityName(InputMethod_TextConfig *config, char16_t *abilityName,
    size_t *length);
#ifdef __cplusplus
}
#endif /* __cplusplus */
/** @} */
#endif // OHOS_INPUTMETHOD_TEXT_CONFIG_CAPI_H