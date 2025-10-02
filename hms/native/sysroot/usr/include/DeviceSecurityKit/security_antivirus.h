/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025. All rights reserved.
 */

/**
 * @addtogroup SecurityAntivirus
 * @{
 *
 * @brief Provides APIs for Security Antivirus.
 *
 * @since 6.0.0(20)
 */

/**
 * @file security_antivirus.h
 *
 * @brief Defines APIs for Security Antivirus.
 *
 * @library libsecurityantivirus_ndk.z.so
 * @kit DeviceSecurityKit
 * @syscap SystemCapability.Security.SecurityAntivirus
 * @since 6.0.0(20)
 */
#ifndef SECURITY_ANTIVIRUS_H
#define SECURITY_ANTIVIRUS_H
#include <stdint.h>
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines the antivirus application information.
 *
 * @since 6.0.0(20)
 */
typedef struct {
    /** 
     * Antivirus application bundle name.
     */
    const char* bundleName;
    /** 
     * JsonStr, which integrates the application version number,
     * virus feature updating time, protection status, and account id.
     */
    const char* metadata;
} SecurityAntivirus_Antivirus;

/**
 * @brief Defines error codes.
 *
 * @since 6.0.0(20)
 */
typedef enum SecurityAntivirus_ErrCode {
    /** Success. */
    SECURITY_ANTIVIRUS_SUCCESS = 0,

    /** Permission not granted. */
    SECURITY_ANTIVIRUS_PERMISSION_NOT_GRANTED = 201,

    /** Invalid parameter. */
    SECURITY_ANTIVIRUS_PARAM_INVALID = 1019900001,

    /** The antivirus software does not require registration. */
    SECURITY_ANTIVIRUS_NO_REGISTER = 1019900002,

    /** Internal error. */
    SECURITY_ANTIVIRUS_INNER_ERROR = 1019900003
} SecurityAntivirus_ErrCode;



/**
 * @brief Registers antivirus software information with the system.
 *
 * @permission ohos.permission.REGISTER_ANTIVIRUS
 * @param {const char*} bundleName Software package name for registration.
 * @return Function execution result. 
 * Result code description: 
 * - 0 is returned if the operation is successful. 
 * - 201 is returned if the permission verification fails. 
 * - 1019900001 is returned if the parameter verification fails. 
 * - 1019900003 is returned if an internal error occurs. 
 * @since 6.0.0(20)
 */
SecurityAntivirus_ErrCode HMS_SecurityAntivirus_RegisterAntivirus(const char* bundleName);

/**
 * @brief Unregisters antivirus software information from the system.
 *
 * @permission ohos.permission.REGISTER_ANTIVIRUS
 * @param {const char*} bundleName Antivirus software package name for unregistration.
 * @return 
 * Function execution result. 
 * Result code description: 
 * - 0 is returned if the operation is successful. 
 * - 201 is returned if the permission verification fails. 
 * - 1019900001 is returned if the parameter verification fails. 
 * - 1019900003 is returned if an internal error occurs. 
 * @since 6.0.0(20)
 */
SecurityAntivirus_ErrCode HMS_SecurityAntivirus_UnregisterAntivirus(const char* bundleName);

/**
 * @brief Updates antivirus software information.
 *
 * @permission ohos.permission.REGISTER_ANTIVIRUS
 * @param {const SecurityAntivirus_Antivirus*} antivirus New antivirus software information for update.
 * @return Function execution result. 
 * Result code description: 
 * - 0 is returned if the operation is successful. 
 * - 201 is returned if the permission verification fails. 
 * - 1019900001 is returned if the parameter verification fails. 
 * - 1019900002 is returned if the antivirus software is not registered. 
 * - 1019900003 is returned if an internal error occurs. 
 * @since 6.0.0(20)
 */
SecurityAntivirus_ErrCode HMS_SecurityAntivirus_UpdateAntivirus(const SecurityAntivirus_Antivirus* antivirus);

/**
 * @brief Queries the third-party antivirus software information.
 *
 * @permission ohos.permission.MANAGE_ANTIVIRUS
 * @param {SecurityAntivirus_Antivirus**} list Third-party antivirus software list.
 * @param {uint32_t*} length Length of the third-party antivirus software list.
 * @return Function execution result. 
 * Result code description: 
 * - 0 is returned if the operation is successful. 
 * - 201 is returned if the permission verification fails. 
 * - 1019900001 is returned if the parameter verification fails. 
 * - 1019900003 is returned if an internal error occurs.
 * @since 6.0.0(20)
 */
SecurityAntivirus_ErrCode HMS_SecurityAntivirus_QueryAntivirus(SecurityAntivirus_Antivirus** list, uint32_t* length);

/**
 * @brief Queries the preinstalled antivirus software information of all users.
 *
 * @permission ohos.permission.MANAGE_PREINSTALLED_ANTIVIRUS
 * @param {SecurityAntivirus_Antivirus**} list List of preinstalled antivirus software information.
 * @param {uint32_t*} length Length of the preinstalled antivirus software information list.
 * @return Function execution result. 
 * Result code description: 
 * - 0 is returned if the operation is successful. 
 * - 201 is returned if the permission verification fails. 
 * - 1019900001 is returned if the parameter verification fails. 
 * - 1019900003 is returned if an internal error occurs.
 * @since 6.0.0(20)
 */
SecurityAntivirus_ErrCode HMS_SecurityAntivirus_QueryPreinstalledAntivirus(
    SecurityAntivirus_Antivirus **list, uint32_t *length);

/**
 * @brief Enables the preinstalled antivirus function.
 *
 * @permission ohos.permission.MANAGE_PREINSTALLED_ANTIVIRUS
 * @return Function execution result. 
 * Result code description: 
 * 0 is returned if the operation is successful. 
 * 201 is returned if the permission verification fails. 
 * 1019900003 is returned if an internal error occurs.
 * @since 6.0.0(20)
 */
SecurityAntivirus_ErrCode HMS_SecurityAntivirus_EnablePreinstalledAntivirus(void);

/**
 * @brief Disables the preinstalled antivirus function.
 *
 * @permission ohos.permission.MANAGE_PREINSTALLED_ANTIVIRUS
 * @return Function execution result. 
 * Result code description: 
 * 0 is returned if the operation is successful. 
 * 201 is returned if the permission verification fails. 
 * 1019900003 is returned if an internal error occurs.
 * @since 6.0.0(20)
 */
SecurityAntivirus_ErrCode HMS_SecurityAntivirus_DisablePreinstalledAntivirus(void);

/**
 * @brief Enables the preinstalled antivirus software by account ID.
 *
 * @permission ohos.permission.MANAGE_PREINSTALLED_ANTIVIRUS
 * @param {int32_t} accountId Account ID for which the preinstalled antivirus software is to be enabled.
 * @return Function execution result. 
 * Result code description: 
 * - 0 is returned if the operation is successful. 
 * - 201 is returned if the permission verification fails. 
 * - 1019900001 is returned if the parameter verification fails. 
 * - 1019900003 is returned if an internal error occurs.
 * @since 6.0.0(20)
 */
SecurityAntivirus_ErrCode HMS_SecurityAntivirus_EnablePreinstalledAntivirusByAccount(int32_t accountId);

/**
 * @brief Disables the preinstalled antivirus software by account ID.
 *
 * @permission ohos.permission.MANAGE_PREINSTALLED_ANTIVIRUS
 * @param {int32_t} accountId Account ID for which the preinstalled antivirus software is to be disabled.
 * @return Function execution result. 
 * Result code description: 
 * - 0 is returned if the operation is successful. 
 * - 201 is returned if the permission verification fails. 
 * - 1019900001 is returned if the parameter verification fails. 
 * - 1019900003 is returned if an internal error occurs.
 * @since 6.0.0(20)
 */
SecurityAntivirus_ErrCode HMS_SecurityAntivirus_DisablePreinstalledAntivirusByAccount(int32_t accountId);

#ifdef __cplusplus
}
#endif
#endif // SECURITY_ANTIVIRUS_H

/** @} */
