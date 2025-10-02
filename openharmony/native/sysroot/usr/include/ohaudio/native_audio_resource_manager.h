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
 * @addtogroup OHAudio
 * @{
 *
 * @brief Provide the definition of the C interface for the audio module.
 *
 * @since 20
 */

/**
 * @file native_audio_resource_manager.h
 *
 * @brief Declare audio stream manager related interfaces.
 *
 * This file interfaces are used for the creation of AudioResourceManager.
 *
 * @library libohaudio.so
 * @syscap SystemCapability.Multimedia.Audio.Core
 * @kit AudioKit
 * @since 20
 */

#ifndef NATIVE_AUDIO_RESOURCE_MANAGER_H
#define NATIVE_AUDIO_RESOURCE_MANAGER_H

#include "native_audio_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Declare the audio resource manager.
 *     Audio resource manager provides many functions for developer to manage system resources to avoid
 *     underrun or overrun in audio playback and recording.
 *
 * @since 20
 */
typedef struct OH_AudioResourceManager OH_AudioResourceManager;

/**
 * @brief Fetch the audio resource manager handle, which is a singleton.
 *
 * @param resourceManager output parameter to get {@link #OH_AudioResourceManager}.
 * @return
 *     {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 *     {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if input param is nullptr
 * @since 20
 */
OH_AudioCommon_Result OH_AudioManager_GetAudioResourceManager(OH_AudioResourceManager **resourceManager);

/**
 * @brief Declare the audio workgroup.
 *     The handle of audio workgroup is used for workgroup related functions.
 *     The system will manage cpu resources on a workgroup basis instead of thread.
 *     For parallel task threads, you can add them into one workgroup, and for
 *     asynchronous task threads, use one workgroup for each thread.
 *     There is an upper limit to the total number of workgroups for each process,
 *     so application should release the workgroup which is no longer in use.
 *
 * @since 20
 */
typedef struct OH_AudioWorkgroup OH_AudioWorkgroup;

/**
 * @brief Create a workgroup for audio data processing threads in application.
 *     System manages cpu resources by workgroup configuration.
 *
 * @param resourceManager {@link OH_AudioResourceManager} handle
 *     provided by {@link OH_AudioManager_GetAudioRoutingManager}.
 * @param name workgroup name
 * @param group {@link OH_AudioWorkgroup} handle for managing audio data processing threads.
 * @return
 *     {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 *     {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if input param is nullptr
 *     {@link #AUDIOCOMMON_RESULT_ERROR_NO_MEMORY} out of workgroup resources
 *     {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} system process error occurs
 * @since 20
 */
OH_AudioCommon_Result OH_AudioResourceManager_CreateWorkgroup(OH_AudioResourceManager *resourceManager,
    const char *name, OH_AudioWorkgroup **group);

/**
 * @brief Release the workgroup created before.
 *
 * @param resourceManager {@link OH_AudioResourceManager} handle
 *     provided by {@link OH_AudioManager_GetAudioRoutingManager}.
 * @param group {@link OH_AudioWorkgroup} handle provided by {@link OH_AudioResourceManager_CreateWorkgroup}.
 * @return
 *     {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 *     {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if input param is nullptr
 *     {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} system process error occurs
 * @since 20
 */
OH_AudioCommon_Result OH_AudioResourceManager_ReleaseWorkgroup(OH_AudioResourceManager *resourceManager,
    OH_AudioWorkgroup *group);

/**
 * @brief Add current thread into a specified audio workgroup as audio data processing thread.
 *
 * @param group {@link OH_AudioWorkgroup} handle provided by {@link OH_AudioResourceManager_CreateWorkgroup}.
 * @param tokenId a token id that represent the thread added.
 * @return
 *     {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 *     {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if input param is nullptr
 *     {@link #AUDIOCOMMON_RESULT_ERROR_NO_MEMORY} out of resources for the new thread
 *     {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} system process error occurs
 * @since 20
 */
OH_AudioCommon_Result OH_AudioWorkgroup_AddCurrentThread(OH_AudioWorkgroup *group, int32_t *tokenId);

/**
 * @brief Remove the thread from a specified audio workgroup.
 *
 * @param group {@link OH_AudioWorkgroup} handle provided by {@link OH_AudioResourceManager_CreateWorkgroup}.
 * @param tokenId id for thread returned by {link OH_AudioWorkgroup_AddCurrentThread}
 * @return
 *     {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 *     {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if input param is nullptr or token id is invalid
 *     {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} system process error occurs
 * @since 20
 */
OH_AudioCommon_Result OH_AudioWorkgroup_RemoveThread(OH_AudioWorkgroup *group, int32_t tokenId);

/**
 * @brief Notify system the audio workgroup start working. Call this function before processing the audio frame.
 *
 * @param group {@link OH_AudioWorkgroup} handle provided by {@link OH_AudioResourceManager_CreateWorkgroup}.
 * @param startTime the time when audio thread start working, using system time. The unit of time is milliseconds.
 * @param deadlineTime the time before which audio work should be finished, otherwise underrun may happens.
 *     The unit of time is milliseconds.
 * @return
 *     {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 *     {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if input param is nullptr, or time is invalid
 *     {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} system process error occurs
 * @since 20
 */
OH_AudioCommon_Result OH_AudioWorkgroup_Start(OH_AudioWorkgroup *group, uint64_t startTime, uint64_t deadlineTime);

/**
 * @brief Notify system the audio workgroup stop working. Call this function after the audio frame processing
 *     is completed.
 *
 * @param group {@link OH_AudioWorkgroup} handle provided by {@link OH_AudioResourceManager_CreateWorkgroup}.
 * @return
 *     {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds
 *     {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if input param is nullptr
 *     {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} system process error occurs
 * @since 20
 */
OH_AudioCommon_Result OH_AudioWorkgroup_Stop(OH_AudioWorkgroup *group);

#ifdef __cplusplus
}
#endif
 
#endif // NATIVE_AUDIO_RESOURCE_MANAGER_H
/** @} */
