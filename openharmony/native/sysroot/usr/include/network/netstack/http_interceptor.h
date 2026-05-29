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
 * @file http_interceptor.h
 * @brief Defines the APIs for http global interceptor.
 *
 * @library libhttp_interceptor.so
 * @kit NetworkKit
 * @syscap SystemCapability.Communication.NetStack
 * @since 24
 */

#ifndef HTTP_INTERCEPTOR_H
#define HTTP_INTERCEPTOR_H

#include "info/application_target_sdk_version.h"
#include "http_interceptor_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief add a read-only http global interceptor for HTTP requests.
 *
 * @param interceptor Http global interceptor configuration, Pointer to {@link OH_Http_Interceptor}.
 * @return {@link OH_HTTP_RESULT_OK} 0 -if the operation is successful.
 *         {@link OH_HTTP_PERMISSION_DENIED} 201 -if permission is denied.
 * @permission ohos.permission.INTERNET
 * @note The interceptor remains active until it is explicitly removed by the developer.
 *     you must call {@link OH_Http_RemoveInterceptor} to release a specific interceptor
 *     or {@link OH_Http_RemoveAllInterceptors} to release a group of interceptors.
 * @since 24
 */
int32_t OH_Http_AddReadOnlyInterceptor(struct OH_Http_Interceptor *interceptor)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief delete a specific http global interceptor
 *
 * @param interceptor Http global interceptor configuration, Pointer to {@link OH_Http_Interceptor}.
 * @return {@link OH_HTTP_RESULT_OK} 0 -if the operation is successful.
 *         {@link OH_HTTP_PERMISSION_DENIED} 201 -if permission is denied.
 * @permission ohos.permission.INTERNET
 * @since 24
 */
int32_t OH_Http_RemoveInterceptor(struct OH_Http_Interceptor *interceptor)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Deletes all HTTP interceptors matching the specified group ID.
 *
 * @param groupId http global interceptor group id
 * @return {@link OH_HTTP_RESULT_OK} 0 -if the operation is successful.
 *         {@link OH_HTTP_PERMISSION_DENIED} 201 -if permission is denied.
 * @permission ohos.permission.INTERNET
 * @note The groupId is allocated and managed by the application itself when creating
 *     interceptors. If multiple modules within the application need to use interceptors,
 *     the application must properly allocate and manage groupId to avoid conflicts.
 *     Conflicts in groupId between internal modules may lead to accidental deletion
 *     of interceptors when calling this function.
 * @since 24
 */
int32_t OH_Http_RemoveAllInterceptors(int32_t groupId) __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief start all http global interceptors by groupId
 *
 * @param groupId http global interceptor group id
 * @return {@link OH_HTTP_RESULT_OK} 0 -if the operation is successful.
 *         {@link OH_HTTP_PERMISSION_DENIED} 201 -if permission is denied.
 * @permission ohos.permission.INTERNET
 * @since 24
 */
int32_t OH_Http_StartAllInterceptors(int32_t groupId) __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief stop all http global interceptors by groupId
 *
 * @param groupId http global interceptor group id
 * @return {@link OH_HTTP_RESULT_OK} 0 -if the operation is successful.
 *         {@link OH_HTTP_PERMISSION_DENIED} 201 -if permission is denied.
 * @permission ohos.permission.INTERNET
 * @since 24
 */
int32_t OH_Http_StopAllInterceptors(int32_t groupId) __attribute__((__availability__(ohos, introduced=24.0.0)));

#ifdef __cplusplus
}
#endif
#endif // HTTP_INTERCEPTOR_H

/** @} */