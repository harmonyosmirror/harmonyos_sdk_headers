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
 * @addtogroup TeeTrusted
 * @{
 *
 * @brief TEE(Trusted Excution Environment) API.
 * Provides security capability APIs such as trusted storage, encryption and decryption,
 * and trusted time for trusted application development.
 *
 * @since 20
 */

/**
 * @file tee_service_public.h
 *
 * @brief Provides the TEE service public function for developers.
 *
 * @library NA
 * @kit TEEKit
 * @syscap SystemCapability.Tee.TeeClient
 * @since 20
 */

#ifndef _TEE_SERVICE_PUBLIC_H_
#define _TEE_SERVICE_PUBLIC_H_

#include "tee_defines.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines a function pointer type.
 *
 * @since 20
 */
typedef void (*func_ptr)(void);

/**
 * @brief Defines the size of the message queue for the TEE service
 *
 * @since 20
 */
#define TEE_SERVICE_MSG_QUEUE_SIZE 100

/**
 * @brief Defines the maximum size of the image hash.
 *
 * @since 20
 */
#define MAX_IMAGE_HASH_SIZE 64

/**
 * @brief Defines the arguments of a message.
 *
 * @since 20
 */
typedef struct {
    /** Argument 0. */
    uint64_t arg0;
    /** Argument 1. */
    uint64_t arg1;
    /** Argument 2. */
    uint64_t arg2;
    /** Argument 3. */
    uint64_t arg3;
    /** Argument 4. */
    uint64_t arg4;
    /** Argument 5. */
    uint64_t arg5;
    /** Argument 6. */
    uint64_t arg6;
    /** Argument 7. */
    uint64_t arg7;
} args_t;

/**
 * @brief Defines the register information of TA.
 *
 * @since 20
 */
struct reg_ta_info {
    /** TA's task ID. */
    uint32_t taskid;
    /** TA's UUID (Universally Unique Identifier). */
    TEE_UUID uuid;
    /** User ID. */
    uint32_t userid;
    /** Used only for SSA; other tasks should ignore this field. */
    bool ssa_enum_enable;
};

/**
 * @brief Defines the IPC message of TEE service.
 *
 * @since 20
 */
typedef union {
    /** Parameter data. */
    args_t args_data;
    /** TA's registration information. */
    struct reg_ta_info reg_ta;
} tee_service_ipc_msg;

/**
 * @brief Defines the IPC request message of TEE service.
 *
 * @since 20
 */
struct tee_service_ipc_msg_req {
    /** Command identifier for the request. */
    uint32_t cmd;
    /** IPC message carried by the request. */
    tee_service_ipc_msg msg;
};

/**
 * @brief Defines the IPC response message of TEE service.
 *
 * @since 20
 */
typedef struct {
    /** Return result of the request. */
    TEE_Result ret;
    /** IPC message carried by the response. */
    tee_service_ipc_msg msg;
} tee_service_ipc_msg_rsp;

/**
 * @brief Defines the message of the TEE service.
 *
 * @since 20
 */
typedef struct {
    /** Message ID, a unique identifier for the message. */
    uint32_t msg_id;
    /** Sender ID of the message. */
    uint32_t sender;
    /** Message data. */
    tee_service_ipc_msg msg;
} tee_service_msg_t;

/**
 * @brief Defines the message queue for the TEE service.
 *
 * @since 20
 */
typedef struct {
    /** Pointer to the input position of the queue. */
    uint32_t in;
    /** Pointer to the output position of the queue. */
    uint32_t out;
    /** Array of messages, storing the messages in the queue. */
    tee_service_msg_t msg[TEE_SERVICE_MSG_QUEUE_SIZE];
} tee_service_msg_queue_t;

/**
 * @brief Provides to send IPC synchronization messages to a specified service
 *  and receive responses from the service.
 *
 * @param task_name Indicates the task name of recipient.
 * @param snd_cmd Indicates the command ID of the send message.
 * @param snd_msg Indicates the send message.
 * @param ack_cmd Indicates the ID of the ack cmd to be received.
 * @param rsp_msg Indicates the service response message.
 *
 * @since 20
 */
void tee_common_ipc_proc_cmd(const char *task_name,
                             uint32_t snd_cmd, const tee_service_ipc_msg *snd_msg,
                             uint32_t ack_cmd, tee_service_ipc_msg_rsp *rsp_msg);

#ifdef __cplusplus
}
#endif

#endif
/** @} */