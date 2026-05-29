/*
 * Copyright (C) 2023 Huawei Device Co., Ltd.
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
 * @addtogroup CodecBase
 * @{
 *
 * @brief The CodecBase module provides variables, properties, and functions
 * for audio and video muxer, demuxer, and basic encoding and decoding functions.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */

/**
 * @file native_avcodec_base.h
 *
 * @brief Declare the Native API used for audio and video muxer,
 * demuxer and basic encoding and decoding functions.
 * @kit AVCodecKit
 * @library libnative_media_codecbase.so
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */

#ifndef NATIVE_AVCODEC_BASE_H
#define NATIVE_AVCODEC_BASE_H

#include "info/application_target_sdk_version.h"
#include <stdint.h>
#include <stdio.h>
#include "native_avbuffer.h"
#include "native_avmemory.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Forward declaration of OHNativeWindow.
 *
 * @since 9
 */
typedef struct NativeWindow OHNativeWindow;
/**
 * @brief Forward declaration of OH_AVCodec.
 *
 * @since 9
 */
typedef struct OH_AVCodec OH_AVCodec;

/**
 * @brief When an error occurs in the running of the OH_AVCodec instance, the function pointer will be called
 * to report specific error information.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @param codec OH_AVCodec instance
 * @param errorCode specific error code
 * @param userData User specific data
 * @since 9
 */
typedef void (*OH_AVCodecOnError)(OH_AVCodec *codec, int32_t errorCode, void *userData);

/**
 * @brief When the output stream changes, the function pointer will be called to report the new stream description
 * information. It should be noted that the life cycle of the OH_AVFormat pointer
 * is only valid when the function pointer is called, and it is forbidden to continue to access after the call ends.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @param codec OH_AVCodec instance
 * @param format New output stream description information
 * @param userData User specific data
 * @since 9
 */
typedef void (*OH_AVCodecOnStreamChanged)(OH_AVCodec *codec, OH_AVFormat *format, void *userData);

/**
 * @brief When OH_AVCodec needs new input data during the running process,
 * the function pointer will be called and carry an available Buffer to fill in the new input data.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @param codec OH_AVCodec instance
 * @param index The index corresponding to the newly available input buffer.
 * @param data New available input buffer.
 * @param userData User specific data
 * @deprecated since 11
 * @useinstead OH_AVCodecOnNeedInputBuffer
 * @since 9
 */
typedef void (*OH_AVCodecOnNeedInputData)(OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, void *userData);

/**
 * @brief When new output data is generated during the operation of OH_AVCodec, the function pointer will be
 * called and carry a Buffer containing the new output data. It should be noted that the life cycle of the
 * OH_AVCodecBufferAttr pointer is only valid when the function pointer is called. , which prohibits continued
 * access after the call ends.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @param codec OH_AVCodec instance
 * @param index The index corresponding to the new output Buffer.
 * @param data Buffer containing the new output data
 * @param attr The description of the new output Buffer, please refer to {@link OH_AVCodecBufferAttr}
 * @param userData specified data
 * @deprecated since 11
 * @useinstead OH_AVCodecOnNewOutputBuffer
 * @since 9
 */
typedef void (*OH_AVCodecOnNewOutputData)(OH_AVCodec *codec, uint32_t index, OH_AVMemory *data,
                                          OH_AVCodecBufferAttr *attr, void *userData);

/**
 * @brief When OH_AVCodec needs new input data during the running process,
 * the function pointer will be called and carry an available Buffer to fill in the new input data.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @param codec OH_AVCodec instance
 * @param index The index corresponding to the newly available input buffer.
 * @param buffer New available input buffer.
 * @param userData User specific data
 * @since 11
 */
typedef void (*OH_AVCodecOnNeedInputBuffer)(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData);

/**
 * @brief When new output data is generated during the operation of OH_AVCodec, the function pointer will be
 * called and carry a Buffer containing the new output data.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @param codec OH_AVCodec instance
 * @param index The index corresponding to the new output Buffer.
 * @param buffer Buffer containing the new output buffer.
 * @param userData specified data
 * @since 11
 */
typedef void (*OH_AVCodecOnNewOutputBuffer)(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData);

/**
 * @brief A collection of all asynchronous callback function pointers in OH_AVCodec. Register an instance of this
 * structure to the OH_AVCodec instance, and process the information reported through the callback to ensure the
 * normal operation of OH_AVCodec.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @param onError Monitor OH_AVCodec operation errors, refer to {@link OH_AVCodecOnError}
 * @param onStreamChanged Monitor codec stream information, refer to {@link OH_AVCodecOnStreamChanged}
 * @param onNeedInputData Monitoring codec requires input data, refer to {@link OH_AVCodecOnNeedInputData}
 * @param onNeedOutputData Monitor codec to generate output data, refer to {@link OH_AVCodecOnNewOutputData}
 * @deprecated since 11
 * @useinstead OH_AVCodecCallback
 * @since 9
 */
typedef struct OH_AVCodecAsyncCallback {
    OH_AVCodecOnError onError;
    OH_AVCodecOnStreamChanged onStreamChanged;
    OH_AVCodecOnNeedInputData onNeedInputData;
    OH_AVCodecOnNewOutputData onNeedOutputData;
} OH_AVCodecAsyncCallback;

/**
 * @brief A collection of all asynchronous callback function pointers in OH_AVCodec. Register an instance of this
 * structure to the OH_AVCodec instance, and process the information reported through the callback to ensure the
 * normal operation of OH_AVCodec.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @param onError Monitor OH_AVCodec operation errors, refer to {@link OH_AVCodecOnError}
 * @param onStreamChanged Monitor codec stream information, refer to {@link OH_AVCodecOnStreamChanged}
 * @param onNeedInputBuffer Monitoring codec requires input buffer, refer to {@link OH_AVCodecOnNeedInputBuffer}
 * @param onNewOutputBuffer Monitor codec to generate output buffer, refer to {@link OH_AVCodecOnNewOutputBuffer}
 * @since 11
 */
typedef struct OH_AVCodecCallback {
    OH_AVCodecOnError onError;
    OH_AVCodecOnStreamChanged onStreamChanged;
    OH_AVCodecOnNeedInputBuffer onNeedInputBuffer;
    OH_AVCodecOnNewOutputBuffer onNewOutputBuffer;
} OH_AVCodecCallback;

/**
 * @brief the function pointer will be called to get sequence media data.
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @param data    OH_AVBuffer buffer to fill
 * @param length   expected to read size;
 * @param pos    current read offset
 * @return  Actual size of data read to the buffer.
 * @since 12
 */
typedef int32_t (*OH_AVDataSourceReadAt)(OH_AVBuffer *data, int32_t length, int64_t pos);

/**
 * @brief User customized data source.
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
typedef struct OH_AVDataSource {
    /**
     * Total size of the data source.
     */
    int64_t size;
    /**
     * Callback interface for reading data from datasource.
     */
    OH_AVDataSourceReadAt readAt;
} OH_AVDataSource;

/**
 * @brief the function pointer will be called to get sequence media data.
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @param data    OH_AVBuffer buffer to fill
 * @param length   expected to read size;
 * @param pos    current read offset
 * @param userData user-defined data
 * @return  Actual size of data read to the buffer.
 * @since 20
 */
typedef int32_t (*OH_AVDataSourceReadAtExt)(OH_AVBuffer *data, int32_t length, int64_t pos, void *userData);

/**
 * @brief User customized data source.
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 20
 */
typedef struct OH_AVDataSourceExt {
    /**
     * Total size of the data source.
     */
    int64_t size;
    /**
     * Callback interface for reading data from datasource.
     */
    OH_AVDataSourceReadAtExt readAt;
} OH_AVDataSourceExt;

/**
 * @brief Enumerates the mime types of video avc codec.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_AVC __attribute__((__availability__(ohos, introduced=9.0.0)));
/**
 * @brief Enumerates the mime types of audio aac codec.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_AAC __attribute__((__availability__(ohos, introduced=9.0.0)));

/**
 * @brief Enumerates the mime types of audio flac codec.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_FLAC __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Enumerates the mime types of audio vorbis codec.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_VORBIS __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Enumerates the mime types of audio mp3 codec.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_MPEG __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Enumerates the mime types of video hevc codec.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_HEVC __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * @brief Enumerates the mime types of video mpeg4 muxer.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @deprecated since 11
 * @since 10
 */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_MPEG4 __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * @brief Enumerates the mime types of cover jpg muxer.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_AVCODEC_MIMETYPE_IMAGE_JPG __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Enumerates the mime types of cover png muxer.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_AVCODEC_MIMETYPE_IMAGE_PNG __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Enumerates the mime types of cover bmp muxer.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_AVCODEC_MIMETYPE_IMAGE_BMP __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * @brief Enumerates the mime types of audio vivid codec.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 11
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_VIVID __attribute__((__availability__(ohos, introduced=11.0.0)));
/**
 * @brief Enumerates the mime types of audio amrnb codec.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 11
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB __attribute__((__availability__(ohos, introduced=11.0.0)));
/**
 * @brief Enumerates the mime types of audio amrwb codec.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 11
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB __attribute__((__availability__(ohos, introduced=11.0.0)));
/**
 * @brief Enumerates the mime types of audio opus codec.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 11
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_OPUS __attribute__((__availability__(ohos, introduced=11.0.0)));
/**
 * @brief Enumerates the mime types of audio g711mu codec.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 11
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_G711MU __attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Enumerates the mime type of audio ape codec.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_APE __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Enumerates the MIME type of versatile video coding.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_VVC __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Enumerates the mime type of subtitle srt.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_AVCODEC_MIMETYPE_SUBTITLE_SRT __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Enumerates the mime type of subtitle webvtt.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_AVCODEC_MIMETYPE_SUBTITLE_WEBVTT __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Enumerates the mime type of audio raw stream.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 18
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_RAW __attribute__((__availability__(ohos, introduced=18.0.0)));

/**
 * @brief Enumerates the mime types of audio G711 A-law codec.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 20
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_G711A __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Enumerates the mime types of ALAC (Apple Lossless Audio Codec).
 *
 * @since 22
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_ALAC __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Enumerates the mime types of audio AC-3 codec.
 *
 * @since 22
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_AC3 __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Enumerates the mime types of audio Enhanced AC-3 codec.
 *
 * @since 22
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_EAC3 __attribute__((__availability__(ohos, introduced=22.0.0)));


/**
 * @brief Enumerates the mime types of windows media audio 1 codec.
 *
 * @since 22
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_WMAV1 __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Enumerates the mime types of windows media audio 2 codec.
 *
 * @since 22
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_WMAV2 __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Enumerates the mime types of windows media audio 9 professional codec.
 *
 * @since 22
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_WMAPRO __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Key for specifying the number of bytes per audio packet. The value type is int32_t.
 *
 * This key is required only for Windows Media audio decoders. The supported decoder MIME types
 * include {@link OH_AVCODEC_MIMETYPE_AUDIO_WMAV1}, {@link OH_AVCODEC_MIMETYPE_AUDIO_WMAV2},
 * and {@link OH_AVCODEC_MIMETYPE_AUDIO_WMAPRO}.
 *
 * @since 22
 */
extern const char *OH_MD_KEY_BLOCK_ALIGN __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Enumerates the mime types of audio GSM codec.
 *
 * @since 22
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_GSM __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Enumerates the mime types of audio GSM Microsoft varient codec.
 *
 * @since 22
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_GSM_MS __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Enumerates the mime types of audio TwinVQ codec.
 *
 * @since 23
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_TWINVQ __attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Enumerates the mime types of audio internet low bitrate codec.
 *
 * @since 23
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_ILBC __attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Enumerates the mime types of audio TrueHD codec.
 *
 * @since 23
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_TRUEHD __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Enumerates the mime types of audio DV Audio codec.
 *
 * @since 23
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_DVAUDIO __attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Enumerates the mime types of audio DTS codec.
 *
 * @since 23
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_DTS __attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Enumerates the mime types of audio COOK codec.
 *
 * @since 23
 */
extern const char *OH_AVCODEC_MIMETYPE_AUDIO_COOK __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Enumerates the MIME type of video mpeg2 codec.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 17
 */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_MPEG2 __attribute__((__availability__(ohos, introduced=17.0.0)));
/**
 * @brief Enumerates the MIME type of video mpeg4 part2 codec.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 17
 */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_MPEG4_PART2 __attribute__((__availability__(ohos, introduced=17.0.0)));

/**
 * @brief Enumerates the MIME type of video h263 codec.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 17
 */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_H263 __attribute__((__availability__(ohos, introduced=17.0.0)));

/**
 * @brief Enumerates the MIME type of video VC-1 codec.
 *
 * @since 22
 */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_VC1 __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
* @brief Enumerates the MIME type of video AV1 codec.
 *
 * @since 23
 * */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_AV1 __attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Enumerates the MIME type of video VP9 codec.
 *
 * @since 23
 */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_VP9 __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Enumerates the MIME type of video VP8 codec.
 *
 * @since 23
 */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_VP8 __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Enumerates the MIME type of video RV30 codec.
 *
 * @since 23
 * */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_RV30 __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Enumerates the MIME type of video RV40 codec.
 *
 * @since 23
 * */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_RV40 __attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Enumerates the MIME type of video WVC1 codec.
 *
 * @since 23
 * */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_WVC1 __attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Enumerates the MIME type of video DV codec.
 *
 * @since 23
 * */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_DVVIDEO __attribute__((__availability__(ohos, introduced=23.0.0)));
 
/**
 * @brief Enumerates the MIME type of video raw.
 *
 * @since 23
 * */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_RAWVIDEO __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Enumerates the MIME type of video MPEG1 codec.
 *
 * @since 23
 * */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_MPEG1 __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Enumerates the MIME type of video Cinepak codec.
 *
 * @since 24
 * */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_CINEPAK __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Enumerates the MIME type of video MSVIDEO1 codec.
 *
 * @since 22
 */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_MSVIDEO1 __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Enumerates the MIME type of video WMV3 codec.
 *
 * @since 22
 */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_WMV3 __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Enumerates the MIME type of video MJPEG codec.
 *
 * @since 22
 */
extern const char *OH_AVCODEC_MIMETYPE_VIDEO_MJPEG __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Key for timeStamp in surface's extraData, value type is int64_t.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @deprecated since 14
 * @since 9
 */
extern const char *OH_ED_KEY_TIME_STAMP __attribute__((__availability__(ohos, introduced=9.0.0)));
/**
 * @brief Key for endOfStream in surface's extraData, value type is bool.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @deprecated since 14
 * @since 9
 */
extern const char *OH_ED_KEY_EOS __attribute__((__availability__(ohos, introduced=9.0.0)));

/**
 * @brief Key for track type, value type is int32_t, see {@link OH_MediaType}.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
extern const char *OH_MD_KEY_TRACK_TYPE __attribute__((__availability__(ohos, introduced=9.0.0)));
/**
 * @brief Key for codec mime type, value type is string.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
extern const char *OH_MD_KEY_CODEC_MIME __attribute__((__availability__(ohos, introduced=9.0.0)));
/**
 * @brief Key for file duration in microseconds, value type is int64_t.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
extern const char *OH_MD_KEY_DURATION __attribute__((__availability__(ohos, introduced=9.0.0)));
/**
 * @brief Key for bitrate, value type is int64_t.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
extern const char *OH_MD_KEY_BITRATE __attribute__((__availability__(ohos, introduced=9.0.0)));
/**
 * @brief Key for max input size, value type is int32_t.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
extern const char *OH_MD_KEY_MAX_INPUT_SIZE __attribute__((__availability__(ohos, introduced=9.0.0)));
/**
 * @brief Key for video width, value type is int32_t.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
extern const char *OH_MD_KEY_WIDTH __attribute__((__availability__(ohos, introduced=9.0.0)));
/**
 * @brief Key for video height, value type is int32_t.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
extern const char *OH_MD_KEY_HEIGHT __attribute__((__availability__(ohos, introduced=9.0.0)));
/**
 * @brief Key for video pixel format, value type is int32_t, see {@link OH_AVPixelFormat}.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
extern const char *OH_MD_KEY_PIXEL_FORMAT __attribute__((__availability__(ohos, introduced=9.0.0)));
/**
 * @brief key for audio raw format, value type is int32_t , see {@link OH_BitsPerSample}.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
extern const char *OH_MD_KEY_AUDIO_SAMPLE_FORMAT __attribute__((__availability__(ohos, introduced=9.0.0)));
/**
 * @brief Key for video frame rate, value type is double.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
extern const char *OH_MD_KEY_FRAME_RATE __attribute__((__availability__(ohos, introduced=9.0.0)));
/**
 * @brief video encode bitrate mode, the value type is int32_t, see {@link OH_VideoEncodeBitrateMode}.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
extern const char *OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE __attribute__((__availability__(ohos, introduced=9.0.0)));
/**
 * @brief encode profile, the value type is int32_t. see {@link OH_AVCProfile}, {@link OH_HEVCProfile},
 * {@link OH_AACProfile}.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
extern const char *OH_MD_KEY_PROFILE __attribute__((__availability__(ohos, introduced=9.0.0)));
/**
 * @brief Key for audio channel count, value type is int32_t.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
extern const char *OH_MD_KEY_AUD_CHANNEL_COUNT __attribute__((__availability__(ohos, introduced=9.0.0)));
/**
 * @brief Key for audio sample rate, value type is int32_t.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
extern const char *OH_MD_KEY_AUD_SAMPLE_RATE __attribute__((__availability__(ohos, introduced=9.0.0)));
/**
 * @brief Key for the interval of key frame. value type is int32_t, the unit is milliseconds. A negative value means no
 * key frames are requested after the first frame. A zero value means a stream containing all key frames is requested.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
extern const char *OH_MD_KEY_I_FRAME_INTERVAL __attribute__((__availability__(ohos, introduced=9.0.0)));
/**
 * @brief Key of the surface rotation angle. value type is int32_t: should be {0, 90, 180, 270}, default is 0.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
extern const char *OH_MD_KEY_ROTATION __attribute__((__availability__(ohos, introduced=9.0.0)));

/**
 * @brief Key for video transform type, value type is int32_t, see {@link OH_NativeBuffer_TransformType}.
 *
 * This key is used to set the surface transform for video decoders (surface mode).
 * If not specified, the default value is 0 ({@link NATIVEBUFFER_ROTATE_NONE}).
 * This key and {@link OH_MD_KEY_ROTATION} are mutually exclusive. If both are provided,
 * OH_MD_KEY_VIDEO_TRANSFORM_TYPE takes precedence.
 * Note that the degrees specified in {@link OH_NativeBuffer_TransformType} represent counter-clockwise rotation,
 * which are opposite to the direction of rotation defined by {@link OH_MD_KEY_ROTATION}.
 * The correspondence is:
 * - {@link NATIVEBUFFER_ROTATE_NONE}  => same as OH_MD_KEY_ROTATION = 0
 * - {@link NATIVEBUFFER_ROTATE_90}    => same as OH_MD_KEY_ROTATION = 270
 * - {@link NATIVEBUFFER_ROTATE_180}   => same as OH_MD_KEY_ROTATION = 180
 * - {@link NATIVEBUFFER_ROTATE_270}   => same as OH_MD_KEY_ROTATION = 90
 *
 * @since 22
 */
extern const char *OH_MD_KEY_VIDEO_TRANSFORM_TYPE __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Key for video YUV value range flag, value type is bool, true for full range, false for limited range.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_RANGE_FLAG __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Key for video color primaries, value type is int32_t, see {@link OH_ColorPrimary}.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_COLOR_PRIMARIES __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Key for video transfer characteristics, value type is int32_t, see {@link OH_TransferCharacteristic}.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_TRANSFER_CHARACTERISTICS __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Key for video matrix coefficients, value type is int32_t, see {@link OH_MatrixCoefficient}.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_MATRIX_COEFFICIENTS __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Key for the request an I-Frame immediately, value type is bool.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_REQUEST_I_FRAME __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Key for the desired encoding quality, value type is int32_t, this key is only.
 * supported for encoders that are configured in constant quality mode.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_QUALITY __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Key of the codec specific data. value type is a uint8_t pointer.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_CODEC_CONFIG __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief source format Key for title, value type is string.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_TITLE __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief source format Key for artist, value type is string.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_ARTIST __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief source format Key for album, value type is string.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_ALBUM __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief source format Key for album artist, value type is string.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_ALBUM_ARTIST __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief source format Key for date, value type is string.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_DATE __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief source format Key for comment, value type is string.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_COMMENT __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief source format Key for genre, value type is string.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_GENRE __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief source format Key for copyright, value type is string.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_COPYRIGHT __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief source format Key for language, value type is string.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_LANGUAGE __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief source format Key for description, value type is string.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_DESCRIPTION __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief source format Key for lyrics, value type is string.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_LYRICS __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief source format Key for track count, value type is int32_t.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_TRACK_COUNT __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Key for the desired encoding channel layout, value type is int64_t, this key is only supported for encoders.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_CHANNEL_LAYOUT __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Key for bits per coded sample, value type is int32_t, supported for flac encoder,
 * see {@link OH_BitsPerSample}.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_BITS_PER_CODED_SAMPLE __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Key for the aac format, value type is int32_t, supported for aac decoder.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_AAC_IS_ADTS __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Key for aac sbr mode, value type is int32_t, supported for aac encoder.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_SBR __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Key for flac compliance level, value type is int32_t.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_COMPLIANCE_LEVEL __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Key for vorbis identification header, value type is a uint8_t pointer, supported only for vorbis decoder.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_IDENTIFICATION_HEADER __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Key for vorbis setup header, value type is a uint8_t pointer, supported only for vorbis decoder.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_KEY_SETUP_HEADER __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Key for video scale type, value type is int32_t, see {@link OH_ScalingMode}.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @deprecated since 14
 * @useinstead OH_NativeWindow_NativeWindowSetScalingModeV2
 * @since 10
 */
extern const char *OH_MD_KEY_SCALING_MODE __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Key for max input buffer count, value type is int32_t.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_MAX_INPUT_BUFFER_COUNT __attribute__((__availability__(ohos, introduced=10.0.0)));
/**
 * @brief Key for max output buffer count, value type is int32_t.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
extern const char *OH_MD_MAX_OUTPUT_BUFFER_COUNT __attribute__((__availability__(ohos, introduced=10.0.0)));

/**
 * @brief Key for audio codec compression level, value type is int32_t.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 11
 */
extern const char *OH_MD_KEY_AUDIO_COMPRESSION_LEVEL __attribute__((__availability__(ohos, introduced=11.0.0)));
/**
 * @brief Key of the video is hdr vivid. value type is bool.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 11
 */
extern const char *OH_MD_KEY_VIDEO_IS_HDR_VIVID __attribute__((__availability__(ohos, introduced=11.0.0)));
/**
 * @brief Key for number of audio objects. value type is int32_t.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 11
 */
extern const char *OH_MD_KEY_AUDIO_OBJECT_NUMBER __attribute__((__availability__(ohos, introduced=11.0.0)));
/**
 * @brief Key for meta data of audio vivid. value type is a uint8_t pointer.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 11
 */
extern const char *OH_MD_KEY_AUDIO_VIVID_METADATA __attribute__((__availability__(ohos, introduced=11.0.0)));

/**
 * @brief Key for querying the maximum long-term reference count of video encoder, value type is int32_t.
 * You should query the count through interface {@link OH_AVCapability_GetFeatureProperties}
 * with enum {@link VIDEO_ENCODER_LONG_TERM_REFERENCE}.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT
__attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for enable the temporal scalability mode, value type is int32_t (0 or 1): 1 is enabled, 0 otherwise.
 * The default value is 0. To query supported, you should use the interface {@link OH_AVCapability_IsFeatureSupported}
 * with enum {@link VIDEO_ENCODER_TEMPORAL_SCALABILITY}. This is an optional key that applies only to video encoder.
 * It is used in configure.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_ENCODER_ENABLE_TEMPORAL_SCALABILITY
__attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for describing the temporal group of picture size, value type is int32_t. It takes effect only when
 * temporal level scale is enable. This is an optional key that applies only to video encoder. It is used in configure.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_SIZE __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for describing the reference mode in temporal group of picture, value type is int32_t, see enum
 * {@link OH_TemporalGopReferenceMode}. It takes effect only when temporal level scale is enabled.
 * This is an optional key that applies only to video encoder. It is used in configure.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_REFERENCE_MODE
__attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for describing the count of used long-term reference frames, value type is int32_t, must be within the
 * supported range. To get supported range, you should query whether the capability is supported through the interface
 * {@link OH_AVCapability_GetFeatureProperties} with enum {@link VIDEO_ENCODER_LONG_TERM_REFERENCE}, otherwise, not set
 * the key. This is an optional key that applies only to video encoder. It is used in configure.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for describing mark this frame as a long term reference frame, value type is int32_t (0 or 1): 1 is mark,
 * 0 otherwise. It takes effect only when the number of used long term reference frames is configured. This is an
 * optional key that applies only to video encoder input loop. It takes effect immediately.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_MARK_LTR __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for describing the long term reference frame poc referenced by this frame, value type is int32_t. This is
 * an optional key that applies only to video encoder input loop. It takes effect immediately.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_USE_LTR __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for indicating this frame is a long-term reference frame, value type is int32_t (0 or 1): 1 is LTR,
 * 0 otherwise. This is an optional key that applies only to video encoder output loop.
 * It indicates the attribute of the frame.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_PER_FRAME_IS_LTR __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for describing the frame poc, value type is int32_t. This is an optional key that applies only to video
 * encoder output loop. It indicates the attribute of the frame.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_PER_FRAME_POC __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for describing the top-coordinate (y) of the crop rectangle, value type is int32_t. This is the top-most
 * row included in the crop frame, where row indices start at 0.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_CROP_TOP __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for describing the bottom-coordinate (y) of the crop rectangle, value type is int32_t. This is the
 * bottom-most row included in the crop frame, where row indices start at 0.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_CROP_BOTTOM __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for describing the left-coordinate (x) of the crop rectangle, value type is int32_t.
 * This is the left-most column included in the crop frame, where column indices start at 0.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_CROP_LEFT __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for describing the right-coordinate (x) of the crop rectangle, value type is int32_t. This is the
 * right-most column included in the crop frame, where column indices start at 0.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_CROP_RIGHT __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for describing the stride of the video buffer layout, value type is int32_t. Stride (or row increment) is
 * the difference between the index of a pixel and that of the pixel directly underneath. For YUV 420 formats, the
 * stride corresponds to the Y plane; the stride of the U and V planes can be calculated based on the color format,
 * though it is generally undefined and depends on the device and release.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_STRIDE __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for describing the plane height of a multi-planar (YUV) video buffer layout, value type is int32_t.
 * Slice height (or plane height/vertical stride) is the number of rows that must be skipped to get from
 * the top of the Y plane to the top of the U plane in the buffer. In essence the offset of the U plane
 * is sliceHeight * stride. The height of the U/V planes can be calculated based on the color format,
 * though it is generally undefined and depends on the device and release.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_SLICE_HEIGHT __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for describing the valid picture width of the video, value type is int32_t.
 * Get the value from an OH_AVFormat instance, which obtained by calling {@link OH_VideoDecoder_GetOutputDescription}
 * or {@link OH_AVCodecOnStreamChanged}.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_PIC_WIDTH __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for describing the valid picture height of the video, value type is int32_t.
 * Get the value from an OH_AVFormat instance, which obtained by calling {@link OH_VideoDecoder_GetOutputDescription}
 * or {@link OH_AVCodecOnStreamChanged}.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_PIC_HEIGHT __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key to enable the low latency mode, value type is int32_t (0 or 1):1 is enabled, 0 otherwise.
 * If enabled, the video decoder doesn't hold input and output data more than required by
 * the codec standards. This is an optional key that applies only to video decoder.
 * It is used in configure.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_ENABLE_LOW_LATENCY __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for describing the maximum quantization parameter allowed for video encoder, value type is int32_t.
 * It is used in configure/setparameter or takes effect immediately with the frame.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_ENCODER_QP_MAX __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for describing the minimum quantization parameter allowed for video encoder, value type is int32_t.
 * It is used in configure/setparameter or takes effect immediately with the frame.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_ENCODER_QP_MIN __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for describing the video frame averge quantization parameter, value type is int32_t.
 * This is a part of a video encoder statistics export feature. This value is emitted from video encoder for a video
 * frame.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_ENCODER_QP_AVERAGE __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for describing video frame mean squared error, value type is double.
 * This is a part of a video encoder statistics export feature. This value is emitted from video encoder for a video
 * frame.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_ENCODER_MSE __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for decoding timestamp of the buffer in microseconds, value type is int64_t.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_DECODING_TIMESTAMP __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for duration of the buffer in microseconds, value type is int64_t.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_BUFFER_DURATION __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for sample aspect ratio, value type is double.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_SAR __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for start time of the first frame in the media file in microseconds, value type is int64_t.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_START_TIME __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for start time of track in microseconds, value type is int64_t.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_TRACK_START_TIME __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for setting the output color space of video decoder. The value type is int32_t.
 * The supported value is {@link OH_COLORSPACE_BT709_LIMIT}, see {@link OH_NativeBuffer_ColorSpace}. It is used in
 * {@link OH_VideoDecoder_Configure}. If the color space conversion capability is supported and this key is configured,
 * the video decoder will automatically transcode an HDR Vivid video to an SDR video with color space BT709.
 * If color space conversion capability is not supported, {@link OH_VideoDecoder_Configure} returns
 * {@link AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION}.
 * If the input video is not an HDR vivid video, an error {@link AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION} will
 * be reported by callback function {@link OH_AVCodecOnError}.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
extern const char *OH_MD_KEY_VIDEO_DECODER_OUTPUT_COLOR_SPACE __attribute__((__availability__(ohos, introduced=12.0.0)));
/**
 * @brief Key for describing if enable VRR or not, value type is int32_t (0 or 1): 1 is enabled, 0 otherwise.
 * This is an optional key that applies only to video decoder. It is used in configure.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 15
 */
extern const char *OH_MD_KEY_VIDEO_DECODER_OUTPUT_ENABLE_VRR __attribute__((__availability__(ohos, introduced=15.0.0)));
/**
 * @brief Key for creation timestamp of a media file, value type is string.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 14
 */
extern const char *OH_MD_KEY_CREATION_TIME __attribute__((__availability__(ohos, introduced=14.0.0)));
/**
 * @brief Key applies only when configuring a video encoder in surface mode, value type is int32_t.
 * If no new frame became available since the last frame submitted to the encoder,
 * it will submit the previous frame repeatedly in milliseconds. It is used in configure.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 18
 */
extern const char *OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER
__attribute__((__availability__(ohos, introduced=18.0.0)));
/**
 * @brief Key for describing the maximum count that the frame previously submitted to the encoder will be
 * repeated, in case no new frame has been available since, value type is int32_t. This key takes effect only when
 * {@link VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER} is valid. It is used in configure.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 18
 */
extern const char *OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_MAX_COUNT
__attribute__((__availability__(ohos, introduced=18.0.0)));
/**
 * @brief Key to enable B-frame encoding, value type is int32_t (0 or 1): 1 is enabled, 0 otherwise.
 *
 * This is an optional key that applies only to video encoder, default is 0.\n
 * If enabled, the video encoder will use B-frame, the decode order will be different from the display order.\n
 * For unsupported platforms, Configuring this key will have no effect.\n
 * Platform capability can be checked via {@link OH_AVCapability_IsFeatureSupported} with
 * {@link OH_AVCapabilityFeature::VIDEO_ENCODER_B_FRAME}.\n
 * It's only used in configuration phase.\n
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 20
*/
extern const char *OH_MD_KEY_VIDEO_ENCODER_ENABLE_B_FRAME __attribute__((__availability__(ohos, introduced=20.0.0)));
 
/**
 * @brief Key for describing the maximum B-frame count of video encoder, value type is int32_t.
 *
 * Note: This key is only for querying the capability of the codec currently.
 * Usage specifications:
 * 1. Check feature support via {@link OH_AVCapability_IsFeatureSupported} with
 * {@link OH_AVCapabilityFeature::VIDEO_ENCODER_B_FRAME}.\n
 * 2. Obtain OH_AVFormat handle via {@link OH_AVCapability_GetFeatureProperties} with
 * {@link OH_AVCapabilityFeature::VIDEO_ENCODER_B_FRAME}.\n
 * 3. Get maximum B-frame count via {@link OH_AVFormat_GetIntValue} with this key.\n
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 20
*/
extern const char *OH_MD_KEY_VIDEO_ENCODER_MAX_B_FRAMES __attribute__((__availability__(ohos, introduced=20.0.0)));
/**
 * @brief Key to set the region of interest(ROI) as QpOffset-Rects, value type is string in the format
 * "Top1,Left1-Bottom1,Right1=Offset1;Top2,Left2-Bottom2,Right2=Offset2;". Each "Top,Left-Bottom,Right=Offset"
 * represents the coordinate information and quantization parameter of one ROI. Each "=Offset" in the string
 * can be omitted, like "Top1,Left1-Bottom1,Right1;Top2,Left2-Bottom2,Right2=Offset2;", the encoder
 * will use the default quantization parameter to perform the ROI encoding on the first ROI and
 * use Offset2 on the second ROI.
 *
 * This is an optional key that applies only to video encoder.
 * It is used in running process and is set with each frame.
 * In surface mode, it is used in {@link OH_VideoEncoder_OnNeedInputParameter}.
 * In buffer mode, it is configured via {@link OH_AVBuffer_SetParameter}.
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 20
 */
extern const char *OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS __attribute__((__availability__(ohos, introduced=20.0.0)));
/**
 *
 * @brief Key for front moov of the mp4 and m4a media file, value type is int32_t (0 or 1):1 is enabled, 0 otherwise.
 * This key may affect the performance of the stop function of the mp4 and m4a muxer.
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 20
 */
extern const char *OH_MD_KEY_ENABLE_MOOV_FRONT __attribute__((__availability__(ohos, introduced=20.0.0)));
/**
 * @brief Key for the desired encoding quality, value type is int32_t, this key is only
 * supported for encoders that are configured in Stable Quality RateControl, the higher
 * values generally result in more efficient(smaller-sized) encoding.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 20
 */
extern const char *OH_MD_KEY_SQR_FACTOR __attribute__((__availability__(ohos, introduced=20.0.0)));
/**
 * @brief Key for maximum bitrate, value type is int64_t.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 20
 */
extern const char *OH_MD_KEY_MAX_BITRATE __attribute__((__availability__(ohos, introduced=20.0.0)));
/**
 * @brief Key for describing the reference relationship between tracks, value type is int32_t*.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 20
*/
extern const char *OH_MD_KEY_REFERENCE_TRACK_IDS __attribute__((__availability__(ohos, introduced=20.0.0)));
/**
 * @brief Key for describing the track reference type, value type is string.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 20
*/
extern const char *OH_MD_KEY_TRACK_REFERENCE_TYPE __attribute__((__availability__(ohos, introduced=20.0.0)));
/**
 * @brief Key for describing the track description, value type is string.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 20
*/
extern const char *OH_MD_KEY_TRACK_DESCRIPTION __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Key to enable Bitrate Control Based on Presentation Time Stamp(PTS),
 * value type is int32_t (0 or 1):1 is enabled, 0 otherwise.
 *
 * This is an optional key that applies only to video encoder, default is 0.
 * If enabled, the PTS information must be carried in each video frame and sent to the encoder.
 * It is used in configure.
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 20
*/
extern const char *OH_MD_KEY_VIDEO_ENCODER_ENABLE_PTS_BASED_RATECONTROL
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Key to enable synchronous mode, value type is (0 or 1): 1 is enabled, 0 otherwise.
 *
 * This is an optional key, default is 0.\n
 * When enabled:
 *       - Callbacks should NOT be set for codecs
 *       - Buffer query APIs must be used instead
 *       - Only used in configuration phase
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 20
 */
extern const char *OH_MD_KEY_ENABLE_SYNC_MODE __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Key for specifying whether to output a blank frame during video decoder shutdown,
 * value type is int32_t (0 or 1): 1 is enabled, 0 otherwise.
 *
 * This is an optional key, only used when configuring a video decoder in surface mode.\n
 * By default, this feature is disabled (0).\n
 * When enabled, the video decoder will output a blank frame (typically black)
 * when stop or release to ensure a smooth transition to no-signal state on display devices.\n
 * This prevents display retention or flickering caused by abrupt termination.\n
 *
 * @since 20
 */
extern const char *OH_MD_KEY_VIDEO_DECODER_BLANK_FRAME_ON_SHUTDOWN
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Key for querying native buffer pixel formats for video codec operations, value type is int32_t.
 * The value represents pixel formats defined in {@link OH_NativeBuffer_Format}.
 *
 * This key serves two primary purposes:
 * 1. Runtime decoder output: Get current output format via {@link OH_VideoDecoder_GetOutputDescription}
 * or {@link OH_AVCodecOnStreamChanged} events.
 * 2. Runtime encoder input: Get current input format via {@link OH_VideoEncoder_GetInputDescription}.
 *
 * @since 22
 */
extern const char *OH_MD_KEY_VIDEO_NATIVE_BUFFER_FORMAT __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Key for skip samples of audio frame. value type is a uint8_t pointer.
 *
 * @since 23
 */
extern const char *OH_MD_KEY_BUFFER_SKIP_SAMPLES_INFO __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Key to enable {@link OH_MD_KEY_BUFFER_SKIP_SAMPLES_INFO} in audio decoder,
 * value type is int32_t (0 or 1): 1 is enabled, 0 is disabled.
 *
 * This is an optional key, default is 0.
 *
 * @since 24
 */
extern const char *OH_MD_KEY_ENABLE_BUFFER_SKIP_SAMPLES __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Key for latitude, value type is float, The range is [-90.0, 90.0].
 * Represents the latitude of the geographic location.
 *
 * @since 24
 */
extern const char *OH_MD_KEY_LATITUDE __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Key for longitude, value type is float, The range is [-180.0, 180.0].
 * Represents the longitude of the geographic location.
 *
 * @since 24
 */
extern const char *OH_MD_KEY_LONGITUDE __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Key for altitude, value type is float.
 * This is an optional key. Represents the altitude of the geographic location.
 *
 * @since 24
 */
extern const char *OH_MD_KEY_ALTITUDE __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Media type.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
typedef enum OH_MediaType {
    /* track is audio. */
    MEDIA_TYPE_AUD = 0,
    /* track is video. */
    MEDIA_TYPE_VID = 1,
    /** track is subtitle.
     * @since 12
     */
    MEDIA_TYPE_SUBTITLE = 2,
    /** track is timed meta.
     * @since 20
     */
    MEDIA_TYPE_TIMED_METADATA = 5,
    /** track is auxiliary.
     * @since 20
     */
    MEDIA_TYPE_AUXILIARY = 6,
} OH_MediaType;

/**
 * @brief AAC Profile
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
typedef enum OH_AACProfile {
    AAC_PROFILE_LC = 0,
    /**
     * High-Efficiency AAC profile, contain the audio object types: AAC LC, SBR
     * @since 14
     */
    AAC_PROFILE_HE = 3,
    /**
     * High-Efficiency AAC v2 profile, contain the audio object types: AAC LC, SBR, PS
     * @since 14
     */
    AAC_PROFILE_HE_V2 = 4,
} OH_AACProfile;

/**
 * @brief AVC Profile
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 9
 */
typedef enum OH_AVCProfile {
    AVC_PROFILE_BASELINE = 0,
    AVC_PROFILE_HIGH = 4,
    AVC_PROFILE_MAIN = 8,
} OH_AVCProfile;

/**
 * @brief HEVC Profile
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
typedef enum OH_HEVCProfile {
    HEVC_PROFILE_MAIN = 0,
    HEVC_PROFILE_MAIN_10 = 1,
    HEVC_PROFILE_MAIN_STILL = 2,
    /**
     * @deprecated since 14
     */
    HEVC_PROFILE_MAIN_10_HDR10 = 3,
    /**
     * @deprecated since 14
     */
    HEVC_PROFILE_MAIN_10_HDR10_PLUS = 4,
} OH_HEVCProfile;

/**
 * @brief Profile: A specified subset of the syntax of VVC.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 15
 */
typedef enum OH_VVCProfile {
    /** Main 10 profile */
    VVC_PROFILE_MAIN_10 = 1,
    /** Main 12 profile */
    VVC_PROFILE_MAIN_12 = 2,
    /** Main 12 Intra profile */
    VVC_PROFILE_MAIN_12_INTRA = 10,
    /** Multilayer Main 10 profile */
    VVC_PROFILE_MULTI_MAIN_10 = 17,
    /** Main 10 4:4:4 profile */
    VVC_PROFILE_MAIN_10_444 = 33,
    /** Main 12 4:4:4 profile */
    VVC_PROFILE_MAIN_12_444 = 34,
    /** Main 16 4:4:4 profile */
    VVC_PROFILE_MAIN_16_444 = 36,
    /** Main 12 4:4:4 Intra profile */
    VVC_PROFILE_MAIN_12_444_INTRA = 42,
    /** Main 16 4:4:4 Intra profile */
    VVC_PROFILE_MAIN_16_444_INTRA = 44,
    /** Multilayer Main 10 4:4:4 profile */
    VVC_PROFILE_MULTI_MAIN_10_444 = 49,
    /** Main 10 Still Picture profile */
    VVC_PROFILE_MAIN_10_STILL = 65,
    /** Main 12 Still Picture profile */
    VVC_PROFILE_MAIN_12_STILL = 66,
    /** Main 10 4:4:4 Still Picture profile */
    VVC_PROFILE_MAIN_10_444_STILL = 97,
    /** Main 12 4:4:4 Still Picture profile */
    VVC_PROFILE_MAIN_12_444_STILL = 98,
    /** Main 16 4:4:4 Still Picture profile */
    VVC_PROFILE_MAIN_16_444_STILL = 100,
} OH_VVCProfile;

/**
 * @brief MPEG2 Profile
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 17
 */
typedef enum OH_MPEG2Profile {
    /** Simple profile */
    MPEG2_PROFILE_SIMPLE = 0,
    /** Main profile */
    MPEG2_PROFILE_MAIN = 1,
    /** SNR scalable profile */
    MPEG2_PROFILE_SNR_SCALABLE = 2,
    /** Spatially scalable profile */
    MPEG2_PROFILE_SPATIALLY_SCALABLE = 3,
    /** High profile */
    MPEG2_PROFILE_HIGH = 4,
    /** 4:2:2 profile */
    MPEG2_PROFILE_422 = 5,
} OH_MPEG2Profile;

/**
 * @brief MPEG4 Profile
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 17
 */
typedef enum OH_MPEG4Profile {
    /** Simple profile */
    MPEG4_PROFILE_SIMPLE = 0,
    /** Simple scalable profile */
    MPEG4_PROFILE_SIMPLE_SCALABLE = 1,
    /** Core profile */
    MPEG4_PROFILE_CORE = 2,
    /** Main profile */
    MPEG4_PROFILE_MAIN = 3,
    /** N-Bit profile */
    MPEG4_PROFILE_N_BIT = 4,
    /** Hybrid profile */
    MPEG4_PROFILE_HYBRID = 5,
    /** Basic animated texture profile */
    MPEG4_PROFILE_BASIC_ANIMATED_TEXTURE = 6,
    /** Scalable texture profile */
    MPEG4_PROFILE_SCALABLE_TEXTURE = 7,
    /** Simple FA profile */
    MPEG4_PROFILE_SIMPLE_FA = 8,
    /** Advanced real time simple profile */
    MPEG4_PROFILE_ADVANCED_REAL_TIME_SIMPLE = 9,
    /** Core scalable profile */
    MPEG4_PROFILE_CORE_SCALABLE = 10,
    /** Advanced coding efficiency profile */
    MPEG4_PROFILE_ADVANCED_CODING_EFFICIENCY = 11,
    /** Advanced core profile */
    MPEG4_PROFILE_ADVANCED_CORE = 12,
    /** Advanced scalable texture profile */
    MPEG4_PROFILE_ADVANCED_SCALABLE_TEXTURE = 13,
    /** Advanced simple profile */
    MPEG4_PROFILE_ADVANCED_SIMPLE = 17,
} OH_MPEG4Profile;

/**
 * @brief H263 Profile
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 17
 */
typedef enum OH_H263Profile {
    /** Baseline profile */
    H263_PROFILE_BASELINE = 0,
    /** Version 1 backward compatibility profile */
    H263_PROFILE_VERSION_1_BACKWARD_COMPATIBILITY = 2,
} OH_H263Profile;

/**
 * @brief VC-1 Profile
 *
 * @since 22
 */
typedef enum OH_VC1Profile {
    /** Simple profile */
    VC1_PROFILE_SIMPLE = 0,
    /** Main profile */
    VC1_PROFILE_MAIN = 1,
    /** Advanced profile */
    VC1_PROFILE_ADVANCED = 2,
} OH_VC1Profile;

/**
 * @brief AV1 Profile
 *
 * @since 23
 */
typedef enum OH_AV1Profile {
    /** Main profile */
    AV1_PROFILE_MAIN = 0,
    /** High profile */
    AV1_PROFILE_HIGH = 1,
    /** Professional profile */
    AV1_PROFILE_PROFESSIONAL = 2,
} OH_AV1Profile;

/**
* @brief VP9 Profile
*
* @since 23
*/
typedef enum OH_VP9Profile {
    /** 0 profile */
    VP9_PROFILE_0 = 0,
    /** 1 profile */
    VP9_PROFILE_1 = 1,
    /** 2 profile */
    VP9_PROFILE_2 = 2,
    /** 3 profile */
    VP9_PROFILE_3 = 3,
} OH_VP9Profile;

/**
* @brief WVC1 Profile.
*
* @since 23
*/
typedef enum OH_WVC1Profile {
    /** Advanced profile */
    WVC1_PROFILE_ADVANCED = 0,
 } OH_WVC1Profile;

/**
 * @brief WMV3 Profile
 *
 * @since 22
 */
typedef enum OH_WMV3Profile {
    /** Simple profile */
    WMV3_PROFILE_SIMPLE = 0,
    /** Main profile */
    WMV3_PROFILE_MAIN = 1,
} OH_WMV3Profile;

/**
 * @brief Enumerates the muxer output file format
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
typedef enum OH_AVOutputFormat {
    AV_OUTPUT_FORMAT_DEFAULT = 0,
    AV_OUTPUT_FORMAT_MPEG_4 = 2,
    AV_OUTPUT_FORMAT_M4A = 6,
    /**
     * The muxer output amr file format.
     * @since 12
     */
    AV_OUTPUT_FORMAT_AMR = 8,
    /**
     * The muxer output mp3 file format.
     * @since 12
     */
    AV_OUTPUT_FORMAT_MP3 = 9,
    /**
     * The muxer output wav file format.
     * @since 12
     */
    AV_OUTPUT_FORMAT_WAV = 10,
    /**
     * The muxer output aac file format.
     * @since 18
     */
    AV_OUTPUT_FORMAT_AAC = 11,
    /**
     * The muxer output flac file format.
     * @since 20
     */
    AV_OUTPUT_FORMAT_FLAC = 12,
    /**
     * The muxer output ogg file format.
     * @since 23
     */
    AV_OUTPUT_FORMAT_OGG = 13,
} OH_AVOutputFormat;

/**
 * @brief Seek Mode
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
typedef enum OH_AVSeekMode {
    /* seek to sync sample after the time */
    SEEK_MODE_NEXT_SYNC = 0,
    /* seek to sync sample before the time */
    SEEK_MODE_PREVIOUS_SYNC,
    /* seek to sync sample closest to time */
    SEEK_MODE_CLOSEST_SYNC,
} OH_AVSeekMode;

/**
 * @brief Scaling Mode
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @deprecated since 14
 * @useinstead OHScalingModeV2
 * @since 10
 */
typedef enum OH_ScalingMode {
    /**
     * @deprecated since 14
     * @useinstead OH_SCALING_MODE_SCALE_TO_WINDOW_V2
     */
    SCALING_MODE_SCALE_TO_WINDOW = 1,
    /**
     * @deprecated since 14
     * @useinstead OH_SCALING_MODE_SCALE_CROP_V2
     */
    SCALING_MODE_SCALE_CROP = 2,
} OH_ScalingMode;

/**
 * @brief enum Audio Bits Per Coded Sample
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
typedef enum OH_BitsPerSample {
    SAMPLE_U8 = 0,
    SAMPLE_S16LE = 1,
    SAMPLE_S24LE = 2,
    SAMPLE_S32LE = 3,
    SAMPLE_F32LE = 4,
    SAMPLE_U8P = 5,
    SAMPLE_S16P = 6,
    SAMPLE_S24P = 7,
    SAMPLE_S32P = 8,
    SAMPLE_F32P = 9,
    INVALID_WIDTH = -1
} OH_BitsPerSample;

/**
 * @brief Color Primary
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
typedef enum OH_ColorPrimary {
    COLOR_PRIMARY_BT709 = 1,
    COLOR_PRIMARY_UNSPECIFIED = 2,
    COLOR_PRIMARY_BT470_M = 4,
    COLOR_PRIMARY_BT601_625 = 5,
    COLOR_PRIMARY_BT601_525 = 6,
    COLOR_PRIMARY_SMPTE_ST240 = 7,
    COLOR_PRIMARY_GENERIC_FILM = 8,
    COLOR_PRIMARY_BT2020 = 9,
    COLOR_PRIMARY_SMPTE_ST428 = 10,
    COLOR_PRIMARY_P3DCI = 11,
    COLOR_PRIMARY_P3D65 = 12,
} OH_ColorPrimary;

/**
 * @brief Transfer Characteristic
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
typedef enum OH_TransferCharacteristic {
    TRANSFER_CHARACTERISTIC_BT709 = 1,
    TRANSFER_CHARACTERISTIC_UNSPECIFIED = 2,
    TRANSFER_CHARACTERISTIC_GAMMA_2_2 = 4,
    TRANSFER_CHARACTERISTIC_GAMMA_2_8 = 5,
    TRANSFER_CHARACTERISTIC_BT601 = 6,
    TRANSFER_CHARACTERISTIC_SMPTE_ST240 = 7,
    TRANSFER_CHARACTERISTIC_LINEAR = 8,
    TRANSFER_CHARACTERISTIC_LOG = 9,
    TRANSFER_CHARACTERISTIC_LOG_SQRT = 10,
    TRANSFER_CHARACTERISTIC_IEC_61966_2_4 = 11,
    TRANSFER_CHARACTERISTIC_BT1361 = 12,
    TRANSFER_CHARACTERISTIC_IEC_61966_2_1 = 13,
    TRANSFER_CHARACTERISTIC_BT2020_10BIT = 14,
    TRANSFER_CHARACTERISTIC_BT2020_12BIT = 15,
    TRANSFER_CHARACTERISTIC_PQ = 16,
    TRANSFER_CHARACTERISTIC_SMPTE_ST428 = 17,
    TRANSFER_CHARACTERISTIC_HLG = 18,
} OH_TransferCharacteristic;

/**
 * @brief Matrix Coefficient
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
typedef enum OH_MatrixCoefficient {
    MATRIX_COEFFICIENT_IDENTITY = 0,
    MATRIX_COEFFICIENT_BT709 = 1,
    MATRIX_COEFFICIENT_UNSPECIFIED = 2,
    MATRIX_COEFFICIENT_FCC = 4,
    MATRIX_COEFFICIENT_BT601_625 = 5,
    MATRIX_COEFFICIENT_BT601_525 = 6,
    MATRIX_COEFFICIENT_SMPTE_ST240 = 7,
    MATRIX_COEFFICIENT_YCGCO = 8,
    MATRIX_COEFFICIENT_BT2020_NCL = 9,
    MATRIX_COEFFICIENT_BT2020_CL = 10,
    MATRIX_COEFFICIENT_SMPTE_ST2085 = 11,
    MATRIX_COEFFICIENT_CHROMATICITY_NCL = 12,
    MATRIX_COEFFICIENT_CHROMATICITY_CL = 13,
    MATRIX_COEFFICIENT_ICTCP = 14,
} OH_MatrixCoefficient;

/**
 * @brief AVC Level.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
typedef enum OH_AVCLevel {
    AVC_LEVEL_1 = 0,
    AVC_LEVEL_1b = 1,
    AVC_LEVEL_11 = 2,
    AVC_LEVEL_12 = 3,
    AVC_LEVEL_13 = 4,
    AVC_LEVEL_2 = 5,
    AVC_LEVEL_21 = 6,
    AVC_LEVEL_22 = 7,
    AVC_LEVEL_3 = 8,
    AVC_LEVEL_31 = 9,
    AVC_LEVEL_32 = 10,
    AVC_LEVEL_4 = 11,
    AVC_LEVEL_41 = 12,
    AVC_LEVEL_42 = 13,
    AVC_LEVEL_5 = 14,
    AVC_LEVEL_51 = 15,
    AVC_LEVEL_52 = 16,
    AVC_LEVEL_6 = 17,
    AVC_LEVEL_61 = 18,
    AVC_LEVEL_62 = 19,
} OH_AVCLevel;

/**
 * @brief HEVC Level.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
typedef enum OH_HEVCLevel {
    HEVC_LEVEL_1 = 0,
    HEVC_LEVEL_2 = 1,
    HEVC_LEVEL_21 = 2,
    HEVC_LEVEL_3 = 3,
    HEVC_LEVEL_31 = 4,
    HEVC_LEVEL_4 = 5,
    HEVC_LEVEL_41 = 6,
    HEVC_LEVEL_5 = 7,
    HEVC_LEVEL_51 = 8,
    HEVC_LEVEL_52 = 9,
    HEVC_LEVEL_6 = 10,
    HEVC_LEVEL_61 = 11,
    HEVC_LEVEL_62 = 12,
} OH_HEVCLevel;

/**
 * @brief VVC Level: A defined set of constraints on the values that may be taken by the syntax elements and variables
 * of VVC, or the value of a transform coefficient prior to scaling.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 15
 */
typedef enum OH_VVCLevel {
    /** VVC level 1.0 */
    VVC_LEVEL_1 = 16,
    /** VVC level 2.0 */
    VVC_LEVEL_2 = 32,
    /** VVC level 2.1 */
    VVC_LEVEL_21 = 35,
    /** VVC level 3.0 */
    VVC_LEVEL_3 = 48,
    /** VVC level 3.1 */
    VVC_LEVEL_31 = 51,
    /** VVC level 4.0 */
    VVC_LEVEL_4 = 64,
    /** VVC level 4.1 */
    VVC_LEVEL_41 = 67,
    /** VVC level 5.0 */
    VVC_LEVEL_5 = 80,
    /** VVC level 5.1 */
    VVC_LEVEL_51 = 83,
    /** VVC level 5.2 */
    VVC_LEVEL_52 = 86,
    /** VVC level 6.0 */
    VVC_LEVEL_6 = 96,
    /** VVC level 6.1 */
    VVC_LEVEL_61 = 99,
    /** VVC level 6.2 */
    VVC_LEVEL_62 = 102,
    /** VVC level 6.3 */
    VVC_LEVEL_63 = 105,
    /** VVC level 15.5 */
    VVC_LEVEL_155 = 255,
} OH_VVCLevel;

/**
 * @brief MPEG2 Level.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 17
 */
typedef enum OH_MPEG2Level {
    /** Low level */
    MPEG2_LEVEL_LOW = 0,
    /** Main level */
    MPEG2_LEVEL_MAIN = 1,
    /** High 1440 level */
    MPEG2_LEVEL_HIGH_1440 = 2,
    /** High level */
    MPEG2_LEVEL_HIGH = 3,
} OH_MPEG2Level;

/**
 * @brief MPEG4 Level.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 17
 */
typedef enum OH_MPEG4Level {
    /** 0 level */
    MPEG4_LEVEL_0 = 0,
    /** 0B level */
    MPEG4_LEVEL_0B = 1,
    /** 1 level */
    MPEG4_LEVEL_1 = 2,
    /** 2 level */
    MPEG4_LEVEL_2 = 3,
    /** 3 level */
    MPEG4_LEVEL_3 = 4,
    /** 3B level */
    MPEG4_LEVEL_3B = 5,
    /** 4 level */
    MPEG4_LEVEL_4 = 6,
    /** 4A level */
    MPEG4_LEVEL_4A = 7,
    /** 5 level */
    MPEG4_LEVEL_5 = 8,
    /** 6 level */
    MPEG4_LEVEL_6 = 9,
} OH_MPEG4Level;

/**
 * @brief H263 Level.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 17
 */
typedef enum OH_H263Level {
    /** 10 level */
    H263_LEVEL_10 = 0,
    /** 20 level */
    H263_LEVEL_20 = 1,
    /** 30 level */
    H263_LEVEL_30 = 2,
    /** 40 level */
    H263_LEVEL_40 = 3,
    /** 45 level */
    H263_LEVEL_45 = 4,
    /** 50 level */
    H263_LEVEL_50 = 5,
    /** 60 level */
    H263_LEVEL_60 = 6,
    /** 70 level */
    H263_LEVEL_70 = 7,
} OH_H263Level;

/**
 * @brief VC-1 Level.
 *
 * @since 22
 */
typedef enum OH_VC1Level {
    /** L0 level */
    VC1_LEVEL_L0 = 0,
    /** L1 level */
    VC1_LEVEL_L1 = 1,
    /** L2 level */
    VC1_LEVEL_L2 = 2,
    /** L3 level */
    VC1_LEVEL_L3 = 3,
    /** L4 level */
    VC1_LEVEL_L4 = 4,
    /** LOW level */
    VC1_LEVEL_LOW = 5,
    /** MEDIUM level */
    VC1_LEVEL_MEDIUM = 6,
    /** HIGH level */
    VC1_LEVEL_HIGH = 7,
} OH_VC1Level;

/**
 * @brief AV1 Level.
 *
 * @since 23
 */
typedef enum OH_AV1Level {
    /** 2.0 level */
    AV1_LEVEL_20 = 0,
    /** 2.1 level */
    AV1_LEVEL_21 = 1,
    /** 2.2 level */
    AV1_LEVEL_22 = 2,
    /** 2.3 level */
    AV1_LEVEL_23 = 3,
    /** 3.0 level */
    AV1_LEVEL_30 = 4,
    /** 3.1 level */
    AV1_LEVEL_31 = 5,
    /** 3.2 level */
    AV1_LEVEL_32 = 6,
    /** 3.3 level */
    AV1_LEVEL_33 = 7,
    /** 4.0 level */
    AV1_LEVEL_40 = 8,
    /** 4.1 level */
    AV1_LEVEL_41 = 9,
    /** 4.2 level */
    AV1_LEVEL_42 = 10,
    /** 4.3 level */
    AV1_LEVEL_43 = 11,
    /** 5.0 level */
    AV1_LEVEL_50 = 12,
    /** 5.1 level */
    AV1_LEVEL_51 = 13,
    /** 5.2 level */
    AV1_LEVEL_52 = 14,
    /** 5.3 level */
    AV1_LEVEL_53 = 15,
    /** 6.0 level */
    AV1_LEVEL_60 = 16,
    /** 6.1 level */
    AV1_LEVEL_61 = 17,
    /** 6.2 level */
    AV1_LEVEL_62 = 18,
    /** 6.3 level */
    AV1_LEVEL_63 = 19,
    /** 7.0 level */
    AV1_LEVEL_70 = 20,
    /** 7.1 level */
    AV1_LEVEL_71 = 21,
    /** 7.2 level */
    AV1_LEVEL_72 = 22,
    /** 7.3 level */
    AV1_LEVEL_73 = 23,
} OH_AV1Level;

/**
 * @brief VP9 Level.
 *
 * @since 23
 */
typedef enum OH_VP9Level {
    /** 1 level */
    VP9_LEVEL_1 = 0,
    /** 1.1 level */
    VP9_LEVEL_11 = 1,
    /** 2 level */
    VP9_LEVEL_2 = 2,
    /** 2.1 level */
    VP9_LEVEL_21 = 3,
    /** 3 level */
    VP9_LEVEL_3 = 4,
    /** 3.1 level */
    VP9_LEVEL_31 = 5,
    /** 4 level */
    VP9_LEVEL_4 = 6,
    /** 4.1 level */
    VP9_LEVEL_41 = 7,
    /** 5 level */
    VP9_LEVEL_5 = 8,
    /** 5.1 level */
    VP9_LEVEL_51 = 9,
    /** 5.2 level */
    VP9_LEVEL_52 = 10,
    /** 6 level */
    VP9_LEVEL_6 = 11,
    /** 6.1 level */
    VP9_LEVEL_61 = 12,
    /** 6.2 level */
    VP9_LEVEL_62 = 13,
} OH_VP9Level;

/**
 * @brief WVC1 level.
 *
 * @since 23
 */
typedef enum OH_WVC1Level {
    /** L0 level */
    WVC1_LEVEL_L0 = 0,
    /** L1 level */
    WVC1_LEVEL_L1 = 1,
    /** L2 level */
    WVC1_LEVEL_L2 = 2,
    /** L3 level */
    WVC1_LEVEL_L3 = 3,
    /** L4 level */
    WVC1_LEVEL_L4 = 4,
} OH_WVC1Level;

/**
 * @brief WMV3 Level.
 *
 * @since 22
 */
typedef enum OH_WMV3Level {
    /** LOW level */
    WMV3_LEVEL_LOW = 0,
    /** MEDIUM level */
    WMV3_LEVEL_MEDIUM = 1,
    /** HIGH level */
    WMV3_LEVEL_HIGH = 2,
} OH_WMV3Level;

/**
 * @brief The reference mode in temporal group of picture.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 12
 */
typedef enum OH_TemporalGopReferenceMode {
    /** Refer to latest short-term reference frame. */
    ADJACENT_REFERENCE = 0,
    /** Refer to latest long-term reference frame. */
    JUMP_REFERENCE = 1,
    /** Uniformly scaled reference structure, which has even distribution of video frames after drop the highest
     *  enhance layer. The temporal group of pictures must be power of 2. */
    UNIFORMLY_SCALED_REFERENCE = 2,
} OH_TemporalGopReferenceMode;

/**
 * @brief The bitrate mode of encoder.
 *
 * Change the location of the header file, since 14.
 *
 * @syscap SystemCapability.Multimedia.Media.CodecBase
 * @since 10
 */
typedef enum OH_BitrateMode {
    /** Constant Bit rate mode. */
    BITRATE_MODE_CBR = 0,
    /** Variable Bit rate mode. */
    BITRATE_MODE_VBR = 1,
    /** Constant Quality mode. */
    BITRATE_MODE_CQ = 2,
    /** Stable Quality RateControl.
     * @since 20
     */
    BITRATE_MODE_SQR = 3
} OH_BitrateMode;

#ifdef __cplusplus
}
#endif

#endif // NATIVE_AVCODEC_BASE_H
/** @} */
