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
 * @file xeg_gles_extension.h
 * @kit XEngineKit
 * @library libxengine.so
 *
 * @brief (GLES) API for querying extensions of XEngine.
 * @syscap SystemCapability.Graphic.XEngine
 * @since 5.0.0(12)
 */

#ifndef XEG_GLES_EXTENSION_H
#define XEG_GLES_EXTENSION_H

#include <GLES3/gl3.h>
#include "xeg_extension_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief Input parameter of the {@link HMS_XEG_GetString} API, which is used to obtain
* GLES extensions supported by XEngine.
*
* @since 5.0.0(12)
*/
#define XEG_EXTENSIONS 0x01U

/**
* @brief Defines the function pointer of the GLES API for querying extensions of XEngine.
*
* @param name Enumerated name of the input parameter. The value can be {@link XEG_EXTENSIONS}.
*
* @return If the parameter is {@link XEG_EXTENSIONS}, a list of extensions supported by XEngine is returned.
* Multiple extensions are separated by spaces. Note that the extension name does not contain any space.
* If the query fails, null pointer is returned.
*
* @since 5.0.0(12)
*/
typedef const GLubyte* (GL_APIENTRYP PFN_HMS_XEG_GETSTRING)(GLenum name);

/**
* @brief GLES API for querying extensions of XEngine.
*
* @param name Enumerated name of the input parameter. The value can be {@link XEG_EXTENSIONS}.
*
* @return If the parameter is {@link XEG_EXTENSIONS}, a list of extensions supported by XEngine is returned.
* Multiple extensions are separated by spaces. Note that the extension name does not contain any space.
* If the query fails, null pointer is returned.
*
* @since 5.0.0(12)
*/
const GLubyte* HMS_XEG_GetString(GLenum name);

#ifdef __cplusplus
}
#endif
/** @} */
#endif // XEG_GLES_EXTENSION_H