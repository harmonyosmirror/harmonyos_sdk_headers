/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

/**
 * @addtogroup Preview
 * @{
 *
 * @brief Provides APIs for file preview capability.
 * @since 6.1.0(23)
 */

/**
 * @file file_cache_boost.h
 *
 * @brief Declares the APIs for file caching acceleration to optimize performance in
 * scenarios such as file opening and file browsing.
 *
 * @kit PreviewKit
 *
 * @library libfile_cache_boost.so
 * @syscap SystemCapability.PCService.OpenFileBoost
 * @since 6.1.0(23)
 */

#ifndef PREVIEW_FILE_CACHE_BOOST_H
#define PREVIEW_FILE_CACHE_BOOST_H
#include "info/application_target_sdk_version.h"
#include <stdint.h>
#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates error codes related to file cache boost.
 * @since 6.1.0(23)
 */
typedef enum {
    /** Success. */
    FILE_CACHE_BOOST_SUCCESS = 0,

    /** Invalid input parameter. */
    FILE_CACHE_BOOST_ERROR_INVALID_PARAM = 401,

    /** Not supported. */
    FILE_CACHE_BOOST_ERROR_NOT_SUPPORTED = 801,

    /** Insufficient memory. */
    FILE_CACHE_BOOST_ERROR_NOMEM = 1017220001,

    /** Internal error. */
    FILE_CACHE_BOOST_ERROR_INTERNAL_ERROR = 1017220002,

    /** The cache key does not exist. */
    FILE_CACHE_BOOST_ERROR_KEY_NOT_FOUND = 1017220003,

    /** The cache key already exists. */
    FILE_CACHE_BOOST_ERROR_KEY_EXIST = 1017220004,

    /** Path initialization error. */
    FILE_CACHE_BOOST_ERROR_NOT_DIR = 1017220005,

    /** I/O error. */
    FILE_CACHE_BOOST_ERROR_IO = 1017220006,

    /** The I/O was canceled. */
    FILE_CACHE_BOOST_ERROR_IO_CANCELED = 1017220007,

    /** Not initialized. */
    FILE_CACHE_BOOST_ERROR_NOT_INITIALIZED = 1017220008,

    /** Single cache size exceeds limit. */
    FILE_CACHE_BOOST_ERROR_EXCEED_LIMIT = 1017220009,

    /** I/O cancellation failed. */
    FILE_CACHE_BOOST_ERROR_IO_CANCEL_FAILED = 1017220010
} FileCacheBoost_ErrCode;

/**
 * @brief Enumerates the error codes of the callback functions {@link DeserializeFunc} and {@link SerializeFunc}.
 * It is used by the app to return the callback function execution result to the system.
 * @since 6.1.0(23)
 */
typedef enum  {
    /** The callback function is successfully executed. */
    FILE_CACHE_BOOST_CALLBACK_SUCCESS = 0,

    /** The callback function fails to be executed. */
    FILE_CACHE_BOOST_CALLBACK_FAILURE = 1017221001,

    /** The I/O was canceled. */
    FILE_CACHE_BOOST_CALLBACK_IO_CANCELED = 1017221002
} FileCacheBoost_CbErrCode;

/**
 * @brief A data structure for passing key-related information between C APIs.
 * You only need to pass it when calling {@link WriteFunc} and {@link ReadFunc} within the serialization function
 * {@link SerializeFunc} and deserialization function {@link DeserializeFunc}.
 * @since 6.1.0(23)
 */
typedef struct CacheKey CacheKey;

/**
 * @brief Initializes the storage path and capacity upper limit of the file cache.
 * This function is used to configure the path for storing cached files and the maximum cache capacity. When the system
 * detects that the cache usage exceeds the configured limit, it will automatically activate the cache eviction policy
 * to free up space.
 * @param path Path for storing cached files. You need to provide a relative path, and the system will automatically
 * create the full path. The input path must be valid.
 * @param pathLen Length of the buffer for the cache path.
 * @param cacheUpperLimitMb Maximum cache capacity, in MB. If the cache usage exceeds the upper limit, the system will
 * activate the cache eviction policy. If the cache capacity specified is greater than the default upper limit preset
 * by the system, the default upper limit will be used.
 * @param dbName Name of the database file used for cache metadata management. The system guarantees thread-safe
 * concurrent access control. For multi-process concurrency support, it is recommended to use different database
 * filenames across processes to ensure access safety.
 * @param dbNameLen Length of the buffer for the dbName.
 * @return Function execution result. {@link FILE_CACHE_BOOST_SUCCESS} is returned if the execution is successful.
 * If the input path is invalid, {@link FILE_CACHE_BOOST_ERROR_NOT_DIR} is returned.
 * If the passed parameter is invalid, {@link FILE_CACHE_BOOST_ERROR_INVALID_PARAM} is returned.
 * For other errors, please refer to {@link FileCacheBoost_ErrCode}.
 * @since 6.1.0(23)
 */
FileCacheBoost_ErrCode HMS_FileCacheBoost_Init(
    const char* path, size_t pathLen, uint32_t cacheUpperLimitMb, const char* dbName, size_t dbNameLen)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Creates and adds a cached object to the file cache.
 * This function caches data to the file cache system based on the specified unique identifier (key) for fast access
 * in the future. You are advised to properly design and manage keys to ensure their uniqueness and accuracy across
 * different contexts.
 * When the original content changes or the cache is no longer needed, you are advised to call
 * {@link HMS_FileCacheBoost_RemoveObjectByKey} to delete the cache item, thereby avoiding resource waste.
 * If the cache item is not deleted, the system will delete it based on the policy when the cache capacity becomes
 * insufficient. To modify the cached content associated with an existing key, you should first call
 * {@link HMS_FileCacheBoost_RemoveObjectByKey} to remove the previous entry and then create and add new content
 * with the same key. Direct modification of existing cached objects is not supported.
 * @param key Key of a cached object. This value can typically be generated from a file's characteristic value, such as
 * the SHA-256 hash of an image. When the image content changes, the key must be updated accordingly, and the
 * original cache content becomes invalid.
 * Conversely, if the content remains consistent, the corresponding cache can be retrieved upon a subsequent opening.
 * @param keyLen Length of a key.
 * @param data Data to be cached.
 * @param dataLen Length of the data to be cached.
 * @param weight Weight of a cached object, ranging from 0 to 10,000, which reflects its importance or priority.
 * If an input weight exceeds 10,000, the system will automatically set it to 10,000. When the cache space reaches
 * its limit, the system will determine the eviction order by referencing this weight.
 * If you want a cached object to be retained with a higher priority, you should assign it a higher weight.
 * @return Function execution result. {@link FILE_CACHE_BOOST_SUCCESS} is returned if the execution is successful.
 * If the key already exists, {@link FILE_CACHE_BOOST_ERROR_KEY_EXIST} is returned.
 * If an I/O error occurs, {@link FILE_CACHE_BOOST_ERROR_IO} is returned.
 * If the in-memory file cache is released and the task of creating a cached object cannot be executed,
 * {@link FILE_CACHE_BOOST_ERROR_IO_CANCELED} is returned.
 * If not initialized, {@link FILE_CACHE_BOOST_ERROR_NOT_INITIALIZED} is returned.
 * If the input data size exceeds cache capacity limit, {@link FILE_CACHE_BOOST_ERROR_EXCEED_LIMIT} is returned.
 * If the passed parameter is invalid, {@link FILE_CACHE_BOOST_ERROR_INVALID_PARAM} is returned.
 * For other errors, please refer to {@link FileCacheBoost_ErrCode}.
 * @since 6.1.0(23)
 */
FileCacheBoost_ErrCode HMS_FileCacheBoost_AddObjectByKey(
    const uint8_t *key, size_t keyLen, const uint8_t *data, size_t dataLen, uint32_t weight)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Queries a cached object based on the specified key. If the cached object exists, its content is returned.
 * This function allocates a memory segment for storing cache data. After using the memory, you need to
 * call {@link HMS_FileCacheBoost_FreeObject} to explicitly release the memory. This function loads the content of a
 * cached object from the disk.
 * @param key Key of a cached object.
 * @param keyLen Length of a key.
 * @param data Output parameter, which indicates the content of a cached object, you need to pass a non-null object.
 * @param dataLen Length of the content of a cached object.
 * @return Function execution result. {@link FILE_CACHE_BOOST_SUCCESS} is returned if the execution is successful.
 * If the key does not exist, {@link FILE_CACHE_BOOST_ERROR_KEY_NOT_FOUND} is returned.
 * If an I/O error occurs, {@link FILE_CACHE_BOOST_ERROR_IO} is returned.
 * If not initialized, {@link FILE_CACHE_BOOST_ERROR_NOT_INITIALIZED} is returned.
 * If the in-memory file cache is released and the task of querying a cached object cannot be executed,
 * {@link FILE_CACHE_BOOST_ERROR_IO_CANCELED} is returned.
 * If the passed parameter is invalid, {@link FILE_CACHE_BOOST_ERROR_INVALID_PARAM} is returned.
 * For other errors, please refer to {@link FileCacheBoost_ErrCode}.
 * @since 6.1.0(23)
 */
FileCacheBoost_ErrCode HMS_FileCacheBoost_GetObjectByKey(
    const uint8_t *key, size_t keyLen, uint8_t **data, size_t *dataLen)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Release the memory allocated by {@link HMS_FileCacheBoost_GetObjectByKey} or
 * {@link HMS_FileCacheBoost_GetSerialObjectByKey}. Call this function promptly for resource reclamation when the
 * memory is no longer needed.
 * @param data Pointer to the data to be released.
 * @since 6.1.0(23)
 */
void HMS_FileCacheBoost_FreeObject(uint8_t *data) __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Defines the callback function that is called by the deserialization function {@link DeserializeFunc} to read
 * serialized data from the cache.
 * This function is provided by the system. You do not need to implement it. Within the deserialization function, if
 * data needs to be read from the cache into a buffer, this function can be called to access the cache.
 * @param buffer Buffer for storing the read data.
 * @param bufferLen Length of the data to be read (input) and length of the data that is actually read (output).
 * @param key Key of an object to be read.
 * @return {@link FILE_CACHE_BOOST_SUCCESS} is returned if the function is executed successfully.
 * If the in-memory file cache is released and the task of reading a cached object cannot be executed,
 * {@link FILE_CACHE_BOOST_ERROR_IO_CANCELED} is returned.
 * For other errors, please refer to {@link FileCacheBoost_ErrCode}.
 * @since 6.1.0(23)
 */
typedef FileCacheBoost_ErrCode (*ReadFunc)(void *buffer, size_t *bufferLen, struct CacheKey *key);

/**
 * @brief Defines the callback function that is called by the serialization function {@link SerializeFunc} to write
 * serialized data to the cache.
 * This function is provided by the system. You do not need to implement it. When the serialization function needs
 * to write data to the cache, this function can be called to write data in the buffer to the cache.
 * @param buffer Data to be written to the cache.
 * @param bufferLen Length of the data to be written to the cache.
 * @param key Key of the object to be written to the cache.
 * @return {@link FILE_CACHE_BOOST_SUCCESS} is returned if the function is executed successfully.
 * If the in-memory file cache is released and the task of writing a cached object cannot be executed,
 * {@link FILE_CACHE_BOOST_ERROR_IO_CANCELED} is returned.
 * For other errors, please refer to {@link FileCacheBoost_ErrCode}.
 * @since 6.1.0(23)
 */
typedef FileCacheBoost_ErrCode (*WriteFunc)(const void *buffer, size_t bufferLen, struct CacheKey *key);

/**
 * @brief Deserialization function, which defines the callback API for deserialization. This function is used to
 * deserialize data to original objects. Implement it yourself.
 * @param object Object generated after deserialization.
 * @param readFunc Callback for reading serialized data from the cache.
 * @param key Key of an object to be deserialized.
 * @return {@link FILE_CACHE_BOOST_CALLBACK_SUCCESS} is returned if the function is executed successfully.
 * {@link FILE_CACHE_BOOST_CALLBACK_FAILURE} is returned if the function fails to be executed.
 * {@link FILE_CACHE_BOOST_CALLBACK_IO_CANCELED} is returned if readFunc encounters an I/O cancellation error.
 * @since 6.1.0(23)
 */
typedef FileCacheBoost_CbErrCode (*DeserializeFunc)(void **object, ReadFunc readFunc, struct CacheKey *key);

/**
 * @brief Serialization function, which defines the callback API for serialization. This function is used to serialize
 * data of complex type objects. Implement it yourself.
 * @param object Object to be serialized.
 * @param writeFunc Callback for writing serialized data to the cache.
 * @param key Key of an object to be serialized.
 * @return {@link FILE_CACHE_BOOST_CALLBACK_SUCCESS} is returned if the function is executed successfully.
 * {@link FILE_CACHE_BOOST_CALLBACK_FAILURE} is returned if the function fails to be executed.
 * {@link FILE_CACHE_BOOST_CALLBACK_IO_CANCELED} is returned if writeFunc encounters an I/O cancellation error.
 * @since 6.1.0(23)
 */
typedef FileCacheBoost_CbErrCode (*SerializeFunc)(const void *object, WriteFunc writeFunc, struct CacheKey *key);

/**
 * @brief Creates a cache item for a complex type object. A custom serialization function {@link SerializeFunc} is
 * passed to serialize the object so that it can be stored on a disk and later restored.
 * For example, for an image object, both its metadata and pixel data must be saved in order to complete the full
 * caching and retrieval process.
 * Serialization and deserialization will consume memory, you need to control object size to reduce memory pressure.
 * @param key Key of a cached object.
 * @param keyLen Length of a key.
 * @param func Serialization function implemented by you, used to serialize data of complex type objects.
 * @param object Complex type object to be cached.
 * @param weight Weight of a cached object, ranging from 0 to 10,000, which reflects its importance or priority.
 * If an input weight exceeds 10,000, the system will automatically set it to 10,000. When the cache space reaches
 * its limit, the system will determine the eviction order by referencing this weight.
 * If you want a cached object to be retained with a higher priority, you should assign it a higher weight.
 * @return Function execution result. {@link FILE_CACHE_BOOST_SUCCESS} is returned if the execution is successful.
 * If the key already exists, {@link FILE_CACHE_BOOST_ERROR_KEY_EXIST} is returned.
 * If an I/O error occurs, {@link FILE_CACHE_BOOST_ERROR_IO} is returned.
 * If the in-memory file cache is released and the task of creating a cached object cannot be executed,
 * {@link FILE_CACHE_BOOST_ERROR_IO_CANCELED} is returned.
 * If not initialized, {@link FILE_CACHE_BOOST_ERROR_NOT_INITIALIZED} is returned.
 * If the input data size exceeds cache capacity limit, {@link FILE_CACHE_BOOST_ERROR_EXCEED_LIMIT} is returned.
 * If the passed parameter is invalid, {@link FILE_CACHE_BOOST_ERROR_INVALID_PARAM} is returned.
 * For other errors, please refer to {@link FileCacheBoost_ErrCode}.
 * @since 6.1.0(23)
 */
FileCacheBoost_ErrCode HMS_FileCacheBoost_AddSerialObjectByKey(
    const uint8_t *key, size_t keyLen, SerializeFunc func, const void *object, uint32_t weight)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Retrieves a complex type object from the cache based on the specified key, and then restores it to its
 * original data format using the passed deserialization function {@link DeserializeFunc}
 * to obtain the complete object content.
 * This function internally allocates memory for cached objects to store the deserialized data. After using the
 * memory, you need to call {@link HMS_FileCacheBoost_FreeObject} to explicitly release the memory.
 * @param key Key of a cached object.
 * @param keyLen Length of a key.
 * @param func Deserialization function implemented by you, used to restore serialized data to the original object.
 * @param object Output parameter, which indicates the content of a cached object, you need to pass a non-null object.
 * @return Function execution result. {@link FILE_CACHE_BOOST_SUCCESS} is returned if the execution is successful.
 * {@link FILE_CACHE_BOOST_ERROR_KEY_NOT_FOUND} is returned if the key does not exist.
 * {@link FILE_CACHE_BOOST_ERROR_IO} is returned if an I/O error occurs.
 * If not initialized, {@link FILE_CACHE_BOOST_ERROR_NOT_INITIALIZED} is returned.
 * If the in-memory file cache is released and the task of querying a cached object cannot be executed,
 * {@link FILE_CACHE_BOOST_ERROR_IO_CANCELED} is returned.
 * If the passed parameter is invalid, {@link FILE_CACHE_BOOST_ERROR_INVALID_PARAM} is returned.
 * For other errors, please refer to {@link FileCacheBoost_ErrCode}.
 * @since 6.1.0(23)
 */
FileCacheBoost_ErrCode HMS_FileCacheBoost_GetSerialObjectByKey(
    const uint8_t *key, size_t keyLen, DeserializeFunc func, void **object)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Deletes the cached object associated with the specified key.
 * @param key Key of a cached object.
 * @param keyLen Length of a key.
 * @return Function execution result. {@link FILE_CACHE_BOOST_SUCCESS} is returned if the execution is successful. If
 * the key does not exist, {@link FILE_CACHE_BOOST_ERROR_KEY_NOT_FOUND} is returned.
 * If not initialized, {@link FILE_CACHE_BOOST_ERROR_NOT_INITIALIZED} is returned.
 * If the passed parameter is invalid, {@link FILE_CACHE_BOOST_ERROR_INVALID_PARAM} is returned.
 * For other errors, please refer to {@link FileCacheBoost_ErrCode}.
 * @since 6.1.0(23)
 */
FileCacheBoost_ErrCode HMS_FileCacheBoost_RemoveObjectByKey(const uint8_t *key, size_t keyLen)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Cancels the ongoing I/O operation of a cached object associated with the specified key. If the object is
 * being cached, the operation will be canceled. If caching has already completed, the function performs no action.
 * You should call this function when releasing a data object to prevent other threads from performing
 * operations like adding cache objects or getting cache objects on that data object.
 * When the function returns {@link FILE_CACHE_BOOST_SUCCESS}, you can immediately release the data object.
 * When it returns {@link FILE_CACHE_BOOST_ERROR_IO_CANCEL_FAILED}, it indicates there are no ongoing keys that need
 * to be canceled. In this case, you should ensure the operation corresponding to the key has either completed
 * execution or doesn't need execution before releasing the data object.
 * This function ensures the safety of a cached object by preventing data races in concurrent
 * environments. Specifically, it avoids situations where one thread attempts to delete the object while another thread
 * is performing {@link HMS_FileCacheBoost_AddObjectByKey} on it.
 * @param key Key of a cached object.
 * @param keyLen Length of a key.
 * @return {@link FILE_CACHE_BOOST_SUCCESS} is returned if the function is executed successfully.
 * If the passed parameter is invalid, {@link FILE_CACHE_BOOST_ERROR_INVALID_PARAM} is returned.
 * {@link FILE_CACHE_BOOST_ERROR_IO_CANCEL_FAILED} is returned if the I/O cancellation fails.
 * For other errors, please refer to {@link FileCacheBoost_ErrCode}.
 * @since 6.1.0(23)
 */
FileCacheBoost_ErrCode HMS_FileCacheBoost_CancelOngoingIOByKey(const uint8_t *key, size_t keyLen)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Clears all cache objects. This function is used to release all cached objects created by
 * {@link HMS_FileCacheBoost_AddObjectByKey} and {@link HMS_FileCacheBoost_AddSerialObjectByKey}.
 * @return Function execution result. {@link FILE_CACHE_BOOST_SUCCESS} is returned if the execution is successful.
 * If not initialized, {@link FILE_CACHE_BOOST_ERROR_NOT_INITIALIZED} is returned.
 * For other errors, please refer to {@link FileCacheBoost_ErrCode}.
 * @since 6.1.0(23)
 */
FileCacheBoost_ErrCode HMS_FileCacheBoost_ClearAllCache(void) __attribute__((__availability__(ohos, introduced=23.0.0)));

#ifdef __cplusplus
};
#endif
#endif // PREVIEW_FILE_CACHE_BOOST_H

/** @} */