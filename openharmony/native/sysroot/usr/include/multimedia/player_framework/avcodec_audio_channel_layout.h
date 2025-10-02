/*
 * Copyright (C) 2023 Huawei Device Co., Ltd.
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
 * @addtogroup CodecBase
 * @{
 *
 * @brief The CodecBase module provides variables, properties, and functions
 * for audio and video muxer, demuxer, and basic encoding and decoding functions.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */

/**
 * @file avcodec_audio_channel_layout.h
 *
 * @brief Declare the enumeration used for audio encoding and decoding.
 *
 * @kit AVCodecKit
 * @library libnative_media_codecbase.so
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @deprecated since 11
 * @since 10
 */

#ifndef AVCODEC_AUDIO_CHANNEL_LAYOUT_H
#define AVCODEC_AUDIO_CHANNEL_LAYOUT_H

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif

/**
 * @file avcodec_audio_channel_layout.h
 *
 * @brief Audio AudioChannel Layout
 *
 * @kit AVCodecKit
 * @library libnative_media_codecbase.so
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @deprecated since 11
 * @since 10
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Audio Channel Set
 * A 64-bit integer with bits set for each channel.
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @deprecated since 11
 * @useinstead OH_AudioChannelSet
 * @since 10
 */
typedef enum AudioChannelSet : uint64_t {
    FRONT_LEFT = 1ULL << 0U,
    FRONT_RIGHT = 1ULL << 1U,
    FRONT_CENTER = 1ULL << 2U,
    LOW_FREQUENCY = 1ULL << 3U,
    BACK_LEFT = 1ULL << 4U,
    BACK_RIGHT = 1ULL << 5U,
    FRONT_LEFT_OF_CENTER = 1ULL << 6U,
    FRONT_RIGHT_OF_CENTER = 1ULL << 7U,
    BACK_CENTER = 1ULL << 8U,
    SIDE_LEFT = 1ULL << 9U,
    SIDE_RIGHT = 1ULL << 10U,
    TOP_CENTER = 1ULL << 11U,
    TOP_FRONT_LEFT = 1ULL << 12U,
    TOP_FRONT_CENTER = 1ULL << 13U,
    TOP_FRONT_RIGHT = 1ULL << 14U,
    TOP_BACK_LEFT = 1ULL << 15U,
    TOP_BACK_CENTER = 1ULL << 16U,
    TOP_BACK_RIGHT = 1ULL << 17U,
    STEREO_LEFT = 1ULL << 29U,
    STEREO_RIGHT = 1ULL << 30U,
    WIDE_LEFT = 1ULL << 31U,
    WIDE_RIGHT = 1ULL << 32U,
    SURROUND_DIRECT_LEFT = 1ULL << 33U,
    SURROUND_DIRECT_RIGHT = 1ULL << 34U,
    LOW_FREQUENCY_2 = 1ULL << 35U,
    TOP_SIDE_LEFT = 1ULL << 36U,
    TOP_SIDE_RIGHT = 1ULL << 37U,
    BOTTOM_FRONT_CENTER = 1ULL << 38U,
    BOTTOM_FRONT_LEFT = 1ULL << 39U,
    BOTTOM_FRONT_RIGHT = 1ULL << 40U,

    // Ambisonics ACN formats
    // 0th and first order ambisonics ACN
    AMBISONICS_ACN0 = 1ULL << 41U,  /** 0th ambisonics channel number 0. */
    AMBISONICS_ACN1 = 1ULL << 42U,  /** first-order ambisonics channel number 1. */
    AMBISONICS_ACN2 = 1ULL << 43U,  /** first-order ambisonics channel number 2. */
    AMBISONICS_ACN3 = 1ULL << 44U,  /** first-order ambisonics channel number 3. */
    AMBISONICS_W = AMBISONICS_ACN0, /** same as 0th ambisonics channel number 0. */
    AMBISONICS_Y = AMBISONICS_ACN1, /** same as first-order ambisonics channel number 1. */
    AMBISONICS_Z = AMBISONICS_ACN2, /** same as first-order ambisonics channel number 2. */
    AMBISONICS_X = AMBISONICS_ACN3, /** same as first-order ambisonics channel number 3. */

    // second order ambisonics ACN
    AMBISONICS_ACN4 = 1ULL << 45U, /** second-order ambisonics channel number 4. */
    AMBISONICS_ACN5 = 1ULL << 46U, /** second-order ambisonics channel number 5. */
    AMBISONICS_ACN6 = 1ULL << 47U, /** second-order ambisonics channel number 6. */
    AMBISONICS_ACN7 = 1ULL << 48U, /** second-order ambisonics channel number 7. */
    AMBISONICS_ACN8 = 1ULL << 49U, /** second-order ambisonics channel number 8. */

    // third order ambisonics ACN
    AMBISONICS_ACN9 = 1ULL << 50U,  /** third-order ambisonics channel number 9. */
    AMBISONICS_ACN10 = 1ULL << 51U, /** third-order ambisonics channel number 10. */
    AMBISONICS_ACN11 = 1ULL << 52U, /** third-order ambisonics channel number 11. */
    AMBISONICS_ACN12 = 1ULL << 53U, /** third-order ambisonics channel number 12. */
    AMBISONICS_ACN13 = 1ULL << 54U, /** third-order ambisonics channel number 13. */
    AMBISONICS_ACN14 = 1ULL << 55U, /** third-order ambisonics channel number 14. */
    AMBISONICS_ACN15 = 1ULL << 56U, /** third-order ambisonics channel number 15. */
} AudioChannelSet;

/**
 * @brief Audio AudioChannel Layout
 * Indicates that the channel order in which the user requests decoder output
 * is the native codec channel order.
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @deprecated since 11
 * @useinstead OH_AudioChannelLayout
 * @since 10
 */
typedef enum AudioChannelLayout : uint64_t {
    UNKNOWN_CHANNEL_LAYOUT = 0,
    MONO = (FRONT_CENTER),
    STEREO = (FRONT_LEFT | FRONT_RIGHT),
    CH_2POINT1 = (STEREO | LOW_FREQUENCY),
    CH_2_1 = (STEREO | BACK_CENTER),
    SURROUND = (STEREO | FRONT_CENTER),
    CH_3POINT1 = (SURROUND | LOW_FREQUENCY),
    CH_4POINT0 = (SURROUND | BACK_CENTER),
    CH_4POINT1 = (CH_4POINT0 | LOW_FREQUENCY),
    CH_2_2 = (STEREO | SIDE_LEFT | SIDE_RIGHT),
    QUAD = (STEREO | BACK_LEFT | BACK_RIGHT),
    CH_5POINT0 = (SURROUND | SIDE_LEFT | SIDE_RIGHT),
    CH_5POINT1 = (CH_5POINT0 | LOW_FREQUENCY),
    CH_5POINT0_BACK = (SURROUND | BACK_LEFT | BACK_RIGHT),
    CH_5POINT1_BACK = (CH_5POINT0_BACK | LOW_FREQUENCY),
    CH_6POINT0 = (CH_5POINT0 | BACK_CENTER),
    CH_6POINT0_FRONT = (CH_2_2 | FRONT_LEFT_OF_CENTER | FRONT_RIGHT_OF_CENTER),
    HEXAGONAL = (CH_5POINT0_BACK | BACK_CENTER),
    CH_6POINT1 = (CH_5POINT1 | BACK_CENTER),
    CH_6POINT1_BACK = (CH_5POINT1_BACK | BACK_CENTER),
    CH_6POINT1_FRONT = (CH_6POINT0_FRONT | LOW_FREQUENCY),
    CH_7POINT0 = (CH_5POINT0 | BACK_LEFT | BACK_RIGHT),
    CH_7POINT0_FRONT = (CH_5POINT0 | FRONT_LEFT_OF_CENTER | FRONT_RIGHT_OF_CENTER),
    CH_7POINT1 = (CH_5POINT1 | BACK_LEFT | BACK_RIGHT),
    CH_7POINT1_WIDE = (CH_5POINT1 | FRONT_LEFT_OF_CENTER | FRONT_RIGHT_OF_CENTER),
    CH_7POINT1_WIDE_BACK =
        (CH_5POINT1_BACK | FRONT_LEFT_OF_CENTER | FRONT_RIGHT_OF_CENTER),
    CH_3POINT1POINT2 = (CH_3POINT1 | TOP_FRONT_LEFT | TOP_FRONT_RIGHT),
    CH_5POINT1POINT2 = (CH_5POINT1 | TOP_SIDE_LEFT | TOP_SIDE_RIGHT),
    CH_5POINT1POINT4 = (CH_5POINT1 | TOP_FRONT_LEFT | TOP_FRONT_RIGHT |
                        TOP_BACK_LEFT | TOP_BACK_RIGHT),
    CH_7POINT1POINT2 = (CH_7POINT1 | TOP_SIDE_LEFT | TOP_SIDE_RIGHT),
    CH_7POINT1POINT4 = (CH_7POINT1 | TOP_FRONT_LEFT | TOP_FRONT_RIGHT |
                        TOP_BACK_LEFT | TOP_BACK_RIGHT),
    CH_9POINT1POINT4 = (CH_7POINT1POINT4 | WIDE_LEFT | WIDE_RIGHT),
    CH_9POINT1POINT6 = (CH_9POINT1POINT4 | TOP_SIDE_LEFT | TOP_SIDE_RIGHT),
    CH_10POINT2 = (FRONT_LEFT | FRONT_RIGHT | FRONT_CENTER |
                   TOP_FRONT_LEFT | TOP_FRONT_RIGHT | BACK_LEFT |
                   BACK_RIGHT | BACK_CENTER | SIDE_LEFT |
                   SIDE_RIGHT | WIDE_LEFT | WIDE_RIGHT),
    CH_22POINT2 = (CH_7POINT1POINT4 | FRONT_LEFT_OF_CENTER | FRONT_RIGHT_OF_CENTER |
                   BACK_CENTER | TOP_CENTER | TOP_FRONT_CENTER |
                   TOP_BACK_CENTER | TOP_SIDE_LEFT | TOP_SIDE_RIGHT |
                   BOTTOM_FRONT_LEFT | BOTTOM_FRONT_RIGHT |
                   BOTTOM_FRONT_CENTER | LOW_FREQUENCY_2),
    OCTAGONAL = (CH_5POINT0 | BACK_LEFT | BACK_CENTER | BACK_RIGHT),
    HEXADECAGONAL =
        (OCTAGONAL | WIDE_LEFT | WIDE_RIGHT | TOP_BACK_LEFT |
         TOP_BACK_RIGHT | TOP_BACK_CENTER | TOP_FRONT_CENTER |
         TOP_FRONT_LEFT | TOP_FRONT_RIGHT),
    STEREO_DOWNMIX = (STEREO_LEFT | STEREO_RIGHT),

    HOA_FIRST = AMBISONICS_ACN0 | AMBISONICS_ACN1 | AMBISONICS_ACN2 |
                AMBISONICS_ACN3,
    HOA_SECOND = HOA_FIRST | AMBISONICS_ACN4 | AMBISONICS_ACN5 |
                 AMBISONICS_ACN6 | AMBISONICS_ACN7 | AMBISONICS_ACN8,
    HOA_THIRD = HOA_SECOND | AMBISONICS_ACN9 | AMBISONICS_ACN10 |
                AMBISONICS_ACN11 | AMBISONICS_ACN12 |
                AMBISONICS_ACN13 | AMBISONICS_ACN14 |
                AMBISONICS_ACN15,
} AudioChannelLayout;
#ifdef __cplusplus
}
#endif
#endif // AVCODEC_AUDIO_CHANNEL_LAYOUT_H
/** @} */
