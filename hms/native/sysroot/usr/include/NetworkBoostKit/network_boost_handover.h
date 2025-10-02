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

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

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
    HMS_NetworkBoost_HandoverCallback* callback, uint32_t* callbackId);

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
int32_t HMS_NetworkBoost_UnregisterHandoverChangeCallback(uint32_t callbackId);

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
int32_t HMS_NetworkBoost_SetHandoverMode(NetworkBoost_HandoverMode mode);

#ifdef __cplusplus
}
#endif

#endif // NETWORK_BOOST_HANDOVER_API_H
/** @} */