/*
 * Copyright (c) 2025 Huawei Device Co., Ltd.
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
 * @addtogroup DeviceManager
 * @{
 *
 * @brief Distributed device management module,
 * which provides APIs to obtain information about trusted devices and local devices.
 *
 * @since 20
 */

/**
 * @file oh_device_manager.h
 *
 * @brief Provides APIs to obtain information about trusted devices and local devices.
 * File to include: <distributedhardware/device_manager/oh_device_manager_err_code.h>
 *
 * @kit DistributedServiceKit
 * @library libdevicemanager_ndk.so
 * @syscap SystemCapability.DistributedHardware.DeviceManager
 *
 * @since 20
 */

#ifndef OH_DEVICE_MANAGER_H
#define OH_DEVICE_MANAGER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Obtains the display name of the local device.
 * The device display name involves user privacy.
 * You need to provide a privacy statement to declare the purpose of the device display name.
 *
 * @permission ohos.permission.READ_LOCAL_DEVICE_NAME
 * @param localDeviceName Pointer to the display name of the local device.
 * After using this API, you need to manually release resources to free up space.
 * If the application has the ohos.permission.READ_LOCAL_DEVICE_NAME permission, the device display name is returned.
 * Otherwise, the default device name is returned.
 * @param len Length of the display name of the local device.
 * @return Error code. For details about the error code definitions, see {@link DeviceManager_ErrorCode}.
 *      Returns {@link ERR_OK} is returned if the execution is successful.
 *      Returns {@link DM_ERR_FAILED} is returned if the function fails to be executed.
 *      Returns {@link DM_ERR_OBTAIN_SERVICE} is returned if the device management service fails to be obtained.
 *      Returns {@link DM_ERR_OBTAIN_BUNDLE_NAME} is returned if the bundle name fails to be obtained.
 * @since 20
 */
int32_t OH_DeviceManager_GetLocalDeviceName(char **localDeviceName, unsigned int &len);

#ifdef __cplusplus
};
#endif

/** @} */
#endif