/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

/**
 * @addtogroup XEngine
 * @{
 *
 * @brief Provides graphics APIs of XEngine.
 *
 * @syscap SystemCapability.Graphic.XEngine
 * @since 5.0.0(12)
 */

/**
 * @file xeg_extension_defs.h
 * @kit XEngineKit
 * @library libxengine.so
 *
 * @brief Provides extension macro definition of XEngine.
 * @syscap SystemCapability.Graphic.XEngine
 * @since 5.0.0(12)
 */

#ifndef XEG_EXTENSION_DEFS_H
#define XEG_EXTENSION_DEFS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief Extension macro definition of GPU spatial upscaling of XEngine.
*
* @since 5.0.0(12)
*/
#define XEG_spatial_upscale 1

/**
* @brief Extension version number of GPU spatial upscaling of XEngine.
*
* @since 5.0.0(12)
*/
#define XEG_SPATIAL_UPSCALE_VERSION 1

/**
* @brief Extension name of GPU spatial upscaling of XEngine.
*
* @since 5.0.0(12)
*/
#define XEG_SPATIAL_UPSCALE_EXTENSION_NAME "XEG_spatial_upscale"


/**
* @brief Extension macro definition of AI spatial upscaling of XEngine.
*
* @since 5.0.0(12)
*/
#define XEG_neural_upscale 1

/**
* @brief Extension version number of AI spatial upscaling of XEngine.
*
* @since 5.0.0(12)
*/
#define XEG_NEURAL_UPSCALE_VERSION 1

/**
* @brief Extension name of AI spatial upscaling of XEngine.
*
* @since 5.0.0(12)
*/
#define XEG_NEURAL_UPSCALE_EXTENSION_NAME "XEG_neural_upscale"


/**
* @brief Extension macro definition of AI temporal upscaling of XEngine.
*
* @since 5.0.0(12)
*/
#define XEG_temporal_upscale 1

/**
* @brief Extension version number of AI temporal upscaling of XEngine.
*
* @since 5.0.0(12)
*/
#define XEG_TEMPORAL_UPSCALE_VERSION 1

/**
* @brief Extension name of AI temporal upscaling of XEngine.
*
* @since 5.0.0(12)
*/
#define XEG_TEMPORAL_UPSCALE_EXTENSION_NAME "XEG_temporal_upscale"


/**
* @brief Extension macro definition of adaptive VRS of XEngine.
*
* @since 5.0.0(12)
*/
#define XEG_adaptive_vrs 1

/**
* @brief Extension version number of adaptive VRS of XEngine.
*
* @since 5.0.0(12)
*/
#define XEG_ADAPTIVE_VRS_VERSION 1

/**
* @brief Extension name of adaptive VRS of XEngine.
*
* @since 5.0.0(12)
*/
#define XEG_ADAPTIVE_VRS_EXTENSION_NAME "XEG_adaptive_vrs"

#ifdef __cplusplus
}
#endif
/** @} */
#endif // XEG_EXTENSION_DEFS_H
