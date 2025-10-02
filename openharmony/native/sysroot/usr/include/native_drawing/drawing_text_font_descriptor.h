/*
 * Copyright (c) 2021-2024 Huawei Device Co., Ltd.
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
 * @addtogroup Drawing
 * @{
 *
 * @brief Provides the font descriptor capability.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 *
 * @since 14
 * @version 1.0
 */

/**
 * @file drawing_text_font_descriptor.h
 *
 * @brief Provide the ability to provide <b>OH_Drawing_FontDescriptor</b>.
 *
 * @kit ArkGraphics2D
 * @library libnative_drawing.so
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @since 14
 * @version 1.0
 */

#ifndef DRAWING_TEXT_FONT_DESCRIPTOR_H
#define DRAWING_TEXT_FONT_DESCRIPTOR_H

#include "drawing_text_typography.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief An enumeration of system font types.
 *
 * @since 14
 */
typedef enum {
    /** All font types */
    ALL = 1 << 0,
    /** System generic font type */
    GENERIC = 1 << 1,
    /** Stylish font type */
    STYLISH = 1 << 2,
    /** Installed font types */
    INSTALLED = 1 << 3,
    /**
     * Customized font types
     * @since 18
    */
    CUSTOMIZED = 1 << 4,
} OH_Drawing_SystemFontType;

/**
 * @brief Obtain all system font descriptive symbols that match the specified font descriptor. Where the 'path'
 * fields are not considered as valid matching values, It takes effect when the remaining fields are not
 * default values, If all the fields of the parameters <b>OH_Drawing_FontDescriptor</b> are default, obtain all system
 * font descriptors. If the match fails, return nullptr.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param desc The pointer to the <b>OH_Drawing_FontDescriptor</b> object. It is recommended to
 * use <b>OH_Drawing_CreateFontDescriptor</b> to obtain a valid <b>OH_Drawing_FontDescriptor</b> instance.
 * If you create your own <b>OH_Drawing_FontDescriptor</b> object, ensure that fields not intended for matching are
 * set to their default values.
 * @param num Indicates the count of obtained <b>OH_Drawing_FontDescriptor</b>.
 * @return Returns an array of <b>OH_Drawing_FontDescriptor</b>. Released through the
 * <b>OH_Drawing_DestroyFontDescriptors</b> interface after use.
 * @since 18
 */
OH_Drawing_FontDescriptor* OH_Drawing_MatchFontDescriptors(OH_Drawing_FontDescriptor* desc, size_t* num);

/**
 * @brief Releases the <b>OH_Drawing_FontDescriptor</b> array.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param descriptors <b>OH_Drawing_FontDescriptor</b> object array.
 * @param num Represents the number of members of the <b>OH_Drawing_FontDescriptor</b> array.
 * @since 18
 */
void OH_Drawing_DestroyFontDescriptors(OH_Drawing_FontDescriptor* descriptors, size_t num);

/**
 * @brief Get the <b>OH_Drawing_FontDescriptor</b> object by the font full name and the font type, supporting generic
 * fonts, stylish fonts, and installed fonts.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param fullName Indicates the full name object <b>OH_Drawing_String</b>.
 * @param fontType Indicates enumerates of system font type object <b>OH_Drawing_SystemFontType</b>.
 * @return Returns the pointer to a font descriptor object <b>OH_Drawing_FontDescriptor</b>.
 * @since 14
 */
OH_Drawing_FontDescriptor* OH_Drawing_GetFontDescriptorByFullName(const OH_Drawing_String* fullName,
    OH_Drawing_SystemFontType fontType);

/**
 * @brief Obtain the corresponding font full name array by the font type.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param fontType Indicates enumerates of system font type object <b>OH_Drawing_SystemFontType</b>.
 * @return Returns the pointer to full name array object <b>OH_Drawing_Array</b>.
 * @since 14
 */
OH_Drawing_Array* OH_Drawing_GetSystemFontFullNamesByType(OH_Drawing_SystemFontType fontType);

/**
 * @brief Get the specified full name object <b>OH_Drawing_String</b> by index from the
 * <b>OH_Drawing_Array</b> object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param fullNameArray Indicates an array of full name object <b>OH_Drawing_Array</b>.
 * @param index The index of full name.
 * @return Returns a full name object <b>OH_Drawing_String</b>.
 * @since 14
 */
const OH_Drawing_String* OH_Drawing_GetSystemFontFullNameByIndex(OH_Drawing_Array* fullNameArray, size_t index);

/**
 * @brief Releases the memory occupied by an array of font full names.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param fullNameArray Indicates an array of full name object <b>OH_Drawing_Array</b>.
 * @since 14
 */
void OH_Drawing_DestroySystemFontFullNames(OH_Drawing_Array* fullNameArray);

#ifdef __cplusplus
}
#endif
/** @} */
#endif