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
 * @addtogroup AVSinkBase
 * @{
 *
 * @brief The AVSinkBase module provides variables, properties, and functions
 * for lowpower audio sink and lowpower video sink.
 *
 * @since 20
 */

/**
 * @file lowpower_avsink_base.h
 *
 * @brief Declare the Native API used for lowpower audio sink
 * and lowpower video sink.
 *
 * @library liblowpower_avsink.so
 * @kit MediaKit
 * @syscap SystemCapability.Multimedia.Media.LowPowerAVSink
 * @since 20
 */

#ifndef NATIVE_LOWPOWER_AVSINK_BASE_H
#define NATIVE_LOWPOWER_AVSINK_BASE_H

#include <stdint.h>
#include "native_averrors.h"
#include "native_avbuffer.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Forward declaration of OH_AVSamplesBuffer.
 *
 * @since 20
 */
typedef struct OH_AVSamplesBuffer OH_AVSamplesBuffer;

/**
 * @brief Forward declaration of OH_LowPowerAVSink_Capability.
 *
 * @since 20
 */
typedef struct OH_LowPowerAVSink_Capability OH_LowPowerAVSink_Capability;

/**
 * @brief Append one OH_AVBuffer data to framePacketBuffer instance.
 *
 * @param samplesBuffer OH_AVSamplesBuffer instance
 * @param avBuffer OH_AVBuffer buffer will be appended to
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}.
 * {@link AV_ERR_INVALID_VAL}, the samplesBuffer or the avBuffer or data pointer is nullptr or invalid.
 * {@link AV_ERR_NO_MEMORY}, the framePacketBuffer has no enough remained capacity to append one OH_AVBuffer.
 * {@link AV_ERR_UNKNOWN}, unknown error.
 * @since 20
 */
OH_AVErrCode OH_AVSamplesBuffer_AppendOneBuffer(OH_AVSamplesBuffer *samplesBuffer, OH_AVBuffer *avBuffer);

/**
 * @brief Get remained capacity of OH_AVSamplesBuffer instance.
 *
 * @param {OH_AVSamplesBuffer} samplesBuffer OH_AVSamplesBuffer instance
 * @return Returns remained capacity of OH_AVSamplesBuffer instance,
 * return -1 if samplesBuffer or data poniter is is nullptr or invalid.
 * @since 20
 */
int32_t OH_AVSamplesBuffer_GetRemainedCapacity(OH_AVSamplesBuffer *samplesBuffer);

/**
 * @brief Query the supported capabilities of a lowpower audio/video sink.
 *
 * This function queries and returns the capability set supported by the current
 * lowpower audio/video sink, including but not limited to supported media formats, etc.
 *
 * @return {OH_LowPowerAVSink_Capability*}
 * - A pointer to the capability structure if the sink supports capability queries and the query is successful.
 * - nullptr if the sink does not support capability queries or the query fails.
 *
 * @since 21
 */
OH_LowPowerAVSink_Capability *OH_LowPowerAVSink_GetCapability();
#ifdef __cplusplus
}
#endif
#endif // NATIVE_LOWPOWER_AVSINK_BASE_H

/** @} */