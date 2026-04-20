/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
 
/**
 * @file spatial_recon_interface.h
 *
 * @brief A module designed for 3D spatial reconstruction tasks, typically processing multi-view image inputs to 
 * generate volumetric scene representations.
 *
 * @library libspatial_recon_ndk.z.so
 * @kit SpatialReconKit
 * @syscap SystemCapability.Graphics.SpatialRecon
 * @since 6.1.0(23)
 */
 
/**
 * @addtogroup SpatialRecon
 * @{
 *
 * @brief Provides APIs related to the 3D spatial reconstruction tasks.
 * @since 6.1.0(23)
 */
 
#ifndef NDK_INCLUDE_SPATIAL_RECON_H
#define NDK_INCLUDE_SPATIAL_RECON_H
#include "info/application_target_sdk_version.h"
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
 
/**
 * @brief Defines a struct for the spatial reconstruction session handle. This struct is used for 3D scene
 *     reconstruction.
 *
 * @since 6.1.0(23)
 */
typedef struct HMS_SpatialRecon_Session HMS_SpatialRecon_Session;
 
/**
 * @brief Defines a struct for the opaque handle of an AR session in the AR Engine, which manages the lifecycle,
 *     tracing, and session status of the AR.
 *
 * @since 6.1.0(23)
 */
typedef struct AREngine_ARSession AREngine_ARSession;
 
/**
 * @brief Defines a struct for the single-frame AR image captured in AR Engine, including the camera image, tracking
 *     status, anchor, and AR data at a specific timestamp.
 *
 * @since 6.1.0(23)
 */
typedef struct AREngine_ARFrame AREngine_ARFrame;
 
/**
 * @brief Defines an enum for the spatial reconstruction status.
 *
 * @since 6.1.0(23)
 *
 */
typedef enum {
    /** The space reconstruction is successful. */
    SPATIAL_RECON_STATUS_SUCCESS = 0,
    /** The maximum number of spacial reconstruction frames is exceeded. */
    SPATIAL_RECON_STATUS_EXCEEDS_MAXIMUM = 1023700001,
    /** The current device does not support spacial reconstruction. */
    SPATIAL_RECON_STATUS_DEVICE_NOT_SUPPORT = 801,
    /** The input working path is invalid. */
    SPATIAL_RECON_STATUS_INVALID_WORK_PATH = 1023700002,
    /** The input frame data is invalid. */
    SPATIAL_RECON_STATUS_INVALID_FRAME_DATA = 1023700003,
    /** The session is not initialized. */
    SPATIAL_RECON_STATUS_STAGE_NOT_INITIALIZED = 1023700004,
    /** The reconstruction session has started. */
    SPATIAL_RECON_STATUS_STAGE_BUILDING = 1023700005,
    /** The reconstruction session has not finished. */
    SPATIAL_RECON_STATUS_STAGE_NOT_FINISHED = 1023700006,
    /** The spacial reconstruction failed. */
    SPATIAL_RECON_STATUS_FAILED = 1023700007
} HMS_SpatialReconStatus;
 
/**
 * @brief Defines an enum for the output formats of the spatial reconstruction model.
 *
 * @since 6.1.0(23)
 */
typedef enum {
    /** PLY format. */
    SPATIAL_RECON_OUTPUT_FORMAT_PLY,
    /** MPEG-4 video format. */
    SPATIAL_RECON_OUTPUT_FORMAT_MP4
} HMS_SpatialReconOutputFormat;
 
/**
 * @brief Spatial reconstruction running mode types
 *
 * @note The SpatialRecon session supports both foreground and background running modes.
 *
 * @note Update the HMS_SpatialReconRunningMode when the application using SpatialRecon is switched to the background
 * or returns to the foreground.
 *
 * @note This allows the system to optimize power consumption for each running mode.
 *
 * @since 6.1.0(23)
 */
typedef enum {
    /** Default mode. When the reconstruction is performed in the foreground, the system allocates more
 * resources to ensure a faster reconstruction speed.
 */
    SPATIAL_RECON_RUNNING_FOREGROUND_MODE,
 
    /** When the spatial reconstruction is running in the background, the system preferentially processes the
 * operations of foreground applications.
 */
    SPATIAL_RECON_RUNNING_BACKGROUND_MODE
} HMS_SpatialReconRunningMode;
 
/**
 * @brief Defines an enum for the spacial reconstruction stages.
 * This enum defines all possible stages of the spacial reconstruction process, from initialization to completion or
 * termination. Each stage represents a specific phase in the 3D reconstruction process.
 *
 * @since 6.1.0(23)
 */
typedef enum {
    /** Initialization stage: resources and environment are being prepared. */
    SPATIAL_RECON_STAGE_INIT,
    /** Reconstruction stage: the data is being processed and a 3D model is being built. */
    SPATIAL_RECON_STAGE_BUILDING, 
    /** The reconstruction process is paused. */
    SPATIAL_RECON_STAGE_PAUSED,
    /** The reconstruction is successful. */
    SPATIAL_RECON_STAGE_FINISHED,
 
    /** Saving stage: the 3D model is being saved into a file. */
    SPATIAL_RECON_STAGE_SAVING,
 
    /** The stage is unknown or uncertain. */
    SPATIAL_RECON_STAGE_UNKNOWN
} HMS_SpatialReconStage;
 
/**
 * @brief Defines an enum for the spatial reconstruction model types.
 * Currently, only the 3D Gaussian Splatting model type is supported.
 *
 * @since 6.1.0(23)
 */
typedef enum {
    /** 3D Gaussian Splatting (3DGS) model for scene reconstruction. */
    SPATIAL_RECON_MODEL_TYPE_GS
} HMS_SpatialReconModelType;
 
/**
 * @brief Defines an enum for the image data formats of spatial reconstruction.
 *  
 * Currently, the RGB format is supported. In the future, other color spaces and data representations may be
 * supported.
 *  
 *
 * @since 6.1.0(23)
 */
typedef enum {
    /** RGB format, a three-channel color representation method based on red, green, and blue. */
    SPATIAL_RECON_IMAGEDATA_FORMAT_RGB
} HMS_SpatialReconImageDataFormat;
 
/**
 * @brief Defines a struct for the spacial reconstruction model write.
 *
 * @since 6.1.0(23)
 */
typedef struct HMS_SpatialRecon_ModelWriteInfo
{
    /**
     * Longitude coordinate for geolocation reference (in decimal degrees)
     * Positive values indicate East, negative values indicate West
     */
    float longitude = 0.0;
    /**
     * Latitude coordinate for geolocation reference (in decimal degrees)
     * Positive values indicate North, negative values indicate South
     */
    float latitude = 0.0;
    /**
     * Optional audio file path associated with the spatial reconstruction
     * Can be nullptr if no audio data is available or required
     * When provided, enables audio-spatial synchronization
     */
    const char *audioFile = 0;
    /**
     * Name of the output file to store the spatial reconstruction model
     * Required field - must specify valid filename with appropriate extension
     */
    const char* modelFile;
    /**
     * Format of the spatial reconstruction model output
     * Specifies the file format and structure of the generated model
     */
    HMS_SpatialReconOutputFormat modelFormat;
} HMS_SpatialRecon_ModelWriteInfo;
 
/**
 * @brief Defines a struct for the HMS spacial reconstruction data frame.
 * It contains camera intrinsic parameters, pose information, timestamps, and image data for spatial reconstruction.
 *
 * @since 6.1.0(23)
 */
typedef struct HMS_SpatialRecon_DataFrame {
    /** Focal length in pixels along X-axis */
    float focalX = 0.0f;
    /** Focal length in pixels along Y-axis */
    float focalY = 0.0f;
    /** Principal point X-coordinate (optical center) in pixels */
    float principalX = 0.0f;
    /** Principal point Y-coordinate (optical center) in pixels */
    float principalY = 0.0f;
    /** Distortion Parameters [k1, k2, p1, p2, k3, k4, k5, k6] */
    float distortionCoef[8];
    /** Width of the image in pixels */
    int32_t imageWidth = 0;
    /** Height of the image in pixels */
    int32_t imageHeight = 0;
    /** Camera position in 3D space [x, y, z] */
    float position[3];
    /** Camera rotation as a quaternion [x, y, z, w] */
    float rotation[4];
    /** Timestamp of the frame capture in nanoseconds */
    int64_t timestamp = 0;
    /** Pointer to the raw image pixel data */
    uint8_t *imageData = 0;
    /** Format/encoding of the image data */
    HMS_SpatialReconImageDataFormat format = SPATIAL_RECON_IMAGEDATA_FORMAT_RGB;
} HMS_SpatialRecon_DataFrame;
 
/**
 * @brief Defines a callback for updating the spatial reconstruction status.
 *
 * @param status Status of the spatial reconstruction process.
 * HMS_SpatialReconStatus indicates the reconstruction result status.
 *
 * @since 6.1.0(23)
 *
 */
typedef void (*HMS_SpatialReconCallbackFunc)(HMS_SpatialReconStatus);
 
/**
 * @brief Queries whether the current device supports a specified spatial reconstruction model type.
 * This function is used to check whether the device has the capability of performing spatial reconstruction using the
 * given model type.
 *
 * @param type Spatial reconstruction model type to be queried.
 * For details about the available types, see the HMS_SpatialReconModelType enum.
 *
 * @return HMS_SpatialReconStatus, indicating whether the model type is supported.
 * @note The support status may vary depending on device hardware, system version,
 *       or current environmental conditions. Some models might require specific
 *       sensors (e.g., depth cameras, LiDAR) or minimum system requirements.
 *
 * @see HMS_SpatialReconModelType
 * @see HMS_SpatialReconStatus
 *
 * @since 6.1.0(23)
 */
HMS_SpatialReconStatus HMS_SpatialRecon_IsSupport(HMS_SpatialReconModelType type)
__attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Creates a new spatial reconstruction session.
 *
 * @param type The type of reconstruction model to use. This determines
 *             the algorithm and capabilities of the reconstruction session.
 * @param workPath The file system path where reconstruction data and temporary files,
 *                 will be stored. Must be a valid, writable directory path.
 * @param outSpatialReconSession Output parameter that receives the pointer to the
 *                               newly created spatial reconstruction session object.
 *                               The caller is responsible for managing the lifetime
 *                               of this object and must eventually destroy it using
 *                               the appropriate cleanup function.
 *
 * @return HMS_SpatialReconStatus indicating the result of the operation
 *
 * @note The created session must be destroyed using HMS_SpatialRecon_DestroySession()
 *       to prevent resource leaks.
 * @note The workPath directory should have sufficient storage space for reconstruction
 *       data, which can be substantial depending on the reconstruction scope and quality.
 * @note On unsupported devices, the Session object will not be successfully created, and
 *       the function will return an error. You can first call the HMS_SpatialRecon_IsSupport
 *       to confirm whether the current device supports this capability.
 *
 * @since 6.1.0(23)
 */
HMS_SpatialReconStatus HMS_SpatialRecon_CreateSession(HMS_SpatialReconModelType type, const char* workPath, 
    HMS_SpatialRecon_Session **outSpatialReconSession)
    __attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Destroys a spatial reconstruction session and releases its resources.
 *
 * This function terminates the spatial reconstruction session and deallocates all memory
 * and system resources associated with it. After calling this function, the provided
 * session pointer becomes invalid and should not be used again.
 *
 * @param spatialReconSession A pointer to the spatial reconstruction session to be destroyed.
 *                           The session must have been previously created.
 *                           If NULL, the function has no effect.
 *
 * @return HMS_SpatialReconStatus indicating the result of the operation
 *
 * @warning Once destroyed, the session cannot be restored. All unsaved reconstruction
 *          data will be lost. Call HMS_SpatialRecon_SaveResultToFile() before destruction
 *          if data persistence is required.
 * @see HMS_SpatialRecon_CreateSession()
 *
 * @since 6.1.0(23)
 */
HMS_SpatialReconStatus HMS_SpatialRecon_DestroySession(HMS_SpatialRecon_Session *spatialReconSession)
__attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Pushes a spatial reconstruction data frame to a spatial reconstruction session.
 * This function submits the captured spatial data frame to the reconstruction session for processing. The session uses
 * the data to update or optimize its internal spatial model.
 * @param spatialReconSession Pointer to the handle of the spatial reconstruction session.
 * @param inputFrame Pointer to the spatial reconstruction data frame that contains the sensor data.
 * @return Status code indicating the push result.
 *
 * @note Frames must be pushed in sequential order; otherwise, the push will fail.
 *
 * @note If HMS_SpatialRecon_StartSession is called to initiate the modeling process, frame data will
 *       no longer be successfully pushed.
 *
 * @since 6.1.0(23)
 */
HMS_SpatialReconStatus HMS_SpatialRecon_PushFrame(HMS_SpatialRecon_Session *spatialReconSession,
    HMS_SpatialRecon_DataFrame *inputFrame)
    __attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Pushes a frame from an AR Engine session to a spatial reconstruction session.
 * This function submits a frame (usually containing camera images, poses, and AR tracking data).
 * The frame is passed to the spacial reconstruction session. It allows the reconstruction system to use real-time AR
 * tracking information (such as camera poses and feature points) to improve spatial modeling.
 *
 * @param spatialReconSession Pointer to the handle of the spatial reconstruction session.
 * @param arSession Pointer to the AR Engine session that generates the AR Engine frame.
 * @param arFrame Pointer to the AR Engine frame that contains the AR tracking data and camera image. 
 * @return Status code indicating the push result.
 *
 * @note AREngine provides core AR capabilities integrated within SystemCapability.AREngine.Core.
 *       Its key features include motion tracking, which enables stable placement of virtual objects
 *       through device pose perception; environment tracking, which uses plane detection and lighting
 *       estimation to understand real-world scenes; and hit detection, which accurately maps virtual objects
 *       onto real surfaces. These capabilities collectively create an immersive experience that blends virtual
 *       and real worlds, supporting smooth AR application development.
 *
 * @note Frames must be pushed in sequential order; otherwise, the push will fail.
 *
 * @note If HMS_SpatialRecon_StartSession is called to initiate the modeling process, frame data will
 *       no longer be successfully pushed.
 *
 * @since 6.1.0(23)
 */
HMS_SpatialReconStatus HMS_SpatialRecon_PushARFrame(HMS_SpatialRecon_Session *spatialReconSession, 
                                AREngine_ARSession* arSession, AREngine_ARFrame *arFrame)
                                __attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Starts a spatial reconstruction session.The operation is performed asynchronously,
 *        and the completion status is reported via a callback function.
 *
 * @param spatialReconSession Pointer to the spatial reconstruction session handle.
 *        If the spatialReconSession is null, the function will return error code.
 * @param writeInfo Pointer to the model write configuration information.
 *        Contains parameters for saving the reconstruction output upon a successful reconstruction.
 *        If the writeInfo pointer is null, no write operation will be executed after reconstruction.
 *        The HMS_SpatialRecon_SaveResultToFile interface can be called separately later.
 * @param onSpatialReconFinished Callback function pointer that will be invoked when the
 *        reconstruction process completes. The callback function can be set to null,
 *        in which case the callback will not be triggered.
 *
 * @return HMS_SpatialReconStatus Status code indicating success or specific error.
 *
 * @since 6.1.0(23)
 */
HMS_SpatialReconStatus HMS_SpatialRecon_StartSession(HMS_SpatialRecon_Session *spatialReconSession, 
    HMS_SpatialRecon_ModelWriteInfo* writeInfo, HMS_SpatialReconCallbackFunc onSpatialReconFinished)
    __attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Sets the running mode for the spatial reconstruction session.
 *
 * @param spatialReconSession Pointer to the spatial reconstruction session handle.
 * @param runningMode The desired running mode for spatial reconstruction.
 *
 * @return HMS_SpatialReconStatus Status code indicating success or specific error.
 *
 * @note The default running mode is foreground mode (SPATIAL_RECON_RUNNING_FOREGROUND_MODE).
 *       Changing modes during reconstruction may affect performance and behavior.
 *
 * @note This function must be called after HMS_SpatialRecon_StartSession() and
 *       before reconstruction finished. It has no effect if called outside
 *       of an active session.
 *
 * @since 6.1.0(23)
 */
HMS_SpatialReconStatus HMS_SpatialRecon_SetRunningMode(HMS_SpatialRecon_Session *spatialReconSession,
    HMS_SpatialReconRunningMode runningMode)
    __attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Pauses an ongoing spatial reconstruction session.
 *
 * @param spatialReconSession Pointer to the handle of the spatial reconstruction session.
 *
 * @return Status code, indicating success or a specific error.
 * If no active session exists, an error is returned.
 *
 * @since 6.1.0(23)
 */
HMS_SpatialReconStatus HMS_SpatialRecon_PauseSession(HMS_SpatialRecon_Session *spatialReconSession)
__attribute__((__availability__(ohos, introduced=23.0.0))); 
 
/**
 * @brief Resumes a paused spatial reconstruction session.
 *
 * @param spatialReconSession Pointer to the handle of the spatial reconstruction session.
 *
 * @return HMS_SpatialReconStatus, indicating success or a specific error.
 * If the session is not paused, an error is returned.
 *
 * @since 6.1.0(23)
 */
HMS_SpatialReconStatus HMS_SpatialRecon_ResumeSession(HMS_SpatialRecon_Session *spatialReconSession)
__attribute__((__availability__(ohos, introduced=23.0.0))); 
 
/**
 * @brief Retrieves the progress of the current task.
 *
 * This function queries the progress fraction of the ongoing task (i.e. reconstruction or saving)
 * and returns the result by the pointer variable below.
 *
 * @param spatialReconSession Pointer to the spatial reconstruction session instance.
 * @param progress Pointer to a float variable where the progress fraction will be stored.
 *        The value ranges from 0.0f (0%) to 1.0f (100%). If the pointer is null, the function will
 *        return error code.
 * @param stage Pointer to a stage variable where the stage value will be stored. If the pointer
 *        is null, the stage value will not be written.
 *
 * @return HMS_SpatialReconStatus Status code indicating success or specific error.
 *
 * @note The returned progress value depends on the current task (i.e. reconstruction or saving).
 *       This distinction is important when monitoring completion during model export operations.
 * @note Once the HMS_SpatialRecon_StartSession function is called, the modeling process begins execution,
 *       and the returned progress value reflects the progress of the modeling. If the writeInfo parameter
 *       of the HMS_SpatialRecon_StartSession function is set, it will automatically save the model to files.
 *       Therefore, the returned progress value will include the progress of both reconstruction and saving.
 * @note Once the function HMS_SpatialRecon_SaveResultToFile function is called, the session starts saving the
 *       3D model to a file manually. The returned progress value will only reflect the file saving progress
 *       rather than the whole progress.
 *
 * @since 6.1.0(23)
 */
HMS_SpatialReconStatus HMS_SpatialRecon_GetProgress(HMS_SpatialRecon_Session *spatialReconSession,
    float* progress, HMS_SpatialReconStage* stage)
    __attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Obtains the optimized camera frame from the spatial reconstruction session.
 * This function provides optimized intrinsic and extrinsic camera parameters for a specified frame index after
 * reconstruction processing.
 *
 * @param spatialReconSession Pointer to the handle of the spatial reconstruction session.
 * @param iFrame Index of the frame to be retrieved (based on 0).
 * @param outFrame Output parameter, which is used to store the optimized frame data.
 *
 * @return HMS_SpatialReconStatus, indicating whether the operation succeeds or fails.
 *
 * @since 6.1.0(23)
 *
 * @note This function can only be called after the model is successfully built;
 *       otherwise, it will return an error value.
 * @note The modeling process does not optimize timestamps, so the frame data pushed through the Push
 *       interface can be associated with optimized frames based on timestamps.
 * @note Obtain the optimized frame data starting from index 0, incrementing the index number
 *       sequentially until no more optimized frame data can be obtained. In this way, all optimized
 *       frame data can be acquired.
 * @note This function does NOT return image pixel data, and the imageData field will be set to null.
 */
HMS_SpatialReconStatus HMS_SpatialRecon_GetRefinedFrame(HMS_SpatialRecon_Session *spatialReconSession, 
                int iFrame, HMS_SpatialRecon_DataFrame *outFrame)
                __attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Saves the spatial reconstruction result to a file.
 * This function exports the processed spatial reconstruction data to a file in the specified format. This operation is
 * performed asynchronously, and the completion status is reported through a callback function.
 *
 * @param spatialReconSession Pointer to the spatial reconstruction session object.
 * The pointer cannot be null and must be a valid and active session.
 * @param writeInfo Pointer to the struct that contains the file export parameters,
 * such as the file path, format, and optional configuration flags.
 * The pointer cannot be null.
 * @param onSaved Pointer to the callback that is triggered when the save operation is complete (regardless of success
 *     or failure). If no callback is required, this parameter can be set to NULL.
 *
 * @return HMS_SpatialReconStatus, indicating the initial verification status or an instant error (for example, an
 *     invalid parameter). The actual result of file export is returned through the callback.
 *
 * @note The session must remain valid until the callback is invoked. Supported file formats and
 *       configurations are defined in `HMS_SpatialRecon_ModelWriteInfo`.
 *
 * @note This function can only be called after the model is successfully built;
 *       otherwise, it will return an error value.
 *
 * @since 6.1.0(23)
 */
HMS_SpatialReconStatus HMS_SpatialRecon_SaveResultToFile(HMS_SpatialRecon_Session *spatialReconSession, 
                                HMS_SpatialRecon_ModelWriteInfo *writeInfo, HMS_SpatialReconCallbackFunc onSaved)
                                __attribute__((__availability__(ohos, introduced=23.0.0)));
 
#ifdef __cplusplus
}
#endif
#endif
 
/** @} */