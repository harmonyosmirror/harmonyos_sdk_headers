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
 * @file tee_mem_mgmt_api.h
 *
 * @brief Provides APIs for memory management.
 *
 * @library NA
 * @kit TEEKit
 * @syscap SystemCapability.Tee.TeeClient
 * @since 20
 */

#ifndef TEE_MEM_MGMT_API_H
#define TEE_MEM_MGMT_API_H

#include "tee_defines.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * The definitions below are defined by Global Platform or Platform SDK released previously
 * for compatibility.
 * Do not make any change to the content below.
 */
#ifndef ZERO_SIZE_PTR

/**
 * @brief Represents a zero-size pointer.
 *
 * @since 20
 */
#define ZERO_SIZE_PTR       ((void *)16)

/**
 * @brief Checks if the pointer is either zero-size or NULL.
 *
 * @since 20
 */
#define zero_or_null_ptr(x) ((unsigned long)(x) <= (unsigned long)ZERO_SIZE_PTR)
#endif

/**
 * @brief Defines the enumeration values for memory allocation hints.
 *
 * @since 20
 */
enum MALLOC_HINT {
    /** Uninitialized buffer. */
    ZERO           = 0,
    /** Non-zero initialized buffer. */
    NOT_ZERO       = 1,
    /** 4-byte aligned buffer. */
    ALIGN_004      = 0x80000002,
    /** 8-byte aligned buffer. */
    ALIGN_008      = 0x80000003,
    /** 16-byte aligned buffer. */
    ALIGN_016      = 0x80000004,
    /** 32-byte aligned buffer. */
    ALIGN_032      = 0x80000005,
    /** 64-byte aligned buffer. */
    ALIGN_064      = 0x80000006,
    /** 128-byte aligned buffer. */
    ALIGN_128      = 0x80000007,
    /** 256-byte aligned buffer. */
    ALIGN_256      = 0x80000008,
    /** 4-byte aligned buffer initialized to zero. */
    ALIGN_004_ZERO = 0x80000012,
    /** 8-byte aligned buffer initialized to zero. */
    ALIGN_008_ZERO = 0x80000013,
    /** 16-byte aligned buffer initialized to zero. */
    ALIGN_016_ZERO = 0x80000014,
    /** 32-byte aligned buffer initialized to zero. */
    ALIGN_032_ZERO = 0x80000015,
    /** 64-byte aligned buffer initialized to zero. */
    ALIGN_064_ZERO = 0x80000016,
    /** 128-byte aligned buffer initialized to zero. */
    ALIGN_128_ZERO = 0x80000017,
    /** 256-byte aligned buffer initialized to zero. */
    ALIGN_256_ZERO = 0x80000018,
};

/**
 * @brief Allocated memory filled with zeros.
 *
 * @since 20
 */
#define TEE_MALLOC_FILL_ZERO 0x00000000

/**
 * @brief Allocated memory with no filling.
 *
 * @since 20
 */
#define TEE_MALLOC_NO_FILL   0x00000001

/**
 * @brief Allocated memory that is not shareable.
 *
 * @since 20
 */
#define TEE_MALLOC_NO_SHARE  0x00000002

/**
 * @brief Grants read access to memory.
 *
 * @since 20
 */
#define TEE_MEMORY_ACCESS_READ      0x00000001

/**
 * @brief Grants write access to memory.
 *
 * @since 20
 */
#define TEE_MEMORY_ACCESS_WRITE     0x00000002

/**
 * @brief Grants access to memory by any owner.
 *
 * @since 20
 */
#define TEE_MEMORY_ACCESS_ANY_OWNER 0x00000004

/**
 * @brief Fills <b>x</b> into the first <b>size</b> bytes of the buffer.
 *
 * @param buffer Indicates the pointer to the buffer.
 * @param x Indicates the value to fill.
 * @param size Indicates the number of bytes to fill.
 *
 * @since 20
 */
void TEE_MemFill(void *buffer, uint8_t x, size_t size);

/**
 * @brief Copies bytes.
 *
 * @param dest Indicates the pointer to the buffer that holds the bytes copied.
 * @param src Indicates the pointer to the buffer that holds the bytes to copy.
 * @param size Indicates the number of bytes to copy.
 *
 * @since 20
 */
void TEE_MemMove(void *dest, const void *src, size_t size);

/**
 * @brief Allocates space of the specified size for an object.
 *
 * @param size Indicates the size of the memory to be allocated.
 * @param hint Indicates a hint to the allocator. The value <b>0</b> indicates that the memory block
 * returned is filled with "\0".
 *
 * @return Returns a pointer to the newly allocated space if the operation is successful.
 * @return Returns a <b>NULL</b> pointer if the allocation fails.
 *
 * @since 20
 */
void *TEE_Malloc(size_t size, uint32_t hint);

/**
 * @brief Releases the memory allocated by <b>TEE_Malloc</b>.
 *
 * If the buffer is a <b>NULL</b> pointer, <b>TEE_Free</b> does nothing.
 * The buffer to be released must have been allocated by <b>TEE_Malloc</b> or <b>TEE_Realloc</b> and cannot be
 * released repeatedly. Otherwise, unexpected result may be caused.
 *
 * @param buffer Indicates the pointer to the memory to release.
 *
 * @since 20
 */
void TEE_Free(void *buffer);

/**
 * @brief Reallocates memory.
 *
 * If <b>new_size</b> is greater than the old size, the content of the original memory does not change
 * and the space in excess of the old size contains unspecified content.
 * If the new size of the memory object requires movement of the object, the space for the previous
 * instantiation of the object is deallocated.
 * If the space cannot be allocated, the original object remains allocated and this function
 * returns a <b>NULL</b> pointer.
 * If the buffer is <b>NULL</b>, this function is equivalent to <b>TEE_Malloc</b>.
 *
 * @param buffer Indicates the pointer to the memory to reallocate.
 * @param new_size Indicates the new size required.
 *
 * @return Returns a pointer to the allocated memory if the operation is successful.
 * @return Returns a <b>NULL</b> pointer if the operation fails.
 *
 * @since 20
 */
void *TEE_Realloc(void *buffer, size_t new_size);

/**
 * @brief Compares memory content from the beginning.
 *
 * @param buffer1 Indicates the pointer to the first buffer.
 * @param buffer2 Indicates the pointer to the second buffer.
 * @param size Indicates the number of the bytes to compare.
 *
 * @return Returns <b>–1</b> if buffer1 < buffer2.
 * @return Returns <b>0</b> if buffer1 == buffer2.
 * @return Returns <b>1</b> if buffer1 > buffer2.
 *
 * @since 20
 */
int32_t TEE_MemCompare(const void *buffer1, const void *buffer2, size_t size);

/**
 * @brief Checks whether this TA has the requested permissions to access a buffer.
 *
 * @param accessFlags Indicates the access permissions to check.
 * @param buffer Indicates the pointer to the target buffer.
 * @param size Indicates the size of the buffer to check.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the TA has the requested permissions.
 * @return Returns <b>TEE_ERROR_ACCESS_DENIED</b> otherwise.
 *
 * @since 20
 */
TEE_Result TEE_CheckMemoryAccessRights(uint32_t accessFlags, const void *buffer, size_t size);

/**
 * @brief Sets the TA instance data pointer.
 *
 * @param instanceData Indicates the pointer to the global TA instance data.
 *
 * @since 20
 */
void TEE_SetInstanceData(void *instanceData);

/**
 * @brief Obtains the instance data pointer set by the TA using <b>TEE_SetInstanceData</b>.
 *
 * @return Returns the pointer to the instance data set by <b>TEE_SetInstanceData</b>
 * @return or <b>NULL</b> if no instance data pointer has been set.
 *
 * @since 20
 */
void *TEE_GetInstanceData(void);

#ifdef __cplusplus
}
#endif

#endif
/** @} */