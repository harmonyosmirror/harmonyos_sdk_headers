/*
   * Copyright (c) Huawei Technologies Co., Ltd. 2025. All rights reserved.
   */

/**
 * @addtogroup SecurityAudit
 * @{
 *
 * @brief Provides APIs for Security Audit.
 *
 * @since 6.0.0(20)
 */

/**
 * @file security_audit.h
 *
 * @brief Defines APIs for Security Audit.
 *
 * @library libsecurityaudit_ndk.z.so
 * @kit DeviceSecurityKit
 * @syscap SystemCapability.Security.SecurityAudit
 * @since 6.0.0(20)
 */
#ifndef SECURITY_AUDIT_H
#define SECURITY_AUDIT_H

#include "info/application_target_sdk_version.h"
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines the eventIds of notify events.
 *
 * @syscap SystemCapability.Security.SecurityAudit
 * @since 6.0.0(20)
 */
typedef enum {
    /**
     * Clipboard copy and paste event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_PASTEBOARD = 0x27000000,
    /**
     * File event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_FILE = 0x1C000007,
    /**
     * File access rule violation event.
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_FILE_INTERCEPTED = 0x1C001100,
    /**
     * Account login and logout event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_ACCOUNT = 0x10000100,
    /**
     * Window screenshot, screen recording, screen projection event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_WINDOW = 0x07000000,
    /**
     * Removable storage insertion and removal event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_VOLUME = 0x0F000000,
    /**
     * Printer event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_PRINTER = 0x2E000000,
    /**
     * Process creation exit event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_PROCESS = 0x1C000008,
    /**
     * Network traffic event.
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_NETWORK_TRAFFIC = 0x1C00000E,
    /**
     * Network connection event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_NETWORK_CONN = 0x1C00000F,
    /**
     * Camera event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_CAMERA = 0x2D000000,
    /**
     * Application event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_APP = 0x10000000,
    /**
     * Edm event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_EDM = 0x11000000,
    /**
     * Certificate operation event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_CERT = 0x12003000,
    /**
     * KIA file creation event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_KIA_CREATE = 0x1C00000B,
    /**
     * KIA file read event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_KIA_READ = 0x1C000012,
    /**
     * KIA file variant event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_KIA_VARIANT = 0x1C00000C,
    /**
     * KIA file interception event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_KIA_INTERCEPT = 0x1C00000A,
    /**
     * Application permission change event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_PERMISSION = 0x0B000000,
    /**
     * DNS audit event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_DNS = 0x03000001,
    /**
     * Application installation intercepts event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_APP_INSTALL_INTERCEPTED = 0x18000100,
    /**
     * Application uninstallation intercepts event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_APP_UNINSTALL_INTERCEPTED = 0x18000101,
    /**
     * Application update intercept event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_APP_UPDATE_INTERCEPTED = 0x18000102,
    /**
     * Application recovery interception event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_APP_RECOVER_INTERCEPTED = 0x18000103,
    /**
     * The application starts intercepting events.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_APP_START_INTERCEPTED = 0x18000104,
    /**
     * USB access intercept event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_NOTIFY_EVENT_USB_ACCESS_INTERCEPTED = 0x30000000
} SecurityAudit_Notify_Event;

/**
 * @brief Defines the eventIds of auth events.
 *
 * @syscap SystemCapability.Security.SecurityAudit
 * @since 6.0.0(20)
 */
typedef enum {
    /**
     * File creation auth event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_AUTH_EVENT_FILE_CREATE = 0x1C801100,
    /**
     * File opening auth event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_AUTH_EVENT_FILE_OPEN = 0x1C801101,
    /**
     * File renaming auth event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_AUTH_EVENT_FILE_RENAME = 0x1C801102,
    /**
     * File deletion auth event.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_AUTH_EVENT_FILE_DELETE = 0x1C801103,
    /**
     * Auth event for setting extended attributes of a file.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_AUTH_EVENT_FILE_SETEXTATTR = 0x1C801104,
    /**
     * Auth event for deleting extended attributes of a file.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    SECURITY_AUDIT_AUTH_EVENT_FILE_DELETEEXTATTR = 0x1C801105
} SecurityAudit_Auth_Event;

/**
 * @brief Defines the audit event information.
 *
 * @since 6.0.0(20)
 */
typedef struct {
    /**
     * Audit event ID.
     */
    int64_t eventId;
    /**
     * JsonStr, which integrates the event version number,
     * event receiving time, device ID, and user ID.
     */
    const char* metadata;
    /**
     * Event content.
     */
    const char* content;
} SecurityAudit_Event;

/**
 * @brief Defines the event processing function.
 *
 * @param {SecurityAudit_Event*} events Pointer to the audit event information.
 * @param {uint64_t} count Number of events in the array.
 * @since 6.0.0(20)
 */
typedef void (*SecurityAudit_Handler)(const SecurityAudit_Event *events, uint64_t count);

/**
 * @brief Defines the auth client.
 *
 * @since 6.0.0(20)
 */
typedef struct SecurityAudit_AuthClient_Impl SecurityAudit_AuthClient;

/**
 * @brief Defines the notify client.
 *
 * @since 6.0.0(20)
 */
typedef struct SecurityAudit_Client_Impl SecurityAudit_Client;

/**
 * @brief Defines the type of filter type.
 *
 * @syscap SystemCapability.Security.SecurityAudit
 * @since 6.0.0(20)
 */
typedef enum {
    /**
     * Filter type of the event type.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    EVENT_TYPE_EQUAL = 0x00000100,

    /**
     * Filter type of the event subtype.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    EVENT_SUBTYPE_EQUAL = 0x00000200,

    /**
     * Filter type of the file path type.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    FILE_PATH_EQUAL = 0x00010000,

    /**
     * Filter type of the file path prefix type.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    FILE_PATH_PREFIX = 0x00010001,

    /**
     * Filter type of the file path suffix type.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    FILE_PATH_SUFFIX = 0x00010002,

    /**
     * Filter type of process uid.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    PROCESS_UID_EQUAL = 0x00020000,

    /**
     * Filter type of process ID.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    PROCESS_PID_EQUAL = 0x00020100,

    /**
     * Filter type of process name.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    PROCESS_NAME_EQUAL = 0x00020200,

    /**
     * Filter type of the process name prefix.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    PROCESS_NAME_PREFIX = 0x00020201,

    /**
     * Filter type of the process name suffix.
     *
     * @syscap SystemCapability.Security.SecurityAudit
     * @since 6.0.0(20)
     */
    PROCESS_NAME_SUFFIX = 0x00020202
} SecurityAudit_FilterType;

/**
 * @brief Provides the conditions of filter.
 *
 * @since 6.0.0(20)
 */
typedef struct {
    /**
     * TRUE: The event that matches the condition is returned to the client.
     * FALSE: The event is not returned.
     */
    bool isInclude;
    /**
     * The type of filter.
     */
    SecurityAudit_FilterType type;
    /**
     * The filter value of an event.
     */
    const char **value;
    /**
     * Number of filter values.
     */
    uint64_t valueCount;
} SecurityAudit_Filter;

/**
 * @brief Defines the type of auth result.
 *
 * @since 6.0.0(20)
 */
typedef enum {
    /** 
     * Allow auth event.
     */
    SECURITY_AUDIT_AUTH_RESULT_ALLOW = 0,
    /** 
     * Deny auth event.
     */
    SECURITY_AUDIT_AUTH_RESULT_DENY = 1
} SecurityAudit_AuthResult;

/**
 * @brief Creates a new notification client.
 *
 * @permission ohos.permission.QUERY_AUDIT_EVENT
 * @param {SecurityAudit_Client**} client Pointer to the new client instance.
 * @param {SecurityAudit_Handler} handler Handler that processes all messages sent to this client.
 * @return Function execution result.
 * Return value description:
 * If the operation is successful, 0 is returned.
 * If the permission verification fails, 201 is returned.
 * If an internal error occurs, 1012000001 is returned.
 * If the number of clients exceeds the total upper limit, 1012000002 is returned.
 * If the number of clients exceeds the upper limit of the current process, 1012000003 is returned.
 * @since 6.0.0(20)
 */
int32_t HMS_SecurityAudit_NewClient(SecurityAudit_Client** client, SecurityAudit_Handler handler)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Deletes a notification client.
 *
 * @permission ohos.permission.QUERY_AUDIT_EVENT
 * @param {SecurityAudit_Client*} client Client instance to be deleted.
 * @return Function execution result.
 * Return value description:
 * If the operation is successful, 0 is returned.
 * If the permission verification fails, 201 is returned.
 * If an internal error occurs, 1012000001 is returned.
 * @since 6.0.0(20)
 */
int32_t HMS_SecurityAudit_DeleteClient(SecurityAudit_Client* client)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Subscribes to notification events.
 *
 * @permission ohos.permission.QUERY_AUDIT_EVENT
 * @param {SecurityAudit_Client*} client Client that subscribes to notification events.
 * @param {SecurityAudit_Notify_Event*} events Array of notification events to be subscribed to.
 * @param {uint64_t} count Number of notification events in the array.
 * @return Function execution result.
 * Return value description:
 * If the operation is successful, 0 is returned.
 * If the permission verification fails, 201 is returned.
 * If an internal error occurs, 1012000001 is returned.
 * @since 6.0.0(20)
 */
int32_t HMS_SecurityAudit_Subscribe(const SecurityAudit_Client* client, const SecurityAudit_Notify_Event *events,
    uint64_t count)
    __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Unsubscribes from notification events.
 *
 * @permission ohos.permission.QUERY_AUDIT_EVENT
 * @param {SecurityAudit_Client*} client Client that unsubscribes from notification events.
 * @param {SecurityAudit_Notify_Event*} events Array of notification events to be unsubscribed from.
 * @param {uint64_t} count Number of notification events in the array.
 * @return Function execution result.
 * Return value description:
 * If the operation is successful, 0 is returned.
 * If the permission verification fails, 201 is returned.
 * If an internal error occurs, 1012000001 is returned.
 * @since 6.0.0(20)
 */
int32_t HMS_SecurityAudit_Unsubscribe(const SecurityAudit_Client* client, const SecurityAudit_Notify_Event *events,
    uint64_t count)
    __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Adds a filter condition to a notify event.
 *
 * @permission ohos.permission.QUERY_AUDIT_EVENT
 * @param {SecurityAudit_Client*} client Client created before.
 * @param {SecurityAudit_Notify_Event} event Notify event for which a filter condition is to be added.
 * @param {SecurityAudit_Filter*} filter Filter description of the notify event.
 * @return Function execution result.
 * Return value description:
 * If the operation is successful, 0 is returned.
 * If the permission verification fails, 201 is returned.
 * If an internal error occurs, 1012000001 is returned.
 * If the number of filters exceeds the upper limit, 1012000004 is returned.
 * If the event does not support the filter condition, 1012000005 is returned.
 * @since 6.0.0(20)
 */
int32_t HMS_SecurityAudit_AddFilter(const SecurityAudit_Client* client, SecurityAudit_Notify_Event event,
    const SecurityAudit_Filter *filter)
    __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Deletes the filter condition of a notify event.
 *
 * @permission ohos.permission.QUERY_AUDIT_EVENT
 * @param {SecurityAudit_Client*} client Client created before.
 * @param {SecurityAudit_Notify_Event} event Notify event whose filter condition is to be deleted.
 * @param {SecurityAudit_Filter*} filter Filter description of the notify event.
 * @return Function execution result.
 * Return value description:
 * If the operation is successful, 0 is returned.
 * If the permission verification fails, 201 is returned.
 * If an internal error occurs, 1012000001 is returned.
 * If the event does not support the filter condition, 1012000005 is returned.
 * @since 6.0.0(20)
 */
int32_t HMS_SecurityAudit_RemoveFilter(const SecurityAudit_Client* client, SecurityAudit_Notify_Event event,
    const SecurityAudit_Filter *filter)
    __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Creates a new auth client.
 *
 * @permission ohos.permission.kernel.AUTH_AUDIT_EVENT
 * @param {SecurityAudit_AuthClient**} client Pointer to the new client instance.
 * @param {SecurityAudit_Handler} handler Handler that processes all messages sent to this client.
 * @return Function execution result.
 * Return value description:
 * If the operation is successful, 0 is returned.
 * If the permission verification fails, 201 is returned.
 * If an internal error occurs, 1012000001 is returned.
 * If the number of clients exceeds the total upper limit, 1012000002 is returned.
 * If the number of clients exceeds the upper limit of the current process, 1012000003 is returned.
 * @since 6.0.0(20)
 */
int32_t HMS_SecurityAudit_NewAuthClient(SecurityAudit_AuthClient** client, SecurityAudit_Handler handler)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Deletes an auth client.
 *
 * @permission ohos.permission.kernel.AUTH_AUDIT_EVENT
 * @param {SecurityAudit_AuthClient*} client Client instance to be deleted.
 * @return Function execution result.
 * Return value description:
 * If the operation is successful, 0 is returned.
 * If the permission verification fails, 201 is returned.
 * If an internal error occurs, 1012000001 is returned.
 * @since 6.0.0(20)
 */
int32_t HMS_SecurityAudit_DeleteAuthClient(SecurityAudit_AuthClient* client)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Subscribes to auth events.
 *
 * @permission ohos.permission.kernel.AUTH_AUDIT_EVENT
 * @param {SecurityAudit_AuthClient*} client Client that subscribes to auth events.
 * @param {SecurityAudit_Auth_Event*} events Array of auth events to be subscribed to.
 * @param {uint64_t} count Number of auth events in the array.
 * @return Function execution result.
 * Return value description:
 * If the operation is successful, 0 is returned.
 * If the permission verification fails, 201 is returned.
 * If an internal error occurs, 1012000001 is returned.
 * @since 6.0.0(20)
 */
int32_t HMS_SecurityAudit_SubscribeAuthEvent(const SecurityAudit_AuthClient* client,
    const SecurityAudit_Auth_Event *events, uint64_t count)
    __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Unsubscribes from auth events.
 *
 * @permission ohos.permission.kernel.AUTH_AUDIT_EVENT
 * @param {SecurityAudit_AuthClient*} client Client that unsubscribes from auth events.
 * @param {SecurityAudit_Auth_Event*} events Array of auth events to be unsubscribed from.
 * @param {uint64_t} count Number of auth events in the array.
 * @return Function execution result.
 * Result code description:
 * 0 is returned if the operation is successful.
 * 201 is returned if the permission verification fails.
 * 1012000001 is returned if an internal error occurs.
 * @since 6.0.0(20)
 */
int32_t HMS_SecurityAudit_UnsubscribeAuthEvent(const SecurityAudit_AuthClient* client,
    const SecurityAudit_Auth_Event *events, uint64_t count)
    __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Adds a filter condition to an auth event.
 *
 * @permission ohos.permission.kernel.AUTH_AUDIT_EVENT
 * @param {SecurityAudit_AuthClient*} client Client created before.
 * @param {SecurityAudit_Auth_Event} event Auth event for which a filter condition is to be added.
 * @param {SecurityAudit_Filter*} filter Filter description of the auth event.
 * @return Function execution result.
 * Return value description:
 * If the operation is successful, 0 is returned.
 * If the permission verification fails, 201 is returned.
 * If an internal error occurs, 1012000001 is returned.
 * If the number of filters exceeds the upper limit, 1012000004 is returned.
 * If the event does not support the filter condition, 1012000005 is returned.
 * @since 6.0.0(20)
 */
int32_t HMS_SecurityAudit_AddAuthEventFilter(const SecurityAudit_AuthClient* client, SecurityAudit_Auth_Event event,
    const SecurityAudit_Filter *filter)
    __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Deletes the filter condition of an auth event.
 *
 * @permission ohos.permission.kernel.AUTH_AUDIT_EVENT
 * @param {SecurityAudit_AuthClient*} client Client created before.
 * @param {SecurityAudit_Auth_Event} event Auth event whose filter condition is to be deleted.
 * @param {SecurityAudit_Filter*} filter Filter description of the auth event.
 * @return Function execution result.
 * Return value description:
 * If the operation is successful, 0 is returned.
 * If the permission verification fails, 201 is returned.
 * If an internal error occurs, 1012000001 is returned.
 * If the event does not support the filter condition, 1012000005 is returned.
 * @since 6.0.0(20)
 */
int32_t HMS_SecurityAudit_RemoveAuthEventFilter(const SecurityAudit_AuthClient* client, SecurityAudit_Auth_Event event,
    const SecurityAudit_Filter *filter)
    __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Sets the authorization result for an audit event.
 *
 * @permission ohos.permission.kernel.AUTH_AUDIT_EVENT
 * @param {SecurityAudit_AuthClient*} client Client that generates the event.
 * @param {SecurityAudit_Event} event Audit event information.
 * @param {SecurityAudit_AuthResult} authResult Authorization result information.
 * @return Function execution result. 
 * Result code description:
 * 0 is returned if the operation is successful.
 * 201 is returned if the permission verification fails.
 * If an internal error occurs, 1012000001 is returned.
 * If the auth event cannot be found, 1012000007 is returned.
 * @since 6.0.0(20)
 */
int32_t HMS_SecurityAudit_Auth(const SecurityAudit_AuthClient* client, const SecurityAudit_Event *event,
    SecurityAudit_AuthResult authResult)
    __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Queries all processes.
 *
 * @permission ohos.permission.QUERY_AUDIT_EVENT
 * @param {char**} result Query result.
 * @return Function execution result.
 * Result code description:
 * 0 is returned if the operation is successful.
 * 201 is returned if the permission verification fails.
 * 1012000001 is returned if an internal error occurs.
 * @since 6.0.0(20)
 */
int32_t HMS_SecurityAudit_QueryAllProcesses(char** result) __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Query process information in batches.
 *
 * @permission ohos.permission.QUERY_AUDIT_EVENT
 * @param {uint64_t*} pids List of process IDs to be queried.
 * @param {uint64_t} count Number of processes.
 * @param {char**} result Query result.
 * @return Function execution result.
 * Return value description:
 * If the operation is successful, 0 is returned.
 * If the permission verification fails, 201 is returned.
 * If an internal error occurs, 1012000001 is returned.
 * If the number of queried processes exceeds the threshold, 1012000006 is returned.
 * @since 6.0.0(20)
 */
int32_t HMS_SecurityAudit_QueryProcesses(uint64_t* pids, uint64_t count, char** result)
__attribute__((__availability__(ohos, introduced=20.0.0)));

#ifdef __cplusplus
}
#endif
#endif // SECURITY_AUDIT_H

/** @} */
