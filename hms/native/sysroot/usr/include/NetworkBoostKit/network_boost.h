
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

/**
 * @addtogroup NetworkBoost
 * @{
 *
 * @brief Defines the functions of NetworkBoost.
 *
 * @since 6.0.2(22)
 */

/**
 * @file network_boost.h
 *
 * @brief Defines the functions of Net boost module.
 * 
 * @kit NetworkBoostKit
 * @library libnetwork_boost.so
 * @syscap SystemCapability.Communication.NetworkBoost.Core
 * @since 6.0.2(22)
 */

#ifndef NETWORK_BOOST_API_H
#define NETWORK_BOOST_API_H

#include "info/application_target_sdk_version.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "network_boost_quality.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Scene event.
 * @since 6.0.2(22)
 */
typedef enum NetworkBoost_SceneEvent {
    /** enter scene event. */
    NB_SCENE_EVENT_ENTER = 0,
    /** update event after entering the scene. */
    NB_SCENE_EVENT_UPDATE = 1,
    /** leave scene event. */
    NB_SCENE_EVENT_LEAVE = 2
} NetworkBoost_SceneEvent;

/**
 * @brief Network scene description.
 * @since 6.0.2(22)
 */
typedef struct NetworkBoost_SceneDesc {
    /** Network scene. */
    NetworkBoost_ServiceType scene;
    /** Scene event. */
    NetworkBoost_SceneEvent sceneEvent;
    /** StartTime is the time point at which the scene event begins, unit: ms.
     * When StartTime is zero, it indicates that it can happen immediately, and if it is greater than zero,
     * it means it will happen in the future.
     */
    uint32_t startTime;
    /** Duration is the duration of the scene, unit: ms.
     * If the duration of the scene is unknown, the duration can be set to zero.
     */
    uint32_t duration;
} NetworkBoost_SceneDesc;

/**
 * @brief Set service scene description.
 *
 * This API is used to set service scene description.
 *
 * @param sceneDesc SceneDesc to be set.
 * @return 0 - Success.
 *         201 - Missing permissions.
 *         1013600001 - Internal error.
 *         1013600002 - System service operation failed.
 * @permission ohos.permission.INTERNET
 * @since 6.0.2(22)
 */
int32_t HMS_NetworkBoost_SetSceneDesc(NetworkBoost_SceneDesc sceneDesc)
__attribute__((__availability__(ohos, introduced=22.0.0)));

#ifdef __cplusplus
}
#endif

#endif // NETWORK_BOOST_API_H
/** @} */
