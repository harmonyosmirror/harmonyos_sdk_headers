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
 * @file aip_retrieval.h
 *
 * @brief Provides knowledge retrieval-related interfaces.
 *
 * @library libnative_aip_retrieval_ndk.so
 * @kit DataAugmentationKit
 * @syscap SystemCapability.DataAugmentation.Retrieval
 * @since 6.0.0(20)
 */

#ifndef AIP_RETRIEVAL_H
#define AIP_RETRIEVAL_H

#include "dataaugmentation/retrieval/aip_retrieval_condition.h"
#include "dataaugmentation/retrieval/aip_retrieval_query.h"
#include "dataaugmentation/retrieval/aip_retrieval_record.h"
#include "database/rdb/relational_store.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Define the retriever type,
 * where a retriever is a handler that performs retrieval operations.
 *
 * @since 6.0.0(20)
 */
typedef struct OH_Retrieval_Retriever OH_Retrieval_Retriever;

/**
 * @brief Define retriever configurations.
 *
 * @since 6.0.0(20)
 */
typedef struct OH_Retrieval_Config OH_Retrieval_Config;

/**
 * @brief Create a retriever based on the retrieval configuration.
 *
 * @param config Represents a pointer to {@link OH_Retrieval_Config} instance.
 * Indicates the configuration of the retriever.
 * @param retriever Returns a pointer to {@link OH_Retrieval_Retriever} instance.
 * @return Returns the status code of the execution.
 *     {@link AIP_OK} - Success.
 *     {@link AIP_E_INVALID_ARGS} - The error code for common invalid args.
 * @see OH_Retrieval_Retriever, OH_Retrieval_Config, OH_Aip_ErrCode.
 * @since 6.0.0(20)
 */
int OH_Retrieval_CreateRetriever(const OH_Retrieval_Config *config, OH_Retrieval_Retriever **retriever);

/**
 * @brief Destroy OH_Retrieval_Retriever which is created by OH_Retrieval_CreateRetriever.
 *
 * @param retriever Represents a pointer to {@link OH_Retrieval_Retriever} instance.
 * @return Returns the status code of the execution.
 *     {@link AIP_OK} - Success.
 *     {@link AIP_E_INVALID_ARGS} - The error code for common invalid args.
 * @see OH_Retrieval_Retriever, OH_Aip_ErrCode, OH_Retrieval_CreateRetriever.
 * @since 6.0.0(20)
 */
int OH_Retrieval_DestroyRetriever(OH_Retrieval_Retriever *retriever);

/**
 * @brief Create a configuration item to initialize the retriever.
 *
 * @return Returns a pointer to {@link OH_Retrieval_Config} instance.
 * When the function execution fails, this pointer is a null pointer.
 * @see OH_Retrieval_Config, OH_Aip_ErrCode.
 * @since 6.0.0(20)
 */
OH_Retrieval_Config *OH_Retrieval_CreateConfig();

/**
 * @brief Destroy OH_Retrieval_Config which is created by OH_Retrieval_CreateConfig.
 *
 * @param config Represents a pointer to {@link OH_Retrieval_Config} instance.
 * @return Returns the status code of the execution.
 *     {@link AIP_OK} - Success.
 *     {@link AIP_E_INVALID_ARGS} - The error code for common invalid args.
 * @see OH_Retrieval_Config, OH_Aip_ErrCode, OH_Retrieval_CreateConfig.
 * @since 6.0.0(20)
 */
int OH_Retrieval_DestroyConfig(OH_Retrieval_Config *config);

/**
 * @brief Define a database configuration which is used to open a database store.
 *
 * @since 6.0.0(20)
 */
typedef struct OH_Retrieval_DbConfig OH_Retrieval_DbConfig;

/**
 * @brief Create a configuration item to open a database.
 *
 * @return Returns a pointer to {@link OH_Retrieval_DbConfig} instance.
 * When the function execution fails, this pointer is a null pointer.
 * @see OH_Retrieval_DbConfig, OH_Aip_ErrCode.
 * @since 6.0.0(20)
 */
OH_Retrieval_DbConfig *OH_Retrieval_CreateDbConfig();

/**
 * @brief Destroy OH_Retrieval_DbConfig which is created by OH_Retrieval_CreateDbConfig.
 *
 * @param dbConfig Represents a pointer to {@link OH_Retrieval_DbConfig} instance.
 * @return Returns the status code of the execution.
 *     {@link AIP_OK} - Success.
 *     {@link AIP_E_INVALID_ARGS} - The error code for common invalid args.
 * @see OH_Retrieval_DbConfig, OH_Aip_ErrCode, OH_Retrieval_CreateDbConfig.
 * @since 6.0.0(20)
 */
int OH_Retrieval_DestroyDbConfig(OH_Retrieval_DbConfig *dbConfig);

/**
 * @brief Set the database configuration in OH_Retrieval_DbConfig.
 *
 * @param dbConfig Represents a pointer to {@link OH_Retrieval_DbConfig} instance.
 * @param rdbConfig Represents a pointer to a database configuration instance,
 * could be {@link OH_Rdb_ConfigV2} instance.
 * @return Returns the status code of the execution.
 *     {@link AIP_OK} - Success.
 *     {@link AIP_E_INVALID_ARGS} - The error code for common invalid args.
 * @see OH_Retrieval_DbConfig, OH_Rdb_ConfigV2, OH_Aip_ErrCode.
 * @since 6.0.0(20)
 */
int OH_Retrieval_SetDbConfig(OH_Retrieval_DbConfig *dbConfig, OH_Rdb_ConfigV2 *rdbConfig);

/**
 * @brief Define the data index type, which currently only includes vector index data.
 *
 * @since 6.0.0(20)
 */
typedef enum Retrieval_Channel_Type {
    /** @brief Represent a vector index. */
    RETRIEVAL_TYPE_VECTOR = 1,
} Retrieval_Channel_Type;

/**
 * @brief Add a database configuration into OH_Retrieval_Config.
 *
 * @param config Represents a pointer to {@link OH_Retrieval_Config} instance.
 * @param channelType Represents the data index type.
 * @param dbConfig Represents a pointer to {@link OH_Retrieval_DbConfig} instance.
 * @return Returns the status code of the execution.
 *     {@link AIP_OK} - Success.
 *     {@link AIP_E_INVALID_ARGS} - The error code for common invalid args.
 * @see OH_Retrieval_Config, Retrieval_Channel_Type, OH_Retrieval_DbConfig, OH_Aip_ErrCode.
 * @since 6.0.0(20)
 */
int OH_Retrieval_AddConfig(OH_Retrieval_Config *config, Retrieval_Channel_Type channelType,
    OH_Retrieval_DbConfig *dbConfig);

/**
 * @brief The callback function of retrieval result record.
 *
 * @param context Represents user-provided data context, which will be passed back into the function when invoked.
 * @param record Represents a pointer to {@link OH_Retrieval_Record} instance.
 * @param errCode The error code of {@link OH_Retrieval_Retrieve}.
 * @see OH_Retrieval_Record, OH_Aip_ErrCode, OH_Retrieval_Retrieve
 * @since 6.0.0(20)
 */
typedef void (*OH_Retrieval_Callback)(void *context, OH_Retrieval_Record *record, int errCode);

/**
 * @brief Executes a search. After obtaining the retriever handle,
 * input the search query and execute the search based on the specified conditions to retrieve results.
 *
 * @param retriever Represents a pointer to {@link OH_Retrieval_Retriever} instance.
 * @param query Represents a pointer to {@link OH_Retrieval_Query} instance.
 * @param condition Represents a pointer to {@link OH_Retrieval_Condition} instance.
 * @param context Represents user-provided data context, which will be passed back into the function when invoked later.
 * @param callback Represents a pointer to {@link OH_Retrieval_Callback} instance.
 * @return Returns the status code of the execution.
 *     {@link AIP_OK} - Success.
 *     {@link AIP_E_INVALID_ARGS} - The error code for common invalid args.
 * @see OH_Retrieval_Retriever, OH_Retrieval_Query, OH_Retrieval_Condition, OH_Retrieval_Callback, OH_Aip_ErrCode
 * @since 6.0.0(20)
 */
int OH_Retrieval_Retrieve(const OH_Retrieval_Retriever *retriever, const OH_Retrieval_Query *query,
    const OH_Retrieval_Condition *condition, void *context, const OH_Retrieval_Callback *callback);

#ifdef __cplusplus
}
#endif

/** @} */

#endif // AIP_RETRIEVAL_H
