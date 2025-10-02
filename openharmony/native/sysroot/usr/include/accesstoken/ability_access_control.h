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
 * @addtogroup AbilityAccessControl
 * @{
 *
 * @brief Provides the capability to manage access token.
 *
 * @since 12
 */

/**
 * @file ability_access_control.h
 *
 * @brief Declares the APIs for managing access token.
 *
 * @library ability_access_control.so
 * @kit AbilityKit
 * @syscap SystemCapability.Security.AccessToken
 * @since 12
 */

#ifndef ABILITY_ACCESS_CONTROL_H
#define ABILITY_ACCESS_CONTROL_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Checks whether this application has been granted the given permission.
 *
 * @param permission - Name of the permission to be granted.
 * @return true  - The permission has been granted to this application.
 *         false - The permission has not been granted to this application.
 * @since 12
 */
bool OH_AT_CheckSelfPermission(const char *permission);

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* ABILITY_ACCESS_CONTROL_H */
