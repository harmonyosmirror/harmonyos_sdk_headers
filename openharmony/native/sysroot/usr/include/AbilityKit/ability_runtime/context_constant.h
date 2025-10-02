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
 * @addtogroup AbilityRuntime
 * @{
 *
 * @brief Describe the constant of context.
 *
 * @syscap SystemCapability.Ability.AbilityRuntime.Core
 * @since 13
 */

/**
 * @file context_constant.h
 *
 * @brief Defines the constant of context.
 *
 * @library libability_runtime.so
 * @kit AbilityKit
 * @syscap SystemCapability.Ability.AbilityRuntime.Core
 * @since 13
 */

#ifndef ABILITY_RUNTIME_CONTEXT_CONSTANT_H
#define ABILITY_RUNTIME_CONTEXT_CONSTANT_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief File area mode.
 *
 * @since 13
 */
typedef enum {
    /**
     * System level device encryption area.
     */
    ABILITY_RUNTIME_AREA_MODE_EL1 = 0,
    /**
     * User credential encryption area.
     */
    ABILITY_RUNTIME_AREA_MODE_EL2 = 1,
    /**
     * User credential encryption area.
     * when screen locked, can read/write, and create file.
     */
    ABILITY_RUNTIME_AREA_MODE_EL3 = 2,
    /**
     * User credential encryption area.
     * when screen locked, FEB2.0 can read/write, FEB3.0 can't
     * read/write, and all can't create file.
     */
    ABILITY_RUNTIME_AREA_MODE_EL4 = 3,
    /**
     * User privacy-sensitive encryption area.
     * when the screen locked, a closed file cannot be opened, read, or written,
     * a file can be created and then opened, read, or written.
     */
    ABILITY_RUNTIME_AREA_MODE_EL5 = 4,
} AbilityRuntime_AreaMode;

#ifdef __cplusplus
} // extern "C"
#endif

/** @} */
#endif // ABILITY_RUNTIME_CONTEXT_CONSTANT_H
