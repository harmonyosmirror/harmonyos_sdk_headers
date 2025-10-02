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
 * @file oh_device_manager_err_code.h
 *
 * @brief Declares the error codes of the distributed device management module.
 * File to include: <distributedhardware/device_manager/oh_device_manager_err_code.h>
 *
 * @kit DistributedServiceKit
 * @library libdevicemanager_ndk.so
 * @syscap SystemCapability.DistributedHardware.DeviceManager
 *
 * @since 20
 */


#ifndef OH_DEVICE_MANAGER_ERR_CODE_H
#define OH_DEVICE_MANAGER_ERR_CODE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Error code information of distributed device management module.
 *
 * @since 20
 */
typedef enum DeviceManager_ErrorCode {
    /**
     * @error Operation success.
     */
    ERR_OK = 0,
    /**
     * @error Permission verification failed.
     */
    ERR_PERMISSION_ERROR = 201,
    /**
     * @error Invalid parameter.
     */
    ERR_INVALID_PARAMETER = 401,
    /**
     * @error Function execution failed.
     */
    DM_ERR_FAILED = 11600101,
    /**
     * @error Failed to obtain the device management service.
     */
    DM_ERR_OBTAIN_SERVICE = 11600102,
    /**
     * @error Failed to obtain the bundle name.
     */
    DM_ERR_OBTAIN_BUNDLE_NAME = 11600109,
} DeviceManager_ErrorCode;
#ifdef __cplusplus
};
#endif

/** @} */
#endif
