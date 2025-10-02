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
 * @addtogroup MuslMalloc
 * @{
 *
 * @brief Provide some methods related to memory management.
 * @since 12
 */
/**
 * @file malloc.h
 *
 * @brief Includes some memory-related methods and structures,
 * such as: malloc, calloc, realloc, and so on.
 * 
 * @library libc.so
 * @kit CstandardLibrary
 * @since 12
 */

#ifndef _MALLOC_H
#define _MALLOC_H

#ifdef __cplusplus
extern "C" {
#endif

#define __NEED_size_t

#include <bits/alltypes.h>

#define M_SET_THREAD_CACHE (-1001)
#define M_THREAD_CACHE_ENABLE 1
#define M_THREAD_CACHE_DISABLE 0

#define M_FLUSH_THREAD_CACHE (-1002)

#define M_DELAYED_FREE (-1003)
#define M_DELAYED_FREE_ENABLE 1
#define M_DELAYED_FREE_DISABLE 0

#define M_OHOS_CONFIG (-1004)
#define M_DISABLE_OPT_TCACHE 100
#define M_ENABLE_OPT_TCACHE 101
#define M_TCACHE_PERFORMANCE_MODE 102
#define M_TCACHE_NORMAL_MODE 103

void *malloc (size_t);
void *calloc (size_t, size_t);
void *realloc (void *, size_t);
void free (void *);
void *valloc (size_t);
void *memalign(size_t, size_t);

size_t malloc_usable_size(void *);
int mallopt(int param, int value);

/**
 * @brief This function determines whether a given memory block was allocated using
 *        Standard C library Memory Allocator.
 * 		    This function is MT-Safe(multi-thread safe) but not signal-safe.
 * @param {void *} ptr A pointer to the memory block to be checked.
 * @return  1 - The memory block was allocated using Standard C library Memory Allocator.
 *          0 - The memory block was not allocated using Standard C library Memory Allocator.
 *          -1 - The function is not implemented or other error.
 * @since 19
 */
int malloc_check_from_ptr(void *ptr);

struct mallinfo {
  int arena;
  int ordblks;
  int smblks;
  int hblks;
  int hblkhd;
  int usmblks;
  int fsmblks;
  int uordblks;
  int fordblks;
  int keepcost;
};

struct mallinfo2 {
  size_t arena;
  size_t ordblks;
  size_t smblks;
  size_t hblks;
  size_t hblkhd;
  size_t usmblks;
  size_t fsmblks;
  size_t uordblks;
  size_t fordblks;
  size_t keepcost;
};

/**
 * @brief Obtains the memory information allocated by malloc-related operations.
 * @return A mallinfo struct containing details about memory allocation.
 * @since 20
 */
struct mallinfo mallinfo(void);

/**
 * @brief Obtains the memory information allocated by malloc-related operations.
 * @return A mallinfo2 struct containing details about memory allocation. Unlike mallinfo, this struct uses
 * size_t for its counters, providing a larger range.
 * @since 20
 */
struct mallinfo2 mallinfo2(void);

#ifdef __cplusplus
}
#endif

#endif
/** @} */