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
 * @file aip_retrieval_query.h
 *
 * @brief Provides retrieval query-related interfaces.
 *
 * @library libretrieval_ndk.so
 * @kit DataAugmentationKit
 * @syscap SystemCapability.DataAugmentation.Retrieval
 * @since 6.0.0(20)
 */

#ifndef AIP_RETRIEVAL_QUERY_H
#define AIP_RETRIEVAL_QUERY_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Define the search terms for knowledge retrieval.
 *
 * @since 6.0.0(20)
 */
typedef struct OH_Retrieval_Query OH_Retrieval_Query;

/**
 * @brief Create query terms as input parameters for the retrieval interface.
 *
 * @return Returns a pointer to {@link OH_Retrieval_Query} instance.
 * When the function execution fails, this pointer is a null pointer.
 * @see OH_Retrieval_Query
 * @since 6.0.0(20)
 */
OH_Retrieval_Query *OH_Retrieval_CreateQuery();

/**
 * @brief Destroy OH_Retrieval_Query which is created by OH_Retrieval_CreateQuery.
 *
 * @param query Represents a pointer to {@link OH_Retrieval_Query} instance.
 * @return Returns the status code of the execution.
 *     {@link AIP_OK} - Success.
 *     {@link AIP_E_INVALID_ARGS} - The error code for common invalid args.
 * @see OH_Retrieval_Query, OH_Aip_ErrCode, OH_Retrieval_CreateQuery.
 * @since 6.0.0(20)
 */
int OH_Retrieval_DestroyQuery(OH_Retrieval_Query *query);

/**
 * @brief Set the retrieval query in OH_Retrieval_Query.
 *
 * @param query Represents a pointer to {@link OH_Retrieval_Query} instance.
 * @param question A text query.
 * @return Returns the status code of the execution.
 *     {@link AIP_OK} - Success.
 *     {@link AIP_E_INVALID_ARGS} - The error code for common invalid args.
 *     {@link AIP_E_OVER_LIMIT} - Array exceeds maximum length.
 * @see OH_Retrieval_Query, OH_Aip_ErrCode.
 * @since 6.0.0(20)
 */
int OH_Retrieval_SetOriginalQuestion(OH_Retrieval_Query *query, const char *question);

#ifdef __cplusplus
}
#endif

/** @} */

#endif // AIP_RETRIEVAL_QUERY_H
