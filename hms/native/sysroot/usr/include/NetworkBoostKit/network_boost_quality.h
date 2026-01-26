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
 * @file network_boost_quality.h
 * @kit NetworkBoostKit
 *
 * @brief Defines the functions of Net Quality module.
 *
 * @library libnetwork_boost.so
 * @syscap SystemCapability.Communication.NetworkBoost.Core
 * @since 5.1.0(18)
 */
 
#ifndef NETWORK_BOOST_QUALITY_API_H
#define NETWORK_BOOST_QUALITY_API_H

#include "info/application_target_sdk_version.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Max length of network qos array
 * @since 5.1.0(18)
 */
#define NETBOOST_MAX_PATH_NUM 4
/**
 * @brief 1bps
 * @since 5.1.0(18)
 */
#define NB_BPS 1
/**
 * @brief 1kbps
 * @since 5.1.0(18)
 */
#define NB_KBPS 1000
/**
 * @brief 1mbps
 * @since 5.1.0(18)
 */
#define NB_MBPS 1000000
/**
 * @brief 1gbps
 * @since 5.1.0(18)
 */
#define NB_GBPS 1000000000
/**
 * @brief 1tbps. Please use uint64_t to avoid overflow
 * @since 5.1.0(18)
 */
#define NB_TBPS 1000000000000

/**
 * @brief Enum of recommended action.
 * @since 5.1.0(18)
 */
typedef enum NetworkBoost_RecommendedAction {
    /** do caching action */
    NB_ACTION_DO_CACHING = 0,
    /** Suspend data action */
    NB_ACTION_SUSPEND_DATA = 1,
    /** Decrease data action. */
    NB_ACTION_DECREASE_DATA = 2,
    /** Increase data action. */
    NB_ACTION_INCREASE_DATA = 3,
    /** Keep data action. */
    NB_ACTION_KEEP_DATA = 4
} NetworkBoost_RecommendedAction;

/**
 * @brief Path type.
 * @since 5.1.0(18)
 */
typedef enum NetworkBoost_PathType {
    /** primary cellular network path type. */
    NB_PATH_CELLULAR_PRIMARY = 0,
    /** secondary cellular network path type. */
    NB_PATH_CELLULAR_SECONDARY = 1,
    /** primary wifi network path type. */
    NB_PATH_WIFI_PRIMARY = 2,
    /** secondary wifi network path type. */
    NB_PATH_WIFI_SECONDARY = 3
} NetworkBoost_PathType;

/**
 * @brief Scene type.
 * @since 5.1.0(18)
 */
typedef enum NetworkBoost_Scene {
    /** normal scene */
    NB_SCENE_NORMAL = 0,
    /** congestion scene */
    NB_SCENE_CONGESTION = 1,
    /** frequentHandover scene */
    NB_SCENE_FREQUENT_HANDOVER = 2,
    /** weakSignal scene */
    NB_SCENE_WEAK_SIGNAL = 3
} NetworkBoost_Scene;

/**
 * @brief Qoe service type.
 * @since 5.1.0(18)
 */
typedef enum NetworkBoost_ServiceType {
    /** default service type */
    NB_SERVICE_DEFAULT = 0,
    /** background service type */
    NB_SERVICE_BACKGROUND = 1,
    /** realtimeVoice service type */
    NB_SERVICE_REAL_TIME_VOICE = 2,
    /** realtimeVideo service type */
    NB_SERVICE_REAL_TIME_VIDEO = 3,
    /** callSignaling service type */
    NB_SERVICE_CALL_SIGNALING = 4,
    /** realtimeGame service type */
    NB_SERVICE_REAL_TIME_GAME = 5,
    /** normalGame service type */
    NB_SERVICE_NORMAL_GAME = 6,
    /** shortVideo service type */
    NB_SERVICE_SHORT_VIDEO = 7,
    /** longVideo service type */
    NB_SERVICE_LONG_VIDEO = 8,
    /** livestreamingAnchor service type */
    NB_SERVICE_LIVE_STREAMING_ANCHOR = 9,
    /** livestreamingWatcher service type */
    NB_SERVICE_LIVE_STREAMING_WATCHER = 10,
    /** download service type */
    NB_SERVICE_DOWNLOAD = 11,
    /** upload service type */
    NB_SERVICE_UPLOAD = 12,
    /** browser service type */
    NB_SERVICE_BROWSER = 13,
    /** Transaction service type
     * @since 6.0.2(22)
     */
    NB_SERVICE_TRANSACTION = 14,
    /** detection service type
     * @since 6.0.2(22)
     */
    NB_SERVICE_DETECTION = 15,
    /** cloudService service type
     * @since 6.0.2(22)
     */
    NB_SERVICE_CLOUDSERVICE = 16,
    /** voiceConference service type
     * @since 6.0.2(22)
     */
    NB_SERVICE_VOICE_CONFERENCE = 17,
    /** videoConference service type
     * @since 6.0.2(22)
     */
    NB_SERVICE_VIDEO_CONFERENCE = 18,
    /** navigation service type
     * @since 6.0.2(22)
     */
    NB_SERVICE_NAVIGATION = 19,
    /** seckillService service type
     * @since 6.0.2(22)
     */
    NB_SERVICE_SECKILL_SERVICE = 20,
    /** login service type
     * @since 6.0.2(22)
     */
    NB_SERVICE_LOGIN = 21,
    /** audio service type
     * @since 6.0.2(22)
     */
    NB_SERVICE_AUDIO = 22,
    /** shopping service type
     * @since 6.0.2(22)
     */
    NB_SERVICE_SHOPPING = 23
} NetworkBoost_ServiceType;

/**
 * @brief Qoe Type.
 * @since 5.1.0(18)
 */
typedef enum NetworkBoost_QoeType {
    /** qoe good */
    NB_QOE_GOOD = 0,
    /** qoe bad cause: unknown */
    NB_QOE_BAD_UNKNOWN = 1,
    /** qoe bad cause: serverErr */
    NB_QOE_BAD_SERVER_ERROR = 2,
    /** qoe bad cause: noData */
    NB_QOE_BAD_NO_DATA = 3,
    /** qoe bad cause: packetLost */
    NB_QOE_BAD_PACKET_LOST = 4,
    /** qoe bad cause: packetOutOfOrder */
    NB_QOE_BAD_PACKET_OUT_OF_ORDER = 5,
    /** qoe bad cause: highJitter */
    NB_QOE_BAD_HIGH_JITTER = 6,
    /** qoe bad cause: highLatency */
    NB_QOE_BAD_HIGH_LATENCY = 7
} NetworkBoost_QoeType;

/**
 * @brief Network qos info.
 * @since 5.1.0(18)
 */
typedef struct NetworkBoost_NetworkQos {
    /** Specify networkQos reported on which pathType. */
    NetworkBoost_PathType pathType;
    /** Uplink bandwidth, unit: bps. */
    uint64_t linkUpBandwidth;
    /** Downlink bandwidth, unit: bps. */
    uint64_t linkDownBandwidth;
    /** Uplink rate, unit: bps. */
    uint64_t linkUpRate;
    /** Downlink rate, unit: bps. */
    uint64_t linkDownRate;
    /** Rtt in ms. */
    uint32_t rttMs;
    /** Uplink buffer delay time in ms. */
    uint32_t linkUpBufferDelayMs;
    /** Uplink buffer congestion percentage, value range [0, 100]. */
    uint32_t linkUpBufferCongestionPercent;
} NetworkBoost_NetworkQos;

/**
 * @brief Network qos info.
 * @since 5.1.0(18)
 */
typedef struct NetworkBoost_NetworkQosArray {
    /** The number of paths in network qos array. */
    uint32_t pathNum;
    /** Network qos array, each element is the qos information of a path, valid index range [0, pathNum - 1]. */
    NetworkBoost_NetworkQos networkQos[NETBOOST_MAX_PATH_NUM];
} NetworkBoost_NetworkQosArray;

/**
 * @brief WeakSignalPrediction info.
 * @since 5.1.0(18)
 */
typedef struct NetworkBoost_WeakSignalPrediction {
    /** If the last weak signal predicition is valid. */
    bool isLastPredictionValid;
    /** Enter the weak signal after startTime in seconds. */
    uint32_t startTime;
    /** Weak signal durations in seconds. */
    uint32_t duration;
} NetworkBoost_WeakSignalPrediction;

/**
 * @brief Network scene info.
 * @since 5.1.0(18)
 */
typedef struct NetworkBoost_NetworkScene {
    /** Specify networkScene reported on which pathType. */
    NetworkBoost_PathType pathType;
    /** Scene type. */
    NetworkBoost_Scene scene;
    /** Recommended action. */
    NetworkBoost_RecommendedAction recommendedAction;
    /** Weaksignal prediction. */
    NetworkBoost_WeakSignalPrediction weakSignalPrediction;
} NetworkBoost_NetworkScene;

/**
 * @brief The callback is used to receive netQos state change event.
 *
 * @param networkQosArray Callback used to listen for the change of the netQos.
 * @since 5.1.0(18)
 */
typedef void (*HMS_NetworkBoost_NetQosChange)(NetworkBoost_NetworkQosArray* networkQosArray);

/**
 * @brief The callback is used to receive netScene state change event.
 *
 * @param networkScene Callback used to listen for the change of the netScene.
 * @since 5.1.0(18)
 */
typedef void (*HMS_NetworkBoost_NetSceneChange)(NetworkBoost_NetworkScene* networkScene);

/**
 * @brief Subscribe to the net Qos state change event.
 *
 * This API is used to subscribe to the net Qos state change event.
 *
 * @param callback Callback used to listen for the net Qos change.
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
int32_t HMS_NetworkBoost_RegisterNetQosCallback(
    HMS_NetworkBoost_NetQosChange callback, uint32_t* callbackId)
    __attribute__((__availability__(ohos, introduced=18.0.0)));

/**
 * @brief Unsubscribe to the net Qos state change event.
 *
 * This API is used to unsubscribe to the net Qos state change event.
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
int32_t HMS_NetworkBoost_UnregisterNetQosCallback(uint32_t callbackId)
__attribute__((__availability__(ohos, introduced=18.0.0)));

/**
 * @brief Subscribe to the net scene change event.
 *
 * This API is used to subscribe to the net scene change event.
 *
 * @param callback Callback used to listen for the net scene change.
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
int32_t HMS_NetworkBoost_RegisterNetSceneCallback(
    HMS_NetworkBoost_NetSceneChange callback, uint32_t* callbackId)
    __attribute__((__availability__(ohos, introduced=18.0.0)));

/**
 * @brief Unsubscribe to the net scene change event.
 *
 * This API is used to unsubscribe to the net scene change event.
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
int32_t HMS_NetworkBoost_UnregisterNetSceneCallback(uint32_t callbackId)
__attribute__((__availability__(ohos, introduced=18.0.0)));

/**
 * @brief App report qoe info.
 *
 * This API is used to report app qoe info.
 *
 * @param serviceType App qoe service type.
 * @param qoeType App report qoe type.
 * @return 0 - Success.
 *         201 - Missing permissions.
 *         401 - Parameter error.
 *         801 - Capability not supported.
 *         62100001 - Internal error.
 *         62100002 - System service operation failed.
 * @permission ohos.permission.GET_NETWORK_INFO
 * @since 5.1.0(18)
 */
int32_t HMS_NetworkBoost_ReportQoe(NetworkBoost_ServiceType serviceType, NetworkBoost_QoeType qoeType)
__attribute__((__availability__(ohos, introduced=18.0.0)));

#ifdef __cplusplus
}
#endif

#endif // NETWORK_BOOST_QUALITY_API_H
/** @} */