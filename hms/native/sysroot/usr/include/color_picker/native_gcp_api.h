/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
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
 * @addtogroup GlobalColorPicker
 * @{
 *
 * @brief Defines the functions of GlobalColorPicker.
 *
 * @since 5.0.0(12)
 */

 /**
 * @file native_gcp_api.h
 * @kit PenKit
 *
 * @brief Defines the functions of GlobalColorPicker.
 *
 * @library libcolorpicker_ndk.z.so
 * @syscap SystemCapability.StylusService.ColorPicker
 * @since 5.0.0(12)
 */
 
#ifndef NATIVE_GCP_API_H
#define NATIVE_GCP_API_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief The color space enum.
 * @since 5.0.0(12)
 */
typedef enum {
    /** an unknown color space */
    HMS_GCP_UNKNOWN = 0,
    /** the color space based on Adobe RGB (1998) */
    HMS_GCP_ADOBE_RGB_1998 = 1,
    /** the color space based on SMPTE RP 431-2-2007 and IEC 61966-2.1:1999 */
    HMS_GCP_DCI_P3 = 2,
    /** the color space based on SMPTE RP 431-2-2007 and IEC 61966-2.1:1999 */
    HMS_GCP_DISPLAY_P3 = 3,
    /** the standard red green blue (SRGB) color space based on IEC 61966-2.1:1999 */
    HMS_GCP_SRGB = 4,
    /** the color space based on ITU-R BT.709, PRIMARIES_BT709 | TRANSFUNC_BT709 | RANGE_FULL */
    HMS_GCP_BT709 = 6,
    /** the color space based on ITU-R BT.601, PRIMARIES_BT601_P | TRANSFUNC_BT709 | RANGE_FULL */
    HMS_GCP_BT601_EBU = 7,
    /** the color space based on ITU-R BT.601, PRIMARIES_BT601_N | TRANSFUNC_BT709 | RANGE_FULL */
    HMS_GCP_BT601_SMPTE_C = 8,
    /** the color space based on ITU-R BT.2020, PRIMARIES_BT2020 | TRANSFUNC_HLG | RANGE_FULL */
    HMS_GCP_BT2020_HLG = 9,
    /** the color space based on ITU-R BT.2020, PRIMARIES_BT2020 | TRANSFUNC_PQ | RANGE_FULL */
    HMS_GCP_BT2020_PQ = 10,
    /** PRIMARIES_P3_D65 | TRANSFUNC_HLG | RANGE_FULL */
    HMS_GCP_P3_HLG = 11,
    /** PRIMARIES_P3_D65 | TRANSFUNC_PQ | RANGE_FULL */
    HMS_GCP_P3_PQ = 12,
    /** PRIMARIES_ADOBE_RGB | TRANSFUNC_ADOBE_RGB | RANGE_LIMIT */
    HMS_GCP_ADOBE_RGB_1998_LIMIT = 13,
    /** PRIMARIES_P3_D65 | TRANSFUNC_SRGB | RANGE_LIMIT */
    HMS_GCP_DISPLAY_P3_LIMIT = 14,
    /** PRIMARIES_SRGB | TRANSFUNC_SRGB | RANGE_LIMIT */
    HMS_GCP_SRGB_LIMIT = 15,
    /** PRIMARIES_BT709 | TRANSFUNC_BT709 | RANGE_LIMIT */
    HMS_GCP_BT709_LIMIT = 16,
    /** PRIMARIES_BT601_P | TRANSFUNC_BT709 | RANGE_LIMIT */
    HMS_GCP_BT601_EBU_LIMIT = 17,
    /** PRIMARIES_BT601_N | TRANSFUNC_BT709 | RANGE_LIMIT */
    HMS_GCP_BT601_SMPTE_C_LIMIT = 18,
    /** PRIMARIES_BT2020 | TRANSFUNC_HLG | RANGE_LIMIT */
    HMS_GCP_BT2020_HLG_LIMIT = 19,
    /** PRIMARIES_BT2020 | TRANSFUNC_PQ | RANGE_LIMIT */
    HMS_GCP_BT2020_PQ_LIMIT = 20,
    /** PRIMARIES_P3_D65 | TRANSFUNC_HLG | RANGE_LIMIT */
    HMS_GCP_P3_HLG_LIMIT = 21,
    /** PRIMARIES_P3_D65 | TRANSFUNC_PQ | RANGE_LIMIT */
    HMS_GCP_P3_PQ_LIMIT = 22,
    /** PRIMARIES_P3_D65 | TRANSFUNC_LINEAR */
    HMS_GCP_LINEAR_P3 = 23,
    /** PRIMARIES_SRGB | TRANSFUNC_LINEAR */
    HMS_GCP_LINEAR_SRGB = 24,
    /** PRIMARIES_BT2020 | TRANSFUNC_LINEAR */
    HMS_GCP_LINEAR_BT2020 = 25,
    /** a customized color space */
    CUSTOM = 5,
} HMS_GCP_ColorSpace;

/**
 * @brief Defines the structure for color value.
 * @since 5.0.0(12)
 */
typedef struct {
    /** The red channel. */
    int32_t red;
    /** The green channel. */
    int32_t green;
    /** The blue channel. */
    int32_t blue;
    /** The alpha channel. */
    int32_t alpha;
} HMS_GCP_Color;

/**
 * @brief Defines the structure for the picked color information.
 * @since 5.0.0(12)
 */
typedef struct {
    /** The picked color value. */
    HMS_GCP_Color color;
    /** The colorspace of color present in. */
    HMS_GCP_ColorSpace colorSpace;
    /** The timestamp of color picked. */
    int64_t timestamp;
} HMS_GCP_PickedColorInfo;

/**
 * @brief The callback is used to receive the picked color result when success.
 *
 * @param userData Pointer to the user data. It can be NULL
 * @param colorInfo The picked color information which needs to be saved by users.
 * @param code result code
 * @see HMS_GCP_PickColor
 * @since 5.0.0(12)
 */
typedef void (*HMS_GCP_OnResult)(void* userData, HMS_GCP_PickedColorInfo colorInfo, const int32_t code);

/**
 * @brief Start global color picker.
 *
 * This API is used to start color picker.
 *
 * @param initialPosX Indicates the x-axis of initial position for color picker.
 * @param initialPosY Indicates the y-axis of initial position for color picker.
 * @param onResultCallback Indicates the callback to receive picked color information.
 * @param userData Pointer to the user data. It can be NULL.
 * @return Returns if the operation is successful,
 * 1013900001 - IPC communication failed
 * 1013900002 - memory is insufficient
 * 1013900003 - service is invalid
 * 1013900004 - multi app call
 * 1013900005 - background service call
 * @since 5.0.0(12)
 */
int32_t HMS_GCP_StartColorPicker(
    int32_t initialPosX, int32_t initialPosY, HMS_GCP_OnResult onResultCallback, void *userData);

#ifdef __cplusplus
}
#endif

#endif // NATIVE_GCP_API_H
/** @} */