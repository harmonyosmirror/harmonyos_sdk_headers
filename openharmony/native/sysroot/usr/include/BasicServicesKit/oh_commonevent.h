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
 * @addtogroup OH_CommonEvent
 * @{
 *
 * @brief Provides the APIs of common event service.
 *
 * @since 12
 */
/**
 * @file oh_commonevent.h
 *
 * @brief Declares the APIs to subscribe and unsubscribe common event, and so on.
 *
 * @library libohcommonevent.so
 * @kit BasicServicesKit
 * @syscap SystemCapability.Notification.CommonEvent
 * @since 12
 * @version 1.0
 */

#ifndef OH_COMMONEVENT_H
#define OH_COMMONEVENT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines error codes.
 *
 * @since 12
 * @version 1.0
 */
typedef enum CommonEvent_ErrCode {
    /** @error Execution successful. */
    COMMONEVENT_ERR_OK = 0,

    /** @error permission verification failed. */
    COMMONEVENT_ERR_PERMISSION_ERROR = 201,

    /** @error invalid input parameter. */
    COMMONEVENT_ERR_INVALID_PARAMETER = 401,

    /** @error IPC request failed to send. */
    COMMONEVENT_ERR_SENDING_REQUEST_FAILED = 1500007,

    /** @error Common event service not init. */
    COMMONEVENT_ERR_INIT_UNDONE = 1500008,

    /** @error The subscriber number exceed system specification */
    COMMONEVENT_ERR_SUBSCRIBER_NUM_EXCEEDED = 1500010,

    /** @error A memory allocation error occurs. */
    COMMONEVENT_ERR_ALLOC_MEMORY_FAILED = 1500011,
} CommonEvent_ErrCode;

/**
 * @brief the information of the subscriber
 *
 * @since 12
 */
typedef struct CommonEvent_SubscribeInfo CommonEvent_SubscribeInfo;

/**
 * @brief the subscriber of common event
 *
 * @since 12
 */
typedef void CommonEvent_Subscriber;

/**
 * @brief the data of the commonEvent callback
 *
 * @since 12
 */
typedef struct CommonEvent_RcvData CommonEvent_RcvData;

/**
 * @brief The description of the parameters in a common event callback data.
 *
 * @since 12
 */
typedef void CommonEvent_Parameters;

/**
 * @brief Common event callback.
 *
 * @param data common event callback data.
 * @since 12
 */
typedef void (*CommonEvent_ReceiveCallback)(const CommonEvent_RcvData *data);

/**
 * @brief Create subscribe information.
 *
 * @param events Indicates the subscribed events.
 * @param eventsNum Indicates the subscribed events of number.
 * @return Returns the CommonEvent_SubscribeInfo, if allocate memory failed, returns null.
 * @since 12
 */
CommonEvent_SubscribeInfo* OH_CommonEvent_CreateSubscribeInfo(const char* events[], int32_t eventsNum);

/**
 * @brief Set the subscribe information of permission.
 *
 * @param info Indicates the subscribed events.
 * @param permission Indicates the subscribed events of number.
 * @return Returns the error code.
 *         Returns {@link COMMONEVENT_ERR_OK} if the operation is successful.
 *         Returns {@link COMMONEVENT_ERR_INVALID_PARAMETER} if a parameter error occurs.
 * @since 12
 */
CommonEvent_ErrCode OH_CommonEvent_SetPublisherPermission(CommonEvent_SubscribeInfo* info, const char* permission);

/**
 * @brief Set the subscribe information of bundleName.
 *
 * @param info Indicates the subscribed events.
 * @param bundleName Indicates the subscribed events of number.
 * @return Returns the error code.
 *         Returns {@link COMMONEVENT_ERR_OK} if the operation is successful.
 *         Returns {@link COMMONEVENT_ERR_INVALID_PARAMETER} if a parameter error occurs.
 * @since 12
 */
CommonEvent_ErrCode OH_CommonEvent_SetPublisherBundleName(CommonEvent_SubscribeInfo* info, const char* bundleName);

/**
 * @brief Destroy the subscribe information.
 *
 * @param info Indicates the subscribe info.
 * @since 12
 */
void OH_CommonEvent_DestroySubscribeInfo(CommonEvent_SubscribeInfo* info);

/**
 * @brief Create a subscriber.
 *
 * @param info Indicates the created subscribe Info.
 * @param callback Indicates the received common event callback.
 * @return Returns the CommonEvent_Subscriber, if allocate memory failed, returns null.
 * @since 12
 */
CommonEvent_Subscriber* OH_CommonEvent_CreateSubscriber(const CommonEvent_SubscribeInfo* info,
    CommonEvent_ReceiveCallback callback);

/**
 * @brief Destory the subscriber.
 *
 * @param subscriber Indicates the created subscriber.
 * @since 12
 */
void OH_CommonEvent_DestroySubscriber(CommonEvent_Subscriber* subscriber);

/**
 * @brief Subscribe event by a subscriber.
 *
 * @param subscriber Indicates the subscriber.
 * @return Returns the error code.
 *         Returns {@link COMMONEVENT_ERR_OK} if the operation is successful.
 *         Returns {@link COMMONEVENT_ERR_INVALID_PARAMETER } if the input parameter is invalid.
 *         Returns {@link COMMONEVENT_ERR_SENDING_REQUEST_FAILED } if IPC request failed to send.
 *         Returns {@link COMMONEVENT_ERR_INIT_UNDONE } if ces not init done.
 *         Returns {@link COMMONEVENT_ERR_SUBSCRIBER_NUM_EXCEEDED } if the subscriber number is exceeded.
 *         Returns {@link COMMONEVENT_ERR_ALLOC_MEMORY_FAILED } if a memory allocation error occurs.
 * @since 12
 */
CommonEvent_ErrCode OH_CommonEvent_Subscribe(const CommonEvent_Subscriber* subscriber);

/**
 * @brief Unsubscribe event by a subscriber.
 *
 * @param subscriber Indicates the subscriber.
 * @return Returns the error code.
 *         Returns {@link COMMONEVENT_ERR_OK} if the operation is successful.
 *         Returns {@link COMMONEVENT_ERR_INVALID_PARAMETER } if the input parameter is invalid.
 *         Returns {@link COMMONEVENT_ERR_SENDING_REQUEST_FAILED } if IPC request failed to send.
 *         Returns {@link COMMONEVENT_ERR_INIT_UNDONE } if ces not init done.
 * @since 12
 */
CommonEvent_ErrCode OH_CommonEvent_UnSubscribe(const CommonEvent_Subscriber* subscriber);

/**
 * @brief Get event name from callback data.
 *
 * @param rcvData Indicates the event of callback data.
 * @return Returns the event name.
 * @since 12
 */
const char* OH_CommonEvent_GetEventFromRcvData(const CommonEvent_RcvData* rcvData);

/**
 * @brief Get event result code from callback data.
 *
 * @param rcvData Indicates the event of callback data.
 * @return Returns the event of result code, default is 0.
 * @since 12
 */
int32_t OH_CommonEvent_GetCodeFromRcvData(const CommonEvent_RcvData* rcvData);

/**
 * @brief Get event result data from callback data.
 *
 * @param rcvData Indicates the event of callback data.
 * @return Returns the event of result data, default is null.
 * @since 12
 */
const char* OH_CommonEvent_GetDataStrFromRcvData(const CommonEvent_RcvData* rcvData);

/**
 * @brief Get event bundlename from callback data.
 *
 * @param rcvData Indicates the event of callback data.
 * @return Returns the event of bundlename, default is null.
 * @since 12
 */
const char* OH_CommonEvent_GetBundleNameFromRcvData(const CommonEvent_RcvData* rcvData);

/**
 * @brief Get event parameters data from callback data.
 *
 * @param rcvData Indicates the event of callback data.
 * @return Returns the event of parameters data, default is null.
 * @since 12
 */
const CommonEvent_Parameters* OH_CommonEvent_GetParametersFromRcvData(const CommonEvent_RcvData* rcvData);

/**
 * @brief Check whether the parameters contains a key.
 *
 * @param rcvData Indicates the event of callback data.
 * @param key Indicates the key of parameter.
 * @return Returns the result of check, true means it contains.
 * @since 12
 */
bool OH_CommonEvent_HasKeyInParameters(const CommonEvent_Parameters* para, const char* key);

/**
 * @brief Get int data from parameters data by key.
 *
 * @param rcvData Indicates the event of parameters data.
 * @param key Indicates the key of parameters data.
 * @param defaultValue Indicates default return value.
 * @return Returns the int data of the key in the parameters.
 * @since 12
 */
int OH_CommonEvent_GetIntFromParameters(const CommonEvent_Parameters* para, const char* key, const int defaultValue);

/**
 * @brief Get int array data from parameters data by key.
 *
 * @param rcvData Indicates the event of parameters data.
 * @param key Indicates the key of parameters data.
 * @param array Indicates the int array.
 * @return Returns the length of the array.
 * @since 12
 */
int32_t OH_CommonEvent_GetIntArrayFromParameters(const CommonEvent_Parameters* para, const char* key, int** array);

/**
 * @brief Get long data from parameters data by key.
 *
 * @param rcvData Indicates the event of parameters data.
 * @param key Indicates the key of parameters data.
 * @param defaultValue Indicates default return value.
 * @return Returns the long data of the key in the parameters.
 * @since 12
 */
long OH_CommonEvent_GetLongFromParameters(const CommonEvent_Parameters* para, const char* key, const long defaultValue);

/**
 * @brief Get long array data from parameters data by key.
 *
 * @param rcvData Indicates the event of parameters data.
 * @param key Indicates the key of parameters data.
 * @param array Indicates the long array.
 * @return Returns the length of the array.
 * @since 12
 */
int32_t OH_CommonEvent_GetLongArrayFromParameters(const CommonEvent_Parameters* para, const char* key, long** array);

/**
 * @brief Get bool data from parameters data by key.
 *
 * @param rcvData Indicates the event of parameters data.
 * @param key Indicates the key of parameters data.
 * @param defaultValue Indicates default return value.
 * @return Returns the bool data of the key in the parameters.
 * @since 12
 */
bool OH_CommonEvent_GetBoolFromParameters(const CommonEvent_Parameters* para, const char* key, const bool defaultValue);

/**
 * @brief Get bool array data from parameters data by key.
 *
 * @param rcvData Indicates the event of parameters data.
 * @param key Indicates the key of parameters data.
 * @param array Indicates the bool array.
 * @return Returns the length of the array.
 * @since 12
 */
int32_t OH_CommonEvent_GetBoolArrayFromParameters(const CommonEvent_Parameters* para, const char* key, bool** array);

/**
 * @brief Get char data from parameters data by key.
 *
 * @param rcvData Indicates the event of parameters data.
 * @param key Indicates the key of parameters data.
 * @param defaultValue Indicates default return value.
 * @return Returns the char data of the key in the parameters.
 * @since 12
 */
char OH_CommonEvent_GetCharFromParameters(const CommonEvent_Parameters* para, const char* key, const char defaultValue);

/**
 * @brief Get char array data from parameters data by key.
 *
 * @param rcvData Indicates the event of parameters data.
 * @param key Indicates the key of parameters data.
 * @param array Indicates the char array.
 * @return Returns the length of the array.
 * @since 12
 */
int32_t OH_CommonEvent_GetCharArrayFromParameters(const CommonEvent_Parameters* para, const char* key, char** array);

/**
 * @brief Get double data from parameters data by key.
 *
 * @param rcvData Indicates the event of parameters data.
 * @param key Indicates the key of parameters data.
 * @param defaultValue Indicates default return value.
 * @return Returns the double data of the key in the parameters.
 * @since 12
 */
double OH_CommonEvent_GetDoubleFromParameters(const CommonEvent_Parameters* para, const char* key,
    const double defaultValue);

/**
 * @brief Get double array data from parameters data by key.
 *
 * @param rcvData Indicates the event of parameters data.
 * @param key Indicates the key of parameters data.
 * @param array Indicates the double array.
 * @return Returns the length of the array, default is 0.
 * @since 12
 */
int32_t OH_CommonEvent_GetDoubleArrayFromParameters(const CommonEvent_Parameters* para, const char* key,
    double** array);

#ifdef __cplusplus
}
#endif
#endif // OH_COMMONEVENT_H
/** @} */
