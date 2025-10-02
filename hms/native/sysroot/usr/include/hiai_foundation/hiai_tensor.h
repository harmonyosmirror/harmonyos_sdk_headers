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
 * @file hiai_tensor.h
 * @kit HiAIFoundationKit
 * @library libhiai_foundation.so
 *
 * @brief Auxiliary APIs related to input and output memory during HiAI Foundation model inference.
 *
 * You can call the following APIs to associate aippParam with a tensor or calculate the tensor memory size required for
 * the image format.
 *
 * @since 4.1.0(11)
 */

#ifndef HIAI_FOUNDATION_TENSOR_H
#define HIAI_FOUNDATION_TENSOR_H
#include "hiai_aipp_param.h"
#include "neural_network_runtime/neural_network_runtime_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Calculates the size of the tensor to be applied for based on NN_TensorDesc and HiAI_ImageFormat.
 *
 * @param desc Pointer to {@link NN_TensorDesc}. The value cannot be null. Otherwise, 0 is returned.
 * @param format Image format {@link HiAI_ImageFormat}.
 * @return Returns the size of the tensor to be applied for if the operation is successful; returns 0 otherwise.
 * @since 4.1.0(11)
 */
size_t HMS_HiAITensor_GetSizeWithImageFormat(NN_TensorDesc* desc, HiAI_ImageFormat format);

/**
 * @brief Sets aippParams for NN_Tensor.
 *
 * After the AIPP parameters are set for {@link NN_Tensor}, release the memory by calling
 * {@link HMS_HiAIAippParam_Destroy} after the tensor is used.
 *
 * @param tensor Pointer to {@link NN_Tensor}. The value cannot be null. Otherwise, a null pointer is
 * returned.
 * @param aippParams AIPP parameter array.
 * @param aippNum Number of AIPP parameters.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @see OH_NNCore_DestroyTensor
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAITensor_SetAippParams(
    NN_Tensor* tensor, HiAI_AippParam* aippParams[], size_t aippNum);

#ifdef __cplusplus
}
#endif

/** @} */
#endif // HIAI_FOUNDATION_TENSOR_H
