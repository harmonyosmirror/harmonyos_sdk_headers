/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 */

/**
 * @addtogroup HiAIFoundation
 * @{
 *
 * @brief Provides APIs for HiAI Foundation model inference.
 *
 * @syscap SystemCapability.AI.HiAIFoundation
 * @since 4.1.0(11)
 */

/**
 * @file hiai_aipp_param.h
 * @kit HiAIFoundationKit
 * @library libhiai_foundation.so
 * @brief APIs for creating dynamic AIPP objects and setting and querying relevant parameters for HiAI Foundation model
 * inference.
 *
 * @since 4.1.0(11)
 */

#ifndef HIAI_FOUNDATION_AIPP_PARAM_H
#define HIAI_FOUNDATION_AIPP_PARAM_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "neural_network_runtime/neural_network_runtime_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief AIPP parameter object.
 * @since 4.1.0(11)
 */
typedef struct HiAI_AippParam HiAI_AippParam;

/**
 * @brief Creates a dynamic AippParam object based on batchNum.
 *
 * This method is used to create a dynamic AippParam object. You can apply for memory based on batchNum to store dynamic
 * AIPP parameters. If {@link HiAI_AippParam} not been used, call {@link HMS_HiAIAippParam_Destroy} to
 * release the pointer. Otherwise, memory leak may occur.
 *
 * @param batchNum Batch size of the model input. The value range is (0, 127].
 * @return Returns the pointer to {@link HiAI_AippParam} if the operation is successful; returns a null pointer
 * otherwise.
 * @see HMS_HiAIAippParam_Destroy
 * @since 4.1.0(11)
 */
HiAI_AippParam* HMS_HiAIAippParam_Create(uint32_t batchNum);

/**
 * @brief Obtains the memory address requested for AippParam.
 *
 * This method is used to obtain the data memory address requested for {@link HiAI_AippParam} through {@link
 * HMS_HiAIAippParam_Create}. data points to the memory requested for AIPP parameters.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, a null
 * pointer is returned.
 * @return Returns the memory address requested for AippParam if the operation is successful; returns a null pointer
 * otherwise.
 * @since 4.1.0(11)
 */
void* HMS_HiAIAippParam_GetData(HiAI_AippParam* aippParam);

/**
 * @brief Obtains the memory size requested for AippParam.
 *
 * This method is used to obtain the memory size requested for {@link HiAI_AippParam} through {@link
 * HMS_HiAIAippParam_Create}. size indicates the memory size requested for AIPP parameters.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, 0 is
 * returned.
 * @return Returns the memory size requested for AippParam if the operation is successful; returns 0 otherwise.
 * @since 4.1.0(11)
 */
uint32_t HMS_HiAIAippParam_GetDataSize(HiAI_AippParam* aippParam);

/**
 * @brief Queries the input index of the AippParam object.
 *
 * This method is used to query the input index of the AippParam object in the case of multiple inputs.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, -1 is
 * returned.
 * @return Returns the input index of the AippParam object if the operation is successful; returns -1 otherwise.
 * @since 4.1.0(11)
 */
int HMS_HiAIAippParam_GetInputIndex(HiAI_AippParam* aippParam);

/**
 * @brief Sets the input index of the AippParam object.
 *
 * This method is used to set the index of the input linked with the AippParam object, in the case of multiple inputs.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null.
 * @param inputIndex Sequence number of the model input linked with the AIPP parameter. The value starts from 0.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_SetInputIndex(HiAI_AippParam* aippParam, uint32_t inputIndex);

/**
 * @brief Queries the index of an output, in the scenario where the input linked with AippParam has more than one
 * output.
 *
 * This method is used to query the data node index of the AippParam object, in the case that the data node has more
 * than one index.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, -1 is
 * returned.
 * @return Returns the data node's index of the AippParam object if the operation is successful; returns -1 otherwise.
 * @since 4.1.0(11)
 */
int HMS_HiAIAippParam_GetInputAippIndex(HiAI_AippParam* aippParam);

/**
 * @brief Sets the index of an output, in the scenario where the input linked with AippParam has more than one output.
 *
 * This method is used to set the index of an output, in the scenario where the data linked with AippParam has more than
 * one output.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null.
 * @param inputAippIndex Identifies the output linked with the AIPP configuration, in the scenario where the input
 * data has more than one output. The value starts from 0.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_SetInputAippIndex(HiAI_AippParam* aippParam, uint32_t inputAippIndex);

/**
 * @brief Releases the AippParam object.
 *
 * This method is used to release {@link HiAI_AippParam} created by using {@link HMS_HiAIAippParam_Create}.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null.
 * @since 4.1.0(11)
 */
void HMS_HiAIAippParam_Destroy(HiAI_AippParam** aippParam);

/**
 * @brief Image format enums of input and output tensors supported by HiAI Foundation inference.
 *
 *        HiAI Foundation only supports the image format enums declared below.
 *
 * @since 4.1.0(11)
 */
typedef enum {
    /** YUV420SP_U8 image */
    HIAI_YUV420SP_U8 = 0,
    /** XRGB8888_U8 image */
    HIAI_XRGB8888_U8 = 1,
    /** YUV400_U8 image */
    HIAI_YUV400_U8 = 2,
    /** ARGB8888_U8 image */
    HIAI_ARGB8888_U8 = 3,
    /** YUYV_U8 image */
    HIAI_YUYV_U8 = 4,
    /** YUV422SP_U8 image */
    HIAI_YUV422SP_U8 = 5,
    /** AYUV444_U8 image */
    HIAI_AYUV444_U8 = 6,
    /** RGB888_U8 image */
    HIAI_RGB888_U8 = 7,
    /** BGR888_U8 image */
    HIAI_BGR888_U8 = 8,
    /** YUV444SP_U8 image */
    HIAI_YUV444SP_U8 = 9,
    /** YVU444SP_U8 image */
    HIAI_YVU444SP_U8 = 10,
    /** not support image */
    HIAI_IMAGE_FORMAT_INVALID = 255,
} HiAI_ImageFormat;

/**
 * @brief Sets the input image format.
 *
 * This method is used to set the input image format in the {@link HiAI_AippParam} object during dynamic AIPP
 * inference. The image formats supported for AIPP are specified in {@link HiAI_ImageFormat}. 8-bit image. The value
 * ranges from 0 to 255. HIAI_YUV444SP_U8 and HIAI_YVU444SP_U8 can't be used for the inputFormat parameter.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param inputFormat Format of the input image. For details, see {@link HiAI_ImageFormat}.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_SetInputFormat(HiAI_AippParam* aippParam, HiAI_ImageFormat inputFormat);

/**
 * @brief Queries the input image format.
 *
 * This method is used to query the input image format based on the {@link HiAI_AippParam} object during
 * dynamic AIPP inference.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, {@link
 * HIAI_IMAGE_FORMAT_INVALID} is returned.
 * @return Returns {@link HiAI_ImageFormat} if the operation is successful; returns {@link HIAI_IMAGE_FORMAT_INVALID}
 * otherwise.
 * @since 4.1.0(11)
 */
HiAI_ImageFormat HMS_HiAIAippParam_GetInputFormat(HiAI_AippParam* aippParam);

/**
 * @brief Sets the width and height of the input image.
 *
 * This method is used to set the width and height of the input image in the {@link HiAI_AippParam} object
 * during dynamic AIPP inference.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param srcImageW Width of the input image. The value range is [16, 4096].
 * @param srcImageH Height of the input image. The value range is [16, 4096].
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_SetInputShape(
    HiAI_AippParam* aippParam, uint32_t srcImageW, uint32_t srcImageH);

/**
 * @brief Queries the width and height of the input image.
 *
 * This method is used to query the width and height of the input image based on the {@link HiAI_AippParam}
 * object during dynamic AIPP inference.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param [out] srcImageW Width of the input image.
 * @param [out] srcImageH Height of the input image.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_GetInputShape(
    HiAI_AippParam* aippParam, uint32_t* srcImageW, uint32_t* srcImageH);

/**
 * @brief Queries the number of images set by AippParam.
 *
 * This method is used to query the number of images of aippParam based on the {@link HiAI_AippParam} object
 * during dynamic AIPP inference. In the single-batch multi-crop scenario, this method queries the number of the cropped
 * subimages. In the multi-batch single-crop scenario, this method queries the input batch value.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null.
 * @return Returns the number of images if the operation is successful; returns 0 otherwise.
 * @since 4.1.0(11)
 */
uint32_t HMS_HiAIAippParam_GetBatchCount(HiAI_AippParam* aippParam);

/**
 * @brief Image's color space type.
 * @since 4.1.0(11)
 */
typedef enum {
    /** JPEG's color space */
    HIAI_JPEG = 0,
    /** BT.601 video range color space */
    HIAI_BT_601_NARROW = 1,
    /** BT.601 full range color space */
    HIAI_BT_601_FULL = 2,
    /** BT.709 video range color space */
    HIAI_BT_709_NARROW = 3,
    /** Invalid color space type */
    HIAI_IMAGE_COLOR_SPACE_INVALID = 4,
} HiAI_ImageColorSpace;

/**
 * @brief Sets Color Space Conversion (CSC) parameters for AIPP.
 *
 * This method is used to set the CSC parameters in the {@link HiAI_AippParam} object during dynamic AIPP
 * inference. CSC refers to the conversion between the YUV and RGB image formats.
 * If the input image is of the YUV (YUV420SP_U8/YUYV_U8/YUV422SP_U8/AYUV444_U8) format, the training set can consist of
 * RGB888_U8, BGR888_U8, or grayscale (YUV400_U8) images.
 * If the input image is in RGB (XRGB8888_U8/ARGB8888_U8/RGB888_U8/BGR888_U8) format, the training set can consist of
 * YUV444SP_U8, YVU444SP_U8, or grayscale (YUV400_U8) images.
 * Conversion from YUV400 to RGB or BGR is not supported.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param inputFormat Image input format. For details, see {@link HiAI_ImageFormat}. HIAI_YUV444SP_U8 and
 * HIAI_YVU444SP_U8 can't be used for the inputFormat parameter.
 * @param outputFormat Image output format. For details, see {@link HiAI_ImageFormat}.
 * @param space Image's color space type. For details, see {@link HiAI_ImageColorSpace}.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_SetCscConfig(
    HiAI_AippParam* aippParam, HiAI_ImageFormat inputFormat, HiAI_ImageFormat outputFormat, HiAI_ImageColorSpace space);

/**
 * @brief Queries the CSC parameters of AIPP.
 *
 * This method is used to query CSC parameters of AippParam based on the {@link HiAI_AippParam} object during
 * dynamic AIPP inference.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param [out] inputFormat Image input format. For details, see {@link HiAI_ImageFormat}.
 * @param [out] outputFormat Image output format. For details, see {@link HiAI_ImageFormat}.
 * @param [out] space Image's color space type. For details, see {@link HiAI_ImageColorSpace}.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_GetCscConfig(HiAI_AippParam* aippParam, HiAI_ImageFormat* inputFormat,
    HiAI_ImageFormat* outputFormat, HiAI_ImageColorSpace* space);

/**
 * @brief Sets AIPP channel swapping parameters.
 *
 * This method is used to set the channel swapping parameters of AippParam in the {@link HiAI_AippParam} object
 * during dynamic AIPP inference. AIPP supports RB/UV channel swapping and AX channel swapping. RB/UV channel swapping
 * greatly enriches the input image formats. Once RB/UV channel swapping is enabled, input image formats supported by
 * AIPP are double of the configured input formats.
 * | Configured image formats   | Supported image formats
 * |YUV420SP_U8                 |YUV420SP_U8，YVU420 + rbuv_swap_switch
 * |XRGB8888_U8                 |XRGB8888_U8，XBGR + rbuv_swap_switch
 * |ARGB8888_U8                 |ARGB8888_U8，ABGR + rbuv_swap_switch
 * |RGB888_U8                   |BGR888_U8 + rbuv_swap_switch
 * |BGR888_U8                   |RGB888_U8 + rbuv_swap_switch
 * |YUYV_U8                     |YUYV_U8，YVYU_U8 + rbuv_swap_switch
 * |YUV422SP_U8                 |YUV422SP_U8，YVU422_U8 + rbuv_swap_switch
 * |AYUV444_U8                  |AYUV444_U8 + rbuv_swap_switch
 * YUV400_U8 is grayscale image, can't use channel swapping.
 *
 * AX channel swapping applies to XRGB, ARGB, and AYUV image inputs. AX channel swapping moves the input of the first
 * channel to the fourth channel. That is, with AX channel swapping enabled, XRGB, ARGB, and AYUV data are converted
 * into RGBX, RGBA, and YUVA data. When the model training set consists of RGB images and the image input for inference
 * is in XRGB or ARGB format, you can enable AX channel swapping to move the RGB channels forward for compatibility.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param rbuvSwapSwitch Flag indicating RB/UV channel swapping.
 * @param axSwapSwitch Flag indicating AX channel swapping.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_SetChannelSwapConfig(
    HiAI_AippParam* aippParam, bool rbuvSwapSwitch, bool axSwapSwitch);

/**
 * @brief Queries AIPP channel swapping parameters.
 *
 * This method is used to query channel swapping parameters based on the {@link HiAI_AippParam} object during
 * dynamic AIPP inference.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param [out] rbuvSwapSwitch Flag indicating RB/UV channel swapping.
 * @param [out] axSwapSwitch Flag indicating AX channel swapping.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_GetChannelSwapConfig(
    HiAI_AippParam* aippParam, bool* rbuvSwapSwitch, bool* axSwapSwitch);

/**
 * @brief Sets the SingleBatchMultiCrop flag of AIPP.
 *
 * This method is used to set the SingleBatchMultiCrop flag of AippParam in the {@link HiAI_AippParam} object
 * during dynamic AIPP inference.
 * In the scenario where a single batch of images are input, multiple groups of AIPP parameters such as crop can be
 * passed at a time. In this way, information about all key points such as the face can be obtained through one
 * inference.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param singleBatchMultiCrop Indicates whether the scenario is single-batch multi-crop.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_SetSingleBatchMultiCrop(
    HiAI_AippParam* aippParam, bool singleBatchMultiCrop);

/**
 * @brief Queries the SingleBatchMultiCrop flag of AIPP.
 *
 * This method is used to query whether the single-batch multi-crop scenario is used based on the {@link
 * HiAI_AippParam} object during dynamic AIPP inference.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null.
 * @return Returns true if the operation is successful; returns false otherwise.
 * @since 4.1.0(11)
 */
bool HMS_HiAIAippParam_GetSingleBatchMultiCrop(HiAI_AippParam* aippParam);

/**
 * @brief Sets AIPP cropping parameters.
 *
 * This method is used to set cropping parameters in the {@link HiAI_AippParam} object during dynamic AIPP
 * inference.
 * As restricted by the YUV image type, when the input image type is YUV420SP, YUYV, YUV422SP, or AYUV444, the
 * coordinates of the crop start and the width and height of the cropped out image must be even numbers.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param batchIndex Index of the input image in the multi-batch single-crop scenario or index of the cropped image
 * in the single-batch multi-crop scenario.
 * @param startPosW Horizontal coordinate of the crop start. The value of startPosW must be less than the width of
 * the input image.
 * @param startPosH Vertical coordinate of the crop start. The value of startPosH must be less than the height of
 * the input image.
 * @param croppedW Width of the cropped out image. The sum of startPosW and croppedW must be less than or equal
 * to the width of the input image.
 * @param croppedH Height of the cropped out image. The sum of startPosH and croppedH must be less than or equal
 * to the height of the input image.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_SetCropConfig(HiAI_AippParam* aippParam, uint32_t batchIndex,
    uint32_t startPosW, uint32_t startPosH, uint32_t croppedW, uint32_t croppedH);

/**
 * @brief Queries AIPP cropping parameters.
 *
 * This method is used to query cropping parameters with a specific index based on the {@link HiAI_AippParam}
 * object during dynamic AIPP inference.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param batchIndex Index of the input image in the multi-batch single-crop scenario or index of the cropped image
 * in the single-batch multi-crop scenario.
 * @param [out] startPosW Horizontal coordinate of the crop start.
 * @param [out] startPosH Vertical coordinate of the crop start.
 * @param [out] croppedW Width of the cropped out image.
 * @param [out] croppedH Height of the cropped out image.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_GetCropConfig(HiAI_AippParam* aippParam, uint32_t batchIndex,
    uint32_t* startPosW, uint32_t* startPosH, uint32_t* croppedW, uint32_t* croppedH);

/**
 * @brief Sets AIPP image resizing parameters.
 *
 * This method is used to set image resizing parameters in the {@link HiAI_AippParam} object during dynamic
 * AIPP inference. Images are resized using the linear interpolation method.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param batchIndex Index of the input image in the multi-batch single-crop scenario or index of the cropped image
 * in the single-batch multi-crop scenario.
 * @param resizedW Width of the resized image. The value range is [16, 448]. The range of the width resize
 * ratio is [1/16, 16].
 * @param resizedH Height of the resized image. The value range is [16, 4096]. The range of the height
 * resize ratio is [1/16, 16].
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_SetResizeConfig(
    HiAI_AippParam* aippParam, uint32_t batchIndex, uint32_t resizedW, uint32_t resizedH);

/**
 * @brief Queries AIPP image resizing parameters.
 *
 * This method is used to query the width and height of the resized image with a specific index based on the {@link
 * HiAI_AippParam} object during dynamic AIPP inference.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param batchIndex Index of the input image in the multi-batch single-crop scenario or index of the cropped image
 * in the single-batch multi-crop scenario.
 * @param [out] resizedW Width of the resized image.
 * @param [out] resizedH Height of the resized image.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_GetResizeConfig(
    HiAI_AippParam* aippParam, uint32_t batchIndex, uint32_t* resizedW, uint32_t* resizedH);

/**
 * @brief Sets the number of pixels padded to the input image by AIPP.
 *
 * This method is used to set the number of pixels padded to the input image in the {@link HiAI_AippParam}
 * object during dynamic AIPP inference. Pixels are padded to the left, right, top, and bottom of an image. Also call
 * {@link HMS_HiAIAippParam_SetPadChannelValue} if you want to set values padded to channels.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param batchIndex Index of the input image in the multi-batch single-crop scenario or index of the cropped image
 * in the single-batch multi-crop scenario.
 * @param leftPadSize Number of pixels padded on the left of the image. The width of the padded image must be the
 * same as that in the original model dimension.
 * @param rightPadSize Number of pixels padded on the right of the image. The width of the padded image must be the
 * same as that in the original model dimension.
 * @param topPadSize Number of pixels padded on the top of the image. The height of the padded image must be the
 * same as that in the original model dimension.
 * @param bottomPadSize Number of pixels padded on the bottom of the image. The height of the padded image must be
 * the same as that in the original model dimension.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_SetPadConfig(HiAI_AippParam* aippParam, uint32_t batchIndex,
    uint32_t leftPadSize, uint32_t rightPadSize, uint32_t topPadSize, uint32_t bottomPadSize);

/**
 * @brief Queries the number of pixels padded to the input image by AIPP.
 *
 * This method is used to query the number of pixels padded to an input image with a specific index based on the {@link
 * HiAI_AippParam} object during dynamic AIPP inference. Also call {@link
 * HMS_HiAIAippParam_GetChannelPadding} if you want to query values padded to channels.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param batchIndex Index of the input image in the multi-batch single-crop scenario or index of the cropped image
 * in the single-batch multi-crop scenario.
 * @param [out] leftPadSize Number of pixels padded on the left of the image.
 * @param [out] rightPadSize Number of pixels padded on the right of the image.
 * @param [out] topPadSize Number of pixels padded on the top of the image.
 * @param [out] bottomPadSize Number of pixels padded on the bottom of the image.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_GetPadConfig(HiAI_AippParam* aippParam, uint32_t batchIndex,
    uint32_t* leftPadSize, uint32_t* rightPadSize, uint32_t* topPadSize, uint32_t* bottomPadSize);

/**
 * @brief Sets the padding value for a channel during AIPP.
 *
 * This method is used to set the padding value for a channel in the {@link HiAI_AippParam} object during
 * dynamic AIPP inference.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param batchIndex Index of the input image in the multi-batch single-crop scenario or index of the cropped image
 * in the single-batch multi-crop scenario.
 * @param paddingValues Arrays of channel padding value. The value range is [-65504, 65504]. The default value is
 * 0.
 * @param channelCount Number of channels to be padded. The value range is [1, 4]. For example, if channelCount is
 * set to 3, channels chn0, chn1, and chn2 will be configured.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_SetChannelPadding(
    HiAI_AippParam* aippParam, uint32_t batchIndex, uint32_t paddingValues[], uint32_t channelCount);

/**
 * @brief Queries the padding value for a channel during AIPP.
 *
 * This method is used to query the padding value of a channel with a specific index based on the {@link
 * HiAI_AippParam} object during dynamic AIPP inference.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param batchIndex Index of the input image in the multi-batch single-crop scenario or index of the cropped image
 * in the single-batch multi-crop scenario.
 * @param [out] paddingValues Arrays of channel padding value. The value range is [-65504, 65504]. The default value is
 * 0.
 * @param channelCount Number of channels to be padded. The value range is [1, 4]. For example, if channelCount is
 * set to 3, channels chn0, chn1, and chn2 will be queried.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_GetChannelPadding(
    HiAI_AippParam* aippParam, uint32_t batchIndex, uint32_t paddingValues[], uint32_t channelCount);

/**
 * @brief Sets the rotation angle in AIPP.
 *
 * This method is used to set the rotation angle in the {@link HiAI_AippParam} object during dynamic AIPP
 * inference.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param batchIndex Index of the input image in the multi-batch single-crop scenario or index of the cropped image
 * in the single-batch multi-crop scenario.
 * @param rotationAngle Rotation angle. The value can only be 0, 90, 180, or 270.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_SetRotationAngle(
    HiAI_AippParam* aippParam, uint32_t batchIndex, float rotationAngle);

/**
 * @brief Queries the image rotation angle in AIPP.
 *
 * This method is used to query the rotation angle of an image with a specific index based on the {@link
 * HiAI_AippParam} object during dynamic AIPP inference.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null.
 * @param batchIndex Index of the input image in the multi-batch single-crop scenario or index of the cropped image
 * in the single-batch multi-crop scenario.
 * @param [out] rotationAngle Rotation angle.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_GetRotationAngle(
    HiAI_AippParam* aippParam, uint32_t batchIndex, float* rotationAngle);

/**
 * @brief Sets the average pixel value of DTC.
 *
 * Data type conversion (DTC) is to convert pixel values of input images into data types used for model training. DTC
 * parameters allow the converted data to fall within the expected range, which avoids forcible conversion. DTC is used
 * to convert the input image type to the FP16 format using a conversion formula, and send the converted result to
 * subsequent modules for further calculation. During the conversion, mean subtraction, minimum value subtraction, and
 * multiplying the variance are performed in sequence.
 *
 * Calculation formula: U8->FP16:
 * pixelOutChn(i) = [pixelInChn(i)–meanChn(i)–minChn(i)] * varReciChn(i), i ∈ [0, 4)
 * In the formula, pixelOutChn(i) indicates the output value of each channel of the DTC module, pixelInChn(i)
 * indicates the input value of each channel of the DTC module, and meanChn(i) indicates the average input value of
 * each channel. minChn(i) indicates the minimum input value of each channel, and varReciChn(i) indicates the input
 * variance of each channel.
 *
 * This method is used to set the average pixel value of DTC in the {@link HiAI_AippParam} object during
 * dynamic AIPP inference. This method must be used together with {@link HMS_HiAIAippParam_SetDtcMinPixel} and
 * {@link HMS_HiAIAippParam_SetDtcVarReciPixel}.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param batchIndex Index of the input image in the multi-batch single-crop scenario or index of the cropped image
 * in the single-batch multi-crop scenario.
 * @param meanPixel Array of the average pixel values of channels. The array size is channelCount. The default
 * value is 0.
 * @param channelCount Number of channels. The value range is [1, 4]. For example, if channelCount is set to 3,
 * channels chn0, chn1, and chn2 will be configured.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_SetDtcMeanPixel(
    HiAI_AippParam* aippParam, uint32_t batchIndex, uint32_t meanPixel[], uint32_t channelCount);

/**
 * @brief Queries the average pixel value of DTC.
 *
 * This method is used to query the average pixel value of the data type with a specific index during DTC, based on the
 * {@link HiAI_AippParam} object for dynamic AIPP inference. This method must be used together with {@link
 * HMS_HiAIAippParam_GetDtcMinPixel} and {@link HMS_HiAIAippParam_GetDtcVarReciPixel}, to obtain
 * conversion parameters for all data types.
 *
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param batchIndex Index of the input image in the multi-batch single-crop scenario or index of the cropped image
 * in the single-batch multi-crop scenario.
 * @param [out] meanPixel Array of the average pixel values of channels. The array size is channelCount.
 * @param channelCount Number of channels. The value range is [1, 4], and the channel starts from chn0. For
 * example, if channelCount is 3, the data of channels chn0, chn1, and chn2 will be queried.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_GetDtcMeanPixel(
    HiAI_AippParam* aippParam, uint32_t batchIndex, uint32_t meanPixel[], uint32_t channelCount);

/**
 * @brief Sets the minimum pixel value of DTC.
 *
 * This method is used to set the minimum pixel value of DTC in the {@link HiAI_AippParam} object during
 * dynamic AIPP inference.
 * This method must be used together with {@link HMS_HiAIAippParam_SetDtcMeanPixel} and
 * {@link HMS_HiAIAippParam_SetDtcVarReciPixel}.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param batchIndex Index of the input image in the multi-batch single-crop scenario or index of the cropped image
 * in the single-batch multi-crop scenario.
 * @param minPixel Array of the minimum pixel values of channels. The array size is channelCount. The default value
 * is 0.
 * @param channelCount Number of channels. The value range is [1, 4]. For example, if channelCount is set to 3,
 * channels chn0, chn1, and chn2 will be configured.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_SetDtcMinPixel(
    HiAI_AippParam* aippParam, uint32_t batchIndex, float minPixel[], uint32_t channelCount);

/**
 * @brief Queries the minimum pixel value of DTC.
 *
 * This method is used to query the minimum pixel value of the data type with a specific index during DTC, based on the
 * {@link HiAI_AippParam} object for dynamic AIPP inference.
 * This method must be used together with {@link HMS_HiAIAippParam_GetDtcMeanPixel} and
 * {@link HMS_HiAIAippParam_GetDtcVarReciPixel}, to obtain conversion parameters for all data types.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param batchIndex Index of the input image in the multi-batch single-crop scenario or index of the cropped image
 * in the single-batch multi-crop scenario.
 * @param [out] minPixel Array of the minimum pixel values of channels. The array size is channelCount.
 * @param channelCount Number of channels. The value range is [1,4], and the channel starts from chn0. For example,
 * if channelCount is 3, the data of channels chn0, chn1, and chn2 will be queried.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_GetDtcMinPixel(
    HiAI_AippParam* aippParam, uint32_t batchIndex, float minPixel[], uint32_t channelCount);

/**
 * @brief Sets the pixel variance of DTC.
 *
 * This method is used to set the pixel variance of DTC in the {@link HiAI_AippParam} object during dynamic
 * AIPP inference.
 * This method must be used together with {@link HMS_HiAIAippParam_SetDtcMeanPixel} and
 * {@link HMS_HiAIAippParam_SetDtcMinPixel}.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param batchIndex Index of the input image in the multi-batch single-crop scenario or index of the cropped image
 * in the single-batch multi-crop scenario.
 * @param varReciPixel Array of pixel variances of channels. The array size is channelCount. The default value
 * is 1.0.
 * @param channelCount Number of channels. The value range is [1, 4]. For example, if channelCount is set to 3,
 * channels chn0, chn1, and chn2 will be configured.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_SetDtcVarReciPixel(
    HiAI_AippParam* aippParam, uint32_t batchIndex, float varReciPixel[], uint32_t channelCount);

/**
 * @brief Queries the pixel variance of DTC.
 *
 * This method is used to query the pixel variance of the data type with a specific index during DTC, based on the
 * {@link HiAI_AippParam} object for dynamic AIPP inference.
 * This method must be used together with {@link HMS_HiAIAippParam_GetDtcMeanPixel} and
 * {@link HMS_HiAIAippParam_GetDtcMinPixel}, to obtain conversion parameters for all data types.
 *
 * @param aippParam Pointer to {@link HiAI_AippParam}. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param batchIndex Index of the input image in the multi-batch single-crop scenario or index of the cropped image
 * in the single-batch multi-crop scenario.
 * @param [out] varReciPixel Array of pixel variances of channels. The array size is channelCount.
 * @param channelCount Number of channels. The value range is [1, 4], and the channel starts from chn0. For
 * example, if channelCount is 3, the data of channels chn0, chn1, and chn2 will be queried.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIAippParam_GetDtcVarReciPixel(
    HiAI_AippParam* aippParam, uint32_t batchIndex, float varReciPixel[], uint32_t channelCount);

#ifdef __cplusplus
}
#endif
/** @} */
#endif // HIAI_FOUNDATION_AIPP_PARAM_H
