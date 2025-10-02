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
 * @file tee_crypto_api.h
 *
 * @brief Provides APIs for cryptographic operations.
 *
 * You can use these APIs to implement encryption and decryption.
 *
 * @library NA
 * @kit TEEKit
 * @syscap SystemCapability.Tee.TeeClient
 * @since 20
 */

#ifndef TEE_CRYPTO_API_H
#define TEE_CRYPTO_API_H

#include <pthread.h>
#include <tee_defines.h>
#include <tee_mem_mgmt_api.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NULL
/**
 * @brief Definition of <b>NULL</b>.
 *
 * @since 20
 */
#define NULL ((void *)0)
#endif

/**
 * @brief Defines the maximum key length, in bits.
 *
 * @since 20
 */
#define TEE_MAX_KEY_SIZE_IN_BITS      (1024 * 8)

/**
 * @brief Defines the length of the SW_RSA key, in bytes.
 *
 * @since 20
 */
#define SW_RSA_KEYLEN                 1024

/**
 * @brief Defines the maximum length of other Diffie-Hellman (DH) information, in bytes.
 *
 * @since 20
 */
#define TEE_DH_MAX_SIZE_OF_OTHER_INFO 64

/**
 * @brief Defines the maximum parameter count.
 *
 * @since 20
 */
#define TEE_PARAM_COUNT_MAX 9

/**
 * @brief Enumerates the cryptographic operation handles.
 *
 * @since 20
 */
enum __TEE_Operation_Constants {
    /** Cipher */
    TEE_OPERATION_CIPHER               = 0x1,
    /** MAC */
    TEE_OPERATION_MAC                  = 3,
    /** AE */
    TEE_OPERATION_AE                   = 4,
    /** Digest */
    TEE_OPERATION_DIGEST               = 5,
    /** Asymmetric Cipher */
    TEE_OPERATION_ASYMMETRIC_CIPHER    = 6,
    /** Asymmetric Signature */
    TEE_OPERATION_ASYMMETRIC_SIGNATURE = 7,
    /** Key Derivation */
    TEE_OPERATION_KEY_DERIVATION       = 8,
    /** KDF Key Derivation */
    TEE_OPERATION_KDF_KEY_DERIVATION   = 9,
};

/**
 * @brief Enumerates the cryptographic algorithms.
 *
 * @since 20
 */
enum __tee_crypto_algorithm_id {
    /** Invalid algorithm */
    TEE_ALG_INVALID                      = 0x0,
    /** AES_ECB_NOPAD */
    TEE_ALG_AES_ECB_NOPAD                = 0x10000010,
    /** AES_CBC_NOPAD */
    TEE_ALG_AES_CBC_NOPAD                = 0x10000110,
    /** AES_CTR */
    TEE_ALG_AES_CTR                      = 0x10000210,
    /** AES_CTS */
    TEE_ALG_AES_CTS                      = 0x10000310,
    /** AES_XTS */
    TEE_ALG_AES_XTS                      = 0x10000410,
    /** AES_CBC_MAC_NOPAD */
    TEE_ALG_AES_CBC_MAC_NOPAD            = 0x30000110,
    /** AES_CBC_MAC_PKCS5 */
    TEE_ALG_AES_CBC_MAC_PKCS5            = 0x30000510,
    /** AES_CMAC */
    TEE_ALG_AES_CMAC                     = 0x30000610,
    /** AES_GMAC */
    TEE_ALG_AES_GMAC                     = 0x30000810,
    /** AES_CCM */
    TEE_ALG_AES_CCM                      = 0x40000710,
    /** AES_GCM */
    TEE_ALG_AES_GCM                      = 0x40000810,
    /** DES_ECB_NOPAD */
    TEE_ALG_DES_ECB_NOPAD                = 0x10000011,
    /** DES_CBC_NOPAD */
    TEE_ALG_DES_CBC_NOPAD                = 0x10000111,
    /** DES_CBC_MAC_NOPAD */
    TEE_ALG_DES_CBC_MAC_NOPAD            = 0x30000111,
    /** DES_CBC_MAC_PKCS5 */
    TEE_ALG_DES_CBC_MAC_PKCS5            = 0x30000511,
    /** DES3_ECB_NOPAD */
    TEE_ALG_DES3_ECB_NOPAD               = 0x10000013,
    /** DES3_CBC_NOPAD */
    TEE_ALG_DES3_CBC_NOPAD               = 0x10000113,
    /** DES3_CBC_MAC_NOPAD */
    TEE_ALG_DES3_CBC_MAC_NOPAD           = 0x30000113,
    /** DES3_CBC_MAC_PKCS5 */
    TEE_ALG_DES3_CBC_MAC_PKCS5           = 0x30000513,
    /** RSASSA_PKCS1_V1_5_MD5 */
    TEE_ALG_RSASSA_PKCS1_V1_5_MD5        = 0x70001830,
    /** RSASSA_PKCS1_V1_5_SHA1 */
    TEE_ALG_RSASSA_PKCS1_V1_5_SHA1       = 0x70002830,
    /** RSASSA_PKCS1_V1_5_SHA224 */
    TEE_ALG_RSASSA_PKCS1_V1_5_SHA224     = 0x70003830,
    /** RSASSA_PKCS1_V1_5_SHA256 */
    TEE_ALG_RSASSA_PKCS1_V1_5_SHA256     = 0x70004830,
    /** RSASSA_PKCS1_V1_5_SHA384 */
    TEE_ALG_RSASSA_PKCS1_V1_5_SHA384     = 0x70005830,
    /** RSASSA_PKCS1_V1_5_SHA512 */
    TEE_ALG_RSASSA_PKCS1_V1_5_SHA512     = 0x70006830,
    /** RSASSA_PKCS1_V1_5_SM3 */
    TEE_ALG_RSASSA_PKCS1_V1_5_SM3        = 0xF0007830,
    /** RSASSA_PKCS1_V1_5_MD5_SHA1 */
    TEE_ALG_RSASSA_PKCS1_V1_5_MD5_SHA1   = 0xF0008830,
    /** RSASSA_PKCS1_PSS_MGF1_MD5 */
    TEE_ALG_RSASSA_PKCS1_PSS_MGF1_MD5    = 0x70111930,
    /** RSASSA_PKCS1_PSS_MGF1_SHA1 */
    TEE_ALG_RSASSA_PKCS1_PSS_MGF1_SHA1   = 0x70212930,
    /** RSASSA_PKCS1_PSS_MGF1_SHA224 */
    TEE_ALG_RSASSA_PKCS1_PSS_MGF1_SHA224 = 0x70313930,
    /** RSASSA_PKCS1_PSS_MGF1_SHA256 */
    TEE_ALG_RSASSA_PKCS1_PSS_MGF1_SHA256 = 0x70414930,
    /** RSASSA_PKCS1_PSS_MGF1_SHA384 */
    TEE_ALG_RSASSA_PKCS1_PSS_MGF1_SHA384 = 0x70515930,
    /** RSASSA_PKCS1_PSS_MGF1_SHA512 */
    TEE_ALG_RSASSA_PKCS1_PSS_MGF1_SHA512 = 0x70616930,
    /** RSAES_PKCS1_V1_5 */
    TEE_ALG_RSAES_PKCS1_V1_5             = 0x60000130,
    /** RSAES_PKCS1_OAEP_MGF1_SHA1 */
    TEE_ALG_RSAES_PKCS1_OAEP_MGF1_SHA1   = 0x60210230,
    /** RSAES_PKCS1_OAEP_MGF1_SHA224 */
    TEE_ALG_RSAES_PKCS1_OAEP_MGF1_SHA224 = 0x60211230,
    /** RSAES_PKCS1_OAEP_MGF1_SHA256 */
    TEE_ALG_RSAES_PKCS1_OAEP_MGF1_SHA256 = 0x60212230,
    /** RSAES_PKCS1_OAEP_MGF1_SHA384 */
    TEE_ALG_RSAES_PKCS1_OAEP_MGF1_SHA384 = 0x60213230,
    /** RSAES_PKCS1_OAEP_MGF1_SHA512 */
    TEE_ALG_RSAES_PKCS1_OAEP_MGF1_SHA512 = 0x60214230,
    /** RSA_NOPAD */
    TEE_ALG_RSA_NOPAD                    = 0x60000030,
    /** DSA_SHA1 */
    TEE_ALG_DSA_SHA1                     = 0x70002131,
    /** DSA_SHA224 */
    TEE_ALG_DSA_SHA224                   = 0x70003131,
    /** DSA_SHA256 */
    TEE_ALG_DSA_SHA256                   = 0x70004131,
    /** DH_DERIVE_SHARED_SECRET */
    TEE_ALG_DH_DERIVE_SHARED_SECRET      = 0x80000032,
    /** MD5 */
    TEE_ALG_MD5                          = 0x50000001,
    /** SHA1 */
    TEE_ALG_SHA1                         = 0x50000002,
    /** SHA224 */
    TEE_ALG_SHA224                       = 0x50000003,
    /** SHA256 */
    TEE_ALG_SHA256                       = 0x50000004,
    /** SHA384 */
    TEE_ALG_SHA384                       = 0x50000005,
    /** SHA512 */
    TEE_ALG_SHA512                       = 0x50000006,
    /** HMAC_MD5 */
    TEE_ALG_HMAC_MD5                     = 0x30000001,
    /** HMAC_SHA1 */
    TEE_ALG_HMAC_SHA1                    = 0x30000002,
    /** HMAC_SHA224 */
    TEE_ALG_HMAC_SHA224                  = 0x30000003,
    /** HMAC_SHA256 */
    TEE_ALG_HMAC_SHA256                  = 0x30000004,
    /** HMAC_SHA384 */
    TEE_ALG_HMAC_SHA384                  = 0x30000005,
    /** HMAC_SHA512 */
    TEE_ALG_HMAC_SHA512                  = 0x30000006,
    /** HMAC_SM3 */
    TEE_ALG_HMAC_SM3                     = 0x30000007,
    /** AES_ECB_PKCS5 */
    TEE_ALG_AES_ECB_PKCS5                = 0x10000020,
    /** AES_CBC_PKCS5 */
    TEE_ALG_AES_CBC_PKCS5                = 0x10000220,
    /** AES_CBC_ISO_PADDING  */
    TEE_ALG_AES_CBC_ISO_PADDING          = 0x10000330,
    /** ECDSA_SHA1 */
    TEE_ALG_ECDSA_SHA1                   = 0x70001042,
    /** ECDSA_SHA224 */
    TEE_ALG_ECDSA_SHA224                 = 0x70002042,
    /** ECDSA_SHA256 */
    TEE_ALG_ECDSA_SHA256                 = 0x70003042,
    /** ECDSA_SHA384 */
    TEE_ALG_ECDSA_SHA384                 = 0x70004042,
    /** ECDSA_SHA512 */
    TEE_ALG_ECDSA_SHA512                 = 0x70005042,
    /** ED25519 */
    TEE_ALG_ED25519                      = 0x70005043,
    /** ECDH_DERIVE_SHARED_SECRET */
    TEE_ALG_ECDH_DERIVE_SHARED_SECRET    = 0x80000042,
    /** X25519 */
    TEE_ALG_X25519                       = 0x80000044,
    /** ECC */
    TEE_ALG_ECC                          = 0x80000001,
    /** ECDSA_P192 */
    TEE_ALG_ECDSA_P192                   = 0x70001042,
    /** ECDSA_P224 */
    TEE_ALG_ECDSA_P224                   = 0x70002042,
    /** ECDSA_P256 */
    TEE_ALG_ECDSA_P256                   = 0x70003042,
    /** ECDSA_P384 */
    TEE_ALG_ECDSA_P384                   = 0x70004042,
    /** ECDSA_P521 */
    TEE_ALG_ECDSA_P521                   = 0x70005042,
    /** ECDH_P192 */
    TEE_ALG_ECDH_P192                    = 0x80001042,
    /** ECDH_P224 */
    TEE_ALG_ECDH_P224                    = 0x80002042,
    /** ECDH_P256 */
    TEE_ALG_ECDH_P256                    = 0x80003042,
    /** ECDH_P384 */
    TEE_ALG_ECDH_P384                    = 0x80004042,
    /** ECDH_P521 */
    TEE_ALG_ECDH_P521                    = 0x80005042,
    /** SIP_HASH */
    TEE_ALG_SIP_HASH                     = 0xF0000002,
    /** SM2_DSA_SM3 */
    TEE_ALG_SM2_DSA_SM3                  = 0x70006045,
    /** SM2_PKE */
    TEE_ALG_SM2_PKE                      = 0x80000045,
    /** SM3 */
    TEE_ALG_SM3                          = 0x50000007,
    /** SM4_ECB_NOPAD */
    TEE_ALG_SM4_ECB_NOPAD                = 0x10000014,
    /** SM4_ECB_PKCS7 */
    TEE_ALG_SM4_ECB_PKCS7                = 0x10000024,
    /** SM4_CBC_NOPAD */
    TEE_ALG_SM4_CBC_NOPAD                = 0x10000114,
    /** SM4_CBC_PKCS7 */
    TEE_ALG_SM4_CBC_PKCS7                = 0xF0000003,
    /** SM4_CTR */
    TEE_ALG_SM4_CTR                      = 0x10000214,
    /** SM4_CFB128 */
    TEE_ALG_SM4_CFB128                   = 0xF0000000,
    /** SM4_XTS */
    TEE_ALG_SM4_XTS                      = 0x10000414,
    /** SM4_OFB */
    TEE_ALG_SM4_OFB                      = 0x10000514,
    /** AES_OFB */
    TEE_ALG_AES_OFB                      = 0x10000510,
    /** AES_CFB128 */
    TEE_ALG_AES_CFB128                   = 0xF0000610,
    /** SM4_GCM */
    TEE_ALG_SM4_GCM                      = 0xF0000005,
    /** PBKDF2_HMAC_SHA1_DERIVE_KEY */
    TEE_ALG_PBKDF2_HMAC_SHA1_DERIVE_KEY  = 0x800020C2,
    /** PBKDF2_HMAC_SHA256_DERIVE_KEY */
    TEE_ALG_PBKDF2_HMAC_SHA256_DERIVE_KEY = 0x800040C2,
    /** PBKDF2_HMAC_SHA384_DERIVE_KEY */
    TEE_ALG_PBKDF2_HMAC_SHA384_DERIVE_KEY = 0x800050C2,
    /** PBKDF2_HMAC_SHA512_DERIVE_KEY */
    TEE_ALG_PBKDF2_HMAC_SHA512_DERIVE_KEY = 0x800060C2,
    /** HKDF */
    TEE_ALG_HKDF                         = 0x80000047,
    /** PRF */
    TEE_ALG_PRF                          = 0xF0000006,
};

/**
 * @brief Defines the <b>__tee_crypto_algorithm_id</b> struct.
 *
 * @see __tee_crypto_algorithm_id
 *
 * @since 20
 */
typedef enum __tee_crypto_algorithm_id tee_crypto_algorithm_id;

/**
 * @brief No element is available.
 *
 * @since 20
 */
#define TEE_OPTIONAL_ELEMENT_NONE 0x00000000

/**
 * @brief Enumerates the Elliptic-Curve Cryptography (ECC) curves supported.
 *
 * @since 20
 */
typedef enum {
    /** CURVE_NIST_P192 */
    TEE_ECC_CURVE_NIST_P192 = 0x00000001,
    /** CURVE_NIST_P224 */
    TEE_ECC_CURVE_NIST_P224 = 0x00000002,
    /** CURVE_NIST_P256 */
    TEE_ECC_CURVE_NIST_P256 = 0x00000003,
    /** CURVE_NIST_P384 */
    TEE_ECC_CURVE_NIST_P384 = 0x00000004,
    /** CURVE_NIST_P521 */
    TEE_ECC_CURVE_NIST_P521 = 0x00000005,
    /** CURVE_SM2 256 bits */
    TEE_ECC_CURVE_SM2       = 0x00000300,
    /** CURVE_25519 256 bits */
    TEE_ECC_CURVE_25519     = 0x00000200,
} TEE_ECC_CURVE;

/**
 * @brief Enumerates the Mask Generation Function (MGF1) modes.
 *
 * @since 20
 */
typedef enum {
    /** SHA1 mode for DH hashing. */
    TEE_DH_HASH_SHA1_mode   = 0,
    /** SHA224 mode for DH hashing. */
    TEE_DH_HASH_SHA224_mode = 1,
    /** SHA256 mode for DH hashing. */
    TEE_DH_HASH_SHA256_mode = 2,
    /** SHA384 mode for DH hashing. */
    TEE_DH_HASH_SHA384_mode = 3,
    /** SHA512 mode for DH hashing. */
    TEE_DH_HASH_SHA512_mode = 4,
    /** Total number of DH hashing modes. */
    TEE_DH_HASH_NumOfModes,
} TEE_DH_HASH_Mode;

/**
 * @brief Enumerates the Diffie-Hellman operation modes.
 *
 * @since 20
 */
typedef enum {
    /** PKCS3 */
    TEE_DH_PKCS3_mode = 0,
    /** X942 algorithm. */
    TEE_DH_ANSI_X942_mode = 1,
    /** Number of modes. */
    TEE_DH_NumOfModes,
} TEE_DH_OpMode_t;

/**
 * @brief Defines an enum for TEE_DH_DerivFuncMode.
 *
 * @since 20
 */
typedef enum {
    /** ASN1_DerivMode */
    TEE_DH_ASN1_DerivMode = 0,
    /** ConcatDerivMode */
    TEE_DH_ConcatDerivMode = 1,
    /** X963_DerivMode */
    TEE_DH_X963_DerivMode = TEE_DH_ConcatDerivMode,
    /** OMADRM_DerivMode */
    TEE_DH_OMADRM_DerivMode = 2,
    /** ISO18033_KDF1_DerivMode */
    TEE_DH_ISO18033_KDF1_DerivMode = 3,
    /** ISO18033_KDF2_DerivMode */
    TEE_DH_ISO18033_KDF2_DerivMode = 4,
    /** Number of modes. */
    TEE_DH_DerivFunc_NumOfModes,
} TEE_DH_DerivFuncMode;

/**
 * @brief Enumerates the object attributes for cryptographic operations.
 *
 * @since 20
 */
enum __TEE_DK_ObjectAttribute {
    /** Pointer to the shared secret value. */
    TEE_DK_SECRECT = 0,
    /** Pointer to a struct that contains other data. */
    TEE_DK_OTHER,
    /** Enumerator ID of the hash function to be used. */
    TEE_DK_HASH_MODE,
    /** Enumerator ID of the derivation function mode. */
    TEE_DK_DERIVATION_MODE
};

/**
 * @brief Defines a struct for __TEE_DK_ObjectAttribute.
 *
 * @see __TEE_DK_ObjectAttribute
 *
 * @since 20
 */
typedef enum __TEE_DK_ObjectAttribute tee_dk_objectattribute;

/**
 * @brief Enumerates the cryptographic operation modes.
 *
 * @since 20
 */
enum __TEE_OperationMode {
    /** Encryption */
    TEE_MODE_ENCRYPT = 0x0,
    /** Decryption */
    TEE_MODE_DECRYPT,
    /** Signing */
    TEE_MODE_SIGN,
    /** Signature verification */
    TEE_MODE_VERIFY,
    /** MAC */
    TEE_MODE_MAC,
    /** Digest */
    TEE_MODE_DIGEST,
    /** Key derivation */
    TEE_MODE_DERIVE
};

/**
 * @brief Enumerates the cryptographic operation states.
 *
 * @since 20
 */
enum tee_operation_state {
    /** Initial */
    TEE_OPERATION_STATE_INITIAL = 0x00000000,
    /** Active */
    TEE_OPERATION_STATE_ACTIVE  = 0x00000001,
};

/**
 * @brief Defines the mode for cryptographic operations.
 *
 * @since 20
 */
typedef uint32_t TEE_OperationMode;

/**
 * @brief Defines a struct for TEE_DH_OtherInfo.
 *
 * @since 20
 */
typedef struct {
    /** object ID(OID) */
    uint8_t algorithm_id[TEE_DH_MAX_SIZE_OF_OTHER_INFO];
    /** length of AlgorithmID */
    uint32_t size_of_algorithm_id;
    /** public info of sender */
    uint8_t party_u_info[TEE_DH_MAX_SIZE_OF_OTHER_INFO];
    /** length of PartyUInfo */
    uint32_t size_of_party_u_info;
    /** public info of receiver */
    uint8_t party_v_info[TEE_DH_MAX_SIZE_OF_OTHER_INFO];
    /** length of PartyVInfo */
    uint32_t size_of_party_v_info;
    /** shared private info */
    uint8_t supp_priv_info[TEE_DH_MAX_SIZE_OF_OTHER_INFO];
    /** length of SuppPrivInfo */
    uint32_t size_of_supp_priv_info;
    /** shared public info */
    uint8_t supp_pub_info[TEE_DH_MAX_SIZE_OF_OTHER_INFO];
    /** length of SuppPubInfo */
    uint32_t size_of_supp_pub_info;
} TEE_DH_OtherInfo;

/**
 * @brief Defines the operation information.
 *
 * @since 20
 */
struct __TEE_OperationInfo {
    /** Algorithm ID */
    uint32_t algorithm;        /* #__TEE_CRYPTO_ALGORITHM_ID */
    /** Operation type */
    uint32_t operationClass;   /* #__TEE_Operation_Constants */
    /** Operation mode */
    uint32_t mode;             /* #__TEE_OperationMode */
    /** Digest length */
    uint32_t digestLength;
    /** Maximum key length */
    uint32_t maxKeySize;
    /** Key length*/
    uint32_t keySize;
    /** Required key usage */
    uint32_t requiredKeyUsage;
    /** Handle state */
    uint32_t handleState;
    /** Key */
    void *keyValue;
};

/**
 * @brief Defines a struct for __TEE_OperationInfo.
 *
 * @see __TEE_OperationInfo
 *
 * @since 20
 */
typedef struct __TEE_OperationInfo TEE_OperationInfo;

/**
 * @brief Defines the key information stored in the <b>OperationInfo</b>.
 *
 * @since 20
 */
typedef struct {
    /** Key length */
    uint32_t keySize;
    /** Required key usage */
    uint32_t requiredKeyUsage;
} TEE_OperationInfoKey;

/**
 * @brief Defines information about an operation.
 *
 * @since 20
 */
typedef struct {
    /** Algorithm ID */
    uint32_t algorithm;
    /** Operation type */
    uint32_t operationClass;
    /** Operation mode */
    uint32_t mode;
    /** Digest length */
    uint32_t digestLength;
    /** Maximum key length */
    uint32_t maxKeySize;
    /** Handle state */
    uint32_t handleState;
    /** Operation state */
    uint32_t operationState;
    /** Number of keys */
    uint32_t numberOfKeys;
    /** Key information */
    TEE_OperationInfoKey keyInformation[];
} TEE_OperationInfoMultiple;

/**
 * @brief Defines the cryptographic operation handle.
 *
 * @since 20
 */
struct __TEE_OperationHandle {
    /** Algorithm ID */
    uint32_t algorithm;
    /** Operation type */
    uint32_t operationClass;
    /** Operation mode */
    uint32_t mode;
    /** Digest length */
    uint32_t digestLength;
    /** Maximum key length */
    uint32_t maxKeySize;
    /** Key length */
    uint32_t keySize;
    /** Key length */
    uint32_t keySize2;
    /** Required key usage */
    uint32_t requiredKeyUsage;
    /** Handle state */
    uint32_t handleState;
    /** Key */
    void *keyValue;
    /** Key */
    void *keyValue2;
    /** */
    void *crypto_ctxt;
    /** */
    void *hmac_rest_ctext;
    /** iv */
    void *IV;
    /** Public key */
    void *publicKey;
    /** Length of the public key */
    uint32_t publicKeyLen;
    /** Private key */
    void *privateKey;
    /** Length of the private key */
    uint32_t privateKeyLen;
    /** Length of the IV */
    uint32_t IVLen;
    /** TEE_DH_OtherInfo */
    TEE_DH_OtherInfo *dh_otherinfo;
    /** TEE_DH_HASH_Mode */
    uint32_t dh_hash_mode;
    /** TEE_DH_DerivFuncMode */
    uint32_t dh_derive_func;
    /** TEE_DH_OpMode_t */
    uint32_t dh_op_mode;
    void *dh_prime;
    uint32_t dh_prime_size;
    /** Operation lock */
    pthread_mutex_t operation_lock;
    /** HAL information */
    void *hal_info;
};

/**
 * @brief Defines the data used for conversion of integers.
 *
 * @since 20
 */
typedef struct {
    /** Source */
    uint32_t src;
    /** Destination */
    uint32_t dest;
} crypto_uint2uint;

/**
 * @brief Defines the maximum length of an RSA public key.
 *
 * @since 20
 */
#define RSA_PUBKEY_MAXSIZE sizeof(CRYS_RSAUserPubKey_t)

/**
 * @brief Defines the maximum length of an RES private key.
 *
 * @since 20
 */
#define RSA_PRIVKEY_MAXSIZE sizeof(CRYS_RSAUserPrivKey_t)

/**
 * @brief Defines a structure to hold the input and output data.
 *
 * @since 20
 */
typedef struct {
    /** Source data */
    void *src_data;
    /** Length of the source data */
    size_t src_len;
    /** Destination data */
    void *dest_data;
    /** Length of the destination data */
    size_t *dest_len;
} operation_src_dest;

/**
 * @brief Defines the AE initialization data.
 *
 * @since 20
 */
typedef struct {
    /** nonce */
    void *nonce;
    /** Leng of nonce */
    size_t nonce_len;
    /** Length of the tag */
    uint32_t tag_len;
    /** Length of the additional authenticated data (AAD) */
    size_t aad_len;
    /** Length of the payload */
    size_t payload_len;
} operation_ae_init;

/**
 * @brief Defines the <b>__TEE_OperationHandle</b> struct.
 *
 * @see __TEE_OperationHandle
 *
 * @since 20
 */
typedef struct __TEE_OperationHandle TEE_OperationHandleVar;

/**
 * @brief Defines the <b>__TEE_ObjectHandle</b> struct.
 *
 * @since 20
 */
typedef struct __TEE_ObjectHandle TEE_ObjectHandleVar;

/**
 * @brief Allocates an operation handle.
 *
 * @param operation Indicates the pointer to the operation handle.
 * @param algorithm Indicates the cipher algorithm.
 * @param mode Indicates the operation mode.
 * @param maxKeySize Indicates the maximum length of the key.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation handle is allocated.
 *         Returns <b>TEE_ERROR_OUT_OF_MEMORY</b> if there is no enough memory for this operation.
 *         Returns <b>TEE_ERROR_NOT_SUPPORTED</b> if the specified algorithm is not supported.
 *         Returns <b>TEE_ERROR_GENERIC</b> if the operation fails due to other errors.
 *
 * @since 20
 */
TEE_Result TEE_AllocateOperation(TEE_OperationHandle *operation, uint32_t algorithm, uint32_t mode,
                                 uint32_t maxKeySize);

/**
 * @brief Releases an operation handle.
 *
 * @param operation Indicates the operation handle to release.
 *
 * @since 20
 */
void TEE_FreeOperation(TEE_OperationHandle operation);

/**
 * @brief Obtains operation information.
 *
 * @param operation Indicates the operation handle.
 * @param operationInfo Indicates the pointer to the operation information.
 *
 * @since 20
 */
void TEE_GetOperationInfo(const TEE_OperationHandle operation, TEE_OperationInfo *operationInfo);

/**
 * @brief Resets an operation handle.
 *
 * @param operation Indicates the operation handle to reset.
 *
 * @since 20
 */
void TEE_ResetOperation(TEE_OperationHandle operation);

/**
 * @brief Sets the key for an operation.
 *
 * @param operation Indicates the operation handle.
 * @param key Indicates the key.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 *         Returns <b>TEE_ERROR_BAD_PARAMETERS</b> if the operation fails due to invalid parameters.
 *         Returns <b>TEE_ERROR_OUT_OF_MEMORY</b> if there is no enough memory for this operation.
 *
 * @since 20
 */
TEE_Result TEE_SetOperationKey(TEE_OperationHandle operation, const TEE_ObjectHandle key);

/**
 * @brief Sets two keys for an operation.
 *
 * @param operation Indicates the operation handle.
 * @param key1 Indicates key 1.
 * @param key2 Indicates key 2.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 *         Returns <b>TEE_ERROR_BAD_PARAMETERS</b> if the operation fails due to invalid parameters.
 *
 * @since 20
 */
TEE_Result TEE_SetOperationKey2(TEE_OperationHandle operation, const TEE_ObjectHandle key1,
                                const TEE_ObjectHandle key2);

/**
 * @brief Copies an operation handle.
 *
 * @param dstOperation Indicates the destination operation handle.
 * @param srcOperation Indicates the source operation handle.
 *
 * @since 20
 */
void TEE_CopyOperation(TEE_OperationHandle dstOperation, const TEE_OperationHandle srcOperation);

/**
 * @brief Initializes the context to start a cipher operation.
 *
 * @param operation Indicates the operation handle.
 * @param IV Indicates the pointer to the buffer storing the operation IV. If this parameter is not used,
 * set it to <b>NULL</b>.
 * @param IVLen Indicates the length of the IV buffer.
 *
 * @since 20
 */
void TEE_CipherInit(TEE_OperationHandle operation, const void *IV, size_t IVLen);

/**
 * @brief Updates the data for a cipher operation.
 *
 * @param operation Indicates the operation handle.
 * @param srcData Indicates the pointer to the source data.
 * @param srcLen Indicates the length of the source data.
 * @param destData Indicates the pointer to the destination data.
 * @param destLen Indicates the pointer to the destination data length.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 *         Returns <b>TEE_ERROR_BAD_PARAMETERS</b> if the operation fails due to invalid parameters.
 *         Returns <b>TEE_ERROR_GENERIC</b> if the operation fails due to other errors.
 *
 * @since 20
 */
TEE_Result TEE_CipherUpdate(TEE_OperationHandle operation, const void *srcData, size_t srcLen, void *destData,
                            size_t *destLen);

/**
 * @brief Finalizes a cipher operation.
 *
 * @param operation Indicates the operation handle.
 * @param srcData Indicates the pointer to the source data.
 * @param srcLen Indicates the length of the source data.
 * @param destData Indicates the pointer to the destination data.
 * @param destLen Indicates the pointer to the destination data length.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 *         Returns <b>TEE_ERROR_BAD_PARAMETERS</b> if the operation fails due to invalid parameters.
 *         Returns <b>TEE_ERROR_GENERIC</b> if the operation fails due to other errors.
 *
 * @since 20
 */
TEE_Result TEE_CipherDoFinal(TEE_OperationHandle operation, const void *srcData, size_t srcLen, void *destData,
                             size_t *destLen);

/**
 * @brief Updates the digest.
 *
 * @param operation Indicates the operation handle.
 * @param chunk Indicates the pointer to the chunk of data to be hashed.
 * @param chunkSize Indicates the length of the chunk.
 *
 * @since 20
 */
void TEE_DigestUpdate(TEE_OperationHandle operation, const void *chunk, size_t chunkSize);

/**
 * @brief Finalizes the message digest operation.
 *
 * @param operation Indicates the operation handle.
 * @param chunk Indicates the pointer to the chunk of data to be hashed.
 * @param chunkLen Indicates the length of the chunk.
 * @param hash Indicates the pointer to the buffer storing the message hash.
 * @param hashLen
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 *         Returns <b>TEE_ERROR_SHORT_BUFFER</b> if the operationInfo buffer is not large enough to
 * hold the information obtained.
 *
 * @since 20
 */
TEE_Result TEE_DigestDoFinal(TEE_OperationHandle operation, const void *chunk, size_t chunkLen, void *hash,
                             size_t *hashLen);

/**
 * @brief Initializes a MAC operation.
 *
 * @param operation Indicates the operation handle.
 * @param IV Indicates the pointer to the buffer storing the operation IV. If this parameter is not used,
 * set it to <b>NULL</b>.
 * @param IVLen Indicates the length of the IV buffer.
 *
 * @since 20
 */
void TEE_MACInit(TEE_OperationHandle operation, void *IV, size_t IVLen);

/**
 * @brief Updates the MAC.
 *
 * @param operation Indicates the operation handle.
 * @param chunk Indicates the pointer to the chunk of MAC data.
 * @param chunkSize Indicates the size of the chunk.
 *
 * @since 20
 */
void TEE_MACUpdate(TEE_OperationHandle operation, const void *chunk, size_t chunkSize);

/**
 * @brief MAC Finalizes the MAC operation with a last chunk of message and computes the MAC.
 *
 * @param operation Indicates the operation handle.
 * @param message Indicates the pointer to the buffer containing the last message chunk to MAC.
 * @param messageLen Indicates the length of the message buffer.
 * @param mac Indicates the pointer to the buffer storing the computed MAC.
 * @param macLen Indicates the pointer to the MAC buffer length.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 *         Returns <b>TEE_ERROR_GENERIC</b> if the operation fails due to other errors.
 *
 * @since 20
 */
TEE_Result TEE_MACComputeFinal(TEE_OperationHandle operation, const void *message, size_t messageLen, void *mac,
                               size_t *macLen);

/**
 * @brief Finalizes the MAC operation and compares the MAC with the one passed in.
 *
 * @param operation Indicates the operation handle.
 * @param message Indicates the pointer to the buffer containing the last message chunk to MAC.
 * @param messageLen Indicates the length of the buffer.
 * @param mac Indicates the pointer to the buffer storing the computed MAC.
 * @param macLen Indicates the MAC buffer length.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 *         Returns <b>TEE_ERROR_GENERIC</b> if the operation fails due to other errors.
 *         Returns <b>TEE_ERROR_MAC_INVALID</b> if the computed MAC is not the same as that passed in.
 *
 * @since 20
 */
TEE_Result TEE_MACCompareFinal(TEE_OperationHandle operation, const void *message, size_t messageLen, const void *mac,
                               const size_t macLen);

/**
 * @brief Derives a key.
 *
 * @param operation Indicates the operation handle.
 * @param params Indicates the pointer to the parameters for this operation.
 * @param paramCount Indicates the number of parameters.
 * @param derivedKey Indicates the derived key.
 *
 * @since 20
 */
void TEE_DeriveKey(TEE_OperationHandle operation, const TEE_Attribute *params, uint32_t paramCount,
                   TEE_ObjectHandle derivedKey);

/**
 * @brief Generates random data.
 *
 * @param randomBuffer Indicates the pointer to the buffer storing the random data generated.
 * @param randomBufferLen Indicates the length of the buffer storing the random data.
 *
 * @since 20
 */
void TEE_GenerateRandom(void *randomBuffer, size_t randomBufferLen);

/**
 * @brief Initializes an AE operation.
 *
 * @param operation Indicates the operation handle.
 * @param nonce Indicates the pointer to the buffer for storing the nonce.
 * @param nonceLen Indicates the length of the nonce.
 * @param tagLen Indicates the length of the tag.
 * @param AADLen Indicates the length of the AAD.
 * @param payloadLen Indicates the length of the payload.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 *         Returns <b>TEE_ERROR_GENERIC</b> if the operation fails due to other errors.
 *
 * @since 20
 */
TEE_Result TEE_AEInit(TEE_OperationHandle operation, void *nonce, size_t nonceLen, uint32_t tagLen, size_t AADLen,
                      size_t payloadLen);

/**
 * @brief Updates the AAD in an AE operation.
 *
 * @param operation Indicates the operation handle.
 * @param AADdata Indicates the pointer to the new AAD.
 * @param AADdataLen Indicates the length of the new AAD.
 *
 * @since 20
 */
void TEE_AEUpdateAAD(TEE_OperationHandle operation, const void *AADdata, size_t AADdataLen);

/**
 * @brief Updates data for an AE operation.
 *
 * @param operation Indicates the operation handle.
 * @param srcData Indicates the pointer to the source data.
 * @param srcLen Indicates the length of the source data.
 * @param destData Indicates the pointer to the destination data.
 * @param destLen Indicates the pointer to the destination data length.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 *         Returns <b>TEE_ERROR_GENERIC</b> if the operation fails due to other errors.
 *
 * @since 20
 */
TEE_Result TEE_AEUpdate(TEE_OperationHandle operation, void *srcData, size_t srcLen, void *destData, size_t *destLen);

/**
 * @brief Finalizes the AE encryption operation.
 *
 * @param operation Indicates the operation handle.
 * @param srcData Indicates the pointer to the source data.
 * @param srcLen Indicates the length of the source data.
 * @param destData Indicates the pointer to the destination data.
 * @param destLen Indicates the pointer to the destination data length.
 * @param tag Indicates the pointer to the buffer storing the computed tag.
 * @param tagLen Indicates the pointer to the tag buffer length.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 *         Returns <b>TEE_ERROR_GENERIC</b> if the operation fails due to other errors.
 *
 * @since 20
 */
TEE_Result TEE_AEEncryptFinal(TEE_OperationHandle operation, void *srcData, size_t srcLen, void *destData,
                              size_t *destLen, void *tag, size_t *tagLen);

/**
 * @brief Finalizes an AE decryption operation.
 *
 * @param operation Indicates the operation handle.
 * @param srcData Indicates the pointer to the source data.
 * @param srcLen Indicates the length of the source data.
 * @param destData Indicates the pointer to the destination data.
 * @param destLen Indicates the pointer to the destination data length.
 * @param tag Indicates the pointer to the buffer storing the computed tag.
 * @param tagLen Indicates the tag buffer length.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 *         Returns <b>TEE_ERROR_MAC_INVALID</b> if the computed tag does not match the provided tag.
 *
 * @since 20
 */
TEE_Result TEE_AEDecryptFinal(TEE_OperationHandle operation, void *srcData, size_t srcLen, void *destData,
                              size_t *destLen, void *tag, size_t tagLen);

/**
 * @brief Performs asymmetric encryption.
 *
 * @param operation Indicates the operation handle.
 * @param params Indicates the pointer to the parameters for this operation.
 * @param paramCount Indicates the number of parameters.
 * @param srcData Indicates the pointer to the source data.
 * @param srcLen Indicates the length of the source data.
 * @param destData Indicates the pointer to the destination data.
 * @param destLen Indicates the pointer to the destination data length.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 *         Returns <b>TEE_ERROR_BAD_PARAMETERS</b> if the operation fails due to invalid parameters.
 *         Returns <b>TEE_ERROR_GENERIC</b> if the operation fails due to other errors.
 *
 * @since 20
 */
TEE_Result TEE_AsymmetricEncrypt(TEE_OperationHandle operation, const TEE_Attribute *params, uint32_t paramCount,
                                 void *srcData, size_t srcLen, void *destData, size_t *destLen);

/**
 * @brief Performs asymmetric decryption.
 *
 * @param operation Indicates the operation handle.
 * @param params Indicates the pointer to the parameters for this operation.
 * @param paramCount Indicates the number of parameters.
 * @param srcData Indicates the pointer to the source data.
 * @param srcLen Indicates the length of the source data.
 * @param destData Indicates the pointer to the destination data.
 * @param destLen Indicates the pointer to the destination data length.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 *         Returns <b>TEE_ERROR_BAD_PARAMETERS</b> if the operation fails due to invalid parameters.
 *         Returns <b>TEE_ERROR_GENERIC</b> if the operation fails due to other errors.
 *
 * @since 20
 */
TEE_Result TEE_AsymmetricDecrypt(TEE_OperationHandle operation, const TEE_Attribute *params, uint32_t paramCount,
                                 void *srcData, size_t srcLen, void *destData, size_t *destLen);

/**
 * @brief Signs a message digest in an asymmetric operation.
 *
 * @param operation Indicates the operation handle.
 * @param params Indicates the pointer to the parameters for this operation.
 * @param paramCount Indicates the number of parameters.
 * @param digest Indicates the pointer to the message digest.
 * @param digestLen Indicates the digest length.
 * @param signature Indicates the pointer to the signature.
 * @param signatureLen Indicates the pointer to the signature length.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 *         Returns <b>TEE_ERROR_BAD_PARAMETERS</b> if the operation fails due to invalid parameters.
 *         Returns <b>TEE_ERROR_GENERIC</b> if the operation fails due to other errors.
 *
 * @since 20
 */
TEE_Result TEE_AsymmetricSignDigest(TEE_OperationHandle operation, const TEE_Attribute *params, uint32_t paramCount,
                                    void *digest, size_t digestLen, void *signature, size_t *signatureLen);

/**
 * @brief Verifies a message digest signature in an asymmetric operation.
 *
 * @param operation Indicates the operation handle.
 * @param params Indicates the pointer to the parameters for this operation.
 * @param paramCount Indicates the number of parameters.
 * @param digest Indicates the pointer to the message digest.
 * @param digestLen Indicates the digest length.
 * @param signature Indicates the pointer to the signature.
 * @param signatureLen Indicates the signature length.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 *         Returns <b>TEE_ERROR_BAD_PARAMETERS</b> if the operation fails due to invalid parameters.
 *         Returns <b>TEE_ERROR_GENERIC</b> if the operation fails due to other errors.
 *
 * @since 20
 */
TEE_Result TEE_AsymmetricVerifyDigest(TEE_OperationHandle operation, const TEE_Attribute *params, uint32_t paramCount,
                                      void *digest, size_t digestLen, void *signature, size_t signatureLen);

/**
 * @brief Obtains information about the operation involving multiple keys.
 *
 * @param operation Indicates the operation handle.
 * @param operationInfoMultiple Indicates the pointer to the operation information obtained.
 * @param operationSize [IN/OUT] Indicates the pointer to the operation information size.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 *         Returns <b>TEE_ERROR_BAD_PARAMETERS</b> if the operation fails due to invalid parameters.
 *         Returns <b>TEE_ERROR_SHORT_BUFFER</b> if the operationInfo buffer is not large enough to
 * hold the information obtained.
 *
 * @since 20
 */
TEE_Result TEE_GetOperationInfoMultiple(TEE_OperationHandle operation, TEE_OperationInfoMultiple *operationInfoMultiple,
                                        const size_t *operationSize);

/**
 * @brief Checks whether the algorithm is supported.
 *
 * @param algId Indicates the algorithm to check.
 * @param element Indicates the cryptographic element.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the algorithm is supported.
 *         Returns <b>TEE_ERROR_NOT_SUPPORTED</b> otherwise.
 *
 * @since 20
 */
TEE_Result TEE_IsAlgorithmSupported(uint32_t algId, uint32_t element);

#ifdef __cplusplus
}
#endif

#endif
/** @} */