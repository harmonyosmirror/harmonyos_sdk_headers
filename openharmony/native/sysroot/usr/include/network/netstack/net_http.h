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
 * @addtogroup netstack
 * @{
 *
 * @brief Defines the APIs for http.
 *
 * @syscap SystemCapability.Communication.NetStack
 * @since 20
 */

/**
 * @file net_http.h
 * @brief Defines the APIs for http.
 *
 * @library libnet_http.so
 * @kit NetworkKit
 * @syscap SystemCapability.Communication.NetStack
 * @since 20
 */

#ifndef NET_HTTP_H
#define NET_HTTP_H

#include <stdint.h>
#include <string.h>

#include "net_http_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Creates headers for a request or response.
 *
 * @return Http_Headers* Pointer to {@link Http_Headers}.
 * @syscap SystemCapability.Communication.NetStack
 * @since 20
 */
Http_Headers *OH_Http_CreateHeaders(void);

/**
 * @brief Destroys the headers of a request or response.
 *
 * @param headers Pointer to the {@link Http_Headers} to be destroyed, headers ends with null.
 * @syscap SystemCapability.Communication.NetStack
 * @since 20
 */
void OH_Http_DestroyHeaders(Http_Headers **headers);

/**
 * @brief Sets the key-value pair of the request or response header.
 *
 * @param headers Pointer to the {@link Http_Headers} to be set.
 * @param name Key.
 * @param value Value.
 * @return uint32_t 0 - success. 401 - Parameter error. 2300027 - Out of memory.
 * @syscap SystemCapability.Communication.NetStack
 * @since 20
 */
uint32_t OH_Http_SetHeaderValue(struct Http_Headers *headers, const char *name, const char *value);

/**
 * @brief Obtains the value of a request or response header by key.
 *
 * @param headers Pointer to {@link Http_Headers}.
 * @param name Key.
 * @return Http_HeaderValue* Pointer to the obtained {@link Http_HeaderValue}.
 * @syscap SystemCapability.Communication.NetStack
 * @since 20
 */
Http_HeaderValue *OH_Http_GetHeaderValue(Http_Headers *headers, const char *name);

/**
 * @brief Obtains all the key-value pairs of a request or response header.
 *
 * @param headers Pointer to {@link Http_Headersaders}.
 * @return Http_HeaderEntry* Pointers to all obtained key-value pairs {@link Http_HeaderEntry}.
 * @syscap SystemCapability.Communication.NetStack
 * @since 20
 */
Http_HeaderEntry *OH_Http_GetHeaderEntries(Http_Headers *headers);

/**
 * @brief Destroys all key-value pairs obtained in {@link OH_Http_GetHeaderEntries}.
 *
 * @param headerEntry Pointer to the {@link Http_HeaderEntry} to be destroyed, headerEntry ends with null.
 * @syscap SystemCapability.Communication.NetStack
 * @since 20
 */
void OH_Http_DestroyHeaderEntries(Http_HeaderEntry **headerEntry);

/**
 * @brief Create a http request.
 *
 * @param url Http request url.
 * @return Pointer of HttpRequest if success; Null otherwise.
 * @syscap SystemCapability.Communication.NetStack
 * @since 20
 */
Http_Request *OH_Http_CreateRequest(const char *url);
 
/**
 * @brief Initiates an HTTP request.
 *
 * @param request Pointer to {@link Http_Request}.
 * @param callback Http response info, pointer to {@link Http_ResponseCallback}
 * @param handler Callbacks to watch different events, pointer to {@link Http_EventsHandler}.
 * @return 0 if success; non-0 otherwise. For details about error codes, see {@link Http_ErrCode}.
 * @permission ohos.permission.INTERNET
 * @syscap SystemCapability.Communication.NetStack
 * @since 20
 */
int OH_Http_Request(Http_Request *request, Http_ResponseCallback callback, Http_EventsHandler handler);
 
/**
 * @brief Destroy the HTTP request.
 *
 * @param request Pointer to the http request {@link Http_Request}.
 * @syscap SystemCapability.Communication.NetStack
 * @since 20
 */
void OH_Http_Destroy(struct Http_Request **request);
#ifdef __cplusplus
}
#endif
#endif // NET_HTTP_H

/** @} */