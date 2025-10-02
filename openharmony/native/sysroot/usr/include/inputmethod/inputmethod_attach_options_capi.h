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
 * @file inputmethod_attach_options_capi.h
 *
 * @brief Provides the input method attach options.
 *
 * @library libohinputmethod.so
 * @kit IMEKit
 * @syscap SystemCapability.MiscServices.InputMethodFramework
 * @since 12
 * @version 1.0
 */
#ifndef OHOS_INPUTMETHOD_ATTACH_OPTIONS_CAPI_H
#define OHOS_INPUTMETHOD_ATTACH_OPTIONS_CAPI_H
#include "inputmethod_types_capi.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/**
 * @brief Define the InputMethod_AttachOptions structure type.
 *
 * The options when attaching input method.
 *
 * @since 12
 */
typedef struct InputMethod_AttachOptions InputMethod_AttachOptions;

/**
 * @brief Create a new {@link InputMethod_AttachOptions} instance.
 *
 * @param showKeyboard Represents whether to show the keyboard.
 * @return If the creation succeeds, a pointer to the newly created {@link InputMethod_AttachOptions}
 * instance is returned. If the creation fails, NULL is returned, possible cause is insufficient memory.
 * @since 12
 */
InputMethod_AttachOptions *OH_AttachOptions_Create(bool showKeyboard);
/**
 * @brief Delete a {@link InputMethod_AttachOptions} instance.
 *
 * @param options Represents a pointer to an {@link InputMethod_AttachOptions} instance which will be destroyed.
 * @since 12
 */
void OH_AttachOptions_Destroy(InputMethod_AttachOptions *options);
/**
 * @brief Get showKeyboard value from {@link InputMethod_AttachOptions}.
 *
 * @param options Represents a pointer to an {@link InputMethod_AttachOptions} instance which will be get value from.
 * @param showKeyboard  Represents showKeyboard value.
 *     true - need to show keyboard.
 *     false - no need to show keyboard.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_AttachOptions_IsShowKeyboard(InputMethod_AttachOptions *options, bool *showKeyboard);
#ifdef __cplusplus
}
#endif /* __cplusplus */
/** @} */
#endif // OHOS_INPUTMETHOD_ATTACH_OPTIONS_CAPI_H