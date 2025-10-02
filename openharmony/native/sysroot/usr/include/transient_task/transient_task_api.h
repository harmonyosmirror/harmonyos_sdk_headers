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
 * @addtogroup TransientTask
 * @{
 *
 * @brief Provide C interface for the Transient task management.
 *
 * @since 13
 * @version 1.0
 */

/**
 * @file transient_task_api.h
 *
 * @brief Declares the APIs for Transient task management.
 *
 * @library libtransient_task.so
 * @kit BackgroundTasksKit
 * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask
 * @since 13
 */

#ifndef OHOS_BACKGROUOND_TASK_MANAGER_TRANSIENT_TASK_API_H
#define OHOS_BACKGROUOND_TASK_MANAGER_TRANSIENT_TASK_API_H

#include <stdint.h>

#include "transient_task_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Requests delayed transition to the suspended state.
 *
 * @param reason Indicates the reason for delayed transition to the suspended state.
 * @param callback Indicates the callback delay time expired.
 * @param delaySuspendInfo Indicates the info of delay request.
 * @return {@link ERR_TRANSIENT_TASK_OK} 0 - Success.
 *         {@link ERR_TRANSIENT_TASK_INVALID_PARAM} 401 - Invalid parameter.
 *         {@link ERR_TRANSIENT_TASK_PARCEL_FAILED} 9800002 - Parcelable failed.
 *         {@link ERR_TRANSIENT_TASK_TRANSACTION_FAILED} 9800003 - Transact failed.
 *         {@link ERR_TRANSIENT_TASK_SYS_NOT_READY} 9800004 - System service not ready.
 *         {@link ERR_TRANSIENT_TASK_CLIENT_INFO_VERIFICATION_FAILED} 9900001 - uid or pid info verify failed.
 *         {@link ERR_TRANSIENT_TASK_SERVICE_VERIFICATION_FAILED} 9900002 - Transient task verification failed.
 * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask
 * @since 13
 * @version 1.0
 */
int32_t OH_BackgroundTaskManager_RequestSuspendDelay(const char* reason,
    TransientTask_Callback callback, TransientTask_DelaySuspendInfo *info);

/**
 * @brief Obtains the remaining time before an application enters the suspended state.
 *
 * @param requestId Indicates the identifier of the delay request.
 * @param time Indicates the remaining Time.
 * @return {@link ERR_TRANSIENT_TASK_OK} 0 - Success.
 *         {@link ERR_TRANSIENT_TASK_INVALID_PARAM} 401 - Invalid parameter.
 *         {@link ERR_TRANSIENT_TASK_PARCEL_FAILED} 9800002 - Parcelable failed.
 *         {@link ERR_TRANSIENT_TASK_TRANSACTION_FAILED} 9800003 - Transact failed.
 *         {@link ERR_TRANSIENT_TASK_SYS_NOT_READY} 9800004 - System service not ready.
 *         {@link ERR_TRANSIENT_TASK_CLIENT_INFO_VERIFICATION_FAILED} 9900001 - uid or pid info verify failed.
 *         {@link ERR_TRANSIENT_TASK_SERVICE_VERIFICATION_FAILED} 9900002 - Transient task verification failed.
 * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask
 * @since 13
 * @version 1.0
 */
int32_t OH_BackgroundTaskManager_GetRemainingDelayTime(int32_t requestId, int32_t *delayTime);

/**
 * @brief Cancels delayed transition to the suspended state.
 *
 * @param requestId Indicates the identifier of the delay request.
 * @return {@link ERR_TRANSIENT_TASK_OK} 0 - Success.
 *         {@link ERR_TRANSIENT_TASK_INVALID_PARAM} 401 - Invalid parameter.
 *         {@link ERR_TRANSIENT_TASK_PARCEL_FAILED} 9800002 - Parcelable failed.
 *         {@link ERR_TRANSIENT_TASK_TRANSACTION_FAILED} 9800003 - Transact failed.
 *         {@link ERR_TRANSIENT_TASK_SYS_NOT_READY} 9800004 - System service not ready.
 *         {@link ERR_TRANSIENT_TASK_CLIENT_INFO_VERIFICATION_FAILED} 9900001 - uid or pid info verify failed.
 *         {@link ERR_TRANSIENT_TASK_SERVICE_VERIFICATION_FAILED} 9900002 - Transient task verification failed.
 * @syscap SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask
 * @since 13
 * @version 1.0
 */
int32_t OH_BackgroundTaskManager_CancelSuspendDelay(int32_t requestId);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
