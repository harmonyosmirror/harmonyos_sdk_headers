/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
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
 * @addtogroup OH_NativeBuffer
 * @{
 *
 * @brief Provides the native buffer capability.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @since 9
 * @version 1.0
 */

/**
 * @file native_buffer.h
 *
 * @brief Defines the functions for obtaining and using a native buffer.
 *
 * @kit ArkGraphics2D
 * @library libnative_buffer.so
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @since 9
 * @version 1.0
 */

#ifndef NDK_INCLUDE_NATIVE_BUFFER_H_
#define NDK_INCLUDE_NATIVE_BUFFER_H_

#include "info/application_target_sdk_version.h"
#include <stdint.h>
#include <native_window/external_window.h>
#include <native_buffer/buffer_common.h>

#ifdef __cplusplus
extern "C" {
#endif

struct OH_NativeBuffer;
typedef struct OH_NativeBuffer OH_NativeBuffer;

/**
 * @brief Defines the ipc parcel.
 *
 * @since 23
 * @version 1.0
 */
typedef struct OHIPCParcel OHIPCParcel;

/**
 * @brief Indicates the usage of a native buffer.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @since 10
 * @version 1.0
 */
typedef enum OH_NativeBuffer_Usage {
    NATIVEBUFFER_USAGE_CPU_READ = (1ULL << 0),        /// < CPU read buffer */
    NATIVEBUFFER_USAGE_CPU_WRITE = (1ULL << 1),       /// < CPU write memory */
    NATIVEBUFFER_USAGE_MEM_DMA = (1ULL << 3),         /// < Direct memory access (DMA) buffer */
    /**
     * MMZ with cache
     * @since 20
     */
    NATIVEBUFFER_USAGE_MEM_MMZ_CACHE = (1ULL << 5),
    /**
     * @since 12
     */
    NATIVEBUFFER_USAGE_HW_RENDER = (1ULL << 8),       /// < For GPU write case */
    /**
     * @since 12
     */
    NATIVEBUFFER_USAGE_HW_TEXTURE = (1ULL << 9),      /// < For GPU read case */
    /**
     * @since 12
     */
    NATIVEBUFFER_USAGE_CPU_READ_OFTEN = (1ULL << 16), /// < Often be mapped for direct CPU reads */
    /**
     * @since 12
     */
    NATIVEBUFFER_USAGE_ALIGNMENT_512 = (1ULL << 18),  /// < 512 bytes alignment */
} OH_NativeBuffer_Usage;

/**
 * @brief Indicates the color gamut of a native buffer.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @since 12
 * @version 1.0
 */
typedef enum OH_NativeBuffer_ColorGamut {
    NATIVEBUFFER_COLOR_GAMUT_NATIVE = 0,            /**< Native or default */
    NATIVEBUFFER_COLOR_GAMUT_STANDARD_BT601 = 1,    /**< Standard BT601 */
    NATIVEBUFFER_COLOR_GAMUT_STANDARD_BT709 = 2,    /**< Standard BT709 */
    NATIVEBUFFER_COLOR_GAMUT_DCI_P3 = 3,            /**< DCI P3 */
    NATIVEBUFFER_COLOR_GAMUT_SRGB = 4,              /**< SRGB */
    NATIVEBUFFER_COLOR_GAMUT_ADOBE_RGB = 5,         /**< Adobe RGB */
    NATIVEBUFFER_COLOR_GAMUT_DISPLAY_P3 = 6,        /**< Display P3 */
    NATIVEBUFFER_COLOR_GAMUT_BT2020 = 7,            /**< BT2020 */
    NATIVEBUFFER_COLOR_GAMUT_BT2100_PQ = 8,         /**< BT2100 PQ */
    NATIVEBUFFER_COLOR_GAMUT_BT2100_HLG = 9,        /**< BT2100 HLG */
    NATIVEBUFFER_COLOR_GAMUT_DISPLAY_BT2020 = 10,   /**< Display BT2020 */
} OH_NativeBuffer_ColorGamut;

/**
 * @brief <b>OH_NativeBuffer</b> config. \n
 * Used to allocating new <b>OH_NativeBuffer</b> and query parameters if existing ones.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @since 9
 * @version 1.0
 */
typedef struct {
    int32_t width;           ///< Width in pixels
    int32_t height;          ///< Height in pixels
    int32_t format;          ///< One of PixelFormat
    int32_t usage;           ///< Combination of buffer usage
    /**
     * @since 10
     */
    int32_t stride;          ///< the stride of memory in bytes
} OH_NativeBuffer_Config;

/**
 * @brief Holds info for a single image plane. \n
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @since 12
 * @version 1.0
 */
typedef struct {
    uint64_t offset;         ///< Offset in bytes of plane.
    uint32_t rowStride;      ///< Distance in bytes from the first value of one row of the image to the first value of the next row.
    uint32_t columnStride;   ///< Distance in bytes from the first value of one column of the image to the first value of the next column.
} OH_NativeBuffer_Plane;

/**
 * @brief Holds all image planes. \n
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @since 12
 * @version 1.0
 */
typedef struct {
    uint32_t planeCount;              ///< Number of distinct planes.
    OH_NativeBuffer_Plane planes[4];  ///< Array of image planes.
} OH_NativeBuffer_Planes;

/**
 * @brief Alloc a <b>OH_NativeBuffer</b> that matches the passed BufferRequestConfig. \n
 * A new <b>OH_NativeBuffer</b> instance is created each time this function is called.\n
 * This interface needs to be used in conjunction with <b>OH_NativeBuffer_Unreference</b>,
 * otherwise memory leaks will occur.\n
 * This interface is a non-thread-safe type interface.\n
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @param config Indicates the pointer to a <b>BufferRequestConfig</b> instance.
 * @return Returns the pointer to the <b>OH_NativeBuffer</b> instance created if the operation is successful, \n
 * returns <b>NULL</b> otherwise.
 * @since 9
 * @version 1.0
 */
OH_NativeBuffer* OH_NativeBuffer_Alloc(const OH_NativeBuffer_Config* config)
__attribute__((__availability__(ohos, introduced=9.0.0)));

/**
 * @brief Adds the reference count of a OH_NativeBuffer.\n
 * This interface needs to be used in conjunction with <b>OH_NativeBuffer_Unreference</b>,
 * otherwise memory leaks will occur.\n
 * This interface is a non-thread-safe type interface.\n
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @param buffer Indicates the pointer to a <b>OH_NativeBuffer</b> instance.
 * @return Returns an error code, 0 is success, otherwise, failed.
 * @since 9
 * @version 1.0
 */
int32_t OH_NativeBuffer_Reference(OH_NativeBuffer *buffer) __attribute__((__availability__(ohos, introduced=9.0.0)));

/**
 * @brief Decreases the reference count of a OH_NativeBuffer and, when the reference count reaches 0,
 * destroys this OH_NativeBuffer.\n
 * This interface is a non-thread-safe type interface.\n
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @param buffer Indicates the pointer to a <b>OH_NativeBuffer</b> instance.
 * @return Returns an error code, 0 is success, otherwise, failed.
 * @since 9
 * @version 1.0
 */
int32_t OH_NativeBuffer_Unreference(OH_NativeBuffer *buffer) __attribute__((__availability__(ohos, introduced=9.0.0)));

/**
 * @brief Return a config of the OH_NativeBuffer in the passed OHNativeBufferConfig struct.\n
 * This interface is a non-thread-safe type interface.\n
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @param buffer Indicates the pointer to a <b>OH_NativeBuffer</b> instance.
 * @param config Indicates the pointer to the <b>NativeBufferConfig</b> of the buffer.
 * @return <b>void</b>
 * @since 9
 * @version 1.0
 */
void OH_NativeBuffer_GetConfig(OH_NativeBuffer *buffer, OH_NativeBuffer_Config* config)
__attribute__((__availability__(ohos, introduced=9.0.0)));

/**
 * @brief Provide direct cpu access to the OH_NativeBuffer in the process's address space.\n
 * This interface needs to be used in conjunction with <b>OH_NativeBuffer_Unmap</b>.\n
 * This interface is a non-thread-safe type interface.\n
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @param buffer Indicates the pointer to a <b>OH_NativeBuffer</b> instance.
 * @param virAddr Indicates the address of the <b>OH_NativeBuffer</b> in virtual memory.
 * @return Returns an error code, 0 is success, otherwise, failed.
 * @since 9
 * @version 1.0
 */

int32_t OH_NativeBuffer_Map(OH_NativeBuffer *buffer, void **virAddr)
__attribute__((__availability__(ohos, introduced=9.0.0)));

/**
 * @brief Remove direct cpu access ability of the OH_NativeBuffer in the process's address space.\n
 * This interface is a non-thread-safe type interface.\n
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @param buffer Indicates the pointer to a <b>OH_NativeBuffer</b> instance.
 * @return Returns an error code, 0 is success, otherwise, failed.
 * @since 9
 * @version 1.0
 */
int32_t OH_NativeBuffer_Unmap(OH_NativeBuffer *buffer) __attribute__((__availability__(ohos, introduced=9.0.0)));

/**
 * @brief Get the system wide unique sequence number of the OH_NativeBuffer.\n
 * This interface is a non-thread-safe type interface.\n
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @param buffer Indicates the pointer to a <b>OH_NativeBuffer</b> instance.
 * @return Returns the sequence number, which is unique for each OH_NativeBuffer.
 * @since 9
 * @version 1.0
 */
uint32_t OH_NativeBuffer_GetSeqNum(OH_NativeBuffer *buffer) __attribute__((__availability__(ohos, introduced=9.0.0)));

/**
 * @brief Provide direct cpu access to the potentially multi-planar OH_NativeBuffer in the process's address space.\n
 * This interface is a non-thread-safe type interface.\n
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @param buffer Indicates the pointer to a <b>OH_NativeBuffer</b> instance.
 * @param virAddr Indicates the address of the <b>OH_NativeBuffer</b> in virtual memory.
 * @param outPlanes Indicates all image planes that contain the pixel data.
 * @return Returns an error code, 0 is success, otherwise, failed.
 * @since 12
 * @version 1.0
 */
int32_t OH_NativeBuffer_MapPlanes(OH_NativeBuffer *buffer, void **virAddr, OH_NativeBuffer_Planes *outPlanes)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Converts an <b>OHNativeWindowBuffer</b> instance to an <b>OH_NativeBuffer</b>.\n
 * This interface is a non-thread-safe type interface.\n
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @param nativeWindowBuffer Indicates the pointer to a <b>OHNativeWindowBuffer</b> instance.
 * @param buffer Indicates the pointer to a <b>OH_NativeBuffer</b> pointer.
 * @return Returns an error code, 0 is success, otherwise, failed.
 * @since 12
 * @version 1.0
 */
int32_t OH_NativeBuffer_FromNativeWindowBuffer(OHNativeWindowBuffer *nativeWindowBuffer, OH_NativeBuffer **buffer)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the color space of the OH_NativeBuffer.\n
 * This interface is a non-thread-safe type interface.\n
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @param buffer Indicates the pointer to a <b>OH_NativeBuffer</b> instance.
 * @param colorSpace Indicates the color space of native buffer, see <b>OH_NativeBuffer_ColorSpace</b>.
 * @return Returns an error code, 0 is success, otherwise, failed.
 * @since 11
 * @version 1.0
 */
int32_t OH_NativeBuffer_SetColorSpace(OH_NativeBuffer *buffer, OH_NativeBuffer_ColorSpace colorSpace)
__attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Get the color space of the OH_NativeBuffer.\n
 * This interface is a non-thread-safe type interface.\n
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @param buffer Indicates the pointer to a <b>OH_NativeBuffer</b> instance.
 * @param colorSpace Indicates the color space of native buffer, see <b>OH_NativeBuffer_ColorSpace</b>.
 * @return {@link NATIVE_ERROR_OK} 0 - Success.
 *     {@link NATIVE_ERROR_INVALID_ARGUMENTS} 40001000 - buffer is NULL.
 *     {@link NATIVE_ERROR_BUFFER_STATE_INVALID} 41207000 - Incorrect colorSpace state.
 * @since 12
 * @version 1.0
 */
int32_t OH_NativeBuffer_GetColorSpace(OH_NativeBuffer *buffer, OH_NativeBuffer_ColorSpace *colorSpace)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the metadata type of the OH_NativeBuffer.\n
 * This interface is a non-thread-safe type interface.\n
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @param buffer Indicates the pointer to a <b>OH_NativeBuffer</b> instance.
 * @param metadataKey Indicates the metadata type of native buffer, see <b>OH_NativeBuffer_MetadataKey</b>.
 * @param size Indicates the size of a uint8_t vector.
 * @param metadata Indicates the pointer to a uint8_t vector.
 * @return {@link NATIVE_ERROR_OK} 0 - Success.
 *     {@link NATIVE_ERROR_INVALID_ARGUMENTS} 40001000 - buffer or metadata is NULL.
 *     {@link NATIVE_ERROR_BUFFER_STATE_INVALID} 41207000 - Incorrect metadata state.
 *     {@link NATIVE_ERROR_UNSUPPORTED} 50102000 - Unsupported metadata key.
 * @since 12
 * @version 1.0
 */
int32_t OH_NativeBuffer_SetMetadataValue(OH_NativeBuffer *buffer, OH_NativeBuffer_MetadataKey metadataKey,
    int32_t size, uint8_t *metadata)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the metadata type of the OH_NativeBuffer.\n
 * This interface is a non-thread-safe type interface.\n
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @param buffer Indicates the pointer to a <b>OH_NativeBuffer</b> instance.
 * @param metadataKey Indicates the metadata type of native buffer, see <b>OH_NativeBuffer_MetadataKey</b>.
 * @param size Indicates the size of a uint8_t vector.
 * @param metadata Indicates the pointer to a uint8_t vector.
 * @return {@link NATIVE_ERROR_OK} 0 - Success.
 *     {@link NATIVE_ERROR_INVALID_ARGUMENTS} 40001000 - buffer, metadata, or size is NULL.
 *     {@link NATIVE_ERROR_BUFFER_STATE_INVALID} 41207000 - Incorrect metadata state.
 *     {@link NATIVE_ERROR_UNSUPPORTED} 50102000 - Unsupported metadata key.
 * @since 12
 * @version 1.0
 */
int32_t OH_NativeBuffer_GetMetadataValue(OH_NativeBuffer *buffer, OH_NativeBuffer_MetadataKey metadataKey,
    int32_t *size, uint8_t **metadata)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Provide direct cpu access to the OH_NativeBuffer in the process's address space and wait fence.\n
 * If the interface returns OK, fenceFd does not need to be closed by the developer,
 * Otherwise, the developer needs to close the fenceFd.\n
 * This interface is a non-thread-safe type interface.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @param buffer Indicates the pointer to a <b>OH_NativeBuffer</b> instance.
 * @param fenceFd Indicates the pointer to a file descriptor handle.
 * @param virAddr Indicates the address of the <b>OH_NativeBuffer</b> in virtual memory.
 * @return {@link NATIVE_ERROR_OK} 0 - Success.
 * {@link NATIVE_ERROR_INVALID_ARGUMENTS} 40001000 - buffer or virAddr is NULL or invalid fenceFd.
 * {@link NATIVE_ERROR_UNKNOWN} 50002000 - map failed.
 * @since 23
 * @version 1.0
 */
int32_t OH_NativeBuffer_MapWaitFence(OH_NativeBuffer *buffer, int32_t fenceFd, void **virAddr)
__attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Serialize <b>OH_NativeBuffer</b> object to the serialized <b>OHIPCParcel</b> object.\n
 * This interface is a non-thread-safe type interface.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @param buffer Indicates the pointer to a <b>OH_NativeBuffer</b> instance.
 * @param parcel Indicates the serialized <b>OHIPCParcel</b> object.
 * @return {@link NATIVE_ERROR_OK} 0 - Success.
 * {@link NATIVE_ERROR_INVALID_ARGUMENTS} 40001000 - buffer or parcel is NULL.
 * {@link SURFACE_ERROR_BINDER_ERROR} 50401000 - ipc send failed.
 * @since 23
 * @version 1.0
 */
int32_t OH_NativeBuffer_WriteToParcel(OH_NativeBuffer* buffer, OHIPCParcel* parcel)
__attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Deserialize data from the serialized <b>OHIPCParcel</b> object and rebuild <b>OH_NativeBuffer</b> object.
 * This interface will cause an increase in the reference count of the <b>OH_NativeBuffer</b> instance.
 * This interface needs to be used in conjunction with <b>OH_NativeBuffer_Unreference</b>,\n
 * otherwise memory leaks will occur.
 * This interface is a non-thread-safe type interface.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @param parcel Indicates the serialized <b>OHIPCParcel</b> object.
 * @param buffer Indicates the pointer to a <b>OH_NativeBuffer</b> pointer.
 * @return {@link NATIVE_ERROR_OK} 0 - Success.
 * {@link NATIVE_ERROR_INVALID_ARGUMENTS} 40001000 - parcel or buffer is NULL.
 * {@link NATIVE_ERROR_UNKNOWN} 50002000 - deserialize failed.
 * @since 23
 * @version 1.0
 */
int32_t OH_NativeBuffer_ReadFromParcel(OHIPCParcel* parcel, OH_NativeBuffer** buffer)
__attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Check whether the system supports the <b>NativeBufferConfig</b>.\n
 * This interface is a non-thread-safe type interface.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @param config Indicates the config of the <b>OH_NativeBuffer</b>.
 * @param isSupported Indicates whether the system supports the <b>NativeBufferConfig</b>.
 * @return {@link NATIVE_ERROR_OK} 0 - Success.
 * {@link NATIVE_ERROR_INVALID_ARGUMENTS} 40001000 - isSupported is NULL.
 * @since 23
 * @version 1.0
 */
int32_t OH_NativeBuffer_IsSupported(OH_NativeBuffer_Config config, bool* isSupported)
__attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Provide direct cpu access to the <b>OH_NativeBuffer</b> in the process's address space,\n
 * and return a <b>NativeBufferConfig<b> of the <b>OH_NativeBuffer</b>.
 * This interface is a non-thread-safe type interface.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeBuffer
 * @param buffer Indicates the pointer to a <b>OH_NativeBuffer</b> instance.
 * @param virAddr Indicates the address of the <b>OH_NativeBuffer</b> in virtual memory.
 * @param config Indicates the pointer to the <b>NativeBufferConfig</b> of the buffer.
 * @return {@link NATIVE_ERROR_OK} 0 - Success.
 * {@link NATIVE_ERROR_INVALID_ARGUMENTS} 40001000 - buffer or virAddr or config is NULL or invalid fenceFd.
 * {@link NATIVE_ERROR_UNKNOWN} 50002000 - map failed.
 * @since 23
 * @version 1.0
 */
int32_t OH_NativeBuffer_MapAndGetConfig(OH_NativeBuffer* buffer, void** virAddr, OH_NativeBuffer_Config* config)
__attribute__((__availability__(ohos, introduced=23.0.0)));
#ifdef __cplusplus
}
#endif

/** @} */
#endif