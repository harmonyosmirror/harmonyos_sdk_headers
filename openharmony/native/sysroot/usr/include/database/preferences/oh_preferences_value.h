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
 * @file oh_preferences_value.h
 *
 * @brief Defines the APIs and enums related to preferences values.
 *
 * @kit ArkData
 * @library libohpreferences.so
 * @syscap SystemCapability.DistributedDataManager.Preferences.Core
 *
 * @since 13
 */

#ifndef OH_PREFERENCES_VALUE_H
#define OH_PREFERENCES_VALUE_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates the Preference value types.
 *
 * @since 13
 */
typedef enum Preference_ValueType {
    /**
     * @brief Null.
     */
    PREFERENCE_TYPE_NULL = 0,
    /**
     * @brief Int.
     */
    PREFERENCE_TYPE_INT,
    /**
     * @brief boolean.
     */
    PREFERENCE_TYPE_BOOL,
    /**
     * @brief String.
     */
    PREFERENCE_TYPE_STRING,
    /**
     * @brief end butt.
     */
    PREFERENCE_TYPE_BUTT
} Preference_ValueType;

/**
 * @brief Represents a KV pair in a Preferences instance.
 *
 * @since 13
 */
typedef struct OH_PreferencesPair OH_PreferencesPair;

/**
 * @brief Represents the value in a KV pair of a Preferences instance.
 *
 * @since 13
 */
typedef struct OH_PreferencesValue OH_PreferencesValue;

/**
 * @brief Obtains a key from an {@Link OH_PreferencesPair} instance.
 *
 * @param pairs Pointer to the target {@Link OH_PreferencesPair} instance.
 * @param index Represents a target index of the pairs
 * @return Returns preferences pointer to the key that when input parameters valid,
 * return nullptr otherwise while invalid args are passed in.
 * @see OH_PreferencesPair.
 * @since 13
 */
const char *OH_PreferencesPair_GetKey(const OH_PreferencesPair *pairs, uint32_t index);

/**
 * @brief Obtains a value from an {@Link OH_PreferencesPair} instance.
 *
 * @param pairs Pointer to the target {@Link OH_PreferencesPair} instance.
 * @param index Index of the value to obtain.
 * @return Returns a pointer to the {@Link OH_PreferencesValue} obtained if the operation is successful,
 * returns nullptr otherwise while invalid args are passed in.
 * @see OH_PreferencesValue.
 * @since 13
 */
const OH_PreferencesValue *OH_PreferencesPair_GetPreferencesValue(const OH_PreferencesPair *pairs, uint32_t index);

/**
 * @brief Obtains the type of a preferences value.
 *
 * @param object Pointer to the target {@Link OH_PreferencesValue} instance.
 * @return Returns the value type obtained.
 *         {@link PREFERENCE_TYPE_NULL} indicates invalid args are passed in.
 * @see OH_PreferencesValue.
 * @since 13
 */
Preference_ValueType OH_PreferencesValue_GetValueType(const OH_PreferencesValue *object);

/**
 * @brief Obtains the int value of an {@Link OH_PreferencesValue} instance.
 *
 * @param object Pointer to the target {@Link OH_PreferencesValue} instance.
 * @param value Pointer to the value obtained.
 * @return Returns the status code of the execution.
 *         {@link PREFERENCES_OK} indicates the operation is successful.
 *         {@link PREFERENCES_ERROR_INVALID_PARAM} indicates invalid args are passed in.
 *         {@link PREFERENCES_ERROR_STORAGE} indicates an storage error.
 *         {@link PREFERENCES_ERROR_MALLOC} indicates an malloc memory error.
 * @see OH_PreferencesValue.
 * @since 13
 */
int OH_PreferencesValue_GetInt(const OH_PreferencesValue *object, int *value);

/**
 * @brief Obtains the Boolean value of an {@Link OH_PreferencesValue} instance.
 *
 * @param object Pointer to the target {@Link OH_PreferencesValue} instance.
 * @param value Pointer to the Boolean value obtained.
 * @return Returns the status code of the execution.
 *         {@link PREFERENCES_OK} indicates the operation is successful.
 *         {@link PREFERENCES_ERROR_INVALID_PARAM} indicates invalid args are passed in.
 *         {@link PREFERENCES_ERROR_STORAGE} indicates an storage error.
 *         {@link PREFERENCES_ERROR_MALLOC} indicates an malloc memory error.
 * @see OH_PreferencesValue.
 * @since 13
 */
int OH_PreferencesValue_GetBool(const OH_PreferencesValue *object, bool *value);

/**
 * @brief Obtains the string value of an {@Link OH_PreferencesValue} instance.
 *
 * @param object Pointer to target {@Link OH_PreferencesValue} instance.
 * @param value Double pointer to the value obtained in an char * array. Release {@Link OH_Preferences_FreeString} the
 * memory by user when this parameter is no longer required.
 * @param valueLen Pointer to the string length.
 * @return Returns the status code of the execution.
 *         {@link PREFERENCES_OK} indicates the operation is successful.
 *         {@link PREFERENCES_ERROR_INVALID_PARAM} indicates invalid args are passed in.
 *         {@link PREFERENCES_ERROR_STORAGE} indicates an storage error.
 *         {@link PREFERENCES_ERROR_MALLOC} indicates an malloc memory error.
 * @see OH_PreferencesValue.
 * @since 13
 */
int OH_PreferencesValue_GetString(const OH_PreferencesValue *object, char **value, uint32_t *valueLen);
#ifdef __cplusplus
};
#endif
#endif // OH_PREFERENCES_VALUE_H