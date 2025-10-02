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

#ifndef HIVIEWDFX_HICOLLIE_H
#define HIVIEWDFX_HICOLLIE_H

/**
 * @addtogroup HiCollie
 * @{
 *
 * @brief Provides the ability to detect thread stuck or jank of your own business thread
 * pls note it should not be the same as main thread.
 *
 * You can use it in these two scenario:
 * (1)The Business thread stuck for 6 seconds;
 * (2)The Business thread jank for a short time，usually it is less than one second.
 *
 * @since 12
 */

/**
 * @file hicollie.h
 *
 * @brief Defines the interface of the HiCollie module.
 *
 * @library libohhicollie.so
 * @kit PerformanceAnalysisKit
 * @syscap SystemCapability.HiviewDFX.HiCollie
 * @since 12
 */

#include <time.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * @brief Defines error code
 *
 * @since 12
 */
typedef enum HiCollie_ErrorCode {
    /** Success */
    HICOLLIE_SUCCESS = 0,
    /** Invalid argument */
    HICOLLIE_INVALID_ARGUMENT = 401,
    /** Wrong thread context */
    HICOLLIE_WRONG_THREAD_CONTEXT = 29800001,
    /** Remote call failed */
    HICOLLIE_REMOTE_FAILED = 29800002,
} HiCollie_ErrorCode;

/**
 * @brief In stuck scenario, you need to implement this function to detect whether your business thread is stuck.
 * HiCollie will call this function every 3 seconds in an independent thread.
 * A possible implementation of this function is to send a message to your business thread.
 * After the business thread receives it, it will set a flag,
 * by checking the flag you can know whether the business thread is stuck or not.
 *
 * @since 12
 */
typedef void (*OH_HiCollie_Task)(void);

/**
 * @brief In jank scenario, you need to insert two stub functions before and after
 * each event processing of your business thread.
 * By checking these two function executing timestamp, HiCollie will know cosuming time for every event.
 * If it exceeds the preset threshold, a jank event will be reported.
 * This is the stub function inserted before each event processing.
 *
 * @param eventName Business thread processing event name.
 * @since 12
 */
typedef void (*OH_HiCollie_BeginFunc)(const char* eventName);

/**
 * @brief In jank scenario, you need to insert two stub functions before and after
 * each event processing of your business thread.
 * By checking these two function executing timestamp, HiCollie will know cosuming time for every event.
 * If it exceeds the preset threshold, a jank event will be reported.
 * This is the stub function inserted after each event processing.
 *
 * @param eventName Business thread processing event name.
 * @since 12
 */
typedef void (*OH_HiCollie_EndFunc)(const char* eventName);

/**
 * @brief Parameters used for jank detection.
 * Pls note these parameters is not valid for API 12, it is only used for future extention.
 *
 * @since 12
 */
typedef struct HiCollie_DetectionParam {
    /** In jank scenario, it's the theshold exceed which sample stack will be collected. */
    int sampleStackTriggerTime;
    /** extended parameter for future use. */
    int reserved;
} HiCollie_DetectionParam;

/**
 * @brief Set up periodic tasks for stuck detection.
 *
 * @param task Periodic task executed every 3 seconds.
 * @return {@link HICOLLIE_SUCCESS} 0 - Success.
 *         {@link HICOLLIE_WRONG_THREAD_CONTEXT} 29800001 - Wrong thread context.
 *              The function can not be called from main thread.
 * @since 12
 */
HiCollie_ErrorCode OH_HiCollie_Init_StuckDetection(OH_HiCollie_Task task);

/**
 * @brief Set up stub functions for jank detection.
 *
 * @param beginFunc The stub function before each event processing.
 * @param endFunc The stub function after each event processing.
 * @param param The parameter for jank detection setting.
 * @return {@link HICOLLIE_SUCCESS} 0 - Success.
 *         {@link HICOLLIE_INVALID_ARGUMENT} 401 - beginFunc and endFunc
 *              must both have values or be empty, otherwise the value will be returned.
 *         {@link HICOLLIE_WRONG_THREAD_CONTEXT} 29800001 - Wrong thread context.
 *              The function can not be called from main thread.
 * @since 12
 */
HiCollie_ErrorCode OH_HiCollie_Init_JankDetection(OH_HiCollie_BeginFunc* beginFunc,
    OH_HiCollie_EndFunc* endFunc, HiCollie_DetectionParam param);

/**
 * @brief Report a stuck event.
 *
 * @param isSixSecond boolean pointer.
 * The value of the boolean pointer.True if it is stuck for 6 seconds. False if it is stuck for 3 seconds.
 * @return {@link HICOLLIE_SUCCESS} 0 - Success.
 *         {@link HICOLLIE_INVALID_ARGUMENT} 401 - if isSixSecond is nullptr.
 *         {@link HICOLLIE_WRONG_THREAD_CONTEXT} 29800001 - Wrong thread context.
 *              The function can only be called from hicollie internal monitor thread
 *              where {@link OH_HiCollie_Task} run on.
 *         {@link HICOLLIE_REMOTE_FAILED} 29800002 - Remote call failed.
 * @since 12
 */
HiCollie_ErrorCode OH_HiCollie_Report(bool* isSixSecond);

#ifdef __cplusplus
}
#endif
/** @} */

#endif // HIVIEWDFX_HICOLLIE_H
