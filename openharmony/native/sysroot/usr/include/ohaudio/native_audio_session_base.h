/*
 * Copyright (c) 2026 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * You may not use this file except in compliance with the License.
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
 * @addtogroup OHAudio
 * @{
 *
 * @brief Provides the definition of the C interface for the audio module.
 *
 * @since 24
 * @version 1.0
 */

/**
 * @file native_audio_session_base.h
 *
 * @brief Declares the audio session base data structure.
 *
 * @library libohaudio.so
 * @syscap SystemCapability.Multimedia.Audio.Core
 * @kit AudioKit
 * @since 24
 * @version 1.0
 */

#ifndef NATIVE_AUDIO_SESSION_BASE_H
#define NATIVE_AUDIO_SESSION_BASE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates the audio session behavior flags.
 *
 * @since 24
 */
typedef enum {
    /**
     * @brief Default behavior, used to clear behavior settings.
     *
     * @since 24
     */
    DEFAULT_BEHAVIOR  = 0x00000000,

    /**
     * @brief When the audio stream is interrupted by the system, it will be muted.
     * The application will receive an {@link #AUDIOSTREAM_INTERRUPT_HINT_MUTE} notification when playback is muted
     * and an {@link #AUDIOSTREAM_INTERRUPT_HINT_UNMUTE} notification when playback is resumed.
     *
     * @since 24
     */
    MUTE_WHEN_INTERRUPTED = 0x00000002,
} OH_AudioSession_BehaviorFlags;

/**
 * @brief Declares the audio concurrency modes.
 *
 * @since 12
 */
typedef enum {
    /**
     * @brief Default mode
     */
    CONCURRENCY_DEFAULT = 0,

    /**
     * @brief Mix with others mode
     */
    CONCURRENCY_MIX_WITH_OTHERS = 1,

    /**
     * @brief Duck others mode
     */
    CONCURRENCY_DUCK_OTHERS = 2,

    /**
     * @brief Pause others mode
     */
    CONCURRENCY_PAUSE_OTHERS = 3,
} OH_AudioSession_ConcurrencyMode;

/**
 * @brief Declares the audio session strategy.
 *
 * @since 12
 */
typedef struct OH_AudioSession_Strategy {
    /**
     * @brief Audio session concurrency mode
     */
    OH_AudioSession_ConcurrencyMode concurrencyMode;
} OH_AudioSession_Strategy;

#ifdef __cplusplus
}
#endif

#endif // NATIVE_AUDIO_SESSION_BASE_H
/** @} */
