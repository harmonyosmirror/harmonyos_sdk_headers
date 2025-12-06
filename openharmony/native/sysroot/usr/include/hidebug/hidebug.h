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
 * @addtogroup HiDebug
 * @{
 *
 * @brief Provides debug functions.
 *
 * For example, you can use these functions to obtain cpu uage, memory, heap, capture trace.
 *
 * @since 12
 */

/**
 * @file hidebug.h
 *
 * @brief Defines the debug functions of the HiDebug module.
 *
 * @library libohhidebug.so
 * @kit PerformanceAnalysisKit
 * @syscap SystemCapability.HiviewDFX.HiProfiler.HiDebug
 * @since 12
 */

#ifndef HIVIEWDFX_HIDEBUG_H
#define HIVIEWDFX_HIDEBUG_H

#include <stdint.h>
#include "hidebug_type.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * @brief Obtains the cpu usage of system.
 *
 * @return Returns the cpu usage of system
 *         If the result is zero,The possible reason is that get failed.
 * @since 12
 */
double OH_HiDebug_GetSystemCpuUsage();

/**
 * @brief Obtains the cpu usage percent of a process.
 *
 * @return Returns the cpu usage percent of a process
 *         If the result is zero.The possbile reason is the current application usage rate is too low
 *         or acquisition has failed
 * @since 12
 */
double OH_HiDebug_GetAppCpuUsage();

/**
 * @brief Obtains cpu usage of application's all thread.
 *
 * @return Returns all thread cpu usage. See {@link HiDebug_ThreadCpuUsagePtr}.
 *         If the HiDebug_ThreadCpuUsagePtr is null.
 *         The possible reason is that no thread related data was obtained
 * @since 12
 */
HiDebug_ThreadCpuUsagePtr OH_HiDebug_GetAppThreadCpuUsage();

/**
 * @brief Free cpu usage buffer of application's all thread.
 *
 * @param threadCpuUsage Indicates applicatoin's all thread. See {@link HiDebug_ThreadCpuUsagePtr}
 *        Use the pointer generated through the OH_HiDebug_GetAppThreadCpuUsage().
 * @since 12
 */
void OH_HiDebug_FreeThreadCpuUsage(HiDebug_ThreadCpuUsagePtr *threadCpuUsage);

/**
 * @brief Obtains the system memory size.
 *
 * @param systemMemInfo Indicates the pointer to {@link HiDebug_SystemMemInfo}.
 *        If there is no data in structure after the function.The Possible reason is system error.
 * @since 12
 */
void OH_HiDebug_GetSystemMemInfo(HiDebug_SystemMemInfo *systemMemInfo);

/**
 * @brief Obtains the memory info of application process.
 *
 * @param nativeMemInfo Indicates the pointer to {@link HiDebug_NativeMemInfo}.
 *        If there is no data in structure after the function.The Possible reason is system error.
 * @since 12
 */
void OH_HiDebug_GetAppNativeMemInfo(HiDebug_NativeMemInfo *nativeMemInfo);

/**
 * @brief Obtains the memory info of application process, with optional caching to improve performance. The cached value
 *        remains valid for 5 minutes.
 *
 * @param nativeMemInfo Indicates the pointer to {@link HiDebug_NativeMemInfo}.
 *        If there is no data in structure after the function.The Possible reason is system error.
 * @param forceRefresh Whether to bypass the cache and retrieve fresh data.
 *                     Set to true to force retrieve fresh data and immediate refresh the cached value;
 *                     Set to false to retrieve the cached value when it is valid; otherwise, retrieve
 *                     fresh data and refresh the cache.
 * @since 20
 */
void OH_HiDebug_GetAppNativeMemInfoWithCache(HiDebug_NativeMemInfo *nativeMemInfo, bool forceRefresh);

/**
 * @brief Obtains the memory limit of application process.
 *
 * @param memoryLimit Indicates the pointer to {@link HiDebug_MemoryLimit}
 *        If there is no data in structure after the function.The Possible reason is system error.
 * @since 12
 */
void OH_HiDebug_GetAppMemoryLimit(HiDebug_MemoryLimit *memoryLimit);

/**
 * @brief Start capture application trace.
 *
 * @param flag Trace flag
 * @param tags Tag of trace
 * @param limitSize Max size of trace file, in bytes, the max is 500MB.
 * @param fileName Output trace file name buffer
 * @param length Output trace file name buffer length
 * @return 0 - Success
 *         {@link HIDEBUG_INVALID_ARGUMENT} 401 - if the fileName is null or the length is too short or
 *         limitSize is too small
 *         11400102 - Have already capture trace
 *         11400103 - Have no permission to trace
 *         11400104 - The Possible reason is some error in the system.
 * @since 12
 */
HiDebug_ErrorCode OH_HiDebug_StartAppTraceCapture(HiDebug_TraceFlag flag,
    uint64_t tags, uint32_t limitSize, char* fileName, uint32_t length);

/**
 * @brief Stop capture application trace.
 *
 * @return 0 - Success
 *         11400104 - Maybe no trace is running or some error in the system.
 *         11400105 - Have no trace running.
 * @since 12
 */
HiDebug_ErrorCode OH_HiDebug_StopAppTraceCapture();

/**
 * @brief Get the graphics memory of application.
 *
 * @param value Indicates value of graphics memory, in kibibytes.
 * @return Result code
 *         {@link HIDEBUG_SUCCESS} Get graphics memory success.
 *         {@link HIDEBUG_INVALID_ARGUMENT} Invalid argument，value is null.
 *         {@link HIDEBUG_TRACE_ABNORMAL} Failed to get the application memory due to a remote exception.
 * @since 14
 */
HiDebug_ErrorCode OH_HiDebug_GetGraphicsMemory(uint32_t *value);

/**
 * @brief Replace MallocDispatch table with developer-defined memory allocation functions.
 *
 * @param dispatchTable A pointer to the MallocDispatch table.
 * @return Result code
 *         {@link HIDEBUG_SUCCESS} The MallocDispatch table is successfully overriden.
 *         {@link HIDEBUG_INVALID_ARGUMENT} Invalid argument, dispatchTable is a null pointer.
 * @since 20
 */
HiDebug_ErrorCode OH_HiDebug_SetMallocDispatchTable(struct HiDebug_MallocDispatch *dispatchTable);

/**
 * @brief Obtain current MallocDispatch table.
 *
 * @return Returns a pointer to MallocDispatch table on success, or NULL on failure.
 *
 * @since 20
 */
HiDebug_MallocDispatch* OH_HiDebug_GetDefaultMallocDispatchTable(void);

/**
 * @brief Restore original MallocDispatch table.
 *
 * @since 20
 */
void OH_HiDebug_RestoreMallocDispatchTable(void);

/**
 * @brief Get backtrace frames start from the given frame pointer and the function is signal-safe.
 *
 * @param object The backtrace object create by {@link OH_HiDebug_CreateBacktraceObject}.
 * @param startFp The entry frame pointer.
 * @param pcArray The array to place program counter values.
 * @param size The size of the array to place program counter values.
 * @return The number of stack frames written to array.
 * @since 20
 */
int OH_HiDebug_BacktraceFromFp(HiDebug_Backtrace_Object object, void* startFp, void** pcArray, int size);

/**
 * @brief Defines the callback of the {@link OH_HiDebug_SymbolicAddress} function.
 *
 * @param pc The program counter pass to {@link OH_HiDebug_SymbolicAddress}.
 * @param arg The arg pass to {@link OH_HiDebug_SymbolicAddress}.
 * @param frame The parsed frame content, the content is invalid after return of {@link OH_HiDebug_SymbolicAddress}.
 * @since 20
 */
typedef void (*OH_HiDebug_SymbolicAddressCallback)(void* pc, void* arg, const HiDebug_StackFrame* frame);

/**
 * @brief Get detailed symbol info by given pc and the function is not signal-safe.
 *
 * @param object The backtrace object create by {@link OH_HiDebug_CreateBacktraceObject}.
 * @param pc The program counter return by {@link OH_HiDebug_BacktraceFromFp}.
 * @param arg The arg will be pass to callback.
 * @param callback The function to pass parsed frame to caller.
 * @return Result code
 *         {@link HIDEBUG_SUCCESS} Get detailed frame info successfully and the callback is invoked.
 *         {@link HIDEBUG_INVALID_ARGUMENT} Invalid argument.
 *         {@link HIDEBUG_INVALID_SYMBOLIC_PC_ADDRESS} Could not find symbol info by given pc.
 * @since 20
 */
HiDebug_ErrorCode OH_HiDebug_SymbolicAddress(HiDebug_Backtrace_Object object, void* pc, void* arg,
    OH_HiDebug_SymbolicAddressCallback callback);

/**
 * @brief Create a backtrace object for further using and the function is not signal-safe.
 *
 * @return BacktraceObject if Success or NULL if is not supported on current arch
 * @since 20
 */
HiDebug_Backtrace_Object OH_HiDebug_CreateBacktraceObject(void);

/**
 * @brief Destroy a backtrace object and the function is not signal-safe.
 *
 * @param object The object to be destroyed.
 * @since 20
 */
void OH_HiDebug_DestroyBacktraceObject(HiDebug_Backtrace_Object object);

/**
 * @brief Obtain the graphics memory summary of application.
 *
 * @param interval If the cache of graphics memory is longer than interval (unit: second), the latest
 *                 graphics memory data will be obtained. The interval value range is 2 seconds to
 *                 3600 seconds, If interval is an invalid value, the default value is 300 seconds.
 * @param summary Indicates value of graphics memory summary, in kibibytes.
 * @return Result code
 *         {@link HIDEBUG_SUCCESS} Get graphics memory success.
 *         {@link HIDEBUG_INVALID_ARGUMENT} Invalid argument, value is null.
 *         {@link HIDEBUG_TRACE_ABNORMAL} Failed to get the application memory due to a remote exception.
 * @since 21
 */
HiDebug_ErrorCode OH_HiDebug_GetGraphicsMemorySummary(uint32_t interval, HiDebug_GraphicsMemorySummary *summary);

#ifdef __cplusplus
}
#endif // __cplusplus
/** @} */

#endif // HIVIEWDFX_HIDEBUG_H