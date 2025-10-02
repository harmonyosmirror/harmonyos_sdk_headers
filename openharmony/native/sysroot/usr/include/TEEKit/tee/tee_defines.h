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
 * @addtogroup TeeTrusted
 * @{
 *
 * @brief TEE(Trusted Excution Environment) API.
 * Provides security capability APIs such as trusted storage, encryption and decryption,
 * and trusted time for trusted application development.
 *
 * @since 20
 */

/**
 * @file tee_defines.h
 *
 * @brief Defines basic data types and data structures of TEE.
 *
 * @library NA
 * @kit TEEKit
 * @syscap SystemCapability.Tee.TeeClient
 * @since 20
 */

#ifndef __TEE_DEFINES_H
#define __TEE_DEFINES_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TA_EXPORT

/**
 * @brief Represents the export attribute for Trusted Applications.
 *
 * @since 20
 */
#define TA_EXPORT
#endif

/**
 * @brief Defines the tee mutex handle.
 *
 * @since 20
 */
typedef int *tee_mutex_handle;

/**
 * @brief Represents API level 1.1.1.
 *
 * @since 20
 */
#define API_LEVEL1_1_1 2

/**
 * @brief Represents API level 1.2.
 *
 * @since 20
 */
#define API_LEVEL1_2   3

/**
 * @brief Represents the number of TEE parameters.
 *
 * @since 20
 */
#define TEE_PARAMS_NUM 4

#ifndef NULL
/**
 * @brief Represents a null pointer constant.
 *
 * @since 20
 */
#define NULL ((void*)0)
#endif

/**
 * @brief Marks a parameter as unused.
 *
 * @since 20
 */
#define PARAM_NOT_USED(val) ((void)(val))

/**
 * @brief Enumerates the TEE parameter.
 *
 * @since 20
 */
typedef union {
    /**
     * @brief Describes a memory reference.
     *
     * @since 20
     */
    struct {
        /** Pointer to the memory buffer. */
        void *buffer;
        /** Size of the memory buffer. */
        size_t size;
    } memref;
    /**
     * @brief Describes value parameters.
     *
     * @since 20
     */
    struct {
        /** First value. */
        unsigned int a;
        /** Second value. */
        unsigned int b;
    } value;
    /**
     * @brief Describes shared memory reference.
     *
     * @since 20
     */
    struct {
        /** Pointer to the shared memory buffer. */
        void *buffer;
        /** Size of the shared memory buffer. */
        size_t size;
    } sharedmem;
} TEE_Param;

/**
 * @brief Constructs the TEE parameter types from the provided types.
 *
 * @since 20
 */
#define TEE_PARAM_TYPES(param0Type, param1Type, param2Type, param3Type) \
    (((param3Type) << 12) | ((param2Type) << 8) | ((param1Type) << 4) | (param0Type))

/**
 * @brief Extracts the parameter type at the specified index from the TEE parameter types.
 *
 * @since 20
 */
#define TEE_PARAM_TYPE_GET(paramTypes, index) (((paramTypes) >> (4U * (index))) & 0x0F)

/**
 * @brief Checks parameter types.
 *
 * @param param_to_check Indicates the expected parameter values.
 * @param valid0 Indicates the first parameter type to check.
 * @param valid1 Indicates the second parameter type to check.
 * @param valid2 Indicates the third parameter type to check.
 * @param valid3 Indicates the fourth parameter type to check.
 *
 * @return Returns <b>true</b> if the parameter types are correct.
 *         Returns <b>false</b> otherwise.
 * @since 20
 */
static inline bool check_param_type(uint32_t param_to_check, uint32_t valid0, uint32_t valid1, uint32_t valid2,
                                    uint32_t valid3)
{
    return (TEE_PARAM_TYPES(valid0, valid1, valid2, valid3) == param_to_check);
}

/**
 * @brief Enumerates the types of the TEE parameter.
 *
 * @since 20
 */
enum TEE_ParamType {
    /** Represents no parameter type. */
    TEE_PARAM_TYPE_NONE             = 0x0,
    /** Represents a value input type. */
    TEE_PARAM_TYPE_VALUE_INPUT      = 0x1,
    /** Represents a value output type. */
    TEE_PARAM_TYPE_VALUE_OUTPUT     = 0x2,
    /** Represents a value inout type. */
    TEE_PARAM_TYPE_VALUE_INOUT      = 0x3,
    /** Represents a memory reference input type. */
    TEE_PARAM_TYPE_MEMREF_INPUT     = 0x5,
    /** Represents a memory reference output type. */
    TEE_PARAM_TYPE_MEMREF_OUTPUT    = 0x6,
    /** Represents a memory reference inout type. */
    TEE_PARAM_TYPE_MEMREF_INOUT     = 0x7,
    /** Represents an ION input type. */
    TEE_PARAM_TYPE_ION_INPUT        = 0x8,
    /** Represents an ION single list input type. */
    TEE_PARAM_TYPE_ION_SGLIST_INPUT = 0x9,
    /** Represents a shared memory reference inout type. */
    TEE_PARAM_TYPE_MEMREF_SHARED_INOUT = 0xa,
    /** Represents a resource memory input type. */
    TEE_PARAM_TYPE_RESMEM_INPUT        = 0xc,
    /** Represents a resource memory output type. */
    TEE_PARAM_TYPE_RESMEM_OUTPUT       = 0xd,
    /** Represents a resource memory inout type. */
    TEE_PARAM_TYPE_RESMEM_INOUT        = 0xe,
};

/**
 * @brief Marks a variable as unused.
 *
 * @since 20
 */
#define S_VAR_NOT_USED(variable) \
    do {                         \
        (void)(variable);        \
    } while (0)

/**
 * @brief Defines an object information.
 *
 * @since 20
 */
typedef struct {
    /** Type of the object. */
    uint32_t objectType;
    /** Size of the object. */
    uint32_t objectSize;
    /** Maximum allowed size for the object. */
    uint32_t maxObjectSize;
    /** Usage flags of the object. */
    uint32_t objectUsage;
    /** Size of the data associated with the object. */
    uint32_t dataSize;
    /** Position of the data within the object. */
    uint32_t dataPosition;
    /** Flags associated with the handle. */
    uint32_t handleFlags;
} TEE_ObjectInfo;

/**
 * @brief Defines an object attribute.
 *
 * @since 20
 */
typedef struct {
    /** Attribute ID. */
    uint32_t attributeID;
    /**
     * @brief Attribute content.
     *
     * @since 20
     */
    union {
        /**
         * @brief Reference type content.
         *
         * @since 20
         */
        struct {
            /** Buffer pointer. */
            void *buffer;
            /** Length of the buffer. */
            size_t length;
        } ref;
        /**
         * @brief Value type content.
         *
         * @since 20
         */
        struct {
            /** First value. */
            uint32_t a;
            /** Second value. */
            uint32_t b;
        } value;
    } content;
} TEE_Attribute;

/**
 * @brief Enumerates the types of object attribute.
 *
 * @since 20
 */
enum TEE_ObjectAttribute {
    /** Secret value attribute. */
    TEE_ATTR_SECRET_VALUE          = 0xC0000000,
    /** RSA modulus attribute. */
    TEE_ATTR_RSA_MODULUS           = 0xD0000130,
    /** RSA public exponent attribute. */
    TEE_ATTR_RSA_PUBLIC_EXPONENT   = 0xD0000230,
    /** RSA private exponent attribute. */
    TEE_ATTR_RSA_PRIVATE_EXPONENT  = 0xC0000330,
    /** RSA prime1 attribute. */
    TEE_ATTR_RSA_PRIME1            = 0xC0000430,
    /** RSA prime2 attribute. */
    TEE_ATTR_RSA_PRIME2            = 0xC0000530,
    /** RSA exponent1 attribute. */
    TEE_ATTR_RSA_EXPONENT1         = 0xC0000630,
    /** RSA exponent2 attribute. */
    TEE_ATTR_RSA_EXPONENT2         = 0xC0000730,
    /** RSA coefficient attribute. */
    TEE_ATTR_RSA_COEFFICIENT       = 0xC0000830,
    /** RSA MGF1 hash attribute. */
    TEE_ATTR_RSA_MGF1_HASH         = 0xF0000830,
    /** DSA prime attribute. */
    TEE_ATTR_DSA_PRIME             = 0xD0001031,
    /** DSA subprime attribute. */
    TEE_ATTR_DSA_SUBPRIME          = 0xD0001131,
    /** DSA base attribute. */
    TEE_ATTR_DSA_BASE              = 0xD0001231,
    /** DSA public value attribute. */
    TEE_ATTR_DSA_PUBLIC_VALUE      = 0xD0000131,
    /** DSA private value attribute. */
    TEE_ATTR_DSA_PRIVATE_VALUE     = 0xC0000231,
    /** DH prime attribute. */
    TEE_ATTR_DH_PRIME              = 0xD0001032,
    /** DH subprime attribute. */
    TEE_ATTR_DH_SUBPRIME           = 0xD0001132,
    /** DH base attribute. */
    TEE_ATTR_DH_BASE               = 0xD0001232,
    /** DH X bits attribute. */
    TEE_ATTR_DH_X_BITS             = 0xF0001332,
    /** DH public value attribute. */
    TEE_ATTR_DH_PUBLIC_VALUE       = 0xD0000132,
    /** DH private value attribute. */
    TEE_ATTR_DH_PRIVATE_VALUE      = 0xC0000232,
    /** RSA OAEP label attribute. */
    TEE_ATTR_RSA_OAEP_LABEL        = 0xD0000930,
    /** RSA PSS salt length attribute. */
    TEE_ATTR_RSA_PSS_SALT_LENGTH   = 0xF0000A30,
    /** ECC public value X attribute. */
    TEE_ATTR_ECC_PUBLIC_VALUE_X    = 0xD0000141,
    /** ECC public value Y attribute. */
    TEE_ATTR_ECC_PUBLIC_VALUE_Y    = 0xD0000241,
    /** ECC private value attribute. */
    TEE_ATTR_ECC_PRIVATE_VALUE     = 0xC0000341,
    /** ECC curve attribute. */
    TEE_ATTR_ECC_CURVE             = 0xF0000441,
    /** ED25519 context attribute. */
    TEE_ATTR_ED25519_CTX           = 0xD0000643,
    /** ED25519 public value attribute. */
    TEE_ATTR_ED25519_PUBLIC_VALUE  = 0xD0000743,
    /** ED25519 private value attribute. */
    TEE_ATTR_ED25519_PRIVATE_VALUE = 0xC0000843,
    /** ED25519 PH attribute. */
    TEE_ATTR_ED25519_PH            = 0xF0000543,
    /** X25519 public value attribute. */
    TEE_ATTR_X25519_PUBLIC_VALUE   = 0xD0000944,
    /** X25519 private value attribute. */
    TEE_ATTR_X25519_PRIVATE_VALUE  = 0xC0000A44,
    /** PBKDF2 HMAC password attribute. */
    TEE_ATTR_PBKDF2_HMAC_PASSWORD  = 0xD0000133,
    /** PBKDF2 HMAC salt attribute. */
    TEE_ATTR_PBKDF2_HMAC_SALT      = 0xD0000134,
    /** PRF label attribute. */
    TEE_ATTR_PRF_LABEL             = 0xD0000136,
    /** PRF seed attribute. */
    TEE_ATTR_PRF_SEED              = 0xD0000137,
    /** PRF hash algorithm attribute. */
    TEE_ATTR_PRF_HASH_ALGORITHM    = 0xF0000138,
    /** HKDF salt attribute. */
    TEE_ATTR_HKDF_SALT             = 0xD0000946,
    /** HKDF info attribute. */
    TEE_ATTR_HKDF_INFO             = 0xD0000A46,
    /** PBKDF2 HMAC digest attribute. */
    TEE_ATTR_PBKDF2_HMAC_DIGEST    = 0xF0000135,
    /** HKDF hash algorithm attribute. */
    TEE_ATTR_HKDF_HASH_ALGORITHM   = 0xF0000B46,
    /** KDF key size attribute. */
    TEE_ATTR_KDF_KEY_SIZE          = 0xF0000C46,
};

/**
 * @brief Enumerates the types of object.
 *
 * @since 20
 */
enum TEE_ObjectType {
    /** AES object type. */
    TEE_TYPE_AES                = 0xA0000010,
    /** DES object type. */
    TEE_TYPE_DES                = 0xA0000011,
    /** DES3 object type. */
    TEE_TYPE_DES3               = 0xA0000013,
    /** HMAC MD5 object type. */
    TEE_TYPE_HMAC_MD5           = 0xA0000001,
    /** HMAC SHA1 object type. */
    TEE_TYPE_HMAC_SHA1          = 0xA0000002,
    /** HMAC SHA224 object type. */
    TEE_TYPE_HMAC_SHA224        = 0xA0000003,
    /** HMAC SHA256 object type. */
    TEE_TYPE_HMAC_SHA256        = 0xA0000004,
    /** HMAC SHA384 object type. */
    TEE_TYPE_HMAC_SHA384        = 0xA0000005,
    /** HMAC SHA512 object type. */
    TEE_TYPE_HMAC_SHA512        = 0xA0000006,
    /** RSA public key object type. */
    TEE_TYPE_RSA_PUBLIC_KEY     = 0xA0000030,
    /** RSA keypair object type. */
    TEE_TYPE_RSA_KEYPAIR        = 0xA1000030,
    /** DSA public key object type. */
    TEE_TYPE_DSA_PUBLIC_KEY     = 0xA0000031,
    /** DSA keypair object type. */
    TEE_TYPE_DSA_KEYPAIR        = 0xA1000031,
    /** DH keypair object type. */
    TEE_TYPE_DH_KEYPAIR         = 0xA1000032,
    /** Generic secret object type. */
    TEE_TYPE_GENERIC_SECRET     = 0xA0000000,
    /** Data object type. */
    TEE_TYPE_DATA               = 0xA1000033,
    /** Data GP1.1 object type. */
    TEE_TYPE_DATA_GP1_1         = 0xA00000BF,
    /** ECDSA public key object type. */
    TEE_TYPE_ECDSA_PUBLIC_KEY   = 0xA0000041,
    /** ECDSA keypair object type. */
    TEE_TYPE_ECDSA_KEYPAIR      = 0xA1000041,
    /** ECDH public key object type. */
    TEE_TYPE_ECDH_PUBLIC_KEY    = 0xA0000042,
    /** ECDH keypair object type. */
    TEE_TYPE_ECDH_KEYPAIR       = 0xA1000042,
    /** ED25519 public key object type. */
    TEE_TYPE_ED25519_PUBLIC_KEY = 0xA0000043,
    /** ED25519 keypair object type. */
    TEE_TYPE_ED25519_KEYPAIR    = 0xA1000043,
    /** X25519 public key object type. */
    TEE_TYPE_X25519_PUBLIC_KEY  = 0xA0000044,
    /** X25519 keypair object type. */
    TEE_TYPE_X25519_KEYPAIR     = 0xA1000044,
    /** SM2 DSA public key object type. */
    TEE_TYPE_SM2_DSA_PUBLIC_KEY = 0xA0000045,
    /** SM2 DSA keypair object type. */
    TEE_TYPE_SM2_DSA_KEYPAIR    = 0xA1000045,
    /** SM2 KEP public key object type. */
    TEE_TYPE_SM2_KEP_PUBLIC_KEY = 0xA0000046,
    /** SM2 KEP keypair object type. */
    TEE_TYPE_SM2_KEP_KEYPAIR    = 0xA1000046,
    /** SM2 PKE public key object type. */
    TEE_TYPE_SM2_PKE_PUBLIC_KEY = 0xA0000047,
    /** SM2 PKE keypair object type. */
    TEE_TYPE_SM2_PKE_KEYPAIR    = 0xA1000047,
    /** HMAC SM3 object type. */
    TEE_TYPE_HMAC_SM3           = 0xA0000007,
    /** SM4 object type. */
    TEE_TYPE_SM4                = 0xA0000014,
    /** HKDF object type. */
    TEE_TYPE_HKDF               = 0xA000004A,
    /** SIP Hash object type. */
    TEE_TYPE_SIP_HASH           = 0xF0000002,
    /** PBKDF2 HMAC object type. */
    TEE_TYPE_PBKDF2_HMAC        = 0xF0000004,
    /** PRF object type. */
    TEE_TYPE_PRF                = 0xF0000005,
    /** Corrupted object type. */
    TEE_TYPE_CORRUPTED_OBJECT = 0xA00000BE,
};

/**
 * @brief Maximum length for the object name.
 *
 * @since 20
 */
#define OBJECT_NAME_LEN_MAX 256

/**
 * @brief Defines an object handle.
 *
 * @since 20
 */
struct __TEE_ObjectHandle {
    /** Pointer to the data. */
    void *dataPtr;
    /** Length of the data. */
    uint32_t dataLen;
    /** Name of the data. */
    uint8_t dataName[OBJECT_NAME_LEN_MAX];
    /** Pointer to the object information. */
    TEE_ObjectInfo *ObjectInfo;
    /** Pointer to the attributes of the object. */
    TEE_Attribute *Attribute;
    /** Length of the attributes. */
    uint32_t attributesLen;
    /** CRT mode. */
    uint32_t CRTMode;
    /** File descriptor for info attributes. */
    void *infoattrfd;
    /** Flag for object generation. */
    uint32_t generate_flag;
    /** Storage ID for the object. */
    uint32_t storage_id;
};

/**
 * @brief Defines the <b>__TEE_ObjectHandle</b> struct.
 *
 * @see __TEE_ObjectHandle
 *
 * @since 20
 */
typedef struct __TEE_ObjectHandle *TEE_ObjectHandle;

/**
 * @brief Defines the length of the node.
 *
 * @since 20
 */
#define NODE_LEN 8

/**
 * @brief Defines an UUID of TA.
 *
 * @since 20
 */
typedef struct tee_uuid {
    /** Low part of the UUID time. */
    uint32_t timeLow;
    /** Mid part of the UUID time. */
    uint16_t timeMid;
    /** High part of the UUID time and version. */
    uint16_t timeHiAndVersion;
    /** Clock sequence and node of the UUID. */
    uint8_t clockSeqAndNode[NODE_LEN];
} TEE_UUID;

/**
 * @brief Defines the type of spawn UUID.
 *
 * @since 20
 */
typedef struct spawn_uuid {
    /** Indicates if the UUID is valid. */
    uint64_t uuid_valid;
    /** The spawn UUID. */
    TEE_UUID uuid;
} spawn_uuid_t;

/**
 * @brief Enumerates the result codes used in the TEEKit APIs.
 *
 * @since 20
 */
enum TEE_Result_Value {
    /** The operation is successful. */
    TEE_SUCCESS                        = 0x00000000,
    /** The command is invalid. */
    TEE_ERROR_INVALID_CMD              = 0x00000001,
    /** The service does not exist. */
    TEE_ERROR_SERVICE_NOT_EXIST        = 0x00000002,
    /** The session does not exist. */
    TEE_ERROR_SESSION_NOT_EXIST        = 0x00000003,
    /** The number of sessions exceeds the limit. */
    TEE_ERROR_SESSION_MAXIMUM          = 0x00000004,
    /** The service has been already registered. */
    TEE_ERROR_REGISTER_EXIST_SERVICE   = 0x00000005,
    /** An internal error occurs. */
    TEE_ERROR_TARGET_DEAD_FATAL        = 0x00000006,
    /** Failed to read data. */
    TEE_ERROR_READ_DATA                = 0x00000007,
    /** Failed to write data. */
    TEE_ERROR_WRITE_DATA               = 0x00000008,
    /** Failed to truncate data. */
    TEE_ERROR_TRUNCATE_OBJECT          = 0x00000009,
    /** Failed to seek data. */
    TEE_ERROR_SEEK_DATA                = 0x0000000A,
    /** Failed to synchronize data. */
    TEE_ERROR_SYNC_DATA                = 0x0000000B,
    /** Failed to rename the file. */
    TEE_ERROR_RENAME_OBJECT            = 0x0000000C,
    /** An error occurs when the TA is loaded. */
    TEE_ERROR_TRUSTED_APP_LOAD_ERROR   = 0x0000000D,
    /** TA type is inconsistent with the loading mode. */
    TEE_ERROR_OTRP_LOAD_NOT_MATCHED    = 0x80000100,
    /** The not open session's otrp service num exceeds. */
    TEE_ERROR_OTRP_LOAD_EXCEED         = 0x80000101,
    /** UUID of load cmd is not inconsistent with the sec file. */
    TEE_ERROR_OTRP_ACCESS_DENIED       = 0x80000102,
    /** Otrp service is aged. */
    TEE_ERROR_OTRP_SERVICE_AGED        = 0x80000103,
    /** An I/O error occurs when data is stored. */
    TEE_ERROR_STORAGE_EIO              = 0x80001001,
    /** The storage section is unavailable. */
    TEE_ERROR_STORAGE_EAGAIN           = 0x80001002,
    /** The operation target is not a directory. */
    TEE_ERROR_STORAGE_ENOTDIR          = 0x80001003,
    /** This operation cannot be performed on a directory. */
    TEE_ERROR_STORAGE_EISDIR           = 0x80001004,
    /** The number of opened files exceeds the limit in system. */
    TEE_ERROR_STORAGE_ENFILE           = 0x80001005,
    /** The number of files opened for the process exceeds the limit.*/
    TEE_ERROR_STORAGE_EMFILE           = 0x80001006,
    /** The storage section is read only. */
    TEE_ERROR_STORAGE_EROFS            = 0x80001007,
    /** The file object has been rolled back. */
    TEE_ERROR_STORAGE_EROLLBACK        = 0x80001008,
    /** The file path is not correct. */
    TEE_ERROR_STORAGE_PATH_WRONG       = 0x8000100A,
    /** The service message queue overflows. */
    TEE_ERROR_MSG_QUEUE_OVERFLOW       = 0x8000100B,
    /** The subthread created by TA cannot access the service */
    TEE_ERROR_SUBTHREAD_ACCESS         = 0x8000100C,
    /** Enable backup feature, original partition is inactive */
    TEE_ERROR_ORIGIN_PARTITION_INACTIVE = 0x8000100D,
    /** Enable backup feature, backup partition is inactive */
    TEE_ERROR_BACKUP_PARTITION_INACTIVE = 0x8000100E,
    /** The file object is corrupted. */
    TEE_ERROR_CORRUPT_OBJECT           = 0xF0100001,
    /** The storage section is unavailable. */
    TEE_ERROR_STORAGE_NOT_AVAILABLE    = 0xF0100003,
    /** The cipher text is incorrect. */
    TEE_ERROR_CIPHERTEXT_INVALID       = 0xF0100006,
    /** Protocol error in socket connection. */
    TEE_ISOCKET_ERROR_PROTOCOL         = 0xF1007001,
    /** The socket is closed by the remote end. */
    TEE_ISOCKET_ERROR_REMOTE_CLOSED    = 0xF1007002,
    /** The socket connection timed out. */
    TEE_ISOCKET_ERROR_TIMEOUT          = 0xF1007003,
    /** There is no resource available for the socket connection. */
    TEE_ISOCKET_ERROR_OUT_OF_RESOURCES = 0xF1007004,
    /** The buffer is too large for the socket connection. */
    TEE_ISOCKET_ERROR_LARGE_BUFFER     = 0xF1007005,
    /** A warning is given in the socket connection. */
    TEE_ISOCKET_WARNING_PROTOCOL       = 0xF1007006,
    /** Generic error. */
    TEE_ERROR_GENERIC                  = 0xFFFF0000,
    /** The access is denied. */
    TEE_ERROR_ACCESS_DENIED            = 0xFFFF0001,
    /** The operation has been canceled. */
    TEE_ERROR_CANCEL                   = 0xFFFF0002,
    /** An access conflict occurs. */
    TEE_ERROR_ACCESS_CONFLICT          = 0xFFFF0003,
    /** The data size exceeds the maximum. */
    TEE_ERROR_EXCESS_DATA              = 0xFFFF0004,
    /** Incorrect data format. */
    TEE_ERROR_BAD_FORMAT               = 0xFFFF0005,
    /** Incorrect parameters. */
    TEE_ERROR_BAD_PARAMETERS           = 0xFFFF0006,
    /** The current state does not support the operation. */
    TEE_ERROR_BAD_STATE                = 0xFFFF0007,
    /** Failed to find the target item. */
    TEE_ERROR_ITEM_NOT_FOUND           = 0xFFFF0008,
    /** The API is not implemented. */
    TEE_ERROR_NOT_IMPLEMENTED          = 0xFFFF0009,
    /** The API is not supported. */
    TEE_ERROR_NOT_SUPPORTED            = 0xFFFF000A,
    /** There is no data available for this operation. */
    TEE_ERROR_NO_DATA                  = 0xFFFF000B,
    /** There is no memory available for this operation. */
    TEE_ERROR_OUT_OF_MEMORY            = 0xFFFF000C,
    /** The system does not respond to this operation. */
    TEE_ERROR_BUSY                     = 0xFFFF000D,
    /** Failed to communicate with the target. */
    TEE_ERROR_COMMUNICATION            = 0xFFFF000E,
    /** A security error occurs. */
    TEE_ERROR_SECURITY                 = 0xFFFF000F,
    /** The buffer is insufficient for this operation. */
    TEE_ERROR_SHORT_BUFFER             = 0xFFFF0010,
    /** The operation has been canceled. */
    TEE_ERROR_EXTERNAL_CANCEL          = 0xFFFF0011,
    /** The service is in the pending state (asynchronous state). */
    TEE_PENDING                        = 0xFFFF2000,
    /** The service is in the pending state(). */
    TEE_PENDING2                       = 0xFFFF2001,
    /** Reserved. */
    TEE_PENDING3                       = 0xFFFF2002,
    /** The operation timed out. */
    TEE_ERROR_TIMEOUT                  = 0xFFFF3001,
    /** Overflow occurs. */
    TEE_ERROR_OVERFLOW                 = 0xFFFF300f,
    /** The TA is crashed. */
    TEE_ERROR_TARGET_DEAD              = 0xFFFF3024,
    /** There is no enough space to store data. */
    TEE_ERROR_STORAGE_NO_SPACE         = 0xFFFF3041,
    /** The MAC operation failed. */
    TEE_ERROR_MAC_INVALID              = 0xFFFF3071,
    /** The signature verification failed. */
    TEE_ERROR_SIGNATURE_INVALID        = 0xFFFF3072,
    /** Thecertificate verify failed. */
    TEE_ERROR_CERTIFICATE_INVALID      = 0xFFFF3073,
    /** Interrupted by CFC. Broken control flow is detected. */
    TEE_CLIENT_INTR                    = 0xFFFF4000,
    /** Time is not set. */
    TEE_ERROR_TIME_NOT_SET             = 0xFFFF5000,
    /** Time needs to be reset. */
    TEE_ERROR_TIME_NEEDS_RESET         = 0xFFFF5001,
    /** System error. */
    TEE_FAIL                           = 0xFFFF5002,
    /** Base value of the timer error code. */
    TEE_ERROR_TIMER                    = 0xFFFF6000,
    /** Failed to create the timer. */
    TEE_ERROR_TIMER_CREATE_FAILED      = 0xFFFF6001,
    /** Failed to destroy the timer. */
    TEE_ERROR_TIMER_DESTROY_FAILED     = 0xFFFF6002,
    /** The timer is not found. */
    TEE_ERROR_TIMER_NOT_FOUND          = 0xFFFF6003,
    /** Base value of RPMB error codes. */
    TEE_ERROR_RPMB_BASE                = 0xFFFF7000,
    /** Generic error of RPMB operations. */
    TEE_ERROR_RPMB_GENERIC             = 0xFFFF7001,
    /** Verify MAC failed in RPMB operations. */
    TEE_ERROR_RPMB_MAC_FAIL            = 0xFFFF7002,
    /** Invalid counter in RPMB operations. */
    TEE_ERROR_RPMB_COUNTER_FAIL        = 0xFFFF7003,
    /** Address check failed in RPMB operations. */
    TEE_ERROR_RPMB_ADDR_FAIL           = 0xFFFF7004,
    /** Fail to write data to RPMB. */
    TEE_ERROR_RPMB_WRITE_FAIL          = 0xFFFF7005,
    /** Fail to read data in RPMB.  */
    TEE_ERROR_RPMB_READ_FAIL           = 0xFFFF7006,
    /** Key is not provisioned in RPMB. */
    TEE_ERROR_RPMB_KEY_NOT_PROGRAM     = 0xFFFF7007,
    /** Incorrect message type in RPMB response. */
    TEE_ERROR_RPMB_RESP_UNEXPECT_MSGTYPE = 0xFFFF7100,
    /** Incorrect message data block count in RPMB response. */
    TEE_ERROR_RPMB_RESP_UNEXPECT_BLKCNT = 0xFFFF7101,
    /** Incorrect message data block count in RPMB response. */
    TEE_ERROR_RPMB_RESP_UNEXPECT_BLKIDX = 0xFFFF7102,
    /** Incorrect message data counter in RPMB response. */
    TEE_ERROR_RPMB_RESP_UNEXPECT_WRCNT = 0xFFFF7103,
    /** Incorrect message data nonce in RPMB response. */
    TEE_ERROR_RPMB_RESP_UNEXPECT_NONCE = 0xFFFF7104,
    /** Incorrect message data MAC in RPMB response. */
    TEE_ERROR_RPMB_RESP_UNEXPECT_MAC   = 0xFFFF7105,
    /** The file is not found in RPMB.  */
    TEE_ERROR_RPMB_FILE_NOT_FOUND      = 0xFFFF7106,
    /** No spece left for RPMB operations. */
    TEE_ERROR_RPMB_NOSPC               = 0xFFFF7107,
    /** Exceeds max space of RPMB for this TA. */
    TEE_ERROR_RPMB_SPC_CONFLICT        = 0xFFFF7108,
    /** RPMB service not ready. */
    TEE_ERROR_RPMB_NOT_AVAILABLE       = 0xFFFF7109,
    /** RPMB partition is damaged. */
    TEE_ERROR_RPMB_DAMAGED             = 0xFFFF710A,
    /** TUI is being used. */
    TEE_ERROR_TUI_IN_USE               = 0xFFFF7110,
    /** Incorrect message switch channal in TUI response. */
    TEE_ERROR_TUI_SWITCH_CHANNAL       = 0xFFFF7111,
    /** Incorrect message configurator driver in TUI response. */
    TEE_ERROR_TUI_CFG_DRIVER           = 0xFFFF7112,
    /** Invalid TUI event. */
    TEE_ERROR_TUI_INVALID_EVENT        = 0xFFFF7113,
    /** Incorrect message polling events in TUI response. */
    TEE_ERROR_TUI_POLL_EVENT           = 0xFFFF7114,
    /** TUI is cancelled. */
    TEE_ERROR_TUI_CANCELED             = 0xFFFF7115,
    /** TUI is exited. */
    TEE_ERROR_TUI_EXIT                 = 0xFFFF7116,
    /** TUI unavailable. */
    TEE_ERROR_TUI_NOT_AVAILABLE        = 0xFFFF7117,
    /** sec flash is not available. */
    TEE_ERROR_SEC_FLASH_NOT_AVAILABLE  = 0xFFFF7118,
    /** SE service has crashed or not enable. */
    TEE_ERROR_SESRV_NOT_AVAILABLE      = 0xFFFF7119,
    /** The BIO service is not available. */
    TEE_ERROR_BIOSRV_NOT_AVAILABLE     = 0xFFFF711A,
    /** The ROT service is not available. */
    TEE_ERROR_ROTSRV_NOT_AVAILABLE     = 0xFFFF711B,
    /** The TA Anti-Rollback service is not available. */
    TEE_ERROR_ARTSRV_NOT_AVAILABLE     = 0xFFFF711C,
    /** The HSM service is not available. */
    TEE_ERROR_HSMSRV_NOT_AVAILABLE     = 0xFFFF711D,
    /** REE vrpmb agent check magic failed, maybe cache fail. */
    TEE_ERROR_VRPMB_AGENT_FAIL              = 0xFFFF7200,
    /** REE ssd driver rw failed. */
    TEE_ERROR_VRPMB_RW_FAIL                 = 0xFFFF7201,
    /** vrpmb check super block mac failed. */
    TEE_ERROR_VRPMB_SUPER_MAC_FAILED        = 0xFFFF7202,
    /** reject write to vrpmb. */
    TEE_ERROR_VRPMB_WRITE_REJECT            = 0xFFFF7203,
    /** Failed to verify AntiRoot response. */
    TEE_ERROR_ANTIROOT_RSP_FAIL        = 0xFFFF9110,
    /** AntiRoot error in invokeCmd(). */
    TEE_ERROR_ANTIROOT_INVOKE_ERROR    = 0xFFFF9111,
    /** Audit failed. */
    TEE_ERROR_AUDIT_FAIL               = 0xFFFF9112,
    /** Unused. */
    TEE_FAIL2                          = 0xFFFF9113,
    /** IPC Channel overflow error. */
    TEE_ERROR_IPC_OVERFLOW             = 0xFFFF9114,
    /** APM error. */
    TEE_ERROR_APM                           = 0xFFFF9115,
    /** CA auth file not exist. */
    TEE_ERROR_CA_AUTHFILE_NOT_EXIST         = 0xFFFF9116,
    /** CA caller access is denied. */
    TEE_ERROR_CA_CALLER_ACCESS_DENIED       = 0xFFFF9117,
    /** Invalid TA format. */
    TEE_ERROR_INVALID_TA_FORMAT             = 0xFFFF9118,
    /** local dstb service sign report error. */
    TEE_DSTB_LOCAL_SIGN_REPORT_ERROR        = 0xFFFF9200,
    /** remote dstb service sign report error. */
    TEE_DSTB_REMOTE_SIGN_REPORT_ERROR       = 0xFFFF9201,
    /** local dstb service report cert chain error. */
    TEE_DSTB_LOCAL_REPORT_CERT_CHAIN_ERROR  = 0xFFFF9202,
    /** remote dstb service report cert chain error. */
    TEE_DSTB_REMOTE_REPORT_CERT_CHAIN_ERROR = 0xFFFF9203,
    /** local dstb service verify report error. */
    TEE_DSTB_LOCAL_REPORT_VERIFY_ERROR      = 0xFFFF9204,
    /** remote dstb service verify report error. */
    TEE_DSTB_REMOTE_REPORT_VERIFY_ERROR     = 0xFFFF9205,
    /** local dstb service verify cert chain error. */
    TEE_DSTB_LOCAL_CERT_CHAIN_VERIFY_ERROR  = 0xFFFF9206,
    /** remote dstb service verify cert chain error. */
    TEE_DSTB_REMOTE_CERT_CHAIN_VERIFY_ERROR = 0xFFFF9207,
    /** local dstb service key version error. */
    TEE_DSTB_LOCAL_INVALID_KEY_VERSION_ERROR = 0xFFFF9208,
    /** remote dstb service key version error. */
    TEE_DSTB_REMOTE_INVALID_KEY_VERSION_ERROR = 0xFFFF9209,
    /** udid is invalid. */
    TEE_DSTB_INVALID_UDID                   = 0xFFFF920A,
    /** dstb service derive key error. */
    TEE_DSTB_DERIVE_KEY_ERROR               = 0xFFFF920B,
    /** dstb service of ree error. */
    TEE_DSTB_REE_SRV_ERROR                  = 0xFFFF920C,
    /** TA load fail becauce of anti-rollback. */
    TEE_ERROR_TA_ANTI_ROLLBACK              = 0xFFFF920D,
    /** open_session fail becauce of race with close_session. */
    TEE_ERROR_RETRY_OPEN_SESSION            = 0xFFFF920E,
    /** TA control file load fail. */
    TEE_ERROR_TA_CTRL_FILE_LOAD_FAIL        = 0xFFFF920F,
    /** TA control file verify fail. */
    TEE_ERROR_TA_CTRL_FILE_VERIFY_FAIL      = 0xFFFF9210,
    /** TA version is below the verison in control file. */
    TEE_ERROR_TA_VER_BELOW_CONTROL_VER      = 0xFFFF9211,
    /** Local dstb cert chain validity check failed. */
    TEE_DSTB_LOCAL_CERT_VALIDITY_ERROR      = 0xFFFF9212,
    /** Remote dstb cert chain validity check failed. */
    TEE_DSTB_REMOTE_CERT_VALIDITY_ERROR     = 0xFFFF9213,
};

/**
 * @brief Login type definitions
 *
 * @since 20
 */
enum TEE_LoginMethod {
    /** Public login method. */
    TEE_LOGIN_PUBLIC = 0x0,
    /** User login method. */
    TEE_LOGIN_USER,
    /** Group login method. */
    TEE_LOGIN_GROUP,
    /** Application login method. */
    TEE_LOGIN_APPLICATION = 0x4,
    /** User-application login method. */
    TEE_LOGIN_USER_APPLICATION = 0x5,
    /** Group-application login method. */
    TEE_LOGIN_GROUP_APPLICATION = 0x6,
    /** Customized login type. */
    TEE_LOGIN_IDENTIFY = 0x7,
    /** Login type from the Linux kernel. */
    TEEK_LOGIN_IDENTIFY = 0x80000001,
};

/**
 * @brief Definitions the TEE Identity.
 *
 * @since 20
 */
typedef struct {
    /** Login method. */
    uint32_t login;
    /** The UUID of the identity. */
    TEE_UUID uuid;
} TEE_Identity;

/**
 * @brief Defines the return values.
 *
 * @since 20
 */
typedef uint32_t TEE_Result;

/**
 * @brief Defines the return values.
 *
 * @since 20
 */
typedef TEE_Result TEEC_Result;

/**
 * @brief Origin of the TEE.
 *
 * @since 20
 */
#define TEE_ORIGIN_TEE             0x00000003

/**
 * @brief Origin of the Trusted Application.
 *
 * @since 20
 */
#define TEE_ORIGIN_TRUSTED_APP     0x00000004

#ifndef _TEE_TA_SESSION_HANDLE
/**
 * @brief Defines the handle for a TA session.
 *
 * @since 20
 */
#define _TEE_TA_SESSION_HANDLE
/**
 * @brief Defines the handle of TA session.
 *
 * @since 20
 */
typedef uint32_t TEE_TASessionHandle;
#endif

/**
 * @brief Defines the pointer to <b>TEE_ObjectEnumHandle</b>.
 *
 * @see __TEE_ObjectEnumHandle
 *
 * @since 20
 */
typedef struct __TEE_ObjectEnumHandle *TEE_ObjectEnumHandle;

/**
 * @brief Defines the pointer to <b>__TEE_OperationHandle</b>.
 *
 * @see __TEE_OperationHandle
 *
 * @since 20
 */
typedef struct __TEE_OperationHandle *TEE_OperationHandle;

/**
 * @brief Defines the infinite timeout value.
 *
 * @since 20
 */
#define TEE_TIMEOUT_INFINITE (0xFFFFFFFF)

/**
 * @brief Definitions the TEE time.
 *
 * @since 20
 */
typedef struct {
    /** Seconds part of the time. */
    uint32_t seconds;
    /** Milliseconds part of the time. */
    uint32_t millis;
} TEE_Time;

/**
 * @brief Definitions the date time of TEE.
 *
 * @since 20
 */
typedef struct {
    /** Seconds part of the date time. */
    int32_t seconds;
    /** Milliseconds part of the date time. */
    int32_t millis;
    /** Minutes part of the date time. */
    int32_t min;
    /** Hours part of the date time. */
    int32_t hour;
    /** Day part of the date time. */
    int32_t day;
    /** Month part of the date time. */
    int32_t month;
    /** Year part of the date time. */
    int32_t year;
} TEE_Date_Time;

/**
 * @brief Definitions the timer property of TEE.
 *
 * @since 20
 */
typedef struct {
    /** Type of the timer. */
    uint32_t type;
    /** Timer ID. */
    uint32_t timer_id;
    /** Timer class. */
    uint32_t timer_class;
    /** Reserved field for future use. */
    uint32_t reserved2;
} TEE_timer_property;

#ifdef __cplusplus
}
#endif

#endif
/** @} */