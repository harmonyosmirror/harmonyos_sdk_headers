/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
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
 * @addtogroup Native_Bundle
 * @{
 *
 * @brief Describes the Native Bundle.
 *
 * @since 9
 * @version 1.0
 */

/**
 * @file native_interface_bundle.h
 *
 * @brief Declares the <b>Bundle</b>-specific function, including function for obtaining application info.
 *
 * @kit AbilityKit
 * @library libbundle_ndk.z.so
 * @syscap SystemCapability.BundleManager.BundleFramework.Core
 * @since 9
 * @version 1.0
 */
#ifndef FOUNDATION_APPEXECFWK_STANDARD_KITS_APPKIT_NATIVE_BUNDLE_INCLUDE_NATIVE_INTERFACE_BUNDLE_H
#define FOUNDATION_APPEXECFWK_STANDARD_KITS_APPKIT_NATIVE_BUNDLE_INCLUDE_NATIVE_INTERFACE_BUNDLE_H

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief Indicates information of application
 *
 * @syscap SystemCapability.BundleManager.BundleFramework.Core
 * @since 9
 */
struct OH_NativeBundle_ApplicationInfo {
    /**
     * Indicates the name of application
     * @syscap SystemCapability.BundleManager.BundleFramework.Core
     * @since 9
     */
    char* bundleName;

    /**
     * Indicates the fingerprint of application
     * @syscap SystemCapability.BundleManager.BundleFramework.Core
     * @since 9
     */
    char* fingerprint;
};

/**
 * @brief Indicates information of elementName.
 *
 * @since 13
 */
struct OH_NativeBundle_ElementName {
    /** Indicates the name of application. */
    char* bundleName;
    /** Indicates the name of module. */
    char* moduleName;
    /** Indicates the name of ability. */
    char* abilityName;
};

/**
 * @brief Indicates information of metadata.
 *
 * @since 20
 */
typedef struct OH_NativeBundle_Metadata {
    /**
     * @brief Indicates the metadata name.
     */
    char* name;
    /**
     * @brief Indicates the metadata value.
     */
    char* value;
    /**
     * @brief Indicates the metadata resource.
     */
    char* resource;
} OH_NativeBundle_Metadata;

/**
 * @brief Indicates information of module metadata.
 *
 * @since 20
 */
typedef struct OH_NativeBundle_ModuleMetadata {
    /**
     * @brief Indicates the moduleName of module.
     */
    char* moduleName;
    /**
     * @brief Indicates the metadata array of module.
     */
    OH_NativeBundle_Metadata* metadataArray;
    /**
     * @brief Indicates the metadata array size of module.
     */
    size_t metadataArraySize;
} OH_NativeBundle_ModuleMetadata;

/**
 * @brief Indicates information of application
 *
 * @since 11
 * @version 1.0
 */
typedef struct OH_NativeBundle_ApplicationInfo OH_NativeBundle_ApplicationInfo;

/**
 * @brief Indicates information of elementName
 *
 * @since 13
 * @version 1.0
 */
typedef struct OH_NativeBundle_ElementName OH_NativeBundle_ElementName;

/**
 * @brief Obtains the application info based on the The current bundle.
 *
 * @return Returns the newly created OH_NativeBundle_ApplicationInfo object, if the returned object is NULL,
 * it indicates creation failure. The possible cause of failure could be that the application address space is full,
 * leading to space allocation failure.
 * @since 9
 * @version 1.0
 */
OH_NativeBundle_ApplicationInfo OH_NativeBundle_GetCurrentApplicationInfo();

/**
 * @brief Obtains the appId of application. AppId indicates the ID of the application to which this bundle belongs
 * The application ID uniquely identifies an application. It is determined by the bundle name and signature.
 * After utilizing this interface, to prevent memory leaks,
 * it is necessary to manually release the pointer returned by the interface.
 *
 * @return Returns the newly created string that indicates appId information,
 * if the returned object is NULL, it indicates creation failure.
 * The possible cause of failure could be that the application address space is full,
 * leading to space allocation failure.
 * @since 11
 * @version 1.0
 */
char* OH_NativeBundle_GetAppId();

/**
 * @brief Obtains the appIdentifier of application. AppIdentifier does not change along the application lifecycle,
 * including version updates, certificate changes, public and private key changes, and application transfer.
 * After utilizing this interface, to prevent memory leaks,
 * it is necessary to manually release the pointer returned by the interface.
 *
 * @return Returns the newly created string that indicates app identifier information,
 * if the returned object is NULL, it indicates creation failure.
 * The possible cause of failure could be that the application address space is full,
 * leading to space allocation failure.
 * @since 11
 * @version 1.0
 */
char* OH_NativeBundle_GetAppIdentifier();

/**
* @brief Obtains information of the entry mainElement based on the current application, including bundle name,
 * module name, and ability name.
 * After utilizing this interface, to prevent memory leaks,
 * it is necessary to manually release the pointer returned by the interface.
 *
 * @return Returns the newly created OH_NativeBundle_ElementName object, if the returned object is NULL,
 * it indicates creation failure. The possible cause of failure could be that the application address space is full,
 * leading to space allocation failure.
 * @since 13
 */
OH_NativeBundle_ElementName OH_NativeBundle_GetMainElementName();

/**
 * @brief Obtains the compatible device type of the current application.
 * After utilizing this interface, to prevent memory leaks,
 * it is necessary to manually release the pointer returned by the interface.
 *
 * @return Returns the newly created string that indicates the compatible device type,
 * if the returned object is NULL, it indicates creation failure.
 * The possible cause of failure could be that the application address space is full,
 * leading to space allocation failure.
 * @since 14
 * @version 1.0
 */
char* OH_NativeBundle_GetCompatibleDeviceType();

/**
 * @brief Obtains the application debug mode.
 *
 * @param isDebugMode Indicates whether the application is in debug mode.
 * @return Returns true if call successful, false otherwise.
 * @since 20
 */
bool OH_NativeBundle_IsDebugMode(bool* isDebugMode);

/**
 * @brief Obtains the module metadata array of the current application.
 * After utilizing this interface, to prevent memory leaks,
 * it is necessary to manually release the pointer returned by the interface.
 *
 * @param size Indicates the module metadata array size.
 * @return Returns the newly created module metadata array, if the returned object is NULL,
 * it indicates creation failure. The possible cause of failure could be that the application address space is full,
 * leading to space allocation failure.
 * @since 20
 */
OH_NativeBundle_ModuleMetadata* OH_NativeBundle_GetModuleMetadata(size_t* size);
#ifdef __cplusplus
};
#endif
/** @} */
#endif // FOUNDATION_APPEXECFWK_STANDARD_KITS_APPKIT_NATIVE_BUNDLE_INCLUDE_NATIVE_INTERFACE_BUNDLE_H
