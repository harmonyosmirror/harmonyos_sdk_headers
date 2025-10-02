/*
 * Copyright (c) 2025 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License"),
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @addtogroup TeeTrusted
 * @{
 *
 * @brief TEE(Trusted Excution Environment) API.
 * Provides security capability APIs such as trusted storage, encryption and decryption,
 * and trusted time for trusted application development.
 *
 * @since 20
 */

/**
 * @file tee_apm_api.h
 *
 * @brief Provides the API about TA APM.
 *
 * @library NA
 * @kit TEEKit
 * @syscap SystemCapability.Tee.TeeClient
 * @since 20
 */

#ifndef TEE_APM_API_H
#define TEE_APM_API_H

#include "tee_defines.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates the TEE measurement result values.
 *
 * @since 20
 */
enum tee_measure_result_value {
    /** Measurement success. */
    TEE_MEASURE_SUCCESS                            = 0x00000000,
    /** Generic error. */
    TEE_MEASURE_ERROR_GENERIC                      = 0x00000001,
    /** TA hash check failed. */
    TEE_MEASURE_ERROR_TA_HASH_CHECK_FAILED         = 0x00000002,
    /** TA baseline does not exist. */
    TEE_MEASURE_ERROR_TA_BASELINE_NOT_EXIST        = 0x00000003,
    /** TA memory hash does not exist. */
    TEE_MEASURE_ERROR_TA_MEMHASH_NOT_EXIST         = 0x00000004,
    /** Permission denied. */
    TEE_MEASURE_ERROR_PERMISSION_DENY              = 0x00000005,
    /** TA history measurement does not exist. */
    TEE_MEASURE_ERROR_TA_HISTORY_MEASURE_NOT_EXIST = 0x00000006,
    /** MSPC report query failed. */
    TEE_MEASURE_ERROR_MSPC_REPORT_QUERY_FAILED     = 0x00000007,
    /** MSPC service is unavailable. */
    TEE_MEASURE_ERROR_MSPC_NOT_SUPPORT             = 0x00000008,
    /** APM measurement report not supported. */
    TEE_MEASURE_ERROR_REPORT_NOT_SUPPORT           = 0x00000009,
    /** APM service is unavailable. */
    TEE_MEASURE_ERROR_APM_NOT_SUPPORT              = 0x0000000a,
};

/**
 * @brief Record the recent measure errors.
 *
 * @since 20
 */
#define MAX_HISTORY_MEASURE_RECORDS_NUM 10

/**
 * @brief Defines the history of measurement errors.
 *
 * @since 20
 */
struct history_measure_result_t {
    /** recent measure errors number. */
    uint8_t error_num;
    /** measure error type */
    uint32_t error_type[MAX_HISTORY_MEASURE_RECORDS_NUM];
    /** measure error time */
    uint64_t error_time[MAX_HISTORY_MEASURE_RECORDS_NUM];
};

/**
 * @brief Defines the size of the TA memory hash.
 *
 * @since 20
 */
#define TA_HASH_SIZE 32

/**
 * @brief Defines the structure of the TA measure report.
 *
 * @since 20
 */
struct ta_measure_report_t {
    /** TA UUID */
    TEE_UUID uuid;
    /** TA's measurement result */
    uint32_t measure_result;
    /** TA's runtime measurement hash */
    uint8_t ta_measured[TA_HASH_SIZE];
    /** TA's baseline measurement hash */
    uint8_t ta_baseline[TA_HASH_SIZE];
    /** History measurement results */
    struct history_measure_result_t history_result;
};

/**
 * @brief Queries the TA measure report.
 *
 * @param uuid A pointer to the TA's UUID.
 * @param report A pointer to the structure that stores the measure report result.
 *
 * @return Returns the query result, TEE_SUCCESS if successful, or the corresponding error code if failed.
 *
 * @since 20
 */
TEE_Result tee_query_ta_measure_report(const TEE_UUID *uuid, struct ta_measure_report_t *report);

/**
 * @brief Defines the structure of the MSPC measure report element.
 *
 * @since 20
 */
struct mspc_metric_report_element_t {
    /** Baseline status */
    uint32_t baseline_status;
    /** Most recent error */
    uint32_t recent_error;
    /** Error type */
    uint32_t error_class;
    /** Time when the error occurred */
    uint32_t error_time;
};

/**
 * @brief Defines the structure of the MSPC measure result report substructure.
 *
 * @since 20
 */
struct mspc_metric_result_report_sub {
    /** Global metric result */
    struct mspc_metric_report_element_t global_result;
    /** BL2 metric result */
    struct mspc_metric_report_element_t bl2_result;
    /** BL31 metric  result */
    struct mspc_metric_report_element_t bl31_result;
    /** TEE metric result */
    struct mspc_metric_report_element_t tee_result;
};

/**
 * @brief Defines the structure of the passive part of the MSPC measure result report.
 *
 * @since 20
 */
struct mspc_metric_result_report_passive {
    /** BL2 verification result */
    struct mspc_metric_report_element_t bl2_verify_result;
    /** TEE active metric result */
    struct mspc_metric_report_element_t tee_active_protect;
};

/**
 * @brief Defines the structure of the command processing part of the MSPC measure result report.
 *
 * @since 20
 */
struct mspc_metric_result_report_of_cmd_process {
    /** Baseline command metirc result */
    struct mspc_metric_report_element_t cmd_baseline;
    /** Active command  metric result */
    struct mspc_metric_report_element_t cmd_active_metric;
    /** Passive command  metric result */
    struct mspc_metric_report_element_t cmd_passive_metric;
    /** Query command  metric result */
    struct mspc_metric_report_element_t cmd_query_result;
};

/**
 * @brief Defines the structure of the MSPC measure result report.
 *
 * @since 20
 */
struct mspc_metric_result_report_t {
    /** Final metric result */
    uint32_t final_result;
    /** Baseline metric report */
    struct mspc_metric_result_report_sub baseline_report;
    /** Idle metric report */
    struct mspc_metric_result_report_sub idle_metric_report;
    /** Active metric report */
    struct mspc_metric_result_report_sub active_metric_report;
    /** Passive metric report */
    struct mspc_metric_result_report_passive passive_metric_report;
    /** Command metric report */
    struct mspc_metric_result_report_of_cmd_process cmd_process_report;
};

/**
 * @brief Queries the MSPC measurement report.
 *
 * @param report A pointer to the structure that stores mspc measurement report.
 *
 * @return Returns {@code TEE_SUCCESS} if the operation is successful.
 *         Returns other information otherwise.
 *
 * @since 20
 */
TEE_Result tee_query_mspc_measure_report(struct mspc_metric_result_report_t *report);

#ifdef __cplusplus
}
#endif

#endif
/** @} */