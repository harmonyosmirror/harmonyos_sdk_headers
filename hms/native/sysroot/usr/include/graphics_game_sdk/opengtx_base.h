/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

/**
 * @addtogroup GraphicsAccelerate
 * @{
 *
 * @brief Provides APIs for graphics accelerate capability.
 *
 * @Syscap SystemCapability.GraphicsGame.RenderAccelerate
 * @since 5.0.0(12)
 */

/**
 * @file opengtx_base.h
 *
 * @brief Defines the graphic-platform-insensitive APIs of OpenGTX.
 *
 * Allows you to create OpenGTX context, configure context attributes, activate context,
 * deactivate context, dipatch frameRenderInfo, dispatch gameSceneInfo,
 * dispatch networkinfo and destroy context instance.
 *
 * @kit GraphicsAccelerateKit
 * @library libopengtx.so
 * @syscap SystemCapability.GraphicsGame.RenderAccelerate
 * @since 5.0.0(12)
 */

#ifndef OPENGTX_BASE_H
#define OPENGTX_BASE_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief OpenGTX context.
 * @since 5.0.0(12)
 */
struct OpenGTX_Context;
typedef struct OpenGTX_Context OpenGTX_Context;

/**
 * @brief Defines the LTPO's mode to control frame rate in game.
 * @since 5.0.0(12)
 */
typedef enum OpenGTX_LTPO_Mode {
    /** sets the frame rate of LTPO by scene, such as 120 fps in game playing mode, 30 fps in dead mode */
    SCENE_MODE = 0x0001,
    /** sets the frame rate of LTPO by touch mode. */
    /** If touches frequently, the frame rate will be set high. */
    TOUCH_MODE = 0x0010,
    /** sets the frame rate of LTPO by adaptive mode, integrated SCENE_MODE and TOUCH_MODE. */
    ADAPTIVE_MODE = 0x0100
} OpenGTX_LTPO_Mode;

/**
 * @brief Defines the game engine type
 * @since 5.0.0(12)
 */
typedef enum OpenGTX_EngineType {
    /** UNITY TYPE. */
    UNITY = 1,
    /** UNREAL TYPE. */
    UNREAL = 2,
    /** MESSIAH TYPE. */
    MESSIAH = 3,
    /** COCOS TYPE. */
    COCOS = 4,
    /** OTHERS TYPE. */
    OTHERS_ENGINE = 100
} OpenGTX_EngineType;

/**
 * @brief Defines the picture quality of game
 * @since 5.0.0(12)
 */
typedef enum OpenGTX_PictureQualityMaxLevel {
    /** SD mode, such as 480p. */
    SD = 1,
    /** HD mode, such as 720p. */
    HD = 2,
    /** FHD mode, such as 1080p. */
    FHD = 3,
    /** QHD mode, such as 2k. */
    QHD = 4,
    /** UHD mode, such as 4k. */
    UHD = 5
} OpenGTX_PictureQualityMaxLevel;

/**
 * @brief Defines the resolution value of game, such as 1920*1080
 * @since 5.0.0(12)
 */
typedef struct OpenGTX_ResolutionValue {
    /** Height value of resolution. */
    int32_t height;
    /** width value of resolution. */
    int32_t width;
} OpenGTX_ResolutionValue;

/**
 * @brief Defines the type of game
 * @since 5.0.0(12)
 */
typedef enum OpenGTX_GameType {
    /** Multiplayer Online Battle Arena. */
    MOBA = 1,
    /**  Role-Playing Game. */
    RPG = 2,
    /** First-person shooting game. */
    FPS = 3,
    /** Race Game. */
    RAC = 4,
    /** OTHERS. */
    OTHERS_TYPE = 100
} OpenGTX_GameType;

/**
 * @brief Defines the Configure value set by game
 * @since 5.0.0(12)
 */
typedef struct OpenGTX_ConfigDescription {
    /** the LTPO's mode to control frame rate. */
    OpenGTX_LTPO_Mode mode;
    /** the target frame rate of game. */
    int32_t targetFPS;
    /** the package name of game. */
    char* packageName;
    /** the version of game. */
    char* appVersion;
    /** the type of game engine. */
    OpenGTX_EngineType engineType;
    /** the version of game engine. */
    char* engineVersion;
    /** the type of game. */
    OpenGTX_GameType gameType;
    /** the picture quality of game. */
    OpenGTX_PictureQualityMaxLevel pictureQualityMaxLevel;
    /** the resolution value of game. */
    OpenGTX_ResolutionValue resolutionMaxValue;
    /** the main thread id of game. */
    int32_t gameMainThreadId;
    /** the render thread id of game. */
    int32_t gameRenderThreadId;
    /** the key thread ids of game, set up to 5 values, fill in with 0 if less than 5. */
    int32_t gameKeyThreadIds[5];
    /** the flag of support vulkan or not. */
    bool vulkanSupport;
} OpenGTX_ConfigDescription;

/**
 * @brief Defines temperature level of device.
 * @since 5.0.0(12)
 */
typedef enum OpenGTX_TempLevel {
    /**
     * The temperature of device is normal, game can remain in its current configuration.
     */
    TEMP_LEVEL1 = 1,
    /**
     * The temperature of device increase one level, game should reduce the imperceptible service,
     * such as decelerate background update.
     */
    TEMP_LEVEL2 = 2,
    /**
     * The temperature of device increase two level, game should stop the imperceptible service and reduce
     * Non-focused service, such as decelerate foreground update.
     */
    TEMP_LEVEL3 = 3,
    /**
     * The temperature of device increase three level, game should reduce the game effects.
     */
    TEMP_LEVEL4 = 4,
    /**
     * The temperature of device increase four level, game should reduce the game scene configuration,
     * such as frame resolution、frame rate、quality.
     */
    TEMP_LEVEL5 = 5,
    /**
     * The temperature of device increase five level(too high), game should keep the minimum configuration.
     */
    TEMP_LEVEL6 = 6,
} OpenGTX_TempLevel;

/**
 * @brief Defines three-dimensional Vector of OpenGTX.
 * @since 5.0.0(12)
 */
typedef struct OpenGTX_Vector3 {
    /** The x-axis coordinate of a 3D vector. */
    float x;
    /** The y-axis coordinate of a 3D vector. */
    float y;
    /** The z-axis coordinate of a 3D vector. */
    float z;
} OpenGTX_Vector3;

/**
 * @brief Defines the frame render information struct, which specifies the required attributes per frame.
 * @since 5.0.0(12)
 */
typedef struct OpenGTX_FrameRenderInfo {
    /** Position of the main camera. */
    OpenGTX_Vector3 mainCameraPosition;
    /** Rotate of the main camera, include yaw、pitch、roll. */
    OpenGTX_Vector3 mainCameraRotate;
} OpenGTX_FrameRenderInfo;

/**
 * @brief Defines the type of game scene for OpenGTX algorithm.
 * @since 5.0.0(12)
 */
typedef enum OpenGTX_SceneID {
    /** The scene of game login. */
    LOGIN = 1,
    /** The scene of game interface, such as main interface. */
    GAME_INTERFACE = 2,
    /** The scene of game loading. */
    LOADING = 3,
    /** The scene of game playing. */
    PLAYING = 4,
    /** The scene of spectator. */
    SPECTATOR = 5,
    /** The scene of character death. */
    DEATH = 6,
    /** The scene of device heavy-load. */
    HEAVY_LOAD = 7,
    /** The scene to be expanded. */
    OTHERS_SCENE = 100
} OpenGTX_SceneID;

/**
 * @brief Defines the game scene information struct, which specifies the required attributes per scene.
 * @since 5.0.0(12)
 */
typedef struct OpenGTX_GameSceneInfo {
    /** The Game Scene ID. */
    OpenGTX_SceneID sceneID;
    /** The descriptions of game scenarios, such as "driving". */
    char* description;
    /** The recommended frame rate for the current scene. */
    int32_t recommendFPS;
    /** The minimum frame rate expected for the current scene. */
    int32_t minFPS;
    /** The maximum frame rate expected for the current scene. */
    int32_t maxFPS;
    /** The resolution of the current scene. */
    OpenGTX_ResolutionValue resolutionCurValue;
} OpenGTX_GameSceneInfo;

/**
 * @brief Defines the network latency for OpenGTX algorithm.
 * @since 5.0.0(12)
 */
typedef struct OpenGTX_NetworkLatency {
    /** The total latency of the game. */
    int32_t total;
    /** The uplink latency of the game. */
    int32_t up;
    /** The downlink latency of the game. */
    int32_t down;
} OpenGTX_NetworkLatency;

/**
 * @brief Defines the network information struct, which specifies the required attributes of network.
 * @since 5.0.0(12)
 */
typedef struct OpenGTX_NetworkInfo {
    /**
     * The network latency in the game.
     * If the game cannot know the uplink and downlink latency, you can set 0 to the total latency,
     * and the value is greater than or equal to 0.
     * The total game latency is divided into 5 levels of 50ms, 100ms, 150ms, and 200ms,
     * and the game application notifies OpenGTX when the gear changes.
     */
    OpenGTX_NetworkLatency networkLatency;
    /** The game server address for IP format verifying. */
    char* networkServerIP;
} OpenGTX_NetworkInfo;

/**
 * @brief Defines error codes for OpenGTX APIs.
 * @since 5.0.0(12)
 */
typedef enum OpenGTX_ErrorCode {
    /** The operation is successful. */
    OPENGTX_SUCCESS = 0,
    /** Invalid parameter. */
    OPENGTX_INVALID_PARAMETER = 401,
    /** The context is not configured when activated. */
    OPENGTX_CONTEXT_NOT_CONFIG = 1009502001,
    /** The context is not active when dispatched. */
    OPENGTX_CONTEXT_NOT_ACTIVE = 1009502002
} OpenGTX_ErrorCode;

/**
 * @ingroup Callbacks
 * @brief
 * This callback is to device report temperature level to game.
 *
 * @param[in] temperature level to be reported to game {@link OpenGTX_TempLevel}.
 * @since 5.0.0(12)
 */
typedef void (*OpenGTX_DeviceInfoCallback)(OpenGTX_TempLevel);

/**
 * @brief Creates a OpenGTX context instance. The context structure is the main object used to interact with
 * OpenGTX APIs, and is responsible for the management of the internal resources used by the OpenGTX algorithm.
 *
 * @param [in] callback function of device information {@link OpenGTX_DeviceInfoCallback}.
 * @return Returns the pointer to a {@link OpenGTX_Context} context instance.
 * @since 5.0.0(12)
 */
OpenGTX_Context* HMS_OpenGTX_CreateContext(OpenGTX_DeviceInfoCallback deviceInfoCallback);

/**
 * @brief Configure OpenGTX context instance for initialing. For instance, sets the LTPO's mode to control
 * frame rate, sets the target frame rate of game, etc.
 *
 * @param [in] context Pointer to the {@link OpenGTX_Context} instance. The value can not be null. Otherwise, an error
 * code is returned.
 * @param [in] config Pointer to the {@link OpenGTX_ConfigDescription} instance. The object specifies the configure
 * attributes added to the context instance. The value can not be null. Otherwise, an error code is returned.
 * @return Execution result of the function. If the operation is successful, <b>OPENGTX_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link OpenGTX_ErrorCode}.
 * @since 5.0.0(12)
 */
OpenGTX_ErrorCode HMS_OpenGTX_SetConfiguration(OpenGTX_Context* context, const OpenGTX_ConfigDescription* config);

/**
 * @brief Destroy OpenGTX instance and memory resource reclamation.
 *
 * @param [in] context Level-2 pointer to the {@link OpenGTX_Context} instance to destroy.
 * @return Execution result of the function. If the operation is successful, <b>OPENGTX_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link OpenGTX_ErrorCode}.
 * @since 5.0.0(12)
 */
OpenGTX_ErrorCode HMS_OpenGTX_DestroyContext(OpenGTX_Context** context);

/**
 * @brief Activate OpenGTX algorithm. An "activated" instance is ready to draw frames.
 * In order to activate it, {@link HMS_OpenGTX_SetConfiguration} must be called. In case of any errors,
 * the instance is considered to be inactive.
 *
 * @param [in] context Pointer to the {@link OpenGTX_Context} instance. The value cannot be null.
 * Otherwise, an error code is returned.
 * @return Execution result of the function. If the operation is successful, <b>OPENGTX_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link OpenGTX_ErrorCode}.
 * @since 5.0.0(12)
 */
OpenGTX_ErrorCode HMS_OpenGTX_Activate(OpenGTX_Context* context);

/**
 * @brief Deactivate OpenGTX algorithm.
 *
 * @param [in] context  Pointer to the {@link OpenGTX_Context} instance. The value cannot be null.
 * Otherwise, an error code is returned.
 * @return Execution result of the function. If the operation is successful, <b>OPENGTX_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link OpenGTX_ErrorCode}.
 * @since 5.0.0(12)
 */
OpenGTX_ErrorCode HMS_OpenGTX_Deactivate(OpenGTX_Context* context);

/**
 * @brief Set all required data of frame rendering for OpenGTX algorithm to reduce device load, such as LTPO.
 *
 * @param [in] context Pointer to the {@link OpenGTX_Context} instance. The value can not be null.
 * @param [in] desc Pointer to the {@link OpenGTX_FrameRenderInfo}. The object specifies the dispatch attributes
 * used by OpenGTX algorithm per frame. The value can not be null.
 * @return Function execution result. If the operation is successful, OPENGTX_SUCCESS is returned.
 * If the operation fails, an error code is returned. For details about the error codes, see {@link OpenGTX_ErrorCode}.
 * @since 5.0.0(12)
 */
OpenGTX_ErrorCode HMS_OpenGTX_DispatchFrameRenderInfo(OpenGTX_Context* context,
    const OpenGTX_FrameRenderInfo* frameRenderInfo);

/**
 * @brief Set all required data of game scene for OpenGTX algorithm to reduce device load.
 *
 * @param [in] context Pointer to the {@link OpenGTX_Context} instance. The value can not be null.
 * @param [in] desc Pointer to the {@link OpenGTX_GameSceneInfo}. The object specifies the dispatch attributes
 * used by OpenGTX algorithm per scene. The value can not be null.
 * @return Function execution result. If the operation is successful, OPENGTX_SUCCESS is returned.
 * If the operation fails, an error code is returned. For details about the error codes, see {@link OpenGTX_ErrorCode}.
 * @since 5.0.0(12)
 */
OpenGTX_ErrorCode HMS_OpenGTX_DispatchGameSceneInfo(OpenGTX_Context* context,
    const OpenGTX_GameSceneInfo* gameSceneInfo);

/**
 * @brief Set all required data of network for OpenGTX algorithm to reduce device load.
 *
 * @param [in] context Pointer to the {@link OpenGTX_Context} instance. The value can not be null.
 * @param [in] desc Pointer to the {@link OpenGTX_NetworkInfo}. The object specifies the dispatch attributes
 * used by OpenGTX algorithm when total latency changes. The value can not be null.
 * @return Function execution result. If the operation is successful, OPENGTX_SUCCESS is returned.
 * If the operation fails, an error code is returned. For details about the error codes, see {@link OpenGTX_ErrorCode}.
 * @since 5.0.0(12)
 */
OpenGTX_ErrorCode HMS_OpenGTX_DispatchNetworkInfo(OpenGTX_Context* context, const OpenGTX_NetworkInfo* networkInfo);
#ifdef __cplusplus
}
#endif // __cplusplus
/** @} */
#endif // OPENGTX_BASE_H