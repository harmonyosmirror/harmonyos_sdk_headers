/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

/**
 * @addtogroup DeviceSecurity
 * @{
 *
 * @brief Provides APIs for Device Security.
 *
 * @Syscap SystemCapability.Security.SafetyDetect
 * @since 5.0.1(13)
 */

/**
 * @file device_security_mode.h
 *
 * @brief Defines APIs for Device Security Mode.
 *
 * Allows you to query current device security mode.
 *
 * @kit DeviceSecurityKit
 * @library libdevice_security_mode_ndk.z.so
 * @Syscap SystemCapability.Security.SafetyDetect
 * @since 5.0.1(13)
 */

#ifndef DEVICE_SECURITY_MODE_H
#define DEVICE_SECURITY_MODE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @breif Defines security modes. This enum is a bitmap.
 * @since 5.0.1(13)
 */
typedef enum DSM_DeviceSecurityMode {
    /** Device in normal mode. */
    DSM_NORMAL_MODE = 0,
    /** Device in secure shield mode. */
    DSM_SECURE_SHIELD_MODE = 1
} DSM_DeviceSecurityMode;

/**
 * @brief Query Device Security Mode.
 *
 * This method is used to query device security mode.
 *
 * @return Current device security mode, see {@link DSM_DeviceSecurityMode}.
 * @since 5.0.1(13)
 */
DSM_DeviceSecurityMode HMS_DSM_GetDeviceSecurityMode(void);

#ifdef __cplusplus
}
#endif

/** @} */
#endif // DEVICE_SECURITY_MODE_H