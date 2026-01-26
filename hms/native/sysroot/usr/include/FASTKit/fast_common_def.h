
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

/**
 * @file fast_common_def.h
 *
 * @brief Common definitions for FASTKit.
 *
 * @library NA
 * @kit FASTKit
 * @syscap SystemCapability.FAST.Core
 * @since 6.0.2(22)
 */

/**
 * @addtogroup FAST
 * @{
 *
 * @brief Provide acceleration capabilities to optimize metrics \n
 *        such as application startup, loading, and response latency.
 *
 * @since 6.0.2(22)
 */
#ifndef FAST_COMMON_DEF_H
#define FAST_COMMON_DEF_H
#include <stddef.h>
#include <stdint.h>
#define FAST_EXPORT __attribute__((visibility("default")))

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief ErrorCode for FASTKit.
 *
 * @since 6.0.2(22)
 */
typedef enum FAST_ErrorCode {
    /** Operation succeeded. */
    FAST_ERROR_CODE_SUCCESS = 1023100000,

    /** General failure. */
    FAST_ERROR_CODE_FAIL = 1023100001,

    /** Input parameter is illegal. */
    FAST_ERROR_CODE_ILLEGAL_INPUT = 1023100002,

    /** Pointer argument is invalid (e.g., NULL). */
    FAST_ERROR_CODE_INVALID_PTR = 1023100003,

    /** Out of memory. */
    FAST_ERROR_CODE_OOM = 1023199001
} FAST_ErrorCode;
#ifdef __cplusplus
}
#endif
#endif // FAST_COMMON_DEF_H

/** @} */
