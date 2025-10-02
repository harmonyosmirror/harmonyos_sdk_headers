/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 */

/**
 * @addtogroup HiAIFoundation
 * @{
 *
 * @brief Provides APIs for HiAI Foundation model inference.
 *
 * @syscap SystemCapability.AI.HiAIFoundation
 * @since 4.1.0(11)
 */

/**
 * @file hiai_helper.h
 * @kit HiAIFoundationKit
 * @library libhiai_foundation.so
 *
 * @brief Defines the APIs for querying the HiAI Foundation version and checking the model compatibility.
 *
 * @since 4.1.0(11)
 */
#ifndef HIAI_FOUNDATION_HELPER_H
#define HIAI_FOUNDATION_HELPER_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Obtains the HiAI Foundation version number.
 * @return Returns the HiAI Foundation version number if the operation is successful; returns a null pointer otherwise.
 * @since 4.1.0(11)
 */
const char* HMS_HiAI_GetVersion(void);

/**
 * @brief Model compatibility.
 * @since 4.1.0(11)
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
 */
HiAI_Compatibility HMS_HiAICompatibility_CheckFromFile(const char* file);

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
 */
HiAI_Compatibility HMS_HiAICompatibility_CheckFromBuffer(const void* data, size_t size);

#ifdef __cplusplus
}
#endif

/** @} */
#endif // HIAI_FOUNDATION_HELPER_H
