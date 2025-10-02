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

#ifndef OHOS_ABILITY_RUNTIME_C_NATIVE_CHILD_PROCESS_H
#define OHOS_ABILITY_RUNTIME_C_NATIVE_CHILD_PROCESS_H

#include "IPCKit/ipc_cparcel.h"

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

    /**
     * @error The callback does not exist; it may not have been registered or has already been unregistered.
     * @since 20
     */
    NCP_ERR_CALLBACK_NOT_EXIST = 16010009,
} Ability_NativeChildProcess_ErrCode;

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
 * @brief Defines a struct for the child process configs.
 * @since 20
 */
typedef struct Ability_ChildProcessConfigs Ability_ChildProcessConfigs;

/**
 * @brief Creates a new child process configs object.
 * The caller is responsible for destroying the returned object by calling
 * {@link OH_Ability_DestroyChildProcessConfigs} to avoid memory leaks.
 * @return Returns a pointer to the newly created {@link Ability_ChildProcessConfigs} object if successful.
 *         Returns nullptr if an internal error occurs or memory allocation fails.
 * @since 20
 */
Ability_ChildProcessConfigs* OH_Ability_CreateChildProcessConfigs();

/**
 * @brief Destroys a child process configs object and releases associated resources.
 *
 * @param configs Pointer to the child process configs object to be destroyed.
 * After this call, the pointer becomes invalid and must not be used.
 * Passing nullptr is allowed and will be ignored.
 * @return Returns {@link NCP_NO_ERROR} if the operation is successful or if the input is nullptr.
 *         Returns {@link NCP_ERR_INVALID_PARAM} if the input parameters are invalid.
 * @since 20
 */
Ability_NativeChildProcess_ErrCode OH_Ability_DestroyChildProcessConfigs(Ability_ChildProcessConfigs* configs);

/**
 * @brief Sets the isolation mode for the specified child process configs.
 * The isolationMode only takes effect in {@link OH_Ability_StartNativeChildProcessWithConfigs}.
 *
 * @param configs Pointer to the child process configs object. Must not be nullptr.
 * @param isolationMode The isolation mode to set. See {@link NativeChildProcess_IsolationMode} for details.
 * @return Returns {@link NCP_NO_ERROR} if the isolation mode is set successfully.
 *         Returns {@link NCP_ERR_INVALID_PARAM} if the input parameters are invalid.
 * @since 20
 */
Ability_NativeChildProcess_ErrCode OH_Ability_ChildProcessConfigs_SetIsolationMode(
    Ability_ChildProcessConfigs* configs, NativeChildProcess_IsolationMode isolationMode);

/**
 * @brief Sets the process name for the specified child process configs.
 *
 * @param configs Pointer to the child process configs object. Must not be nullptr.
 * @param processName The process name to set.
 * Must be a non-empty string containing only letters, digits, or underscores.
 * Maximum length is 64 characters.
 * The name ultimately assigned to the process is {bundleName}:{processName}.
 * @return Returns {@link NCP_NO_ERROR} if the process name is set successfully.
 *         Returns {@link NCP_ERR_INVALID_PARAM} if the input parameters are invalid.
 * @since 20
 */
Ability_NativeChildProcess_ErrCode OH_Ability_ChildProcessConfigs_SetProcessName(Ability_ChildProcessConfigs* configs,
    const char* processName);

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
 * @brief Creates a child process, loads the specified dynamic library file, and returns the startup result
 * asynchronously through a callback parameter.
 * The callback notification is an independent thread. When implementing the callback function,
 * pay attention to thread synchronization and do not perform time-consuming operations to avoid long-time blocking.
 *
 * The dynamic library specified must implement and export the following functions:
 *   1. OHIPCRemoteStub* NativeChildProcess_OnConnect()
 *   2. void NativeChildProcess_MainProc()
 *
 * The processing logic sequence is shown in the following pseudocode: 
 *   Main process: 
 *     1. OH_Ability_CreateNativeChildProcessWithConfigs(libName, configs, onProcessStartedCallback)
 *   Child process: 
 *     2. dlopen(libName)
 *     3. dlsym("NativeChildProcess_OnConnect")
 *     4. dlsym("NativeChildProcess_MainProc")
 *     5. ipcRemote = NativeChildProcess_OnConnect()
 *     6. NativeChildProcess_MainProc()
 * Main process: 
 *     7. onProcessStartedCallback(ipcRemote, errCode)
 * Child process: 
 *     8. The child process exits after the NativeChildProcess_MainProc() function is returned. 
 *
 * @param libName Name of the dynamic library file loaded in the child process. The value cannot be nullptr.
 * @param configs Pointer to the child process configs object. The value cannot be nullptr.
 * @param onProcessStarted Pointer to the callback function for notifying the child process startup result.
 * The value cannot be nullptr. For details, see {@link OH_Ability_OnNativeChildProcessStarted}.
 * @return Returns {@link NCP_NO_ERROR} if the call is successful, but the actual startup result is notified by the
 * callback function.
 * Returns {@link NCP_ERR_INVALID_PARAM} if the dynamic library name or callback function pointer is invalid.
 * Returns {@link NCP_ERR_NOT_SUPPORTED} if the device does not support the creation of native child processes.
 * Returns {@link NCP_ERR_MULTI_PROCESS_DISABLED} if the multi-process mode is disabled on the device.
 * Returns {@link NCP_ERR_ALREADY_IN_CHILD} if it is not allowed to create another child process in the child process.
 * Returns {@link NCP_ERR_MAX_CHILD_PROCESSES_REACHED} if the maximum number of native child processes is reached.
 * For details, see {@link Ability_NativeChildProcess_ErrCode}.
 * @see OH_Ability_OnNativeChildProcessStarted
 * @since 20
 */
Ability_NativeChildProcess_ErrCode OH_Ability_CreateNativeChildProcessWithConfigs(const char* libName,
    Ability_ChildProcessConfigs* configs, OH_Ability_OnNativeChildProcessStarted onProcessStarted);

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

/**
 * @brief Starts a child process, loads the specified dynamic library file.
 *
 * The dynamic library specified must implement a function with NativeChildProcess_Args as a
 * pamameter(function name can be customized), and export the function, such as:
 *   1. void Main(NativeChildProcess_Args args);
 *
 * The processing logic sequence is shown in the following pseudocode: 
 *   Main process: 
 *     1. OH_Ability_StartNativeChildProcessWithConfigs(entryPoint, args, configs, &pid)
 *   Child process: 
 *     2. dlopen(libName)
 *     3. dlsym("Main")
 *     4. Main(args)
 *     5. The child process exits after the Main(args) function is returned 
 *
 * @param entry Dynamic library and entry function loaded in child process, such as "libEntry.so:Main".
 * The value cannot be nullptr.
 * @param args The arguments passed to the child process.
 * For details, see {@link NativeChildProcess_Args}.
 * @param configs Pointer to the child process configs object. The value cannot be null.
 * For details, see {@link Ability_ChildProcessConfigs}.
 * @param pid The started child process id.
 * @return Returns {@link NCP_NO_ERROR} if the call is successful.
 * Returns {@link NCP_ERR_INVALID_PARAM} if the dynamic library name or callback function pointer is invalid.
 * Returns {@link NCP_ERR_NOT_SUPPORTED} if the device does not support the creation of native child processes.
 * Returns {@link NCP_ERR_ALREADY_IN_CHILD} if it is not allowed to create another child process in the child process.
 * Returns {@link NCP_ERR_MAX_CHILD_PROCESSES_REACHED} if the maximum number of native child processes is reached.
 * For details, see {@link Ability_NativeChildProcess_ErrCode}.
 * @since 20
 */
Ability_NativeChildProcess_ErrCode OH_Ability_StartNativeChildProcessWithConfigs(
    const char* entry, NativeChildProcess_Args args, Ability_ChildProcessConfigs* configs, int32_t *pid);

/**
 * @brief Child process get self NativeChildProcess_Args.
 *
 * @return Returns a pointer to the arguments passed to current child process.\n
 * For details, see {@link NativeChildProcess_Args}.
 * @since 17
 */
NativeChildProcess_Args* OH_Ability_GetCurrentChildProcessArgs();

/**
 * @brief Defines a callback function to handle the exit of a native child process.
 *
 * @param pid The pid of the exited native child process.
 * @param signal The signal of the exited native child process.
 * @since 20
 */
typedef void (*OH_Ability_OnNativeChildProcessExit)(int32_t pid, int32_t signal);

 /**
 * @brief Register a native child process exit callback.
 * Registering the same callback repeatedly will only keep one.
 *
 * @param onProcessExit Pointer to the callback function to handle the exit of a native child process.
 * For details, see {@link OH_Ability_OnNativeChildProcessExit}.
 * @return Returns {@link NCP_NO_ERROR} if the call is successful.
 *         Returns {@link NCP_ERR_INTERNAL} if internal error occurs.
 *         For details, see {@link Ability_NativeChildProcess_ErrCode}.
 * @since 20
 */
Ability_NativeChildProcess_ErrCode OH_Ability_RegisterNativeChildProcessExitCallback(
    OH_Ability_OnNativeChildProcessExit onProcessExit);

 /**
 * @brief Unregister a native child process exit callback.
 *
 * @param onProcessExit Pointer to the callback function to handle the exit of a native child process.
 * For details, see {@link OH_Ability_OnNativeChildProcessExit}.
 * @return Returns {@link NCP_NO_ERROR} if the call is successful.
 *         Returns {@link NCP_ERR_INTERNAL} if internal error occurs.
 *         Returns {@link NCP_ERR_CALLBACK_NOT_EXIST} if the callback is not exist.
 *         For details, see {@link Ability_NativeChildProcess_ErrCode}.
 * @since 20
 */
Ability_NativeChildProcess_ErrCode OH_Ability_UnregisterNativeChildProcessExitCallback(
    OH_Ability_OnNativeChildProcessExit onProcessExit);

#ifdef __cplusplus
} // extern "C"
#endif

/** @} */
#endif // OHOS_ABILITY_RUNTIME_C_NATIVE_CHILD_PROCESS_H
