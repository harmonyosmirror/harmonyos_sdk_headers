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
 * @file hiai_options.h
 * @kit HiAIFoundationKit
 * @library libhiai_foundation.so
 *
 * @brief Defines the API for build options.
 *
 * Allows you to update model shapes, and set dynamic shapes, data layout formats, operator fusion strategies,
 * quantization configurations, operator-level tuning, model-level tuning, assisted tuning, and bandwidth modes.
 *
 * @since 4.1.0(11)
 */
#ifndef HIAI_FOUNDATION_OPTIONS_H
#define HIAI_FOUNDATION_OPTIONS_H

#include "neural_network_runtime/neural_network_runtime_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Updates the model input's shape during model building.
 *
 * This method takes effect only in the model building phase and applies when the model structure and weight remain
 * unchanged but the shapes of model inputs need to be updated. The array size must be the same as the number of model
 * inputs. After the model is compiled, the model inputs' shapes will be updated. During inference, the input and output
 * data must comply with the new input and output description.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null.
 * @param inputTensorDescs Array of model inputs' shape list {@link NN_TensorDesc}. The value cannot be null.
 * @param shapeCount Number of input shapes, which must be consistent with the number of model inputs.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIOptions_SetInputTensorShapes(
    OH_NNCompilation* compilation, NN_TensorDesc* inputTensorDescs[], size_t shapeCount);

/**
 * @brief Queries the number of shape descriptions among the build options.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, 0 is returned.
 * @return Returns the number of shape descriptions among the build options if the operation is successful; returns 0
 * otherwise.
 * @since 4.1.0(11)
 */
size_t HMS_HiAIOptions_GetInputTensorShapeSize(const OH_NNCompilation* compilation);

/**
 * @brief Queries the shape description of a specific index among the build options.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, a null pointer is
 * returned.
 * @param index Index of the input shape. The value is [0, {@link HMS_HiAIOptions_GetInputTensorShapeSize}).
 * @return Returns the shape description among the build options if the operation is successful; returns a null pointer
 * otherwise.
 * @since 4.1.0(11)
 */
NN_TensorDesc* HMS_HiAIOptions_GetInputTensorShape(const OH_NNCompilation* compilation, size_t index);

/**
 * @brief Data layout formats during model building.
 * @since 4.1.0(11)
 */
typedef enum {
    /** NCHW format (default value). */
    HIAI_FORMAT_MODE_NCHW = 0,
    /** Original model format. */
    HIAI_FORMAT_MODE_ORIGIN = 1
} HiAI_FormatMode;

/**
 * @brief Sets the data layout format during model building.
 *
 * This method takes effect only in the model building phase and applies when the data layout formats are different from
 * the default values.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null.
 * @param formatMode Data layout formats {@link HiAI_FormatMode}.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIOptions_SetFormatMode(OH_NNCompilation* compilation, HiAI_FormatMode formatMode);

/**
 * @brief Queries the data layout format among build options.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, the default value
 * is returned.
 * @return Returns {@link HiAI_FormatModeOption} if the operation is successful; returns the default value otherwise.
 * @since 4.1.0(11)
 */
HiAI_FormatMode HMS_HiAIOptions_GetFormatMode(const OH_NNCompilation* compilation);

/**
 * @brief Indicates whether to enable variable shapes before model building.
 * @since 4.1.0(11)
 */
typedef enum {
    /** Disables variable shapes before model building. This is the default value. */
    HIAI_DYNAMIC_SHAPE_DISABLED = 0,
    /** Enables variable shapes before model building. */
    HIAI_DYNAMIC_SHAPE_ENABLED = 1
} HiAI_DynamicShapeStatus;

/**
 * @brief Modes supported for the variable shapes before model building.
 * @since 4.1.0(11)
 */
typedef enum {
    /** Caches the built model. This is the default mode and features small memory usage. */
    HIAI_DYNAMIC_SHAPE_CACHE_BUILT_MODEL = 0,
    /** Caches the loaded model. This mode provides better performance. */
    HIAI_DYNAMIC_SHAPE_CACHE_LOADED_MODEL = 1
} HiAI_DynamicShapeCacheMode;

/**
 * @brief Sets the EnableMode parameter in the variable shape configuration before model building.
 *
 * This method takes effect only in the model building phase and applies when the shape is expected to be updated in the
 * inference phase and the number of updated shapes does not exceed 10. This method must be used together with {@link
 * HMS_HiAIOptions_SetDynamicShapeMaxCache} and {@link HMS_HiAIOptions_SetDynamicShapeCacheMode}.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, an error code is
 * returned.
 * @param status Indicates whether to enable variable shapes before model building ({@link
 * HiAI_DynamicShapeStatus}).
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIOptions_SetDynamicShapeStatus(
    OH_NNCompilation* compilation, HiAI_DynamicShapeStatus status);

/**
 * @brief Sets the maximum number of cached models in the variable shape configuration before model building.
 *
 * This method takes effect only in the model building phase and applies when the shape is expected to be updated in the
 * inference phase and the number of updated shapes does not exceed 10. This method must be used together with {@link
 * HMS_HiAIOptions_SetDynamicShapeStatus} and {@link HMS_HiAIOptions_SetDynamicShapeCacheMode}.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, an error code is
 * returned.
 * @param maxCacheCount Maximum level. The value range is [1,10].
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIOptions_SetDynamicShapeMaxCache(
    OH_NNCompilation* compilation, size_t maxCacheCount);

/**
 * @brief Sets the cache mode in the variable shape configuration before model building.
 *
 * This method takes effect only in the model building phase and applies when the shape is expected to be updated in the
 * inference phase and the number of updated shapes does not exceed 10. This method must be used together with {@link
 * HMS_HiAIOptions_SetDynamicShapeStatus} and {@link HMS_HiAIOptions_SetDynamicShapeMaxCache}.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, an error code is
 * returned.
 * @param mode Cache mode for variable shapes before model building ({@link HiAI_DynamicShapeCacheMode}).
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIOptions_SetDynamicShapeCacheMode(
    OH_NNCompilation* compilation, HiAI_DynamicShapeCacheMode mode);

/**
 * @brief Queries the dynamic shape status parameter in the variable shape configuration before model building.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, the default value
 * is returned.
 * @return Returns {@link HiAI_DynamicShapeStatus} if the operation is successful; returns the default value otherwise.
 * @since 4.1.0(11)
 */
HiAI_DynamicShapeStatus HMS_HiAIOptions_GetDynamicShapeStatus(const OH_NNCompilation* compilation);

/**
 * @brief Queries the maximum number of caches in the variable shape configuration before model building.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, 0 is returned.
 * @return Returns the maximum number of caches if the operation is successful; returns 0 otherwise.
 * @since 4.1.0(11)
 */
size_t HMS_HiAIOptions_GetDynamicShapeMaxCache(const OH_NNCompilation* compilation);

/**
 * @brief Queries the cacheMode parameter in the variable shape configuration before model building.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, the default value
 * is returned.
 * @return Returns {@link HiAI_DynamicShapeCacheMode} if the operation is successful; returns the default value
 * otherwise.
 * @since 4.1.0(11)
 */
HiAI_DynamicShapeCacheMode HMS_HiAIOptions_GetDynamicShapeCacheMode(const OH_NNCompilation* compilation);

/**
 * @brief Device types supported for model running.
 * @since 4.1.0(11)
 */
typedef enum {
    /** NPU, which is the default value. */
    HIAI_EXECUTE_DEVICE_NPU = 0,
    /** CPU */
    HIAI_EXECUTE_DEVICE_CPU = 1,
    /** GPU */
    HIAI_EXECUTE_DEVICE_GPU = 2
} HiAI_ExecuteDevice;

/**
 * @brief Sets the list of devices to execute operators in the operator-level tuning configuration.
 *
 * This method takes effect only in the model building phase and cannot be used together with other tuning methods. It
 * specifies the list of devices to execute operators in the model. Make sure that the devices are sorted by priority
 * and operator names are unique. You can specify the device for some of the operators in the model. NPU will be used
 * preferentially for operators with no device specified. You can check the operator names using Netron, which is an
 * open-source tool.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, an error code is
 * returned.
 * @param operatorName Operator name. The value cannot be null. Otherwise, an error code is returned.
 * @param executeDevices List of supported device types {@link HiAI_ExecuteDevice}. The value cannot be null.
 * Otherwise, an error code is returned.
 * @param deviceCount Number of supported devices.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIOptions_SetOperatorDeviceOrder(
    OH_NNCompilation* compilation, const char* operatorName, HiAI_ExecuteDevice* executeDevices, size_t deviceCount);

/**
 * @brief Queries the number of devices to execute a specific operator in the model from the operator-level tuning
 * configuration.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, 0 is returned.
 * @param operatorName Operator name. The value cannot be null. Otherwise, 0 is returned.
 * @return Returns the number of devices to execute the operator if the operation is successful; returns 0 otherwise.
 * @since 4.1.0(11)
 */
size_t HMS_HiAIOptions_GetOperatorDeviceCount(const OH_NNCompilation* compilation, const char* operatorName);

/**
 * @brief Queries the list of devices to execute a specific operator in the model from the operator-level tuning
 * configuration.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, a null pointer is
 * returned.
 * @param operatorName Operator name. The value cannot be null. Otherwise, a null pointer is returned.
 * @return Returns the device list {@link HiAI_ExecuteDevice} if the operation is successful; returns a null pointer
 * otherwise.
 * @since 4.1.0(11)
 */
HiAI_ExecuteDevice* HMS_HiAIOptions_GetOperatorDeviceOrder(
    const OH_NNCompilation* compilation, const char* operatorName);

/**
 * @brief Sets the list of devices to execute the model in the model-level tuning configuration.
 *
 * This method takes effect only in the model building phase and cannot be used together with other tuning methods. It
 * specifies the list of devices that execute the model. The devices are sorted by priority. NPU takes the higher
 * priority by default.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, an error code is
 * returned.
 * @param executeDevices List of supported device types {@link HiAI_ExecuteDevice}. The value cannot be null.
 * Otherwise, an error code is returned.
 * @param deviceCount Number of supported devices.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIOptions_SetModelDeviceOrder(
    OH_NNCompilation* compilation, HiAI_ExecuteDevice* executeDevices, size_t deviceCount);

/**
 * @brief Queries the number of devices to execute the model in the model-level tuning configuration.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, 0 is returned.
 * @return Returns the number of devices to execute the model if the operation is successful; returns 0 otherwise.
 * @since 4.1.0(11)
 */
size_t HMS_HiAIOptions_GetModelDeviceCount(const OH_NNCompilation* compilation);

/**
 * @brief Queries the list of devices to execute the model in the model-level tuning configuration.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, a null pointer is
 * returned.
 * @return Returns the device list {@link HiAI_ExecuteDevice} if the operation is successful; returns a null pointer
 * otherwise.
 * @since 4.1.0(11)
 */
HiAI_ExecuteDevice* HMS_HiAIOptions_GetModelDeviceOrder(const OH_NNCompilation* compilation);

/**
 * @brief Indicates whether to allow HiAI Foundation to select other devices, such as the CPU, when the specified device
 * cannot build a model.
 * @since 4.1.0(11)
 */
typedef enum {
    /** Yes, which is the default value. */
    HIAI_FALLBACK_ENABLED = 0,
    /** No. */
    HIAI_FALLBACK_DISABLED = 1
} HiAI_FallbackMode;

/**
 * @brief Sets the fallback mode in the tuning configuration.
 *
 * This method takes effect only in the model building phase. It specifies whether to enable the fallback mode when the
 * specified device list is not supported, in operator-level or model-level tuning.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, an error code is
 * returned.
 * @param fallbackMode Indicates whether to enable the fallback mode ({@link HiAI_FallbackMode}).
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIOptions_SetFallbackMode(
    OH_NNCompilation* compilation, HiAI_FallbackMode fallbackMode);

/**
 * @brief Queries the fallback mode in the tuning configuration.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, the default value
 * is returned.
 * @return Returns {@link HiAI_FallbackMode} if the operation is successful; returns the default value otherwise.
 * @since 4.1.0(11)
 */
HiAI_FallbackMode HMS_HiAIOptions_GetFallbackMode(const OH_NNCompilation* compilation);

/**
 * @brief Device memory overcommitment option.
 * @since 4.1.0(11)
 */
typedef enum {
    /** Not used, which is the default value. */
    HIAI_DEVICE_MEMORY_REUSE_PLAN_UNSET = 0,
    /** Low memory overcommitment rate. In this mode, the memory requested by the model is large, but the model
       inference performance is better. */
    HIAI_DEVICE_MEMORY_REUSE_PLAN_LOW = 1,
    /** High memory overcommitment rate. In this mode, the memory requested by the model is small, but the model
       inference performance is inferior. */
    HIAI_DEVICE_MEMORY_REUSE_PLAN_HIGH = 2
} HiAI_DeviceMemoryReusePlan;

/**
 * @brief Sets the device memory overcommitment parameters in the tuning configuration.
 *
 * This method takes effect only in the model building phase. It specifies the device memory overcommitment mode during
 * tuning.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, an error code is
 * returned.
 * @param deviceMemoryReusePlan Device memory overcommitment mode {@link HiAI_DeviceMemoryReusePlan}.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIOptions_SetDeviceMemoryReusePlan(
    OH_NNCompilation* compilation, HiAI_DeviceMemoryReusePlan deviceMemoryReusePlan);

/**
 * @brief Queries the device memory overcommitment parameters in the tuning configuration.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, the default value
 * is returned.
 * @return Returns {@link HiAI_DeviceMemoryReusePlan} if the operation is successful; returns the default value
 * otherwise.
 * @since 4.1.0(11)
 */
HiAI_DeviceMemoryReusePlan HMS_HiAIOptions_GetDeviceMemoryReusePlan(const OH_NNCompilation* compilation);

/**
 * @brief Configuration options of the model tuning strategy.
 * @since 4.1.0(11)
 */
typedef enum {
    /** Neither in-depth convergence nor dynamic shape is supported, which is the default value. */
    HIAI_TUNING_STRATEGY_OFF = 0,
    /** In-depth convergence in dynamic shape mode is supported. */
    HIAI_TUNING_STRATEGY_ON_DEVICE_TUNING = 1,
    /** In-depth convergence is supported for dynamic update of the NPU operator library. */
    HIAI_TUNING_STRATEGY_ON_DEVICE_PREPROCESS_TUNING = 2,
    /** Reserved for future uses and not used currently. */
    HIAI_TUNING_STRATEGY_ON_CLOUD_TUNING = 3
} HiAI_TuningStrategy;

/**
 * @brief Sets the model tuning strategy during model building.
 *
 * This method takes effect only in the model building phase and applies for in-depth convergence.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, an error code is
 * returned.
 * @param tuningStrategy Model tuning strategy {@link HiAI_TuningStrategy}.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIOptions_SetTuningStrategy(
    OH_NNCompilation* compilation, HiAI_TuningStrategy tuningStrategy);

/**
 * @brief Queries the model tuning strategy.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, the default value
 * is returned.
 * @return Returns {@link HiAI_TuningStrategy} if the operation is successful; returns the default value otherwise.
 * @since 4.1.0(11)
 */
HiAI_TuningStrategy HMS_HiAIOptions_GetTuningStrategy(const OH_NNCompilation* compilation);

/**
 * @brief Sets the quantization configuration during model building.
 *
 * This method takes effect only in the model building phase and is used for quantization during model building.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, an error code is
 * returned.
 * @param data Data address of the quantization configuration. The value cannot be null. Otherwise, an error code
 * is returned.
 * @param size Data size of the quantization configuration. The value must be greater than 0. Otherwise, an error
 * code is returned.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIOptions_SetQuantConfig(OH_NNCompilation* compilation, void* data, size_t size);

/**
 * @brief Queries the data address of the quantization configuration.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, a null pointer is
 * returned.
 * @return Returns the data address of the quantization configuration if the operation is successful; returns a null
 * pointer otherwise.
 * @since 4.1.0(11)
 */
void* HMS_HiAIOptions_GetQuantConfigData(const OH_NNCompilation* compilation);

/**
 * @brief Queries the data size of the quantization configuration.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, 0 is returned.
 * @return Returns the data size of the quantization configuration if the operation is successful; returns 0 otherwise.
 * @since 4.1.0(11)
 */
size_t HMS_HiAIOptions_GetQuantConfigSize(const OH_NNCompilation* compilation);

/**
 * @brief Assisted tuning mode.
 * @since 4.1.0(11)
 */
typedef enum {
    /** Disables the tunning mode. */
    HIAI_TUNING_MODE_UNSET = 0,
    /** Automatic tuning mode, which is recommended. Tuning is controlled by the internal algorithm. */
    HIAI_TUNING_MODE_AUTO = 1,
    /** Heterogeneous tuning mode. */
    HIAI_TUNING_MODE_HETER = 2
} HiAI_TuningMode;

/**
 * @brief Selects the assisted tuning mode.
 *
 * This method takes effect only in the model building phase and cannot be used together with other tuning methods. It
 * enables HiAI-assisted tuning. This method must be used together with {@link HMS_HiAIOptions_SetTuningCacheDir}.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, an error code is
 * returned.
 * @param tuningMode Assisted tuning mode {@link HiAI_TuningMode}.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIOptions_SetTuningMode(OH_NNCompilation* compilation, HiAI_TuningMode tuningMode);

/**
 * @brief Sets the cache directory for assisted tuning.
 *
 * The user process must have the read and write permissions on the cache directory. This method must be used together
 * with {@link HMS_HiAIOptions_SetTuningMode}.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, an error code is
 * returned.
 * @param cacheDir Cache directory. The value cannot be null. Otherwise, an error code is returned.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIOptions_SetTuningCacheDir(OH_NNCompilation* compilation, const char* cacheDir);

/**
 * @brief Queries the assisted tuning mode.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, the default value
 * is returned.
 * @return Returns the assisted tuning mode {@link HiAI_TuningMode} if the operation is successful; returns the default
 * value otherwise.
 * @since 4.1.0(11)
 */
HiAI_TuningMode HMS_HiAIOptions_GetTuningMode(const OH_NNCompilation* compilation);

/**
 * @brief Queries the cache directory for assisted tuning.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, a null pointer is
 * returned.
 * @return Returns the cache directory if the operation is successful; returns a null pointer otherwise.
 * @since 4.1.0(11)
 */
const char* HMS_HiAIOptions_GetTuningCacheDir(const OH_NNCompilation* compilation);

/**
 * @brief Defines the inter-device bandwidth mode.
 * @since 4.1.0(11)
 */
typedef enum {
    /** Automatically adjusted by the system. */
    HIAI_BANDMODE_UNSET = 0,
    /** Low bandwidth mode. */
    HIAI_BANDMODE_LOW = 1,
    /** Medium bandwidth mode. */
    HIAI_BANDMODE_NORMAL = 2,
    /** High bandwidth mode. */
    HIAI_BANDMODE_HIGH = 3,
} HiAI_BandMode;

/**
 * @brief Sets the bandwidth mode for the NPU and peripheral input/output (I/O) devices.
 *
 * Set this parameter as required. Note that a high bandwidth will lead to a high consumption.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, an error code is
 * returned.
 * @param bandMode Bandwidth mode {@link HiAI_BandMode}.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 4.1.0(11)
 */
OH_NN_ReturnCode HMS_HiAIOptions_SetBandMode(OH_NNCompilation* compilation, HiAI_BandMode bandMode);

/**
 * @brief Queries the bandwidth mode.
 *
 * @param compilation Pointer to {@link OH_NNCompilation}. The value cannot be null. Otherwise, the default value
 * is returned.
 * @return Returns the bandwidth mode {@link HiAI_BandMode} if the operation is successful; returns the default value
 * otherwise.
 * @since 4.1.0(11)
 */
HiAI_BandMode HMS_HiAIOptions_GetBandMode(const OH_NNCompilation* compilation);

#ifdef __cplusplus
}
#endif

/** @} */
#endif // HIAI_FOUNDATION_OPTIONS_H
