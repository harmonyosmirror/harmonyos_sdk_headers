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
 * @addtogroup RemoteCommunication
 * @{
 *
 * @brief Provides interfaces related to the remote communication capability.
 *
 * Support http session capability temporarily.
 *
 * @since 5.0.0(12)
 */

/**
 * @file rcp.h
 * @kit RemoteCommunicationKit
 * @brief Declare the API used to access remote communication. Provides basic functions, structures and const
 * definitions
 *
 * @library librcp_c.so
 * @syscap SystemCapability.Collaboration.RemoteCommunication
 * @since 5.0.0(12)
 */
#ifndef NDK_INCLUDE_RCP_H
#define NDK_INCLUDE_RCP_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Max length of request id
 * @since 5.0.0(12)
 */
#define RCP_MAX_REQUEST_ID_LEN 32
/**
 * @brief Max length of content type
 * @since 5.0.0(12)
 */
#define RCP_MAX_CONTENT_TYPE_LEN 64
/**
 * @brief Max length of file name
 * @since 5.0.0(12)
 */
#define RCP_MAX_FILENAME_LEN 128
/**
 * @brief Max length of path
 * @since 5.0.0(12)
 */
#define RCP_MAX_PATH_LEN 128

/**
 * @brief HTTP get method
 * @since 5.0.0(12)
 */
#define RCP_METHOD_GET "GET"
/**
 * @brief HTTP head method
 * @since 5.0.0(12)
 */
#define RCP_METHOD_HEAD "HEAD"
/**
 * @brief HTTP options method
 * @since 5.0.0(12)
 */
#define RCP_METHOD_OPTIONS "OPTIONS"
/**
 * @brief HTTP trace method
 * @since 5.0.0(12)
 */
#define RCP_METHOD_TRACE "TRACE"
/**
 * @brief HTTP delete method
 * @since 5.0.0(12)
 */
#define RCP_METHOD_DELETE "DELETE"
/**
 * @brief HTTP post method
 * @since 5.0.0(12)
 */
#define RCP_METHOD_POST "POST"
/**
 * @brief HTTP put method
 * @since 5.0.0(12)
 */
#define RCP_METHOD_PUT "PUT"
/**
 * @brief HTTP patch method
 * @since 5.0.0(12)
 */
#define RCP_METHOD_PATCH "PATCH"

/**
 * @brief Form value type
 * @since 5.0.0(12)
 */
typedef enum Rcp_FormValueType {
    /** Indicates the INT32 data type. */
    RCP_FORM_VALUE_TYPE_INT32,
    /** Indicates the INT64 data type. */
    RCP_FORM_VALUE_TYPE_INT64,
    /** Indicates the bool data type. */
    RCP_FORM_VALUE_TYPE_BOOL,
    /** Indicates the string data type. */
    RCP_FORM_VALUE_TYPE_STRING,
    /** Indicates the double data type. */
    RCP_FORM_VALUE_TYPE_DOUBLE,
} Rcp_FormValueType;

/**
 * @brief The callback signature which maybe used in {@link Rcp_FormFieldFileValue.contentOrPathOrCb} and
 * {@link Rcp_RequestContent}. This callback is called when API needs next portion of the data to send to the server.
 *
 * @param out out data
 * @param size size
 * @return Returns -1 for error, 0 to stop transfer
 * @since 5.0.0(12)
 */
typedef int (*Rcp_GetDataCallback)(char *out, uint32_t size);

/**
 * @brief Content or path or type of callback. Used to distinguish the data used in {@link Rcp_ContentOrPathOrCallback}.
 * @since 5.0.0(12)
 */
typedef enum Rcp_ContentOrPathOrCallbackType {
    /** Indicates the content type. */
    RCP_FILE_VALUE_TYPE_CONTENT,
    /** Indicates the path type. */
    RCP_FILE_VALUE_TYPE_PATH,
    /** Indicates the callback type. */
    RCP_FILE_VALUE_TYPE_CALLBACK,
} Rcp_ContentOrPathOrCallbackType;

/**
 * @brief Buffer
 * @since 5.0.0(12)
 */
typedef struct Rcp_Buffer {
    /** Content. Buffer will not be copied. */
    const char *buffer;
    /** Buffer length */
    uint32_t length;
} Rcp_Buffer;

/**
 * @brief Simple form data field values used in {@link Rcp_FormFieldFileValue}
 * @since 5.0.0(12)
 */
typedef struct Rcp_ContentOrPathOrCallback {
    /** Data type. */
    Rcp_ContentOrPathOrCallbackType type;
    union {
        /** Buffer */
        Rcp_Buffer content;
        /** Path */
        char path[RCP_MAX_PATH_LEN];
        /** Callback */
        Rcp_GetDataCallback callback;
    } data;
} Rcp_ContentOrPathOrCallback;

/**
 * @brief Multi-part value type. Used to distinguish the data used in {@link Rcp_MultipartFormFieldValue}.
 * @since 5.0.0(12)
 */
typedef enum Rcp_MultipartValueType {
    /** Indicates that {@link Rcp_FormFieldValue} is used. */
    RCP_TYPE_FORM_FIELD_VALUE,
    /** Indicates that {@link Rcp_FormFieldFileValue} is used. */
    RCP_TYPE_FORM_FIELD_FILE_VALUE,
} Rcp_MultipartValueType;

/**
 * @brief Form field file value.
 * @since 5.0.0(12)
 */
typedef struct Rcp_FormFieldFileValue {
    /** Multi-part form data content type. */
    char contentType[RCP_MAX_CONTENT_TYPE_LEN];
    /** Multi-part form data remote file name. */
    char remoteFileName[RCP_MAX_FILENAME_LEN];
    /** Multi-part form data content. */
    Rcp_ContentOrPathOrCallback contentOrPathOrCb;
} Rcp_FormFieldFileValue;

/**
 * @brief Simple form data field value, see {@link Rcp_Form} and {@link Rcp_MultipartFormFieldValue}.
 * @since 5.0.0(12)
 */
typedef struct Rcp_FormFieldValue {
    /** Indicates the data type used in union. */
    Rcp_FormValueType type;
    union {
        /** bool */
        uint8_t varBool;
        /** int32 */
        int32_t varInt32;
        /** int64 */
        int64_t varInt64;
        /** double */
        double varDouble;
        /** string */
        Rcp_Buffer varStr;
    } data;
    struct Rcp_FormFieldValue *next;
} Rcp_FormFieldValue;

/**
 * @brief Multipart form filed value，used in {@link Rcp_MultipartForm}.
 * @since 5.0.0(12)
 */
typedef struct Rcp_MultipartFormFieldValue {
    /** Indicates the data type used in union. */
    Rcp_MultipartValueType type;
    union {
        /** Simple form data field value */
        Rcp_FormFieldValue formValue;
        /** Simple form data field file value */
        Rcp_FormFieldFileValue formFileValue;
    } data;
    /** Point to the next {@link Rcp_MultipartFormFieldValue} */
    struct Rcp_MultipartFormFieldValue *next;
} Rcp_MultipartFormFieldValue;

/**
 * @brief Content type. Used to distinguish the data used in {@link Rcp_RequestContent}.
 * @since 5.0.0(12)
 */
typedef enum Rcp_ContentType {
    /** String */
    RCP_CONTENT_TYPE_STRING,
    /** Form */
    RCP_CONTENT_TYPE_FORM,
    /** Multipart form */
    RCP_CONTENT_TYPE_MULTIPARTFORM,
    /** Callback */
    RCP_CONTENT_TYPE_GETCALLBACK,
} Rcp_ContentType;

/**
 * @brief Simple form.
 * @since 5.0.0(12)
 */
typedef struct Rcp_Form Rcp_Form;
/**
 * @brief Multi-part form.
 * @since 5.0.0(12)
 */
typedef struct Rcp_MultipartForm Rcp_MultipartForm;

/**
 * @brief Request content.
 * @since 5.0.0(12)
 */
typedef struct Rcp_RequestContent {
    /** Indicates the data type used in union. */
    Rcp_ContentType type;
    union {
        /** String content */
        Rcp_Buffer contentStr;
        /** Form content */
        Rcp_Form *form;
        /** Multi-part form content. Map<String, Rcp_FormFieldValue> */
        Rcp_MultipartForm *multipartForm;
        /** Callback */
        Rcp_GetDataCallback getDataCallback;
    } data;
} Rcp_RequestContent;

/**
 * @brief Creates a form.
 *
 * @return Rcp_Form* Pointer to {@link Rcp_Form}.
 * @since 5.0.0(12)
 */
Rcp_Form *HMS_Rcp_CreateForm(void);
/**
 * @brief Destroys a form.
 *
 * @param form A Form to be destroyed. Pointer to {@link Rcp_Form}.
 * @since 5.0.0(12)
 */
void HMS_Rcp_DestroyForm(Rcp_Form *form);
/**
 * @brief Sets the key-value pair of the form.
 *
 * @param form Pointer to {@link Rcp_Form}
 * @param key Key.
 * @param value Value.
 * @return uint32_t 0 - success. 401 - Parameter error. 1007900027 - Out of memory.
 * @since 5.0.0(12)
 */
uint32_t HMS_Rcp_SetFormValue(Rcp_Form *form, const char *key, const Rcp_FormFieldValue *value);
/**
 * @brief Obtains the value of a form by key.
 *
 * @param form Pointer to {@link Rcp_Form}.
 * @param key Key.
 * @return Rcp_FormFieldValue* Value. Pointer to {@link Rcp_FormFieldValue}.
 * @since 5.0.0(12)
 */
Rcp_FormFieldValue *HMS_Rcp_GetFormValue(Rcp_Form *form, const char *key);

/**
 * @brief Creates a multi-part form.
 *
 * @return Rcp_MultipartForm* Pointer to {@link Rcp_MultipartForm}.
 * @since 5.0.0(12)
 */
Rcp_MultipartForm *HMS_Rcp_CreateMultipartForm(void);
/**
 * @brief Destroys a multi-part form.
 *
 * @param multipartForm A multi-part form to be destroyed. Pointer to {@link Rcp_MultipartForm}.
 * @since 5.0.0(12)
 */
void HMS_Rcp_DestroyMultipartForm(Rcp_MultipartForm *multipartForm);
/**
 * @brief Sets the Key-Value pairs for a multi-part Form.
 *
 * @param multipartForm Pointer to {@link Rcp_MultipartForm}.
 * @param key Key.
 * @param value Value.
 * @return uint32_t 0 - success. 401 - Parameter error. 1007900027 - Out of memory.
 * @since 5.0.0(12)
 */
uint32_t HMS_Rcp_SetMultipartFormValue(Rcp_MultipartForm *multipartForm, const char *key,
                                       const Rcp_MultipartFormFieldValue *value);
/**
 * @brief Obtains the key-value pair of a multi-part form through the key.
 *
 * @param multipartForm Pointer to {@link Rcp_MultipartForm}.
 * @param key Key.
 * @return Rcp_MultipartFormFieldValue* Pointer to {@link Rcp_MultipartFormFieldValue}.
 * @since 5.0.0(12)
 */
Rcp_MultipartFormFieldValue *HMS_Rcp_GetMultipartFormValue(Rcp_MultipartForm *multipartForm, const char *key);

/**
 * @brief Headers of the request or response.
 * @since 5.0.0(12)
 */
typedef struct Rcp_Headers Rcp_Headers;

/**
 * @brief The value type of the header map of the request or response.
 * @since 5.0.0(12)
 */
typedef struct Rcp_HeaderValue {
    /** Value */
    char *value;
    /** Point to the next {@link Rcp_HeaderValue} */
    struct Rcp_HeaderValue *next;
} Rcp_HeaderValue;

/**
 * @brief All key-value pairs of the headers of the request or response.
 * @since 5.0.0(12)
 */
typedef struct Rcp_HeaderEntry {
    /** Key */
    char *key;
    /** Value */
    Rcp_HeaderValue *value;
    /** Points to the next key-value pair {@link Rcp_HeaderEntry} */
    struct Rcp_HeaderEntry *next;
} Rcp_HeaderEntry;

/**
 * @brief Creates headers for a request or response.
 *
 * @return Rcp_Headers* Pointer to {@link Rcp_Headers}.
 * @since 5.0.0(12)
 */
Rcp_Headers *HMS_Rcp_CreateHeaders(void);
/**
 * @brief Destroys the headers of a request or response.
 *
 * @param headers Pointer to the {@link Rcp_Headers} to be destroyed.
 * @since 5.0.0(12)
 */
void HMS_Rcp_DestroyHeaders(Rcp_Headers *headers);
/**
 * @brief Sets the key-value pair of the request or response header.
 *
 * @param headers Pointer to the {@link Rcp_Headers} to be set.
 * @param name Key.
 * @param value Value.
 * @return uint32_t 0 - success. 401 - Parameter error. 1007900027 - Out of memory.
 * @since 5.0.0(12)
 */
uint32_t HMS_Rcp_SetHeaderValue(Rcp_Headers *headers, const char *name, const char *value);
/**
 * @brief Obtains the value of a request or response header by key.
 *
 * @param headers Pointer to {@link Rcp_Headers}.
 * @param name Key.
 * @return Rcp_HeaderValue* Pointer to the obtained {@link Rcp_HeaderValue}.
 * @since 5.0.0(12)
 */
Rcp_HeaderValue *HMS_Rcp_GetHeaderValue(Rcp_Headers *headers, const char *name);
/**
 * @brief Obtains all the key-value pairs of a request or response header.
 *
 * @param headers Pointer to {@link Rcp_Headers}.
 * @return Rcp_HeaderEntry* Pointers to all obtained key-value pairs {@link Rcp_HeaderEntry}.
 * @since 5.0.0(12)
 */
Rcp_HeaderEntry *HMS_Rcp_GetHeaderEntries(Rcp_Headers *headers);
/**
 * @brief Destroys all key-value pairs obtained in {@link HMS_Rcp_GetHeaderEntries}.
 *
 * @param headerEntry Pointer to the {@link Rcp_HeaderEntry} to be destroyed.
 * @since 5.0.0(12)
 */
void HMS_Rcp_DestroyHeaderEntries(Rcp_HeaderEntry *headerEntry);

/**
 * @brief Maximum length of an IP address.
 * @since 5.0.0(12)
 */
#define RCP_IP_MAX_LEN 40

/**
 * @brief Maximum length of a host name.
 * @since 5.0.0(12)
 */
#define RCP_HOST_MAX_LEN 256

/**
 * @brief Enumeration type. Authentication type for the server. If not set, negotiate with the server.
 * @since 5.0.0(12)
 */
typedef enum Rcp_AuthenticationType {
    /** Auto */
    RCP_AUTHENTICATION_AUTO,
    /** Basic */
    RCP_AUTHENTICATION_BASIC,
    /** NTLM */
    RCP_AUTHENTICATION_NTLM,
    /** DIGEST */
    RCP_AUTHENTICATION_DIGEST,
} Rcp_AuthenticationType;

/**
 * @brief Credentials. Some servers or proxy servers require this.
 * @since 5.0.0(12)
 */
typedef struct Rcp_Credential {
    /** The username of the credential. The default value is "". */
    char *username;
    /** The password for the credential. The default value is "". */
    char *password;
} Rcp_Credential;

/**
 * @brief Server authentication.
 * @since 5.0.0(12)
 */
typedef struct Rcp_ServerAuthentication {
    /** The credentials for the server. */
    Rcp_Credential credential;
    /** Authentication type for the server. If not set, negotiate with the server. */
    Rcp_AuthenticationType authenticationType;
} Rcp_ServerAuthentication;

/**
 * @brief Function pointer for determining whether the host uses a proxy
 * @param url Requested URL.
 * @return bool Returns whether a proxy is used.
 * @since 5.0.0(12)
 */
typedef bool (*Rcp_ExclusionFunction)(const char *url);

/**
 * @brief Urls, used to determine if the host is using a proxy.
 * @since 5.0.0(12)
 */
typedef struct Rcp_Urls {
    /** Matched url */
    const char *url;
    /** Pointer to the next {@link Rcp_Urls} */
    struct Rcp_Urls *next;
} Rcp_Urls;

/**
 * @brief Exclusion value type. Used to distinguish the data used in {@link Rcp_Exclusions}.
 * @since 5.0.0(12)
 */
typedef enum Rcp_ExclusionsValueType {
    /** Urls in {@link Rcp_Exclusions} */
    RCP_EXCLUSION_USE_URL_ARRAY,
    /** Use the callback function {@link Rcp_ExclusionFunction} in {@link Rcp_Exclusions} */
    RCP_EXCLUSION_USE_CALLBACK
} Rcp_ExclusionsValueType;

/**
 * @brief If the {@link Rcp_Request.url} matches the {@link Rcp_Exclusions} rule, the {@link Rcp_Request} will not use a
 * proxy.
 * @since 5.0.0(12)
 */
typedef struct Rcp_Exclusions {
    /** Indicates the data type used in union. */
    Rcp_ExclusionsValueType type;
    union {
        /** Urls */
        Rcp_Urls *urls;
        /** Callback */
        Rcp_ExclusionFunction exclusionFunction;
    } data;
} Rcp_Exclusions;

/**
 * @brief Client certificate type.
 * @since 5.0.0(12)
 */
typedef enum Rcp_CertType {
    /** PEM cert type */
    RCP_CERT_PEM,
    /** DER cert type */
    RCP_CERT_DER,
    /** P12 cert type */
    RCP_CERT_P12,
} Rcp_CertType;

/**
 * @brief Certificate authority(CA) which is used to verify the remote server's identification.
 * @since 5.0.0(12)
 */
typedef struct Rcp_CertificateAuthority {
    /** Certificate Authority certificates bundle used to verify the peer. It should be in PEM format. */
    char *content;
    /**
     * A path to a Certificate Authority certificates file used to verify the peer. The file should be in PEM format.
     */
    char *filePath;
    /**
     * @brief A path to the directory holding multiple CA certificates used to verify the peer.
     * The files in this directory should be PEM format.
     * The files must be named by the subject name's hash and an extension of '.0''.
     */
    char *folderPath;
} Rcp_CertificateAuthority;

/**
 * @brief Client certificate which is sent to the remote server, the the remote server will use it to verify the
 * client's identification.
 * @since 5.0.0(12)
 */
typedef struct Rcp_ClientCertificate {
    /** Client certificate content. It should be in 'PEM', 'DER' or 'P12' format. */
    char *content;
    /** A path to a client certificate. The file should be in 'PEM', 'DER' or 'P12' format. */
    char *filePath;
    /** File name of your client certificate private key. */
    char *key;
    /** Password for your client certificate private key. */
    char *keyPassword;
    /** Client certificate type. */
    Rcp_CertType type;
} Rcp_ClientCertificate;

/**
 * @brief Remote validation type. used to distinguish the CA that is validating the identity of the remote server is
 * described in {@link Rcp_SecurityConfiguration}.
 * @since 5.0.0(12)
 */
typedef enum Rcp_RemoteValidationType {
    /** System validation */
    RCP_REMOTE_VALIDATION_SYSTEM,
    /** Skip validation */
    RCP_REMOTE_VALIDATION_SKIP,
    /** CA validation */
    RCP_REMOTE_VALIDATION_CERTIFICATE_AUTHORITY
} Rcp_RemoteValidationType;

/**
 * @brief Security configuration.
 * @since 5.0.0(12)
 */
typedef struct Rcp_SecurityConfiguration {
    /** Remote authentication method Type */
    Rcp_RemoteValidationType remoteValidationType;
    /**
     * @brief Certificate authority(CA) which is used to verify the remote server's identification.
     * Default is 'system', if this field is not set, system CA will be used to verify the remote server's
     * identification.
     */
    Rcp_CertificateAuthority certificateAuthority;
    /**
     * @brief Client certificate which is sent to the remote server, the the remote server will use it to verify the
     * client's identification.
     */
    Rcp_ClientCertificate certificate;
    /** Server authentication settings. No authentication by default. */
    Rcp_ServerAuthentication serverAuthentication;
} Rcp_SecurityConfiguration;

/**
 * @brief Used to control when to create a proxy tunnel.
 * Tunnel or tunneling means that an HTTP CONNECT request is sent to the proxy, asking it to connect to a remote host on
 * a specific port number and then the traffic is just passed through the proxy. 'auto' means create tunnel for HTTPS,
 * and not to create for HTTP. 'always' means always create tunnel.
 * @since 5.0.0(12)
 */
typedef enum Rcp_ProxyTunnelMode {
    /** Auto */
    RCP_PROXY_TUNNEL_AUTO,
    /** Always */
    RCP_PROXY_TUNNEL_ALWAYS,
} Rcp_ProxyTunnelMode;

/**
 * @brief Custom proxy configuration.
 * @since 5.0.0(12)
 */
typedef struct Rcp_WebProxy {
    /** Indicates the URL of the proxy server. If you do not set port explicitly, port will be 1080. */
    const char *url;
    /** Used to control when to create a proxy tunnel. */
    Rcp_ProxyTunnelMode createTunnel;
    /**
     * @brief If {@link Rcp_Request.url} matches the rule of {@link Rcp_Exclusions}, the {@link Rcp_Request} will not
     * use proxy.
     */
    Rcp_Exclusions exclusions;
    /** The {@link Rcp_SecurityConfiguration} in proxy. */
    Rcp_SecurityConfiguration securityConfiguration;
} Rcp_WebProxy;

/**
 * @brief This interface is used in {@link Rcp_DnsServers}, indicates a DNS server address and port.
 * @since 5.0.0(12)
 */
typedef struct Rcp_IpAndPort {
    /** Indicates an IPv4 or IPv6 address. */
    char ip[RCP_IP_MAX_LEN];
    /** Indicates a port. Range: [0, 65535]. */
    uint16_t port;
} Rcp_IpAndPort;

/**
 * @brief One of the types in {@link Rcp_DnsConfiguration.dnsRules}.
 * @since 5.0.0(12)
 */
typedef struct Rcp_DnsServers {
    /** Ip and port */
    Rcp_IpAndPort ipAndPort;
    /** Pointer to the next {@link Rcp_DnsServers} */
    struct Rcp_DnsServers *next;
} Rcp_DnsServers;

/**
 * @brief Specifies the IP address group used in the static DNS rule {@link Rcp_StaticDnsRuleItem}.
 * @since 5.0.0(12)
 */
typedef struct Rcp_IpAddress {
    char ipAddress[RCP_IP_MAX_LEN];
    struct Rcp_IpAddress *next;
} Rcp_IpAddress;

/**
 * @brief Describes a single static dns rule.
 * @since 5.0.0(12)
 */
typedef struct Rcp_StaticDnsRuleItem {
    /** Indicates a hostname. */
    char host[RCP_HOST_MAX_LEN];
    /** Indicates a port. Range: [0, 65535]. */
    uint16_t port;
    /** Indicates the IP addresses corresponding to the {@link Rcp_StaticDnsRuleItem.host}. */
    Rcp_IpAddress *ipAddresses;
} Rcp_StaticDnsRuleItem;

/**
 * @brief One of the types in {@link Rcp_DnsConfiguration.dnsRules}.
 * @since 5.0.0(12)
 */
typedef struct Rcp_StaticDnsRule {
    /** Single static dns rule */
    Rcp_StaticDnsRuleItem staticDnsRule;
    /** Pointer to the next {@link Rcp_StaticDnsRule} */
    struct Rcp_StaticDnsRule *next;
} Rcp_StaticDnsRule;

/**
 * @brief A function that can directly return IP addresses based on hostname and port. Used for dynamic DNS resolution.
 * @param host Host name.
 * @param port Port.
 * @return Rcp_IpAddress* Pointer to {@link Rcp_IpAddress}. IP addresses based on hostname and port.
 * @since 5.0.0(12)
 */
typedef Rcp_IpAddress *(*Rcp_DynamicDnsRuleFunction)(const char *host, uint16_t port);

/**
 * @brief Dns rule type. Used to distinguish the type of dns rule used in {@link Rcp_DnsRule}.
 *
 * @since 5.0.0(12)
 */
typedef enum Rcp_DnsRuleType {
    /** Dns Servers */
    RCP_DNS_RULE_DNS_SERVERS,
    /** Static rules */
    RCP_DNS_RULE_STATIC,
    /** Dynamic dns rule */
    RCP_DNS_RULE_DYNAMIC
} Rcp_DnsRuleType;

/**
 * @brief Dns rule configuration.
 * @since 5.0.0(12)
 */
typedef struct Rcp_DnsRule {
    /** Indicates the data type used in union. */
    Rcp_DnsRuleType type;
    union {
        /** Dns servers */
        Rcp_DnsServers *dnsServers;
        /** Static dns rules */
        Rcp_StaticDnsRule *staticDnsRule;
        /** Dynamic dns rule */
        Rcp_DynamicDnsRuleFunction dynamicDnsRule;
    } data;
} Rcp_DnsRule;

/**
 * @brief Callback function that is invoked when a response body is received.
 * @param usrObject User defined object.
 * @param data Response body.
 * @return size_t the length of response body.
 * @since 5.0.0(12)
 */
typedef size_t (*Rcp_OnDataReceiveCallbackFunc)(void *usrObject, const char *data);
/**
 * @brief Callback function invoked during request/response data transmission.
 * @param usrObject User defined object.
 * @param totalSize total size
 * @param transferredSize transferred size
 * @since 5.0.0(12)
 */
typedef void (*Rcp_OnProgressCallbackFunc)(void *usrObject, uint64_t totalSize, uint64_t transferredSize);
/**
 * @brief Callback called when all requests are received.
 * @param usrObject User defined object.
 * @param headers Headers of the received requests, which points to the pointer of {@link Rcp_Headers}.
 * @since 5.0.0(12)
 */
typedef void (*Rcp_OnHeaderReceiveCallbackFunc)(void *usrObject, Rcp_Headers *headers);
/**
 * @brief Empty callback function for requested DataEnd or Canceled event callback
 * @param usrObject User defined object.
 * @since 5.0.0(12)
 */
typedef void (*Rcp_OnVoidCallbackFunc)(void *usrObject);

/**
 * @brief Callback configuration configured in {@link Rcp_EventsHandler} when data is received.
 * @since 5.0.0(12)
 */
typedef struct Rcp_OnDataReceiveCallback {
    /** Callback function for receiving data */
    Rcp_OnDataReceiveCallbackFunc callback;
    /** User-defined object, used within a callback function */
    void *usrObject;
} Rcp_OnDataReceiveCallback;

/**
 * @brief Callback configuration during receiving and sending configured in {@link Rcp_EventsHandler}.
 * @since 5.0.0(12)
 */
typedef struct Rcp_OnProgressCallback {
    /** Callback function during receiving and sending */
    Rcp_OnProgressCallbackFunc callback;
    /** User-defined object, used within a callback function */
    void *usrObject;
} Rcp_OnProgressCallback;

/**
 * @brief Callback configuration for received headers configured in {@link Rcp_EventsHandler}
 * @since 5.0.0(12)
 */
typedef struct Rcp_OnHeaderReceiveCallback {
    /** Callback function for received headers */
    Rcp_OnHeaderReceiveCallbackFunc callback;
    /** User-defined object, used within a callback function */
    void *usrObject;
} Rcp_OnHeaderReceiveCallback;

/**
 * @brief 在{@link Rcp_EventsHandler}中配置的DataEnd或Canceled事件回调配置
 * @since 5.0.0(12)
 */
typedef struct Rcp_OnVoidCallback {
    /** DataEnd or Canceled event callback function */
    Rcp_OnVoidCallbackFunc callback;
    /** User-defined object, used within a callback function */
    void *usrObject;
} Rcp_OnVoidCallback;

/**
 * @brief Callbacks to watch different events.
 * @since 5.0.0(12)
 */
typedef struct Rcp_EventsHandler {
    /** Callback function when the response body is received */
    Rcp_OnDataReceiveCallback onDataReceive;
    /** Callback function during uploading */
    Rcp_OnProgressCallback onUploadProgress;
    /** Callback function during downloading */
    Rcp_OnProgressCallback onDownloadProgress;
    /** Callback function when a header is received */
    Rcp_OnHeaderReceiveCallback onHeaderReceive;
    /** Callback function at the end of the transfer */
    Rcp_OnVoidCallback onDataEnd;
    /** Callback function when a request or session is canceled */
    Rcp_OnVoidCallback onCanceled;
} Rcp_EventsHandler;

/**
 * @brief Timeout configuration for requests
 * @since 5.0.0(12)
 */
typedef struct Rcp_Timeout {
    /** Connection timeout interval. The default value is 60000 ms. */
    uint32_t connectMs;
    /** Transmission timeout interval. The default value is 60000 ms. */
    uint32_t transferMs;
} Rcp_Timeout;

/**
 * @brief DNS configuration on HTTPS If set, the address resolved by the DOH dns server is preferred.
 * @since 5.0.0(12)
 */
typedef struct Rcp_DnsOverHttps {
    /** URL of the DOH server */
    const char *url;
    /** Whether to skip certificate verification. The default value is false. */
    bool skipCertificatesValidation;
} Rcp_DnsOverHttps;

/**
 * @brief Request path preference.
 * This is only a suggestion of the caller, and the system decides which path to use.
 * @since 5.0.0(12)
 */
typedef enum Rcp_PathPreference {
    RCP_PATH_PREFERENCE_AUTO,
    RCP_PATH_PREFERENCE_WIFI,
    RCP_PATH_PREFERENCE_CELLULAR,
} Rcp_PathPreference;

/**
 * @brief Transfer configuration.
 * @since 5.0.0(12)
 */
typedef struct Rcp_TransferConfiguration {
    /** Whether to automatically follow HTTP redirect response. True by default. */
    bool autoRedirect;
    /** Timeout configuration. If this option is not set, the default timeouts will be applied. */
    Rcp_Timeout timeout;
    /** Whether to assume that the target server supports HTTP/3. Default is false. */
    bool assumesHTTP3Capable;
    /** Request path preference. */
    Rcp_PathPreference pathPreference;
} Rcp_TransferConfiguration;

/**
 * @brief Specify which request-processing events to collect. The collected events can be examined via response object.
 * @since 5.0.0(12)
 */
typedef struct Rcp_InfoToCollect {
    /** Whether to collect unclassified textual events. Default is false. */
    bool textual;
    /** Whether to collect incoming HTTP header events. Default is false. */
    bool incomingHeader;
    /** Whether to collect outgoing HTTP header events. Default is false. */
    bool outgoingHeader;
    /** Whether to collect events about incoming HTTP data. Default is false. */
    bool incomingData;
    /** Whether to collect events about outgoing HTTP data. Default is false. */
    bool outgoingData;
    /** Whether to collect incoming SSL/TLS events. Default is false. */
    bool incomingSslData;
    /** Whether to collect outgoing SSL/TLS events. Default is false. */
    bool outgoingSslData;
} Rcp_InfoToCollect;

/**
 * @brief Tracing configuration.
 * @since 5.0.0(12)
 */
typedef struct Rcp_TracingConfiguration {
    /**
     * @brief Indicates whether to record detailed logs when a request is running. The default value is false.
     * Automatically enabled if the option in infoToCollect is set.
     */
    bool verbose;
    /** Specify which request-processing events to collect. The collected events can be examined via response object. */
    Rcp_InfoToCollect infoToCollect;
    /** Whether to collect request timing information. Default is false. */
    bool collectTimeInfo;
    /** Callbacks to watch different events. */
    Rcp_EventsHandler httpEventsHandler;
} Rcp_TracingConfiguration;

/**
 * @brief Proxy type. Used to distinguish different proxy configurations.
 * @since 5.0.0(12)
 */
typedef enum Rcp_ProxyType {
    /** System proxy */
    RCP_PROXY_SYSTEM,
    /** Use custom proxy, {@link Rcp_ProxyConfiguration.customProxy} will be parsed after selection */
    RCP_PROXY_CUSTOM,
    /** No proxy */
    RCP_PROXY_NO_PROXY,
} Rcp_ProxyType;

/**
 * @brief Proxy configuration.
 * @since 5.0.0(12)
 */
typedef struct Rcp_ProxyConfiguration {
    /** Distinguish the proxy type used by the request */
    Rcp_ProxyType proxyType;
    /** Custom proxy configuration, see {@link Rcp_WebProxy} */
    Rcp_WebProxy customProxy;
} Rcp_ProxyConfiguration;

/**
 * @brief Name resolution configuration.
 * @since 5.0.0(12)
 */
typedef struct Rcp_DnsConfiguration {
    /**
     * @brief Dns rule configuration.
     * {@link Rcp_DnsServers}: means that preferentially use the specified dns servers to resolve hostname.
     * {@link Rcp_StaticDnsRule}: means that preferentially use the specified address if hostname matches.
     * {@link Rcp_DynamicDnsRuleFunction}: means that preferentially use the address returned in the function.
     */
    Rcp_DnsRule *dnsRules;
    /** Dns over HTTPS configuration */
    Rcp_DnsOverHttps dnsOverHttps;
} Rcp_DnsConfiguration;

/**
 * @brief Request configuration.
 * @since 5.0.0(12)
 */
typedef struct Rcp_Configuration {
    /** Transfer configuration. */
    Rcp_TransferConfiguration transferConfiguration;
    /** Tracing configuration. */
    Rcp_TracingConfiguration tracingConfiguration;
    /** Proxy configuration. */
    Rcp_ProxyConfiguration proxyConfiguration;
    /** Dns configuration. */
    Rcp_DnsConfiguration dnsConfiguration;
    /** Security configuration. */
    Rcp_SecurityConfiguration securityConfiguration;
    /** Expandable Field */
    void *configurationPrivate;
} Rcp_Configuration;

/**
 * @brief HTTP transfer ranges. The setting is converted to the HTTP Range header.
 * An HTTP request with range header asks the server to send back only a portion of an HTTP response.
 * @since 5.0.0(12)
 */
typedef struct Rcp_TransferRange {
    /** Transfer start position. */
    int64_t from;
    /** Whether to start from zero */
    bool hasZeroFrom;
    /** Transfer end position. */
    int64_t to;
    /** Whether to end at zero */
    bool hasZeroTo;
    /** Point to the next {@link Rcp_TransferRange} */
    struct Rcp_TransferRange *next;
} Rcp_TransferRange;

/**
 * @brief Request cookies.
 * Allow you to specify all cookies you need in one object as follows: {'name1': 'value1', 'name2': 'value2'}.
 * @since 5.0.0(12)
 */
typedef struct Rcp_RequestCookies Rcp_RequestCookies;

/**
 * @brief Request.
 * @since 5.0.0(12)
 */
typedef struct Rcp_Request {
    /** The unique id for every single request. Generated by system. */
    char id[RCP_MAX_REQUEST_ID_LEN];
    /** Request url */
    char *url;
    /** Request method. Default is GET. */
    const char *method;
    /** Request headers. */
    Rcp_Headers *headers;
    /** Request body. */
    Rcp_RequestContent *content;
    /** Request configuration. See {@link Rcp_Configuration}. */
    Rcp_Configuration *configuration;
    /** HTTP transfer ranges. The setting is converted to the HTTP Range header. */
    Rcp_TransferRange *transferRange;
    /** Request cookies. The setting is converted to the HTTP Cookies header. */
    Rcp_RequestCookies *cookies;

    /** Expandable Field */
    void *requestPrivate;
} Rcp_Request;

/**
 * @brief Describes all cookie key-value pairs of the request.
 * @since 5.0.0(12)
 */
typedef struct Rcp_RequestCookieEntry {
    /** Key */
    char *key;
    /** Value */
    char *value;
    /** Pointer to the next {@link Rcp_RequestCookieEntry} */
    struct Rcp_RequestCookieEntry *next;
} Rcp_RequestCookieEntry;

/**
 * @brief Creates a request.
 * @param url Request url.
 * @return Rcp_Request* Pointer to {@link Rcp_Request}.
 * @since 5.0.0(12)
 */
Rcp_Request *HMS_Rcp_CreateRequest(const char *url);

/**
 * @brief Destroys a request.
 * @param request Pointer to the {@link Rcp_Request} to be destroyed.
 * @since 5.0.0(12)
 */
void HMS_Rcp_DestroyRequest(Rcp_Request *request);

/**
 * @brief Creates empty request cookies.
 *
 * @return Pointer to the created {@link Rcp_RequestCookies}.
 * @since 5.0.0(12)
 */
Rcp_RequestCookies *HMS_Rcp_CreateRequestCookies(void);

/**
 * @brief Destroys request cookies.
 *
 * @param cookies Pointer to the {@link Rcp_RequestCookies} to be destroyed.
 * @since 5.0.0(12)
 */
void HMS_Rcp_DestroyRequestCookies(Rcp_RequestCookies *cookies);

/**
 * @brief Sets the request cookie.
 *
 * @param cookies Pointer to {@link Rcp_RequestCookies}.
 * @param name name.
 * @param value value.
 * @return uint32_t 0 - success. 401 - Parameter error. 1007900027 - Out of memory.
 * @since 5.0.0(12)
 */
uint32_t HMS_Rcp_SetRequestCookieValue(Rcp_RequestCookies *cookies, const char *name, const char *value);

/**
 * @brief Obtains the value of the request cookie by name.
 *
 * @param cookies Pointer to {@link Rcp_RequestCookies}.
 * @param name Key.
 * @return char* The value of the request cookie.
 * @since 5.0.0(12)
 */
char *HMS_Rcp_GetRequestCookieValue(Rcp_RequestCookies *cookies, const char *name);

/**
 * @brief Obtains all key-value pairs in request cookies.
 * @param cookies Pointer to {@link Rcp_RequestCookies}
 * @return Rcp_RequestCookieEntry* Pointer to {@link Rcp_RequestCookieEntry}
 * @since 5.0.0(12)
 */
Rcp_RequestCookieEntry *HMS_Rcp_GetRequestCookieEntries(Rcp_RequestCookies *cookies);

/**
 * @brief Destroys all key-value pairs related to request cookies obtained from the
 * {@link HMS_Rcp_GetRequestCookieValue}.
 * @param cookieEntry Pointer to {@link Rcp_RequestCookieEntry}.
 * @since 5.0.0(12)
 */
void HMS_Rcp_DestroyRequestCookieEntries(Rcp_RequestCookieEntry *cookieEntry);

/**
 * @brief Status code of the response to the request.
 *
 * @since 5.0.0(12)
 */
typedef enum Rcp_StatusCode {
    /** 0 */
    RCP_NONE = 0,
    /** 200 */
    RCP_OK = 200,
    /** 201 */
    RCP_CREATED,
    /** 202 */
    RCP_ACCEPTED,
    /** 203 */
    RCP_NOT_AUTHORITATIVE,
    /** 204 */
    RCP_NO_CONTENT,
    /** 205 */
    RCP_RESET,
    /** 206 */
    RCP_PARTIAL,
    /** 300 */
    RCP_MULTI_CHOICE = 300,
    /** 301 */
    RCP_MOVED_PERMANENTLY,
    /** 302 */
    RCP_MOVED_TEMPORARILY,
    /** 303 */
    RCP_SEE_OTHER,
    /** 304 */
    RCP_NOT_MODIFIED,
    /** 305 */
    RCP_USE_PROXY,
    /** 400 */
    RCP_BAD_REQUEST = 400,
    /** 401 */
    RCP_UNAUTHORIZED,
    /** 402 */
    RCP_PAYMENT_REQUIRED,
    /** 403 */
    RCP_FORBIDDEN,
    /** 404 */
    RCP_NOT_FOUND,
    /** 405 */
    RCP_BAD_METHOD,
    /** 406 */
    RCP_NOT_ACCEPTABLE,
    /** 407 */
    RCP_PROXY_AUTH,
    /** 408 */
    RCP_CLIENT_TIMEOUT,
    /** 409 */
    RCP_CONFLICT,
    /** 410 */
    RCP_GONE,
    /** 411 */
    RCP_LENGTH_REQUIRED,
    /** 412 */
    RCP_PRECON_FAILED,
    /** 413 */
    RCP_ENTITY_TOO_LARGE,
    /** 414 */
    RCP_REQ_TOO_LONG,
    /** 415 */
    RCP_UNSUPPORTED_TYPE,
    /** 500 */
    RCP_INTERNAL_ERROR = 500,
    /** 501 */
    RCP_NOT_IMPLEMENTED,
    /** 502 */
    RCP_BAD_GATEWAY,
    /** 503 */
    RCP_UNAVAILABLE,
    /** 504 */
    RCP_GATEWAY_TIMEOUT,
    /** 505 */
    RCP_VERSION,
} Rcp_StatusCode;

/**
 * @brief Describes the event type of the debugging information.
 *
 * @since 5.0.0(12)
 */
typedef enum Rcp_DebugEvent {
    /** Text event */
    RCP_DEBUG_EVENT_TEXT,
    /** Incoming header events */
    RCP_DEBUG_EVENT_HEADER_IN,
    /** Outgoing header events */
    RCP_DEBUG_EVENT_HEADER_OUT,
    /** Events about incoming data */
    RCP_DEBUG_EVENT_DATA_IN,
    /** Events about outgoing data */
    RCP_DEBUG_EVENT_DATA_OUT,
    /** Incoming SSL/TLS events */
    RCP_DEBUG_EVENT_SSL_DATA_IN,
    /** Outgoing SSL/TLS events */
    RCP_DEBUG_EVENT_SSL_DATA_OUT,
} Rcp_DebugEvent;

/**
 * @brief Describes the structure of the debugging information stored in {@link Rcp_Response}.
 *
 * @since 5.0.0(12)
 */
typedef struct Rcp_DebugInfo {
    /** Debug event type */
    Rcp_DebugEvent type;
    /** Debug info */
    Rcp_Buffer data;
    /** Point to the next {@link Rcp_DebugInfo} */
    struct Rcp_DebugInfo *next;
} Rcp_DebugInfo;

/**
 * @brief Describes the type of cookie attribute in {@link Rcp_Response}
 * @since 5.0.0(12)
 */
typedef struct Rcp_CookieAttributes Rcp_CookieAttributes;

/**
 * @brief Obtains the value of the cookie attribute by name.
 *
 * @param cookieAttributes Pointer to {@link Rcp_CookieAttributes}
 * @param name Key
 * @return char* Value in the cookie attribute
 * @since 5.0.0(12)
 */
const char *HMS_Rcp_GetResponseCookieAttrValue(Rcp_CookieAttributes *cookieAttributes, const char *name);

/**
 * @brief Response cookie attribute entry
 * @since 5.0.0(12)
 */
typedef struct Rcp_CookieAttributeEntry {
    /** key */
    const char *key;
    /** value */
    const char *value;
    /** refer to next {@link Rcp_CookieAttributeEntry} */
    struct Rcp_CookieAttributeEntry *next;
} Rcp_CookieAttributeEntry;

/**
 * @brief Get All Response CookieAttributes List in {@link Rcp_CookieAttributes}
 *
 * @param cookieAttributes Pointer refer to {@link Rcp_CookieAttributes}
 * @return {@link Rcp_CookieAttributeEntry} Response CookieAttributes List
 * @since 5.0.0(12)
 */
Rcp_CookieAttributeEntry *HMS_Rcp_GetResponseCookieAttrEntries(Rcp_CookieAttributes *cookieAttributes);

/**
 * @brief Release Response CookieAttributes List
 *
 * @param entries pointer refer to {@link Rcp_CookieAttributeEntry}
 * @since 5.0.0(12)
 */
void HMS_Rcp_DestroyResponseCookieAttrEntries(Rcp_CookieAttributeEntry *entries);

/**
 * @brief Describe response cookies in {@link Rcp_Response}.
 * @since 5.0.0(12)
 */
typedef struct Rcp_ResponseCookies {
    /** Response cookie name. */
    char *name;
    /** Response cookie value. */
    char *value;
    /** Response cookie domain attribute. */
    char *domain;
    /** Response cookie path attribute. */
    char *path;
    /** Response cookie expires attribute. */
    char *expires;
    /** Response cookie maxAge attribute. */
    uint64_t maxAge;
    /** Response cookie Secure attribute. */
    bool secure;
    /** Response cookie httpOnly attribute. */
    bool httpOnly;
    /** Response cookie sameSite attribute. */
    char *sameSite;
    /** Raw size of this response cookie. */
    uint64_t rawSize;
    /** original string */
    char *originString;
    /** All attributes in the response cookie. */
    Rcp_CookieAttributes *cookieAttributes;

    /** Pointer to the next {@link Rcp_ResponseCookies} */
    struct Rcp_ResponseCookies *next;
} Rcp_ResponseCookies;

/**
 * @brief Response timing information. It will be collected in {@link Rcp_Response.timeInfo} and
 * {@link Rcp_TracingConfiguration.collectTimeInfo} decides whether to collect it.
 * @since 5.0.0(12)
 */
typedef struct Rcp_TimeInfo {
    /** The total time in milliseconds for the HTTP transfer, including name resolving, TCP connect etc. */
    double totalTime;
    /** The time in milliseconds from the start until the remote host name was resolved. */
    double nameLookUpTime;
    /** The time in milliseconds from the start until the connection to the remote host (or proxy) was completed. */
    double connectTime;
    /** The time in milliseconds, it took from the start until the transfer is just about to begin. */
    double preTransferTime;
    /** The time in milliseconds from last modification time of the remote file. */
    double fileTime;
    /** The time in milliseconds, it took from the start until the first byte is received. */
    double startTransferTime;
    /** The time in milliseconds it took for all redirection steps including name lookup, connect, etc.*/
    double redirectTime;
    /** The time in milliseconds from the start until the TLS handshake to the remote host (or proxy) was completed. */
    double tlsHandshakeTime;
} Rcp_TimeInfo;

/**
 * @brief Response.
 * @since 5.0.0(12)
 */
typedef struct Rcp_Response Rcp_Response;

/**
 * @brief Response callback function pointer.
 *
 * @param usrCtx User Context.
 * @param response Pointer to {@link Rcp_Response}.
 * @param errCode [out] Indicates the common error codes.
 * 0 - Success.
 * 1007900001 - Unsupported protocol.
 * 1007900003 - URL using bad/illegal format or missing URL.
 * 1007900005 - Couldn't resolve proxy name.
 * 1007900006 - Couldn't resolve host name.
 * 1007900007 - Couldn't connect to server.
 * 1007900008 - Weird server reply.
 * 1007900009 - Access denied to remote resource.
 * 1007900016 - Error in the HTTP2 framing layer.
 * 1007900018 - Transferred a partial file.
 * 1007900025 - Upload failed.
 * 1007900026 - Failed to open/read local data from file/application.
 * 1007900027 - Out of memory.
 * 1007900028 - Timeout was reached.
 * 1007900047 - Number of redirects hit maximum amount.
 * 1007900052 - Server returned nothing (no headers, no data).
 * 1007900055 - Failed sending data to the peer.
 * 1007900056 - Failure when receiving data from the peer.
 * 1007900058 - Problem with the local SSL certificate.
 * 1007900059 - Couldn't use specified SSL cipher.
 * 1007900060 - SSL peer certificate or SSH remote key was not OK.
 * 1007900061 - Unrecognized or bad HTTP Content or Transfer-Encoding.
 * 1007900063 - Maximum file size exceeded.
 * 1007900070 - Disk full or allocation exceeded.
 * 1007900073 - Remote file already exists.
 * 1007900077 - Problem with the SSL CA cert (path? access rights?).
 * 1007900078 - Remote file not found.
 * 1007900992 - Request is canceled.
 * 1007900993 - Session is closed or invalid.
 * 1007900094 - An authentication function returned an error.
 * 1007900995 - Get system proxy failed.
 * 1007900996 - Proxy type not supported.
 * 1007900997 - Invalid content type.
 * 1007900998 - Method not supported.
 * 1007900999 - Internal Error.
 * Others - 1007900000 + CURL_ERROR_CODE. For more common error codes, see curl error codes.
 * @since 5.0.0(12)
 */
typedef void (*Rcp_ResponseCallback)(void *usrCtx, Rcp_Response *response, uint32_t errCode);

/**
 * @brief Response callback structure
 * @since 5.0.0(12)
 */
typedef struct Rcp_ResponseCallbackObject {
    /** Response callback function */
    Rcp_ResponseCallback callback;
    /** User Context */
    void *usrCtx;
} Rcp_ResponseCallbackObject;

/**
 * @brief Response.
 * @since 5.0.0(12)
 */
struct Rcp_Response {
    /** Indicates the request that generated the response */
    const Rcp_Request *request;
    /**
     * @brief Last used valid URL
     * Effective url may not be equal to {@link Rcp_Request.url} if redirected, or if
     * {@link Rcp_SessionConfiguration.baseUrl} is set.
     */
    char *effectiveUrl;
    /** Response status code */
    Rcp_StatusCode statusCode;
    /** Response headers */
    Rcp_Headers *headers;
    /** Response body */
    Rcp_Buffer body;
    /**
     * @brief Request/Response processing debug information.
     * The events that are collected depend on the {@link Rcp_TracingConfiguration} configuration information
     */
    Rcp_DebugInfo *debugInfo;
    /**
     * @brief Response time information.
     * Whether to collect this information depends on the configuration information in the
     * {@link Rcp_TracingConfiguration.collectTimeInfo} file.
     */
    Rcp_TimeInfo *timeInfo;
    /** The response cookies */
    Rcp_ResponseCookies *cookies;
    /** Response callback */
    const Rcp_ResponseCallbackObject *responseCallback;

    /**
     * @brief Response deletion function
     * @param response Indicates the response to be deleted. It is a pointer that points to {@link Rcp_Response}.
     * @since 5.0.0(12)
     */
    void (*destroyResponse)(struct Rcp_Response *response);

    /** Expandable Field */
    void *responsePrivate;
};

/**
 * @brief Async handler associated with {@link Rcp_Interceptor}
 * @since 5.0.0(12)
 */
typedef struct Rcp_RequestHandler Rcp_RequestHandler;

/**
 * @brief Sync handler associated with {@link Rcp_SyncInterceptor}
 * @since 5.0.0(12)
 */
typedef struct Rcp_SyncRequestHandler Rcp_SyncRequestHandler;

/**
 * @brief Async Interceptor
 * @since 5.0.0(12)
 */
typedef struct Rcp_Interceptor {
    /**
     * @brief Pointer to the async interceptor function.
     *
     * @param request Pointer to {@link Rcp_Request}
     * @param next Pointer to the next async handler {@link Rcp_RequestHandler}
     * @param responseCallback Pointer to {@link Rcp_ResponseCallbackObject}.
     * @return uint32_t Indicates the return value of the interceptor.
     * @since 5.0.0(12)
     */
    uint32_t (*intercept)(Rcp_Request *request, const Rcp_RequestHandler *next,
                          const Rcp_ResponseCallbackObject *responseCallback);
} Rcp_Interceptor;

/**
 * @brief Sync Interceptor.
 * @since 5.0.0(12)
 */
typedef struct Rcp_SyncInterceptor {
    /**
     * @brief Pointer to the sync interceptor function
     * @param request Pointer to {@link Rcp_Request}
     * @param next Pointer to the next sync handler {@link Rcp_SyncRequestHandler}
     * @param errCode Indicates the return value of the interceptor.
     * @return Rcp_Response* Returns response
     * @since 5.0.0(12)
     */
    Rcp_Response *(*intercept)(Rcp_Request *request, const Rcp_SyncRequestHandler *next, uint32_t *errCode);
} Rcp_SyncInterceptor;

/**
 * @brief Async Interceptor array.
 * @since 5.0.0(12)
 */
typedef struct Rcp_InterceptorArray {
    /** Async interceptor array Rcp_Interceptor[]*/
    Rcp_Interceptor *interceptors;
    /** Size */
    int size;
} Rcp_InterceptorArray;

/**
 * @brief Sync Interceptor array.
 * @since 5.0.0(12)
 */
typedef struct Rcp_SyncInterceptorArray {
    /** Sync interceptor array Rcp_SyncInterceptor[] */
    Rcp_SyncInterceptor *interceptors;
    /** Size */
    int size;
} Rcp_SyncInterceptorArray;

/**
 * @brief The next interceptor or defaultHandler can be called in the function of the interceptor
 * {@link Rcp_Interceptor}.

 * @param request Pointer to {@link Rcp_Request}
 * @param next Pointer to the next async handler {@link Rcp_RequestHandler}
 * @param responseCallback Pointer to {@link Rcp_ResponseCallbackObject}.
 * @return uint32_t 401 - Parameter error or indicates the return value of the next RequestHandler.
 * @since 5.0.0(12)
 */
uint32_t HMS_Rcp_CallNextRequestHandler(Rcp_Request *request, const Rcp_RequestHandler *next,
                                        const Rcp_ResponseCallbackObject *responseCallback);

/**
 * @brief The next interceptor or defaultHandler can be called in the function of the interceptor
 * {@link Rcp_SyncInterceptor}.
 *
 * @param request Pointer to {@link Rcp_Request}
 * @param next Pointer to the next sync handler {@link Rcp_SyncRequestHandler}
 * @param errCode [out] 401 - Parameter error or indicates the return value of the next SyncRequestHandler.
 * @return Rcp_Response* Returns response
 * @since 5.0.0(12)
 */
Rcp_Response *HMS_Rcp_CallNextSyncRequestHandler(Rcp_Request *request, const Rcp_SyncRequestHandler *next,
                                                 uint32_t *errCode);

/**
 * @brief Session type
 * @since 5.0.0(12)
 */
typedef enum Rcp_SessionType {
    /** HTTP */
    RCP_SESSION_TYPE_HTTP = 0,
    /** MAX */
    RCP_SESSION_TYPE_MAX = 100,
} Rcp_SessionType;

/**
 * @brief Rcp session type
 * @since 5.0.0(12)
 */
typedef struct Rcp_Session Rcp_Session;

/**
 * @brief Callback function for closing or canceling a session.
 * @since 5.0.0(12)
 */
typedef struct Rcp_SessionListener {
    /** This function is called when {@link Rcp_Session} is closed. */
    void (*onClosed)(void);
    /** This function is called when {@link Rcp_Session} is canceled. */
    void (*onCanceled)(void);
} Rcp_SessionListener;

/**
 * @brief Connection configuration.
 * @since 5.0.0(12)
 */
typedef struct Rcp_ConnectionConfiguration {
    /** max connections per host */
    long maxConnectionsPerHost;
    /** max total connections */
    long maxTotalConnections;
    /** max cache connections */
    long maxCacheConnections;
} Rcp_ConnectionConfiguration;

/**
 * @brief Session configuration
 * @since 5.0.0(12)
 */
typedef struct Rcp_SessionConfiguration {
    /** Session type */
    Rcp_SessionType type;
    /**
     * User-defined async interceptor array.
     * Interceptors will be made into an interceptor chain.
     * Input: [A, B, C, D], made into A->B->C->D->defaultHandler.
     */
    Rcp_InterceptorArray interceptors;
    /**
     * User-Defined sync interceptor array.
     * SyncInterceptors will be made into an interceptor chain.
     * Input: [A, B, C, D], made into A->B->C->D->defaultHandler.
     */
    Rcp_SyncInterceptorArray syncInterceptors;
    /**
     * Base url.
     * For example, Request.url is '?name=value', baseAddress is 'https://example.com',
     * then the real URL becomes 'https://example.com?name=value' when request is sent to server.
     */
    const char *baseUrl;
    /**
     * Headers.
     * If {@link HMS_Rcp_Fetch} or {@link HMS_Rcp_FetchSync} is called, but no {@link Rcp_Headers} are in
     * {@link Rcp_Request}, {@link Rcp_SessionConfiguration.headers} will be the {@link Rcp_Request.headers}. If both
     * exist, they will be merged.
     */
    Rcp_Headers *headers;
    /**
     * Cookies.
     * If {@link HMS_Rcp_Fetch} or {@link HMS_Rcp_FetchSync} is called, but no {@link Rcp_RequestCookies} in
     * {@link Rcp_Request}, {@link Rcp_SessionConfiguration.cookies} will be the {@link Rcp_Request.cookies}. If both
     * exist, they will be merged.
     */
    Rcp_RequestCookies *cookies;
    /** Callback function for the session to listen to the close () or cancel () event */
    Rcp_SessionListener sessionListener;
    /** Default request level configuration. The options can be overridden via {@link Request.configuration}. */
    Rcp_Configuration *requestConfiguration;
    /**
     * Connection configuration.
     * It's used to specify the maximum number of simultaneous connections allowed total in this session and allowed
     * to a single host.
     */
    Rcp_ConnectionConfiguration connectionConfiguration;
} Rcp_SessionConfiguration;

/**
 * @brief Creates a session
 *
 * @param configuration Session configuration
 * @param errCode 0 - success. 401 - Parameter error. 201 - Permission denied. 1007900027 - Out of memory.
 * @return Rcp_Session* Pointer to {@link Rcp_Session}
 * @syscap SystemCapability.Collaboration.RemoteCommunication
 * @since 5.0.0(12)
 */
Rcp_Session *HMS_Rcp_CreateSession(const Rcp_SessionConfiguration *configuration, uint32_t *errCode);

/**
 * @brief Gets session id
 *
 * @param session Pointer to {@link Rcp_Session}
 * @return char* session id
 * @syscap SystemCapability.Collaboration.RemoteCommunication
 * @since 5.0.0(12)
 */
const char *HMS_Rcp_GetSessionId(Rcp_Session *session);

/**
 * @brief Gets session configuration
 *
 * @param session Pointer to {@link Rcp_Session}
 * @return Rcp_SessionConfiguration* Pointer to {@link Rcp_SessionConfiguration}
 * @syscap SystemCapability.Collaboration.RemoteCommunication
 * @since 5.0.0(12)
 */
const Rcp_SessionConfiguration *HMS_Rcp_GetSessionConfiguration(Rcp_Session *session);

/**
 * @brief Send an async request and get a response
 *
 * @param session Pointer to {@link Rcp_Session}
 * @param request Pointer to {@link Rcp_Request}
 * @param errCode [out] Indicates the common error codes.
 * 0 - success.
 * 201 - Permission denied.
 * 401 - Parameter error.
 * 1007900001 - Unsupported protocol.
 * 1007900003 - URL using bad/illegal format or missing URL.
 * 1007900005 - Couldn't resolve proxy name.
 * 1007900006 - Couldn't resolve host name.
 * 1007900007 - Couldn't connect to server.
 * 1007900008 - Weird server reply.
 * 1007900009 - Access denied to remote resource.
 * 1007900016 - Error in the HTTP2 framing layer.
 * 1007900018 - Transferred a partial file.
 * 1007900025 - Upload failed.
 * 1007900026 - Failed to open/read local data from file/application.
 * 1007900027 - Out of memory.
 * 1007900028 - Timeout was reached.
 * 1007900047 - Number of redirects hit maximum amount.
 * 1007900052 - Server returned nothing (no headers, no data).
 * 1007900055 - Failed sending data to the peer.
 * 1007900056 - Failure when receiving data from the peer.
 * 1007900058 - Problem with the local SSL certificate.
 * 1007900059 - Couldn't use specified SSL cipher.
 * 1007900060 - SSL peer certificate or SSH remote key was not OK.
 * 1007900061 - Unrecognized or bad HTTP Content or Transfer-Encoding.
 * 1007900063 - Maximum file size exceeded.
 * 1007900070 - Disk full or allocation exceeded.
 * 1007900073 - Remote file already exists.
 * 1007900077 - Problem with the SSL CA cert (path? access rights?).
 * 1007900078 - Remote file not found.
 * 1007900992 - Request is canceled.
 * 1007900993 - Session is closed or invalid.
 * 1007900094 - An authentication function returned an error.
 * 1007900995 - Get system proxy failed.
 * 1007900996 - Proxy type not supported.
 * 1007900997 - Invalid content type.
 * 1007900998 - Method not supported.
 * 1007900999 - Internal Error.
 * Others - 1007900000 + CURL_ERROR_CODE. For more common error codes, see curl error codes.
 * @return Rcp_Response* Pointer to {@link Rcp_Response}
 * @permission ohos.permission.INTERNET
 * @permission ohos.permission.GET_NETWORK_INFO If you want to use 'cellular' of {@link PathPreference}.
 * @syscap SystemCapability.Collaboration.RemoteCommunication
 * @since 5.0.0(12)
 */
Rcp_Response *HMS_Rcp_FetchSync(Rcp_Session *session, Rcp_Request *request, uint32_t *errCode);

/**
 * @brief Send a sync request and get a response
 *
 * @param session Pointer to {@link Rcp_Session}
 * @param request Pointer to {@link Rcp_Request}
 * @param responseCallback Pointer to the user-defined response callback function. For details, see
 * {@link Rcp_ResponseCallbackObject}.
 * @return uint32_t Error code. 0 - success. 201 - Permission denied. 401 - Parameter error. 1007900993 - Session is
 * closed or invalid.
 * @permission ohos.permission.INTERNET
 * @permission ohos.permission.GET_NETWORK_INFO If you want to use 'cellular' of {@link PathPreference}.
 * @syscap SystemCapability.Collaboration.RemoteCommunication
 * @since 5.0.0(12)
 */
uint32_t HMS_Rcp_Fetch(Rcp_Session *session, Rcp_Request *request, const Rcp_ResponseCallbackObject *responseCallback);

/**
 * @brief Cancels a request.
 *
 * @param session Pointer to {@link Rcp_Session}.
 * @param request Pointer to {@link Rcp_Request} to be closed.
 * @return uint32_t 0 - success. 201 - Permission denied. 401 - Parameter error. 1007900993 - Session is closed or
 * invalid.
 * @syscap SystemCapability.Collaboration.RemoteCommunication
 * @since 5.0.0(12)
 */
uint32_t HMS_Rcp_CancelRequest(Rcp_Session *session, const Rcp_Request *request);

/**
 * @brief Cancels a session.
 *
 * @param session Pointer to {@link Rcp_Session} to be closed.
 * @return uint32_t 0 - success. 201 - Permission denied. 401 - Parameter error. 1007900993 - Session is closed or
 * invalid.
 * @syscap SystemCapability.Collaboration.RemoteCommunication
 * @since 5.0.0(12)
 */
uint32_t HMS_Rcp_CancelSession(Rcp_Session *session);
/**
 * @brief Closes a session
 *
 * @param session Pointer to the {@link Rcp_Session} pointer.
 * @return uint32_t 0 - success. 201 - Permission denied. 1007900993 - Session is closed or invalid.
 * @syscap SystemCapability.Collaboration.RemoteCommunication
 * @since 5.0.0(12)
 */
uint32_t HMS_Rcp_CloseSession(Rcp_Session **session);

/**
 * @brief Callback function that is invoked when a response body is received. The callback point is the same as that of
 * {@link Rcp_OnDataReceiveCallback}.
 *
 * @param usrObject User defined object.
 * @param buffer Binary data buffer.
 * @return size_t the length of binary data.
 * @since 5.0.1(13)
 */
typedef size_t (*Rcp_OnBinaryReceiveCallbackFunc)(void *usrObject, Rcp_Buffer *buffer);

/**
 * @brief Binary data receive callback for request.
 * @since 5.0.1(13)
 */
typedef struct Rcp_OnBinaryReceiveCallback {
    /** Callback function for receiving binary data */
    Rcp_OnBinaryReceiveCallbackFunc callback;
    /** User-defined object, used within a callback function */
    void *usrObject;
} Rcp_OnBinaryReceiveCallback;

/**
 * @brief Sets the binary data receive callback for the request. This callback will replace the
 * {@link Rcp_OnDataReceiveCallback} that may have been set.
 *
 * @param request Pointer to {@link Rcp_Request} to be set.
 * @param onBinaryReceiveCallback Binary data callback function to be set
 * @return uint32_t 0 - success. 401 - Parameter error.
 * @syscap SystemCapability.Collaboration.RemoteCommunication
 * @since 5.0.1(13)
 */
uint32_t HMS_Rcp_SetRequestOnBinaryDataRecvCallback(Rcp_Request *request,
                                                    Rcp_OnBinaryReceiveCallback onBinaryReceiveCallback);

#ifdef __cplusplus
}
#endif
#endif // NDK_INCLUDE_RCP_H

/** @} */
