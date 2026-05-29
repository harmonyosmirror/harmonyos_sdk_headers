/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

/**
 * @addtogroup CANN
 * @{
 *
 * @brief Provides APIs for LLM model inference.
 * @since 6.1.1(24)
 */

/**
 * @file llm_engine.h
 *
 * @brief Defines the API for LLM model inference.
 *
 * @library libhiai_foundation.so
 * @kit CANNKit
 * @syscap SystemCapability.AI.CANN.LLMEngine
 * @since 6.1.1(24)
 */
#ifndef CANN_LLM_ENGNIE_H
#define CANN_LLM_ENGNIE_H

#include "info/application_target_sdk_version.h"
#include "neural_network_runtime/neural_network_runtime_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines the alias for the LLM engine context.
 * @since 6.1.1(24)
 */
typedef struct HMS_LLMEngine_Context HMS_LLMEngine_Context;

/**
 * @brief Creates an LLM engine context handle using a JSON configuration file.
 * @param jsonFile Path of the JSON configuration file, which cannot be empty.
 * @return Created LLM engine context handle.
 * @since 6.1.1(24)
 */
HMS_LLMEngine_Context* HMS_LLMEngineContext_CreateFromContextJson(const char* jsonFile)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroys the LLM engine context.
 * @param ctx Context to be destroyed.
 * @since 6.1.1(24)
 */
void HMS_LLMEngine_Context_Destroy(HMS_LLMEngine_Context** ctx)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief LLM engine executor.
 * @since 6.1.1(24)
 */
typedef struct HMS_LLMEngine_Executor HMS_LLMEngine_Executor;

/**
 * @brief Creates an LLM engine executor handle using a JSON configuration file.
 * @param jsonFile Path of the JSON configuration file, which cannot be empty.
 * @return Created LLM engine executor handle.
 * @since 6.1.1(24)
 */
HMS_LLMEngine_Executor* HMS_LLMEngineExecutor_CreateFromExecutorJson(const char* jsonFile)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroys an LLM engine executor.
 * @param executor Executor to be destroyed.
 * @since 6.1.1(24)
 */
void HMS_LLMEngineExecutor_Destroy(HMS_LLMEngine_Executor** executor)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Prompt input.
 * @since 6.1.1(24)
 */
typedef struct HMS_LLMEngine_Prompt HMS_LLMEngine_Prompt;

/**
 * @brief Creates an LLM engine prompt handle.
 * @return Created LLM engine prompt handle.
 * @since 6.1.1(24)
 */
HMS_LLMEngine_Prompt* HMS_LLMEnginePrompt_Create(void) __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the text input.
 * @param prompt Pointer to {@link HMS_LLMEngine_Prompt}. The value cannot be null.
 * @param text Text prompt.
 * @return Function execution result. If the operation is successful, OH_NN_SUCCESS is returned. Otherwise, an error
 *     code is returned.
 * For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 6.1.1(24)
 */
OH_NN_ReturnCode HMS_LLMEnginePrompt_SetText(HMS_LLMEngine_Prompt* prompt, const char* text)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the input token IDs.
 * @param prompt Pointer to {@link HMS_LLMEngine_Prompt}. The value cannot be null.
 * @param tokenIds Token IDs to be set to the prompt.
 * @param tokenNum Number of Token IDs.
 * @return Function execution result. If the operation is successful, OH_NN_SUCCESS is returned. Otherwise, an error
 *     code is returned.
 * For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 6.1.1(24)
 */
OH_NN_ReturnCode HMS_LLMEnginePrompt_SetTokenId(HMS_LLMEngine_Prompt* prompt, int32_t* tokenIds, uint32_t tokenNum)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroys the LLM engine prompt handle.
 * @param prompt LLM engine prompt handle to be destroyed.
 * @since 6.1.1(24)
 */
void HMS_LLMEnginePrompt_Destroy(HMS_LLMEngine_Prompt** prompt)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Generates a callback function.
 * @since 6.1.1(24)
 */
typedef void(*callbackFunctionType)(const HMS_LLMEngine_Context*);

/**
 * @brief Sets the callback function triggered during token generation.
 * @param ctx Pointer to {@link HMS_LLMEngine_Context}. The value cannot be null.
 * @param func Context callback function.
 * @return Function execution result. If the operation is successful, OH_NN_SUCCESS is returned. Otherwise, an error
 *     code is returned.
 * For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 6.1.1(24)
 */
OH_NN_ReturnCode HMS_LLMEngineContext_SetOnOneTokenGenerateDoneFunc(HMS_LLMEngine_Context* ctx,  callbackFunctionType func)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the callback function triggered when all tokens are generated.
 * @param ctx Pointer to {@link HMS_LLMEngine_Context}. The value cannot be null.
 * @param func Context callback function.
 * @return Function execution result. If the operation is successful, OH_NN_SUCCESS is returned. Otherwise, an error
 *     code is returned.
 * For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 6.1.1(24)
 */
OH_NN_ReturnCode HMS_LLMEngineContext_SetOnAllTokensGenerateDoneFunc(HMS_LLMEngine_Context* ctx, callbackFunctionType func)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the callback function triggered upon generation failure.
 * @param ctx Pointer to {@link HMS_LLMEngine_Context}. The value cannot be null.
 * @param func Context callback function.
 * @return Function execution result. If the operation is successful, OH_NN_SUCCESS is returned. Otherwise, an error
 *     code is returned.
 * For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 6.1.1(24)
 */
OH_NN_ReturnCode HMS_LLMEngineContext_SetOnGenerateAsyncFailed(HMS_LLMEngine_Context* ctx, callbackFunctionType func)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Obtains the length of a generated text chunk.
 * @param ctx Pointer to {@link HMS_LLMEngine_Context}. The value cannot be null.
 * @param len Length of the generated text chunk.
 * @return Function execution result. If the operation is successful, OH_NN_SUCCESS is returned. Otherwise, an error
 *     code is returned.
 * For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 6.1.1(24)
 */
OH_NN_ReturnCode HMS_LLMEngineContext_GetOneGenerationLen(const HMS_LLMEngine_Context* ctx, uint32_t* len)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Obtains a generated text chunk.
 * @param ctx Pointer to {@link HMS_LLMEngine_Context}. The value cannot be null.
 * @param generation Pointer to the generated text chunk.
 * @param len Length of the generated text chunk.
 * @return Function execution result. If the operation is successful, OH_NN_SUCCESS is returned. Otherwise, an error
 *     code is returned.
 * For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 6.1.1(24)
 */
OH_NN_ReturnCode HMS_LLMEngineContext_GetOneGeneration(const HMS_LLMEngine_Context* ctx, char* generation, uint32_t len)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the lenght of all generated text.
 * @param ctx Pointer to {@link HMS_LLMEngine_Context}. The value cannot be null.
 * @param len the lenght of all generated text.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 6.1.1(24)
 */
OH_NN_ReturnCode HMS_LLMEngineContext_GetAllGenerationLen(const HMS_LLMEngine_Context* ctx, uint32_t* len)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get all generated text.
 * @param ctx Pointer to {@link HMS_LLMEngine_Context}. The value cannot be null.
 * @param generation the pointer of all generated text.
 * @param len the lenght of all generated text.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 6.1.1(24)
 */
OH_NN_ReturnCode HMS_LLMEngineContext_GetAllGeneration(const HMS_LLMEngine_Context* ctx, char* generation, uint32_t len)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Obtains a generated token ID.
 * @param ctx Pointer to {@link HMS_LLMEngine_Context}. The value cannot be null.
 * @param genToken Pointer to the generated token ID.
 * @return Function execution result. If the operation is successful, OH_NN_SUCCESS is returned. Otherwise, an error
 *     code is returned.
 * For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 6.1.1(24)
 */
OH_NN_ReturnCode HMS_LLMEngineContext_GetOneTokenGeneration(const HMS_LLMEngine_Context* ctx, int32_t* genToken)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the lenght of all generated tokenids.
 * @param ctx Pointer to {@link HMS_LLMEngine_Context}. The value cannot be null.
 * @param len the lenght of all generated tokenids.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 6.1.1(24)
 */
OH_NN_ReturnCode HMS_LLMEngineContext_GetAllTokenGenerationLen(const HMS_LLMEngine_Context* ctx, uint32_t* len)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get all generated tokenids.
 * @param ctx Pointer to {@link HMS_LLMEngine_Context}. The value cannot be null.
 * @param genToken the pointer of generated tokenids.
 * @param len the lenght of all generated tokenids.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 6.1.1(24)
 */
OH_NN_ReturnCode HMS_LLMEngineContext_GetAllTokenGeneration(const HMS_LLMEngine_Context* ctx, int32_t* genToken, uint32_t len)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Performs synchronous LLM inference.
 * @param executor Pointer to {@link HMS_LLMEngine_Executor}. The value cannot be null.
 * @param ctx Pointer to {@link HMS_LLMEngine_Context}. The value cannot be null.
 * @param prompt Input for synchronous LLM inference.
 * @return Function execution result. If the operation is successful, OH_NN_SUCCESS is returned. Otherwise, an error
 *     code is returned.
 * For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 6.1.1(24)
 */
OH_NN_ReturnCode HMS_LLMEngineExecutor_Generate(HMS_LLMEngine_Executor* executor, HMS_LLMEngine_Context* ctx, const HMS_LLMEngine_Prompt* prompt)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Performs asynchronous LLM inference.
 * @param executor Pointer to {@link HMS_LLMEngine_Executor}. The value cannot be null.
 * @param ctx Pointer to {@link HMS_LLMEngine_Context}. The value cannot be null.
 * @param prompt Input for asynchronous LLM inference.
 * @return Function execution result. If the operation is successful, OH_NN_SUCCESS is returned. Otherwise, an error
 *     code is returned.
 * For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 6.1.1(24)
 */
OH_NN_ReturnCode HMS_LLMEngineExecutor_GenerateAsync(HMS_LLMEngine_Executor* executor, HMS_LLMEngine_Context* ctx, const HMS_LLMEngine_Prompt* prompt)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief infer perfmode.
 * @since 6.1.1(24)
 */
typedef enum {
    /** infer perfmode unset. */
    HMS_LLMENGINE_INFERPERF_UNSET = 0,
    /** Low inference performance mode. */
    HMS_LLMENGINE_INFERPERF_LOW,
    /** middle inference perfmode. */
    HMS_LLMENGINE_INFERPERF_MIDDLE,
    /** high inference perfmode. */
    HMS_LLMENGINE_INFERPERF_HIGH,
    /** Extreme high inference performance mode. */
    HMS_LLMENGINE_INFERPERF_EXTREME_HIGH,
} HMS_LLMEngine_InferPerfMode;

/**
 * @brief set infer perf mode.
 * @param executor Pointer to {@link HMS_LLMEngine_Executor}. The value cannot be null.
 * @param inferPerfMode {@link HMS_LLMEngine_InferPerfMode}. The value cannot be null.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 6.1.1(24)
 */
OH_NN_ReturnCode HMS_LLMEngineExecutor_SetInferencePerfMode(HMS_LLMEngine_Executor* executor, HMS_LLMEngine_InferPerfMode inferPerfMode)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief total generation time in ms.
 * @param ctx Pointer to {@link HMS_LLMEngine_Context}. The value cannot be null.
 * @param ms total generation time in ms.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 6.1.1(24)
 */
OH_NN_ReturnCode HMS_LLMEngineContext_GetTotalTimeMs(const HMS_LLMEngine_Context* ctx, double* ms)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief prefill time in ms.
 * @param ctx Pointer to {@link HMS_LLMEngine_Context}. The value cannot be null.
 * @param ms prefill time in ms.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 6.1.1(24)
 */
OH_NN_ReturnCode HMS_LLMEngineContext_GetPrefillTimeMs(const HMS_LLMEngine_Context* ctx, double* ms)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief decode time in ms.
 * @param ctx Pointer to {@link HMS_LLMEngine_Context}. The value cannot be null.
 * @param ms decode time in ms.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 6.1.1(24)
 */
OH_NN_ReturnCode HMS_LLMEngineContext_GetDecodeTimeMs(const HMS_LLMEngine_Context* ctx, double* ms)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief input token count.
 * @param ctx Pointer to {@link HMS_LLMEngine_Context}. The value cannot be null.
 * @param count input token count.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 6.1.1(24)
 */
OH_NN_ReturnCode HMS_LLMEngineContext_GetInputTokenCount(const HMS_LLMEngine_Context* ctx, uint64_t* count)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief output token count.
 * @param ctx Pointer to {@link HMS_LLMEngine_Context}. The value cannot be null.
 * @param count output token count.
 * @return Function execution result. Returns OH_NN_SUCCESS if the operation is successful; returns an error code
 * otherwise. For details about the error codes, see {@link OH_NN_ReturnCode}.
 * @since 6.1.1(24)
 */
OH_NN_ReturnCode HMS_LLMEngineContext_GetOutputTokenCount(const HMS_LLMEngine_Context* ctx, uint64_t* count)
__attribute__((__availability__(ohos, introduced=24.0.0)));

#ifdef __cplusplus
}
#endif

/** @} */
#endif // CANN_LLM_ENGNIE_H
