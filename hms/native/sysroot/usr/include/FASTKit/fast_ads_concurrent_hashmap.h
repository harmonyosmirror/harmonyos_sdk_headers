
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

/**
 * @file fast_ads_concurrent_hashmap.h
 *
 * @brief A thread-safe concurrent hash map implementation supporting safe multi-threaded access.
 *
 * @library libfast_ads.so
 * @kit FASTKit
 * @syscap SystemCapability.FAST.Core
 * @since 6.1.1(24)
 */

/**
 * @addtogroup FAST
 * @{
 *
 * @brief Provide acceleration capabilities to optimize metrics
 *        such as application startup, loading, and response latency.
 * 
 * @since 6.1.1(24)
 */
#ifndef FAST_ADS_CONCURRENT_HASHMAP_H
#define FAST_ADS_CONCURRENT_HASHMAP_H
#include "info/application_target_sdk_version.h"
#include "fast_common_def.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Opaque handle to a concurrent hash map instance.
 *
 * @since 6.1.1(24)
 */
typedef void* FAST_ConcurrentHashmapHandle;

/**
 * @brief Pointer type representing a key in the concurrent hash map.
 *
 * @note The memory pointed to must be managed by the caller and remain valid for the lifetime of the entry.
 *
 * @since 6.1.1(24)
 */
typedef void* FAST_ConcurrentHashmapKeyPtr;

/**
 * @brief Pointer type representing a value in the concurrent hash map.
 *
 * @note The memory pointed to must be managed by the caller and remain valid for the lifetime of the entry.
 *
 * @since 6.1.1(24)
 */
typedef void* FAST_ConcurrentHashmapValuePtr;

/**
 * @brief Custom hash function callback.
 *
 * @param key The {@link FAST_ConcurrentHashmapKeyPtr} to compute the hash for.
 * @return A 64-bit hash value derived from the key.
 *
 * @since 6.1.1(24)
 */
typedef uint64_t (*HMS_FAST_ConcurrentHashmap_HashFunc)(const FAST_ConcurrentHashmapKeyPtr key);

/**
 * @brief Custom key equality comparison function callback.
 *
 * @param leftKey A pointer to a key in the hashmap, passed as the left operand of equality comparison.
 * @param rightKey A pointer to another key in the hashmap, passed as the right operand of equality comparison.
 * @return Non-zero if the keys are considered equal; zero otherwise.
 *
 * @since 6.1.1(24)
 */
typedef int32_t (*HMS_FAST_ConcurrentHashmap_KeyEqualFunc)(
    const FAST_ConcurrentHashmapKeyPtr leftKey,
    const FAST_ConcurrentHashmapKeyPtr rightKey
);

/**
 * @brief Generic predicate or action callback function used during hash map traversal.
 *
 * @param key Key of the current element being visited.
 * @param value Value associated with the key.
 * @param context User-defined context passed through the traversal API.
 * @return Non-zero to indicate the condition is satisfied (e.g., for filtering);
 *         zero otherwise.
 *
 * @note This function is typically used in APIs that support conditional processing,
 *       such as selective deletion or transformation. The exact interpretation of
 *       the return value depends on the calling function:
 *       - In a predicate context (e.g., erase-if), a non-zero return usually means "match".
 *       - In an action context, the return value may be ignored.
 *
 * @since 6.1.1(24)
 */
typedef int32_t (*HMS_FAST_ConcurrentHashmap_HookFunc)(
    const FAST_ConcurrentHashmapKeyPtr key,
    FAST_ConcurrentHashmapValuePtr value,
    void* context
);

/**
 * @brief Creates a new concurrent hash map instance.
 *
 * @param handle Pointer to store the created hash map handle.
 * @param hasher Hash function callback.
 * @param equaler Key equality comparison callback.
 * @param maxLoadFac Maximum load factor before internal resizing.
 * @param numShards Number of internal shards for concurrency control.
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success.
 *         {@link FAST_ERROR_CODE_INVALID_PTR} The pointer is NULL.
 *         {@link FAST_ERROR_CODE_OOM} Out of memory.
 * @release HMS_FAST_ConcurrentHashmap_Destroy {handle}
 *
 * @note This operation is thread-safe but must be called only once per handle.
 *       Concurrent calls with the same output handle lead to undefined behavior.
 *
 * @since 6.1.1(24)
 */
FAST_ErrorCode HMS_FAST_ConcurrentHashmap_Create(
    FAST_ConcurrentHashmapHandle* handle,
    HMS_FAST_ConcurrentHashmap_HashFunc hasher,
    HMS_FAST_ConcurrentHashmap_KeyEqualFunc equaler,
    float maxLoadFac,
    size_t numShards
)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroys a concurrent hash map.
 *
 * @param handle Handle to the hash map to destroy.
 * @return NA
 *
 * @note 1) The hash map must not be accessed by any other thread during or after this call.
 *          The caller is responsible for ensuring exclusive access and proper synchronization.
 *       2) This function does not release memory associated with keys or values.
 *          The caller retains ownership of all key and value resources and must explicitly
 *          free them to avoid memory leaks.
 *
 * @since 6.1.1(24)
 */
void HMS_FAST_ConcurrentHashmap_Destroy(FAST_ConcurrentHashmapHandle handle)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Inserts or updates a key-value pair in the hash map.
 *
 * @param handle Hash map handle.
 * @param key Key to insert or update.
 * @param value Value to associate with the key.
 * @param originValue Pointer of value which will be overwritten,
 *                    valid only when return {@link FAST_ERROR_CODE_KEY_EXISTS}, pass NULL if unnecessary.
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success;
 *         {@link FAST_ERROR_CODE_INVALID_PTR} The pointer is NULL;
 *         {@link FAST_ERROR_CODE_KEY_EXISTS} Overwritten;
 *         {@link FAST_ERROR_CODE_OOM} Out of memory.
 *
 * @note - If the key already exists, the return value will be {@link FAST_ERROR_CODE_KEY_EXISTS},
 *            and its value will be overwritten.
 *       - The caller retains ownership of both key and value memory.
 *         The hash map stores only pointers; it does not copy or manage memory.
 *
 * @since 6.1.1(24)
 */
FAST_ErrorCode HMS_FAST_ConcurrentHashmap_Insert(
    FAST_ConcurrentHashmapHandle handle,
    const FAST_ConcurrentHashmapKeyPtr key,
    const FAST_ConcurrentHashmapValuePtr value,
    FAST_ConcurrentHashmapValuePtr* originValue
)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Retrieves the value associated with a given key.
 *
 * @param handle Hash map handle.
 * @param key Key to look up.
 * @param value Pointer to store the retrieved value.
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success;
 *         {@link FAST_ERROR_CODE_INVALID_PTR} The pointer is NULL;
 *         {@link FAST_ERROR_CODE_KEY_NOT_EXISTS} Not exists.
 *
 * @since 6.1.1(24)
 */
FAST_ErrorCode HMS_FAST_ConcurrentHashmap_Find(
    FAST_ConcurrentHashmapHandle handle,
    const FAST_ConcurrentHashmapKeyPtr key,
    FAST_ConcurrentHashmapValuePtr* value
)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Removes an entry by key from the hash map.
 *
 * @param handle Hash map handle.
 * @param key Key of the entry to remove.
 * @param originKey Pointer of key which will be removed, valid only on success, pass NULL if unnecessary.
 * @param originValue Pointer of value which will be removed, valid only on success, pass NULL if unnecessary.
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success;
 *         {@link FAST_ERROR_CODE_INVALID_PTR} {@link handle} or {@link key} is NULL;
 *         {@link FAST_ERROR_CODE_KEY_NOT_EXISTS} Not exists.
 *
 * @note Memory is not automatically freed,
 *       the user must manually release it using {@link originKey} and {@link originValue}.
 *
 * @since 6.1.1(24)
 */
FAST_ErrorCode HMS_FAST_ConcurrentHashmap_Erase(
    FAST_ConcurrentHashmapHandle handle,
    const FAST_ConcurrentHashmapKeyPtr key,
    FAST_ConcurrentHashmapKeyPtr* originKey,
    FAST_ConcurrentHashmapValuePtr* originValue
)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Inserts a key-value pair only if the key does not already exist.
 *
 * @param handle Hash map handle.
 * @param key Key to insert.
 * @param value Value to associate with the key.
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success;
 *         {@link FAST_ERROR_CODE_INVALID_PTR} The pointer is NULL;
 *         {@link FAST_ERROR_CODE_KEY_EXISTS} The key is already present.
 *
 * @note The caller manages the lifetime of key and value memory.
 *
 * @since 6.1.1(24)
 */
FAST_ErrorCode HMS_FAST_ConcurrentHashmap_TryInsert(
    FAST_ConcurrentHashmapHandle handle,
    const FAST_ConcurrentHashmapKeyPtr key,
    const FAST_ConcurrentHashmapValuePtr value
)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Returns the number of key-value pairs currently stored in the hash map.
 *
 * @param handle Hash map handle.
 * @return Number of elements in the hash map.
 *
 * @note This operation is thread-safe but may reflect a slightly stale count
 *       under heavy concurrent modification.
 *
 * @since 6.1.1(24)
 */
size_t HMS_FAST_ConcurrentHashmap_Size(FAST_ConcurrentHashmapHandle handle)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Removes all entries from the hash map.
 *
 * @param handle Hash map handle.
 * @return NA
 *
 * @note Does not deallocate internal structures; the map remains usable after clear.
 *
 * @since 6.1.1(24)
 */
void HMS_FAST_ConcurrentHashmap_Clear(FAST_ConcurrentHashmapHandle handle)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Removes all entries satisfying a given predicate.
 *
 * @param handle Hash map handle.
 * @param condFunc Predicate function; returns non-zero to delete the element.
 * @param condCtx User-defined context allowing users to supply custom data that the condFunc may need during execution.
 * @param freeFunc Function to free memory for key and value that satisfy the predicate, pass NULL if unnecessary.
 * @param freeCtx User-defined context for free function.
 * @return Number of elements successfully erased.
 *
 * @since 6.1.1(24)
 */
size_t HMS_FAST_ConcurrentHashmap_EraseIf(
    FAST_ConcurrentHashmapHandle handle,
    HMS_FAST_ConcurrentHashmap_HookFunc condFunc,
    void* condCtx,
    HMS_FAST_ConcurrentHashmap_HookFunc freeFunc,
    void* freeCtx
)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Traverses the hash map, optionally filtering elements and applying a work function.
 *
 * @param handle Hash map handle.
 * @param condFunc Optional condition function; if provided, workFunc is called only
 *                   for entries where condFunc returns non-zero.
 *                   Pass NULL to apply workFunc to all entries.
 * @param condCtx User-defined context allowing users to supply custom data that the condFunc may need during execution.
 * @param workFunc Function to apply to selected entries.
 * @param workCtx User-defined context allowing users to supply custom data that the workFunc may need during execution.
 * @return NA
 *
 * @note Both condFunc and workFunc are invoked under internal locks; avoid blocking or
 *       re-entering the hash map API within these callbacks.
 *
 * @since 6.1.1(24)
 */
void HMS_FAST_ConcurrentHashmap_Traverse(
    FAST_ConcurrentHashmapHandle handle,
    HMS_FAST_ConcurrentHashmap_HookFunc condFunc,
    void* condCtx,
    HMS_FAST_ConcurrentHashmap_HookFunc workFunc,
    void* workCtx
)
__attribute__((__availability__(ohos, introduced=24.0.0)));
#ifdef __cplusplus
}
#endif
#endif // FAST_ADS_CONCURRENT_HASHMAP_H

/** @} */
