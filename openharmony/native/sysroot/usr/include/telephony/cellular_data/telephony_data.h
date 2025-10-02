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

#ifndef NATIVE_TELEPHONY_DATA_API_H
#define NATIVE_TELEPHONY_DATA_API_H

/**
 * @file telephony_data.h
 *
 * @brief Provides C interface for the telephony cellular data.
 *
 * @kit TelephonyKit
 * @syscap SystemCapability.Telephony.CellularData
 * @library libtelephony_data.so
 * @since 13
 */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Obtains the default cellular data slot id.
 *
 * @return the default cellular data slot id (0 for slot 1, 1 for slot 2).
 * @syscap SystemCapability.Telephony.CellularData
 * @since 13
 */
int32_t OH_Telephony_GetDefaultCellularDataSlotId(void);

#ifdef __cplusplus
}
#endif

#endif // NATIVE_TELEPHONY_DATA_API_H
