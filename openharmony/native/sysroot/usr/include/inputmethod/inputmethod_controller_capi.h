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
 * @file inputmethod_controller_capi.h
 *
 * @brief Provides the functions for using input method.
 *
 * @library libohinputmethod.so
 * @kit IMEKit
 * @syscap SystemCapability.MiscServices.InputMethodFramework
 * @since 12
 * @version 1.0
 */
#ifndef OHOS_INPUTMETHOD_CONTROLLER_CAPI_H
#define OHOS_INPUTMETHOD_CONTROLLER_CAPI_H
#include <stdint.h>
#include <stdlib.h>

#include "inputmethod_text_editor_proxy_capi.h"
#include "inputmethod_inputmethod_proxy_capi.h"
#include "inputmethod_attach_options_capi.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/**
 * @brief Attach application to the input method service.
 *
 * @param textEditorProxy Represents a pointer to an {@link InputMethod_TextEditorProxy} instance.
 *     The caller needs to manage the lifecycle of textEditorProxy.
 *     If the call succeeds, caller cannot release textEditorProxy until the next attach or detach call.
 * @param options Represents a pointer to an {@link InputMethod_AttachOptions} instance.
 *     The options when attaching input method.
 * @param inputMethodProxy Represents a pointer to an {@link InputMethod_InputMethodProxy} instance.
 *     Lifecycle is mantianed until the next attach or detach call.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_PARAMCHECK} - parameter check failed.
 *     {@link IME_ERR_IMCLIENT} - input method client error.
 *     {@link IME_ERR_IMMS} - input method manager service error.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_InputMethodController_Attach(InputMethod_TextEditorProxy *textEditorProxy,
    InputMethod_AttachOptions *options, InputMethod_InputMethodProxy **inputMethodProxy);

/**
 * @brief Detach application from the input method service.
 *
 * @param inputMethodProxy Represents a pointer to an {@link InputMethod_InputMethodProxy} instance.
 *     The inputMethodProxy is obtained from {@link OH_InputMethodController_Attach}.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_IMCLIENT} - input method client error.
 *     {@link IME_ERR_IMMS} - input method manager service error.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_InputMethodController_Detach(InputMethod_InputMethodProxy *inputMethodProxy);
#ifdef __cplusplus
}
#endif /* __cplusplus */
/** @} */
#endif // OHOS_INPUTMETHOD_CONTROLLER_CAPI_H