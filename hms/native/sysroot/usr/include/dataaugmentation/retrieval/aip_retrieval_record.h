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
 * @file aip_retrieval_record.h
 *
 * @brief Provides retrieval result-related interfaces.
 *
 * @library libretrieval_ndk.so
 * @kit DataAugmentationKit
 * @syscap SystemCapability.DataAugmentation.Retrieval
 * @since 6.0.0(20)
 */

#ifndef AIP_RETRIEVAL_RECORD_H
#define AIP_RETRIEVAL_RECORD_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Define the retrieval result,
 * which includes fields and their values obtained from the knowledge base retrieval.
 *
 * @since 6.0.0(20)
 */
typedef struct OH_Retrieval_Record OH_Retrieval_Record;

/**
 * @brief Define the database bucket array in the retrieval result.
 *
 * @since 6.0.0(20)
 */
typedef struct OH_Retrieval_RecordItem OH_Retrieval_RecordItem;

/**
 * @brief Destroy OH_Retrieval_Record which is obtained by OH_Retriever_Retrieve.
 *
 * @param record Represents a pointer to {@link OH_Retrieval_Record} instance.
 *
 * @return Returns the status code of the execution.
 *     {@link AIP_OK} - Success.
 *     {@link AIP_E_INVALID_ARGS} - The error code for common invalid args.
 * @see OH_Retrieval_Record, OH_Aip_ErrCode, OH_Retriever_Retrieve.
 * @since 6.0.0(20)
 */
int OH_Retrieval_DestroyRecord(OH_Retrieval_Record *record);

/**
 * @brief Get length of the retrieval result {@link OH_Retrieval_Record}.
 *
 * @param record Represents a pointer to {@link OH_Retrieval_Record} instance.
 * @param length Length of the retrieval result.
 * @return Returns the status code of the execution.
 *     {@link AIP_OK} - Success.
 *     {@link AIP_E_INVALID_ARGS} - The error code for common invalid args.
 * @see OH_Retrieval_Record, OH_Aip_ErrCode.
 * @since 6.0.0(20)
 */
int OH_Retrieval_GetRecordLength(const OH_Retrieval_Record *record, uint32_t *length);

/**
 * @brief Get the database bucket array from the retrieval result {@link OH_Retrieval_Record}.
 *
 * @param record Represents a pointer to {@link OH_Retrieval_Record} instance.
 * @param index Index of a single item in the record.The maximum is 999.
 * @param item A pointer to a single item {@link OH_Retrieval_RecordItem} in the record.
 * @return Returns the status code of the execution.
 *     {@link AIP_OK} - Success.
 *     {@link AIP_E_INVALID_ARGS} - The error code for common invalid args.
 *     {@link AIP_E_OUT_OF_RANGE} - Index out of bounds.
 * @see OH_Retrieval_Record, OH_Retrieval_RecordItem, OH_Aip_ErrCode.
 * @since 6.0.0(20)
 */
int OH_Retrieval_GetRecordItem(const OH_Retrieval_Record *record, uint32_t index,
    const OH_Retrieval_RecordItem **item);

/**
 * @brief Get the size of the value for a specified field in the database bucket array {@link OH_Retrieval_RecordItem}.
 * The size includes the terminator.
 *
 * @param items Represents a pointer to {@link OH_Retrieval_RecordItem} instance.
 * @param fieldName Field name of the database bucket.
 * @param size Size of the corresponding field's value in the database bucket.
 * @return Returns the status code of the execution.
 *     {@link AIP_OK} - Success.
 *     {@link AIP_E_INVALID_ARGS} - The error code for common invalid args.
 *     {@link AIP_E_NO_SUCH_FIELD} - The field does not exist.
 * @see OH_Retrieval_RecordItem, OH_Aip_ErrCode.
 * @since 6.0.0(20)
 */
int OH_Retrieval_GetItemSize(const OH_Retrieval_RecordItem *items, const char *fieldName, size_t *size);

/**
 * @brief Get the value of a specified field in the database bucket array {@link OH_Retrieval_RecordItem}.
 *
 * @param items Represents a pointer to {@link OH_Retrieval_RecordItem} instance.
 * @param fieldName Field name of the database bucket.
 * @param value The output value of the corresponding field in the database bucket.
 * @param size Size of the corresponding field's value in the database bucket.
 * @return Returns the status code of the execution.
 *     {@link AIP_OK} - Success.
 *     {@link AIP_E_INVALID_ARGS} - The error code for common invalid args.
 *     {@link AIP_E_NO_SUCH_FIELD} - The field does not exist.
 * @see OH_Retrieval_RecordItem, OH_Aip_ErrCode.
 * @since 6.0.0(20)
 */
int OH_Retrieval_GetItemText(const OH_Retrieval_RecordItem *items, const char *fieldName, char *value, size_t size);

#ifdef __cplusplus
}
#endif

/** @} */

#endif // AIP_RETRIEVAL_RECORD_H
