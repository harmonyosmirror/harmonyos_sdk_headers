
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

/**
 * @file fast_solver_rect_partition.h
 *
 * @brief A solver for the rectangle partition problem.
 *
 * @library libfast_solver.so
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

#ifndef FAST_SOLVER_RECT_PARTITION_H
#define FAST_SOLVER_RECT_PARTITION_H
#include "info/application_target_sdk_version.h"
#include "fast_common_def.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Structure representing a rectangle.
 *
 * @since 6.0.2(22)
 */
typedef struct FAST_Rect {
    /** Left boundary on the x-axis */
    int32_t left;
    /** Top boundary on the y-axis */
    int32_t top;
    /** Right boundary on the x-axis */
    int32_t right;
    /** Bottom boundary on the y-axis */
    int32_t bottom;
} FAST_Rect;

/**
 * @brief Opaque configuration structure for the rectangle partition solver.
 *
 * @since 6.0.2(22)
 */
typedef struct FAST_RectPartitionConfig FAST_RectPartitionConfig;

/**
 * @brief Creates a configuration object for the rectangle partition solver.
 *
 * @param config Pointer to the created {@link FAST_RectPartitionConfig}.
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success.
 *         {@link FAST_ERROR_CODE_INVALID_PTR} {@p config} is NULL.
 *         {@link FAST_ERROR_CODE_OOM} Out of memory.
 *
 * @since 6.0.2(22)
 */
FAST_EXPORT FAST_ErrorCode HMS_FAST_RectPartition_CreateConfig(FAST_RectPartitionConfig** config)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Destroys a rectangle partition solver configuration object.
 *
 * @param config The {@link FAST_RectPartitionConfig} to destroy.
 * @return NA
 *
 * @since 6.0.2(22)
 */
FAST_EXPORT void HMS_FAST_RectPartition_DestroyConfig(FAST_RectPartitionConfig* config)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Sets the algorithm used by the solver.
 *
 * @param config The {@link FAST_RectPartitionConfig} to configure.
 * @param name   The name of the algorithm to use.
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success.
 *         {@link FAST_ERROR_CODE_INVALID_PTR} {@p config} or {@p name} is NULL.
 *         {@link FAST_ERROR_CODE_ILLEGAL_INPUT} Unsupported algorithm.
 *
 * @note Currently, only "SweepLineAlgo" is supported.
 *
 * @since 6.0.2(22)
 */
FAST_EXPORT FAST_ErrorCode HMS_FAST_RectPartition_SetAlgo(FAST_RectPartitionConfig* config,
    const char* name)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Solves the rectangle partition problem using the given configuration.
 *
 * @param config      The solver configuration.
 * @param size        Number of input rectangles in the {@p origin} array.
 * @param origin      Array of input {@link FAST_Rect} rectangles to be partitioned.
 * @param result      Output array to store the partitioned rectangles.
 * @param resultSize  Actual number of rectangles produced after partitioning.
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success.
 *         {@link FAST_ERROR_CODE_INVALID_PTR} Input pointer is NULL.
 *         {@link FAST_ERROR_CODE_ILLEGAL_INPUT} Illegal input, e.g. the rectangles are disjoint.
 *         {@link FAST_ERROR_CODE_FAIL} The algorithm get a wrong answer.
 *
 * @note
 * 1. If no algorithm is explicitly set, the default is "SweepLineAlgo".
 * 2. The caller must allocate the {@p result} array before calling this function.
 * 3. The allocated size of {@p result} must be sufficient to hold all output rectangles;
 *    otherwise, buffer overflow may occur.
 * 4. {@link FAST_ERROR_CODE_FAIL} should never reach when algorithm is "SweepLineAlgo" currently.
 *
 * @since 6.0.2(22)
 */
FAST_EXPORT FAST_ErrorCode HMS_FAST_RectPartition_Solve(FAST_RectPartitionConfig* config,
    size_t size, const FAST_Rect* origin, FAST_Rect* result, size_t* resultSize)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

#ifdef __cplusplus
}
#endif
#endif // FAST_SOLVER_RECT_PARTITION_H

/** @} */
