/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @addtogroup ar_engine
 * @{
 *
 * @brief Provides APIs related to the augmented reality capability of AREngine.
 *
 * Covers basic AR capabilities, including motion tracking, environment tracking, and hit testing.
 *
 *
 * @since 5.0.0(12)
 */

/**
 * @file ar_engine_core.h
 * @kit AREngine

 * @brief Declares the APIs for accessing AREngine, and provides basic AREngine capabilities, including motion tracking,
 * environment tracking, and hit testing.
 *
 * @library libarengine_ndk.z.so
 * @syscap SystemCapability.AREngine.Core
 * @since 5.0.0(12)
 */
#ifndef NDK_INCLUDE_AR_ENGINE_CORE_H
#define NDK_INCLUDE_AR_ENGINE_CORE_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Used for configuring <b>AREngine_ARSession</b> capabilities (which capabilities and modes to use).
 * @since 5.0.0(12)
 */
typedef struct AREngine_ARConfig AREngine_ARConfig;

/**
 * @brief Used for managing the system status of AREngine.
 * @since 5.0.0(12)
 */
typedef struct AREngine_ARSession AREngine_ARSession;

/**
 * @brief Indicates the pose (translation + rotation), representing an immutable rigid transformation from one
 * coordinate system to another.
 * @since 5.0.0(12)
 */
typedef struct AREngine_ARPose AREngine_ARPose;

/**
 * @brief Indicates the camera information for the current frame.
 * @since 5.0.0(12)
 */
typedef struct AREngine_ARCamera AREngine_ARCamera;

/**
 * @brief Indicates intrinsic camera parameters, including fx, fy, cx, cy, and camera distortion parameters.
 * @since 5.0.0(12)
 */
typedef struct AREngine_ARCameraIntrinsics AREngine_ARCameraIntrinsics;

/**
 * @brief Provides camera configuration information, such as the image size to be processed by CPU, or the texture size
 * to be processed by GPU.
 * @since 5.0.0(12)
 */
typedef struct AREngine_ARCameraConfig AREngine_ARCameraConfig;

/**
 * @brief Indicates a frame of data processed by AREngine.
 * @since 5.0.0(12)
 */
typedef struct AREngine_ARFrame AREngine_ARFrame;

/**
 * @brief Indicates the camera video stream frame object.
 * @since 5.0.0(12)
 */
typedef struct AREngine_ARImage AREngine_ARImage;

/**
 * @brief Indicates a collection of trackable 3D point clouds.
 * @since 5.0.0(12)
 */
typedef struct AREngine_ARPointCloud AREngine_ARPointCloud;

/**
 * @brief Indicates a trackable object, such as a point or a plane.
 *
 * After obtaining the object, if you need to obtain the center point position of the plane (by calling
 * <b>HMS_AREngine_ARPlane_GetCenterPose</b>), obtain the pose information of the point (by calling
 * <b>HMS_AREngine_ARPoint_GetPose</b>), or perform any other operations on this object, convert this object into
 * another one (such as <b>AREngine_ARPlane</b> or <b>AREngine_ARPoint</b>) according to the type of this trackable
 * object (obtained through <b>HMS_AREngine_ARTrackable_GetType</b>), by referring to <b>AREngine_ARPlane *arPlane =
 * reinterpret_cast<AREngine_ARPlane *>(trackable)</b>.
 *
 * @since 5.0.0(12)
 */
typedef struct AREngine_ARTrackable AREngine_ARTrackable;

/**
 * @brief Indicates a list of trackable objects.
 * @since 5.0.0(12)
 */
typedef struct AREngine_ARTrackableList AREngine_ARTrackableList;

/**
 * @brief Indicates a plane object, which describes the detected trackable plane information.
 * @since 5.0.0(12)
 */
typedef struct AREngine_ARPlane AREngine_ARPlane;

/**
 * @brief Indicates a point object, which describes the detected trackable point data.
 * @since 5.0.0(12)
 */
typedef struct AREngine_ARPoint AREngine_ARPoint;

/**
 * @brief Indicates an object, which describes a trackable semantic object, such as a semantic plane.
 * @since 5.0.0(12)
 */
typedef struct AREngine_ARTarget AREngine_ARTarget;

/**
 * @brief Indicates an anchor object, which describes the spatial location associated with a trackable object.
 * @since 5.0.0(12)
 */
typedef struct AREngine_ARAnchor AREngine_ARAnchor;

/**
 * @brief Indicates a list of anchor objects.
 * @since 5.0.0(12)
 */
typedef struct AREngine_ARAnchorList AREngine_ARAnchorList;

/**
 * @brief Indicates the hit testing result object, which describes the hit testing result of a single trackable
 * object.
 * @since 5.0.0(12)
 */
typedef struct AREngine_ARHitResult AREngine_ARHitResult;

/**
 * @brief Indicates the list of hit testing results.
 * @since 5.0.0(12)
 */
typedef struct AREngine_ARHitResultList AREngine_ARHitResultList;

/**
 * @brief Distance to the clipping planes.
 *
 * Used as the input for <b>HMS_AREngine_ARCamera_GetProjectionMatrix<b>.
 *
 * @since 5.0.0(12)
 */
typedef struct {
    /** Distance to the near clipping plane in OpenGL, in meters. */
    float near;

    /** Distance to the far clipping plane in OpenGL, in meters. */
    float far;
} AREngine_ClipPlaneDistance;

/**
 * @brief Size of the bounding box coordinate array.
 * @since 5.0.0(12)
 */
const static int32_t ARENGINE_AABB_POINT_SIZE = 6;

/**
 * @brief Size of the pose data array.
 * @since 5.0.0(12)
 */
const static int32_t ARENGINE_POSE_RAW_SIZE = 7;

/**
 * @brief Size of the transformation matrix array.
 * @since 5.0.0(12)
 */
const static int32_t ARENGINE_VIEW_MATRIX_SIZE = 16;

/**
 * @brief Number of camera distortion parameters.
 * @since 5.0.0(12)
 */
const static int32_t ARENGINE_DISTORTION_COUNT = 5;

/**
 * @brief Image format.
 * @since 5.0.0(12)
 */
typedef enum {
    /** Unknown image format */
    ARENGINE_IMAGE_UNKNOWN = 0,

    /** The <b>ARENGINE_IMAGE_YUV_420_888</b> format consists of three data buffers, with the Y plane indexed as 0,
        the U plane indexed as 1, and the V plane indexed as 2. The Y plane does not intersect with the U/V plane.
        That is, the pixel stride of the Y plane is always 1. The U and V planes share the same row stride and
        pixel stride. */
    ARENGINE_IMAGE_YUV_420_888 = 2,

    /**
     * The <b>ARENGINE_IMAGE_Y_8</b> format consists of one data buffer, with the plane indexed as 0.
     * The data buffer type is an 8-bit unsigned integer.
     * @since 5.0.5(17)
     */
    ARENGINE_IMAGE_Y_8 = 3,
 
    /**
     * The <b>ARENGINE_IMAGE_Y_16</b> format consists of one data buffer, with the plane indexed as 0.
     * The data buffer type is a 16-bit unsigned integer.
     * @since 5.0.5(17)
     */
    ARENGINE_IMAGE_Y_16 = 4
} AREngine_ARImageFormat;

/**
 * @brief Type of a trackable object, such as a plane or point.
 * @since 5.0.0(12)
 */
typedef enum {
    /** Basic trackable object type, which can be used as the default <b>AREngine_ARTrackableType</b>. */
    ARENGINE_TRACKABLE_BASE = 0x41520100,

    /** Trackable object of the plane type. */
    ARENGINE_TRACKABLE_PLANE = 0x41520101,

    /** Trackable object of the point type. */
    ARENGINE_TRACKABLE_POINT = 0x41520102,

    /** Trackable object of the object type. */
    ARENGINE_TRACKABLE_TARGET = 0x50000008,

    /** Invalid trackable object type. */
    ARENGINE_TRACKABLE_INVALID = 0
} AREngine_ARTrackableType;

/**
 * @brief Tracking status of the trackable object.
 * @since 5.0.0(12)
 */
typedef enum {
    /** Tracking status: tracking. */
    ARENGINE_TRACKING_STATE_TRACKING = 0,

    /** Tracking status: paused. */
    ARENGINE_TRACKING_STATE_PAUSED = 1,

    /** Tracking status: stopped. */
    ARENGINE_TRACKING_STATE_STOPPED = 2
} AREngine_ARTrackingState;

/**
 * @brief Possible causes of tracking failures.
 * @since 5.0.0(12)
 */
typedef enum {
    /** Tracking failure cause: none. */
    ARENGINE_TRACKING_STATE_REASON_NONE = 0,
    /** Tracking failure cause: targets moving fast. */
    ARENGINE_TRACKING_STATE_REASON_EXCESSIVE_MOTION = 1,
    /** Tracking failure cause: insufficient visual features (such as weak texture). */
    ARENGINE_TRACKING_STATE_REASON_INSUFFICIENT_FEATURES = 2,
} AREngine_ARTrackingStateReason;

/**
 * @brief Plane finding mode.
 * @since 5.0.0(12)
 */
typedef enum {
    /** Plane finding is disabled. */
    ARENGINE_PLANE_FINDING_MODE_DISABLED = 0,

    /** Only horizontal planes are detected. */
    ARENGINE_PLANE_FINDING_MODE_HORIZONTAL = 1,

    /** Only vertical planes are detected. */
    ARENGINE_PLANE_FINDING_MODE_VERTICAL = 2,

    /** Both horizontal and vertical planes are detected. */
    ARENGINE_PLANE_FINDING_MODE_HORIZONTAL_AND_VERTICAL = 3
} AREngine_ARPlaneFindingMode;

/**
 * @brief Data update mode specified by <b>HMS_AREngine_ARSession_Update</b>.
 * @since 5.0.0(12)
 */
typedef enum {
    /** <b>The HMS_AREngine_ARSession_Update</b> returns results only when new frames are available. */
    ARENGINE_UPDATE_MODE_BLOCKING = 0,

    /** <b>HMS_AREngine_ARSession_Update</b> returns results immediately (returns the previous frame when no new frame
        is available). */
    ARENGINE_UPDATE_MODE_LATEST = 1
} AREngine_ARUpdateMode;

/**
 * @brief Power consumption mode.
 * @since 5.0.0(12)
 */
typedef enum {
    /** Normal mode. */
    ARENGINE_POWER_MODE_NORMAL = 0,

    /** Power saving mode. */
    ARENGINE_POWER_MODE_POWER_SAVING = 1,

    /** Performance-preferred mode. */
    ARENGINE_POWER_MODE_PERFORMANCE_FIRST = 2,

    /** Outputs the device pose information only.
     * The power consumption in this mode is lower than that in <b>ARENGINE_POWER_MODE_NORMAL</b> mode.
     * In this mode, plane-related settings, such as <b>HMS_AREngine_ARConfig_SetPlaneFindingMode</b>, do not take
     * effect. */
    ARENGINE_POWER_MODE_BOOST = 3,

    /** Ultra power saving mode. */
    ARENGINE_POWER_MODE_ULTRA_POWER_SAVING = 11
} AREngine_ARPowerMode;

/**
 * @brief Focus mode.
 * @since 5.0.0(12)
 */
typedef enum {
    /** Focus fixed to infinity. */
    ARENGINE_FOCUS_MODE_FIXED = 0,

    /** Auto focus. */
    ARENGINE_FOCUS_MODE_AUTO = 1
} AREngine_ARFocusMode;

/**
 * @brief Plane type.
 * @since 5.0.0(12)
 */
typedef enum {
    /** A horizontal plane facing up (such as the ground and desk platform). */
    ARENGINE_PLANE_FACING_HORIZONTAL_UPWARD = 0,

    /** A horizontal plane facing down (such as the ceiling). */
    ARENGINE_PLANE_FACING_HORIZONTAL_DOWNWARD = 1,

    /** A vertical plane. */
    ARENGINE_PLANE_FACING_VERTICAL = 2,

    /** Unsupported type. */
    ARENGINE_PLANE_FACING_INVALID = 3
} AREngine_ARPlaneType;

/**
 * @brief AR capability type.
 * @since 5.0.0(12)
 */
typedef enum {
    /** Environment tracking capability. */
    ARENGINE_TYPE_WORLD = 0x01
} AREngine_ARType;

/**
 * @brief Semantic mode. If both of them need to be supported,
 * you can set them in (<b>ARENGINE_SEMANTIC_MODE_PLANE</b> | <b>ARENGINE_SEMANTIC_MODE_TARGET</b>) mode.
 * @since 5.0.0(12)
 */
typedef enum {
    /** Semantics not used. */
    ARENGINE_SEMANTIC_MODE_NONE = 0,

    /** Uses plane semantics. */
    ARENGINE_SEMANTIC_MODE_PLANE = 1,

    /** Uses object semantics. */
    ARENGINE_SEMANTIC_MODE_TARGET = 2
} AREngine_ARSemanticMode;

/**
 * @brief Orientation mode.
 * @since 5.0.0(12)
 */
typedef enum {
    /**
     * The orientation is consistent with that of the world coordinate system, but with minor adjustments. */
    ARENGINE_POINT_ORIENTATION_INITIALIZED_TO_IDENTITY = 0,

    /** The orientation is determined by the estimated plane's normal vector. */
    ARENGINE_POINT_ORIENTATION_ESTIMATED_SURFACE_NORMAL = 1
} AREngine_ARPointOrientationMode;

/**
 * @brief Semantic type of the current plane.
 * @since 5.0.0(12)
 */
typedef enum {
    /** Unknown type. */
    ARENGINE_PLANE_UNKNOWN = 0,

    /** Wall. */
    ARENGINE_PLANE_WALL = 1,

    /** Floor. */
    ARENGINE_PLANE_FLOOR = 2,

    /** Seat. */
    ARENGINE_PLANE_SEAT = 3,

    /** Table. */
    ARENGINE_PLANE_TABLE = 4,

    /** Ceiling. */
    ARENGINE_PLANE_CEILING = 5,

    /** Door. */
    ARENGINE_PLANE_DOOR = 6,

    /** Window. */
    ARENGINE_PLANE_WINDOW = 7,

    /** Bed. */
    ARENGINE_PLANE_BED = 8
} AREngine_ARSemanticPlaneLabel;

/**
 * @brief Shape of the recognized object.
 * @since 5.0.0(12)
 */
typedef enum {
    /** Unknown shape. */
    ARENGINE_TARGET_SHAPE_UNKNOWN = 0,

    /** Cube. The bounding box of regular objects can be recognized as a cube. */
    ARENGINE_TARGET_SHAPE_CUBE = 1,

    /** Circle. */
    ARENGINE_TARGET_SHAPE_CIRCLE = 2,

    /** Rectangle. */
    ARENGINE_TARGET_SHAPE_RECTANGLE = 3,
} AREngine_ARTargetShapeLabel;

/**
 * @brief Pose type.
 * @since 5.0.0(12)
 */
typedef enum {
    /** Default pose. */
    ARENGINE_POSE_TYPE_IDENTITY = 0,

    /** Pose that performs a 90-degree rotation. */
    ARENGINE_POSE_TYPE_ROTATE_90 = 1,

    /** Pose that performs a 180-degree rotation. */
    ARENGINE_POSE_TYPE_ROTATE_180 = 2,

    /** Pose that performs a 270-degree rotation. */
    ARENGINE_POSE_TYPE_ROTATE_270 = 3
} AREngine_ARPoseType;

/**
 * @brief Preview mode.
 * @since 5.0.0(12)
 */
typedef enum {
    /** Enables camera preview. */
    ARENGINE_PREVIEW_MODE_ENABLED = 0,

    /** Disables camera preview, for example, when in VR mode and the preview stream is not required.
        In this mode, OpenGL textures set through <b>HMS_AREngine_ARSession_SetCameraGLTexture</b> won't be updated. */
    ARENGINE_PREVIEW_MODE_DISABLED = 1
} AREngine_ARPreviewMode;

/**
 * @brief Error code returned by an API.
 * @since 5.0.0(12)
 */
typedef enum {
    /** Success. */
    ARENGINE_SUCCESS = 0,

    /** Permissions not granted, such as the camera permission. */
    ARENGINE_ERROR_PERMISSION_NOT_GRANTED = 201,

    /** Invalid parameters, for example, the input parameter is empty or invalid. */
    ARENGINE_ERROR_INVALID_ARGUMENT = 401,

    /** Device not compatible. */
    ARENGINE_ERROR_DEVICE_NOT_SUPPORTED = 801,

    /** Failure. */
    ARENGINE_ERROR_FATAL = 1009200001,

    /** Session paused. */
    ARENGINE_ERROR_SESSION_PAUSED = 1009200002,

    /** Session not paused. */
    ARENGINE_ERROR_SESSION_NOT_PAUSED = 1009200003,

    /** Not tracking. */
    ARENGINE_ERROR_NOT_TRACKING = 1009200004,

    /** Texture not set. */
    ARENGINE_ERROR_TEXTURE_NOT_SET = 1009200005,

    /** GL context missing. */
    ARENGINE_ERROR_MISSING_GL_CONTEXT = 1009200006,

    /** Configuration not supported. */
    ARENGINE_ERROR_UNSUPPORTED_CONFIGURATION = 1009200007,

    /** Resource exhausted. */
    ARENGINE_ERROR_RESOURCE_EXHAUSTED = 1009200008,

    /** Service unavailable. */
    ARENGINE_ERROR_NOT_AVAILABLE = 1009200009,

    /** Camera unavailable. */
    ARENGINE_ERROR_CAMERA_NOT_AVAILABLE = 1009200010
} AREngine_ARStatus;

/**
 * @brief Depth image mode.
 * @since 5.0.5(17)
 */
typedef enum {
    /** Does not provide depth information. */
    ARENGINE_DEPTH_MODE_DISABLED = 0,
 
    /** There are two depth sources, one from the motion algorithm and one from the hardware depth sensor (TOF).
     * Currently, only the depth from the motion used by master RGB camera is supported.
     */
    ARENGINE_DEPTH_MODE_AUTOMATIC = 1
} AREngine_ARDepthMode;

/**
 * @brief Depth Confidence mode.
 * @since 5.0.5(17)
 */
typedef enum {
    /** The confidence of this depth image is low. */
    ARENGINE_DEPTH_CONFIDENCE_LOW = 0,
 
    /** The confidence of this depth image is medium. */
    ARENGINE_DEPTH_CONFIDENCE_MEDIUM = 1,
 
    /** The confidence of this depth image is high. */
    ARENGINE_DEPTH_CONFIDENCE_HIGH = 2,
} AREngine_ARConfidenceLevel;

/**
 * @brief Creates a configuration object with a proper default configuration.
 * @param session The AREngine session.
 * @param outConfig Pointer to the newly allocated address of the configuration object.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARConfig_Create(const AREngine_ARSession *session, AREngine_ARConfig **outConfig);

/**
 * @brief Releases the memory used by a specific configuration object.
 * @param config To-be-released configuration object.
 * @since 5.0.0(12)
 */
void HMS_AREngine_ARConfig_Destroy(AREngine_ARConfig *config);

/**
 * @brief Obtains the current plane finding mode.
 * @param session The AREngine session.
 * @param config Points to the configuration object with the target configuration information.
 * @param planeFindingMode Plane finding mode. For details, please refer to <b>REngine_ARPlaneFindingMode<b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARConfig_GetPlaneFindingMode(const AREngine_ARSession *session,
    const AREngine_ARConfig *config, AREngine_ARPlaneFindingMode *planeFindingMode);

/**
 * @brief Sets the plane finding mode.
 * @param session The AREngine session.
 * @param config Points to the configuration object with the target configuration information.
 * @param planeFindingMode Plane finding mode. For details, please refer to <b>AREngine_ARPlaneFindingMode</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARConfig_SetPlaneFindingMode(const AREngine_ARSession *session,
    AREngine_ARConfig *config, AREngine_ARPlaneFindingMode planeFindingMode);

/**
 * @brief Obtains the preview update mode.
 * @param session The AREngine session.
 * @param config Points to the configuration object with the target configuration information.
 * @param updateMode Preview update mode. For details, please refer to <b>AREngine_ARUpdateMode</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARConfig_GetUpdateMode(const AREngine_ARSession *session,
    const AREngine_ARConfig *config, AREngine_ARUpdateMode *updateMode);

/**
 * @brief Sets the preview update mode.
 * @param session The AREngine session.
 * @param config Points to the configuration object with the target configuration information.
 * @param updateMode Preview update mode. For details, please refer to <b>AREngine_ARUpdateMode</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 *
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARConfig_SetUpdateMode(const AREngine_ARSession *session, AREngine_ARConfig *config,
    AREngine_ARUpdateMode updateMode);

/**
 * @brief Obtains the current power consumption mode.
 * @param session The AREngine session.
 * @param config Points to the configuration object with the target configuration information.
 * @param powerMode Power consumption mode. For details, please refer to <b>AREngine_ARPowerMode</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARConfig_GetPowerMode(const AREngine_ARSession *session, const AREngine_ARConfig *config,
    AREngine_ARPowerMode *powerMode);

/**
 * @brief Sets the power consumption mode.
 * @param session The AREngine session.
 * @param config Points to the configuration object with the target configuration information.
 * @param powerMode Power consumption mode. For details, please refer to <b>AREngine_ARPowerMode</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARConfig_SetPowerMode(const AREngine_ARSession *session, AREngine_ARConfig *config,
    AREngine_ARPowerMode powerMode);

/**
 * @brief Obtains the current focus mode.
 * @param session The AREngine session.
 * @param config Points to the configuration object with the target configuration information.
 * @param focusMode Focus mode. For details, please refer to <b>AREngine_ARFocusMode</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARConfig_GetFocusMode(const AREngine_ARSession *session, const AREngine_ARConfig *config,
    AREngine_ARFocusMode *focusMode);

/**
 * @brief Sets the focus mode.
 * @param session The AREngine session.
 * @param config Points to the configuration object with the target configuration information.
 * @param focusMode Focus mode. For details, please refer to <b>AREngine_ARFocusMode</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARConfig_SetFocusMode(const AREngine_ARSession *session, AREngine_ARConfig *config,
    AREngine_ARFocusMode focusMode);

/**
 * @brief Obtains the depth mode.
 * @param session The AREngine session.
 * @param config Points to the configuration object with the target configuration information.
 * @param outDepthMode Depth mode. For details, please refer to <b>AREngine_ARDepthMode</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.5(17)
 */
AREngine_ARStatus HMS_AREngine_ARConfig_GetDepthMode(const AREngine_ARSession *session, const AREngine_ARConfig *config,
    AREngine_ARDepthMode *outDepthMode);
 
/**
 * @brief Sets the depth mode.
 * @param session The AREngine session.
 * @param config Points to the configuration object with the target configuration information.
 * @param depthMode Depth mode. For details, please refer to <b>AREngine_ARDepthMode</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.5(17)
 */
AREngine_ARStatus HMS_AREngine_ARConfig_SetDepthMode(const AREngine_ARSession *session, AREngine_ARConfig *config,
    AREngine_ARDepthMode depthMode);

/**
 * @brief Sets the preview image size.
 * @param session The AREngine session.
 * @param config Points to the configuration object with the target configuration information.
 * @param width Width of the preview image, in pixels. You can check the value by calling
 * <b>OH_CameraManager_GetSupportedCameraOutputCapability</b>.
 * @param height Height of the preview image, in pixels. You can check the value by calling
 * <b>OH_CameraManager_GetSupportedCameraOutputCapability</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARConfig_SetPreviewSize(const AREngine_ARSession *session, AREngine_ARConfig *config,
    uint32_t width, uint32_t height);

/**
 * @brief Obtains the AR capability type in use.
 * @param session The AREngine session.
 * @param config Points to the configuration object with the target configuration information.
 * @param type Type of the AREngine capability in use. For details, please refer to <b>AREngine_ARType</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARConfig_GetARType(const AREngine_ARSession *session, const AREngine_ARConfig *config,
    AREngine_ARType *type);

/**
 * @brief Sets the AR capability type to use.
 * @param session The AREngine session.
 * @param config Points to the configuration object with the target configuration information.
 * @param type Type of capabilities supported by AREngine. For details, please refer to <b>AREngine_ARType</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARConfig_SetARType(const AREngine_ARSession *session, AREngine_ARConfig *config,
    AREngine_ARType type);

/**
 * @brief Obtains the current semantic recognition mode. This function is valid after
 * <b>HMS_AREngine_ARConfig_SetSemanticMode</b> has been called.
 * @param session The AREngine session.
 * @param config Points to the configuration object with the target configuration information.
 * @param mode Semantic mode. For details, please refer to <b>AREngine_ARSemanticMode</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARConfig_GetSemanticMode(const AREngine_ARSession *session,
    const AREngine_ARConfig *config, AREngine_ARSemanticMode *mode);

/**
 * @brief Sets the semantic recognition mode.
 * @param session The AREngine session.
 * @param config Points to the configuration object with the target configuration information.
 * @param mode Semantic mode. For details, please refer to <b>AREngine_ARSemanticMode</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARConfig_SetSemanticMode(const AREngine_ARSession *session, AREngine_ARConfig *config,
    AREngine_ARSemanticMode mode);

/**
 * @brief Obtains the maximum memory size for storing map data.
 * You can call this API to obtain the maximum memory size for storing map data after
 * <b>HMS_AREngine_ARSession_Configure</b> is executed.
 *
 * @param session The AREngine session.
 * @param config Points to the configuration object with the target configuration information.
 * @param maxMapSize Maximum memory size for storing map data, in MB.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARConfig_GetMaxMapSize(const AREngine_ARSession *session,
    const AREngine_ARConfig *config, uint64_t *maxMapSize);

/**
 * @brief Sets the maximum memory size for storing map data.
 * If the value you set is indicated as invalid, a valid size closest to the value you set will take effect.
 * The default value of the maximum memory size is 800 MB.
 *
 * @param session The AREngine session.
 * @param config Points to the configuration object with the target configuration information.
 * @param maxMapSize Maximum memory size for storing map data, in MB. The value ranges from 100 MB to 16 GB.
 * You are advised to set the memory size according to the device's memory capacity.
 * Exceeding the hardware limits may result in unexpected errors.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARConfig_SetMaxMapSize(const AREngine_ARSession *session, AREngine_ARConfig *config,
    uint64_t maxMapSize);

/**
 * @brief Sets the preview mode.
 * @param session The AREngine session.
 * @param config Points to the configuration object with the target configuration information.
 * @param mode Camera preview mode. For details, please refer to <b>AREngine_ARPreviewMode</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARConfig_SetCameraPreviewMode(const AREngine_ARSession *session,
    AREngine_ARConfig *config, AREngine_ARPreviewMode mode);

/**
 * @brief Obtains the current preview mode.
 * @param session The AREngine session.
 * @param config Points to the configuration object with the target configuration information.
 * @param outMode Camera preview mode. For details, please refer to <b>AREngine_ARPreviewMode</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARConfig_GetCameraPreviewMode(const AREngine_ARSession *session,
    AREngine_ARConfig *config, AREngine_ARPreviewMode *outMode);

/**
 * @brief Creates an <b>AREngine_ARSession</b> session.
 * @Permission This function depends on the camera, acceleration sensor, and gyroscope sensor permissions.
 * @param env JNI environment for the current APK.
 * @param applicationContext App context.
 * @param outSessionPointer Created session object.
 * @return Status type, indicating the calling status of the method.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARSession_Create(void *env, void *applicationContext,
    AREngine_ARSession **outSessionPointer);

/**
 * @brief Stops AREngine and the camera preview stream, clears the plane and anchor data, releases the camera, and
 * terminates the session.
 * After this method is called, you need to create <b>AREngine_ARSession</b> if you want to start AREngine again.
 *
 * @param session The AREngine session.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARSession_Stop(AREngine_ARSession *session);

/**
 * @brief Releases the resources used by the <b>AREngine_ARSession</b> session.
 * @param session The AREngine session.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
void HMS_AREngine_ARSession_Destroy(AREngine_ARSession *session);

/**
 * @brief Starts <b>AREngine_ARSession</b>, or restores <b>AREngine_ARSession</b> after
 * <b>HMS_AREngine_ARSession_Pause</b> is called.
 * @param session The AREngine session.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARSession_Resume(AREngine_ARSession *session);

/**
 * @brief Pauses the session, stops the camera preview stream, and releases the camera (otherwise, other apps will not
 * be able to use the camera service), without clearing the plane and anchor data.
 * @param session The AREngine session.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARSession_Pause(AREngine_ARSession *session);

/**
 * @brief Updates the computation result of AREngine.
 *
 * Call this API when you need to obtain the latest data. For example, after the camera moves, call this API
 * to obtain the new anchor's coordinates, plane coordinates, and image frames obtained by the camera.
 *
 * If <b>HMS_AREngine_ARConfig_GetUpdateMode</b> returns <b>ARENGINE_UPDATE_MODE_BLOCKING</b>,
 * this function is blocked until a new frame is available.
 *
 * @param session The AREngine session.
 * @param outFrame Updated frame object.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARSession_Update(AREngine_ARSession *session, AREngine_ARFrame *outFrame);

/**
 * @brief Configures an <b>AREngine_ARSession</b> session.
 * @param session The AREngine session.
 * @param config Configuration object to be applied on the device.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARSession_Configure(AREngine_ARSession *session, const AREngine_ARConfig *config);

/**
 * @brief Creates an anchor for continuous tracking.
 * @param session The AREngine session.
 * @param pose Pose object used for creating an anchor.
 * @param outAnchor Created anchor object.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARSession_AcquireNewAnchor(AREngine_ARSession *session, const AREngine_ARPose *pose,
    AREngine_ARAnchor **outAnchor);

/**
 * @brief Sets the OpenGL texture for storing the camera preview stream data.
 *
 * After your app calls <b>HMS_AREngine_ARSession_Update</b>, AREngine will update the camera preview to the texture.
 *
 * When using the texture, set it to the GL_TEXTURE_EXTERNAL_OES type, for example, by calling
 * glBindTexture(GL_TEXTURE_EXTERNAL_OES, textureId).
 *
 * @param session The AREngine session.
 * @param textureId OpenGL texture of the camera preview data stream.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARSession_SetCameraGLTexture(AREngine_ARSession *session, uint32_t textureId);

/**
 * @brief Sets the display height and width (in pixels). Make sure that the height and width you set here are
 * consistent with those of the display view. Otherwise, an error will occur with the camera preview.
 * @param session The AREngine session.
 * @param rotation Display rotation constant. The value is an enum defined in <b>AREngine_ARPoseType</b>.
 * @param width Display width, in pixels.
 * @param height Display height, in pixels.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARSession_SetDisplayGeometry(AREngine_ARSession *session, AREngine_ARPoseType rotation,
    int32_t width, int32_t height);

/**
 * @brief Obtains all anchors, including anchors in all states contained in <b>AREngine_ARTrackingState</b>.
 *
 * During app processing, only anchors in the <b>ARENGINE_TRACKING_STATE_TRACKING<b/> state need to be drawn,
 * and anchors in the <b>ARENGINE_TRACKING_STATE_STOPPED</b> state need to be deleted.
 * @param session The AREngine session.
 * @param outAnchorList List of all anchor objects.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARSession_GetAllAnchors(const AREngine_ARSession *session,
    AREngine_ARAnchorList *outAnchorList);

/**
 * @brief Obtains the list of all trackable objects of the specified type.
 * @param session The AREngine session.
 * @param filterType Type of the current trackable object.
 * @param outTrackableList A list of trackable objects of a specified type.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARSession_GetAllTrackables(const AREngine_ARSession *session,
    AREngine_ARTrackableType filterType, AREngine_ARTrackableList *outTrackableList);

/**
 * @brief Obtains the camera configuration information.
 * @param session The AREngine session.
 * @param outCameraConfig Camera configuration.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARSession_GetCameraConfig(const AREngine_ARSession *session,
    AREngine_ARCameraConfig *outCameraConfig);

/**
 * @brief Allocates and initializes a new pose object. You can leave poseRaw empty to create an uninitialized pose
 * object, and then call <b>HMS_AREngine_ARPoint_GetPose</b> and <b>HMS_AREngine_ARAnchor_GetPose</b> to assign a value
 * to the pose object.
 * @param session The AREngine session.
 * @param poseRaw Pose data, including translation components and rotation components. The obtained pose data is
 * an array with 7 elements: poseRaw[0] to poseRaw[3] are rotation quaternions, and poseRaw[4] to poseRaw[6] are
 * translation components (x, y, z).
 * @param poseRawSize Array size, which should be greater than or equal to <b>ARENGINE_POSE_RAW_SIZE</b>.
 * @param outPose Newly created pose object.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARPose_Create(const AREngine_ARSession *session, const float *poseRaw,
    const uint32_t poseRawSize, AREngine_ARPose **outPose);

/**
 * @brief Releases the memory used by the pose object.
 * @param pose Pose object to be released.
 * @since 5.0.0(12)
 */
void HMS_AREngine_ARPose_Destroy(AREngine_ARPose *pose);

/**
 * @brief Obtains pose data from the pose object, including translation components and rotation components.
 * The obtained pose data is an array with 7 elements: poseRaw[0] to poseRaw[3] are rotation quaternions,
 * and poseRaw[4] to poseRaw[6] are translation components (x, y, z).
 * @param session The AREngine session.
 * @param pose Pose object.
 * @param outPoseRaw Pose data.
 * @param poseRawSize Array size: <b>ARENGINE_POSE_RAW_SIZE</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARPose_GetPoseRaw(const AREngine_ARSession *session, const AREngine_ARPose *pose,
    float *outPoseRaw, int32_t poseRawSize);

/**
 * @brief Converts the pose data into a 4 x 4 matrix. outMatrixColMajor4x4 is the array for storing the matrix, where
 * data is stored in column-major order. Coordinates in the local coordinate system can be converted into ones in the
 * world coordinate system by multiplying this matrix with the coordinates in the local coordinate system.
 * @param session The AREngine session.
 * @param pose Pose object.
 * @param outMatrixColMajor4x4 Array with 16 floating point numbers, which are stored in a column-major order.
 * @param matrixColMajor4x4Size Array size: <b>ARENGINE_VIEW_MATRIX_SIZE</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARPose_GetMatrix(const AREngine_ARSession *session, const AREngine_ARPose *pose,
    float *outMatrixColMajor4x4, int32_t matrixColMajor4x4Size);

/**
 * @brief Sets outPose to the pose of the physical camera in the world space in the latest frame. The pose is that of
 * the OpenGL camera, where the positive direction of the x-axis is to the right, the positive direction of the y-axis
 * is upwards, and the negative direction of the z-axis is the look-at direction of the camera. The camera position
 * refers to the physical camera position, and the orientation of the camera's x-axis and y-axis is not affected by the
 * screen orientation (taking display rotation into account).
 *
 * The pose information can be used only when <b>ARENGINE_TRACKING_STATE_TRACKING </b> is returned by
 * <b>HMS_AREngine_ARCamera_GetTrackingState</b>.
 *
 * @param session The AREngine session.
 * @param camera Camera corresponding to the session.
 * @param outPose Pose of the physical camera in the world space.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARCamera_GetPose(const AREngine_ARSession *session, const AREngine_ARCamera *camera,
    AREngine_ARPose *outPose);

/**
 * @brief Sets outPose to the pose of the virtual camera (facing the display) in the world space, in order to render
 * AR content into the latest frame. The pose is that of the OpenGL camera, where the positive direction of the x-axis
 * is to the right, the positive direction of the y-axis is upwards, and the negative direction of the z-axis is the
 * look-at direction of the camera. The camera position refers to the physical camera position, and the orientation of
 * the camera's x-axis and y-axis is affected by the screen orientation (taking display rotation into account).
 *
 * The pose information can be used only when <b>ARENGINE_TRACKING_STATE_TRACKING</b> is returned by
 * <b>HMS_AREngine_ARCamera_GetTrackingState</b>.
 *
 * @param session The AREngine session.
 * @param camera Camera corresponding to the session.
 * @param outPose Pose of the virtual camera in the world space.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARCamera_GetDisplayOrientedPose(const AREngine_ARSession *session,
    const AREngine_ARCamera *camera, AREngine_ARPose *outPose);

/**
 * @brief Obtains the view matrix of the camera in the latest frame.
 *
 * This matrix performs the inverse transformation of the pose obtained through
 * <b>HMS_AREngine_ARCamera_GetDisplayOrientedPose</b>. That is, it transforms the world coordinate system to the camera
 * coordinate system.
 *
 * @param session The AREngine session.
 * @param camera Camera corresponding to the session.
 * @param outColMajor4x4 Array consisting of 16 floating point numbers, indicating a column-major uniform transformation
 * matrix in OpenGL.
 * @param colMajor4x4Num Array size. The array size must be greater than or equal to <b>ARENGINE_VIEW_MATRIX_SIZE</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARCamera_GetViewMatrix(const AREngine_ARSession *session,
    const AREngine_ARCamera *camera, float *outColMajor4x4, int32_t colMajor4x4Num);

/**
 * @brief Obtains the current tracking status of the camera. The camera pose is available only when the tracking status
 * is <b>ARENGINE_TRACKING_STATE_TRACKING</b>.
 * @param session The AREngine session.
 * @param camera Camera corresponding to the session.
 * @param outTrackingState current tracking status of the camera. For details, please refer to
 * <b>AREngine_ARTrackingState</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARCamera_GetTrackingState(const AREngine_ARSession *session,
    const AREngine_ARCamera *camera, AREngine_ARTrackingState *outTrackingState);

/**
 * @brief Obtains the reason why the current tracking status of the camera is <b>ARENGINE_TRACKING_STATE_PAUSED</b>.
 *
 * When the current tracking status of the camera is <b>ARENGINE_TRACKING_STATE_TRACKING</b>, the function returns
 * <b>ARENGINE_TRACKING_STATE_REASON_NONE</b>.
 *
 * @param session The AREngine session.
 * @param camera Camera corresponding to the session.
 * @param outTrackingStateReason Cause of the tracking failure. For details, please refer to
 * AREngine_ARTrackingStateReason.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARCamera_GetTrackingStateReason(const AREngine_ARSession *session,
    const AREngine_ARCamera *camera, AREngine_ARTrackingStateReason *outTrackingStateReason);

/**
 * @brief Obtains the projection matrix used for rendering virtual content on top of the camera image. This matrix can
 * be used for converting from the camera coordinate system to the clip coordinate system.
 * @param session The AREngine session.
 * @param camera Camera corresponding to the session.
 * @param clipPlaneDistance Distance to the OpenGL clipping plane. For details, please refer to
 * <b>AREngine_ClipPlaneDistance</b>.
 * @param outDestColMajor4x4 Array consisting of 16 floating point numbers, indicating a column-major
 * uniform transformation matrix in OpenGL.
 * @param destColMajor4x4Num Array size: <b>ARENGINE_VIEW_MATRIX_SIZE</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARCamera_GetProjectionMatrix(const AREngine_ARSession *session,
    const AREngine_ARCamera *camera, AREngine_ClipPlaneDistance clipPlaneDistance, float *outDestColMajor4x4,
    int32_t destColMajor4x4Num);

/**
 * @brief Obtains the object of the offline intrinsic camera parameters. This object can be used obtain the camera's
 * focal length, image size, principal point, and distortion parameters.
 * @param session The AREngine session.
 * @param camera Camera corresponding to the session.
 * @param outIntrinsics Object of the intrinsic camera parameters. For details, please refer to
 * <b>AREngine_ARCameraIntrinsics</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARCamera_GetImageIntrinsics(const AREngine_ARSession *session,
    const AREngine_ARCamera *camera, AREngine_ARCameraIntrinsics *outIntrinsics);

/**
 * @brief Releases the reference to the camera. You need to call <b>HMS_AREngine_ARCamera_Release</b> if you have called
 * <b>HMS_AREngine_ARFrame_AcquireCamera</b>. Calling this method before  <b>HMS_AREngine_ARFrame_AcquireCamera</b>
 * is called does not take effect.
 * @param camera Camera reference to be released..
 * @since 5.0.0(12)
 */
void HMS_AREngine_ARCamera_Release(AREngine_ARCamera *camera);

/**
 * @brief Creates an object of the intrinsic camera parameters.
 * @param session The AREngine session.
 * @param outIntrinsics Pointer to the newly allocated address of the object of intrinsic camera parameters.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARCameraIntrinsics_Create(const AREngine_ARSession *session,
    AREngine_ARCameraIntrinsics **outIntrinsics);

/**
 * @brief Releases a specific object of intrinsic camera parameters.
 * @param intrinsics To-be-released object of intrinsic camera parameters.
 * @since 5.0.0(12)
 */
void HMS_AREngine_ARCameraIntrinsics_Destroy(AREngine_ARCameraIntrinsics *intrinsics);

/**
 * @brief Obtains the focal length of a camera in pixels.
 * @param session The AREngine session.
 * @param intrinsics Pointer to the object of intrinsic camera parameters.
 * @param outFocalX Pixel focal length in the x(u) direction of the intrinsic camera parameter matrix.
 * @param outFocalY Pixel focal length in the y(v) direction of the intrinsic camera parameter matrix.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARCameraIntrinsics_GetFocalLength(const AREngine_ARSession *session,
    const AREngine_ARCameraIntrinsics *intrinsics, float *outFocalX, float *outFocalY);

/**
 * @brief Obtains the principal point of a camera, with the location of the point expressed in pixels.
 * @param session The AREngine session.
 * @param intrinsics Pointer to the object of intrinsic camera parameters.
 * @param outPrincipalX x-axis coordinate of the camera's principal point.
 * @param outPrincipalY y-axis coordinate of the camera's principal point.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARCameraIntrinsics_GetPrincipalPoint(const AREngine_ARSession *session,
    const AREngine_ARCameraIntrinsics *intrinsics, float *outPrincipalX, float *outPrincipalY);

/**
 * @brief Obtains the camera image size, including the width and height (in pixels).
 * @param session The AREngine session.
 * @param intrinsics Pointer to the object of intrinsic camera parameters.
 * @param outWidth Camera image width, in pixels.
 * @param outHeight Camera image height, in pixels.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARCameraIntrinsics_GetImageDimensions(const AREngine_ARSession *session,
    const AREngine_ARCameraIntrinsics *intrinsics, int32_t *outWidth, int32_t *outHeight);

/**
 * @brief Obtains a camera's distortion coefficients, which include 5 components: outDistortion[0] to outDistortion [2]
 * represent k1, k2, and k3 (radial distortion coefficients), and outDistortion [3] to outDistortion [4] are the
 * tangential distortion coefficients.
 * @param session The AREngine session.
 * @param intrinsics Pointer to the object of intrinsic camera parameters.
 * @param outDistortion Array of camera distortion parameters.
 * @param distortionNum Numbers of camera distortion parameters. For details, please refer to
 * <b>ARENGINE_DISTORTION_COUNT</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARCameraIntrinsics_GetDistortion(const AREngine_ARSession *session,
    const AREngine_ARCameraIntrinsics *intrinsics, float *outDistortion, int32_t distortionNum);

/**
 * @brief Creates an <b>AREngine_ARFrame</b> object and stores the pointer in *outFrame.
 * @param session The AREngine session.
 * @param outFrame Current frame object.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARFrame_Create(const AREngine_ARSession *session, AREngine_ARFrame **outFrame);

/**
 * @brief Deletes the current AREngine_ARFrame object.
 * @param frame Current frame object.
 * @since 5.0.0(12)
 */
void HMS_AREngine_ARFrame_Destroy(AREngine_ARFrame *frame);

/**
 * @brief Obtains whether the display (length, width, and rotation) changes. If so, you need to call
 * <b>HMS_AREngine_ARFrame_TransformDisplayUvCoords</b> again to obtain the correct coordinates of the texture map.
 * If the return value of outGeometryChangeState is 0, no changes have occurred. Otherwise, changes have occurred.
 * @param session The AREngine session.
 * @param frame Current frame object.
 * @param outGeometryChangeState Indicates whether the display (length, width, and rotation) changes. Value 0 indicates
 * that no change has occurred. Other values indicate that changes have occurred.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARFrame_GetDisplayGeometryChanged(const AREngine_ARSession *session,
    const AREngine_ARFrame *frame, int32_t *outGeometryChangeState);

/**
 * @brief Obtains the timestamp information (in nanoseconds) of the current frame.
 * @param session The AREngine session.
 * @param frame Current frame object.
 * @param outTimestampNs Timestamp information, in nanoseconds.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARFrame_GetTimestamp(const AREngine_ARSession *session, const AREngine_ARFrame *frame,
    int64_t *outTimestampNs);

/**
 * @brief Converts the texture coordinates so that the background image captured by the camera can be correctly
 * displayed.
 *
 * You need to call this method to convert the texture coordinates only when outGeometryChangeState returned by
 * <b>HMS_AREngine_ARFrame_GetDisplayGeometryChanged</b> is not 0, or when you have set a new display size by calling
 * <b>HMS_AREngine_ARSession_SetDisplayGeometry</b>.
 *
 * @param session The AREngine session.
 * @param frame Current frame object.
 * @param elementSize Number of texture coordinates to be converted. The value must be a multiple of 2 (uv coordinates).
 * @param uvsIn Original input UV coordinate. The array size is elementSize.
 * @param uvsOut Converted UV coordinates. The array size is elementSize.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARFrame_TransformDisplayUvCoords(const AREngine_ARSession *session,
    const AREngine_ARFrame *frame, int32_t elementSize, const float *uvsIn, float *uvsOut);

/**
 * @brief Casts a ray from the camera, with the direction of the ray determined by the points (pixelX, pixelY) in the
 * preview area. pixelX and pixelY can be obtained through the XComponent's DispatchTouchEvent() event.
 *
 * The ray collides with the plane or the points in the point cloud tracked by the system (if the point cloud is
 * recognized), resulting in intersections and hit results. The intersections are sorted by their distance from the
 * device, from closest to farthest, and stored in a linked list. (pixelX, pixelY) indicate the coordinates of a pixel
 * in the preview area.
 *
 * @param session The AREngine session.
 * @param frame Current frame object.
 * @param pixelX X coordinate.
 * @param pixelY Y coordinate.
 * @param hitResultList Hit result list.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARFrame_HitTest(const AREngine_ARSession *session, const AREngine_ARFrame *frame,
    float pixelX, float pixelY, AREngine_ARHitResultList *hitResultList);

/**
 * @brief Returns the point cloud data of the current frame.
 * @param session The AREngine session.
 * @param frame Current frame object.
 * @param outPointCloud Point cloud object of the current frame.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARFrame_AcquirePointCloud(const AREngine_ARSession *session,
    const AREngine_ARFrame *frame, AREngine_ARPointCloud **outPointCloud);

/**
 * @brief Obtains the camera parameter object of the current frame.
 * @param session The AREngine session.
 * @param frame Current frame object.
 * @param outCamera Camera parameter object of the current frame.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARFrame_AcquireCamera(const AREngine_ARSession *session, const AREngine_ARFrame *frame,
    AREngine_ARCamera **outCamera);

/**
 * @brief Obtains the updated trackable object of the specified type after <b>HMS_AREngine_ARSession_Update</b> is
 * called. For details about trackable object types, please refer to <b>AREngine_ARTrackableType</b>.
 * @param session The AREngine session.
 * @param frame Current frame object.
 * @param filterType Type of the trackable object to be returned.
 * @param outTrackableList List of trackable objects.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARFrame_GetUpdatedTrackables(const AREngine_ARSession *session,
    const AREngine_ARFrame *frame, AREngine_ARTrackableType filterType, AREngine_ARTrackableList *outTrackableList);

/**
 * @brief Obtains the image of the current frame of the camera.
 * @param session The AREngine session.
 * @param frame Current frame object.
 * @param outImage Image object of the current frame. For details, please refer to <b>AREngine_ARImage</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARFrame_AcquireCameraImage(const AREngine_ARSession *session,
    const AREngine_ARFrame *frame, AREngine_ARImage **outImage);

/**
 * @brief Obtains the coordinates of all points in a point cloud, as well as their confidence array.
 *
 * The coordinates are in the world coordinate system and are right-handed coordinates. You can obtain the point
 * cloud object by calling <b>HMS_AREngine_ARFrame_AcquirePointCloud</b>.
 *
 * @param session The AREngine session.
 * @param pointCloud Point cloud object.
 * @param outPointCloudData Coordinates of all points in a point cloud, as well as their confidence array, in the format
 * [x0, y0, z0, c0, x1, y1, z1, c1, x2,...].
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARPointCloud_GetData(const AREngine_ARSession *session,
    const AREngine_ARPointCloud *pointCloud, const float **outPointCloudData);

/**
 * @brief Obtains the coordinates of all points in a point cloud, as well as their confidence array size.
 * This function is used together with <b>HMS_AREngine_ARPointCloud_GetData</b>.
 * @param session The AREngine session.
 * @param pointCloud Point cloud object.
 * @param outNumberOfPoints Coordinates of all points in a point cloud, as well as their confidence array size.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARPointCloud_GetNumberOfPoints(const AREngine_ARSession *session,
    const AREngine_ARPointCloud *pointCloud, int32_t *outNumberOfPoints);

/**
 * @brief Obtains the timestamp when the current feature point cloud is detected, in nanoseconds.
 * @param session The AREngine session.
 * @param pointCloud Point cloud object.
 * @param outTimestampNs Timestamp when the current feature point cloud is detected.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARPointCloud_GetTimestamp(const AREngine_ARSession *session,
    const AREngine_ARPointCloud *pointCloud, int64_t *outTimestampNs);

/**
 * @brief Releases the memory used by the point cloud object.
 * @param pointCloud To-be-released point cloud object.
 * @since 5.0.0(12)
 */
void HMS_AREngine_ARPointCloud_Release(AREngine_ARPointCloud *pointCloud);

/**
 * @brief Obtains the pose of a specific anchor in the world coordinate system.
 *
 * Each time <b>HMS_AREngine_ARSession_Update</b> is called, the pose information returned by
 * <b>HMS_AREngine_ARAnchor_GetPose</b> may change.
 *
 * @param session The AREngine session.
 * @param anchor Anchor, whose pose needs to be obtained.
 * @param outPose Pose object of the anchor.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARAnchor_GetPose(const AREngine_ARSession *session, const AREngine_ARAnchor *anchor,
    AREngine_ARPose *outPose);

/**
 * @brief Obtains the tracking status of the pose of a specific anchor.
 * @param session The AREngine session.
 * @param anchor Anchor, the tracking status of whose pose needs to be obtained.
 * @param outTrackingState Tracking status of the anchor's current pose. For details, please refer to
 * <b>AREngine_ARTrackingState</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARAnchor_GetTrackingState(const AREngine_ARSession *session,
    const AREngine_ARAnchor *anchor, AREngine_ARTrackingState *outTrackingState);

/**
 * @brief Instructs AREngine to stop tracking and unbinds an anchor. However, this function does not release the
 * anchor. You need to release the anchor by calling <b>HMS_AREngine_ARAnchor_Release</b>.
 * @param session The AREngine session.
 * @param anchor Anchor object to be unbound.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARAnchor_Detach(AREngine_ARSession *session, AREngine_ARAnchor *anchor);

/**
 * @brief Releases the memory used by a specific anchor object. Before releasing the memory,
 * instruct AREngine to stop tracking and unbind the anchor.
 * @param anchor Anchor object to be released.
 * @since 5.0.0(12)
 */
void HMS_AREngine_ARAnchor_Release(AREngine_ARAnchor *anchor);

/**
 * @brief Creates a list of trackable objects.
 * @param session The AREngine session.
 * @param outTrackableList List of trackable objects.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARTrackableList_Create(const AREngine_ARSession *session,
    AREngine_ARTrackableList **outTrackableList);

/**
 * @brief Releases the list of trackable objects, along with all the anchor references it holds.
 * @param trackableList To-be-released list of trackable objects.
 * @since 5.0.0(12)
 */
void HMS_AREngine_ARTrackableList_Destroy(AREngine_ARTrackableList *trackableList);

/**
 * @brief Obtains the number of trackable objects in the list.
 * @param session The AREngine session.
 * @param trackableList List of trackable objects.
 * @param outSize Number of trackable objects in the trackable object list.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARTrackableList_GetSize(const AREngine_ARSession *session,
    const AREngine_ARTrackableList *trackableList, int32_t *outSize);

/**
 * @brief Obtains the object at a specific index from the trackable object list.
 * @param session The AREngine session.
 * @param trackableList List of trackable objects.
 * @param index Location of a trackable object in the trackable object list.
 * @param outTrackable Target trackable object.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARTrackableList_AcquireItem(const AREngine_ARSession *session,
    const AREngine_ARTrackableList *trackableList, int32_t index, AREngine_ARTrackable **outTrackable);

/**
 * @brief Releases a trackable object.
 * @param trackable Trackable objects to be released.
 * @since 5.0.0(12)
 */
void HMS_AREngine_ARTrackable_Release(AREngine_ARTrackable *trackable);

/**
 * @brief Obtains the type of a trackable object.
 * @param session The AREngine session.
 * @param trackable Trackable object.
 * @param outTrackableType Type of the trackable object. For details, please refer to <b>AREngine_ARTrackableType</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARTrackable_GetType(const AREngine_ARSession *session,
    const AREngine_ARTrackable *trackable, AREngine_ARTrackableType *outTrackableType);

/**
 * @brief Obtains the tracing status of the current trackable object.
 * @param session The AREngine session.
 * @param trackable Trackable object.
 * @param outTrackingState Tracking status of the trackable object. For details, please refer to
 * <b>AREngine_ARTrackingState</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARTrackable_GetTrackingState(const AREngine_ARSession *session,
    const AREngine_ARTrackable *trackable, AREngine_ARTrackingState *outTrackingState);

/**
 * @brief Creates an anchor object using the pose information of the trackable object. This anchor will be bound to the
 * current trackable object.
 * This anchor will be bound to the current trackable object.
 * @param session The AREngine session.
 * @param trackable Trackable object.
 * @param pose Pose information of a trackable object.
 * @param outAnchor Newly created anchor object.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARTrackable_AcquireNewAnchor(AREngine_ARSession *session,
    AREngine_ARTrackable *trackable, AREngine_ARPose *pose, AREngine_ARAnchor **outAnchor);

/**
 * @brief Obtains a list of anchor objects bound to the input trackable objects.
 * @param session The AREngine session.
 * @param trackable Trackable object.
 * @param outAnchorList List of anchor objects. This list must be created using <b>HMS_AREngine_ARAnchorList_Create</b>.
 * If you use a list that has been created, values will be reassigned for this list.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARTrackable_GetAnchors(AREngine_ARSession *session,
    const AREngine_ARTrackable *trackable, AREngine_ARAnchorList *outAnchorList);

/**
 * @brief Obtains the parent plane of a plane (a parent plane is generated when a plane is merged with another one). If
 * there is no parent plane, NULL is returned.
 * @param session The AREngine session.
 * @param plane Plane object to be processed.
 * @param outSubsumedBy Parent plane object of a specific plane.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARPlane_AcquireSubsumedBy(const AREngine_ARSession *session,
    const AREngine_ARPlane *plane, AREngine_ARPlane **outSubsumedBy);

/**
 * @brief Obtains the plane type.
 * @param session The AREngine session.
 * @param plane Plane object to be processed.
 * @param outPlaneType Plane type. For details, please refer to <b>AREngine_ARPlaneType</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARPlane_GetType(const AREngine_ARSession *session, const AREngine_ARPlane *plane,
    AREngine_ARPlaneType *outPlaneType);

/**
 * @brief Obtains the pose information for the conversion from the local coordinate system of a plane to the
 * world coordinate system.
 *
 * In the plane's local coordinate system (right-handed): The origin is at the center of the plane's bounding rectangle;
 * the x-axis is along the longer edge, the z-axis is along the shorter edge, and Y+ indicates the plane's normal
 * vector.
 *
 * @param session The AREngine session.
 * @param plane Plane object to be processed.
 * @param outPose Pose information for the conversion from the local coordinate system of a plane to the world
 * coordinate system.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARPlane_GetCenterPose(const AREngine_ARSession *session, const AREngine_ARPlane *plane,
    AREngine_ARPose *outPose);

/**
 * @brief Obtains the semantic type of a plane, such as desktop and floor. When using this function,
 * you need to call <b>HMS_AREngine_ARConfig_SetSemanticMode</b> to enable the semantic recognition mode.
 * @param session The AREngine session.
 * @param plane Plane object to be processed.
 * @param label Semantic type of the current plane. For details, please refer to <b>AREngine_ARSemanticPlaneLabel</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARPlane_GetLabel(const AREngine_ARSession *session, const AREngine_ARPlane *plane,
    AREngine_ARSemanticPlaneLabel *label);

/**
 * @brief Obtains the length of the plane's bounding rectangle along the x-axis of the plane's local coordinate system,
 * such as the width of the rectangle.
 * @param session The AREngine session.
 * @param plane Plane object to be processed.
 * @param outExtentX Length of the plane's bounding rectangle along the x-axis of the plane's local coordinate system,
 * in meters.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARPlane_GetExtentX(const AREngine_ARSession *session, const AREngine_ARPlane *plane,
    float *outExtentX);

/**
 * @brief Obtains the length of the plane's bounding rectangle along the z-axis of the plane's local coordinate system,
 * such as the height of the rectangle.
 * @param session The AREngine session.
 * @param plane Plane object to be processed.
 * @param outExtentZ Length of the plane's bounding rectangle along the z-axis of the plane's local coordinate system,
 * in meters.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARPlane_GetExtentZ(const AREngine_ARSession *session, const AREngine_ARPlane *plane,
    float *outExtentZ);

/**
 * @brief Obtains the size of the 2D vertex array of the detected plane. This function is used together
 * with <b>HMS_AREngine_ARPlane_GetPolygon</b>.
 * @param session The AREngine session.
 * @param plane Plane object to be processed.
 * @param outPolygonSize Size of a 2D vertex array.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARPlane_GetPolygonSize(const AREngine_ARSession *session, const AREngine_ARPlane *plane,
    int32_t *outPolygonSize);

/**
 * @brief Obtains the 2D vertex array of the detected plane, in the format of [x1, z1, x2, z2, ...].
 *
 * These values are defined in the x-z plane of the plane's local coordinate system and must be converted to the world
 * coordinate system through <b>HMS_AREngine_ARPlane_GetCenterPose</b>.
 *
 * Note: The returned coordinates [x1, z1, x2, z2, ...] in the vertical plane are also the coordinates in the
 * local coordinate system, which should be converted to the world coordinate system through
 * <b>HMS_AREngine_ARPlane_GetCenterPose</b>.
 *
 * @param session The AREngine session.
 * @param plane Plane object to be processed.
 * @param outPolygonXz Array consisting of 2D vertices of the detected plane.
 * @param polygonSize Size of the 2D vertex array, which is obtained through <b>HMS_AREngine_ARPlane_GetPolygonSize</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARPlane_GetPolygon(const AREngine_ARSession *session, const AREngine_ARPlane *plane,
    float *outPolygonXz, int32_t polygonSize);

/**
 * @brief Checks whether a pose is within the plane's bounding rectangle.
 *
 * A none-zero value is returned if the input pose (obtained through <b>HMS_AREngine_ARHitResult_GetHitPose</b>) is
 * within the plane's bounding rectangle.
 *
 * @param session The AREngine session.
 * @param plane Plane object to be processed.
 * @param pose Pose information.
 * @param outPoseInExtents Indicates whether the pose is within the plane's bounding rectangle.
 * Value 0 indicates that it is out of the range, and other values indicate that it is within the range.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARPlane_IsPoseInExtents(const AREngine_ARSession *session, const AREngine_ARPlane *plane,
    const AREngine_ARPose *pose, int32_t *outPoseInExtents);

/**
 * @brief Checks whether a pose is within the plane's bounding polygon.
 * @param session The AREngine session.
 * @param plane Plane object to be processed.
 * @param pose Pose information.
 * @param outPoseInPolygon Indicates whether the pose is within the plane's bounding polygon. Value 0 indicates that
 * it is out of the range, and other values indicate that it is within the range.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARPlane_IsPoseInPolygon(const AREngine_ARSession *session, const AREngine_ARPlane *plane,
    const AREngine_ARPose *pose, int32_t *outPoseInPolygon);

/**
 * @brief Obtains the orientation mode of an input point.
 * @param session The AREngine session.
 * @param point Input point object.
 * @param outOrientationMode Orientation mode of an input point. For details, please refer to
 * <b>AREngine_ARPointOrientationMode</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARPoint_GetOrientationMode(const AREngine_ARSession *session,
    const AREngine_ARPoint *point, AREngine_ARPointOrientationMode *outOrientationMode);

/**
 * @brief Obtains the pose information of an input point.
 * @param session The AREngine session.
 * @param point Input point object.
 * @param outPose Pose information of the input point.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARPoint_GetPose(const AREngine_ARSession *session, const AREngine_ARPoint *point,
    AREngine_ARPose *outPose);

/**
 * @brief Creates a list of hit testing result objects.
 * @param session The AREngine session.
 * @param outHitResultList To-be-created list of hit testing result objects.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARHitResultList_Create(const AREngine_ARSession *session,
    AREngine_ARHitResultList **outHitResultList);

/**
 * @brief Releases the list of hit testing result objects, as well as all hit testing result objects in the list.
 * @param hitResultList To-be-released list of hit testing result objects.
 * @since 5.0.0(12)
 */
void HMS_AREngine_ARHitResultList_Destroy(AREngine_ARHitResultList *hitResultList);

/**
 * @brief Obtains the number of objects in the hit testing result object list.
 * @param session The AREngine session.
 * @param hitResultList List of hit testing result objects.
 * @param outSize List size.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARHitResultList_GetSize(const AREngine_ARSession *session,
    const AREngine_ARHitResultList *hitResultList, int32_t *outSize);

/**
 * @brief Obtains the hit testing result object at a specific index from the hit testing result list.
 * @param session The AREngine session.
 * @param hitResultList List of hit testing result objects.
 * @param index Index of the hit testing result object to be obtained.
 * @param outHitResult Hit testing result object to be obtained.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARHitResultList_GetItem(const AREngine_ARSession *session,
    const AREngine_ARHitResultList *hitResultList, int32_t index, AREngine_ARHitResult *outHitResult);

/**
 * @brief Creates an empty hit testing result object.
 * @param session The AREngine session.
 * @param outHitResult Hit testing result object to be created.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARHitResult_Create(const AREngine_ARSession *session,
    AREngine_ARHitResult **outHitResult);

/**
 * @brief Releases the memory used by the hit testing result object.
 * @param hitResult Hit testing result object to be created.
 * @since 5.0.0(12)
 */
void HMS_AREngine_ARHitResult_Destroy(AREngine_ARHitResult *hitResult);

/**
 * @brief Obtains the distance from the camera to the hit location, in meters.
 * @param session The AREngine session.
 * @param hitResult Hit testing result object.
 * @param outDistance Distance from the camera to the hit object, in meters.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARHitResult_GetDistance(const AREngine_ARSession *session,
    const AREngine_ARHitResult *hitResult, float *outDistance);

/**
 * @brief Obtains the pose of an intersection. The pose's translation component corresponds to the intersection's
 * coordinates in the world coordinate system, while its rotation component varies according to the type of the
 * intersection (such as the intersection with a plane or a point cloud).
 *
 * 1. When a ray collides with the plane, in the local coordinate system: X+ is perpendicular to the ray and parallel to
 * the tracked plane; Y+ is the normal vector of the tracked plane; Z+ is parallel to the plane and roughly points to
 * the camera.
 * 2. When a ray collides with points in a point cloud, the system attempts to estimate a plane with the point cloud of
 * the hit area.
 * 2.1 If <b>HMS_AREngine_ARPoint_GetOrientationMode</b> returns
 * <b>ARENGINE_POINT_ORIENTATION_ESTIMATED_SURFACE_NORMAL</b>, X+ is perpendicular to the ray and parallel to the
 * tracked plane, Y+ is the normal vector of the tracked plane, and Z+ is parallel to the plane and roughly points to
 * the camera.
 * 2.2 If <b>ARENGINE_POINT_ORIENTATION_INITIALIZED_TO_IDENTITY</b> is returned, the orientation of the
 * coordinates won't change with the plane's angle. X+ is perpendicular to the ray and points to the right (from the
 * device's perspective), Y+ points upward, and Z+ roughly points to the camera. For details, please refer to the
 * orientation mode definition.
 *
 * @param session The AREngine session.
 * @param hitResult Hit testing result object.
 * @param outPose Intersection pose.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARHitResult_GetHitPose(const AREngine_ARSession *session,
    const AREngine_ARHitResult *hitResult, AREngine_ARPose *outPose);

/**
 * @brief Obtains the trackable object that is hit.
 * @param session The AREngine session.
 * @param hitResult Hit testing result object.
 * @param outTrackable Trackable object that is hit.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARHitResult_AcquireTrackable(const AREngine_ARSession *session,
    const AREngine_ARHitResult *hitResult, AREngine_ARTrackable **outTrackable);

/**
 * @brief Creates an anchor at the intersection.
 * @param session The AREngine session.
 * @param hitResult Hit testing result object.
 * @param outAnchor Newly created anchor object.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARHitResult_AcquireNewAnchor(AREngine_ARSession *session,
    AREngine_ARHitResult *hitResult, AREngine_ARAnchor **outAnchor);

/**
 * @brief Obtains the pose object for the conversion from the local coordinate system of the target semantic object
 * to the world coordinate system.
 * @param session The AREngine session.
 * @param target Target semantic object to be processed.
 * @param outARPose Pose for the conversion from the local coordinate system of the target semantic object to the world
 * coordinate system.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARTarget_GetCenterPose(const AREngine_ARSession *session,
    const AREngine_ARTarget *target, AREngine_ARPose *outARPose);

/**
 * @brief Obtains the coordinates of the minimum bounding box of a semantic object, in the format of (xmin, ymin, zmin,
 * xmax, ymax, zmax).
 * @param session The AREngine session.
 * @param target Target semantic object to be processed.
 * @param outAabb Coordinate set of the minimum bounding box of a semantic object.
 * @param aabbSize Array size: <b>ARENGINE_AABB_POINT_SIZE</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARTarget_GetAxisAlignedBoundingBox(const AREngine_ARSession *session,
    const AREngine_ARTarget *target, float *outAabb, int32_t aabbSize);

/**
 * @brief Obtains the sphere radius of a semantic object.
 * @param session The AREngine session.
 * @param target Target semantic object to be processed.
 * @param radius Sphere radius of the target semantic object, in meters.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARTarget_GetRadius(const AREngine_ARSession *session, const AREngine_ARTarget *target,
    float *radius);

/**
 * @brief Obtains the shape type of a semantic object.
 * @param session The AREngine session.
 * @param target Target semantic object to be processed.
 * @param shape Shape type of the target semantic object. For details, please refer to
 * <b>AREngine_ARTargetShapeLabel</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARTarget_GetShapeType(const AREngine_ARSession *session, const AREngine_ARTarget *target,
    AREngine_ARTargetShapeLabel *shape);

/**
 * @brief Creates a list of anchor objects.
 * @param session The AREngine session.
 * @param outAnchorList Reference to the anchor object list to be created.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARAnchorList_Create(const AREngine_ARSession *session,
    AREngine_ARAnchorList **outAnchorList);

/**
 * @brief Releases a list of anchor objects.
 * @param anchorList To-be-released list of anchor objects.
 * @since 5.0.0(12)
 */
void HMS_AREngine_ARAnchorList_Destroy(AREngine_ARAnchorList *anchorList);

/**
 * @brief Obtains the number of anchors in the anchor object list.
 * @param session The AREngine session.
 * @param anchorList List of anchor objects.
 * @param outSize Number of anchors in the anchor object list.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARAnchorList_GetSize(const AREngine_ARSession *session,
    const AREngine_ARAnchorList *anchorList, int32_t *outSize);

/**
 * @brief Obtains the anchor at a specific location from the anchor object list.
 * @param session The AREngine session.
 * @param anchorList List of anchor objects.
 * @param index Index of the anchor to be obtained in the anchor object list.
 * @param outAnchor Anchor information to be returned.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARAnchorList_AcquireItem(const AREngine_ARSession *session,
    const AREngine_ARAnchorList *anchorList, int32_t index, AREngine_ARAnchor **outAnchor);

/**
 * @brief Creates a camera configuration object.
 * @param session The AREngine session.
 * @param outCameraConfig Pointer to the newly allocated address of the camera configuration object.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARCameraConfig_Create(const AREngine_ARSession *session,
    AREngine_ARCameraConfig **outCameraConfig);

/**
 * @brief Releases a camera configuration object.
 * @param cameraConfig Pointer to the camera configuration object.
 * @since 5.0.0(12)
 */
void HMS_AREngine_ARCameraConfig_Destroy(AREngine_ARCameraConfig *cameraConfig);

/**
 * @brief Obtains the size of the image sent by the camera to the CPU for processing from a camera configuration object.
 * @param session The AREngine session.
 * @param cameraConfig Pointer to the camera configuration object.
 * @param outWidth Image width, in pixels.
 * @param outHeight Image height, in pixels.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARCameraConfig_GetImageDimensions(const AREngine_ARSession *session,
    const AREngine_ARCameraConfig *cameraConfig, int32_t *outWidth, int32_t *outHeight);

/**
 * @brief Obtains the size of the image texture sent by the camera to the GPU for processing from a camera configuration
 * object.
 * @param session The AREngine session.
 * @param cameraConfig Pointer to the camera configuration object.
 * @param outWidth Image texture width, in pixels.
 * @param outHeight Image texture height, in pixels.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARCameraConfig_GetTextureDimensions(const AREngine_ARSession *session,
    const AREngine_ARCameraConfig *cameraConfig, int32_t *outWidth, int32_t *outHeight);

/**
 * @brief Obtains the image format of the current frame.
 * @param session The AREngine session.
 * @param image Input image data.
 * @param outFormat Image format of the current frame.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARImage_GetFormat(const AREngine_ARSession *session, const AREngine_ARImage *image,
    AREngine_ARImageFormat *outFormat);

/**
 * @brief Obtains the image width of the current frame.
 * @param session The AREngine session.
 * @param image Image object of the current frame.
 * @param outWidth Image width (in pixels) of the current frame.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARImage_GetWidth(const AREngine_ARSession *session, const AREngine_ARImage *image,
    int32_t *outWidth);

/**
 * @brief Obtains the image height of the current frame.
 * @param session The AREngine session.
 * @param image Image object of the current frame.
 * @param outHeight Image height (in pixels) of the current frame.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARImage_GetHeight(const AREngine_ARSession *session, const AREngine_ARImage *image,
    int32_t *outHeight);

/**
 * @brief Obtains the number of planes in the current frame.
 * @param session The AREngine session.
 * @param image Image object of the current frame.
 * @param outCount Number of planes in the current frame.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARImage_GetPlaneCount(const AREngine_ARSession *session, const AREngine_ARImage *image,
    int32_t *outCount);

/**
 * @brief Obtains the plane data in the current frame.
 * @param session The AREngine session.
 * @param image Image object of the current frame.
 * @param planeIndex Plane index. The value ranges from 0 to n-1, where n is the number of planes in the image.
 * @param outData Pointer to the current image data.
 * @param outLength Length of the current image (in bytes).
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARImage_GetPlaneData(const AREngine_ARSession *session, const AREngine_ARImage *image,
    int32_t planeIndex, const uint8_t **outData, int32_t *outLength);

/**
 * @brief Obtains the distance between the start points of two consecutive pixels in an image, in bytes. The pixel
 * stride is always greater than 0.
 * @param session The AREngine session.
 * @param image Image object of the current frame.
 * @param planeIndex Plane index. The value ranges from 0 to n-1, where n is the number of planes in the image.
 * @param outPixelStride Image stride (in bytes).
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARImage_GetPlanePixelStride(const AREngine_ARSession *session,
    const AREngine_ARImage *image, int32_t planeIndex, int32_t *outPixelStride);

/**
 * @brief Obtains the number of bytes between the start positions of two consecutive pixel lines in an image. The line
 * spacing is always greater than 0.
 * @param session The AREngine session.
 * @param image Image object of the current frame.
 * @param planeIndex Plane index. The value ranges from 0 to n-1, where n is the number of planes in the image.
 * @param outRowStride Row stride (in bytes).
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARImage_GetPlaneRowStride(const AREngine_ARSession *session,
    const AREngine_ARImage *image, int32_t planeIndex, int32_t *outRowStride);

/**
 * @brief Obtains the timestamp of an image (in nanoseconds). Timestamps are usually monotonically increasing.
 * The specific meaning and time base of the timestamp depend on the image source. Timestamps of images from different
 * sources may have different time bases, so they should not be compared with each other.
 * @param session The AREngine session.
 * @param image Image object of the current frame.
 * @param outTimestamp Timestamp of the image (in nanoseconds).
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.0(12)
 */
AREngine_ARStatus HMS_AREngine_ARImage_GetTimestamp(const AREngine_ARSession *session, const AREngine_ARImage *image,
    int64_t *outTimestamp);

/**
 * @brief Releases the image object of the current frame, that is, the object created by
 * <b>HMS_AREngine_ARFrame_AcquireCameraImage</b>.
 * @param image Image object of the current frame.
 * @since 5.0.0(12)
 */
void HMS_AREngine_ARImage_Release(AREngine_ARImage *image);

/**
 * @brief Acquires a depth image object that corresponds to the current frame.
 * The depth image is a single 16-bit plane at index 0. Each pixel contains the distance in millimeters to the camera
 * plane, with the representable depth range between 0 millimeters and 65535 millimeters, or about 65 meters.
 * @param session The AREngine session.
 * @param frame Current frame object.
 * @param outDepthImage Depth image object of the current frame, please refer to <b>AREngine_ARImage</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.5(17)
 */
AREngine_ARStatus HMS_AREngine_ARFrame_AcquireDepthImage16Bits(const AREngine_ARSession *session,
    const AREngine_ARFrame *frame, AREngine_ARImage **outDepthImage);
 
/**
 * @brief Obtains the depth confidence image of the current frame. The confidence value is between
 * 0<b>ARENGINE_DEPTH_CONFIDENCE_LOW</b> and 2<b>ARENGINE_DEPTH_CONFIDENCE_HIGH</b>, inclusive, with 0 representing the
 * lowest confidence and 2 representing the highest confidence in the measured depth value. The width and height of the
 * depth confidence image are consistent with the depth image.
 * @param session The AREngine session.
 * @param frame Current frame object.
 * @param outConfidenceImage Depth confidence image of the current frame, please refer to <b>AREngine_ARImage</b>.
 * @return Execution status. For details, please refer to <b>AREngine_ARStatus</b>.
 * @since 5.0.5(17)
 */
AREngine_ARStatus HMS_AREngine_ARFrame_AcquireDepthConfidenceImage(const AREngine_ARSession *session,
    const AREngine_ARFrame *frame, AREngine_ARImage **outConfidenceImage);
#ifdef __cplusplus
}
#endif
/** @} */
#endif // NDK_INCLUDE_AR_ENGINE_CORE_H
