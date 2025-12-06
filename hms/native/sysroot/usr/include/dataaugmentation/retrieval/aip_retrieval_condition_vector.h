/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

/**
 * @addtogroup Retrieval
 * @{
 *
 * @brief This module enables retrieval from the knowledge base.
 *
 * @since 6.0.0(20)
 */

/**
 * @file aip_retrieval_condition_vector.h
 *
 * @brief Provides vector condition-related interfaces.
 *
 * @library libnative_aip_retrieval_ndk.so
 * @kit DataAugmentationKit
 * @syscap SystemCapability.DataAugmentation.Retrieval
 * @since 6.0.0(20)
 */

#ifndef AIP_RETRIEVAL_CONDITION_VECTOR_H
#define AIP_RETRIEVAL_CONDITION_VECTOR_H

#include <stdint.h>

#include "dataaugmentation/retrieval/aip_retrieval_condition.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Define a vector retrieval condition, including retrieval parameters.
 *
 * @since 6.0.0(20)
 */
typedef struct OH_Retrieval_SubCondition OH_Retrieval_VectorCondition;

/**
 * @brief Create a vector retrieval condition.
 *
 * @return Returns a pointer to {@link OH_Retrieval_VectorCondition} instance.
 * When the function execution fails, this pointer is a null pointer.
 * @see OH_Retrieval_VectorCondition
 * @since 6.0.0(20)
 */
OH_Retrieval_VectorCondition *OH_Retrieval_CreateVectorCondition();

/**
 * @brief Destroy OH_Retrieval_VectorCondition which is created by OH_Retrieval_CreateVectorCondition.
 *
 * @param condition Represents a pointer to {@link OH_Retrieval_VectorCondition} instance.
 * @return Returns the status code of the execution.
 *     {@link AIP_OK} - Success.
 *     {@link AIP_E_INVALID_ARGS} - The error code for common invalid args.
 * @see OH_Retrieval_VectorCondition, OH_Aip_ErrCode, OH_Retrieval_CreateVectorCondition.
 * @since 6.0.0(20)
 */
int OH_Retrieval_DestroyVectorCondition(OH_Retrieval_VectorCondition *condition);

/**
 * @brief Set the maximum number of retrieved results in the vector retrieval condition.
 *
 * @param condition Represents a pointer to {@link OH_Retrieval_VectorCondition} instance.
 * @param limit The number of vector retrieved results, the maximum is 1000.
 * @return Returns the status code of the execution.
 *     {@link AIP_OK} - Success.
 *     {@link AIP_E_INVALID_ARGS} - The error code for common invalid args.
 * @see OH_Retrieval_VectorCondition, OH_Aip_ErrCode.
 * @since 6.0.0(20)
 */
int OH_Retrieval_SetVectorRecallLimit(OH_Retrieval_VectorCondition *condition, uint32_t limit);

/**
 * @brief Set the similarity threshold for vector retrieval in the retrieval condition.
 *
 * @param condition Represents a pointer to {@link OH_Retrieval_VectorCondition} instance.
 * @param threshold The cosine similarity threshold for vector retrieval,
 * which must be within the range [0, 1].
 * @return Returns the status code of the execution.
 *     {@link AIP_OK} - Success.
 *     {@link AIP_E_INVALID_ARGS} - The error code for common invalid args.
 * @see OH_Retrieval_VectorCondition, OH_Aip_ErrCode.
 * @since 6.0.0(20)
 */
int OH_Retrieval_SetSimilarityThreshold(OH_Retrieval_VectorCondition *condition, double threshold);

#ifdef __cplusplus
}
#endif

/** @} */

#endif // AIP_RETRIEVAL_CONDITION_VECTOR_H
