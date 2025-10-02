/*
 * Copyright (c) 2021-2025 Huawei Device Co., Ltd.
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
 * @addtogroup HiAppEvent
 * @{
 *
 * @brief Provides application event logging functions.
 *
 * Provides the event logging function for applications to log the fault, statistical, security, and user behavior
 * events reported during running. Based on event information, you will be able to analyze the running status of
 * applications.
 *
 * @since 8
 * @version 1.0
 */

/**
 * @file hiappevent.h
 *
 * @brief Defines the application event logging functions of the HiAppEvent module.
 *
 * Before performing application event logging, you must construct a ParamList object to store the input
 * event parameters and specify the event domain, event name, and event type.
 *
 * <p>Event domain: a string used to identify the domain of event logging.
 * <p>Event name: a string used to identify the event name of event logging.
 * <p>Event type: FAULT, STATISTIC, SECURITY, BEHAVIOR.
 * <p>ParamList: a linked list used to store event parameters, each of which is comprised of the parameter name and
 * parameter value.
 *
 * Sample code:
 * 00 Including the header file:
 * <pre>
 *     #include "hiappevent/hiappevent.h"
 * </pre>
 * 01 create a ParamList pointer.
 * <pre>
 *     ParamList list = OH_HiAppEvent_CreateParamList();
 * </pre>
 * 02 add params to the ParamList.
 * <pre>
 *     bool boolean = true;
 *     OH_HiAppEvent_AddBoolParam(list, "bool_key", boolean);
 *     int32_t nums[] = {1, 2, 3};
 *     OH_HiAppEvent_AddInt32ArrayParam(list, "int32_arr_key", nums, sizeof(nums) / sizeof(nums[0]));
 * </pre>
 * 03 performing event logging.
 * <pre>
 *     int res = OH_HiAppEvent_Write("test_domain", "test_event", BEHAVIOR, list);
 * </pre>
 * 04 destroy the ParamList pointer.
 * <pre>
 *     OH_HiAppEvent_DestroyParamList(list);
 * </pre>
 *
 * @kit PerformanceAnalysisKit
 * @library libhiappevent_ndk.z.so
 * @syscap SystemCapability.HiviewDFX.HiAppEvent
 * @since 8
 * @version 1.0
 */

#ifndef HIVIEWDFX_HIAPPEVENT_H
#define HIVIEWDFX_HIAPPEVENT_H

#include <stdbool.h>
#include <stdint.h>

#include "hiappevent_cfg.h"
#include "hiappevent_event.h"
#include "hiappevent_param.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines error code
 *
 * @since 15
 */
typedef enum {
    /** @error The operation is successful. */
    HIAPPEVENT_SUCCESS = 0,
    /**
     * @error Invalid param value length
     * @since 18
     */
    HIAPPEVENT_INVALID_PARAM_VALUE_LENGTH = 4,
    /**
     * @error Processor is null
     * @since 18
     */
    HIAPPEVENT_PROCESSOR_IS_NULL = -7,
    /**
     * @error Processor not found
     * @since 18
     */
    HIAPPEVENT_PROCESSOR_NOT_FOUND = -8,
    /** @error Invalid param value */
    HIAPPEVENT_INVALID_PARAM_VALUE = -9,
    /** @error event config is null */
    HIAPPEVENT_EVENT_CONFIG_IS_NULL = -10,
    /**
     * @error Operate failed
     * @since 18
     */
    HIAPPEVENT_OPERATE_FAILED = -100,
    /**
     * @error Invalid uid
     * @since 18
     */
    HIAPPEVENT_INVALID_UID = -200
} HiAppEvent_ErrorCode;

/**
 * @brief Event types.
 *
 * You are advised to select event types based on their respective usage scenarios.
 *
 * @since 8
 * @version 1.0
 */
enum EventType {
    /* Fault event type */
    FAULT = 1,

    /* Statistic event type */
    STATISTIC = 2,

    /* Security event type */
    SECURITY = 3,

    /* Behavior event type */
    BEHAVIOR = 4
};

/**
 * @brief The HiAppEvent_AppEventInfo structure is used to represent event information in an application, including
 * the event's domain, name, type, and parameters.
 *
 * @since 12
 * @version 1.0
 */
typedef struct HiAppEvent_AppEventInfo {
    /* The domain of the event. */
    const char* domain;
    /* The name of the event. */
    const char* name;
    /* The type of the event. */
    enum EventType type;
    /* The json string of the parameter. */
    const char* params;
} HiAppEvent_AppEventInfo;

/**
 * @brief The HiAppEvent_AppEventGroup structure represents a group of events in an application. It contains the name
 * of the event group, an array of HiAppEvent_AppEventInfo structures representing individual events grouped by the
 * name, and the length of the event array.
 *
 * @syscap SystemCapability.HiviewDFX.HiAppEvent
 * @since 12
 * @version 1.0
 */
typedef struct HiAppEvent_AppEventGroup {
    /* The name of the event. */
    const char* name;
    /* The event array which is group by the name. */
    const struct HiAppEvent_AppEventInfo* appEventInfos;
    /* The length of appEventInfos array. */
    uint32_t infoLen;
} HiAppEvent_AppEventGroup;

/**
 * @brief Event param list node.
 *
 * @since 8
 * @version 1.0
 */
typedef struct ParamListNode* ParamList;

/**
 * @brief The HiAppEvent_Watcher structure is designed for event monitoring, allowing it to be invoked when the event
 * occurs.
 *
 * @syscap SystemCapability.HiviewDFX.HiAppEvent
 * @since 12
 * @version 1.0
 */
typedef struct HiAppEvent_Watcher HiAppEvent_Watcher;

/**
 * @brief The HiAppEvent_Processor structure is designed for event report.
 *
 * @since 18
 */
typedef struct HiAppEvent_Processor HiAppEvent_Processor;

/**
 * @brief The HiAppEvent_Config structure is designed for configuration.
 *
 * @since 15
 */
typedef struct HiAppEvent_Config HiAppEvent_Config;

/**
 * @brief The OH_HiAppEvent_OnReceive function acts as the callback function for the HiAppEvent_Watcher. It is called
 * when an event occurs.
 *
 * @param domain The domain of the event.
 * @param appEventGroups The event group by the domain.
 * @param groupLen The length of appEventGroups array.
 * @since 12
 * @version 1.0
 */
typedef void (*OH_HiAppEvent_OnReceive)(
    const char* domain, const struct HiAppEvent_AppEventGroup* appEventGroups, uint32_t groupLen);

/**
 * @brief Called when watcher receive the event meet the condition.
 *
 * @param row The row of events received by watcher.
 * @param size The size of events received by watcher.
 * @since 12
 * @version 1.0
 */
typedef void (*OH_HiAppEvent_OnTrigger)(int row, int size);

/**
 * @brief Called when watcher take the events.
 *
 * @param events The event json string array.
 * @param eventLen The length of events array.
 * @since 12
 * @version 1.0
 */
typedef void (*OH_HiAppEvent_OnTake)(const char* const *events, uint32_t eventLen);

/**
 * @brief Create a pointer to the ParamList.
 *
 * @return Pointer to the ParamList.
 * @since 8
 * @version 1.0
 */
ParamList OH_HiAppEvent_CreateParamList(void);

/**
 * @brief Destroy a pointer to the ParamList.
 *
 * @param list Event param list.
 * @since 8
 * @version 1.0
 */
void OH_HiAppEvent_DestroyParamList(ParamList list);

/**
 * @brief Add bool param to the ParamList.
 *
 * @param list The ParamList of params to be added.
 * @param name The name of the param to be added.
 * @param boolean The bool value of the param to be added.
 * @return ParamList after the param is added.
 * @since 8
 * @version 1.0
 */
ParamList OH_HiAppEvent_AddBoolParam(ParamList list, const char* name, bool boolean);

/**
 * @brief Add bool array param to the ParamList.
 *
 * @param list The ParamList of params to be added.
 * @param name The name of the param to be added.
 * @param booleans The bool array value of the param to be added.
 * @param arrSize The array size of the param to be added.
 * @return ParamList after the param is added.
 * @since 8
 * @version 1.0
 */
ParamList OH_HiAppEvent_AddBoolArrayParam(ParamList list, const char* name, const bool* booleans, int arrSize);

/**
 * @brief Add int8_t param to the ParamList.
 *
 * @param list The ParamList of params to be added.
 * @param name The name of the param to be added.
 * @param num The int8_t value of the param to be added.
 * @return ParamList after the param is added.
 * @since 8
 * @version 1.0
 */
ParamList OH_HiAppEvent_AddInt8Param(ParamList list, const char* name, int8_t num);

/**
 * @brief Add int8_t array param to the ParamList.
 *
 * @param list The ParamList of params to be added.
 * @param name The name of the param to be added.
 * @param nums The int8_t array value of the param to be added.
 * @param arrSize The array size of the param to be added.
 * @return ParamList after the param is added.
 * @since 8
 * @version 1.0
 */
ParamList OH_HiAppEvent_AddInt8ArrayParam(ParamList list, const char* name, const int8_t* nums, int arrSize);

/**
 * @brief Add int16_t param to the ParamList.
 *
 * @param list The ParamList of params to be added.
 * @param name The name of the param to be added.
 * @param num The int16_t value of the param to be added.
 * @return ParamList after the param is added.
 * @since 8
 * @version 1.0
 */
ParamList OH_HiAppEvent_AddInt16Param(ParamList list, const char* name, int16_t num);

/**
 * @brief Add int16_t array param to the ParamList.
 *
 * @param list The ParamList of params to be added.
 * @param name The name of the param to be added.
 * @param nums The int16_t array value of the param to be added.
 * @param arrSize The array size of the param to be added.
 * @return ParamList after the param is added.
 * @since 8
 * @version 1.0
 */
ParamList OH_HiAppEvent_AddInt16ArrayParam(ParamList list, const char* name, const int16_t* nums, int arrSize);

/**
 * @brief Add int32_t param to the ParamList.
 *
 * @param list The ParamList of params to be added.
 * @param name The name of the param to be added.
 * @param num The int32_t value of the param to be added.
 * @return ParamList after the param is added.
 * @since 8
 * @version 1.0
 */
ParamList OH_HiAppEvent_AddInt32Param(ParamList list, const char* name, int32_t num);

/**
 * @brief Add int32_t array param to the ParamList.
 *
 * @param list The ParamList of params to be added.
 * @param name The name of the param to be added.
 * @param nums The int32_t array value of the param to be added.
 * @param arrSize The array size of the param to be added.
 * @return ParamList after the param is added.
 * @since 8
 * @version 1.0
 */
ParamList OH_HiAppEvent_AddInt32ArrayParam(ParamList list, const char* name, const int32_t* nums, int arrSize);

/**
 * @brief Add int64_t param to the ParamList.
 *
 * @param list The ParamList of params to be added.
 * @param name The name of the param to be added.
 * @param num The int64_t value of the param to be added.
 * @return ParamList after the param is added.
 * @since 8
 * @version 1.0
 */
ParamList OH_HiAppEvent_AddInt64Param(ParamList list, const char* name, int64_t num);

/**
 * @brief Add int64_t array param to the ParamList.
 *
 * @param list The ParamList of params to be added.
 * @param name The name of the param to be added.
 * @param nums The int64_t array value of the param to be added.
 * @param arrSize The array size of the param to be added.
 * @return ParamList after the param is added.
 * @since 8
 * @version 1.0
 */
ParamList OH_HiAppEvent_AddInt64ArrayParam(ParamList list, const char* name, const int64_t* nums, int arrSize);

/**
 * @brief Add float param to the ParamList.
 *
 * @param list The ParamList of params to be added.
 * @param name The name of the param to be added.
 * @param num The float value of the param to be added.
 * @return ParamList after the param is added.
 * @since 8
 * @version 1.0
 */
ParamList OH_HiAppEvent_AddFloatParam(ParamList list, const char* name, float num);

/**
 * @brief Add float array param to the ParamList.
 *
 * @param list The ParamList of params to be added.
 * @param name The name of the param to be added.
 * @param nums The float array value of the param to be added.
 * @param arrSize The array size of the param to be added.
 * @return ParamList after the param is added.
 * @since 8
 * @version 1.0
 */
ParamList OH_HiAppEvent_AddFloatArrayParam(ParamList list, const char* name, const float* nums, int arrSize);

/**
 * @brief Add double param to the ParamList.
 *
 * @param list The ParamList of params to be added.
 * @param name The name of the param to be added.
 * @param num The double value of the param to be added.
 * @return ParamList after the param is added.
 * @since 8
 * @version 1.0
 */
ParamList OH_HiAppEvent_AddDoubleParam(ParamList list, const char* name, double num);

/**
 * @brief Add double array param to the ParamList.
 *
 * @param list The ParamList of params to be added.
 * @param name The name of the param to be added.
 * @param nums The double array value of the param to be added.
 * @param arrSize The array size of the param to be added.
 * @return ParamList after the param is added.
 * @since 8
 * @version 1.0
 */
ParamList OH_HiAppEvent_AddDoubleArrayParam(ParamList list, const char* name, const double* nums, int arrSize);

/**
 * @brief Add string param to the ParamList.
 *
 * @param list The ParamList of params to be added.
 * @param name The name of the param to be added.
 * @param str The string value of the param to be added.
 * @return ParamList after the param is added.
 * @since 8
 * @version 1.0
 */
ParamList OH_HiAppEvent_AddStringParam(ParamList list, const char* name, const char* str);

/**
 * @brief Add string array param to the ParamList.
 *
 * @param list The ParamList of params to be added.
 * @param name The name of the param to be added.
 * @param strs The string array value of the param to be added.
 * @param arrSize The array size of the param to be added.
 * @return ParamList after the param is added.
 * @since 8
 * @version 1.0
 */
ParamList OH_HiAppEvent_AddStringArrayParam(ParamList list, const char* name, const char * const *strs, int arrSize);

/**
 * @brief Implements logging of application events whose parameters are of the list type.
 *
 * Before logging an application event, this API will first verify parameters of this event.
 * If the verification is successful, the API will write the event to the event file.
 *
 * @param domain Indicates the event domain. You can customize the event domain as needed.
 * @param name Indicates the event name. You can customize the event name as needed.
 * @param type Indicates the event type, which is defined in {@link EventType}.
 * @param list Indicates a linked list of event parameters, each of which is comprised of the parameter name and
 * parameter value.
 * @return Returns 0 if the event parameter verification is successful, and the event will be written to
 * the event file; returns a positive integer if invalid parameters are present in the event, and
 * the event will be written to the event file after the invalid parameters are ignored; returns a
 * negative integer if the event parameter verification fails, and the event will not be written to the event file.
 *         {@code 0} Parameters verification is successful.
 *         {@code -1} Invalid event name.
 *         {@code -4} Invalid event domain.
 *         {@code -99} Function disabled.
 *         {@code 1} Invalid event parameter name.
 *         {@code 4} Invalid string length of the event parameter.
 *         {@code 5} Invalid number of event parameters.
 *         {@code 6} Invalid array length of the event parameter.
 *         {@code 8} Duplicate parameter.
 * @since 8
 * @version 1.0
 */
int OH_HiAppEvent_Write(const char* domain, const char* name, enum EventType type, const ParamList list);

/**
 * @brief Implements the configuration function of application events logging.
 *
 * Application event logging configuration interface, which is used to configure event logging switch,
 * event file directory storage quota size and other functions.
 *
 * @param name Configuration item name.
 * @param value Configuration item value.
 * @return Returns true if configuration successful; returns false if configuration failed.
 * @since 8
 * @version 1.0
 */
bool OH_HiAppEvent_Configure(const char* name, const char* value);

/**
 * @brief Create a HiAppEvent_Watcher handler pointer to set the property.
 *
 * @param name The name of the watcher.
 * @return Returns a pointer to the HiAppEvent_Watcher instance.
 * @since 12
 * @version 1.0
 */
HiAppEvent_Watcher* OH_HiAppEvent_CreateWatcher(const char* name);

/**
 * @brief Destroy the specified HiAppEvent_Watcher handle resource.
 *
 * @param watcher The pointer to the HiAppEvent_Watcher instance.
 * @since 12
 * @version 1.0
 */
void OH_HiAppEvent_DestroyWatcher(HiAppEvent_Watcher* watcher);

/**
 * @brief The interface to set trigger conditions for the watcher. Three trigger conditions can be set through this
 * interface and any of the condition which is set over than 0 met, the onTrigger callback set through
 * OH_HiAppEvent_SetWatcherOnTrigger will be invoked.
 *
 * @param watcher The pointer to the HiAppEvent_Watcher instance.
 * @param row The row of write events that trigger the onTrigger callback.
 * @param size The size of write events that trigger the onTrigger callback.
 * @param timeOut The interval for trigger the onTrigger callback.
 * @return Returns 0 if set TriggerCondition is successful, and returns a
 * negative integer if set fail.
 *         {@code 0} Success.
 *         {@code -5} The watcher is nullptr.
 * @since 12
 * @version 1.0
 */
int OH_HiAppEvent_SetTriggerCondition(HiAppEvent_Watcher* watcher, int row, int size, int timeOut);

/**
 * @brief The interface to set the AppEventFilter which defines the kind of app events will be received by  the watcher.
 *
 * @param watcher The pointer to the HiAppEvent_Watcher instance.
 * @param domain The name of the event domain to be monitored by the watcher.
 * @param eventTypes The types of the events to be monitored by the watcher.0x08 means BEHAVIOR,0x04 means
 * SECURITY, 0x02 means STATISTIC,0x01 means FAULT, 0xff and 0x00 means all.
 * @param names The names of the events to be monitored by the watcher.
 * @param namesLen The length of names array.
 * @return Returns 0 if set AppEventFilter is successful, and returns a
 * negative integer if set fail.
 *         {@code 0} Success.
 *         {@code -1} Invalid event name.
 *         {@code -4} Invalid event domain.
 *         {@code -5} The watcher is nullptr.
 * @since 12
 * @version 1.0
 */
int OH_HiAppEvent_SetAppEventFilter(HiAppEvent_Watcher* watcher, const char* domain, uint8_t eventTypes,
    const char* const *names, int namesLen);

/**
 * @brief The interface to set onTrigger callback for watcher. If the OnReceive callback is not be set or has been set
 * to nullptr, the app events received by the watcher will be saved. When the new saved appEvents met the conditions set
 * by OH_HiAppEvent_SetTriggerCondition, the onTrigger callback will be invoked.
 *
 * @param watcher The pointer to the HiAppEvent_Watcher instance.
 * @param onTrigger The callback of the watcher.
 * @return Returns 0 if set OnTrigger is successful, and returns a
 * negative integer if set fail.
 *         {@code 0} Success.
 *         {@code -5} The watcher is nullptr.
 * @since 12
 * @version 1.0
 */
int OH_HiAppEvent_SetWatcherOnTrigger(HiAppEvent_Watcher* watcher, OH_HiAppEvent_OnTrigger onTrigger);

/**
 * @brief The interface to set onReceive callback for watcher. When the watcher received an app event, the onReceive
 * callback set will be invoked.
 *
 * @param watcher The pointer to the HiAppEvent_Watcher instance.
 * @param onReceive The callback of the watcher.
 * @return Returns 0 if set OnReceive is successful, and returns a
 * negative integer if set fail.
 *         {@code 0} Success.
 *         {@code -5} The watcher is nullptr.
 * @since 12
 * @version 1.0
 */
int OH_HiAppEvent_SetWatcherOnReceive(HiAppEvent_Watcher* watcher, OH_HiAppEvent_OnReceive onReceive);

/**
 * @brief The interface to take saved events data for the watcher.
 *
 * @param watcher The pointer to the HiAppEvent_Watcher instance.
 * @param eventNum The num of events to take.
 * @param onTake The callback of the watcher.
 * @return Returns 0 if take events is successful, and returns a
 * negative integer if take fail.
 *         {@code 0} Success.
 *         {@code -5} The watcher is nullptr.
 *         {@code -6} This interface must be called after OH_HiAppEvent_AddWatcher.
 * @since 12
 * @version 1.0
 */
int OH_HiAppEvent_TakeWatcherData(HiAppEvent_Watcher* watcher, uint32_t eventNum, OH_HiAppEvent_OnTake onTake);

/**
 * @brief The interface to add the watcher. The watcher will start receiving app events after it is added.
 *
 * @param watcher The pointer to the HiAppEvent_Watcher instance which receive the event.
 * @return Returns 0 if add watcher is successful, and returns a
 * negative integer if add fail.
 *         {@code 0} Success.
 *         {@code -5} The watcher is nullptr.
 * @since 12
 * @version 1.0
 */
int OH_HiAppEvent_AddWatcher(HiAppEvent_Watcher* watcher);

/**
 * @brief The interface to remove the watcher. The watcher will stop receiving app events after it is removed.
 *
 * @param watcher The pointer to the HiAppEvent_Watcher instance.
 * @return Returns 0 if remove watcher is successful, and returns a
 * negative integer if remove fail.
 *         {@code 0} Success.
 *         {@code -5} The watcher is nullptr.
 *         {@code -6} This interface must be called after OH_HiAppEvent_AddWatcher.
 * @since 12
 * @version 1.0
 */
int OH_HiAppEvent_RemoveWatcher(HiAppEvent_Watcher* watcher);

/**
 * @brief Clear all local saved event data of the application.
 *
 * @since 12
 * @version 1.0
 */
void OH_HiAppEvent_ClearData();

/**
 * @brief Create a HiAppEvent_Processor handler pointer to set the property.
 *
 * @param name The name of the processor.
 * @return Returns a pointer to the HiAppEvent_Processor instance.
 * @since 18
 */
HiAppEvent_Processor* OH_HiAppEvent_CreateProcessor(const char* name);

/**
 * @brief The interface to set route for processor.
 *
 * @param processor The pointer to the HiAppEvent_Processor instance.
 * @param appId The appid of the processor.
 * @param routeInfo The server location information.
 * @return set result.
 *         {@link HIAPPEVENT_SUCCESS} The operation is successful.
 *         {@link HIAPPEVENT_PROCESSOR_IS_NULL} The processor is nullptr.
 *         {@link HIAPPEVENT_INVALID_PARAM_VALUE} Invalid Param value.
 *         {@link HIAPPEVENT_INVALID_UID} Invalid uid.
 *         {@link HIAPPEVENT_INVALID_PARAM_VALUE_LENGTH} Invalid param value length.
 * @since 18
 */
int OH_HiAppEvent_SetReportRoute(HiAppEvent_Processor* processor, const char* appId, const char* routeInfo);

/**
 * @brief The interface to set policy for processor.
 *
 * @param processor The pointer to the HiAppEvent_Processor instance.
 * @param periodReport The time interval to report.
 * @param batchReport The threthold to report.
 * @param onStartReport The strategy to report.
 * @param onBackgroundReport The strategy to report.
 * @return set result.
 *         {@link HIAPPEVENT_SUCCESS} The operation is successful.
 *         {@link HIAPPEVENT_PROCESSOR_IS_NULL} The processor is nullptr.
 *         {@link HIAPPEVENT_INVALID_PARAM_VALUE} Invalid Param value.
 *         {@link HIAPPEVENT_INVALID_UID} Invalid uid.
 * @since 18
 */
int OH_HiAppEvent_SetReportPolicy(HiAppEvent_Processor* processor, int periodReport, int batchReport,
    bool onStartReport, bool onBackgroundReport);

/**
 * @brief The interface to set report event for processor.
 *
 * @param processor The pointer to the HiAppEvent_Processor instance.
 * @param domain The event domain to report.
 * @param name The event name to report.
 * @param isRealTime The strategy to report.
 * @return set result.
 *         {@link HIAPPEVENT_SUCCESS} The operation is successful.
 *         {@link HIAPPEVENT_PROCESSOR_IS_NULL} The processor is nullptr.
 *         {@link HIAPPEVENT_INVALID_PARAM_VALUE} Invalid Param value.
 *         {@link HIAPPEVENT_INVALID_UID} Invalid uid.
 * @since 18
 */
int OH_HiAppEvent_SetReportEvent(HiAppEvent_Processor* processor, const char* domain, const char* name,
    bool isRealTime);

/**
 * @brief The interface to set config for processor.
 *
 * @param processor The pointer to the HiAppEvent_Processor instance.
 * @param key The custom key of processor.
 * @param value The custom value of processor.
 * @return set result.
 *         {@link HIAPPEVENT_SUCCESS} The operation is successful.
 *         {@link HIAPPEVENT_PROCESSOR_IS_NULL} The processor is nullptr.
 *         {@link HIAPPEVENT_INVALID_PARAM_VALUE} Invalid Param value.
 *         {@link HIAPPEVENT_INVALID_UID} Invalid uid.
 *         {@link HIAPPEVENT_INVALID_PARAM_VALUE_LENGTH} Invalid param value length.
 * @since 18
 */
int OH_HiAppEvent_SetCustomConfig(HiAppEvent_Processor* processor, const char* key, const char* value);

/**
 * @brief The interface to set configId for processor.
 *
 * @param processor The pointer to the HiAppEvent_Processor instance.
 * @param configId The configId of processor.
 * @return set result.
 *         {@link HIAPPEVENT_SUCCESS} The operation is successful.
 *         {@link HIAPPEVENT_PROCESSOR_IS_NULL} The processor is nullptr.
 *         {@link HIAPPEVENT_INVALID_PARAM_VALUE} Invalid Param value.
 *         {@link HIAPPEVENT_INVALID_UID} Invalid uid.
 * @since 18
 */
int OH_HiAppEvent_SetConfigId(HiAppEvent_Processor* processor, int configId);

/**
 * @brief The interface to set user info for processor.
 *
 * @param processor The pointer to the HiAppEvent_Processor instance.
 * @param userIdNames The userIdNames of processor.
 * @param size The size of userIdNames array.
 * @return set result.
 *         {@link HIAPPEVENT_SUCCESS} The operation is successful.
 *         {@link HIAPPEVENT_PROCESSOR_IS_NULL} The processor is nullptr.
 *         {@link HIAPPEVENT_INVALID_PARAM_VALUE} Invalid Param value.
 *         {@link HIAPPEVENT_INVALID_UID} Invalid uid.
 *         {@link HIAPPEVENT_INVALID_PARAM_VALUE_LENGTH} Invalid param value length.
 * @since 18
 */
int OH_HiAppEvent_SetReportUserId(HiAppEvent_Processor* processor, const char* const * userIdNames, int size);

/**
 * @brief The interface to set user property for processor.
 *
 * @param processor The pointer to the HiAppEvent_Processor instance.
 * @param userPropertyNames The userPropertyNames of processor.
 * @param size The size of userPropertyNames array.
 * @return set result.
 *         {@link HIAPPEVENT_SUCCESS} The operation is successful.
 *         {@link HIAPPEVENT_PROCESSOR_IS_NULL} The processor is nullptr.
 *         {@link HIAPPEVENT_INVALID_PARAM_VALUE} Invalid Param value.
 *         {@link HIAPPEVENT_INVALID_UID} Invalid uid.
 *         {@link HIAPPEVENT_INVALID_PARAM_VALUE_LENGTH} Invalid param value length.
 * @since 18
 */
int OH_HiAppEvent_SetReportUserProperty(HiAppEvent_Processor* processor, const char* const * userPropertyNames,
    int size);

/**
 * @brief The interface to add processor.
 *
 * @param processor The pointer to the HiAppEvent_Processor instance.
 * @return process id if set is successful.
 *         {@link HIAPPEVENT_PROCESSOR_IS_NULL} The processor is nullptr.
 *         {@link HIAPPEVENT_INVALID_PARAM_VALUE} Invalid Param value.
 *         {@link HIAPPEVENT_OPERATE_FAILED} Name not found or register processor error.
 *         {@link HIAPPEVENT_INVALID_UID} Invalid uid.
 * @since 18
 */
int64_t OH_HiAppEvent_AddProcessor(HiAppEvent_Processor* processor);

/**
 * @brief The interface to destroy processor.
 *
 * @param processor The pointer to the HiAppEvent_Processor instance.
 * @since 18
 */
void OH_HiAppEvent_DestroyProcessor(HiAppEvent_Processor* processor);

/**
 * @brief The interface to remove processor.
 *
 * @param processorId The id of the processor.
 * @return set result.
 *         {@link HIAPPEVENT_SUCCESS} The operation is successful.
 *         {@link HIAPPEVENT_PROCESSOR_NOT_FOUND} Processor not add.
 *         {@link HIAPPEVENT_OPERATE_FAILED} The operation is failed.
 *         {@link HIAPPEVENT_INVALID_UID} Invalid uid.
 * @since 18
 */
int OH_HiAppEvent_RemoveProcessor(int64_t processorId);

/**
 * @brief Create a HiAppEvent_Config handler pointer to set the config.
 *
 * @return Returns a pointer to the HiAppEvent_Config instance.
 * @since 15
 */
HiAppEvent_Config* OH_HiAppEvent_CreateConfig(void);

/**
 * @brief Destroy the specified HiAppEvent_Config handle resource.
 *
 * @param config The pointer to the HiAppEvent_Config instance.
 * @since 15
 */
void OH_HiAppEvent_DestroyConfig(HiAppEvent_Config* config);

/**
 * @brief The interface to set item to the config.
 *
 * @param config The pointer to the HiAppEvent_Config instance.
 * @param itemName The name of config item.
 * @param itemValue The value of config item.
 * @return set result.
 *         {@link HIAPPEVENT_SUCCESS} The operation is successful.
 *         {@link HIAPPEVENT_EVENT_CONFIG_IS_NULL} The event config is null.
 *         {@link HIAPPEVENT_INVALID_PARAM_VALUE} The item is invalid.
 * @since 15
 */
int OH_HiAppEvent_SetConfigItem(HiAppEvent_Config* config, const char* itemName, const char* itemValue);

/**
 * @brief The interface to set the config.
 *
 * @param name The name of the os event.
 * @param config The pointer to the HiAppEvent_Config instance.
 * @return set result.
 *         {@link HIAPPEVENT_SUCCESS} The operation is successful.
 *         {@link HIAPPEVENT_INVALID_PARAM_VALUE} The config is invalid.
 * @since 15
 */
int OH_HiAppEvent_SetEventConfig(const char* name, HiAppEvent_Config* config);
#ifdef __cplusplus
}
#endif
/** @} */
#endif // HIVIEWDFX_HIAPPEVENT_H