/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

/**
 * @addtogroup AIP
 * @{
 *
 * @brief Provide interfaces for Arkdata Intelligence Platform, including knowledge base capabilities.
 *
 * @since 6.0.0(20)
 */

/**
 * @file aip_error_code.h
 *
 * @brief Provides error code-related interfaces.
 *
 * @library libretrieval_ndk.so
 * @kit DataAugmentationKit
 * @syscap SystemCapability.DataAugmentation.Retrieval
 * @since 6.0.0(20)
 */

#ifndef AIP_ERROR_CODE_H
#define AIP_ERROR_CODE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Define error codes.
 *
 * @since 6.0.0(20)
 */
typedef enum OH_Aip_ErrCode {
    /** @brief Success. */
    AIP_OK = 0,

    /** @brief Execution error. */
    AIP_E_EXEC_ERR = 1021200005,

    /** @brief Index out of bounds. */
    AIP_E_OUT_OF_RANGE = 1021200006,

    /** @brief The field does not exist. */
    AIP_E_NO_SUCH_FIELD = 1021200007,

    /** @brief Array exceeds maximum length. */
    AIP_E_OVER_LIMIT = 1021200008,

    /** @brief The number of conditions exceeds the upper limit. */
    AIP_E_CONDITION_OVER_LIMIT = 1021200009,

    /** @brief The error code for common invalid args. */
    AIP_E_INVALID_ARGS = 1021200010,

    /** @brief Unable to generate embeddings. */
    AIP_E_EMBEDDING_ERR = 1021200012
} OH_Aip_ErrCode;

#ifdef __cplusplus
}
#endif

/** @} */

#endif // AIP_ERROR_CODE_H
