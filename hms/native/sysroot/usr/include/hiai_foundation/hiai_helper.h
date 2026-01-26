/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 */

/**
 * @addtogroup HiAIFoundation
 * @{
 *
 * @brief Provides APIs for HiAI Foundation model inference.
 *
 * @since 4.1.0(11)
 * @deprecated since 18
 * @useinstead {@link CANNKit/hiai_helper.h}
 */

/**
 * @file hiai_helper.h
 *
 * @brief Defines the APIs for querying the HiAI Foundation version and checking the model compatibility.
 *
 * @library libhiai_foundation.so
 * @syscap SystemCapability.AI.HiAIFoundation
 * @kit HiAIFoundationKit
 * @since 4.1.0(11)
 * @deprecated since 18
 * @useinstead {@link CANNKit/hiai_helper.h}
 */
#ifndef HIAI_FOUNDATION_HELPER_H
#define HIAI_FOUNDATION_HELPER_H

#include "info/application_target_sdk_version.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Obtains the HiAI Foundation version number.
 * @return Returns the HiAI Foundation version number if the operation is successful; returns a null pointer otherwise.
 * @since 4.1.0(11)
 * @deprecated since 18
 * @useinstead {@link CANNKit/HMS_HiAI_GetVersion}
 */
const char* HMS_HiAI_GetVersion(void) __attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Model compatibility.
 * @since 4.1.0(11)
 * @deprecated since 18
 * @useinstead {@link CANNKit/HiAI_Compatibility}
 */
typedef enum {
    /** Model compatible */
    HIAI_COMPATIBILITY_COMPATIBLE = 0,
    /** Model incompatible */
    HIAI_COMPATIBILITY_INCOMPATIBLE = 1
} HiAI_Compatibility;

/**
 * @brief Queries the compatibility of the model stored in the file.
 *
 * @param file Path and name of the model file. The value cannot be empty, and the process must have the permission
 * to access the model file. Otherwise, a message is returned indicating that the model is incompatible.
 * @return Returns {@link HiAI_Compatibility} if the operation is successful; returns a message indicating that the
 * model is incompatible otherwise.
 * @since 4.1.0(11)
 * @deprecated since 18
 * @useinstead {@link CANNKit/HMS_HiAICompatibility_CheckFromFile}
 */
HiAI_Compatibility HMS_HiAICompatibility_CheckFromFile(const char* file)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Queries the compatibility of the model stored in the memory.
 *
 * @param data Model data address. The value cannot be null. Otherwise, a message indicating that the model is
 * incompatible is returned.
 * @param size Model data size. The value cannot be null. Otherwise, a message indicating that the model is
 * incompatible is returned.
 * @return Returns {@link HiAI_Compatibility} if the operation is successful; returns a message indicating that the
 * model is incompatible otherwise.
 * @since 4.1.0(11)
 * @deprecated since 18
 * @useinstead {@link CANNKit/HMS_HiAICompatibility_CheckFromBuffer}
 */
HiAI_Compatibility HMS_HiAICompatibility_CheckFromBuffer(const void* data, size_t size)
__attribute__((__availability__(ohos, introduced=11.0.0)));

#ifdef __cplusplus
}
#endif

/** @} */
#endif // HIAI_FOUNDATION_HELPER_H
