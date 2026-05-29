
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2026. All rights reserved.
 */

/**
 * @file fast_dsp_common.h
 *
 * @brief Declares common data structures and utility functions for digital signal processing (DSP),
 *        including vector operations, complex number handling, and biquad IIR filter management.
 *        These utilities support both single-precision (float) and double-precision (double) arithmetic.
 *
 * @library libfast_dsp.so
 * @kit FASTKit
 * @syscap SystemCapability.FAST.Core
 * @since 6.1.1(24)
 */

/**
 * @addtogroup FAST
 * @{
 *
 * @brief Provides acceleration capabilities to optimize metrics
 *        such as application startup, loading, and response latency.
 *
 * @since 6.1.1(24)
 */

#ifndef FAST_DSP_COMMON_H
#define FAST_DSP_COMMON_H

#include "info/application_target_sdk_version.h"
#include <float.h>
#include "fast_common_def.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Represents a complex signal in split format using single-precision floating-point numbers.
 *
 * @since 6.1.1(24)
 */
typedef struct FAST_SplitComplex {
    /**
     * @brief Pointer to array of real components.
     * @since 6.1.1(24)
     */
    float* real;
    /**
     * @brief Pointer to array of imaginary components.
     * @since 6.1.1(24)
     */
    float* imag;
} FAST_SplitComplex;

/**
 * @brief Represents a complex signal in split format using double-precision floating-point numbers.
 *
 * @since 6.1.1(24)
 */
typedef struct FAST_SplitComplexD {
    /**
     * @brief Pointer to array of real components.
     * @since 6.1.1(24)
     */
    double* real;
    /**
     * @brief Pointer to array of imaginary components.
     * @since 6.1.1(24)
     */
    double* imag;
} FAST_SplitComplexD;

/**
 * @brief Coefficients of a second-order (biquad) IIR filter section in direct form I or II.
 *        Transfer function: H(z) = (b0 + b1*z⁻¹ + b2*z⁻²) / (1 + a1*z⁻¹ + a2*z⁻²)
 *
 * @note a0 is normalized to 1.
 *
 * @since 6.1.1(24)
 */
typedef struct FAST_BiquadCoefficients {
    /**
     * @brief Numerator coefficient for z⁰
     * @since 6.1.1(24)
     */
    float b0;
    /**
     * @brief Numerator coefficient for z⁻¹
     * @since 6.1.1(24)
     */
    float b1;
    /**
     * @brief Numerator coefficient for z⁻²
     * @since 6.1.1(24)
     */
    float b2;
    /**
     * @brief Denominator coefficient for z⁻¹
     * @since 6.1.1(24)
     */
    float a1;
    /**
     * @brief Denominator coefficient for z⁻²
     * @since 6.1.1(24)
     */
    float a2;
} FAST_BiquadCoefficients;

/**
 * @brief Double-precision version of biquad filter coefficients.
 *
 * @note a0 is normalized to 1.
 *
 * @since 6.1.1(24)
 */
typedef struct FAST_BiquadCoefficientsD {
    /**
     * @brief Numerator coefficient for z⁰
     * @since 6.1.1(24)
     */
    double b0;
    /**
     * @brief Numerator coefficient for z⁻¹
     * @since 6.1.1(24)
     */
    double b1;
    /**
     * @brief Numerator coefficient for z⁻²
     * @since 6.1.1(24)
     */
    double b2;
    /**
     * @brief Denominator coefficient for z⁻¹
     * @since 6.1.1(24)
     */
    double a1;
    /**
     * @brief Denominator coefficient for z⁻²
     * @since 6.1.1(24)
     */
    double a2;
} FAST_BiquadCoefficientsD;

/**
 * @brief State variables for a single biquad filter section (single-precision).
 *
 * @since 6.1.1(24)
 */
typedef struct FAST_BiquadState {
    /**
     * @brief First delay element (y[n-1])
     * @since 6.1.1(24)
     */
    float d1;
    /**
     * @brief Second delay element (y[n-2])
     * @since 6.1.1(24)
     */
    float d2;
} FAST_BiquadState;

/**
 * @brief State variables for a single biquad filter section (double-precision).
 *
 * @since 6.1.1(24)
 */
typedef struct FAST_BiquadStateD {
    /**
     * @brief First delay element (y[n-1])
     * @since 6.1.1(24)
     */
    double d1;
    /**
     * @brief Second delay element (y[n-2])
     * @since 6.1.1(24)
     */
    double d2;
} FAST_BiquadStateD;

/**
 * @brief Multi-channel, multi-section biquad filter bank (single-precision).
 *
 * @since 6.1.1(24)
 */
typedef struct FAST_Biquadm {
    /**
     * @brief Number of audio or signal channels
     * @since 6.1.1(24)
     */
    size_t numChannels;
    /**
     * @brief Number of cascaded biquad sections per channel
     * @since 6.1.1(24)
     */
    size_t numSections;
    /**
     * @brief Maximum number of samples per processing call
     * @since 6.1.1(24)
     */
    size_t maxFrames;
    /**
     * @brief Array of size [numSections]
     * @since 6.1.1(24)
     */
    FAST_BiquadCoefficients* coefficients;
    /**
     * @brief Array of size [numChannels * numSections]
     * @since 6.1.1(24)
     */
    FAST_BiquadState* states;
    /**
     * @brief Boolean mask (size [numSections]) indicating which sections are active
     * @since 6.1.1(24)
     */
    uint8_t* activeFilters;
    /**
     * @brief Per-channel linear gain factors (size [numChannels])
     * @since 6.1.1(24)
     */
    float* channelGains;
    /**
     * @brief Flag indicating whether the structure has been initialized
     * @since 6.1.1(24)
     */
    uint8_t isInitialized;
} FAST_Biquadm;

/**
 * @brief Multi-channel, multi-section biquad filter bank (double-precision).
 *
 * @since 6.1.1(24)
 */
typedef struct FAST_BiquadmD {
    /**
     * @brief Number of audio or signal channels
     * @since 6.1.1(24)
     */
    size_t numChannels;
    /**
     * @brief Number of cascaded biquad sections per channel
     * @since 6.1.1(24)
     */
    size_t numSections;
    /**
     * @brief Maximum number of samples per processing call
     * @since 6.1.1(24)
     */
    size_t maxFrames;
    /**
     * @brief Array of size [numSections]
     * @since 6.1.1(24)
     */
    FAST_BiquadCoefficientsD* coefficients;
    /**
     * @brief Array of size [numChannels * numSections]
     * @since 6.1.1(24)
     */
    FAST_BiquadStateD* states;
    /**
     * @brief Boolean mask (size [numSections]) indicating which sections are active
     * @since 6.1.1(24)
     */
    uint8_t* activeFilters;
    /**
     * @brief Per-channel linear gain factors (size [numChannels])
     * @since 6.1.1(24)
     */
    double* channelGains;
    /**
     * @brief Flag indicating whether the structure has been initialized
     * @since 6.1.1(24)
     */
    uint8_t isInitialized;
} FAST_BiquadmD;

/**
 * @brief Computes the maximum magnitude value in a strided real-valued vector (single-precision).
 *
 * @param input Pointer to input vector.
 * @param stride Distance between consecutive samples. A value of 1 indicates contiguous storage.
 * @param length Number of samples to process.
 * @return Maximum absolute value in the vector. Will be 0.0f if {@link length} == 0.
 *
 * @since 6.1.1(24)
 */
float HMS_FAST_DSP_Maxmgv(const float* input, size_t stride, size_t length)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Computes the maximum magnitude value in a strided real-valued vector (double-precision).
 *
 * @param input Pointer to input vector.
 * @param stride Distance between consecutive samples. A value of 1 indicates contiguous storage.
 * @param length Number of samples to process.
 * @return Maximum absolute value in the vector. Will be 0.0 if {@link length} == 0.
 *
 * @since 6.1.1(24)
 */
double HMS_FAST_DSP_MaxmgvD(const double* input, size_t stride, size_t length)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Finds the maximum value and its index in a strided real-valued vector (single-precision).
 *
 * @param input Pointer to input vector.
 * @param stride Distance between consecutive samples. A value of 1 indicates contiguous storage.
 * @param length Number of samples.
 * @param value Pointer to store the maximum value. Will be -FLT_MAX if {@link length} == 0.
 * @param index Index (0-based) of the sample with maximum value. Will be 0 if {@link length} == 0.
 *
 * @since 6.1.1(24)
 */
void HMS_FAST_DSP_Maxvi(const float* input, size_t stride, size_t length, float* value, size_t* index)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Finds the maximum value and its index in a strided real-valued vector (double-precision).
 *
 * @param input Pointer to input vector.
 * @param stride Distance between consecutive samples. A value of 1 indicates contiguous storage.
 * @param length Number of samples.
 * @param value Pointer to store the maximum value. Will be -DBL_MAX if {@link length} == 0.
 * @param index Index (0-based) of the sample with maximum value. Will be 0 if {@link length} == 0.
 *
 * @since 6.1.1(24)
 */
void HMS_FAST_DSP_MaxviD(const double* input, size_t stride, size_t length, double* value, size_t* index)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Computes the mean of absolute values in a strided real-valued vector (single-precision).
 *
 * @param input Pointer to input vector.
 * @param stride Distance between consecutive samples. A value of 1 indicates contiguous storage.
 * @param length Number of samples.
 * @return Mean of |input[i]|. Will be 0 if {@link length} == 0.
 *
 * @since 6.1.1(24)
 */
float HMS_FAST_DSP_Meamgv(const float* input, size_t stride, size_t length)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Computes the mean of absolute values in a strided real-valued vector (double-precision).
 *
 * @param input Pointer to input vector.
 * @param stride Distance between consecutive samples. A value of 1 indicates contiguous storage.
 * @param length Number of samples.
 * @return Mean of |input[i]|. Will be 0 if {@link length} == 0.
 *
 * @since 6.1.1(24)
 */
double HMS_FAST_DSP_MeamgvD(const double* input, size_t stride, size_t length)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Computes the sum of values in a strided real-valued vector (single-precision).
 *
 * @param input Pointer to input vector.
 * @param stride Distance between consecutive samples. A value of 1 indicates contiguous storage.
 * @param length Number of samples.
 * @return Sum of input[i]. Will be 0.0f if {@link length} == 0.
 *
 * @since 6.1.1(24)
 */
float HMS_FAST_DSP_Sve(const float* input, size_t stride, size_t length)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Computes the sum of values in a strided real-valued vector (double-precision).
 *
 * @param input Pointer to input vector.
 * @param stride Distance between consecutive samples. A value of 1 indicates contiguous storage.
 * @param length Number of samples.
 * @return Sum of input[i]. Will be 0.0 if {@link length} == 0.
 *
 * @since 6.1.1(24)
 */
double HMS_FAST_DSP_SveD(const double* input, size_t stride, size_t length)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Computes the sum of absolute values (L1 norm) in a strided vector (single-precision).
 *
 * @param input Pointer to input vector.
 * @param stride Distance between consecutive samples. A value of 1 indicates contiguous storage.
 * @param length Number of samples.
 * @return sum(|input[i]|). Will be 0.0f if {@link length} == 0.
 *
 * @since 6.1.1(24)
 */
float HMS_FAST_DSP_Svemg(const float* input, size_t stride, size_t length)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Computes the sum of absolute values (L1 norm) in a strided vector (double-precision).
 *
 * @param input Pointer to input vector.
 * @param stride Distance between consecutive samples. A value of 1 indicates contiguous storage.
 * @param length Number of samples.
 * @return sum(|input[i]|). Will be 0.0 if {@link length} == 0.
 *
 * @since 6.1.1(24)
 */
double HMS_FAST_DSP_SvemgD(const double* input, size_t stride, size_t length)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Computes the dot product of two strided real-valued vectors (single-precision).
 *
 * @param inputA First input vector.
 * @param strideA Stride for first vector. A value of 1 indicates contiguous storage.
 * @param inputB Second input vector.
 * @param strideB Stride for second vector. A value of 1 indicates contiguous storage.
 * @param length Number of samples.
 * @return Dot product: sum(inputA[i] * inputB[i]). Will be 0.0f if {@link length} == 0.
 *
 * @since 6.1.1(24)
 */
float HMS_FAST_DSP_Dotpr(const float* inputA, size_t strideA, const float* inputB, size_t strideB, size_t length)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Computes the dot product of two strided real-valued vectors (double-precision).
 *
 * @param inputA First input vector.
 * @param strideA Stride for first vector. A value of 1 indicates contiguous storage.
 * @param inputB Second input vector.
 * @param strideB Stride for second vector. A value of 1 indicates contiguous storage.
 * @param length Number of samples.
 * @return Dot product: sum(inputA[i] * inputB[i]). Will be 0.0 if {@link length} == 0.
 *
 * @since 6.1.1(24)
 */
double HMS_FAST_DSP_DotprD(const double* inputA, size_t strideA, const double* inputB, size_t strideB, size_t length)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Performs vector subtraction: outputC[i] = (inputA[i] - inputB[i]) * scalar (single-precision).
 *
 * @param inputA First input vector.
 * @param strideA Stride for first vector. A value of 1 indicates contiguous storage.
 * @param inputB Second input vector.
 * @param strideB Stride for second vector. A value of 1 indicates contiguous storage.
 * @param scalar Scalar for the calculate.
 * @param outputC Output vector (caller-allocated).
 * @param strideC Stride for output vector. A value of 1 indicates contiguous storage.
 * @param length Number of samples. Must be greater than 0.
 * @return NA
 * @since 6.1.1(24)
 */
void HMS_FAST_DSP_Vsbsm(const float* inputA, size_t strideA, const float* inputB, size_t strideB, float scalar,
    float* outputC, size_t strideC, size_t length)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Performs vector subtraction: outputC[i] = (inputA[i] - inputB[i]) * scalar (double-precision).
 *
 * @param inputA First input vector.
 * @param strideA Stride for first vector. A value of 1 indicates contiguous storage.
 * @param inputB Second input vector.
 * @param strideB Stride for second vector. A value of 1 indicates contiguous storage.
 * @param scalar Scalar for the calculate.
 * @param outputC Output vector (caller-allocated).
 * @param strideC Stride for output vector. A value of 1 indicates contiguous storage.
 * @param length Number of samples. Must be greater than 0.
 * @return NA
 * @since 6.1.1(24)
 */
void HMS_FAST_DSP_VsbsmD(const double* inputA, size_t strideA, const double* inputB, size_t strideB, double scalar,
    double* outputC, size_t strideC, size_t length)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Converts an interleaved complex array (real, imag, real, imag, ...) to split format (single-precision).
 *
 * @param input Interleaved complex input (length = 2 * {@link length}).
 * @param strideInput Stride between complex samples. A value of 1 indicates contiguous storage.
 * @param output Split-complex output structure.
 * @param strideOutput Stride between real/imag samples in output arrays. A value of 1 indicates contiguous storage.
 * @param length Number of complex samples to convert. Must be greater than 0.
 * @return NA
 *
 * @since 6.1.1(24)
 */
void HMS_FAST_DSP_Ctoz(const float* input, size_t strideInput,
    FAST_SplitComplex* output, size_t strideOutput, size_t length)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Converts an interleaved complex array (real, imag, real, imag, ...) to split format (double-precision).
 *
 * @param input Interleaved complex input (length = 2 * {@link length}).
 * @param strideInput Stride between complex samples. A value of 1 indicates contiguous storage.
 * @param output Split-complex output structure.
 * @param strideOutput Stride between real/imag samples in output arrays. A value of 1 indicates contiguous storage.
 * @param length Number of complex samples to convert. Must be greater than 0.
 * @return NA
 *
 * @since 6.1.1(24)
 */
void HMS_FAST_DSP_CtozD(const double* input, size_t strideInput,
    FAST_SplitComplexD* output, size_t strideOutput, size_t length)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Converts a split-complex array to interleaved format (single-precision).
 *
 * @param input Split-complex input structure.
 * @param strideInput Stride between samples in real/imag arrays. A value of 1 indicates contiguous storage.
 * @param output Interleaved output array (length = 2 * {@link length}).
 * @param strideOutput Stride between complex samples in output. A value of 1 indicates contiguous storage.
 * @param length Number of complex samples to convert. Must be greater than 0.
 *
 * @since 6.1.1(24)
 */
void HMS_FAST_DSP_Ztoc(const FAST_SplitComplex* input, size_t strideInput,
    float* output, size_t strideOutput, size_t length)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Converts a split-complex array to interleaved format (double-precision).
 *
 * @param input Split-complex input structure.
 * @param strideInput Stride between samples in real/imag arrays. A value of 1 indicates contiguous storage.
 * @param output Interleaved output array (length = 2 * {@link length}).
 * @param strideOutput Stride between complex samples in output. A value of 1 indicates contiguous storage.
 * @param length Number of complex samples to convert. Must be greater than 0.
 *
 * @since 6.1.1(24)
 */
void HMS_FAST_DSP_ZtocD(const FAST_SplitComplexD* input, size_t strideInput,
    double* output, size_t strideOutput, size_t length)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the activation mask for biquad filter sections (single-precision).
 *        Mask is expected in order: [ch0_sec0, ch0_sec1, ..., ch1_sec0, ch1_sec1, ...].
 *
 * @param filter Pointer to initialized biquad filter bank.
 * @param activeMask Boolean array (size = filter->numSections); non-zero means active.
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success.
 *         {@link FAST_ERROR_CODE_INVALID_PTR} {@link filter} or {@link activeMask} is NULL,
 *                                             or activeFilters of {@link filter} is NULL.
 *         {@link FAST_ERROR_CODE_ILLEGAL_INPUT} {@link filter} is not initialized.
 *
 * @since 6.1.1(24)
 */
FAST_ErrorCode HMS_FAST_Biquadm_SetActiveFilters(FAST_Biquadm* filter, const uint8_t* activeMask)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the activation mask for biquad filter sections (double-precision).
 *        Mask is expected in order: [ch0_sec0, ch0_sec1, ..., ch1_sec0, ch1_sec1, ...].
 *
 * @param filter Pointer to initialized biquad filter bank.
 * @param activeMask Boolean array (size = filter->numSections); non-zero means active.
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success.
 *         {@link FAST_ERROR_CODE_INVALID_PTR} {@link filter} or {@link activeMask} is NULL,
 *                                             or activeFilters of {@link filter} is NULL.
 *         {@link FAST_ERROR_CODE_ILLEGAL_INPUT} {@link filter} is not initialized.
 *
 * @since 6.1.1(24)
 */
FAST_ErrorCode HMS_FAST_Biquadm_SetActiveFiltersD(FAST_BiquadmD* filter, const uint8_t* activeMask)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets all biquad coefficients from a strided single-precision source array into a single-precision filter.
 *        Coefficients are expected in order: [b0, b1, b2, a1, a2] per section.
 *
 * @param filter Pointer to initialized biquad filter bank.
 * @param coeff Source coefficient array.
 * @param stride Stride (in elements) between sections in {@link coeff}. A value of 1 indicates contiguous storage.
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success.
 *         {@link FAST_ERROR_CODE_INVALID_PTR} {@link filter} or {@link coeff} is NULL.
 *         {@link FAST_ERROR_CODE_ILLEGAL_INPUT} {@link filter} is not initialized.
 *
 * @since 6.1.1(24)
 */
FAST_ErrorCode HMS_FAST_Biquadm_SetCoeffSingle(FAST_Biquadm* filter, const float* coeff, size_t stride)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets all biquad coefficients from a strided double-precision source array into a single-precision filter.
 *        Coefficients are expected in order: [b0, b1, b2, a1, a2] per section.
 *
 * @param filter Pointer to initialized biquad filter bank.
 * @param coeff Source coefficient array.
 * @param stride Stride (in elements) between sections in {@link coeff}. A value of 1 indicates contiguous storage.
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success.
 *         {@link FAST_ERROR_CODE_INVALID_PTR} {@link filter} or {@link coeff} is NULL.
 *         {@link FAST_ERROR_CODE_ILLEGAL_INPUT} {@link filter} is not initialized.
 *
 * @since 6.1.1(24)
 */
FAST_ErrorCode HMS_FAST_Biquadm_SetCoeffDouble(FAST_Biquadm* filter, const double* coeff, size_t stride)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets all biquad coefficients from a strided single-precision source array into a double-precision filter.
 *        Coefficients are expected in order: [b0, b1, b2, a1, a2] per section.
 *
 * @param filter Pointer to initialized biquad filter bank.
 * @param coeff Source coefficient array.
 * @param stride Stride (in elements) between sections in {@link coeff}. A value of 1 indicates contiguous storage.
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success.
 *         {@link FAST_ERROR_CODE_INVALID_PTR} {@link filter} or {@link coeff} is NULL.
 *         {@link FAST_ERROR_CODE_ILLEGAL_INPUT} {@link filter} is not initialized.
 *
 * @since 6.1.1(24)
 */
FAST_ErrorCode HMS_FAST_Biquadm_SetCoeffSingleD(FAST_BiquadmD* filter, const float* coeff, size_t stride)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets all biquad coefficients from a strided double-precision source array into a double-precision filter.
 *        Coefficients are expected in order: [b0, b1, b2, a1, a2] per section.
 *
 * @param filter Pointer to initialized biquad filter bank.
 * @param coeff Source coefficient array.
 * @param stride Stride (in elements) between sections in {@link coeff}. A value of 1 indicates contiguous storage.
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success.
 *         {@link FAST_ERROR_CODE_INVALID_PTR} {@link filter} or {@link coeff} is NULL.
 *         {@link FAST_ERROR_CODE_ILLEGAL_INPUT} {@link filter} is not initialized.
 *
 * @since 6.1.1(24)
 */
FAST_ErrorCode HMS_FAST_Biquadm_SetCoeffDoubleD(FAST_BiquadmD* filter, const double* coeff, size_t stride)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Creates and initializes a multi-channel, multi-section biquad IIR filter bank (single-precision).
 *
 * @param numChannels  Number of signal channels. Must be greater than 0.
 * @param numSections  Number of biquad sections per channel. Must be greater than 0.
 * @param maxFrames    Maximum number of samples (per channel) that can be processed in a single call.
 *                     Must be greater than 0.
 * @param filter       Pointer to a variable that will receive the address of the newly created filter.
 *                     On success, *@link filter points to a valid @c FAST_Biquadm instance.
 *                     On failure, *@link filter is set to NULL.
 *
 * @return {@link FAST_ERROR_CODE_SUCCESS} Filter successfully created.
 *         {@link FAST_ERROR_CODE_INVALID_PTR} {@link filter} is NULL.
 *         {@link FAST_ERROR_CODE_ILLEGAL_INPUT} Any of {@link numChannels}, {@link numSections},
 *                                               or {@link maxFrames} is 0.
 *         {@link FAST_ERROR_CODE_OOM} Memory allocation failed.
 *
 * @note This function allocates and configures internal coefficient, state, and control arrays for a biquad filter
 *       supporting {@link numChannels} channels, each processed through {@link numSections} cascaded
 *       second-order sections.
 *       The filter is designed to handle up to {@link maxFrames} samples per processing call.
 *       The caller must later free the allocated structure using {@link HMS_FAST_Biquadm_Destroy}.
 *
 * @since 6.1.1(24)
 */
FAST_ErrorCode HMS_FAST_Biquadm_Create(size_t numChannels, size_t numSections, size_t maxFrames,
    FAST_Biquadm** filter)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Creates and initializes a multi-channel, multi-section biquad IIR filter bank (double-precision).
 *
 * @param numChannels  Number of signal channels. Must be greater than 0.
 * @param numSections  Number of biquad sections per channel. Must be greater than 0.
 * @param maxFrames    Maximum number of samples (per channel) that can be processed in a single call.
 *                     Must be greater than 0.
 * @param filter       Pointer to a variable that will receive the address of the newly created filter.
 *                     On success, *@link filter points to a valid @c FAST_Biquadm instance.
 *                     On failure, *@link filter is set to NULL.
 *
 * @return {@link FAST_ERROR_CODE_SUCCESS} Filter successfully created.
 *         {@link FAST_ERROR_CODE_INVALID_PTR} {@link filter} is NULL.
 *         {@link FAST_ERROR_CODE_ILLEGAL_INPUT} Any of {@link numChannels}, {@link numSections},
 *                                               or {@link maxFrames} is 0.
 *         {@link FAST_ERROR_CODE_OOM} Memory allocation failed.
 *
 * @note This function allocates and configures internal coefficient, state, and control arrays for a biquad filter
 *       supporting {@link numChannels} channels, each processed through {@link numSections} cascaded
 *        second-order sections.
 *       The filter is designed to handle up to {@link maxFrames} samples per processing call.
 *       The caller must later free the allocated structure using {@link HMS_FAST_Biquadm_Destroy}.
 *
 * @since 6.1.1(24)
 */
FAST_ErrorCode HMS_FAST_Biquadm_CreateD(size_t numChannels, size_t numSections, size_t maxFrames,
    FAST_BiquadmD** filter)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroy a biquad instance (single-precision).
 *
 * @param filter Biquad filter.
 * @return NA
 *
 * @since 6.1.1(24)
 */
void HMS_FAST_Biquadm_Destroy(FAST_Biquadm* filter) __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroy a biquad instance (double-precision).
 *
 * @param filter Biquad filter.
 * @return NA
 *
 * @since 6.1.1(24)
 */
void HMS_FAST_Biquadm_DestroyD(FAST_BiquadmD* filter) __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Processes multi-channel audio through a biquad filter bank (single-precision).
 *
 * @param filter Initialized filter bank.
 * @param input Array of pointers to input channels (size = filter->numChannels).
 * @param strideInput Stride within each input channel. A value of 1 indicates contiguous storage.
 * @param output Array of pointers to output channels (size = filter->numChannels).
 * @param strideOutput Stride within each output channel. A value of 1 indicates contiguous storage.
 * @param length Number of frames to process (must ≤ filter->maxFrames).
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success.
 *         {@link FAST_ERROR_CODE_INVALID_PTR} {@link filter}, {@link coeff} or {@link output} is NULL.
 *         {@link FAST_ERROR_CODE_ILLEGAL_INPUT} {@link filter} is not initialized or {@link length} is out of range.
 *
 * @since 6.1.1(24)
 */
FAST_ErrorCode HMS_FAST_Biquadm(FAST_Biquadm* filter, const float** input, const size_t strideInput,
    float** output, const size_t strideOutput, size_t length)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Processes multi-channel audio through a biquad filter bank (double-precision).
 *
 * @param filter Initialized filter bank.
 * @param input Array of pointers to input channels (size = filter->numChannels).
 * @param strideInput Stride within each input channel. A value of 1 indicates contiguous storage.
 * @param output Array of pointers to output channels (size = filter->numChannels).
 * @param strideOutput Stride within each output channel. A value of 1 indicates contiguous storage.
 * @param length Number of frames to process (must ≤ filter->maxFrames).
 * @return {@link FAST_ERROR_CODE_SUCCESS} Success.
 *         {@link FAST_ERROR_CODE_INVALID_PTR} {@link filter}, {@link coeff} or {@link output} is NULL.
 *         {@link FAST_ERROR_CODE_ILLEGAL_INPUT} {@link filter} is not initialized or {@link length} is out of range.
 *
 * @since 6.1.1(24)
 */
FAST_ErrorCode HMS_FAST_BiquadmD(FAST_BiquadmD* filter, const double** input, const size_t strideInput,
    double** output, const size_t strideOutput, size_t length)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

#ifdef __cplusplus
}
#endif
#endif // FAST_DSP_COMMON_H

/** @} */
