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
#include "info/application_target_sdk_version.h"
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
double OH_HiDebug_GetSystemCpuUsage() __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the cpu usage percent of a process.
 *
 * @return Returns the cpu usage percent of a process
 *         If the result is zero.The possbile reason is the current application usage rate is too low
 *         or acquisition has failed
 * @since 12
 */
double OH_HiDebug_GetAppCpuUsage() __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains cpu usage of application's all thread.
 *
 * @return Returns all thread cpu usage. See {@link HiDebug_ThreadCpuUsagePtr}.
 *         If the HiDebug_ThreadCpuUsagePtr is null.
 *         The possible reason is that no thread related data was obtained
 * @since 12
 */
HiDebug_ThreadCpuUsagePtr OH_HiDebug_GetAppThreadCpuUsage() __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Free cpu usage buffer of application's all thread.
 *
 * @param threadCpuUsage Indicates applicatoin's all thread. See {@link HiDebug_ThreadCpuUsagePtr}
 *        Use the pointer generated through the OH_HiDebug_GetAppThreadCpuUsage().
 * @since 12
 */
void OH_HiDebug_FreeThreadCpuUsage(HiDebug_ThreadCpuUsagePtr *threadCpuUsage)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the system memory size.
 *
 * @param systemMemInfo Indicates the pointer to {@link HiDebug_SystemMemInfo}.
 *        If there is no data in structure after the function.The Possible reason is system error.
 * @since 12
 */
void OH_HiDebug_GetSystemMemInfo(HiDebug_SystemMemInfo *systemMemInfo)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the memory info of application process.
 *
 * @param nativeMemInfo Indicates the pointer to {@link HiDebug_NativeMemInfo}.
 *        If there is no data in structure after the function.The Possible reason is system error.
 * @since 12
 */
void OH_HiDebug_GetAppNativeMemInfo(HiDebug_NativeMemInfo *nativeMemInfo)
__attribute__((__availability__(ohos, introduced=12.0.0)));

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
void OH_HiDebug_GetAppNativeMemInfoWithCache(HiDebug_NativeMemInfo *nativeMemInfo, bool forceRefresh)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Obtains the memory limit of application process.
 *
 * @param memoryLimit Indicates the pointer to {@link HiDebug_MemoryLimit}
 *        If there is no data in structure after the function.The Possible reason is system error.
 * @since 12
 */
void OH_HiDebug_GetAppMemoryLimit(HiDebug_MemoryLimit *memoryLimit)
__attribute__((__availability__(ohos, introduced=12.0.0)));

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
    uint64_t tags, uint32_t limitSize, char* fileName, uint32_t length)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Stop capture application trace.
 *
 * @return 0 - Success
 *         11400104 - Maybe no trace is running or some error in the system.
 *         11400105 - Have no trace running.
 * @since 12
 */
HiDebug_ErrorCode OH_HiDebug_StopAppTraceCapture() __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Requests application trace capture with specified configuration.
 *
 * @param config Indicates the trace request configuration. See {@link OH_HiDebug_RequestTraceConfig}.
 * @param callback Indicates the callback for the trace request. See {@link OH_HiDebug_RequestTraceCallback}.
 * @return Result code.
 *         {@link HIDEBUG_SUCCESS} The operation is successful.
 *         {@link HIDEBUG_TRACE_ABNORMAL} Remote service exception.
 *         {@link OH_HIDEBUG_TRACE_STORAGE_LIMIT} Trace storage limit reached.
 *         {@link HIDEBUG_RESOURCE_UNAVAILABLE} Resource unavailable.
 * @since 24
 */
HiDebug_ErrorCode OH_HiDebug_RequestTrace(OH_HiDebug_RequestTraceConfig *config,
    OH_HiDebug_RequestTraceCallback callback)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

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
HiDebug_ErrorCode OH_HiDebug_GetGraphicsMemory(uint32_t *value)
__attribute__((__availability__(ohos, introduced=14.0.0)));

/**
 * @brief Replace MallocDispatch table with developer-defined memory allocation functions.
 *
 * @param dispatchTable A pointer to the MallocDispatch table.
 * @return Result code
 *         {@link HIDEBUG_SUCCESS} The MallocDispatch table is successfully overriden.
 *         {@link HIDEBUG_INVALID_ARGUMENT} Invalid argument, dispatchTable is a null pointer.
 * @since 20
 */
HiDebug_ErrorCode OH_HiDebug_SetMallocDispatchTable(struct HiDebug_MallocDispatch *dispatchTable)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Obtain current MallocDispatch table.
 *
 * @return Returns a pointer to MallocDispatch table on success, or NULL on failure.
 *
 * @since 20
 */
HiDebug_MallocDispatch* OH_HiDebug_GetDefaultMallocDispatchTable(void)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Restore original MallocDispatch table.
 *
 * @since 20
 */
void OH_HiDebug_RestoreMallocDispatchTable(void) __attribute__((__availability__(ohos, introduced=20.0.0)));

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
int OH_HiDebug_BacktraceFromFp(HiDebug_Backtrace_Object object, void* startFp, void** pcArray, int size)
__attribute__((__availability__(ohos, introduced=20.0.0)));

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
    OH_HiDebug_SymbolicAddressCallback callback)
    __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Create a backtrace object for further using and the function is not signal-safe.
 *
 * @return BacktraceObject if Success or NULL if is not supported on current arch
 * @since 20
 */
HiDebug_Backtrace_Object OH_HiDebug_CreateBacktraceObject(void)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Destroy a backtrace object and the function is not signal-safe.
 *
 * @param object The object to be destroyed.
 * @since 20
 */
void OH_HiDebug_DestroyBacktraceObject(HiDebug_Backtrace_Object object)
__attribute__((__availability__(ohos, introduced=20.0.0)));

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
HiDebug_ErrorCode OH_HiDebug_GetGraphicsMemorySummary(uint32_t interval, HiDebug_GraphicsMemorySummary *summary)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Defines the callback of the lightweight performance stack.
 *
 * @param stacks Stacks.
 * @since 22
 */
typedef void (*OH_HiDebug_ThreadLiteSamplingCallback)(const char* stacks);

/**
 * Requests stack sampling for the current process.
 * The calling thread is blocked until the sampling is complete.
 *
 * @param config Sampling configuration parameters.
 * @param stacksCallback Callback of the sampling stack. This function is called after the sampling to pass
 * the sampling stack information.
 * @return Result code.
 *         {@link HIDEBUG_SUCCESS } The operation is successful.
 *         {@link HIDEBUG_INVALID_ARGUMENT } Invalid argument.
 *         {@link HIDEBUG_NOT_SUPPORTED } The device does not support sampling.
 *         {@link HIDEBUG_UNDER_SAMPLING } The sampling is in progress.
 *         {@link HIDEBUG_RESOURCE_UNAVAILABLE } Resource unavailable.
 * @since 22
 */
HiDebug_ErrorCode OH_HiDebug_RequestThreadLiteSampling(
    HiDebug_ProcessSamplerConfig* config, OH_HiDebug_ThreadLiteSamplingCallback stacksCallback)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Attaches diagnostic information to the current crash context.
 *
 * @param type Type of diagnostic data.
 * @param addr Point to the data buffer(must remain valid until crash).
 * @return Handle to the previously set crash object(0 if none).
 * @since 23
 */
uint64_t OH_HiDebug_SetCrashObj(HiDebug_CrashObjType type, void* addr)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Detaches diagnostic information from the current crash context.
 *
 * @param crashObj Handle returned by OH_HiDebug_SetCrashObj.
 * @since 23
 */
void OH_HiDebug_ResetCrashObj(uint64_t crashObj) __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Starts Resource Profiler for the current process asynchronously.
 * The callback is invoked only after profiling stops, including auto-stop caused by the maximum duration.
 * When profiling output is available, the callback carries the output file path. If profiling stops without
 * producing output, the callback is invoked with a NULL file path.
 *
 * @param type Type of resource to be profiled.
 * @param config Configuration parameters for the profiler.
 * @param callback Callback to receive the profiling result. See {@link OH_HiDebug_ProfilingCallback}.
 * @return Result code
 *         {@link HIDEBUG_RES_PROF_SUCCESS} Resource profiler started successfully.
 *         {@link HIDEBUG_RES_PROF_INVALID_ARG} Invalid resource profiler argument.
 *         {@link HIDEBUG_RES_PROF_INVALID_MAX_DURATION} Invalid maximum duration.
 *         {@link HIDEBUG_RES_PROF_INVALID_FILTER_SIZE} Invalid filter size.
 *         {@link HIDEBUG_RES_PROF_INVALID_MAX_STACK_DEPTH} Invalid maximum stack depth.
 *         {@link HIDEBUG_RES_PROF_INVALID_STATISTICS_INTERVAL} Invalid statistics interval.
 *         {@link HIDEBUG_RES_PROF_INVALID_SAMPLE_INTERVAL} Invalid sample interval.
 *         {@link HIDEBUG_RES_PROF_INVALID_RESOURCE_TYPE} Invalid resource type.
 *         {@link HIDEBUG_RES_PROF_PERMISSION_DENIED} Resource profiler permission denied.
 *         {@link HIDEBUG_RES_PROF_ALREADY_STARTED} Resource profiler already started.
 *         {@link HIDEBUG_RES_PROF_PROCESS_OVERLIMIT} Resource profiler process count exceeds the limit.
 *         {@link HIDEBUG_RES_PROF_CONFLICT} Resource profiler conflicts with CLI tools or system profiling tasks.
 *         {@link HIDEBUG_RES_PROF_DAILY_QUOTA_EXCEEDED} Daily quota exceeded during resource profiling.
 *         {@link HIDEBUG_RES_PROF_CPU_OVERLOADED} System is experiencing high CPU utilization.
 *         {@link HIDEBUG_RES_PROF_MEM_PRESSURE_CRITICAL} Insufficient available memory.
 *         {@link HIDEBUG_RES_PROF_STORAGE_PRESSURE_CRITICAL} Insufficient available storage space.
 *         {@link HIDEBUG_RES_PROF_FAILURE} Failed to start the resource profiler.
 * @since 24
 */
HiDebug_ErrorCode OH_HiDebug_StartProfiler(OH_HiDebug_ResourceType type, OH_HiDebug_ResProfilerConfig* config,
    OH_HiDebug_ProfilingCallback callback)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Stops resource profiler for the current process. This API can be called after the
 * {@link OH_HiDebug_StartProfiler} API and the call duration must be within the maximum duration.
 *
 * @return Result code
 *         {@link HIDEBUG_RES_PROF_SUCCESS} Resource profiler stopped successfully.
 *         {@link HIDEBUG_RES_PROF_NOT_STARTED} Resource profiler not started.
 *         {@link HIDEBUG_RES_PROF_FAILURE} Failed to stop the resource profiler.
 * @since 24
 */
HiDebug_ErrorCode OH_HiDebug_StopProfiler(void) __attribute__((__availability__(ohos, introduced=24.0.0)));
#ifdef __cplusplus
}
#endif // __cplusplus

/** @} */
#endif // HIVIEWDFX_HIDEBUG_H