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
 * @file aip_retrieval_condition.h
 *
 * @brief Provides retrieval condition-related interfaces.
 *
 * @library libnative_aip_retrieval_ndk.so
 * @kit DataAugmentationKit
 * @syscap SystemCapability.DataAugmentation.Retrieval
 * @since 6.0.0(20)
 */

#ifndef AIP_RETRIEVAL_CONDITION_H
#define AIP_RETRIEVAL_CONDITION_H

#include "info/application_target_sdk_version.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Define a retrieval condition, which may include multiple subconditions.
 *
 * @since 6.0.0(20)
 */
typedef struct OH_Retrieval_Condition OH_Retrieval_Condition;

/**
 * @brief Define a subcondition, which can be a vector retrieval (operation).
 *
 * @since 6.0.0(20)
 */
typedef struct OH_Retrieval_SubCondition OH_Retrieval_SubCondition;

/**
 * @brief Create a retrieval condition to serve as the input parameter for the search API.
 *
 * @return Returns a pointer to {@link OH_Retrieval_Condition} instance.
 * When the function execution fails, this pointer is a null pointer.
 * @see OH_Retrieval_Condition
 * @since 6.0.0(20)
 */
OH_Retrieval_Condition *OH_Retrieval_CreateCondition() __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Destroy OH_Retrieval_Condition which is created by OH_Retrieval_CreateCondition.
 *
 * @param condition Represents a pointer to {@link OH_Retrieval_Condition} instance.
 * @return Returns the status code of the execution.
 *     {@link AIP_OK} - Success.
 *     {@link AIP_E_INVALID_ARGS} - The error code for common invalid args.
 * @see OH_Retrieval_Condition, OH_Aip_ErrCode, OH_Retrieval_CreateCondition.
 * @since 6.0.0(20)
 */
int OH_Retrieval_DestroyCondition(OH_Retrieval_Condition *condition)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Destroy OH_Retrieval_SubCondition.
 *
 * @param condition Represents a pointer to {@link OH_Retrieval_SubCondition} instance.
 * @return Returns the status code of the execution.
 *     {@link AIP_OK} - Success.
 *     {@link AIP_E_INVALID_ARGS} - The error code for common invalid args.
 * @see OH_Retrieval_SubCondition, OH_Aip_ErrCode.
 * @since 6.0.0(20)
 */
int OH_Retrieval_DestroySubCondition(OH_Retrieval_SubCondition *condition)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Add a subcondition to the retrieval condition.
 *
 * @param condition Represents a pointer to {@link OH_Retrieval_Condition} instance.
 * @param subCondition Represents a pointer to {@link OH_Retrieval_SubCondition} instance,
 * could be {@link OH_Retrieval_VectorCondition} instance.
 * @return Returns the status code of the execution.
 *     {@link AIP_OK} - Success.
 *     {@link AIP_E_INVALID_ARGS} - The error code for common invalid args.
 *     {@link AIP_E_CONDITION_OVER_LIMIT} - The number of conditions exceeds the upper limit.
 * @see OH_Retrieval_Condition, OH_Retrieval_SubCondition, OH_Retrieval_VectorCondition, OH_Aip_ErrCode.
 * @since 6.0.0(20)
 */
int OH_Retrieval_AddSubCondition(OH_Retrieval_Condition *condition, OH_Retrieval_SubCondition *subCondition)
__attribute__((__availability__(ohos, introduced=20.0.0)));

#ifdef __cplusplus
}
#endif

/** @} */

#endif // AIP_RETRIEVAL_CONDITION_H
