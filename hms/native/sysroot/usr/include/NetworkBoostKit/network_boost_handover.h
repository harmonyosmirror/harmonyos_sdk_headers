 /*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024. All rights reserved.
 */

/**
 * @addtogroup NetworkBoost
 * @{
 *
 * @brief Defines the functions of NetworkBoost.
 *
 * @since 5.1.0(18)
 */

 /**
 * @file network_boost_handover.h
 * @kit NetworkBoostKit
 *
 * @brief Defines the functions of Net Handover module.
 *
 * @library libnetwork_boost.so
 * @syscap SystemCapability.Communication.NetworkBoost.Core
 * @since 5.1.0(18)
 */
 
#ifndef NETWORK_BOOST_HANDOVER_API_H
#define NETWORK_BOOST_HANDOVER_API_H

#include "info/application_target_sdk_version.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "network_boost_quality.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Data speed simple action.
 * @since 5.1.0(18)
 */
typedef enum NetworkBoost_DataSpeedSimpleAction {
    /** Suspend data action */
    NB_SIMPLEACTION_SUSPEND_DATA = 1,
    /** Decrease data action. */
    NB_SIMPLEACTION_DECREASE_DATA = 2,
    /** Increase data action. */
    NB_SIMPLEACTION_INCREASE_DATA = 3,
    /** Keep data action. */
    NB_SIMPLEACTION_KEEP_DATA = 4
} NetworkBoost_DataSpeedSimpleAction;

/**
 * @brief Enum of handover error result.
 * @since 5.1.0(18)
 */
typedef enum NetworkBoost_ErrorResult {
    /** Indicates no error, handover is success */
    NB_ERROR_NONE = 0,
    /** Indicates handover timeout */
    NB_ERROR_HANDOVER_TIMEOUT = 1,
    /** Indicates that the activation of the new path has failed */
    NB_ERROR_NEW_PATH_ACTIVATION_FAILED = 2,
    /** Indicates handover abort */
    NB_ERROR_ABORT = 3
} NetworkBoost_ErrorResult;

/**
 * @brief Enum of the re-establish action.
 * @since 5.1.0(18)
 */
typedef enum NetworkBoost_ReEstAction {
    /** The App needs to re-establish the connection through the same remote IP address */
    NB_REEST_DEFAULT = 0,
    /** Data path type changed, e.g. wifi -> cell, or operator changed */
    NB_REEST_QUERY_DNS = 1,
    /** The remote IP needs to be changed, and the App needs to re-establish the connection using the new remote IP */
    NB_REEST_CHANGE_REMOTE_IP = 2,
    /** The IP version needs to be changed, e.g. ipv4 <-> ipv6 */
    NB_REEST_CHANGE_IP_VERSION = 3,
    /**
     * The data path and IP do not change.
     * The App needs to retry to fetch the resource from the remote in the current connection
     */
    NB_NO_EST = 4
} NetworkBoost_ReEstAction;

/**
 * @brief Data speed action info.
 * @since 5.1.0(18)
 */
typedef struct NetworkBoost_DataSpeedAction {
    /** Data speed simple action */
    NetworkBoost_DataSpeedSimpleAction dataSpeedSimpleAction;
    /** Uplink bandwidth */
    uint64_t linkUpBandwidth;
    /** Downlink bandwidth */
    uint64_t linkDownBandwidth;
} NetworkBoost_DataSpeedAction;

/**
 * @brief Net handle info.
 * @since 5.1.0(18)
 */
typedef struct NetworkBoost_NetHandle {
    /** Network ID */
    int32_t netId;
} NetworkBoost_NetHandle;

/**
 * @brief Handover start info.
 * @since 5.1.0(18)
 */
typedef struct NetworkBoost_HandoverStart {
    /** Timeout of handover, in seconds */
    uint32_t expires;
    /** Data speed action on old path */
    NetworkBoost_DataSpeedAction dataSpeedAction;
} NetworkBoost_HandoverStart;

/**
 * @brief Handover complete info.
 * @since 5.1.0(18)
 */
typedef struct NetworkBoost_HandoverComplete {
    /** Handover result */
    NetworkBoost_ErrorResult result;
    /** Whether is still new path to be activated, if value set to false, means the last new path */
    bool handoverContinue;
    /** Old path lifetime in seconds */
    uint32_t oldPathLifetime;
    /** Data speed action on old path */
    NetworkBoost_DataSpeedAction oldDataSpeedAction;
    /** Whether pathType changed */
    bool pathTypeChanged;
    /** New path netHandle */
    NetworkBoost_NetHandle newNetHandle;
    /** ReEst action */
    NetworkBoost_ReEstAction reEstAction;
    /** Data speed action on new path */
    NetworkBoost_DataSpeedAction newDataSpeedAction;
} NetworkBoost_HandoverComplete;

/**
 * @brief Enum of Handover mode.
 * @since 5.1.0(18)
 */
typedef enum NetworkBoost_HandoverMode {
    /**
     * Handover is triggered by the OS, and the OS activates the new path.
     * This is the default value.
     */
    NB_MODE_DELEGATION = 0,
    /**
     * Handover is not triggered by the OS, app activates the new path itself,
     * however, when the app is in the background, handover may triggered by the OS.
     */
    NB_MODE_DISCRETION = 1
} NetworkBoost_HandoverMode;

/**
 * @brief Enum of Path state.
 * @since 6.0.2(22)
 */
typedef enum NetworkBoost_PathState {
    /** Path state is idle, it can be activated */
    NB_PATH_IDLE = 0,
    /** Path has been activated */
    NB_PATH_CONNECTED,
    /** Path has been suspended, indicate link normal, but can not transfer data */
    NB_PATH_SUSPENDED,
} NetworkBoost_PathState;

/**
 * @brief Enum of Multi-Path error result.
 * @since 6.0.2(22)
 */
typedef enum NetworkBoost_MultiPathErrorResult {
    /** No error */
    NB_MULTIPATH_ERROR_NONE = 0,
    /** Refused by network */
    NB_MULTIPATH_ERROR_NETWORK_REFUSED,
    /** Active timeout */
    NB_MULTIPATH_ERROR_TIMEOUT,
    /** Active failed because user disable mobile data switch or other local 
     * abnormal occurred during activing process.
     */
    NB_MULTIPATH_ERROR_LOCAL
} NetworkBoost_MultiPathErrorResult;

/**
 * @brief Enum of Multi-Path change cause.
 * @since 6.0.2(22)
 */
typedef enum NetworkBoost_MultiPathChangeCause {
    /** Normal request */
    NB_MULTIPATH_CAUSE_REQUEST_NORMAL = 0,
    /** App release normally */
    NB_MULTIPATH_CAUSE_RELEASE_NORMAL = 50,
    /** Released by network */
    NB_MULTIPATH_CHANGE_CAUSE_RELEASE_NETWORK = 51,
    /** Released by user, for example, user turns off mobile data switch, WiFi switch, etc. */
    NB_MULTIPATH_CHANGE_CAUSE_RELEASE_USER_REFUSED = 52,
    /** Released cause application quota has been exhausted */
    NB_MULTIPATH_CAUSE_RELEASE_NO_QUOTA = 53,
    /** Released cause power consumption restrictions */
    NB_MULTIPATH_CAUSE_RELEASE_POWER_CONSUMPTION = 54,
    /** Released cause insufficient traffic control */
    NB_MULTIPATH_CHANGE_CAUSE_RELEASE_INSUFFICIENT_TRAFFIC = 55,
    /** Released cause multi-path conflict */
    NB_MULTIPATH_CHANGE_CAUSE_RELEASE_CONFLICT = 56,
    /** Released cause system fuse, such as malicious use of multi-path by applications */
    NB_MULTIPATH_CHANGE_CAUSE_RELEASE_SYS_FUSING = 57,
    /** Released cause system network state change */
    NB_MULTIPATH_CHANGE_CAUSE_RELEASE_SYS_DEFAULT = 99,
    /** Suspended cause can not concurrency */
    NB_MULTIPATH_CHANGE_CAUSE_SUSPEND_ENTER = 100,
    /** Cancel suspended cause can concurrency */
    NB_MULTIPATH_CHANGE_CAUSE_SUSPEND_LEAVE = 101,
    /** Multi-path connect properties change, such as IP change, etc. */
    NB_MULTIPATH_CHANGE_CAUSE_CONN_PROPERTIES_UPDATE = 102
} NetworkBoost_MultiPathChangeCause;

/**
 * @brief Multi-path quota information.
 * @since 6.0.2(22)
 */
typedef struct NetworkBoost_MultiPathQuotaInfo {
    /** Count */
    uint16_t count;
    /** Duration, Unit: seconds */
    uint16_t duration;
} NetworkBoost_MultiPathQuotaInfo;

/**
 * @brief Multi-path quota.
 * @since 6.0.2(22)
 */
typedef struct NetworkBoost_MultiPathQuota {
    /** Used quota */
    NetworkBoost_MultiPathQuotaInfo used;
    /** Remaining quota */
    NetworkBoost_MultiPathQuotaInfo remaining;
} NetworkBoost_MultiPathQuota;

/**
 * @brief getMultiPathQuotaStats 
 *
 * Get the multi-path quota for the current application.
 *
 * @param quota The callback result of multipath quota information. Quota cannot be nullptr.
 * @return 0 - Success.
 *         201 - Missing permissions.
 *         1013600001 - Internal error.
 *         1013600002 - System service operation failed.
 *         1013600041 - Parameter error.
 * @permission ohos.permission.LINKTURBO
 * @since 6.0.2(22)
 */
int32_t HMS_NetworkBoost_GetMultiPathQuotaStats(NetworkBoost_MultiPathQuota *quota)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief multipath request result.
 * @since 6.0.2(22)
 */
typedef struct NetworkBoost_MultiPathRequestResult {
    /** Request result */
    NetworkBoost_MultiPathErrorResult result;
} NetworkBoost_MultiPathRequestResult;

/**
 * @brief The callback is used to receive multipath request result.
 *
 * @param result Callbacks to listen multipath request result.
 * @since 6.0.2(22)
 */
typedef void (*HMS_NetworkBoost_OnMultiPathRequestResult)(NetworkBoost_MultiPathRequestResult* result);

/**
 * @brief Request multi-path
 *
 * This API is used to request multi-path.
 *
 * @param result The callback result of request multipath. Result cannot be nullptr.
 * @return 0 - Success.
 *         201 - Missing permissions.
 *         1013600001 - Internal error.
 *         1013600002 - System service operation failed.
 *         1013600041 - Parameter error.
 *         1013620000 - Multi-path capability is disabled.
 *         1013620001 - Multi-path links are already active or in the process of being established.
 *         1013620002 - App request limit reached.
 *         1013620003 - Request denied due to power consumption restrictions.
 *         1013620004 - No quota.
 *         1013620005 - Conflict.
 *         1013620006 - Requests are too frequent.
 *         1013620007 - No suitable path.
 *         1013620008 - Insufficient traffic.
 *         1013620009 - Concurrency is not allowed.
 * @permission ohos.permission.LINKTURBO
 * @since 6.0.2(22)
 */
int32_t HMS_NetworkBoost_RequestMultiPath(HMS_NetworkBoost_OnMultiPathRequestResult result)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Release multipath
 *
 * This API is used to release multipath.
 *
 * @return 0 - Success.
 *         201 - Missing permissions.
 *         1013600001 - Internal error.
 *         1013600002 - System service operation failed.
 *         1013620100 - Release request mismatch.
 *         1013620101 - Multi-path not activated.
 * @permission ohos.permission.LINKTURBO
 * @since 6.0.2(22)
 */
int32_t HMS_NetworkBoost_ReleaseMultiPath() __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Enum of Multi-Path state.
 * @since 6.0.2(22)
 */
typedef enum NetworkBoost_MultiPathState {
    /** Multi-path state is idle */
    NB_MULTIPATH_IDLE = 0,
    /** Indicates multi-path creation is in progress */
    NB_MULTIPATH_CREATING,
    /** Indicates multi-path has been created and is available */
    NB_MULTIPATH_CREATED,
    /** Indicates multi-path is releasing */
    NB_MULTIPATH_RELEASING,
} NetworkBoost_MultiPathState;

/**
 * @brief Multi-path state change.
 * @since 6.0.2(22)
 */
typedef struct NetworkBoost_MultiPathStateChange {
    /** Multi path state */
    NetworkBoost_MultiPathState multiPathState;
    /** Multi-path state change cause */
    NetworkBoost_MultiPathChangeCause changeCause;
    /** NetHandle of the changed path */
    NetworkBoost_NetHandle netHandle;
    /** Path state */
    NetworkBoost_PathState pathState;
    /** Path type */
    NetworkBoost_PathType pathType;
} NetworkBoost_MultiPathStateChange;

/**
 * @brief The callback is used to receive multipath state change.
 *
 * @param multiPathState Callbacks to listen multipath state.
 * @since 6.0.2(22)
 */
typedef void (*HMS_NetworkBoost_OnMultiPathStateChange)(NetworkBoost_MultiPathStateChange* multiPathState);

/**
 * @brief Enum of Multi-Path action.
 * @since 6.0.2(22)
 */
typedef enum NetworkBoost_MultiPathAction {
    /** Request multi-path */
    NB_MULTIPATH_ACTION_REQUEST = 0,
    /** Release multi-path */
    NB_MULTIPATH_ACTION_RELEASE
} NetworkBoost_MultiPathAction;

/**
 * @brief Multi-path recommendation.
 * @since 6.0.2(22)
 */
typedef struct NetworkBoost_MultiPathRecommendation {
    /** Multi-Path action */
    NetworkBoost_MultiPathAction action;
} NetworkBoost_MultiPathRecommendation;

/**
 * @brief The callback is used to receive multipath recommendation.
 *
 * @param multiPathState Callbacks to listen multipath recommendation.
 * @since 6.0.2(22)
 */
typedef void (*HMS_NetworkBoost_OnMultiPathRecommendation)(NetworkBoost_MultiPathRecommendation* recommendation);

/**
 * @brief Subscribe to the multi-path state change event
 *
 * This API is used to subscribe to the multi-path state change event.
 *
 * @param callback Callback used to listen for the multi-path state change. Callback cannot be nullptr.
 * @param callbackId CallbackId of the callback, assigned by the service.
 *         Used to unregister the callback. CallbackId cannot be nullptr.
 * @return 0 - Success.
 *         201 - Missing permissions.
 *         1013600001 - Internal error.
 *         1013600002 - System service error.
 *         1013600041 - Parameter error.
 * @permission ohos.permission.LINKTURBO
 * @since 6.0.2(22)
 */
int32_t HMS_NetworkBoost_RegisterMultiPathStateChangeCallback(
    HMS_NetworkBoost_OnMultiPathStateChange callback, uint32_t* callbackId)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Unsubscribe to the multi-path state change event.
 *
 * This API is used to unsubscribe to the multi-path state change event.
 *
 * @param callbackId CallbackId of the callback, assigned by the service. Used to unregister the callback.
 * @return 0 - Success.
 *         201 - Missing permissions.
 *         1013600001 - Internal error.
 *         1013600002 - System service error.
 * @permission ohos.permission.LINKTURBO
 * @since 6.0.2(22)
 */
int32_t HMS_NetworkBoost_UnregisterMultiPathStateChangeCallback(uint32_t callbackId)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Subscribe to the multi-path recommendation event
 *
 * This API is used to subscribe to the recommendation event.
 *
 * @param callback Callback used to listen for the multi-path state change. Callback cannot be nullptr.
 * @param callbackId CallbackId of the callback, assigned by the service.
 *         Used to unregister the callback. CallbackId cannot be nullptr.
 * @return 0 - Success.
 *         201 - Missing permissions.
 *         1013600001 - Internal error.
 *         1013600002 - System service error.
 *         1013600041 - Parameter error.
 * @permission ohos.permission.LINKTURBO
 * @since 6.0.2(22)
 */
int32_t HMS_NetworkBoost_RegisterMultiPathRecommendationCallback(
    HMS_NetworkBoost_OnMultiPathRecommendation callback, uint32_t* callbackId)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Unsubscribe to the multi-path recommendation event.
 *
 * This API is used to unsubscribe to the multi-path state change event.
 *
 * @param callbackId CallbackId of the callback, assigned by the service. Used to unregister the callback.
 * @return 0 - Success.
 *         201 - Missing permissions.
 *         1013600001 - Internal error.
 *         1013600002 - System service error.
 * @permission ohos.permission.LINKTURBO
 * @since 6.0.2(22)
 */
int32_t HMS_NetworkBoost_UnregisterMultiPathRecommendationCallback(uint32_t callbackId)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief The callback is used to receive handover start events during handover.
 *
 * @param handoverStart Callbacks to listen handover start events during handover.
 * @since 5.1.0(18)
 */
typedef void (*HMS_NetworkBoost_OnHandoverStart)(NetworkBoost_HandoverStart* handoverStart);

/**
 * @brief The callback is used to receive handover complete events during handover.
 *
 * @param handoverComplete Callbacks to listen handover complete events during handover.
 * @since 5.1.0(18)
 */
typedef void (*HMS_NetworkBoost_OnHandoverComplete)(NetworkBoost_HandoverComplete* handoverComplete);

/**
 * @brief Struct of the handover callback. Each fuction in the callback cannot be nullptr.
 *        This struct will not be changed in the future.
 * @since 5.1.0(18)
 */
typedef struct HMS_NetworkBoost_HandoverCallback {
    HMS_NetworkBoost_OnHandoverStart onNetworkHandoverStart;
    HMS_NetworkBoost_OnHandoverComplete onNetworkHandoverComplete;
} HMS_NetworkBoost_HandoverCallback;

/**
 * @brief Subscribe to the handover state change event.
 *
 * This API is used to subscribe to the handover state change event.
 *
 * @param callback Callback used to listen for the handover change. Each fuction in the callback cannot be nullptr.
 * @param callbackId CallbackId of the callback, assigned by the service. Used to unregister the callback.
 * @return 0 - Success.
 *         201 - Missing permissions.
 *         401 - Parameter error.
 *         801 - Capability not supported.
 *         62100001 - Internal error.
 *         62100002 - System service operation failed.
 *         62100003 - The number of registrations exceeds the limit.
 * @permission ohos.permission.GET_NETWORK_INFO
 * @since 5.1.0(18)
 */
int32_t HMS_NetworkBoost_RegisterHandoverChangeCallback(
    HMS_NetworkBoost_HandoverCallback* callback, uint32_t* callbackId)
    __attribute__((__availability__(ohos, introduced=18.0.0)));

/**
 * @brief Unsubscribe to the handover state change event.
 *
 * This API is used to unsubscribe to the handover state change event.
 *
 * @param callbackId CallbackId of the callback, assigned by the service when registering the callback.
 * @return 0 - Success.
 *         201 - Missing permissions.
 *         401 - Parameter error.
 *         801 - Capability not supported.
 *         62100001 - Internal error.
 *         62100002 - System service operation failed.
 * @permission ohos.permission.GET_NETWORK_INFO
 * @since 5.1.0(18)
 */
int32_t HMS_NetworkBoost_UnregisterHandoverChangeCallback(uint32_t callbackId)
__attribute__((__availability__(ohos, introduced=18.0.0)));

/**
 * @brief Set net handover mode.
 *
 * This API is used to set net handover mode.
 *
 * @param mode Mode of the net handover.
 * @return 0 - Success.
 *         201 - Missing permissions.
 *         401 - Parameter error.
 *         801 - Capability not supported.
 *         62100001 - Internal error.
 *         62100002 - System service operation failed.
 * @permission ohos.permission.GET_NETWORK_INFO
 * @since 5.1.0(18)
 */
int32_t HMS_NetworkBoost_SetHandoverMode(NetworkBoost_HandoverMode mode)
__attribute__((__availability__(ohos, introduced=18.0.0)));

#ifdef __cplusplus
}
#endif

#endif // NETWORK_BOOST_HANDOVER_API_H
/** @} */