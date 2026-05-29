/*
 * Copyright (C) 2023 Huawei Device Co., Ltd.
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
 * @addtogroup Image_NativeModule
 * @{
 *
 * @brief Provides APIs for access to the image interface.
 *
 * @since 12
 */

/**
 * @file image_source_native.h
 *
 * @brief Declares APIs for decoding an image source into a pixel map.
 *
 * @library libimage_source.so
 * @kit ImageKit
 * @syscap SystemCapability.Multimedia.Image.ImageSource
 * @since 12
 */

#ifndef INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_IMAGE_SOURCE_NATIVE_H_
#define INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_IMAGE_SOURCE_NATIVE_H_
#include "info/application_target_sdk_version.h"
#include "image_common.h"

#include "pixelmap_native.h"
#include "picture_native.h"
#include "rawfile/raw_file.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines an image source object for the image interface.
 *
 * @since 12
 */
struct OH_ImageSourceNative;
typedef struct OH_ImageSourceNative OH_ImageSourceNative;

/**
 * @brief Defines image source infomation
 * {@link OH_ImageSourceInfo_Create}.
 *
 * @since 12
 */
struct OH_ImageSource_Info;
typedef struct OH_ImageSource_Info OH_ImageSource_Info;

/**
 * @brief Defines decoding options for picture
 * {@link OH_DecodingOptionsForPicture_Create}.
 *
 * @since 13
 */
struct OH_DecodingOptionsForPicture;

/**
 * @brief Defines decoding options for picture
 * {@link OH_DecodingOptionsForPicture_Create}.
 *
 * @since 13
 */
typedef struct OH_DecodingOptionsForPicture OH_DecodingOptionsForPicture;

/**
 * @brief Enumerates decoding dynamic range..
 *
 * @since 12
 */
typedef enum {
    /*
    * Dynamic range depends on the image.
    */
    IMAGE_DYNAMIC_RANGE_AUTO = 0,
    /*
    * Standard dynamic range.
    */
    IMAGE_DYNAMIC_RANGE_SDR = 1,
    /*
    * High dynamic range.
    */
    IMAGE_DYNAMIC_RANGE_HDR = 2,
} IMAGE_DYNAMIC_RANGE;

/**
 * @brief Type of allocator used to allocate memory of a PixelMap..
 *
 * @since 15
 */
typedef enum {
    /*
    * The system determines which memory to use to create the PixelMap.
    */
    IMAGE_ALLOCATOR_TYPE_AUTO = 0,
    /*
    * Use DMA buffer to create the PixelMap.
    */
    IMAGE_ALLOCATOR_TYPE_DMA = 1,
    /*
    * Use share memory to create the PixelMap.
    */
    IMAGE_ALLOCATOR_TYPE_SHARE_MEMORY = 2,
} IMAGE_ALLOCATOR_TYPE;

/**
 * @brief The strategy for executing the two operations when both desiredSize and desiredRegion
 * are specified.
 *
 * @since 18
 */
typedef enum {
    /**
     * Scale first, then crop.
     */
    IMAGE_CROP_AND_SCALE_STRATEGY_SCALE_FIRST = 1,

    /**
     * Crop first, then scale.
     */
    IMAGE_CROP_AND_SCALE_STRATEGY_CROP_FIRST = 2,
} Image_CropAndScaleStrategy;

/**
 * @brief Create a pointer for OH_ImageSource_Info struct.
 *
 * @param info The OH_ImageSource_Info pointer will be operated.
 * @return Returns {@link Image_ErrorCode}
 * @since 12
 */
Image_ErrorCode OH_ImageSourceInfo_Create(OH_ImageSource_Info **info)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get width number for OH_ImageSource_Info struct.
 *
 * @param info The OH_ImageSource_Info pointer will be operated.
 * @param width the number of image width.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} info is nullptr, or width is nullptr.
 * @since 12
 */
Image_ErrorCode OH_ImageSourceInfo_GetWidth(OH_ImageSource_Info *info, uint32_t *width)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get height number for OH_ImageSource_Info struct.
 *
 * @param info The OH_ImageSource_Info pointer will be operated.
 * @param height the number of image height.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} info is nullptr, or height is nullptr.
 * @since 12
 */
Image_ErrorCode OH_ImageSourceInfo_GetHeight(OH_ImageSource_Info *info, uint32_t *height)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get isHdr for OH_ImageSource_Info struct.
 *
 * @param info The OH_ImageSource_Info pointer will be operated. Pointer connot be null.
 * @param isHdr Whether the image has a high dynamic range.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} info is nullptr, or isHdr is nullptr.
 * @since 12
 */
Image_ErrorCode OH_ImageSourceInfo_GetDynamicRange(OH_ImageSource_Info *info, bool *isHdr)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the MIME type of an image source.
 *
 * @param info Pointer to the OH_ImageSource_Info struct.
 * @param mimetype Pointer to the MIME type of the image source.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} info is nullptr, or mimeType is nullptr.
 * @since 20
 */
Image_ErrorCode OH_ImageSourceInfo_GetMimeType(OH_ImageSource_Info *info, Image_MimeType *mimetype)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief delete OH_ImageSource_Info pointer.
 *
 * @param info The OH_ImageSource_Info pointer will be operated.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} info is nullptr.
 * @since 12
 */
Image_ErrorCode OH_ImageSourceInfo_Release(OH_ImageSource_Info *info)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Defines the options for decoding the image source.
 * It is used in {@link OH_ImageSourceNative_CreatePixelmap}.
 *
 * @since 12
 */
struct OH_DecodingOptions;
typedef struct OH_DecodingOptions OH_DecodingOptions;

/**
 * @brief Create a pointer for OH_DecodingOptions struct.
 *
 * @param  options The OH_DecodingOptions pointer will be operated.
 * @return Returns {@link Image_ErrorCode}
 * @since 12
 */
Image_ErrorCode OH_DecodingOptions_Create(OH_DecodingOptions **options)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get pixelFormat number for OH_DecodingOptions struct.
 *
 * @param  options The OH_DecodingOptions pointer will be operated.
 * @param pixelFormat the number of image pixelFormat.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} options is nullptr, or pixelFormat is nullptr.
 * @since 12
 */
Image_ErrorCode OH_DecodingOptions_GetPixelFormat(OH_DecodingOptions *options,
    int32_t *pixelFormat)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set pixelFormat number for OH_DecodingOptions struct.
 *
 * @param  options The OH_DecodingOptions pointer will be operated.
 * @param pixelFormat the number of image pixelFormat.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} options is nullptr.
 * @since 12
 */
Image_ErrorCode OH_DecodingOptions_SetPixelFormat(OH_DecodingOptions *options,
    int32_t pixelFormat)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get index number for OH_DecodingOptions struct.
 *
 * @param  options The OH_DecodingOptions pointer will be operated.
 * @param index the number of image index.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} options is nullptr, or index is nullptr.
 * @since 12
 */
Image_ErrorCode OH_DecodingOptions_GetIndex(OH_DecodingOptions *options, uint32_t *index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set index number for OH_DecodingOptions struct.
 *
 * @param  options The OH_DecodingOptions pointer will be operated.
 * @param index the number of image index.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} options is nullptr.
 * @since 12
 */
Image_ErrorCode OH_DecodingOptions_SetIndex(OH_DecodingOptions *options, uint32_t index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get rotate number for OH_DecodingOptions struct.
 *
 * @param  options The OH_DecodingOptions pointer will be operated.
 * @param rotate the number of image rotate.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} options is nullptr, or rotate is nullptr.
 * @since 12
 */
Image_ErrorCode OH_DecodingOptions_GetRotate(OH_DecodingOptions *options, float *rotate)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set rotate number for OH_DecodingOptions struct.
 *
 * @param  options The OH_DecodingOptions pointer will be operated.
 * @param rotate the number of image rotate.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} options is nullptr.
 * @since 12
 */
Image_ErrorCode OH_DecodingOptions_SetRotate(OH_DecodingOptions *options, float rotate)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get desiredSize number for OH_DecodingOptions struct.
 *
 * @param  options The OH_DecodingOptions pointer will be operated.
 * @param desiredSize the number of image desiredSize.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} options is nullptr, or desiredSize is nullptr.
 * @since 12
 */
Image_ErrorCode OH_DecodingOptions_GetDesiredSize(OH_DecodingOptions *options,
    Image_Size *desiredSize)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set desiredSize number for OH_DecodingOptions struct.
 *
 * @param  options The OH_DecodingOptions pointer will be operated.
 * @param desiredSize the number of image desiredSize.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} options is nullptr, or desiredSize is nullptr.
 * @since 12
 */
Image_ErrorCode OH_DecodingOptions_SetDesiredSize(OH_DecodingOptions *options,
    Image_Size *desiredSize)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set desiredRegion number for OH_DecodingOptions struct.
 *
 * @param  options The OH_DecodingOptions pointer will be operated.
 * @param desiredRegion the number of image desiredRegion.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} options is nullptr, or desiredRegion is nullptr.
 * @since 12
 */
Image_ErrorCode OH_DecodingOptions_GetDesiredRegion(OH_DecodingOptions *options,
    Image_Region *desiredRegion)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set desiredRegion number for OH_DecodingOptions struct.
 *
 * @param  options The OH_DecodingOptions pointer will be operated.
 * @param desiredRegion the number of image desiredRegion.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} options or desiredRegion is nullptr.
 * @since 12
 */
Image_ErrorCode OH_DecodingOptions_SetDesiredRegion(OH_DecodingOptions *options,
    Image_Region *desiredRegion)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set desiredDynamicRange number for OH_DecodingOptions struct.
 *
 * @param options The OH_DecodingOptions pointer will be operated. Pointer connot be null.
 * @param desiredDynamicRange the number of desired dynamic range {@link IMAGE_DYNAMIC_RANGE}. Pointer connot be null.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} options is nullptr, or desiredDynamicRange is nullptr.
 * @since 12
 */
Image_ErrorCode OH_DecodingOptions_GetDesiredDynamicRange(OH_DecodingOptions *options,
    int32_t *desiredDynamicRange)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets a cropping and scaling strategy for decoding options.
 *
 * @param options Pointer to the decoding options.
 * @param cropAndScaleStrategy Strategy for executing the cropping and scaling operations when both desiredSize and
 * desiredRegion are specified.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} The execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} options is a null pointer or cropAndScaleStrategy is not in the range of
 *         Image_CropAndScaleStrategy.
 * @since 18
 */
Image_ErrorCode OH_DecodingOptions_SetCropAndScaleStrategy(OH_DecodingOptions *options,
    int32_t cropAndScaleStrategy)
    __attribute__((__availability__(ohos, introduced=18.0.0)));

/**
 * @brief Obtains the cropping and scaling strategy of decoding options.
 *
 * @param options Pointer to the decoding options.
 * @param cropAndScaleStrategy Pointer to the strategy for executing the cropping and scaling operations when both
 * desiredSize and desiredRegion are specified.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS}: The execution is successful. 
 *         {@link IMAGE_BAD_PARAMETER}: options or cropAndScaleStrategy is a null pointer.
 * @since 18
 */
Image_ErrorCode OH_DecodingOptions_GetCropAndScaleStrategy(OH_DecodingOptions *options,
    int32_t *cropAndScaleStrategy)
    __attribute__((__availability__(ohos, introduced=18.0.0)));

/**
 * @brief Set desiredDynamicRange number for OH_DecodingOptions struct.
 *
 * @param options The OH_DecodingOptions pointer will be operated. Pointer connot be null.
 * @param desiredDynamicRange the number of desired dynamic range {@link IMAGE_DYNAMIC_RANGE}.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} options is nullptr.
 * @since 12
 */
Image_ErrorCode OH_DecodingOptions_SetDesiredDynamicRange(OH_DecodingOptions *options,
    int32_t desiredDynamicRange)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the color space set in the decoding options.
 *
 * @param options Pointer to the decoding options.
 * @param colorSpace Pointer to the color space.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if options or colorSpace is null pointer.
 * @since 20
 */
Image_ErrorCode OH_DecodingOptions_GetDesiredColorSpace(OH_DecodingOptions *options, int32_t *colorSpace)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Sets the desired color space for the decoding options.
 *
 * @param options Pointer to the decoding options.
 * @param colorSpace Desired color space.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if options is a null pointer or colorSpace is not supported.
 * @since 20
 */
Image_ErrorCode OH_DecodingOptions_SetDesiredColorSpace(OH_DecodingOptions *options, int32_t colorSpace)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Sets the crop region for the decoding options.
 *
 * @param options Pointer to the decoding options.
 * @param cropRegion The target region will be cropped from the image.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if options or cropRegion is null pointer.
 * @since 19
 */
Image_ErrorCode OH_DecodingOptions_SetCropRegion(OH_DecodingOptions *options, Image_Region *cropRegion)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Gets the crop region for the decoding options.
 *
 * @param options Pointer to the decoding options.
 * @param cropRegion The target region will be cropped from the image.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if options or cropRegion is null pointer.
 * @since 19
 */
Image_ErrorCode OH_DecodingOptions_GetCropRegion(OH_DecodingOptions *options, Image_Region *cropRegion)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief delete OH_DecodingOptions pointer.
 *
 * @param  options The OH_DecodingOptions pointer will be operated.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} if options is a null pointer.
 * @since 12
 */
Image_ErrorCode OH_DecodingOptions_Release(OH_DecodingOptions *options)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Creates an ImageSource pointer.
 *
 * @param uri Indicates a pointer to the image source URI. Only a file URI or Base64 URI is accepted.
 * @param uriSize Indicates the length of the image source URI.
 * @param res Indicates a pointer to the <b>ImageSource</b> object created at the C++ native layer.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} if uri is a null pointer.
 * @since 12
 */
Image_ErrorCode OH_ImageSourceNative_CreateFromUri(char *uri, size_t uriSize, OH_ImageSourceNative **res)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Creates an void pointer
 *
 * @param fd Indicates the image source file descriptor.
 * @param res Indicates a void pointer to the <b>ImageSource</b> object created at the C++ native layer.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} if fd is invalid.
 * @since 12
 */
Image_ErrorCode OH_ImageSourceNative_CreateFromFd(int32_t fd, OH_ImageSourceNative **res)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Creates an void pointer
 *
 * @param data Indicates a pointer to the image source data. Only a formatted packet data or Base64 data is accepted.
 * @param dataSize Indicates the size of the image source data.
 * @param res Indicates a void pointer to the <b>ImageSource</b> object created at the C++ native layer.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} if data is a null pointer or if dataSize is 0.
 * @since 12
 */
Image_ErrorCode OH_ImageSourceNative_CreateFromData(uint8_t *data, size_t dataSize, OH_ImageSourceNative **res)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Create an image source from data buffer. The data buffer is directly accessed by the image source
 * object, and therefore the data buffer must remain accessible within the lifecycle of the image source object.
 *
 * @param data Pointer to the data buffer.
 * @param datalength Length of the data buffer.
 * @param imageSource Double pointer to the image source.
 * @return Result code.
 * {@link IMAGE_SUCCESS} if the execution is successful. 
 * {@link IMAGE_SOURCE_INVALID_PARAMETER} if data or imageSource is a null pointer or if datalength is 0.
 * @since 20
 */
Image_ErrorCode OH_ImageSourceNative_CreateFromDataWithUserBuffer(uint8_t *data, size_t datalength,
                                                                  OH_ImageSourceNative **imageSource)
                                                                  __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Creates an void pointer
 *
 * @param rawFile Indicates the raw file's file descriptor.
 * @param res Indicates a void pointer to the <b>ImageSource</b> object created at the C++ native layer.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} if rawFile is a null pointer.
 * @since 12
 */
Image_ErrorCode OH_ImageSourceNative_CreateFromRawFile(RawFileDescriptor *rawFile, OH_ImageSourceNative **res)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Decodes an void pointer
 * based on the specified {@link OH_DecodingOptions} struct.
 *
 * @param source Indicates a void pointer(from ImageSource pointer convert).
 * @param  options Indicates a pointer to the options for decoding the image source.
 * For details, see {@link OH_DecodingOptions}.
 * @param pixelmap Indicates a void pointer to the <b>Pixelmap</b> object obtained at the C++ native layer.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} source is nullptr.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_OPTIONS} unsupported options,
 *         e.g, cannot convert image into desired pixel format.
 * @since 12
 */
Image_ErrorCode OH_ImageSourceNative_CreatePixelmap(OH_ImageSourceNative *source, OH_DecodingOptions *options,
    OH_PixelmapNative **pixelmap)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Creates a PixelMap based on decoding parameters {@link OH_DecodingOptions}, the memory type used by the
 * PixelMap can be specified by allocatorType {@link IMAGE_ALLOCATOR_TYPE}. By default, the system selects the memory
 * type based on the image type, image size, platform capability, etc. When processing the PixelMap returned by this
 * interface, please always consider the impact of stride.
 *
 * @param source Image Source.
 * @param options Decoding parameters, such as the size, pixel format, and color space of the pixelMap.
 * For details, see {@link OH_DecodingOptions}.
 * @param allocator Indicate which memory type will be used by the returned PixelMap.
 * @param pixelmap Decoded <b>Pixelmap</b> object.
 * @return Error code.
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} source is nullptr, or picture is nullptr.
 *         {@link IMAGE_BAD_SOURCE} data source exception.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE} unsupported mime type.
 *         {@link IMAGE_SOURCE_TOO_LARGE} image to large.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_ALLOCATOR_TYPE} unsupported allocator type,
 *         e.g., use share memory to decode a HDR image as only DMA supported hdr metadata.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_OPTIONS} unsupported options,
 *         e.g, cannot convert image into desired pixel format.
 *         {@link IMAGE_DECODE_FAILED} decode failed.
 *         {@link IMAGE_SOURCE_ALLOC_FAILED} memory allocation failed.
 * @since 15
 */
Image_ErrorCode OH_ImageSourceNative_CreatePixelmapUsingAllocator(OH_ImageSourceNative *source,
    OH_DecodingOptions *options, IMAGE_ALLOCATOR_TYPE allocator, OH_PixelmapNative **pixelmap)
    __attribute__((__availability__(ohos, introduced=15.0.0)));


/**
 * @brief Decodes an void pointer
 * the <b>Pixelmap</b> objects at the C++ native layer
 * based on the specified {@link OH_DecodingOptions} struct.
 *
 * @param source Indicates a void pointer(from ImageSource pointer convert).
 * @param  options Indicates a pointer to the options for decoding the image source.
 * For details, see {@link OH_DecodingOptions}.
 * @param resVecPixMap Indicates a pointer array to the <b>Pixelmap</b> objects obtained at the C++ native layer.
 * It cannot be a null pointer.
 * @param size Indicates a size of resVecPixMap. User can get size from {@link OH_ImageSourceNative_GetFrameCount}.
 * @return @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} source is nullptr, or options is nullptr, or resVecPixMap is nullptr.
 * @since 12
 */
Image_ErrorCode OH_ImageSourceNative_CreatePixelmapList(OH_ImageSourceNative *source, OH_DecodingOptions *options,
    OH_PixelmapNative *resVecPixMap[], size_t size)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Create Picture pointer from ImageSource
 * based on the specified {@link OH_DecodingOptionsForPicture} struct.
 *
 * @param source Indicates a void pointer(from ImageSource pointer convert).
 * @param options Indicates a pointer to the options for decoding the image source.
 * For details, see {@link OH_DecodingOptionsForPicture}.
 * @param picture Indicates a void pointer to the <b>Picture</b> object obtained at the C++ native layer.
 * @return Image functions result code.
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} source is nullptr, or picture is nullptr.
 *         {@link IMAGE_DECODE_FAILED} decode failed.
 * @since 13
 */
Image_ErrorCode OH_ImageSourceNative_CreatePicture(OH_ImageSourceNative *source, OH_DecodingOptionsForPicture *options,
    OH_PictureNative **picture)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Decodes an image at the specified index into a Picture object.
 *
 * @param source Pointer to the image source.
 * @param index Image index.
 * @param picture Double pointer to the Picture object obtained after decoding.
 * @return Result code. 
 * {@link IMAGE_SUCCESS}: The execution is successful.
 * {@link IMAGE_BAD_SOURCE}: The data source is abnormal.
 * {@link IMAGE_SOURCE_UNSUPPORTED_MIMETYPE}: The image format is unsupported.
 * {@link IMAGE_SOURCE_TOO_LARGE}: The image is too large.
 * {@link IMAGE_SOURCE_UNSUPPORTED_OPTIONS}: The operation is not supported, for example, invalid index.
 * {@link IMAGE_DECODE_FAILED}: Decoding fails.
 * @since 20
 */
Image_ErrorCode OH_ImageSourceNative_CreatePictureAtIndex(OH_ImageSourceNative *source, uint32_t index,
    OH_PictureNative **picture)
    __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Obtains the delay time list from some <b>ImageSource</b> objects (such as GIF image sources).
 *
 * @param source Indicates a void pointer(from ImageSource pointer convert).
 * @param delayTimeList Indicates a pointer to the delay time list obtained. It cannot be a null pointer.
 * @param size Indicates a size of delayTimeList. User can get size from {@link OH_ImageSourceNative_GetFrameCount}.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} source is nullptr, or delayTimeList is nullptr.
 * @since 12
 */
Image_ErrorCode OH_ImageSourceNative_GetDelayTimeList(OH_ImageSourceNative *source, int32_t *delayTimeList, size_t size)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains image source information from an <b>ImageSource</b> object by index.
 *
 * @param source Indicates a void pointer(from ImageSource pointer convert).
 * @param index Indicates the index of the frame.
 * @param info Indicates a pointer to the image source information obtained.
 * For details, see {@link OH_ImageSource_Info}.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} source is nullptr, or info is nullptr, or failed to get image info.
 * @since 12
 */
Image_ErrorCode OH_ImageSourceNative_GetImageInfo(OH_ImageSourceNative *source, int32_t index,
    OH_ImageSource_Info *info)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the value of an image property from an <b>ImageSource</b> object.
 *
 * @param source Pointer to ImageSource.
 * @param key Pointer to the property key.
 * @param value Pointer to the property value. Output Parameter.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} source is nullptr, or key is nullptr, or value is nullptr.
 *         {@link IMAGE_ALLOC_FAILED} allocate memory failed.
 *         {@link IMAGE_COPY_FAILED} copy memory failed.
 * @since 12
 */
Image_ErrorCode OH_ImageSourceNative_GetImageProperty(OH_ImageSourceNative *source, Image_String *key,
    Image_String *value)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the value of an image property from an <b>ImageSource</b> object. The output value.data is null-terminated.
 *
 * @param source Pointer to ImageSource.
 * @param key Pointer to the property key.
 * @param value Pointer to the property value. Output Parameter.
 * @return Returns One of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if source, key or value is nullptr.
 * @since 19
 */
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyWithNull(OH_ImageSourceNative *source, Image_String *key,
    Image_String *value)
    __attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Modifies the value of an image property of an <b>ImageSource</b> object.
 * @param source Indicates a void pointer(from ImageSource pointer convert).
 * @param key Indicates a pointer to the property. For details, see {@link Image_String}., key is an exif constant.
 * Release after use ImageSource, see {@link OH_ImageSourceNative_Release}.
 * @param value Indicates a pointer to the new value of the property.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} source is nullptr, or key is nullptr, or value is nullptr,
 *         or failed to modify image property because of invalid parameters.
 * @since 12
 */
Image_ErrorCode OH_ImageSourceNative_ModifyImageProperty(OH_ImageSourceNative *source, Image_String *key,
    Image_String *value)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the number of frames from an <b>ImageSource</b> object.
 *
 * @param source Indicates a pointer to the {@link OH_ImageSource} object at the C++ native layer.
 * @param res Indicates a pointer to the number of frames obtained.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} source is nullptr, or frameCount is nullptr.
 * @since 12
 */
Image_ErrorCode OH_ImageSourceNative_GetFrameCount(OH_ImageSourceNative *source, uint32_t *frameCount)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Releases an <b>ImageSourc</b> object.
 *
 * @param source Indicates a ImageSource pointer.
 * @return Returns one of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} source is nullptr.
 * @since 12
 */
Image_ErrorCode OH_ImageSourceNative_Release(OH_ImageSourceNative *source)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Create a pointer for OH_DecodingOptionsForPicture struct.
 *
 * @param options The OH_DecodingOptionsForPicture pointer will be operated.
 * @return Image functions result code.
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} options is nullptr.
 * @since 13
 */
Image_ErrorCode OH_DecodingOptionsForPicture_Create(OH_DecodingOptionsForPicture **options)
__attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Obtains the desired auxiliary pictures of decoding options.
 *
 * @param options The OH_DecodingOptionsForPicture pointer will be operated.
 * @param desiredAuxiliaryPictures The desired auxiliary pictures in DecodingOptionsForPicture.
 * @param length The length of desired auxiliary pictures.
 * @return Image functions result code.
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} options is nullptr, desiredAuxiliaryPictures is nullptr,
 *         or length is invalid.
 * @since 13
 */
Image_ErrorCode OH_DecodingOptionsForPicture_GetDesiredAuxiliaryPictures(OH_DecodingOptionsForPicture *options,
    Image_AuxiliaryPictureType **desiredAuxiliaryPictures, size_t *length)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Set decoding options desired auxiliary pictures.
 *
 * @param options The OH_DecodingOptionsForPicture pointer will be operated.
 * @param desiredAuxiliaryPictures The desired auxiliary pictures will be set.
 * @param length The length of desired auxiliary pictures.
 * @return Image functions result code.
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} options is nullptr, desiredAuxiliaryPictures is nullptr,
 *         or length is invalid.
 * @since 13
 */
Image_ErrorCode OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures(OH_DecodingOptionsForPicture *options,
    Image_AuxiliaryPictureType *desiredAuxiliaryPictures, size_t length)
    __attribute__((__availability__(ohos, introduced=13.0.0)));

/**
 * @brief Releases an <b>DecodingOptionsForPicture</b> object.
 *
 * @param options Indicates a DecodingOptionsForPicture pointer.
 * @return Image functions result code.
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_PARAMETER} options is nullptr.
 * @since 13
 */
Image_ErrorCode OH_DecodingOptionsForPicture_Release(OH_DecodingOptionsForPicture *options)
__attribute__((__availability__(ohos, introduced=13.0.0)));

/**
  * @brief Obtains the supported image formats that can be decoded.
  *
  * @param supportedFormats Double pointer to an array of the supported image formats.
  * @param length Pointer to the length of the array.
  * @return One of the following result codes:
  *         {@link IMAGE_SUCCESS} if the execution is successful.
  *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if <b>supportedFormats</b> or <b>length</b> is empty.
  * @since 20
 */
Image_ErrorCode OH_ImageSourceNative_GetSupportedFormats(Image_MimeType **supportedFormats, size_t *length)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Obtains the value of an image property as short int type.
 *
 * @param source ImageSource from which the property is queried.
 * @param key The property to be queried.
 * @param value Query result. Output Parameter.
 * @return Returns One of the following result codes: 
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if source, key or value is nullptr.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE} if query image property of current mimetype is not supported.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_METADATA} if indicated metadata doesn't exist, or is not a short int value.
 * @since 23
 */
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyShort(OH_ImageSourceNative *source,
    Image_String *key, uint16_t *value)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Obtains the value of an image property as long int type.
 *
 * @param source ImageSource from which the property is queried.
 * @param key The property to be queried.
 * @param value Query result. Output Parameter.
 * @return Returns One of the following result codes: 
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if source, key or value is nullptr.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE} if query image property of current mimetype is not supported.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_METADATA} if indicated metadata doesn't exist, or is not a long int value.
 * @since 23
 */
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyLong(OH_ImageSourceNative *source,
    Image_String *key, uint32_t *value)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Obtains the value of an image property as double type.
 *
 * @param source ImageSource from which the property is queried.
 * @param key The property to be queried.
 * @param value Query result. Output Parameter.
 * @return Returns One of the following result codes: 
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if source, key or value is nullptr.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE} if query image property of current mimetype is not supported.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_METADATA} if indicated metadata doesn't exist, or is not a double value.
 * @since 23
 */
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyDouble(OH_ImageSourceNative *source,
    Image_String *key, double *value)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Gets the array length of an array type property or the string length of a string type property.
 *
 * @param source ImageSource from which the property is queried.
 * @param key The property to be queried.
 * @param size Array length for an array type property, string length for a string type property. Output Parameter.
 * @return Returns One of the following result codes: 
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if source, key or size is nullptr.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE} if query image property of current mimetype is not supported.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_METADATA} if indicated metadata doesn't exist,
 *         or is not a array\string value.
 * @since 23
 */
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyArraySize(OH_ImageSourceNative *source,
    Image_String *key, size_t *size)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Obtains the value of an image property as string type.
 *
 * @param source ImageSource from which the property is queried.
 * @param key The property to be queried.
 * @param value Query result. Output Parameter. The caller needs to manage memory application and release.
 * @param size String length.
 * @return Returns One of the following result codes: 
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if source, key, value or size is nullptr.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE} if query image property of current mimetype is not supported.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_METADATA} if indicated metadata doesn't exist, or is not a string value.
 * @since 23
 */
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyString(OH_ImageSourceNative *source,
    Image_String *key, char *value, size_t size)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Obtains the value of an image property as int array.
 *
 * @param source ImageSource from which the property is queried.
 * @param key The property to be queried.
 * @param value Query result. Output Parameter. The caller needs to manage memory application and release.
 * @param size Array length.
 * @return Returns One of the following result codes: 
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if source, key, value or size is nullptr.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE} if query image property of current mimetype is not supported.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_METADATA} if indicated metadata doesn't exist, or is not a int array.
 * @since 23
 */
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyIntArray(OH_ImageSourceNative *source,
    Image_String *key, int32_t *value, size_t size)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Obtains the value of an image property as double array.
 *
 * @param source ImageSource from which the property is queried.
 * @param key The property to be queried.
 * @param value Query result. Output Parameter. The caller needs to manage memory application and release.
 * @param size Array length.
 * @return Returns One of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if source, key, value or size is nullptr.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE} if query image property of current mimetype is not supported.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_METADATA} if indicated metadata doesn't exist, or is not a double array.
 * @since 23
 */
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyDoubleArray(OH_ImageSourceNative *source,
    Image_String *key, double *value, size_t size)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Obtains the value of an image property as blob.
 *
 * @param source ImageSource from which the property is queried.
 * @param key The property to be queried.
 * @param value Query result. Output Parameter. The caller needs to manage memory application and release.
 * @param size Array length.
 * @return Returns One of the following result codes: 
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if source, key, value or size is nullptr.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE} if query image property of current mimetype is not supported.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_METADATA} if indicated metadata doesn't exist, or is not a blob.
 * @since 23
 */
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyBlob(OH_ImageSourceNative *source, Image_String *key,
    void *value, size_t size)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Modify the value of an image property as short int.
 *
 * @param source ImageSource from which the property is modified.
 * @param key The property to be modified.
 * @param value The value set to the property.
 * @return Returns One of the following result codes: 
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if source, key or value is nullptr.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE} if query image property of current mimetype is not supported.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_METADATA} if indicated metadata doesn't exist, or is not a short int.
 * @since 23
 */
Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyShort(OH_ImageSourceNative *source, Image_String *key,
    uint16_t value)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Modify the value of an image property as long int.
 *
 * @param source ImageSource from which the property is modified.
 * @param key The property to be modified.
 * @param value The value set to the property.
 * @return Returns One of the following result codes: 
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if source, key or value is nullptr.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE} if query image property of current mimetype is not supported.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_METADATA} if indicated metadata doesn't exist, or is not a long int.
 * @since 23
 */
Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyLong(OH_ImageSourceNative *source, Image_String *key,
    uint32_t value)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Modify the value of an image property as double.
 *
 * @param source ImageSource from which the property is modified.
 * @param key The property to be modified.
 * @param value The value set to the property.
 * @return Returns One of the following result codes: 
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if source, key or value is nullptr.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE} if query image property of current mimetype is not supported.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_METADATA} if indicated metadata doesn't exist, or is not a double.
 * @since 23
 */
Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyDouble(OH_ImageSourceNative *source, Image_String *key,
    double value)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Modify the value of an image property as int array.
 *
 * @param source ImageSource from which the property is modified.
 * @param key The property to be modified.
 * @param value The value set to the property.
 * @param size Array length.
 * @return Returns One of the following result codes: 
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if source, key or value is nullptr.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE} if query image property of current mimetype is not supported.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_METADATA} if indicated metadata doesn't exist, or is not an int array.
 * @since 23
 */
Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyIntArray(OH_ImageSourceNative *source, Image_String *key,
    int32_t *value, size_t size)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Modify the value of an image property as double array.
 *
 * @param source ImageSource from which the property is modified.
 * @param key The property to be modified.
 * @param value The value set to the property.
 * @param size Array length.
 * @return Returns One of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if source, key or value is nullptr.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE} if query image property of current mimetype is not supported.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_METADATA} if indicated metadata doesn't exist, or is not a double array.
 * @since 23
 */
Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyDoubleArray(OH_ImageSourceNative *source, Image_String *key,
    double *value, size_t size)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Modify the value of an image property as blob.
 *
 * @param source ImageSource from which the property is modified.
 * @param key The property to be modified.
 * @param value The value set to the property.
 * @param size Array length.
 * @return Returns One of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if source, key or value is nullptr.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE} if query image property of current mimetype is not supported.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_METADATA} if indicated metadata doesn't exist, or is not a blob.
 * @since 23
 */
Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyBlob(OH_ImageSourceNative *source, Image_String *key,
    void *value, size_t size)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Defines raw data in an image.
 * It is used in {@link OH_ImageSourceNative_CreateImageRawData}.
 *
 * @since 24
 */
struct OH_ImageRawData;

/**
 * @brief Defines raw data in an image.
 * It is used in {@link OH_ImageSourceNative_CreateImageRawData}.
 *
 * @since 24
 */
typedef struct OH_ImageRawData OH_ImageRawData;

/**
 * @brief Obtains rawData object from an image.
 *         The rawData object usually occupies a large amount of memory because it contains
 *         raw data from the camera. When the rawData object and the data it contains are not used, call the
 *         {@link OH_ImageSourceNative_DestroyImageRawData} method to destroy them in a timely manner.
 *
 * @param source Pointer to the image source.
 * @param rawData Double pointer to the rawData object obtained after decoding.
 * @return Returns One of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_BAD_SOURCE} Bad source.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if the rawData object is invalid.
 *         {@link IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE} Unsupported MIME type.
 * @since 24
 */
Image_ErrorCode OH_ImageSourceNative_CreateImageRawData(const OH_ImageSourceNative *source, OH_ImageRawData **rawData)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets binary data from the rawData object.
 *
 * @param rawData Pointer to the rawData object.
 * @param data Pointer to the binary buffer data.
 * @param length Pointer to the length of data obtained.
 * @return Returns One of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if the rawData object is invalid.
 * @since 24
 */
 Image_ErrorCode OH_ImageSourceNative_GetBufferFromRawData(const OH_ImageRawData *rawData,
    uint8_t **data, size_t *length)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets number of bits that each pixel actually occupies in the buffer data.
 *
 * @param rawData Pointer to the rawData object.
 * @param bitsPerPixel Pointer to the bitsPerPixel obtained.
 * @return Returns One of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if the rawData object is invalid.
 * @since 24
 */
Image_ErrorCode OH_ImageSourceNative_GetBitsPerPixelFromRawData(const OH_ImageRawData *rawData, uint8_t *bitsPerPixel)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroys the rawData object.
 *
 * @param rawData Pointer to the rawData object.
 * @return Returns One of the following result codes:
 *         {@link IMAGE_SUCCESS} if the execution is successful.
 *         {@link IMAGE_SOURCE_INVALID_PARAMETER} if the rawData object is invalid.
 * @since 24
 */
Image_ErrorCode OH_ImageSourceNative_DestroyImageRawData(OH_ImageRawData *rawData)
__attribute__((__availability__(ohos, introduced=24.0.0)));
#ifdef __cplusplus
};
#endif
/** @} */
#endif // INTERFACES_KITS_NATIVE_INCLUDE_IMAGE_IMAGE_SOURCE_NATIVE_H_