/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
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
 * @addtogroup OH_Scan
 * @{
 *
 * @brief Provides the definition of the C interface for the scan module.
 *
 * @syscap SystemCapability.Print.PrintFramework
 *
 * @since 12
 * @version 1.0
 */

/**
 * @file ohscan.h
 *
 * @brief Declares the APIs to discover and connect scanners, scan images from the scanner,
 *        obtain the page scanning progress and set scanned image parameters, and so on.
 *
 * @library libohscan.so
 * @kit BasicServicesKit
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 * @version 1.0
 */

#ifndef OH_SCAN_H
#define OH_SCAN_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines error codes.
 *
 * @since 12
 * @version 1.0
 */
typedef enum {
    /** @error The operation is successful. */
    SCAN_ERROR_NONE = 0,
    /** @error Permission verification failed. */
    SCAN_ERROR_NO_PERMISSION = 201,
    /** @error The parameter is invalid. For example, the pointer is null or the character string is null. */
    SCAN_ERROR_INVALID_PARAMETER = 401,
    /** @error General internal error. */
    SCAN_ERROR_GENERIC_FAILURE = 24300101,
    /** @error RPC communication error. */
    SCAN_ERROR_RPC_FAILURE = 24300102,
    /** @error Server error. */
    SCAN_ERROR_SERVER_FAILURE = 24300103,
    /** @error Operation is not supported. **/
    SCAN_ERROR_UNSUPPORTED = 24300104,
    /** @error Operation was cancelled. **/
    SCAN_ERROR_CANCELED = 24300105,
    /** @error Device is busy, try again later. **/
    SCAN_ERROR_DEVICE_BUSY = 24300106,
    /** @error Data is invalid (includes no dev at open). **/
    SCAN_ERROR_INVALID = 24300107,
    /** @error Document feeder jammed. **/
    SCAN_ERROR_JAMMED = 24300108,
    /** @error Document feeder out of documents. **/
    SCAN_ERROR_NO_DOCS = 24300109,
    /** @error Scanner cover is open. **/
    SCAN_ERROR_COVER_OPEN = 24300110,
    /** @error Error during device I/O. **/
    SCAN_ERROR_IO_ERROR = 24300111,
    /** @error Out of memory. **/
    SCAN_ERROR_NO_MEMORY = 24300112,
} Scan_ErrorCode;

/**
 * @brief Indicates scanner device information.
 *
 * @since 12
 */
typedef struct {
    /** Scanner id. */
    const char* scannerId;
    /** Scanner manufacturer. */
    const char* manufacturer;
    /** Scanner model. */
    const char* model;
    /** Scanner discoverMode. */
    const char* discoverMode;
    /** Scanner serialNumber. */
    const char* serialNumber;
} Scan_ScannerDevice;

/**
 * @brief Indicates the progress of scanning a picture by the scanner.
 *
 * @since 12
 */
typedef struct {
    /** Picture progress from 0 to 100. */
    int32_t progress;
    /** scanner file handle. */
    int32_t fd;
    /** Indicates whether the image is the last scanned image. */
    bool isFinal;
} Scan_PictureScanProgress;

/**
 * @brief Indicates all parameter options for one scanner.
 *
 * @since 12
 */
typedef struct {
    /** Title of an option. */
    char** titles;
    /** Description of an option. */
    char** descriptions;
    /** The range that an option can be set to. */
    char** ranges;
    /** Number of parameter options that can be set. */
    int32_t optionCount;
} Scan_ScannerOptions;

/**
 * @brief Scanner devices discovery callback, register by {@link OH_Scan_StartScannerDiscovery}.
 * The memory to which the pointer points will be released when the callback function ends.
 *
 * @param devices List of all discovered scanner devices.
 * @param deviceCount Number of Scanners Found.
 * @since 12
 */
typedef void (*Scan_ScannerDiscoveryCallback)(Scan_ScannerDevice** devices, int32_t deviceCount);

/**
 * @brief This API checks and pulls up the scan service, initializes the scan client,
 *        and establishes a connection to the scan service.
 *
 * @permission {@code ohos.permission.PRINT}
 * @return {@link Scan_ERROR_NONE} Indicates the scanning service is successfully started.
 *         {@link SCAN_ERROR_NO_PERMISSION} Indicates have no permission to use this interface.
 *         {@link SCAN_ERROR_RPC_FAILURE} Indicates an RPC communication error.
 *         {@link SCAN_ERROR_SERVER_FAILURE} Indicates An error occurs in the scan process.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Scan_Init();

/**
 * @brief This API starts discovering scanners, Register a callback to handle discovered scanner devices.
 *
 * @permission {@code ohos.permission.PRINT}
 * @param callback The {@link Scan_ScannerDiscoveryCallback} of scanner discovery event.
 * @return {@link Scan_ERROR_NONE} Indicates successful start of scanner search.
 *         {@link SCAN_ERROR_NO_PERMISSION} Indicates have no permission to use this interface.
 *         {@link SCAN_ERROR_RPC_FAILURE} Indicates an RPC communication error.
 *         {@link SCAN_ERROR_SERVER_FAILURE} Indicates An error occurs in the scan process.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Scan_StartScannerDiscovery(Scan_ScannerDiscoveryCallback callback);

/**
 * @brief This API connects to scanner devices.
 *
 * @permission {@code ohos.permission.PRINT}
 * @param scannerId The id used to connect to the scanner.
 * @return {@link Scan_ERROR_NONE} Indicates that the scanner was successfully connected.
 *         {@link SCAN_ERROR_NO_PERMISSION} Indicates have no permission to use this interface.
 *         {@link SCAN_ERROR_RPC_FAILURE} Indicates an RPC communication error.
 *         {@link SCAN_ERROR_SERVER_FAILURE} Indicates An error occurs in the scan process.
 *         {@link SCAN_ERROR_DEVICE_BUSY} Indicates that the scanner is busy.
 *         {@link SCAN_ERROR_INVALID_PARAMETER} Indicates that the input parameter is invalid.
 *         {@link SCAN_ERROR_IO_ERROR} Indicates an error occured while communicating with the device.
 *         {@link SCAN_ERROR_NO_MEM} Indicates an insufficent amount of memory is available.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Scan_OpenScanner(const char* scannerId);

/**
 * @brief This API is used to close the connected scanner device.
 *
 * @permission {@code ohos.permission.PRINT}
 * @param scannerId The id to disconnect the scanner.
 * @return {@link Scan_ERROR_NONE} Indicates that the scanner connection was successfully closed.
 *         {@link SCAN_ERROR_NO_PERMISSION} Indicates have no permission to use this interface.
 *         {@link SCAN_ERROR_RPC_FAILURE} Indicates an RPC communication error.
 *         {@link SCAN_ERROR_SERVER_FAILURE} Indicates An error occurs in the scan process.
 *         {@link SCAN_ERROR_INVALID_PARAMETER} Indicates that the input parameter is invalid.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Scan_CloseScanner(const char* scannerId);

/**
 * @brief This API can be used to get a list of options that can be set by the scanner.
 * The returned struct pointer points to memory that is automatically freed when {@link OH_Scan_Exit},
 * and only one copy will be stored in memory for each model.
 *
 * @permission {@code ohos.permission.PRINT}
 * @param scannerId The id used to obtain the scanner parameters.
 * @param errorCode The errorCode returns {@link Scan_ErrorCode#Scan_ERROR_NONE} if the execution is successful,
 *         otherwise returns a specific error code, refer to {@link Print_ErrorCode}.
 * @return {@link Scan_ERROR_NONE} Indicates that the scanner parameter options are successfully obtained.
 *         {@link SCAN_ERROR_NO_PERMISSION} Indicates have no permission to use this interface.
 *         {@link SCAN_ERROR_RPC_FAILURE} Indicates an RPC communication error.
 *         {@link SCAN_ERROR_SERVER_FAILURE} Indicates An error occurs in the scan process.
 *         {@link SCAN_ERROR_INVALID_PARAMETER} Indicates invalid parameter.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
Scan_ScannerOptions* OH_Scan_GetScannerParameter(const char* scannerId, int32_t* errorCode);

/**
 * @brief This API can be used to set one of the scanner's option parameters.
 * The option and value passed in are obtained from {@link OH_Scan_GetScannerParameter}.
 *
 * @permission {@code ohos.permission.PRINT}
 * @param scannerId This id is used to set the options for a specific scanner.
 * @param option Options number to be set.The value ranges from 0 to {@link optionCount} - 1,
 * be obtained from the {@link Scan_ScannerOptions}.
 * @param value Option value to be set, valid value is obtained from the {@link ranges},
 * be obtained from the {@link Scan_ScannerOptions}.
 * @return {@link Scan_ERROR_NONE} Indicates that the scanner parameters were successfully set.
 *         {@link SCAN_ERROR_NO_PERMISSION} Indicates have no permission to use this interface.
 *         {@link SCAN_ERROR_RPC_FAILURE} Indicates an RPC communication error.
 *         {@link SCAN_ERROR_SERVER_FAILURE} Indicates an error occurs in the scan process.
 *         {@link SCAN_ERROR_INVALID_PARAMETER} Indicates invalid parameter.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Scan_SetScannerParameter(const char* scannerId, const int32_t option, const char* value);

/**
 * @brief This API allows the scanner to start scanning.
 *
 * @permission {@code ohos.permission.PRINT}
 * @param scannerId This id is used to start the scan job for the specified scanner.
 * @param batchMode Whether to start the scanner in batch mode.
 * @return {@link Scan_ERROR_NONE} Indicates that the scanner has successfully canceled the scan job.
 *         {@link SCAN_ERROR_NO_PERMISSION} Indicates have no permission to use this interface.
 *         {@link SCAN_ERROR_RPC_FAILURE} Indicates an RPC communication error.
 *         {@link SCAN_ERROR_SERVER_FAILURE} Indicates An error occurs in the scan process.
 *         {@link SCAN_ERROR_JAMMED} Indicates the document feeder is jammed.
 *         {@link SCAN_ERROR_NO_DOCS} Indicates the document feeder is out of documents.
 *         {@link SCAN_ERROR_COVER_OPEN} Indicates the scanner cover is open.
 *         {@link SCAN_ERROR_IO_ERROR} Indicates an error occurred while communicating with the device.
 *         {@link SCAN_ERROR_NO_MEM} Indicates an insufficent amount of memory is available.
 *         {@link SCAN_ERROR_INVALID_PARAMETER} Indicates that the input parameter is invalid.
 *         {@link SCAN_ERROR_DEVICE_BUSY} Indicates the device is busy, the operation should be retried later.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Scan_StartScan(const char* scannerId, bool batchMode);

/**
 * @brief This API allows the scanner to cancel the scan.
 *
 * @permission {@code ohos.permission.PRINT}
 * @param scannerId This id is used to cancel the scan job for the specified scanner.
 * @return {@link Scan_ERROR_NONE} Indicates that the scanner has successfully canceled the scan job.
 *         {@link SCAN_ERROR_NO_PERMISSION} Indicates have no permission to use this interface.
 *         {@link SCAN_ERROR_INVALID_PARAMETER} Indicates if the pointer is null or the character string is null.
 *         {@link SCAN_ERROR_RPC_FAILURE} Indicates an RPC communication error.
 *         {@link SCAN_ERROR_SERVER_FAILURE} Indicates An error occurs in the scan process.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Scan_CancelScan(const char* scannerId);

/**
 * @brief This API can get the progress of the scanner scanning the picture.A non-null value must be passed in,
 * and the scan progress will be written to the structure to which the pointer points.
 *
 * @permission {@code ohos.permission.PRINT}
 * @param scannerId The id for querying the image scanning progress of the scanner.
 * @param prog The {@link Scan_PictureScanProgress} of scanning pictures, must be a non-null value.
 * @return {@link Scan_ERROR_NONE} Indicates the scanner has successfully queried the progress of the scanned image.
 *         {@link SCAN_ERROR_NO_PERMISSION} Indicates have no permission to use this interface.
 *         {@link SCAN_ERROR_INVALID_PARAMETER} Indicates if the pointer is null or the character string is null.
 *         {@link SCAN_ERROR_RPC_FAILURE} Indicates an RPC communication error.
 *         {@link SCAN_ERROR_SERVER_FAILURE} Indicates An error occurs in the scan process.
 *         {@link SCAN_ERROR_JAMMED} Indicates the document feeder is jammed.
 *         {@link SCAN_ERROR_NO_DOCS} Indicates the document feeder is out of documents.
 *         {@link SCAN_ERROR_COVER_OPEN} Indicates the scanner cover is open.
 *         {@link SCAN_ERROR_IO_ERROR} Indicates an error occurred while communicating with the scanner.
 *         {@link SCAN_ERROR_NO_MEM} Indicates an insufficent amount of memory is available.
 *         {@link SCAN_ERROR_DEVICE_BUSY} Indicates the device is busy, the operation should be retried later.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Scan_GetPictureScanProgress(const char* scannerId, Scan_PictureScanProgress* prog);

/**
 * @brief This API can be used to exit the scanning service, free the Scan Framework Memory,
 *        and unregister the callback for scanner discover.
 *
 * @permission {@code ohos.permission.PRINT}
 * @return {@link Scan_ERROR_NONE} Indicates the scan service exit successfully.
 *         {@link SCAN_ERROR_NO_PERMISSION} Indicates have no permission to use this interface.
 *         {@link SCAN_ERROR_RPC_FAILURE} Indicates an RPC communication error.
 *         {@link SCAN_ERROR_SERVER_FAILURE} Indicates An error occurs in the scan process.
 * @syscap SystemCapability.Print.PrintFramework
 * @since 12
 */
int32_t OH_Scan_Exit();

#ifdef __cplusplus
}
#endif

#endif  // OH_SCAN_H
/** @} */
