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
 * @addtogroup OH_CommonEvent
 * @{
 *
 * @brief Provides the APIs of common event service.
 *
 * @since 12
 */
/**
 * @file oh_commonevent_support.h
 *
 * @brief Declares the constants of system-defined common event.
 *
 * @library libohcommonevent.so
 * @kit BasicServicesKit
 * @syscap SystemCapability.Notification.CommonEvent
 * @since 12
 * @version 1.0
 */

#ifndef OH_COMMONEVENT_SUPPORT_H
#define OH_COMMONEVENT_SUPPORT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief This commonEvent means when the device is shutting down, note: turn off, not sleeping.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_SHUTDOWN = "usual.event.SHUTDOWN";

/**
 * @brief This commonEvent means when the charging state, level and so on about the battery.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_BATTERY_CHANGED = "usual.event.BATTERY_CHANGED";

/**
 * @brief This commonEvent means when the device in low battery state..
 *
 * @since 12
 */
static const char* const COMMON_EVENT_BATTERY_LOW = "usual.event.BATTERY_LOW";

/**
 * @brief This commonEvent means when the battery level is an ok state.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_BATTERY_OKAY = "usual.event.BATTERY_OKAY";

/**
 * @brief This commonEvent means when the other power is connected to the device.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_POWER_CONNECTED = "usual.event.POWER_CONNECTED";

/**
 * @brief This commonEvent means when the other power is removed from the device.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_POWER_DISCONNECTED = "usual.event.POWER_DISCONNECTED";

/**
 * @brief This commonEvent means when the screen is turned off.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_SCREEN_OFF = "usual.event.SCREEN_OFF";

/**
 * @brief This commonEvent means when the device is awakened and interactive.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_SCREEN_ON = "usual.event.SCREEN_ON";

/**
 * @brief This commonEvent means when the thermal state level change
 *
 * @since 12
 */
static const char* const COMMON_EVENT_THERMAL_LEVEL_CHANGED = "usual.event.THERMAL_LEVEL_CHANGED";

/**
 * @brief This commonEvent means when the current time is changed.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_TIME_TICK = "usual.event.TIME_TICK";

/**
 * @brief This commonEvent means when the time is set.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_TIME_CHANGED = "usual.event.TIME_CHANGED";

/**
 * @brief This commonEvent means when the time zone is changed.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_TIMEZONE_CHANGED = "usual.event.TIMEZONE_CHANGED";

/**
 * @brief This commonEvent means when a new application package is installed on the device.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_PACKAGE_ADDED = "usual.event.PACKAGE_ADDED";

/**
 * @brief This commonEvent means when an existing application package is removed from the device.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_PACKAGE_REMOVED = "usual.event.PACKAGE_REMOVED";

/**
 * @brief This commonEvent means when an existing application package is removed from the device.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_BUNDLE_REMOVED = "usual.event.BUNDLE_REMOVED";

/**
 * @brief This commonEvent means when an existing application package is completely removed from the device.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_PACKAGE_FULLY_REMOVED = "usual.event.PACKAGE_FULLY_REMOVED";

/**
 * @brief This commonEvent means when an existing application package has been changed.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_PACKAGE_CHANGED = "usual.event.PACKAGE_CHANGED";

/**
 * @brief This commonEvent means the user has restarted a package, and all of its processes have been killed.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_PACKAGE_RESTARTED = "usual.event.PACKAGE_RESTARTED";

/**
 * @brief This commonEvent means the user has cleared the package data.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_PACKAGE_DATA_CLEARED = "usual.event.PACKAGE_DATA_CLEARED";

/**
 * @brief This commonEvent means the user has cleared the package cache.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_PACKAGE_CACHE_CLEARED = "usual.event.PACKAGE_CACHE_CLEARED";

/**
 * @brief This commonEvent means the packages have been suspended.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_PACKAGES_SUSPENDED = "usual.event.PACKAGES_SUSPENDED";

/**
 * @brief This commonEvent Sent to a package that has been suspended by the system.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_MY_PACKAGE_SUSPENDED = "usual.event.MY_PACKAGE_SUSPENDED";

/**
 * @brief Sent to a package that has been un-suspended.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_MY_PACKAGE_UNSUSPENDED = "usual.event.MY_PACKAGE_UNSUSPENDED";

/**
 * @brief The current device's locale has changed.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_LOCALE_CHANGED = "usual.event.LOCALE_CHANGED";

/**
 * @brief Indicates low memory condition notification acknowledged by user and package
 * management should be started.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_MANAGE_PACKAGE_STORAGE = "usual.event.MANAGE_PACKAGE_STORAGE";

/**
 * @brief Remind new user of that the service has been unlocked.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_USER_UNLOCKED = "usual.event.USER_UNLOCKED";

/**
 * @brief Distributed account logout successfully.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOUT = "common.event.DISTRIBUTED_ACCOUNT_LOGOUT";

/**
 * @brief Distributed account is invalid.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_DISTRIBUTED_ACCOUNT_TOKEN_INVALID =
    "common.event.DISTRIBUTED_ACCOUNT_TOKEN_INVALID";

/**
 * @brief Distributed account logs off.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOFF = "common.event.DISTRIBUTED_ACCOUNT_LOGOFF";

/**
 * @brief WIFI state.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_WIFI_POWER_STATE = "usual.event.wifi.POWER_STATE";

/**
 * @brief WIFI scan results.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_WIFI_SCAN_FINISHED = "usual.event.wifi.SCAN_FINISHED";

/**
 * @brief WIFI RSSI change.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_WIFI_RSSI_VALUE = "usual.event.wifi.RSSI_VALUE";

/**
 * @brief WIFI connect state.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_WIFI_CONN_STATE = "usual.event.wifi.CONN_STATE";

/**
 * @brief WIFI hotspot state.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_WIFI_HOTSPOT_STATE = "usual.event.wifi.HOTSPOT_STATE";

/**
 * @brief WIFI ap sta join.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_WIFI_AP_STA_JOIN = "usual.event.wifi.WIFI_HS_STA_JOIN";

/**
 * @brief WIFI ap sta join.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_WIFI_AP_STA_LEAVE = "usual.event.wifi.WIFI_HS_STA_LEAVE";

/**
 * @brief Indicates Wi-Fi MpLink state notification acknowledged by binding or unbinding MpLink.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE = "usual.event.wifi.mplink.STATE_CHANGE";

/**
 * @brief Indicates Wi-Fi P2P connection state notification acknowledged by connecting or disconnected P2P.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_WIFI_P2P_CONN_STATE = "usual.event.wifi.p2p.CONN_STATE_CHANGE";

/**
 * @brief Indicates that the Wi-Fi P2P state change.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_WIFI_P2P_STATE_CHANGED = "usual.event.wifi.p2p.STATE_CHANGE";

/**
 * @brief Indicates that the Wi-Fi P2P peers state change.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED = "usual.event.wifi.p2p.DEVICES_CHANGE";

/**
 * @brief Indicates that the Wi-Fi P2P discovery state change.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED =
    "usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE";

/**
 * @brief Indicates that the Wi-Fi P2P current device state change.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED =
    "usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE";

/**
 * @brief Indicates that the Wi-Fi P2P group info is changed.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED = "usual.event.wifi.p2p.GROUP_STATE_CHANGED";

/**
 * @brief Nfc state change.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED = "usual.event.nfc.action.ADAPTER_STATE_CHANGED";

/**
 * @brief Nfc field on detected.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED = "usual.event.nfc.action.RF_FIELD_ON_DETECTED";

/**
 * @brief Nfc field off detected.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED = "usual.event.nfc.action.RF_FIELD_OFF_DETECTED";

/**
 * @brief Sent when stop charging battery.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_DISCHARGING = "usual.event.DISCHARGING";

/**
 * @brief Sent when start charging battery.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_CHARGING = "usual.event.CHARGING";

/**
 * @brief Sent when device's idle mode changed
 *
 * @since 12
 */
static const char* const COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED = "usual.event.DEVICE_IDLE_MODE_CHANGED";

/**
 * @brief Sent when device's charge idle mode changed.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_CHARGE_IDLE_MODE_CHANGED = "usual.event.CHARGE_IDLE_MODE_CHANGED";

/**
 * @brief Sent when device's power save mode changed
 *
 * @since 12
 */
static const char* const COMMON_EVENT_POWER_SAVE_MODE_CHANGED = "usual.event.POWER_SAVE_MODE_CHANGED";

/**
 * @brief The usb state change events.
 * This is a protected common event that can only be sent by system.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_USB_STATE = "usual.event.hardware.usb.action.USB_STATE";

/**
 * @brief The usb port changed.
 * This is a protected common event that can only be sent by system.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_USB_PORT_CHANGED = "usual.event.hardware.usb.action.USB_PORT_CHANGED";

/**
 * @brief The usb device attached.
 * This is a protected common event that can only be sent by system.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_USB_DEVICE_ATTACHED = "usual.event.hardware.usb.action.USB_DEVICE_ATTACHED";

/**
 * @brief The usb device detached.
 * This is a protected common event that can only be sent by system.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_USB_DEVICE_DETACHED = "usual.event.hardware.usb.action.USB_DEVICE_DETACHED";

/**
 * @brief Indicates the common event Action indicating that the airplane mode status of the device changes.
 * Users can register this event to listen to the change of the airplane mode status of the device.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_AIRPLANE_MODE_CHANGED = "usual.event.AIRPLANE_MODE";

/**
 * @brief sent by the window manager service when the window mode is split.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_SPLIT_SCREEN = "common.event.SPLIT_SCREEN";

/**
 * @brief Indicate the result of quick fix apply.
 * This common event can be triggered only by system.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_QUICK_FIX_APPLY_RESULT = "usual.event.QUICK_FIX_APPLY_RESULT";

/**
 * @brief Indicate the result of quick fix revoke.
 * This common event can be triggered only by system.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_QUICK_FIX_REVOKE_RESULT = "usual.event.QUICK_FIX_REVOKE_RESULT";

/**
 * @brief Indicate the action of a common event that the user information has been updated.
 * This common event can be triggered only by system.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_USER_INFO_UPDATED = "usual.event.USER_INFO_UPDATED";

/**
 * @brief Indicates the action of a common event that the phone SIM card state has changed.
 * This is a protected common event that can only be sent by system.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_SIM_STATE_CHANGED = "usual.event.SIM_STATE_CHANGED";

/**
 * @brief Indicates the action of a common event that the call state has been changed.
 * To subscribe to this protected common event, your application must have the ohos.permission.GET_TELEPHONY_STATE
 * permission.
 * This is a protected common event that can only be sent by system.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_CALL_STATE_CHANGED = "usual.event.CALL_STATE_CHANGED";

/**
 * @brief Indicates the action of a common event that the network state has been changed.
 * This is a protected common event that can only be sent by system.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_NETWORK_STATE_CHANGED = "usual.event.NETWORK_STATE_CHANGED";

/**
 * @brief Indicates the action of a common event that the signal info has been changed.
 * This is a protected common event that can only be sent by system.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_SIGNAL_INFO_CHANGED = "usual.event.SIGNAL_INFO_CHANGED";

/**
 * @brief This commonEvent means when the screen is unlocked.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_SCREEN_UNLOCKED = "usual.event.SCREEN_UNLOCKED";

/**
 * @brief This commonEvent means when the screen is locked.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_SCREEN_LOCKED = "usual.event.SCREEN_LOCKED";

/**
 * @brief This commonEvent means when the http proxy change.
 *
 * This is a protected common event that can only be sent by system.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_HTTP_PROXY_CHANGE = "usual.event.HTTP_PROXY_CHANGE";

/**
 * @brief This commonEvent means when the network connectivityy change.
 *
 * This is a protected common event that can only be sent by system.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_CONNECTIVITY_CHANGE = "usual.event.CONNECTIVITY_CHANGE";

/**
 * @brief This common event means that minors mode is enabled.
 * This is a protected common event that can only be sent by system.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_MINORSMODE_ON = "usual.event.MINORSMODE_ON";

/**
 * @brief This common event means that minors mode is disabled.
 * This is a protected common event that can only be sent by system.
 *
 * @since 12
 */
static const char* const COMMON_EVENT_MINORSMODE_OFF = "usual.event.MINORSMODE_OFF";
#ifdef __cplusplus
}
#endif
#endif // OH_COMMONEVENT_SUPPORT_H
/** @} */
