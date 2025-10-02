/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

/**
 * @addtogroup GraphicsAccelerate
 * @{
 *
 * @brief Provides APIs for graphics accelerate capability.
 *
 * @syscap SystemCapability.GraphicsGame.RenderAccelerate
 * @since 5.0.0(12)
 */

/**
 * @file frame_generation_vk.h
 * @kit GraphicsAccelerateKit
 *
 * @brief Defines the APIs of Frame Generation dedicated to the Vulkan API platform.
 *
 * Allows you to create Frame Generaion context on Vulkan platform, configure context attributes, activate
 * context, deactivate context, create input and output image instance, draw predicted frames with dispatch Info
 * and destroy context instance.
 *
 * @library libframegeneration.so
 * @syscap SystemCapability.GraphicsGame.RenderAccelerate
 * @since 5.0.0(12)
 */

#ifndef FRAME_GENERATION_VK_H
#define FRAME_GENERATION_VK_H

#include <stdbool.h>
#include <vulkan/vulkan.h>

#include "frame_generation_base.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Frame Generation context on Vulkan platform.
 * @since 5.0.0(12)
 */
struct FG_Context_VK;
typedef struct FG_Context_VK FG_Context_VK;

/**
 * @brief Frame generation input and output image struct for Vulkan platform.
 * @since 5.0.0(12)
 */
struct FG_Image_VK;
typedef struct FG_Image_VK FG_Image_VK;

/**
 * @brief Defines a structure encapsulating the parameters required to initialize FG_Context_VK.
 * @since 5.0.0(12)
 */
typedef struct FG_ContextDescription_VK {
    /** Vulkan instance handle, the instance must be valid throughout the lifetime of the FG_Context_VK. */
    VkInstance vkInstance;
    /** Vulkan physical device handle, the device must be valid throughout the lifetime of the FG_Context_VK. */
    VkPhysicalDevice vkPhysicalDevice;
    /** Vulkan logical device handle, the device must be valid throughout the lifetime of the FG_Context_VK. */
    VkDevice vkDevice;
    /**
     * Specifies how many frames can be "in flight".
     * For example, if the next frame is being rendered ONLY AFTER the previous one has been presented,
     * than `framesInFlight` should be set to 1.
     * For example, if the next frame is being rendered WHILE the previous one is being presented,
     * than `framesInFlight` should be set to 2.
     * Note: Must not be zero!
     */
    uint8_t framesInFlight;
    /** Function pointer to Vulkan's vkGetInstanceProcAddr. Must not be NULL. */
    PFN_vkGetInstanceProcAddr fnVulkanLoaderFunction;
} FG_ContextDescription_VK;

/**
 * @brief Defines the image format of input scene color, depth/stencil and final predicted image.
 * @since 5.0.0(12)
 */
typedef struct FG_ImageFormat_VK {
    /** Opauqe scene color image format. */
    VkFormat inputColorFormat;
    /** Depth stencil image format. */
    VkFormat inputDepthStencilFormat;
    /** Predicted output color image format. */
    VkFormat outputColorFormat;
} FG_ImageFormat_VK;

/**
 * @brief In order for Frame Generation to setup image barriers correctly, {@link FG_ImageSync_VK} struct is used
 * (for each needed image).
 * @since 5.0.0(12)
 */
typedef struct FG_ImageSync_VK {
    /** Bitmask specifying memory access types that will participate in a memory dependency. */
    VkAccessFlagBits accessMask;
    /** Layout of image and image subresources. */
    VkImageLayout layout;
    /** Bitmask specifying pipeline stages. */
    VkPipelineStageFlagBits stages;
} FG_ImageSync_VK;

/**
 * @brief Defines the Frame Generation input and output image information.
 * @since 5.0.0(12)
 */
typedef struct FG_ImageInfo_VK {
    /** Frame Generation image handle which {@link HMS_FG_CreateImage} returns. */
    FG_Image_VK* image;
    /** Previous usage of the image in order to setup image barriers correctly. */
    FG_ImageSync_VK initialSync;
    /** Desired future usage of the image after {@link HMS_FG_Dispatch_VK}. */
    FG_ImageSync_VK finalSync;
} FG_ImageInfo_VK;

/**
 * @brief Defines Frame Generation dispatch info struct which specifies the required attributes to predict frames,
 * only for Vulkan platform.
 * @since 5.0.0(12)
 */
typedef struct FG_DispatchDescription_VK {
    /** Image instance of opaque scene color image. */
    FG_ImageInfo_VK inputColorInfo;
    /** Image instance of depth/stencil texture with scene information. */
    FG_ImageInfo_VK inputDepthStencilInfo;
    /** Image instance of predicted frame. */
    FG_ImageInfo_VK outputColorInfo;
    /**
     * Composite view-projection matrix which was used for rendering opaque scene.
     * Corresponding to transformation from world-space coordinates to clip-space coordinates.
     */
    FG_Mat4x4 viewProj;
    /**
     * Inverse matrix from {@link viewProj}.
     * Corresponds to transformation from clip-space coordinates to world-space coordinates.
     */
    FG_Mat4x4 invViewProj;
    /** Vulkan command buffer to which Frame Generation will record its commands. */
    VkCommandBuffer vkCommandBuffer;
    /**
     * Current frame's index. Must be less than `framesInFlight` which was passed to
     * {@link FG_ContextDescription_VK}.
     */
    uint8_t frameIdx;
} FG_DispatchDescription_VK;

/**
 * @brief Creates the frame generation context instance on Vulkan platform. The context structure is the main object
 * used to interact with Frame Generation APIs, and is reponsible for the management of the internal resources used by
 * the Frame Generation algorithm.
 *
 * @param contextDescription Pointer to the {@link FG_ContextDescription_VK}.The object specifies the attributes
 * used to create a frame prediction context instance. The value can not be null.
 * @return Returns the pointer to a {@link FG_Context_VK} context instance.
 * @since 5.0.0(12)
 */
FG_Context_VK* HMS_FG_CreateContext_VK(const FG_ContextDescription_VK* contextDescription);

/**
 * @brief Provide the selection of the prediction mode and motion vector estimation mode of Frame Generation.
 *
 * @param context Pointer to the {@link FG_Context_VK} instance. The value can not be null. Otherwise, an error
 * code is returned.
 * @param predictionModeInfo Pointer to the {@link FG_AlgorithmModeInfo} instance. The object specifies prediction
 * mode and motion vector estimation mode. The value can not be null. Otherwise, an error code is returned.
 * @return Execution result of the function. If the operation is successful, <b>FG_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_SetAlgorithmMode_VK(FG_Context_VK* context, const FG_AlgorithmModeInfo* predictionModeInfo);

/**
 * @brief Provide the resolution in pixels of frame generation input and output images.
 *
 * @param context Pointer to the {@link FG_Context_VK} instance. The value can not be null. Otherwise, an error
 * code is returned.
 * @param resolutionInfo Pointer to the {@link FG_ResolutionInfo} instance. The object specifies the resolution
 * in pixels of frame generation input and output images. The value can't be null. Otherwise, an error code is returned.
 * @return Execution result of the function. If the operation is successful, <b>FG_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_SetResolution_VK(FG_Context_VK* context, const FG_ResolutionInfo* resolutionInfo);

/**
 * @brief Provide the Z range semantic of projection matrix used by application.
 *
 * @param context Pointer to the {@link FG_Context_VK} instance. The value can not be null. Otherwise, an error
 * code is returned.
 * @param semantic One of the enumeration values.
 * @return Execution result of the function. If the operation is successful, <b>FG_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_SetCvvZSemantic_VK(FG_Context_VK* context, FG_CvvZSemantic semantic);

/**
 * @brief Provide frame generation input and output image formats.
 *
 * @param context Pointer to the {@link FG_Context_VK} instance. The value can not be null. Otherwise, an error
 * code is returned.
 * @param format Image format of input scene color, input depth/stencil and final predicted image.
 * @return Execution result of the function. If the operation is successful, <b>FG_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_SetImageFormat_VK(FG_Context_VK* context, const FG_ImageFormat_VK* format);

/**
 * @brief This should be called when color buffer is Y axis inverted relative to Depth/Stencil buffer.
 *
 * @param context Pointer to the {@link FG_Context_VK} instance. The value can not be null. Otherwise, an error
 * code is returned.
 * @param inverted The value is 'true' when color buffer is Y axis inverted relative to Depth/Stencil buffer.
 * @return Execution result of the function. If the operation is successful, <b>FG_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_SetDepthStencilYDirectionInverted_VK(FG_Context_VK* context, bool inverted);

/**
 * @brief Make connection between user provided images and internal implementation and returns an image instance
 * handle which represents this connection.
 *
 * @param context Pointer to the {@link FG_Context_VK} instance. The value can not be null. Otherwise, an error
 * code is returned.
 * @param image Image handle.
 * @param view Image view handle.
 * @return The image instance handle which represents the connection.
 * @since 5.0.0(12)
 */
FG_Image_VK* HMS_FG_CreateImage_VK(FG_Context_VK* context, VkImage image, VkImageView view);

/**
 * @brief Destroy connection between user provided images and internal implementation and destroy the image instance.
 *
 * @param context Pointer to the {@link FG_Context_VK} instance. The value can not be null. Otherwise, an error
 * code is returned.
 * @param image FG_Image_VK image instance handle.
 * @return Execution result of the function. If the operation is successful, <b>FG_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_DestroyImage_VK(FG_Context_VK* context, FG_Image_VK* image);

/**
 * @brief Activate Frame Generation instance on Vulkan platform. An "activated" instance is ready to draw frames.
 * In order to activate it, some set functions must be called. In case of any errors,
 * the instance is considered to be inactive.
 *
 * @param context Pointer to the {@link FG_Context_VK} instance. The value cannot be null.
 * Otherwise, an error code is returned.
 * @return Execution result of the function. If the operation is successful, <b>FG_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_Activate_VK(FG_Context_VK* context);

/**
 * @brief Deactivate Frame Generation instance on Vulkan platform.
 *
 * @param context Pointer to the {@link FG_Context_VK} instance. The value cannot be null.
 * Otherwise, an error code is returned.
 * @return Execution result of the function. If the operation is successful, <b>FG_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_Deactivate_VK(FG_Context_VK* context);

/**
 * @brief Query if the frame generation instance is currently activated.
 *
 * @param context Pointer to the {@link FG_Context_VK} instance.
 * @param isActive Active status of {@link FG_Context_VK} instance.
 * 'true' : instance is activated;
 * 'false' : instance is deactivated.
 * @return Execution result of the function. If the operation is successful, <b>FG_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_IsActive_VK(FG_Context_VK* context, bool* isActive);

/**
 * @brief Sets all required data for prediction of a frame to draw predicted frames on Vulkan platform.
 *
 * @param context Pointer to the {@link FG_Context_VK} instance. The value can not be null.
 * @param desc Pointer to the {@link FG_DispatchDescription_VK}. The object specifies the dispatch attributes
 * used by executing frame prediction. The value can not be null.
 * @return Function execution result. If the operation is successful, FG_SUCCESS is returned. If the operation fails,
 * an error code is returned. For details about the error codes, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_Dispatch_VK(FG_Context_VK* context, const FG_DispatchDescription_VK* desc);

/**
 * @brief Destroy Frame Generation instance and memory resource reclamation on Vulkan platform.
 *
 * @param context Level-2 pointer to the {@link FG_Context_VK} instance to destroy.
 * @return Execution result of the function. If the operation is successful, <b>FG_SUCCESS</b> is returned.
 * If the operation fails, an error code is returned. For details, see {@link FG_ErrorCode}.
 * @since 5.0.0(12)
 */
FG_ErrorCode HMS_FG_DestroyContext_VK(FG_Context_VK** context);

/**
 * @brief Set the frame prediction integration information on the vulkan platform.
 * @param context Pointer to the {@link FG_Context_VK} instance.
 * The value can not be null. Otherwise, an error code is returned.
 * @param integrationInfo Include integration information such as present mode,
 * whether the game caches textures, and whether the color textures need to be flipped.
 * @return Function execution result. If the operation is successful, FG_SUCCESS is returned. If the operation fails,
 * an error code is returned. For details about the error codes, see {@link FG_ErrorCode}.
 * @since 5.1.0(18)
 */
FG_ErrorCode HMS_FG_SetIntegrationMode_VK(FG_Context_VK* context, const FG_IntegrationInfo* integrationInfo);

/**
 * @brief Select whether to enable the UI prediction feature on the vulkan platform.
 * This feature can only be enabled in the system present mode. It has no effect in the game present mode.
 * @param context Pointer to the {@link FG_Context_VK} instance.
 * The value can not be null. Otherwise, an error code is returned.
 * @param isEnabled If the parameter is true, the UI prediction feature is enabled. If false, this feature is disabled.
 * @return Function execution result. If the operation is successful, FG_SUCCESS is returned. If the operation fails,
 * an error code is returned. For details about the error codes, see {@link FG_ErrorCode}.
 * @since 5.1.0(18)
 */
FG_ErrorCode HMS_FG_SetUiPredictionEnabled_VK(FG_Context_VK* context, bool isEnabled);

/**
 * @brief Set the target frame rate after enabling frame prediction on the vulkan platform.
 * This setting only takes effect in the system present mode and has no impact in the game present mode.
 * @param context Pointer to the {@link FG_Context_VK} instance.
 * The value can not be null. Otherwise, an error code is returned.
 * @param targetFps The parameter is the target frame rate after enabling frame prediction,
 * setting how many frames present per second.
 * @return Function execution result. If the operation is successful, FG_SUCCESS is returned. If the operation fails,
 * an error code is returned. For details about the error codes, see {@link FG_ErrorCode}.
 * @since 5.1.0(18)
 */
FG_ErrorCode HMS_FG_SetTargetFps_VK(FG_Context_VK* context, int targetFps);

#ifdef __cplusplus
};
#endif // __cplusplus

/** @} */
#endif // FRAME_GENERATION_VK_H