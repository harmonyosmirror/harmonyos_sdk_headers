/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

/**
 * @addtogroup GamePerformance
 * @{
 *
 * @brief Provides APIs for game service performance capability.
 *
 * @since 5.0.2(14)
 */

/**
 * @file game_performance.h
 * @kit GameServiceKit
 *
 * @brief Defines performance capabilities APIs for game app.
 *
 * Defines performance capabilities APIs for game app
 *
 * @library libgame_performance.z.so
 * @syscap SystemCapability.GameService.GamePerformance
 * @since 5.0.2(14)
 */

#ifndef GAME_PERFORMANCE_H
#define GAME_PERFORMANCE_H
#include <stdint.h>
#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines device information.
 * @since 5.0.2(14)
 */
typedef struct GamePerformance_DeviceInfo GamePerformance_DeviceInfo;

/**
 * @brief Defines GPU information.
 * @since 5.0.2(14)
 */
typedef struct GamePerformance_GpuInfo GamePerformance_GpuInfo;

/**
 * @brief Defines thermal information.
 * @since 5.0.2(14)
 */
typedef struct GamePerformance_ThermalInfo GamePerformance_ThermalInfo;

/**
 * @brief Defines thermal information query parameters.
 * @since 5.0.2(14)
 */
typedef struct GamePerformance_ThermalInfoQueryParameters GamePerformance_ThermalInfoQueryParameters;

/**
 * @brief Defines init parameters.
 * @since 5.0.2(14)
 */
typedef struct GamePerformance_InitParameters GamePerformance_InitParameters;

/**
 * @brief Defines package information.
 * @since 5.0.2(14)
 */
typedef struct GamePerformance_PackageInfo GamePerformance_PackageInfo;

/**
 * @brief Defines config information.
 * @since 5.0.2(14)
 */
typedef struct GamePerformance_ConfigInfo GamePerformance_ConfigInfo;

/**
 * @brief Defines scene information.
 * @since 5.0.2(14)
 */
typedef struct GamePerformance_SceneInfo GamePerformance_SceneInfo;

/**
 * @brief Defines network information.
 * @since 5.0.2(14)
 */
typedef struct GamePerformance_NetInfo GamePerformance_NetInfo;

/**
 * @brief Defines player information.
 * @since 5.0.2(14)
 */
typedef struct GamePerformance_PlayerInfo GamePerformance_PlayerInfo;

/**
 * @brief Defines engine information.
 * @since 5.0.2(14)
 */
typedef enum GamePerformance_EngineType {
    /**
     * UNITY
     */
    GAME_PERFORMANCE_ENGINE_TYPE_UNITY = 1,

    /**
     * UNREAL
     */
    GAME_PERFORMANCE_ENGINE_TYPE_UNREAL = 2,

    /**
     * MESSIAH
     */
    GAME_PERFORMANCE_ENGINE_TYPE_MESSIAH = 3,

    /**
     * COCOS
     */
    GAME_PERFORMANCE_ENGINE_TYPE_COCOS = 4,

    /**
     * Other engine type
     */
    GAME_PERFORMANCE_ENGINE_TYPE_OTHERS = 200
} GamePerformance_EngineType;

/**
 * @brief Defines game type.
 * @since 5.0.2(14)
 */
typedef enum GamePerformance_GameType {
    /**
     * MOBA
     */
    GAME_PERFORMANCE_GAME_TYPE_MOBA = 1,

    /**
     * RPG
     */
    GAME_PERFORMANCE_GAME_TYPE_RPG = 2,

    /**
     * FPS
     */
    GAME_PERFORMANCE_GAME_TYPE_FPS = 3,

    /**
     * FTG
     */
    GAME_PERFORMANCE_GAME_TYPE_FTG = 4,

    /**
     * RAC
     */
    GAME_PERFORMANCE_GAME_TYPE_RAC = 5,

    /**
     * Other game type
     */
    GAME_PERFORMANCE_GAME_TYPE_OTHERS = 200
} GamePerformance_GameType;

/**
 * @brief Defines level of picture quality.
 * @since 5.0.2(14)
 */
typedef enum GamePerformance_PictureQualityLevel {
    /**
     * SMOOTH (Low Quality)
     */
    GAME_PERFORMANCE_PQL_SMOOTH = 1,

    /**
     * BALANCED (Medium Quality)
     */
    GAME_PERFORMANCE_PQL_BALANCED = 2,

    /**
     * HD (High Definition)
     */
    GAME_PERFORMANCE_PQL_HD = 3,

    /**
     * HDR (High Dynamic Range)
     */
    GAME_PERFORMANCE_PQL_HDR = 4,

    /**
     * UHD (Ultra High Definition)
     */
    GAME_PERFORMANCE_PQL_UHD = 5
} GamePerformance_PictureQualityLevel;

/**
 * @brief Defines importance level of scene.
 * @since 5.0.2(14)
 */
typedef enum GamePerformance_SceneImportanceLevel {
    /**
     * Level 1.
     */
    GAME_PERFORMANCE_SIL_LEVEL1 = 1,

    /**
     * Level 2.
     */
    GAME_PERFORMANCE_SIL_LEVEL2 = 2,

    /**
     * Level 3.
     */
    GAME_PERFORMANCE_SIL_LEVEL3 = 3,

    /**
     * Level 4.
     */
    GAME_PERFORMANCE_SIL_LEVEL4 = 4,

    /**
     * Level 5.
     */
    GAME_PERFORMANCE_SIL_LEVEL5 = 5
} GamePerformance_SceneImportanceLevel;

/**
 * @brief Defines level of CPU.
 * @since 5.0.2(14)
 */
typedef enum GamePerformance_CpuLevel {
    /**
     * Low.
     */
    GAME_PERFORMANCE_CPU_LEVEL_LOW = 1,

    /**
     * Middle.
     */
    GAME_PERFORMANCE_CPU_LEVEL_MIDDLE = 2,

    /**
     * High.
     */
    GAME_PERFORMANCE_CPU_LEVEL_HIGH = 3
} GamePerformance_CpuLevel;

/**
 * @brief Defines level of GPU.
 * @since 5.0.2(14)
 */
typedef enum GamePerformance_GpuLevel {
    /**
     * Low.
     */
    GAME_PERFORMANCE_GPU_LEVEL_LOW = 1,

    /**
     * Middle.
     */
    GAME_PERFORMANCE_GPU_LEVEL_MIDDLE = 2,

    /**
     * High.
     */
    GAME_PERFORMANCE_GPU_LEVEL_HIGH = 3
} GamePerformance_GpuLevel;

/**
 * @brief Defines level of DDR.
 * @since 5.0.2(14)
 */
typedef enum GamePerformance_DdrLevel {
    /**
     * Low.
     */
    GAME_PERFORMANCE_DDR_LEVEL_LOW = 1,

    /**
     * Middle.
     */
    GAME_PERFORMANCE_DDR_LEVEL_MIDDLE = 2,

    /**
     * High.
     */
    GAME_PERFORMANCE_DDR_LEVEL_HIGH = 3
} GamePerformance_DdrLevel;

/**
 * @brief Defines level of net load.
 * @since 5.0.2(14)
 */
typedef enum GamePerformance_NetLoad {
    /**
     * Light load.
     */
    GAME_PERFORMANCE_NET_LOAD_LIGHT = 1,

    /**
     * Moderate load.
     */
    GAME_PERFORMANCE_NET_LOAD_MODERATE = 2,

    /**
     * Heavy load.
     */
    GAME_PERFORMANCE_NET_LOAD_HEAVY = 3
} GamePerformance_NetLoad;

/**
 * @brief Defines ErrorCode.
 * @since 5.0.2(14)
 */
typedef enum GamePerformance_ErrorCode {
    /**
     * Success.
     */
    GAME_PERFORMANCE_SUCCESS = 0,

    /**
     * Invalid parameter.
     */
    GAME_PERFORMANCE_PARAM_INVALID = 401,

    /**
     * System internal error.
     */
    GAME_PERFORMANCE_INTERNAL_ERROR = 1010300001,

    /**
     * Invalid caller.
     */
    GAME_PERFORMANCE_AUTH_FAILED = 1010300002,

    /**
     * Invalid request.
     */
    GAME_PERFORMANCE_INVALID_REQUEST = 1010300003
} GamePerformance_ErrorCode;

/**
 * @brief Defines type of deviceInfo.
 * @since 5.0.2(14)
 */
typedef enum GamePerformance_DeviceInfoType {
    /**
     * THERMAL.
     */
    GAME_PERFORMANCE_DEVICEINFO_TYPE_THERMAL = 0,

    /**
     * GPU.
     */
    GAME_PERFORMANCE_DEVICEINFO_TYPE_GPU = 1
} GamePerformance_DeviceInfoType;

/**
 * @brief The callback signature which is used in {@link HMS_GamePerformance_RegisterThermalLevelChangedCallback}.
 * the function will be invoked once when thermal level changed and thermal level is less than 3.
 * the function will be invoked once evenry ten seconds when thermal level is greater than or equal level 3.
 *
 * @param deviceInfo Output data. Detail information of device {@link GamePerformance_DeviceInfo}.
 * @param userData User specific data.
 * @since 5.0.2(14)
 */
typedef void (*GamePerformance_ThermalLevelChangedCallback)(GamePerformance_DeviceInfo *deviceInfo, void *userData);

/**
 * @brief Create {@link GamePerformance_InitParameters} instance , which is used in {@link HMS_GamePerformance_Init}.
 *
 * @param initParameters Output data. {@link GamePerformance_InitParameters} instance.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_CreateInitParameters(GamePerformance_InitParameters **initParameters);

/**
 * @brief Destroy {@link GamePerformance_InitParameters} instance, When the instance is no longer needed.
 *
 * @param initParameters Secondary pointer to the {@link GamePerformance_InitParameters} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_DestroyInitParameters(GamePerformance_InitParameters **initParameters);

/**
 * @brief Set bundle name for {@link GamePerformance_InitParameters} instance.
 *
 * @param initParameters Pointer to the {@link GamePerformance_InitParameters} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param bundleName The bundleName of the app.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_InitParameters_SetBundleName(
    GamePerformance_InitParameters *initParameters, const char *bundleName);

/**
 * @brief Set app version for {@link GamePerformance_InitParameters} instance.
 *
 * @param initParameters Pointer to the {@link GamePerformance_InitParameters} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param appVersion The version of the app.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_InitParameters_SetAppVersion(
    GamePerformance_InitParameters *initParameters, const char *appVersion);

/**
 * Init game performance with {@link GamePerformance_InitParameters} instance.
 *
 * @param initParameters Pointer to the {@link GamePerformance_InitParameters} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_Init(GamePerformance_InitParameters *initParameters);

/**
 * @brief Create {@link GamePerformance_PackageInfo} instance,
 * which is used in {@link HMS_GamePerformance_UpdatePackageInfo}.
 *
 * @param packageInfo Output data. {@link GamePerformance_PackageInfo} instance.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_CreatePackageInfo(GamePerformance_PackageInfo **packageInfo);

/**
 * @brief Destroy {@link GamePerformance_PackageInfo} instance, When the instance is no longer needed.
 *
 * @param packageInfo Secondary pointer to the {@link GamePerformance_PackageInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_DestroyPackageInfo(GamePerformance_PackageInfo **packageInfo);

/**
 * @brief Set bundle name for {@link GamePerformance_PackageInfo} instance.
 *
 * @param packageInfo Pointer to the {@link GamePerformance_PackageInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param bundleName The bundleName of the app.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_PackageInfo_SetBundleName(GamePerformance_PackageInfo *packageInfo,
                                                                        const char *bundleName);

/**
 * @brief Set app version for {@link GamePerformance_PackageInfo} instance.
 *
 * @param packageInfo Pointer to the {@link GamePerformance_PackageInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param appVersion The version of the app.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_PackageInfo_SetAppVersion(GamePerformance_PackageInfo *packageInfo,
                                                                        const char *appVersion);

/**
 * @brief Set engine type for {@link GamePerformance_PackageInfo} instance.
 *
 * @param packageInfo Pointer to the {@link GamePerformance_PackageInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param engineType The type of the engine {@link GamePerformance_EngineType}.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_PackageInfo_SetEngineType(GamePerformance_PackageInfo *packageInfo,
                                                                        const GamePerformance_EngineType engineType);

/**
 * @brief Set engine version for {@link GamePerformance_PackageInfo} instance.
 *
 * @param packageInfo Pointer to the {@link GamePerformance_PackageInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param engineVersion The version of the engine.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_PackageInfo_SetEngineVersion(GamePerformance_PackageInfo *packageInfo,
                                                                           const char *engineVersion);

/**
 * @brief Set game type for {@link GamePerformance_PackageInfo} instance.
 *
 * @param packageInfo Pointer to the {@link GamePerformance_PackageInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param gameType The type of the game {@link GamePerformance_GameType}.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_PackageInfo_SetGameType(GamePerformance_PackageInfo *packageInfo,
                                                                      const GamePerformance_GameType gameType);

/**
 * @brief Set whether vulkan is supported  for {@link GamePerformance_PackageInfo} instance.
 *
 * @param packageInfo Pointer to the {@link GamePerformance_PackageInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param vulkanSupported Whether vulkan is supported.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_PackageInfo_SetVulkanSupported(GamePerformance_PackageInfo *packageInfo,
                                                                             const bool vulkanSupported);

/**
 * @brief Update game package info.
 *
 * @param packageInfo Pointer to the {@link GamePerformance_PackageInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_UpdatePackageInfo(GamePerformance_PackageInfo *packageInfo);

/**
 * @brief Create {@link GamePerformance_ConfigInfo} instance,
 * which is used in {@link HMS_GamePerformance_UpdateConfigInfo}.
 *
 * @param configInfo Output data. {@link GamePerformance_ConfigInfo} instance.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_CreateConfigInfo(GamePerformance_ConfigInfo **configInfo);

/**
 * @brief Destroy {@link GamePerformance_ConfigInfo} instance, When the instance is no longer needed.
 *
 * @param configInfo Secondary pointer to the {@link GamePerformance_ConfigInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_DestroyConfigInfo(GamePerformance_ConfigInfo **configInfo);

/**
 * @brief Set max picture quality level for {@link GamePerformance_ConfigInfo} instance.
 *
 * @param configInfo Pointer to the {@link GamePerformance_ConfigInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param maxPictureQualityLevel Max picture quality level.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_ConfigInfo_SetMaxPictureQualityLevel(
    GamePerformance_ConfigInfo *configInfo, const GamePerformance_PictureQualityLevel maxPictureQualityLevel);

/**
 * @brief Set current picture quality level for {@link GamePerformance_ConfigInfo} instance.
 *
 * @param configInfo Pointer to the {@link GamePerformance_ConfigInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param currentPictureQualityLevel Current picture quality level.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_ConfigInfo_SetCurrentPictureQualityLevel(
    GamePerformance_ConfigInfo *configInfo, const GamePerformance_PictureQualityLevel currentPictureQualityLevel);

/**
 * @brief Set max frame rate for {@link GamePerformance_ConfigInfo} instance.
 *
 * @param configInfo Pointer to the {@link GamePerformance_ConfigInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param maxFrameRate Max frame rate.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_ConfigInfo_SetMaxFrameRate(GamePerformance_ConfigInfo *configInfo,
                                                                         const int64_t maxFrameRate);

/**
 * @brief Set current frame rate for {@link GamePerformance_ConfigInfo} instance.
 *
 * @param configInfo Pointer to the {@link GamePerformance_ConfigInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param currentFrameRate Current frame rate.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_ConfigInfo_SetCurrentFrameRate(GamePerformance_ConfigInfo *configInfo,
                                                                             const int64_t currentFrameRate);

/**
 * @brief Set max resolution for {@link GamePerformance_ConfigInfo} instance.
 *
 * @param configInfo Pointer to the {@link GamePerformance_ConfigInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param maxResolution Max resolution.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_ConfigInfo_SetMaxResolution(GamePerformance_ConfigInfo *configInfo,
                                                                          const char *maxResolution);

/**
 * @brief Set current resolution for {@link GamePerformance_ConfigInfo} instance.
 *
 * @param configInfo Pointer to the {@link GamePerformance_ConfigInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param currentResolution Current resolution.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_ConfigInfo_SetCurrentResolution(GamePerformance_ConfigInfo *configInfo,
                                                                              const char *currentResolution);

/**
 * @brief Set whether antiAliasing is enabled for {@link GamePerformance_ConfigInfo} instance.
 *
 * @param configInfo Pointer to the {@link GamePerformance_ConfigInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param antiAliasingEnabled Whether antiAliasing is enabled.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_ConfigInfo_SetAntiAliasingEnabled(GamePerformance_ConfigInfo *configInfo,
                                                                                const bool antiAliasingEnabled);

/**
 * @brief Set whether shadow is enabled for {@link GamePerformance_ConfigInfo} instance.
 *
 * @param configInfo Pointer to the {@link GamePerformance_ConfigInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param shadowEnabled Whether shadow is enabled.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_ConfigInfo_SetShadowEnabled(GamePerformance_ConfigInfo *configInfo,
                                                                          const bool shadowEnabled);

/**
 * @brief Set whether multi thread is enabled for {@link GamePerformance_ConfigInfo} instance.
 *
 * @param configInfo Pointer to the {@link GamePerformance_ConfigInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param multithreadingEnabled Whether multi thread is enabled.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_ConfigInfo_SetMultithreadingEnabled(
    GamePerformance_ConfigInfo *configInfo, const bool multithreadingEnabled);

/**
 * @brief Set whether particle is enabled for {@link GamePerformance_ConfigInfo} instance.
 *
 * @param configInfo Pointer to the {@link GamePerformance_ConfigInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param particleEnabled Whether particle is enabled.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_ConfigInfo_SetParticleEnabled(GamePerformance_ConfigInfo *configInfo,
                                                                            const bool particleEnabled);

/**
 * @brief Set whether HD mode is enabled for {@link GamePerformance_ConfigInfo} instance.
 *
 * @param configInfo Pointer to the {@link GamePerformance_ConfigInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param hdModeEnabled Whether HD mode is enabled.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_ConfigInfo_SetHdModeEnabled(GamePerformance_ConfigInfo *configInfo,
                                                                          const bool hdModeEnabled);

/**
 * @brief Update game config info.
 *
 * @param configInfo Pointer to the {@link GamePerformance_ConfigInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_UpdateConfigInfo(GamePerformance_ConfigInfo *configInfo);

/**
 * @brief Create {@link GamePerformance_SceneInfo} instance,
 * which is used in {@link HMS_GamePerformance_UpdateSceneInfo}
 *
 * @param sceneInfo Output data. {@link GamePerformance_SceneInfo} instance.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_CreateSceneInfo(GamePerformance_SceneInfo **sceneInfo);

/**
 * @brief Destroy {@link GamePerformance_SceneInfo} instance, When the instance is no longer needed.
 *
 * @param sceneInfo Secondary pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_DestroySceneInfo(GamePerformance_SceneInfo **sceneInfo);

/**
 * @brief Set scene ID for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param sceneID Scene ID.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetSceneID(GamePerformance_SceneInfo *sceneInfo,
                                                                   const int64_t sceneID);

/**
 * @brief Set scene description for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param description Scene description.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetDescription(GamePerformance_SceneInfo *sceneInfo,
                                                                       const char *description);

/**
 * @brief Set sub scene ID for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param subSceneID Sub scene ID
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetSubSceneID(GamePerformance_SceneInfo *sceneInfo,
                                                                      const char *subSceneID);

/**
 * @brief Set sub scene description for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param subDescription Sub scene description.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetSubDescription(GamePerformance_SceneInfo *sceneInfo,
                                                                          const char *subDescription);

/**
 * @brief Set importance level of scene for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param importanceLevel Importance level of scene {@link GamePerformance_SceneImportanceLevel}
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetImportanceLevel(GamePerformance_SceneInfo *sceneInfo,
    const GamePerformance_SceneImportanceLevel importanceLevel);

/**
 * @brief Set scene frequency for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param sceneFrequency Scene frequency.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetSceneFrequency(GamePerformance_SceneInfo *sceneInfo,
                                                                          const int64_t sceneFrequency);

/**
 * @brief Set length of time in the scene for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param sceneTime Length of time in the scene.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetSceneTime(GamePerformance_SceneInfo *sceneInfo,
                                                                     const int64_t sceneTime);

/**
 * @brief Set recommended CPU level for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param recommendedCpuLevel Recommended CPU level {@link GamePerformance_CpuLevel}.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetRecommendedCpuLevel(GamePerformance_SceneInfo *sceneInfo,
    const GamePerformance_CpuLevel recommendedCpuLevel);

/**
 * @brief Set recommended GPU level for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param recommendedGpuLevel Recommended GPU level  {@link GamePerformance_GpuLevel}
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetRecommendedGpuLevel(GamePerformance_SceneInfo *sceneInfo,
    const GamePerformance_GpuLevel recommendedGpuLevel);

/**
 * @brief Set recommended DDR level for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param recommendedDdrLevel Recommended DDR level {@link GamePerformance_DdrLevel}.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetRecommendedDdrLevel(GamePerformance_SceneInfo *sceneInfo,
    const GamePerformance_DdrLevel recommendedDdrLevel);

/**
 * @brief Set max frame rate in the scene for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param maxFrameRate Max frame rate in the scene.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetMaxFrameRate(GamePerformance_SceneInfo *sceneInfo,
                                                                        const int64_t maxFrameRate);

/**
 * @brief Set current frame rate in the scene for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param currentFrameRate Current frame rate in the scene.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetCurrentFrameRate(GamePerformance_SceneInfo *sceneInfo,
                                                                            const int64_t currentFrameRate);

/**
 * @brief Set name of key thread for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param keyThread Name of key thread.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetKeyThread(GamePerformance_SceneInfo *sceneInfo,
                                                                     const char *keyThread);

/**
 * @brief Set drawCall count for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param drawCallCount DrawCall count.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetDrawCallCount(GamePerformance_SceneInfo *sceneInfo,
                                                                         const int64_t drawCallCount);

/**
 * @brief Set vertex count for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param vertexCount Vertex count.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetVertexCount(GamePerformance_SceneInfo *sceneInfo,
                                                                       const int64_t vertexCount);

/**
 * @brief Set triangle count for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param triangleCount Triangle count.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetTriangleCount(GamePerformance_SceneInfo *sceneInfo,
                                                                         const int64_t triangleCount);

/**
 * @brief Set shader count for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param shaderCount Shader count.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetShaderCount(GamePerformance_SceneInfo *sceneInfo,
                                                                       const int64_t shaderCount);

/**
 * @brief Set texture count for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param textureCount Texture count.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetTextureCount(GamePerformance_SceneInfo *sceneInfo,
                                                                        const int64_t textureCount);

/**
 * @brief Set mesh count for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param meshCount Mesh count.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetMeshCount(GamePerformance_SceneInfo *sceneInfo,
                                                                     const int64_t meshCount);

/**
 * @brief Set channel count for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param channelCount Channel count.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetChannelCount(GamePerformance_SceneInfo *sceneInfo,
                                                                        const int64_t channelCount);

/**
 * @brief Set participant count for {@link GamePerformance_SceneInfo} instance.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param participantCount Participant count.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_SceneInfo_SetParticipantCount(GamePerformance_SceneInfo *sceneInfo,
                                                                            const int64_t participantCount);

/**
 * @brief Update game scene info.
 *
 * @param sceneInfo Pointer to the {@link GamePerformance_SceneInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_UpdateSceneInfo(GamePerformance_SceneInfo *sceneInfo);

/**
 * @brief Create {@link GamePerformance_NetInfo} instance,
 * which is used in {@link HMS_GamePerformance_UpdateNetInfo}.
 *
 * @param netInfo Output data. {@link GamePerformance_NetInfo} instance.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_CreateNetInfo(GamePerformance_NetInfo **netInfo);

/**
 * @brief Destroy {@link GamePerformance_NetInfo} instance, When the instance is no longer needed.
 *
 * @param netInfo Secondary pointer to the {@link GamePerformance_NetInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_DestroyNetInfo(GamePerformance_NetInfo **netInfo);

/**
 * @brief Set total net latency for {@link GamePerformance_NetInfo} instance.
 *
 * @param netInfo Pointer to the {@link GamePerformance_NetInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param total Total net latency.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_NetInfo_SetTotalLatency(GamePerformance_NetInfo *netInfo,
                                                                      const int64_t total);

/**
 * @brief Set up net latency for {@link GamePerformance_NetInfo} instance.
 *
 * @param netInfo Pointer to the {@link GamePerformance_NetInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param up Up net latency.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_NetInfo_SetUplinkLatency(GamePerformance_NetInfo *netInfo,
                                                                       const int64_t up);

/**
 * @brief Set down net latency for {@link GamePerformance_NetInfo} instance.
 *
 * @param netInfo Pointer to the {@link GamePerformance_NetInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param down Down net latency.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_NetInfo_SetDownlinkLatency(GamePerformance_NetInfo *netInfo,
                                                                         const int64_t down);

/**
 * @brief Set server net latency for {@link GamePerformance_NetInfo} instance.
 *
 * @param netInfo Pointer to the {@link GamePerformance_NetInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param server Server net latency.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_NetInfo_SetServerLatency(GamePerformance_NetInfo *netInfo,
                                                                       const int64_t server);

/**
 * @brief Set net load for {@link GamePerformance_NetInfo} instance.
 *
 * @param netInfo Pointer to the {@link GamePerformance_NetInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param netLoad Net load {@link GamePerformance_NetLoad}.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_NetInfo_SetNetLoad(GamePerformance_NetInfo *netInfo,
                                                                 const GamePerformance_NetLoad netLoad);

/**
 * @brief Update game net info.
 *
 * @param netInfo Pointer to the {@link GamePerformance_NetInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_UpdateNetInfo(GamePerformance_NetInfo *netInfo);

/**
 * @brief Create {@link GamePerformance_PlayerInfo} instance,
 * which is used in {@link HMS_GamePerformance_UpdatePlayerInfo}.
 *
 * @param playerInfo Output data. {@link GamePerformance_PlayerInfo} instance.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_CreatePlayerInfo(GamePerformance_PlayerInfo **playerInfo);

/**
 * @brief Destroy {@link GamePerformance_PlayerInfo} instance, When the instance is no longer needed.
 *
 * @param playerInfo Secondary pointer to the {@link GamePerformance_PlayerInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_DestroyPlayerInfo(GamePerformance_PlayerInfo **playerInfo);

/**
 * @brief Set gamePlayerId for {@link GamePerformance_PlayerInfo} instance.
 *
 * @param playerInfo Pointer to the {@link GamePerformance_PlayerInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param gamePlayerId GamePlayerId.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_PlayerInfo_SetGamePlayerId(GamePerformance_PlayerInfo *playerInfo,
                                                                         const char *gamePlayerId);

/**
 * @brief Set teamPlayerId for {@link GamePerformance_PlayerInfo} instance.
 *
 * @param playerInfo Pointer to the {@link GamePerformance_PlayerInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param teamPlayerId TeamPlayerId.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_PlayerInfo_SetTeamPlayerId(GamePerformance_PlayerInfo *playerInfo,
                                                                         const char *teamPlayerId);

/**
 * @brief Set thirdOpenId for {@link GamePerformance_PlayerInfo} instance.
 *
 * @param playerInfo Pointer to the {@link GamePerformance_PlayerInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param thirdOpenId ThirdOpenId.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_PlayerInfo_SetThirdOpenId(GamePerformance_PlayerInfo *playerInfo,
                                                                        const char *thirdOpenId);

/**
 * @brief Update game player info.
 *
 * @param playerInfo Pointer to the {@link GamePerformance_PlayerInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_UpdatePlayerInfo(GamePerformance_PlayerInfo *playerInfo);

/**
 * @brief Subscribes thermal level change event. When target word is detected, the callback is invoked.
 *
 * the callback will be invoked once when thermal level changed and thermal level is less than 3.
 * the callback will be invoked once evenry ten seconds when thermal level is greater than or equal level 3.
 *
 * @param types Types of device information that register callback for.
 * @param size Size of types.
 * @param callback Call back function {@link GamePerformance_ThermalLevelChangedCallback}.
 * @param userData User specific data.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_RegisterThermalLevelChangedCallback(
    GamePerformance_DeviceInfoType *types[],
    size_t size,
    GamePerformance_ThermalLevelChangedCallback callback,
    void *userData);

/**
 * @brief Unsubscribes thermal level change event for the callback.
 *
 * @param callback Call back function {@link GamePerformance_ThermalLevelChangedCallback}.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_UnregisterThermalLevelChangedCallback(
    GamePerformance_ThermalLevelChangedCallback callback);

/**
 * @brief Unsubscribes thermal level change event for all of callbacks.
 *
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_UnregisterAllThermalLevelChangedCallbacks(void);

/**
 * @brief Create {@link GamePerformance_ThermalInfoQueryParameters} instance ,
 * which is used in {@link HMS_GamePerformance_QueryThermalInfo}.
 *
 * @param parameters Output data. {@link GamePerformance_ThermalInfoQueryParameters} instance.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_CreateThermalInfoQueryParameters(
    GamePerformance_ThermalInfoQueryParameters **parameters);

/**
 * @brief Destroy {@link GamePerformance_ThermalInfoQueryParameters} instance, When the instance is no longer needed.
 *
 * @param parameters Secondary pointer to the {@link GamePerformance_ThermalInfoQueryParameters} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_DestroyThermalInfoQueryParameters(
    GamePerformance_ThermalInfoQueryParameters **parameters);

/**
 * @brief Set needsPrediction for {@link GamePerformance_ThermalInfoQueryParameters} instance.
 *
 * @param parameters Pointer to the {@link GamePerformance_ThermalInfoQueryParameters} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param needsPrediction If need predict thermal trend, thermalMargin and thermalTrend will be answered.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_ThermalInfoQueryParameters_SetNeedsPrediction(
    GamePerformance_ThermalInfoQueryParameters *parameters, const bool needsPrediction);

/**
 * @brief Set target thermal level of thermal predict for {@link GamePerformance_ThermalInfoQueryParameters} instance.
 *
 * @param parameters Pointer to the {@link GamePerformance_ThermalInfoQueryParameters} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param targetThermalLevel Target thermal level of thermal predict. If need predict thermal trend,
 * thermalMargin and thermalTrend will be answered according to the targetThermalLevel.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_ThermalInfoQueryParameters_SetTargetThermalLevel(
    GamePerformance_ThermalInfoQueryParameters *parameters, const int32_t targetThermalLevel);

/**
 * @brief Query thermal info.
 *
 * @param parameters Pointer to the {@link GamePerformance_ThermalInfoQueryParameters} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param thermalInfo Output data. {@link GamePerformance_ThermalInfo} instance.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_QueryThermalInfo(
    GamePerformance_ThermalInfoQueryParameters *parameters, GamePerformance_ThermalInfo **thermalInfo);

/**
 * @brief Destroy {@link GamePerformance_ThermalInfo} instance, When the instance is no longer needed.
 *
 * @param thermalInfo Secondary pointer to the {@link GamePerformance_ThermalInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_DestroyThermalInfo(GamePerformance_ThermalInfo **thermalInfo);

/**
 * @brief Query GPU info.
 *
 * @param gpuInfo Output data. {@link GamePerformance_GpuInfo} instance.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_QueryGpuInfo(GamePerformance_GpuInfo **gpuInfo);

/**
 * @brief Destroy {@link GamePerformance_GpuInfo} instance, When the instance is no longer needed.
 *
 * @param gpuInfo Secondary pointer to the {@link GamePerformance_GpuInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_DestroyGpuInfo(GamePerformance_GpuInfo **gpuInfo);

/**
 * @brief Get GPU info {@link GamePerformance_GpuInfo} from device info {@link GamePerformance_DeviceInfo}.
 *
 * @param deviceInfo Pointer to the {@link GamePerformance_DeviceInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param gpuInfo Output data. Secondary pointer to the {@link GamePerformance_GpuInfo} instance.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_DeviceInfo_GetGpuInfo(GamePerformance_DeviceInfo *deviceInfo,
                                                                    GamePerformance_GpuInfo **gpuInfo);

/**
 * @brief Get thermal info {@link GamePerformance_ThermalInfo} from device info {@link GamePerformance_DeviceInfo}.
 *
 * @param deviceInfo Pointer to the {@link GamePerformance_DeviceInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param thermalInfo Output data. Secondary pointer to the {@link GamePerformance_GpuInfo} instance.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_DeviceInfo_GetThermalInfo(GamePerformance_DeviceInfo *deviceInfo,
                                                                        GamePerformance_ThermalInfo **thermalInfo);

/**
 * @brief Get thermal margin from thermal info {@link GamePerformance_ThermalInfo}.
 *
 * @param thermalInfo Pointer to the {@link GamePerformance_ThermalInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param thermalMargin Output data. Thermal margin.
 * provides an estimate of the thermal margin the device will have before it reaches the threshold.
 * A negative value indicates that the system cannot predict thermal margin.
 * Unit: second.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_ThermalInfo_GetThermalMargin(GamePerformance_ThermalInfo *thermalInfo,
                                                                           int32_t *thermalMargin);

/**
 * @brief Get thermal trend from thermal info {@link GamePerformance_ThermalInfo}.
 *
 * @param thermalInfo Pointer to the {@link GamePerformance_ThermalInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param thermalTrend Output data. Thermal trend.
 * Thermal trend, rate of current temperature rise. The value ranges from -100 to 100.
 * A negative value indicates that the temperature is decreasing.
 * The absolute value of the magnitude represents the rate of rise or fall.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_ThermalInfo_GetThermalTrend(GamePerformance_ThermalInfo *thermalInfo,
                                                                          int32_t *thermalTrend);

/**
 * @brief Get thermal level from thermal info {@link GamePerformance_ThermalInfo}.
 *
 * @param thermalInfo Pointer to the {@link GamePerformance_ThermalInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param thermalLevel Output data. Temperature level.
 * Temperature level. A higher value indicates a higher temperature.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_ThermalInfo_GetThermalLevel(GamePerformance_ThermalInfo *thermalInfo,
                                                                          int32_t *thermalLevel);

/**
 * @brief Get GPU load level from GPU info {@link GamePerformance_GpuInfo}.
 *
 * @param gpuInfo Pointer to the {@link GamePerformance_GpuInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param gpuLoadLevel Output data.  GPU laod level, the value ranges from 1 to 10 in ascending order.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_GpuInfo_GetGpuLoadLevel(GamePerformance_GpuInfo *gpuInfo,
                                                                      int32_t *gpuLoadLevel);

/**
 * @brief Get vertex load level from GPU info {@link GamePerformance_GpuInfo}.
 *
 * @param gpuInfo Pointer to the {@link GamePerformance_GpuInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param vertexLoadLevel Output data. GPU vertex level, the value ranges from 1 to 10 in ascending order.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_GpuInfo_GetVertexLoadLevel(GamePerformance_GpuInfo *gpuInfo,
                                                                         int32_t *vertexLoadLevel);

/**
 * @brief Get fragment load level from GPU info {@link GamePerformance_GpuInfo}.
 *
 * @param gpuInfo Pointer to the {@link GamePerformance_GpuInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param fragmentLoadLevel Output data. GPU fragment load level, the value ranges from 1 to 10 in ascending order.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_GpuInfo_GetFragmentLoadLevel(GamePerformance_GpuInfo *gpuInfo,
                                                                           int32_t *fragmentLoadLevel);

/**
 * @brief Get texture load level from GPU info {@link GamePerformance_GpuInfo}.
 *
 * @param gpuInfo Pointer to the {@link GamePerformance_GpuInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param textureLoadLevel Output data. GPU texture load level, the value ranges from 1 to 10 in ascending order.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_GpuInfo_GetTextureLoadLevel(GamePerformance_GpuInfo *gpuInfo,
                                                                          int32_t *textureLoadLevel);

/**
 * @brief Get bindwith load level from GPU info {@link GamePerformance_GpuInfo}.
 *
 * @param gpuInfo Pointer to the {@link GamePerformance_GpuInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param bandwidthLoadLevel Output data. GPU bindwith load level, the value ranges from 1 to 10 in ascending order.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_GpuInfo_GetBandwidthLoadLevel(GamePerformance_GpuInfo *gpuInfo,
                                                                            int32_t *bandwidthLoadLevel);

/**
 * @brief Get current GPU current frequency from GPU info {@link GamePerformance_GpuInfo}.
 *
 * @param gpuInfo Pointer to the {@link GamePerformance_GpuInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @param currentFrequency Output data. current GPU current frequency,
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_GpuInfo_GetCurrentFrequency(GamePerformance_GpuInfo *gpuInfo,
                                                                          int32_t *currentFrequency);

/**
 * @brief Destroy {@link GamePerformance_DeviceInfo} instance, When the instance is no longer needed.
 *
 * @param deviceInfo Secondary pointer to the {@link GamePerformance_DeviceInfo} instance.
 * The value can not be null. Otherwise, an error code will be returned.
 * @return Execution result of the function. If the operation is successful, GAME_PERFORMANCE_SUCCESS will be returned,
 * If the operation fails, an error code will be returned. For details, see {@link GamePerformance_ErrorCode}.
 * @since 5.0.2(14)
 */
GamePerformance_ErrorCode HMS_GamePerformance_DestroyDeviceInfo(GamePerformance_DeviceInfo **deviceInfo);

#ifdef __cplusplus
}
#endif

#endif //GAME_PERFORMANCE_H

/** @} */
