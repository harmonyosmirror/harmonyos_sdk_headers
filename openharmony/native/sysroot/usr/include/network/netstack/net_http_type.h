/*
 * Copyright (c) 2025 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License"),
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
 * @addtogroup netstack
 * @{
 *
 * @brief Provides C APIs for the Http client module.
 *
 * @since 20
 */

/**
 * @file net_http_type.h
 * @brief Defines the data structure for the C APIs of the http module.
 *
 * @library libnet_http.so
 * @kit NetworkKit
 * @syscap SystemCapability.Communication.NetStack
 * @since 20
 */

#ifndef NET_HTTP_TYPE_H
#define NET_HTTP_TYPE_H

#ifdef __cplusplus
extern "C" {
#endif

#define OHOS_HTTP_MAX_PATH_LEN 128
#define OHOS_HTTP_MAX_STR_LEN 256
#define OHOS_HTTP_DNS_SERVER_NUM_MAX 3

/**
 * @brief Defines http error code.
 *
 * @since 20
 */
typedef enum Http_ErrCode {
  /** Operation success. */
  OH_HTTP_RESULT_OK = 0,
  /** @brief Parameter error. */
  OH_HTTP_PARAMETER_ERROR = 401,
  /** @brief Permission denied. */
  OH_HTTP_PERMISSION_DENIED = 201,
  /** @brief Error code base. */
  OH_HTTP_NETSTACK_E_BASE = 2300000,
  /** @brief Unsupported protocol. */
  OH_HTTP_UNSUPPORTED_PROTOCOL = (OH_HTTP_NETSTACK_E_BASE + 1),
  /** @brief Invalid URL format or missing URL. */
  OH_HTTP_INVALID_URL = (OH_HTTP_NETSTACK_E_BASE + 3),
  /** @brief Failed to resolve the proxy name. */
  OH_HTTP_RESOLVE_PROXY_FAILED = (OH_HTTP_NETSTACK_E_BASE + 5),
  /** @brief Failed to resolve the host name. */
  OH_HTTP_RESOLVE_HOST_FAILED = (OH_HTTP_NETSTACK_E_BASE + 6),
  /** @brief Failed to connect to the server. */
  OH_HTTP_CONNECT_SERVER_FAILED = (OH_HTTP_NETSTACK_E_BASE + 7),
  /** @brief Invalid server response. */
  OH_HTTP_INVALID_SERVER_RESPONSE = (OH_HTTP_NETSTACK_E_BASE + 8),
  /** @brief Access to the remote resource denied. */
  OH_HTTP_ACCESS_REMOTE_DENIED = (OH_HTTP_NETSTACK_E_BASE + 9),
  /** @brief Error in the HTTP2 framing layer. */
  OH_HTTP_HTTP2_FRAMING_ERROR = (OH_HTTP_NETSTACK_E_BASE + 16),
  /** @brief Transferred a partial file. */
  OH_HTTP_TRANSFER_PARTIAL_FILE = (OH_HTTP_NETSTACK_E_BASE + 18),
  /** @brief Failed to write the received data to the disk or application. */
  OH_HTTP_WRITE_DATA_FAILED = (OH_HTTP_NETSTACK_E_BASE + 23),
  /** @brief Upload failed. */
  OH_HTTP_UPLOAD_FAILED = (OH_HTTP_NETSTACK_E_BASE + 25),
  /** @brief Failed to open or read local data from the file or application. */
  OH_HTTP_OPEN_LOCAL_DATA_FAILED = (OH_HTTP_NETSTACK_E_BASE + 26),
  /** @brief Out of memory. */
  OH_HTTP_OUT_OF_MEMORY = (OH_HTTP_NETSTACK_E_BASE + 27),
  /** @brief Operation timeout. */
  OH_HTTP_OPERATION_TIMEOUT = (OH_HTTP_NETSTACK_E_BASE + 28),
  /** @brief The number of redirections reaches the maximum allowed. */
  OH_HTTP_TOO_MANY_REDIRECTIONS = (OH_HTTP_NETSTACK_E_BASE + 47),
  /** @brief The server returned nothing (no header or data). */
  OH_HTTP_SERVER_RETURNED_NOTHING = (OH_HTTP_NETSTACK_E_BASE + 52),
  /** @brief Failed to send data to the peer. */
  OH_HTTP_SEND_DATA_FAILED = (OH_HTTP_NETSTACK_E_BASE + 55),
  /** @brief Failed to receive data from the peer. */
  OH_HTTP_RECEIVE_DATA_FAILED = (OH_HTTP_NETSTACK_E_BASE + 56),
  /** @brief Local SSL certificate error. */
  OH_HTTP_SSL_CERTIFICATE_ERROR = (OH_HTTP_NETSTACK_E_BASE + 58),
  /** @brief The specified SSL cipher cannot be used. */
  OH_HTTP_SSL_CIPHER_USED_ERROR = (OH_HTTP_NETSTACK_E_BASE + 59),
  /** @brief Invalid SSL peer certificate or SSH remote key. */
  OH_HTTP_INVALID_SSL_PEER_CERT = (OH_HTTP_NETSTACK_E_BASE + 60),
  /** @brief Invalid HTTP encoding format. */
  OH_HTTP_INVALID_ENCODING_FORMAT = (OH_HTTP_NETSTACK_E_BASE + 61),
  /** @brief Maximum file size exceeded. */
  OH_HTTP_FILE_TOO_LARGE = (OH_HTTP_NETSTACK_E_BASE + 63),
  /** @brief Remote disk full. */
  OH_HTTP_REMOTE_DISK_FULL = (OH_HTTP_NETSTACK_E_BASE + 70),
  /** @brief Remote file already exists. */
  OH_HTTP_REMOTE_FILE_EXISTS = (OH_HTTP_NETSTACK_E_BASE + 73),
  /** @brief The SSL CA certificate does not exist or is inaccessible. */
  OH_HTTP_SSL_CA_NOT_EXIST = (OH_HTTP_NETSTACK_E_BASE + 77),
  /** @brief Remote file not found. */
  OH_HTTP_REMOTE_FILE_NOT_FOUND = (OH_HTTP_NETSTACK_E_BASE + 78),
  /** @brief Authentication error. */
  OH_HTTP_AUTHENTICATION_ERROR = (OH_HTTP_NETSTACK_E_BASE + 94),
  /** @brief It is not allowed to access this domain. */
  OH_HTTP_ACCESS_DOMAIN_NOT_ALLOWED = (OH_HTTP_NETSTACK_E_BASE + 998),
  /** @brief Unknown error. */
  OH_HTTP_UNKNOWN_ERROR = (OH_HTTP_NETSTACK_E_BASE + 999)
} Http_ErrCode;

/**
 * @brief Defines http response code.
 *
 * @since 20
 */
typedef enum Http_ResponseCode {
  /** @brief The request was successful. */
  OH_HTTP_OK = 200,
  /** @brief Successfully requested and created a new resource. */
  OH_HTTP_CREATED = 201,
  /** @brief The request has been accepted but has not been processed completely. */
  OH_HTTP_ACCEPTED = 202,
  /** @brief Unauthorized information. The request was successful. */
  OH_HTTP_NON_AUTHORITATIVE_INFO = 203,
  /** @brief No content. The server successfully processed, but did not return content. */
  OH_HTTP_NO_CONTENT = 204,
  /** @brief Reset the content. */
  OH_HTTP_RESET = 205,
  /** @brief Partial content. The server successfully processed some GET requests. */
  OH_HTTP_PARTIAL = 206,
  /** @brief Multiple options. */
  OH_HTTP_MULTI_CHOICE = 300,
  /**
   * @brief Permanently move. The requested resource has been permanently moved to a new URI,
   * and the returned information will include the new URI. The browser will automatically redirect to the new URI.
   */
  OH_HTTP_MOVED_PERM = 301,
  /** @brief Temporary movement. */
  OH_HTTP_MOVED_TEMP = 302,
  /** @brief View other addresses. */
  OH_HTTP_SEE_OTHER = 303,
  /** @brief Not modified. */
  OH_HTTP_NOT_MODIFIED = 304,
  /** @brief Using proxies. */
  OH_HTTP_USE_PROXY = 305,
  /** @brief The server cannot understand the syntax error error requested by the client. */
  OH_HTTP_BAD_REQUEST = 400,
  /** @brief Request for user authentication. */
  OH_HTTP_UNAUTHORIZED = 401,
  /** @brief Reserved for future use. */
  OH_HTTP_PAYMENT_REQUIRED = 402,
  /** @brief The server understands the request from the requesting client, but refuses to execute it. */
  OH_HTTP_FORBIDDEN = 403,
  /** @brief The server was unable to find resources (web pages) based on the client's request. */
  OH_HTTP_NOT_FOUND = 404,
  /** @brief The method in the client request is prohibited. */
  OH_HTTP_BAD_METHOD = 405,
  /** @brief The server unabled to complete request based on the content characteristics requested by the client. */
  OH_HTTP_NOT_ACCEPTABLE = 406,
  /** @brief Request authentication of the proxy's identity. */
  OH_HTTP_PROXY_AUTH = 407,
  /** @brief The request took too long and timed out. */
  OH_HTTP_CLIENT_TIMEOUT = 408,
  /**
   * @brief The server may have returned this code when completing the client's PUT request,
   * as there was a conflict when the server was processing the request.
   */
  OH_HTTP_CONFLICT = 409,
  /** @brief The resource requested by the client no longer exists. */
  OH_HTTP_GONE = 410,
  /** @brief The server is unable to process request information sent by the client without Content Length. */
  OH_HTTP_LENGTH_REQUIRED = 411,
  /** @brief The prerequisite for requesting information from the client is incorrect. */
  OH_HTTP_PRECON_FAILED = 412,
  /** @brief The request was rejected because the requested entity was too large for the server to process. */
  OH_HTTP_ENTITY_TOO_LARGE = 413,
  /** @brief The requested URI is too long (usually a URL) and the server cannot process it. */
  OH_HTTP_REQUEST_TOO_LONG = 414,
  /** @brief The server is unable to process the requested format. */
  OH_HTTP_UNSUPPORTED_TYPE = 415,
  /** @brief Requested Range not satisfiable. */
  OH_HTTP_RANGE_NOT_MET = 416,
  /** @brief Internal server error, unable to complete the request. */
  OH_HTTP_INTERNAL_ERROR = 500,
  /** @brief The server does not support the requested functionality and cannot complete the request. */
  OH_HTTP_NOT_IMPLEMENTED = 501,
  /** @brief The server acting as a gateway or proxy received an invalid request from the remote server. */
  OH_HTTP_BAD_GATEWAY = 502,
  /** @brief Due to overload or system maintenance, the server is temporarily unable to process client requests. */
  OH_HTTP_UNAVAILABLE = 503,
  /** @brief The server acting as gateway did not obtain requests from the remote server in a timely manner. */
  OH_HTTP_GATEWAY_TIMEOUT = 504,
  /** @brief The version of the HTTP protocol requested by the server. */
  OH_HTTP_VERSION = 505
} Http_ResponseCode;

/**
 * @brief Buffer.
 *
 * @since 20
 */
typedef struct Http_Buffer {
  /** Content. Buffer will not be copied. */
  const char *buffer;
  /** Buffer length. */
  uint32_t length;
} Http_Buffer;

/**
 * @brief Defines the address Family.
 *
 * @since 20
 */
typedef enum Http_AddressFamilyType {
  /** Default, The system automatically selects the IPv4 or IPv6 address of the domain name. */
  HTTP_ADDRESS_FAMILY_DEFAULT = 0,
  /** IPv4, Selects the IPv4 address of the domain name. */
  HTTP_ADDRESS_FAMILY_ONLY_V4 = 1,
  /** IPv6, Selects the IPv4 address of the domain name. */
  HTTP_ADDRESS_FAMILY_ONLY_V6 = 2
} Http_AddressFamilyType;
 
/**
 * @brief HTTP get method.
 *
 * @since 20
 */
#define NET_HTTP_METHOD_GET "GET"

/**
 * @brief HTTP head method.
 *
 * @since 20
 */
#define NET_HTTPMETHOD_HEAD "HEAD"

/**
 * @brief HTTP options method.
 *
 * @since 20
 */
#define NET_HTTPMETHOD_OPTIONS "OPTIONS"

/**
 * @brief HTTP trace method.
 *
 * @since 20
 */
#define NET_HTTPMETHOD_TRACE "TRACE"
/**
 * @brief HTTP delete method.
 * @since 20
 */
#define NET_HTTPMETHOD_DELETE "DELETE"

/**
 * @brief HTTP post method.
 *
 * @since 20
 */
#define NET_HTTP_METHOD_POST "POST"

/**
 * @brief HTTP put method.
 *
 * @since 20
 */
#define NET_HTTP_METHOD_PUT "PUT"

/**
 * @brief HTTP connect method.
 *
 * @since 20
 */
#define NET_HTTP_METHOD_PATCH "CONNECT"

/**
 * @brief Defines the HTTP version.
 *
 * @since 20
 */
typedef enum Http_HttpProtocol {
  /** Default choose by curl. */
  OH_HTTP_NONE = 0,
  /** HTTP 1.1 version. */
  OH_HTTP1_1,
  /** HTTP 2 version. */
  OH_HTTP2,
  /** HTTP 3 version. */
  OH_HTTP3
} Http_HttpProtocol;

/**
 * @brief Defines the Cert Type.
 *
 * @since 20
 */
typedef enum Http_CertType {
  /** PEM Cert Type. */
  OH_HTTP_PEM = 0,
  /** DER Cert Type. */
  OH_HTTP_DER = 1,
  /** P12 Cert Type. */
  OH_HTTP_P12 = 2
} Http_CertType;

/**
 * @brief Headers of the request or response.
 *
 * @since 20
 */
typedef struct Http_Headers Http_Headers;

/**
 * @brief The value type of the header map of the request or response.
 *
 * @since 20
 */
typedef struct Http_HeaderValue {
  /** Value. */
  char *value;
  /** Point to the next {@link Http_HeaderValue}. */
  struct Http_HeaderValue *next;
} Http_HeaderValue;

/**
 * @brief All key-value pairs of the headers of the request or response.
 *
 * @since 20
 */
typedef struct Http_HeaderEntry {
  /** Key. */
  char *key;
  /** Value, see {@link Http_HeaderValue}. */
  Http_HeaderValue *value;
  /** Points to the next key-value pair {@link Http_HeaderEntry} */
  struct Http_HeaderEntry *next;
} Http_HeaderEntry;

/**
 * @brief Client certificate which is sent to the remote server, the the remote server will use it to verify the
 * client's identification.
 *
 * @since 20
 */
typedef struct Http_ClientCert {
  /** A path to a client certificate. */
  char *certPath;
  /** Client certificate type, see {@link Http_CertType}. */
  Http_CertType type;
  /** File path of your client certificate private key. */
  char *keyPath;
  /** Password for your client certificate private key. */
  char *keyPassword;
} Http_ClientCert;

/**
 * @brief Proxy type. Used to distinguish different proxy configurations.
 *
 * @since 20
 */
typedef enum Http_ProxyType {
  /** No proxy */
  HTTP_PROXY_NOT_USE,
  /** System proxy */
  HTTP_PROXY_SYSTEM,
  /** Use custom proxy */
  HTTP_PROXY_CUSTOM
} Http_ProxyType;

/**
 * @brief Custom proxy configuration.
 *
 * @since 20
 */
typedef struct Http_CustomProxy {
  /** Indicates the URL of the proxy server. If you do not set port explicitly, port will be 1080. */
  const char *host;
  int32_t port;
  const char *exclusionLists;
} Http_CustomProxy;

/**
 * @brief Proxy configuration.
 *
 * @since 20
 */
typedef struct Http_Proxy {
  /** Distinguish the proxy type used by the request, see {@link Http_ProxyType}. */
  Http_ProxyType proxyType;
  /** Custom proxy configuration, see {@link Http_CustomProxy}. */
  Http_CustomProxy customProxy;
} Http_Proxy;

/**
 * @brief Response timing information. It will be collected in {@link Http_Response.performanceTiming}.
 *
 * @since 20
 */
typedef struct Http_PerformanceTiming {
  /** The total time in milliseconds for the HTTP transfer, including name resolving, TCP connect etc. */
  double dnsTiming;
  /** The time in milliseconds from the start until the remote host name was resolved. */
  double tcpTiming;
  /** The time in milliseconds from the start until the connection to the remote host (or proxy) was completed. */
  double tlsTiming;
  /** The time in milliseconds, it took from the start until the transfer is just about to begin. */
  double firstSendTiming;
  /** The time in milliseconds from last modification time of the remote file. */
  double firstReceiveTiming;
  /** The time in milliseconds, it took from the start until the first byte is received. */
  double totalFinishTiming;
  /** The time in milliseconds it took for all redirection steps including name lookup, connect, etc.*/
  double redirectTiming;
} Http_PerformanceTiming;

/**
 * @brief Defines the parameters for http request options.
 *
 * @since 20
 */
typedef struct Http_RequestOptions {
  /** Request method. */
  const char *method;
  /** Priority of http requests. A larger value indicates a higher priority. */
  uint32_t priority;
  /** Header of http requests, see {@link Http_Headers}. */
  Http_Headers *headers;
  /** Read timeout interval. */
  uint32_t readTimeout;
  /** Connection timeout interval. */
  uint32_t connectTimeout;
  /** Use the protocol. The default value is automatically specified by the system, see {@link Http_HttpProtocol}. */
  Http_HttpProtocol httpProtocol;
  /**
   * Indicates whether to use the HTTP proxy. The default value is false,
   * and http proxy config, see {@link Http_Proxy}.
   */
  Http_Proxy *httpProxy;
  /** CA certificate of the user-specified path. */
  const char *caPath;
  /** Set the download start position. This parameter can be used only in the GET method. */
  int64_t resumeFrom;
  /** Set the download end position. This parameter can be used only in the GET method. */
  int64_t resumeTo;
  /** Client certificates can be transferred, see {@link Http_ClientCert}. */
  Http_ClientCert *clientCert;
  /** Set the DNS resolution for the https server. */
  const char *dnsOverHttps;
  /** The address family can be specified when target domain name is resolved, see {@link Http_AddressFamilyType}. */
  Http_AddressFamilyType addressFamily;
} Http_RequestOptions;

/**
 * @brief Defines the parameters for http response.
 *
 * @since 20
 */
typedef struct Http_Response {
  /** Response body, see {@link Http_Buffer}. */
  Http_Buffer body;
  /** Server status code, see {@link Http_ResponseCode}. */
  Http_ResponseCode responseCode;
  /** Header of http response, see {@link Http_Headers}. */
  Http_Headers *headers;
  /** Cookies returned by the server. */
  char *cookies;
  /** The time taken of various stages of HTTP request, see {@link Http_PerformanceTiming}. */
  Http_PerformanceTiming *performanceTiming;
  /**
   * @brief Response deletion function.
   *
   * @param response Indicates the response to be deleted. It is a pointer that points to {@link Http_Response}.
   * @since 20
   */
  void (*destroyResponse)(struct Http_Response **response);
} Http_Response;

/**
 * @brief Http request.
 *
 * @since 20
 */
typedef struct Http_Request {
  /** The request id for every single request. Generated by system. */
  uint32_t requestId;
  /** Request url. */
  char *url;
  /** Request options, see {@link Http_RequestOptions}. */
  Http_RequestOptions *options;
} Http_Request;

/**
 * @brief Callback function that is invoked when response is received.
 *
 * @param response Http response struct, see {@link Http_Response}.
 * @param errCode Response error code.
 * @since 20
 */
typedef void (*Http_ResponseCallback)(struct Http_Response *response, uint32_t errCode);

/**
 * @brief Callback function that is invoked when a response body is received.
 *
 * @param data Response body.
 * @param length Length of response body.
 * @since 20
 */
typedef void (*Http_OnDataReceiveCallback)(const char *data, size_t length);

/**
 * @brief Callback function invoked during request/response data transmission.
 *
 * @param totalSize total size.
 * @param transferredSize transferred size.
 * @since 20
 */
typedef void (*Http_OnProgressCallback)(uint64_t totalSize, uint64_t transferredSize);

/**
 * @brief Callback called when header are received.
 *
 * @param headers Headers of the received requests, which points to the pointer of {@link Http_Headers}.
 * @since 20
 */
typedef void (*Http_OnHeaderReceiveCallback)(Http_Headers *headers);

/**
 * @brief Empty callback function for requested DataEnd or Canceled event callback.
 *
 * @since 20
 */
typedef void (*Http_OnVoidCallback)(void);

/**
 * @brief Callbacks to watch different events.
 *
 * @since 20
 */
typedef struct Http_EventsHandler {
  /** Callback function when the response body is received */
  Http_OnDataReceiveCallback onDataReceive;
  /** Callback function during uploading */
  Http_OnProgressCallback onUploadProgress;
  /** Callback function during downloading */
  Http_OnProgressCallback onDownloadProgress;
  /** Callback function when a header is received */
  Http_OnHeaderReceiveCallback onHeadersReceive;
  /** Callback function at the end of the transfer */
  Http_OnVoidCallback onDataEnd;
  /** Callback function when a request is canceled */
  Http_OnVoidCallback onCanceled;
} Http_EventsHandler;
#ifdef __cplusplus
}
#endif
#endif // NET_HTTP_TYPE_H

/** @} */