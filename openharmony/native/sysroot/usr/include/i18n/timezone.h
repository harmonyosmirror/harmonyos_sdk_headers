/*
 * Copyright (c) 2025 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
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
 * @addtogroup i18n
 * @{
 *
 * @brief Provides internationalization APIs for application localization, and relies on libohi18n.z.so when used.
 * @since 22
 */

/**
 * @file timezone.h
 *
 * @brief Provides the API for obtaining timezone offset transition information.
 *
 * @library libohi18n.so
 * @kit LocalizationKit
 * @syscap SystemCapability.Global.I18n
 * @since 22
 */

#ifndef GLOBAL_I18N_TIMEZONE_H
#define GLOBAL_I18N_TIMEZONE_H

#include "info/application_target_sdk_version.h"
#include <stddef.h>
#include <stdint.h>
#include "errorcode.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates the types of rules for defining dates.
 *
 * @since 22
 */
typedef enum DateRuleType {
    /**
     * @brief Indicates that a day is specified by day_of_month.
     */
    DOM = 0,

    /**
     * @brief Indicates that a day is specified by day_of_week.
     */
    DOW = 1,

    /**
     * @brief Indicates that a day is specified by day_of_week on or after day_of_month.
     */
    DOW_GEQ_DOM = 2,
    
    /**
     * @brief Indicates that a day is specified by day_of_week on or before day_of_month.
     */
    DOW_LEQ_DOM = 3
} DateRuleType;

/**
 * @brief Enumerates the types of rules for defining time.
 *
 * @since 22
 */
typedef enum TimeRuleType {
    /**
     * @brief Indicates that time is specified by wall time.
     */
    WALL_TIME = 0,
    
    /**
     * @brief Indicates that time is specified by standard time.
     */
    STANDARD_TIME = 1,

    /**
     * @brief Indicates that time is specified by UTC time.
     */
    UTC_TIME = 2,
} TimeRuleType;

/**
 * @brief Defines the date and time rules to specify a date and time.
 *
 * @since 22
 */
typedef struct DateTimeRule {
    /**
     * @brief Indicates the month.
     */
    int32_t month;

    /**
     * @brief Indicates the day of a month.
     */
    int32_t dayOfMonth;

    /**
     * @brief Indicates the day of a week.
     */
    int32_t dayOfWeek;
    
    /**
     * @brief Indicates the week in a month.
     */
    int32_t weekInMonth;

    /**
     * @brief Indicates the milliseconds in a day.
     */
    int32_t millisInDay;

    /**
     * @brief Indicates the date rule type.
     */
    DateRuleType dateRuleType;

    /**
     * @brief Indicates the time rule type.
     */
    TimeRuleType timeRuleType;
} DateTimeRule;

/**
 * @brief Defines the initial rule of a timezone which has no clear start time.
 *
 * @since 22
 */
typedef struct InitialTimeZoneRule {
    /**
     * @brief Indicates the raw offset of a timezone.
     */
    int32_t rawOffset;

    /**
     * @brief Indicates the dstSavings offset of a timezone.
     */
    int32_t dstSavings;
} InitialTimeZoneRule;

/**
 * @brief Defines a set of timezone rules by the rule effective time array.
 *
 * @since 22
 */
typedef struct TimeArrayTimeZoneRule {
    /**
     * @brief Indicates the timezone name.
     */
    char* name;

    /**
     * @brief Indicates the raw offset of timezone.
     */
    int32_t rawOffset;

    /**
     * @brief Indicates the dstSavings offset of timezone.
     */
    int32_t dstSavings;

    /**
     * @brief Indicates the start times when the rule takes effect. The caller is responsible for releasing the array.
     */
    double* startTimes;

    /**
     * @brief Indicates the num of start times when the rule takes effect.
     */
    int32_t numStartTimes;

    /**
     * @brief Indicates the TimeRule of the rule to specify the time.
     */
    TimeRuleType timeRuleType;
} TimeArrayTimeZoneRule;

/**
 * @brief Indicates the maximum year when the rule takes effective in AnnualTimeZoneRule.
 *
 * @since 22
 */
#define MAX_YEAR_IN_ANNUAL_TIMEZONE_RULE 0x7fffffff

/**
 * @brief Defines a set of timezone rules by specifying the start year when the rules come into effect and end.
 *
 * @since 22
 */
typedef struct AnnualTimeZoneRule {
    /**
     * @brief Indicates the timezone name.
     */
    char* name;
    
    /**
     * @brief Indicates the start year when the rule takes effective.
     */
    int32_t startYear;

    /**
     * @brief Indicates the end year when the rule takes effective.
     */
    int32_t endYear;

    /**
     * @brief Indicates the raw offset of timezone.
     */
    int32_t rawOffset;

    /**
     * @brief Indicates the dstSavings offset of timezone.
     */
    int32_t dstSavings;

    /**
     * @brief Indicates DateTimeRule of the rule to specify the date and time.
     */
    DateTimeRule dateTimeRule;
} AnnualTimeZoneRule;

/**
 * @brief Defines a set of timezone rules of a timezone.
 *
 * @since 22
 */
typedef struct TimeZoneRules {
    /**
     * @brief Indicates the InitialTimeZoneRule of a timezone.
     */
    InitialTimeZoneRule initial;

    /**
     * @brief Indicates the TimeArrayTimeZoneRules of a timezone. The caller is responsible for releasing the array.
     */
    TimeArrayTimeZoneRule* timeArrayRules;

    /**
     * @brief Indicates the AnnualTimeZoneRules of a timezone. The caller is responsible for releasing the array.
     */
    AnnualTimeZoneRule* annualRules;

    /**
     * @brief Indicates the num of TimeArrayTimeZoneRules.
     */
    size_t numTimeArrayRules;

    /**
     * @brief Indicates the num of AnnualTimeZoneRules.
     */
    size_t numAnnualRules;
} TimeZoneRules;

/**
 * @brief Obtains the timezone rules by timezone ID.
 *
 * @param timeZoneID Indicates the timezone ID, such as "Asia/Shanghai".
 * @param rules Indicates the TimeZoneRules{@link TimeZoneRules} of timezoneID.
 * @return {@link SUCCESS} 0 - Success.
 *         {@link ERROR_INVALID_PARAMETER} 8900001 - Invalid parameter. Possible causes: Parameter verification failed.
 *         {@link UNEXPECTED_ERROR} 8900050 - Unexpected error, such as memory error.
 * @since 22
 */
I18n_ErrorCode OH_i18n_GetTimeZoneRules(const char* timeZoneID, TimeZoneRules* rules)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Defines the query information and query result.
 *
 * @since 22
 */
typedef struct TimeZoneRuleQuery {
    /**
     * @brief Indicates the base time in a next start or previous start time query.
     */
    double base;

    /**
     * @brief Indicates the previous raw offset.
     */
    int32_t prevRawOffset;

    /**
     * @brief Indicates the previous dstSavings offset.
     */
    int32_t prevDSTSavings;

    /**
     * @brief Indicates whether the base time is inclusive.
     */
    bool inclusive;

    /**
     * @brief Indicates the query result.
     */
    double result;
} TimeZoneRuleQuery;

/**
 * @brief Obtains the time when the TimeArrayTimeZoneRule first took effect.
 *
 * @param rule Indicates the rule defined by TimeArrayTimeZoneRule{@link TimeArrayTimeZoneRule}.
 * @param query Indicates the query information and query result.
 * @return {@link SUCCESS} 0 - Success.
 *         {@link ERROR_INVALID_PARAMETER} 8900001 - Invalid parameter. Possible causes:
 *     Parameter verification failed.
 *         {@link UNEXPECTED_ERROR} 8900050 - Unexpected error, such as memory error.
 * @since 22
 */
I18n_ErrorCode OH_i18n_GetFirstStartFromTimeArrayTimeZoneRule(TimeArrayTimeZoneRule* rule, TimeZoneRuleQuery* query)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Obtains the time when the AnnualTimeZoneRule first took effect.
 *
 * @param rule Indicates the rule defined by AnnualTimeZoneRule{@link AnnualTimeZoneRule}.
 * @param query Indicates the query information and query result.
 * @return {@link SUCCESS} 0 - Success.
 *         {@link ERROR_INVALID_PARAMETER} 8900001 - Invalid parameter. Possible causes:
 *     Parameter verification failed.
 *         {@link UNEXPECTED_ERROR} 8900050 - Unexpected error, such as memory error.
 * @since 22
 */
I18n_ErrorCode OH_i18n_GetFirstStartFromAnnualTimeZoneRule(AnnualTimeZoneRule* rule, TimeZoneRuleQuery* query)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Obtains the time when the TimeArrayTimeZoneRule final took effect.
 *
 * @param rule Indicates the rule defined by TimeArrayTimeZoneRule{@link TimeArrayTimeZoneRule}.
 * @param query Indicates the query information and query result.
 * @return {@link SUCCESS} 0 - Success.
 *         {@link ERROR_INVALID_PARAMETER} 8900001 - Invalid parameter. Possible causes:
 *     Parameter verification failed.
 *         {@link UNEXPECTED_ERROR} 8900050 - Unexpected error, such as memory error.
 * @since 22
 */
I18n_ErrorCode OH_i18n_GetFinalStartFromTimeArrayTimeZoneRule(TimeArrayTimeZoneRule* rule, TimeZoneRuleQuery* query)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Obtains the time when the AnnualTimeZoneRule final took effect.
 *
 * @param rule Indicates the rule defined by AnnualTimeZoneRule{@link AnnualTimeZoneRule}.
 * @param query Indicates the query information and query result.
 * @return {@link SUCCESS} 0 - Success.
 *         {@link ERROR_INVALID_PARAMETER} 8900001 - Invalid parameter. Possible causes:
 *     Parameter verification failed.
 *         {@link UNEXPECTED_ERROR} 8900050 - Unexpected error, such as memory error.
 * @since 22
 */
I18n_ErrorCode OH_i18n_GetFinalStartFromAnnualTimeZoneRule(AnnualTimeZoneRule* rule, TimeZoneRuleQuery* query)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Obtains the time when the TimeArrayTimeZoneRule next took effect.
 *
 * @param rule Indicates the rule defined by TimeArrayTimeZoneRule{@link TimeArrayTimeZoneRule}.
 * @param query Indicates the query information and query result.
 * @return {@link SUCCESS} 0 - Success.
 *         {@link ERROR_INVALID_PARAMETER} 8900001 - Invalid parameter. Possible causes:
 *     Parameter verification failed.
 *         {@link UNEXPECTED_ERROR} 8900050 - Unexpected error, such as memory error.
 * @since 22
 */
I18n_ErrorCode OH_i18n_GetNextStartFromTimeArrayTimeZoneRule(TimeArrayTimeZoneRule* rule, TimeZoneRuleQuery* query)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Obtains the time when the AnnualTimeZoneRule next took effect.
 *
 * @param rule Indicates the rule defined by AnnualTimeZoneRule{@link AnnualTimeZoneRule}.
 * @param query Indicates the query information and query result.
 * @return {@link SUCCESS} 0 - Success.
 *         {@link ERROR_INVALID_PARAMETER} 8900001 - Invalid parameter. Possible causes:
 *     Parameter verification failed.
 *         {@link UNEXPECTED_ERROR} 8900050 - Unexpected error, such as memory error.
 * @since 22
 */
I18n_ErrorCode OH_i18n_GetNextStartFromAnnualTimeZoneRule(AnnualTimeZoneRule* rule, TimeZoneRuleQuery* query)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Obtains the time when the TimeArrayTimeZoneRule previous took effect.
 *
 * @param rule Indicates the rule defined by TimeArrayTimeZoneRule{@link TimeArrayTimeZoneRule}.
 * @param query Indicates the query information and query result.
 * @return {@link SUCCESS} 0 - Success.
 *         {@link ERROR_INVALID_PARAMETER} 8900001 - Invalid parameter. Possible causes:
 *     Parameter verification failed.
 *         {@link UNEXPECTED_ERROR} 8900050 - Unexpected error, such as memory error.
 * @since 22
 */
I18n_ErrorCode OH_i18n_GetPrevStartFromTimeArrayTimeZoneRule(TimeArrayTimeZoneRule* rule, TimeZoneRuleQuery* query)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Obtains the time when the AnnualTimeZoneRule previous took effect.
 *
 * @param rule Indicates the rule defined by AnnualTimeZoneRule{@link AnnualTimeZoneRule}.
 * @param query Indicates the query information and query result.
 * @return {@link SUCCESS} 0 - Success.
 *         {@link ERROR_INVALID_PARAMETER} 8900001 - Invalid parameter. Possible causes:
 *     Parameter verification failed.
 *         {@link UNEXPECTED_ERROR} 8900050 - Unexpected error, such as memory error.
 * @since 22
 */
I18n_ErrorCode OH_i18n_GetPrevStartFromAnnualTimeZoneRule(AnnualTimeZoneRule* rule, TimeZoneRuleQuery* query)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Obtain the effective start time of a specific rule in the TimeArrayTimeZoneRule.
 *
 * @param rule Indicates the rule defined by TimeArrayTimeZoneRule{@link TimeArrayTimeZoneRule}.
 * @param index Indicates the rule index.
 * @param result the start time of the rule.
 * @return {@link SUCCESS} 0 - Success.
 *         {@link ERROR_INVALID_PARAMETER} 8900001 - Invalid parameter. Possible causes:
 *     Parameter verification failed.
 *         {@link UNEXPECTED_ERROR} 8900050 - Unexpected error, such as memory error.
 * @since 22
 */
I18n_ErrorCode OH_i18n_GetStartTimeAt(TimeArrayTimeZoneRule* rule, int32_t index, double* result)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Obtain the effective start time of a specific rule for target year in the AnnualTimeZoneRule.
 *
 * @param rule Indicates the rule defined by AnnualTimeZoneRule{@link AnnualTimeZoneRule}.
 * @param year Indicates the year used to get the rule defined by AnnualTimeZoneRule.
 * @param query Indicates the query information and result.
 * @return {@link SUCCESS} 0 - Success.
 *         {@link ERROR_INVALID_PARAMETER} 8900001 - Invalid parameter. Possible causes:
 *     Parameter verification failed.
 *         {@link UNEXPECTED_ERROR} 8900050 - Unexpected error, such as memory error.
 * @since 22
 */
I18n_ErrorCode OH_i18n_GetStartInYear(AnnualTimeZoneRule* rule, int32_t year, TimeZoneRuleQuery* query)
__attribute__((__availability__(ohos, introduced=22.0.0)));

#ifdef __cplusplus
};
#endif
#endif // GLOBAL_I18N_TIMEZONE_H
/** @} */
