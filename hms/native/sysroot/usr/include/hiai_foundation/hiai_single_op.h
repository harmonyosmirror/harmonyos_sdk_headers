/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

/**
 * @addtogroup HiAIFoundation
 * @{
 *
 * @brief Provides APIs for HiAI Foundation model inference.
 *
 * @syscap SystemCapability.AI.HiAIFoundation
 * @since 5.0.0(12)
 */

/**
 * @file hiai_single_op.h
 * @kit HiAIFoundationKit
 * @library libhiai_foundation.so
 *
 * @brief Defines the single-operator APIs of HiAI Foundation, which is used for creating and calculating single
 * operators, and managing tensors and buffers.
 *
 * @since 5.0.0(12)
 */

#ifndef HIAI_FOUNDATION_SINGLE_OP_H
#define HIAI_FOUNDATION_SINGLE_OP_H
#include <stdbool.h>

#include "neural_network_runtime/neural_network_runtime_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines the single op tensor data type enums.
 * @since 5.0.0(12)
 */
typedef enum {
    /** float. */
    HIAI_SINGLEOP_DT_FLOAT = 0,
    /** float16. */
    HIAI_SINGLEOP_DT_FLOAT16 = 1,
    /** Undefined. */
    HIAI_SINGLEOP_DT_UNDEFINED = 17
} HiAI_SingleOpDataType;

/**
 * @brief Defines the single op tensor formats.
 * @since 5.0.0(12)
 */
typedef enum {
    /** NCHW format. */
    HIAI_SINGLEOP_FORMAT_NCHW = 0,
    /** NHWC format. */
    HIAI_SINGLEOP_FORMAT_NHWC = 1,
    /** ND format. Single op tensors in ND format layout are not currently supported. */
    HIAI_SINGLEOP_FORMAT_ND = 2,
    /** NC1HWC0 format. */
    HIAI_SINGLEOP_FORMAT_NC1HWC0 = 3,
    /** NC4HW4 format. */
    HIAI_SINGLEOP_FORMAT_NC4HW4 = 28,
    /** NC8HW8 format. */
    HIAI_SINGLEOP_FORMAT_NC8HW8 = 31,
    /** Undefined format. */
    HIAI_SINGLEOP_FORMAT_RESERVED = 255
} HiAI_SingleOpFormat;

/**
 * @brief Single op tensor description handle.
 * @since 5.0.0(12)
 */
typedef struct HiAI_SingleOpTensorDesc HiAI_SingleOpTensorDesc;

/**
 * @brief Creates a {@link HiAI_SingleOpTensorDesc} object.
 *
 * This method is used to create a {@link HiAI_SingleOpTensorDesc} object according to the input parameters like
 * dimensions, data type and format.
 *
 * You can call the following APIs to create a {@link HiAI_SingleOpTensor} object based on the pointer to
 * {@link HiAI_SingleOpTensorDesc}: {@link HMS_HiAISingleOpTensor_CreateFromTensorDesc},
 * {@link HMS_HiAISingleOpTensor_CreateFromSingleOpBuffer}, {@link HMS_HiAISingleOpTensor_CreateFromConst}.
 *
 * Note: These APIs copy the {@link HiAI_SingleOpTensorDesc} object to {@link HiAI_SingleOpTensor}. If the
 * {@link HiAI_SingleOpTensorDesc} object is no longer used, call {@link HMS_HiAISingleOpTensorDesc_Destroy} to destroy
 * it. Otherwise, a memory leak may occur.
 *
 * @param dims Tensor dimension list. The value cannot be a null pointer. Otherwise, a null pointer is returned.
 * @param dimNum Number of tensor dimensions. The value cannot be 0. Otherwise, a null pointer is returned.
 * @param dataType Tensor data type.
 * @param format Tensor format.
 * @param isVirtual Indicates whether a tensor is a virtual tensor. <b>true</b> represents the tensor is a virtual
 * tensor, and <b>false</b> represents the tensor is a non-virtual tensor. A virtual tensor is an intermediate tensor
 * between connected single operators of HiAI Foundation. Data in virtual tensors exists only temporarily. Virtual
 * tensors are only read or written by single operators of HiAI Foundation. For example, if the output tensor T1 of
 * operator A is used only as the input tensor of operator B, and you only read the output tensor T2 of operator B,
 * without reading or writing T1, then T1 will be a virtual tensor, and T2 will be a non-virtual tensor.
 * @return Returns the pointer to {@link HiAI_SingleOpTensorDesc} if the operation is successful; returns a null
 * pointer otherwise.
 * @since 5.0.0(12)
 */
HiAI_SingleOpTensorDesc* HMS_HiAISingleOpTensorDesc_Create(const int64_t* dims, size_t dimNum,
    HiAI_SingleOpDataType dataType, HiAI_SingleOpFormat format, bool isVirtual);

/**
 * @brief Queries the number of dimensions of the {@link HiAI_SingleOpTensorDesc} object.
 *
 * This method is used to obtain the number of dimensions of a specific {@link HiAI_SingleOpTensorDesc} object.
 *
 * @param tensorDesc Pointer to the {@link HiAI_SingleOpTensorDesc} object. The value cannot be a null pointer.
 * Otherwise, 0 is returned.
 * @return Number of dimensions of the tensor. If the execution fails, 0 is returned.
 * @since 5.0.0(12)
 */
size_t HMS_HiAISingleOpTensorDesc_GetDimensionCount(const HiAI_SingleOpTensorDesc* tensorDesc);

/**
 * @brief Queries the length of a dimension with a specific index of the {@link HiAI_SingleOpTensorDesc} object.
 *
 * This method is used to obtain the length of a specific dimension of a specific {@link HiAI_SingleOpTensorDesc}
 * object.
 *
 * @param tensorDesc Pointer to the {@link HiAI_SingleOpTensorDesc} object. The value cannot be a null pointer.
 * Otherwise, 0 is returned.
 * @param index Index of a dimension. The index starts from 0.
 * @return Length of the dimension whose index is <b>index</b>. If the execution fails, 0 is returned.
 * @since 5.0.0(12)
 */
int64_t HMS_HiAISingleOpTensorDesc_GetDimension(const HiAI_SingleOpTensorDesc* tensorDesc, size_t index);

/**
 * @brief Queries the data type of the {@link HiAI_SingleOpTensorDesc} object.
 *
 * This method is used to obtain the data type of a specific {@link HiAI_SingleOpTensorDesc} object.
 *
 * @param tensorDesc Pointer to the {@link HiAI_SingleOpTensorDesc} object. The value cannot be a null pointer.
 * Otherwise, <b>HIAI_SINGLEOP_DT_UNDEFINED</b> is returned.
 * @return Data type of the tensor.
 * @since 5.0.0(12)
 */
HiAI_SingleOpDataType HMS_HiAISingleOpTensorDesc_GetDataType(const HiAI_SingleOpTensorDesc* tensorDesc);

/**
 * @brief Queries format of the {@link HiAI_SingleOpTensorDesc} object.
 *
 * This method is used to obtain the format of a specific {@link HiAI_SingleOpTensorDesc} object.
 *
 * @param tensorDesc Pointer to the {@link HiAI_SingleOpTensorDesc} object. The value cannot be a null pointer.
 * Otherwise, <b>HIAI_SINGLEOP_FORMAT_RESERVED</b> is returned.
 * @return Tensor format.
 * @since 5.0.0(12)
 */
HiAI_SingleOpFormat HMS_HiAISingleOpTensorDesc_GetFormat(const HiAI_SingleOpTensorDesc* tensorDesc);

/**
 * @brief Queries whether {@link HiAI_SingleOpTensorDesc} describes a virtual tensor.
 *
 * A virtual tensor is an intermediate tensor between connected single operators of HiAI Foundation. Data in virtual
 * tensors exists only temporarily. Virtual tensors are only read or written by single operators of HiAI Foundation.
 * For example, if the output tensor T1 of operator A is used only as the input tensor of operator B, and you only read
 * the output tensor T2 of operator B, without reading or writing T1, then T1 will be a virtual tensor, and T2 will be
 * a non-virtual tensor.
 *
 * @param tensorDesc Pointer to the {@link HiAI_SingleOpTensorDesc} object. The value cannot be a null pointer.
 * Otherwise, false is returned.
 * @return Returns true if the tensor is a virtual tensor; returns false otherwise.
 * @since 5.0.0(12)
 */
bool HMS_HiAISingleOpTensorDesc_IsVirtual(const HiAI_SingleOpTensorDesc* tensorDesc);

/**
 * @brief Queries the number of bytes occupied by the data calculated based on the dimension and data type of
 * {@link HiAI_SingleOpTensorDesc}.
 *
 * This method is used to obtain the number of bytes occupied by the data calculated based on the dimension and data
 * type of {@link HiAI_SingleOpTensorDesc}.
 *
 * @param tensorDesc Pointer to the {@link HiAI_SingleOpTensorDesc} object. The value cannot be a null pointer.
 * Otherwise, 0 is returned.
 * @return Number of data bytes of the tensor.
 * @since 5.0.0(12)
 */
size_t HMS_HiAISingleOpTensorDesc_GetByteSize(const HiAI_SingleOpTensorDesc* tensorDesc);

/**
 * @brief Releases a {@link HiAI_SingleOpTensorDesc} object.
 *
 * This method is used to release the {@link HiAI_SingleOpTensorDesc} object created by calling
 * {@link HMS_HiAISingleOpTensorDesc_Create}.
 *
 * @param tensorDesc Double pointer to the {@link HiAI_SingleOpTensorDesc} object. <b>tensorDesc</b> and
 * <b>*tensorDesc</b> cannot be null pointers.
 * @since 5.0.0(12)
 */
void HMS_HiAISingleOpTensorDesc_Destroy(HiAI_SingleOpTensorDesc** tensorDesc);

/**
 * @brief Single op buffer handle.
 * @since 5.0.0(12)
 */
typedef struct HiAI_SingleOpBuffer HiAI_SingleOpBuffer;

/**
 * @brief Creates a {@link HiAI_SingleOpBuffer} object based on the specific memory size.
 *
 * This method is used to apply for ION memory based on the specified <b>dataSize</b> and create a
 * {@link HiAI_SingleOpBuffer} object. When you no longer use {@link HiAI_SingleOpBuffer}, call
 * {@link HMS_HiAISingleOpBuffer_Destroy} to destroy it. Otherwise, a memory leak may occur.
 *
 * @param dataSize Size of the memory to be applied for, in bytes. The value cannot be 0. Otherwise, a null pointer is
 * returned.
 * @return Returns the pointer to {@link HiAI_SingleOpBuffer} if the operation is successful; returns a null pointer
 * otherwise.
 * @since 5.0.0(12)
 */
HiAI_SingleOpBuffer* HMS_HiAISingleOpBuffer_Create(size_t dataSize);

/**
 * @brief Queries the byte size of {@link HiAI_SingleOpBuffer}.
 *
 * This method is used to obtain the byte size of the specific {@link HiAI_SingleOpBuffer} object.
 *
 * @param buffer Pointer to the {@link HiAI_SingleOpBuffer} object. The value cannot be a null pointer. Otherwise,
 * 0 is returned.
 * @return Size of the buffer, in bytes.
 * @since 5.0.0(12)
 */
size_t HMS_HiAISingleOpBuffer_GetSize(const HiAI_SingleOpBuffer* buffer);

/**
 * @brief Queries the memory address of {@link HiAI_SingleOpBuffer}.
 *
 * This method is used to obtain the memory address of the specific {@link HiAI_SingleOpBuffer} object.
 *
 * @param buffer Pointer to the {@link HiAI_SingleOpBuffer} object. The value cannot be a null pointer. Otherwise, a
 * null pointer is returned.
 * @return Memory address of the buffer.
 * @since 5.0.0(12)
 */
void* HMS_HiAISingleOpBuffer_GetData(const HiAI_SingleOpBuffer* buffer);

/**
 * @brief Releases a {@link HiAI_SingleOpBuffer} object.
 *
 * This method is used to release the {@link HiAI_SingleOpBuffer} object created by calling
 * {@link HMS_HiAISingleOpBuffer_Create}.
 *
 * @param buffer Double pointer to the {@link HiAI_SingleOpBuffer} object. <b>buffer</b> and <b>*buffer</b> cannot be
 * null pointers. Otherwise, an error code is returned.
 * @return Function execution result. If the operation is successful, OH_NN_SUCCESS is returned. If the operation
 * fails, an error code is returned. For details about the error codes, please refer to {@link OH_NN_ReturnCode}.
 * @since 5.0.0(12)
 */
OH_NN_ReturnCode HMS_HiAISingleOpBuffer_Destroy(HiAI_SingleOpBuffer** buffer);

/**
 * @brief Single op tensor handle.
 * @since 5.0.0(12)
 */
typedef struct HiAI_SingleOpTensor HiAI_SingleOpTensor;

/**
 * @brief Creates a {@link HiAI_SingleOpTensor} object based on {@link HiAI_SingleOpTensorDesc}.
 *
 * This method is used to create a {@link HiAI_SingleOpTensor} object based on {@link HiAI_SingleOpTensorDesc}.
 *
 * This method uses {@link HMS_HiAISingleOpTensorDesc_GetByteSize} to calculate the number of bytes of tensor data, and
 * uses {@link HMS_HiAISingleOpBuffer_Create} to allocate ION memory for tensor data. The device driver directly
 * obtains tensor data in zero-copy mode.
 *
 * Note: This API copies <b>desc</b> into {@link HiAI_SingleOpTensor}. Therefore, when you no longer use <b>desc</b>,
 * destroy <b>desc</b> using {@link HMS_HiAISingleOpTensorDesc_Destroy}.
 *
 * When you no longer use the {@link HiAI_SingleOpTensor} object, destroy it by calling
 * {@link HMS_HiAISingleOpTensor_Destroy}. Otherwise, a memory leak may occur.
 *
 * @param desc Pointer to the {@link HiAI_SingleOpTensorDesc} object. The value cannot be a null pointer. Otherwise, a
 * null pointer is returned.
 * @return Returns the pointer to {@link HiAI_SingleOpTensor} if the operation is successful; returns a null pointer
 * otherwise.
 * @since 5.0.0(12)
 */
HiAI_SingleOpTensor* HMS_HiAISingleOpTensor_CreateFromTensorDesc(const HiAI_SingleOpTensorDesc* desc);

/**
 * @brief Creates a {@link HiAI_SingleOpTensor} object based on {@link HiAI_SingleOpTensorDesc}, the memory address
 * from {@link HiAI_SingleOpBuffer} and data size.
 *
 * This method reuses the ION memory from a spefific {@link HiAI_SingleOpBuffer}. The memory address and size are
 * determined by <b>data</b> and <b>dataSize</b>. The value of <b>dataSize</b> must be equal to the byte size of
 * <b>desc</b> calculated by calling {@link HMS_HiAISingleOpTensorDesc_GetByteSize}. When you call
 * {@link HMS_HiAISingleOpTensor_Destroy} to destroy the tensor created by the API, the tensor data memory will not be
 * released.
 *
 * Note: This API copies <b>desc</b> into {@link HiAI_SingleOpTensor}. Therefore, when you no longer use <b>desc</b>,
 * you need destroy <b>desc</b> using {@link HMS_HiAISingleOpTensorDesc_Destroy}.
 *
 * When you no longer use the {@link HiAI_SingleOpTensor} object, destroy it by calling
 * {@link HMS_HiAISingleOpTensor_Destroy}. Otherwise, a memory leak may occur.
 *
 * @param desc Pointer to the {@link HiAI_SingleOpTensorDesc} object. The value cannot be a null pointer. Otherwise,
 * a null pointer is returned.
 * @param data Tensor data address. The value must be a memory address from {@link HiAI_SingleOpBuffer}. Otherwise,
 * a null pointer is returned.
 * @param dataSize Tensor data size. The value cannot be 0. Otherwise, a null pointer is returned.
 * @return Returns the pointer to {@link HiAI_SingleOpTensor} if the operation is successful; returns a null pointer
 * otherwise.
 * @since 5.0.0(12)
 */
HiAI_SingleOpTensor* HMS_HiAISingleOpTensor_CreateFromSingleOpBuffer(const HiAI_SingleOpTensorDesc* desc,
    void* data, size_t dataSize);

/**
 * @brief Creates a {@link HiAI_SingleOpTensor} object based on {@link HiAI_SingleOpTensorDesc}, the memory address and
 * the size of constant data (such as the convolution weight and bias).
 *
 * This method directly reuses the constant data corresponding to <b>data</b> and <b>dataSize</b>, without copying
 * data. Therefore, do not release the constant data memory of the tensor if the tensor created by this method is still
 * in use. This method only reads the constant data corresponding to <b>data</b> and <b>dataSize</b> and does not
 * modify the data.
 *
 * Note: This API copies <b>desc</b> into {@link HiAI_SingleOpTensor}. Therefore, when you no longer use <b>desc</b>,
 * you need destroy <b>desc</b> using {@link HMS_HiAISingleOpTensorDesc_Destroy}.
 *
 * When you no longer use the {@link HiAI_SingleOpTensor} object, destroy it by calling
 * {@link HMS_HiAISingleOpTensor_Destroy}. Otherwise, a memory leak may occur.
 *
 * @param desc Pointer to the {@link HiAI_SingleOpTensorDesc} object. The value cannot be a null pointer. Otherwise, a
 * null pointer is returned.
 * @param data Constant data address. The value cannot be a null pointer. Otherwise, a null pointer is returned.
 * @param dataSize Constant data size. The value cannot be 0. Otherwise, a null pointer is returned.
 * @return Returns the pointer to {@link HiAI_SingleOpTensor} if the operation is successful; returns a null pointer
 * otherwise.
 * @since 5.0.0(12)
 */
HiAI_SingleOpTensor* HMS_HiAISingleOpTensor_CreateFromConst(const HiAI_SingleOpTensorDesc* desc, void* data,
    size_t dataSize);

/**
 * @brief Obtains the tensor description of {@link HiAI_SingleOpTensor}.
 *
 * This method is used to obtain the {@link HiAI_SingleOpTensorDesc} of the specific {@link HiAI_SingleOpTensor}
 * object.
 *
 * @param tensor Pointer to the {@link HiAI_SingleOpTensor} object. The value cannot be a null pointer. Otherwise, a
 * null pointer is returned.
 * @return Returns the pointer to the {@link HiAI_SingleOpTensorDesc} object.
 * @since 5.0.0(12)
 */
HiAI_SingleOpTensorDesc* HMS_HiAISingleOpTensor_GetTensorDesc(const HiAI_SingleOpTensor* tensor);

/**
 * @brief Obtains the buffer of {@link HiAI_SingleOpTensor}.
 *
 * This method is used to obtain the {@link HiAI_SingleOpBuffer} of the specific {@link HiAI_SingleOpTensor} object.
 *
 * @param tensor Pointer to the {@link HiAI_SingleOpTensor} object. The value cannot be a null pointer. Otherwise, a
 * null pointer is returned.
 * @return Returns the pointer to the {@link HiAI_SingleOpBuffer} object.
 * @since 5.0.0(12)
 */
HiAI_SingleOpBuffer* HMS_HiAISingleOpTensor_GetBuffer(const HiAI_SingleOpTensor* tensor);

/**
 * @brief Releases a {@link HiAI_SingleOpTensor} object.
 *
 * When you no longer use the {@link HiAI_SingleOpTensor} object, call this API to destroy the object. Otherwise, a
 * memory leak may occur.
 *
 * @param tensor Double pointer to the {@link HiAI_SingleOpTensor} object. <b>tensor</b> and <b>*tensor</b> cannot be
 * null pointers. Otherwise, an error code is returned.
 * @return Function execution result. If the operation is successful, OH_NN_SUCCESS is returned. If the operation
 * fails, an error code is returned. For details about the error codes, please refer to {@link OH_NN_ReturnCode}.
 * @since 5.0.0(12)
 */
OH_NN_ReturnCode HMS_HiAISingleOpTensor_Destroy(HiAI_SingleOpTensor** tensor);

/**
 * @brief Single op option handle.
 * @since 5.0.0(12)
 */
typedef struct HiAI_SingleOpOptions HiAI_SingleOpOptions;

/**
 * @brief Creates a {@link HiAI_SingleOpOptions} object.
 *
 * When you no longer use the {@link HiAI_SingleOpOptions} object, destroy it by calling
 * {@link HMS_HiAISingleOpOptions_Destroy}. Otherwise, a memory leak may occur.
 *
 * @return Returns the pointer to {@link HiAI_SingleOpOptions} if the operation is successful; returns a null pointer
 * otherwise.
 * @since 5.0.0(12)
 */
HiAI_SingleOpOptions* HMS_HiAISingleOpOptions_Create(void);

/**
 * @brief Releases a {@link HiAI_SingleOpOptions} object.
 *
 * This method is used to release the {@link HiAI_SingleOpOptions} object created by calling
 * {@link HMS_HiAISingleOpOptions_Create}.
 *
 * @param options Double pointer to the {@link HiAI_SingleOpOptions} object. <b>options</b> and <b>*options</b> cannot
 * be null pointers, otherwise the destroying fails.
 * @since 5.0.0(12)
 */
void HMS_HiAISingleOpOptions_Destroy(HiAI_SingleOpOptions** options);

/**
 * @brief Defines the single op convolution mode enums.
 * @since 5.0.0(12)
 */
typedef enum {
    /** Common convolution. */
    HIAI_SINGLEOP_CONV_MODE_COMMON = 0,
    /** Transposed convolution. */
    HIAI_SINGLEOP_CONV_MODE_TRANSPOSED = 1,
    /** Depthwise convolution. */
    HIAI_SINGLEOP_CONV_MODE_DEPTHWISE = 2
} HiAI_SingleOpConvMode;

/**
 * @brief Defines the single op padding mode enums.
 * @since 5.0.0(12)
 */
typedef enum {
    /** If no padding algorithm is set, padding settings specified by parameter <b>pads</b> will apply. */
    HIAI_SINGLEOP_PAD_MODE_SPECIFIC = 0,
    /**
    * Pads the input so that the output dimensions are the same as the input dimensions. The output dimensions are
    * determined by ceil(input dimensions/strides).
    */
    HIAI_SINGLEOP_PAD_MODE_SAME = 1,
    /**
    * SAME_UPPER padding mode. In this mode, when the padding length is an odd number, the beginning padding length
    * is less than or equal to the end padding length.
    */
    HIAI_SINGLEOP_PAD_MODE_SAME_UPPER = 2,
    /**
    * SAME_LOWER padding mode. In this mode, when the padding length is an odd number, the beginning padding length
    * is greater than or equal to the end padding length.
    */
    HIAI_SINGLEOP_PAD_MODE_SAME_LOWER = 3,
    /**
    * No padding is performed. The output dimensions are determined by
    * ceil((input dimensions – filter dimensions + 1)/strides).
    */
    HIAI_SINGLEOP_PAD_MODE_VALID = 4
} HiAI_SingleOpPadMode;

/**
 * @brief Single op operation description handle.
 * @since 5.0.0(12)
 */
typedef struct HiAI_SingleOpDescriptor HiAI_SingleOpDescriptor;

/**
 * @brief HiAISingleOpDescriptor_CreateConvolution input parameters.
 * @since 5.0.0(12)
 */
typedef struct HiAISingleOpDescriptor_ConvolutionParam {
    /** Convolution mode.*/
    HiAI_SingleOpConvMode convMode;
    /**
    * Strides of the convolution kernel in terms of height and width. It is an int array [strideHeight, strideWidth]
    * with length of 2.
    */
    int64_t strides[2];
    /**
    * Dilation rates of the convolution kernel in terms of height and width. It is an int array
    * [dilationHeight, dilationWidth] with length of 2.
    */
    int64_t dilations[2];
    /**
    * Padding length of the begin and end of each axis. It is an int array [h_begin, h_end, w_begin, w_end] with
    * length of 4. The value is valid only when <b>padMode</b> is set to <b>HIAI_SINGLEOP_PAD_MODE_SPECIFIC</b>.
    */
    int64_t pads[4];
    /**
    * Number of groups into which the input channels is divided. If <b>convMode</b> is set to
    * <b>HIAI_SINGLEOP_CONV_MODE_DEPTHWISE</b>, <b>groups</b> does not take effect.
    */
    int64_t groups;
    /**
    * Input padding mode. For <b>HIAI_SINGLEOP_CONV_MODE_COMMON</b> and <b>HIAI_SINGLEOP_CONV_MODE_DEPTHWISE</b>,
    * the value can be <b>0</b> (SPECIFIC), <b>1</b> (SAME), <b>2</b> (SAME_UPPER), <b>3</b> (SAME_LOWER),
    * or <b>4</b> (VALID). For <b>HIAI_SINGLEOP_CONV_MODE_TRANSPOSED</b>, the value can be <b>0</b> (SPECIFIC),
    * <b>1</b> (SAME), or <b>4</b> (VALID).
    */
    HiAI_SingleOpPadMode padMode;
} HiAISingleOpDescriptor_ConvolutionParam;

/**
 * @brief Creates a descriptor object of a convolution class (common convolution, transposed convolution, and depthwise
 * convolution).
 *
 * This method is used to create a {@link HiAI_SingleOpDescriptor} object of the convolution class according to the
 * input parameters. When you no longer use {@link HiAI_SingleOpDescriptor}, call
 * {@link HMS_HiAISingleOpDescriptor_Destroy} to destroy it. Otherwise, a memory leak may occur.
 *
 * @param param Refer to {@link HiAISingleOpDescriptor_ConvolutionParam} for details of the input
 * parameters.
 * @return Returns the pointer to {@link HiAI_SingleOpDescriptor} if the operation is successful; returns a null
 * pointer otherwise.
 * @since 5.0.0(12)
 */
HiAI_SingleOpDescriptor* HMS_HiAISingleOpDescriptor_CreateConvolution(
    HiAISingleOpDescriptor_ConvolutionParam param);

/**
 * @brief Defines the single op activation mode enums.
 * @since 5.0.0(12)
 */
typedef enum {
    /** ReLU. */
    HIAI_SINGLEOP_ACTIVATION_TYPE_RELU = 0,
    /** ReLU6. */
    HIAI_SINGLEOP_ACTIVATION_TYPE_RELU6 = 1
} HiAI_SingleOpActivationType;

/**
 * @brief Creates a descriptor object of the activation function class.
 *
 * This method is used to create a {@link HiAI_SingleOpDescriptor} object of the activation function class according
 * to the input parameters. When you no longer use {@link HiAI_SingleOpDescriptor}, call
 * {@link HMS_HiAISingleOpDescriptor_Destroy} to destroy it. Otherwise, a memory leak may occur.
 *
 * @param activationType Activation mode.
 * @param coef If the activation comes with a coefficient, the value indicates the coefficient. Otherwise, the value
 * does not take effect.
 * @return Returns the pointer to {@link HiAI_SingleOpDescriptor} if the operation is successful; returns a null
 * pointer otherwise.
 * @since 5.0.0(12)
 */
HiAI_SingleOpDescriptor* HMS_HiAISingleOpDescriptor_CreateActivation(
    HiAI_SingleOpActivationType activationType, float coef);

/**
 * @brief Releases a {@link HiAI_SingleOpDescriptor} object.
 *
 * When you no longer use the {@link HiAI_SingleOpDescriptor} object, destroy it by calling the API. Otherwise, a
 * memory leak may occur.
 *
 * @param opDesc Double pointer to the {@link HiAI_SingleOpDescriptor} object. <b>opDesc</b> and <b>*opDesc</b> cannot
 * be null pointers, otherwise the destroying fails.
 * @since 5.0.0(12)
 */
void HMS_HiAISingleOpDescriptor_Destroy(HiAI_SingleOpDescriptor** opDesc);

/**
 * @brief Defines the single op support status enums.
 * @since 5.0.0(12)
 */
typedef enum {
    /**
    * Performance optimized. It is recommended for user to use single op executor to perform
    * single-operator inference computations.
    */
    HIAI_SINGLEOP_OPTIMIZED = 0,
    /** Common performance. This single op executor is supported but it may yield small performance gains. */
    HIAI_SINGLEOP_COMMON = 1,
    /** Not supported. If users create this single op executor, it will fail. */
    HIAI_SINGLEOP_UNSUPPORTED = 2
} HiAI_SingleOpSupportStatus;

/**
 * @brief HMS_HiAISingleOpExecutor_CreateConvolution input parameters.
 * @since 5.0.0(12)
 */
typedef struct HiAI_SingleOpExecutorConvolutionParam {
    /**
    * Pointer to the {@link HiAI_SingleOpOptions} object. The value cannot be a null pointer. Otherwise, the called
    * method fails.
    */
    HiAI_SingleOpOptions* options;
    /**
    * Pointer to the {@link HiAI_SingleOpDescriptor} object of a convolution operation. The value cannot be a null
    * pointer. Otherwise, the called method fails.
    */
    HiAI_SingleOpDescriptor* opDesc;
    /**
    * Pointer to the input tensor description. The value cannot be a null pointer. Otherwise, the called method
    * fails.
    */
    HiAI_SingleOpTensorDesc* input;
    /**
    * Pointer to the output tensor description. The value cannot be a null pointer. Otherwise, the called method
    * fails.
    */
    HiAI_SingleOpTensorDesc* output;
    /**
    * Pointer to the convolution kernel tensor. The value cannot be a null pointer. Otherwise, the called method
    * fails.
    */
    HiAI_SingleOpTensor* filter;
    /** Pointer to the bias tensor. If the convolution has no bias, the value can be a null pointer.*/
    HiAI_SingleOpTensor* bias;
} HiAI_SingleOpExecutorConvolutionParam;

/**
 * @brief HMS_HiAISingleOpExecutor_CreateFusedConvolutionActivation input parameters.
 * @since 5.0.0(12)
 */
typedef struct HiAI_SingleOpExecutorFusedConvolutionActivationParam {
    /**
    * Pointer to the {@link HiAI_SingleOpOptions} object. The value cannot be a null pointer. Otherwise, the called
    * method fails.
    */
    HiAI_SingleOpOptions* options;
    /**
    * Pointer to the {@link HiAI_SingleOpDescriptor} object of a convolution operation. The value cannot be a null
    * pointer. Otherwise, the called method fails.
    */
    HiAI_SingleOpDescriptor* convOpDesc;
    /**
    * Pointer to the {@link HiAI_SingleOpDescriptor} object of an activation operation. The value cannot be a null
    * pointer. Otherwise, the called method fails.
    */
    HiAI_SingleOpDescriptor* actOpDesc;
    /**
    * Pointer to the input tensor description. The value cannot be a null pointer. Otherwise, the called method
    * fails.
    */
    HiAI_SingleOpTensorDesc* input;
    /**
    * Pointer to the output tensor description. The value cannot be a null pointer. Otherwise, the called method
    * fails.
    */
    HiAI_SingleOpTensorDesc* output;
    /**
    * Pointer to the convolution kernel tensor. The value cannot be a null pointer. Otherwise, the called method
    * fails.
    */
    HiAI_SingleOpTensor* filter;
    /** Pointer to the bias tensor. If the convolution has no bias, the value can be a null pointer.*/
    HiAI_SingleOpTensor* bias;
} HiAI_SingleOpExecutorFusedConvolutionActivationParam;

/**
 * @brief Pre-checks whether a convolution operation is supported or optimized.
 *
 * You can determine whether to call {@link HMS_HiAISingleOpExecutor_CreateConvolution} to create a convolution
 * executor based on the return value of this API. Alternatively, you can also directly call
 * {@link HMS_HiAISingleOpExecutor_CreateConvolution} to create a convolution executor.
 *
 * @param param Refer to {@link HiAI_SingleOpExecutorConvolutionParam} for details of the input parameters.
 * @return Support status. For details about the status, please refer to {@link HiAI_SingleOpSupportStatus}.
 * @since 5.0.0(12)
 */
HiAI_SingleOpSupportStatus HMS_HiAISingleOpExecutor_PreCheckConvolution(
    HiAI_SingleOpExecutorConvolutionParam param);

/**
 * @brief Pre-checks whether a fused convolution-and-activation operation is supported or optimized.
 *
 * You can determine whether to call {@link HMS_HiAISingleOpExecutor_CreateFusedConvolutionActivation} to create a
 * fused convolution-and-activation executor based on the return value of this API. Alternatively, you can also
 * directly call {@link HMS_HiAISingleOpExecutor_CreateFusedConvolutionActivation} to create a fused
 * convolution-and-activation executor.
 *
 * @param param Refer to {@link HiAI_SingleOpExecutorFusedConvolutionActivationParam} for details of the
 * input parameters.
 * @return Support status. For details about the status, please refer to {@link HiAI_SingleOpSupportStatus}.
 * @since 5.0.0(12)
 */
HiAI_SingleOpSupportStatus HMS_HiAISingleOpExecutor_PreCheckFusedConvolutionActivation(
    HiAI_SingleOpExecutorFusedConvolutionActivationParam param);

/**
 * @brief Single op executor handle.
 * @since 5.0.0(12)
 */
typedef struct HiAI_SingleOpExecutor HiAI_SingleOpExecutor;

/**
 * @brief Creates a {@link HiAI_SingleOpExecutor} object of a convolution operation.
 *
 * When you no longer use the {@link HiAI_SingleOpExecutor} object, call {@link HMS_HiAISingleOpExecutor_Destroy} to
 * destroy it. Otherwise, a memory leak may occur.
 *
 * The data type and format of an output tensor description can respectively be HIAI_SINGLEOP_DT_UNDEFINED and
 * HIAI_SINGLEOP_FORMAT_RESERVED. In this case, the executor sets the output data type and the format to the optimal
 * values that adapt to the hardware. After this API is successfully executed, you can call
 * {@link HMS_HiAISingleOpExecutor_UpdateOutputTensorDesc} to update the data type and format of the output tensor
 * description.
 *
 * @param param Refer to {@link HiAI_SingleOpExecutorConvolutionParam} for details of the input parameters.
 * @return Returns the pointer to {@link HiAI_SingleOpExecutor} if the operation is successful; returns a null pointer
 * otherwise.
 * @since 5.0.0(12)
 */
HiAI_SingleOpExecutor* HMS_HiAISingleOpExecutor_CreateConvolution(
    HiAI_SingleOpExecutorConvolutionParam param);

/**
 * @brief Creates a {@link HiAI_SingleOpExecutor} object of the fused convolution-and-activation operation.
 *
 * When you no longer use {@link HiAI_SingleOpExecutor}, call {@link HMS_HiAISingleOpExecutor_Destroy} to destroy it.
 * Otherwise, a memory leak may occur.
 *
 * The data type and format of an output tensor description can respectively be HIAI_SINGLEOP_DT_UNDEFINED and
 * HIAI_SINGLEOP_FORMAT_RESERVED. In this case, the executor sets the output data type and format to the optimal values
 * that adapt to the hardware. After this API is successfully executed, you can call
 * {@link HMS_HiAISingleOpExecutor_UpdateOutputTensorDesc} to update the data type and format of the output tensor
 * description.
 *
 * @param param Refer to {@link HiAI_SingleOpExecutorFusedConvolutionActivationParam} for details of the
 * input parameters.
 * @return Returns the pointer to {@link HiAI_SingleOpExecutor} if the operation is successful; returns a null pointer
 * otherwise.
 * @since 5.0.0(12)
 */
HiAI_SingleOpExecutor* HMS_HiAISingleOpExecutor_CreateFusedConvolutionActivation(
    HiAI_SingleOpExecutorFusedConvolutionActivationParam param);

/**
 * @brief Updates the output tensor description of {@link HiAI_SingleOpExecutor}.
 *
 * When creating {@link HiAI_SingleOpExecutor}, if you set the data type of input parameter <b>output</b> to
 * <b>HIAI_SINGLEOP_DT_UNDEFINED</b>, and set the format to <b>HIAI_SINGLEOP_FORMAT_RESERVED</b>, calling this API will
 * update the data type and format in the output tensor description to the optimal values that adapt to the hardware.
 *
 * @param executor Pointer to the {@link HiAI_SingleOpExecutor} object. The value cannot be a null pointer. Otherwise,
 * an error code is returned.
 * @param index Index of the output tensor description, which is the same as the value specified when the executor is
 * created. The index starts from 0.
 * @param output Pointer to the {@link HiAI_SingleOpTensorDesc} object to be updated.
 * @return Function execution result. If the operation is successful, OH_NN_SUCCESS is returned. If the operation
 * fails, an error code is returned. For details about the error codes, please refer to {@link OH_NN_ReturnCode}.
 * @since 5.0.0(12)
 */
OH_NN_ReturnCode HMS_HiAISingleOpExecutor_UpdateOutputTensorDesc(const HiAI_SingleOpExecutor* executor,
    uint32_t index, HiAI_SingleOpTensorDesc* output);

/**
 * @brief Queries the size (in bytes) of the ION workspace memory required by {@link HiAI_SingleOpExecutor}.
 *
 * After {@link HiAI_SingleOpExecutor} is successfully created, you need call this API to obtain the size (in bytes) of
 * the ION workspace memory required by the executor. You need to call {@link HMS_HiAISingleOpBuffer_Create} to apply
 * for adequate memory, then pass the allocated memory to the {@link HMS_HiAISingleOpExecutor_Init} API.
 *
 * Note: The workspace memory cannot reuse the input tensor memory and the output tensor memory of the same executor.
 * The workspace memory from different executors can be reused.
 *
 * @param executor Pointer to the {@link HiAI_SingleOpExecutor} object. The value cannot be a null pointer. Otherwise,
 * 0 is returned.
 * @return Size of the workspace, in bytes.
 * @since 5.0.0(12)
 */
size_t HMS_HiAISingleOpExecutor_GetWorkspaceSize(const HiAI_SingleOpExecutor* executor);

/**
 * @brief Loads {@link HiAI_SingleOpExecutor}.
 *
 * Before calling this API, you need to apply for the workspace memory required by the executor.
 *
 * @param executor Pointer to the {@link HiAI_SingleOpExecutor} object. The value cannot be a null pointer. Otherwise,
 * an error code is returned.
 * @param workspace Workspace address. When <b>workspaceSize</b> is not 0, the value must be a memory address from
 * {@link HiAI_SingleOpBuffer}. Otherwise, an error code is returned.
 * @param workspaceSize Size of the provided <b>workspace</b>, in bytes. The value must be greater than or equal to the
 * size of the required workspace obtained by {@link HMS_HiAISingleOpExecutor_GetWorkspaceSize}. Otherwise, an error
 * code is returned.
 * @return Function execution result. If the operation is successful, OH_NN_SUCCESS is returned. If the operation
 * fails, an error code is returned. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 5.0.0(12)
 */
OH_NN_ReturnCode HMS_HiAISingleOpExecutor_Init(HiAI_SingleOpExecutor* executor, void* workspace,
    size_t workspaceSize);

/**
 * @brief Performs synchronous inference.
 *
 * Before calling this API, call {@link HMS_HiAISingleOpTensor_CreateFromTensorDesc} or
 * {@link HMS_HiAISingleOpTensor_CreateFromSingleOpBuffer} to create the input and output tensors and fill the input
 * tensors with data. The executor performs inference, and writes the result to the output tensors.
 *
 * @param executor Pointer to the {@link HiAI_SingleOpExecutor} object. The value cannot be a null pointer. Otherwise,
 * an error code is returned.
 * @param input[] Array of input tensors.
 * @param inputNum Number of input tensors.
 * @param output[] Array of output tensors.
 * @param outputNum Number of output tensors.
 * @return Function execution result. If the operation is successful, OH_NN_SUCCESS is returned. If the operation
 * fails, an error code is returned. For details about the error codes, please refer to {@link OH_NN_ReturnCode}.
 * @since 5.0.0(12)
 */
OH_NN_ReturnCode HMS_HiAISingleOpExecutor_Execute(HiAI_SingleOpExecutor* executor,
    HiAI_SingleOpTensor* input[], int32_t inputNum, HiAI_SingleOpTensor* output[], int32_t outputNum);

/**
 * @brief Destroys the {@link HiAI_SingleOpExecutor} object to release the memory occupied by the executor.
 *
 * When you no longer use the {@link HiAI_SingleOpExecutor} object, destroy it by calling the API. Otherwise, a memory
 * leak may occur.
 *
 * Note: This API does not release the workspace memory passed to {@link HMS_HiAISingleOpExecutor_Init}. You need to
 * release the workspace memory of {@link HiAI_SingleOpBuffer} separately.
 *
 * @param executor Double pointer to the {@link HiAI_SingleOpExecutor} object. <b>executor</b> and <b>*executor</b>
 * cannot be null pointers. Otherwise, an error code is returned.
 * @return Function execution result. If the operation is successful, OH_NN_SUCCESS is returned. If the operation
 * fails, an error code is returned. For details about the error codes, please refer to {@link OH_NN_ReturnCode}.
 * @since 5.0.0(12)
 */
OH_NN_ReturnCode HMS_HiAISingleOpExecutor_Destroy(HiAI_SingleOpExecutor** executor);


#ifdef __cplusplus
}
#endif

/** @} */
#endif // HIAI_FOUNDATION_SINGLE_OP_H
