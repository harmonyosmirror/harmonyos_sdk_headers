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
 * @addtogroup TeeClient
 * @{
 *
 * @brief Provides APIs for the client applications (CAs) in the Rich Execution Environment (normal mode) to
 * access the trusted applications (TAs) in a Trusted Execution Environment (TEE).
 *
 * @since 20
 */

/**
 * @file tee_client_type.h
 *
 * @brief Defines basic data types and data structures.
 *
 * @library libteec.so
 * @kit TEEKit
 * @syscap SystemCapability.Tee.TeeClient
 * @since 20
 */

#ifndef TEE_CLIENT_TYPE_H
#define TEE_CLIENT_TYPE_H

#include <semaphore.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include "tee_client_constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines the linked list type.
 *
 * @since 20
 */
struct ListNode {
    /** Pointer to the next node in the list. */
    struct ListNode *next;
    /** Pointer to the previous node in the list. */
    struct ListNode *prev;
};

/**
 * @brief Defines the return values.
 *
 * @since 20
 */
typedef enum TEEC_ReturnCode TEEC_Result;

/**
 * @brief Defines the universally unique identifier (UUID) as defined in RFC4122 [2].
 * The UUIDs are used to identify TAs.
 *
 * @since 20
 */
typedef struct {
    /** The low part of the time field. */
    uint32_t timeLow;
    /** The middle part of the time field. */
    uint16_t timeMid;
    /** The high part of the time field and version information. */
    uint16_t timeHiAndVersion;
    /** The clock sequence and node field (8 bytes). */
    uint8_t clockSeqAndNode[8];
} TEEC_UUID;

/**
 * @brief Defines the context, a logical connection between a CA and a TEE.
 *
 * @since 20
 */
typedef struct {
    /** File descriptor for the TA. */
    int32_t fd;
    /** Path to the Trusted Application (TA). */
    uint8_t *ta_path;
    /** Linked list of sessions associated with the context. */
    struct ListNode session_list;
    /** Linked list of shared memory regions associated with the context. */
    struct ListNode shrd_mem_list;
    /**
     * @brief Union for either shared buffer or implementation data.
     *
     * @since 20
     */
    union {
        /**
         * @brief Shared buffer used for data exchange and synchronization.
         *
         * @since 20
         */
        struct {
            /** Pointer to the shared buffer. */
            void *buffer;
            /** Semaphore for synchronization of the shared buffer. */
            sem_t buffer_barrier;
        } share_buffer;
        /** Implementation-specific data. */
        uint64_t imp;
    };
} TEEC_Context;

/**
 * @brief Defines the session between a CA and a TA.
 *
 * @since 20
 */
typedef struct {
    /** Session ID for the session. */
    uint32_t session_id;
    /** UUID representing the service associated with the session. */
    TEEC_UUID service_id;
    /** The number of operations associated with the session. */
    uint32_t ops_cnt;
    /**
     * @brief Union for either a linked list head or implementation-specific data.
     *
     * @since 20
     */
    union {
        /** Linked list head for session-related data. */
        struct ListNode head;
        /** Implementation-specific data. */
        uint64_t imp;
    };
    /** Pointer to the TEEC context associated with the session. */
    TEEC_Context *context;
} TEEC_Session;

/**
 * @brief Defines a shared memory block, which can be registered or allocated.
 *
 * @since 20
 */
typedef struct {
    /** Pointer to the shared memory buffer. */
    void *buffer;
    /** Size of the shared memory buffer. */
    uint32_t size;
    /** Flags associated with the shared memory. */
    uint32_t flags;
    /** The number of operations associated with the shared memory. */
    uint32_t ops_cnt;
    /** Indicates whether the memory has been allocated. */
    bool is_allocated;
    /**
     * @brief Union for either a linked list head or implementation-specific data.
     *
     * @since 20
     */
    union {
        /** Linked list head for shared memory-related data. */
        struct ListNode head;
        /** Implementation-specific data. */
        void* imp;
    };
    /** Pointer to the TEEC context associated with the shared memory. */
    TEEC_Context *context;
} TEEC_SharedMemory;

/**
 * @brief Defines a pointer to a temporary buffer.
 *
 * @since 20
 */
typedef struct {
    /** Pointer to the temporary memory buffer. */
    void *buffer;
    /** Size of the temporary memory buffer. */
    uint32_t size;
} TEEC_TempMemoryReference;

/**
 * @brief Defines a pointer to the shared memory that is registered or allocated.
 *
 * @since 20
 */
typedef struct {
    /** Pointer to the parent shared memory. */
    TEEC_SharedMemory *parent;
    /** Size of the registered memory reference. */
    uint32_t size;
    /** Offset within the parent shared memory. */
    uint32_t offset;
} TEEC_RegisteredMemoryReference;

/**
 * @brief Describes a parameter that carries small raw data passed by <b>value</b>.
 *
 * @since 20
 */
typedef struct {
    /** The first value. */
    uint32_t a;
    /** The second value. */
    uint32_t b;
} TEEC_Value;

/**
 * @brief Describes the size and handle of the ION memory.
 *
 * @since 20
 */
typedef struct {
    /** File descriptor for the shared ion memory. */
    int ion_share_fd;
    /** Size of the ion memory. */
    uint32_t ion_size;
} TEEC_IonReference;

/**
 * @brief Defines a parameter of {@code TEEC_Operation}.
 *
 * @since 20
 */
typedef union {
    /** Temporary memory reference. */
    TEEC_TempMemoryReference tmpref;
    /** Registered memory reference. */
    TEEC_RegisteredMemoryReference memref;
    /** A value containing two 32-bit values. */
    TEEC_Value value;
    /** Ion memory reference. */
    TEEC_IonReference ionref;
} TEEC_Parameter;

/**
 * @brief Defines the parameters for the Trusted User Interface (TUI).
 *
 * @since 20
 */
typedef struct {
    /** TUI event type. */
    uint32_t event_type;
    /** Return value, is keycode if TUI event is getKeycode. */
    uint32_t value;
    /** Notch size of the screen for the TUI. */
    uint32_t notch;
    /** Width of the foldable screen for the TUI. */
    uint32_t width;
    /** Height of the foldable screen for the TUI. */
    uint32_t height;
    /** State of the foldable screen for the TUI. */
    uint32_t fold_state;
    /** One state of the folded screen for the TUI. */
    uint32_t display_state;
    /** Real width of the mobile device for the TUI. */
    uint32_t phy_width;
    /** Real height of the mobile device for the TUI. */
    uint32_t phy_height;
} TEEC_TUI_Parameter;

/**
 * @brief Defines the parameters for opening a session or sending a command.
 *
 * @since 20
 */
typedef struct {
    /** The value 0 means to cancel the command, and other values mean to execute the command. */
    uint32_t started;
    /** Use {@code TEEC_PARAM_TYPES} to create this parameter. */
    uint32_t paramTypes;
    /** Array of parameters for the operation. */
    TEEC_Parameter params[TEEC_PARAM_NUM];
    /** Pointer to the session associated with the operation. */
    TEEC_Session *session;
    /** Flag indicating whether the operation is canceled. */
    bool cancel_flag;
} TEEC_Operation;

#ifdef __cplusplus
}
#endif

#endif
/** @} */