/*
 * Copyright (C) 2026 Huawei Device Co., Ltd.
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
 * @addtogroup netstack
 * @{
 *
 * @brief Defines the APIs for http global interceptor.
 *
 * @since 24
 */

/**
 * @file http_interceptor_type.h
 * @brief Defines the data structure for the C APIs of the http global interceptor.
 *
 * @library libhttp_interceptor.so
 * @kit NetworkKit
 * @syscap SystemCapability.Communication.NetStack
 * @since 24
 */

#ifndef HTTP_INTERCEPTOR_TYPE_H
#define HTTP_INTERCEPTOR_TYPE_H

#include <stdint.h>
#ifdef __cplusplus
#include <cstddef>
#else
#include <stddef.h>
#endif
#include "net_http_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines interceptor header.
 *
 * @since 24
 */
typedef struct OH_Http_Interceptor_Headers {
    /**
     * @brief Header data
     * @since 24
     */
    char *data;
    /**
     * @brief Next Header
     * @since 24
     */
    struct OH_Http_Interceptor_Headers *next;
} OH_Http_Interceptor_Headers;

/**
 * @brief Defines interceptor request
 *
 * @since 24
 */
typedef struct OH_Http_Interceptor_Request {
    /**
     * @brief Request url, see {@link Http_Buffer}.
     * @since 24
     */
    Http_Buffer url;
    /**
     * @brief Request method, see {@link Http_Buffer}.
     * @since 24
     */
    Http_Buffer method;
    /**
     * @brief Header of http Request, see {@link OH_Http_Interceptor_Headers}.
     * @since 24
     */
    OH_Http_Interceptor_Headers *headers;
    /**
     * @brief Request body, see {@link Http_Buffer}.
     * @since 24
     */
    Http_Buffer body;
} OH_Http_Interceptor_Request;

/**
 * @brief Defines interceptor response
 *
 * @since 24
 */
typedef struct OH_Http_Interceptor_Response {
    /**
     * @brief Response body, see {@link Http_Buffer}.
     * @since 24
     */
    Http_Buffer body;
    /**
     * @brief Server status code, see {@link Http_ResponseCode}.
     * @since 24
     */
    Http_ResponseCode responseCode;
    /**
     * @brief Header of http response, see {@link OH_Http_Interceptor_Headers}.
     * @since 24
     */
    OH_Http_Interceptor_Headers *headers;
    /**
     * @brief The time taken of various stages of HTTP request, see {@link Http_PerformanceTiming}.
     * @since 24
     */
    Http_PerformanceTiming performanceTiming;
} OH_Http_Interceptor_Response;

/**
 * @brief Defines interceptor stage
 *
 * @since 24
 */
typedef enum OH_Interceptor_Stage {
    /**
     * @brief http request hook
     * @since 24
     */
    OH_STAGE_REQUEST,
    /**
     * @brief http response hook
     * @since 24
     */
    OH_STAGE_RESPONSE
} OH_Interceptor_Stage;

/**
 * @brief Defines interceptor type
 *
 * @since 24
 */
typedef enum OH_Interceptor_Type {
    /**
     * @brief interceptor will not modify the packet
     * @since 24
     */
    OH_TYPE_READ_ONLY
} OH_Interceptor_Type;

/**
 * @brief Defines interceptor process result
 *
 * @since 24
 */
typedef enum OH_Interceptor_Result {
    /**
     * @brief interceptor result is continue
     * @since 24
     */
    OH_CONTINUE,
    /**
     * @brief interceptor result is abort this packet
     * @since 24
     */
    OH_ABORT
} OH_Interceptor_Result;

/**
 * @brief Defines interceptor handler
 *
 * @since 24
 */
typedef OH_Interceptor_Result (*OH_Http_InterceptorHandler)(
    /**
     * @brief http request packet
     * @since 24
     */
    OH_Http_Interceptor_Request *request,
    /**
     * @brief http response packet
     * @since 24
     */
    OH_Http_Interceptor_Response *response,
    /**
     * @brief whether interceptor modified the packet
     * @since 24
     */
    int32_t *isModified);

/**
 * @brief Defines interceptor configuration
 *
 * @since 24
 */
typedef struct OH_Http_Interceptor {
    /**
     * @brief group id of interceptor
     * @since 24
     */
    int32_t groupId;
    /**
     * @brief stage of interceptor
     * @since 24
     */
    OH_Interceptor_Stage stage;
    /**
     * @brief type of interceptor
     * @since 24
     */
    OH_Interceptor_Type type;
    /**
     * @brief handler of interceptor
     * @since 24
     */
    OH_Http_InterceptorHandler handler;
    /**
     * @brief whether the interceptor is enabled
     * @since 24
     */
    int32_t enabled;
} OH_Http_Interceptor;

#ifdef __cplusplus
}
#endif
#endif // HTTP_INTERCEPTOR_TYPE_H

/** @} */