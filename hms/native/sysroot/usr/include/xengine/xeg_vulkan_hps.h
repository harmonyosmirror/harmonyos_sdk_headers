/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

/**
 * @addtogroup XEngine
 * @{
 *
 * @brief Provides APIs related to XEngine graphics capabilities.
 *
 * @syscap SystemCapability.Graphic.XEngine
 * @since 6.0.0(20)
 */

/**
 * @file xeg_vulkan_hps.h
 * @kit XEngineKit
 * @library libxengine.so
 *
 * @brief APIs for the High Performance Shaders (HPS) feature of XEngine. Before using the APIs in this header file, you
 * need to call {@link HMS_XEG_EnumerateDeviceExtensionProperties} to check whether the HPS feature extension to be used
 * is supported.
 * @syscap SystemCapability.Graphic.XEngine
 * @since 6.0.0(20)
 */
#ifndef XEG_VULKAN_HPS_H
#define XEG_VULKAN_HPS_H

#include "info/application_target_sdk_version.h"
#include <vulkan/vulkan.h>
#include "xeg_vulkan_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Handle to {@link XEG_HPS}.
 *
 * @since 6.0.0(20)
 */
VK_DEFINE_HANDLE(XEG_HPS)

/**
 * @brief This structure describes the information for creating an {@link XEG_HPS} object.
 *
 * @since 6.0.0(20)
 */
typedef struct XEG_HPSCreateInfo {
    /** Identifies the {@link XEG_StructureType} value of this structure, which must be
     * XEG_STRUCTURE_TYPE_HPS_CREATE_INFO. */
    XEG_StructureType sType;

    /** Pointer to the extension structure. The value cannot be null. It indicates the enabled XEngine HPS extension
     * feature. For example, when the {@link XEG_HPS_RADIX_SORT_EXTENSION_NAME} feature is used, the value must be
     * specified as {@link XEG_HPSRadixSort}. */
    const void *pNext;
} XEG_HPSCreateInfo;

/**
 * @brief This structure describes the HPS radix sort extension structure information.
 *
 * @since 6.0.0(20)
 */
typedef struct XEG_HPSRadixSort {
    /** Identifies the {@link XEG_StructureType} value of this structure, which must be
     * {@link XEG_STRUCTURE_TYPE_HPS_RADIX_SORT}. */
    XEG_StructureType sType;

    /** Pointer to the extension structure. */
    const void *pNext;
} XEG_HPSRadixSort;

/**
 * @brief This structure describes the information required for sorting using the
 * {@link XEG_HPS_RADIX_SORT_EXTENSION_NAME} feature.
 *
 * @since 6.0.0(20)
 */
typedef struct XEG_HPSRadixSortDescription {
    /** Identifies the {@link XEG_StructureType} value of this structure, which must be
     * XEG_STRUCTURE_TYPE_HPS_RADIX_SORT_DESCRIPTION. */
    XEG_StructureType sType;

    /** Pointer to the extension structure. */
    const void *pNext;

    /** Buffer that stores the number of indexes to be sorted. The number value is read from bit 0 of the buffer. */
    VkBuffer sortCount;

    /** Buffer for storing key values used for sorting. The data format is a 32-bit unsigned integer. */
    VkBuffer keyBuffer;

    /** Buffer for storing values to be sorted. The data format is a 32-bit unsigned integer. */
    VkBuffer indexBuffer;
} XEG_HPSRadixSortDescription;

/**
 * @brief Defines the function pointer for creating an {@link XEG_HPS} object.
 *
 * @param device VkDevice that is currently in use.
 * @param pCreateInfo Pointer to the structure containing the information needed for creating an {@link XEG_HPS}
 * instance handle. The value cannot be null.
 * @param pHps Pointer to the HPS instance handle. The created {@link XEG_HPS} is returned in this handle.
 * @return Returns an error code of the VkResult type. VK_SUCCESS indicates successful execution.
 * @since 6.0.0(20)
 */
typedef VkResult(VKAPI_PTR *PFN_HMS_XEG_CreateHPS)(VkDevice device, const XEG_HPSCreateInfo *pCreateInfo,
                                                   XEG_HPS *pHps);

/**
 * @brief Defines the function pointer for destroying an {@link XEG_HPS} object.
 *
 * @param hps {@link XEG_HPS} object to be destroyed.
 * @since 6.0.0(20)
 */
typedef void(VKAPI_PTR *PFN_HMS_XEG_DestroyHPS)(XEG_HPS hps);

/**
 * @brief Defines the function pointer for recording an HPS radix sort command. Before using this API, you need to call
 * {@link HMS_XEG_EnumerateDeviceExtensionProperties} to check whether the {@link XEG_HPS_RADIX_SORT_EXTENSION_NAME}
 * extension is supported.
 *
 * @param commandBuffer Vulkan command buffer object.
 * @param hps Created {@link XEG_HPS} object.
 * @param pDescription Pointer to the input information structure {@link XEG_HPSRadixSortDescription} of the
 * {@link XEG_HPS_RADIX_SORT_EXTENSION_NAME} feature. The value cannot be null.
 * @return Returns an error code of the VkResult type. VK_SUCCESS indicates successful execution.
 * @since 6.0.0(20)
 */
typedef VkResult(VKAPI_PTR *PFN_HMS_XEG_CmdRadixSortHPS)(VkCommandBuffer commandBuffer, XEG_HPS hps,
                                                         const XEG_HPSRadixSortDescription *pDescription);

#ifndef XEG_NO_PROTOTYPES

/**
 * @brief Creates an {@link XEG_HPS} object.
 *
 * @param device VkDevice that is currently in use.
 * @param pCreateInfo Pointer to the structure containing the information needed for creating an {@link XEG_HPS}
 * instance handle. The value cannot be null.
 * @param pHps Pointer to the HPS instance handle. The created {@link XEG_HPS} is returned in this handle.
 * @return Returns an error code of the VkResult type. VK_SUCCESS indicates successful execution.
 * @since 6.0.0(20)
 */
VKAPI_ATTR VkResult VKAPI_CALL HMS_XEG_CreateHPS(
    VkDevice device,
    const XEG_HPSCreateInfo *pCreateInfo,
    XEG_HPS *pHps
)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Destroys an {@link XEG_HPS} object.
 *
 * @param hps {@link XEG_HPS} object to be destroyed.
 * @since 6.0.0(20)
 */
VKAPI_ATTR void VKAPI_CALL HMS_XEG_DestroyHPS(
    XEG_HPS hps
)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Records an HPS radix sort command. Before using this API, you need to call {@link
 * HMS_XEG_EnumerateDeviceExtensionProperties} to check whether the {@link XEG_HPS_RADIX_SORT_EXTENSION_NAME} extension
 * is supported.
 *
 * @param commandBuffer Vulkan command buffer object.
 * @param hps Created {@link XEG_HPS} object.
 * @param pDescription Pointer to the input information structure {@link XEG_HPSRadixSortDescription} of the
 * {@link XEG_HPS_RADIX_SORT_EXTENSION_NAME} feature. The value cannot be null.
 * @return Returns an error code of the VkResult type. VK_SUCCESS indicates successful execution.
 * @since 6.0.0(20)
 */
VKAPI_ATTR VkResult VKAPI_CALL HMS_XEG_CmdRadixSortHPS(
    VkCommandBuffer commandBuffer,
    XEG_HPS hps,
    const XEG_HPSRadixSortDescription *pDescription
)
__attribute__((__availability__(ohos, introduced=20.0.0)));

#endif /* XEG_NO_PROTOTYPES */

#ifdef __cplusplus
}
#endif

#endif // XEG_VULKAN_HPS_H
/** @} */
