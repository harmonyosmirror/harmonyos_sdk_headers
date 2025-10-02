/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
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
 * @addtogroup Pasteboard
 * @{
 *
 * @brief Provides the copy and paste support for the system Pasteboard.
 * You can use the APIs of this module to operate the Pasteboard content of the plain text, HTML,
 * URI, Want, pixel map, and other types.
 *
 * @since 13
 */

/**
 * @file OH_Pasteboard.h
 *
 * @brief Provides APIs and enums of the Pasteboard module.
 *
 * @kit BasicServicesKit
 * @library libpasteboard.so
 * @syscap SystemCapability.MiscServices.Pasteboard
 *
 * @since 13
 */

#ifndef OH_PASTEBOARD_H
#define OH_PASTEBOARD_H

#include <inttypes.h>
#include <stdbool.h>
#include "database/udmf/udmf.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates the types of data changes that can be observed.
 *
 * @since 13
 */
typedef enum Pasteboard_NotifyType {
    /**
     * @brief Change of the Pasteboard data in the local device.
     */
    NOTIFY_LOCAL_DATA_CHANGE = 1,
    /**
     * @brief Change of the Pasteboard data in the remote devices.
     */
    NOTIFY_REMOTE_DATA_CHANGE = 2
} Pasteboard_NotifyType;

/**
 * @brief Defines the callback function used to return the Pasteboard data changed.
 *
 * @param context The context set by {@link OH_PasteboardObserver_SetData} function.
 * @param type The types of data changes. For details, see {@link Pasteboard_NotifyType}.
 * @since 13
 */
typedef void (*Pasteboard_Notify)(void* context, Pasteboard_NotifyType type);

/**
 * @brief Defines the callback function used free the context.
 * @param context Pointer to the context which is to be free.
 * @since 13
 */
typedef void (*Pasteboard_Finalize)(void* context);

/**
 * @brief Defines the Pasteboard subscriber information
 *
 * @since 13
 */
typedef struct OH_PasteboardObserver OH_PasteboardObserver;

/**
 * @brief Creates a {@link OH_PasteboardObserver} instance.
 *
 * @return Returns the pointer to the {@link OH_PasteboardObserver} instance created if the operation is successful.
 * Returns nullptr if the operation is failed.
 * @see OH_PasteboardObserver.
 * @since 13
 */
OH_PasteboardObserver* OH_PasteboardObserver_Create();

/**
 * @brief Destroy a {@link OH_PasteboardObserver} instance.
 *
 * @param observer Pointer to the {@link OH_PasteboardObserver} instance to destroy.
 * @return Returns the status code of the execution. For details, see {@link PASTEBOARD_ErrCode}.
 *         Returns {@link ERR_OK} if the operation is successful.
 *         Returns {@link ERR_INVALID_PARAMETER} if invalid args are detected.
 * @see OH_PasteboardObserver PASTEBOARD_ErrCode.
 * @since 13
 */
int OH_PasteboardObserver_Destroy(OH_PasteboardObserver* observer);

/**
 * @brief Sets a callback function to return the Pasteboard data changed.
 *
 * @param observer Pointer to the {@link OH_PasteboardObserver} instance.
 * @param context Pointer to the context set, which is the first parameter in Pasteboard_Notify.
 * @param callback Callback to set. For details, see {@link Pasteboard_Notify}.
 * @param finalize Optional callback that can free context when destroy observer.
 *         For details, see {@link Pasteboard_Finalize}.
 * @return Returns the status code of the execution. For details, see {@link PASTEBOARD_ErrCode}.
 *         Returns {@link ERR_OK} if the operation is successful.
 *         Returns {@link ERR_INVALID_PARAMETER} if invalid args are detected.
 * @see OH_PasteboardObserver Pasteboard_Notify PASTEBOARD_ErrCode.
 * @since 13
 */
int OH_PasteboardObserver_SetData(OH_PasteboardObserver* observer, void* context,
    const Pasteboard_Notify callback, const Pasteboard_Finalize finalize);

/**
 * @brief Represents the Pasteboard information.
 *
 * @since 13
 */
typedef struct OH_Pasteboard OH_Pasteboard;

/**
 * @brief Creates a {@link OH_Pasteboard} instance.
 *
 * @return Returns the pointer to the {@link OH_Pasteboard} instance created if the operation is successful.
 * Returns nullptr if the memory is not enough.
 * @see OH_Pasteboard.
 * @since 13
 */
OH_Pasteboard* OH_Pasteboard_Create();

/**
 * @brief Destroy a {@link OH_Pasteboard} instance.
 *
 * @param pasteboard Pointer to the {@link OH_Pasteboard} instance to destroy.
 * @see OH_Pasteboard.
 * @since 13
 */
void OH_Pasteboard_Destroy(OH_Pasteboard* pasteboard);

/**
 * @brief Subscribes to the Pasteboard data change.
 *
 * @param pasteboard Pointer to the {@link OH_Pasteboard} instance.
 * @param type Event type to subscribe to.
 * @param observer - Pointer to the observer information, which specifies the callback used to
 * reporting the pasteboard data change. For details, see {@link OH_PasteboardObserver}.
 * @return Returns the status code of the execution. For details, {@link PASTEBOARD_ErrCode}.
 *         Returns {@link ERR_OK} if the operation is successful.
 *         Returns {@link ERR_INVALID_PARAMETER} if invalid args are detected.
 * @see OH_Pasteboard OH_PasteboardObserver PASTEBOARD_ErrCode.
 * @since 13
 */
int OH_Pasteboard_Subscribe(OH_Pasteboard* pasteboard, int type, const OH_PasteboardObserver* observer);

/**
 * @brief Unsubscribes from the Pasteboard data change.
 *
 * @param pasteboard Pointer to the {@link OH_Pasteboard} instance.
 * @param type Event type to subscribe to.
 * @param observer - Pointer to the observer information, which specifies the callback used to
 * reporting the pasteboard data change. For details, see {@link OH_PasteboardObserver}.
 * @return Returns the status code of the execution. For details, {@link PASTEBOARD_ErrCode}.
 *         Returns {@link ERR_OK} if the operation is successful.
 *         Returns {@link ERR_INVALID_PARAMETER} if invalid args are detected.
 * @see OH_Pasteboard OH_PasteboardObserver PASTEBOARD_ErrCode.
 * @since 13
 */
int OH_Pasteboard_Unsubscribe(OH_Pasteboard* pasteboard, int type, const OH_PasteboardObserver* observer);

/**
 * @brief Checks whether the Pasteboard data is from a remote device.
 *
 * @param pasteboard Pointer to the {@link OH_Pasteboard} instance.
 * @return Returns a boolean value, which indicates whether the the data is from a remote device.
 *         The value {@code false} means Pasteboard data is not from a remote device.
 *         The value {@code true} means the opposite.
 * @see OH_Pasteboard.
 * @since 13
 */
bool OH_Pasteboard_IsRemoteData(OH_Pasteboard* pasteboard);

/**
 * @brief Obtains the source of Pasteboard data.
 *
 * @param pasteboard Pointer to the {@link OH_Pasteboard} instance.
 * @param source Pointer to the source data.
 * @param len Length of the source data.
 * @return Returns the status code of the execution. For details, see {@link PASTEBOARD_ErrCode}.
 *         Returns {@link ERR_OK} if the operation is successful.
 *         Returns {@link ERR_INVALID_PARAMETER} if invalid args are detected.
 * @see OH_Pasteboard PASTEBOARD_ErrCode.
 * @since 13
 */
int OH_Pasteboard_GetDataSource(OH_Pasteboard* pasteboard, char* source, unsigned int len);

/**
 * @brief Checks whether the Pasteboard has the specified type of data.
 *
 * @param pasteboard Pointer to the {@link OH_Pasteboard} instance.
 * @param type Poniter to the type of data to check.
 * @return Returns a boolean value, which indicates whether the Pasteboard has the specified type of data.
 *         The value {@code true} means the Pasteboard has the specified type of data.
 *         The value {@code false} means the opposite.
 * @see OH_Pasteboard.
 * @since 13
 */
bool OH_Pasteboard_HasType(OH_Pasteboard* pasteboard, const char* type);

/**
 * @brief Checks whether there is data in the Pasteboard.
 *
 * @param pasteboard Pointer to the {@link OH_Pasteboard} instance.
 * @return Returns a boolean value, which indicates whether there is data in the Pasteboard.
 *         The value {@code true} means there is data in Pasteboard.
 *         The value {@code false} means the opposite.
 * @see OH_Pasteboard.
 * @since 13
 */
bool OH_Pasteboard_HasData(OH_Pasteboard* pasteboard);

/**
 * @brief Obtains data from the Pasteboard.
 *
 * @param pasteboard Pointer to the {@link OH_Pasteboard} instance.
 * @param status The status code of the execution. For details, see {@link PASTEBOARD_ErrCode}.
 * @return Returns the pointer to the {@link OH_UdmfData} instance.
 * @see OH_Pasteboard OH_UdmfData PASTEBOARD_ErrCode.
 * @since 13
 */
OH_UdmfData* OH_Pasteboard_GetData(OH_Pasteboard* pasteboard, int* status);

/**
 * @brief Writes data to the Pasteboard.
 *
 * @param pasteboard Pointer to the {@link OH_Pasteboard} instance.
 * @param data Pointer to the {@link OH_UdmfData} instance.
 * @return Returns the status code of the execution. For details, see {@link PASTEBOARD_ErrCode}.
 *         Returns {@link ERR_OK} if the operation is successful.
 *         Returns {@link ERR_INVALID_PARAMETER} if invalid args are detected.
 * @see OH_Pasteboard OH_UdmfData PASTEBOARD_ErrCode.
 * @since 13
 */
int OH_Pasteboard_SetData(OH_Pasteboard* pasteboard, OH_UdmfData* data);

/**
 * @brief Clears the data in the Pastedboard.
 *
 * @param pasteboard Pointer to the {@link OH_Pasteboard} instance.
 * @return Returns the status code of the execution. For details, see {@link PASTEBOARD_ErrCode}.
 *         Returns {@link ERR_OK} if the operation is successful.
 *         Returns {@link ERR_INVALID_PARAMETER} if invalid args are detected.
 * @see OH_Pasteboard PASTEBOARD_ErrCode.
 * @since 13
 */
int OH_Pasteboard_ClearData(OH_Pasteboard* pasteboard);
#ifdef __cplusplus
};
#endif

/** @} */
#endif