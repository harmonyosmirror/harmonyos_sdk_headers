/**
 * Copyright 2021 Huawei Technologies Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @addtogroup MindSpore
 * @{
 *
 * @brief Provides APIs related to MindSpore Lite model inference.
 *
 * @Syscap SystemCapability.Ai.MindSpore
 * @since 9
 */

/**
 * @file status.h
 * @kit MindSporeLiteKit
 * @brief Provides the status codes of MindSpore Lite.
 *
 * @library libmindspore_lite_ndk.so
 * @since 9
 */
#ifndef MINDSPORE_INCLUDE_C_API_STATUS_C_H
#define MINDSPORE_INCLUDE_C_API_STATUS_C_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines the component code enumeration for MindSpore Lite.
 *
 * Used to identify the component module to which a status code belongs.
 * Each status code contains a component code part.
 * Component codes are used to distinguish error codes from different modules.
 *
 * @since 9
 */
enum OH_AI_CompCode {
  /** Core component code. */
  OH_AI_COMPCODE_CORE = 0x00000000u,
  /** MD component code. */
  OH_AI_COMPCODE_MD = 0x10000000u,
  /** ME component code. */
  OH_AI_COMPCODE_ME = 0x20000000u,
  /** MC component code. */
  OH_AI_COMPCODE_MC = 0x30000000u,
  /** Lite component code. */
  OH_AI_COMPCODE_LITE = 0xF0000000u,
};

/**
 * @brief Defines the status code enumeration for MindSpore Lite.
 *
 * Used to indicate the return status of MindSpore Lite API calls, including success and various error conditions.
 * Status codes are divided into different ranges, each corresponding to a specific type of error or status.
 * Common error code ranges: (-100,-1] for general errors, (-200,-100] for executor errors, (-300,-200] for graph
 * errors, (-400,-300] for operator errors, (-500,-400] for tensor errors, (-600,-500] for shape inference errors,
 * (-700,-600] for user input parameter errors, (-800,-700] for AIPP module errors.
 *
 * @since 9
 */
typedef enum OH_AI_Status {
  /** Success. */
  OH_AI_STATUS_SUCCESS = 0,
  /** Core failure. */
  OH_AI_STATUS_CORE_FAILED = OH_AI_COMPCODE_CORE | 0x1,
  /** Common error. */
  OH_AI_STATUS_LITE_ERROR = OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -1),
  /** Null pointer returned. */
  OH_AI_STATUS_LITE_NULLPTR = OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -2),
  /** Invalid parameter. */
  OH_AI_STATUS_LITE_PARAM_INVALID = OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -3),
  /** No change. */
  OH_AI_STATUS_LITE_NO_CHANGE = OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -4),
  /** No error but exit. */
  OH_AI_STATUS_LITE_SUCCESS_EXIT = OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -5),
  /** Failed to create memory. */
  OH_AI_STATUS_LITE_MEMORY_FAILED = OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -6),
  /** Not support. */
  OH_AI_STATUS_LITE_NOT_SUPPORT = OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -7),
  /** Error occurred in thread pool. */
  OH_AI_STATUS_LITE_THREADPOOL_ERROR = OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -8),
  /** Object is not initialized. */
  OH_AI_STATUS_LITE_UNINITIALIZED_OBJ = OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -9),

  /** Failed to check tensor range. */
  OH_AI_STATUS_LITE_OUT_OF_TENSOR_RANGE = OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -100),
  /** Failed to check input tensor. */
  OH_AI_STATUS_LITE_INPUT_TENSOR_ERROR =
    OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -101),
  /** Executor is already running. */
  OH_AI_STATUS_LITE_REENTRANT_ERROR = OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -102),

  /** Failed to verify graph file. */
  OH_AI_STATUS_LITE_GRAPH_FILE_ERROR = OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -200),
  /** Failed to find operator. */
  OH_AI_STATUS_LITE_NOT_FIND_OP = OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -300),
  /** Invalid operator name. */
  OH_AI_STATUS_LITE_INVALID_OP_NAME = OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -301),
  /** Invalid operator attribute. */
  OH_AI_STATUS_LITE_INVALID_OP_ATTR = OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -302),
  /** Failed to execute operator. */
  OH_AI_STATUS_LITE_OP_EXECUTE_FAILURE =
    OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -303),

  /** Failed to check tensor format. */
  OH_AI_STATUS_LITE_FORMAT_ERROR = OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -400),
  /** Failed to infer shape. */
  OH_AI_STATUS_LITE_INFER_ERROR = OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -500),
  /** Invalid shape inference before runtime. */
  OH_AI_STATUS_LITE_INFER_INVALID =
    OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -501),
  /** Invalid input parameter from user. */
  OH_AI_STATUS_LITE_INPUT_PARAM_INVALID =
    OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -600),

  /**
   * @brief AIPP is not supported.
   * @since 23
   */
  OH_AI_STATUS_LITE_AIPP_NOT_SUPPORTED = OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -700),

  /**
   * @brief Failed to infer with AIPP.
   * @since 23
   */
  OH_AI_STATUS_LITE_AIPP_INFER_ERROR = OH_AI_COMPCODE_LITE | (0x0FFFFFFF & -701),
} OH_AI_Status;
#ifdef __cplusplus
}
#endif

/** @} */
#endif  // MINDSPORE_INCLUDE_C_API_STATUS_C_H
