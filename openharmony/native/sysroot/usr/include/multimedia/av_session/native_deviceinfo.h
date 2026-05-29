/*
 * Copyright (c) 2026 Huawei Device Co., Ltd.
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
 * @addtogroup OHAVSession
 * @{
 *
 * @brief Provide the definition of the C interface for the avsession module.
 *
 * @syscap SystemCapability.Multimedia.AVSession.Core
 *
 * @since 23
 * @version 1.0
 */

 /**
 * @file native_deviceinfo.h
 *
 * @brief Declare device info interfaces.
 *
 * @library libohavsession.so
 * @syscap SystemCapability.Multimedia.AVSession.Core
 * @kit AVSessionKit
 * @since 23
 * @version 1.0
 */

#ifndef NATIVE_DEVICEINFO_H
#define NATIVE_DEVICEINFO_H

#include "info/application_target_sdk_version.h"
#include <stdint.h>
#include "native_avsession_base.h"
#include "native_avsession_errors.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Declaring the device information.
 * The instance is used to get more device information detail attributes.
 *
 * @since 23
 */
typedef struct AVSession_DeviceInfo AVSession_DeviceInfo;

/**
 * @brief Declaring the target Device Information.
 *
 * @since 23
 */

typedef struct AVSession_OutputDeviceInfo {
    /**
     * @brief Array size of device information.
     */
    uint32_t size;
    /**
     * @brief Arrays of device information.
     */
    AVSession_DeviceInfo **deviceInfos;
} AVSession_OutputDeviceInfo;

/**
 * @brief Get Cast Category of the target device.
 *
 * @param deviceInfo The deviceInfo instance pointer
 * @param aVCastCategory The pointer {@link AVSession_AVCastCategory} variable
 *                       that will be set the device Cast Category value.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1.The param of deviceInfo is nullptr;
 *                                                 2.The param of aVCastCategory is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_DeviceInfo_GetAVCastCategory(AVSession_DeviceInfo *deviceInfo,
    AVSession_AVCastCategory *aVCastCategory)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get device Id of the target device.
 *
 * @param deviceInfo The deviceInfo instance pointer
 * @param deviceId the pointer variable that will be set the device id value.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1.The param of deviceInfo is nullptr;
 *                                                 2.The param of deviceId is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_DeviceInfo_GetDeviceId(AVSession_DeviceInfo *deviceInfo, char **deviceId)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get device name of the target device.
 *
 * @param deviceInfo The deviceInfo instance pointer
 * @param deviceName the pointer variable that will be set the device name value.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1.The param of deviceInfo is nullptr;
 *                                                 2.The param of deviceName is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_DeviceInfo_GetDeviceName(AVSession_DeviceInfo *deviceInfo, char **deviceName)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get device type of the target device.
 *
 * @param deviceInfo The deviceInfo instance pointer
 * @param deviceType the pointer {@link AVSession_DeviceType} variable that will be set the device type value.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1.The param of deviceInfo is nullptr;
 *                                                 2.The param of deviceType is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_DeviceInfo_GetDeviceType(AVSession_DeviceInfo *deviceInfo, AVSession_DeviceType *deviceType)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Get supported protocols of the target device.
 *
 * @param deviceInfo The deviceInfo instance pointer
 * @param deviceProtocolType the pointer variable that will be set the protocols supported by current device,
 *                           can be union of {@link ProtocolType}.
 * @return Function result code:
 *         {@link AV_SESSION_ERR_SUCCESS} If the execution is successful.
 *         {@link AV_SESSION_ERR_INVALID_PARAMETER}
 *                                                 1.The param of deviceInfo is nullptr;
 *                                                 2.The param of deviceProtocolType is nullptr.
 * @since 23
 */
AVSession_ErrCode OH_DeviceInfo_GetSupportedProtocols(AVSession_DeviceInfo *deviceInfo,
    uint32_t *deviceProtocolType)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

#ifdef __cplusplus
}
#endif

#endif // NATIVE_DEVICEINFO_H
/** @} */