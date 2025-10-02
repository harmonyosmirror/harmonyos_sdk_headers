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
 * @addtogroup AVTranscoder
 * @{
 *
 * @brief Provides APIs of request capability for Transcoder.
 *
 * @syscap SystemCapability.Multimedia.Media.AVTranscoder
 * @since 20
 * @}
 */

 /**
 * @file avtranscoder.h
 *
 * @brief Defines the avtranscoder APIs. Uses the Native APIs provided by Media AVTranscoder
 *        to transcode a source video file to a new video file.
 *
 * @kit MediaKit
 * @library libavtranscoder.so
 * @syscap SystemCapability.Multimedia.Media.AVTranscoder
 * @since 20
 */

#ifndef MULTIMEDIA_PLAYER_FRAMEWORK_AVTRANSCODER_H
#define MULTIMEDIA_PLAYER_FRAMEWORK_AVTRANSCODER_H

#include <stdint.h>
#include <stdio.h>
#include "avtranscoder_base.h"
#include "native_avcodec_base.h"
#include "native_averrors.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Create a transcoder config
 * @return Returns a pointer to an OH_AVTranscoder_Config instance for success, nullptr for failure
 * @since 20
 */
OH_AVTranscoder_Config *OH_AVTranscoderConfig_Create();

/**
 * @brief release a transcoder config instance.
 * @param {OH_AVTranscoder_Config*} config Pointer to an OH_AVTranscoder_Config instance.
 * @return @return Function result code.
 *          {@link AV_ERR_OK} if the execution is successful.
 *          {@link AV_ERR_INVALID_VAL} if input config is nullptr.
 * @since 20
 */
OH_AVErrCode OH_AVTranscoderConfig_Release(OH_AVTranscoder_Config* config);

/**
 * @brief Set Source file descriptor for transcoding.
 * @param {OH_AVTranscoder_Config*} config Pointer to an OH_AVTranscoder_Config instance.
 * @param {int32_t} srcFd Source file descriptor.
 * @param {int64_t} srcOffset The offset into the file where the data to be read, in bytes.
 * @param {int64_t} length The length in bytes of the data to be read
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input config is nullptr or file related parameter error.
 * @since 20
 */
OH_AVErrCode OH_AVTranscoderConfig_SetSrcFD(
    OH_AVTranscoder_Config *config, int32_t srcFd, int64_t srcOffset, int64_t length);

/**
 * @brief Set destination file descriptor for transcoding.
 * @param {OH_AVTranscoder_Config*} config Pointer to an OH_AVTranscoder_Config instance
 * @param {int32_t} dstFd Destination file descriptor
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input config is nullptr or dstFd is invalid.
 * @since 20
 */
OH_AVErrCode OH_AVTranscoderConfig_SetDstFD(OH_AVTranscoder_Config *config, int32_t dstFd);

/**
 * @brief Set destination video mime type.
 * @param {OH_AVTranscoder_Config*} config Pointer to an OH_AVTranscoder_Config instance
 * @param {const char*} mimeType Destination video mime type. See native_avcodec_base.h
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input config is nullptr or mimeType is unrecognized.
 * @since 20
 */
OH_AVErrCode OH_AVTranscoderConfig_SetDstVideoType(OH_AVTranscoder_Config *config, const char *mimeType);

/**
 * @brief Set destination audio mime type.
 * @param {OH_AVTranscoder_Config*} config Pointer to an OH_AVTranscoder_Config instance
 * @param {const char*} mimeType Destination audio mime type. See native_avcodec_base.h
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input config is nullptr or mimeType is unrecognized.
 * @since 20
 */
OH_AVErrCode OH_AVTranscoderConfig_SetDstAudioType(OH_AVTranscoder_Config *config, const char *mimeType);

/**
 * @brief Set destination file type.
 * @param {OH_AVTranscoder_Config*} config Pointer to an OH_AVTranscoder_Config instance
 * @param {OH_AVOutputFormat} mimeType Destination file type. See native_avcodec_base.h
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input config is nullptr or mimeType is invalid.
 * @since 20
 */
OH_AVErrCode OH_AVTranscoderConfig_SetDstFileType(OH_AVTranscoder_Config *config, OH_AVOutputFormat mimeType);

/**
 * @brief Set destination audio bitrate.
 * @param {OH_AVTranscoder_Config*} config Pointer to an OH_AVTranscoder_Config instance
 * @param {int32_t} bitrate Destination audio bitrate.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input config is nullptr or bitrate value is invalid.
 * @since 20
 */
OH_AVErrCode OH_AVTranscoderConfig_SetDstAudioBitrate(OH_AVTranscoder_Config *config, int32_t bitrate);

/**
 * @brief Set destination video bitrate.
 * @param {OH_AVTranscoder_Config*} config Pointer to an OH_AVTranscoder_Config instance
 * @param {int32_t} bitrate Destination video bitrate.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input config is nullptr or bitrate value is invalid.
 * @since 20
 */
OH_AVErrCode OH_AVTranscoderConfig_SetDstVideoBitrate(OH_AVTranscoder_Config *config, int32_t bitrate);

/**
 * @brief Set destination video resolution.
 * @param {OH_AVTranscoder_Config*} config Pointer to an OH_AVTranscoder_Config instance
 * @param {int32_t} width Destination for video width.
 * @param {int32_t} height Destination for video height.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input config is nullptr or width/height value is invalid.
* @since 20
 */
OH_AVErrCode OH_AVTranscoderConfig_SetDstVideoResolution(OH_AVTranscoder_Config *config, int32_t width, int32_t height);

/**
 * @brief Create a transcoder
 * @return {OH_AVTranscoder*} Returns a pointer to an OH_AVTranscoder instance for success, nullptr for failure
 * @since 20
 */
OH_AVTranscoder *OH_AVTranscoder_Create(void);

/**
 * @brief Prepare for transcoding with a config.
 * @param {OH_AVTranscoder*} transcoder Pointer to an OH_AVTranscoder instance
 * @param {OH_AVTranscoder_Config*} config Pointer to an OH_AVTranscoder_Config instance,
 *        see {@link OH_AVTranscoder_Config}
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input transcoder is nullptr or transcoder Prepare failed.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if the operation of Prepare not allowed.
 *         {@link AV_ERR_IO} if Errors related to IO access
 *         {@link AV_ERR_SERVICE_DIED} if media service died.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if unsupported format.
 * @since 20
 */
OH_AVErrCode OH_AVTranscoder_Prepare(OH_AVTranscoder *transcoder, OH_AVTranscoder_Config *config);

/**
 * @brief Start AVTranscoder.
 * @param {OH_AVTranscoder*} transcoder Pointer to an OH_AVTranscoder instance
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input transcoder is nullptr or transcoder start failed.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if the operation of Start not allowed.
 *         {@link AV_ERR_IO} if errors related to IO access.
 *         {@link AV_ERR_SERVICE_DIED} if media service died.
 * @since 20
 */
OH_AVErrCode OH_AVTranscoder_Start(OH_AVTranscoder *transcoder);

/**
 * @brief Pause AVTranscoder.
 * @param {OH_AVTranscoder*} transcoder Pointer to an OH_AVTranscoder instance
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input transcoder is nullptr or transcoder pause failed.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if the operation of Start not allowed.
 *         {@link AV_ERR_IO} if errors related to IO access.
 *         {@link AV_ERR_SERVICE_DIED} if media service died.
 * @since 20
 */
OH_AVErrCode OH_AVTranscoder_Pause(OH_AVTranscoder *transcoder);

/**
 * @brief Resume AVTranscoder.
 * @param {OH_AVTranscoder*} transcoder Pointer to an OH_AVTranscoder instance
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input transcoder is nullptr or transcoder resume failed.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if the operation of Start not allowed.
 *         {@link AV_ERR_IO} if errors related to IO access.
 *         {@link AV_ERR_SERVICE_DIED} if media service died.
 * @since 20
 */
OH_AVErrCode OH_AVTranscoder_Resume(OH_AVTranscoder *transcoder);

/**
 * @brief Cancel AVTranscoder.
 * @param {OH_AVTranscoder*} transcoder Pointer to an OH_AVTranscoder instance
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input transcoder is nullptr or transcoder stop failed.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if the operation of Start not allowed.
 *         {@link AV_ERR_IO} if errors related to IO access.
 *         {@link AV_ERR_SERVICE_DIED} if media service died.
 * @since 20
 */
OH_AVErrCode OH_AVTranscoder_Cancel(OH_AVTranscoder *transcoder);

/**
 * @brief Release AVTranscoder.
 * @param {OH_AVTranscoder*} transcoder Pointer to an OH_AVTranscoder instance
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input transcoder is nullptr or transcoder release failed.
 *         {@link AV_ERR_OPERATE_NOT_PERMIT} if the operation of Start not allowed.
 *         {@link AV_ERR_IO} if errors related to IO access.
 *         {@link AV_ERR_SERVICE_DIED} if media service died.
 * @since 20
 */
OH_AVErrCode OH_AVTranscoder_Release(OH_AVTranscoder *transcoder);

/**
 * @brief Set the state callback function so that your application can respond to the
 * state change events generated by the avtranscoder. This interface must be called before Start is called.
 * @param {OH_AVTranscoder*} transcoder Pointer to an OH_AVTranscoder instance
 * @param {OH_AVTranscoder_OnStateChange} callback State callback function, see {@link OH_AVTranscoder_OnStateChange}
 * @param {void*} userData Pointer to user specific data
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input transcoder is nullptr or input callback is nullptr.
 * @since 20
 */
OH_AVErrCode OH_AVTranscoder_SetStateCallback(
    OH_AVTranscoder *transcoder, OH_AVTranscoder_OnStateChange callback, void *userData);

/**
 * @brief Set the error callback function so that your application can respond to the
 * error events generated by the avtranscoder. This interface must be called before Start is called.
 * @param {OH_AVTranscoder*} transcoder Pointer to an OH_AVTranscoder instance
 * @param {OH_AVTranscoder_OnError} callback Error callback function, see {@link OH_AVTranscoder_OnError}
 * @param {void*} userData Pointer to user specific data
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input transcoder is nullptr or input callback is nullptr.
 * @since 20
 */
OH_AVErrCode OH_AVTranscoder_SetErrorCallback(
    OH_AVTranscoder *transcoder, OH_AVTranscoder_OnError callback, void *userData);

/**
 * @brief Set the progress updating callback function so that your application can respond to the
 * progress updating events generated by the avtranscoder. This interface must be called before Start is called.
 * @param {OH_AVTranscoder*} transcoder Pointer to an OH_AVTranscoder instance
 * @param {OH_AVTranscoder_OnProgressUpdate} callback Uri callback function,
 *        see {@link OH_AVTranscoder_OnProgressUpdate}
 * @param {void*} userData Pointer to user specific data
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input transcoder is nullptr or input callback is nullptr.
 * @since 20
 */
OH_AVErrCode OH_AVTranscoder_SetProgressUpdateCallback(
    OH_AVTranscoder *transcoder, OH_AVTranscoder_OnProgressUpdate callback, void *userData);

/**
 * @brief Enable B frame in destination video.
 * @param {OH_AVTranscoder_Config*} config Pointer to an OH_AVTranscoder_Config instance
 * @param {bool} enabled Whecher enable B Frame. If this function is not called, B Frame is disabled.
 * @return Function result code.
 *         {@link AV_ERR_OK} if the execution is successful.
 *         {@link AV_ERR_INVALID_VAL} if input config is nullptr.
 * @since 20
 */
OH_AVErrCode OH_AVTranscoderConfig_EnableBFrame(OH_AVTranscoder_Config *config, bool enabled);

#ifdef __cplusplus
}
#endif

#endif // MULTIMEDIA_PLAYER_FRAMEWORK_AVTRANSCODER_H