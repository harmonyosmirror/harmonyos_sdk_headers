/*
 * Copyright (c) 2026 Huawei Device Co., Ltd.
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
 * @addtogroup AbilityRuntime
 * @{
 *
 * @brief Provide the definition of the C interface for the extension ability AbilityRuntime
 *
 * @since 24
 */

/**
 * @file extension_ability.h
 *
 * @brief Declare the common types for the extension ability AbilityRuntime.
 *
 * @library libability_runtime.so
 * @kit AbilityKit
 * @syscap SystemCapability.Ability.AbilityRuntime.Core
 * @since 24
 */

#ifndef ABILITY_RUNTIME_EXTENSION_ABILITY_H
#define ABILITY_RUNTIME_EXTENSION_ABILITY_H

#include "ability_runtime_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Define the AbilityRuntime_ExtensionInstance structure type.
 *
 * @since 24
 */
struct AbilityRuntime_ExtensionInstance;

/**
 * @brief Defines the pointer to AbilityRuntime_ExtensionInstance.
 *
 * @since 24
 */
typedef struct AbilityRuntime_ExtensionInstance* AbilityRuntime_ExtensionInstanceHandle;

/**
 * @brief Define the function that must be in the native code to instantiate the native extension ability.
 *
 * @since 24
 */
typedef void AbilityRuntime_Extension_CreateFunc(
    AbilityRuntime_ExtensionInstanceHandle handle, const char *abilityName);

/**
 * @brief The name of the function that native extension ability instance looks for when launching its native code.
 *
 * @since 24
 */
AbilityRuntime_Extension_CreateFunc OH_AbilityRuntime_OnNativeExtensionCreate;

#ifdef __cplusplus
}
#endif

/** @} */
#endif // ABILITY_RUNTIME_EXTENSION_ABILITY_H