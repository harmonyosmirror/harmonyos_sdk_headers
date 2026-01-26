/*
 * Copyright (c) 2025 Huawei Device Co., Ltd.
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
 * @addtogroup OHAudioSuite
 * @{
 *
 * @brief Provide the definition of the C interface for the audio module.
 *
 * @since 22
 * @version 1.0
 */
/**
 * @file native_audio_suite_engine.h
 *
 * @brief Declare audio suite engine related interfaces.
 *
 * This file interfaces are used for the creation of audioSuiteEngine
 * as well as creation of audioSuitePipeLine
 * as well as creation of audioSuiteNode
 *
 * @library libohaudiosuite.so
 * @syscap SystemCapability.Multimedia.Audio.SuiteEngine
 * @kit AudioKit
 * @since 22
 * @version 1.0
 */
#ifndef NATIVE_AUDIO_SUITE_ENGINE_H
#define NATIVE_AUDIO_SUITE_ENGINE_H
#include "info/application_target_sdk_version.h"
#include "native_audio_suite_base.h"
#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief Request to create the audio engine.
 *
 * @param audioSuiteEngine Pointer to a viriable to receive audioSuiteEngine.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds,
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if audioSuiteEngine is nullptr,
 * or {@link #AUDIOSUITE_ERROR_INVALID_STATE} if the engine is already created.
 * or {@link #AUDIOSUITE_ERROR_MEMORY_ALLOC_FAILED} if memory allocation failed.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_Create(OH_AudioSuiteEngine** audioSuiteEngine)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Request to release the engine.
 *
 * @param audioSuiteEngine Reference created by OH_AudioSuiteEngine_Create.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds,
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if audioSuiteEngine is nullptr,
 * or {@link #AUDIOSUITE_ERROR_INVALID_STATE} if audioSuiteEngine has not been created.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_Destroy(OH_AudioSuiteEngine* audioSuiteEngine)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Request to create the pipeline.
 *
 * The pipeline is the unit within the engine responsible for executing audio editing,
 * the engine can create multiple pipelines, and one pipeline must include at least one input node and one output node.
 * When the pipeline operates in {@link #AUDIOSUITE_PIPELINE_EDIT_MODE}, it supports all effect nodes.
 * When the pipeline operates in {@link #AUDIOSUITE_PIPELINE_REALTIME_MODE},
 * it only supports the {@link EFFECT_NODE_TYPE_EQUALIZER} effect node.
 *
 * @param audioSuiteEngine Reference created by OH_AudioSuiteEngine_Create.
 * @param audioSuitePipeline Pointer to a viriable to receive the pipeline.
 * @param workMode It indicates whether the pipeline is operating in Edit mode or real-time rendering mode.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is nullptr
 * or {@link #AUDIOSUITE_ERROR_ENGINE_NOT_EXIST} if the engine is not created.
 * or {@link #AUDIOSUITE_ERROR_CREATED_EXCEED_SYSTEM_LIMITS} if the number of created pipelines exceeds the upper limit.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_MEMORY_ALLOC_FAILED} if memory allocation failed.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_CreatePipeline(
    OH_AudioSuiteEngine* audioSuiteEngine,
    OH_AudioSuitePipeline** audioSuitePipeline, OH_AudioSuite_PipelineWorkMode workMode)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Request to release the pipeline.
 *
 * @param audioSuitePipeline Reference created by OH_AudioSuiteEngine_CreatePipeline.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds,
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. audioSuiteEngine is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_PIPELINE_NOT_EXIST} if pipeline does not exist or has already been destroyed.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_DestroyPipeline(OH_AudioSuitePipeline* audioSuitePipeline)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Request to start the pipeline.
 *
 * @param audioSuitePipeline Reference created by OH_AudioSuiteEngine_CreatePipeline.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds,
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. audioSuitePipeline is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_PIPELINE_NOT_EXIST} if pipeline does not exist or has already been destroyed.
 * or {@link #AUDIOSUITE_ERROR_INVALID_STATE} if the pipeline is already in running state
 * or the node connection is abnormal.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_StartPipeline(OH_AudioSuitePipeline* audioSuitePipeline)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Stop the pipeline and clear the node cache.
 *
 * This function will not alter the connection relationships between nodes in the pipeline.
 * Once the pipeline is stopped, {@link OH_AudioSuiteEngine_RenderFrame}
 * should not be used for executing audio processing.
 *
 * @param audioSuitePipeline Reference created by OH_AudioSuiteEngine_CreatePipeline.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. audioSuitePipeline is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_PIPELINE_NOT_EXIST} if pipeline does not exist or has already been destroyed.
 * or {@link #AUDIOSUITE_ERROR_INVALID_STATE} if the pipeline is already in stopped state.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_StopPipeline(OH_AudioSuitePipeline* audioSuitePipeline)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Request to get one pipeline state
 *
 * @param audioSuitePipeline Reference created by OH_AudioSuiteEngine_CreatePipeline.
 * @param pipelineState Pipeline state, which will be returned as the output parameter.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. audioSuitePipeline is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_PIPELINE_NOT_EXIST} if pipeline does not exist or has already been destroyed.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_GetPipelineState(
    OH_AudioSuitePipeline* audioSuitePipeline, OH_AudioSuite_PipelineState* pipelineState)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief The application uses this interface for audio data processing.
 *
 * The application needs to call this interface to retrieve the data processed with effects frame by frame.
 * After the application calls this interface,
 * the pipeline will sequentially fetch data from the output node forward, process the effects,
 * and ultimately fill the processed data into the audioData pointer passed by the application.
 * The pipeline will attempt to fill the data according to the requestFrameSize as much as possible,
 * and the actual size of the data processed by the pipeline will be returned to the application via responseSize.
 * The pipeline supports multiple input nodes,
 * each of which will obtain raw audio data from the application
 * through the data acquisition interface registered by the application.
 * When the application has handed over all the data prepared for each input node to the pipeline,
 * the application should pass a finish flag during the last callback.
 * Once all inputs in the pipeline have passed the finish flag,
 * the pipeline will inform the application through the finishedFlag in the OH_AudioSuiteEngine_RenderFrame interface
 * after processing is complete.
 * When finishedFlag is true, the application should no longer call this interface.
 *
 * @param audioSuitePipeline Reference created by OH_AudioSuiteEngine_CreatePipeline
 * @param audioData Audio data pointer, where user should read.
 * @param requestFrameSize Size of audio data user specified.
 * @param responseSize Size of audio data the system realy write.
 * @param finishedFlag This flag is used to indicate user whether all data processing has been completed.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is nullptr or not valid value.
 * or {@link #AUDIOSUITE_ERROR_PIPELINE_NOT_EXIST} if pipeline does not exist or has already been destroyed.
 * or {@link #AUDIOSUITE_ERROR_INVALID_STATE} if the pipeline is in the Stop state.
 * or {@link #AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION} if in the last call, finishedFlag was set to true.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_RenderFrame(OH_AudioSuitePipeline* audioSuitePipeline,
    void* audioData, int32_t requestFrameSize, int32_t* responseSize, bool* finishedFlag)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief The application uses this interface for audio data processing.
 *
 * For most nodes, a piece of data is obtained from the preceding node, processed,
 * and then passed on to the subsequent node.
 * For nodes with multiple outputs, such as the {@link EFFECT_MULTII_OUTPUT_NODE_TYPE_AUDIO_SEPARATION},
 * a piece of data is obtained from the preceding node, processed by an algorithm,
 * and then multiple pieces of data are passed on to the subsequent nodes.
 * If such nodes exist in the pipeline, this interface must be used to obtain the processed data.
 * The size of the audioDataArray should correspond one-to-one with the number of data outputs from the node.
 * For the audio source separation node, audioDataArray should have two elements:
 * the first element carries the vocal sound, and the second element carries the background sound.
 *
 * @param audioSuitePipeline Reference created by OH_AudioSuiteEngine_CreatePipeline.
 * @param audioDataArray Audio data array pointer, where user should read,
 * The size of each one-dimensional array should be consistent.
 * @param responseSize Size of audio data the system realy write,
 * The system ensures that the data size filled for each one-dimensional array is consistent.
 * @param finishedFlag This flag is used to indicate user whether all data processing has been completed.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is nullptr or not valid value.
 * or {@link #AUDIOSUITE_ERROR_PIPELINE_NOT_EXIST} if pipeline does not exist or has already been destroyed.
 * or {@link #AUDIOSUITE_ERROR_INVALID_STATE} if the pipeline is in the Stop state.
 * or {@link #AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION} if in the last call, finishedFlag was set to true.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_MultiRenderFrame(OH_AudioSuitePipeline* audioSuitePipeline,
    OH_AudioDataArray* audioDataArray, int32_t* responseSize, bool* finishedFlag)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Create a audio node builder which can be used to create an audio node
 *
 * The builder is a tool used to create nodes, and it can be utilized to set the properties of the nodes to be created.
 * After creating a node, the builder can be reused.
 * However, it must be noted that if the attributes of the new node are inconsistent with the previous node,
 * the application must use OH_AudioSuiteNodeBuilder_Reset to reset the builder.
 *
 * @param builder The builder reference to the created result.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. builder is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_MEMORY_ALLOC_FAILED} if memory allocation failed.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteNodeBuilder_Create(OH_AudioNodeBuilder** builder)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Destroy audio node builder.
 *
 * This function must be called when you are done using the builder.
 *
 * @param builder Reference created by OH_AudioSuiteNodeBuilder_Create.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. builder is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteNodeBuilder_Destroy(OH_AudioNodeBuilder* builder)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Reset audio node builder.
 *
 * If the application intends to reuse the builder to add new nodes
 * and the properties of the new nodes differ from those of the previously created nodes,
 * the application must call this interface to clear all properties, such as audio node type, e.t.c
 *
 * @param builder Reference created by OH_AudioSuiteNodeBuilder_Create.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. builder is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteNodeBuilder_Reset(OH_AudioNodeBuilder* builder)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Set the audio node type to be created by the builder.
 *
 * When creating a node, other parameters are validated based on the node type,
 * so this method needs to be executed for all types of nodes.
 *
 * @param builder Reference created by OH_AudioSuiteNodeBuilder_Create.
 * @param type Audio node type. {@link OH_AudioNode_Type}
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. builder is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteNodeBuilder_SetNodeType(OH_AudioNodeBuilder* builder, OH_AudioNode_Type type)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Set the audio format supported by the node.
 *
 * For {@link INPUT_NODE_TYPE_DEFAULT},
 * the set audioFormat is used to specify the format in which the application writes data.
 * For {@link OUTPUT_NODE_TYPE_DEFAULT},
 * the set audioFormat is used to specify the format in which the application ultimately wants to retrieve the data.
 * Other types of nodes do not support this setting.
 *
 * @param builder Reference created by OH_AudioSuiteNodeBuilder_Create.
 * @param audioFormat audio node format.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. builder is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_UNSUPPORTED_FORMAT} if an unsupported format is set in audioFormat.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteNodeBuilder_SetFormat(OH_AudioNodeBuilder* builder, OH_AudioFormat audioFormat)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Callback function of request data, Only {@link INPUT_NODE_TYPE_DEFAULT} support this setting.
 *
 * This function allows the application to write partial data which ranges from 0 to the audioDataSize.
 * The application should fill the data according to the size of audioDataSize.
 * When all the data from the application has been passed to the pipeline through the callback,
 * the application should set finished to true in the last callback.
 * When finished is set to true, the pipeline will no longer call this interface to obtain data from the application.
 *
 * @param audioNode AudioNode where this callback occurs.
 * @param userData User data which is passed by user.
 * @param audioData Audio data pointer, where user should fill in audio data.
 * @param audioDataSize Size of audio data that user should fill in.
 * @param finished This boolean value indicates that all data
 * of the application has been consumed since last execute {@link OH_AudioSuiteEngine_StartPipeline}.
 * @return Length of the valid data that has written into audioData buffer.
 * The return value must be in range of
 * [0, audioDataSize]. If the return value is less than 0,
 * the system changes it to 0. And, if the return value is
 * greater than audioDataSize, the system changes it to audioDataSize.
 * @since 22
 */
typedef int32_t (*OH_InputNode_RequestDataCallback)(
    OH_AudioNode* audioNode, void* userData, void* audioData, int32_t audioDataSize, bool* finished);

/**
 * @brief Set input node request data callback, Only {@link INPUT_NODE_TYPE_DEFAULT} support this setting.
 *
 * @param builder Reference created by OH_AudioSuiteNodeBuilder_Create.
 * @param callback Callback to functions that will write audio data.
 * @param userData Pointer to an application data structure that will be passed to the callback functions.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. builder is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteNodeBuilder_SetRequestDataCallback(
    OH_AudioNodeBuilder* builder, OH_InputNode_RequestDataCallback callback, void* userData)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Request to create audio node with audio node builder.
 *
 * When executing this function, the system will validate the parameters based on the audio node type in the builder.
 * The application can determine the cause of the error through the return value.
 * If more detailed error information is needed, please use the xx interface to obtain it.
 *
 * @param audioSuitePipeline Reference created by OH_AudioSuiteEngine_CreatePipeline.
 * @param builder Audio node builder created by OH_AudioSuiteNodeBuilder_Create.
 * @param audioNode Pointer to a viriable to receive the audio node.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds,
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is nullptr or not valid value.
 * or {@link #AUDIOSUITE_ERROR_CREATED_EXCEED_SYSTEM_LIMITS} the number of nodes
 * of the current type exceeds the pipeline limit.
 * or {@link #AUDIOSUITE_ERROR_REQUIRED_PARAMETERS_MISSING} if The input type is inputNode,
 * but no callback function is set,e.t.c.
 * or {@link #AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION} if the current constructor node type is output node but the
 * Callback function was set, or the constructor node type is an effect node but the audio format or callback
 * function was set.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_MEMORY_ALLOC_FAILED} if memory allocation failed.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_CreateNode(
    OH_AudioSuitePipeline* audioSuitePipeline, OH_AudioNodeBuilder* builder, OH_AudioNode** audioNode)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Destory an audio node.
 *
 * Whether the node can be deleted depends on the state of the pipeline it belongs to.
 * If the pipeline is not in the stopped state and the node is in an active processing path,
 * the operation will return that deletion is not supported.
 *
 * @param audioNode Reference created by OH_AudioSuiteEngine_CreateNode.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds,
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is nullptr,
 * or {@link #AUDIOSUITE_ERROR_NODE_NOT_EXIST} if audioNode does not exist or has been destroyed.
 * or {@link #AUDIOSUITE_ERROR_INVALID_STATE} if the pipeline is not stopped.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_DestroyNode(OH_AudioNode* audioNode)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Request to get audio node bypass status.
 *
 * Only effect node support bypass,
 * When application call this interface with an input node or output node,
 * it will return {@link #AUDIOSUITE_ERROR_INVALID_PARAM}
 *
 * @param audioNode Reference created by OH_AudioSuiteEngine_CreateNode.
 * @param bypassStatus node bypass status, which will be returned as the output parameter,
 * When the value of bypassStatusfalse is false, it indicates that the node has not been set to bypass;
 * when it is true, it means the node has been set to bypass.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. audioNode is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_NODE_NOT_EXIST} if audioNode does not exist or has been destroyed.
 * or {@link #AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION} if audioNode is not an effect node type.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_GetNodeBypassStatus(
    OH_AudioNode* audioNode, bool* bypassStatus)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Request to set the effect node bypass.
 *
 * This command can only be set to effect node. when bypass is set true,
 * the effect node only passes data to the next node without performing any effect processing.
 *
 * @param audioNode Reference created by OH_AudioSuiteEngine_CreateNode.
 * @param bypass This parameter determines whether the node merely forwards data transparently.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. audioNode is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_NODE_NOT_EXIST} if audioNode does not exist or has been destroyed.
 * or {@link #AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION} if the audioNode is not an effect node.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_BypassEffectNode(OH_AudioNode* audioNode, bool bypass)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Set the audio format for input and output nodes, specify the audio format of the audio source for
 * the input node, or specify the target audio format for the output node.
 *
 * @param audioNode Reference created by OH_AudioSuiteEngine_CreateNode.
 * @param audioFormat Audio Format.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is nullptr.
 * or {@link #AUDIOSUITE_ERROR_NODE_NOT_EXIST} if audioNode does not exist or has been destroyed.
 * or {@link #AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION} if the audioNode is an effect node.
 * or {@link #AUDIOSUITE_ERROR_INVALID_STATE} if the pipeline where the node resides is not in the stop state.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_SetAudioFormat(OH_AudioNode* audioNode, OH_AudioFormat *audioFormat)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Executing the connect command will link two nodes in sequence.
 *
 * Connect two nodes will alter the topology of the pipeline. This may result in partial data loss,
 * so it is recommended to perform this command when the engine is in stopped state.
 * Node connections follow a specific order: the input node is the starting point of the pipeline,
 * multiple effect nodes can be connected in between, and the output node is the endpoint of the pipeline.
 *
 * @param sourceAudioNode source node Reference created by OH_AudioSuiteEngine_CreateNode.
 * @param destAudioNode dest node Reference created by OH_AudioSuiteEngine_CreateNode.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. sourceAudioNode is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_INVALID_STATE} if pipline state is invalid, e.g. can not find output node, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_NODE_NOT_EXIST} if audioNode does not exist or has been destroyed.
 * or {@link #AUDIOSUITE_ERROR_UNSUPPORTED_CONNECT} if connections between two node types are not supported.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_ConnectNodes(
    OH_AudioNode* sourceAudioNode, OH_AudioNode* destAudioNode)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Executing the disconnect command will sever the connection between two nodes.
 * This command alters the pipeline's topology and may result in partial data loss.
 * It is recommended to perform this operation when the engine is in a stopped state.
 *
 * @param sourceAudioNode Preceding audio node Reference created by OH_AudioSuiteEngine_CreateNode.
 * @param destAudioNode Subsequent audio node Reference created by OH_AudioSuiteEngine_CreateNode.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. sourceAudioNode is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_INVALID_STATE} if pipline state is invalid, e.g. can not find output node, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_NODE_NOT_EXIST} if audioNode does not exist or has been destroyed.
 * or {@link #AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION} if sourceAudioNode and destAudioNode are the same node, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_DisconnectNodes(OH_AudioNode* sourceAudioNode, OH_AudioNode* destAudioNode)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Request to check whether the current system supports a specific node type.
 *
 * @param nodeType Audio node type. {@link OH_AudioNode_Type}
 * @param isSupported True means this node type is supported.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds,
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if param nullptr or not valid value.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_IsNodeTypeSupported(OH_AudioNode_Type nodeType, bool* isSupported)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Set equalier frequency band gains of audio node.
 *
 * @param audioNode Reference created by OH_AudioSuiteEngine_CreateNode.
 * @param frequencyBandGains The equalizer frequency band gains.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_NODE_NOT_EXIST} if audioNode does not exist or has been destroyed.
 * or {@link #AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION} if audioNode is not an equalizer node.
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. audioNode is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_SetEqualizerFrequencyBandGains(
    OH_AudioNode* audioNode, OH_EqualizerFrequencyBandGains frequencyBandGains)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Get equalier frequency band gains of audio node.
 *
 * @param audioNode Reference created by OH_AudioSuiteEngine_CreateNode.
 * @param frequencyBandGains Current equalizer frequency band gains of audioNode.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_NODE_NOT_EXIST} if audioNode does not exist or has been destroyed.
 * or {@link #AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION} if audioNode is not an equalizer node.
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. audioNode or
 * frequencyBandGains is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_GetEqualizerFrequencyBandGains(
    OH_AudioNode* audioNode, OH_EqualizerFrequencyBandGains* frequencyBandGains)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Set sound field type of audio node.
 *
 * @param audioNode Reference created by OH_AudioSuiteEngine_CreateNode.
 * @param soundFieldType The sound field type.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_NODE_NOT_EXIST} if audioNode does not exist or has been destroyed.
 * or {@link #AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION} if audioNode is not an soundfield node.
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. audioNode is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_SetSoundFieldType(OH_AudioNode* audioNode, OH_SoundFieldType soundFieldType)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Get sound field type of audio node.
 *
 * @param audioNode Reference created by OH_AudioSuiteEngine_CreateNode.
 * @param soundFieldType Current sound field type of audioNode.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_NODE_NOT_EXIST} if audioNode does not exist or has been destroyed.
 * or {@link #AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION} if audioNode is not an soundfield node.
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. audioNode or
 * soundFieldType is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_GetSoundFieldType(
    OH_AudioNode* audioNode, OH_SoundFieldType* soundFieldType)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Set environment type of audio node.
 *
 * @param audioNode Reference created by OH_AudioSuiteEngine_CreateNode.
 * @param environmentType The environment type.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_NODE_NOT_EXIST} if audioNode does not exist or has been destroyed.
 * or {@link #AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION} if audioNode is not an environment node.
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. audioNode is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_SetEnvironmentType(
    OH_AudioNode* audioNode, OH_EnvironmentType environmentType)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Get environment type of audio node.
 *
 * @param audioNode Reference created by OH_AudioSuiteEngine_CreateNode.
 * @param environmentType Current environment type of audioNode.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_NODE_NOT_EXIST} if audioNode does not exist or has been destroyed.
 * or {@link #AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION} if audioNode is not an environment node.
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. audioNode or
 * environmentType is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_GetEnvironmentType(
    OH_AudioNode* audioNode, OH_EnvironmentType* environmentType)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Set voice beautifier type of audio node.
 *
 * @param audioNode Reference created by OH_AudioSuiteEngine_CreateNode.
 * @param voiceBeautifierType the voice beautifier type.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_NODE_NOT_EXIST} if audioNode does not exist or has been destroyed.
 * or {@link #AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION} if audioNode is not an voiceBeautifier node.
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. audioNode is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_SetVoiceBeautifierType(
    OH_AudioNode* audioNode, OH_VoiceBeautifierType voiceBeautifierType)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Get voice beautifier type of audio node.
 *
 * @param audioNode Reference created by OH_AudioSuiteEngine_CreateNode.
 * @param voiceBeautifierType Current voice beautifier type of audioNode.
 * @return {@link #AUDIOSUITE_SUCCESS} if execution succeeds
 * or {@link #AUDIOSUITE_ERROR_NODE_NOT_EXIST} if audioNode does not exist or has been destroyed.
 * or {@link #AUDIOSUITE_ERROR_UNSUPPORTED_OPERATION} if audioNode is not an voiceBeautifier node.
 * or {@link #AUDIOSUITE_ERROR_INVALID_PARAM} if parameter is invalid, e.g. audioNode or
 * voiceBeautifierType is nullptr, e.t.c.
 * or {@link #AUDIOSUITE_ERROR_TIMEOUT} if an operation times out before completion.
 * or {@link #AUDIOSUITE_ERROR_SYSTEM} if the system has other abnormalities.
 * @since 22
 */
OH_AudioSuite_Result OH_AudioSuiteEngine_GetVoiceBeautifierType(
    OH_AudioNode* audioNode, OH_VoiceBeautifierType* voiceBeautifierType)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

#ifdef __cplusplus
}
#endif
/** @} */
#endif // NATIVE_AUDIO_SUITE_ENGINE_H