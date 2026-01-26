/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

/**
 * @addtogroup ServiceCollaboration
 * @{
 *
 * @brief Provides APIs for service collaboration capability.
 *
 * @syscap SystemCapability.Collaboration.Service
 * @since 5.0.0(12)
 */

/**
 * @file service_collaboration_api.h Defines collaboration service capabilities and provides collaboration service
 * interfaces.
 *
 * @brief Defines the service collaboration APIs of cross device service.
 *
 * @kit ServiceCollaborationKit
 * @library libservice_collaboration_ndk.z.so
 * @syscap SystemCapability.Collaboration.Service
 * @since 5.0.0(12)
 */

#ifndef SERVICE_COLLABORATION_API_H
#define SERVICE_COLLABORATION_API_H

#include "info/application_target_sdk_version.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates the types of collaboration services.
 * The caller must set up { @link ServiceCollaborationFilterType } to specify the type of service to get.
 *
 * @since 5.0.0(12)
 */
typedef enum ServiceCollaborationFilterType {
    /** indicates the collaboration service used to take photos. */
    TAKE_PHOTO = 1,
    /** indicates the collaboration service used to scan documents. */
    SCAN_DOCUMENT = 2,
    /** indicates the collaboration service used to pick images. */
    IMAGE_PICKER = 3
} ServiceCollaborationFilterType;

/**
 * @brief Enumerates the types of data type.
 * The caller must set up { @link ServiceCollaborationDataType } to specify the type of service to get.
 *
 * @since 5.0.0(12)
 */
typedef enum ServiceCollaborationDataType {
    /** indicates the data type is IMAGE. */
    IMAGE = 1,
} ServiceCollaborationDataType;

/**
 * @brief Enumerates the types of collaboration service event code.
 * The caller must set up { @link ServiceCollaborationEventCode } to specify the type of service to get.
 * @since 5.0.0(12)
 */
typedef enum ServiceCollaborationEventCode {
    /** Indicates indicates received the last pack of data. */
    LAST_DATA_BACK = 1001202000,
    /** Indicates service cancellation from the peer. */
    PEER_CANCEL = 1001202001,
    /** Indicates an network error. */
    NETWORK_ERROR = 1001202002,
    /** Indicates peer wifi not open. */
    PEER_WIFI_NOT_OPEN = 1001202004,
    /** Indicates local wifi not open. */
    LOCAL_WIFI_NOT_OPEN = 1001202005,
    /** Indicates data will be back with {@link extraCode} indicates data count. */
    DATA_BACK_START = 1001202006,
    /** Indicates received the middle data. */
    MIDDLE_DATA_BACK = 1001202007,
    /** Indicates auto canceled by timeout without task finished. */
    TIMEOUT_AUTO_CANCEL = 1001202008,
    /** Indicates data read failed. */
    DATA_READ_FAILED = 1001202009,
    /** Indicates link shutdown. */
    LINK_SHUTDOWN = 1001202011,
    /**
     * Link conflict because the peer device has activated its hotspot.
     * @since 5.1.0(18)
     */
    REMOTE_HOTSPOT_CONFLICT = 1001202013,
    /**
     * The peer device is connecting to another distributed device.
     * @since 5.1.0(18)
     */
    REMOTE_DISTRIBUTED_SERVICES_CONFLICT = 1001202014,
} ServiceCollaborationEventCode;

/**
 * @brief Indicates the peer device with its basic properties and service filter type.
 *
 * @since 5.0.0(12)
 */
#define COLLABORATIONDEVICEINFO_DEVICENETWORKID_MAXLENGTH  65
#define COLLABORATIONDEVICEINFO_DEVICENAME_MAXLENGTH 128
typedef struct ServiceCollaboration_CollaborationDeviceInfo {
    /** the peer device type. only could be 0x14 for phone or 0x17 for pad. */
    uint32_t deviceType;
    /** the peer device network id. */
    char deviceNetworkId[COLLABORATIONDEVICEINFO_DEVICENETWORKID_MAXLENGTH];
    /** the peer device name. */
    char deviceName[COLLABORATIONDEVICEINFO_DEVICENAME_MAXLENGTH];
    /** the list size of supported service type for the peer device. */
    uint32_t filterNum;
    /** the list of supported service types for the peer device. */
    ServiceCollaborationFilterType *serviceFilterTypes;
} ServiceCollaboration_CollaborationDeviceInfo;

/**
 * @brief Indicates the peer devices by { @link HMS_ServiceCollaboration_GetCollaborationDeviceInfos}.
 *
 * @since 5.0.0(12)
 */
typedef struct ServiceCollaboration_CollaborationDeviceInfoSets {
    /** the set size of peer devices. */
    uint32_t size;
    /** the set of peer devices. */
    ServiceCollaboration_CollaborationDeviceInfo *deviceInfoSets;
} ServiceCollaboration_CollaborationDeviceInfoSets;

/**
 * @brief Indicates the selected device which to do service collaboration
 * with { @link HMS_ServiceCollaboration_StartCollaboration}.
 *
 * @since 5.0.0(12)
 */
typedef struct ServiceCollaboration_SelectInfo {
    /** the wanted service filter type. */
    ServiceCollaborationFilterType serviceFilterType;
    /** the selected device network id. */
    char deviceNetworkId[COLLABORATIONDEVICEINFO_DEVICENETWORKID_MAXLENGTH];
    /** maximum number of images that can be selected. */
    uint32_t maxSize;
} ServiceCollaboration_SelectInfo;

/**
 * @brief Indicates the callback with { @link HMS_ServiceCollaboration_StartCollaboration}.
 *
 * @since 5.0.0(12)
 */
typedef struct ServiceCollaborationCallback {
    /**
     * @brief Called when the collaboration service state is changed.
     *
     * @param [in] {@link ServiceCollaborationCode} State of the collaboration service.
     * The following values are available:
     * 1001202001 indicates service cancellation from the peer.
     * 1001202002 indicates a network error.
     * 1001202004 indicates that WiFi is not open on the peer device.
     * 1001202005 indicates that WiFi is not open on the local device.
     * 1001202006 indicates that data will be sent back, along with {@link extraCode}, which indicates the data count.
     * 1001202008 indicates the request is automatically canceled due to 3-minute timeout.
     * 1001202009 indicates a failure in reading data.
     * 1001202011 indicates that the link is shut down.
     * 1001202013 indicates link conflict because the peer device has activated its hotspot.
     * 1001202014 indicates that the peer device is connecting to another distributed device.
     * @param [in] Extra code. The value could be the total data count within code 1001202006; others are reserved.
     * @return The return value is reserved.
     *
     * @since 5.0.0(12)
     */
    int32_t (*OnEvent)(ServiceCollaborationEventCode code, uint32_t extraCode);

    /**
     * @brief Called when the collaboration service data is back.
     *
     * @param [in] {@link ServiceCollaborationCode} State of the collaboration service. The value 1001202000
     * indicates received the last data, 1001202007 indicates received the middle data.
     * @param [in] The data type, 1 indicates image arraybuffer, others for reserved.
     * @param [in] The data size.
     * @param [in] The data.
     * @return The return value reserved.
     *
     * @since 5.0.0(12)
     */
    int32_t (*OnDataCallback)(
        ServiceCollaborationEventCode code, ServiceCollaborationDataType dataType, uint32_t dataSize, char* data);
} ServiceCollaborationCallback;

/**
 * @brief Get collaboration devices with supported service filter types.
 *
 * @param fileterNum The service filter types size.
 * @param serviceFileterTypes {@link ServiceCollaborationFilterType} The service filter types.
 * @return The peer devices with its service filter types.
 *
 * @since 5.0.0(12)
 */
ServiceCollaboration_CollaborationDeviceInfoSets* HMS_ServiceCollaboration_GetCollaborationDeviceInfos(
    uint32_t fileterNum, ServiceCollaborationFilterType serviceFileterTypes[])
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief start collaboration to selected device.
 *
 * @param selectService {@link ServiceCollaboration_SelectInfo} The selected service info.
 * @param callback {@link ServiceCollaborationCallback} The service collaboration callback.
 * @return The collaborationId.
 *
 * @since 5.0.0(12)
 */
uint32_t HMS_ServiceCollaboration_StartCollaboration(
    const ServiceCollaboration_SelectInfo* selectService, ServiceCollaborationCallback* callback)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief stop collaboration to selected device.
 *
 * @param collaborationId The collaboration id.
 * @return The stop result. 0 indicates success
 *
 * @since 5.0.0(12)
 */
int32_t HMS_ServiceCollaboration_StopCollaboration(uint32_t collaborationId)
__attribute__((__availability__(ohos, introduced=12.0.0)));

#ifdef __cplusplus
}
#endif

/** @} */
#endif //SERVICE_COLLABORATION_API_H