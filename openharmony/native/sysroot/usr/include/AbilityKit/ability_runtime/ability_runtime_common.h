/*
* Copyright (C) 2024-2025 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
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
 * @brief Provide the definition of the C interface for the native AbilityRuntime
 *
 * @syscap SystemCapability.Ability.AbilityRuntime.Core
 * @since 13
 */

/**
 * @file ability_runtime_common.h
 *
 * @brief Declare the common types for the native AbilityRuntime.
 *
 * @library libability_runtime.so
 * @kit AbilityKit
 * @syscap SystemCapability.Ability.AbilityRuntime.Core
 * @since 13
 */

#ifndef ABILITY_RUNTIME_COMMON_H
#define ABILITY_RUNTIME_COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates the error codes.
 *
 * @since 13
 */
typedef enum {
    /** @error No error. */
    ABILITY_RUNTIME_ERROR_CODE_NO_ERROR = 0,
    /**
     * @error permission denied.
     * @since 15
     */
    ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED = 201,
    /** @error Invalid parameters. */
    ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID = 401,
    /**
     * @error StartSelfUIAbility is not supported.
     * @since 15
     */
    ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED = 801,
    /**
     * @error No such ability.
     * @since 15
     */
    ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY = 16000001,
    /**
     * @error Incorrect ability type.
     * @since 15
     */
    ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE = 16000002,
    /**
     * @error The crowdtesting application expires.
     * @since 15
     */
    ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED = 16000008,
    /**
     * @error The ability cannot be started in Wukong Mode.
     * @since 15
     */
    ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE = 16000009,
    /** @error The context does not exist. */
    ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST = 16000011,
    /**
     * @error The app is controlled.
     * @since 15
     */
    ABILITY_RUNTIME_ERROR_CODE_CONTROLLED = 16000012,
    /**
     * @error The app is controlled by EDM.
     * @since 15
     */
    ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED = 16000013,
    /**
     * @error Cross-app start is not allowed.
     * @since 15
     */
    ABILITY_RUNTIME_ERROR_CODE_CROSS_APP = 16000018,
    /**
     * @error Internal error.
     * @since 15
     */
    ABILITY_RUNTIME_ERROR_CODE_INTERNAL = 16000050,
    /**
     * @error Not top ability.
     * @since 15
     */
    ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY = 16000053,
    /**
     * @error Setting visibility is disabled.
     * @since 17
     */
    ABILITY_RUNTIME_ERROR_VISIBILITY_SETTING_DISABLED = 16000067,
    /**
     * @error App clone or multi-instance is not supported.
     * @since 17
     */
    ABILITY_RUNTIME_ERROR_CODE_MULTI_APP_NOT_SUPPORTED = 16000072,
    /**
     * @error The app instance key is invalid.
     * @since 17
     */
    ABILITY_RUNTIME_ERROR_CODE_INVALID_APP_INSTANCE_KEY = 16000076,
    /**
     * @error The number of app instances reaches the limit.
     * @since 17
     */
    ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED = 16000077,
    /**
     * @error The multi-instance is not supported.
     * @since 17
     */
    ABILITY_RUNTIME_ERROR_MULTI_INSTANCE_NOT_SUPPORTED = 16000078,
    /**
     * @error The APP_INSTANCE_KEY cannot be specified.
     * @since 17
     */
    ABILITY_RUNTIME_ERROR_CODE_APP_INSTANCE_KEY_NOT_SUPPORTED = 16000079,
} AbilityRuntime_ErrorCode;

#ifdef __cplusplus
}
#endif

/** @} */
#endif // ABILITY_RUNTIME_COMMON_H
