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
 * @addtogroup AbilityBase
 * @{
 *
 * @brief Describe the functions of want.
 *
 * @syscap SystemCapability.Ability.AbilityBase
 * @since 15
 */

/**
 * @file want.h
 *
 * @brief Defines the want APIs.
 *
 * @library libability_base_want.so
 * @kit AbilityKit
 * @syscap SystemCapability.Ability.AbilityBase
 * @since 15
 */

#ifndef ABILITY_BASE_WANT_H
#define ABILITY_BASE_WANT_H

#include <stddef.h>
#include <stdint.h>
#include "ability_base_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Indicates information of element.
 *
 * @since 15
 */
typedef struct AbilityBase_Element {
    /** Indicates the name of application. */
    char* bundleName;
    /** Indicates the name of module. */
    char* moduleName;
    /** Indicates the name of ability. */
    char* abilityName;
} AbilityBase_Element;

struct AbilityBase_Want;
typedef struct AbilityBase_Want AbilityBase_Want;

/**
 * @brief Create want.
 *
 * @param element Information of element.
 * @return Returns the newly created AbilityBase_Want object.
 *
 * @since 15
 */
AbilityBase_Want* OH_AbilityBase_CreateWant(AbilityBase_Element element);

/**
 * @brief Destroy input want.
 *
 * @param want The want to be deleted.
 * @return The error code.
 *         {@link ABILITY_BASE_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_BASE_ERROR_CODE_PARAM_INVALID} if the want is invalid.
 * @since 15
 */
AbilityBase_ErrorCode OH_AbilityBase_DestroyWant(AbilityBase_Want* want);

/**
 * @brief Set want element.
 *
 * @param want The want that needs to be set element.
 * @param element Information of element.
 * @return The error code.
 *         {@link ABILITY_BASE_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_BASE_ERROR_CODE_PARAM_INVALID} if the want is invalid.
 * @since 15
 */
AbilityBase_ErrorCode OH_AbilityBase_SetWantElement(AbilityBase_Want* want, AbilityBase_Element element);

/**
 * @brief Get want element.
 *
 * @param want The want for the element that has been obtained.
 * @param element The element obtained from want.
 * @return The error code.
 *         {@link ABILITY_BASE_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_BASE_ERROR_CODE_PARAM_INVALID} if the want or element is invalid.
 * @since 15
 */
AbilityBase_ErrorCode OH_AbilityBase_GetWantElement(AbilityBase_Want* want, AbilityBase_Element* element);

/**
 * @brief Set want char param.
 *
 * @param want The want needs to be set char param.
 * @param key The key of char param.
 * @param value The value of char param.
 * @return The error code.
 *         {@link ABILITY_BASE_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_BASE_ERROR_CODE_PARAM_INVALID} if the input parameters are invalid.
 * @since 15
 */
AbilityBase_ErrorCode OH_AbilityBase_SetWantCharParam(AbilityBase_Want* want, const char* key, const char* value);

/**
 * @brief Get want char param.
 *
 * @param want The want for the char param that has been obtained.
 * @param key The key of char param.
 * @param value The value of char param.
 * @param valueSize Size of the value.
 * @return The error code.
 *         {@link ABILITY_BASE_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_BASE_ERROR_CODE_PARAM_INVALID} if the input parameters are invalid.
 * @since 15
 */
AbilityBase_ErrorCode OH_AbilityBase_GetWantCharParam(AbilityBase_Want* want, const char* key,
    char* value, size_t valueSize);

/**
 * @brief Add fd to want.
 *
 * @param want The want needs to be add fd.
 * @param key The key of the fd.
 * @param fd File Descriptor.
 * @return The error code.
 *         {@link ABILITY_BASE_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_BASE_ERROR_CODE_PARAM_INVALID} if the input parameters are invalid.
 * @since 15
 */
AbilityBase_ErrorCode OH_AbilityBase_AddWantFd(AbilityBase_Want* want, const char* key, int32_t fd);

/**
 * @brief Get fd from want.
 *
 * @param want The want that includes fd.
 * @param key The key of the fd.
 * @param fd File Descriptor.
 * @return The error code.
 *         {@link ABILITY_BASE_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_BASE_ERROR_CODE_PARAM_INVALID} if the input parameters are invalid.
 * @since 15
 */
AbilityBase_ErrorCode OH_AbilityBase_GetWantFd(AbilityBase_Want* want, const char* key, int32_t* fd);

/**
 * @brief Set uri to want.
 *
 * @param want The want needs to set uri.
 * @param uri The uri of the want.
 * @return The error code.
 *         {@link ABILITY_BASE_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_BASE_ERROR_CODE_PARAM_INVALID} if the input parameters are invalid.
 * @since 17
 */
AbilityBase_ErrorCode OH_AbilityBase_SetWantUri(AbilityBase_Want* want, const char* uri);

/**
 * @brief Get uri from want.
 *
 * @param want The want that includes uri.
 * @param uri The uri of the want.
 * @param uriSize Size of the uri.
 * @return The error code.
 *         {@link ABILITY_BASE_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_BASE_ERROR_CODE_PARAM_INVALID} if the input parameters are invalid.
 * @since 17
 */
AbilityBase_ErrorCode OH_AbilityBase_GetWantUri(AbilityBase_Want* want, char* uri, size_t uriSize);

/**
 * @brief Set int32_t to want.
 *
 * @param want The want needs to set int32_t value.
 * @param key The key of int32_t param.
 * @param value The value of int32_t param.
 * @return The error code.
 *         {@link ABILITY_BASE_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_BASE_ERROR_CODE_PARAM_INVALID} if the input parameters are invalid.
 * @since 17
 */
AbilityBase_ErrorCode OH_AbilityBase_SetWantInt32Param(AbilityBase_Want* want, const char* key, int32_t value);

/**
 * @brief Get int32_t from want.
 *
 * @param want The want includes int32_t value.
 * @param key The key of int32_t param.
 * @param value The value of int32_t param.
 * @return The error code.
 *         {@link ABILITY_BASE_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_BASE_ERROR_CODE_PARAM_INVALID} if the input parameters are invalid.
 * @since 17
 */
AbilityBase_ErrorCode OH_AbilityBase_GetWantInt32Param(AbilityBase_Want* want, const char* key, int32_t* value);

/**
 * @brief Set bool to want.
 *
 * @param want The want needs to set bool value.
 * @param key The key of bool param.
 * @param value The value of bool param.
 * @return The error code.
 *         {@link ABILITY_BASE_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_BASE_ERROR_CODE_PARAM_INVALID} if the input parameters are invalid.
 * @since 17
 */
AbilityBase_ErrorCode OH_AbilityBase_SetWantBoolParam(AbilityBase_Want* want, const char* key, bool value);

/**
 * @brief Get bool from want.
 *
 * @param want The want needs to set bool value.
 * @param key The key of bool param.
 * @param value The value of bool param.
 * @return The error code.
 *         {@link ABILITY_BASE_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_BASE_ERROR_CODE_PARAM_INVALID} if the input parameters are invalid.
 * @since 17
 */
AbilityBase_ErrorCode OH_AbilityBase_GetWantBoolParam(AbilityBase_Want* want, const char* key, bool* value);

/**
 * @brief Set double to want.
 *
 * @param want The want needs to set double value.
 * @param key The key of double param.
 * @param value The value of double param.
 * @return The error code.
 *         {@link ABILITY_BASE_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_BASE_ERROR_CODE_PARAM_INVALID} if the input parameters are invalid.
 * @since 17
 */
AbilityBase_ErrorCode OH_AbilityBase_SetWantDoubleParam(AbilityBase_Want* want, const char* key, double value);

/**
 * @brief Get double from want.
 *
 * @param want The want needs to set double value.
 * @param key The key of double param.
 * @param value The value of double param.
 * @return The error code.
 *         {@link ABILITY_BASE_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ABILITY_BASE_ERROR_CODE_PARAM_INVALID} if the input parameters are invalid.
 * @since 17
 */
AbilityBase_ErrorCode OH_AbilityBase_GetWantDoubleParam(AbilityBase_Want* want, const char* key, double* value);

#ifdef __cplusplus
} // extern "C"
#endif

/** @} */
#endif // ABILITY_BASE_WANT_H
