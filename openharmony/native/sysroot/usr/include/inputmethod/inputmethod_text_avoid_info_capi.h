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
 * @file inputmethod_text_avoid_info_capi.h
 *
 * @brief Provides functions to manage text editor to avoid the keyboard.
 *
 * @library libohinputmethod.so
 * @kit IMEKit
 * @syscap SystemCapability.MiscServices.InputMethodFramework
 * @since 12
 * @version 1.0
 */
#ifndef OHOS_INPUTMETHOD_TEXT_AVOID_INFO_CAPI_H
#define OHOS_INPUTMETHOD_TEXT_AVOID_INFO_CAPI_H
#include "inputmethod_types_capi.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @brief Define the InputMethod_TextAvoidInfo structure type.
 *
 * Information for text editor to avoid the keyboard.
 *
 * @since 12
 */
typedef struct InputMethod_TextAvoidInfo InputMethod_TextAvoidInfo;

/**
 * @brief Create a new {@link InputMethod_TextAvoidInfo} instance.
 *
 * @param positionY The y-coordinate of the avoid area.
 * @param height The height of the avoid area.
 * @return If the creation succeeds, a pointer to the newly created {@link InputMethod_TextAvoidInfo}
 * instance is returned. If the creation fails, NULL is returned, possible cause is insufficient memory.
 * @since 12
 */
InputMethod_TextAvoidInfo *OH_TextAvoidInfo_Create(double positionY, double height);
/**
 * @brief Destroy a {@link InputMethod_TextAvoidInfo} instance.
 *
 * @param options Represents a pointer to an {@link InputMethod_TextAvoidInfo} instance which will be destroyed.
 * @since 12
 */
void OH_TextAvoidInfo_Destroy(InputMethod_TextAvoidInfo *info);
/**
 * @brief Set positionY value into {@link InputMethod_TextAvoidInfo}.
 *
 * @param info Represents a pointer to an {@link InputMethod_TextAvoidInfo} instance which will be set value.
 * @param positionY Represents positionY value.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextAvoidInfo_SetPositionY(InputMethod_TextAvoidInfo *info, double positionY);
/**
 * @brief Set height value into {@link InputMethod_TextAvoidInfo}.
 *
 * @param info Represents a pointer to an {@link InputMethod_TextAvoidInfo} instance which will be set value.
 * @param height Represents height value.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextAvoidInfo_SetHeight(InputMethod_TextAvoidInfo *info, double height);
/**
 * @brief Get positionY value from {@link InputMethod_TextAvoidInfo}.
 *
 * @param info Represents a pointer to an {@link InputMethod_TextAvoidInfo} instance which will be get value from.
 * @param positionY Represents positionY value.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextAvoidInfo_GetPositionY(InputMethod_TextAvoidInfo *info, double *positionY);
/**
 * @brief Get height value into {@link InputMethod_TextAvoidInfo}.
 *
 * @param info Represents a pointer to an {@link InputMethod_TextAvoidInfo} instance which will be get value from.
 * @param height Represents height value.
 * @return Returns a specific error code.
 *     {@link IME_ERR_OK} - success.
 *     {@link IME_ERR_NULL_POINTER} - unexpected null pointer.
 * Specific error codes can be referenced {@link InputMethod_ErrorCode}.
 * @since 12
 */
InputMethod_ErrorCode OH_TextAvoidInfo_GetHeight(InputMethod_TextAvoidInfo *info, double *height);
#ifdef __cplusplus
}
#endif /* __cplusplus */
/** @} */
#endif // OHOS_INPUTMETHOD_TEXT_AVOID_INFO_CAP_H