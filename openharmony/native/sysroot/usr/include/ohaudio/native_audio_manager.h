/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
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
 * @addtogroup OHAudio
 * @{
 *
 * @brief Provide the definition of the C interface for the audio module.
 *
 * @syscap SystemCapability.Multimedia.Audio.Core
 *
 * @since 12
 * @version 1.0
 */

/**
 * @file native_audio_manager.h
 *
 * @brief Declare audio manager related interfaces.
 *
 * @library libohaudio.so
 * @syscap SystemCapability.Multimedia.Audio.Core
 * @kit AudioKit
 * @since 12
 * @version 1.0
 */
#ifndef NATIVE_AUDIO_MANAGER_H
#define NATIVE_AUDIO_MANAGER_H

#include "native_audio_common.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Declare the audio manager.
 * The handle of audio manager is used for audio management related functions.
 *
 * @since 12
 */
typedef struct OH_AudioManager OH_AudioManager;

/**
 * @brief Get audio manager handle.
 *
 * @param audioManager the {@link OH_AudioManager} handle received from this function.
 * @return Function result code:
 *         {@link AUDIOCOMMON_RESULT_SUCCESS} If the execution is successful.
 *         {@link AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM}:
 *                                                        1.The param of audioManager is nullptr;
 * @since 12
 */
OH_AudioCommon_Result OH_GetAudioManager(OH_AudioManager **audioManager);

/**
 * @brief Get audio scene.
 * @param audioManager the {@link OH_AudioManager} handle received from {@link OH_GetAudioManager}.
 * @param scene the {@link OH_AudioScene} pointer to receive the result.
 * @return Function result code:
 *         {@link AUDIOCOMMON_RESULT_SUCCESS} If the execution is successful.
 *         {@link AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM}:
 *                                                        1.The param of audioManager is nullptr;
 *                                                        2.The param of scene is nullptr.
 * @since 12
 */
OH_AudioCommon_Result OH_GetAudioScene(OH_AudioManager* manager, OH_AudioScene *scene);

#ifdef __cplusplus
}
#endif
/** @} */
#endif // NATIVE_AUDIO_ROUTING_MANAGER_H