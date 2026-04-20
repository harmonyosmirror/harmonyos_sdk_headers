/*
 * Copyright (C) 2024-2026 Huawei Device Co., Ltd.
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
 * @addtogroup OHAVSession
 * @{
 *
 * @brief Provide the definition of the C interface for the avsession module.
 * @since 13
 */

/**
 * @file native_avsession_errors.h
 *
 * @brief Declare avsession related error.
 *
 * @library libohavsession.so
 * @syscap SystemCapability.Multimedia.AVSession.Core
 * @kit AVSessionKit
 * @since 13
 */

#ifndef NATIVE_AVSESSION_ERRORS_H
#define NATIVE_AVSESSION_ERRORS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief AVSession error code
 *
 * @since 13
 * @version 1.0
 */
typedef enum {
    /**
     * @error The operation completed successfully.
     */
    AV_SESSION_ERR_SUCCESS = 0,

    /**
     * @error Invalid parameter。
     */
    AV_SESSION_ERR_INVALID_PARAMETER = 401,

    /**
     * @error Service exception.
     */
    AV_SESSION_ERR_SERVICE_EXCEPTION = 6600101,

    /**
     * @error The session does not exist.
     */
    AV_SESSION_ERR_CODE_SESSION_NOT_EXIST = 6600102,

    /**
     * @error Invalid session command.
     */
    AV_SESSION_ERR_CODE_COMMAND_INVALID = 6600105,

    /**
     * @error The session is not activated.
     */
    AV_SESSION_ERR_CODE_SESSION_INACTIVE = 6600106,

    /**
     * @error Too many commands or events.
     */
    AV_SESSION_ERR_CODE_MESSAGE_OVERLOAD = 6600107,

    /**
     * @error The remote connection is not established.
     * @since 23
     */
    AV_SESSION_ERR_CODE_REMOTE_CONNECTION_NOT_EXIST = 6600109,

    /**
     * The error code for cast control is unspecified.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_UNSPECIFIED = 6611000,

    /**
     * An unspecified error occurs in the remote player.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_REMOTE_ERROR = 6611001,

    /**
     * The playback position falls behind the live window.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_BEHIND_LIVE_WINDOW = 6611002,

    /**
     * The process of cast control times out.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_TIMEOUT = 6611003,

    /**
     * The runtime check failed.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_RUNTIME_CHECK_FAILED = 6611004,

    /**
     * Cross-device data transmission is locked.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_PLAYER_NOT_WORKING = 6611100,

    /**
     * The specified seek mode is not supported.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_SEEK_MODE_UNSUPPORTED = 6611101,

    /**
     * The position to seek to is out of the range of the media asset or the specified seek mode is not supported.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_ILLEGAL_SEEK_TARGET = 6611102,

    /**
     * The specified playback mode is not supported.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_PLAY_MODE_UNSUPPORTED = 6611103,

    /**
     * The specified playback speed is not supported.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_PLAY_SPEED_UNSUPPORTED = 6611104,

    /**
     * The action failed because either the media source device or the media sink device has been revoked.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_DEVICE_MISSING = 6611105,

    /**
     * The parameter is invalid, for example, the url is illegal to play.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_INVALID_PARAM = 6611106,

    /**
     * Allocation of memory failed.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_NO_MEMORY = 6611107,

    /**
     * Operation is not allowed.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_OPERATION_NOT_ALLOWED = 6611108,

    /**
     * An unspecified input/output error occurs.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_IO_UNSPECIFIED = 6612000,

    /**
     * Network connection failure.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_IO_NETWORK_CONNECTION_FAILED = 6612001,

    /**
     * Network timeout.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_IO_NETWORK_CONNECTION_TIMEOUT = 6612002,

    /**
     * Invalid "Content-Type" HTTP header.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_IO_INVALID_HTTP_CONTENT_TYPE = 6612003,

    /**
     * The HTTP server returns an unexpected HTTP response status code.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_IO_BAD_HTTP_STATUS = 6612004,

    /**
     * The file does not exist.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_IO_FILE_NOT_FOUND = 6612005,

    /**
     * No permission is granted to perform the IO operation.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_IO_NO_PERMISSION = 6612006,

    /**
     * Access to cleartext HTTP traffic is not allowed by the app's network security configuration.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_IO_CLEARTEXT_NOT_PERMITTED = 6612007,

    /**
     * Reading data out of the data bound.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_IO_READ_POSITION_OUT_OF_RANGE = 6612008,

    /**
     * The media does not contain any contents that can be played.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_IO_NO_CONTENTS = 6612100,

    /**
     * The media cannot be read, for example, because of dust or scratches.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_IO_READ_ERROR = 6612101,

    /**
     * This resource is already in use.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_IO_CONTENT_BUSY = 6612102,

    /**
     * The content using the validity interval has expired.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_IO_CONTENT_EXPIRED = 6612103,

    /**
     * Using the requested content to play is not allowed.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_IO_USE_FORBIDDEN = 6612104,

    /**
     * The use of the allowed content cannot be verified.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_IO_NOT_VERIFIED = 6612105,

    /**
     * The number of times this content has been used as requested has reached the maximum allowed number of uses.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_IO_EXHAUSTED_ALLOWED_USES = 6612106,

    /**
     * An error occurs when sending packet from source device to sink device.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_IO_NETWORK_PACKET_SENDING_FAILED = 6612107,

    /**
     * Unspecified error related to content parsing.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_PARSING_UNSPECIFIED = 6613000,

    /**
     * Parsing error associated with media container format bit streams.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_PARSING_CONTAINER_MALFORMED = 6613001,

    /**
     * Parsing error associated with the media manifest.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_PARSING_MANIFEST_MALFORMED = 6613002,

    /**
     * An error occurs when attempting to extract a file with an unsupported media container format
     * or an unsupported media container feature.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_PARSING_CONTAINER_UNSUPPORTED = 6613003,

    /**
     * Unsupported feature in the media manifest.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_PARSING_MANIFEST_UNSUPPORTED = 6613004,

    /**
     * Unspecified decoding error.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_DECODING_UNSPECIFIED = 6614000,

    /**
     * Decoder initialization failed.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_DECODING_INIT_FAILED = 6614001,

    /**
     * Decoder query failed.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_DECODING_QUERY_FAILED = 6614002,

    /**
     * Decoding the media samples failed.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_DECODING_FAILED = 6614003,

    /**
     * The format of the content to decode exceeds the capabilities of the device.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_DECODING_FORMAT_EXCEEDS_CAPABILITIES = 6614004,

    /**
     * The format of the content to decode is not supported.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_DECODING_FORMAT_UNSUPPORTED = 6614005,

    /**
     * Unspecified errors related to the audio renderer.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_AUDIO_RENDERER_UNSPECIFIED = 6615000,

    /**
     * Initializing the audio renderer failed.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_AUDIO_RENDERER_INIT_FAILED = 6615001,

    /**
     * The audio renderer fails to write data.
     * @since 23
     */
    AV_SESSION_ERR_CODE_CAST_CONTROL_AUDIO_RENDERER_WRITE_FAILED = 6615002,
} AVSession_ErrCode;

/**
 * @brief Defines enumeration of avsession callback result.
 *
 * @since 13
 */
typedef enum {
    /**
     * @brief Result of avsession callabck is success.
     */
    AVSESSION_CALLBACK_RESULT_SUCCESS = 0,

    /**
     * @brief Result of avsession callabck failed.
     */
    AVSESSION_CALLBACK_RESULT_FAILURE = -1,
} AVSessionCallback_Result;

/**
 * @brief AVMetadata error code
 *
 * @since 13
 * @version 1.0
 */
typedef enum {
    /**
     * @error The call was successful.
     */
    AVMETADATA_SUCCESS = 0,

    /**
     * @error This means that the function was executed with an invalid input parameter.
     */
    AVMETADATA_ERROR_INVALID_PARAM = 1,

    /**
     * @error This means there is no memory left.
     */
    AVMETADATA_ERROR_NO_MEMORY = 2,
} AVMetadata_Result;

/**
 * @brief AVQUEUEITEM error code
 *
 * @since 23
 * @version 1.0
 */
typedef enum {
    /**
     * @error The call was successful. 
     * @since 23
     */
    AVQUEUEITEM_SUCCESS = 0,

    /**
     * @error This means that the function was executed with an invalid input parameter.
     * @since 23
     */
    AVQUEUEITEM_ERROR_INVALID_PARAM = 1,

    /**
     * @error This means there is no memory left.
     * @since 23
     */
    AVQUEUEITEM_ERROR_NO_MEMORY = 2,
} AVQueueItem_Result;

#ifdef __cplusplus
}
#endif

#endif // NATIVE_AVSESSION_ERRORS_H
/** @} */
