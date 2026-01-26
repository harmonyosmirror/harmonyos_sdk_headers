/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
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
 * @addtogroup DeviceInfo
 * @{
 *
 * @brief Provides APIs for querying terminal device information.
 *
 * @since 10
 */

/**
 * @file deviceinfo.h
 * @kit BasicServicesKit
 * @brief Declares APIs for querying terminal device information.
 * @library libdeviceinfo_ndk.z.so
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */

#ifndef DEVICEINFO_CSDK_H
#define DEVICEINFO_CSDK_H

#include "info/application_target_sdk_version.h"
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/**
 * Obtains the device type represented by a string,
 * which can be {@code phone} (or {@code default} for phones), {@code wearable}, {@code liteWearable},
 * {@code tablet}, {@code tv}, {@code car}, or {@code smartVision}.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetDeviceType(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the device manufacturer represented by a string.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetManufacture(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the device brand represented by a string.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetBrand(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the product name speaded in the market
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetMarketName(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the product series represented by a string.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetProductSeries(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the product model represented by a string.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetProductModel(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the software model represented by a string.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetSoftwareModel(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the hardware model represented by a string.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetHardwareModel(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the bootloader version number represented by a string.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetBootloaderVersion(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the application binary interface (Abi) list represented by a string.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetAbiList(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the security patch tag represented by a string.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetSecurityPatchTag(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the product version displayed for customer represented by a string.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetDisplayVersion(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the incremental version represented by a string.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetIncrementalVersion(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the OS release type represented by a string.
 *
 * <p>The OS release category can be {@code Release}, {@code Beta}, or {@code Canary}.
 * The specific release type may be {@code Release}, {@code Beta1}, or others alike.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetOsReleaseType(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the OS full version name represented by a string.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetOSFullName(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the SDK API version number.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
int OH_GetSdkApiVersion(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the first API version number.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
int OH_GetFirstApiVersion(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the version ID by a string.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetVersionId(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the build type of the current running OS.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetBuildType(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the build user of the current running OS.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetBuildUser(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the build host of the current running OS.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetBuildHost(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the build time of the current running OS.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetBuildTime(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the version hash of the current running OS.
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetBuildRootHash(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the Distribution OS name represented by a string.
 *
 * <p>Independent Software Vendor (ISV) may distribute OHOS with their own OS name.
 * If ISV not specified, it will return an empty string
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetDistributionOSName(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the ISV distribution OS version represented by a string.
 * If ISV not specified, it will return the same value as OH_GetOSFullName
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetDistributionOSVersion(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the ISV distribution OS api version represented by a integer.
 * If ISV not specified, it will return the same value as OH_GetSdkApiVersion
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
int OH_GetDistributionOSApiVersion(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * Obtains the ISV distribution OS release type represented by a string.
 * If ISV not specified, it will return the same value as OH_GetOsReleaseType
 * @syscap SystemCapability.Startup.SystemInfo
 * @since 10
 */
const char *OH_GetDistributionOSReleaseType(void) __attribute__((__availability__(ohos, introduced=10.0.0)));

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
/** @} */
