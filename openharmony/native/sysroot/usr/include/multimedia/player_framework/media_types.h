/*
 * Copyright (C) 2025 Huawei Device Co., Ltd.
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
 * @addtogroup Core
 * @{
 *
 * @brief The Core module provides basic backbone capabilities for media frameworks,
 *        including functions such as memory, error codes, and media data structures.
 *
 * @syscap SystemCapability.Multimedia.Media.Core
 * @since 18
 */

/**
 * @file media_types.h
 *
 * @brief Declared the common media types definition.
 *
 * @kit AVCodecKit
 * @library libnative_media_core.so
 * @syscap SystemCapability.Multimedia.Media.Core
 * @since 18
 */

#ifndef MEDIA_TYPES_H
#define MEDIA_TYPES_H

#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates HDR types.
 *
 * @syscap SystemCapability.Multimedia.Media.Core
 * @since 18
 */
typedef enum OH_Core_HdrType {
    /**
     * This option is used to mark none HDR type.
     */
    OH_CORE_HDR_TYPE_NONE = 0,
    /**
     * This option is used to mark HDR Vivid type.
     */
    OH_CORE_HDR_TYPE_VIVID = 1,
} OH_Core_HdrType;

#ifdef __cplusplus
}
#endif

#endif // MEDIA_TYPES_H
/** @} */
