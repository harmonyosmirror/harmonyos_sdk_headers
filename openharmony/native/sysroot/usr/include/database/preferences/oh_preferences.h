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
 * @file oh_preferences.h
 *
 * @brief Defines the APIS and enums of Preference.
 *
 * @kit ArkData
 * @library libohpreferences.so
 * @syscap SystemCapability.DistributedDataManager.Preferences.Core
 *
 * @since 13
 */

#ifndef OH_PREFERENCES_H
#define OH_PREFERENCES_H

#include <stdbool.h>
#include <stdint.h>

#include "oh_preferences_value.h"
#include "oh_preferences_option.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Represents a Preferences instance.
 *
 * @since 13
 */
typedef struct OH_Preferences OH_Preferences;

/**
 * @brief Call to return the change in KV pairs.
 *
 * @param context Pointer to the context of data observer.
 * @param pairs Pointer to the KV pairs to be observed.
 * @param count Number of KV pairs to be observed.
 * @see OH_PreferencesPair.
 * @since 13
 */
typedef void (*OH_PreferencesDataObserver)(void *context, const OH_PreferencesPair *pairs, uint32_t count);

/**
 * @brief Opens a Preferences object.
 *
 * @param option Pointer to an {@Link OH_PreferencesOption} instance.
 * @param errCode Pointer to the status code of the execution. For details, See {@link OH_Preferences_ErrCode}.
 * @return Returns an pointer to the Preferences object in {@Link OH_Preferences} if the operation is successful,
 * returns nullptr otherwise.
 *         {@link PREFERENCES_OK} indicates the operation is successful.
 *         {@link PREFERENCES_ERROR_INVALID_PARAM} indicates invalid args are passed in.
 *         {@link PREFERENCES_ERROR_NOT_SUPPORTED} indicates the capability is not supported.
 *         {@link PREFERENCES_ERROR_DELETE_FILE} indicates delete file failed.
 *         {@link PREFERENCES_ERROR_STORAGE} indicates an storage error.
 *         {@link PREFERENCES_ERROR_MALLOC} indicates an malloc memory error.
 * @see OH_Preferences OH_PreferencesOption.
 * @since 13
 */
OH_Preferences *OH_Preferences_Open(OH_PreferencesOption *option, int *errCode);

/**
 * @brief Closes a Preferences object.
 *
 * @param preference Pointer to the {@Link OH_Preferences} instance to close.
 * @param option Pointer to an {@Link OH_PreferencesOption} instance.
 * @return Returns the status code of the execution. For details, see {@Link OH_Preferences_ErrCode}.
 *         {@link PREFERENCES_OK} indicates the operation is successful.
 *         {@link PREFERENCES_ERROR_INVALID_PARAM} indicates invalid args are passed in.
 *         {@link PREFERENCES_ERROR_STORAGE} indicates an storage error.
 *         {@link PREFERENCES_ERROR_MALLOC} indicates an malloc memory error.
 * @see OH_Preferences.
 * @since 13
 */
int OH_Preferences_Close(OH_Preferences *preference);

/**
 * @brief Obtains the integer value in a Preferences object based on the given key.
 *
 * @param preference Pointer to the target {@Link OH_Preferences} instance.
 * @param key Pointer to the key of the value to obtain.
 * @param value Pointer to the value obtained.
 * @return Returns the status code of the execution.
 *         {@link PREFERENCES_OK} indicates the operation is successful.
 *         {@link PREFERENCES_ERROR_INVALID_PARAM} indicates invalid args are passed in.
 *         {@link PREFERENCES_ERROR_STORAGE} indicates an storage error.
 *         {@link PREFERENCES_ERROR_MALLOC} indicates an malloc memory error.
 *         {@link PREFERENCES_ERROR_KEY_NOT_FOUND} indicates the key does not exist.
 * @see OH_Preferences.
 * @since 13
 */
int OH_Preferences_GetInt(OH_Preferences *preference, const char *key, int *value);

/**
 * @brief Obtains the Boolean value in a Preferences object based on the given key.
 *
 * @param preference Pointer to the target {@Link OH_Preferences} instance.
 * @param key Pointer to the key of the value to obtain.
 * @param value Pointer to the Boolean value obtained.
 * @return Returns the status code of the execution.
 *         {@link PREFERENCES_OK} indicates the operation is successful.
 *         {@link PREFERENCES_ERROR_INVALID_PARAM} indicates invalid args are passed in.
 *         {@link PREFERENCES_ERROR_STORAGE} indicates an storage error.
 *         {@link PREFERENCES_ERROR_MALLOC} indicates an malloc memory error.
 *         {@link PREFERENCES_ERROR_KEY_NOT_FOUND} indicates the key does not exist.
 * @see OH_Preferences.
 * @since 13
 */
int OH_Preferences_GetBool(OH_Preferences *preference, const char *key, bool *value);

/**
 * @brief Obtains the string value in a Preferences object based on the given key.
 *
 * @param preference Pointer to the target {@Link OH_Preferences} instance.
 * @param key Pointer to the key of the value to obtain.
 * @param value Double pointer to the value obtained in an char * array. Release {@Link OH_Preferences_FreeString} the
 * memory by user when this parameter is no longer required.
 * @param valueLen Pointer to the length of the string obtained.
 * @return Returns the status code of the execution.
 *         {@link PREFERENCES_OK} indicates the operation is successful.
 *         {@link PREFERENCES_ERROR_INVALID_PARAM} indicates invalid args are passed in.
 *         {@link PREFERENCES_ERROR_STORAGE} indicates an storage error.
 *         {@link PREFERENCES_ERROR_MALLOC} indicates an malloc memory error.
 *         {@link PREFERENCES_ERROR_KEY_NOT_FOUND} indicates the key does not exist.
 * @see OH_Preferences.
 * @since 13
 */
int OH_Preferences_GetString(OH_Preferences *preference, const char *key, char **value, uint32_t *valueLen);

/**
 * @brief Free a string got by Preferences object.
 *
 * @param string Point to string need to free.
 * @see OH_Preferences.
 * @since 13
 */
void OH_Preferences_FreeString(char *string);

/**
 * @brief Sets an integer in a Preferences object.
 *
 * @param preference Pointer to the target {@Link OH_Preferences} instance.
 * @param key Pointer to the key to set.
 * @param value Value to set.
 * @return Returns the status code of the execution.
 *         {@link PREFERENCES_OK} indicates the operation is successful.
 *         {@link PREFERENCES_ERROR_INVALID_PARAM} indicates invalid args are passed in.
 *         {@link PREFERENCES_ERROR_STORAGE} indicates an storage error.
 *         {@link PREFERENCES_ERROR_MALLOC} indicates an malloc memory error.
 * @see OH_Preferences.
 * @since 13
 */
int OH_Preferences_SetInt(OH_Preferences *preference, const char *key, int value);

/**
 * @brief Sets a Boolean value in a Preferences object.
 *
 * @param preference Pointer to the target {@Link OH_Preferences} instance.
 * @param key Pointer to the key to set.
 * @param value Boolean value to set.
 * @return Returns the status code of the execution.
 *         {@link PREFERENCES_OK} indicates the operation is successful.
 *         {@link PREFERENCES_ERROR_INVALID_PARAM} indicates invalid args are passed in.
 *         {@link PREFERENCES_ERROR_STORAGE} indicates an storage error.
 *         {@link PREFERENCES_ERROR_MALLOC} indicates an malloc memory error.
 * @see OH_Preferences.
 * @since 13
 */
int OH_Preferences_SetBool(OH_Preferences *preference, const char *key, bool value);

/**
 * @brief Sets a string in a Preferences object.
 *
 * @param preference Pointer to the target {@Link OH_Preferences} instance.
 * @param key Pointer to the key to set.
 * @param value Point to string to set.
 * @return Returns the status code of the execution.
 *         {@link PREFERENCES_OK} indicates the operation is successful.
 *         {@link PREFERENCES_ERROR_INVALID_PARAM} indicates invalid args are passed in.
 *         {@link PREFERENCES_ERROR_STORAGE} indicates an storage error.
 *         {@link PREFERENCES_ERROR_MALLOC} indicates an malloc memory error.
 * @see OH_Preferences.
 * @since 13
 */
int OH_Preferences_SetString(OH_Preferences *preference, const char *key, const char *value);

/**
 * @brief Deletes a KV pair from a Preferences object.
 *
 * @param preference Pointer to the target {@Link OH_Preferences} instance.
 * @param key Pointer to the key of the data to delete.
 * @return Returns the status code of the execution.
 *         {@link PREFERENCES_OK} indicates the operation is successful.
 *         {@link PREFERENCES_ERROR_INVALID_PARAM} indicates invalid args are passed in.
 *         {@link PREFERENCES_ERROR_STORAGE} indicates an storage error.
 *         {@link PREFERENCES_ERROR_MALLOC} indicates an malloc memory error.
 * @see OH_Preferences.
 * @since 13
 */
int OH_Preferences_Delete(OH_Preferences *preference, const char *key);

/**
 * @brief Registers a data observer for a Preferences object.
 *
 * @param preference Pointer to the target {@Link OH_Preferences} instance.
 * @param context Pointer to the context of the data observer.
 * @param observer the {@Link OH_PreferencesDataObserver} to register.
 * @param keys Pointer to the keys to observe.
 * @param keyCount Number of keys to observe.
 * @return Returns the status code of the execution.
 *         {@link PREFERENCES_OK} indicates the operation is successful.
 *         {@link PREFERENCES_ERROR_INVALID_PARAM} indicates invalid args are passed in.
 *         {@link PREFERENCES_ERROR_STORAGE} indicates an storage error.
 *         {@link PREFERENCES_ERROR_MALLOC} indicates an malloc memory error.
 *         {@link PREFERENCES_ERROR_GET_DATAOBSMGRCLIENT} indicates get dataObsMgrClient error.
 * @see OH_Preferences OH_PreferencesDataObserver.
 * @since 13
 */
int OH_Preferences_RegisterDataObserver(OH_Preferences *preference, void *context,
    OH_PreferencesDataObserver observer, const char *keys[], uint32_t keyCount);

/**
 * @brief Unregisters a data observer for a Preferences object.
 *
 * @param preference Pointer to the target {@Link OH_Preferences} instance.
 * @param context Pointer to the context of the data observer.
 * @param observer the {@Link OH_PreferencesDataObserver} to unregister.
 * @param keys Pointer to the keys observed. If this parameter is null, this API unregisters the listening for all keys.
 * @param keyCount Number of the keys.
 * @return Returns the status code of the execution.
 *         {@link PREFERENCES_OK} indicates the operation is successful.
 *         {@link PREFERENCES_ERROR_INVALID_PARAM} indicates invalid args are passed in.
 *         {@link PREFERENCES_ERROR_STORAGE} indicates an storage error.
 *         {@link PREFERENCES_ERROR_MALLOC} indicates an malloc memory error.
 * @see OH_Preferences OH_PreferencesDataObserver.
 * @since 13
 */
int OH_Preferences_UnregisterDataObserver(OH_Preferences *preference, void *context,
    OH_PreferencesDataObserver observer, const char *keys[], uint32_t keyCount);

#ifdef __cplusplus
};
#endif

/** @} */
#endif // OH_PREFERENCES_H