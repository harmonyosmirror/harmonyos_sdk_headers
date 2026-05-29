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
 * @addtogroup ArkUI_NativeModule
 * @{
 *
 * @brief Provides ArkUI UI capabilities on the Native side, such as UI component creation and destruction,
 * tree node operation, property setting, event monitoring, and so on.
 *
 * @since 12
 */

/**
 * @file styled_string.h
 *
 * @brief Provides ArkUI with property string capabilities on the Native side.
 *
 * @library libace_ndk.z.so
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @kit ArkUI
 * @since 12
 */

#ifndef ARKUI_NATIVE_STYLED_STRING_H
#define ARKUI_NATIVE_STYLED_STRING_H

#include "info/application_target_sdk_version.h"
#include "native_drawing/drawing_text_declaration.h"
#include "native_drawing/drawing_text_typography.h"
#include "native_drawing/drawing_types.h"
#include "native_gesture.h"
#include "native_node.h"
#include "native_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines formatted string data objects supported by the text component.
 *
 * @since 12
 */
typedef struct ArkUI_StyledString ArkUI_StyledString;

/**
 * @brief Creates a pointer to the ArkUI_StyledString object.
 *
 * @param style A pointer to OH_Drawing_TypographyStyle, obtained by {@link OH_Drawing_CreateTypographyStyle}.
 * @param collection A pointer to OH_Drawing_FontCollection, obtained by {@link OH_Drawing_CreateFontCollection}.
 * @return Creates a pointer to the ArkUI_StyledString object. If the object returns a null pointer,
 *         the creation failed, either because the address space was full,
 *         or because the style, collection parameter was an exception such as a null pointer.
 * @since 12
 */
ArkUI_StyledString* OH_ArkUI_StyledString_Create(
    OH_Drawing_TypographyStyle* style, OH_Drawing_FontCollection* collection)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Free the memory occupied by the ArkUI_StyledString object.
 *
 * @param handle A pointer to the ArkUI_StyledString object.
 * @since 12
 */
void OH_ArkUI_StyledString_Destroy(ArkUI_StyledString* handle)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets the new layout style to the top of the current format string style stack.
 *
 * @param handle A pointer to the ArkUI_StyledString object.
 * @param style A pointer to the OH_Drawing_TextStyle object.
 * @since 12
 */
void OH_ArkUI_StyledString_PushTextStyle(ArkUI_StyledString* handle, OH_Drawing_TextStyle* style)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets the corresponding text content based on the current format string style.
 *
 * @param handle A pointer to the ArkUI_StyledString object.
 * @param content A pointer to the text content.
 * @since 12
 */
void OH_ArkUI_StyledString_AddText(ArkUI_StyledString* handle, const char* content)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Removes the top style from the stack in the current format string object.
 *
 * @param handle A pointer to the ArkUI_StyledString object.
 * @since 12
 */
void OH_ArkUI_StyledString_PopTextStyle(ArkUI_StyledString* handle)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Creates a pointer to an OH_Drawing_Typography object based on a format string object
 * for advanced text estimation and typography.
 *
 * @param handle A pointer to the ArkUI_StyledString object.
 * @return A pointer to the OH_Drawing_Typography object. If the object returns a null pointer,
 *         the creation fails because the handle parameter is abnormal, such as a null pointer.
 * @since 12
 */
OH_Drawing_Typography* OH_ArkUI_StyledString_CreateTypography(ArkUI_StyledString* handle)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the placeholder.
 *
 * @param handle A pointer to the ArkUI_StyledString object.
 * @param placeholder A pointer to the OH_Drawing_PlaceholderSpan object.
 * @since 12
 */
void OH_ArkUI_StyledString_AddPlaceholder(ArkUI_StyledString* handle, OH_Drawing_PlaceholderSpan* placeholder)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Creates an <b>ArkUI_StyledString_Descriptor</b> object.
 *
 * @return Returns the pointer to the <b>ArkUI_StyledString_Descriptor</b> object created.
 * @since 14
 */
ArkUI_StyledString_Descriptor* OH_ArkUI_StyledString_Descriptor_Create(void)
__attribute__((__availability__(ohos, introduced=14.0.0)));

/**
 * @brief Destroys an <b>ArkUI_StyledString_Descriptor</b> object and reclaims the memory occupied by the object.
 *
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @since 14
 */
void OH_ArkUI_StyledString_Descriptor_Destroy(ArkUI_StyledString_Descriptor* descriptor)
__attribute__((__availability__(ohos, introduced=14.0.0)));

/**
 * @brief Converts styled string information into HTML.
 *
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @return Returns the pointer to the resulting HTML string. This pointer is managed internally and should be destroyed
 *         by calling <b>OH_ArkUI_StyledString_Descriptor_Destroy()</b> when no longer needed to free the memory.
 * @since 14
 */
const char* OH_ArkUI_ConvertToHtml(ArkUI_StyledString_Descriptor* descriptor)
__attribute__((__availability__(ohos, introduced=14.0.0)));

/**
 * @brief Deserializes a byte array containing styled string information into a styled string.
 *
 * @param buffer Byte array to be deserialized.
 * @param bufferSize Length of the byte array.
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 * @since 14
 */
int32_t OH_ArkUI_UnmarshallStyledStringDescriptor(
    uint8_t* buffer, size_t bufferSize, ArkUI_StyledString_Descriptor* descriptor)
    __attribute__((__availability__(ohos, introduced=14.0.0)));

/**
 * @brief Serializes the styled string information into a byte array.
 *
 * @param buffer Byte array where the serialized data will be stored.
 * @param bufferSize Length of the byte array.
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @param resultSize Actual length of the byte array.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_INVALID_STYLED_STRING} if the styled string is invalid.
 * @since 14
 */
int32_t OH_ArkUI_MarshallStyledStringDescriptor(
    uint8_t* buffer, size_t bufferSize, ArkUI_StyledString_Descriptor* descriptor, size_t* resultSize)
    __attribute__((__availability__(ohos, introduced=14.0.0)));

/**
 * @brief Defines span style.
 * @since 24
 */
typedef struct OH_ArkUI_SpanStyle OH_ArkUI_SpanStyle;
 
/**
 * @brief Defines image attachment.
 * @since 24
 */
typedef struct OH_ArkUI_ImageAttachment OH_ArkUI_ImageAttachment;
 
/**
 * @brief Defines custom span.
 * @since 24
 */
typedef struct OH_ArkUI_CustomSpan OH_ArkUI_CustomSpan;
 
/**
 * @brief Enumerates the attribute type of the styled string.
 *
 * @since 24
 */
typedef enum {
    /**
     * The key of unspecified style.
     *
     * @since 24
     */
    OH_ARKUI_STYLEDSTRINGKEY_UNSPECIFIED = -1,

    /**
     * The key of <b>OH_ArkUI_TextStyle</b>.
     *
     * @since 24
     */
    OH_ARKUI_STYLEDSTRINGKEY_FONT = 0,

    /**
     * The key of <b>OH_ArkUI_DecorationStyle</b>.
     *
     * @since 24
     */
    OH_ARKUI_STYLEDSTRINGKEY_DECORATION = 1,

    /**
     * The key of <b>OH_ArkUI_BaselineOffsetStyle</b>.
     *
     * @since 24
     */
    OH_ARKUI_STYLEDSTRINGKEY_BASELINE_OFFSET = 2,

    /**
     * The key of <b>OH_ArkUI_LetterSpacingStyle</b>.
     *
     * @since 24
     */
    OH_ARKUI_STYLEDSTRINGKEY_LETTER_SPACING = 3,

    /**
     * The key of <b>OH_ArkUI_TextShadowStyle</b>.
     *
     * @since 24
     */
    OH_ARKUI_STYLEDSTRINGKEY_TEXT_SHADOW = 4,

    /**
     * The key of <b>OH_ArkUI_LineHeightStyle</b>.
     *
     * @since 24
     */
    OH_ARKUI_STYLEDSTRINGKEY_LINE_HEIGHT = 5,

    /**
     * The key of <b>OH_ArkUI_BackgroundColorStyle</b>.
     *
     * @since 24
     */
    OH_ARKUI_STYLEDSTRINGKEY_BACKGROUND_COLOR = 6,

    /**
     * The key of <b>OH_ArkUI_UrlStyle</b>.
     *
     * @since 24
     */
    OH_ARKUI_STYLEDSTRINGKEY_URL = 7,

    /**
     * The key of <b>OH_ArkUI_GestureStyle</b>.
     *
     * @since 24
     */
    OH_ARKUI_STYLEDSTRINGKEY_GESTURE = 100,

    /**
     * The key of <b>OH_ArkUI_ParagraphStyle</b>.
     *
     * @since 24
     */
    OH_ARKUI_STYLEDSTRINGKEY_PARAGRAPH_STYLE = 200,

    /**
     * The key of <b>OH_ArkUI_ImageAttachment</b>.
     *
     * @since 24
     */
    OH_ARKUI_STYLEDSTRINGKEY_IMAGE = 300,

    /**
     * The key of <b>OH_ArkUI_CustomSpan</b>.
     *
     * @since 24
     */
    OH_ARKUI_STYLEDSTRINGKEY_CUSTOM_SPAN = 400,

    /**
     * The key of <b>OH_ArkUI_UserDataSpan</b>.
     *
     * @since 24
     */
    OH_ARKUI_STYLEDSTRINGKEY_USER_DATA = 500
} OH_ArkUI_StyledStringKey;
 
/**
 * @brief Creates an <b>ArkUI_StyledString_Descriptor</b> object about text.
 *
 * @note When the object is no longer in use, invoke <b> OH_ArkUI_StyledString_Descriptor_Destroy </b> to destroy it.
 * All input pointer parameters must be allocated, managed, and released by the caller.
 * @param value Pointer to the text content.
 * @param styles Data set about span style.
 * @param length The length of data set about span style.
 * @return The pointer to the <b>ArkUI_StyledString_Descriptor</b> object created. If the result is a null pointer,
 *         it may be params is invalid.
 * @since 24
 */
ArkUI_StyledString_Descriptor* OH_ArkUI_StyledString_Descriptor_CreateWithString(const char* value,
    const OH_ArkUI_SpanStyle** styles, int32_t length)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Creates an <b>ArkUI_StyledString_Descriptor</b> object about image.
 *
 * @note When the object is no longer in use, invoke <b> OH_ArkUI_StyledString_Descriptor_Destroy </b> to destroy it.
 * All input pointer parameters must be allocated, managed, and released by the caller.
 * @param value Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @return The pointer to the <b>ArkUI_StyledString_Descriptor</b> object created. If the result is a null pointer,
 *         it may be params is invalid.
 * @since 24
 */
ArkUI_StyledString_Descriptor* OH_ArkUI_StyledString_Descriptor_CreateWithImageAttachment(
    const OH_ArkUI_ImageAttachment* value)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Creates an <b>ArkUI_StyledString_Descriptor</b> object about custom span.
 *
 * @note When the object is no longer in use, invoke <b> OH_ArkUI_StyledString_Descriptor_Destroy </b> to destroy it.
 * All input pointer parameters must be allocated, managed, and released by the caller.
 * @param value Pointer to the <b>OH_ArkUI_CustomSpan</b> object.
 * @return The pointer to the <b>ArkUI_StyledString_Descriptor</b> object created. If the result is a null pointer,
 *         it may be params is invalid.
 * @since 24
 */
ArkUI_StyledString_Descriptor* OH_ArkUI_StyledString_Descriptor_CreateWithCustomSpan(const OH_ArkUI_CustomSpan* value)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the characters length of styled string.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @param length The characters length.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_INVALID_STYLED_STRING} if the styled string is invalid.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_GetLength(const ArkUI_StyledString_Descriptor* descriptor,
    int32_t* length)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get the literal content of the styled string.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @param buffer The buffer to which text content writes to the memory,
 *               memory space needs to be allocated by the developer.
 * @param bufferSize The buffer size
 * @param writeLength Indicates the string length actually written to the buffer
 *                    when returning {@link ARKUI_ERROR_CODE_NO_ERROR}.
 *                    Indicates the minimum buffer size that can accommodate the target
 *                    when {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} is returned.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_INVALID_STYLED_STRING} if the styled string is invalid.
 *         Returns {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} If the buffer size is less than the minimum buffer size.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_GetString(
    const ArkUI_StyledString_Descriptor* descriptor, char* buffer, int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Judge if two styled strings are equal.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param firstDescriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @param secondDescriptor Pointer to another <b>ArkUI_StyledString_Descriptor</b> object.
 * @param isEqual If two objects about the <b>ArkUI_StyledString_Descriptor</b> are equal.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_INVALID_STYLED_STRING} if the styled string is invalid.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_IsEqual(const ArkUI_StyledString_Descriptor* firstDescriptor,
    const ArkUI_StyledString_Descriptor* secondDescriptor, bool* isEqual)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the substring of the styled string.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @param subDescriptor Pointer to the substring of <b>ArkUI_StyledString_Descriptor</b> object.
 * @param start The start position of the sub styled string.
 * @param length The characters length of the sub styled string.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_INVALID_STYLED_STRING} if the styled string is invalid.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_SubStyledString(const ArkUI_StyledString_Descriptor* descriptor,
    ArkUI_StyledString_Descriptor* subDescriptor, uint32_t start, uint32_t length)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get span styles within a specified range of the styled string.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @param start The start position of the range.
 * @param length The length of the range.
 * @param styledKey The specified style type.
 * @param styles The span styles.
 * @param stylesSize Buffer size for span styles.
 * @param writeLength The actual size of span styles in styled string.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_INVALID_STYLED_STRING} if the styled string is invalid.
 *         Returns {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} If the buffer size is less than the minimum buffer size.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_GetStyles(const ArkUI_StyledString_Descriptor* descriptor,
    uint32_t start, uint32_t length, OH_ArkUI_StyledStringKey styledKey, OH_ArkUI_SpanStyle** styles,
    uint32_t stylesSize, uint32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get styled string from the provided HTML string.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @param html The html text will be converted to a StyledString.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_INVALID_STYLED_STRING} if the styled string is invalid.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_FromHtml(ArkUI_StyledString_Descriptor* descriptor, const char* html)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Replace the string of the specified range of styled string.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @param start The start position of the replaced string.
 * @param length The characters length of the replaced string.
 * @param string Replaced string.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_INVALID_STYLED_STRING} if the styled string is invalid.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_ReplaceString(
    ArkUI_StyledString_Descriptor* descriptor, uint32_t start, uint32_t length, const char* string)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Insert the string at the specified location in styled string.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @param start The start position of the inserted string.
 * @param string Inserted string.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_INVALID_STYLED_STRING} if the styled string is invalid.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_InsertString(
    ArkUI_StyledString_Descriptor* descriptor, uint32_t start, const char* string)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Remove the string of the specified range of styled string.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @param start The start position of the removed string.
 * @param length The characters length of the removed string.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_INVALID_STYLED_STRING} if the styled string is invalid.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_RemoveString(
    ArkUI_StyledString_Descriptor* descriptor, uint32_t start, uint32_t length)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Replace span style in the specified range of styled string.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_INVALID_STYLED_STRING} if the styled string is invalid.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_ReplaceStyle(
    ArkUI_StyledString_Descriptor* descriptor, const OH_ArkUI_SpanStyle* spanStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Add span style to the specified range string of styled string.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_INVALID_STYLED_STRING} if the styled string is invalid.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_SetStyle(
    ArkUI_StyledString_Descriptor* descriptor, const OH_ArkUI_SpanStyle* spanStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Delete the specified type span style from the specified range of styled string.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @param start The start position in styled string.
 * @param length The length in styled string.
 * @param styledKey The key of the specified span style type.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_INVALID_STYLED_STRING} if the styled string is invalid.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_RemoveStyle(
    ArkUI_StyledString_Descriptor* descriptor, uint32_t start, uint32_t length, OH_ArkUI_StyledStringKey styledKey)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Clear all span style in the styled string.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_INVALID_STYLED_STRING} if the styled string is invalid.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_ClearStyles(ArkUI_StyledString_Descriptor* descriptor)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Replace the styled string of the specified range.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @param start The start position of the replaced styled string.
 * @param length The characters length of the replaced styled string.
 * @param other The other pointer to <b>ArkUI_StyledString_Descriptor</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_INVALID_STYLED_STRING} if the styled string is invalid.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_ReplaceStyledString(ArkUI_StyledString_Descriptor* descriptor,
    uint32_t start, uint32_t length, const ArkUI_StyledString_Descriptor* other)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Insert new styled string at the specified location of styled string.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @param start The start position of the inserted styled string.
 * @param other The other pointer to <b>ArkUI_StyledString_Descriptor</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_INVALID_STYLED_STRING} if the styled string is invalid.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_InsertStyledString(
    ArkUI_StyledString_Descriptor* descriptor, uint32_t start, const ArkUI_StyledString_Descriptor* other)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Append new styled string at the end.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @param other The other pointer to <b>ArkUI_StyledString_Descriptor</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_INVALID_STYLED_STRING} if the styled string is invalid.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_AppendStyledString(
    ArkUI_StyledString_Descriptor* descriptor, const ArkUI_StyledString_Descriptor* other)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Invalidate custom span drawing in the styled string.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_INVALID_STYLED_STRING} if the styled string is invalid.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_InvalidateCustomSpan(const ArkUI_StyledString_Descriptor* descriptor)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Defines text style.
 * @since 24
 */
typedef struct OH_ArkUI_TextStyle OH_ArkUI_TextStyle;
 
/**
 * @brief Enumerates the superscript style type.
 *
 * @since 24
 */
typedef enum {
    /**
     * Normal font style.
     *
     * @since 24
     */
    OH_ARKUI_SUPERSCRIPTSTYLE_NORMAL = 0,

    /**
     * Superscript font style.
     *
     * @since 24
     */
    OH_ARKUI_SUPERSCRIPTSTYLE_SUPERSCRIPT,

    /**
     * Subscript font style.
     *
     * @since 24
     */
    OH_ARKUI_SUPERSCRIPTSTYLE_SUBSCRIPT
} OH_ArkUI_SuperscriptStyle;
 
/**
 * @brief Create an <b>OH_ArkUI_TextStyle</b> object.
 *
 * @note When the object is no longer in use, invoke <b> OH_ArkUI_TextStyle_Destroy </b> to destroy it.
 * @return Pointer to the <b>OH_ArkUI_TextStyle</b> object.
 * @since 24
 */
OH_ArkUI_TextStyle* OH_ArkUI_TextStyle_Create() __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Release the memory occupied by the <b>OH_ArkUI_TextStyle</b> object.
 *
 * @param textStyle Pointer to the <b>OH_ArkUI_TextStyle</b> object.
 * @since 24
 */
void OH_ArkUI_TextStyle_Destroy(OH_ArkUI_TextStyle* textStyle)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set font color in the text style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param textStyle Pointer to the <b>OH_ArkUI_TextStyle</b> object.
 * @param fontColor Font color.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextStyle_SetFontColor(OH_ArkUI_TextStyle* textStyle, uint32_t fontColor)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get font color in the text style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param textStyle Pointer to the <b>OH_ArkUI_TextStyle</b> object.
 * @param fontColor Font color.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextStyle_GetFontColor(const OH_ArkUI_TextStyle* textStyle, uint32_t* fontColor)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set font family in the text style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param textStyle Pointer to the <b>OH_ArkUI_TextStyle</b> object.
 * @param fontFamily Font family.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextStyle_SetFontFamily(OH_ArkUI_TextStyle* textStyle, const char* fontFamily)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get font family in the text style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param textStyle Pointer to the <b>OH_ArkUI_TextStyle</b> object.
 * @param buffer The buffer to which font family writes to the memory,
 *               memory space needs to be allocated by the developer.
 * @param bufferSize The buffer size
 * @param writeLength Indicates the string length actually written to the buffer
 *                    when returning {@link ARKUI_ERROR_CODE_NO_ERROR}.
 *                    Indicates the minimum buffer size that can accommodate the target
 *                    when {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} is returned.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 *         Returns {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} If the buffer size is less than the minimum buffer size.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextStyle_GetFontFamily(const OH_ArkUI_TextStyle* textStyle,
    char* buffer, int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set font size in the text style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param textStyle Pointer to the <b>OH_ArkUI_TextStyle</b> object.
 * @param fontSize Font size.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextStyle_SetFontSize(OH_ArkUI_TextStyle* textStyle, float fontSize)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get font size in the text style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param textStyle Pointer to the <b>OH_ArkUI_TextStyle</b> object.
 * @param fontSize Font size.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextStyle_GetFontSize(const OH_ArkUI_TextStyle* textStyle, float* fontSize)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set Font weight in the text style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param textStyle Pointer to the <b>OH_ArkUI_TextStyle</b> object.
 * @param fontWeight Font weight.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextStyle_SetFontWeight(OH_ArkUI_TextStyle* textStyle, uint32_t fontWeight)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get font weight in the text style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param textStyle Pointer to the <b>OH_ArkUI_TextStyle</b> object.
 * @param fontWeight Font weight.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextStyle_GetFontWeight(const OH_ArkUI_TextStyle* textStyle, uint32_t* fontWeight)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set font style in the text style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param textStyle Pointer to the <b>OH_ArkUI_TextStyle</b> object.
 * @param fontStyle Font style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextStyle_SetFontStyle(OH_ArkUI_TextStyle* textStyle, ArkUI_FontStyle fontStyle)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get font style in the text style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param textStyle Pointer to the <b>OH_ArkUI_TextStyle</b> object.
 * @param fontStyle Font style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextStyle_GetFontStyle(const OH_ArkUI_TextStyle* textStyle, ArkUI_FontStyle* fontStyle)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set stroke width in the text style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param textStyle Pointer to the <b>OH_ArkUI_TextStyle</b> object.
 * @param strokeWidth Stroke width.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextStyle_SetStrokeWidth(OH_ArkUI_TextStyle* textStyle, float strokeWidth)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get stroke width in the text style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param textStyle Pointer to the <b>OH_ArkUI_TextStyle</b> object.
 * @param strokeWidth Stroke width.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextStyle_GetStrokeWidth(const OH_ArkUI_TextStyle* textStyle, float* strokeWidth)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set stroke color in the text style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param textStyle Pointer to the <b>OH_ArkUI_TextStyle</b> object.
 * @param strokeColor Stroke color.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextStyle_SetStrokeColor(OH_ArkUI_TextStyle* textStyle, uint32_t strokeColor)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get stroke color in the text style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param textStyle Pointer to the <b>OH_ArkUI_TextStyle</b> object.
 * @param strokeColor Stroke color.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextStyle_GetStrokeColor(const OH_ArkUI_TextStyle* textStyle, uint32_t* strokeColor)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set superscript style in the text style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param textStyle Pointer to the <b>OH_ArkUI_TextStyle</b> object.
 * @param superscript Superscript style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextStyle_SetSuperscript(OH_ArkUI_TextStyle* textStyle,
    OH_ArkUI_SuperscriptStyle superscript)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get superscript style in the text style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param textStyle Pointer to the <b>OH_ArkUI_TextStyle</b> object.
 * @param superscript Superscript style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextStyle_GetSuperscript(const OH_ArkUI_TextStyle* textStyle,
    OH_ArkUI_SuperscriptStyle* superscript)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Create an <b>OH_ArkUI_SpanStyle</b> object.
 *
 * @note When the object is no longer in use, invoke <b> OH_ArkUI_SpanStyle_Destroy </b> to destroy it.
 * @return Pointer to the <b>OH_ArkUI_SpanStyle</b> object.
 * @since 24
 */
OH_ArkUI_SpanStyle* OH_ArkUI_SpanStyle_Create() __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Release the memory occupied by the <b>OH_ArkUI_SpanStyle</b> object.
 *
 * @param spanStyle Pointer to the <b>OH_ArkUI_SpanStyle</b> object.
 * @since 24
 */
void OH_ArkUI_SpanStyle_Destroy(OH_ArkUI_SpanStyle* spanStyle)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get styled string key of span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to the <b>OH_ArkUI_SpanStyle</b> object.
 * @param styledKey The styled string key of span style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetStyledKey(const OH_ArkUI_SpanStyle* spanStyle,
    OH_ArkUI_StyledStringKey* styledKey)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set start position of span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to the <b>OH_ArkUI_SpanStyle</b> object.
 * @param start The start position of span style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetStart(OH_ArkUI_SpanStyle* spanStyle, int32_t start)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get start position of span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to the <b>OH_ArkUI_SpanStyle</b> object.
 * @param start The start position of span style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetStart(const OH_ArkUI_SpanStyle* spanStyle, int32_t* start)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set length of span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to the <b>OH_ArkUI_SpanStyle</b> object.
 * @param length The length of span style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetLength(OH_ArkUI_SpanStyle* spanStyle, int32_t length)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get length of span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to the <b>OH_ArkUI_SpanStyle</b> object.
 * @param length The length of span style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetLength(const OH_ArkUI_SpanStyle* spanStyle, int32_t* length)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set text style of span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to the <b>OH_ArkUI_SpanStyle</b> object.
 * @param textStyle Pointer to the <b>OH_ArkUI_TextStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetTextStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_TextStyle* textStyle)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get text style of span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to the <b>OH_ArkUI_SpanStyle</b> object.
 * @param textStyle Pointer to the <b>OH_ArkUI_TextStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetTextStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_TextStyle* textStyle)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Defines paragraph style.
 * @since 24
 */
typedef struct OH_ArkUI_ParagraphStyle OH_ArkUI_ParagraphStyle;
 
/**
 * @brief Set the paragraph style of span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to the <b>OH_ArkUI_SpanStyle</b> object.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetParagraphStyle(
    OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_ParagraphStyle* paragraphStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get paragraph style with span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to the <b>OH_ArkUI_SpanStyle</b> object.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetParagraphStyle(
    const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_ParagraphStyle* paragraphStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Defines gesture style.
 * @since 24
 */
typedef struct OH_ArkUI_GestureStyle OH_ArkUI_GestureStyle;
 
/**
 * @brief Set the gesture style of span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param gestureStyle Pointer to the <b>OH_ArkUI_GestureStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetGestureStyle(
    OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_GestureStyle* gestureStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get gesture style with span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param gestureStyle Pointer to the <b>OH_ArkUI_GestureStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetGestureStyle(
    const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_GestureStyle* gestureStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Defines text shadow style.
 * @since 24
 */
typedef struct OH_ArkUI_TextShadowStyle OH_ArkUI_TextShadowStyle;
 
/**
 * @brief Set text shadow style of span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param textShadowStyle Pointer to the <b>OH_ArkUI_TextShadowStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetTextShadowStyle(
    OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_TextShadowStyle* textShadowStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get text shadow style with span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param textShadowStyle Pointer to the <b>OH_ArkUI_TextShadowStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetTextShadowStyle(
    const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_TextShadowStyle* textShadowStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Defines decoration style.
 * @since 24
 */
typedef struct OH_ArkUI_DecorationStyle OH_ArkUI_DecorationStyle;
 
/**
 * @brief Set decoration style of span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param decorationStyle Pointer to the <b>OH_ArkUI_DecorationStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetDecorationStyle(
    OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_DecorationStyle* decorationStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get decoration style with span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param decorationStyle Pointer to the <b>OH_ArkUI_DecorationStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetDecorationStyle(
    const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_DecorationStyle* decorationStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Defines baseline offset style.
 * @since 24
 */
typedef struct OH_ArkUI_BaselineOffsetStyle OH_ArkUI_BaselineOffsetStyle;

/**
 * @brief Set baseline offset style of span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param baselineOffsetStyle Pointer to the <b>OH_ArkUI_BaselineOffsetStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetBaselineOffsetStyle(
    OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_BaselineOffsetStyle* baselineOffsetStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get baseline offset style with span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param baselineOffsetStyle Pointer to the <b>OH_ArkUI_BaselineOffsetStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetBaselineOffsetStyle(
    const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_BaselineOffsetStyle* baselineOffsetStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Defines letter spacing style.
 * @since 24
 */
typedef struct OH_ArkUI_LetterSpacingStyle OH_ArkUI_LetterSpacingStyle;
 
/**
 * @brief Set letter spacing style of span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param letterSpacingStyle Pointer to the <b>OH_ArkUI_LetterSpacingStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetLetterSpacingStyle(
    OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_LetterSpacingStyle* letterSpacingStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get letter spacing style with span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param letterSpacingStyle Pointer to the <b>OH_ArkUI_LetterSpacingStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetLetterSpacingStyle(
    const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_LetterSpacingStyle* letterSpacingStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Defines line height style.
 * @since 24
 */
typedef struct OH_ArkUI_LineHeightStyle OH_ArkUI_LineHeightStyle;
 
/**
 * @brief Set line height style of span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param lineHeightStyle Pointer to the <b>OH_ArkUI_LineHeightStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetLineHeightStyle(
    OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_LineHeightStyle* lineHeightStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get line height style with span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param lineHeightStyle Pointer to the <b>OH_ArkUI_LineHeightStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetLineHeightStyle(
    const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_LineHeightStyle* lineHeightStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Defines url style.
 * @since 24
 */
typedef struct OH_ArkUI_UrlStyle OH_ArkUI_UrlStyle;
 
/**
 * @brief Set url style of span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param urlStyle Pointer to the <b>OH_ArkUI_UrlStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetUrlStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_UrlStyle* urlStyle)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get url style with span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param urlStyle Pointer to the <b>OH_ArkUI_UrlStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetUrlStyle(
    const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_UrlStyle* urlStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Defines background color style.
 * @since 24
 */
typedef struct OH_ArkUI_BackgroundColorStyle OH_ArkUI_BackgroundColorStyle;
 
/**
 * @brief Set background color style with span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param backgroundColorStyle Pointer to the <b>OH_ArkUI_BackgroundColorStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetBackgroundColorStyle(
    OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_BackgroundColorStyle* backgroundColorStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get background color style with span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param backgroundColorStyle Pointer to the <b>OH_ArkUI_BackgroundColorStyle</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetBackgroundColorStyle(
    const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_BackgroundColorStyle* backgroundColorStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Defines user data span.
 * @since 24
 */
typedef struct OH_ArkUI_UserDataSpan OH_ArkUI_UserDataSpan;
 
/**
 * @brief Set user data style of span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param userDataSpan Pointer to the <b>OH_ArkUI_UserDataSpan</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetUserDataSpan(
    OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_UserDataSpan* userDataSpan)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get user data style with span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param userDataSpan Pointer to the <b>OH_ArkUI_UserDataSpan</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetUserDataSpan(
    const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_UserDataSpan* userDataSpan)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set custom span with span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param customSpan Pointer to the <b>OH_ArkUI_CustomSpan</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetCustomSpan(
    OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_CustomSpan* customSpan)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get custom span with span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param customSpan Pointer to the <b>OH_ArkUI_CustomSpan</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetCustomSpan(
    const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_CustomSpan* customSpan)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set image attachment with span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetImageAttachment(
    OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_ImageAttachment* imageAttachment)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get image attachment with span style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param spanStyle Pointer to an <b>OH_ArkUI_SpanStyle</b> object.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetImageAttachment(
    const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_ImageAttachment* imageAttachment)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Defines drawing info about leading margin.
 * @since 24
 */
typedef struct OH_ArkUI_LeadingMarginSpanDrawInfo OH_ArkUI_LeadingMarginSpanDrawInfo;
 
/**
 * @brief Create an <b>OH_ArkUI_LeadingMarginSpanDrawInfo</b> object.
 *
 * @note When the object is no longer in use, invoke <b> OH_ArkUI_LeadingMarginSpanDrawInfo_Destroy </b> to destroy it.
 * @return Pointer to the <b>OH_ArkUI_LeadingMarginSpanDrawInfo</b> object.
 * @since 24
 */
OH_ArkUI_LeadingMarginSpanDrawInfo* OH_ArkUI_LeadingMarginSpanDrawInfo_Create()
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Release the memory occupied by the <b>OH_ArkUI_LeadingMarginSpanDrawInfo</b> object.
 *
 * @param drawInfo Pointer to the <b>OH_ArkUI_LeadingMarginSpanDrawInfo</b> object.
 * @since 24
 */
void OH_ArkUI_LeadingMarginSpanDrawInfo_Destroy(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set the x offset of the line with leading margin span draw info.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param drawInfo Pointer to the <b>OH_ArkUI_LeadingMarginSpanDrawInfo</b> object.
 * @param x The x offset of the line.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetX(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, float x)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get the x offset of the line with leading margin span draw info.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param drawInfo Pointer to the <b>OH_ArkUI_LeadingMarginSpanDrawInfo</b> object.
 * @param x The x offset of the line.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetX(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, float* x)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set the top position of the line with leading margin span draw info.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param drawInfo Pointer to the <b>OH_ArkUI_LeadingMarginSpanDrawInfo</b> object.
 * @param top The top position of the line.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetTop(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, float top)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get the top position of the line with leading margin span draw info.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param drawInfo Pointer to the <b>OH_ArkUI_LeadingMarginSpanDrawInfo</b> object.
 * @param top The top position of the line.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetTop(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo,
    float* top)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set the bottom position of the line with leading margin span draw info.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param drawInfo Pointer to the <b>OH_ArkUI_LeadingMarginSpanDrawInfo</b> object.
 * @param bottom The bottom position of the line.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetBottom(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo,
    float bottom)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get the bottom position of the line with leading margin span draw info.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param drawInfo Pointer to the <b>OH_ArkUI_LeadingMarginSpanDrawInfo</b> object.
 * @param bottom The bottom position of the line.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetBottom(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo,
    float* bottom)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set the baseline offset of the line with leading margin span draw info.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param drawInfo Pointer to the <b>OH_ArkUI_LeadingMarginSpanDrawInfo</b> object.
 * @param baseline The baseline offset of the line.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetBaseline(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo,
    float baseline)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get the baseline offset of the line with leading margin span draw info.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param drawInfo Pointer to the <b>OH_ArkUI_LeadingMarginSpanDrawInfo</b> object.
 * @param baseline The baseline offset of the line.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetBaseline(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo,
    float* baseline)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set the direction of text with leading margin span draw info.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param drawInfo Pointer to the <b>OH_ArkUI_LeadingMarginSpanDrawInfo</b> object.
 * @param direction The direction of text.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetTextDirection(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo,
    ArkUI_TextDirection direction)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get the direction of text with leading margin span draw info.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param drawInfo Pointer to the <b>OH_ArkUI_LeadingMarginSpanDrawInfo</b> object.
 * @param direction The direction of text.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetTextDirection(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo,
    ArkUI_TextDirection* direction)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set start index of the first character in the current line relative to the component text content.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param drawInfo Pointer to the <b>OH_ArkUI_LeadingMarginSpanDrawInfo</b> object.
 * @param start The start index.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetStart(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo,
    uint32_t start)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get start index of the first character in the current line relative to the component text content.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param drawInfo Pointer to the <b>OH_ArkUI_LeadingMarginSpanDrawInfo</b> object.
 * @param start The start index.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetStart(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo,
    uint32_t* start)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set end index of the last character in the current line relative to the component text content.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param drawInfo Pointer to the <b>OH_ArkUI_LeadingMarginSpanDrawInfo</b> object.
 * @param end The end index.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetEnd(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, uint32_t end)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get end index of the last character in the current line relative to the component text content.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param drawInfo Pointer to the <b>OH_ArkUI_LeadingMarginSpanDrawInfo</b> object.
 * @param end The end index.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetEnd(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo,
    uint32_t* end)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set whether current line is first line of a paragraph.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param drawInfo Pointer to the <b>OH_ArkUI_LeadingMarginSpanDrawInfo</b> object.
 * @param first Whether current line is first line of a paragraph.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetFirst(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, bool first)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get whether current line is first line of a paragraph.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param drawInfo Pointer to the <b>OH_ArkUI_LeadingMarginSpanDrawInfo</b> object.
 * @param first Whether current line is first line of a paragraph.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetFirst(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo,
    bool* first)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Create an <b>OH_ArkUI_ParagraphStyle</b> object.
 *
 * @note When the object is no longer in use, invoke <b> OH_ArkUI_ParagraphStyle_Destroy </b> to destroy it.
 * @return Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @since 24
 */
OH_ArkUI_ParagraphStyle* OH_ArkUI_ParagraphStyle_Create() __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Release the memory occupied by the <b>OH_ArkUI_ParagraphStyle</b> object.
 *
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @since 24
 */
void OH_ArkUI_ParagraphStyle_Destroy(OH_ArkUI_ParagraphStyle* paragraphStyle)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set text align of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param align The text align of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetTextAlign(OH_ArkUI_ParagraphStyle* paragraphStyle,
    ArkUI_TextAlignment align)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get text align of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param align The text align of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetTextAlign(const OH_ArkUI_ParagraphStyle* paragraphStyle,
    ArkUI_TextAlignment* align)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set text indent of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param textIndent The text indent of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetTextIndent(OH_ArkUI_ParagraphStyle* paragraphStyle, float textIndent)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get text indent of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param textIndent The text indent of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetTextIndent(const OH_ArkUI_ParagraphStyle* paragraphStyle, float* textIndent)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set max lines of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param maxLines The max lines of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetMaxLines(OH_ArkUI_ParagraphStyle* paragraphStyle, int32_t maxLines)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get max lines of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param maxLines The max lines of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetMaxLines(const OH_ArkUI_ParagraphStyle* paragraphStyle, int32_t* maxLines)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set overflow of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param overflow The overflow of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetOverflow(OH_ArkUI_ParagraphStyle* paragraphStyle,
    ArkUI_TextOverflow overflow)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get overflow of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param overflow The overflow of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetOverflow(const OH_ArkUI_ParagraphStyle* paragraphStyle,
    ArkUI_TextOverflow* overflow)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set word break of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param wordBreak The word break of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetWordBreak(OH_ArkUI_ParagraphStyle* paragraphStyle,
    ArkUI_WordBreak wordBreak)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get word break of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param wordBreak The word break of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetWordBreak(const OH_ArkUI_ParagraphStyle* paragraphStyle,
    ArkUI_WordBreak* wordBreak)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set leading margin pixelmap of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param pixelmap The leading margin pixelmap of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetLeadingMarginPixelMap(OH_ArkUI_ParagraphStyle* paragraphStyle,
    struct OH_PixelmapNative* pixelmap)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get leading margin pixelmap of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param pixelmap The leading margin pixelmap of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetLeadingMarginPixelMap(const OH_ArkUI_ParagraphStyle* paragraphStyle,
    struct OH_PixelmapNative** pixelmap)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set leading margin width of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param width The leading margin width of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetLeadingMarginWidth(OH_ArkUI_ParagraphStyle* paragraphStyle, uint32_t width)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get leading margin width of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param width The leading margin width of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetLeadingMarginWidth(const OH_ArkUI_ParagraphStyle* paragraphStyle,
    uint32_t* width)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set leading margin height of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param height The leading margin height of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetLeadingMarginHeight(OH_ArkUI_ParagraphStyle* paragraphStyle,
    uint32_t height)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get leading margin height of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param height The leading margin height of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetLeadingMarginHeight(const OH_ArkUI_ParagraphStyle* paragraphStyle,
    uint32_t* height)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set paragraph spacing of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param paragraphSpacing The paragraph spacing of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetParagraphSpacing(OH_ArkUI_ParagraphStyle* paragraphStyle,
    uint32_t paragraphSpacing)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get paragraph spacing of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param paragraphSpacing The paragraph spacing of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetParagraphSpacing(const OH_ArkUI_ParagraphStyle* paragraphStyle,
    uint32_t* paragraphSpacing)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set text vertical align of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param verticalAlignment The text vertical align of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetTextVerticalAlign(OH_ArkUI_ParagraphStyle* paragraphStyle,
    ArkUI_TextVerticalAlignment verticalAlignment)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get text vertical align of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param verticalAlignment The text vertical align of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetTextVerticalAlign(const OH_ArkUI_ParagraphStyle* paragraphStyle,
    ArkUI_TextVerticalAlignment* verticalAlignment)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set a callback function for drawing leading margin.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param onDraw The callback function for drawing leading margin.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_RegisterOnDrawLeadingMarginCallback(OH_ArkUI_ParagraphStyle* paragraphStyle,
    void(*onDraw)(ArkUI_DrawContext* context, OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo))
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Register a callback function for obtaining the indentation distance of a text paragraph.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param leadingMargin The callback function for obtaining the indentation distance of a text paragraph.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_RegisterOnGetLeadingMarginCallback(OH_ArkUI_ParagraphStyle* paragraphStyle,
    float(*leadingMargin)())
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set text direction of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param textDirection The text direction of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetTextDirection(OH_ArkUI_ParagraphStyle* paragraphStyle,
    ArkUI_TextDirection textDirection)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get text direction of paragraph style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param paragraphStyle Pointer to the <b>OH_ArkUI_ParagraphStyle</b> object.
 * @param textDirection The text direction of paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetTextDirection(const OH_ArkUI_ParagraphStyle* paragraphStyle,
    ArkUI_TextDirection* textDirection)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Create an <b>OH_ArkUI_GestureStyle</b> object.
 *
 * @note When the object is no longer in use, invoke <b> OH_ArkUI_GestureStyle_Destroy </b> to destroy it.
 * @return Pointer to the <b>OH_ArkUI_GestureStyle</b> object.
 * @since 24
 */
OH_ArkUI_GestureStyle* OH_ArkUI_GestureStyle_Create() __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Release the memory occupied by the <b>OH_ArkUI_GestureStyle</b> object.
 *
 * @param gestureStyle Pointer to the <b>OH_ArkUI_GestureStyle</b> object.
 * @since 24
 */
void OH_ArkUI_GestureStyle_Destroy(OH_ArkUI_GestureStyle* gestureStyle)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set click callback of gesture style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param gestureStyle Pointer to the <b>OH_ArkUI_GestureStyle</b> object.
 * @param onClick The callback of click event.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_GestureStyle_RegisterOnClickCallback(
    OH_ArkUI_GestureStyle* gestureStyle, void(*onClick)(ArkUI_NodeEvent*))
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set long press callback of gesture style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param gestureStyle Pointer to the <b>OH_ArkUI_GestureStyle</b> object.
 * @param onLongPress The callback of long press event.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_GestureStyle_RegisterOnLongPressCallback(
    OH_ArkUI_GestureStyle* gestureStyle, void(*onLongPress)(ArkUI_GestureEvent*))
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set touch callback of gesture style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param gestureStyle Pointer to the <b>OH_ArkUI_GestureStyle</b> object.
 * @param onTouch The callback of touch event.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_GestureStyle_RegisterOnTouchCallback(
    OH_ArkUI_GestureStyle* gestureStyle, void(*onTouch)(ArkUI_NodeEvent*))
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Create an <b>OH_ArkUI_TextShadowStyle</b> object.
 *
 * @note When the object is no longer in use, invoke <b> OH_ArkUI_TextShadowStyle_Destroy </b> to destroy it.
 * @return Pointer to the <b>OH_ArkUI_TextShadowStyle</b> object.
 * @since 24
 */
OH_ArkUI_TextShadowStyle* OH_ArkUI_TextShadowStyle_Create() __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Release the memory occupied by the <b>OH_ArkUI_TextShadowStyle</b> object.
 *
 * @param textShadowStyle Pointer to the <b>OH_ArkUI_TextShadowStyle</b> object.
 * @since 24
 */
void OH_ArkUI_TextShadowStyle_Destroy(OH_ArkUI_TextShadowStyle* textShadowStyle)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set text shadow options of text shadow style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param textShadowStyle Pointer to the <b>OH_ArkUI_TextShadowStyle</b> object.
 * @param options The text shadow options.
 * @param length The length of text shadow options.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextShadowStyle_SetTextShadow(OH_ArkUI_TextShadowStyle* textShadowStyle,
    const OH_ArkUI_ShadowOptions** options, uint32_t length)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get text shadow options of text shadow style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param textShadowStyle Pointer to the <b>OH_ArkUI_TextShadowStyle</b> object.
 * @param shadowOptions The text shadow options.
 * @param shadowOptionsSize The size of text shadow options.
 * @param writeLength The real size of text shadow options in text shadow style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 *         Returns {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} If the buffer size is less than the minimum buffer size.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextShadowStyle_GetTextShadow(const OH_ArkUI_TextShadowStyle* textShadowStyle,
    OH_ArkUI_ShadowOptions** shadowOptions, uint32_t shadowOptionsSize, uint32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Create an <b>OH_ArkUI_DecorationStyle</b> object.
 *
 * @note When the object is no longer in use, invoke <b> OH_ArkUI_DecorationStyle_Destroy </b> to destroy it.
 * @return Pointer to the <b>OH_ArkUI_DecorationStyle</b> object.
 * @since 24
 */
OH_ArkUI_DecorationStyle* OH_ArkUI_DecorationStyle_Create() __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Release the memory occupied by the <b>OH_ArkUI_DecorationStyle</b> object.
 *
 * @param decorationStyle Pointer to the <b>OH_ArkUI_DecorationStyle</b> object.
 * @since 24
 */
void OH_ArkUI_DecorationStyle_Destroy(OH_ArkUI_DecorationStyle* decorationStyle)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set the decoration type of decoration style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param decorationStyle Pointer to the <b>OH_ArkUI_DecorationStyle</b> object.
 * @param type The decoration type {@link ArkUI_TextDecorationType}.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_DecorationStyle_SetTextDecorationType(OH_ArkUI_DecorationStyle* decorationStyle,
    ArkUI_TextDecorationType type)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get the decoration type of decoration style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param decorationStyle Pointer to the <b>OH_ArkUI_DecorationStyle</b> object.
 * @param type The decoration type {@link ArkUI_TextDecorationType}.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_DecorationStyle_GetTextDecorationType(const OH_ArkUI_DecorationStyle* decorationStyle,
    ArkUI_TextDecorationType* type)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set the color of decoration line.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param decorationStyle Pointer to the <b>OH_ArkUI_DecorationStyle</b> object.
 * @param color Color of decoration line.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_DecorationStyle_SetColor(OH_ArkUI_DecorationStyle* decorationStyle, uint32_t color)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get the color of decoration line.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param decorationStyle Pointer to the <b>OH_ArkUI_DecorationStyle</b> object.
 * @param color Color of decoration line.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_DecorationStyle_GetColor(const OH_ArkUI_DecorationStyle* decorationStyle, uint32_t* color)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set the style of decoration line.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param decorationStyle Pointer to the <b>OH_ArkUI_DecorationStyle</b> object.
 * @param style Style of decoration line.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_DecorationStyle_SetTextDecorationStyle(OH_ArkUI_DecorationStyle* decorationStyle,
    ArkUI_TextDecorationStyle style)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get the style of decoration line.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param decorationStyle Pointer to the <b>OH_ArkUI_DecorationStyle</b> object.
 * @param style Style of decoration line.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_DecorationStyle_GetTextDecorationStyle(const OH_ArkUI_DecorationStyle* decorationStyle,
    ArkUI_TextDecorationStyle* style)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set the thickness scale of decoration line.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param decorationStyle Pointer to the <b>OH_ArkUI_DecorationStyle</b> object.
 * @param thicknessScale Thickness of decoration line.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_DecorationStyle_SetThicknessScale(OH_ArkUI_DecorationStyle* decorationStyle,
    float thicknessScale)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get the thickness scale of decoration line.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param decorationStyle Pointer to the <b>OH_ArkUI_DecorationStyle</b> object.
 * @param thicknessScale Thickness of decoration line.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_DecorationStyle_GetThicknessScale(const OH_ArkUI_DecorationStyle* decorationStyle,
    float* thicknessScale)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set the enable flag about multiple type in decoration line.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param decorationStyle Pointer to the <b>OH_ArkUI_DecorationStyle</b> object.
 * @param enableMultiType The enable flag about multiple type.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_DecorationStyle_SetEnableMultiType(
    OH_ArkUI_DecorationStyle* decorationStyle, bool enableMultiType)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get the enable flag about multiple type in decoration line.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param decorationStyle Pointer to the <b>OH_ArkUI_DecorationStyle</b> object.
 * @param enableMultiType The enable flag about multiple type.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_DecorationStyle_GetEnableMultiType(
    const OH_ArkUI_DecorationStyle* decorationStyle, bool* enableMultiType)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Create an <b>OH_ArkUI_BaselineOffsetStyle</b> object.
 *
 * @note When the object is no longer in use, invoke <b> OH_ArkUI_BaselineOffsetStyle_Destroy </b> to destroy it.
 * @return Pointer to the <b>OH_ArkUI_BaselineOffsetStyle</b> object.
 * @since 24
 */
OH_ArkUI_BaselineOffsetStyle* OH_ArkUI_BaselineOffsetStyle_Create()
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Release the memory occupied by the <b>OH_ArkUI_BaselineOffsetStyle</b> object.
 *
 * @param baselineOffsetStyle Pointer to the <b>OH_ArkUI_BaselineOffsetStyle</b> object.
 * @since 24
 */
void OH_ArkUI_BaselineOffsetStyle_Destroy(OH_ArkUI_BaselineOffsetStyle* baselineOffsetStyle)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set baseline offset of the baseline offset style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param baselineOffsetStyle Pointer to the <b>OH_ArkUI_BaselineOffsetStyle</b> object.
 * @param baselineOffset The baseline offset.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_BaselineOffsetStyle_SetBaselineOffset(
    OH_ArkUI_BaselineOffsetStyle* baselineOffsetStyle, float baselineOffset)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get baseline offset of the baseline offset style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param baselineOffsetStyle Pointer to the <b>OH_ArkUI_BaselineOffsetStyle</b> object.
 * @param baselineOffset The baseline offset.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_BaselineOffsetStyle_GetBaselineOffset(
    const OH_ArkUI_BaselineOffsetStyle* baselineOffsetStyle, float* baselineOffset)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Create an <b>OH_ArkUI_LetterSpacingStyle</b> object.
 *
 * @note When the object is no longer in use, invoke <b> OH_ArkUI_LetterSpacingStyle_Destroy </b> to destroy it.
 * @return Pointer to the <b>OH_ArkUI_LetterSpacingStyle</b> object.
 * @since 24
 */
OH_ArkUI_LetterSpacingStyle* OH_ArkUI_LetterSpacingStyle_Create()
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Release the memory occupied by the <b>OH_ArkUI_LetterSpacingStyle</b> object.
 *
 * @param letterSpacingStyle Pointer to the <b>OH_ArkUI_LetterSpacingStyle</b> object.
 * @since 24
 */
void OH_ArkUI_LetterSpacingStyle_Destroy(OH_ArkUI_LetterSpacingStyle* letterSpacingStyle)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set letter spacing of the letter spacing style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param letterSpacingStyle Pointer to the <b>OH_ArkUI_LetterSpacingStyle</b> object.
 * @param letterSpacing The letter spacing.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_LetterSpacingStyle_SetLetterSpacing(
    OH_ArkUI_LetterSpacingStyle* letterSpacingStyle, float letterSpacing)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get letter spacing of the letter spacing style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param letterSpacingStyle Pointer to the <b>OH_ArkUI_LetterSpacingStyle</b> object.
 * @param letterSpacing The letter spacing.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_LetterSpacingStyle_GetLetterSpacing(
    const OH_ArkUI_LetterSpacingStyle* letterSpacingStyle, float* letterSpacing)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Create an <b>OH_ArkUI_LineHeightStyle</b> object.
 *
 * @note When the object is no longer in use, invoke <b> OH_ArkUI_LineHeightStyle_Destroy </b> to destroy it.
 * @return Pointer to the <b>OH_ArkUI_LineHeightStyle</b> object.
 * @since 24
 */
OH_ArkUI_LineHeightStyle* OH_ArkUI_LineHeightStyle_Create() __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Release the memory occupied by the <b>OH_ArkUI_LineHeightStyle</b> object.
 *
 * @param lineHeightStyle Pointer to the <b>OH_ArkUI_LineHeightStyle</b> object.
 * @since 24
 */
void OH_ArkUI_LineHeightStyle_Destroy(OH_ArkUI_LineHeightStyle* lineHeightStyle)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set line height of the line height style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param lineHeightStyle Pointer to the <b>OH_ArkUI_LineHeightStyle</b> object.
 * @param lineHeight The line height.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_LineHeightStyle_SetLineHeight(OH_ArkUI_LineHeightStyle* lineHeightStyle,
    float lineHeight)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get line height of the line height style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param lineHeightStyle Pointer to the <b>OH_ArkUI_LineHeightStyle</b> object.
 * @param lineHeight The line height.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_LineHeightStyle_GetLineHeight(const OH_ArkUI_LineHeightStyle* lineHeightStyle,
    float* lineHeight)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Create a <b>OH_ArkUI_BackgroundColorStyle</b> object.
 *
 * @note When the object is no longer in use, invoke <b> OH_ArkUI_BackgroundColorStyle_Destroy </b> to destroy it.
 * @return Pointer to the <b>OH_ArkUI_BackgroundColorStyle</b> object.
 * @since 24
 */
OH_ArkUI_BackgroundColorStyle* OH_ArkUI_BackgroundColorStyle_Create()
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Release the memory occupied by the <b>OH_ArkUI_BackgroundColorStyle</b> object.
 *
 * @param style Pointer to the <b>OH_ArkUI_BackgroundColorStyle</b> object.
 * @since 24
 */
void OH_ArkUI_BackgroundColorStyle_Destroy(OH_ArkUI_BackgroundColorStyle* style)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set color of the background color style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param style Pointer to the <b>OH_ArkUI_BackgroundColorStyle</b> object.
 * @param color The background color.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_BackgroundColorStyle_SetColor(OH_ArkUI_BackgroundColorStyle* style, uint32_t color)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get color of the background color style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param style Pointer to the <b>OH_ArkUI_BackgroundColorStyle</b> object.
 * @param color The background color.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_BackgroundColorStyle_GetColor(const OH_ArkUI_BackgroundColorStyle* style, uint32_t* color)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set radius of the background color style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param style Pointer to the <b>OH_ArkUI_BackgroundColorStyle</b> object.
 * @param topLeft The top left radius.
 * @param topRight The top right radius.
 * @param bottomLeft The bottom left radius.
 * @param bottomRight The bottom right radius.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_BackgroundColorStyle_SetRadius(OH_ArkUI_BackgroundColorStyle* style, float topLeft,
    float topRight, float bottomLeft, float bottomRight)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get radius of the background color style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param style Pointer to the <b>OH_ArkUI_BackgroundColorStyle</b> object.
 * @param topLeft The top left radius.
 * @param topRight The top right radius.
 * @param bottomLeft The bottom left radius.
 * @param bottomRight The bottom right radius.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_BackgroundColorStyle_GetRadius(const OH_ArkUI_BackgroundColorStyle* style, float* topLeft,
    float* topRight, float* bottomLeft, float* bottomRight)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Create an <b>OH_ArkUI_UrlStyle</b> object.
 *
 * @note When the object is no longer in use, invoke <b> OH_ArkUI_UrlStyle_Destroy </b> to destroy it.
 * @return Pointer to the <b>OH_ArkUI_UrlStyle</b> object.
 * @since 24
 */
OH_ArkUI_UrlStyle* OH_ArkUI_UrlStyle_Create() __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Release the memory occupied by the ArkUI_UrlStyle object.
 *
 * @param style Pointer to the <b>OH_ArkUI_UrlStyle</b> object.
 * @since 24
 */
void OH_ArkUI_UrlStyle_Destroy(OH_ArkUI_UrlStyle* style) __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set url of the url style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param style Pointer to the <b>OH_ArkUI_UrlStyle</b> object.
 * @param url The url.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_UrlStyle_SetUrl(OH_ArkUI_UrlStyle* style, const char* url)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get url of the url style.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param style Pointer to the <b>OH_ArkUI_UrlStyle</b> object.
 * @param buffer The buffer to which url content writes to the memory,
 *               memory space needs to be allocated by the developer.
 * @param bufferSize The buffer size.
 * @param writeLength Indicates the string length actually written to the buffer
 *                    when returning {@link ARKUI_ERROR_CODE_NO_ERROR}.
 *                    Indicates the minimum buffer size that can accommodate the target
 *                    when {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} is returned.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 *         Returns {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} If the buffer size is less than the minimum buffer size.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_UrlStyle_GetUrl(const OH_ArkUI_UrlStyle* style, char* buffer, int32_t bufferSize,
    int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Create an <b>OH_ArkUI_UserDataSpan</b> object.
 *
 * @note When the object is no longer in use, invoke <b> OH_ArkUI_UserDataSpan_Destroy </b> to destroy it.
 * @return Pointer to the <b>OH_ArkUI_UserDataSpan</b> object.
 * @since 24
 */
OH_ArkUI_UserDataSpan* OH_ArkUI_UserDataSpan_Create() __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Release the memory occupied by the <b>OH_ArkUI_UserDataSpan</b> object.
 *
 * @param userDataSpan Pointer to the <b>OH_ArkUI_UserDataSpan</b> object.
 * @since 24
 */
void OH_ArkUI_UserDataSpan_Destroy(OH_ArkUI_UserDataSpan* userDataSpan)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set user data of the user data span.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param userDataSpan Pointer to the <b>OH_ArkUI_UserDataSpan</b> object.
 * @param userData The user data.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_UserDataSpan_SetUserData(OH_ArkUI_UserDataSpan* userDataSpan, void* userData)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get user data of the user data span.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param userDataSpan Pointer to the <b>OH_ArkUI_UserDataSpan</b> object.
 * @param userData The user data.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_UserDataSpan_GetUserData(const OH_ArkUI_UserDataSpan* userDataSpan, void** userData)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Create an <b>OH_ArkUI_CustomSpan</b> object.
 *
 * @note When the object is no longer in use, invoke <b> OH_ArkUI_CustomSpan_Destroy </b> to destroy it.
 * @return Pointer to the <b>OH_ArkUI_CustomSpan</b> object.
 * @since 24
 */
OH_ArkUI_CustomSpan* OH_ArkUI_CustomSpan_Create() __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Release the memory occupied by the <b>OH_ArkUI_CustomSpan</b> object.
 *
 * @param customSpan Pointer to the <b>OH_ArkUI_CustomSpan</b> object.
 * @since 24
 */
void OH_ArkUI_CustomSpan_Destroy(OH_ArkUI_CustomSpan* customSpan)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief register measure callback of the custom span.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param customSpan Pointer to the <b>OH_ArkUI_CustomSpan</b> object.
 * @param onMeasure The callback function for measuring the size of custom span.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_CustomSpan_RegisterOnMeasureCallback(
    OH_ArkUI_CustomSpan* customSpan, ArkUI_CustomSpanMetrics*(*onMeasure)(float))
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief register draw callback of the custom span.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param customSpan Pointer to the <b>OH_ArkUI_CustomSpan</b> object.
 * @param onDraw The callback function for drawing the custom span.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_CustomSpan_RegisterOnDrawCallback(
    OH_ArkUI_CustomSpan* customSpan, void(*onDraw)(ArkUI_DrawContext*, ArkUI_CustomSpanDrawInfo*))
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Create an <b>OH_ArkUI_ImageAttachment</b> object.
 *
 * @note When the object is no longer in use, invoke <b> OH_ArkUI_ImageAttachment_Destroy </b> to destroy it.
 * @return Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @since 24
 */
OH_ArkUI_ImageAttachment* OH_ArkUI_ImageAttachment_Create() __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Release the memory occupied by the <b>OH_ArkUI_ImageAttachment</b> object.
 *
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @since 24
 */
void OH_ArkUI_ImageAttachment_Destroy(OH_ArkUI_ImageAttachment* imageAttachment)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set pixelmap of the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param pixelmap The pixelmap of the image attachment.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetPixelMap(OH_ArkUI_ImageAttachment* imageAttachment,
    struct OH_PixelmapNative* pixelmap)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get pixelmap of the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param pixelmap The pixelmap of the image attachment.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetPixelMap(const OH_ArkUI_ImageAttachment* imageAttachment,
    struct OH_PixelmapNative** pixelmap)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set string about image src in the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param resource The string about image src in the image attachment.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetResource(OH_ArkUI_ImageAttachment* imageAttachment, const char* resource)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get string about image src in the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param buffer The buffer to which string about image src writes to the memory,
 *               memory space needs to be allocated by the developer.
 * @param bufferSize The buffer size
 * @param writeLength Indicates the string length actually written to the buffer
 *                    when returning {@link ARKUI_ERROR_CODE_NO_ERROR}.
 *                    Indicates the minimum buffer size that can accommodate the target
 *                    when {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} is returned.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 *         Returns {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} If the buffer size is less than the minimum buffer size.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetResource(const OH_ArkUI_ImageAttachment* imageAttachment,
    char* buffer, int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set image width of the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param width The image width of the image attachment.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetSizeWidth(OH_ArkUI_ImageAttachment* imageAttachment, float width)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get image width of the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param width The image width of the image attachment.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetSizeWidth(const OH_ArkUI_ImageAttachment* imageAttachment, float* width)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set image height of the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param height The image height of the image attachment.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetSizeHeight(OH_ArkUI_ImageAttachment* imageAttachment, float height)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get image height of the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param height The image height of the image attachment.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetSizeHeight(const OH_ArkUI_ImageAttachment* imageAttachment, float* height)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set image alignment of the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param verticalAlign The image alignment of the image attachment.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetVerticalAlign(
    OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_ImageSpanAlignment verticalAlign)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get image alignment of the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param verticalAlign The image alignment of the image attachment.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetVerticalAlign(const OH_ArkUI_ImageAttachment* imageAttachment,
    ArkUI_ImageSpanAlignment* verticalAlign)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set image object fit of the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param objectFit The image object fit of the image attachment.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetObjectFit(
    OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_ObjectFit objectFit)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get image object fit of the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param objectFit The image object fit of the image attachment.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetObjectFit(
    const OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_ObjectFit* objectFit)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set image margin of the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param margin The image margin of the image attachment.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetMargin(OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_Margin margin)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get image margin of the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param margin The image margin of the image attachment.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetMargin(const OH_ArkUI_ImageAttachment* imageAttachment,
    ArkUI_Margin* margin)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set image padding of the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param padding The image padding of the image attachment.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetPadding(OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_Margin padding)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get image padding of the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param padding The image padding of the image attachment.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetPadding(const OH_ArkUI_ImageAttachment* imageAttachment,
    ArkUI_Margin* padding)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set image border radius of the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param topLeft The top left radius.
 * @param topRight The top right radius.
 * @param bottomLeft The bottom left radius.
 * @param bottomRight The bottom right radius.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetBorderRadiuses(OH_ArkUI_ImageAttachment* imageAttachment,
    float topLeft, float topRight, float bottomLeft, float bottomRight)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get image border radius of the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param topLeft The top left radius.
 * @param topRight The top right radius.
 * @param bottomLeft The bottom left radius.
 * @param bottomRight The bottom right radius.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetBorderRadiuses(const OH_ArkUI_ImageAttachment* imageAttachment,
    float* topLeft, float* topRight, float* bottomLeft, float* bottomRight)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set image colorFilter of the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param colorFilter The image colorFilter.
 * @param size The size of colorFilter.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetColorFilter(
    OH_ArkUI_ImageAttachment* imageAttachment, const float* colorFilter, uint32_t size)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get image colorFilter of the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param colorFilter The image colorFilter.
 * @param colorFilterSize The size of colorFilter.
 * @param writeLength the real size of colorFilter in the image attachment.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 *         Returns {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} If the buffer size is less than the minimum buffer size.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetColorFilter(const OH_ArkUI_ImageAttachment* imageAttachment,
    float** colorFilter, uint32_t colorFilterSize, uint32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set image colorFilter of the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param drawingColorFilter The image colorFilter.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetDrawingColorFilter(
    OH_ArkUI_ImageAttachment* imageAttachment, const OH_Drawing_ColorFilter* drawingColorFilter)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get image colorFilter of the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param drawingColorFilter The image colorFilter.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetDrawingColorFilter(
    const OH_ArkUI_ImageAttachment* imageAttachment, OH_Drawing_ColorFilter* drawingColorFilter)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set the flag about image sync load in the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param syncLoad The flag about image sync load.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetSyncLoad(OH_ArkUI_ImageAttachment* imageAttachment, bool syncLoad)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get the flag about image sync load in the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param syncLoad The flag about image sync load.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetSyncLoad(const OH_ArkUI_ImageAttachment* imageAttachment, bool* syncLoad)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Set the flag about image support svg in the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param supportSvg The flag about image support svg.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetSupportSvg(OH_ArkUI_ImageAttachment* imageAttachment, bool supportSvg)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Get the flag about image support svg in the image attachment.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param imageAttachment Pointer to the <b>OH_ArkUI_ImageAttachment</b> object.
 * @param supportSvg The flag about image support svg.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetSupportSvg(const OH_ArkUI_ImageAttachment* imageAttachment,
    bool* supportSvg)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Obtains the range of content that will be replaced.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param event Pointer to an <b>OH_ArkUI_TextEditorChangeEvent</b> object.
 * @param start Range start offset.
 * @param end Range end offset.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function params is invalid.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorChangeEvent_GetRangeBefore(const OH_ArkUI_TextEditorChangeEvent* event,
    uint32_t* start, uint32_t* end)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Obtains the styled string used for replacement.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param event Pointer to an <b>OH_ArkUI_TextEditorChangeEvent</b> object.
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function params is invalid.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorChangeEvent_GetReplacementStyledString(
    const OH_ArkUI_TextEditorChangeEvent* event, ArkUI_StyledString_Descriptor* descriptor)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Obtains the preview styled string.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param event Pointer to an <b>OH_ArkUI_TextEditorChangeEvent</b> object.
 * @param descriptor Pointer to an <b>ArkUI_StyledString_Descriptor</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} Function params is invalid.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorChangeEvent_GetPreviewStyledString(
    const OH_ArkUI_TextEditorChangeEvent* event, ArkUI_StyledString_Descriptor* descriptor)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Defines the layout manager of text.
 *
 * @since 22
 */
typedef struct ArkUI_TextLayoutManager ArkUI_TextLayoutManager;

/**
 * @brief Dispose an object of the text layout manager.
 *
 * @param layoutManager Pointer to the ArkUI_TextLayoutManager object to be disposed.
 * @since 22
 */
void OH_ArkUI_TextLayoutManager_Dispose(ArkUI_TextLayoutManager* layoutManager)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Gets the line count.
 *
 * @param layoutManager Indicates the pointer to an <b>ArkUI_TextLayoutManager</b> object.
 * @param outLineCount Returns the line count.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetLineCount(ArkUI_TextLayoutManager* layoutManager, int32_t* outLineCount)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Gets the rects for range.
 *
 * @param layoutManager Indicates the pointer to an <b>ArkUI_TextLayoutManager</b> object.
 * @param start Indicates the start of range to set.
 * @param end Indicates the end of range to set.
 * @param widthStyle Indicates the width style to set.
 *     For details, see the enum <b>OH_Drawing_RectWidthStyle</b>.
 * @param heightStyle Indicates the height style to set.
 *     For details, see the enum <b>OH_Drawing_RectHeightStyle</b>.
 * @param outTextBoxes Returns the array of rects for range.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetRectsForRange(ArkUI_TextLayoutManager* layoutManager,
    int32_t start, int32_t end, OH_Drawing_RectWidthStyle widthStyle, OH_Drawing_RectHeightStyle heightStyle,
    OH_Drawing_TextBox** outTextBoxes)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Gets the glyph position at coordinate.
 *
 * @param layoutManager Indicates the pointer to an <b>ArkUI_TextLayoutManager</b> object.
 * @param dx Indicates the positionX of typography to set.
 * @param dy Indicates the positionY of typography to set.
 * @param outPos Returns the glyph position at coordinate.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetGlyphPositionAtCoordinate(
    ArkUI_TextLayoutManager* layoutManager, double dx, double dy, OH_Drawing_PositionAndAffinity** outPos)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Get line metrics information.
 *
 * @param layoutManager Indicates the pointer to a typography object <b>ArkUI_TextLayoutManager</b>.
 * @param lineNumber Indicates the number of line.
 * @param outMetrics Indicates the pointer to a line metrics object <b>OH_Drawing_LineMetrics</b>.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetLineMetrics(ArkUI_TextLayoutManager* layoutManager,
    int32_t lineNumber, OH_Drawing_LineMetrics* outMetrics)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Gets the character position at coordinate.
 *
 * @param layoutManager Indicates the pointer to an <b>ArkUI_TextLayoutManager</b> object.
 * @param dx Indicates the positionX of typography to set.
 * @param dy Indicates the positionY of typography to set.
 * @param outPos Returns the character position at coordinate.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetCharacterPositionAtCoordinate(
    ArkUI_TextLayoutManager* layoutManager, double dx, double dy, OH_Drawing_PositionAndAffinity** outPos)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the glyph range produced by the specified range of characters.
 *
 * @param layoutManager Indicates the pointer to an <b>ArkUI_TextLayoutManager</b> object.
 * @param charRange The character range.
 * @param outGlyphRange The range of glyphs generated by charRange.
 * @param outActualCharRange If not null, specifies the actual character range that fully defines the returned
 *      glyph range, which may match or slightly exceed the requested range.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetGlyphRangeForCharacterRange(
    ArkUI_TextLayoutManager* layoutManager, OH_Drawing_Range* charRange,
    OH_Drawing_Range** outGlyphRange, OH_Drawing_Range** outActualCharRange)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the character range that maps to the glyphs in the given glyph range.
 *
 * @param layoutManager Indicates the pointer to an <b>ArkUI_TextLayoutManager</b> object.
 * @param glyphRange The glyph range.
 * @param outCharRange The range of characters generated by glyphRange.
 * @param outActualGlyphRange If not null, specifies the full glyph range generated by the returned character range,
 *      which may match or slightly exceed the requested glyph range.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetCharacterRangeForGlyphRange(
    ArkUI_TextLayoutManager* layoutManager, OH_Drawing_Range* glyphRange,
    OH_Drawing_Range** outCharRange, OH_Drawing_Range** outActualGlyphRange)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

#ifdef __cplusplus
};
#endif

#endif // ARKUI_NATIVE_STYLED_STRING_H
/** @} */
