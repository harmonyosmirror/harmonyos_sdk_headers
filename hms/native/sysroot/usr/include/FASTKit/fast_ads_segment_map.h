
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

/**
 * @file fast_ads_segment_map.h
 *
 * @brief A segment map data structure for range queries and updates.
 *
 * @library libfast_ads.so
 * @kit FASTKit
 * @syscap SystemCapability.FAST.Core
 * @since 6.0.2(22)
 */

/**
 * @addtogroup FAST
 * @{
 *
 * @brief Provide acceleration capabilities to optimize metrics
 *        such as application startup, loading, and response latency.
 *
 * @since 6.0.2(22)
 */
#ifndef FAST_ADS_SEGMENT_MAP_H
#define FAST_ADS_SEGMENT_MAP_H
#include "info/application_target_sdk_version.h"
#include "fast_common_def.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Query operation types supported by the segment map.
 *
 * @since 6.0.2(22)
 */
typedef enum FAST_SegmentMapQueryType {
    /** Range sum query */
    FAST_SEGMENTMAP_QUERY_TYPE_SUM = 0,

    /** Range minimum query */
    FAST_SEGMENTMAP_QUERY_TYPE_MIN = 1,

    /** Range maximum query */
    FAST_SEGMENTMAP_QUERY_TYPE_MAX = 2
} FAST_SegmentMapQueryType;

/**
 * @brief Update operation types supported by the segment map.
 *
 * @since 6.0.2(22)
 */
typedef enum FAST_SegmentMapUpdateType {
    /** Assign a value to a range (set) */
    FAST_SEGMENTMAP_UPDATE_TYPE_SET = 0,

    /** Add a value to a range */
    FAST_SEGMENTMAP_UPDATE_TYPE_ADD = 1,

    /** Subtract a value from a range */
    FAST_SEGMENTMAP_UPDATE_TYPE_SUB = 2
} FAST_SegmentMapUpdateType;

/**
 * @brief Opaque configuration structure for the segment map.
 *
 * @since 6.0.2(22)
 */
typedef struct FAST_SegmentMapConfig FAST_SegmentMapConfig;

/**
 * @brief Opaque handle to a segment map instance.
 *
 * @since 6.0.2(22)
 */
typedef void* FAST_SegmentMapHandle;

/**
 * @brief Creates a configuration object for the segment map.
 *
 * @param config Pointer to the created {@link FAST_SegmentMapConfig}.
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success.
 *         {@link FAST_ERROR_CODE_INVALID_PTR} {@p config} is NULL.
 *         {@link FAST_ERROR_CODE_OOM} Out of memory.
 *
 * @since 6.0.2(22)
 */
FAST_EXPORT FAST_ErrorCode HMS_FAST_SegmentMap_CreateConfig(FAST_SegmentMapConfig** config)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Destroys a segment map configuration object.
 *
 * @param config The {@link FAST_SegmentMapConfig} to destroy.
 * @return NA
 *
 * @since 6.0.2(22)
 */
FAST_EXPORT void HMS_FAST_SegmentMap_DestroyConfig(FAST_SegmentMapConfig* config)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Sets the query type in the configuration.
 *
 * @param config The configuration to modify.
 * @param type The desired query type.
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success.
 *         {@link FAST_ERROR_CODE_INVALID_PTR} {@p config} is NULL.
 *
 * @since 6.0.2(22)
 */
FAST_EXPORT FAST_ErrorCode HMS_FAST_SegmentMap_SetQueryType(FAST_SegmentMapConfig* config,
    FAST_SegmentMapQueryType type)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Sets the update type in the configuration.
 *
 * @param config The configuration to modify.
 * @param type The desired update type.
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success.
 *         {@link FAST_ERROR_CODE_INVALID_PTR} {@p config} is NULL.
 *
 * @since 6.0.2(22)
 */
FAST_EXPORT FAST_ErrorCode HMS_FAST_SegmentMap_SetUpdateType(FAST_SegmentMapConfig* config,
    FAST_SegmentMapUpdateType type)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Creates a segment map instance.
 *
 * @param handle Pointer to the created {@link FAST_SegmentMapHandle}.
 * @param size Size of the segment map (number of elements).
 * @param array Optional initial values; if NULL, the map is initialized to zero.
 * @param config Configuration for query/update behavior.
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success.
 *         {@link FAST_ERROR_CODE_INVALID_PTR} {@p handle} or {@p config} is NULL.
 *         {@link FAST_ERROR_CODE_OOM} Out of memory.
 *
 * @note 1. If {@p config} is not configured, the default behavior is:
 *          - Query type: {@link FAST_SEGMENTMAP_QUERY_TYPE_SUM}
 *          - Update type: {@link FAST_SEGMENTMAP_UPDATE_TYPE_SET}
 *        2. The {@p array} parameter is optional. If provided, it must contain {@p size} elements.
 *
 * @since 6.0.2(22)
 */
FAST_EXPORT FAST_ErrorCode HMS_FAST_SegmentMap_Create(FAST_SegmentMapHandle* handle,
    size_t size, const int32_t* array, FAST_SegmentMapConfig* config)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Destroys a segment map instance.
 *
 * @param handle The {@link FAST_SegmentMapHandle} to destroy.
 * @return NA
 *
 * @since 6.0.2(22)
 */
FAST_EXPORT void HMS_FAST_SegmentMap_Destroy(FAST_SegmentMapHandle handle)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Updates a range in the segment map.
 *
 * @param handle The segment map handle.
 * @param left Left boundary of the range (inclusive).
 * @param right Right boundary of the range (exclusive).
 * @param value Value to apply based on the configured update type.
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success.
 *         {@link FAST_ERROR_CODE_INVALID_PTR} {@p handle} is NULL.
 *         {@link FAST_ERROR_CODE_ILLEGAL_INPUT} Invalid range, e.g. {@p left} >= {p right}.
 *
 * @note The valid range is [@p left, @p right).
 *
 * @since 6.0.2(22)
 */
FAST_EXPORT FAST_ErrorCode HMS_FAST_SegmentMap_Update(FAST_SegmentMapHandle handle,
    size_t left, size_t right, int32_t value)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Queries a range in the segment map.
 *
 * @param handle The segment map handle.
 * @param left Left boundary of the range (inclusive).
 * @param right Right boundary of the range (exclusive).
 * @param result Pointer to store the query result.
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success.
 *         {@link FAST_ERROR_CODE_INVALID_PTR} {@p handle} is NULL.
 *         {@link FAST_ERROR_CODE_ILLEGAL_INPUT} Invalid range, e.g. {@p left} >= {p right}.
 *
 * @note The valid range is [@p left, @p right).
 *
 * @since 6.0.2(22)
 */
FAST_EXPORT FAST_ErrorCode HMS_FAST_SegmentMap_Query(FAST_SegmentMapHandle handle,
    size_t left, size_t right, int32_t* result)
    __attribute__((__availability__(ohos, introduced=22.0.0)));
#ifdef __cplusplus
}
#endif
#endif // FAST_ADS_SEGMENT_MAP_H

/** @} */
