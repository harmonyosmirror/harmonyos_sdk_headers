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
 * @brief Provides UI capabilities of ArkUI on the native side, such as UI component creation and destruction,
 * tree node operations, attribute setting, and event listening.
 *
 * @since 12
 */

/**
 * @file native_type.h
 *
 * @brief Defines the common types for the native module.
 *
 * @library libace_ndk.z.so
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @kit ArkUI
 * @since 12
 */

#ifndef ARKUI_NATIVE_TYPE_H
#define ARKUI_NATIVE_TYPE_H

#include "info/application_target_sdk_version.h"
#include <stdint.h>

#include "drawable_descriptor.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines the ArkUI native component object.
 *
 * @since 12
 */
struct ArkUI_Node;

/**
 * @brief Defines the pointer type of the ArkUI node content
 *
 * @since 12
 */
typedef struct ArkUI_NodeContent* ArkUI_NodeContentHandle;

/**
 * @brief Defines the custom dialog box controller of ArkUI on the native side.
 *
 * @since 12
 */
struct ArkUI_NativeDialog;

/**
 * @brief Sets the size constraints of a component during component layout.
 *
 * @since 12
 */
typedef struct ArkUI_LayoutConstraint ArkUI_LayoutConstraint;

/**
 * @brief Defines the structure of the component drawing context.
 *
 * @since 12
 */
typedef struct ArkUI_DrawContext ArkUI_DrawContext;

/**
 * @brief Defines the pointer to the ArkUI native component object.
 *
 * @since 12
 */
typedef struct ArkUI_Node* ArkUI_NodeHandle;

/**
 * @brief Defines the pointer to the custom dialog box controller of ArkUI on the native side.
 *
 * @since 12
 */
typedef struct ArkUI_NativeDialog* ArkUI_NativeDialogHandle;

/**
 * @brief Defines the return value structure for the <b>onGetIrregularSizeByIndex</b> callback
 * in <b>Grid</b> layout options.
 *
 * @since 22
 */
typedef struct {
    /** Number of rows occupied by the <b>GridItem</b> component. */
    uint32_t rowSpan;
    /** Number of columns occupied by the <b>GridItem</b> component. */
    uint32_t columnSpan;
} ArkUI_GridItemSize;

/**
 * @brief Defines the return value structure for the <b>onGetRectByIndex</b> callback in <b>Grid</b> layout options.
 *
 * @since 22
 */
typedef struct {
    /** Starting row position of the <b>GridItem</b> component. */
    uint32_t rowStart;
    /** Starting column position of the <b>GridItem</b> component. */
    uint32_t columnStart;
    /** Number of rows occupied by the <b>GridItem</b> component. */
    uint32_t rowSpan;
    /** Number of columns occupied by the <b>GridItem</b> component. */
    uint32_t columnSpan;
} ArkUI_GridItemRect;

/**
 * @brief Enumerates the selected indicator type of picker.
 *
 * @since 23
 */
typedef enum {
    /** background. */
    ARKUI_PICKER_INDICATOR_BACKGROUND = 0,
    /** divider. */
    ARKUI_PICKER_INDICATOR_DIVIDER = 1,
} ArkUI_PickerIndicatorType;

/**
 * @brief Style parameters of background indicator.
 *
 * @since 23
 */
typedef struct {
    /**  background color, 0xARGB format for example <b>0xFF1122FF</b> */
    uint32_t backgroundColor;
    /** radius of the top left corner. */
    float topLeftRadius;
    /** radius of the top right corner */
    float topRightRadius;
    /** radius of the bottom left corner */
    float bottomLeftRadius;
    /** radius of the bottom right corner. */
    float bottomRightRadius;
} ArkUI_PickerIndicatorBackground;

/**
 * @brief Style parameters of divider indicator.
 *
 * @since 23
 */
typedef struct {
    /** stroke width */
    float strokeWidth;
    /** divider color, 0xARGB format for example <b>0xFF1122FF</b> */
    uint32_t dividerColor;
    /** the distance between the divider and the beginning of the side of the picker (unit: vp). */
    float startMargin;
    /** the distance between the divider and the end of the side of the picker (unit: vp). */
    float endMargin;
} ArkUI_PickerIndicatorDivider;

/**
 * @brief Definition of indicator style.
 *
 * @since 23
 */
typedef struct ArkUI_PickerIndicatorStyle ArkUI_PickerIndicatorStyle;

/**
 * @brief Defines the <b>Grid</b> layout options.
 *
 * @since 22
 */
typedef struct ArkUI_GridLayoutOptions ArkUI_GridLayoutOptions;

/**
 * @brief Defines the water flow section configuration.
 *
 * @since 12
 */
typedef struct ArkUI_WaterFlowSectionOption ArkUI_WaterFlowSectionOption;

/**
 * @brief Define the configuration information of the Item within the ListitemSwipeActionOption method.
 *
 * @since 12
 */
typedef struct ArkUI_ListItemSwipeActionItem ArkUI_ListItemSwipeActionItem;

/**
 * @brief Define the configuration information for the ListitemSwipeActionOption method.
 *
 * @since 12
 */
typedef struct ArkUI_ListItemSwipeActionOption ArkUI_ListItemSwipeActionOption;

/**
 * @brief Defines the ArkUI native context object.
 *
 * @since 12
 */
struct ArkUI_Context;

/**
  * @brief Defines the pointer to the context instance object pointer definition of ArkUI on the native side.
  *
  * @since 12
  */
typedef struct ArkUI_Context* ArkUI_ContextHandle;

/**
 * @brief Defines the navigation indicator style for the swiper.
 *
 * @since 12
 */
typedef struct ArkUI_SwiperIndicator ArkUI_SwiperIndicator;

/**
 * @brief Defines the digital indicator style for the swiper.
 *
 * @since 19
 */
typedef struct ArkUI_SwiperDigitIndicator ArkUI_SwiperDigitIndicator;

/**
 * @brief Defines the arrow style for the swiper.
 *
 * @since 19
 */
typedef struct ArkUI_SwiperArrowStyle ArkUI_SwiperArrowStyle;

/**
* @brief Define the data objects of styled string supported by text components.
*
* @since 14
*/
typedef struct ArkUI_StyledString_Descriptor ArkUI_StyledString_Descriptor;

/**
  * @brief specifies the alignment rules for subcomponents set in relative containers.
  *
  * @since 12
  */
typedef struct ArkUI_AlignmentRuleOption ArkUI_AlignmentRuleOption;

/**
  * @brief guideLine parameters, used to define the id, direction and position of the guideline.
  *
  * @since 12
  */
typedef struct ArkUI_GuidelineOption ArkUI_GuidelineOption;

/**
  * @brief barrier parameter, used to define the id,
  * direction and components of the barrier that it depends on when generating it.
  *
  * @since 12
  */
typedef struct ArkUI_BarrierOption ArkUI_BarrierOption;

/**
 * @brief Define the ChildrenMainSize class information for a List.
 *
 * @since 12
*/
typedef struct ArkUI_ListChildrenMainSize ArkUI_ListChildrenMainSize;

/**
 * @brief Defines the image frame.
 *
 * @since 12
*/
typedef struct ArkUI_ImageAnimatorFrameInfo ArkUI_ImageAnimatorFrameInfo;

/**
 * @brief Defines the accessibility state for the component.
 *
 * @since 12
 */
typedef struct ArkUI_AccessibilityState ArkUI_AccessibilityState;

/**
 * @brief Defines the accessibility value for the component.
 *
 * @since 12
 */
typedef struct ArkUI_AccessibilityValue ArkUI_AccessibilityValue;

/**
 * @brief Define the information of the Custom Property class for custom properties.
 *
 * @since 14
 */
typedef struct ArkUI_CustomProperty ArkUI_CustomProperty;

/**
 * @brief Define the information of the HostWindowInfo class for window properties.
 *
 * @since 15
 */
typedef struct ArkUI_HostWindowInfo ArkUI_HostWindowInfo;

/**
 * @brief Define ActiveChildenInfo class information.
 *
 * @since 14
 */
typedef struct ArkUI_ActiveChildrenInfo ArkUI_ActiveChildrenInfo;

/**
 * @brief Set the linear progress indicator style.
 *
 * @since 15
 */
typedef struct ArkUI_ProgressLinearStyleOption ArkUI_ProgressLinearStyleOption;

/**
 * @brief The cross-language option.
 *
 * @since 15
 */
typedef struct ArkUI_CrossLanguageOption ArkUI_CrossLanguageOption;

/**
 * @brief Declares the Ability base want.
 *
 * @since 20
 */
typedef struct AbilityBase_Want AbilityBase_Want;

/**
 * @brief Define the EmbeddedComponentOption for the EmbeddedComponent.
 *
 * @since 20
 */
typedef struct ArkUI_EmbeddedComponentOption ArkUI_EmbeddedComponentOption;

/**
 * @brief Define the Edges describing the position of a component by distances to the container's four edges.
 *
 * @since 21
 */
typedef struct ArkUI_PositionEdges ArkUI_PositionEdges;

/**
 * @brief Defines the PixelRound policy of a component's four edges.
 *
 * @since 21
 */
typedef struct ArkUI_PixelRoundPolicy ArkUI_PixelRoundPolicy;

/**
 * @brief Defines the textField's counter configuration.
 *
 * @since 22
 */
typedef struct ArkUI_ShowCounterConfig ArkUI_ShowCounterConfig;

/**
 * @brief Defines the matrix4 object.
 *
 * @since 24
 */
typedef struct ArkUI_Matrix4 ArkUI_Matrix4;

/**
 * @brief Defines the text content base controller.
 *
 * @since 23
 */
typedef struct ArkUI_TextContentBaseController ArkUI_TextContentBaseController;

/**
 * @brief Defines the selected drag preview style configuration.
 * @since 23
 */
typedef struct ArkUI_SelectedDragPreviewStyle ArkUI_SelectedDragPreviewStyle;

/**
 * @brief Defines the event callback type.
 *
 * @since 12
 */
typedef struct {
    /** Custom type, data of a user-defined type that is passed as a parameter during callbacks. */
    void* userData;
    /** Event callback. */
    void (*callback)(void* userData);
} ArkUI_ContextCallback;
/**
 * @brief Provides the number types of ArkUI in the native code.
 *
 * @since 12
 */
typedef union {
    /** Floating-point type, used to store a floating-point value. */
    float f32;
    /** Signed integer, used to store a signed integer value. */
    int32_t i32;
    /** Unsigned integer, used to store an unsigned integer value. */
    uint32_t u32;
} ArkUI_NumberValue;

/**
 * @brief Enumerates the alignment modes.
 *
 * @since 12
 */
typedef enum {
    /** Top start. */
    ARKUI_ALIGNMENT_TOP_START = 0,
    /** Top center. */
    ARKUI_ALIGNMENT_TOP,
    /** Top end. */
    ARKUI_ALIGNMENT_TOP_END,
    /** Vertically centered start. */
    ARKUI_ALIGNMENT_START,
    /** Horizontally and vertically centered. */
    ARKUI_ALIGNMENT_CENTER,
    /** Vertically centered end. */
    ARKUI_ALIGNMENT_END,
    /** Bottom start. */
    ARKUI_ALIGNMENT_BOTTOM_START,
    /** Horizontally centered on the bottom. */
    ARKUI_ALIGNMENT_BOTTOM,
    /** Bottom end. */
    ARKUI_ALIGNMENT_BOTTOM_END,
} ArkUI_Alignment;

/**
 * @brief Enumerates the image repeat patterns.
 *
 * @since 12
 */
typedef enum {
    /** The image is not repeatedly drawn. */
    ARKUI_IMAGE_REPEAT_NONE = 0,
    /** The image is repeatedly drawn only along the x-axis. */
    ARKUI_IMAGE_REPEAT_X,
    /** The image is repeatedly drawn only along the y-axis. */
    ARKUI_IMAGE_REPEAT_Y,
    /** The image is repeatedly drawn along both axes. */
    ARKUI_IMAGE_REPEAT_XY,
} ArkUI_ImageRepeat;

/**
 * @brief Enumerates the font styles.
 *
 * @since 12
 */
typedef enum {
    /** Standard font style. */
    ARKUI_FONT_STYLE_NORMAL = 0,
    /** Italic font style. */
    ARKUI_FONT_STYLE_ITALIC
} ArkUI_FontStyle;

/**
 * @brief Enumerates the font weights.
 *
 * @since 12
 */
typedef enum {
    /** 100 */
    ARKUI_FONT_WEIGHT_W100 = 0,
    /** 200 */
    ARKUI_FONT_WEIGHT_W200,
    /** 300 */
    ARKUI_FONT_WEIGHT_W300,
    /** 400 */
    ARKUI_FONT_WEIGHT_W400,
    /** 500 */
    ARKUI_FONT_WEIGHT_W500,
    /** 600 */
    ARKUI_FONT_WEIGHT_W600,
    /** 700 */
    ARKUI_FONT_WEIGHT_W700,
    /** 800 */
    ARKUI_FONT_WEIGHT_W800,
    /** 900 */
    ARKUI_FONT_WEIGHT_W900,
    /** The font weight is bold. */
    ARKUI_FONT_WEIGHT_BOLD,
    /** The font weight is normal. */
    ARKUI_FONT_WEIGHT_NORMAL,
    /** The font weight is bolder. */
    ARKUI_FONT_WEIGHT_BOLDER,
    /** The font weight is lighter. */
    ARKUI_FONT_WEIGHT_LIGHTER,
    /** The font weight is medium. */
    ARKUI_FONT_WEIGHT_MEDIUM,
    /** The font weight is normal. */
    ARKUI_FONT_WEIGHT_REGULAR,
} ArkUI_FontWeight;

/**
 * @brief Enumerates the text alignment mode.
 *
 * @since 12
 */
typedef enum {
    /** Aligned with the start. */
    ARKUI_TEXT_ALIGNMENT_START = 0,
    /** Horizontally centered. */
    ARKUI_TEXT_ALIGNMENT_CENTER,
    /** Aligned with the end. */
    ARKUI_TEXT_ALIGNMENT_END,
    /** Aligned with both margins. */
    ARKUI_TEXT_ALIGNMENT_JUSTIFY,
    /** Aligned with left to right.
     * @since 23
     */
    ARKUI_TEXT_ALIGNMENT_LEFT_TO_RIGHT = 4,
    /** Aligned with right to left.
     * @since 23
     */
    ARKUI_TEXT_ALIGNMENT_RIGHT_TO_LEFT = 5,
} ArkUI_TextAlignment;

/**
 * @brief Enumerates text vertical alignment styles.
 *
 * @since 20
 */
typedef enum {
    /** Aligned to the baseline. */
    ARKUI_TEXT_VERTICAL_ALIGNMENT_BASELINE = 0,
    /** Bottom aligned. */
    ARKUI_TEXT_VERTICAL_ALIGNMENT_BOTTOM,
    /** Center aligned. */
    ARKUI_TEXT_VERTICAL_ALIGNMENT_CENTER,
    /** Top aligned. */
    ARKUI_TEXT_VERTICAL_ALIGNMENT_TOP,
} ArkUI_TextVerticalAlignment;

/**
 * @brief Enumerates text content align styles.
 *
 * @since 21
 */
typedef enum {
    /** Top aligned. */
    ARKUI_TEXT_CONTENT_ALIGN_TOP = 0,
    /** Center aligned. */
    ARKUI_TEXT_CONTENT_ALIGN_CENTER = 1,
    /** Bottom aligned. */
    ARKUI_TEXT_CONTENT_ALIGN_BOTTOM = 2,
} ArkUI_TextContentAlign;

/**
 * @brief Enumerates the text text direction.
 *
 * @since 23
 */
typedef enum {
    /** The text direction is left to right. */
    ARKUI_TEXT_DIRECTION_LTR = 0,
    /** The text direction is right to left. */
    ARKUI_TEXT_DIRECTION_RTL = 1,
    /** The text direction follows the component layout. */
    ARKUI_TEXT_DIRECTION_DEFAULT = 2,
    /** The text direction follows the actual text. */
    ARKUI_TEXT_DIRECTION_AUTO = 3,
} ArkUI_TextDirection;

/**
 * @brief Enumerates the types of the Enter key for a single-line text box.
 *
 * @since 12
 */
typedef enum {
    /** The Enter key is labeled "Go." */
    ARKUI_ENTER_KEY_TYPE_GO = 2,
    /** The Enter key is labeled "Search." */
    ARKUI_ENTER_KEY_TYPE_SEARCH = 3,
    /** The Enter key is labeled "Send." */
    ARKUI_ENTER_KEY_TYPE_SEND,
    /** The Enter key is labeled "Next." */
    ARKUI_ENTER_KEY_TYPE_NEXT,
    /** The Enter key is labeled "Done." */
    ARKUI_ENTER_KEY_TYPE_DONE,
    /** The Enter key is labeled "Previous." */
    ARKUI_ENTER_KEY_TYPE_PREVIOUS,
    /** The Enter key is labeled "New Line." */
    ARKUI_ENTER_KEY_TYPE_NEW_LINE,
} ArkUI_EnterKeyType;

/**
 * @brief Enumerates the text input types.
 *
 * @since 12
 */
typedef enum {
    /** Normal input mode. */
    ARKUI_TEXTINPUT_TYPE_NORMAL = 0,
    /** Number input mode. */
    ARKUI_TEXTINPUT_TYPE_NUMBER = 2,
    /** Phone number input mode. */
    ARKUI_TEXTINPUT_TYPE_PHONE_NUMBER = 3,
    /** Email address input mode. */
    ARKUI_TEXTINPUT_TYPE_EMAIL = 5,
    /** Password input mode. */
    ARKUI_TEXTINPUT_TYPE_PASSWORD = 7,
    /** Numeric password input mode. */
    ARKUI_TEXTINPUT_TYPE_NUMBER_PASSWORD = 8,
    /** Lock screen password input mode. */
    ARKUI_TEXTINPUT_TYPE_SCREEN_LOCK_PASSWORD = 9,
    /** Username input mode. */
    ARKUI_TEXTINPUT_TYPE_USER_NAME = 10,
    /** New password input mode. */
    ARKUI_TEXTINPUT_TYPE_NEW_PASSWORD = 11,
    /** Number input mode with a decimal point. */
    ARKUI_TEXTINPUT_TYPE_NUMBER_DECIMAL = 12,
    /**
     * One time code input mode.
     * @since 20
     */
    ARKUI_TEXTINPUT_TYPE_ONE_TIME_CODE = 14,
} ArkUI_TextInputType;

/**
 * @brief Enumerates the text box types.
 *
 * @since 12
 */
typedef enum {
    /** Normal input mode. */
    ARKUI_TEXTAREA_TYPE_NORMAL = 0,
    /** Number input mode. */
    ARKUI_TEXTAREA_TYPE_NUMBER = 2,
    /** Phone number input mode. */
    ARKUI_TEXTAREA_TYPE_PHONE_NUMBER = 3,
    /** Email address input mode. */
    ARKUI_TEXTAREA_TYPE_EMAIL = 5,
    /**
     * One time code input mode.
     * @since 20
     */
    ARKUI_TEXTAREA_TYPE_ONE_TIME_CODE = 14,
} ArkUI_TextAreaType;

/**
 * @brief Enumerates the styles of the Cancel button.
 *
 * @since 12
 */
typedef enum {
    /** The Cancel button is always displayed. */
    ARKUI_CANCELBUTTON_STYLE_CONSTANT = 0,
    /** The Cancel button is always hidden. */
    ARKUI_CANCELBUTTON_STYLE_INVISIBLE,
    /** The Cancel button is displayed when there is text input. */
    ARKUI_CANCELBUTTON_STYLE_INPUT,
} ArkUI_CancelButtonStyle;

/**
 * @brief Enumerates the types of the <b><XComponent></b> component.
 *
 * @since 12
 */
typedef enum {
    /** The custom content of EGL/OpenGL ES and media data is displayed individually on the screen. */
    ARKUI_XCOMPONENT_TYPE_SURFACE = 0,
    /** The custom content of EGL/OpenGL ES and media data is grouped and displayed together with content
      * of the component.
      */
    ARKUI_XCOMPONENT_TYPE_TEXTURE = 2,
} ArkUI_XComponentType;

/**
 * @brief Enumerates the styles of the progress indicator.
 *
 * @since 12
 */
typedef enum {
    /** Linear style. */
    ARKUI_PROGRESS_TYPE_LINEAR = 0,
    /** Indeterminate ring style. */
    ARKUI_PROGRESS_TYPE_RING,
    /** Eclipse style. */
    ARKUI_PROGRESS_TYPE_ECLIPSE,
    /** Determinate ring style. */
    ARKUI_PROGRESS_TYPE_SCALE_RING,
    /** Capsule style. */
    ARKUI_PROGRESS_TYPE_CAPSULE,
} ArkUI_ProgressType;

/**
 * @brief Enumerates the text decoration types.
 *
 * @since 12
 */
typedef enum {
    /** No text decoration. */
    ARKUI_TEXT_DECORATION_TYPE_NONE = 0,
    /** Line under the text. */
    ARKUI_TEXT_DECORATION_TYPE_UNDERLINE,
    /** Line over the text. */
    ARKUI_TEXT_DECORATION_TYPE_OVERLINE,
    /** Line through the text. */
    ARKUI_TEXT_DECORATION_TYPE_LINE_THROUGH,
} ArkUI_TextDecorationType;

/**
 * @brief Enumerates the text decoration styles.
 *
 * @since 12
 */
typedef enum {
    /** Single solid line. */
    ARKUI_TEXT_DECORATION_STYLE_SOLID = 0,
    /** Double solid line. */
    ARKUI_TEXT_DECORATION_STYLE_DOUBLE,
    /** Dotted line. */
    ARKUI_TEXT_DECORATION_STYLE_DOTTED,
    /** Dashed line. */
    ARKUI_TEXT_DECORATION_STYLE_DASHED,
    /** Wavy line. */
    ARKUI_TEXT_DECORATION_STYLE_WAVY,
} ArkUI_TextDecorationStyle;

/**
 * @brief Enumerates the text cases.
 *
 * @since 12
 */
typedef enum {
    /** The original case of the text is retained. */
    ARKUI_TEXT_CASE_NORMAL = 0,
    /** All letters in the text are in lowercase. */
    ARKUI_TEXT_CASE_LOWER,
    /** All letters in the text are in uppercase. */
    ARKUI_TEXT_CASE_UPPER,
} ArkUI_TextCase;

/**
 * @brief Enumerates the text copy and paste modes.
 *
 * @since 12
 */
typedef enum {
    /** Copy is not allowed. */
    ARKUI_COPY_OPTIONS_NONE = 0,
    /** Intra-application copy is allowed. */
    ARKUI_COPY_OPTIONS_IN_APP,
    /** Intra-device copy is allowed. */
    ARKUI_COPY_OPTIONS_LOCAL_DEVICE,
    /** Cross-device copy is allowed. */
    ARKUI_COPY_OPTIONS_CROSS_DEVICE,
} ArkUI_CopyOptions;

/**
 * @brief Enumerates the shadow types.
 *
 * @since 12
 */
typedef enum {
    /** Color. */
    ARKUI_SHADOW_TYPE_COLOR = 0,
    /** Blur. */
    ARKUI_SHADOW_TYPE_BLUR
} ArkUI_ShadowType;

/**
 * @brief Enumerates the modes of the date picker.
 *
 * @since 18
 */
typedef enum {
    /** A mode that displays the date in months, days of month, and years. */
    ARKUI_DATEPICKER_MODE_DATE = 0,
    /** A mode that displays the date in months and years. */
    ARKUI_DATEPICKER_YEAR_AND_MONTH = 1,
    /** A mode that displays the date in months and days of the month. */
    ARKUI_DATEPICKER_MONTH_AND_DAY = 2,
} ArkUI_DatePickerMode;

/**
 * @brief Enumerates the types of the text picker.
 *
 * @since 12
 */
typedef enum {
    /** Single-column text picker. */
    ARKUI_TEXTPICKER_RANGETYPE_SINGLE = 0,
    /** Multi-column text picker. */
    ARKUI_TEXTPICKER_RANGETYPE_MULTI,
    /** Single-column text picker with image resources. */
    ARKUI_TEXTPICKER_RANGETYPE_RANGE_CONTENT,
    /** Interconnected multi-column text picker. */
    ARKUI_TEXTPICKER_RANGETYPE_CASCADE_RANGE_CONTENT,
} ArkUI_TextPickerRangeType;

/**
 * @brief Defines the input structure of the single-column text picker with image resources.
 *
 * @since 12
 */
typedef struct {
    /** Image resource. */
    const char* icon;
    /** Text information. */
    const char* text;
} ARKUI_TextPickerRangeContent;

/**
 * @brief Defines the input structure of the interconnected multi-column text picker.
 *
 * @since 12
 */
typedef struct {
    /** Text information. */
    const char* text;
    /** Interconnected data. */
    const ARKUI_TextPickerRangeContent* children;
    /** Size of the interconnected data array. */
    int32_t size;
} ARKUI_TextPickerCascadeRangeContent;

/**
 * @brief Enumerates the effects used at the edges of the component when the boundary of the scrollable content is
 * reached.
 *
 * @since 12
 */
typedef enum {
    /** Spring effect. When at one of the edges, the component can move beyond the bounds based on the initial
     *  speed or through touches, and produces a bounce effect when the user releases their finger. */
    ARKUI_EDGE_EFFECT_SPRING = 0,
    /** Fade effect. When at one of the edges, the component produces a fade effect. */
    ARKUI_EDGE_EFFECT_FADE,
    /** No effect after the scrollbar is moved to the edge. */
    ARKUI_EDGE_EFFECT_NONE,
} ArkUI_EdgeEffect;

/**
 * @brief Enumerates the status of the scroll bar.
 *
 * @since 22
 */
typedef enum {
    /** Not displayed. */
    ARKUI_BAR_STATE_OFF = 0,
    /** On-demand display. */
    ARKUI_BAR_STATE_AUTO = 1,
    /** Resident display. */
    ARKUI_BAR_STATE_ON = 2,
} ArkUI_BarState;

/**
 * @brief Enumerates the edges for which the effect takes effect when the boundary of the scrollable content is reached.
 *
 * @since 18
 */
typedef enum {
    /** Start edge. */
    ARKUI_EFFECT_EDGE_START = 1,
    /** End edge. */
    ARKUI_EFFECT_EDGE_END = 2,
} ArkUI_EffectEdge;

/**
 * @brief Enumerates the focus wrap mode of components.
 *
 * @since 20
 */
typedef enum {
    /** Default mode, where focus does not wrap when arrow keys are used. */
    ARKUI_FOCUS_WRAP_MODE_DEFAULT = 0,
    /** Focus wraps automatically when arrow keys are used. */
    ARKUI_FOCUS_WRAP_WITH_ARROW = 1,
} ArkUI_FocusWrapMode;

/**
 * @brief Specifies the number of columns for different responsive breakpoint specifications.
 *
 * @since 22
 */
typedef enum {
    /** No responsive breakpoint configuration. */
    ARKUI_ITEMFILLPOLICY_NONE = -1,
    /**
     * Default responsive layout:
     * <b>List</b> or <b>Swiper</b> component: 1 column (SM or smaller), 2 columns (MD), 3 columns (LG or larger).
     * <b>Grid</b> or <b>WaterFlow</b> component: 2 columns (SM or smaller), 3 columns (MD), 5 columns (LG or larger).
     */
    ARKUI_ITEMFILLPOLICY_DEFAULT = 0,
    /** 1 column (SM or smaller), 2 columns (MD), 3 columns (LG or larger). */
    ARKUI_ITEMFILLPOLICY_SM1MD2LG3 = 1,
    /** 2 columns (SM or smaller), 3 columns (MD), 5 columns (LG or larger). */
    ARKUI_ITEMFILLPOLICY_SM2MD3LG5 = 2,
} ArkUI_ItemFillPolicy;

/**
 * @brief Enumerates the grid item alignment modes.
 *
 * @since 22
 */
typedef enum {
    /** Use the default alignment mode of the grid. */
    GRID_ITEM_ALIGNMENT_DEFAULT = 0,
    /** Set the height of all grid items in a row to match the height of the tallest item in that row. */
    GRID_ITEM_ALIGNMENT_STRETCH = 1,
} ArkUI_GridItemAlignment;

/**
 * @brief Enumerates styles of grid items.
 *
 * @since 22
 */
typedef enum {
    /** No style. */
    GRID_ITEM_STYLE_NONE = 0,
    /** Hover or press style. */
    GRID_ITEM_STYLE_PLAIN = 1,
} ArkUI_GridItemStyle;

/**
 * @brief Enumerates the scroll directions for the <b><Scroll></b> component.
 *
 * @since 12
 */
typedef enum {
    /** Only vertical scrolling is supported. */
    ARKUI_SCROLL_DIRECTION_VERTICAL = 0,
    /** Only horizontal scrolling is supported. */
    ARKUI_SCROLL_DIRECTION_HORIZONTAL,
    /** Scrolling is not allowed. */
    ARKUI_SCROLL_DIRECTION_NONE = 3,
    /**
     * Free scrolling in both directions.
     *
     * @since 20
     */
    ARKUI_SCROLL_DIRECTION_FREE = 4,
} ArkUI_ScrollDirection;

/**
 * @brief Enumerates the alignment modes of list items when scrolling ends.
 *
 * @since 12
 */
typedef enum {
    /** No alignment. This is the default value. */
    ARKUI_SCROLL_SNAP_ALIGN_NONE = 0,
    /** The first item in the view is aligned at the start of the list. */
    ARKUI_SCROLL_SNAP_ALIGN_START,
    /** The middle items in the view are aligned in the center of the list. */
    ARKUI_SCROLL_SNAP_ALIGN_CENTER,
    /** The last item in the view is aligned at the end of the list. */
    ARKUI_SCROLL_SNAP_ALIGN_END,
} ArkUI_ScrollSnapAlign;

/**
 * @brief Enumerates the scroll snap animation speeds for lists.
 *
 * @since 22
 */
typedef enum {
    /** Normal scroll snap animation speed. */
    ARKUI_SCROLL_SNAP_ANIMATION_NORMAL = 0,
    /** Slow scroll snap animation speed. */
    ARKUI_SCROLL_SNAP_ANIMATION_SLOW = 1,
} ArkUI_ScrollSnapAnimationSpeed;

/**
 * @brief Enumerates the scrollbar display modes.
 *
 * @since 12
 */
typedef enum {
    /** Hide. */
    ARKUI_SCROLL_BAR_DISPLAY_MODE_OFF = 0,
    /** Display on demand (displays when the screen is touched and disappears after 2s). */
    ARKUI_SCROLL_BAR_DISPLAY_MODE_AUTO,
    /** Always display. */
    ARKUI_SCROLL_BAR_DISPLAY_MODE_ON,
} ArkUI_ScrollBarDisplayMode;

/**
 * @brief Enumerates the scroll directions for the <b><List></b> component.
 *
 * @since 12
 */
typedef enum {
    /** Only vertical scrolling is supported. */
    ARKUI_AXIS_VERTICAL = 0,
    /** Only horizontal scrolling is supported. */
    ARKUI_AXIS_HORIZONTAL,
} ArkUI_Axis;

/**
 * @brief Enumerates the modes for pinning the header to the top or the footer to the bottom.
 *
 * @since 12
 */
typedef enum {
    /** In the list item group, the header is not pinned to the top, and the footer is not pinned to the bottom. */
    ARKUI_STICKY_STYLE_NONE = 0,
    /** In the list item group, the header is pinned to the top, and the footer is not pinned to the bottom. */
    ARKUI_STICKY_STYLE_HEADER = 1,
    /** In the list item group, the footer is pinned to the bottom, and the header is not pinned to the top. */
    ARKUI_STICKY_STYLE_FOOTER = 2,
    /** In the list item group, the footer is pinned to the bottom, and the header is pinned to the top. */
    ARKUI_STICKY_STYLE_BOTH = 3,
} ArkUI_StickyStyle;

/**
 * @brief Enumerates the content clipping modes of scrollable components.
 *
 * @since 18
 */
typedef enum {
    /** clip by content */
    ARKUI_CONTENT_CLIP_MODE_CONTENT_ONLY = 0,
    /** clip by boundary */
    ARKUI_CONTENT_CLIP_MODE_BOUNDARY,
    /** clip by safe area padding */
    ARKUI_CONTENT_CLIP_MODE_SAFE_AREA,
} ArkUI_ContentClipMode;

/**
 * @brief Enumerates the layout modes of the WaterFlow component.
 *
 * @since 18
 */
typedef enum {
    /** Layout items from top to viewport. */
    ARKUI_WATER_FLOW_LAYOUT_MODE_ALWAYS_TOP_DOWN = 0,
    /** Layout items in viewport. */
    ARKUI_WATER_FLOW_LAYOUT_MODE_SLIDING_WINDOW,
} ArkUI_WaterFlowLayoutMode;

/**
 * @brief Enumerates the border styles.
 *
 * @since 12
 */
typedef enum {
    /** Solid border. */
    ARKUI_BORDER_STYLE_SOLID = 0,
    /** Dashed border. */
    ARKUI_BORDER_STYLE_DASHED,
    /** Dotted border. */
    ARKUI_BORDER_STYLE_DOTTED,
} ArkUI_BorderStyle;

/**
 * @brief Enumerates the hit test modes.
 *
 * @since 12
 */
typedef enum {
    /** Both the node and its child node respond to the hit test of a touch event, but its sibling node is blocked from
     *  the hit test. */
    ARKUI_HIT_TEST_MODE_DEFAULT = 0,
    /** The node responds to the hit test of a touch event, but its child node and sibling node are blocked from the
     *  hit test. */
    ARKUI_HIT_TEST_MODE_BLOCK,
    /** Both the node and its child node respond to the hit test of a touch event, and its sibling node is also
     * considered during the hit test. */
    ARKUI_HIT_TEST_MODE_TRANSPARENT,
    /** The node does not respond to the hit test of a touch event. */
    ARKUI_HIT_TEST_MODE_NONE,
    /**
     * The node and its child nodes participate in hit tests, while blocking hit tests for all sibling nodes and
     * parent nodes with lower priority.
     *
     * @since 20
     */
    ARKUI_HIT_TEST_MODE_BLOCK_HIERARCHY,
    /**
     * The node does not respond to hit tests, and none of its descendants (including children and grandchildren)
     * participate in hit tests either.
     *
     * @since 20
     */
    ARKUI_HIT_TEST_MODE_BLOCK_DESCENDANTS,
} ArkUI_HitTestMode;

/**
 * @brief Enumerates the shadow styles.
 *
 * @since 12
 */
typedef enum {
    /** Mini shadow. */
    ARKUI_SHADOW_STYLE_OUTER_DEFAULT_XS = 0,
    /** Little shadow. */
    ARKUI_SHADOW_STYLE_OUTER_DEFAULT_SM,
    /** Medium shadow. */
    ARKUI_SHADOW_STYLE_OUTER_DEFAULT_MD,
    /** Large shadow. */
    ARKUI_SHADOW_STYLE_OUTER_DEFAULT_LG,
    /** Floating small shadow. */
    ARKUI_SHADOW_STYLE_OUTER_FLOATING_SM,
    /** Floating medium shadow. */
    ARKUI_SHADOW_STYLE_OUTER_FLOATING_MD,
} ArkUI_ShadowStyle;

/**
 * @brief Enumerates the animation curves.
 *
 * @since 12
 */
typedef enum {
    /** The animation speed keeps unchanged. */
    ARKUI_CURVE_LINEAR = 0,
    /** The animation starts slowly, accelerates, and then slows down towards the end. */
    ARKUI_CURVE_EASE,
    /** The animation starts at a low speed and then picks up speed until the end. */
    ARKUI_CURVE_EASE_IN,
    /** The animation ends at a low speed. */
    ARKUI_CURVE_EASE_OUT,
    /** The animation starts and ends at a low speed. */
    ARKUI_CURVE_EASE_IN_OUT,
    /** The animation uses the standard curve */
    ARKUI_CURVE_FAST_OUT_SLOW_IN,
    /** The animation uses the deceleration curve. */
    ARKUI_CURVE_LINEAR_OUT_SLOW_IN,
    /** The animation uses the acceleration curve. */
    ARKUI_CURVE_FAST_OUT_LINEAR_IN,
    /** The animation uses the extreme deceleration curve. */
    ARKUI_CURVE_EXTREME_DECELERATION,
    /** The animation uses the sharp curve. */
    ARKUI_CURVE_SHARP,
    /** The animation uses the rhythm curve. */
    ARKUI_CURVE_RHYTHM,
    /** The animation uses the smooth curve. */
    ARKUI_CURVE_SMOOTH,
    /** The animation uses the friction curve */
    ARKUI_CURVE_FRICTION,
} ArkUI_AnimationCurve;

/**
 * @brief Enumerates arrow styles of the navigation point indicator.
 *
 * @since 12
 */
typedef enum {
    /** The arrow is not displayed for the navigation point indicator. */
    ARKUI_SWIPER_ARROW_HIDE = 0,
    /** The arrow is displayed for the navigation point indicator. */
    ARKUI_SWIPER_ARROW_SHOW,
    /** The arrow is displayed only when the mouse pointer hovers over the navigation point indicator. */
    ARKUI_SWIPER_ARROW_SHOW_ON_HOVER,
} ArkUI_SwiperArrow;

/**
 * @brief Nested scrolling mode for Swiper components and parent components.
 *
 * @since 12
 */
typedef enum {
    /** Swiper only scrolls on its own and is not linked to its parent component. */
    ARKUI_SWIPER_NESTED_SRCOLL_SELF_ONLY = 0,
    /** The Swiper itself scrolls first, and the parent component scrolls after it reaches the edge. After the parent
     * component scrolls to the edge, if the parent component has an edge effect, the parent component triggers the edge
     * effect; otherwise, the Swiper triggers the edge effect. */
    ARKUI_SWIPER_NESTED_SRCOLL_SELF_FIRST,
} ArkUI_SwiperNestedScrollMode;

/**
 * @brief Enumerates the page flipping modes using the mouse wheel for the <b>Swiper</b> component.
 *
 * @since 15
 */
typedef enum {
    /** When the mouse wheel is scrolled continuously, multiple pages are flipped, which is determined by the number of
     *  times that mouse events are reported. */
    ARKUI_PAGE_FLIP_MODE_CONTINUOUS = 0,
    /** The system does not respond to other mouse wheel events until the page flipping animation ends. */
    ARKUI_PAGE_FLIP_MODE_SINGLE,
} ArkUI_PageFlipMode;

/**
 * @brief Enumerates the animation modes for {@link NODE_SWIPER_INDEX}.
 *
 * @since 15
 */
typedef enum {
    /** Jump to target index without animation. */
    ARKUI_SWIPER_NO_ANIMATION = 0,
    /** Scroll to target index with animation. */
    ARKUI_SWIPER_DEFAULT_ANIMATION = 1,
    /** Jump to some index near the target index without animation, then scroll to target index with animation. */
    ARKUI_SWIPER_FAST_ANIMATION = 2,
} ArkUI_SwiperAnimationMode;

/**
 * @brief Enumerates the accessibility modes.
 *
 * @since 12
 */
typedef enum {
    /** Whether the component can be identified by the accessibility service is dependent on the component. */
    ARKUI_ACCESSIBILITY_MODE_AUTO = 0,
    /** The component can be identified by the accessibility service. */
    ARKUI_ACCESSIBILITY_MODE_ENABLED,
    /** The component cannot be identified by the accessibility service. */
    ARKUI_ACCESSIBILITY_MODE_DISABLED,
    /** The component and all its child components cannot be identified by the accessibility service. */
    ARKUI_ACCESSIBILITY_MODE_DISABLED_FOR_DESCENDANTS,
} ArkUI_AccessibilityMode;

/**
 * @brief Defines whether copy and paste is allowed for text content.
 *
 * @since 12
 */
typedef enum {
    /** Copy is not allowed. */
    ARKUI_TEXT_COPY_OPTIONS_NONE = 0,
    /** Intra-application copy is allowed. */
    ARKUI_TEXT_COPY_OPTIONS_IN_APP,
    /** Intra-device copy is allowed. */
    ARKUI_TEXT_COPY_OPTIONS_LOCAL_DEVICE,
    /** Cross-device copy is allowed. */
    ARKUI_TEXT_COPY_OPTIONS_CROSS_DEVICE,
} ArkUI_TextCopyOptions;

/**
 * @brief Defines how the adaptive height is determined for the text.
 *
 * @since 12
 */
typedef enum {
    /** Prioritize the <b>maxLines</b> settings. */
    ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MAX_LINES_FIRST = 0,
    /** Prioritize the <b>minFontSize</b> settings. */
    ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MIN_FONT_SIZE_FIRST,
    /** Prioritize the layout constraint settings in terms of height. */
    ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_LAYOUT_CONSTRAINT_FIRST,
} ArkUI_TextHeightAdaptivePolicy;

/**
 * @brief Defines nested scrolling options.
 *
 * @since 12
 */
typedef enum {
    /** The scrolling is contained within the component, and no scroll chaining occurs, that is, the parent component
     * does not scroll when the component scrolling reaches the boundary. */
    ARKUI_SCROLL_NESTED_MODE_SELF_ONLY = 0,
    /** The component scrolls first, and when it hits the boundary, the parent component scrolls.
     *  When the parent component hits the boundary, its edge effect is displayed. If no edge
     *  effect is specified for the parent component, the edge effect of the child component is displayed instead. */
    ARKUI_SCROLL_NESTED_MODE_SELF_FIRST,
    /** The parent component scrolls first, and when it hits the boundary, the component scrolls.
     *  When the component hits the boundary, its edge effect is displayed. If no edge effect is specified for the
     *  component, the edge effect of the parent component is displayed instead. */
    ARKUI_SCROLL_NESTED_MODE_PARENT_FIRST,
    /** The component and its parent component scroll at the same time. When both the component and its parent component
     *  hit the boundary, the edge effect of the component is displayed. If no edge effect is specified for the
     *  component, the edge effect of the parent component is displayed instead. */
    ARKUI_SCROLL_NESTED_MODE_PARALLEL,
} ArkUI_ScrollNestedMode;

/**
 * @brief Defines the edge to which the component scrolls.
 *
 * @since 12
 */
typedef enum {
    /** Top edge in the vertical direction. */
    ARKUI_SCROLL_EDGE_TOP = 0,
    /** Bottom edge in the vertical direction. */
    ARKUI_SCROLL_EDGE_BOTTOM,
    /** Start position in the horizontal direction. */
    ARKUI_SCROLL_EDGE_START,
    /** End position in the horizontal direction. */
    ARKUI_SCROLL_EDGE_END,
} ArkUI_ScrollEdge;

/**
 * @brief Alignment when scrolling to specific items.
 *
 * @since 12
 */
typedef enum {
    /** Align the head. Align the head of the specified item with the head of the container.*/
    ARKUI_SCROLL_ALIGNMENT_START = 0,
    /** Center alignment. Align the axis direction of the specified item to the center of the container.*/
    ARKUI_SCROLL_ALIGNMENT_CENTER,
    /** Tail alignment. Align the tail of the specified item with the tail of the container.*/
    ARKUI_SCROLL_ALIGNMENT_END,
    /** Automatic alignment. If the specified item is completely in the display area, no adjustments will be made.
     * Otherwise, according to the principle of the shortest sliding distance, align the head or tail of the specified
     * item with the container, so that the specified item is completely in the display area.*/
    ARKUI_SCROLL_ALIGNMENT_AUTO,
} ArkUI_ScrollAlignment;

/**
 * @brief Define the current scrolling state.
 *
 * @since 12
 */
typedef enum {
    /** Idle state. Trigger when using the method provided by the controller to control scrolling, and trigger when
     * dragging the scroll bar to scroll.*/
    ARKUI_SCROLL_STATE_IDLE = 0,
    /** Scroll state. Triggered when dragging the container with fingers to scroll.*/
    ARKUI_SCROLL_STATE_SCROLL,
    /** Inertial rolling state. Triggered when inertia rolling and bouncing back to the edge are performed after
     * releasing the hand quickly.*/
    ARKUI_SCROLL_STATE_FLING,
} ArkUI_ScrollState;

/**
 * @brief Enumerates the types of the slider in the block direction.
 *
 * @since 12
 */
typedef enum {
    /** Round slider. */
    ARKUI_SLIDER_BLOCK_STYLE_DEFAULT = 0,
    /** Slider with an image background. */
    ARKUI_SLIDER_BLOCK_STYLE_IMAGE,
    /** Slider in a custom shape. */
    ARKUI_SLIDER_BLOCK_STYLE_SHAPE,
} ArkUI_SliderBlockStyle;

/**
 * @brief Enumerates the scroll directions of the slider.
 *
 * @since 12
 */
typedef enum {
    /** Vertical direction. */
    ARKUI_SLIDER_DIRECTION_VERTICAL = 0,
    /** Horizontal direction. */
    ARKUI_SLIDER_DIRECTION_HORIZONTAL,
} ArkUI_SliderDirection;

/**
 * @brief Enumerates the slider styles.
 *
 * @since 12
 */
typedef enum {
    /** The slider is on the slider track. */
    ARKUI_SLIDER_STYLE_OUT_SET = 0,
    /** The slider is in the slider track. */
    ARKUI_SLIDER_STYLE_IN_SET,
    /** No slider. */
    ARKUI_SLIDER_STYLE_NONE,
} ArkUI_SliderStyle;

/**
 * @brief Enumerates the shapes of the check box
 *
 * @since 12
 */
typedef enum {
    /** Circle. */
    ArkUI_CHECKBOX_SHAPE_CIRCLE = 0,
    /** Rounded square. */
    ArkUI_CHECKBOX_SHAPE_ROUNDED_SQUARE,
} ArkUI_CheckboxShape;

/**
 * @brief Enumerates the animation playback modes.
 *
 * @since 12
 */
typedef enum {
    /** The animation is played forwards. */
    ARKUI_ANIMATION_PLAY_MODE_NORMAL = 0,
    /** The animation is played reversely. */
    ARKUI_ANIMATION_PLAY_MODE_REVERSE,
    /** The animation is played normally for an odd number of times (1, 3, 5...) and reversely for an even number
     *  of times (2, 4, 6...). */
    ARKUI_ANIMATION_PLAY_MODE_ALTERNATE,
    /** The animation is played reversely for an odd number of times (1, 3, 5...) and normally for an even number
     *  of times (2, 4, 6...). */
    ARKUI_ANIMATION_PLAY_MODE_ALTERNATE_REVERSE,
} ArkUI_AnimationPlayMode;

/**
 * @brief Defines the image size.
 *
 * @since 12
 */
typedef enum {
    /** The original image aspect ratio is retained. */
    ARKUI_IMAGE_SIZE_AUTO = 0,
    /** The image is scaled with its aspect ratio retained for both sides to be greater than or equal
     *  to the display boundaries. */
    ARKUI_IMAGE_SIZE_COVER,
    /** The image is scaled with its aspect ratio retained for the content to be completely displayed within the display
     *  boundaries. */
    ARKUI_IMAGE_SIZE_CONTAIN,
} ArkUI_ImageSize;

/**
 * @brief Enumerates the adaptive color modes.
 *
 * @since 12
 */
typedef enum {
    /** Adaptive color mode is not used. */
    ARKUI_ADAPTIVE_COLOR_DEFAULT = 0,
    /** Adaptive color mode is used. */
    ARKUI_ADAPTIVE_COLOR_AVERAGE,
} ArkUI_AdaptiveColor;

/**
 * @brief Enumerates the color modes.
 *
 * @since 12
 */
typedef enum {
    /** Following the system color mode. */
    ARKUI_COLOR_MODE_SYSTEM = 0,
    /** Light color mode. */
    ARKUI_COLOR_MODE_LIGHT,
    /** Dark color mode. */
    ARKUI_COLOR_MODE_DARK,
} ArkUI_ColorMode;

/**
 * @brief Enumerates the system color modes.
 *
 * @since 12
 */
typedef enum {
    /** Light color mode. */
    ARKUI_SYSTEM_COLOR_MODE_LIGHT = 0,
    /** Dark color mode. */
    ARKUI_SYSTEM_COLOR_MODE_DARK,
} ArkUI_SystemColorMode;

/**
 * @brief Enumerates the blur styles.
 *
 * @since 12
 */
typedef enum {
    /** Thin material. */
    ARKUI_BLUR_STYLE_THIN = 0,
    /** Regular material. */
    ARKUI_BLUR_STYLE_REGULAR,
    /** Thick material. */
    ARKUI_BLUR_STYLE_THICK,
    /** Material that creates the minimum depth of field effect. */
    ARKUI_BLUR_STYLE_BACKGROUND_THIN,
    /** Material that creates a medium shallow depth of field effect. */
    ARKUI_BLUR_STYLE_BACKGROUND_REGULAR,
    /** Material that creates a high shallow depth of field effect. */
    ARKUI_BLUR_STYLE_BACKGROUND_THICK,
    /** Material that creates the maximum depth of field effect. */
    ARKUI_BLUR_STYLE_BACKGROUND_ULTRA_THICK,
    /** No blur. */
    ARKUI_BLUR_STYLE_NONE,
    /** Component ultra-thin material. */
    ARKUI_BLUR_STYLE_COMPONENT_ULTRA_THIN,
    /** Component thin material. */
    ARKUI_BLUR_STYLE_COMPONENT_THIN,
    /** Component regular material. */
    ARKUI_BLUR_STYLE_COMPONENT_REGULAR,
    /** Component thick material. */
    ARKUI_BLUR_STYLE_COMPONENT_THICK,
    /** Component ultra-thick material. */
    ARKUI_BLUR_STYLE_COMPONENT_ULTRA_THICK,
} ArkUI_BlurStyle;

/**
 * @brief Enumerates the activation policies for the background blur effect.
 *
 * @since 19
 */
typedef enum {
    /** The blur effect changes according to the window's focus state;
     *  it is inactive when the window is not in focus and active when the window is in focus. */
    ARKUI_BLUR_STYLE_ACTIVE_POLICY_FOLLOWS_WINDOW_ACTIVE_STATE = 0,
    /** The blur effect is always active. */
    ARKUI_BLUR_STYLE_ACTIVE_POLICY_ALWAYS_ACTIVE,
    /** The blur effect is always inactive. */
    ARKUI_BLUR_STYLE_ACTIVE_POLICY_ALWAYS_INACTIVE,
} ArkUI_BlurStyleActivePolicy;

/**
 * @brief Enumerates the vertical alignment modes.
 *
 * @since 12
 */
typedef enum {
    /** Top aligned. */
    ARKUI_VERTICAL_ALIGNMENT_TOP = 0,
    /** Center aligned. This is the default alignment mode. */
    ARKUI_VERTICAL_ALIGNMENT_CENTER,
    /** Bottom aligned. */
    ARKUI_VERTICAL_ALIGNMENT_BOTTOM,
} ArkUI_VerticalAlignment;

/**
 * @brief Enumerates the alignment mode in the horizontal direction.
 *
 * @since 12
 */
typedef enum {
    /** Aligned with the start edge in the same direction as the language in use. */
    ARKUI_HORIZONTAL_ALIGNMENT_START = 0,
    /** Center aligned. This is the default alignment mode. */
    ARKUI_HORIZONTAL_ALIGNMENT_CENTER,
    /** Aligned with the end edge in the same direction as the language in use. */
    ARKUI_HORIZONTAL_ALIGNMENT_END,
} ArkUI_HorizontalAlignment;

/**
 * @brief Enumerates the display modes when the text is too long.
 *
 * @since 12
 */
typedef enum {
    /** Extra-long text is not clipped. */
    ARKUI_TEXT_OVERFLOW_NONE = 0,
    /** Extra-long text is clipped. */
    ARKUI_TEXT_OVERFLOW_CLIP,
    /** An ellipsis (...) is used to represent text overflow. */
    ARKUI_TEXT_OVERFLOW_ELLIPSIS,
    /** Text continuously scrolls when text overflow occurs. */
    ARKUI_TEXT_OVERFLOW_MARQUEE,
} ArkUI_TextOverflow;

/**
 * @brief Enumerates the alignment mode of the image with the text.
 *
 * @since 12
 */
typedef enum {
    /** The image is bottom aligned with the text baseline. */
    ARKUI_IMAGE_SPAN_ALIGNMENT_BASELINE = 0,
    /** The image is bottom aligned with the text. */
    ARKUI_IMAGE_SPAN_ALIGNMENT_BOTTOM,
    /** The image is centered aligned with the text. */
    ARKUI_IMAGE_SPAN_ALIGNMENT_CENTER,
    /** The image is top aligned with the text. */
    ARKUI_IMAGE_SPAN_ALIGNMENT_TOP,
    /**
     * The image alignment mode follows the text component's alignment mode.
     *
     * @since 20
     */
    ARKUI_IMAGE_SPAN_ALIGNMENT_FOLLOW_PARAGRAPH,
} ArkUI_ImageSpanAlignment;

/**
 * @brief Defines how the image is resized to fit its container.
 *ImageSpanAlignment
 * @since 12
 */
typedef enum {
    /** The image is scaled with its aspect ratio retained for the content to be completely displayed within the
     *  display boundaries. */
    ARKUI_OBJECT_FIT_CONTAIN = 0,
    /** The image is scaled with its aspect ratio retained for both sides to be greater than or equal to the
     *  display boundaries. */
    ARKUI_OBJECT_FIT_COVER,
    /** The image is scaled automatically to fit the display area. */
    ARKUI_OBJECT_FIT_AUTO,
    /** The image is scaled to fill the display area, and its aspect ratio is not retained. */
    ARKUI_OBJECT_FIT_FILL,
    /** The image content is displayed with its aspect ratio retained. The size is smaller than or equal to the
     *  original size. */
    ARKUI_OBJECT_FIT_SCALE_DOWN,
    /** The original size is retained. */
    ARKUI_OBJECT_FIT_NONE,
    /** Not resized, the image is aligned with the start edge of the top of the container. */
    ARKUI_OBJECT_FIT_NONE_AND_ALIGN_TOP_START,
    /** Not resized, the image is horizontally centered at the top of the container. */
    ARKUI_OBJECT_FIT_NONE_AND_ALIGN_TOP,
    /** Not resized, the image is aligned with the end edge at the top of the container. */
    ARKUI_OBJECT_FIT_NONE_AND_ALIGN_TOP_END,
    /** Not resized, the image is vertically centered on the start edge of the container. */
    ARKUI_OBJECT_FIT_NONE_AND_ALIGN_START,
    /** Not resized, the image is horizontally and vertically centered in the container. */
    ARKUI_OBJECT_FIT_NONE_AND_ALIGN_CENTER,
    /** Not resized, the image is vertically centered on the end edge of the container. */
    ARKUI_OBJECT_FIT_NONE_AND_ALIGN_END,
    /** Not resized, the image is aligned with the start edge at the bottom of the container. */
    ARKUI_OBJECT_FIT_NONE_AND_ALIGN_BOTTOM_START,
    /** Not resized, the image is horizontally centered at the bottom of the container. */
    ARKUI_OBJECT_FIT_NONE_AND_ALIGN_BOTTOM,
    /** Not resized, the image is aligned with the end edge at the bottom of the container. */
    ARKUI_OBJECT_FIT_NONE_AND_ALIGN_BOTTOM_END,
    /**
     * Not resized, and is used in conjunction with NODE_IMAGE_IMAGE_MATRIX.
     *
     * @since 21
     */
    ARKUI_OBJECT_FIT_NONE_MATRIX,
} ArkUI_ObjectFit;

/**
 * @brief Enumerates the image interpolation effect.
 *
 * @since 12
 */
typedef enum {
    /** No image interpolation. */
    ARKUI_IMAGE_INTERPOLATION_NONE = 0,
    /** Low quality interpolation. */
    ARKUI_IMAGE_INTERPOLATION_LOW,
    /** Medium quality interpolation. */
    ARKUI_IMAGE_INTERPOLATION_MEDIUM,
    /** High quality interpolation. This mode produces scaled images of the highest possible quality. */
    ARKUI_IMAGE_INTERPOLATION_HIGH,
} ArkUI_ImageInterpolation;

/**
 * @brief Enumerates the image dynamic range mode.
 *
 * @since 21
 */
typedef enum {
    /** high dynamic range mode. */
    ARKUI_DYNAMIC_RANGE_MODE_HIGH = 0,
    /** constraint dynamic range mode. */
    ARKUI_DYNAMIC_RANGE_MODE_CONSTRAINT,
    /** standard dynamic range mode. */
    ARKUI_DYNAMIC_RANGE_MODE_STANDARD,
} ArkUI_DynamicRangeMode;

/**
 * @brief Enumerates the image rotate orientation.
 *
 * @since 21
 */
typedef enum {
    /** Use EXIF metadata for display orientation, with support for rotation and mirroring. */
    ARKUI_ORIENTATION_AUTO = 0,
    /** Display original pixel data without transformation. */
    ARKUI_ORIENTATION_UP,
    /** Display the image after rotating it 90 degrees clockwise. */
    ARKUI_ORIENTATION_RIGHT,
    /** Display the image after rotating it 180 degrees clockwise. */
    ARKUI_ORIENTATION_DOWN,
    /** Display the image after rotating it 270 degrees clockwise. */
    ARKUI_ORIENTATION_LEFT,
    /** Display the image after flipping it horizontally. */
    ARKUI_ORIENTATION_UP_MIRRORED,
    /** Display the image after flipping it horizontally and then rotating it 90 degrees clockwise. */
    ARKUI_ORIENTATION_RIGHT_MIRRORED,
    /** Display the image after flipping it vertically. */
    ARKUI_ORIENTATION_DOWN_MIRRORED,
    /** Display the image after flipping it horizontally and then rotating it 270 degrees clockwise. */
    ARKUI_ORIENTATION_LEFT_MIRRORED,
} ArkUI_ImageRotateOrientation;

/**
 * @brief Enumerates the blend modes.
 *
 * @since 12
 */
typedef enum {
    /** The top image is superimposed on the bottom image without any blending. */
    ARKUI_BLEND_MODE_NONE = 0,
    /** The target pixels covered by the source pixels are erased by being turned to completely transparent. */
    ARKUI_BLEND_MODE_CLEAR,
    /** r = s: Only the source pixels are displayed. */
    ARKUI_BLEND_MODE_SRC,
    /** r = d: Only the target pixels are displayed. */
    ARKUI_BLEND_MODE_DST,
    /** r = s + (1 - sa) * d: The source pixels are blended based on opacity and cover the target pixels. */
    ARKUI_BLEND_MODE_SRC_OVER,
    /** r = d + (1 - da) * s: The target pixels are blended based on opacity and cover on the source pixels. */
    ARKUI_BLEND_MODE_DST_OVER,
    /** r = s * da: Only the part of the source pixels that overlap with the target pixels is displayed. */
    ARKUI_BLEND_MODE_SRC_IN,
    /** r = d * sa: Only the part of the target pixels that overlap with the source pixels is displayed. */
    ARKUI_BLEND_MODE_DST_IN,
    /** r = s * (1 - da): Only the part of the source pixels that do not overlap with the target pixels is displayed. */
    ARKUI_BLEND_MODE_SRC_OUT,
    /** r = d * (1 - sa): Only the part of the target pixels that do not overlap with the source pixels is displayed. */
    ARKUI_BLEND_MODE_DST_OUT,
    /** r = s * da + d * (1 - sa): The part of the source pixels that overlap with the target pixels is displayed and
     *  the part of the target pixels that do not overlap with the source pixels are displayed.
     */
    ARKUI_BLEND_MODE_SRC_ATOP,
    /** r = d * sa + s * (1 - da): The part of the target pixels that overlap with the source pixels and the part of
     *  the source pixels that do not overlap with the target pixels are displayed.
     */
    ARKUI_BLEND_MODE_DST_ATOP,
    /** r = s * (1 - da) + d * (1 - sa): Only the non-overlapping part between the source pixels and the target pixels
     * is displayed. */
    ARKUI_BLEND_MODE_XOR,
    /** r = min(s + d, 1): New pixels resulting from adding the source pixels to the target pixels are displayed. */
    ARKUI_BLEND_MODE_PLUS,
    /** r = s * d: New pixels resulting from multiplying the source pixels with the target pixels are displayed. */
    ARKUI_BLEND_MODE_MODULATE,
    /** r = s + d - s * d: Pixels are blended by adding the source pixels to the target pixels and subtracting the
     *  product of their multiplication. */
    ARKUI_BLEND_MODE_SCREEN,
    /** The MULTIPLY or SCREEN mode is used based on the target pixels. */
    ARKUI_BLEND_MODE_OVERLAY,
    /** rc = s + d - max(s * da, d * sa), ra = kSrcOver: When two colors overlap, whichever is darker is used. */
    ARKUI_BLEND_MODE_DARKEN,
    /** rc = s + d - min(s * da, d * sa), ra =
       kSrcOver: The final pixels are composed of the lightest values of pixels. */
    ARKUI_BLEND_MODE_LIGHTEN,
    /** The colors of the target pixels are lightened to reflect the source pixels. */
    ARKUI_BLEND_MODE_COLOR_DODGE,
    /** The colors of the target pixels are darkened to reflect the source pixels. */
    ARKUI_BLEND_MODE_COLOR_BURN,
    /** The MULTIPLY or SCREEN mode is used, depending on the source pixels. */
    ARKUI_BLEND_MODE_HARD_LIGHT,
    /** The LIGHTEN or DARKEN mode is used, depending on the source pixels. */
    ARKUI_BLEND_MODE_SOFT_LIGHT,
    /** rc = s + d - 2 * (min(s * da, d * sa)), ra =
       kSrcOver: The final pixel is the result of subtracting the darker of the two pixels (source and target) from
       the lighter one. */
    ARKUI_BLEND_MODE_DIFFERENCE,
    /** rc = s + d - two(s * d), ra = kSrcOver: The final pixel is similar to <b>DIFFERENCE</b>, but with less contrast.
     */
    ARKUI_BLEND_MODE_EXCLUSION,
    /** r = s * (1 - da) + d * (1 - sa) + s * d: The final pixel is the result of multiplying the source pixel
     *  by the target pixel.	 */
    ARKUI_BLEND_MODE_MULTIPLY,
    /** The resultant image is created with the luminance and saturation of the source image and the hue of the target
     *  image. */
    ARKUI_BLEND_MODE_HUE,
    /** The resultant image is created with the luminance and hue of the target image and the saturation of the source
     *  image. */
    ARKUI_BLEND_MODE_SATURATION,
    /** The resultant image is created with the saturation and hue of the source image and the luminance of the target
     *  image. */
    ARKUI_BLEND_MODE_COLOR,
    /** The resultant image is created with the saturation and hue of the target image and the luminance of the source
     *  image. */
    ARKUI_BLEND_MODE_LUMINOSITY,
} ArkUI_BlendMode;

/**
 * @brief Enumerates the modes in which components are laid out along the main axis of the container.
 *
 * @since 12
 */
typedef enum {
    /** Components are arranged from left to right. */
    ARKUI_DIRECTION_LTR = 0,
    /** Components are arranged from right to left. */
    ARKUI_DIRECTION_RTL,
    /** The default layout direction is used. */
    ARKUI_DIRECTION_AUTO = 3,
} ArkUI_Direction;

/**
 * @brief Enumerates the modes in which components are laid out along the cross axis of the container.
 *
 * @since 12
 */
typedef enum {
    /** The default configuration in the container is used. */
    ARKUI_ITEM_ALIGNMENT_AUTO = 0,
    /** The items in the container are aligned with the cross-start edge. */
    ARKUI_ITEM_ALIGNMENT_START,
    /** The items in the container are centered along the cross axis. */
    ARKUI_ITEM_ALIGNMENT_CENTER,
    /** The items in the container are aligned with the cross-end edge. */
    ARKUI_ITEM_ALIGNMENT_END,
    /** The items in the container are stretched and padded along the cross axis. */
    ARKUI_ITEM_ALIGNMENT_STRETCH,
    /** The items in the container are aligned in such a manner that their text baselines are aligned along the
     *  cross axis. */
    ARKUI_ITEM_ALIGNMENT_BASELINE,
} ArkUI_ItemAlignment;

/**
 * @brief Enumerates the foreground colors.
 *
 * @since 12
 */
typedef enum {
    /** The foreground colors are the inverse of the component background colors. */
    ARKUI_COLOR_STRATEGY_INVERT = 0,
    /** The shadow colors of the component are the average color obtained from the component background shadow area. */
    ARKUI_COLOR_STRATEGY_AVERAGE,
    /** The shadow colors of the component are the primary color obtained from the component background shadow area. */
    ARKUI_COLOR_STRATEGY_PRIMARY,
} ArkUI_ColorStrategy;

/**
 * @brief Enumerates the vertical alignment modes.
 *
 * @since 12
 */
typedef enum {
    /** The child components are aligned with the start edge of the main axis. */
    ARKUI_FLEX_ALIGNMENT_START = 1,
    /** The child components are aligned in the center of the main axis. */
    ARKUI_FLEX_ALIGNMENT_CENTER = 2,
    /** The child components are aligned with the end edge of the main axis. */
    ARKUI_FLEX_ALIGNMENT_END = 3,
    /** The child components are evenly distributed along the main axis. The space between any two adjacent components
     *  is the same. The first component is aligned with the main-start, and the last component is aligned with
     *  the main-end. */
    ARKUI_FLEX_ALIGNMENT_SPACE_BETWEEN = 6,
    /** The child components are evenly distributed along the main axis. The space between any two adjacent components
     *  is the same. The space between the first component and main-start, and that between the last component and
     *  cross-main are both half the size of the space between two adjacent components. */
    ARKUI_FLEX_ALIGNMENT_SPACE_AROUND = 7,
    /** The child components are evenly distributed along the main axis. The space between the first component
     *  and main-start, the space between the last component and main-end, and the space between any two adjacent
     *  components are the same. */
    ARKUI_FLEX_ALIGNMENT_SPACE_EVENLY = 8,
} ArkUI_FlexAlignment;

/**
 * @brief Enumerates the directions of the main axis in the flex container.
 *
 * @since 12
 */
typedef enum {
    /** The child components are arranged in the same direction as the main axis runs along the rows. */
    ARKUI_FLEX_DIRECTION_ROW = 0,
    /** The child components are arranged in the same direction as the main axis runs down the columns. */
    ARKUI_FLEX_DIRECTION_COLUMN,
    /** The child components are arranged opposite to the <b>ROW</b> direction. */
    ARKUI_FLEX_DIRECTION_ROW_REVERSE,
    /** The child components are arranged opposite to the <b>COLUMN</b> direction. */
    ARKUI_FLEX_DIRECTION_COLUMN_REVERSE,
} ArkUI_FlexDirection;

/**
 * @brief Defines whether the flex container has a single line or multiple lines.
 *
 * @since 12
 */
typedef enum {
    /** The child components in the flex container are arranged in a single line, and they cannot overflow. */
    ARKUI_FLEX_WRAP_NO_WRAP = 0,
    /** The child components in the flex container are arranged in multiple lines, and they may overflow. */
    ARKUI_FLEX_WRAP_WRAP,
    /** The child components in the flex container are reversely arranged in multiple lines, and they may overflow. */
    ARKUI_FLEX_WRAP_WRAP_REVERSE,
} ArkUI_FlexWrap;

/**
 * @brief Enumerates the visibility values.
 *
 * @since 12
 */
typedef enum {
    /** The component is visible. */
    ARKUI_VISIBILITY_VISIBLE = 0,
    /** The component is hidden, and a placeholder is used for it in the layout. */
    ARKUI_VISIBILITY_HIDDEN,
    /** The component is hidden. It is not involved in the layout, and no placeholder is used for it. */
    ARKUI_VISIBILITY_NONE,
} ArkUI_Visibility;

/**
 * @brief Enumerates the alignment modes between the calendar picker and the entry component.
 *
 * @since 12
 */
typedef enum {
    /** Left aligned. */
    ARKUI_CALENDAR_ALIGNMENT_START = 0,
    /** Center aligned. */
    ARKUI_CALENDAR_ALIGNMENT_CENTER,
    /** Right aligned. */
    ARKUI_CALENDAR_ALIGNMENT_END,
} ArkUI_CalendarAlignment;

/**
 * @brief Enumerates the mask types.
 *
 * @since 12
 */
typedef enum {
    /** Rectangle. */
    ARKUI_MASK_TYPE_RECTANGLE = 0,
    /** Circle. */
    ARKUI_MASK_TYPE_CIRCLE,
    /** Ellipse. */
    ARKUI_MASK_TYPE_ELLIPSE,
    /** Path. */
    ARKUI_MASK_TYPE_PATH,
    /** Progress indicator. */
    ARKUI_MASK_TYPE_PROGRESS,
} ArkUI_MaskType;

/**
 * @brief Enumerates the clipping region types.
 *
 * @since 12
 */
typedef enum {
    /** Rectangle. */
    ARKUI_CLIP_TYPE_RECTANGLE = 0,
    /** Circle. */
    ARKUI_CLIP_TYPE_CIRCLE,
    /** Ellipse. */
    ARKUI_CLIP_TYPE_ELLIPSE,
    /** Path. */
    ARKUI_CLIP_TYPE_PATH,
} ArkUI_ClipType;

/**
 * @brief Defines the gradient color stop structure.
 *
 * @since 12
 */
typedef struct {
    /** Color array. */
    const uint32_t* colors;
    /** Position array. */
    float* stops;
    /** Length array. */
    int size;
} ArkUI_ColorStop;

/**
 * @brief Enumerates the custom shapes.
 *
 * @since 12
 */
typedef enum {
    /** Rectangle. */
    ARKUI_SHAPE_TYPE_RECTANGLE = 0,
    /** Circle. */
    ARKUI_SHAPE_TYPE_CIRCLE,
    /** Ellipse. */
    ARKUI_SHAPE_TYPE_ELLIPSE,
    /** Path. */
    ARKUI_SHAPE_TYPE_PATH,
} ArkUI_ShapeType;

/**
 * @brief Enumerates the gradient directions.
 *
 * @since 12
 */
typedef enum {
    /** From right to left. */
    ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT = 0,
    /** From bottom to top. */
    ARKUI_LINEAR_GRADIENT_DIRECTION_TOP,
    /** From left to right. */
    ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT,
    /** From top to bottom. */
    ARKUI_LINEAR_GRADIENT_DIRECTION_BOTTOM,
    /** From lower right to upper left. */
    ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_TOP,
    /** From upper right to lower left. */
    ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_BOTTOM,
    /** From lower left to upper right. */
    ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_TOP,
    /** From upper left to lower right. */
    ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_BOTTOM,
    /** No gradient. */
    ARKUI_LINEAR_GRADIENT_DIRECTION_NONE,
    /** Custom direction. */
    ARKUI_LINEAR_GRADIENT_DIRECTION_CUSTOM,
} ArkUI_LinearGradientDirection;

/**
 * @brief Enumerates the word break rules.
 *
 * @since 12
 */
typedef enum {
    /** Word breaks can occur between any two characters for Chinese, Japanese, and Korean (CJK) text, but can occur
     *  only at a space character for non-CJK text (such as English). */
    ARKUI_WORD_BREAK_NORMAL = 0,
    /** Word breaks can occur between any two characters for non-CJK text. CJK text behavior is the same as for
     *  <b>NORMAL</b>. */
    ARKUI_WORD_BREAK_BREAK_ALL,
    /** This option has the same effect as <b>BREAK_ALL</b> for non-CJK text, except that if it preferentially wraps
     *  lines at appropriate characters (for example, spaces) whenever possible.
        CJK text behavior is the same as for <b>NORMAL</b>. */
    ARKUI_WORD_BREAK_BREAK_WORD,
    /**
     * @brief Line breaks can occur between any two syllabic units for non-CJK text.
     * CJK text behavior is the same as for <b>NORMAL</b>.
     * @since 18
     */
    ARKUI_WORD_BREAK_HYPHENATION,
} ArkUI_WordBreak;

/**
 * @brief Enumerates the ellipsis positions.
 *
 * @since 12
 */
typedef enum {
    /** An ellipsis is used at the start of the line of text. */
    ARKUI_ELLIPSIS_MODE_START = 0,
    /** An ellipsis is used at the center of the line of text. */
    ARKUI_ELLIPSIS_MODE_CENTER,
    /** An ellipsis is used at the end of the line of text. */
    ARKUI_ELLIPSIS_MODE_END,
    /**
     *@brief An ellipsis is used at the start of the line of text for multiline and single line.
     *@since 24
     */
    ARKUI_ELLIPSIS_MODE_MULTILINE_START,
    /**
     *@brief An ellipsis is used at the center of the line of text for multiline and single line.
     *@since 24
     */
    ARKUI_ELLIPSIS_MODE_MULTILINE_CENTER,
} ArkUI_EllipsisMode;

/**
 * @brief Enumerates the image rendering modes.
 *
 * @since 12
 */
typedef enum {
    /** Render image pixels as they are in the original source image. */
    ARKUI_IMAGE_RENDER_MODE_ORIGINAL = 0,
    /** Render image pixels to create a monochrome template image. */
    ARKUI_IMAGE_RENDER_MODE_TEMPLATE,
} ArkUI_ImageRenderMode;

/**
 * @brief Enumerates the slide-in and slide-out positions of the component from the screen edge during transition.
 *
 * @since 12
 */
typedef enum {
    /** Top edge of the window. */
    ARKUI_TRANSITION_EDGE_TOP = 0,
    /** Bottom edge of the window. */
    ARKUI_TRANSITION_EDGE_BOTTOM,
    /** Left edge of the window. */
    ARKUI_TRANSITION_EDGE_START,
    /** Right edge of the window. */
    ARKUI_TRANSITION_EDGE_END,
} ArkUI_TransitionEdge;

/**
 * @brief Defines how the specified blend mode is applied.
 *
 * @since 12
 */
typedef enum {
    /** The content of the view is blended in sequence on the target image. */
    BLEND_APPLY_TYPE_FAST = 0,
    /** The content of the component and its child components are drawn on the offscreen canvas, and then blended with
     *  the existing content on the canvas. */
    BLEND_APPLY_TYPE_OFFSCREEN,
} ArkUI_BlendApplyType;

/**
 * @brief Defines a mask area.
 *
 * @since 12
 */
typedef struct {
    /** X coordinate of the mask area. */
    float x;
    /** Y coordinate of the mask area. */
    float y;
    /** Width of the mask area. */
    float width;
    /** Height of the mask area. */
    float height;
} ArkUI_Rect;

/**
 * @brief Describes the width and height of a component.
 *
 * @since 12
 */
typedef struct {
    /** Width, in px. */
    int32_t width;
    /** Height, in px. */
    int32_t height;
} ArkUI_IntSize;

/**
 * @brief Describes the position of a component.
 *
 * @since 12
 */
typedef struct {
    /** Horizontal coordinate, in px. */
    int32_t x;
    /** Vertical coordinate, in px. */
    int32_t y;
} ArkUI_IntOffset;

/**
 * @brief Enumerates the animation onFinish callback types.
 *
 * @since 12
 */
typedef enum {
    /** The callback is invoked when the entire animation is removed once it has finished. */
    ARKUI_FINISH_CALLBACK_REMOVED = 0,
    /** The callback is invoked when the animation logically enters the falling state, though it may still be in its
      * long tail state. */
    ARKUI_FINISH_CALLBACK_LOGICALLY,
} ArkUI_FinishCallbackType;

/**
 * @brief Enumerates the alignment modes of items along the cross axis.
  *
 * @since 12
 */
typedef enum {
    /** The list items are packed toward the start edge of the list container along the cross axis. */
    ARKUI_LIST_ITEM_ALIGNMENT_START = 0,
    /** The list items are centered in the list container along the cross axis. */
    ARKUI_LIST_ITEM_ALIGNMENT_CENTER,
    /** The list items are packed toward the end edge of the list container along the cross axis. */
    ARKUI_LIST_ITEM_ALIGNMENT_END,
} ArkUI_ListItemAlignment;

/**
  * @brief defines the direction of the barrier line.
  *
  * @since 12
  */
typedef enum {
    /** The barrier is the leftmost of all its referencedIds. */
    ARKUI_BARRIER_DIRECTION_START = 0,
    /** The barrier is on the rightmost side of all its referencedIds. */
    ARKUI_BARRIER_DIRECTION_END,
    /** The barrier is at the top of all its referencedIds. */
    ARKUI_BARRIER_DIRECTION_TOP,
    /** The barrier is at the bottom of all its referencedIds. */
    ARKUI_BARRIER_DIRECTION_BOTTOM
} ArkUI_BarrierDirection;

/**
  * @brief defines the style of the chain.
  *
  * @since 12
  */
typedef enum {
    /** Components are evenly distributed among constraint anchor points. */
    ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_SPREAD = 0,
    /** Except for the first and last two sub-components,
      * other components are evenly distributed between the constraint anchor points. */
    ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_SPREAD_INSIDE,
    /** No gaps in subcomponents within the chain. */
    ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_PACKED,
} ArkUI_RelativeLayoutChainStyle;

/**
 * @brief Describes the margins of a component.
 *
 * @since 12
 */
typedef struct {
    /** Top margin, in vp. */
    float top;
    /** Right margin, in vp. */
    float right;
    /** Bottom margin, in vp. */
    float bottom;
    /** Left margin, in vp. */
    float left;
} ArkUI_Margin;

/**
 * @brief Enumerates the component units.
 *
 * @since 12
 */
typedef enum {
    /** Default, which is fp for fonts and vp for non-fonts. */
    ARKUI_LENGTH_METRIC_UNIT_DEFAULT = -1,
    /** px. */
    ARKUI_LENGTH_METRIC_UNIT_PX = 0,
    /** vp. */
    ARKUI_LENGTH_METRIC_UNIT_VP,
    /** fp. */
    ARKUI_LENGTH_METRIC_UNIT_FP
} ArkUI_LengthMetricUnit;

/**
 * @brief Enumerates the render fit.
 *
 * @since 12
 */
typedef enum {
    /** Maintains the content size of the animation's final state,
      * and the content is always centered with the component.*/
    ARKUI_RENDER_FIT_CENTER = 0,
    /** Maintains the content size of the animation's final state,
      * and the content is always aligned with the top center of the component. */
    ARKUI_RENDER_FIT_TOP,
    /** Maintains the content size of the animation's final state,
      * and the content is always aligned with the bottom center of the component. */
    ARKUI_RENDER_FIT_BOTTOM,
    /** Maintains the content size of the animation's final state,
      * and the content is always aligned to the left of the component. */
    ARKUI_RENDER_FIT_LEFT,
    /** Maintains the content size of the animation's final state,
      * and the content is always right-aligned with the component. */
    ARKUI_RENDER_FIT_RIGHT,
    /** Maintains the content size of the animation's final state,
      * and the content is always aligned with the top left corner of the component. */
    ARKUI_RENDER_FIT_TOP_LEFT,
    /** Keep the content size of the animation final state,
      * and the content is always aligned with the upper right corner of the component. */
    ARKUI_RENDER_FIT_TOP_RIGHT,
    /** Keep the content size of the animation final state,
      * and the content always aligns with the lower-left corner of the component. */
    ARKUI_RENDER_FIT_BOTTOM_LEFT,
    /** Keep the content size of the animation final state,
      *and the content always aligns with the lower-right corner of the component. */
    ARKUI_RENDER_FIT_BOTTOM_RIGHT,
    /** The aspect ratio of the animation's final state content is not considered,
      *and the content is always scaled to the size of the component. */
    ARKUI_RENDER_FIT_RESIZE_FILL,
    /** Reduce or enlarge the aspect ratio of the animation final state content,
      * so that the content is fully displayed in the component,
      * and keep the center aligned with the component. */
    ARKUI_RENDER_FIT_RESIZE_CONTAIN,
    /** Keep the aspect ratio of the animation final state content to reduce or enlarge,
      * so that the content is fully displayed in the component.
      * When there is left over in the broad direction of the component,
      * the content is aligned to the left of the component,
      * and when there is left over in the high direction of the component,
      * the content is aligned to the top of the component. */
    ARKUI_RENDER_FIT_RESIZE_CONTAIN_TOP_LEFT,
    /** Keep the aspect ratio of the animation final state content to reduce or enlarge,
      * so that the content is fully displayed in the component.
      * When there is left in the wide direction of the component,
      * the content is aligned with the component on the right.
      * When there is left in the high direction of the component,
      * the content is aligned with the component on the bottom. */
    ARKUI_RENDER_FIT_RESIZE_CONTAIN_BOTTOM_RIGHT,
    /** Keep the aspect ratio of the animation final state content reduced or enlarged,
      * so that both sides of the content are greater than or equal to both sides of the component,
      * and keep the center aligned with the component to display the middle part of the content. */
    ARKUI_RENDER_FIT_RESIZE_COVER,
    /** Keep the aspect ratio of the final content of the animation reduced or enlarged
      * so that both sides of the content are exactly greater than or equal to both sides of the component.
      * When the content width is left, the content is aligned to the left of the component,
      * and the left portion of the content is displayed. When the content is left in the high direction,
      * the content and the component remain top aligned, showing the top side of the content. */
    ARKUI_RENDER_FIT_RESIZE_COVER_TOP_LEFT,
    /** Keep the aspect ratio of the final content of the animation reduced or enlarged so
      * that both sides of the content are exactly greater than or equal to both sides of the component.
      * When the content width is left, the content and the component remain right aligned,
      * and the right part of the content is displayed. When the content is left in the high direction,
      * the content and the component remain aligned at the bottom,
      * and the bottom part of the content is displayed. */
    ARKUI_RENDER_FIT_RESIZE_COVER_BOTTOM_RIGHT
} ArkUI_RenderFit;

/**
 * @brief Enumerates the button types.
 *
 * @since 12
 */
typedef enum {
    /** Normal button (without rounded corners by default). */
    ARKUI_BUTTON_TYPE_NORMAL = 0,
    /** Capsule-type button (the round corner is half of the height by default). */
    ARKUI_BUTTON_TYPE_CAPSULE,
    /** Circle button. */
    ARKUI_BUTTON_TYPE_CIRCLE,
    /**
     * Rounded rectangle button.
     * @since 19
     */
    ARKUI_BUTTON_ROUNDED_RECTANGLE = 8
} ArkUI_ButtonType;

/**
 * @brief Enumerates the autofill types.
 *
 * @since 12
 */
typedef enum {
    /** Username. Password Vault, when enabled, can automatically save and fill in usernames. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_USER_NAME = 0,
    /** Password. Password Vault, when enabled, can automatically save and fill in passwords. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_PASSWORD,
    /** New password. Password Vault, when enabled, can automatically generate a new password. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_NEW_PASSWORD,
    /** Full street address. The scenario-based autofill feature, when enabled, can automatically save and fill in full
     *  street addresses. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_FULL_STREET_ADDRESS,
    /** House number. The scenario-based autofill feature, when enabled, can automatically save and fill in house
     *  numbers. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_HOUSE_NUMBER,
    /** District and county. The scenario-based autofill feature, when enabled, can automatically save and fill in
     *  districts and counties. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_DISTRICT_ADDRESS,
    /** City. The scenario-based autofill feature, when enabled, can automatically save and fill in cities. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_CITY_ADDRESS,
    /** Province. The scenario-based autofill feature, when enabled, can automatically save and fill in provinces. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_PROVINCE_ADDRESS,
    /** Country. The scenario-based autofill feature, when enabled, can automatically save and fill in countries. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_COUNTRY_ADDRESS,
    /** Full name. The scenario-based autofill feature, when enabled, can automatically save and fill in full names. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_FULL_NAME,
    /** Last name. The scenario-based autofill feature, when enabled, can automatically save and fill in last names. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_LAST_NAME,
    /** First name. The scenario-based autofill feature, when enabled, can automatically save and fill in first names.
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_FIRST_NAME,
    /** Phone number. The scenario-based autofill feature, when enabled, can automatically save and fill in phone
     *  numbers. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_PHONE_NUMBER,
    /** Country code. The scenario-based autofill feature, when enabled, can automatically save and fill in country
     *  codes. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_PHONE_COUNTRY_CODE,
    /** Phone number with country code. The scenario-based autofill feature, when enabled, can automatically save and
     *  fill in phone numbers with country codes. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_FULL_PHONE_NUMBER,
    /** Email address. The scenario-based autofill feature, when enabled, can automatically save and fill in email
     *  addresses. */
    ARKUI_TEXTINPUT_CONTENT_EMAIL_ADDRESS,
    /** Bank card number. The scenario-based autofill feature, when enabled, can automatically save and fill in bank
     *  card numbers. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_BANK_CARD_NUMBER,
    /** ID card number. The scenario-based autofill feature, when enabled, can automatically save and fill in ID card
     *  numbers. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_ID_CARD_NUMBER,
    /** Nickname. The scenario-based autofill feature, when enabled, can automatically save and fill in nicknames. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_NICKNAME,
    /** Address information without street address. The scenario-based autofill feature, when enabled, can automatically
     *  save and fill in address information without street addresses. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_DETAIL_INFO_WITHOUT_STREET,
    /** Standard address. The scenario-based autofill feature, when enabled, can automatically save and fill in standard
     *  addresses. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_FORMAT_ADDRESS,
    /**
     * Passport number. The scenario-based autofill feature, when enabled, can automatically save and fill in passport
     * numbers.
     * @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_PASSPORT_NUMBER,
    /**
     *  Passport validity. The scenario-based autofill feature, when enabled, can automatically save and fill in
     *  passport validities.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_VALIDITY,
    /**
     *  Place of issue. The scenario-based autofill feature, when enabled, can automatically save and fill in
     *  place of issues.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_ISSUE_AT,
    /**
     *  Tax organization. The scenario-based autofill feature, when enabled, can automatically save and fill in tax
     *  organizations.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_ORGANIZATION,
    /**
     *  Tax id. The scenario-based autofill feature, when enabled, can automatically save and fill in standard Tax ids.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_TAX_ID,
    /**
     *  City name and state name or state code. The scenario-based autofill feature, when enabled, can automatically
     *  save and fill in city names and state names or state codes.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_ADDRESS_CITY_AND_STATE,
    /**
     *  Flight number. The scenario-based autofill feature, when enabled, can automatically save and fill in flight
     *  numbers.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_FLIGHT_NUMBER,
    /**
     *  License number. The scenario-based autofill feature, when enabled, can automatically save and fill in license
     *  numbers.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_LICENSE_NUMBER,
    /**
     *  License file number. The scenario-based autofill feature, when enabled, can automatically save and fill in
     *  license file numbers.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_LICENSE_FILE_NUMBER,
    /**
     *  License plate number. The scenario-based autofill feature, when enabled, can automatically save and fill in
     *  license plate numbers.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_LICENSE_PLATE,
    /**
     *  Engine number. The scenario-based autofill feature, when enabled, can automatically save and fill in engine
     *  numbers.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_ENGINE_NUMBER,
    /**
     *  License chassis number. The scenario-based autofill feature, when enabled, can automatically save and fill in
     *  license chassis numbers.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_LICENSE_CHASSIS_NUMBER,
} ArkUI_TextInputContentType;

/**
 * @brief Defines the text input style.
 *
 * @since 12
 */
typedef enum {
    /** Default style. The caret width is fixed at 1.5 vp, and the caret height is subject to the background height and
     *  font size of the selected text. */
    ARKUI_TEXTINPUT_STYLE_DEFAULT = 0,
    /** Inline input style. The background height of the selected text is the same as the height of the text box. */
    ARKUI_TEXTINPUT_STYLE_INLINE
} ArkUI_TextInputStyle;

/**
 * @brief Defines the keyboard style of input box
 *
 * @since 15
 */
typedef enum {
    /**
     * Default appearance mode, won't adopt immersive styles.
     * @since 15
     */
    ARKUI_KEYBOARD_APPEARANCE_NONE_IMMERSIVE = 0,
    /**
     * Immersive mode.
     * @since 15
     */
    ARKUI_KEYBOARD_APPEARANCE_IMMERSIVE = 1,
    /**
     * Light immersive style.
     * @since 15
     */
    ARKUI_KEYBOARD_APPEARANCE_LIGHT_IMMERSIVE = 2,
    /**
     * Dark immersive style.
     * @since 15
     */
    ARKUI_KEYBOARD_APPEARANCE_DARK_IMMERSIVE = 3,
} ArkUI_KeyboardAppearance;

/**
 * @brief Defines the entity type for text recognition.
 *
 * @since 12
 */
typedef enum {
    /** Phone Number.*/
    ARKUI_TEXT_DATA_DETECTOR_TYPE_PHONE_NUMBER = 0,
    /** Link. */
    ARKUI_TEXT_DATA_DETECTOR_TYPE_URL,
    /** Mailbox. */
    ARKUI_TEXT_DATA_DETECTOR_TYPE_EMAIL,
    /** Address. */
    ARKUI_TEXT_DATA_DETECTOR_TYPE_ADDRESS,
} ArkUI_TextDataDetectorType;

/**
 * @brief Define the navigation indicator type of the swiper.
 *
 * @since 12
 */
typedef enum {
    /** dot type. */
    ARKUI_SWIPER_INDICATOR_TYPE_DOT,
    /** digit type. */
    ARKUI_SWIPER_INDICATOR_TYPE_DIGIT,
} ArkUI_SwiperIndicatorType;

/**
 * @brief Define the pattern of element arrangement in the main axis direction of the Swiper component.
 *
 * @since 12
 */
typedef enum {
    /** In the folded state, when the ListItem slides in the opposite direction to the main axis,
     * the operation item is hidden.*/
    ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_COLLAPSED = 0,
    /** In the folded state, when the ListItem slides in the opposite direction to the spindle,
     * the operation item is displayed.*/
    ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_EXPANDED,
    /** Long distance state, the state of deleting a ListItem after it enters the long distance deletion area.*/
    ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_ACTIONING,
} ArkUI_ListItemSwipeActionState;

/**
 * @brief Define the explicit and implicit mode of the SwipeAction method for the Listitem component.
 *
 * @since 12
 */
typedef enum {
    /** The ListItem can continue to be scratched after the distance exceeds the size of the scratched component.*/
    ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_SPRING = 0,
    /** The sliding distance of the ListItem cannot exceed the size of the scratched component.*/
    ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_NONE,
} ArkUI_ListItemSwipeEdgeEffect;

/**
 * @brief Define error code enumeration values.
 *
 * @since 12
 */
typedef enum {
    /** @error No errors. */
    ARKUI_ERROR_CODE_NO_ERROR = 0,
    /** @error Parameter error. */
    ARKUI_ERROR_CODE_PARAM_INVALID = 401,
    /**
     * @error CAPI init error.
     * @since 18
     */
    ARKUI_ERROR_CODE_CAPI_INIT_ERROR = 500,
    /**
     * @error Internal error occurs, such as failure occurs because of the internal environment error,
     * or operation failed because of the internal execution failed.
     * @since 15
     */
    ARKUI_ERROR_CODE_INTERNAL_ERROR = 100001,
    /**
     * @error The XComponent is in invalid state.
     * @since 19
     */
    ARKUI_ERROR_CODE_XCOMPONENT_STATE_INVALID = 103501,
    /** @error The component does not support specific properties or events. */
    ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED = 106102,
    /** @error The corresponding operation does not support nodes created by ArkTS. */
    ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED = 106103,
    /** @error The lazy loading adapter is not bound to the component. */
    ARKUI_ERROR_CODE_ADAPTER_NOT_BOUND = 106104,
    /** @error The adapter already exists. */
    ARKUI_ERROR_CODE_ADAPTER_EXIST = 106105,
    /** @error The corresponding node already has a child node and cannot add an adapter. */
    ARKUI_ERROR_CODE_CHILD_NODE_EXIST = 106106,
    /** The parameter length in the parameter event exceeds the limit. */
    ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INDEX_OUT_OF_RANGE = 106107,
    /** The data does not exist in the component event. */
    ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INVALID = 106108,
    /** The component event does not support return values. */
    ARKUI_ERROR_CODE_NODE_EVENT_NO_RETURN = 106109,
    /**
     * @error The event type is not supported by the node.
     * @since 21
     */
    ARKUI_ERROR_CODE_NODE_UNSUPPORTED_EVENT_TYPE = 106110,
    /** The index value is invalid. */
    ARKUI_ERROR_CODE_NODE_INDEX_INVALID = 106200,
    /**  Failed to query route navigation information. */
    ARKUI_ERROR_CODE_GET_INFO_FAILED = 106201,
    /** The buffer size is not large enough. */
    ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR = 106202,
    /**
     * @error The node is not on main tree.
     * @since 15
     */
    ARKUI_ERROR_CODE_NODE_NOT_ON_MAIN_TREE = 106203,
    /**
     * @error The node is running on invalid thread.
     * @since 22
     */
    ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD = 106204,
    /**
     * @error Force dark config is invalid.
     * @since 20
     */
    ARKUI_ERROR_CODE_FORCE_DARK_CONFIG_INVALID = 106205,
    /**
     * @error The node has already been adopted.
     * @since 22
     */
    ARKUI_ERROR_CODE_NODE_IS_ADOPTED = 106206,
    /**
     * @error This node already has a parent node.
     * @since 22
     */
    ARKUI_ERROR_CODE_NODE_HAS_PARENT = 106207,
    /**
     * @error The node cannot be adopted.
     * @since 22
     */
    ARKUI_ERROR_CODE_NODE_CAN_NOT_BE_ADOPTED = 106208,
    /**
     * @error The node cannot adopt children.
     * @since 22
     */
    ARKUI_ERROR_CODE_NODE_CAN_NOT_ADOPT_TO = 106209,
    /**
     * @error This child node is not adopted by the parent node.
     * @since 22
     */
    ARKUI_ERROR_CODE_NODE_IS_NOT_IN_ADOPTED_CHILDREN = 106210,
    /**
     * @error The node type is not custom node.
     * @since 20
     */
    ARKUI_ERROR_CODE_NOT_CUSTOM_NODE = 106401,
    /**
     * @error Node already has children.
     * @since 20
     */
    ARKUI_ERROR_CODE_CHILD_EXISTED = 106402,
    /**
     * @error RenderNode parent is existed.
     * @since 20
     */
    ARKUI_ERROR_CODE_RENDER_PARENT_EXISTED = 106403,
    /**
     * @error RenderNode child is not exist.
     * @since 20
     */
    ARKUI_ERROR_CODE_RENDER_CHILD_NOT_EXIST = 106404,
    /**
     * @error Param is out of range.
     * @since 20
     */
    ARKUI_ERROR_CODE_PARAM_OUT_OF_RANGE = 106405,
    /**
     * @error The RenderNode is obtained from a FrameNode.
     * @since 22
     */
    ARKUI_ERROR_CODE_RENDER_IS_FROM_FRAME_NODE = 106406,
    /**
     * @error The RenderNode is obtained from a FrameNode,
     * and its corresponding FrameNode is no longer in the adopted state.
     * @since 22
     */
    ARKUI_ERROR_CODE_RENDER_HAS_INVALID_FRAME_NODE = 106407,
    /**
     * @error The node is not adopted.
     * @since 22
     */
    ARKUI_ERROR_CODE_RENDER_NOT_ADOPTED_NODE = 106408,
    /**
     * @error The node requesting focus is not focusable.
     * @since 15
     */
    ARKUI_ERROR_CODE_FOCUS_NON_FOCUSABLE = 150001,
    /**
     * @error The node requesting focus has unfocusable ancestor.
     * @since 15
     */
    ARKUI_ERROR_CODE_FOCUS_NON_FOCUSABLE_ANCESTOR = 150002,
    /**
     * @error The node requesting focus does not exists.
     * @since 15
     */
    ARKUI_ERROR_CODE_FOCUS_NON_EXISTENT = 150003,
    /**
     * @error The snapshot taking is timeout.
     * @since 15
     */
    ARKUI_ERROR_CODE_COMPONENT_SNAPSHOT_TIMEOUT = 160002,
    /**
     * @error The provided color space or dynamic range mode is not supported. For details about the error codes,
     * see [Snapshot Error Codes](../apis-arkui/errorcode-snapshot.md).
     * @since 23
     */
    ARKUI_ERROR_CODE_COMPONENT_SNAPSHOT_MODE_NOT_SUPPORTED = 160003,
    /**
     * @error The isAuto parameter of the color space or dynamic range mode is set to true for offscreen node snapshot.
     * For details about the error codes, see [Snapshot Error Codes](../apis-arkui/errorcode-snapshot.md).
     * @since 23
     */
    ARKUI_ERROR_CODE_COMPONENT_SNAPSHOT_AUTO_NOT_SUPPORTED = 160004,
    /** The component is not a scroll container. */
    ARKUI_ERROR_CODE_NON_SCROLLABLE_CONTAINER = 180001,
    /** The buffer is not large enough. */
    ARKUI_ERROR_CODE_BUFFER_SIZE_NOT_ENOUGH = 180002,
    /**
     * @error The event is not a clone event.
     * @since 15
     */
    ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT = 180003,
    /**
     * @error The component status is abnormal.
     * @since 15
     */
    ARKUI_ERROR_CODE_POST_CLONED_COMPONENT_STATUS_ABNORMAL = 180004,
    /**
     * @error No component hit to respond to the event.
     * @since 15
     */
    ARKUI_ERROR_CODE_POST_CLONED_NO_COMPONENT_HIT_TO_RESPOND_TO_THE_EVENT = 180005,
    /**
     * @error Input event type not supported.
     * @since 20
     */
    ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED = 180006,
    /**
     * @error invalid styled string.
     * @since 14
     */
    ARKUI_ERROR_CODE_INVALID_STYLED_STRING = 180101,
    /**
     * @error The gesture recognizer type is not supported.
     * @since 18
     */
    ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED = 180102,
    /**
     * @error The uiContext is invalid.
     * @since 18
     */
    ARKUI_ERROR_CODE_UI_CONTEXT_INVALID = 190001,
    /**
     * @error The callback function is invalid.
     * @since 18
     */
    ARKUI_ERROR_CODE_CALLBACK_INVALID = 190002,
    /**
     * @error operation is not allowed for current drag drop pharse.
     * @since 19
     */
    ARKUI_ERROR_CODE_DRAG_DROP_OPERATION_NOT_ALLOWED = 190004,
    /**
     * @error Parameter error.
     * @since 21
     */
    ARKUI_ERROR_CODE_PARAM_ERROR = 100023,
} ArkUI_ErrorCode;

/**
 * @brief Defines the playback status for the image animator.
 *
 * @since 12
*/
typedef enum {
    /** The animation is in the initial state. */
    ARKUI_ANIMATION_STATUS_INITIAL,
    /** The animation is being played. */
    ARKUI_ANIMATION_STATUS_RUNNING,
    /** The animation is paused. */
    ARKUI_ANIMATION_STATUS_PAUSED,
    /** The animation is stopped. */
    ARKUI_ANIMATION_STATUS_STOPPED,
} ArkUI_AnimationStatus;

/**
 * @brief Defines the status before and after execution of the animation in the current playback direction.
 *
 * @since 12
*/
typedef enum {
    /** Before execution, the animation does not apply any styles to the target component.
     * After execution, the animation restores the target component to its default state. */
    ARKUI_ANIMATION_FILL_MODE_NONE,
    /** The target component retains the state set by the last keyframe encountered
     * during execution of the animation. */
    ARKUI_ANIMATION_FILL_MODE_FORWARDS,
    /** The animation applies the values defined in the first relevant keyframe once it is applied to
     * the target component, and retains the values during the period set by delay. */
    ARKUI_ANIMATION_FILL_MODE_BACKWARDS,
    /** The animation follows the rules for both Forwards and Backwards,
     * extending the animation attributes in both directions. */
    ARKUI_ANIMATION_FILL_MODE_BOTH,
} ArkUI_AnimationFillMode;

/**
 * @brief Defines the state type for the accessibility checkbox.
 *
 * @since 12
 */
typedef enum {
    /** The Checkbox unchecked. */
    ARKUI_ACCESSIBILITY_UNCHECKED = 0,
    /** The Checkbox checked. */
    ARKUI_ACCESSIBILITY_CHECKED,
} ArkUI_AccessibilityCheckedState;

/**
 * @brief Enumerates the animation playback modes.
 *
 * @since 12
 */
typedef enum {
    /** The animation plays in forward loop mode. */
    ARKUI_ANIMATION_DIRECTION_NORMAL = 0,
    /** The animation plays in reverse loop mode. */
    ARKUI_ANIMATION_DIRECTION_REVERSE,
    /** The animation plays in alternating loop mode. When the animation is played for an odd number of times, the
     *  playback is in forward direction. When the animation is played for an even number of times, the playback is in
     *  reverse direction. */
    ARKUI_ANIMATION_DIRECTION_ALTERNATE,
    /** The animation plays in reverse alternating loop mode. When the animation is played for an odd number of times,
     *  the playback is in reverse direction. When the animation is played for an even number of times, the playback is
     *  in forward direction. */
    ARKUI_ANIMATION_DIRECTION_ALTERNATE_REVERSE,
} ArkUI_AnimationDirection;

/**
 * @brief Enumerates the hover effects when a component is hovered over.
 *
 * @since 23
 */
typedef enum {
    /** Default effect. */
    ARKUI_HOVER_EFFECT_AUTO = 0,
    /** Scale effect. */
    ARKUI_HOVER_EFFECT_SCALE,
    /** Highlight effect. */
    ARKUI_HOVER_EFFECT_HIGHLIGHT,
    /** No effect. */
    ARKUI_HOVER_EFFECT_NONE,
} ArkUI_HoverEffect;

/**
 * @brief Enumerates the priority levels for focus management within the application.
 * These levels determine the sequence in which UI components receive focus during user interaction.
 *
 * @since 23
 */
typedef enum {
    /** Default priority. */
    ARKUI_FOCUS_PRIORITY_AUTO = 0,
    /** Higher priority. */
    ARKUI_FOCUS_PRIORITY_PRIOR = 2000,
    /** Previous focus priority. */
    ARKUI_FOCUS_PRIORITY_PREVIOUS = 3000,
} ArkUI_FocusPriority;

/**
 * @brief Define the rolling source enumeration value.
 *
 * @since 12
 */
typedef enum {
    /** Finger drag. */
    ARKUI_SCROLL_SOURCE_DRAG = 0,
    /** Inertial roll after finger drag. */
    ARKUI_SCROLL_SOURCE_FLING,
    /** Execute the EdgeEffect.Spring edge effect when crossing the boundary.*/
    ARKUI_SCROLL_SOURCE_EDGE_EFFECT,
    /** Other user input other than dragging, such as mouse wheel, keyboard events, etc.*/
    ARKUI_SCROLL_SOURCE_OTHER_USER_INPUT,
    /** Drag the scroll bar.*/
    ARKUI_SCROLL_SOURCE_SCROLL_BAR,
    /** Inertia scrolling after dragging the scroll bar.*/
    ARKUI_SCROLL_SOURCE_SCROLL_BAR_FLING,
    /** The scroll controller causes unanimated scrolling.*/
    ARKUI_SCROLL_SOURCE_SCROLLER,
    /** The scroll controller causes the scroll to drive the painting.*/
    ARKUI_SCROLL_SOURCE_ANIMATION,
} ArkUI_ScrollSource;

/**
 * @brief Define accessible action types.
 *
 * @since 12
 */
typedef enum {
    /** click action. */
    ARKUI_ACCESSIBILITY_ACTION_CLICK = 1 << 0,
    /** long click action. */
    ARKUI_ACCESSIBILITY_ACTION_LONG_CLICK = 1 << 1,
    /** cut action. */
    ARKUI_ACCESSIBILITY_ACTION_CUT = 1 << 2,
    /** copy action. */
    ARKUI_ACCESSIBILITY_ACTION_COPY = 1 << 3,
    /** paste action. */
    ARKUI_ACCESSIBILITY_ACTION_PASTE = 1 << 4,
} ArkUI_AccessibilityActionType;

/**
 * @brief Defines the translation options for component transition.
 *
 * @since 12
 */
typedef struct {
    /** Translation distance along the x-axis. */
    float x;
    /** Translation distance along the y-axis. */
    float y;
    /** Translation distance along the z-axis. */
    float z;
} ArkUI_TranslationOptions;

/**
 * @brief Defines the scaling options for component transition.
 *
 * @since 12
 */
typedef struct {
    /** Scale ratio along the x-axis. */
    float x;
    /** Scale ratio along the y-axis. */
    float y;
    /** Scale factor along the z-axis (not effective for the current 2D graphics). */
    float z;
    /** X coordinate of the center point. */
    float centerX;
    /** Y coordinate of the center point. */
    float centerY;
} ArkUI_ScaleOptions;

/**
 * @brief Defines the rotation options for component transition.
 *
 * @since 12
 */
typedef struct {
    /** X-component of the rotation vector. */
    float x;
    /** Y-component of the rotation vector. */
    float y;
    /** Z-component of the rotation vector. */
    float z;
    /** Rotation angle. */
    float angle;
    /** X coordinate of the center point. */
    float centerX;
    /** Y coordinate of the center point. */
    float centerY;
    /** Z-axis anchor, that is, the z-component of the 3D rotation center point. */
    float centerZ;
    /** Distance from the user to the z=0 plane. */
    float perspective;
} ArkUI_RotationOptions;

/**
 * @brief Defines a struct for the measurement information of a custom span.
 *
 * @since 12
 */
typedef struct ArkUI_CustomSpanMeasureInfo ArkUI_CustomSpanMeasureInfo;

/**
 * @brief Defines a struct for the measurement metrics of a custom span.
 *
 * @since 12
 */
typedef struct ArkUI_CustomSpanMetrics ArkUI_CustomSpanMetrics;

/**
 * @brief Defines a struct for the drawing information of a custom span.
 *
 * @since 12
 */
typedef struct ArkUI_CustomSpanDrawInfo ArkUI_CustomSpanDrawInfo;

/**
 * @brief Defines the state of the NavDestination component.
 *
 * @since 12
 */
typedef enum {
    /** The NavDestination show. */
    ARKUI_NAV_DESTINATION_STATE_ON_SHOW = 0,
    /** The NavDestination hide. */
    ARKUI_NAV_DESTINATION_STATE_ON_HIDE = 1,
    /** The NavDestination is mounted to the component tree. */
    ARKUI_NAV_DESTINATION_STATE_ON_APPEAR = 2,
    /** The NavDestination removed from the component tree. */
    ARKUI_NAV_DESTINATION_STATE_ON_DISAPPEAR = 3,
    /** Before the NavDestination show. */
    ARKUI_NAV_DESTINATION_STATE_ON_WILL_SHOW = 4,
    /** Before the NavDestination hide. */
    ARKUI_NAV_DESTINATION_STATE_ON_WILL_HIDE = 5,
    /** Before the NavDestination mount to the component tree. */
    ARKUI_NAV_DESTINATION_STATE_ON_WILL_APPEAR = 6,
    /** Before the NavDestination removed from the component tree. */
    ARKUI_NAV_DESTINATION_STATE_ON_WILL_DISAPPEAR = 7,
    /** The NavDestination returns from the component.*/
    ARKUI_NAV_DESTINATION_STATE_ON_BACK_PRESS = 100,
} ArkUI_NavDestinationState;

/**
 * @brief Define the state of Router Page.
 *
 * @since 12
 */
typedef enum {
    /** The Router Page is about to be created. */
    ARKUI_ROUTER_PAGE_STATE_ABOUT_TO_APPEAR = 0,
    /** The Router Page is about to be destroyed. */
    ARKUI_ROUTER_PAGE_STATE_ABOUT_TO_DISAPPEAR = 1,
    /** The Router Page show. */
    ARKUI_ROUTER_PAGE_STATE_ON_SHOW = 2,
    /** The Router Page hide. */
    ARKUI_ROUTER_PAGE_STATE_ON_HIDE = 3,
    /** The Router Page returns. */
    ARKUI_ROUTER_PAGE_STATE_ON_BACK_PRESS = 4,
} ArkUI_RouterPageState;

/**
 * @brief defines the enumerated value of the extended security zone.
 *
 * @since 12
 */
typedef enum {
    /** The default security zone includes the status bar and navigation bar. */
    ARKUI_SAFE_AREA_TYPE_SYSTEM = 1,
    /** Non-secure areas of the device, such as bangs or hole holes. */
    ARKUI_SAFE_AREA_TYPE_CUTOUT = 1 << 1,
    /** Soft keyboard area. */
    ARKUI_SAFE_AREA_TYPE_KEYBOARD = 1 << 2,
} ArkUI_SafeAreaType;

/**
 * @brief Define an enum for the areas of the <b>ListItemGroup</b> component.
 *
 * @since 15
 */
typedef enum {
    /** Outside the area of the <b>ListItemGroup</b> component. */
    ARKUI_LIST_ITEM_GROUP_AREA_OUTSIDE = 0,
    /** Area when the <b>ListItemGroup</b> component does not have the header, footer, or list item. */
    ARKUI_LIST_ITEM_SWIPE_AREA_NONE,
    /** List item area of the <b>ListItemGroup</b> component. */
    ARKUI_LIST_ITEM_SWIPE_AREA_ITEM,
    /** Header area of the <b>ListItemGroup</b> component. */
    ARKUI_LIST_ITEM_SWIPE_AREA_HEADER,
    /** Footer area of the <b>ListItemGroup</b> component. */
    ARKUI_LIST_ITEM_SWIPE_AREA_FOOTER,
} ArkUI_ListItemGroupArea;

/**
 * @brief defines the enumerated value of the direction of the extended security zone.
 *
 * @since 12
 */
typedef enum {
    /** Upper area. */
    ARKUI_SAFE_AREA_EDGE_TOP = 1,
    /** Lower area. */
    ARKUI_SAFE_AREA_EDGE_BOTTOM = 1 << 1,
    /** Front area. */
    ARKUI_SAFE_AREA_EDGE_START = 1 << 2,
    /** Tail area. */
    ARKUI_SAFE_AREA_EDGE_END = 1 << 3,
} ArkUI_SafeAreaEdge;

/**
 * @brief Define an enum for the focus movement directions.
 *
 * @since 18
*/
typedef enum {
    /** Move focus forward. */
    ARKUI_FOCUS_MOVE_FORWARD = 0,
    /** Move focus backward. */
    ARKUI_FOCUS_MOVE_BACKWARD,
    /** Move focus up. */
    ARKUI_FOCUS_MOVE_UP,
    /** Move focus down. */
    ARKUI_FOCUS_MOVE_DOWN,
    /** Move focus left. */
    ARKUI_FOCUS_MOVE_LEFT,
    /** Move focus right. */
    ARKUI_FOCUS_MOVE_RIGHT,
} ArkUI_FocusMove;

/**
 * @brief defines the enumerated value of the customDialog's keyboard avoid mode.
 *
 * @since 15
 */
typedef enum {
    /** Defines avoid keyboard when keyboard shows. */
    ARKUI_KEYBOARD_AVOID_MODE_DEFAULT = 0,
    /** Defines not avoid keyboard when keyboard shows. */
    ARKUI_KEYBOARD_AVOID_MODE_NONE,
} ArkUI_KeyboardAvoidMode;

/**
 * @brief defines the enumerated value of area in hover mode.
 *
 * @since 15
 */
typedef enum {
    /** Layout top half screen when the phone in hover mode. */
    ARKUI_HOVER_MODE_AREA_TYPE_TOP = 0,
    /** Layout bottom half screen when the phone in hover mode. */
    ARKUI_HOVER_MODE_AREA_TYPE_BOTTOM,
} ArkUI_HoverModeAreaType;

/**
 * @brief Enumerates the expand modes.
 *
 * @since 15
 */
typedef enum {
    /** Not expand. */
    ARKUI_NOT_EXPAND = 0,
    /** Expand. */
    ARKUI_EXPAND = 1,
    /** Lazy expand. Expand the children of node if needed. */
    ARKUI_LAZY_EXPAND = 2,
} ArkUI_ExpandMode;

/**
 * @brief Defines the navigation point indicator style of the <b><Swiper></b> component.
 * @brief Enumerates the UI states of a component, used for handling state-specific styles.
 *
 * @since 20
 */
typedef enum {
    /** Normal state. */
    UI_STATE_NORMAL = 0,
    /** Pressed state. */
    UI_STATE_PRESSED = 1 << 0,
    /** Focused state. */
    UI_STATE_FOCUSED = 1 << 1,
    /** Disabled state. */
    UI_STATE_DISABLED = 1 << 2,
    /**
     * Selected state. This state is supported only by specific component types:
     * <b>Checkbox</b>, <b>Radio</b>, <b>Toggle</b>, <b>List</b>, <b>Grid</b>, and <b>MenuItem</b>.
     */
    UI_STATE_SELECTED = 1 << 3,
} ArkUI_UIState;

/**
 * @brief Enumerates the edge direction.
 *
 * @since 20
 */
typedef enum {
    /** Set all edge direction. */
    ARKUI_EDGE_DIRECTION_ALL = 0,
    /** Set left edge direction. */
    ARKUI_EDGE_DIRECTION_LEFT,
    /** Set right edge direction. */
    ARKUI_EDGE_DIRECTION_RIGHT,
    /** Set top edge direction. */
    ARKUI_EDGE_DIRECTION_TOP,
    /** Set bottom edge direction. */
    ARKUI_EDGE_DIRECTION_BOTTOM,
} ArkUI_EdgeDirection;
 
/**
 * @brief Enumerates the corner direction.
 *
 * @since 20
 */
typedef enum {
    /** Set all corner direction. */
    ARKUI_CORNER_DIRECTION_ALL = 0,
    /** Set top left corner direction. */
    ARKUI_CORNER_DIRECTION_TOP_LEFT,
    /** Set top right corner direction. */
    ARKUI_CORNER_DIRECTION_TOP_RIGHT,
    /** Set bottom left corner direction. */
    ARKUI_CORNER_DIRECTION_BOTTOM_LEFT,
    /** Set bottom right corner direction. */
    ARKUI_CORNER_DIRECTION_BOTTOM_RIGHT,
} ArkUI_CornerDirection;

/**
 * @brief Enumerates the PixelRoundPolicy.
 *
 * @since 21
 */
typedef enum {
    /** No Force round the component boundary coordinates to integer pixel. */
    ARKUI_PIXELROUNDCALCPOLICY_NOFORCEROUND = 0,
    /** Force ceil the component boundary coordinates to integer pixel. */
    ARKUI_PIXELROUNDCALCPOLICY_FORCECEIL,
    /** Force floor the component boundary coordinates to integer pixel. */
    ARKUI_PIXELROUNDCALCPOLICY_FORCEFLOOR,
} ArkUI_PixelRoundCalcPolicy;

/**
 * @brief Menu pop-up strategy.
 *
 * @since 23
 */
typedef enum {
    /** Determine whether to pop up the menu according to the underlying default logic. */
    ARKUI_MENU_POLICY_DEFAULT = 0,
    /** Never pop up the menu. */
    ARKUI_MENU_POLICY_HIDE = 1,
    /** Always pop up the menu. */
    ARKUI_MENU_POLICY_SHOW = 2,
} ArkUI_MenuPolicy;

/**
 * @brief Define the direction to expand the swipe action.
 *
 * @since 21
 */
typedef enum {
    /**
     * When the List direction is vertical, it indicates the left in LTR mode and right in RTL mode.
     * When the List direction is horizontal, it indicates the top.
     */
    ARKUI_LIST_ITEM_SWIPE_ACTION_DIRECTION_START = 0,
    /**
     * When the List direction is vertical, it indicates the right in LTR mode and left in RTL mode.
     * When the List direction is horizontal, it indicates the bottom.
     */
    ARKUI_LIST_ITEM_SWIPE_ACTION_DIRECTION_END = 1,
} ArkUI_ListItemSwipeActionDirection;

/**
 * @brief Enumerates the input tool types supported for response region configuration.
 *
 * @since 23
 */
typedef enum {
    /** All input tool types. */
    ARKUI_RESPONSE_REGIN_SUPPORTED_TOOL_ALL = 0,
    /** Finger input. */
    ARKUI_RESPONSE_REGIN_SUPPORTED_TOOL_FINGER = 1,
    /** Stylus input. */
    ARKUI_RESPONSE_REGIN_SUPPORTED_TOOL_PEN = 2,
    /** Mouse input. */
    ARKUI_RESPONSE_REGIN_SUPPORTED_TOOL_MOUSE = 3,
} ArkUI_ResponseRegionSupportedTool;
/**
 * @brief Define the types for expanding the safe area in layout.
 *
 * @since 23
 */
typedef enum {
    /** Default non-safe area of the system, including the status bar and navigation bar. */
    ARKUI_LAYOUT_SAFE_AREA_TYPE_SYSTEM = 1,
} ArkUI_LayoutSafeAreaType;
/**
 * @brief Define the edges for expanding the safe area in layout.
 *
 * @since 23
 */
typedef enum {
    /** Top edge of the safe area. */
    ARKUI_LAYOUT_SAFE_AREA_EDGE_TOP = 1,
    /** Bottom edge of the safe area. */
    ARKUI_LAYOUT_SAFE_AREA_EDGE_BOTTOM = 1 << 1,
    /** Start edge of the safe area. */
    ARKUI_LAYOUT_SAFE_AREA_EDGE_START = 1 << 2,
    /** End edge of the safe area. */
    ARKUI_LAYOUT_SAFE_AREA_EDGE_END = 1 << 3,
    /** Vertical edge of the safe area. */
    ARKUI_LAYOUT_SAFE_AREA_EDGE_VERTICAL = ARKUI_LAYOUT_SAFE_AREA_EDGE_TOP | ARKUI_LAYOUT_SAFE_AREA_EDGE_BOTTOM,
    /** Horizontal edge of the safe area. */
    ARKUI_LAYOUT_SAFE_AREA_EDGE_HORIZONTAL = ARKUI_LAYOUT_SAFE_AREA_EDGE_START | ARKUI_LAYOUT_SAFE_AREA_EDGE_END,
    /** All edges of the safe area. */
    ARKUI_LAYOUT_SAFE_AREA_EDGE_ALL = ARKUI_LAYOUT_SAFE_AREA_EDGE_VERTICAL | ARKUI_LAYOUT_SAFE_AREA_EDGE_HORIZONTAL,
} ArkUI_LayoutSafeAreaEdge;

/**
 * @brief Enumerates the localizedAlignment modes.
 *
 * @since 23
 */
typedef enum {
    /** Top start. */
    ARKUI_LOCALIZED_ALIGNMENT_TOP_START = 0,
    /** Top center. */
    ARKUI_LOCALIZED_ALIGNMENT_TOP,
    /** Top end. */
    ARKUI_LOCALIZED_ALIGNMENT_TOP_END,
    /** Vertically centered start. */
    ARKUI_LOCALIZED_ALIGNMENT_START,
    /** Horizontally and vertically centered. */
    ARKUI_LOCALIZED_ALIGNMENT_CENTER,
    /** Vertically centered end. */
    ARKUI_LOCALIZED_ALIGNMENT_END,
    /** Bottom start. */
    ARKUI_LOCALIZED_ALIGNMENT_BOTTOM_START,
    /** Horizontally centered on the bottom. */
    ARKUI_LOCALIZED_ALIGNMENT_BOTTOM,
    /** Bottom end. */
    ARKUI_LOCALIZED_ALIGNMENT_BOTTOM_END,
} ArkUI_LocalizedAlignment;
/**
 * @brief Enumerates the graphics rendering strategy.
 *
 * @since 23
 */
typedef enum {
    /** The current component and its child components will be drawn directly onto the screen canvas. */
    ARKUI_RENDERSTRATEGY_FAST = 0,
    /**
    * The current component and its child components will first be drawn onto an off-screen canvas,
    *     then undergo some graphic rendering operations, and finally be drawn onto the main canvas.
    */
    ARKUI_RENDERSTRATEGY_OFFSCREEN,
} ArkUI_RenderStrategy;

/**
 * @brief Enumerates the LayoutPolicy.
 *
 * @since 21
 */
typedef enum {
    /** The component fills its parent, which means its size is as large as its parent */
    ARKUI_LAYOUTPOLICY_MATCHPARENT = 0,
    /**
     * The component fills its content, which means its size is as large as its children but it is constrained
     * by its parent.
     */
    ARKUI_LAYOUTPOLICY_WRAPCONTENT,
    /** The component fills its content which means its size is as large as its children. */
    ARKUI_LAYOUTPOLICY_FIXATIDEALSIZE,
} ArkUI_LayoutPolicy;

/**
 * @brief Defines parameter used by the system font style callback event.
 *
 * @since 12
 */
typedef struct ArkUI_SystemFontStyleEvent ArkUI_SystemFontStyleEvent;

/**
 * @brief Defines the options for taking snapshot.
 *
 * @since 15
 */
typedef struct ArkUI_SnapshotOptions ArkUI_SnapshotOptions;

/**
  * @brief TextPicker single column selector, supports mixing text and images.
  *
  * @since 19
  */
typedef struct ArkUI_TextPickerRangeContentArray ArkUI_TextPickerRangeContentArray;

 /**
   * @brief TextPicker multi column selector, supports mixing text and images.
   *
   * @since 19
   */
typedef struct ArkUI_TextCascadePickerRangeContentArray ArkUI_TextCascadePickerRangeContentArray;

/**
 * @brief Defines a two-dimensional point struct, with coordinates stored as float type.
 *
 * @since 24
 */
typedef struct {
    /**
     * x-axis coordinate.
     */
    float x;
    /**
     * y-axis coordinate.
     */
    float y;
} ArkUI_PointF;

 /**
   * @brief Defines the options for selection operation.
   *
   * @since 23
   */
typedef struct ArkUI_SelectionOptions ArkUI_SelectionOptions;

/**
* @brief Creates a size constraint.
*
* @since 12
*/
ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Create() __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Creates a deep copy of a size constraint.
*
* @param Constraint Indicates the pointer to the size constraint.
* @return Returns the pointer to the new size constraint.
* @since 12
*/
ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Copy(const ArkUI_LayoutConstraint* Constraint)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Destroys the pointer to a size constraint.
*
* @param Constraint Indicates the pointer to the size constraint.
* @since 12
*/
void* OH_ArkUI_LayoutConstraint_Dispose(ArkUI_LayoutConstraint* Constraint)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Obtains the maximum width for a size constraint, in px.
*
* @param Constraint Indicates the pointer to the size constraint.
* @return Returns the maximum width.
* @since 12
*/
int32_t OH_ArkUI_LayoutConstraint_GetMaxWidth(const ArkUI_LayoutConstraint* Constraint)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Obtains the minimum width for a size constraint, in px.
*
* @param Constraint Indicates the pointer to the size constraint.
* @return Returns the minimum width.
* @since 12
*/
int32_t OH_ArkUI_LayoutConstraint_GetMinWidth(const ArkUI_LayoutConstraint* Constraint)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Obtains the maximum height for a size constraint, in px.
*
* @param Constraint Indicates the pointer to the size constraint.
* @return Returns the maximum height.
* @since 12
*/
int32_t OH_ArkUI_LayoutConstraint_GetMaxHeight(const ArkUI_LayoutConstraint* Constraint)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Obtains the minimum height for a size constraint, in px.
*
* @param Constraint Indicates the pointer to the size constraint.
* @return Returns the minimum height.
* @since 12
*/
int32_t OH_ArkUI_LayoutConstraint_GetMinHeight(const ArkUI_LayoutConstraint* Constraint)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Obtains the width percentage reference for a size constraint, in px.
*
* @param Constraint Indicates the pointer to the size constraint.
* @return Returns the width percentage reference.
* @since 12
*/
int32_t OH_ArkUI_LayoutConstraint_GetPercentReferenceWidth(const ArkUI_LayoutConstraint* Constraint)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Obtains the height percentage reference for a size constraint, in px.
*
* @param Constraint Indicates the pointer to the size constraint.
* @return Returns the height percentage reference.
* @since 12
*/
int32_t OH_ArkUI_LayoutConstraint_GetPercentReferenceHeight(const ArkUI_LayoutConstraint* Constraint)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Sets the maximum width.
*
* @param Constraint Indicates the pointer to the size constraint.
* @param value Indicates the maximum width, in px.
* @since 12
*/
void OH_ArkUI_LayoutConstraint_SetMaxWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Sets the minimum width.
*
* @param Constraint Indicates the pointer to the size constraint.
* @param value Indicates the minimum width, in px.
* @since 12
*/
void OH_ArkUI_LayoutConstraint_SetMinWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Sets the maximum height.
*
* @param Constraint Indicates the pointer to the size constraint.
* @param value Indicates the maximum height, in px.
* @since 12
*/
void OH_ArkUI_LayoutConstraint_SetMaxHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Sets the minimum height.
*
* @param Constraint Indicates the pointer to the size constraint.
* @param value Indicates the minimum height, in px.
* @since 12
*/
void OH_ArkUI_LayoutConstraint_SetMinHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Sets the width percentage reference.
*
* @param Constraint Indicates the pointer to the size constraint.
* @param value Indicates the width percentage reference, in px.
* @since 12
*/
void OH_ArkUI_LayoutConstraint_SetPercentReferenceWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Sets the height percentage reference.
*
* @param Constraint Indicates the pointer to the size constraint.
* @param value Indicates the height percentage reference, in px.
* @since 12
*/
void OH_ArkUI_LayoutConstraint_SetPercentReferenceHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Obtains the pointer to a canvas for drawing, which can be converted into the <b>OH_Drawing_Canvas</b> pointer
* in the <b>Drawing</b> module.
*
* @param context Indicates the pointer to the drawing context.
* @return Returns the pointer to the canvas for drawing.
* @since 12
*/
void* OH_ArkUI_DrawContext_GetCanvas(ArkUI_DrawContext* context)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Obtains the size of a drawing area.
*
* @param context Indicates the pointer to the drawing context.
* @return Returns the size of the drawing area.
* @since 12
*/
ArkUI_IntSize OH_ArkUI_DrawContext_GetSize(ArkUI_DrawContext* context)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Creates <b>Grid</b> layout options.
 *
 * @return <b>Grid</b> layout options created.
 * @since 22
 */
ArkUI_GridLayoutOptions* OH_ArkUI_GridLayoutOptions_Create() __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Disposes of <b>Grid</b> layout options.
 *
 * @param option <b>Grid</b> layout options.
 * @since 22
 */
void OH_ArkUI_GridLayoutOptions_Dispose(ArkUI_GridLayoutOptions* option)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Sets the irregular grid item index array for the grid layout.
 *
 * @param option <b>Grid</b> layout options.
 * @param irregularIndexes Array of irregular grid item indexes.
 * @param size Size of the index array.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         If an error code is returned, it may be due to a failure in parameter validation;
 *         the parameter must not be null.
 * @since 22
 */
int32_t OH_ArkUI_GridLayoutOptions_SetIrregularIndexes(
    ArkUI_GridLayoutOptions* option, uint32_t* irregularIndexes, int32_t size)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Obtains the irregular grid item index array for the grid layout.
 * When <b>OH_ArkUI_GridLayoutOptions_RegisterGetIrregularSizeByIndexCallback</b> is not set,
 * the grid item specified in <b>irregularIndexes</b> occupies an entire row of the grid that scrolls vertically or
 * an entire column of the grid that scrolls horizontally.
 *
 * @param option <b>Grid</b> layout options.
 * @param irregularIndexes Array of irregular grid item indexes.
 * @param size Size of the index array.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} if the provided buffer size is insufficient.
 *         If an error code is returned, it may be due to a failure in parameter validation;
 *         the parameter must not be null.
 * @since 22
 */
int32_t OH_ArkUI_GridLayoutOptions_GetIrregularIndexes(
    ArkUI_GridLayoutOptions* option, uint32_t* irregularIndexes, int32_t* size)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Registers a callback to obtain the row and column span for the grid item at the specified index.
 *
 * @param option <b>Grid</b> layout options.
 * @param userData Indicates the custom data.
 * @param callback Callback that returns the row and column span for the grid item at the specified index.
 *        itemIndex: grid item index, which must be within the range set by
 *        {@link OH_ArkUI_GridLayoutOptions_SetIrregularIndexes}.
 * @since 22
 */
void OH_ArkUI_GridLayoutOptions_RegisterGetIrregularSizeByIndexCallback(
    ArkUI_GridLayoutOptions* option, void* userData, ArkUI_GridItemSize (*callback)(int32_t itemIndex, void* userData))
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Registers a callback to obtain the starting row, starting column, row span,
 * and column span for the grid item at the specified index.
 *
 * @param option <b>Grid</b> layout options.
 * @param userData Indicates the custom data.
 * @param callback Callback that returns the starting row, starting column, row span,
 *        and column span for the grid item at the specified index.
 *        itemIndex: grid item index.
 * @since 22
 */
void OH_ArkUI_GridLayoutOptions_RegisterGetRectByIndexCallback(
    ArkUI_GridLayoutOptions* option, void* userData, ArkUI_GridItemRect (*callback)(int32_t itemIndex, void* userData))
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
* @brief Creates water flow section configuration.
*
* @return Returns the water flow section configuration.
* @since 12
*/
ArkUI_WaterFlowSectionOption* OH_ArkUI_WaterFlowSectionOption_Create()
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Destroys the pointer to a water flow section configuration.
*
* @param option Indicates the pointer to a water flow section configuration.
* @since 12
*/
void OH_ArkUI_WaterFlowSectionOption_Dispose(ArkUI_WaterFlowSectionOption* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Sets the FlowItem block configuration information array length.
*
* @param option FlowItem Indicates the packet configuration.
* @param size Array Length.
* @since 12
*/
void OH_ArkUI_WaterFlowSectionOption_SetSize(ArkUI_WaterFlowSectionOption* option, int32_t size)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Gets the FlowItem grouping configuration information array length.
*
* @param option FlowItem Indicates the packet configuration.
* @return Array size. If -1 is returned, the return fails.
*         The possible cause of the failure is that the option parameter is abnormal, such as a null pointer.
* @since 12
*/
int32_t OH_ArkUI_WaterFlowSectionOption_GetSize(ArkUI_WaterFlowSectionOption* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Sets the number of items in a water flow section.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @param itemCount Indicates the number of items in the water flow section.
* @since 12
*/
void OH_ArkUI_WaterFlowSectionOption_SetItemCount(ArkUI_WaterFlowSectionOption* option,
    int32_t index, int32_t itemCount)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Obtains the number of items in the water flow section that matches the specified index.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @return Returns the number of items in the water flow section.
* @since 12
*/
int32_t OH_ArkUI_WaterFlowSectionOption_GetItemCount(ArkUI_WaterFlowSectionOption* option, int32_t index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief The FlowItem grouping configuration information getsthe spindle size of
* the specified Item based on flowItemIndex.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @param callback Gets the spindle size of the specified Item based on index.
* @since 12
*/
void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex(ArkUI_WaterFlowSectionOption* option,
    int32_t index, float(*callback)(int32_t itemIndex))
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief The FlowItem grouping configuration information getsthe spindle size of
* the specified Item based on flowItemIndex.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @param userData FlowItem Custom data.
* @param callback Gets the spindle size of the specified Item based on index.
* @since 12
*/
void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData(
    ArkUI_WaterFlowSectionOption* option, int32_t index, void* userData,
    float (*callback)(int32_t itemIndex, void* userData))
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Sets the number of columns (in a vertical layout) or rows (in a horizontal layout) of a water flow.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @param crossCount Indicates the number of columns or rows, depending on the layout direction.
* @since 12
*/
void OH_ArkUI_WaterFlowSectionOption_SetCrossCount(
    ArkUI_WaterFlowSectionOption* option, int32_t index, int32_t crossCount)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Obtains the number of columns (in a vertical layout) or rows (in a horizontal layout) in the water flow section
* that matches the specified index.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @return Returns the number of columns or rows.
* @since 12
*/
int32_t OH_ArkUI_WaterFlowSectionOption_GetCrossCount(ArkUI_WaterFlowSectionOption* option, int32_t index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Sets the gap between columns in the specified water flow section.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @param columnGap Indicates the gap between columns to set.
* @since 12
*/
void OH_ArkUI_WaterFlowSectionOption_SetColumnGap(ArkUI_WaterFlowSectionOption* option,
    int32_t index, float columnGap)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Obtains the gap between columns in the water flow section that matches the specified index.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @return Returns the gap between columns.
* @since 12
*/
float OH_ArkUI_WaterFlowSectionOption_GetColumnGap(ArkUI_WaterFlowSectionOption* option, int32_t index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Sets the gap between rows in the specified water flow section.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @param rowGap Indicates the gap between rows to set.
* @since 12
*/
void OH_ArkUI_WaterFlowSectionOption_SetRowGap(ArkUI_WaterFlowSectionOption* option,
    int32_t index, float rowGap)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Obtains the gap between rows in the water flow section that matches the specified index.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @return Returns the gap between rows.
* @since 12
*/
float OH_ArkUI_WaterFlowSectionOption_GetRowGap(ArkUI_WaterFlowSectionOption* option, int32_t index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Sets the margins for the specified water flow section.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @param marginTop Indicates the top margin of the water flow section.
* @param marginRight Indicates the right margin of the water flow section.
* @param marginBottom Indicates the bottom margin of the water flow section.
* @param marginLeft Indicates the left margin of the water flow section.
* @since 12
*/
void OH_ArkUI_WaterFlowSectionOption_SetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index,
    float marginTop, float marginRight, float marginBottom, float marginLeft)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Obtains the margins of the water flow section that matches the specified index.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @return Returns the margins.
* @since 12
*/
ArkUI_Margin OH_ArkUI_WaterFlowSectionOption_GetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Creates a navigation indicator.
 *
 * @param type Indicates the type of the indicator.
 * @return Returns the pointer to the new indicator.
 * @since 12
*/
ArkUI_SwiperIndicator* OH_ArkUI_SwiperIndicator_Create(ArkUI_SwiperIndicatorType type)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Destroys the pointer to the indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_Dispose(ArkUI_SwiperIndicator* indicator)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets the distance between the navigation point and the start of the swiper.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param value Indicates the distance between the navigation point and the start of the swiper.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetStartPosition(ArkUI_SwiperIndicator* indicator, float value)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the distance between the navigation point and the start of the swiper.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the distance between the navigation point and the start of the swiper.
 * @since 12
*/
float OH_ArkUI_SwiperIndicator_GetStartPosition(ArkUI_SwiperIndicator* indicator)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets the distance between the navigation point and the top of the swiper.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param value Indicates the distance between the navigation point and the top of the swiper.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetTopPosition(ArkUI_SwiperIndicator* indicator, float value)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the distance between the navigation point and the top of the swiper.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the distance between the navigation point and the top of the swiper.
 * @since 12
*/
float OH_ArkUI_SwiperIndicator_GetTopPosition(ArkUI_SwiperIndicator* indicator)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets the distance between the navigation point and the right of the swiper.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param value Indicates the distance between the navigation point and the right of the swiper.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetEndPosition(ArkUI_SwiperIndicator* indicator, float value)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the distance between the navigation point and the end of the swiper.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the distance between the navigation point and the end of the swiper.
 * @since 12
*/
float OH_ArkUI_SwiperIndicator_GetEndPosition(ArkUI_SwiperIndicator* indicator)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets the distance between the navigation point and the bottom of the swiper.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param value Indicates the distance between the navigation point and the bottom of the swiper.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetBottomPosition(ArkUI_SwiperIndicator* indicator, float value)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the distance between the navigation point and the bottom of the swiper.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the distance between the navigation point and the bottom of the swiper.
 * @since 12
*/
float OH_ArkUI_SwiperIndicator_GetBottomPosition(ArkUI_SwiperIndicator* indicator)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets the width of the dot for the dot indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param value Indicates the width of the dot for the dot indicator.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetItemWidth(ArkUI_SwiperIndicator* indicator, float value)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the width of the dot for the dot indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the width of the dot for the dot indicator.
 * @since 12
*/
float OH_ArkUI_SwiperIndicator_GetItemWidth(ArkUI_SwiperIndicator* indicator)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets the height of the dot for the dot indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param value Indicates the height of the dot for the dot indicator.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetItemHeight(ArkUI_SwiperIndicator* indicator, float value)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief  Obtains the height of the dot for the dot indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the height of the dot for the dot indicator.
 * @since 12
*/
float OH_ArkUI_SwiperIndicator_GetItemHeight(ArkUI_SwiperIndicator* indicator)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets the width of the selected dot for the dot indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param value Indicates the width of the selected dot for the dot indicator.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetSelectedItemWidth(ArkUI_SwiperIndicator* indicator, float value)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief  Obtains the width of the selected dot for the dot indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the width of the selected dot for the dot indicator.
 * @since 12
*/
float OH_ArkUI_SwiperIndicator_GetSelectedItemWidth(ArkUI_SwiperIndicator* indicator)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets the height of the selected dot for the dot indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param value Indicates the height of the selected dot for the dot indicator.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetSelectedItemHeight(ArkUI_SwiperIndicator* indicator, float value)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief  Obtains the height of the selected dot for the dot indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the height of the selected dot for the dot indicator.
 * @since 12
*/
float OH_ArkUI_SwiperIndicator_GetSelectedItemHeight(ArkUI_SwiperIndicator* indicator)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets whether to display the mask style of the dot navigation indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param mask Whether to display the mask style. True means to display.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetMask(ArkUI_SwiperIndicator* indicator, int32_t mask)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains whether to display the mask style of the dot navigation indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns whether to display the mask style. True means to display.
 * @since 12
*/
int32_t OH_ArkUI_SwiperIndicator_GetMask(ArkUI_SwiperIndicator* indicator)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets the color of the dot navigation indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param color the color of the dot navigation indicator, in 0xARGB format.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetColor(ArkUI_SwiperIndicator* indicator, uint32_t color)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the color of the dot navigation indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the color of the dot navigation indicator, in 0xARGB format.
 * @since 12
*/
uint32_t OH_ArkUI_SwiperIndicator_GetColor(ArkUI_SwiperIndicator* indicator)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets the color of the selected dot for the navigation indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param selectedColor the color of the selected dot, in 0xARGB format.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetSelectedColor(ArkUI_SwiperIndicator* indicator, uint32_t selectedColor)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the color of the selected dot for the dot navigation indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the color of the selected dot, in 0xARGB format.
 * @since 12
*/
uint32_t OH_ArkUI_SwiperIndicator_GetSelectedColor(ArkUI_SwiperIndicator* indicator)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets the number of maxDisplayCount for the dot navigation indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param maxDisplayCount the maxDisplayCount of the navigation dot, span is 6-9.
 * @return {@link ARKUI_ERROR_CODE_NO_ERROR} Success.
 *         {@link ARKUI_ERROR_CODE_PARAM_INVALID} indicator is null or maxDisplayCount less then 6 or
 *         maxDisplayCount more then 9
 * @since 12
*/
int32_t OH_ArkUI_SwiperIndicator_SetMaxDisplayCount(ArkUI_SwiperIndicator* indicator, int32_t maxDisplayCount)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the number of maxDisplayCount for the dot navigation indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the number of the maxDisplayCount, span is 6-9.
 *         0 - indicator is null
 * @since 12
*/
int32_t OH_ArkUI_SwiperIndicator_GetMaxDisplayCount(ArkUI_SwiperIndicator* indicator)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets whether to ignore the size of the indicator for {@link OH_ArkUI_SwiperIndicator_SetBottomPosition}.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param ignoreSize Whether to ignore the size of the indicator. The value 1 means to ignore, and 0 means the opposite.
 * The default value is 0.
 * @since 19
*/
void OH_ArkUI_SwiperIndicator_SetIgnoreSizeOfBottom(ArkUI_SwiperIndicator* indicator, int32_t ignoreSize)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Obtains whether to ignore the size of the indicator for {@link OH_ArkUI_SwiperIndicator_SetBottomPosition}.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns whether to ignore the size of the indicator.
 * @since 19
*/
int32_t OH_ArkUI_SwiperIndicator_GetIgnoreSizeOfBottom(ArkUI_SwiperIndicator* indicator)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Sets the space between the dots of the navigation indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param space the space between the dots of the navigation indicator, the default value is 8vp.
 * @since 19
*/
void OH_ArkUI_SwiperIndicator_SetSpace(ArkUI_SwiperIndicator* indicator, float space)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Obtains the space between the dots of the navigation indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return the space between the dots of the navigation indicator
 * @since 19
*/
float OH_ArkUI_SwiperIndicator_GetSpace(ArkUI_SwiperIndicator* indicator)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Creates a digital indicator.
 *
 * @return Returns the pointer to the new indicator.
 * @since 19
 */
ArkUI_SwiperDigitIndicator *OH_ArkUI_SwiperDigitIndicator_Create()
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Sets the distance between the digital indicator and the start of the swiper.
 *
 * @param indicator The pointer to the digital indicator.
 * @param value Indicates the distance between the digital indicator and the start of the swiper.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_SetStartPosition(ArkUI_SwiperDigitIndicator* indicator, float value)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Gets the distance between the digital indicator and the start of the swiper.
 *
 * @param indicator The pointer to the digital indicator.
 * @return Returns the distance between the digital indicator and the start of the swiper.
 * @since 19
 */
float OH_ArkUI_SwiperDigitIndicator_GetStartPosition(ArkUI_SwiperDigitIndicator* indicator)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Sets the distance between the digital indicator and the top of the swiper.
 *
 * @param indicator The pointer to the digital indicator.
 * @param value Indicates the distance between the digital indicator and the top of the swiper.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_SetTopPosition(ArkUI_SwiperDigitIndicator* indicator, float value)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Gets the distance between the digital indicator and the top of the swiper.
 *
 * @param indicator The pointer to the digital indicator.
 * @return Returns the distance between the digital indicator and the top of the swiper.
 * @since 19
 */
float OH_ArkUI_SwiperDigitIndicator_GetTopPosition(ArkUI_SwiperDigitIndicator* indicator)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Sets the distance between the digital indicator and the end of the swiper.
 *
 * @param indicator The pointer to the digital indicator.
 * @param value Indicates the distance between the digital indicator and the end of the swiper.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_SetEndPosition(ArkUI_SwiperDigitIndicator* indicator, float value)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Gets the distance between the digital indicator and the end of the swiper.
 *
 * @param indicator The pointer to the digital indicator.
 * @return Returns the distance between the digital indicator and the end of the swiper.
 * @since 19
 */
float OH_ArkUI_SwiperDigitIndicator_GetEndPosition(ArkUI_SwiperDigitIndicator* indicator)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Sets the distance between the digital indicator and the bottom of the swiper.
 *
 * @param indicator The pointer to the digital indicator.
 * @param value Returns the distance between the digital indicator and the bottom of the swiper.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_SetBottomPosition(ArkUI_SwiperDigitIndicator* indicator, float value)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Gets the distance between the digital indicator and the bottom of the swiper.
 *
 * @param indicator The pointer to the digital indicator.
 * @return Returns the distance between the digital indicator and the bottom of the swiper.
 * @since 19
 */
float OH_ArkUI_SwiperDigitIndicator_GetBottomPosition(ArkUI_SwiperDigitIndicator* indicator)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Sets the font color of total count in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @param color font color, in 0xARGB format. Default value: 0xFF182431.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_SetFontColor(ArkUI_SwiperDigitIndicator* indicator, uint32_t color)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Gets the font color of total count in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @return font color, in 0xARGB format.
 * @since 19
 */
uint32_t OH_ArkUI_SwiperDigitIndicator_GetFontColor(ArkUI_SwiperDigitIndicator* indicator)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Sets the font color of selected index in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @param selectedColor font color, in 0xARGB format. Default value: 0xFF182431.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_SetSelectedFontColor(ArkUI_SwiperDigitIndicator* indicator, uint32_t selectedColor)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Gets the font color of selected index in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @return font color, in 0xARGB format.
 * @since 19
 */
uint32_t OH_ArkUI_SwiperDigitIndicator_GetSelectedFontColor(ArkUI_SwiperDigitIndicator* indicator)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Sets the font size of total count in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @param size font size, in fp.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_SetFontSize(ArkUI_SwiperDigitIndicator* indicator, float size)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Gets the font size of total count in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @return font size, in fp.
 * @since 19
 */
float OH_ArkUI_SwiperDigitIndicator_GetFontSize(ArkUI_SwiperDigitIndicator* indicator)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Sets the font size of selected index in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @param size font size, in fp.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_SetSelectedFontSize(ArkUI_SwiperDigitIndicator* indicator, float size)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Gets the font size of selected index in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @return font size, in fp.
 * @since 19
 */
float OH_ArkUI_SwiperDigitIndicator_GetSelectedFontSize(ArkUI_SwiperDigitIndicator* indicator)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Sets the font weight of total count in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @param fontWeight font weight {@link ArkUI_FontWeight}. The default value is <b>ARKUI_FONT_WEIGHT_NORMAL</b>.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_SetFontWeight(ArkUI_SwiperDigitIndicator *indicator, ArkUI_FontWeight fontWeight)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Gets the font weight of total count in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @return font weight {@link ArkUI_FontWeight}.
 * @since 19
 */
ArkUI_FontWeight OH_ArkUI_SwiperDigitIndicator_GetFontWeight(ArkUI_SwiperDigitIndicator* indicator)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Sets the font weight of selected index in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @param selectedFontWeight font weight {@link ArkUI_FontWeight}. The default value is <b>ARKUI_FONT_WEIGHT_NORMAL</b>.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_SetSelectedFontWeight(
    ArkUI_SwiperDigitIndicator *indicator, ArkUI_FontWeight selectedFontWeight)
    __attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Gets the font weight of selected index in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @return font weight {@link ArkUI_FontWeight}.
 * @since 19
 */
ArkUI_FontWeight OH_ArkUI_SwiperDigitIndicator_GetSelectedFontWeight(ArkUI_SwiperDigitIndicator* indicator)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Destroys the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_Destroy(ArkUI_SwiperDigitIndicator *indicator)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Sets whether to ignore the size of the indicator for {@link OH_ArkUI_SwiperDigitIndicator_SetBottomPosition}.
 *
 * @param indicator The pointer to the digital indicator.
 * @param ignoreSize Whether to ignore the size of the indicator. The value 1 means to ignore, and 0 means the opposite.
 * The default value is 0.
 * @since 19
*/
void OH_ArkUI_SwiperDigitIndicator_SetIgnoreSizeOfBottom(ArkUI_SwiperDigitIndicator* indicator, int32_t ignoreSize)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Obtains whether to ignore the size of the indicator for {@link OH_ArkUI_SwiperDigitIndicator_SetBottomPosition}.
 *
 * @param indicator The pointer to the digital indicator.
 * @return Returns whether to ignore the size of the indicator.
 * @since 19
*/
int32_t OH_ArkUI_SwiperDigitIndicator_GetIgnoreSizeOfBottom(ArkUI_SwiperDigitIndicator* indicator)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Creates a arrow style for swiper.
 *
 * @return Returns the pointer to the new arrow style.
 * @since 19
 */
ArkUI_SwiperArrowStyle *OH_ArkUI_SwiperArrowStyle_Create() __attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Sets whether to show the background for the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @param showBackground whether to show the background for the arrow.
 *        The value <b>1</b> means to show the background, and <b>0</b> means the opposite.
 *        The default value is <b>0</b>.
 * @since 19
 */
void OH_ArkUI_SwiperArrowStyle_SetShowBackground(ArkUI_SwiperArrowStyle *arrowStyle, int32_t showBackground)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Gets whether to show the background for the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @return whether to show the background for the arrow.
 *         The value <b>1</b> means to show the background, and <b>0</b> means the opposite.
 * @since 19
 */
int32_t OH_ArkUI_SwiperArrowStyle_GetShowBackground(ArkUI_SwiperArrowStyle* arrowStyle)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Sets the display position of the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @param showSidebarMiddle the display position of the arrow.
 *        The value <b>1</b> means to display on boths sides of the swiper,
 *        and <b>0</b> means display on boths sides of the swiper indicator.
 *        The default value is <b>0</b>.
 * @since 19
 */
void OH_ArkUI_SwiperArrowStyle_SetShowSidebarMiddle(ArkUI_SwiperArrowStyle* arrowStyle, int32_t showSidebarMiddle)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Gets the display position of the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @return the display position of the arrow. The value <b>1</b> means to display on boths sides of the swiper,
 *         and <b>0</b> means display on boths sides of the swiper indicator.
 * @since 19
 */
int32_t OH_ArkUI_SwiperArrowStyle_GetShowSidebarMiddle(ArkUI_SwiperArrowStyle* arrowStyle)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Sets the background size of the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @param backgroundSize the background size of the arrow. The unit is vp.
 *        The default value is <b>24</b> when the arrow displays on both sides of the swiper indicator.
 *        The default value is <b>32</b> when the arrow displays on both sides of the swiper.
 * @since 19
 */
void OH_ArkUI_SwiperArrowStyle_SetBackgroundSize(ArkUI_SwiperArrowStyle* arrowStyle, float backgroundSize)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Gets the background size of the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @return Returns the background size of the arrow. The unit is vp.
 * @since 19
 */
float OH_ArkUI_SwiperArrowStyle_GetBackgroundSize(ArkUI_SwiperArrowStyle *arrowStyle)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Destroys the arrow style.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @since 19
 */
void OH_ArkUI_SwiperArrowStyle_Destroy(ArkUI_SwiperArrowStyle *arrowStyle)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Sets the background color of the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @param backgroundColor the background color of the arrow, in 0xARGB format.
 *        The default value is <b>0x00000000</b> when the arrow displays on both sides of the swiper indicator.
 *        The default value is <b>0x19182431</b> when the arrow displays on both sides of the swiper.
 * @since 19
 */
void OH_ArkUI_SwiperArrowStyle_SetBackgroundColor(ArkUI_SwiperArrowStyle *arrowStyle, uint32_t backgroundColor)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Gets the background color of the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @return Returns the background color of the arrow, in 0xARGB format.
 * @since 19
 */
uint32_t OH_ArkUI_SwiperArrowStyle_GetBackgroundColor(ArkUI_SwiperArrowStyle* arrowStyle)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Sets the size of the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @param arrowSize the size of the arrow. The unit is vp.
 *        The default value is <b>18</b> when the arrow displays on both sides of the swiper indicator.
 *        The default value is <b>24</b> when the arrow displays on both sides of the swiper.
 *        The arrow size is fixed to 3/4 of the background size when the background is shown.
 * @since 19
 */
void OH_ArkUI_SwiperArrowStyle_SetArrowSize(ArkUI_SwiperArrowStyle* arrowStyle, float arrowSize)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Gets the size of the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @return the size of the arrow. The unit is vp.
 * @since 19
 */
float OH_ArkUI_SwiperArrowStyle_GetArrowSize(ArkUI_SwiperArrowStyle* arrowStyle)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Sets the color of the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @param arrowColor the color of the arrow, in 0xARGB format. The default value is <b>0x00182431</b>.
 * @since 19
 */
void OH_ArkUI_SwiperArrowStyle_SetArrowColor(ArkUI_SwiperArrowStyle* arrowStyle, uint32_t arrowColor)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Gets the color of the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @return Returns the color of the arrow, in 0xARGB format.
 * @since 19
 */
uint32_t OH_ArkUI_SwiperArrowStyle_GetArrowColor(ArkUI_SwiperArrowStyle* arrowStyle)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Create auxiliary line information in the RelativeContaine container.
 *
 * @param size The number of auxiliary lines.
 * @return auxiliary line information.
 * @since 12
 */
ArkUI_GuidelineOption* OH_ArkUI_GuidelineOption_Create(int32_t size)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Destroy auxiliary line information.
 *
 * @param guideline auxiliary line information.
 * @since 12
 */
void OH_ArkUI_GuidelineOption_Dispose(ArkUI_GuidelineOption* guideline)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the Id of the auxiliary line.
 *
 * @param guideline auxiliary line information.
 * @param value id, must be unique and cannot have the same name as the component in the container.
 * @param index auxiliary line index value.
 * @since 12
 */
void OH_ArkUI_GuidelineOption_SetId(ArkUI_GuidelineOption* guideline, const char* value, int32_t index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the direction of the auxiliary line.
 *
 * @param guideline auxiliary line information.
 * @param value direction.
 * @param index auxiliary line index value.
 * @since 12
 */
void OH_ArkUI_GuidelineOption_SetDirection(ArkUI_GuidelineOption* guideline, ArkUI_Axis value, int32_t index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the distance from the left or top of the container.
 *
 * @param guideline auxiliary line information.
 * @param value The distance from the left or top of the container.
 * @param index auxiliary line index value.
 * @since 12
 */
void OH_ArkUI_GuidelineOption_SetPositionStart(ArkUI_GuidelineOption* guideline, float value, int32_t index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the distance from the right or bottom of the container.
 *
 * @param guideline auxiliary line information.
 * @param value The distance from the right side or bottom of the container.
 * @param index auxiliary line index value.
 * @since 12
 */
void OH_ArkUI_GuidelineOption_SetPositionEnd(ArkUI_GuidelineOption* guideline, float value, int32_t index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get the Id of the auxiliary line.
 *
 * @param guideline auxiliary line information.
 * @param index auxiliary line index value.
 * @return Id.
 * @since 12
 */
const char* OH_ArkUI_GuidelineOption_GetId(ArkUI_GuidelineOption* guideline, int32_t index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get the direction of the auxiliary line.
 *
 * @param guideline auxiliary line information.
 * @param index auxiliary line index value.
 * @return direction.
 * @since 12
 */
ArkUI_Axis OH_ArkUI_GuidelineOption_GetDirection(ArkUI_GuidelineOption* guideline, int32_t index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get the distance from the left or top of the container.
 *
 * @param guideline auxiliary line information.
 * @param index auxiliary line index value.
 * @return The distance from the left or top of the container.
 * @since 12
 */
float OH_ArkUI_GuidelineOption_GetPositionStart(ArkUI_GuidelineOption* guideline, int32_t index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get the distance from the right side or bottom of the container.
 *
 * @param guideline auxiliary line information.
 * @param index auxiliary line index value.
 * @return The distance from the right side or bottom of the container.
 * @since 12
 */
float OH_ArkUI_GuidelineOption_GetPositionEnd(ArkUI_GuidelineOption* guideline, int32_t index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief creates barrier information within the RelativeContaine container.
 *
 * @param size Number of barriers.
 * @return barrier information.
 * @since 12
 */
ArkUI_BarrierOption* OH_ArkUI_BarrierOption_Create(int32_t size)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Destroy barrier information.
 *
 * @param barrierStyle barrier information.
 * @since 12
 */
void OH_ArkUI_BarrierOption_Dispose(ArkUI_BarrierOption* barrierStyle)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the Id of the barrier.
 *
 * @param barrierStyle barrier information.
 * @param value id, must be unique and cannot have the same name as the component in the container.
 * @param index Barrier index value.
 * @since 12
 */
void OH_ArkUI_BarrierOption_SetId(ArkUI_BarrierOption* barrierStyle, const char* value, int32_t index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the direction of the barrier.
 *
 * @param barrierStyle barrier information.
 * @param value direction.
 * @param index Barrier index value.
 * @since 12
 */
void OH_ArkUI_BarrierOption_SetDirection(
    ArkUI_BarrierOption* barrierStyle, ArkUI_BarrierDirection value, int32_t index)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets the dependent component of the barrier.
 *
 * @param barrierStyle barrier information.
 * @param value The ID of the dependent component.
 * @param index Barrier index value.
 * @since 12
 */
void OH_ArkUI_BarrierOption_SetReferencedId(ArkUI_BarrierOption* barrierStyle, const char* value, int32_t index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get the Id of the barrier.
 *
 * @param barrierStyle auxiliary line information.
 * @param index auxiliary line index value.
 * @return The Id of the barrier.
 * @since 12
 */
const char* OH_ArkUI_BarrierOption_GetId(ArkUI_BarrierOption* barrierStyle, int32_t index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Gets the direction of the barrier.
 *
 * @param barrierStyle auxiliary line information.
 * @param index auxiliary line index value.
 * @return The direction of the barrier.
 * @since 12
 */
ArkUI_BarrierDirection OH_ArkUI_BarrierOption_GetDirection(ArkUI_BarrierOption* barrierStyle, int32_t index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get the dependent components of the barrier.
 *
 * @param barrierStyle auxiliary line information.
 * @param index auxiliary line index value.
 * @param referencedIndex dependent component Id index value.
 * @return The barrier's dependent components.
 * @since 12
 */
const char* OH_ArkUI_BarrierOption_GetReferencedId(
    ArkUI_BarrierOption* barrierStyle, int32_t index, int32_t referencedIndex)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Gets the number of dependent components of the barrier.
 *
 * @param barrierStyle auxiliary line information.
 * @param index auxiliary line index value.
 * @return The number of dependent components of the barrier.
 * @since 12
 */
int32_t OH_ArkUI_BarrierOption_GetReferencedIdSize(ArkUI_BarrierOption* barrierStyle, int32_t index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the types and parameters related to content transition effects.
 *
 * @since 21
 */
typedef struct ArkUI_ContentTransitionEffect ArkUI_ContentTransitionEffect;

/**
 * @brief creates content switching animation effects.
 *
 * @param type content transition type: 0-identity, 1-opacity.
 * @return content transition effect.
 * @since 21
 */
ArkUI_ContentTransitionEffect* OH_ArkUI_ContentTransitionEffect_Create(int32_t type)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief creates alignment rule information for subcomponents in relative containers.
 *
 * @return Alignment rule information.
 * @since 12
 */
ArkUI_AlignmentRuleOption* OH_ArkUI_AlignmentRuleOption_Create()
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Destroys the alignment rule information of subcomponents in relative containers.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @since 12
 */
void OH_ArkUI_AlignmentRuleOption_Dispose(ArkUI_AlignmentRuleOption* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the start alignment parameter.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @param id The id value of the anchor component.
 * @param alignment Alignment relative to the anchor component.
 * @since 12
 */
void OH_ArkUI_AlignmentRuleOption_SetStart(
    ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the end alignment parameter.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @param id The id value of the anchor component.
 * @param alignment Alignment relative to the anchor component.
 * @since 12
 */
void OH_ArkUI_AlignmentRuleOption_SetEnd(
    ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Set the parameters for horizontal center alignment.
*
* @param option Alignment rule information of subcomponents in the relative container.
* @param id The id value of the anchor component.
* @param alignment Alignment relative to anchor component
* @since 12
*/
void OH_ArkUI_AlignmentRuleOption_SetCenterHorizontal(
    ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the parameters for top alignment.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @param id The id value of the anchor component.
 * @param alignment Alignment relative to anchor component
 * @since 12
 */
void OH_ArkUI_AlignmentRuleOption_SetTop(ArkUI_AlignmentRuleOption* option, const char* id,
    ArkUI_VerticalAlignment alignment)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the bottom alignment parameters.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @param id The id value of the anchor component.
 * @param alignment Alignment relative to anchor component
 * @since 12
 */
void OH_ArkUI_AlignmentRuleOption_SetBottom(
    ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Set the parameters for vertical center alignment.
*
* @param option Alignment rule information of subcomponents in the relative container.
* @param id The id value of the anchor component.
* @param alignment Alignment relative to the anchor component.
* @since 12
*/
void OH_ArkUI_AlignmentRuleOption_SetCenterVertical(
    ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets the horizontal offset parameter of the component under the anchor point constraint.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @param horizontal bias value in the horizontal direction.
 * @since 12
 */
void OH_ArkUI_AlignmentRuleOption_SetBiasHorizontal(ArkUI_AlignmentRuleOption* option, float horizontal)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the vertical offset parameter of the component under the anchor point constraint.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @param vertical bias value in the vertical direction.
 * @since 12
 */
void OH_ArkUI_AlignmentRuleOption_SetBiasVertical(ArkUI_AlignmentRuleOption* option, float vertical)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get the Id of the start-aligned parameter.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @return The id value of the anchor component.
 * @since 12
 */
const char* OH_ArkUI_AlignmentRuleOption_GetStartId(ArkUI_AlignmentRuleOption* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Gets the alignment of the start-aligned parameter.
*
* @param option Alignment rule information of subcomponents in the relative container.
* @return The alignment of the parameters.
* @since 12
*/
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetStartAlignment(ArkUI_AlignmentRuleOption* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get the end alignment parameter.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @return End-aligned parameter id.
 * @since 12
 */
const char* OH_ArkUI_AlignmentRuleOption_GetEndId(ArkUI_AlignmentRuleOption* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Get the end alignment parameter.
*
* @param option Alignment rule information of subcomponents in the relative container.
* @return The alignment of the end-aligned parameter.
* @since 12
*/
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetEndAlignment(ArkUI_AlignmentRuleOption* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Gets the parameters of horizontal center alignment.
*
* @param option Alignment rule information of subcomponents in the relative container.
* @return The id of the parameter of horizontal center alignment.
* @since 12
*/
const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdHorizontal(ArkUI_AlignmentRuleOption* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Gets the parameters of horizontal center alignment.
*
* @param option Alignment rule information of subcomponents in the relative container.
* @return The alignment of the horizontally centered alignment parameter.
* @since 12
*/
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentHorizontal(ArkUI_AlignmentRuleOption* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get the top-aligned parameters.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @return Top aligned parameter id.
 * @since 12
 */
const char* OH_ArkUI_AlignmentRuleOption_GetTopId(ArkUI_AlignmentRuleOption* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Get the top-aligned parameters.
*
* @param option Alignment rule information of subcomponents in the relative container.
* @return The alignment of the top-aligned parameter.
* @since 12
*/
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetTopAlignment(ArkUI_AlignmentRuleOption* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get the bottom alignment parameters.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @return The id of the bottom-aligned parameter.
 * @since 12
 */
const char* OH_ArkUI_AlignmentRuleOption_GetBottomId(ArkUI_AlignmentRuleOption* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Get the bottom alignment parameters.
*
* @param option Alignment rule information of subcomponents in the relative container.
* @return The alignment of the bottom-aligned parameter.
* @since 12
*/
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetBottomAlignment(ArkUI_AlignmentRuleOption* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Gets the parameters of vertical center alignment.
*
* @param option Alignment rule information of subcomponents in the relative container.
* @return The id of the vertical center alignment parameter.
* @since 12
*/
const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdVertical(ArkUI_AlignmentRuleOption* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Gets the parameters of vertical center alignment.
*
* @param option Alignment rule information of subcomponents in the relative container.
* @return The alignment of the vertical center alignment parameter.
* @since 12
*/
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentVertical(ArkUI_AlignmentRuleOption* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get the bias value in the horizontal direction.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @return The bias value in the horizontal direction.
 * @since 12
 */
float OH_ArkUI_AlignmentRuleOption_GetBiasHorizontal(ArkUI_AlignmentRuleOption* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get the bias value in the vertical direction.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @return bias value in vertical direction.
 * @since 12
*/
float OH_ArkUI_AlignmentRuleOption_GetBiasVertical(ArkUI_AlignmentRuleOption* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Create a configuration item for the ListitemSwipeActionItem interface settings.
 *
 * @return List Item SwipeActionItem configuration item instance. If the object returns a null pointer,
 *         it indicates creation failure, and the reason for the failure may be that the address space is full.
 * @since 12
*/
ArkUI_ListItemSwipeActionItem* OH_ArkUI_ListItemSwipeActionItem_Create()
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Destroy the ListitemSwipeActionItem instance.
*
* @param item List Item SwipeActionItem instance to be destroyed.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionItem_Dispose(ArkUI_ListItemSwipeActionItem* item)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Set the layout content of ListItem SwipeActionItem.
*
* @param item List Item SwipeActionItem instance.
* @param node Layout information.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionItem_SetContent(ArkUI_ListItemSwipeActionItem* item, ArkUI_NodeHandle node)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Set the threshold for long-distance sliding deletion distance of components.
*
* @param item List Item SwipeActionItem instance.
* @param distance Component long-distance sliding deletion distance threshold.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionItem_SetActionAreaDistance(ArkUI_ListItemSwipeActionItem* item, float distance)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Obtain the threshold for long-distance sliding deletion distance of components.
*
* @param item List Item SwipeActionItem instance.
* @return Component long-distance sliding deletion distance threshold. If -1.0f is returned, the return fails.
*         The possible cause of the failure is that the item parameter is abnormal, such as a null pointer.
* @since 12
*/
float OH_ArkUI_ListItemSwipeActionItem_GetActionAreaDistance(ArkUI_ListItemSwipeActionItem* item)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Set the event to be called when a sliding entry enters the deletion area.
*
* @param item List Item SwipeActionItem instance.
* @param callback Callback Events.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionArea(ArkUI_ListItemSwipeActionItem* item, void (*callback)())
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the event triggered when a sliding entry enters the deletion area.
 *
 * @param item List Item SwipeActionItem instance.
 * @param userData User defined data.
 * @param callback Callback Events.
 * @since 12
 */
void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionAreaWithUserData(ArkUI_ListItemSwipeActionItem* item,
    void* userData, void (*callback)(void* userData))
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Set the event to be called when a component enters the long-range deletion area and deletes a ListItem.
*
* @param item List Item SwipeActionItem instance.
* @param callback Callback Events.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionItem_SetOnAction(ArkUI_ListItemSwipeActionItem* item, void (*callback)())
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the event triggered when a component enters the long-range deletion area and deletes a ListItem.
 *
 * @param item List Item SwipeActionItem instance.
 * @param userData User defined data.
 * @param callback Callback Events.
 * @since 12
 */
void OH_ArkUI_ListItemSwipeActionItem_SetOnActionWithUserData(ArkUI_ListItemSwipeActionItem* item,
    void* userData, void (*callback)(void* userData))
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Set the event to be called when a sliding entry exits the deletion area.
*
* @param item List Item SwipeActionItem instance.
* @param callback Callback Events.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionArea(ArkUI_ListItemSwipeActionItem* item, void (*callback)())
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the event triggered when a sliding entry exits the deletion area.
 *
 * @param item List Item SwipeActionItem instance.
 * @param userData User defined data.
 * @param callback Callback Events.
 * @since 12
 */
void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionAreaWithUserData(ArkUI_ListItemSwipeActionItem* item,
    void* userData, void (*callback)(void* userData))
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Set the event triggered when the sliding state of a list item changes.
*
* @param item List Item SwipeActionItem instance.
* @param callback Callback Events.
*        swipeActionState The changed state.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChange(ArkUI_ListItemSwipeActionItem* item,
    void (*callback)(ArkUI_ListItemSwipeActionState swipeActionState))
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the event triggered when the sliding state of a list item changes.
 *
 * @param item List Item SwipeActionItem instance.
 * @param userData User defined data.
 * @param callback Callback Events.
 *        swipeActionState The changed state.
 * @since 12
 */
void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChangeWithUserData(ArkUI_ListItemSwipeActionItem* item,
    void* userData, void (*callback)(ArkUI_ListItemSwipeActionState swipeActionState, void* userData))
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Create a configuration item for the ListitemSwipeActionOption interface settings.
 *
 * @return List Item SwipeActionOption configuration item instance.If the object returns a null pointer,
 *         it indicates a creation failure, and the reason for the failure may be that the address space is full.
 * @since 12
*/
ArkUI_ListItemSwipeActionOption* OH_ArkUI_ListItemSwipeActionOption_Create()
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Destroy the ListitemSwipeActionOption instance.
*
* @param option List Item SwipeActionOption instance to be destroyed.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionOption_Dispose(ArkUI_ListItemSwipeActionOption* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Set the layout content on the left (vertical layout) or top (horizontal layout)
* of the ListItem SwipeActionItem.
*
* @param option List Item SwipeActionItem instance.
* @param item Layout information.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionOption_SetStart(ArkUI_ListItemSwipeActionOption* option,
    ArkUI_ListItemSwipeActionItem* item)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Set the layout content on the right (vertical layout) or bottom (horizontal layout)
* of the ListItem SwipeActionItem.
*
* @param option List Item SwipeActionItem instance.
* @param item Layout information.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionOption_SetEnd(ArkUI_ListItemSwipeActionOption* option,
    ArkUI_ListItemSwipeActionItem* item)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Set the sliding effect.
*
* @param option List Item SwipeActionItem instance.
* @param edgeEffect Sliding effect.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionOption_SetEdgeEffect(ArkUI_ListItemSwipeActionOption* option,
    ArkUI_ListItemSwipeEdgeEffect edgeEffect)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Get the sliding effect.
*
* @param option List Item SwipeActionItem instance.
* @return Sliding effect. The default return value is 0. If -1 is returned, the return fails.
*         The possible cause of the failure is that the option parameter is abnormal, such as a null pointer.
* @since 12
*/
int32_t OH_ArkUI_ListItemSwipeActionOption_GetEdgeEffect(ArkUI_ListItemSwipeActionOption* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief The event called when the sliding operation offset changes.
*
* @param option List Item SwipeActionItem instance.
* @param callback Callback Events.
*        offset Slide offset.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChange(ArkUI_ListItemSwipeActionOption* option,
    void (*callback)(float offset))
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the event triggered when the sliding operation offset changes.
 *
 * @param option List Item SwipeActionItem instance.
 * @param userData User defined data.
 * @param callback Callback Events.
 *        offset Slide offset.
 * @since 12
 */
void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChangeWithUserData(ArkUI_ListItemSwipeActionOption* option,
    void* userData, void (*callback)(float offset, void* userData))
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Create configuration items for the ListChildrenMainSize interface settings.
 *
 * @return ListChildrenMainSize configuration item instance.If the object returns a null pointer,
 *         it indicates a creation failure, and the reason for the failure may be that the address space is full.
 * @since 12
*/
ArkUI_ListChildrenMainSize* OH_ArkUI_ListChildrenMainSizeOption_Create()
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Destroy the ListChildrenMainSize instance.
*
* @param option The ListChildrenMainSize instance to be destroyed.
* @since 12
*/
void OH_ArkUI_ListChildrenMainSizeOption_Dispose(ArkUI_ListChildrenMainSize* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the default size of ChildrenMainSizeOption for the List component.
 *
 * @param option ListChildrenMainSize instance.
 * @param defaultMainSize The default size of the ListItem under the List, measured in vp.
 * @return 0 represents success. If defaultMainSize is less than 0 or option is a null pointer, return 401.
 * @since 12
*/
int32_t OH_ArkUI_ListChildrenMainSizeOption_SetDefaultMainSize(ArkUI_ListChildrenMainSize* option,
    float defaultMainSize)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get the default size of ChildrenMainSizeOption for the List component.
 *
 * @param option ListChildrenMainSize instance.
 * @return The default size of the ListItem under the List is 0, measured in vp.
 *         When the option is a null pointer, it returns -1.
 * @since 12
*/
float OH_ArkUI_ListChildrenMainSizeOption_GetDefaultMainSize(ArkUI_ListChildrenMainSize* option)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Reset the array size of ChildrenMainSizeOption for the List component.
 *
 * @param option ListChildrenMainSize instance.
 * @param totalSize Array size.
 * @since 12
*/
void OH_ArkUI_ListChildrenMainSizeOption_Resize(ArkUI_ListChildrenMainSize* option, int32_t totalSize)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Resize the ChildrenMainSizeOption array operation on the List component.
 *
 * @param option ListChildrenMainSize instance.
 * @param index To modify the starting position of the MainSize array.
 * @param deleteCount The number of MainSize arrays to be deleted starting from index.
 * @param addCount The number of MainSize arrays to be added starting from index.
 * @return 0 represents success. If the function parameter is abnormal, return 401.
 * @since 12
*/
int32_t OH_ArkUI_ListChildrenMainSizeOption_Splice(ArkUI_ListChildrenMainSize* option, int32_t index,
    int32_t deleteCount, int32_t addCount)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Update the value of the ChildrenMainSizeOption array in the List component.
 *
 * @param option ListChildrenMainSize instance.
 * @param index To modify the starting position of the MainSize array.
 * @param mainSize The actual modified value.
 * @return 0 represents success. If the function parameter is abnormal, return 401.
 * @since 12
*/
int32_t OH_ArkUI_ListChildrenMainSizeOption_UpdateSize(ArkUI_ListChildrenMainSize* option,
    int32_t index, float mainSize)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get the value of the ChildrenMainSizeOption array for the List component.
 *
 * @param option ListChildrenMainSize instance.
 * @param index The index position of the value to be obtained.
 * @return The value of the specific position of the array. If the function parameter is abnormal, return -1.
 * @since 12
*/
float OH_ArkUI_ListChildrenMainSizeOption_GetMainSize(ArkUI_ListChildrenMainSize* option, int32_t index)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Creates measurement information for this custom span.
 *
 * @return Returns a <b>CustomSpanMeasureInfo</b> instance.
 * <br> If the result returns nullptr, there may be out of memory.
 * @since 12
*/
ArkUI_CustomSpanMeasureInfo* OH_ArkUI_CustomSpanMeasureInfo_Create(void)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Disposes of measurement information of this custom span.
 *
 * @param info The CustomSpanMeasureInfo instance to be destroyed.
 * @since 12
*/
void OH_ArkUI_CustomSpanMeasureInfo_Dispose(ArkUI_CustomSpanMeasureInfo* info)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the font size of a custom span.
 *
 * @param info Indicates the pointer to the measurement information of a custom span.
 * @return Returns the font size. If a parameter error occurs, <b>0.0f</b> is returned.
 * <br> Possible causes: Parameter verification failed, the parameter should not be nullptr.
 * @since 12
*/
float OH_ArkUI_CustomSpanMeasureInfo_GetFontSize(ArkUI_CustomSpanMeasureInfo* info)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Creates measurement metrics for this custom span.
 *
 * @return Returns a <b>CustomSpanMetrics</b> instance.
 * <br> If the result returns nullptr, there may be out of memory.
 * @since 12
*/
ArkUI_CustomSpanMetrics* OH_ArkUI_CustomSpanMetrics_Create(void)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Disposes of measurement metrics of this custom span.
 *
 * @param metrics The CustomSpanMetrics instance to be destroyed.
 * @since 12
*/
void OH_ArkUI_CustomSpanMetrics_Dispose(ArkUI_CustomSpanMetrics* metrics)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets the width for a custom span.
 *
 * @param metrics Indicates the pointer to a <b>CustomSpanMetrics</b> instance.
 * @param width Indicates the width, in px. The width should be greater than 0.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         <br> Possible causes: Parameter verification failed, the parameter should not be nullptr.
 * @since 12
*/
int32_t OH_ArkUI_CustomSpanMetrics_SetWidth(ArkUI_CustomSpanMetrics* metrics, float width)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Sets the height for a custom span.
 *
 * @param metrics Indicates the pointer to a <b>CustomSpanMetrics</b> instance.
 * @param width Indicates the height, in px. The width should be greater than 0.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         <br> Possible causes: Parameter verification failed, the parameter should not be nullptr.
 * @since 12
*/
int32_t OH_ArkUI_CustomSpanMetrics_SetHeight(ArkUI_CustomSpanMetrics* metrics, float height)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Creates drawing information for this custom span.
 *
 * @return Returns a <b>CustomSpanDrawInfo</b> instance.
 * <br> If the result returns nullptr, there may be out of memory.
 * @since 12
*/
ArkUI_CustomSpanDrawInfo* OH_ArkUI_CustomSpanDrawInfo_Create(void)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Disposes of drawing information for this custom span.
 *
 * @param info The CustomSpanDrawInfo instance to be destroyed.
 * @since 12
*/
void OH_ArkUI_CustomSpanDrawInfo_Dispose(ArkUI_CustomSpanDrawInfo* info)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the x-axis offset of the custom span relative to the mounted component.
 *
 * @param info Indicates the pointer to the drawing information of a custom span.
 * @return Returns the x-axis offset. If a parameter error occurs, <b>0.0f</b> is returned.
 * <br> Possible causes: Parameter verification failed, the parameter should not be nullptr.
 * @since 12
*/
float OH_ArkUI_CustomSpanDrawInfo_GetXOffset(ArkUI_CustomSpanDrawInfo* info)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the top margin of the custom span relative to the mounted component.
 *
 * @param info Indicates the pointer to the drawing information of a custom span.
 * @return Returns the top margin. If a parameter error occurs, <b>0.0f</b> is returned.
 * <br> Possible causes: Parameter verification failed, the parameter should not be nullptr.
 * @since 12
*/
float OH_ArkUI_CustomSpanDrawInfo_GetLineTop(ArkUI_CustomSpanDrawInfo* info)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the bottom margin of the custom span relative to the mounted component.
 *
 * @param info Indicates the pointer to the drawing information of a custom span.
 * @return Returns the bottom margin. If a parameter error occurs, <b>0.0f</b> is returned.
 * <br> Possible causes: Parameter verification failed, the parameter should not be nullptr.
 * @since 12
*/
float OH_ArkUI_CustomSpanDrawInfo_GetLineBottom(ArkUI_CustomSpanDrawInfo* info)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Obtains the baseline offset of the custom span relative to the mounted component.
 *
 * @param info Indicates the pointer to the drawing information of a custom span.
 * @return Returns the baseline offset. If a parameter error occurs, <b>0.0f</b> is returned.
 * <br> Possible causes: Parameter verification failed, the parameter should not be nullptr.
 * @since 12
*/
float OH_ArkUI_CustomSpanDrawInfo_GetBaseline(ArkUI_CustomSpanDrawInfo* info)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Create a image frame from the image path.
 * @param src Indicates the image path.
 * @return Returns the pointer to the image frame object.
 * If a null pointer is returned, the object fails to be created. The possible cause is that
 * the src parameter is abnormal, for example, the pointer is null.
 * @since 12
*/
ArkUI_ImageAnimatorFrameInfo* OH_ArkUI_ImageAnimatorFrameInfo_CreateFromString(char* src)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Create a image frame from the drawable descriptor.
 *
 * @param drawable Indicates the pointer to the drawable descriptor.
 * @return Returns the pointer to the image frame object.
 * If a null pointer is returned, the object fails to be created. The possible cause is that
 * the drawable parameter is abnormal, for example, the pointer is null.
 * @since 12
*/
ArkUI_ImageAnimatorFrameInfo* OH_ArkUI_ImageAnimatorFrameInfo_CreateFromDrawableDescriptor(
    ArkUI_DrawableDescriptor* drawable)
    __attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Destroy the pointer to the image frame.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @since 12
*/
void OH_ArkUI_ImageAnimatorFrameInfo_Dispose(ArkUI_ImageAnimatorFrameInfo* imageInfo)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the width of the image frame.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @param width Indicates the width of the image frame, and the unit is PX.
 * @since 12
*/
void OH_ArkUI_ImageAnimatorFrameInfo_SetWidth(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t width)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get the width of the image frame.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @return Return the width of the image frame, and the unit is PX. Return 0 when the imageInfo is null.
 * @since 12
*/
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetWidth(ArkUI_ImageAnimatorFrameInfo* imageInfo)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the height of the image frame.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @param height Indicates the height of the image frame, and the unit is PX.
 * @since 12
*/
void OH_ArkUI_ImageAnimatorFrameInfo_SetHeight(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t height)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get the height of the image frame.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @return Return the height of the image frame, and the unit is PX. Return 0 when the imageInfo is null.
 * @since 12
*/
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetHeight(ArkUI_ImageAnimatorFrameInfo* imageInfo)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the vertical coordinate of the image relative to the upper left corner of the widget.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @param top Indicates the vertical coordinate of the image relative to the upper left corner of the widget,
 * and the unit is PX.
 * @since 12
*/
void OH_ArkUI_ImageAnimatorFrameInfo_SetTop(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t top)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get the vertical coordinate of the image relative to the upper left corner of the widget.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @return Returns the vertical coordinate of the image relative to the upper left corner of the widget,
 * and the unit is PX. Return 0 when the imageInfo is null.
 * @since 12
*/
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetTop(ArkUI_ImageAnimatorFrameInfo* imageInfo)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the horizontal coordinate of the image relative to the upper left corner of the widget.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @param left Indicates the horizontal coordinate of the image relative to the upper left corner of the widget,
 * and the unit is PX.
 * @since 12
*/
void OH_ArkUI_ImageAnimatorFrameInfo_SetLeft(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t left)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get the horizontal coordinate of the image relative to the upper left corner of the widget.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @return Returns the horizontal coordinate of the image relative to the upper left corner of the widget,
 * and the unit is PX. Return 0 when the imageInfo is null.
 * @since 12
*/
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetLeft(ArkUI_ImageAnimatorFrameInfo* imageInfo)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set the playback duration of the image frame.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @param duration Indicates the playback duration of each image frame, and the unit is milliseconds.
 * @since 12
*/
void OH_ArkUI_ImageAnimatorFrameInfo_SetDuration(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t duration)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get the playback duration of the image frame.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @return Returns the playback duration of the image frame, and the unit is milliseconds.
 * Return 0 when the imageInfo is null.
 * @since 12
*/
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetDuration(ArkUI_ImageAnimatorFrameInfo* imageInfo)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Create accessibility state.
 *
 * @return Returns the pointer to the accessibility state object.
 * If a null pointer is returned, the object fails to be created. The possible cause is that the address space is full.
 * @since 12
*/
ArkUI_AccessibilityState* OH_ArkUI_AccessibilityState_Create(void)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Dispose accessibility state.
*
* @param state accessibility state object.
* @since 12
*/
void OH_ArkUI_AccessibilityState_Dispose(ArkUI_AccessibilityState* state)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set accessibility state disabled.
 *
 * @param state accessibility state object.
 * @param isDisabled accessibility state disabled, Value 1 indicates disabled and 0 indicates enbled.
 * @since 12
*/
void OH_ArkUI_AccessibilityState_SetDisabled(ArkUI_AccessibilityState* state, int32_t isDisabled)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get accessibility state disabled.
 *
 * @param state accessibility state object.
 * @return accessibility state disabled, Value 1 indicates disabled and 0 indicates enbled. The default value is 0.
 *         If the function parameter is abnormal, return the default value.
 * @since 12
*/
int32_t OH_ArkUI_AccessibilityState_IsDisabled(ArkUI_AccessibilityState* state)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set accessibility state selected.
 *
 * @param state accessibility state object.
 * @param isSelected accessibility state selected, Value 1 indicates selected, and 0 indicates not selected.
 *        The default value is 0.
 * @since 12
*/
void OH_ArkUI_AccessibilityState_SetSelected(ArkUI_AccessibilityState* state, int32_t isSelected)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get accessibility state selected.
 *
 * @param state accessibility state object.
 * @return accessibility state selected, Value 1 indicates selected, and 0 indicates not selected.
 *         The default value is 0.
 *         If the function parameter is abnormal, return the default value.
 * @since 12
*/
int32_t OH_ArkUI_AccessibilityState_IsSelected(ArkUI_AccessibilityState* state)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set accessibility checked state.
 *
 * @param state accessibility state object.
 * @param checkedState checked state, and uses the {@link ArkUI_AccessibilityCheckedState} enumeration value,
 *        The default value is ARKUI_ACCESSIBILITY_UNCHECKED.
 * @since 12
*/
void OH_ArkUI_AccessibilityState_SetCheckedState(ArkUI_AccessibilityState* state, int32_t checkedState)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get accessibility checked state.
 *
 * @param state accessibility state object.
 * @return checked state, and uses the {@link ArkUI_AccessibilityCheckedState} enumeration value,
 *         The default value is ARKUI_ACCESSIBILITY_UNCHECKED.
 *         If the function parameter is abnormal, return the default value.
 * @since 12
*/
int32_t OH_ArkUI_AccessibilityState_GetCheckedState(ArkUI_AccessibilityState* state)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Create accessibility value.
 *
 * @return Returns the pointer to the accessibility state object.
 * If a null pointer is returned, the object fails to be created. The possible cause is that the address space is full.
 * @since 12
*/
ArkUI_AccessibilityValue* OH_ArkUI_AccessibilityValue_Create(void)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
* @brief Dispose accessibility value.
*
* @param value accessibility value object.
* @since 12
*/
void OH_ArkUI_AccessibilityValue_Dispose(ArkUI_AccessibilityValue* value)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set accessibility minimum value.
 *
 * @param value accessibility value object.
 * @param min minimum value based on range components, The default value is -1.
 * @since 12
*/
void OH_ArkUI_AccessibilityValue_SetMin(ArkUI_AccessibilityValue* value, int32_t min)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get accessibility minimum value.
 *
 * @param value accessibility value object.
 * @return minimum value based on range components, The default value is -1.
 *         If the function parameter is abnormal, return -1.
 * @since 12
*/
int32_t OH_ArkUI_AccessibilityValue_GetMin(ArkUI_AccessibilityValue* value)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set accessibility minimum value.
 *
 * @param value accessibility value object.
 * @param max maximum value based on range components, The default value is -1.
 * @since 12
*/
void OH_ArkUI_AccessibilityValue_SetMax(ArkUI_AccessibilityValue* value, int32_t max)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get accessibility minimum value.
 *
 * @param value accessibility value object.
 * @return maximum value based on range components, The default value is -1.
 *         If the function parameter is abnormal, return -1.
 * @since 12
*/
int32_t OH_ArkUI_AccessibilityValue_GetMax(ArkUI_AccessibilityValue* value)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set accessibility current value.
 *
 * @param value accessibility value object.
 * @param current value based on range components, The default value is -1.
 * @since 12
*/
void OH_ArkUI_AccessibilityValue_SetCurrent(ArkUI_AccessibilityValue* value, int32_t current)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get accessibility current value.
 *
 * @param value accessibility value object.
 * @return current value based on range components, The default value is -1.
 *         If the function parameter is abnormal, return -1.
 * @since 12
*/
int32_t OH_ArkUI_AccessibilityValue_GetCurrent(ArkUI_AccessibilityValue* value)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Set accessibility minimum value.
 *
 * @param value accessibility value object.
 * @param rangeMin minimum value based on range components, The default value is -1.
 * @since 18
*/
void OH_ArkUI_AccessibilityValue_SetRangeMin(ArkUI_AccessibilityValue* value, int32_t rangeMin)
__attribute__((__availability__(ohos, introduced=18.0.0)));

/**
 * @brief Get accessibility minimum value.
 *
 * @param value accessibility value object.
 * @return minimum value based on range components, The default value is -1.
 *         If the function parameter is abnormal, return -1.
 * @since 18
*/
int32_t OH_ArkUI_AccessibilityValue_GetRangeMin(ArkUI_AccessibilityValue* value)
__attribute__((__availability__(ohos, introduced=18.0.0)));

/**
 * @brief Set accessibility maximum value.
 *
 * @param value accessibility value object.
 * @param rangeMax maximum value based on range components, The default value is -1.
 * @since 18
*/
void OH_ArkUI_AccessibilityValue_SetRangeMax(ArkUI_AccessibilityValue* value, int32_t rangeMax)
__attribute__((__availability__(ohos, introduced=18.0.0)));

/**
 * @brief Get accessibility maximum value.
 *
 * @param value accessibility value object.
 * @return maximum value based on range components, The default value is -1.
 *         If the function parameter is abnormal, return -1.
 * @since 18
*/
int32_t OH_ArkUI_AccessibilityValue_GetRangeMax(ArkUI_AccessibilityValue* value)
__attribute__((__availability__(ohos, introduced=18.0.0)));

/**
 * @brief Set accessibility current value.
 *
 * @param value accessibility value object.
 * @param rangeCurrent value based on range components, The default value is -1.
 * @since 18
*/
void OH_ArkUI_AccessibilityValue_SetRangeCurrent(ArkUI_AccessibilityValue* value, int32_t rangeCurrent)
__attribute__((__availability__(ohos, introduced=18.0.0)));

/**
 * @brief Get accessibility current value.
 *
 * @param value accessibility value object.
 * @return current value based on range components, The default value is -1.
 *         If the function parameter is abnormal, return -1.
 * @since 18
*/
int32_t OH_ArkUI_AccessibilityValue_GetRangeCurrent(ArkUI_AccessibilityValue* value)
__attribute__((__availability__(ohos, introduced=18.0.0)));

/**
 * @brief Set accessibility text value.
 *
 * @param value accessibility value object.
 * @param text The textual description information of the component, which defaults to an empty string.
 * @since 12
*/
void OH_ArkUI_AccessibilityValue_SetText(ArkUI_AccessibilityValue* value, const char* text)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Get accessibility text value.
 *
 * @param value accessibility value object.
 * @return The textual description information of the component, which defaults to an empty string;
 *         If the function parameter is abnormal, return null.
 * @since 12
*/
const char* OH_ArkUI_AccessibilityValue_GetText(ArkUI_AccessibilityValue* value)
__attribute__((__availability__(ohos, introduced=12.0.0)));

/**
 * @brief Destroy the instance of Customs Property.
 *
 * @param handle The instance of Customs Property to be destroyed.
 * @since 14
 */
void OH_ArkUI_CustomProperty_Destroy(ArkUI_CustomProperty* handle)
__attribute__((__availability__(ohos, introduced=14.0.0)));

/**
 * @brief Get custom attribute value information.
 *
 * @param handle Custom attribute object pointer.
 * @return Customize the value information within the attribute structure.
 * @since 14
 */
const char* OH_ArkUI_CustomProperty_GetStringValue(ArkUI_CustomProperty* handle)
__attribute__((__availability__(ohos, introduced=14.0.0)));

/**
 * @brief Get window name from HostWindowInfo.
 *
 * @param info HostWindowInfo object pointer.
 * @return Window name in HostWindowInfo.
 * @since 15
 */
const char* OH_ArkUI_HostWindowInfo_GetName(ArkUI_HostWindowInfo* info)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Destroy the instance of HostWindowInfo.
 *
 * @param info Instance of HostWindowInfo to be destroyed.
 * @since 15
 */
void OH_ArkUI_HostWindowInfo_Destroy(ArkUI_HostWindowInfo* info)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Destroy ActiveChildenInfo instance.
 *
 * @param handle ActiveChild instance to be destroyed.
 * @since 14
 */
void OH_ArkUI_ActiveChildrenInfo_Destroy(ArkUI_ActiveChildrenInfo* handle)
__attribute__((__availability__(ohos, introduced=14.0.0)));

/**
 * @brief Retrieve the child nodes of ActiveChildenInfo with the structure index.
 *
 * @param handle The ActiveChildenInfo instance for obtaining information.
 * @param index The index of child nodes.
 * @return The child node pointer corresponding to the index. Return nullptr in case of exception.
 * @since 14
 */
ArkUI_NodeHandle OH_ArkUI_ActiveChildrenInfo_GetNodeByIndex(ArkUI_ActiveChildrenInfo* handle, int32_t index)
__attribute__((__availability__(ohos, introduced=14.0.0)));

/**
 * @brief Retrieve the number of nodes within the structure of ActiveChildenInfo.
 *
 * @param handle The ActiveChildenInfo instance for obtaining information.
 * @return Number of child nodes. Default value: 0.
 * @since 14
 */
int32_t OH_ArkUI_ActiveChildrenInfo_GetCount(ArkUI_ActiveChildrenInfo* handle)
__attribute__((__availability__(ohos, introduced=14.0.0)));

/**
 * @brief Create linear progress indicator style information.
 *
 * @return Returns a <b>ProgressLinearStyleOption</b> instance.
 * <br> If the result returns nullptr, there may be out of memory.
 * @since 15
 */
ArkUI_ProgressLinearStyleOption* OH_ArkUI_ProgressLinearStyleOption_Create(void)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Destroy linear progress indicator style information.
 *
 * @param option Linear progress indicator style information.
 * @since 15
 */
void OH_ArkUI_ProgressLinearStyleOption_Destroy(ArkUI_ProgressLinearStyleOption* option)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Set whether the scan effect is enabled.
 *
 * @param option Linear progress indicator style information.
 * @param enabled Whether to enable the scan effect. Default value: false.
 * @since 15
 */
void OH_ArkUI_ProgressLinearStyleOption_SetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Set whether smoothing effect is enabled.
 *
 * @param option Linear progress indicator style information.
 * @param enabled Whether to enable the smooth effect. When this effect is enabled, the progress change to
 * the set value takes place gradually. Otherwise, it takes place immediately. Default value: true.
 * @since 15
 */
void OH_ArkUI_ProgressLinearStyleOption_SetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Set linear progress indicator stroke width.
 *
 * @param option Linear progress indicator style information.
 * @param strokeWidth Stroke width of the progress indicator. It cannot be set in percentage.
 * Default value: 4.0vp.
 * @since 15
 */
void OH_ArkUI_ProgressLinearStyleOption_SetStrokeWidth(ArkUI_ProgressLinearStyleOption* option, float strokeWidth)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Set linear progress indicator stroke radius.
 *
 * @param option Linear progress indicator style information.
 * @param strokeRadius Rounded corner radius of the progress indicator. Value range: [0, strokeWidth/2].
 * Default value: strokeWidth/2.
 * @since 15
 */
void OH_ArkUI_ProgressLinearStyleOption_SetStrokeRadius(ArkUI_ProgressLinearStyleOption* option, float strokeRadius)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Get whether scan effect is enable.
 *
 * @param option Linear progress indicator style information.
 * @return Whether to enable the scan effect.
 * @since 15
 */
bool OH_ArkUI_ProgressLinearStyleOption_GetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Get whether smoothing effect is enabled.
 *
 * @param option Linear progress indicator style information.
 * @return Whether to enable the smooth effect.
 * @since 15
 */
bool OH_ArkUI_ProgressLinearStyleOption_GetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Get linear progress indicator stroke width.
 *
 * @param option Linear progress indicator style information.
 * @return Stroke width of the progress indicator.
 * @since 15
 */
float OH_ArkUI_ProgressLinearStyleOption_GetStrokeWidth(ArkUI_ProgressLinearStyleOption* option)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Get linear progress indicator stroke radius.
 *
 * @param option Linear progress indicator style information.
 * @return Rounded corner radius of the progress indicator.
 * @since 15
 */
float OH_ArkUI_ProgressLinearStyleOption_GetStrokeRadius(ArkUI_ProgressLinearStyleOption* option)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Create a cross-language option instance.
 *
 * @return Returns a cross-language option instance. If the result is a null pointer, it may be out of memory.
 * @since 15
 */
ArkUI_CrossLanguageOption* OH_ArkUI_CrossLanguageOption_Create(void)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Destroy the cross-language option instance.
 *
 * @param option The cross-language option instance.
 * @since 15
 */
void OH_ArkUI_CrossLanguageOption_Destroy(ArkUI_CrossLanguageOption* option)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Enable the attribute setting in the cross-language option.
 *
 * @param option The cross-language option.
 * @param enabled The attribute setting in the cross-language option.
 * Default value: false.
 * @since 15
 */
void OH_ArkUI_CrossLanguageOption_SetAttributeSettingStatus(ArkUI_CrossLanguageOption* option, bool enabled)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Get the attribute setting enable of the cross-language option.
 *
 * @param option The cross-language option.
 * @return The attribute setting enable of the cross-language option.
 * @since 15
 */
bool OH_ArkUI_CrossLanguageOption_GetAttributeSettingStatus(ArkUI_CrossLanguageOption* option)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Creates an option for taking snapshot, the returned value must be released through
 *        {@link OH_ArkUI_DestroySnapshotOptions} when it's not used anymore.
 *
 * @return Returns the pointer to the created snapshot options object.If the object returns a null pointer,
 *         it indicates a creation failure, and the reason for the failure may be that the address space is full.
 * @since 15
 */
ArkUI_SnapshotOptions* OH_ArkUI_CreateSnapshotOptions() __attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Dispose a snapshot option object.
 *
 * @param snapshotOptions Indicates the pointer to the snapshot option.
 * @since 15
 */
void OH_ArkUI_DestroySnapshotOptions(ArkUI_SnapshotOptions* snapshotOptions)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Config the snapshot option with scale.
 *
 * @param snapshotOptions Indicates the pointer to the snapshot option.
 * @param scale Indicates the scale property to take the snapshot.
 * @return Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 * @since 15
 */
int32_t OH_ArkUI_SnapshotOptions_SetScale(ArkUI_SnapshotOptions* snapshotOptions, float scale)
__attribute__((__availability__(ohos, introduced=15.0.0)));

/**
 * @brief Sets the color mode for snapshot capture.
 * By default, snapshots are captured in SRGB mode, which may lose visual effects for components using wide color
 * gamut display modes.
 * If the target component's color space is known, specify it through <b>colorSpace</b> and set <b>isAuto</b> to
 * <b>false</b> to achieve optimal snapshot quality.
 * Since determining the exact color space used by a component is often difficult, set <b>isAuto</b> to <b>true</b>
 * to let the system automatically select the appropriate color space.
 * If <b>isAuto</b> is set to <b>true</b>, the <b>colorSpace</b> parameter value is ignored.
 *
 * @param snapshotOptions Pointer to the target snapshot configuration options.
 * @param colorSpace Target color space. Supported values: <b>3</b> (DISPLAY_P3), <b>4</b> (SRGB), <b>27</b>
 *                   (DISPLAY_BT2020_SRGB).
 * @param isAuto Whether to auto-detect the color space.
 *               <b>true</b>: ignores the <b>colorSpace</b> parameter value and auto-detects the color space.
 *               <b>false</b>: uses the color space specified by <b>colorSpace</b>.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 * @since 23
 */
int32_t OH_ArkUI_SnapshotOptions_SetColorMode(ArkUI_SnapshotOptions* snapshotOptions, int32_t colorSpace, bool isAuto)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Sets the dynamic range mode for snapshot capture.
 * By default, the system captures snapshots in {@link ARKUI_DYNAMIC_RANGE_MODE_STANDARD} mode.
 * To use a specific mode, specify it via the <b>dynamicRangeMode</b> parameter and set <b>isAuto</b> to <b>false</b>.
 * Alternatively, set <b>isAuto</b> to <b>true</b> to let the system auto-detect the appropriate dynamic range mode.
 * If <b>isAuto</b> is set to <b>true</b>, the <b>dynamicRangeMode</b> parameter value is ignored.
 *
 * @param snapshotOptions Pointer to the target snapshot configuration options.
 * @param dynamicRangeMode Target dynamic range mode, specified using {@link ArkUI_DynamicRangeMode}.
 * @param isAuto Whether to auto-detect the dynamic range mode.
 *               <b>true</b>: ignores the <b>dynamicRangeMode</b> parameter value and auto-detects the dynamic range
 *                            mode.
 *               <b>false</b>: uses the dynamic range mode specified by <b>dynamicRangeMode</b>.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 * @since 23
 */
int32_t OH_ArkUI_SnapshotOptions_SetDynamicRangeMode(
    ArkUI_SnapshotOptions* snapshotOptions, int32_t dynamicRangeMode, bool isAuto)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Defines the parameters for visible area change events.
 *
 * @since 17
 */
typedef struct ArkUI_VisibleAreaEventOptions ArkUI_VisibleAreaEventOptions;

/**
* @brief Creates an instance of visible area change event parameters
*
* @return Returns the created instance of visible area change event parameters.
* @since 17
*/
ArkUI_VisibleAreaEventOptions* OH_ArkUI_VisibleAreaEventOptions_Create()
__attribute__((__availability__(ohos, introduced=17.0.0)));

/**
* @brief Disposes of an instance of visible area change event parameters.
*
* @param option Instance to be destroyed.
* @since 17
*/
void OH_ArkUI_VisibleAreaEventOptions_Dispose(ArkUI_VisibleAreaEventOptions* option)
__attribute__((__availability__(ohos, introduced=17.0.0)));

/**
* @brief Sets the threshold ratios for visible area changes.
*
* @param option Instance of visible area change event parameters.
* @param value Array of threshold ratios. Each element represents the ratio of the visible area of a component to
* its total area. The visible area is calculated within the parent component's bounds; any area outside the parent
* component is not considered. Each value must be within the [0.0, 1.0] range.
* Values outside this range will be handled as 0.0 or 1.0.
* @param size Size of the threshold array.
* @return Returns the result code.
*         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
*         If an error code is returned, it may be due to a failure in parameter validation;
*         the parameter must not be null.
* @since 17
*/
int32_t OH_ArkUI_VisibleAreaEventOptions_SetRatios(ArkUI_VisibleAreaEventOptions* option, float* value, int32_t size)
__attribute__((__availability__(ohos, introduced=17.0.0)));

/**
* @brief Sets the expected update interval for visible area changes.
*
* @param option Instance of visible area change event parameters.
* @param value Expected update interval, in ms.  Default value: <b>1000</b>.
* @return Returns the result code.
*         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
*         If an error code is returned, it may be due to a failure in parameter validation;
*         the parameter must not be null.
* @since 17
*/
int32_t OH_ArkUI_VisibleAreaEventOptions_SetExpectedUpdateInterval(
    ArkUI_VisibleAreaEventOptions *option, int32_t value)
    __attribute__((__availability__(ohos, introduced=17.0.0)));

/**
* @brief Sets the flag for controlling if the child components can exceed the parent's bounds.
* if set to false, the part that exceeds the parent's bounds will be considered as invisible area,
* set to true to allow the exceeding, the part that exceeds will be considered as visible area.
*
* Please note that if the parent component set clip(true), the measureFromViewport configuration
* will be ignored.
*
* @param option Instance of visible area change event parameters.
* @param measureFromViewport When this parameter is set to true, the parts of the component
*    that exceed the parent component's area will also be included in the visible area calculation. However, this
*    only applies if the parent component does not explicitly set the clip property to true. If the parent component
*    sets clip to true, regardless of the value of this parameter, the parts that exceed the parent component's area
*    will still be treated as invisible in the visible area calculation.
* Default measureFromViewport: <b>false</b>.
* @return Returns the result code.
*         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
*         If an error code is returned, it may be due to a failure in parameter validation;
*         the parameter must not be null.
* @since 22
*/
int32_t OH_ArkUI_VisibleAreaEventOptions_SetMeasureFromViewport(
    ArkUI_VisibleAreaEventOptions* option, bool measureFromViewport)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Obtains the threshold ratios for visible area changes.
 *
 * @param option Instance of visible area change event parameters.
 * @param value Array of threshold ratios.
 * @param size Size of the threshold array.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} if the provided buffer size is insufficient.
 *         If an error code is returned, it may be due to a failure in parameter validation;
 *         the parameter must not be null.
 * @since 17
 */
int32_t OH_ArkUI_VisibleAreaEventOptions_GetRatios(ArkUI_VisibleAreaEventOptions* option, float* value, int32_t* size)
__attribute__((__availability__(ohos, introduced=17.0.0)));

/**
 * @brief Obtains the expected update interval for visible area changes.
 *
 * @param option Instance of visible area change event parameters.
 * @return Returns the expected update interval, in ms.  Default value: <b>1000</b>.
 * @since 17
 */
int32_t OH_ArkUI_VisibleAreaEventOptions_GetExpectedUpdateInterval(ArkUI_VisibleAreaEventOptions* option)
__attribute__((__availability__(ohos, introduced=17.0.0)));

/**
 * @brief Obtains the value set through {@link OH_ArkUI_VisibleAreaEventOptions_SetMeasureFromViewport} .
 *
 * @param option Instance of visible area change event parameters.
 * @return Returns the flag for controlling of the visible area calculation. Default value: <b>false</b>.
 *
 * @since 22
 */
bool OH_ArkUI_VisibleAreaEventOptions_GetMeasureFromViewport(ArkUI_VisibleAreaEventOptions* option)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 *@brief Creates a TextPickerRangeContent instance.
 *
 *@param length The length of the picker array.
 *@return Returns a <b>TextPickerRangeContent</b> instance.
 *@since 19
 */
ArkUI_TextPickerRangeContentArray* OH_ArkUI_TextPickerRangeContentArray_Create(int32_t length)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 *@brief Sets the icon of items in a text picker ranges.
 *
 *@param handle The TextPickerRangeContent instance for obtaining information.
 *@param icon Icon addreass.
 *@param index The index position of the value to be obtained.
 *@since 19
 */
void OH_ArkUI_TextPickerRangeContentArray_SetIconAtIndex(
    ArkUI_TextPickerRangeContentArray* handle, char* icon, int32_t index)
    __attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 *@brief Sets the text of items in a text picker ranges
 *
 *@param handle The TextPickerRangeContent instance for obtaining information.
 *@param text Text content
 *@param index The index position of the value to be obtained.
 *@since 19
 */
void OH_ArkUI_TextPickerRangeContentArray_SetTextAtIndex(
    ArkUI_TextPickerRangeContentArray* handle, char* text, int32_t index)
    __attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 *@brief Destroy the TextPickerRangeContent instance.
 *
 *@param handle The TextPickerRangeContent instance for obtaining information.
 *@since 19
 */
void OH_ArkUI_TextPickerRangeContentArray_Destroy(ArkUI_TextPickerRangeContentArray* handle)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 *@brief Creates a TextCascadePickerRangeContent instance.
 *
 *@param length The length of the picker array.
 *@return Returns a <b>TextCascadePickerRangeContent</b> instance.
 *@since 19
 */
ArkUI_TextCascadePickerRangeContentArray* OH_ArkUI_TextCascadePickerRangeContentArray_Create(int32_t length)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 *@brief Sets the text of items in a multi text picker ranges.
 *
 *@param handle The TextCascadePickerRangeContent instance for obtaining information.
 *@param text text content
 *@param index The index position of the value to be obtained.
 *@since 19
 */
void OH_ArkUI_TextCascadePickerRangeContentArray_SetTextAtIndex(
    ArkUI_TextCascadePickerRangeContentArray* handle, char* text, int32_t index)
    __attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 *@brief Sets the childs info of items in a multi text picker ranges.
 *
 *@param handle The TextCascadePickerRangeContent instance for obtaining information.
 *@param child The child instance.
 *@param index The index position of the value to be obtained.
 *@since 19
 */
void OH_ArkUI_TextCascadePickerRangeContentArray_SetChildAtIndex(
    ArkUI_TextCascadePickerRangeContentArray* handle, ArkUI_TextCascadePickerRangeContentArray* child, int32_t index)
    __attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 *@brief Destroy the TextCascadePickerRangeContent instance.
 *
 *@param handle The TextCascadePickerRangeContent instance for obtaining information.
 *@since 19
 */
void OH_ArkUI_TextCascadePickerRangeContentArray_Destroy(ArkUI_TextCascadePickerRangeContentArray* handle)
__attribute__((__availability__(ohos, introduced=19.0.0)));

/**
 * @brief Create an object for the EmbeddedComponent option.
 *
 * @return A pointer to the object of the EmbeddedComponent option.
 * @since 20
 */
ArkUI_EmbeddedComponentOption* OH_ArkUI_EmbeddedComponentOption_Create()
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Destroy the object by EmbeddedComponent option.
 *
 * @param option Pointer to the object by the EmbeddeComponent to be destroyed.
 * @since 20
 */
void OH_ArkUI_EmbeddedComponentOption_Dispose(ArkUI_EmbeddedComponentOption* option)
__attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Set the onError of EmbeddedComponent.
 *
 * @param option Pointer to the object option by the EmbeddedComponent.
 * @param code Common error information about the API invoking failure.
 * @param name Common error name information about the API invoking failure.
 * @param message Common error message information about the API invoking failure.
 * @since 20
 */
void OH_ArkUI_EmbeddedComponentOption_SetOnError(
    ArkUI_EmbeddedComponentOption* option, void (*callback)(int32_t code, const char* name, const char* message))
    __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Set the onTerminated of EmbeddedComponent.
 *
 * @param option Pointer to the object option by the EmbeddedComponent.
 * @param code Result code returned when the EmbeddedUIExtensionAbility exits.
 * @param want Data returned when the EmbeddedUIExtensionAbility exits.
 * @since 20
 */
void OH_ArkUI_EmbeddedComponentOption_SetOnTerminated(
    ArkUI_EmbeddedComponentOption* option, void (*callback)(int32_t code, AbilityBase_Want* want))
    __attribute__((__availability__(ohos, introduced=20.0.0)));

/**
 * @brief Expand the swipe action.
 *
 * @param node List Item node.
 * @param direction expand direction of swipeAction.
 * @return Error code.
 *         {@link ARKUI_ERROR_CODE_NO_ERROR} success.
 *         {@link ARKUI_ERROR_CODE_PARAM_ERROR} The component type of the node is incorrect.
 *         {@link ARKUI_ERROR_CODE_NODE_NOT_ON_MAIN_TREE} The node not mounted to component tree.
 * @since 21
 */
int32_t OH_ArkUI_ListItemSwipeAction_Expand(ArkUI_NodeHandle node, ArkUI_ListItemSwipeActionDirection direction)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Collapse the swipe action.
 *
 * @param node List Item node.
 * @return Error code.
 *         {@link ARKUI_ERROR_CODE_NO_ERROR} success.
 *         {@link ARKUI_ERROR_CODE_PARAM_ERROR} The component type of the node is incorrect.
 *         {@link ARKUI_ERROR_CODE_NODE_NOT_ON_MAIN_TREE} The node not mounted to component tree.
 * @since 21
 */
int32_t OH_ArkUI_ListItemSwipeAction_Collapse(ArkUI_NodeHandle node)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Create an edge object for position attribute.
 *
 * @return A pointer to the edge object.
 * @since 21
 */
ArkUI_PositionEdges* OH_ArkUI_PositionEdges_Create() __attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Creates a deep copy of an edge object for position attribute.
 *
 * @param edges A pointer to an edge object.
 * @return A pointer to the new edge object.
 * @since 21
 */
ArkUI_PositionEdges* OH_ArkUI_PositionEdges_Copy(const ArkUI_PositionEdges* edges)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Dispose an edge object for position attribute.
 *
 * @param edges Pointer to the edge object to be disposed.
 * @since 21
 */
void OH_ArkUI_PositionEdges_Dispose(ArkUI_PositionEdges* edges)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Sets the top edge of an edge object for position attribute.
 *
 * @param edges Pointer to the edge object.
 * @param value The distance of top edge to the corresponding edge of parent container, in vp.
 * @since 21
 */
void OH_ArkUI_PositionEdges_SetTop(ArkUI_PositionEdges* edges, float value)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Gets the top edge of an edge object for position attribute.
 *
 * @param edges Pointer to the edge object.
 * @param value The distance of top edge to the corresponding edge of parent container, in vp.
 * @return Returns the result code.
 *      Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *      Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if the parameter is invalid.
 * @since 21
 */
int32_t OH_ArkUI_PositionEdges_GetTop(ArkUI_PositionEdges* edges, float* value)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Sets the left edge of an edge object for position attribute.
 *
 * @param edges Pointer to the edge object.
 * @param value The distance of left edge to the corresponding edge of parent container, in vp.
 * @since 21
 */
void OH_ArkUI_PositionEdges_SetLeft(ArkUI_PositionEdges* edges, float value)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Gets the left edge of an edge object for position attribute.
 *
 * @param edges Pointer to the edge object.
 * @param value The distance of left edge to the corresponding edge of parent container, in vp.
 * @return Returns the result code.
 *      Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *      Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if the parameter is invalid.
 * @since 21
 */
int32_t OH_ArkUI_PositionEdges_GetLeft(ArkUI_PositionEdges* edges, float* value)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Sets the bottom edge of an edge object for position attribute.
 *
 * @param edges Pointer to the edge object.
 * @param value The distance of bottom edge to the corresponding edge of parent container, in vp.
 * @since 21
 */
void OH_ArkUI_PositionEdges_SetBottom(ArkUI_PositionEdges* edges, float value)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Gets the bottom edge of an edge object for position attribute.
 *
 * @param edges Pointer to the edge object.
 * @param value The distance of bottom edge to the corresponding edge of parent container, in vp.
 * @return Returns the result code.
 *      Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *      Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if the parameter is invalid.
 * @since 21
 */
int32_t OH_ArkUI_PositionEdges_GetBottom(ArkUI_PositionEdges* edges, float* value)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Sets the right edge of an edge object for position attribute.
 *
 * @param edges Pointer to the edge object.
 * @param value The distance of right edge to the corresponding edge of parent container, in vp.
 * @since 21
 */
void OH_ArkUI_PositionEdges_SetRight(ArkUI_PositionEdges* edges, float value)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Gets the right edge of an edge object for position attribute.
 *
 * @param edges Pointer to the edge object.
 * @param value The distance of right edge to the corresponding edge of parent container, in vp.
 * @return Returns the result code.
 *      Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *      Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if the parameter is invalid.
 * @since 21
 */
int32_t OH_ArkUI_PositionEdges_GetRight(ArkUI_PositionEdges* edges, float* value)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Create a policy object for PixelRound attribute.
 *
 * @return A pointer to the policy object.
 * @since 21
 */
ArkUI_PixelRoundPolicy* OH_ArkUI_PixelRoundPolicy_Create() __attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Dispose a policy object for PixelRound attribute.
 *
 * @param policy Pointer to the policy object to be disposed.
 * @since 21
 */
void OH_ArkUI_PixelRoundPolicy_Dispose(ArkUI_PixelRoundPolicy* policy)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Sets the top edge of a policy object for PixelRound attribute.
 *
 * @param policy Pointer to the policy object.
 * @param value The CalcPolicy of top edge.
 * @since 21
 */
void OH_ArkUI_PixelRoundPolicy_SetTop(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy value)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Gets the top edge of a policy object for PixelRound attribute.
 *
 * @param policy Pointer to the policy object.
 * @param value The CalcPolicy of top edge.
 * @return Returns the result code.
 *      Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *      Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if the parameter is invalid.
 * @since 21
 */
int32_t OH_ArkUI_PixelRoundPolicy_GetTop(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy* value)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Sets the start edge of a policy object for PixelRound attribute.
 *
 * @param policy Pointer to the policy object.
 * @param value The CalcPolicy of start edge.
 * @since 21
 */
void OH_ArkUI_PixelRoundPolicy_SetStart(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy value)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Gets the start edge of a policy object for PixelRound attribute.
 *
 * @param policy Pointer to the policy object.
 * @param value The CalcPolicy of start edge.
 * @return Returns the result code.
 *      Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *      Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if the parameter is invalid.
 * @since 21
 */
int32_t OH_ArkUI_PixelRoundPolicy_GetStart(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy* value)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Sets the bottom edge of a policy object for PixelRound attribute.
 *
 * @param policy Pointer to the policy object.
 * @param value The CalcPolicy of bottom edge.
 * @since 21
 */
void OH_ArkUI_PixelRoundPolicy_SetBottom(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy value)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Gets the bottom edge of a policy object for PixelRound attribute.
 *
 * @param policy Pointer to the policy object.
 * @param value The CalcPolicy of bottom edge.
 * @return Returns the result code.
 *      Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *      Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if the parameter is invalid.
 * @since 21
 */
int32_t OH_ArkUI_PixelRoundPolicy_GetBottom(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy* value)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Sets the end edge of a policy object for PixelRound attribute.
 *
 * @param policy Pointer to the policy object.
 * @param value The CalcPolicy of end edge.
 * @since 21
 */
void OH_ArkUI_PixelRoundPolicy_SetEnd(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy value)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Gets the end edge of a policy object for PixelRound attribute.
 *
 * @param policy Pointer to the policy object.
 * @param value The CalcPolicy of end edge.
 * @return Returns the result code.
 *      Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *      Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if the parameter is invalid.
 * @since 21
 */
int32_t OH_ArkUI_PixelRoundPolicy_GetEnd(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy* value)
__attribute__((__availability__(ohos, introduced=21.0.0)));

/**
 * @brief Creates a configuration object for textField's counter.
 *
 * @return A pointer to the configuration object.
 * @since 22
 */
ArkUI_ShowCounterConfig* OH_ArkUI_ShowCounterConfig_Create() __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Disposes a configuration object for textField's counter.
 *
 * @param config Pointer to the configuration object to be disposed.
 * @since 22
 */
void OH_ArkUI_ShowCounterConfig_Dispose(ArkUI_ShowCounterConfig* config)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Sets the color of counter when textField hasn't wanted to exceed the maximum character count.
 *
 * @param config Pointer to the configuration object to be modified.
 * @param color The color of the counter when textField hasn't wanted to exceed the maximum character count, in 0xARGB format.
 * @since 22
 */
void OH_ArkUI_ShowCounterConfig_SetCounterTextColor(ArkUI_ShowCounterConfig* config, uint32_t color)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Sets the color of counter when textField wants to exceed the maximum character count.
 *
 * @param config Pointer to the configuration object to be modified.
 * @param color The color of the counter when textField wants to exceed the maximum character count, in 0xARGB format.
 * @since 22
 */
void OH_ArkUI_ShowCounterConfig_SetCounterTextOverflowColor(ArkUI_ShowCounterConfig* config, uint32_t color)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Gets the color of counter when textField hasn't wanted to exceed the maximum character count.
 *
 * @param config Pointer to the configuration object.
 * @return Returns the color of the counter when textField hasn't wanted to exceed the maximum character count, in 0xARGB format.
 * @since 22
 */
uint32_t OH_ArkUI_ShowCounterConfig_GetCounterTextColor(ArkUI_ShowCounterConfig* config)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Gets the color of counter when textField wants to exceed the maximum character count.
 *
 * @param config Pointer to the configuration object.
 * @return Returns the color of the counter when textField wants to exceed the maximum character count, in 0xARGB format.
 * @since 22
 */
uint32_t OH_ArkUI_ShowCounterConfig_GetCounterTextOverflowColor(ArkUI_ShowCounterConfig* config)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Defines the text menu item for edit menu item.
 *
 * @since 22
 */
typedef struct ArkUI_TextMenuItem ArkUI_TextMenuItem;
/**
 * @brief Create an object of the text edit menu item.
 *
 * @return A pointer to the ArkUI_TextMenuItem.
 * @since 22
 */
ArkUI_TextMenuItem* OH_ArkUI_TextMenuItem_Create() __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Dispose an object of the text edit menu options.
 *
 * @param textMenuItem Pointer to the ArkUI_TextMenuItem object to be disposed.
 * @since 22
 */
void OH_ArkUI_TextMenuItem_Dispose(ArkUI_TextMenuItem* textMenuItem)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Set text menu item title.
 *
 * @param item The text menu item.
 * @param content The name of the text menu item, which defaults to an empty string. The string will copy to framework.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextMenuItem_SetContent(ArkUI_TextMenuItem* item, const char* content)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Get text menu item title.
 *
 * @param item The text menu item object.
 * @param buffer The buffer of the text menu content, memory space needs to be allocated by the developer.
 * @param bufferSize The name of the text menu item, which defaults to an empty string;
 * @param writeLength Indicates the string length actually written to the buffer
 *                    when returning {@link ARKUI_ERROR_CODE_NO_ERROR}.
 *                    Indicates the minimum buffer size that can accommodate the target
 *                    when {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} is returned.
 *
 * @return The error code.
 *         {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ARKUI_ERROR_CODE_PARAM_INVALID} if the node, buffer or writeLength is null.
 *         {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} If the buffer size is less than the minimum buffer size.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextMenuItem_GetContent(const ArkUI_TextMenuItem* item, char* buffer, int32_t bufferSize,
    int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Set text menu item icon.
 *
 * @param item The text menu item.
 * @param icon The text menu item icon resource, which defaults to an empty string. The string will copy to framework.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextMenuItem_SetIcon(ArkUI_TextMenuItem* item, const char* icon)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Get text menu item icon.
 *
 * @param item The text menu item object
 * @param buffer The buffer of the text menu content, memory space needs to be allocated by the developer.
 * @param bufferSize The icon of the text menu item, which defaults to an empty string;
 * @param writeLength Indicates the string length actually written to the buffer
 *                    when returning {@link ARKUI_ERROR_CODE_NO_ERROR}.
 *                    Indicates the minimum buffer size that can accommodate the target
 *                    when {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} is returned.
 *
 * @return The error code.
 *         {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ARKUI_ERROR_CODE_PARAM_INVALID} if the node, buffer or writeLength is null.
 *         {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} If the buffer size is less than the minimum buffer size.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextMenuItem_GetIcon(const ArkUI_TextMenuItem* item, char* buffer, int32_t bufferSize,
    int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Set text menu item label info for keyboard shortcut.
 *
 * @param item The text menu item.
 * @param labelInfo The text menu item shortcut displays, which defaults to an empty string.
 *      The string will copy to framework.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextMenuItem_SetLabelInfo(ArkUI_TextMenuItem* item, const char* labelInfo)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Get text menu item label info for keyboard shortcut..
 *
 * @param item The text menu item object
 * @param buffer The buffer of the text menu content, memory space needs to be allocated by the developer.
 * @param bufferSize The shortcuts of the text menu item, which defaults to an empty string;
 * @param writeLength Indicates the string length actually written to the buffer
 *                    when returning {@link ARKUI_ERROR_CODE_NO_ERROR}.
 *                    Indicates the minimum buffer size that can accommodate the target
 *                    when {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} is returned.
 *
 * @return The error code.
 *         {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ARKUI_ERROR_CODE_PARAM_INVALID} if the node, buffer or writeLength is null.
 *         {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} If the buffer size is less than the minimum buffer size.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextMenuItem_GetLabelInfo(const ArkUI_TextMenuItem* item, char* buffer, int32_t bufferSize,
    int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Set text menu item id.
 *
 * @param item The text menu item.
 * @param id The text menu id.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextMenuItem_SetId(ArkUI_TextMenuItem* item, int32_t id)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Get text menu item id.
 *
 * @param item The text menu item object
 * @param id The text menu item id;
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
*/
ArkUI_ErrorCode OH_ArkUI_TextMenuItem_GetId(const ArkUI_TextMenuItem* item, int32_t* id)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Defines text menu item array.
 *
 * @since 22
 */
typedef struct ArkUI_TextMenuItemArray ArkUI_TextMenuItemArray;

/**
 * @brief Get the size of text menu items.
 *
 * @param items The text menu items.
 * @param size The size of text menu items.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
*/
ArkUI_ErrorCode OH_ArkUI_TextMenuItemArray_GetSize(ArkUI_TextMenuItemArray* items, int32_t* size)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Get text menu item at index.
 *
 * @param items The text menu items.
 * @param index The index of text menu items.
 * @param item The text menu item at index of array.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextMenuItemArray_GetItem(ArkUI_TextMenuItemArray* items, int32_t index,
    ArkUI_TextMenuItem** item)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Insert text menu item at index.
 *
 * @param items The text menu items.
 * @param item The text menu item at index of array. The item will copy by framework.
 * @param index The index of text menu items.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextMenuItemArray_Insert(ArkUI_TextMenuItemArray* items, ArkUI_TextMenuItem* item,
    int32_t index)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Erase text menu item at index.
 *
 * @param items The text menu items.
 * @param index The index of text menu items.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextMenuItemArray_Erase(ArkUI_TextMenuItemArray* items, int32_t index)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Clear all the items.
 *
 * @param items The text menu items.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextMenuItemArray_Clear(ArkUI_TextMenuItemArray* items)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Enumerates the text menu item id.
 *
 * @since 22
 */
typedef enum {
    /**
     * Indicates the TextMenuItemId to copy and delete the currently selected text.
     */
    ARKUI_TEXT_MENU_ITEM_ID_CUT = 0,

    /**
     * Indicates the TextMenuItemId to copy the currently selected text to the clipboard.
     */
    ARKUI_TEXT_MENU_ITEM_ID_COPY = 1,

    /**
     * Indicates the TextMenuItemId to copy the current contents of the clipboard into the text view.
     */
    ARKUI_TEXT_MENU_ITEM_ID_PASTE = 2,

    /**
     * Indicates the TextMenuItemId to select all text in a text view.
     */
    ARKUI_TEXT_MENU_ITEM_ID_SELECT_ALL = 3,

    /**
     * Indicates the TextMenuItemId for collaboration service menu items.
     */
    ARKUI_TEXT_MENU_ITEM_ID_COLLABORATION_SERVICE = 4,

    /**
     * Indicates the TextMenuItemId to recognize the text in the picture and input it into the text view.
     */
    ARKUI_TEXT_MENU_ITEM_ID_CAMERA_INPUT = 5,

    /**
     * Indicates the TextMenuItemId to help with text creation by invoking large models.
     */
    ARKUI_TEXT_MENU_ITEM_ID_AI_WRITER = 6,

    /**
     * Indicates the TextMenuItemId to translate the selected content.
     */
    ARKUI_TEXT_MENU_ITEM_ID_TRANSLATE = 7,

    /**
     * Indicates the TextMenuItemId to search the selected content.
     */
    ARKUI_TEXT_MENU_ITEM_ID_SEARCH = 8,

    /**
     * Indicates the TextMenuItemId to share the selected content.
     */
    ARKUI_TEXT_MENU_ITEM_ID_SHARE = 9,

    /**
     * Indicates the TextMenuItemId to open url.
     */
    ARKUI_TEXT_MENU_ITEM_ID_URL = 10,

    /**
     * Indicates the TextMenuItemId to open email.
     */
    ARKUI_TEXT_MENU_ITEM_ID_EMAIL = 11,

    /**
     * Indicates the TextMenuItemId to call the phone number.
     */
    ARKUI_TEXT_MENU_ITEM_ID_PHONE_NUMBER = 12,

    /**
     * Indicates the TextMenuItemId to open map.
     */
    ARKUI_TEXT_MENU_ITEM_ID_ADDRESS = 13,

    /**
     * Indicates the TextMenuItemId to open calendar.
     */
    ARKUI_TEXT_MENU_ITEM_ID_DATA_TIME = 14,

    /**
     * Indicates the TextMenuItemId for asking AI.
     */
    ARKUI_TEXT_MENU_ITEM_ID_ASK_AI = 15,

    /**
     * Indicates the TextMenuItemId for auto fill.
     *
     * @since 24
     */
    ARKUI_TEXT_MENU_ITEM_ID_AUTO_FILL = 16,

    /**
     * Indicates the TextMenuItemId for password vault.
     *
     * @since 24
     */
    ARKUI_TEXT_MENU_ITEM_ID_PASSWORD_VAULT = 17,

    /**
     * Inclusive begin of app-reserved ID range.
     */
    ARKUI_TEXT_MENU_ITEM_ID_APP_RESERVED_BEGIN = 10000,

    /**
     * Inclusive end of app-reserved ID range.
     */
    ARKUI_TEXT_MENU_ITEM_ID_APP_RESERVED_END = 20000,
} ArkUI_TextMenuItemId;

/**
 * @brief Defines the text menu item for edit menu options.
 *
 * @since 22
 */
typedef struct ArkUI_TextEditMenuOptions ArkUI_TextEditMenuOptions;
/**
 * @brief Create an object of the text edit menu options.
 *
 * @return A pointer to the ArkUI_TextEditMenuOptions.
 * @since 22
 */
ArkUI_TextEditMenuOptions* OH_ArkUI_TextEditMenuOptions_Create()
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Dispose an object of the text edit menu options.
 *
 * @param editMenuOptions Pointer to the ArkUI_TextEditMenuOptions object to be disposed.
 * @since 22
 */
void OH_ArkUI_TextEditMenuOptions_Dispose(ArkUI_TextEditMenuOptions* editMenuOptions)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * The text menu create callback function.
 *
 * @param items The framework creates and owns the array.
 *     In callback: the developer can modify the array by calling {@link OH_ArkUI_TextMenuItemArray_Insert},
 *     {@link OH_ArkUI_TextMenuItemArray_Erase}, or similar APIs.
 *     The developer must not free the array instance.
 * @param userData User defined data.
 * @since 22
 */
typedef void (*ArkUI_TextCreateMenuCallback)(
    ArkUI_TextMenuItemArray*    items,
    void*                       userData
);

/**
 * The text menu prepare callback function.
 *
 * @param items The framework creates and owns the array.
 *     In callback: the developer can modify the array by calling {@link OH_ArkUI_TextMenuItemArray_Insert},
 *     {@link OH_ArkUI_TextMenuItemArray_Erase}, or similar APIs.
 *     The developer must not free the array instance.
 * @param userData User defined data.
 * @since 22
 */
typedef void (*ArkUI_TextPrepareMenuCallback)(
    ArkUI_TextMenuItemArray*    items,
    void*                       userData
);

/**
 * The text menu item click callback function.
 *
 * @param item The menu item click.
 * @param start The start offset of the selected content.
 * @param end The end offset of the selected content.
 * @param userData The user data.
 * @return bool Return True, the event is consumed, false otherwise.
 * @since 22
 */
typedef bool (*ArkUI_TextMenuItemClickCallback)(
    const ArkUI_TextMenuItem*    item,
    int32_t                      start,
    int32_t                      end,
    void*                        userData
);

/**
 * @brief Set the event to be called when text menu create.
 *
 * @param editMenuOptions Pointer to the ArkUI_TextEditMenuOptions object.
 * @param userData The user data.
 * @param cb The create callback function.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextEditMenuOptions_RegisterOnCreateMenuCallback(
    ArkUI_TextEditMenuOptions* editMenuOptions, void* userData, ArkUI_TextCreateMenuCallback cb)
    __attribute__((__availability__(ohos, introduced=22.0.0)));
/**
 * @brief Set the event to be called when menu prepare.
 *
 * @param editMenuOptions Pointer to the ArkUI_TextEditMenuOptions object.
 * @param userData The user data.
 * @param cb The prepare callback function.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextEditMenuOptions_RegisterOnPrepareMenuCallback(
    ArkUI_TextEditMenuOptions* editMenuOptions, void* userData, ArkUI_TextPrepareMenuCallback cb)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Set the event to be called when menu item click.
 *
 * @param editMenuOptions Pointer to the ArkUI_TextEditMenuOptions object.
 * @param userData The user data.
 * @param cb The menu item click callback function.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextEditMenuOptions_RegisterOnMenuItemClickCallback(
    ArkUI_TextEditMenuOptions* editMenuOptions, void* userData, ArkUI_TextMenuItemClickCallback cb)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Defines the selection menu.
 *
 * @since 22
 */
typedef struct ArkUI_TextSelectionMenuOptions ArkUI_TextSelectionMenuOptions;

/**
 * @brief Defines the decoration style.
 *
 * @since 24
 */
typedef struct OH_ArkUI_DecorationStyleOptions OH_ArkUI_DecorationStyleOptions;

/**
 * @brief Defines the config of data detector.
 *
 * @since 24
 */
typedef struct OH_ArkUI_TextDataDetectorConfig OH_ArkUI_TextDataDetectorConfig;

/**
 * @brief Defines the selection menu option of text editor.
 *
 * @since 24
 */
typedef struct OH_ArkUI_TextEditorSelectionMenuOptions OH_ArkUI_TextEditorSelectionMenuOptions;

/**
 * @brief Defines prompt options when text editor has no input.
 *
 * @since 24
 */
typedef struct OH_ArkUI_TextEditorPlaceholderOptions OH_ArkUI_TextEditorPlaceholderOptions;

/**
 * @brief Defines styled string controller for text editor.
 *
 * @since 24
 */
typedef struct OH_ArkUI_TextEditorStyledStringController OH_ArkUI_TextEditorStyledStringController;

/**
 * @brief Defines paragraph style for text editor.
 *
 * @since 24
 */
typedef struct OH_ArkUI_TextEditorParagraphStyle OH_ArkUI_TextEditorParagraphStyle;

/**
 * @brief Defines shadow options.
 *
 * @since 24
 */
typedef struct OH_ArkUI_ShadowOptions OH_ArkUI_ShadowOptions;

/**
 * @brief Defines text style for text editor.
 *
 * @since 24
 */
typedef struct OH_ArkUI_TextEditorTextStyle OH_ArkUI_TextEditorTextStyle;

/**
 * @brief Enumerates the haptic feedback mode.
 *
 * @since 24
 */
typedef enum {
    /**
     * No haptic feedback.
     *
     * @since 24
     */
    OH_ARKUI_HAPTIC_FEEDBACK_MODE_DISABLED = 0,
    /**
     * Defines always haptic feedback.
     *
     * @since 24
     */
    OH_ARKUI_HAPTIC_FEEDBACK_MODE_ENABLED  = 1,
    /**
     * Defines automatically haptic feedback.
     *
     * @since 24
     */
    OH_ARKUI_HAPTIC_FEEDBACK_MODE_AUTO = 2,
} OH_ArkUI_HapticFeedbackMode;

/**
 * @brief Enumerates the text editor span type.
 *
 * @since 24
 */
typedef enum {
    /**
     * The span type of text.
     *
     * @since 24
     */
    OH_ARKUI_TEXT_EDITOR_SPAN_TYPE_TEXT = 0,
    /**
     * The span type of image.
     *
     * @since 24
     */
    OH_ARKUI_TEXT_EDITOR_SPAN_TYPE_IMAGE = 1,
    /**
     * The span type of mixed.
     *
     * @since 24
     */
    OH_ARKUI_TEXT_EDITOR_SPAN_TYPE_MIXED = 2,
    /**
     * The span type of builder.
     *
     * @since 24
     */
    OH_ARKUI_TEXT_EDITOR_SPAN_TYPE_BUILDER = 3,
    /**
     * The span type of default.
     *
     * @since 24
     */
    OH_ARKUI_TEXT_EDITOR_SPAN_TYPE_DEFAULT = 4
} OH_ArkUI_TextEditorSpanType;

/**
 * @brief Enumerates the text editor response type.
 *
 * @since 24
 */
typedef enum {
    /**
     * The text editor response type of right click.
     *
     * @since 24
     */
    OH_ARKUI_TEXT_EDITOR_RESPONSE_TYPE_RIGHT_CLICK = 0,
    /**
     * The text editor response type of long press.
     *
     * @since 24
     */
    OH_ARKUI_TEXT_EDITOR_RESPONSE_TYPE_LONG_PRESS = 1,
    /**
     * The text editor response type of select.
     *
     * @since 24
     */
    OH_ARKUI_TEXT_EDITOR_RESPONSE_TYPE_SELECT = 2,
    /**
     * The text editor response type of default.
     *
     * @since 24
     */
    OH_ARKUI_TEXT_EDITOR_RESPONSE_TYPE_DEFAULT = 3,
} OH_ArkUI_TextEditorResponseType;

/**
 * @brief Enumerates the text menu type.
 *
 * @since 24
 */
typedef enum {
    /**
     * The text menu type of selection menu.
     *
     * @since 24
     */
    OH_ARKUI_TEXT_EDITOR_SELECTION_MENU = 0,
    /**
     * The text menu type of preview menu.
     *
     * @since 24
     */
    OH_ARKUI_TEXT_EDITOR_PREVIEW_MENU = 1,
} OH_ArkUI_TextMenuType;

/**
 * @brief Define line break types.
 *
 * @since 24
 */
typedef enum {
    /**
     * Places as many words on a line as possible
     * and moves to the next line only if no more words can fit into the same line.
     *
     * @since 24
     */
    OH_ARKUI_LINE_BREAK_STRATEGY_GREEDY = 0,
    /**
     * Fills in lines as much as possible on the basis of BALANCED,
     * which may results in a large blank area on the last line.
     *
     * @since 24
     */
    OH_ARKUI_LINE_BREAK_STRATEGY_HIGH_QUALITY = 1,
    /**
     * Without splitting words, the width of each line in a paragraph is the same as much as possible.
     *
     * @since 24
     */
    OH_ARKUI_LINE_BREAK_STRATEGY_BALANCE = 2,
} OH_ArkUI_LineBreakStrategy;

/**
 * @brief Enumerates the text span type.
 *
 * @since 22
 */
typedef enum {
    /** The span type only contains text. */
    ARKUI_TEXT_SPAN_TYPE_TEXT = 0,
    /** The span type only contains image. */
    ARKUI_TEXT_SPAN_TYPE_IMAGE = 1,
    /** The span type contains both text and image. */
    ARKUI_TEXT_SPAN_TYPE_MIXED = 2,
    /**
     * When no other types are explicitly specified, this type will be matched.
     * When this type is registered but TEXT, IMAGE, or MIXED types are not registered,
     * this type will be triggered and displayed for those registered types.
     */
    ARKUI_TEXT_SPAN_TYPE_DEFAULT = 3,
} ArkUI_TextSpanType;

/**
 * @brief Enumerates the text response type.
 *
 * @since 22
 */
typedef enum {
    /** The response type of right click. */
    ARKUI_TEXT_RESPONSE_TYPE_RIGHT_CLICK = 0,
    /** The response type of long press. */
    ARKUI_TEXT_RESPONSE_TYPE_LONG_PRESS = 1,
    /** The response type of select by mouse. */
    ARKUI_TEXT_RESPONSE_TYPE_SELECT = 2,
    /**
     * When no other types are explicitly specified, this type will be matched.
     * When this type is registered but RIGHT_CLICK, LONG_PRESS, or SELECT types are not registered,
     * this type will be triggered and displayed for right-click, long press, and mouse selection actions.
     */
    ARKUI_TEXT_RESPONSE_TYPE_DEFAULT = 3,
} ArkUI_TextResponseType;

/**
 * @brief Create an object of the text selection menu options.
 *
 * @return A pointer to the ArkUI_TextSelectionMenuOptions.
 * @since 22
 */
ArkUI_TextSelectionMenuOptions* OH_ArkUI_TextSelectionMenuOptions_Create()
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Dispose an object of the text selection menu options.
 *
 * @param selectionMenuOptions Pointer to the ArkUI_TextSelectionMenuOptions object to be disposed.
 * @since 22
 */
void OH_ArkUI_TextSelectionMenuOptions_Dispose(ArkUI_TextSelectionMenuOptions* selectionMenuOptions)
__attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Sets the recognition types of a configuration object for selected text recognition.
 *
 * @param selectionMenuOptions Pointer to the ArkUI_TextSelectionMenuOptions object.
 * @param textSpanType The span type of {@link ArkUI_TextSpanType}.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_SetSpanType(ArkUI_TextSelectionMenuOptions* selectionMenuOptions,
    ArkUI_TextSpanType textSpanType)
    __attribute__((__availability__(ohos, introduced=22.0.0)));
/**
 * @brief Gets the span type select menu options.
 *
 * @param selectionMenuOptions Pointer to the ArkUI_TextSelectionMenuOptions object.
 * @param spanType the text span type {@link ArkUI_TextSpanType}.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_GetSpanType(ArkUI_TextSelectionMenuOptions* selectionMenuOptions,
    ArkUI_TextSpanType* spanType)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Set custom text menu node of text.
 *
 * @param selectionMenuOptions Pointer to the ArkUI_TextSelectionMenuOptions object.
 * @param node The custom menu node.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_SetContentNode(ArkUI_TextSelectionMenuOptions* selectionMenuOptions,
    ArkUI_NodeHandle node)
    __attribute__((__availability__(ohos, introduced=22.0.0)));
/**
 * @brief Get custom text menu node of text.
 *
 * @param selectionMenuOptions Pointer to the ArkUI_TextSelectionMenuOptions object.
 * @param node The custom menu node.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_GetContentNode(ArkUI_TextSelectionMenuOptions* selectionMenuOptions,
    ArkUI_NodeHandle* node)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Sets the recognition types of a configuration object for selected text recognition.
 *
 * @param selectionMenuOptions Pointer to the ArkUI_TextSelectionMenuOptions object.
 * @param responseType The response type of {@link ArkUI_TextResponseType}.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_SetResponseType(ArkUI_TextSelectionMenuOptions* selectionMenuOptions,
    ArkUI_TextResponseType responseType)
    __attribute__((__availability__(ohos, introduced=22.0.0)));
/**
 * @brief Gets the response type select menu options.
 *
 * @param selectionMenuOptions Pointer to the ArkUI_TextSelectionMenuOptions object.
 * @param responseType The text response type {@link ArkUI_TextResponseType}.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_GetResponseType(ArkUI_TextSelectionMenuOptions* selectionMenuOptions,
    ArkUI_TextResponseType* responseType)
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Set the event to be called when selection menu show.
 *
 * @param selectionMenuOptions Pointer to the ArkUI_TextSelectionMenuOptions object.
 * @param userData The user data.
 * @param callback The callback function of menu show.
 *     start The start offset of the selected content.
 *     end The end offset of the selected content.
 *     userData The user data.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_RegisterOnMenuShowCallback(
    ArkUI_TextSelectionMenuOptions* selectionMenuOptions, void* userData,
    void (*callback)(int32_t start, int32_t end, void* userData))
    __attribute__((__availability__(ohos, introduced=22.0.0)));
/**
 * @brief Set the event to be called when selection menu hide.
 *
 * @param selectionMenuOptions Pointer to the ArkUI_TextSelectionMenuOptions object.
 * @param userData The user data.
 * @param callback The callback function of menu hide.
 *     start The start offset of the selected content.
 *     end The end offset of the selected content.
 *     userData The user data.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 22
 */
ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_RegisterOnMenuHideCallback(
    ArkUI_TextSelectionMenuOptions* selectionMenuOptions, void* userData,
    void (*callback)(int32_t start, int32_t end, void* userData))
    __attribute__((__availability__(ohos, introduced=22.0.0)));

/**
 * @brief Create selection options.
 *
 * @return A pointer to the selection options object.
 * @since 23
 */
ArkUI_SelectionOptions* OH_ArkUI_SelectionOptions_Create() __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Dispose selection options object.
 *
 * @param {ArkUI_SelectionOptions*} options Pointer to the selection options object. to be disposed.
 * @since 23
 */
void OH_ArkUI_SelectionOptions_Dispose(ArkUI_SelectionOptions* options)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Sets the menu policy for selection options.
 *
 * @param {ArkUI_SelectionOptions*} options Pointer to the selection options.
 * @param {ArkUI_MenuPolicy} menuPolicy The menu policy.
 * @since 23
 */
void OH_ArkUI_SelectionOptions_SetMenuPolicy(
    ArkUI_SelectionOptions* options, ArkUI_MenuPolicy menuPolicy)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Gets the menu policy of selection options.
 *
 * @param {ArkUI_SelectionOptions*} options Pointer to the selection options object.
 * @return Returns the menu policy.
 * @since 23
 */
ArkUI_MenuPolicy OH_ArkUI_SelectionOptions_GetMenuPolicy(ArkUI_SelectionOptions* options)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Create an object of the text content base controller.
 *
 * @return A pointer to the controller object.
 * @since 23
 */
ArkUI_TextContentBaseController* OH_ArkUI_TextContentBaseController_Create()
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Dispose an object of the text content base controller.
 *
 * @param {ArkUI_TextContentBaseController*} controller Pointer to the controller object to be disposed.
 * @since 23
 */
void OH_ArkUI_TextContentBaseController_Dispose(ArkUI_TextContentBaseController* controller)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Delete the character before the caret of the input field component in editing state.
 *        Otherwise, delete the last character of the input field component.
 *
 * @param {ArkUI_TextContentBaseController*} controller Pointer to the configuration object to be modified.
 * @since 23
 */
void OH_ArkUI_TextContentBaseController_DeleteBackward(ArkUI_TextContentBaseController* controller)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Scroll the input field component to make the specified content visible.
 *
 * @param {ArkUI_TextContentBaseController*} controller Pointer to the
 * configuration object to be modified.
 * @param {int32_t} start The start offset of the content to be made visible.
 * @param {int32_t} end The end offset of the content to be made visible
 * @since 23
 */
void OH_ArkUI_TextContentBaseController_ScrollToVisible(
    ArkUI_TextContentBaseController *controller, int32_t start, int32_t end)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Defines the motion path options for path animation.
 *
 * @since 23
 */
typedef struct ArkUI_MotionPathOptions ArkUI_MotionPathOptions;

/**
 * @brief Create an object of the motion path options for path animation.
 *        In the newly created ArkUI_MotionPathOptions, the "path" value is an empty string, the "from" value is 0,
 *        the "to" value is 1, and the "rotatable" value is false.
 *
 * @return A pointer to the ArkUI_MotionPathOptions.
 * @since 23
 */
ArkUI_MotionPathOptions* OH_ArkUI_MotionPathOptions_Create() __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Dispose the ArkUI_MotionPathOptions object.
 *
 * @param options Pointer to the ArkUI_MotionPathOptions object to be disposed.
 * @since 23
 */
void OH_ArkUI_MotionPathOptions_Dispose(ArkUI_MotionPathOptions* options)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Sets the the motion path for the animation using an SVG path string. The path supports using "start" and
 *        "end" as placeholders for the starting and ending points, for example:
 *        "Mstart.x start.y L50 50 Lend.x end.y Z". Refer to the SVG path format for the path string.
 *        When set to an empty string, it is equivalent to not setting a path animation.
 *
 * @param options Pointer to the ArkUI_MotionPathOptions object.
 * @param svgPath The motion path for the path animation.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 23
 */
ArkUI_ErrorCode OH_ArkUI_MotionPathOptions_SetPath(ArkUI_MotionPathOptions* options, const char* svgPath)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Gets the motion path string in the ArkUI_MotionPathOptions object.
 *
 * @param options Pointer to the ArkUI_MotionPathOptions object.
 * @param svgPathBuffer Buffer pointer to the motion path string.
 * @param bufferSize The buffer size of the svgPathBuffer parameter.
 * @param writeLength Indicates the string length actually written to the buffer
 *                    when returning {@link ARKUI_ERROR_CODE_NO_ERROR}.
 *                    Indicates the minimum buffer size that can accommodate the target
 *                    when {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} is returned.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 *         Returns {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} if the buffer size is less than the minimum buffer size.
 * @since 23
 */
ArkUI_ErrorCode OH_ArkUI_MotionPathOptions_GetPath(const ArkUI_MotionPathOptions* options, char* svgPathBuffer,
    const int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Sets the starting progress in the ArkUI_MotionPathOptions. Progress refers to the ratio of the length of the
 *        path that has been traveled to the total length of the entire path. The value range is [0.0, 1.0], and the
 *        "from" value should be less than or equal to the "to" value; otherwise, an ARKUI_ERROR_CODE_PARAM_OUT_OF_RANGE
 *        error code will be returned.
 *
 * @param options Pointer to the ArkUI_MotionPathOptions object.
 * @param from The starting progress in the ArkUI_MotionPathOptions.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_OUT_OF_RANGE} if the "from" value is out of range or the "from" value
 *                 is greater than the "to" value.
 * @since 23
 */
ArkUI_ErrorCode OH_ArkUI_MotionPathOptions_SetFrom(ArkUI_MotionPathOptions* options, const float from)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Gets the starting progress in the ArkUI_MotionPathOptions object.
 *
 * @param options Pointer to the ArkUI_MotionPathOptions object.
 * @param from The starting progress in the ArkUI_MotionPathOptions.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 23
 */
ArkUI_ErrorCode OH_ArkUI_MotionPathOptions_GetFrom(const ArkUI_MotionPathOptions* options, float* from)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Sets the endpoint progress in the ArkUI_MotionPathOptions. Progress refers to the ratio of the length of the
 *        path that has been traveled to the total length of the entire path. The value range is [0.0, 1.0], and the
 *        "from" value should be less than or equal to the "to" value; otherwise, an ARKUI_ERROR_CODE_PARAM_OUT_OF_RANGE
 *        error code will be returned.
 *
 * @param options Pointer to the ArkUI_MotionPathOptions object.
 * @param to The endpoint progress in the ArkUI_MotionPathOptions.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_OUT_OF_RANGE} if the "to" value is out of range or the "to" value
 *                 is less than the "from" value.
 * @since 23
 */
ArkUI_ErrorCode OH_ArkUI_MotionPathOptions_SetTo(ArkUI_MotionPathOptions* options, const float to)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Gets the endpoint progress in the ArkUI_MotionPathOptions object.
 *
 * @param options Pointer to the ArkUI_MotionPathOptions object.
 * @param to The endpoint progress in the ArkUI_MotionPathOptions.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 23
 */
ArkUI_ErrorCode OH_ArkUI_MotionPathOptions_GetTo(const ArkUI_MotionPathOptions* options, float* to)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Sets the rotatable parameter in the ArkUI_MotionPathOptions. It indicates whether to rotate along the path.
 *        True means rotating along the path, while false means not rotating along the path.
 *
 * @param options Pointer to the ArkUI_MotionPathOptions object.
 * @param rotatable The rotatable parameter in the ArkUI_MotionPathOptions.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 23
 */
ArkUI_ErrorCode OH_ArkUI_MotionPathOptions_SetRotatable(ArkUI_MotionPathOptions* options, const bool rotatable)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Gets the rotatable parameter in the ArkUI_MotionPathOptions.
 *
 * @param options Pointer to the ArkUI_MotionPathOptions object.
 * @param rotatable The rotatable parameter in the ArkUI_MotionPathOptions.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 23
 */
ArkUI_ErrorCode OH_ArkUI_MotionPathOptions_GetRotatable(const ArkUI_MotionPathOptions* options, bool* rotatable)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Enumerates the MarqueeStartPolicy.
 *
 * @since 23
 */
typedef enum {
    /** Start marquee in any case. This is the default policy. */
    ARKUI_MARQUEESTARTPOLICY_DEFAULT = 0,
    /** Start marquee only when get focus. */
    ARKUI_MARQUEESTARTPOLICY_ONFOCUS = 1
} ArkUI_MarqueeStartPolicy;

/**
 * @brief Enumerates the MarqueeUpdatePolicy.
 *
 * @since 23
 */
typedef enum {
    /** Reset scroll position and restart scroll. */
    ARKUI_MARQUEEUPDATEPOLICY_DEFAULT = 0,
    /** Preserve scroll position, just change to new text. */
    ARKUI_MARQUEEUPDATEPOLICY_PRESERVEPOSITION = 1
} ArkUI_MarqueeUpdatePolicy;

/**
 * @brief Defines the marquee options of text.
 *
 * @since 23
 */
typedef struct ArkUI_TextMarqueeOptions ArkUI_TextMarqueeOptions;

/**
 * @brief Create an option object for marquee animation of text.
 *
 * @return A pointer to the option object.
 * @since 23
 */
ArkUI_TextMarqueeOptions* OH_ArkUI_TextMarqueeOptions_Create()
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Dispose the option object for marquee animation of text.
 *
 * @param option Pointer to the option object to be disposed.
 * @since 23
 */
void OH_ArkUI_TextMarqueeOptions_Dispose(ArkUI_TextMarqueeOptions* option)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Sets the start flag of the option object for marquee animation of text.
 *
 * @param option Pointer to the option object to be modified.
 * @param start Flag of is need to start marquee. True means start marquee, false means stop marquee.
 * @since 23
 */
void OH_ArkUI_TextMarqueeOptions_SetStart(ArkUI_TextMarqueeOptions* option, bool start)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Gets the start flag of the option object for marquee animation of text.
 *
 * @param option Pointer to the option object.
 * @return Returns the start flag.
 * @since 23
 */
bool OH_ArkUI_TextMarqueeOptions_GetStart(ArkUI_TextMarqueeOptions* option)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Sets the step size of the option object for marquee animation of text.
 *
 * @param option Pointer to the option object to be modified.
 * @param step The step size of the marquee. The unit is vp.
 * @since 23
 */
void OH_ArkUI_TextMarqueeOptions_SetStep(ArkUI_TextMarqueeOptions* option, float step)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Gets the step size of the option object for marquee animation of text.
 *
 * @param option Pointer to the option object.
 * @return Returns the step size of the marquee. The unit is vp.
 * @since 23
 */
float OH_ArkUI_TextMarqueeOptions_GetStep(ArkUI_TextMarqueeOptions* option)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Sets the spacing between two rounds of the option object for marquee animation of text.
 *
 * @param option Pointer to the option object to be modified.
 * @param spacing The spacing between two rounds of marquee. The unit is vp.
 * @since 23
 */
void OH_ArkUI_TextMarqueeOptions_SetSpacing(ArkUI_TextMarqueeOptions* option, float spacing)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Gets the spacing between two rounds of the option object for marquee animation of text.
 *
 * @param option Pointer to the option object.
 * @return Returns the spacing between two rounds of marquee. The unit is vp.
 * @since 23
 */
float OH_ArkUI_TextMarqueeOptions_GetSpacing(ArkUI_TextMarqueeOptions* option)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Sets the rounds of the option object for marquee animation of text.
 *
 * @param option Pointer to the option object to be modified.
 * @param loop The rounds of the marquee.
 * @since 23
 */
void OH_ArkUI_TextMarqueeOptions_SetLoop(ArkUI_TextMarqueeOptions* option, int32_t loop)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Gets the rounds of the option object for marquee animation of text.
 *
 * @param option Pointer to the option object.
 * @return Returns the rounds of the marquee.
 * @since 23
 */
int32_t OH_ArkUI_TextMarqueeOptions_GetLoop(ArkUI_TextMarqueeOptions* option)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Sets the fromStart flag of the option object for marquee animation of text.
 *
 * @param option Pointer to the option object to be modified.
 * @param fromStart The running direction of the marquee, true means running from start.
 * @since 23
 */
void OH_ArkUI_TextMarqueeOptions_SetFromStart(ArkUI_TextMarqueeOptions* option, bool fromStart)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Gets the fromStart flag of the option object for marquee animation of text.
 *
 * @param option Pointer to the option object.
 * @return Returns the fromStart flag.
 * @since 23
 */
bool OH_ArkUI_TextMarqueeOptions_GetFromStart(ArkUI_TextMarqueeOptions* option)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Sets the delay time between each round of the option object for marquee animation of text.
 *
 * @param option Pointer to the option object to be modified.
 * @param delay The delay time between each round of the marquee.
 * @since 23
 */
void OH_ArkUI_TextMarqueeOptions_SetDelay(ArkUI_TextMarqueeOptions* option, int32_t delay)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Gets the delay time between each round of the option object for marquee animation of text.
 *
 * @param option Pointer to the option object.
 * @return Returns the delay time between each round of the marquee.
 * @since 23
 */
int32_t OH_ArkUI_TextMarqueeOptions_GetDelay(ArkUI_TextMarqueeOptions* option)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Sets the fadeout flag of the option object for marquee animation of text.
 *
 * @param option Pointer to the option object to be modified.
 * @param fadeout The flag of whether the text is faded out.
 * @since 23
 */
void OH_ArkUI_TextMarqueeOptions_SetFadeout(ArkUI_TextMarqueeOptions* option, bool fadeout)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Gets the fadeout flag of the option object for marquee animation of text.
 *
 * @param option Pointer to the option object.
 * @return Returns the fadeout flag.
 * @since 23
 */
bool OH_ArkUI_TextMarqueeOptions_GetFadeout(ArkUI_TextMarqueeOptions* option)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Sets the start policy of the option object for marquee animation of text.
 *
 * @param option Pointer to the option object to be modified.
 * @param startPolicy The start policy for marquee.
 * @since 23
 */
void OH_ArkUI_TextMarqueeOptions_SetStartPolicy(ArkUI_TextMarqueeOptions* option, ArkUI_MarqueeStartPolicy startPolicy)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Gets the start policy of the option object for marquee animation of text.
 *
 * @param option Pointer to the option object.
 * @return Returns the start policy for marquee.
 * @since 23
 */
ArkUI_MarqueeStartPolicy OH_ArkUI_TextMarqueeOptions_GetStartPolicy(ArkUI_TextMarqueeOptions* option)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Sets the update policy of the option object for marquee animation of text.
 *
 * @param option Pointer to the option object to be modified.
 * @param updatePolicy The update policy for marquee.
 * @since 23
 */
void OH_ArkUI_TextMarqueeOptions_SetUpdatePolicy(ArkUI_TextMarqueeOptions* option,
    ArkUI_MarqueeUpdatePolicy updatePolicy)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Gets the update policy of the option object for marquee animation of text.
 *
 * @param option Pointer to the option object.
 * @return Returns the update policy for marquee.
 * @since 23
 */
ArkUI_MarqueeUpdatePolicy OH_ArkUI_TextMarqueeOptions_GetUpdatePolicy(ArkUI_TextMarqueeOptions* option)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Create a configuration object for selected drag preview style.
 * @return A pointer to the configuration object.
 * @since 23
 */
ArkUI_SelectedDragPreviewStyle* OH_ArkUI_SelectedDragPreviewStyle_Create()
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Dispose a configuration object for selected drag preview style.
 * @param config Pointer to the configuration object to be disposed.
 * @since 23
 */
void OH_ArkUI_SelectedDragPreviewStyle_Dispose(ArkUI_SelectedDragPreviewStyle* config)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Sets the color of background for selected drag preview style.
 * @param config Pointer to the configuration object to be modified.
 * @param color Background color.
 * @since 23
 */
void OH_ArkUI_SelectedDragPreviewStyle_SetColor(
    ArkUI_SelectedDragPreviewStyle* config, uint32_t color)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Gets the color of background for selected drag preview style.
 * @param config Pointer to the configuration object.
 * @return Returns the background color.
 * @since 23
 */
uint32_t OH_ArkUI_SelectedDragPreviewStyle_GetColor(
    ArkUI_SelectedDragPreviewStyle* config)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Creates an decoration line style object.
 * When the object is no longer in use, invoke {@link OH_ArkUI_DecorationStyleOptions_Destroy} to destroy it.
 *
 * @return A pointer to the option object.
 * @since 24
 */
OH_ArkUI_DecorationStyleOptions* OH_ArkUI_DecorationStyleOptions_Create()
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroys the decoration line style object.
 *
 * @param options Pointer to the option object to be destroyed.
 * @since 24
 */
void OH_ArkUI_DecorationStyleOptions_Destroy(OH_ArkUI_DecorationStyleOptions* options)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the decoration type of decoration line style.
 *
 * @param options Pointer to the {@link OH_ArkUI_DecorationStyleOptions} object.
 * @param type The decoration type {@link ArkUI_TextDecorationType}.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_SetTextDecorationType(OH_ArkUI_DecorationStyleOptions* options,
    ArkUI_TextDecorationType type)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the decoration type of decoration line style.
 *
 * @param options Pointer to the {@link OH_ArkUI_DecorationStyleOptions} object.
 * @param type The decoration type {@link ArkUI_TextDecorationType}.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_GetTextDecorationType(OH_ArkUI_DecorationStyleOptions* options,
    ArkUI_TextDecorationType* type)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the color of decoration line.
 *
 * @param options Pointer to the {@link OH_ArkUI_DecorationStyleOptions} object.
 * @param color Color of decoration line.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_SetColor(OH_ArkUI_DecorationStyleOptions* options, uint32_t color)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the color of decoration line.
 *
 * @param options Pointer to the {@link OH_ArkUI_DecorationStyleOptions} object.
 * @param color Color of decoration line.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_GetColor(OH_ArkUI_DecorationStyleOptions* options, uint32_t* color)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the style of decoration line.
 *
 * @param options Pointer to the {@link OH_ArkUI_DecorationStyleOptions} object.
 * @param style Style of decoration line.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_SetTextDecorationStyle(OH_ArkUI_DecorationStyleOptions* options,
    ArkUI_TextDecorationStyle style)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the style of decoration line.
 *
 * @param options Pointer to the {@link OH_ArkUI_DecorationStyleOptions} object.
 * @param style Style of decoration line.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_GetTextDecorationStyle(OH_ArkUI_DecorationStyleOptions* options,
    ArkUI_TextDecorationStyle* style)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the thickness scale of decoration line.
 *
 * @param options Pointer to the {@link OH_ArkUI_DecorationStyleOptions} object.
 * @param thicknessScale Thickness of decoration line.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_SetThicknessScale(
    OH_ArkUI_DecorationStyleOptions* options, float thicknessScale)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the thickness scale of decoration line.
 *
 * @param options Pointer to the {@link OH_ArkUI_DecorationStyleOptions} object.
 * @param thicknessScale Thickness of decoration line.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_GetThicknessScale(OH_ArkUI_DecorationStyleOptions* options,
    float* thicknessScale)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Creates a data detector config object.
 * When the object is no longer in use, invoke {@link OH_ArkUI_TextDataDetectorConfig_Destroy} to destroy it.
 *
 * @return A pointer to the option object.
 * @since 24
 */
OH_ArkUI_TextDataDetectorConfig* OH_ArkUI_TextDataDetectorConfig_Create()
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroys the data detector config object.
 *
 * @param config Pointer to the object to be destroyed.
 * @since 24
 */
void OH_ArkUI_TextDataDetectorConfig_Destroy(OH_ArkUI_TextDataDetectorConfig* config)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the types of data detector config.
 *
 * @param config Pointer to the {@link OH_ArkUI_TextDataDetectorConfig} object.
 * @param types Types of data detector config.
 * @param length Number of types.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_SetTypes(
    OH_ArkUI_TextDataDetectorConfig* config, const ArkUI_TextDataDetectorType* types, int32_t length)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the types of data detector config.
 *
 * @param config Pointer to the {@link OH_ArkUI_TextDataDetectorConfig} object.
 * @param buffer Buffer pointer to the type array.
 * @param bufferSize Buffer size reserved for types by developer.
 *                   It should be larger than writeLength,
 *                   otherwise the operation will return ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR.
 * @param writeLength Number of types.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 *         Returns {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} if bufferSize is less than writeLength.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_GetTypes(OH_ArkUI_TextDataDetectorConfig* config,
    ArkUI_TextDataDetectorType* buffer, int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the event to be called when data detector works.
 *
 * @param config Pointer to the {@link OH_ArkUI_TextDataDetectorConfig} object.
 * @param userData User data.
 * @param callback detect result update callback.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_RegisterOnDetectResultUpdateCallback(
    OH_ArkUI_TextDataDetectorConfig* config, void* userData,
    void (*callback)(const char* result, int32_t length, void* userData))
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the color of detected content.
 *
 * @param config Pointer to the {@link OH_ArkUI_TextDataDetectorConfig} object.
 * @param color Color of detected content.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_SetColor(OH_ArkUI_TextDataDetectorConfig* config, uint32_t color)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the color of detected content.
 *
 * @param config Pointer to the {@link OH_ArkUI_TextDataDetectorConfig} object.
 * @param color Color of detected content.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_GetColor(OH_ArkUI_TextDataDetectorConfig* config, uint32_t* color)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the decoration style of detected content.
 *
 * @param config Pointer to the {@link OH_ArkUI_TextDataDetectorConfig} object.
 * @param decoration Decoration style of detected content.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_SetDecorationStyleOptions(
    OH_ArkUI_TextDataDetectorConfig* config, OH_ArkUI_DecorationStyleOptions* decoration)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the decoration style of detected content.
 *
 * @param config Pointer to the {@link OH_ArkUI_TextDataDetectorConfig} object.
 * @param decoration Decoration style of detected content.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_GetDecorationStyleOptions(
    OH_ArkUI_TextDataDetectorConfig* config, OH_ArkUI_DecorationStyleOptions* decoration)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets whether to display a preview menu when the detected content is long-pressed.
 *
 * @param config Pointer to the {@link OH_ArkUI_TextDataDetectorConfig} object.
 * @param enablePreviewMenu Whether to display a preview menu when the detected content is long-pressed.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_SetEnablePreviewMenu(
    OH_ArkUI_TextDataDetectorConfig* config, bool enablePreviewMenu)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets whether to display a preview menu when the detected content is long-pressed.
 *
 * @param config Pointer to the {@link OH_ArkUI_TextDataDetectorConfig} object.
 * @param enablePreviewMenu Whether to display a preview menu when the detected content is long-pressed.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_GetEnablePreviewMenu(
    OH_ArkUI_TextDataDetectorConfig* config, bool* enablePreviewMenu)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Create a placeholder options object.
 * When the object is no longer in use, invoke {@link OH_ArkUI_TextEditorPlaceholderOptions_Destroy} to destroy it.
 *
 * @return A pointer to the configuration object.
 * @since 24
 */
OH_ArkUI_TextEditorPlaceholderOptions* OH_ArkUI_TextEditorPlaceholderOptions_Create()
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroys the placeholder options object.
 *
 * @param options <b>TextEditor</b> placeholder options.
 * @since 24
 */
void OH_ArkUI_TextEditorPlaceholderOptions_Destroy(OH_ArkUI_TextEditorPlaceholderOptions* options)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set the hint text of placeholder options.
 *
 * @param options <b>TextEditor</b> placeholder options.
 * @param value The hint text.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_SetValue(
    OH_ArkUI_TextEditorPlaceholderOptions* options, const char* value)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the hint text of placeholder options.
 *
 * @param options <b>TextEditor</b> placeholder options.
 * @param buffer The buffer to which hint text writes to the memory,
 *               memory space needs to be allocated by the developer.
 * @param bufferSize The buffer size
 * @param writeLength Indicates the string length actually written to the buffer
 *                    when returning {@link ARKUI_ERROR_CODE_NO_ERROR}.
 *                    Indicates the minimum buffer size that can accommodate the target
 *                    when {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} is returned.
 * @return The error code.
 *         {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ARKUI_ERROR_CODE_PARAM_INVALID} if the node, buffer or writeLength is null.
 *         {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} If the buffer size is less than the minimum buffer size.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_GetValue(
    OH_ArkUI_TextEditorPlaceholderOptions* options, char* buffer, int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets font size of placeholder options.
 *
 * @param options <b>TextEditor</b> placeholder options.
 * @param fontSize The font size.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_SetFontSize(
    OH_ArkUI_TextEditorPlaceholderOptions* options, float fontSize)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets font size of placeholder options.
 *
 * @param options <b>TextEditor</b> placeholder options.
 * @param fontSize The font size.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_GetFontSize(
    OH_ArkUI_TextEditorPlaceholderOptions* options, float* fontSize)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set font weight of placeholder options.
 *
 * @param options <b>TextEditor</b> placeholder options.
 * @param fontWeight The font weight.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_SetFontWeight(
    OH_ArkUI_TextEditorPlaceholderOptions* options, uint32_t fontWeight)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get font weight of placeholder options.
 *
 * @param options <b>TextEditor</b> placeholder options.
 * @param fontWeight The font weight.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_GetFontWeight(
    OH_ArkUI_TextEditorPlaceholderOptions* options, uint32_t* fontWeight)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set the font family of placeholder options.
 *
 * @param options <b>TextEditor</b> placeholder options.
 * @param fontFamily The font family.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_SetFontFamily(
    OH_ArkUI_TextEditorPlaceholderOptions* options, const char* fontFamily)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the font family of placeholder options.
 *
 * @param options <b>TextEditor</b> placeholder options.
 * @param buffer The buffer to which font family writes to the memory,
 *               memory space needs to be allocated by the developer.
 * @param bufferSize The buffer size
 * @param writeLength Indicates the string length actually written to the buffer
 *                    when returning {@link ARKUI_ERROR_CODE_NO_ERROR}.
 *                    Indicates the minimum buffer size that can accommodate the target
 *                    when {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} is returned.
 * @return The error code.
 *         {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         {@link ARKUI_ERROR_CODE_PARAM_INVALID} if the node, buffer or writeLength is null.
 *         {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} If the buffer size is less than the minimum buffer size.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_GetFontFamily(
    OH_ArkUI_TextEditorPlaceholderOptions* options, char* buffer, int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set the font style of placeholder options.
 *
 * @param options <b>TextEditor</b> placeholder options.
 * @param fontStyle The font style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_SetFontStyle(
    OH_ArkUI_TextEditorPlaceholderOptions* options, ArkUI_FontStyle fontStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the font style of placeholder options.
 *
 * @param options <b>TextEditor</b> placeholder options.
 * @param fontStyle The font style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_GetFontStyle(
    OH_ArkUI_TextEditorPlaceholderOptions* options, ArkUI_FontStyle* fontStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set the font color of placeholder options.
 *
 * @param options <b>TextEditor</b> placeholder options.
 * @param fontColor The font color.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_SetFontColor(
    OH_ArkUI_TextEditorPlaceholderOptions* options, uint32_t fontColor)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the font color of placeholder options.
 *
 * @param options <b>TextEditor</b> placeholder options.
 * @param fontColor The font color.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_GetFontColor(OH_ArkUI_TextEditorPlaceholderOptions* options,
    uint32_t* fontColor)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Create a styled string controller object for text editor.
 * When the object is no longer in use, invoke {@link OH_ArkUI_TextEditorStyledStringController_Destroy} to destroy it.
 *
 * @return A pointer to the styled string controller object.
 * @since 24
 */
OH_ArkUI_TextEditorStyledStringController* OH_ArkUI_TextEditorStyledStringController_Create()
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroys the styled string controller.
 *
 * @param controller <b>TextEditor</b> styled string controller.
 * @since 24
 */
void OH_ArkUI_TextEditorStyledStringController_Destroy(OH_ArkUI_TextEditorStyledStringController* controller)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set caret offset with styled string controller.
 *
 * @param controller <b>TextEditor</b> styled string controller.
 * @param caretOffset caret position.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_SetCaretOffset(
    OH_ArkUI_TextEditorStyledStringController* controller, int32_t caretOffset)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get caret offset with styled string controller.
 *
 * @param controller <b>TextEditor</b> styled string controller.
 * @param caretOffset caret position.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetCaretOffset(
    OH_ArkUI_TextEditorStyledStringController* controller, int32_t* caretOffset)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set selection area with styled string controller.
 *
 * @param controller <b>TextEditor</b> styled string controller.
 * @param start selection area start.
 * @param end selection area end.
 * @param menuPolicy selection area menu policy.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_SetSelection(
    OH_ArkUI_TextEditorStyledStringController* controller, uint32_t start, uint32_t end, ArkUI_MenuPolicy menuPolicy)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get editing state of text editor with styled string controller.
 *
 * @param controller <b>TextEditor</b> styled string controller.
 * @param isEditing editing state.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_IsEditing(
    OH_ArkUI_TextEditorStyledStringController* controller, bool* isEditing)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Exit editing state of text editor with styled string controller.
 *
 * @param controller <b>TextEditor</b> styled string controller.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_StopEditing(
    OH_ArkUI_TextEditorStyledStringController* controller)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get preview text content with styled string controller.
 *
 * @param controller <b>TextEditor</b> styled string controller.
 * @param offset Preview text position.
 * @param buffer The buffer to which preview text content writes to the memory,
 *               memory space needs to be allocated by the developer.
 * @param bufferSize The buffer size
 * @param writeLength Indicates the string length actually written to the buffer
 *                    when returning {@link ARKUI_ERROR_CODE_NO_ERROR}.
 *                    Indicates the minimum buffer size that can accommodate the target
 *                    when {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} is returned.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetPreviewText(
    OH_ArkUI_TextEditorStyledStringController* controller, uint32_t* offset, char* buffer,
    int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get caret rect with styled string controller.
 *
 * @param controller <b>TextEditor</b> styled string controller.
 * @param rect caret area info.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetCaretRect(
    OH_ArkUI_TextEditorStyledStringController* controller, ArkUI_Rect* rect)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Delete character with styled string controller.
 *
 * @param controller <b>TextEditor</b> styled string controller.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_DeleteBackward(
    OH_ArkUI_TextEditorStyledStringController* controller)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Create a paragraph style object for text editor.
 * When the object is no longer in use, invoke {@link OH_ArkUI_TextEditorParagraphStyle_Destroy} to destroy it.
 *
 * @return A pointer to the paragraph style object.
 * @since 24
 */
OH_ArkUI_TextEditorParagraphStyle* OH_ArkUI_TextEditorParagraphStyle_Create()
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroys the paragraph style object.
 *
 * @param style <b>TextEditor</b> paragraph style.
 * @since 24
 */
void OH_ArkUI_TextEditorParagraphStyle_Destroy(OH_ArkUI_TextEditorParagraphStyle* style)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets text alignment in paragraph style.
 *
 * @param style paragraph style.
 * @param align text alignment.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetTextAlign(
    OH_ArkUI_TextEditorParagraphStyle* style, ArkUI_TextAlignment align)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get text alignment in paragraph style.
 *
 * @param style paragraph style.
 * @param align text alignment.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetTextAlign(
    OH_ArkUI_TextEditorParagraphStyle* style, ArkUI_TextAlignment* align)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set pixelmap of leading margin in paragraph style.
 *
 * @param style paragraph style.
 * @param pixelmap pixelmap of leading margin.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetLeadingMarginPixelMap(
    OH_ArkUI_TextEditorParagraphStyle* style, struct OH_PixelmapNative* pixelmap)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get pixelmap of leading margin in paragraph style.
 *
 * @param style paragraph style.
 * @param pixelmap pixelmap of leading margin.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetLeadingMarginPixelMap(
    OH_ArkUI_TextEditorParagraphStyle* style, struct OH_PixelmapNative** pixelmap)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set width of leading margin in paragraph style.
 *
 * @param style paragraph style.
 * @param width width of leading margin.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetLeadingMarginWidth(OH_ArkUI_TextEditorParagraphStyle* style,
    uint32_t width)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get width of leading margin in paragraph style.
 *
 * @param style paragraph style.
 * @param width width of leading margin.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetLeadingMarginWidth(OH_ArkUI_TextEditorParagraphStyle* style,
    uint32_t* width)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets height of leading margin in paragraph style.
 *
 * @param style paragraph style.
 * @param height height of leading margin.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetLeadingMarginHeight(OH_ArkUI_TextEditorParagraphStyle* style,
    uint32_t height)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get height of leading margin in paragraph style.
 *
 * @param style paragraph style.
 * @param height height of leading margin.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetLeadingMarginHeight(OH_ArkUI_TextEditorParagraphStyle* style,
    uint32_t* height)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set word break of paragraph style.
 *
 * @param style paragraph style.
 * @param wordBreak word break.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetWordBreak(OH_ArkUI_TextEditorParagraphStyle* style,
    ArkUI_WordBreak wordBreak)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get word break of paragraph style.
 *
 * @param style paragraph style.
 * @param wordBreak word break.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetWordBreak(OH_ArkUI_TextEditorParagraphStyle* style,
    ArkUI_WordBreak* wordBreak)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set line break strategy of paragraph style.
 *
 * @param style paragraph style.
 * @param lineBreakStrategy line break strategy.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetLineBreakStrategy(OH_ArkUI_TextEditorParagraphStyle* style,
    OH_ArkUI_LineBreakStrategy lineBreakStrategy)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get line break strategy of paragraph style.
 *
 * @param style paragraph style.
 * @param lineBreakStrategy line break strategy.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetLineBreakStrategy(OH_ArkUI_TextEditorParagraphStyle* style,
    OH_ArkUI_LineBreakStrategy* lineBreakStrategy)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set paragraph spacing of paragraph style.
 *
 * @param style paragraph style.
 * @param paragraphSpacing paragraph spacing.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetParagraphSpacing(OH_ArkUI_TextEditorParagraphStyle* style,
    uint32_t paragraphSpacing)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get paragraph spacing of paragraph style.
 *
 * @param style paragraph style.
 * @param paragraphSpacing paragraph spacing.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetParagraphSpacing(OH_ArkUI_TextEditorParagraphStyle* style,
    uint32_t* paragraphSpacing)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set text vertical alignment of paragraph style.
 *
 * @param style paragraph style.
 * @param verticalAlignment text vertical alignment.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetTextVerticalAlign(OH_ArkUI_TextEditorParagraphStyle* style,
    ArkUI_TextVerticalAlignment verticalAlignment)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get text vertical alignment of paragraph style.
 *
 * @param style paragraph style.
 * @param verticalAlignment text vertical alignment.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetTextVerticalAlign(OH_ArkUI_TextEditorParagraphStyle* style,
    ArkUI_TextVerticalAlignment* verticalAlignment)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set text direction of paragraph style.
 *
 * @param style paragraph style.
 * @param textDirection text direction.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetTextDirection(OH_ArkUI_TextEditorParagraphStyle* style,
    ArkUI_TextDirection textDirection)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get text direction of paragraph style.
 *
 * @param style paragraph style.
 * @param textDirection text direction.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetTextDirection(OH_ArkUI_TextEditorParagraphStyle* style,
    ArkUI_TextDirection* textDirection)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set preset paragraph style with styled string controller.
 *
 * @param controller <b>TextEditor</b> styled string controller.
 * @param style preset paragraph style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_SetTypingParagraphStyle(
    OH_ArkUI_TextEditorStyledStringController* controller, OH_ArkUI_TextEditorParagraphStyle* style)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Create a shadow options object.
 * When the object is no longer in use, invoke {@link OH_ArkUI_ShadowOptions_Destroy} to destroy it.
 *
 * @return A pointer to the shadow options object.
 * @since 24
 */
OH_ArkUI_ShadowOptions* OH_ArkUI_ShadowOptions_Create() __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroys the shadow options object.
 *
 * @param options Pointer to the object to be destroyed.
 * @since 24
 */
void OH_ArkUI_ShadowOptions_Destroy(OH_ArkUI_ShadowOptions* options)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets blur radius of the shadow options.
 *
 * @param options shadow options.
 * @param radius blur radius of the shadow.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ShadowOptions_SetRadius(OH_ArkUI_ShadowOptions* options, float radius)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets blur radius of the shadow options.
 *
 * @param options shadow options.
 * @param radius blur radius of the shadow.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ShadowOptions_GetRadius(OH_ArkUI_ShadowOptions* options, float* radius)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set shadow type of the shadow options.
 *
 * @param options shadow options.
 * @param type shadow type.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ShadowOptions_SetType(OH_ArkUI_ShadowOptions* options, ArkUI_ShadowType type)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get shadow type of the shadow options.
 *
 * @param options shadow options.
 * @param type shadow type.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ShadowOptions_GetType(OH_ArkUI_ShadowOptions* options, ArkUI_ShadowType* type)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set shadow color of the shadow options.
 *
 * @param options shadow options.
 * @param color shadow color.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ShadowOptions_SetColor(OH_ArkUI_ShadowOptions* options, uint32_t color)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get shadow color of the shadow options.
 *
 * @param options shadow options.
 * @param color shadow color.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ShadowOptions_GetColor(OH_ArkUI_ShadowOptions* options, uint32_t* color)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set offset of the shadow along the x-axis.
 *
 * @param options shadow options.
 * @param offsetX offset of the shadow along the x-axis.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ShadowOptions_SetOffsetX(OH_ArkUI_ShadowOptions* options, float offsetX)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get offset of the shadow along the x-axis.
 *
 * @param options shadow options.
 * @param offsetX offset of the shadow along the x-axis.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ShadowOptions_GetOffsetX(OH_ArkUI_ShadowOptions* options, float* offsetX)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set offset of the shadow along the y-axis.
 *
 * @param options shadow options.
 * @param offsetY offset of the shadow along the y-axis.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ShadowOptions_SetOffsetY(OH_ArkUI_ShadowOptions* options, float offsetY)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get offset of the shadow along the y-axis.
 *
 * @param options shadow options.
 * @param offsetY offset of the shadow along the y-axis.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ShadowOptions_GetOffsetY(OH_ArkUI_ShadowOptions* options, float* offsetY)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set whether to fill the inside of the component with shadow.
 *
 * @param options shadow options.
 * @param isFill whether to fill the inside of the component with shadow.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ShadowOptions_SetFill(OH_ArkUI_ShadowOptions* options, bool isFill)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get whether to fill the inside of the component with shadow.
 *
 * @param options shadow options.
 * @param isFill whether to fill the inside of the component with shadow.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_ShadowOptions_GetFill(OH_ArkUI_ShadowOptions* options, bool* isFill)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Create a text style object.
 * When the object is no longer in use, invoke {@link OH_ArkUI_TextEditorTextStyle_Destroy} to destroy it.
 *
 * @return A pointer to the text style object.
 * @since 24
 */
OH_ArkUI_TextEditorTextStyle* OH_ArkUI_TextEditorTextStyle_Create()
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroys the text style object.
 *
 * @param style Pointer to the object to be destroyed.
 * @since 24
 */
void OH_ArkUI_TextEditorTextStyle_Destroy(OH_ArkUI_TextEditorTextStyle* style)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set font color of the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param color font color.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetFontColor(OH_ArkUI_TextEditorTextStyle* style, uint32_t color)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get font color of the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param color font color.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetFontColor(OH_ArkUI_TextEditorTextStyle* style, uint32_t* color)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set font size of the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param size font size.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetFontSize(OH_ArkUI_TextEditorTextStyle* style, float size)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get font size of the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param size font size.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetFontSize(OH_ArkUI_TextEditorTextStyle* style, float* size)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set font style of the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param fontStyle font style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetFontStyle(OH_ArkUI_TextEditorTextStyle* style,
    ArkUI_FontStyle fontStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get font style of the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param fontStyle font style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetFontStyle(OH_ArkUI_TextEditorTextStyle* style,
    ArkUI_FontStyle* fontStyle)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set font weight of the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param fontWeight font weight.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetFontWeight(OH_ArkUI_TextEditorTextStyle* style, uint32_t fontWeight)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get font weight of the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param fontWeight font weight.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetFontWeight(OH_ArkUI_TextEditorTextStyle* style, uint32_t* fontWeight)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set font family of the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param fontFamily font family.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetFontFamily(OH_ArkUI_TextEditorTextStyle* style, const char* fontFamily)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get font family of the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param buffer The buffer to which font family content writes to the memory,
 *               memory space needs to be allocated by the developer.
 * @param bufferSize The buffer size
 * @param writeLength Indicates the string length actually written to the buffer
 *                    when returning {@link ARKUI_ERROR_CODE_NO_ERROR}.
 *                    Indicates the minimum buffer size that can accommodate the target
 *                    when {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} is returned.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetFontFamily(OH_ArkUI_TextEditorTextStyle* style,
    char* buffer, int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set text decoration options of the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param options text decoration options.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetDecoration(OH_ArkUI_TextEditorTextStyle* style,
    OH_ArkUI_DecorationStyleOptions* options)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get text decoration options of the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param options text decoration options.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetDecoration(OH_ArkUI_TextEditorTextStyle* style,
    OH_ArkUI_DecorationStyleOptions* options)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set text shadow options of the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param options text shadow options.
 * @param length the length of text shadow options.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetTextShadows(OH_ArkUI_TextEditorTextStyle* style,
    const OH_ArkUI_ShadowOptions** options, int32_t length)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get text shadow options of the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param shadowOptions text shadow options.
 * @param shadowOptionsSize buffer size for shadow options.
 * @param writeLength the actual size of text shadow options in text style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetTextShadows(OH_ArkUI_TextEditorTextStyle* style,
    OH_ArkUI_ShadowOptions** shadowOptions, uint32_t shadowOptionsSize, uint32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set text line height of the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param lineHeight text line height.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetLineHeight(OH_ArkUI_TextEditorTextStyle* style, int32_t lineHeight)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get text line height of the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param lineHeight text line height.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetLineHeight(OH_ArkUI_TextEditorTextStyle* style, int32_t* lineHeight)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set letter spacing of the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param letterSpacing letter spacing.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetLetterSpacing(OH_ArkUI_TextEditorTextStyle* style,
    int32_t letterSpacing)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get letter spacing of the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param letterSpacing letter spacing.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetLetterSpacing(OH_ArkUI_TextEditorTextStyle* style,
    int32_t* letterSpacing)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set font feature of the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param fontFeature font feature.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetFontFeature(OH_ArkUI_TextEditorTextStyle* style,
    const char* fontFeature)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get font feature of the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param buffer The buffer to which font feature content writes to the memory,
 *               memory space needs to be allocated by the developer.
 * @param bufferSize The buffer size
 * @param writeLength Indicates the string length actually written to the buffer
 *                    when returning {@link ARKUI_ERROR_CODE_NO_ERROR}.
 *                    Indicates the minimum buffer size that can accommodate the target
 *                    when {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} is returned.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetFontFeature(OH_ArkUI_TextEditorTextStyle* style, char* buffer,
    int32_t bufferSize, int32_t* writeLength)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set whether half leading is enabled in the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param halfLeading whether half leading is enabled.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetHalfLeading(OH_ArkUI_TextEditorTextStyle* style, bool halfLeading)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get whether half leading is enabled in the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param halfLeading whether half leading is enabled.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetHalfLeading(OH_ArkUI_TextEditorTextStyle* style, bool* halfLeading)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set text background color in the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param color text background color.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetTextBackgroundColor(OH_ArkUI_TextEditorTextStyle* style,
    uint32_t color)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get text background color in the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param color text background color.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetTextBackgroundColor(OH_ArkUI_TextEditorTextStyle* style,
    uint32_t* color)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set the rounded corner radius of the text background in the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param topLeft radius of the upper left corner of text background.
 * @param topRight radius of the upper right corner of text background.
 * @param bottomLeft radius of the lower left corner of text background.
 * @param bottomRight radius of the lower right corner of text background.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetTextBackgroundRadius(OH_ArkUI_TextEditorTextStyle* style, float topLeft,
    float topRight, float bottomLeft, float bottomRight)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the rounded corner radius of the text background in the text style.
 *
 * @param style <b>TextEditor</b> text style.
 * @param topLeft radius of the upper left corner of text background.
 * @param topRight radius of the upper right corner of text background.
 * @param bottomLeft radius of the lower left corner of text background.
 * @param bottomRight radius of the lower right corner of text background.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetTextBackgroundRadius(OH_ArkUI_TextEditorTextStyle* style,
    float* topLeft, float* topRight, float* bottomLeft, float* bottomRight)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set the preset typing style with styled string controller.
 *
 * @param controller <b>TextEditor</b> styled string controller.
 * @param style the preset typing style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_SetTypingStyle(
    OH_ArkUI_TextEditorStyledStringController* controller, OH_ArkUI_TextEditorTextStyle* style)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the preset typing style with styled string controller.
 *
 * @param controller <b>TextEditor</b> styled string controller.
 * @param style the preset typing style.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetTypingStyle(
    OH_ArkUI_TextEditorStyledStringController* controller, OH_ArkUI_TextEditorTextStyle* style)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Creates a TextEditor selection menu options object.
 * When the object is no longer in use, invoke {@link OH_ArkUI_TextEditorSelectionMenuOptions_Destroy} to destroy it.
 *
 * @return A pointer to the OH_ArkUI_TextEditorSelectionMenuOptions.
 * @since 24
 */
OH_ArkUI_TextEditorSelectionMenuOptions* OH_ArkUI_TextEditorSelectionMenuOptions_Create()
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroys the TextEditor selection menu options object.
 *
 * @param options Pointer to the {@link OH_ArkUI_TextEditorSelectionMenuOptions} object to be destroyed.
 * @since 24
 */
void OH_ArkUI_TextEditorSelectionMenuOptions_Destroy(OH_ArkUI_TextEditorSelectionMenuOptions* options)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the span type of selection menu in TextEditor.
 *
 * @param options Pointer to the {@link OH_ArkUI_TextEditorSelectionMenuOptions} object.
 * @param textEditorSpanType span type.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_SetSpanType(
    OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_TextEditorSpanType textEditorSpanType)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the span type of selection menu in TextEditor.
 *
 * @param options Pointer to the {@link OH_ArkUI_TextEditorSelectionMenuOptions} object.
 * @param textEditorSpanType span type.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_GetSpanType(
    OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_TextEditorSpanType* textEditorSpanType)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the content of selection menu in TextEditor.
 *
 * @param options Pointer to the {@link OH_ArkUI_TextEditorSelectionMenuOptions} object.
 * @param node content node.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_SetContentNode(OH_ArkUI_TextEditorSelectionMenuOptions* options,
    ArkUI_NodeHandle node)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the content node of selection menu in TextEditor.
 *
 * @param options Pointer to the {@link OH_ArkUI_TextEditorSelectionMenuOptions} object.
 * @param node content node.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_GetContentNode(OH_ArkUI_TextEditorSelectionMenuOptions* options,
    ArkUI_NodeHandle* node)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the response type of selection menu in TextEditor.
 *
 * @param options Pointer to the {@link OH_ArkUI_TextEditorSelectionMenuOptions} object.
 * @param responseType response type.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_SetResponseType(
    OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_TextEditorResponseType responseType)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the response type of selection menu in TextEditor.
 *
 * @param options Pointer to the {@link OH_ArkUI_TextEditorSelectionMenuOptions} object.
 * @param responseType response type.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_GetResponseType(
    OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_TextEditorResponseType* responseType)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the type of selection menu in TextEditor.
 *
 * @param options Pointer to the {@link OH_ArkUI_TextEditorSelectionMenuOptions} object.
 * @param menuType menu type.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_SetMenuType(OH_ArkUI_TextEditorSelectionMenuOptions* options,
    OH_ArkUI_TextMenuType menuType)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the type of selection menu in TextEditor.
 *
 * @param options Pointer to the {@link OH_ArkUI_TextEditorSelectionMenuOptions} object.
 * @param menuType Menu type.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_GetMenuType(OH_ArkUI_TextEditorSelectionMenuOptions* options,
    OH_ArkUI_TextMenuType* menuType)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the event to be called when selection menu shows.
 *
 * @param options Pointer to the {@link OH_ArkUI_TextEditorSelectionMenuOptions} object.
 * @param userData User data.
 * @param callback The callback function of menu show.
 *     start The start offset of the selected content.
 *     end The end offset of the selected content.
 *     callbackUserData The user data.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_RegisterOnMenuShowCallback(
    OH_ArkUI_TextEditorSelectionMenuOptions* options, void* userData,
    void (*callback)(int32_t start, int32_t end, void* callbackUserData))
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the event to be called when selection menu hides.
 *
 * @param options Pointer to the {@link OH_ArkUI_TextEditorSelectionMenuOptions} object.
 * @param userData user data.
 * @param callback The callback function of menu hide.
 *     start The start offset of the selected content.
 *     end The end offset of the selected content.
 *     userData The user data.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_RegisterOnMenuHideCallback(
    OH_ArkUI_TextEditorSelectionMenuOptions* options, void* userData,
    void (*callback)(int32_t start, int32_t end, void* callbackUserData))
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the event to be called when selection menu appears.
 *
 * @param options Pointer to the {@link OH_ArkUI_TextEditorSelectionMenuOptions} object.
 * @param userData user data.
 * @param callback The callback function of menu appear.
 *     start The start offset of the selected content.
 *     end The end offset of the selected content.
 *     userData The user data.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_RegisterOnMenuAppearCallback(
    OH_ArkUI_TextEditorSelectionMenuOptions* options, void* userData,
    void (*callback)(int32_t start, int32_t end, void* callbackUserData))
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the event to be called when selection menu disappears.
 *
 * @param options Pointer to the {@link OH_ArkUI_TextEditorSelectionMenuOptions} object.
 * @param userData user data.
 * @param callback The callback function of menu disappear.
 *     userData The user data.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_RegisterOnMenuDisappearCallback(
    OH_ArkUI_TextEditorSelectionMenuOptions* options, void* userData, void (*callback)(void* callbackUserData))
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the haptic feedback mode of selection menu in TextEditor.
 *
 * @param options Pointer to the {@link OH_ArkUI_TextEditorSelectionMenuOptions} object.
 * @param mode haptic feedback mode.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_SetHapticFeedbackMode(
    OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_HapticFeedbackMode mode)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the haptic feedback mode of selection menu in TextEditor.
 *
 * @param options Pointer to the {@link OH_ArkUI_TextEditorSelectionMenuOptions} object.
 * @param mode haptic feedback mode.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_GetHapticFeedbackMode(
    OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_HapticFeedbackMode* mode)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Close selection menu of text editor with styled string controller.
 *
 * @param controller <b>TextEditor</b> styled string controller.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_CloseSelectionMenu(
    OH_ArkUI_TextEditorStyledStringController* controller)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the selection of text editor with styled string controller.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param controller <b>TextEditor</b> styled string controller.
 * @param start Start offset of selection.
 * @param end End offset of selection.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetSelection(
    const OH_ArkUI_TextEditorStyledStringController* controller, uint32_t* start, uint32_t* end)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the styled string of text editor.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param controller <b>TextEditor</b> styled string controller.
 * @param descriptor Pointer to a <b>ArkUI_StyledString_Descriptor</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_SetStyledString(
    const OH_ArkUI_TextEditorStyledStringController* controller, const ArkUI_StyledString_Descriptor* descriptor)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the styled string of text editor.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param controller <b>TextEditor</b> styled string controller.
 * @param descriptor Pointer to a <b>ArkUI_StyledString_Descriptor</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetStyledString(
    const OH_ArkUI_TextEditorStyledStringController* controller, ArkUI_StyledString_Descriptor* descriptor)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the styled string placeholder.
 *
 * @note All input pointer parameters must be allocated, managed, and released by the caller.
 * @param controller <b>TextEditor</b> styled string controller.
 * @param descriptor Pointer to a <b>ArkUI_StyledString_Descriptor</b> object.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_SetStyledPlaceholder(
    const OH_ArkUI_TextEditorStyledStringController* controller, const ArkUI_StyledString_Descriptor* descriptor)
    __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Create the ArkUI_PickerIndicatorStyle instance.
 *
 * @param type The picker selection indicator enumeration type.
 * @return  ArkUI_PickerIndicatorStyle instance. If the instance returns a null pointer,
 *         it indicates creation failure, and the reason for the failure may be that the address space is full or
 *         the type not supported.
 * @since 23
*/
ArkUI_PickerIndicatorStyle* OH_ArkUI_PickerIndicatorStyle_Create(ArkUI_PickerIndicatorType type)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
* @brief Destroy the ArkUI_PickerIndicatorStyle instance.
*
* @param style The ArkUI_PickerIndicatorStyle instance to be destroyed.
* @since 23
*/
void OH_ArkUI_PickerIndicatorStyle_Dispose(ArkUI_PickerIndicatorStyle* style)
__attribute__((__availability__(ohos, introduced=23.0.0)));

/**
* @brief Set the parameters of background style.
*
* @param style The ArkUI_PickerIndicatorStyle instance.
* @param background The parameters of background style.
* @return Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if success.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} The parameters set need to be consistent with
*         the type of the created instance. If they are not consistent, this error code will be returned.
*         This interface only takes effect when the type is "background".
* @since 23
*/
ArkUI_ErrorCode OH_ArkUI_PickerIndicatorStyle_ConfigureBackground(ArkUI_PickerIndicatorStyle* style,
    ArkUI_PickerIndicatorBackground* background)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
* @brief Set the parameters of divider style.
*
* @param style The ArkUI_PickerIndicatorStyle instance.
* @param divider The parameters of divider style.
* @return Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if success.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} The parameters set need to be consistent with
*         the type of the created instance. If they are not consistent, this error code will be returned.
*         This interface only takes effect when the type is "divider".
* @since 23
*/
ArkUI_ErrorCode OH_ArkUI_PickerIndicatorStyle_ConfigureDivider(ArkUI_PickerIndicatorStyle* style,
    ArkUI_PickerIndicatorDivider* divider)
    __attribute__((__availability__(ohos, introduced=23.0.0)));

/**
 * @brief Defines the font weight configuration of text.
 *
 * @since 24
 */
typedef struct OH_ArkUI_FontWeightConfigs OH_ArkUI_FontWeightConfigs;

/**
 * @brief Defines the font configuration of text.
 *
 * @since 24
 */
typedef struct OH_ArkUI_FontConfigs OH_ArkUI_FontConfigs;

/**
 * @brief Create an option object for font weight configuration of text.
 *
 * @return A pointer to the option object.
 * @since 24
 */
OH_ArkUI_FontWeightConfigs* OH_ArkUI_FontWeightConfigs_Create()
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroy an option object for font weight configuration of text.
 *
 * @param option Pointer to the option object to be destroyed.
 * @since 24
 */
void OH_ArkUI_FontWeightConfigs_Destroy(OH_ArkUI_FontWeightConfigs* option)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the enableVariableFontWeight flag of an option object for font weight configuration of text.
 * The flag defines whether VariableFontWeight is supported. The default value is false.
 * True means enable VariableFontWeight, false means disable VariableFontWeight.
 *
 * @param option Pointer to the option object to be modified.
 * @param enable enableVariableFontWeight Flag.
 * @since 24
 */
void OH_ArkUI_FontWeightConfigs_SetEnableVariableFontWeight(OH_ArkUI_FontWeightConfigs* option, bool enable)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Gets the enableVariableFontWeight flag of an option object for font weight configuration of text.
 * The flag defines whether VariableFontWeight is supported. The default value is false.
 * True means enable VariableFontWeight, false means disable VariableFontWeight.
 *
 * @param option Pointer to the option object.
 * @return Returns the enableVariableFontWeight flag.
 * @since 24
 */
bool OH_ArkUI_FontWeightConfigs_GetEnableVariableFontWeight(OH_ArkUI_FontWeightConfigs* option)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the enableDeviceFontWeightCategory flag of an option object for font weight configuration of text.
 * Defines whether font weight will be automatically updated when the device's font weight category changes.
 * The default value is true.
 * True means font weight will be automatically updated when the device's font weight category changes.
 * False means font weight will not be automatically updated when the device's font weight category changes.
 *
 * @param option Pointer to the option object to be modified.
 * @param enable enableDeviceFontWeightCategory Flag.
 * @since 24
 */
void OH_ArkUI_FontWeightConfigs_SetEnableDeviceFontWeightCategory(OH_ArkUI_FontWeightConfigs* option, bool enable)
__attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Gets the enableDeviceFontWeightCategory flag of an option object for font weight configuration of text.
 * Defines whether font weight will be automatically updated when the device's font weight category changes.
 * The default value is true.
 * True means font weight will be automatically updated when the device's font weight category changes.
 * False means font weight will not be automatically updated when the device's font weight category changes.
 *
 * @param option Pointer to the option object.
 * @return Returns the enableDeviceFontWeightCategory flag.
 * @since 24
 */
bool OH_ArkUI_FontWeightConfigs_GetEnableDeviceFontWeightCategory(OH_ArkUI_FontWeightConfigs* option)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Create an option object for font configuration of text.
 *
 * @return A pointer to the option object.
 * @since 24
 */
OH_ArkUI_FontConfigs* OH_ArkUI_FontConfigs_Create() __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Destroy an option object for font configuration of text.
 *
 * @param option Pointer to the option object to be destroyed.
 * @since 24
 */
void OH_ArkUI_FontConfigs_Destroy(OH_ArkUI_FontConfigs* option)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Sets the font weight configs of an option object for font configuration of text.
 *
 * @param option Pointer to the option object to be modified.
 * @param fontWeightConfigs font weight configs.
 * @since 24
 */
void OH_ArkUI_FontConfigs_SetFontWeightConfigs(OH_ArkUI_FontConfigs* option,
    OH_ArkUI_FontWeightConfigs* fontWeightConfigs)
    __attribute__((__availability__(ohos, introduced=24.0.0)));
 
/**
 * @brief Gets the font weight configs of an option object for font configuration of text.
 *
 * @param option Pointer to the option object.
 * @return Returns the font weight configs.
 * @since 24
 */
OH_ArkUI_FontWeightConfigs* OH_ArkUI_FontConfigs_GetFontWeightConfigs(OH_ArkUI_FontConfigs* option)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Defines the scale options for matrix scaling.
 *
 * @since 24
 */
typedef struct ArkUI_Matrix4ScaleOptions ArkUI_Matrix4ScaleOptions;

/**
 * @brief Create an object of ArkUI_Matrix4ScaleOptions.
 *        In the newly created options, the default values for the scaling coefficients in the x, y and z directions
 *        are 1, and the default values for centerX, centerY are 0. 
 *
 * @return Returns a pointer to the newly created ArkUI_Matrix4ScaleOptions.
 * @since 24
 */
ArkUI_Matrix4ScaleOptions* OH_ArkUI_Matrix4ScaleOptions_Create()
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Disposes the ArkUI_Matrix4ScaleOptions object.
 *
 * @param options Pointer to the ArkUI_Matrix4ScaleOptions instance to be destroyed.
 * @since 24
 */
void OH_ArkUI_Matrix4ScaleOptions_Dispose(ArkUI_Matrix4ScaleOptions* options)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set the scaling factor in the x direction in ArkUI_Matrix4ScaleOptions. 
 *
 * @param options Pointer to the ArkUI_Matrix4ScaleOptions object.
 * @param scaleX The scaling factor in the x direction. Value range: (-∞, +∞).
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful. 
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4ScaleOptions_SetX(ArkUI_Matrix4ScaleOptions* options, const float scaleX)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the scaling factor in the x direction in ArkUI_Matrix4ScaleOptions.
 *        If the value of x is never set, its default value is 1.
 *
 * @param options Pointer to the ArkUI_Matrix4ScaleOptions object.
 * @param scaleX The scaling factor in the x direction.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4ScaleOptions_GetX(const ArkUI_Matrix4ScaleOptions* options, float* scaleX)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set the scaling factor in the y direction in ArkUI_Matrix4ScaleOptions.
 *
 * @param options Pointer to the ArkUI_Matrix4ScaleOptions object.
 * @param scaleY The scaling factor in the y direction. Value range: (-∞, +∞).
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4ScaleOptions_SetY(ArkUI_Matrix4ScaleOptions* options, const float scaleY)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the scaling factor in the y direction in ArkUI_Matrix4ScaleOptions.
 *        If the value of y is never set, its default value is 1.
 *
 * @param options Pointer to the ArkUI_Matrix4ScaleOptions object.
 * @param scaleY The scaling factor in the y direction.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4ScaleOptions_GetY(const ArkUI_Matrix4ScaleOptions* options, float* scaleY)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set the scaling factor in the z direction in ArkUI_Matrix4ScaleOptions.
 *
 * @param options Pointer to the ArkUI_Matrix4ScaleOptions object.
 * @param scaleZ The scaling factor in the z direction. Value range: (-∞, +∞).
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4ScaleOptions_SetZ(ArkUI_Matrix4ScaleOptions* options, const float scaleZ)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the scaling factor in the z direction in ArkUI_Matrix4ScaleOptions.
 *        If the value of z is never set, its default value is 1.
 *
 * @param options Pointer to the ArkUI_Matrix4ScaleOptions object.
 * @param scaleZ The scaling factor in the z direction.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4ScaleOptions_GetZ(const ArkUI_Matrix4ScaleOptions* options, float* scaleZ)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set x offset relative to the transformation center. 0 means no additional x-direction offset from the
 *        transformation center. The unit is px.
 *
 * @param options Pointer to the ArkUI_Matrix4ScaleOptions object.
 * @param centerX The x offset relative to the transformation center. Value range: (-∞, +∞).
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4ScaleOptions_SetCenterX(ArkUI_Matrix4ScaleOptions* options, const float centerX)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the value of centerX from the options, which represents the x-direction offset relative to the
 *        transformation center. The unit is px. If the value of centerX is never set, its default value is 0.
 *
 * @param options Pointer to the ArkUI_Matrix4ScaleOptions object.
 * @param centerX The x-direction offset relative to the transformation center.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4ScaleOptions_GetCenterX(const ArkUI_Matrix4ScaleOptions* options, float* centerX)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set y offset relative to the transformation center. 0 means no additional y-direction offset from the
 *        transformation center. The unit is px.
 *
 * @param options Pointer to the ArkUI_Matrix4ScaleOptions object.
 * @param centerY The y offset relative to the transformation center. Value range: (-∞, +∞).
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4ScaleOptions_SetCenterY(ArkUI_Matrix4ScaleOptions* options, const float centerY)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the value of centerY from the options, which represents the y-direction offset relative to the
 *        transformation center. The unit is px. If the value of centerY is never set, its default value is 0.
 *
 * @param options Pointer to the ArkUI_Matrix4ScaleOptions object.
 * @param centerY The y-direction offset relative to the transformation center.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4ScaleOptions_GetCenterY(const ArkUI_Matrix4ScaleOptions* options, float* centerY)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Defines the rotation options for matrix rotating.
 *
 * @since 24
 */
typedef struct ArkUI_Matrix4RotationOptions ArkUI_Matrix4RotationOptions;

/**
 * @brief Create an object of ArkUI_Matrix4RotationOptions.
 *        In the newly created options, the x, y, and z values in the direction vector specifying the rotation axis
 *        are undetermined; The default values for centerX, centerY are 0; The default value for angle is 0.
 *        If none of x, y, z are specified, it is equivalent to x=0, y=0, z=1, which means rotation around the z-axis.
 *        Once any one of x, y, z is specified, the remaining unspecified values are equivalent to 0.
 *
 * @return Returns a pointer to the newly created ArkUI_Matrix4RotationOptions.
 * @since 24
 */
ArkUI_Matrix4RotationOptions* OH_ArkUI_Matrix4RotationOptions_Create()
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Disposes the ArkUI_Matrix4RotationOptions object.
 *
 * @param options Pointer to the ArkUI_Matrix4RotationOptions instance to be destroyed.
 * @since 24
 */
void OH_ArkUI_Matrix4RotationOptions_Dispose(ArkUI_Matrix4RotationOptions* options)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set the value of the direction vector for the x-axis direction in ArkUI_Matrix4RotationOptions.
 *
 * @param options Pointer to the ArkUI_Matrix4RotationOptions object.
 * @param x The value of the direction vector for the x-axis direction. Value range: (-∞, +∞).
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4RotationOptions_SetX(ArkUI_Matrix4RotationOptions* options, const float x)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the value of the direction vector for the x-axis direction in ArkUI_Matrix4RotationOptions.
 *        If the value of x is never set, its value will be undefined, so the function will return
 *        ARKUI_ERROR_CODE_PARAM_INVALID.
 *
 * @param options Pointer to the ArkUI_Matrix4RotationOptions object.
 * @param x The value of the direction vector for the x-axis direction.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4RotationOptions_GetX(const ArkUI_Matrix4RotationOptions* options, float* x)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set the value of the direction vector for the y-axis direction in ArkUI_Matrix4RotationOptions.
 *
 * @param options Pointer to the ArkUI_Matrix4RotationOptions object.
 * @param y The value of the direction vector for the y-axis direction. Value range: (-∞, +∞).
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4RotationOptions_SetY(ArkUI_Matrix4RotationOptions* options, const float y)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the value of the direction vector for the y-axis direction in ArkUI_Matrix4RotationOptions.
 *        If the value of y is never set, its value will be undefined, so the function will return
 *        ARKUI_ERROR_CODE_PARAM_INVALID.
 *
 * @param options Pointer to the ArkUI_Matrix4RotationOptions object.
 * @param y The value of the direction vector for the y-axis direction.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4RotationOptions_GetY(const ArkUI_Matrix4RotationOptions* options, float* y)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set the value of the direction vector for the z-axis direction in ArkUI_Matrix4RotationOptions.
 *
 * @param options Pointer to the ArkUI_Matrix4RotationOptions object.
 * @param z The value of the direction vector for the z-axis direction. Value range: (-∞, +∞).
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4RotationOptions_SetZ(ArkUI_Matrix4RotationOptions* options, const float z)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the value of the direction vector for the z-axis direction in ArkUI_Matrix4RotationOptions.
 *        If the value of z is never set, its value will be undefined, so the function will return
 *        ARKUI_ERROR_CODE_PARAM_INVALID.
 *
 * @param options Pointer to the ArkUI_Matrix4RotationOptions object.
 * @param z The value of the direction vector for the z-axis direction.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4RotationOptions_GetZ(const ArkUI_Matrix4RotationOptions* options, float* z)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set the value of the rotation angle in ArkUI_Matrix4RotationOptions. The unit is degree.
 *
 * @param options Pointer to the ArkUI_Matrix4RotationOptions object.
 * @param angle The value of the rotation angle in ArkUI_Matrix4RotationOptions. Value range: (-∞, +∞).
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4RotationOptions_SetAngle(ArkUI_Matrix4RotationOptions* options, const float angle)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the value of the rotation angle in ArkUI_Matrix4RotationOptions. The unit is degree.
 *        If the value of angle is never set, its default value is 0.
 *
 * @param options Pointer to the ArkUI_Matrix4RotationOptions object.
 * @param angle The value of the rotation angle in ArkUI_Matrix4RotationOptions.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4RotationOptions_GetAngle(const ArkUI_Matrix4RotationOptions* options, float* angle)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set x offset relative to the transformation center. 0 means no additional x-direction offset from the
 *        transformation center. The unit is px.
 *
 * @param options Pointer to the ArkUI_Matrix4RotationOptions object.
 * @param centerX The x offset relative to the transformation center. Value range: (-∞, +∞).
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4RotationOptions_SetCenterX(ArkUI_Matrix4RotationOptions* options, const float centerX)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the value of centerX from the options, which represents the x-direction offset relative to the
 *        transformation center. The unit is px. If the value of centerX is never set, its default value is 0.
 *
 * @param options Pointer to the ArkUI_Matrix4RotationOptions object.
 * @param centerX The x-direction offset relative to the transformation center.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4RotationOptions_GetCenterX(const ArkUI_Matrix4RotationOptions* options, float* centerX)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set y offset relative to the transformation center. 0 means no additional y-direction offset from the
 *        transformation center. The unit is px.
 *
 * @param options Pointer to the ArkUI_Matrix4RotationOptions object.
 * @param centerY The y offset relative to the transformation center. Value range: (-∞, +∞).
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4RotationOptions_SetCenterY(ArkUI_Matrix4RotationOptions* options, const float centerY)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the value of centerY from the options, which represents the y-direction offset relative to the
 *        transformation center. The unit is px. If the value of centerY is never set, its default value is 0.
 *
 * @param options Pointer to the ArkUI_Matrix4RotationOptions object.
 * @param centerY The y-direction offset relative to the transformation center.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4RotationOptions_GetCenterY(const ArkUI_Matrix4RotationOptions* options, float* centerY)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Defines the translation options for matrix translating.
 *
 * @since 24
 */
typedef struct ArkUI_Matrix4TranslationOptions ArkUI_Matrix4TranslationOptions;

/**
 * @brief Create an object of ArkUI_Matrix4TranslationOptions.
 *        In the newly created options, the default values for x, y and z are 0.
 *
 * @return Returns a pointer to the newly created ArkUI_Matrix4TranslationOptions.
 * @since 24
 */
ArkUI_Matrix4TranslationOptions* OH_ArkUI_Matrix4TranslationOptions_Create()
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Disposes the ArkUI_Matrix4TranslationOptions object.
 *
 * @param options Pointer to the ArkUI_Matrix4TranslationOptions instance to be destroyed.
 * @since 24
 */
void OH_ArkUI_Matrix4TranslationOptions_Dispose(ArkUI_Matrix4TranslationOptions* options)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set the translation value in the x-axis direction. The unit is px.
 *        If the value of x is never set, its default value is 0.
 *
 * @param options Pointer to the ArkUI_Matrix4TranslationOptions object.
 * @param x The translation value in the x-axis direction. Value range: (-∞, +∞).
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4TranslationOptions_SetX(ArkUI_Matrix4TranslationOptions* options, const float x)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the translation value in the x-axis direction from ArkUI_Matrix4TranslationOptions.
 *
 * @param options Pointer to the ArkUI_Matrix4TranslationOptions object.
 * @param x The translation value in the x-axis direction.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4TranslationOptions_GetX(const ArkUI_Matrix4TranslationOptions* options, float* x)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set the translation value in the y-axis direction. The unit is px.
 *        If the value of y is never set, its default value is 0.
 *
 * @param options Pointer to the ArkUI_Matrix4TranslationOptions object.
 * @param y The translation value in the y-axis direction. Value range: (-∞, +∞).
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4TranslationOptions_SetY(ArkUI_Matrix4TranslationOptions* options, const float y)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the translation value in the y-axis direction from ArkUI_Matrix4TranslationOptions.
 *
 * @param options Pointer to the ArkUI_Matrix4TranslationOptions object.
 * @param y The translation value in the y-axis direction.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4TranslationOptions_GetY(const ArkUI_Matrix4TranslationOptions* options, float* y)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Set the translation value in the z-axis direction. The unit is px.
 *        If the value of z is never set, its default value is 0.
 *
 * @param options Pointer to the ArkUI_Matrix4TranslationOptions object.
 * @param z The translation value in the z-axis direction. Value range: (-∞, +∞).
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4TranslationOptions_SetZ(ArkUI_Matrix4TranslationOptions* options, const float z)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Get the translation value in the z-axis direction from ArkUI_Matrix4TranslationOptions.
 *
 * @param options Pointer to the ArkUI_Matrix4TranslationOptions object.
 * @param z The translation value in the z-axis direction.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4TranslationOptions_GetZ(const ArkUI_Matrix4TranslationOptions* options, float* z)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Create an identity matrix4 object.
 *
 * @return Returns the created identity matrix4 object.
 * @since 24
 */
ArkUI_Matrix4* OH_ArkUI_Matrix4_CreateIdentity() __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Specify each element of the matrix to create a matrix4 object.
 *
 * @param elements Pointer to the array of expected matrix element data. The length of array should be greater than
 *                 or equal to 16. The parameter must not be null.
 * @return Returns the newly created matrix4 object.
 *         If the pointer of elements is null, the function will return null.
 * @since 24
 */
ArkUI_Matrix4* OH_ArkUI_Matrix4_CreateByElements(const float* elements)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Disposes a matrix4 object.
 *
 * @param matrix Pointer to the matrix4 object to be disposed.
 * @since 24
 */
void OH_ArkUI_Matrix4_Dispose(ArkUI_Matrix4* matrix) __attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Create a copy of the matrix4 object.
 *
 * @param matrix Pointer to the original matrix4 object.
 * @return Returns the newly created matrix4 object.
 * @since 24
 */
ArkUI_Matrix4* OH_ArkUI_Matrix4_Copy(const ArkUI_Matrix4* matrix)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Perform an inverse matrix transformation on the input matrix.
 *        If the matrix is invertible, this function will modify the input matrix; otherwise, the matrix will remain
 *        unchanged and an error code will be returned.
 *
 * @param matrix Pointer to the matrix4 object to be inverted.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if the matrix is not invertible.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4_Invert(ArkUI_Matrix4* matrix)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Combine another matrix with the original matrix, and storing the resulting matrix in oriMatrix.
 *        The resulting matrix is equivalent to first applying the transformation of oriMatrix and then applying
 *        the transformation of anotherMatrix. This function will alter the oriMatrix object.
 *
 * @param oriMatrix Pointer to the original matrix4 object.
 * @param anotherMatrix Pointer to another matrix object to be combined.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4_Combine(ArkUI_Matrix4* oriMatrix, const ArkUI_Matrix4* anotherMatrix)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Apply a tranlation transformation to the original matrix to obtain the translated matrix. Each translation
 *        transformation is applied cumulatively. This function will alter the input matrix object.
 *
 * @param matrix Pointer to the matrix4 object to be translated.
 * @param translate Pointer to the translation options.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4_Translate(ArkUI_Matrix4* matrix, const ArkUI_Matrix4TranslationOptions* translate)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Apply a scale transformation to the original matrix to obtain the scaled matrix. Each scale
 *        transformation is applied cumulatively. This function will alter the input matrix object.
 *
 * @param matrix Pointer to the matrix4 object to be scaled.
 * @param scale Pointer to the scale options.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4_Scale(ArkUI_Matrix4* matrix, const ArkUI_Matrix4ScaleOptions* scale)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Apply a rotation transformation to the original matrix to obtain the rotated matrix. Each rotation
 *        transformation is applied cumulatively. This function will alter the input matrix object.
 *
 * @param matrix Pointer to the matrix4 object to be rotated.
 * @param rotate Pointer to the rotation options.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4_Rotate(ArkUI_Matrix4* matrix, const ArkUI_Matrix4RotationOptions* rotate)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Apply a skew transformation to the original matrix to obtain the skewed matrix. Each skew
 *        transformation is applied cumulatively. This function will alter the input matrix object.
 *
 * @param matrix Pointer to the matrix4 object to be skewed. It must not be null.
 * @param skewX Skew coefficient in the x direction.
 * @param skewY Skew coefficient in the y direction.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4_Skew(ArkUI_Matrix4* matrix, const float skewX, const float skewY)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Calculate the new coordinate position of a point after it has been transformed by a matrix.
 *        The calculated transformed coordinate point will be filled into the ArkUI_PointF structure
 *        pointed to by result.
 *
 * @param matrix Pointer to the matrix4 object.
 * @param oriPoint Pointer to the original coordinate point.
 * @param result Pointer to the result point. It must not be null.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4_TransformPoint(const ArkUI_Matrix4* matrix, const ArkUI_PointF* oriPoint, ArkUI_PointF* result)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Map the vertex coordinates of one polygon to the vertex coordinates of another polygon, and calculate the required
 *        matrix. The resulting matrix will be filled into the object pointed to by matrix.
 * 
 * @param matrix Pointer to the original matrix4 object. The result matrix will be filled into the object pointed to by it.
 *               It must not be null.
 * @param src Pointer to the array of original polygon coordinate points. The array should be at least as long as pointCount.
 * @param dst Pointer to the array of polygon coordinate points after mapping. The array should be at least as long as pointCount.
 * @param pointCount The number of polygon points, which must be one of the values 0, 1, 2, 3, or 4.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4_SetPolyToPoly(ArkUI_Matrix4* matrix, const ArkUI_PointF* src, const ArkUI_PointF* dst, const uint32_t pointCount)
__attribute__((__availability__(ohos, introduced=24.0.0)));

/**
 * @brief Obtain the 16 elements of the matrix and fill them into the array pointed to by result.
 *        The array pointed to by result must have space for 16 float elements.
 *
 * @param matrix Pointer to the original matrix4 object.
 * @param result Pointer to an array that can hold 16 floating-point numbers. It must not be null.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
 * @since 24
 */
ArkUI_ErrorCode OH_ArkUI_Matrix4_GetElements(const ArkUI_Matrix4* matrix, float* result)
__attribute__((__availability__(ohos, introduced=24.0.0)));
#ifdef __cplusplus
};
#endif

#endif // ARKUI_NATIVE_TYPE_H
/** @} */
