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
 * @brief Provides debug code define.
 *
 * For example, you can use these code for check result or parameter of HiDebug function.
 *
 * @since 12
 */

/**
 * @file hidebug_type.h
 *
 * @brief Defines the code of the HiDebug module.
 *
 * @kit PerformanceAnalysisKit
 * @library libohhidebug.so
 * @syscap SystemCapability.HiviewDFX.HiProfiler.HiDebug
 * @since 12
 */

#ifndef HIVIEWDFX_HIDEBUG_TYPE_H
#define HIVIEWDFX_HIDEBUG_TYPE_H

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * @brief Defines error code
 *
 * @since 12
 */
typedef enum HiDebug_ErrorCode {
    /** Success */
    HIDEBUG_SUCCESS = 0,
    /** Invalid argument */
    HIDEBUG_INVALID_ARGUMENT = 401,
    /** Have already capture trace */
    HIDEBUG_TRACE_CAPTURED_ALREADY = 11400102,
    /** No write permission on the file */
    HIDEBUG_NO_PERMISSION = 11400103,
    /** The status of the trace is abnormal */
    HIDEBUG_TRACE_ABNORMAL = 11400104,
    /** No trace running */
    HIDEBUG_NO_TRACE_RUNNING = 11400105,
    /**
     * The pc passed to the symbolic function is invalid
     * @since 20
     */
    HIDEBUG_INVALID_SYMBOLIC_PC_ADDRESS = 11400200,
    /**
     * Current device is not supported.
     * @since 22
     */
    HIDEBUG_NOT_SUPPORTED = 11400300,
    /**
     * Sampling is in progress.
     * @since 22
     */
    HIDEBUG_UNDER_SAMPLING = 11400301,
    /**
     * Resource unavailable
     * @since 22
     */
    HIDEBUG_RESOURCE_UNAVAILABLE = 11400302,
} HiDebug_ErrorCode;

/**
 * @brief Defines application cpu usage of all threads structure type.
 *
 * @since 12
 */
typedef struct HiDebug_ThreadCpuUsage {
    /**
     * Thread id
     */
    uint32_t threadId;
    /**
     * Cpu usage of thread
     */
    double cpuUsage;
    /**
     * Next thread cpu usage
     */
    struct HiDebug_ThreadCpuUsage *next;
} HiDebug_ThreadCpuUsage;

/**
 * @brief Defines pointer of HiDebug_ThreadCpuUsage.
 *
 * @since 12
 */
typedef HiDebug_ThreadCpuUsage* HiDebug_ThreadCpuUsagePtr;

/**
 * @brief Defines system memory information structure type.
 *
 * @since 12
 */
typedef struct HiDebug_SystemMemInfo {
    /**
     * Total system memory size, in kibibytes
     */
    uint32_t totalMem;
    /**
     * System free memory size, in kibibytes
     */
    uint32_t freeMem;
    /**
     * System available memory size, in kibibytes
     */
    uint32_t availableMem;
} HiDebug_SystemMemInfo;

/**
 * @brief Defines application process native memory information structure type.
 *
 * @since 12
 */
typedef struct HiDebug_NativeMemInfo {
    /**
     * Process proportional set size memory, in kibibytes
     */
    uint32_t pss;
    /**
     * Virtual set size memory, in kibibytes
     */
    uint32_t vss;
    /**
     * Resident set size, in kibibytes
     */
    uint32_t rss;
    /**
     * The size of the shared dirty memory, in kibibytes
     */
    uint32_t sharedDirty;
    /**
     * The size of the private dirty memory, in kibibytes
     */
    uint32_t privateDirty;
    /**
     * The size of the shared clean memory, in kibibytes
     */
    uint32_t sharedClean;
    /**
     * The size of the private clean memory, in kibibytes
     */
    uint32_t privateClean;
} HiDebug_NativeMemInfo;

/**
 * @brief Defines application process memory limit structure type.
 *
 * @since 12
 */
typedef struct HiDebug_MemoryLimit {
    /**
     * The limit of the application process's resident set, in kibibytes
     */
    uint64_t rssLimit;
    /**
     * The limit of the application process's virtual memory, in kibibytes
     */
    uint64_t vssLimit;
} HiDebug_MemoryLimit;

/**
 * @brief Enum for trace flag.
 *
 * @since 12
 */
typedef enum HiDebug_TraceFlag {
    /** Only capture main thread trace */
    HIDEBUG_TRACE_FLAG_MAIN_THREAD = 1,
    /** Capture all thread trace */
    HIDEBUG_TRACE_FLAG_ALL_THREADS = 2
} HiDebug_TraceFlag;

/**
 * @brief Defines structure type for MallocDispatch table.
 *
 * @since 20
 */
typedef struct HiDebug_MallocDispatch {
    void* (*malloc)(size_t);
    void* (*calloc)(size_t, size_t);
    void* (*realloc)(void*, size_t);
    void (*free)(void*);
    void* (*mmap) (void*, size_t, int, int, int, off_t);
    int (*munmap) (void*, size_t);
} HiDebug_MallocDispatch;

/**
 * @brief Defines Js stack frame content
 *
 * @since 20
 */
typedef struct HiDebug_JsStackFrame {
    /**
     * The pc relative to the start of current file in /proc/self/maps
     */
    uint64_t relativePc;
 
    /**
     * The line number of the source code from url
     */
    int32_t line;
 
    /**
     * The column number of the source code from url
     */
    int32_t column;
 
    /**
     * The name parsed by pc from /proc/self/maps, maybe NULL
     */
    const char* mapName;
 
    /**
     * The functionName of current frame, maybe NULL
     */
    const char* functionName;
 
    /**
     * The url of current frame, maybe NULL
     */
    const char* url;
 
    /**
     * The packageName of current frame, maybe NULL
     */
    const char* packageName;
} HiDebug_JsStackFrame;

/**
 * @brief Defines native frame content
 *
 * @since 20
 */
typedef struct HiDebug_NativeStackFrame {
    /**
     * The pc relative to the start of current file in /proc/self/maps
     */
    uint64_t relativePc;
 
    /**
     * The pc relative to the start of current function
     */
    uint64_t funcOffset;
 
    /**
     * The name parsed by pc from /proc/self/maps
     */
    const char* mapName;
 
    /**
     * The functionName parsed by relativePc from symbol table in elf, maybe NULL
     */
    const char* functionName;
 
    /**
     * The buildId parsed from .note.gnu.build-id in elf, maybe NULL
     */
    const char* buildId;
 
    /**
     * Reserved, maybe NULL
     */
    const char* reserved;
} HiDebug_NativeStackFrame;

/**
 * @brief Enum for stack frame type.
 *
 * @since 20
 */
typedef enum HiDebug_StackFrameType {
    /** Type of js frame */
    HIDEBUG_STACK_FRAME_TYPE_JS = 1,
    /** Type of native frame */
    HIDEBUG_STACK_FRAME_TYPE_NATIVE = 2,
} HiDebug_StackFrameType;

/**
 * @brief Defines Stack Frame content
 *
 * @since 20
 */
typedef struct HiDebug_StackFrame {
    /**
     * The type of current frame
     */
    HiDebug_StackFrameType type;

    /** frame content. */
    union {
        /** Js stack frame defined in {@link HiDebug_JsStackFrame} */
        struct HiDebug_JsStackFrame js;
        /** Native frame defined in {@link HiDebug_NativeStackFrame} */
        struct HiDebug_NativeStackFrame native;
    } frame;
} HiDebug_StackFrame;

/**
 * @brief To represent a backtrace object
 *
 * @since 20
 */
typedef struct HiDebug_Backtrace_Object__* HiDebug_Backtrace_Object;

/**
 * @brief Defines the graphics memory summary structure type.
 *
 * @since 21
 */
typedef struct HiDebug_GraphicsMemorySummary {
    /**
     * GL memory
     */
    uint32_t gl;

    /**
     * graph memory
     */
    uint32_t graph;
} HiDebug_GraphicsMemorySummary;

/**
 * @brief Defines a struct for the process sampler configuration.
 *
 * @since 22
 */
typedef struct HiDebug_ProcessSamplerConfig {
    /**
     * The threads id
     */
    uint32_t* tids;

    /**
     * The threads num
     */
    uint32_t size;

    /**
     * The frequency of the sampling
     */
    uint32_t frequency;

    /**
     * The duration of the sampling
     */
    uint32_t duration;

    /**
     * The reserved of the sampling
     */
    uint32_t reserved;
} HiDebug_ProcessSamplerConfig;

#ifdef __cplusplus
}
#endif // __cplusplus

/**
 * @brief FFRT tasks.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_FFRT (1ULL << 13)
/**
 * @brief Common library subsystem tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_COMMON_LIBRARY (1ULL << 16)
/**
 * @brief HDF subsystem tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_HDF (1ULL << 18)
/**
 * @brief Net tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_NET (1ULL << 23)
/**
 * @brief NWeb tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_NWEB (1ULL << 24)
/**
 * @brief Distributed audio tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_AUDIO (1ULL << 27)
/**
 * @brief File management tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_FILE_MANAGEMENT (1ULL << 29)
/**
 * @brief OHOS generic tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_OHOS (1ULL << 30)
/**
 * @brief Ability Manager tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_ABILITY_MANAGER (1ULL << 31)
/**
 * @brief Camera module tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_CAMERA (1ULL << 32)
/**
 * @brief Media module tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_MEDIA (1ULL << 33)
/**
 * @brief Image module tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_IMAGE (1ULL << 34)
/**
 * @brief Audio module tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_AUDIO (1ULL << 35)
/**
 * @brief Distributed data manager module tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_DATA (1ULL << 36)
/**
 * @brief Graphics module tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_GRAPHICS (1ULL << 38)
/**
 * @brief ARKUI development framework tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_ARKUI (1ULL << 39)
/**
 * @brief Notification module tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_NOTIFICATION (1ULL << 40)
/**
 * @brief MISC module tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_MISC (1ULL << 41)
/**
 * @brief Multimodal input module tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_MULTIMODAL_INPUT (1ULL << 42)
/**
 * @brief RPC tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_RPC (1ULL << 46)
/**
 * @brief ARK tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_ARK (1ULL << 47)
/**
 * @brief Window manager tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_WINDOW_MANAGER (1ULL << 48)
/**
 * @brief Distributed screen tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_SCREEN (1ULL << 50)
/**
 * @brief Distributed camera tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_CAMERA (1ULL << 51)
/**
 * @brief Distributed hardware framework tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_FRAMEWORK (1ULL << 52)
/**
 * @brief Global resource manager tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_GLOBAL_RESOURCE_MANAGER (1ULL << 53)
/**
 * @brief Distributed hardware device manager tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_DEVICE_MANAGER (1ULL << 54)
/**
 * @brief SA tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_SAMGR (1ULL << 55)
/**
 * @brief Power manager tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_POWER_MANAGER (1ULL << 56)
/**
 * @brief Distributed scheduler tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_SCHEDULER (1ULL << 57)
/**
 * @brief Distributed input tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_INPUT (1ULL << 59)
/**
 * @brief bluetooth tag.
 *
 * @since 12
 */
#define HIDEBUG_TRACE_TAG_BLUETOOTH (1ULL << 60)

/** @} */

#endif // HIVIEWDFX_HIDEBUG_TYPE_H