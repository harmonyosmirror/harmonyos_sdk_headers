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
 * @addtogroup OH_PictureInPicture
 * @{
 *
 * @file oh_window_pip.h
 *
 * @brief Declares C APIs for picture in picture window
 *
 * @kit ArkUI
 * @library libnative_window_manager.so
 * @syscap SystemCapability.Window.SessionManager
 * @since 20
 * @version 1.0
 */
#ifndef OH_WINDOW_PIP_H
#define OH_WINDOW_PIP_H

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Picture in picture config.
 * @since 20
 */
typedef void* PictureInPicture_PipConfig;

/**
 * @brief Enumerates picture in picture template type.
 * @since 20
 */
typedef enum {
    /** Video play. */
    VIDEO_PLAY = 0,
    /** Video call. */
    VIDEO_CALL = 1,
    /** Video meeting. */
    VIDEO_MEETING = 2,
    /** Video live. */
    VIDEO_LIVE = 3,
} PictureInPicture_PipTemplateType;

/**
 * @brief Enumerates picture in picture control group.
 * @since 20
 */
typedef enum {
    /** Previous/next control group for video play. */
    VIDEO_PLAY_VIDEO_PREVIOUS_NEXT = 101,
    /** Fast forward/backward control group for video play. */
    VIDEO_PLAY_FAST_FORWARD_BACKWARD = 102,
    /** Switch on/off the microphone control group for video call. */
    VIDEO_CALL_MICROPHONE_SWITCH = 201,
    /** Hang up control group for video call. */
    VIDEO_CALL_HANG_UP_BUTTON = 202,
    /** Switch on/off the camera control group for video call. */
    VIDEO_CALL_CAMERA_SWITCH = 203,
    /** Mute control group for video call. */
    VIDEO_CALL_MUTE_SWITCH = 204,
    /** Hang up control group for video meeting. */
    VIDEO_MEETING_HANG_UP_BUTTON = 301,
    /** Switch on/off the camera control group for video meeting. */
    VIDEO_MEETING_CAMERA_SWITCH = 302,
    /** Mute control group for video meeting. */
    VIDEO_MEETING_MUTE_SWITCH = 303,
    /** Switch on/off the microphone control group for video meeting. */
    VIDEO_MEETING_MICROPHONE_SWITCH = 304,
    /** Video play/pause control group for video live. */
    VIDEO_LIVE_VIDEO_PLAY_PAUSE = 401,
    /** Mute control group for video live. */
    VIDEO_LIVE_MUTE_SWITCH = 402,
} PictureInPicture_PipControlGroup;

/**
 * @brief Enumerates picture in picture control type.
 * @since 20
 */
typedef enum {
    /** Video play/pause. */
    VIDEO_PLAY_PAUSE = 0,
    /** Video previous. */
    VIDEO_PREVIOUS = 1,
    /** Video next. */
    VIDEO_NEXT = 2,
    /** Video fast forward. */
    FAST_FORWARD = 3,
    /** Video back forward. */
    FAST_BACKWARD = 4,
    /** Hang up. */
    HANG_UP_BUTTON = 5,
    /** Microphone switch. */
    MICROPHONE_SWITCH = 6,
    /** camera switch. */
    CAMERA_SWITCH = 7,
    /** mute switch. */
    MUTE_SWITCH = 8,
} PictureInPicture_PipControlType;

/**
 * @brief Enumerates picture in picture control status.
 * @since 20
 */
typedef enum {
    /** Play. */
    PLAY = 1,
    /** Pause. */
    PAUSE = 0,
    /** Open. */
    OPEN = 1,
    /** Close. */
    CLOSE = 0,
} PictureInPicture_PipControlStatus;

/**
 * @brief Enumerates picture in picture state.
 * @since 20
 */
typedef enum {
    /** About to start. */
    ABOUT_TO_START = 1,
    /** started. */
    STARTED = 2,
    /** About to stop. */
    ABOUT_TO_STOP = 3,
    /** stopped. */
    STOPPED = 4,
    /** About to restore. */
    ABOUT_TO_RESTORE = 5,
    /** Error. */
    ERROR = 6,
} PictureInPicture_PipState;

/**
 * @brief Start the picture-in-picture callback
 * @param controllerId The picture-in-picture controller ID
 * @param requestId The picture-in-picture requestId
 * @param surfaceId The picture-in-picture surfaceId
 * @since 20
 */
typedef void (*WebPipStartPipCallback)(uint32_t controllerId, uint8_t requestId, uint64_t surfaceId);

/**
 * @brief The picture-in-picture lifecycle callback
 * @param controllerId The picture-in-picture controller ID
 * @param state The picture-in-picture state
 * @param errcode The picture-in-picture error code
 * @since 20
 */
typedef void (*WebPipLifecycleCallback)(uint32_t controllerId, PictureInPicture_PipState state, int32_t errcode);

/**
 * @brief The picture-in-picture control event callback
 * @param controllerId The picture-in-picture controller ID
 * @param controlType The picture-in-picture control type
 * @param status The picture-in-picture control status
 * @since 20
 */
typedef void (*WebPipControlEventCallback)(uint32_t controllerId, PictureInPicture_PipControlType controlType,
    PictureInPicture_PipControlStatus status);

/**
 * @brief The picture-in-picture size change callback
 * @param controllerId The picture-in-picture controller ID
 * @param width The picture-in-picture window width
 * @param height The picture-in-picture window height
 * @param scale The picture-in-picture window scale
 * @since 20
 */
typedef void (*WebPipResizeCallback)(uint32_t controllerId, uint32_t width, uint32_t height, double scale);

/**
 * @brief Create picture-in-picture config.
 * @param pipConfig The picture-in-picture config
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 * @since 20
 */
int32_t OH_PictureInPicture_CreatePipConfig(PictureInPicture_PipConfig* pipConfig);

/**
 * @brief Destroy picture-in-picture config.
 * @param pipConfig The picture-in-picture config
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 * @since 20
 */
int32_t OH_PictureInPicture_DestroyPipConfig(PictureInPicture_PipConfig* pipConfig);

/**
 * @brief Set picture-in-picture mainWindowId.
 *
 * @param pipConfig The picture-in-picture config
 * @param mainWindowId WindowId of corresponding mainWindow
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 * @since 20
 */
int32_t OH_PictureInPicture_SetPipMainWindowId(PictureInPicture_PipConfig pipConfig, uint32_t mainWindowId);

/**
 * @brief Set picture-in-picture templateType.
 *
 * @param pipConfig The picture-in-picture config
 * @param pipTemplateType The picture-in-picture template type
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 * @since 20
 */
int32_t OH_PictureInPicture_SetPipTemplateType(PictureInPicture_PipConfig pipConfig,
    PictureInPicture_PipTemplateType pipTemplateType);

/**
 * @brief Set picture-in-picture rect.
 *
 * @param pipConfig The picture-in-picture config
 * @param width The picture-in-picture window width
 * @param height The picture-in-picture window height
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 * @since 20
 */
int32_t OH_PictureInPicture_SetPipRect(PictureInPicture_PipConfig pipConfig, uint32_t width, uint32_t height);

/**
 * @brief Set picture-in-picture control group.
 *
 * @param pipConfig The picture-in-picture config
 * @param controlGroup The picture-in-picture control group
 * @param controlGroupLength The length of picture-in-picture control group
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 * @since 20
 */
int32_t OH_PictureInPicture_SetPipControlGroup(PictureInPicture_PipConfig pipConfig,
    PictureInPicture_PipControlGroup* controlGroup, uint8_t controlGroupLength);

/**
 * @brief Set picture-in-picture napi env.
 *
 * @param pipConfig The picture-in-picture config
 * @param env The picture-in-picture napi env
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 * @since 20
 */
int32_t OH_PictureInPicture_SetPipNapiEnv(PictureInPicture_PipConfig pipConfig, void* env);

/**
 * @brief Create picture-in-picture controller.
 * @param pipConfig The picture-in-picture config
 * @param controllerId The picture-in-picture controller ID
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR} pip internal error.
 * @since 20
 */
int32_t OH_PictureInPicture_CreatePip(PictureInPicture_PipConfig pipConfig, uint32_t* controllerId);

/**
 * @brief Delete picture-in-picture controller.
 *
 * @param controllerId The picture-in-picture controller ID
 * @return Return the result code.
 *         {@link OK} The function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 * @since 20
 */
int32_t OH_PictureInPicture_DeletePip(uint32_t controllerId);

/**
 * @brief Start picture-in-picture.
 *
 * @param controllerId The picture-in-picture controller ID
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_STATE_ABNORMAL} the PiP window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_CREATE_FAILED} failed to create the PiP window.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR} pip internal error.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_REPEATED_OPERATION} repeated PiP operation.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 * @since 20
 */
int32_t OH_PictureInPicture_StartPip(uint32_t controllerId);

/**
 * @brief Stop picture-in-picture.
 *
 * @param controllerId The picture-in-picture controller ID
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_DESTROY_FAILED} failed to destroy the PiP window.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_STATE_ABNORMAL} the PiP window state is abnormal.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR} pip internal error.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_REPEATED_OPERATION} repeated PiP operation.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 * @since 20
 */
int32_t OH_PictureInPicture_StopPip(uint32_t controllerId);

/**
 * @brief Update picture-in-picture content size.
 *
 * @param controllerId The picture-in-picture controller ID
 * @param width The picture-in-picture content width
 * @param height The picture-in-picture content height
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR} pip internal error.
 * @since 20
 */
int32_t OH_PictureInPicture_UpdatePipContentSize(uint32_t controllerId, uint32_t width, uint32_t height);

/**
 * @brief Update picture-in-picture control status.
 *
 * @param controllerId The picture-in-picture controller ID
 * @param controlType The picture-in-picture control type.
 * @param status The picture-in-picture control status.
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR} pip internal error.
 * @since 20
 */
int32_t OH_PictureInPicture_UpdatePipControlStatus(uint32_t controllerId, PictureInPicture_PipControlType controlType,
    PictureInPicture_PipControlStatus status);

/**
 * @brief Set picture-in-picture controll enable status.
 *
 * @param controllerId The picture-in-picture controller ID
 * @param controlType The picture-in-picture control type.
 * @param enabled Indicate the picture-in-picture control is enabled.
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR} pip internal error.
 * @since 20
 */
int32_t OH_PictureInPicture_SetPipControlEnabled(uint32_t controllerId, PictureInPicture_PipControlType controlType,
    bool enabled);

/**
 * @brief Set picture-in-picture initial surface rect.
 *
 * @param controllerId The picture-in-picture controller ID
 * @param positionX The X position of the first frame when start the picture-in-picture.
 * @param positionY The Y position of the first frame when start the picture-in-picture.
 * @param width The width of the first frame when start the picture-in-picture.
 * @param height The height of the first frame when start the picture-in-picture.
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR} pip internal error.
 * @since 20
 */
int32_t OH_PictureInPicture_SetPipInitialSurfaceRect(uint32_t controllerId, int32_t positionX, int32_t positionY,
    uint32_t width, uint32_t height);

/**
 * @brief Unset picture-in-picture initial surface rect.
 *
 * @param controllerId The picture-in-picture controller ID
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR} pip internal error.
 * @since 20
 */
int32_t OH_PictureInPicture_UnsetPipInitialSurfaceRect(uint32_t controllerId);

/**
 * @brief Register picture-in-picture controller start callback.
 *
 * @param controllerId The picture-in-picture controller ID
 * @param callback Start the picture-in-picture callback
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR} pip internal error.
 * @since 20
 */
int32_t OH_PictureInPicture_RegisterStartPipCallback(uint32_t controllerId, WebPipStartPipCallback callback);

/**
 * @brief Unregister picture-in-picture controller start callback.
 *
 * @param controllerId The picture-in-picture controller ID
 * @param callback Start the picture-in-picture callback
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR} pip internal error.
 * @since 20
 */
int32_t OH_PictureInPicture_UnregisterStartPipCallback(uint32_t controllerId, WebPipStartPipCallback callback);

/**
 * @brief Unregister all picture-in-picture controller start callbacks.
 *
 * @param controllerId The picture-in-picture controller ID
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR} pip internal error.
 * @since 20
 */
int32_t OH_PictureInPicture_UnregisterAllStartPipCallbacks(uint32_t controllerId);

/**
 * @brief Register picture-in-picture lifecycle listener callback.
 *
 * @param controllerId The picture-in-picture controller ID
 * @param callback The picture-in-picture lifecycle callback.
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR} pip internal error.
 * @since 20
 */
int32_t OH_PictureInPicture_RegisterLifecycleListener(uint32_t controllerId, WebPipLifecycleCallback callback);

/**
 * @brief Unregister picture-in-picture lifecycle listener callback.
 *
 * @param controllerId The picture-in-picture controller ID
 * @param callback The picture-in-picture lifecycle callback.
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR} pip internal error.
 * @since 20
 */
int32_t OH_PictureInPicture_UnregisterLifecycleListener(uint32_t controllerId, WebPipLifecycleCallback callback);

/**
 * @brief Unregister all picture-in-picture lifecycle listener callbacks.
 *
 * @param controllerId The picture-in-picture controller ID
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR} pip internal error.
 * @since 20
 */
int32_t OH_PictureInPicture_UnregisterAllLifecycleListeners(uint32_t controllerId);

/**
 * @brief Register picture-in-picture control event listener callback.
 *
 * @param controllerId The picture-in-picture controller ID
 * @param callback The picture-in-picture control event callback.
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR} pip internal error.
 * @since 20
 */
int32_t OH_PictureInPicture_RegisterControlEventListener(uint32_t controllerId, WebPipControlEventCallback callback);

/**
 * @brief Unregister picture-in-picture control event listener callback.
 *
 * @param controllerId The picture-in-picture controller ID
 * @param callback The picture-in-picture control event callback.
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR} pip internal error.
 * @since 20
 */
int32_t OH_PictureInPicture_UnregisterControlEventListener(uint32_t controllerId, WebPipControlEventCallback callback);

/**
 * @brief Unregister all picture-in-picture control event listener callbacks.
 *
 * @param controllerId The picture-in-picture controller ID
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR} pip internal error.
 * @since 20
 */
int32_t OH_PictureInPicture_UnregisterAllControlEventListeners(uint32_t controllerId);

/**
 * @brief Register picture-in-picture resize listener callback.
 *
 * @param controllerId The picture-in-picture controller ID
 * @param callback The picture-in-picture size change callback.
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR} pip internal error.
 * @since 20
 */
int32_t OH_PictureInPicture_RegisterResizeListener(uint32_t controllerId, WebPipResizeCallback callback);

/**
 * @brief Unregister picture-in-picture resize listener callback.
 *
 * @param controllerId The picture-in-picture controller ID
 * @param callback The picture-in-picture size change callback.
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR} pip internal error.
 * @since 20
 */
int32_t OH_PictureInPicture_UnregisterResizeListener(uint32_t controllerId, WebPipResizeCallback callback);

/**
 * @brief Unregister all picture-in-picture resize listener callbacks.
 *
 * @param controllerId The picture-in-picture controller ID
 * @return Return the result code.
 *         {@link OK} the function call is successful.
 *         {@link WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM} parameter error.
 *         {@link WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED} capability not supported.
 *         {@link WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR} pip internal error.
 * @since 20
 */
int32_t OH_PictureInPicture_UnregisterAllResizeListeners(uint32_t controllerId);

#ifdef __cplusplus
}
#endif

#endif // OH_WINDOW_PIP_H
/** @} */