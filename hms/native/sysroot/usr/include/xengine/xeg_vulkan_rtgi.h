/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */

/**
 * @addtogroup XEngine
 * @{
 *
 * @brief Provides APIs related to XEngine graphics capabilities.
 *
 * @syscap SystemCapability.Graphic.XEngine
 * @since 6.0.0(20)
 */

/**
 * @file xeg_vulkan_rtgi.h
 * @kit XEngineKit
 * @library libxengine.so
 *
 * @brief XEngine Vulkan APIs for the Ray-Traced Global Illumination feature, which provides two features:
 * Dynamic Diffuse Global Illumination (DDGI) and Neural Network Global Illumination (NNGI).
 * Before using the APIs in this header file, call {@link HMS_XEG_EnumerateDeviceExtensionProperties} to check
 * whether the {@link XEG_RTGI_EXTENSION_NAME} extension is available.
 * @syscap SystemCapability.Graphic.XEngine
 * @since 6.0.0(20)
 */

#ifndef XEG_VULKAN_RTGI_H
#define XEG_VULKAN_RTGI_H

#include "info/application_target_sdk_version.h"
#include <stdbool.h>
#include <vulkan/vulkan.h>
#include "xeg_vulkan_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Handle to {@link XEG_RTGI}.
 *
 * @since 6.0.0(20)
 */
VK_DEFINE_HANDLE(XEG_RTGI)

/**
 * @brief Enum for the quality modes of output images.
 *
 * @since 6.0.0(20)
 */
typedef enum XEG_RTGIQualityMode {
    /** Quality mode. */
    XEG_RTGI_QUALITY_MODE_QUALITY = 0,

    /** Balanced mode. */
    XEG_RTGI_QUALITY_MODE_BALANCED = 1,

    /** Performance mode. */
    XEG_RTGI_QUALITY_MODE_PERFORMANCE = 2
} XEG_RTGIQualityMode;

/**
 * @brief This structure describes the mandatory parameters of each DDGI volume.
 *
 * @since 6.0.0(20)
 */
struct XEG_DDGIVolumeEntryParameters {
    /** The volume index range is [0, 65535] and is unique. */
    uint32_t volumeIndex;

    /** Number of rays emitted by probes. The recommended value is 64. The value range is [1, 1024]. */
    uint32_t raysPerProbe;

    /** Maximum intersection distance of the rays emitted by probes. The recommended value is 1000.0. */
    float probeMaxRayDistance;

    /** Coordinates of the volume center. */
    float volumePosition[3];

    /** Probe spacing. The value must be greater than 0. */
    float probeSpacing[3];

    /** Volume lighting channel mask. The recommended value is 0xFFFFFFFF. */
    uint32_t volumeLightingChannelMask;

    /** Number of probes. The value must be greater than 0. The value range is [1, 32]. */
    uint32_t volumeProbeGridCounts[3];

    /** Gamma correction coefficient of irradiance. The recommended value is 5.0. The value cannot be 0. */
    float volumeProbeIrradianceEncodingGamma;

    /** Historical weight of probe irradiance. The recommended value is 0.95. The value range is [0, 1]. */
    float probeHysteresis;

    /** Probe change threshold. The recommended value is 1.0. */
    float probeChangeThreshold;

    /** Probe brightness threshold. The recommended value is 1.0. */
    float probeBrightnessThreshold;

    /** Probe normal bias. The recommended value is 0.12. */
    float volumeNormalBias;

    /** Probe view bias. The recommended value is 0.48. */
    float volumeViewBias;

    /** Volume lighting blending distance. The recommended value is 1.0. */
    float volumeBlendDistance;

    /** Fade-in range of the lighting at the volume edges. The recommended value is 1.0. */
    float volumeBlendDistanceBlack;

    /** Backward judgment threshold of probes. The recommended value is 0.0. */
    float probeBackfaceThreshold;

    /** Minimum forward distance of probes. The recommended value is 0.0. */
    float probeMinFrontfaceDistance;

    /** Volume irradiance scaling ratio. The recommended value is 1.0. The value must be non-negative. */
    float volumeIrradianceScalar;

    /** Emissive intensity multiplier. The recommended value is 1.0. The value must be non-negative. */
    float emissiveMultiplier;

    /** Lighting multiplier. The recommended value is 1.0. The value must be non-negative. */
    float lightingMultiplier;

    /** Whether to forcibly update all probes. The value true indicates that all probes are forcibly updated,
	* and the value false indicates that some probes are updated. The recommended value is false.
	*/
    bool bForceUpdate;

    /** 3D image that stores the second-order spherical harmonic coefficients of probe irradiance.
	* The width, height, and depth are
	* volumeProbeGridCounts.y x 4 (number of second-order spherical harmonic coefficients),
	* volumeProbeGridCounts.x, and volumeProbeGridCounts.z, respectively.
	* The VkFormat value is VK_FORMAT_R32G32B32A32_SFLOAT.
	*/
    VkImageView probeIrradianceSH;
};

/**
 * @brief This structure describes the information about creating an {@link XEG_RTGI} object with the DDGI feature.
 * If the information in the structure changes, a new {@link XEG_RTGI} object needs to be created.
 *
 * @since 6.0.0(20)
 */
struct XEG_DDGICreateInfo {
    /** Identifies the {@link XEG_StructureType} value of this structure,
	* which must be XEG_STRUCTURE_TYPE_DDGI_CREATE_INFO.
	*/
    XEG_StructureType sType;

    /** Pointer to the extended structure. */
    const void* pNext;

    /** Quality mode of output images, which must be an enum in {@link XEG_RTGIQualityMode}. */
    XEG_RTGIQualityMode qualityMode;

    /** Maximum number of volumes to be rendered at the same time. The value range is [1, 9]. */
    uint32_t numberVolume;

    /** Scaling ratio of the rendering width and height. The recommended value range is [1, 4].
	The value must be greater than or equal to 1. */
    VkExtent2D scaledView;

    /** Rendering width and height of output GI images. */
    VkExtent2D viewSize;

    /** Whether to enable the device-cloud mode (true) or not (false). */
    bool enableCloud;
};

/**
 * @brief This structure describes the information required for
 * updating the DDGI probe irradiance and rendering the output GI images.
 *
 * @since 6.0.0(20)
 */
struct XEG_DDGIDescription {
    /** Identifies the {@link XEG_StructureType} value of this structure,
	* which must be XEG_STRUCTURE_TYPE_DDGI_DESCRIPTION.
	*/
    XEG_StructureType sType;

    /** Pointer to the extended structure. */
    const void* pNext;

    /** Camera view matrix, which must be a 4 x 4 matrix in column-major order. */
    float viewMatrix[16];

    /** Camera projection matrix, which must be a 4 x 4 matrix in column-major order. */
    float projectionMatrix[16];

    /** Input Gbuffer normal image, whose width and height must be
	* the same as those of viewSize in {@link XEG_DDGICreateInfo}.
	*/
    VkImageView inputNormalImage;

    /** Input Gbuffer depth image, whose width and height must be
	* the same as those of viewSize in {@link XEG_DDGICreateInfo}.
	*/
    VkImageView inputDepthImage;

    /** Input Gbuffer base color and metallic image, whose width and height must be
	* the same as those of viewSize in {@link XEG_DDGICreateInfo}.
	*/
    VkImageView inputBasecolorMetallicImage;

    /** Input probe rays direction image, whose width and height are
	* the number of rays emitted by probes and the number of the input probes respectively.
	*/
    VkImageView inputDirectionImage;

    /** Input image indicating the radiance at the intersection point of the rays emitted by probes and the distance,
	* whose width and height are the number of rays emitted by the probes
	* and the number of the input probes respectively.
	*/
    VkImageView inputRayRadianceDistanceImage;

    /** Input image indicating the normal and metalness at the intersection point of the rays emitted by probes,
	* whose width and height are the number of rays emitted by the probes
	* and the number of the input probes respectively.
	*/
    VkImageView inputRayHitNormalAndMetallicImage;

    /** Index information of input probes, corresponding to the information about the rays emitted by the probes.
	* Each data record consists of two uint values (probe index/volume index).
	*/
    VkBuffer inputVolumeIndexAndProbeIndex;

    /** Number of input probes, corresponding to the number of valid data records in inputVolumeIndexAndProbeIndex. */
    uint32_t inputProbeCount;

    /** Index information of output probes, indicating how the user emits rays in the next frame.
	* Each data record consists of two uint values (probe index/volume index).
	*/
    VkBuffer outputVolumeIndexAndProbeIndex;

    /** Number of output probes, corresponding to the number of valid data records in outputVolumeIndexAndProbeIndex. */
    VkBuffer outputProbeCount;

    /** Output GI 2D image, whose width and height must be the same as those of viewSize in {@link XEG_DDGICreateInfo}.
	* The VkFormat value is VK_FORMAT_R8G8B8A8_UNORM.
	*/
    VkImageView outputGIImage;

    /** Number of volumes used. The value must be less than or equal to
	* the numberVolume value in {@link XEG_DDGICreateInfo}.
	*/
    uint32_t enableVolumeNumber;

    /** Input volume parameter information, corresponding to {@link XEG_DDGIVolumeEntryParameters}.
	* The size of the structure array must be equal to the enableVolumeNumber value.
	*/
    const struct XEG_DDGIVolumeEntryParameters* pVolumeEntryParameters;
};

/**
 * @brief This structure describes the information about creating an {@link XEG_RTGI} object with the NNGI feature.
 * If the information in the structure changes, a new {@link XEG_RTGI} object needs to be created.
 *
 * @since 6.0.0(20)
 */
struct XEG_NNGICreateInfo {
    /** Identifies the {@link XEG_StructureType} value of this structure,
	* which must be XEG_STRUCTURE_TYPE_NNGI_CREATE_INFO.
	*/
    XEG_StructureType sType;

    /** Pointer to the extended structure. */
    const void* pNext;

    /** Quality mode of output images, which must be an enum in {@link XEG_RTGIQualityMode}. */
    XEG_RTGIQualityMode qualityMode;

    /** Resolution of inference input images, which must be the same as
	* that of the inference input images in {@link XEG_NNGIDescription}.
	*/
    VkExtent2D inferenceInputSize;

    /** Resolution of inference output images, which must be the same as
	* that of the inference output images in {@link XEG_NNGIDescription}. The recommended value is (640, 368).
	*/
    VkExtent2D inferenceOutputSize;

    /** Resolution of training images, which must be the same as
	* that of the training input and output images in {@link XEG_NNGIDescription}. The recommended value is (64, 32).
	*/
    VkExtent2D trainingSize;
};

/**
 * @brief This structure describes the information required for
 * updating the NNGI to calculate the ray-traced global illumination.
 *
 * @since 6.0.0(20)
 */
struct XEG_NNGIDescription {
    /** Identifies the {@link XEG_StructureType} value of this structure,
	* which must be XEG_STRUCTURE_TYPE_NNGI_DESCRIPTION.
	*/
    XEG_StructureType sType;

    /** Pointer to the extended structure. */
    const void *pNext;

    /** Camera view matrix of inference images, which must be consistent with the matrix used by the user to generate
	* the G-buffer, and it must be a 4 x 4 matrix in column-major order. */
    float inferenceCameraViewMatrix[16];

    /** Camera projection matrix of inference images, which must be consistent with the matrix used by the user to
	* generate the G-buffer, and it must be a 4 x 4 matrix in column-major order. */
    float inferenceCameraProjectionMatrix[16];

    /** Inference input depth image, which cannot be empty. Its format must support depth stencil attachment,
	* and it must be stored as the depth texture in the G-buffer.
    * The resolution is the same as that of inferenceInputSize in {@link XEG_NNGICreateInfo}.
    */
    VkImageView inferenceInputDepthImage;

    /** Inference input normal image, which cannot be empty. The format must have at least 3 channels, 
	* and the RGB channels should store the x, y, z components of the normal vector respectively.
    * The resolution is the same as that of inferenceInputSize in {@link XEG_NNGICreateInfo}.
    */
    VkImageView inferenceInputNormalImage;

    /** Inference input base color image, which cannot be empty. The format must have at least 3 channels,
    * and the RGB channels should store the red, green, and blue components respectively, discarding the alpha
    * channel information. The resolution is the same as that of inferenceInputSize in {@link XEG_NNGICreateInfo}.
    */
    VkImageView inferenceInputBaseColorMetallicImage;

    /** Inference output GI image, which cannot be empty. The format must have at least 3 channels,
	* and the RGB channels should store the indirect illumination values for the red, green, and blue components
    * respectively, discarding the alpha channel information.
    * The resolution is the same as that of inferenceOutputSize in {@link XEG_NNGICreateInfo}.
    */
    VkImageView inferenceOutputGIImage;

    /** Camera view matrix of training images, which must be consistent with the matrix used by the user for
    * path tracing, and must be a 4 x 4 column-major matrix.
	*/
    float trainingCameraViewMatrix[16];

    /** Camera projection matrix of training images, which must be consistent with the matrix used by the user
    * for path tracing, and must be a 4 x 4 column-major matrix.
	*/
    float trainingCameraProjectionMatrix[16];

    /** Training input position image, which cannot be empty. The format must have at least 3 channels, 
	* and the RGB channels should store the X, Y, and Z coordinates of each pixel respectively.
	* The resolution is the same as that of trainingSize in {@link XEG_NNGICreateInfo}.
	*/
    VkImageView trainingInputPositionImage;

    /** Training input normal image, which cannot be empty. The format must have at least 3 channels, 
	* and the RGB channels should store the X, Y, and Z components of the normal respectively.
	* The resolution is the same as that of trainingSize in {@link XEG_NNGICreateInfo}.
	*/
    VkImageView trainingInputNormalImage;

    /** Training input base color image, which cannot be empty. The format must have at least 3 channels, 
	* and the RGB channels should store the red, green, and blue components respectively, 
	* discarding the alpha channel information.
	* The resolution is the same as that of trainingSize in {@link XEG_NNGICreateInfo}.
	*/
    VkImageView trainingInputBaseColorMetallicImage;

    /** Training input GI image, which cannot be empty. The format must have at least 3 channels, 
	* and the RGB channels should store the radiance values of the red, green, and blue components respectively,
	* and the alpha channel information should be ignored. A higher quality of the GI result of training images
    * indicates a higher quality of the GI result output by the inference.
    * The resolution is the same as that of trainingSize in {@link XEG_NNGICreateInfo}.
	*/
    VkImageView trainingInputGIImage;

    /** Rendering bounding box range. */
    VkAabbPositionsKHR sceneAabb;

    /** Whether the rendering scene is unbounded. Currently, only false is supported. */
    bool isSceneUnbounded = false;

    /** Scene scaling factor. For bounded scenes, this parameter does not need to be set.
	* XEngine calculates the value based on sceneAabb. For unbounded scenes,
	* you are advised to set this parameter to the average depth.
	*/
    float spatialScaleFactor = 0;
};

/**
* @brief Defines the function pointer for creating an {@link XEG_RTGI} object.
*
* @param device VkDevice that is currently in use.
* @param pCreateInfo Pointer to the structure containing the information needed for creating an {@link XEG_RTGI} object.
* If a DDGI handle is created, it is the pointer to the {@link XEG_DDGICreateInfo} structure.
* If an NNGI handle is created, it is the pointer to the {@link XEG_NNGICreateInfo} structure. The value cannot be null.
* @param pRtGI Pointer to the handle. The created {@link XEG_RTGI} is returned in this handle.
* @return Returns an error code of the VkResult type. VK_SUCCESS indicates successful execution.
* @since 6.0.0(20)
*/
typedef VkResult (VKAPI_PTR *PFN_HMS_XEG_CreateRTGI)(VkDevice device,
    const void* pCreateInfo, XEG_RTGI* pRtGI);

/**
* @brief Defines the function pointer for destroying an {@link XEG_RTGI} object.
*
* @param rtGI Created {@link XEG_RTGI} object.
* @since 6.0.0(20)
*/
typedef void (VKAPI_PTR *PFN_HMS_XEG_DestroyRTGI)(XEG_RTGI rtGI);

/**
* @brief Defines the function pointer for executing the rendering command.
*
* @param commandBuffer VkCommandBuffer of the current command, which must be submitted to vkQueueSubmit before being
* executed.
* @param rtGI Created {@link XEG_RTGI} object.
* @param pDescription Pointer to the structure containing the information needed for excuting the rendering command.
* If DDGI rendering is used, it is the pointer to the {@link XEG_DDGIDescription} structure.
* If NNGI rendering is used, it is the pointer to the {@link XEG_NNGIDescription} structure. The value cannot be null.
* @return Returns an error code of the VkResult type. VK_SUCCESS indicates successful execution.
* @since 6.0.0(20)
*/
typedef VkResult (VKAPI_PTR *PFN_HMS_XEG_CmdRenderRTGI)(VkCommandBuffer commandBuffer,
    XEG_RTGI rtGI, const void* pDescription);

#ifndef XEG_NO_PROTOTYPES

/**
* @brief Creates an {@link XEG_RTGI} object.
*
* @param device VkDevice that is currently in use.
* @param pCreateInfo Pointer to the structure containing the information needed for creating an {@link XEG_RTGI} object.
* If a DDGI handle is created, it is the pointer to the {@link XEG_DDGICreateInfo} structure.
* If an NNGI handle is created, it is the pointer to the {@link XEG_NNGICreateInfo} structure. The value cannot be null.
* @param pRtGI Pointer to the handle. The created {@link XEG_RTGI} is returned in this handle.
* @return Returns an error code of the VkResult type. VK_SUCCESS indicates successful execution.
* @since 6.0.0(20)
*/
VKAPI_ATTR VkResult VKAPI_CALL HMS_XEG_CreateRTGI(
    VkDevice      device,
    const void*   pCreateInfo,
    XEG_RTGI*     pRtGI
)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
* @brief Destroys an {@link XEG_RTGI} object.
*
* @param rtGI Created {@link XEG_RTGI} object.
* @since 6.0.0(20)
*/
VKAPI_ATTR void VKAPI_CALL HMS_XEG_DestroyRTGI(
    XEG_RTGI  rtGI
)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
* @brief Executes the rendering command.
*
* @param commandBuffer VkCommandBuffer of the current command, which must be submitted to vkQueueSubmit before being
* executed.
* @param rtGI Created {@link XEG_RTGI} object.
* @param pDescription Pointer to the structure containing the information needed for excuting the rendering command.
* If DDGI rendering is used, it is the pointer to the {@link XEG_DDGIDescription} structure.
* If NNGI rendering is used, it is the pointer to the {@link XEG_NNGIDescription} structure. The value cannot be null.
* @return Returns an error code of the VkResult type. VK_SUCCESS indicates successful execution.
* @since 6.0.0(20)
*/
VKAPI_ATTR VkResult VKAPI_CALL HMS_XEG_CmdRenderRTGI(
    VkCommandBuffer  commandBuffer,
    XEG_RTGI         rtGI,
    const void*      pDescription
)
__attribute__((__availability__(ohos, introduced=20.0.0)));

#endif /* XEG_NO_PROTOTYPES */

#ifdef __cplusplus
}
#endif

#endif // XEG_VULKAN_RTGI_H
/** @} */
