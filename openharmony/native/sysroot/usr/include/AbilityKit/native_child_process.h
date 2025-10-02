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

#ifndef OHOS_ABILITY_RUNTIME_C_NATIVE_CHILD_PROCESS_H
#define OHOS_ABILITY_RUNTIME_C_NATIVE_CHILD_PROCESS_H

#include "IPCKit/ipc_cparcel.h"

/**
 * @addtogroup ChildProcess
 * @{
 *
 * @brief Provides the APIs to manage child processes.
 *
 * @syscap SystemCapability.Ability.AbilityRuntime.Core
 * @since 12
 */

/**
 * @file native_child_process.h
 *
 * @brief Declares the APIs used to create a native child process and establish an IPC channel between the parent and
 * child processes.
 *
 * @kit AbilityKit
 * @library libchild_process.so
 * @syscap SystemCapability.Ability.AbilityRuntime.Core
 * @since 12
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates the error codes used by the native child process module.
 * @since 12
 */
typedef enum Ability_NativeChildProcess_ErrCode {
    /**
     * @error Operation successful.
     */
    NCP_NO_ERROR = 0,

    /**
     * @error Invalid parameter.
     */
    NCP_ERR_INVALID_PARAM = 401,

    /**
     * @error Creating a native child process is not supported.
     */
    NCP_ERR_NOT_SUPPORTED = 801,

    /**
     * @error Internal error.
     */
    NCP_ERR_INTERNAL = 16000050,

    /**
     * @error A new child process cannot be created during the startup of another native child process.
     * You can try again after the child process is started.
     */
    NCP_ERR_BUSY = 16010001,

    /**
     * @error Starting the native child process times out.
     */
    NCP_ERR_TIMEOUT = 16010002,

    /**
     * @error Server error.
     */
    NCP_ERR_SERVICE_ERROR = 16010003,

    /**
     * @error The multi-process mode is disabled. A child process cannot be started.
     */
    NCP_ERR_MULTI_PROCESS_DISABLED = 16010004,

    /**
     * @error A process cannot be created in a child process.
     */
    NCP_ERR_ALREADY_IN_CHILD = 16010005,

    /**
     * @error The number of native child processes reaches the maximum.
     */
    NCP_ERR_MAX_CHILD_PROCESSES_REACHED = 16010006,

    /**
     * @error The child process fails to load the dynamic library because the file does not exist
     * or the corresponding method is not implemented or exported.
     */
    NCP_ERR_LIB_LOADING_FAILED = 16010007,

    /**
     * @error The child process fails to call the OnConnect method of the dynamic library.
     * An invalid IPC object pointer may be returned.
     */
    NCP_ERR_CONNECTION_FAILED = 16010008,
} Ability_NativeChildProcess_ErrCode;


/**
 * @brief Defines a callback function for notifying the child process startup result.
 *
 * @param errCode Error code corresponding to the callback function. The following values are available:
 * {@link NCP_NO_ERROR} if the child process is created successfully.\n
 * {@link NCP_ERR_LIB_LOADING_FAILED} if loading the dynamic library file fails or the necessary export function
 * is not implemented in the dynamic library.\n
 * {@link NCP_ERR_CONNECTION_FAILED} if the OnConnect method implemented in the dynamic library does not return
 * a valid IPC stub pointer.\n
 * For details, see {@link Ability_NativeChildProcess_ErrCode}.
 * @param remoteProxy Pointer to the IPC object of the child process. If an exception occurs, the value may be nullptr.
 * The object must be released by calling {@link OH_IPCRemoteProxy_Destory} when it is no longer needed.
 * @see OH_Ability_CreateNativeChildProcess
 * @see OH_IPCRemoteProxy_Destory
 * @since 12
 */
typedef void (*OH_Ability_OnNativeChildProcessStarted)(int errCode, OHIPCRemoteProxy *remoteProxy);

/**
 * @brief Creates a child process, loads the specified dynamic library file, and returns the startup result
 * asynchronously through a callback parameter.
 * The callback notification is an independent thread. When implementing the callback function,
 * pay attention to thread synchronization and do not perform time-consuming operations to avoid long-time blocking.
 *
 * The dynamic library specified must implement and export the following functions:\n
 *   1. OHIPCRemoteStub* NativeChildProcess_OnConnect()\n
 *   2. void NativeChildProcess_MainProc()\n
 *
 * The processing logic sequence is shown in the following pseudocode: \n
 *   Main process: \n
 *     1. OH_Ability_CreateNativeChildProcess(libName, onProcessStartedCallback)\n
 *   Child process: \n
 *     2. dlopen(libName)\n
 *     3. dlsym("NativeChildProcess_OnConnect")\n
 *     4. dlsym("NativeChildProcess_MainProc")\n
 *     5. ipcRemote = NativeChildProcess_OnConnect()\n
 *     6. NativeChildProcess_MainProc()\n
 * Main process: \n
 *     7. onProcessStartedCallback(ipcRemote, errCode)\n
 * Child process: \n
 *     8. The child process exits after the NativeChildProcess_MainProc() function is returned. \n
 *
 * @param libName Name of the dynamic library file loaded in the child process. The value cannot be nullptr.
 * @param onProcessStarted Pointer to the callback function for notifying the child process startup result.
 * The value cannot be nullptr. For details, see {@link OH_Ability_OnNativeChildProcessStarted}.
 * @return Returns {@link NCP_NO_ERROR} if the call is successful, but the actual startup result is notified by the
 * callback function.\n
 * Returns {@link NCP_ERR_INVALID_PARAM} if the dynamic library name or callback function pointer is invalid.\n
 * Returns {@link NCP_ERR_NOT_SUPPORTED} if the device does not support the creation of native child processes.\n
 * Returns {@link NCP_ERR_MULTI_PROCESS_DISABLED} if the multi-process mode is disabled on the device.\n
 * Returns {@link NCP_ERR_ALREADY_IN_CHILD} if it is not allowed to create another child process in the child process.\n
 * Returns {@link NCP_ERR_MAX_CHILD_PROCESSES_REACHED} if the maximum number of native child processes is reached.\n
 * For details, see {@link Ability_NativeChildProcess_ErrCode}.
 * @see OH_Ability_OnNativeChildProcessStarted
 * @since 12
 */
int OH_Ability_CreateNativeChildProcess(const char* libName,
                                        OH_Ability_OnNativeChildProcessStarted onProcessStarted);

/**
 * @brief The info of the file descriptors passed to child process.
 * @since 13
 */
typedef struct NativeChildProcess_Fd {
    /** the key of the file descriptor. */
    char* fdName;

    /** the value of the file descriptor. */
    int32_t fd;

    /** the next pointer of the linked list. */
    struct NativeChildProcess_Fd* next;
} NativeChildProcess_Fd;

/**
 * @brief The list of the info of the file descriptors passed to child process.
 * @since 13
 */
typedef struct NativeChildProcess_FdList {
    /** the head of the list.
     * For details, see {@link NativeChildProcess_Fd}.
     */
    struct NativeChildProcess_Fd* head;
} NativeChildProcess_FdList;

/**
 * @brief Enumerates the isolation modes used by the native child process module.
 * @since 13
 */
typedef enum NativeChildProcess_IsolationMode {
    /**
     * Normal isolation mode, parent process shares the same sandbox or internet with the child process.
     */
    NCP_ISOLATION_MODE_NORMAL = 0,

    /**
     * Isolated mode, parent process does not share the same sandbox or internet with the child process.
     */
    NCP_ISOLATION_MODE_ISOLATED = 1,
} NativeChildProcess_IsolationMode;

/**
 * @brief The options used by the child process.
 * @since 13
 */
typedef struct NativeChildProcess_Options {
    /** the isolation mode used by the child process.
     * For details, see {@link NativeChildProcess_IsolationMode}.
     */
    NativeChildProcess_IsolationMode isolationMode;

    /** reserved field for future extension purposes */
    int64_t reserved;
} NativeChildProcess_Options;

/**
 * @brief The arguments passed to the child process.
 * @since 13
 */
typedef struct NativeChildProcess_Args {
    /** the entry parameter. */
    char* entryParams;

    /** the list of the info of the file descriptors passed to child process.
     * For details, see {@link NativeChildProcess_FdList}.
     */
    struct NativeChildProcess_FdList fdList;
} NativeChildProcess_Args;

/**
 * @brief Starts a child process, loads the specified dynamic library file.
 *
 * The dynamic library specified must implement a function with NativeChildProcess_Args as a
 * pamameter(function name can be customized), and export the function, such as:\n
 *   1. void Main(NativeChildProcess_Args args);
 *
 * The processing logic sequence is shown in the following pseudocode: \n
 *   Main process: \n
 *     1. OH_Ability_StartNativeChildProcess(entryPoint, args, options)\n
 *   Child process: \n
 *     2. dlopen(libName)\n
 *     3. dlsym("Main")\n
 *     4. Main(args)\n
 *     5. The child process exits after the Main(args) function is returned \n
 *
 * @param entry Dynamic library and entry function loaded in child process, such as "libEntry.so:Main".
 * The value cannot be nullptr.
 * @param args The arguments passed to the child process.
 * For details, see {@link NativeChildProcess_Args}.
 * @param options The child process options.
 * For details, see {@link NativeChildProcess_Options}.
 * @param pid The started child process id.
 * @return Returns {@link NCP_NO_ERROR} if the call is successful.\n
 * Returns {@link NCP_ERR_INVALID_PARAM} if the dynamic library name or callback function pointer is invalid.\n
 * Returns {@link NCP_ERR_NOT_SUPPORTED} if the device does not support the creation of native child processes.\n
 * Returns {@link NCP_ERR_ALREADY_IN_CHILD} if it is not allowed to create another child process in the child process.\n
 * Returns {@link NCP_ERR_MAX_CHILD_PROCESSES_REACHED} if the maximum number of native child processes is reached.\n
 * For details, see {@link Ability_NativeChildProcess_ErrCode}.
 * @see OH_Ability_OnNativeChildProcessStarted
 * @since 13
 */
Ability_NativeChildProcess_ErrCode OH_Ability_StartNativeChildProcess(
    const char* entry, NativeChildProcess_Args args,
    NativeChildProcess_Options options, int32_t *pid);

#ifdef __cplusplus
} // extern "C"
#endif

/** @} */
#endif // OHOS_ABILITY_RUNTIME_C_NATIVE_CHILD_PROCESS_H
