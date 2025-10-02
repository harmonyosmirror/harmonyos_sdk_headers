/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

/**
 * @addtogroup Preview
 * @{
 *
 * @brief Provides APIs for file preview capability.
 * @since 5.0.3(15)
 */

/**
 * @file open_file_boost.h
 * @kit PreviewKit
 *
 * @brief Declares the APIs used to speed up the opening time of large files.
 *
 * @library libopen_file_boost.so
 * @syscap SystemCapability.PCService.OpenFileBoost
 * @since 5.0.3(15)
 */

#ifndef PREVIEW_OPEN_FILE_BOOST_H
#define PREVIEW_OPEN_FILE_BOOST_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Max length of sandbox buffer.
 * @since 5.0.3(15)
 */
#define MAX_BUFFER_LENGTH 1024

/**
 * @brief Enumerates the error code for file open acceleration.
 * @since 5.0.3(15)
 */
typedef enum {
    /** The call was successful. */
    OPEN_FILE_BOOST_SUCCESS = 0,
    /** Permissions not granted. */
    OPEN_FILE_BOOST_PERMISSION_NOT_GRANTED = 201,
    /** Invalid input parameter. */
    OPEN_FILE_BOOST_INVALID_PARAM = 401,
    /** Internal error. */
    OPEN_FILE_BOOST_INTERNAL_ERROR = 1017200001,
    /** The length of the input buffer is insufficient. */
    OPEN_FILE_BOOST_INSUFFICIENT_BUFFER = 1017200002,
    /** Service unavailable. */
    OPEN_FILE_BOOST_SERVICE_UNAVAILABLE = 1017200003,
    /** Memory is not enough. */
    OPEN_FILE_BOOST_NO_MEMORY = 1017200004
} OpenFileBoost_ErrCode;

/**
 * @brief Enumerates the error codes of the callback function {@link HMS_OpenFileBoost_OnFilePreload}.
 * It is used by the app to return the callback function execution result to the system.
 * @since 5.0.3(15)
 */
typedef enum {
    /** It's returned when the system invokes the callback function of the app successfully. */
    OPEN_FILE_BOOST_CALLBACK_SUCCESS = 0,
    /** It's returned when the system invokes the callback function of the app failure. */
    OPEN_FILE_BOOST_CALLBACK_FAILURE = 1017210000
} OpenFileBoost_CbErrCode;

/**
 * @brief Enumerates the app status, indicating whether the app allows the system to recommend preloaded files.
 * @since 5.0.3(15)
 */
typedef enum {
    /** App allow preload file. */
    OPEN_FILE_BOOST_APP_STATE_ALLOW_PRELOAD = 0,
    /** App reject preload file this time. */
    OPEN_FILE_BOOST_APP_STATE_REJECT_PRELOAD = 1,
    /** App reject preload file forever during this registration. */
    OPEN_FILE_BOOST_APP_STATE_FOREVER_REJECT_PRELOAD = 2
} OpenFileBoost_AppState;

/**
 * @brief Called when the system queries the app status. This function calls back the app before calling the
 * {@link HMS_OpenFileBoost_OnFilePreload} recommendation file. This function is used by the system to query whether
 * files can be recommended to the app. For example, if the app is in the foreground focus or in some special states and
 * is not suitable for preloading files, the app returns a specific enumerated value to reject preloading.
 * @return Returns {@link OPEN_FILE_BOOST_APP_STATE_ALLOW_PRELOAD} if the app allows file recommendation. Then the
 * system calls {@link HMS_OpenFileBoost_OnFilePreload} to preload the recommendation file. If the app rejects the
 * recommendation, {@link OPEN_FILE_BOOST_APP_STATE_REJECT_PRELOAD} is returned. If the app does not want to receive
 * recommendations during the registration, {@link OPEN_FILE_BOOST_APP_STATE_FOREVER_REJECT_PRELOAD} is returned
 * and {@link HMS_OpenFileBoost_UnregisterFilePreload} should be called to cancel the registration as soon as possible.
 * @since 5.0.3(15)
 */
typedef OpenFileBoost_AppState (*HMS_OpenFileBoost_QueryAppState)(void);

/**
 * @brief Called when the system recommends or cancels the recommendation of a preloaded file to an app. The system
 * predicts the files that may be opened by the user and notifies the app through the callback function. In some
 * scenarios, for example, the available memory of the system is insufficient or other files are more likely to be
 * opened by the user, the system instructs the app to cancel the preloading of some files.
 * @param fileInfo: Preloaded file information. The app can invoke {@link HMS_OpenFileBoost_GetFdFromPreloadFileInfo}
 * to obtain the corresponding file descriptor information and then invoke
 * {@link HMS_OpenFileBoost_GetSandboxPathFromPreloadFileInfo} to obtain the corresponding sandbox path information. The
 * app must synchronously parse the preloaded file in the current callback context so that the system can evaluate the
 * resource consumption of the preloaded file.
 * @return Returns {@link OPEN_FILE_BOOST_CALLBACK_SUCCESS} if the function is executed successfully; returns
 * {@link OPEN_FILE_BOOST_CALLBACK_FAILURE} if the function fails to be executed.
 * @since 5.0.3(15)
 */
typedef OpenFileBoost_CbErrCode (*HMS_OpenFileBoost_OnFilePreload)(void* fileInfo);

/**
 * @brief Obtains the file descriptor information.
 * @param fileInfo Information about the preloaded file recommended by the system to the app.
 * @param fd File descriptor information of the preloaded file.
 * @return Returns {@link OPEN_FILE_BOOST_SUCCESS} if the function is executed successfully; returns a specific error
 * code if the function fails to be executed. For details, see {@link OpenFileBoost_ErrCode}.
 * @since 5.0.3(15)
 */
OpenFileBoost_ErrCode HMS_OpenFileBoost_GetFdFromPreloadFileInfo(void* fileInfo, int32_t* fd);

/**
 * @brief Obtains the sandbox path information.
 * @param fileInfo Information about the preloaded file recommended by the system to the app.
 * @param sandboxPath Information about the sandbox path of the pre-loaded file. The app should pass a pointer to a
 * valid memory region, into which the system fills the sandbox path information.
 * @param pathLen Length of the memory area used to fill in the sandbox path.
 * @return Returns {@link OPEN_FILE_BOOST_SUCCESS} if the function is executed successfully; returns
 * {@link OPEN_FILE_BOOST_INSUFFICIENT_BUFFER} if the input memory buffer is too small. For details about other errors,
 * see {@link OpenFileBoost_ErrCode}.
 * @since 5.0.3(15)
 */
OpenFileBoost_ErrCode HMS_OpenFileBoost_GetSandboxPathFromPreloadFileInfo(
    void* fileInfo, char* sandboxPath, int32_t pathLen);

/**
 * @brief Registers the callbacks used for preloading.
 *
 * @param queryAppState Callback used for querying the app status. Before the preloading notification is sent, the
 * callback function is invoked to query whether the preloading file can be recommended.
 * @param filePreload Callback used for file preloading. The system predicts the files that may be opened by users and
 * notifies the invoker through this callback function.
 * @param cancelFilePreload Callback used for canceling file preloading. For example, when the available system memory
 * is insufficient, the system notifies the invoker of canceling file preloading.
 * @return Returns {@link OPEN_FILE_BOOST_SUCCESS} if the function is executed successfully; returns a specific error
 * code if the function fails to be executed. For details, see {@link OpenFileBoost_ErrCode}.
 * @since 5.0.3(15)
 */
OpenFileBoost_ErrCode HMS_OpenFileBoost_RegisterFilePreload(
    HMS_OpenFileBoost_QueryAppState queryAppState,
    HMS_OpenFileBoost_OnFilePreload filePreload,
    HMS_OpenFileBoost_OnFilePreload cancelFilePreload);

/**
 * @brief Unregisters the preloading callback.
 *
 * @return Returns {@link OPEN_FILE_BOOST_SUCCESS} if the function is executed successfully; returns a specific error
 * code if the function fails to be executed. For details, see {@link OpenFileBoost_ErrCode}.
 * @since 5.0.3(15)
 */
OpenFileBoost_ErrCode HMS_OpenFileBoost_UnregisterFilePreload(void);

/**
 * @brief Calls this API to notify the system of the preloading hit when a user opens a preloaded file. This helps
 * improve the prediction accuracy of the preloaded file.
 * @param fd File descriptor information of the hit file.
 * @param sandboxPath Sandbox path of the hit file.
 * @param pathLen Length of the sandbox path.
 * @return Returns {@link OPEN_FILE_BOOST_SUCCESS} if the function is executed successfully; returns a specific error
 * code if the function fails to be executed. For details, see {@link OpenFileBoost_ErrCode}.
 * @since 5.0.3(15)
 */
OpenFileBoost_ErrCode HMS_OpenFileBoost_NotifyPreloadHit(int32_t fd, char* sandboxPath, int32_t pathLen);

#ifdef __cplusplus
}
#endif

#endif // PREVIEW_FILE_OPEN_BOOST_H
/** @} */
