/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

/**
 * @addtogroup ModuleInstall
 * @{
 *
 * @brief Provides APIs related to module install of AppGalleryKit.
 *
 * Covers module install, including related API.
 *
 *
 * @since 5.0.3(15)
 */

/**
 * @file module_install.h
 * @kit AppGalleryKit
 *
 * @brief module install
 * This class is mainly for module install;
 * @library libhmsmoduleinstall.so
 * @syscap SystemCapability.AppGalleryService.Distribution.OnDemandInstall
 * @since 5.0.3(15)
 */

#ifndef APPGALLERY_KIT_MODULE_INSTALL_H
#define APPGALLERY_KIT_MODULE_INSTALL_H

#include <stdlib.h>
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines module install error code.
 * @since 5.0.3(15)
 */
typedef enum ModuleInstall_ErrCode {
    /* * @error Execution successful. */
    E_NO_ERROR = 0,
    /* * @error Invalid input parameter. */
    E_PARAMS = 401,
    /* * @error Failed to invoke the BMS. */
    E_QUERY_MODULE = 1006500001,
    /* * @error The interface is called repeatedly with the same input. */
    E_REPEATED_CALL = 1006500002,
    /* * @error SA connection failed. */
    E_CONNECT_SA = 1006500004,
    /* * @error The interface is not used together with "HMS_Module_Install_On". */
    E_OFF_WITHOUT_ON = 1006500006,
    /* * @error The specified service extension connect failed. */
    E_CONNECT_SERVICE_EXTENSION = 1006500007,
    /* * @error Write param into container failed. */
    E_WRITE_PARAM = 1006500008,
    /* * @error Request to service error. */
    E_REQUEST_SERVER = 1006500009,
    /* * @error Response from service cannot be recognized. */
    E_RESPONSE_INVALID = 1006500010,
    /* * @error System inner error. */
    E_INNER_ERROR = 1006500011,
} ModuleInstall_ErrCode;

/**
 * @brief Defines install status.
 * @since 5.0.3(15)
 */
typedef enum ModuleInstall_InstallStatus {
    /* * Module has been installed. */
    INSTALLED = 0,
    /* * Module has not been installed. */
    NOT_INSTALLED = 1,
} ModuleInstall_InstallStatus;

/**
 * @brief Defines module install request code.
 * @since 5.0.3(15)
 */
typedef enum ModuleInstall_RequestCode {
    /* * Module already exists. */
    MODULE_ALREADY_EXISTS = -8,
    /* * Module anavailable. */
    MODULE_UNAVAILABLE = -7,
    /* * Invalid request. */
    INVALID_REQUEST = -6,
    /* * Network error. */
    NETWORK_ERROR = -5,
    /* * Invoke verfication failed. */
    INVOKER_VERIFICATION_FAILED = -4,
    /* * Foregound required. */
    FOREGROUND_REQUIRED = -3,
    /* * Active session limit exceeded. */
    ACTIVE_SESSION_LIMIT_EXCEEDED = -2,
    /* * Failure. */
    FAILURE = -1,
    /* * Success. */
    SUCCESS = 0,
    /* * Download wait wifi. */
    DOWNLOAD_WAIT_WIFI = 1,
} ModuleInstall_RequestCode;

/**
 * @brief Defines module install task status.
 * @since 5.0.3(15)
 */
typedef enum ModuleInstall_TaskStatus {
    /* * Create task failed. */
    CREATE_TASK_FAILED = -4,
    /* * Higher version installed. */
    HIGHER_VERSION_INSTALLED = -3,
    /* * Higher version installed. */
    TASK_ALREADY_EXISTS = -2,
    /* * Task unfound. */
    TASK_UNFOUND = -1,
    /* * Task created. */
    TASK_CREATED = 0,
    /* * Task Downloading. */
    DOWNLOADING = 1,
    /* * Download paused. */
    DOWNLOAD_PAUSED = 2,
    /* * Download waiting. */
    DOWNLOAD_WAITING = 3,
    /* * Download successful. */
    DOWNLOAD_SUCCESSFUL = 4,
    /* * Download failed. */
    DOWNLOAD_FAILED = 5,
    /* * Download wait foe wifi. */
    DOWNLOAD_WAIT_FOR_WIFI = 6,
    /* * Install waiting. */
    INSTALL_WAITING = 20,
    /* * Installing. */
    INSTALLING = 21,
    /* * Install successful. */
    INSTALL_SUCCESSFUL = 22,
    /* * Install failed. */
    INSTALL_FAILED = 23,
} ModuleInstall_TaskStatus;

/**
 * @brief the information of the installedModule
 * @since 5.0.3(15)
 */
typedef struct ModuleInstall_InstalledModule ModuleInstall_InstalledModule;

/**
 * @brief the information of the ModuleInstallResult
 * @since 5.0.3(15)
 */
typedef struct ModuleInstall_FetchModulesResult ModuleInstall_FetchModulesResult;

/**
 * @brief the information of the StatusCallback
 * @since 5.0.3(15)
 */
typedef struct ModuleInstall_StatusCallback ModuleInstall_StatusCallback;

/**
 * @brief Defines the OnStatusCallback
 * @since 5.0.3(15)
 */
typedef void (*ModuleInstall_OnStatusCallback)(char *bundleName, char *eventInfo);

/**
 * @brief HMS_ModuleInstall_GetInstalledModule.
 *
 * @param moduleName moduleName.
 * @param length The length of moduleName.
 * @param installedModule installedModule.
 * @return Returns the status code of the execution.
 * {@link E_PARAMS}  401 - Invalid input parameter.
 * {@link E_QUERY_MODULE} 1006500001 - Failed to invoke the BMS.
 * @syscap SystemCapability.AppGalleryService.Distribution.OnDemandInstall
 * @since 5.0.3(15)
 */
ModuleInstall_ErrCode HMS_ModuleInstall_GetInstalledModule(const char *moduleName, unsigned int length,
    ModuleInstall_InstalledModule **installedModule);

/**
 * @brief Get module name from installedModule.
 *
 * @param installedModule installedModule.
 * @return Returns the module name of module.
 * @since 5.0.3(15)
 */
char *HMS_ModuleInstall_GetInstalledModuleName(const ModuleInstall_InstalledModule *installedModule);

/**
 * @brief Get module type from installedModule.
 *
 * @param installedModule installedModule.
 * @return Returns the module type of module.
 * @since 5.0.3(15)
 */
int HMS_ModuleInstall_GetInstalledModuleType(const ModuleInstall_InstalledModule *installedModule);

/**
 * @brief Get module install status from installedModule.
 *
 * @param installedModule installedModule.
 * @return Returns the install status of module.
 * @since 5.0.3(15)
 */
ModuleInstall_InstallStatus HMS_ModuleInstall_GetModuleInstallStatus(
    const ModuleInstall_InstalledModule *installedModule);

/**
 * @brief HMS_ModuleInstall_FetchModules.
 *
 * @param bundleName bundleName.
 * @param length The length of bundleName.
 * @param moduleNames ModuleName array.
 * @param moduleNamesLength The length of moduleNames array.
 * @param fetchModulesResult fetchModulesResult.
 * @return Returns the status code of the execution.
 * {@link E_PARAMS}  401 - Invalid input parameter.
 * {@link E_CONNECT_SA} 1006500004 - SA connection failed.
 * {@link E_CONNECT_SERVICE_EXTENSION} 1006500007 - The specified service extension connect failed.
 * {@link E_WRITE_PARAM} 1006500008 - Write param into container failed.
 * {@link E_REQUEST_SERVER} 1006500009 - Request to service error.
 * {@link E_RESPONSE_INVALID} 1006500010 - Response from service cannot be recognized.
 * {@link E_INNER_ERROR} 1006500011 - System inner error.
 * @syscap SystemCapability.AppGalleryService.Distribution.OnDemandInstall
 * @since 5.0.3(15)
 */
ModuleInstall_ErrCode HMS_ModuleInstall_FetchModules(const char *bundleName, unsigned int length, char **moduleNames,
    unsigned int moduleNamesLength, ModuleInstall_FetchModulesResult **fetchModulesResult);

/**
 * @brief Get request code from fetchModulesResult.
 *
 * @param fetchModulesResult Indicates the result of fetch modules.
 * @return Returns the request code of fetch modules.
 * @since 5.0.3(15)
 */
ModuleInstall_RequestCode HMS_ModuleInstall_GetFetchModulesRequestCode(
    const ModuleInstall_FetchModulesResult *fetchModulesResult);

/**
 * @brief Get task status from fetchModulesResult.
 *
 * @param fetchModulesResult Indicates the result of fetch modules.
 * @return Returns the task status of fetch modules.
 * @since 5.0.3(15)
 */
ModuleInstall_TaskStatus HMS_ModuleInstall_GetFetchModulesTaskStatus(
    const ModuleInstall_FetchModulesResult *fetchModulesResult);

/**
 * @brief Get task id from fetchModulesResult.
 *
 * @param fetchModulesResult Indicates the result of fetch modules.
 * @return Returns task id of fetch modules.
 * @since 5.0.3(15)
 */
char *HMS_ModuleInstall_GetFetchModulesTaskId(const ModuleInstall_FetchModulesResult *fetchModulesResult);

/**
 * @brief Get desc from fetchModulesResult.
 *
 * @param fetchModulesResult Indicates the result of fetch modules.
 * @return Returns desc of fetch modules.
 * @since 5.0.3(15)
 */
char *HMS_ModuleInstall_GetFetchModulesDesc(const ModuleInstall_FetchModulesResult *fetchModulesResult);

/**
 * @brief Get modules from fetchModulesResult.
 *
 * @param fetchModulesResult Indicates the result of fetch modules.
 * @return Returns modules of fetch modules.
 * @since 5.0.3(15)
 */
char *HMS_ModuleInstall_GetFetchModules(const ModuleInstall_FetchModulesResult *fetchModulesResult);

/**
 * @brief Get total size from fetchModulesResult.
 *
 * @param fetchModulesResult Indicates the result of fetch modules.
 * @return Returns total size of fetch modules.
 * @since 5.0.3(15)
 */
int HMS_ModuleInstall_GetFetchModulesTotalSize(const ModuleInstall_FetchModulesResult *fetchModulesResult);

/**
 * @brief Get downloaded size from fetchModulesResult.
 *
 * @param fetchModulesResult Indicates the result of fetch modules.
 * @return Returns downloaded size of fetch modules.
 * @since 5.0.3(15)
 */
int HMS_ModuleInstall_GetFetchModulesDownloadedSize(const ModuleInstall_FetchModulesResult *fetchModulesResult);

/**
 * @brief HMS_ModuleInstall_CancelTask.
 *
 * @param taskId taskId.
 * @param length The length of taskId.
 * @param cancelResult Cancel result of cancelTak.
 * @return Returns the status code of the execution.
 * {@link E_PARAMS}  401 - Invalid input parameter.
 * {@link E_CONNECT_SERVICE_EXTENSION} 1006500007 - The specified service extension connect failed.
 * {@link E_WRITE_PARAM} 1006500008 - Write param into container failed.
 * {@link E_REQUEST_SERVER} 1006500009 - Request to service error.
 * {@link E_RESPONSE_INVALID} 1006500010 - Response from service cannot be recognized.
 * @syscap SystemCapability.AppGalleryService.Distribution.OnDemandInstall
 * @since 5.0.3(15)
 */
ModuleInstall_ErrCode HMS_ModuleInstall_CancelTask(const char *taskId, unsigned int length, unsigned int cancelResult);

/**
 * @brief HMS_ModuleInstall_ShowCellularDataConfirmation.
 *
 * @param taskId taskId.
 * @param length The length of taskId.
 * @param showResult Result of show cellular data confirmation.
 * @return Returns the status code of the execution.
 * {@link E_PARAMS}  401 - Invalid input parameter.
 * {@link E_CONNECT_SERVICE_EXTENSION} 1006500007 - The specified service extension connect failed.
 * {@link E_WRITE_PARAM} 1006500008 - Write param into container failed.
 * {@link E_REQUEST_SERVER} 1006500009 - Request to service error.
 * {@link E_RESPONSE_INVALID} 1006500010 - Response from service cannot be recognized.
 * @syscap SystemCapability.AppGalleryService.Distribution.OnDemandInstall
 * @since 5.0.3(15)
 */
ModuleInstall_ErrCode HMS_ModuleInstall_ShowCellularDataConfirmation(const char *taskId, unsigned int length,
    unsigned int showResult);

/**
 * @brief Create StatusCallback
 *
 * @param onStatusCallback The callback function.
 * @return Returns StatusCallback.
 * @since 5.0.3(15)
 */
ModuleInstall_StatusCallback *HMS_ModuleInstall_CreateStatusCallback(ModuleInstall_OnStatusCallback *onStatusCallback);

/**
 * @brief HMS_ModuleInstall_On.
 *
 * @param bundleName bundleName.
 * @param length The length of bundleName.
 * @param appIndex The appIndex of bundleName.
 * @param period The period of on.
 * @param callback The callback of on.
 * @return Returns the status code of the execution.
 * {@link E_PARAMS}  401 - Invalid input parameter.
 * {@link E_REPEATED_CALL} 1006500002 - The interface is called repeatedly with the same input.
 * {@link E_CONNECT_SA} 1006500004 - SA connection failed.
 * @syscap SystemCapability.AppGalleryService.Distribution.OnDemandInstall
 * @since 5.0.3(15)
 */
ModuleInstall_ErrCode HMS_ModuleInstall_On(const char *bundleName, unsigned int length, unsigned int appIndex,
    unsigned int period, ModuleInstall_StatusCallback **callback);

/**
 * @brief Release statusCallback.
 *
 * @param statusCallback statusCallback.
 * @since 5.0.3(15)
 */
void HMS_ModuleInstall_ReleaseStatusCallback(ModuleInstall_StatusCallback *statusCallback);

/**
 * @brief HMS_ModuleInstall_Off.
 *
 * @param bundleName bundleName.
 * @param length The length of bundleName.
 * @param appIndex The appIndex of bundleName.
 * @return Returns the status code of the execution.
 * {@link E_PARAMS}  401 - Invalid input parameter.
 * {@link E_CONNECT_SA} 1006500004 - SA connection failed.
 * {@link E_OFF_WITHOUT_ON} 1006500006 - The interface is not used together with "HMS_Module_Install_On".
 * @syscap SystemCapability.AppGalleryService.Distribution.OnDemandInstall
 * @since 5.0.3(15)
 */
ModuleInstall_ErrCode HMS_ModuleInstall_Off(const char *bundleName, unsigned int length, unsigned int appIndex);

#ifdef __cplusplus
};
#endif
/** @} */
#endif // APPGALLERY_KIT_MODULE_INSTALL_H
