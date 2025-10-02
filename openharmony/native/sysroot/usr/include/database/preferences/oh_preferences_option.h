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
 * @addtogroup PREFERENCES
 * @{
 *
 * @brief Provides APIs for processing data in the form of key-value (KV) pairs.
 * You can use the APIs provided by the Preferences module to query, modify, and persist KV pairs.
 * The key is of the string type, and the value can be a number, a string, a boolean value.
 *
 * @since 13
 */

/**
 * @file oh_preferences_option.h
 *
 * @brief Defines the APIs and enums related to preferences option.
 *
 * @kit ArkData
 * @library libohpreferences.so
 * @syscap SystemCapability.DistributedDataManager.Preferences.Core
 *
 * @since 13
 */

#ifndef OH_PREFERENCES_OPTION_H
#define OH_PREFERENCES_OPTION_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Represents an OH_PreferencesOption instance.
 *
 * @since 13
 */
typedef struct OH_PreferencesOption OH_PreferencesOption;

/**
 * @brief Creates an {@Link OH_PreferencesOption} instance.
 *
 * @return Returns a pointer to the {@Link OH_PreferencesOption} instance created if the operation is successful;
 * returns nullptr otherwise while malloc memory failed.
 * @see OH_PreferencesOption.
 * @since 13
 */
OH_PreferencesOption *OH_PreferencesOption_Create(void);

/**
 * @brief Sets the file path in an {@Link OH_PreferencesOption} instance.
 *
 * @param option Pointer to the target {@Link OH_PreferencesOption} instance.
 * @param fileName Pointer to the file name to set.
 * @return Returns the status code of the execution.
 *         {@link PREFERENCES_OK} success.
 *         {@link PREFERENCES_ERROR_INVALID_PARAM} indicates invalid args are passed in.
 * @see OH_PreferencesOption.
 * @since 13
 */
int OH_PreferencesOption_SetFileName(OH_PreferencesOption *option, const char *fileName);

/**
 * @brief Sets the bundle name in an {@Link OH_PreferencesOption} instance.
 *
 * @param option Pointer to the target {@Link OH_PreferencesOption} instance.
 * @param bundleName Pointer to the bundle name to set.
 * @return Returns the status code of the execution.
 *         {@link PREFERENCES_OK} success.
 *         {@link PREFERENCES_ERROR_INVALID_PARAM} indicates invalid args are passed in.
 * @see OH_PreferencesOption.
 * @since 13
 */
int OH_PreferencesOption_SetBundleName(OH_PreferencesOption *option, const char *bundleName);

/**
 * @brief Sets the data group ID in an {@Link OH_PreferencesOption} instance.
 *
 * @param option Represents a pointer to an {@link OH_PreferencesOption} instance.
 * @param dataGroupId Represents preferences data group id param.
 * @return Returns the status code of the execution.
 *         {@link PREFERENCES_OK} success.
 *         {@link PREFERENCES_ERROR_INVALID_PARAM} indicates invalid args are passed in.
 * @see OH_PreferencesOption.
 * @since 13
 */
int OH_PreferencesOption_SetDataGroupId(OH_PreferencesOption *option, const char *dataGroupId);

/**
 * @brief Destroys an {@Link OH_PreferencesOption} instance.
 *
 * @param option Pointer to the {@Link OH_PreferencesOption} instance to destroy.
 * @return Returns the status code of the execution.
 *         {@link PREFERENCES_OK} indicates the operation is successful.
 *         {@link PREFERENCES_ERROR_INVALID_PARAM} indicates invalid args are passed in.
 * @see OH_PreferencesOption.
 * @since 13
 */
int OH_PreferencesOption_Destroy(OH_PreferencesOption *option);
#ifdef __cplusplus
};
#endif
#endif // OH_PREFERENCES_OPTION_H