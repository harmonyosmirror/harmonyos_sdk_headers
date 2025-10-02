/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

/**
 * @addtogroup XEngine
 * @{
 *
 * @brief Provides graphics APIs of XEngine.
 *
 * @syscap SystemCapability.Graphic.XEngine
 * @since 5.0.0(12)
 */

/**
 * @file xeg_vulkan_extension.h
 * @kit XEngineKit
 * @library libxengine.so
 *
 * @brief (Vulkan) API for querying extensions of XEngine.
 * @syscap SystemCapability.Graphic.XEngine
 * @since 5.0.0(12)
 */

#ifndef XEG_VULKAN_EXTENSION_H
#define XEG_VULKAN_EXTENSION_H

#include <vulkan/vulkan.h>
#include "xeg_extension_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief Maximum length of the extension name supported by XEngine.
*
* @since 5.0.0(12)
*/
#define XEG_MAX_EXTENSION_NAME_SIZE 256

/**
 * @brief This structure describes the set of XEngine extensions queried through the
 * {@link HMS_XEG_EnumerateDeviceExtensionProperties} API.
 *
 * @since 5.0.0(12)
 */
typedef struct XEG_ExtensionProperties {
    /** Extension name supported by XEngine. */
    char extensionName[XEG_MAX_EXTENSION_NAME_SIZE];

    /** Extension version number supported by XEngine. */
    uint32_t version;
} XEG_ExtensionProperties;

/**
* @brief Defines the function pointer of the Vulkan API for querying extensions of XEngine.
*
* @param physicalDevice Current Vulkan physical device.
* @param pPropertyCount Number of queried or passed extensions. If {@link pProperties} is nullptr, the number of
* currently supported XEngine extensions is returned.
* If the passed {@link propertyCount} is greater than or equal to the number of actually supported XEngine extensions,
*    the query information is returned through the {@link pProperties} API and the return result is VK_SUCCESS.
* If the passed {@link propertyCount} is less than the number of actually supported XEngine extensions, the query
*    information is returned through the {@link pProperties} API and the return result is VK_INCOMPLETE.
* @param pProperties Queried XEngine extensions, which are returned through the
* {@link XEG_ExtensionProperties} pointer of the structure.
*
* @return Result code of the VkResult type. If the query is successful, VK_SUCCESS is returned.
* If {@link pProperties} is not nullptr and the passed {@link propertyCount} is less than the number of actually
* supported XEngine extensions, VK_INCOMPLETE is returned, indicating that the queried features are incomplete.
*
* @since 5.0.0(12)
*/
typedef VkResult (VKAPI_PTR *PFN_HMS_XEG_EnumerateDeviceExtensionProperties)(
    VkPhysicalDevice physicalDevice,
    uint32_t* pPropertyCount,
    XEG_ExtensionProperties* pProperties);

#ifndef XEG_NO_PROTOTYPES
/**
* @brief Vulkan API for querying extensions of XEngine.
*
* @param physicalDevice Current Vulkan physical device.
* @param pPropertyCount Number of queried or passed extensions. If {@link pProperties} is nullptr, the number of
* currently supported XEngine extensions is returned.
* If the passed {@link propertyCount} is greater than or equal to the number of actually supported XEngine extensions,
*    the query information is returned through the {@link pProperties} API and the return result is VK_SUCCESS.
* If the passed {@link propertyCount} is less than the number of actually supported XEngine extensions, the query
*    information is returned through the {@link pProperties} API and the return result is VK_INCOMPLETE.
* @param pProperties Queried XEngine extensions, which are returned through the
* {@link XEG_ExtensionProperties} pointer of the structure.
*
* @return Result code of the VkResult type. If the query is successful, VK_SUCCESS is returned.
* If {@link pProperties} is not nullptr and the passed {@link propertyCount} is less than the number of actually
* supported XEngine extensions, VK_INCOMPLETE is returned, indicating that the queried features are incomplete.
*
* @since 5.0.0(12)
*/
VKAPI_ATTR VkResult VKAPI_CALL HMS_XEG_EnumerateDeviceExtensionProperties(
    VkPhysicalDevice physicalDevice,
    uint32_t* pPropertyCount,
    XEG_ExtensionProperties* pProperties);

#endif /* XEG_NO_PROTOTYPES */

#ifdef __cplusplus
}
#endif
/** @} */
#endif // XEG_VULKAN_EXTENSION_H