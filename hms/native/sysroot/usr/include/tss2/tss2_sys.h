/**
 * Licenses and Notices
 * 1. Copyright Licenses:
 *    Trusted Computing Group (TCG) grants to the user of the source code in this
 *  specification (the “Source Code”) a worldwide, irrevocable, nonexclusive, royalty free,
 *  copyright license to reproduce, create derivative works, distribute, display and perform
 *  the Source Code and derivative works thereof, and to grant others the rights granted
 *  herein.
 *    The TCG grants to the user of the other parts of the specification (other than the Source
 *  Code) the rights to reproduce, distribute, display, and perform the specification solely for
 *  the purpose of developing products based on such documents.
 * 2. Source Code Distribution Conditions:
 *    Redistributions of Source Code must retain the above copyright licenses, this list of
 *  conditions and the following disclaimers.
 *    Redistributions in binary form must reproduce the above copyright licenses, this list of
 *  conditions and the following disclaimers in the documentation and/or other materials
 *  provided with the distribution.
 * 3. Disclaimers:
 *    THE COPYRIGHT LICENSES SET FORTH ABOVE DO NOT REPRESENT ANY FORM
 *  OF LICENSE OR WAIVER, EXPRESS OR IMPLIED, BY ESTOPPEL OR OTHERWISE,
 *  WITH RESPECT TO PATENT RIGHTS HELD BY TCG MEMBERS (OR OTHER THIRD
 *  PARTIES) THAT MAY BE NECESSARY TO IMPLEMENT THIS SPECIFICATION OR
 *  OTHERWISE. Contact TCG Administration, admin@trustedcomputinggroup.org, for
 *  information on specification licensing rights available through TCG membership
 *  agreements.
 *    THIS SPECIFICATION IS PROVIDED "AS IS" WITH NO EXPRESS OR IMPLIED
 *  WARRANTIES WHATSOEVER, INCLUDING ANY WARRANTY OF
 *  MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, ACCURACY,
 *  COMPLETENESS, OR NONINFRINGEMENT OF INTELLECTUAL PROPERTY
 *  RIGHTS, OR ANY WARRANTY OTHERWISE ARISING OUT OF ANY PROPOSAL,
 *  SPECIFICATION OR SAMPLE.
 *    Without limitation, TCG and its members and licensors disclaim all liability, including
 *  liability for infringement of any proprietary rights, relating to use of information in this
 *  specification and to the implementation of this specification, and TCG disclaims all liability
 *  for cost of procurement of substitute goods or services, lost profits, loss of use, loss of
 *  data or any incidental, consequential, direct, indirect, or special damages, whether under
 *  contract, tort, warranty or otherwise, arising in any way out of use or reliance upon this
 *  specification or any information herein.
 * 
 */

/**
 * References:
 * TCG TSS 2.0 System Level API (SAPI) Specification Version 1.1 Revision 36, October 1 2021
 */

/**
 * @addtogroup tss2
 * @{
 *
 * @brief Provides APIs for tss2.
 *
 * @since 6.0.0(20)
 */

/**
 * @file tss2_sys.h
 *
 * @brief Defines SAPI(System Level API) for tss2.
 *
 * Allows you to call TPM command.
 *
 * @library libtss2-sys.so
 * @since 6.0.0(20)
 */
#ifndef TSS2_SYS_H
#define TSS2_SYS_H

#include <stdlib.h>
#include "tss2_common.h"
#include "tss2_tpm2_types.h"
#include "tss2_tcti.h"

#ifndef TSS2_API_VERSION_1_2_1_108
#error Version mismatch among TSS2 header files.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * System API Structures
 */

/* Opaque context structure */
typedef struct TSS2_SYS_OPAQUE_CONTEXT_BLOB TSS2_SYS_CONTEXT;

/* Maximum number of sessions supported in a command */
#define TSS2_SYS_MAX_SESSIONS 3

/* Structures to hold authorization data to and from the TPM */
typedef struct {
    uint16_t count;
    TPMS_AUTH_COMMAND auths[TSS2_SYS_MAX_SESSIONS];
} TSS2L_SYS_AUTH_COMMAND;

typedef struct {
    uint16_t count;
    TPMS_AUTH_RESPONSE auths[TSS2_SYS_MAX_SESSIONS];
} TSS2L_SYS_AUTH_RESPONSE;

/*
 * System API Context Management Functions
*/
TSS2_DLL_EXPORT size_t Tss2_Sys_GetContextSize(
    size_t maxCommandResponseSize);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Initialize(
    TSS2_SYS_CONTEXT *sysContext,
    size_t contextSize,
    TSS2_TCTI_CONTEXT *tctiContext,
    TSS2_ABI_VERSION *abiVersion);

TSS2_DLL_EXPORT void Tss2_Sys_Finalize(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_GetTctiContext(
    TSS2_SYS_CONTEXT *sysContext,
    TSS2_TCTI_CONTEXT **tctiContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_SetCmdAuths(
    TSS2_SYS_CONTEXT *sysContext,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ExecuteAsync(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ExecuteFinish(
    TSS2_SYS_CONTEXT *sysContext,
    int32_t timeout);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Execute(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_GetRspAuths(
    TSS2_SYS_CONTEXT *sysContext,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

/*
 * The following functions are the Prepare, Complete, and One-Shot
 * functions corresponding to each command in part 3 of the TPM
 * specification.
*/
TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Startup_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2_SU startupType);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Startup_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Startup(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2_SU startupType);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Shutdown_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2_SU shutdownType);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Shutdown_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Shutdown(
    TSS2_SYS_CONTEXT *sysContext,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2_SU shutdownType,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_SelfTest_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_YES_NO fullTest);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_SelfTest_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_SelfTest(
    TSS2_SYS_CONTEXT *sysContext,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPMI_YES_NO fullTest,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_IncrementalSelfTest_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPML_ALG const *toTest);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_IncrementalSelfTest_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPML_ALG *toDoList);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_IncrementalSelfTest(
    TSS2_SYS_CONTEXT *sysContext,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPML_ALG const *toTest,
    TPML_ALG *toDoList,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_GetTestResult_Prepare(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_GetTestResult_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_MAX_BUFFER *outData,
    TPM2_RC *testResult);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_GetTestResult(
    TSS2_SYS_CONTEXT *sysContext,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_MAX_BUFFER *outData,
    TPM2_RC *testResult,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_StartAuthSession_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT tpmKey,
    TPMI_DH_ENTITY bind,
    TPM2B_NONCE const *nonceCaller,
    TPM2B_ENCRYPTED_SECRET const *encryptedSalt,
    TPM2_SE sessionType,
    TPMT_SYM_DEF const *symmetric,
    TPMI_ALG_HASH authHash);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_StartAuthSession_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_SH_AUTH_SESSION *sessionHandle,
    TPM2B_NONCE *nonceTPM);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_StartAuthSession(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT tpmKey,
    TPMI_DH_ENTITY bind,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_NONCE const *nonceCaller,
    TPM2B_ENCRYPTED_SECRET const *encryptedSalt,
    TPM2_SE sessionType,
    TPMT_SYM_DEF const *symmetric,
    TPMI_ALG_HASH authHash,
    TPMI_SH_AUTH_SESSION *sessionHandle,
    TPM2B_NONCE *nonceTPM,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyRestart_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_SH_POLICY sessionHandle);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyRestart_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyRestart(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_SH_POLICY sessionHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Create_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT parentHandle,
    TPM2B_SENSITIVE_CREATE const *inSensitive,
    TPM2B_PUBLIC const *inPublic,
    TPM2B_DATA const *outsideInfo,
    TPML_PCR_SELECTION const *creationPCR);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Create_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_PRIVATE *outPrivate,
    TPM2B_PUBLIC *outPublic,
    TPM2B_CREATION_DATA *creationData,
    TPM2B_DIGEST *creationHash,
    TPMT_TK_CREATION *creationTicket);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Create(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT parentHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_SENSITIVE_CREATE const *inSensitive,
    TPM2B_PUBLIC const *inPublic,
    TPM2B_DATA const *outsideInfo,
    TPML_PCR_SELECTION const *creationPCR,
    TPM2B_PRIVATE *outPrivate,
    TPM2B_PUBLIC *outPublic,
    TPM2B_CREATION_DATA *creationData,
    TPM2B_DIGEST *creationHash,
    TPMT_TK_CREATION *creationTicket,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Load_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT parentHandle,
    TPM2B_PRIVATE const *inPrivate,
    TPM2B_PUBLIC const *inPublic);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Load_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2_HANDLE *objectHandle,
    TPM2B_NAME *name);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Load(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT parentHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_PRIVATE const *inPrivate,
    TPM2B_PUBLIC const *inPublic,
    TPM2_HANDLE *objectHandle,
    TPM2B_NAME *name,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_LoadExternal_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_SENSITIVE const *inPrivate,
    TPM2B_PUBLIC const *inPublic,
    TPMI_RH_HIERARCHY hierarchy);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_LoadExternal_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2_HANDLE *objectHandle,
    TPM2B_NAME *name);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_LoadExternal(
    TSS2_SYS_CONTEXT *sysContext,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_SENSITIVE const *inPrivate,
    TPM2B_PUBLIC const *inPublic,
    TPMI_RH_HIERARCHY hierarchy,
    TPM2_HANDLE *objectHandle,
    TPM2B_NAME *name,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ReadPublic_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT objectHandle);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ReadPublic_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_PUBLIC *outPublic,
    TPM2B_NAME *name,
    TPM2B_NAME *qualifiedName);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ReadPublic(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT objectHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_PUBLIC *outPublic,
    TPM2B_NAME *name,
    TPM2B_NAME *qualifiedName,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ActivateCredential_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT activateHandle,
    TPMI_DH_OBJECT keyHandle,
    TPM2B_ID_OBJECT const *credentialBlob,
    TPM2B_ENCRYPTED_SECRET const *secret);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ActivateCredential_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_DIGEST *certInfo);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ActivateCredential(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT activateHandle,
    TPMI_DH_OBJECT keyHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_ID_OBJECT const *credentialBlob,
    TPM2B_ENCRYPTED_SECRET const *secret,
    TPM2B_DIGEST *certInfo,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_MakeCredential_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT handle,
    TPM2B_DIGEST const *credential,
    TPM2B_NAME const *objectName);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_MakeCredential_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_ID_OBJECT *credentialBlob,
    TPM2B_ENCRYPTED_SECRET *secret);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_MakeCredential(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT handle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_DIGEST const *credential,
    TPM2B_NAME const *objectName,
    TPM2B_ID_OBJECT *credentialBlob,
    TPM2B_ENCRYPTED_SECRET *secret,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Unseal_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT itemHandle);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Unseal_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_SENSITIVE_DATA *outData);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Unseal(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT itemHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_SENSITIVE_DATA *outData,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ObjectChangeAuth_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT objectHandle,
    TPMI_DH_OBJECT parentHandle,
    TPM2B_AUTH const *newAuth);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ObjectChangeAuth_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_PRIVATE *outPrivate);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ObjectChangeAuth(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT objectHandle,
    TPMI_DH_OBJECT parentHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_AUTH const *newAuth,
    TPM2B_PRIVATE *outPrivate,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_CreateLoaded_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_PARENT parentHandle,
    TPM2B_SENSITIVE_CREATE const *inSensitive,
    TPM2B_TEMPLATE const *inPublic);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_CreateLoaded_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2_HANDLE *objectHandle,
    TPM2B_PRIVATE *outPrivate,
    TPM2B_PUBLIC *outPublic,
    TPM2B_NAME *name);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_CreateLoaded(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_PARENT parentHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_SENSITIVE_CREATE const *inSensitive,
    TPM2B_TEMPLATE const *inPublic,
    TPM2_HANDLE *objectHandle,
    TPM2B_PRIVATE *outPrivate,
    TPM2B_PUBLIC *outPublic,
    TPM2B_NAME *name,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Duplicate_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT objectHandle,
    TPMI_DH_OBJECT newParentHandle,
    TPM2B_DATA const *encryptionKeyIn,
    TPMT_SYM_DEF_OBJECT const *symmetricAlg);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Duplicate_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_DATA *encryptionKeyOut,
    TPM2B_PRIVATE *duplicate,
    TPM2B_ENCRYPTED_SECRET *outSymSeed);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Duplicate(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT objectHandle,
    TPMI_DH_OBJECT newParentHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_DATA const *encryptionKeyIn,
    TPMT_SYM_DEF_OBJECT const *symmetricAlg,
    TPM2B_DATA *encryptionKeyOut,
    TPM2B_PRIVATE *duplicate,
    TPM2B_ENCRYPTED_SECRET *outSymSeed,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Rewrap_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT oldParent,
    TPMI_DH_OBJECT newParent,
    TPM2B_PRIVATE const *inDuplicate,
    TPM2B_NAME const *name,
    TPM2B_ENCRYPTED_SECRET const *inSymSeed);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Rewrap_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_PRIVATE *outDuplicate,
    TPM2B_ENCRYPTED_SECRET *outSymSeed);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Rewrap(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT oldParent,
    TPMI_DH_OBJECT newParent,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_PRIVATE const *inDuplicate,
    TPM2B_NAME const *name,
    TPM2B_ENCRYPTED_SECRET const *inSymSeed,
    TPM2B_PRIVATE *outDuplicate,
    TPM2B_ENCRYPTED_SECRET *outSymSeed,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Import_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT parentHandle,
    TPM2B_DATA const *encryptionKey,
    TPM2B_PUBLIC const *objectPublic,
    TPM2B_PRIVATE const *duplicate,
    TPM2B_ENCRYPTED_SECRET const *inSymSeed,
    TPMT_SYM_DEF_OBJECT const *symmetricAlg);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Import_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_PRIVATE *outPrivate);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Import(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT parentHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_DATA const *encryptionKey,
    TPM2B_PUBLIC const *objectPublic,
    TPM2B_PRIVATE const *duplicate,
    TPM2B_ENCRYPTED_SECRET const *inSymSeed,
    TPMT_SYM_DEF_OBJECT const *symmetricAlg,
    TPM2B_PRIVATE *outPrivate,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_RSA_Encrypt_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT keyHandle,
    TPM2B_PUBLIC_KEY_RSA const *message,
    TPMT_RSA_DECRYPT const *inScheme,
    TPM2B_DATA const *label);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_RSA_Encrypt_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_PUBLIC_KEY_RSA *outData);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_RSA_Encrypt(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT keyHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_PUBLIC_KEY_RSA const *message,
    TPMT_RSA_DECRYPT const *inScheme,
    TPM2B_DATA const *label,
    TPM2B_PUBLIC_KEY_RSA *outData,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_RSA_Decrypt_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT keyHandle,
    TPM2B_PUBLIC_KEY_RSA const *cipherText,
    TPMT_RSA_DECRYPT const *inScheme,
    TPM2B_DATA const *label);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_RSA_Decrypt_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_PUBLIC_KEY_RSA *message);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_RSA_Decrypt(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT keyHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_PUBLIC_KEY_RSA const *cipherText,
    TPMT_RSA_DECRYPT const *inScheme,
    TPM2B_DATA const *label,
    TPM2B_PUBLIC_KEY_RSA *message,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ECDH_KeyGen_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT keyHandle);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ECDH_KeyGen_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_ECC_POINT *zPoint,
    TPM2B_ECC_POINT *pubPoint);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ECDH_KeyGen(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT keyHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_ECC_POINT *zPoint,
    TPM2B_ECC_POINT *pubPoint,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ECDH_ZGen_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT keyHandle,
    TPM2B_ECC_POINT const *inPoint);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ECDH_ZGen_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_ECC_POINT *outPoint);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ECDH_ZGen(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT keyHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_ECC_POINT const *inPoint,
    TPM2B_ECC_POINT *outPoint,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ECC_Parameters_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_ECC_CURVE curveID);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ECC_Parameters_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPMS_ALGORITHM_DETAIL_ECC *parameters);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ECC_Parameters(
    TSS2_SYS_CONTEXT *sysContext,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPMI_ECC_CURVE curveID,
    TPMS_ALGORITHM_DETAIL_ECC *parameters,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ZGen_2Phase_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT keyA,
    TPM2B_ECC_POINT const *inQsB,
    TPM2B_ECC_POINT const *inQeB,
    TPMI_ECC_KEY_EXCHANGE inScheme,
    UINT16 counter);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ZGen_2Phase_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_ECC_POINT *outZ1,
    TPM2B_ECC_POINT *outZ2);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ZGen_2Phase(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT keyA,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_ECC_POINT const *inQsB,
    TPM2B_ECC_POINT const *inQeB,
    TPMI_ECC_KEY_EXCHANGE inScheme,
    UINT16 counter,
    TPM2B_ECC_POINT *outZ1,
    TPM2B_ECC_POINT *outZ2,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_EncryptDecrypt_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT keyHandle,
    TPMI_YES_NO decrypt,
    TPMI_ALG_CIPHER_MODE mode,
    TPM2B_IV const *ivIn,
    TPM2B_MAX_BUFFER const *inData);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_EncryptDecrypt_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_MAX_BUFFER *outData,
    TPM2B_IV *ivOut);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_EncryptDecrypt(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT keyHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPMI_YES_NO decrypt,
    TPMI_ALG_SYM_MODE mode,
    TPM2B_IV const *ivIn,
    TPM2B_MAX_BUFFER const *inData,
    TPM2B_MAX_BUFFER *outData,
    TPM2B_IV *ivOut,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_EncryptDecrypt2_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT keyHandle,
    TPM2B_MAX_BUFFER const *inData,
    TPMI_YES_NO decrypt,
    TPMI_ALG_CIPHER_MODE mode,
    TPM2B_IV const *ivIn);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_EncryptDecrypt2_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_MAX_BUFFER *outData,
    TPM2B_IV *ivOut);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_EncryptDecrypt2(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT keyHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_MAX_BUFFER const *inData,
    TPMI_YES_NO decrypt,
    TPMI_ALG_SYM_MODE mode,
    TPM2B_IV const *ivIn,
    TPM2B_MAX_BUFFER *outData,
    TPM2B_IV *ivOut,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Hash_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_MAX_BUFFER const *data,
    TPMI_ALG_HASH hashAlg,
    TPMI_RH_HIERARCHY hierarchy);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Hash_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_DIGEST *outHash,
    TPMT_TK_HASHCHECK *validation);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Hash(
    TSS2_SYS_CONTEXT *sysContext,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_MAX_BUFFER const *data,
    TPMI_ALG_HASH hashAlg,
    TPMI_RH_HIERARCHY hierarchy,
    TPM2B_DIGEST *outHash,
    TPMT_TK_HASHCHECK *validation,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_HMAC_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT handle,
    TPM2B_MAX_BUFFER const *buffer,
    TPMI_ALG_HASH hashAlg);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_HMAC_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_DIGEST *outHMAC);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_HMAC(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT handle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_MAX_BUFFER const *buffer,
    TPMI_ALG_HASH hashAlg,
    TPM2B_DIGEST *outHMAC,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_GetRandom_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    UINT16 bytesRequested);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_GetRandom_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_DIGEST *randomBytes);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_GetRandom(
    TSS2_SYS_CONTEXT *sysContext,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    UINT16 bytesRequested,
    TPM2B_DIGEST *randomBytes,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_StirRandom_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_SENSITIVE_DATA const *inData);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_StirRandom_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_StirRandom(
    TSS2_SYS_CONTEXT *sysContext,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_SENSITIVE_DATA const *inData,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_HashSequenceStart_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_AUTH const *auth,
    TPMI_ALG_HASH hashAlg);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_HashSequenceStart_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT *sequenceHandle);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_HashSequenceStart(
    TSS2_SYS_CONTEXT *sysContext,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_AUTH const *auth,
    TPMI_ALG_HASH hashAlg,
    TPMI_DH_OBJECT *sequenceHandle,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_SequenceUpdate_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT sequenceHandle,
    TPM2B_MAX_BUFFER const *buffer);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_SequenceUpdate_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_SequenceUpdate(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT sequenceHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_MAX_BUFFER const *buffer,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_SequenceComplete_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT sequenceHandle,
    TPM2B_MAX_BUFFER const *buffer,
    TPMI_RH_HIERARCHY hierarchy);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_SequenceComplete_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_DIGEST *result,
    TPMT_TK_HASHCHECK *validation);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_SequenceComplete(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT sequenceHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_MAX_BUFFER const *buffer,
    TPMI_RH_HIERARCHY hierarchy,
    TPM2B_DIGEST *result,
    TPMT_TK_HASHCHECK *validation,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Certify_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT objectHandle,
    TPMI_DH_OBJECT signHandle,
    TPM2B_DATA const *qualifyingData,
    TPMT_SIG_SCHEME const *inScheme);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Certify_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_ATTEST *certifyInfo,
    TPMT_SIGNATURE *signature);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Certify(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT objectHandle,
    TPMI_DH_OBJECT signHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_DATA const *qualifyingData,
    TPMT_SIG_SCHEME const *inScheme,
    TPM2B_ATTEST *certifyInfo,
    TPMT_SIGNATURE *signature,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_CertifyCreation_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT signHandle,
    TPMI_DH_OBJECT objectHandle,
    TPM2B_DATA const *qualifyingData,
    TPM2B_DIGEST const *creationHash,
    TPMT_SIG_SCHEME const *inScheme,
    TPMT_TK_CREATION const *creationTicket);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_CertifyCreation_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_ATTEST *certifyInfo,
    TPMT_SIGNATURE *signature);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_CertifyCreation(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT signHandle,
    TPMI_DH_OBJECT objectHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_DATA const *qualifyingData,
    TPM2B_DIGEST const *creationHash,
    TPMT_SIG_SCHEME const *inScheme,
    TPMT_TK_CREATION const *creationTicket,
    TPM2B_ATTEST *certifyInfo,
    TPMT_SIGNATURE *signature,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Quote_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT signHandle,
    TPM2B_DATA const *qualifyingData,
    TPMT_SIG_SCHEME const *inScheme,
    TPML_PCR_SELECTION const *PCRselect);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Quote_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_ATTEST *quoted,
    TPMT_SIGNATURE *signature);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Quote(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT signHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_DATA const *qualifyingData,
    TPMT_SIG_SCHEME const *inScheme,
    TPML_PCR_SELECTION const *PCRselect,
    TPM2B_ATTEST *quoted,
    TPMT_SIGNATURE *signature,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Commit_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT signHandle,
    TPM2B_ECC_POINT const *P1,
    TPM2B_SENSITIVE_DATA const *s2,
    TPM2B_ECC_PARAMETER const *y2);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Commit_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_ECC_POINT *K,
    TPM2B_ECC_POINT *L,
    TPM2B_ECC_POINT *E,
    UINT16 *counter);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Commit(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT signHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_ECC_POINT const *P1,
    TPM2B_SENSITIVE_DATA const *s2,
    TPM2B_ECC_PARAMETER const *y2,
    TPM2B_ECC_POINT *K,
    TPM2B_ECC_POINT *L,
    TPM2B_ECC_POINT *E,
    UINT16 *counter,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_EC_Ephemeral_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_ECC_CURVE curveID);
TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_EC_Ephemeral_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_ECC_POINT *Q,
    UINT16 *counter);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_EC_Ephemeral(
    TSS2_SYS_CONTEXT *sysContext,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPMI_ECC_CURVE curveID,
    TPM2B_ECC_POINT *Q,
    UINT16 *counter,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_VerifySignature_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT keyHandle,
    TPM2B_DIGEST const *digest,
    TPMT_SIGNATURE const *signature);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_VerifySignature_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPMT_TK_VERIFIED *validation);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_VerifySignature(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT keyHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_DIGEST const *digest,
    TPMT_SIGNATURE const *signature,
    TPMT_TK_VERIFIED *validation,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Sign_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT keyHandle,
    TPM2B_DIGEST const *digest,
    TPMT_SIG_SCHEME const *inScheme,
    TPMT_TK_HASHCHECK const *validation);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Sign_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPMT_SIGNATURE *signature);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Sign(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT keyHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_DIGEST const *digest,
    TPMT_SIG_SCHEME const *inScheme,
    TPMT_TK_HASHCHECK const *validation,
    TPMT_SIGNATURE *signature,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PCR_Extend_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_PCR pcrHandle,
    TPML_DIGEST_VALUES const *digests);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PCR_Extend_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PCR_Extend(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_PCR pcrHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPML_DIGEST_VALUES const *digests,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PCR_Event_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_PCR pcrHandle,
    TPM2B_EVENT const *eventData);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PCR_Event_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPML_DIGEST_VALUES *digests);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PCR_Event(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_PCR pcrHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_EVENT const *eventData,
    TPML_DIGEST_VALUES *digests,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PCR_Read_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPML_PCR_SELECTION const *pcrSelectionIn);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PCR_Read_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    UINT32 *pcrUpdateCounter,
    TPML_PCR_SELECTION *pcrSelectionOut,
    TPML_DIGEST *pcrValues);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PCR_Read(
    TSS2_SYS_CONTEXT *sysContext,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPML_PCR_SELECTION const *pcrSelectionIn,
    UINT32 *pcrUpdateCounter,
    TPML_PCR_SELECTION *pcrSelectionOut,
    TPML_DIGEST *pcrValues,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PCR_Allocate_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_PLATFORM authHandle,
    TPML_PCR_SELECTION const *pcrAllocation);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PCR_Allocate_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_YES_NO *allocationSuccess,
    UINT32 *maxPCR,
    UINT32 *sizeNeeded,
    UINT32 *sizeAvailable);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PCR_Allocate(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_PLATFORM authHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPML_PCR_SELECTION const *pcrAllocation,
    TPMI_YES_NO *allocationSuccess,
    UINT32 *maxPCR,
    UINT32 *sizeNeeded,
    UINT32 *sizeAvailable,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PCR_Reset_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_PCR pcrHandle);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PCR_Reset_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PCR_Reset(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_PCR pcrHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicySigned_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT authObject,
    TPMI_SH_POLICY policySession,
    TPM2B_NONCE const *nonceTPM,
    TPM2B_DIGEST const *cpHashA,
    TPM2B_NONCE const *policyRef,
    INT32 expiration,
    TPMT_SIGNATURE const *auth);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicySigned_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_TIMEOUT *timeout,
    TPMT_TK_AUTH *policyTicket);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicySigned(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_OBJECT authObject,
    TPMI_SH_POLICY policySession,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_NONCE const *nonceTPM,
    TPM2B_DIGEST const *cpHashA,
    TPM2B_NONCE const *policyRef,
    INT32 expiration,
    TPMT_SIGNATURE const *auth,
    TPM2B_TIMEOUT *timeout,
    TPMT_TK_AUTH *policyTicket,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicySecret_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_ENTITY authHandle,
    TPMI_SH_POLICY policySession,
    TPM2B_NONCE const *nonceTPM,
    TPM2B_DIGEST const *cpHashA,
    TPM2B_NONCE const *policyRef,
    INT32 expiration);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicySecret_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_TIMEOUT *timeout,
    TPMT_TK_AUTH *policyTicket);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicySecret(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_ENTITY authHandle,
    TPMI_SH_POLICY policySession,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_NONCE const *nonceTPM,
    TPM2B_DIGEST const *cpHashA,
    TPM2B_NONCE const *policyRef,
    INT32 expiration,
    TPM2B_TIMEOUT *timeout,
    TPMT_TK_AUTH *policyTicket,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyTicket_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_SH_POLICY policySession,
    TPM2B_TIMEOUT const *timeout,
    TPM2B_DIGEST const *cpHashA,
    TPM2B_NONCE const *policyRef,
    TPM2B_NAME const *authName,
    TPMT_TK_AUTH const *ticket);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyTicket_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyTicket(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_SH_POLICY policySession,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_TIMEOUT const *timeout,
    TPM2B_DIGEST const *cpHashA,
    TPM2B_NONCE const *policyRef,
    TPM2B_NAME const *authName,
    TPMT_TK_AUTH const *ticket,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyOR_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_SH_POLICY policySession,
    TPML_DIGEST const *policyHashList);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyOR_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyOR(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_SH_POLICY policySession,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPML_DIGEST const *policyHashList,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyPCR_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_SH_POLICY policySession,
    TPM2B_DIGEST const *pcrDigest,
    TPML_PCR_SELECTION const *pcrs);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyPCR_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyPCR(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_SH_POLICY policySession,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_DIGEST const *pcrDigest,
    TPML_PCR_SELECTION const *pcrs,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyCommandCode_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_SH_POLICY policySession,
    TPM2_CC code);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyCommandCode_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyCommandCode(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_SH_POLICY policySession,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2_CC code,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyCpHash_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_SH_POLICY policySession,
    TPM2B_DIGEST const *cpHashA);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyCpHash_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyCpHash(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_SH_POLICY policySession,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_DIGEST const *cpHashA,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyAuthValue_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_SH_POLICY policySession);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyAuthValue_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyAuthValue(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_SH_POLICY policySession,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyPassword_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_SH_POLICY policySession);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyPassword_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyPassword(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_SH_POLICY policySession,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyGetDigest_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_SH_POLICY policySession);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyGetDigest_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_DIGEST *policyDigest);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_PolicyGetDigest(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_SH_POLICY policySession,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_DIGEST *policyDigest,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_CreatePrimary_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_HIERARCHY primaryHandle,
    TPM2B_SENSITIVE_CREATE const *inSensitive,
    TPM2B_PUBLIC const *inPublic,
    TPM2B_DATA const *outsideInfo,
    TPML_PCR_SELECTION const *creationPCR);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_CreatePrimary_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2_HANDLE *objectHandle,
    TPM2B_PUBLIC *outPublic,
    TPM2B_CREATION_DATA *creationData,
    TPM2B_DIGEST *creationHash,
    TPMT_TK_CREATION *creationTicket,
    TPM2B_NAME *name);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_CreatePrimary(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_HIERARCHY primaryHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_SENSITIVE_CREATE const *inSensitive,
    TPM2B_PUBLIC const *inPublic,
    TPM2B_DATA const *outsideInfo,
    TPML_PCR_SELECTION const *creationPCR,
    TPM2_HANDLE *objectHandle,
    TPM2B_PUBLIC *outPublic,
    TPM2B_CREATION_DATA *creationData,
    TPM2B_DIGEST *creationHash,
    TPMT_TK_CREATION *creationTicket,
    TPM2B_NAME *name,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_HierarchyControl_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_HIERARCHY authHandle,
    TPMI_RH_ENABLES enable,
    TPMI_YES_NO state);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_HierarchyControl_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_HierarchyControl(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_HIERARCHY authHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPMI_RH_ENABLES enable,
    TPMI_YES_NO state,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Clear_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_CLEAR authHandle);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Clear_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_Clear(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_CLEAR authHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ClearControl_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_CLEAR auth,
    TPMI_YES_NO disable);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ClearControl_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ClearControl(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_CLEAR auth,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPMI_YES_NO disable,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_HierarchyChangeAuth_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_HIERARCHY_AUTH authHandle,
    TPM2B_AUTH const *newAuth);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_HierarchyChangeAuth_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_HierarchyChangeAuth(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_HIERARCHY_AUTH authHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_AUTH const *newAuth,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_DictionaryAttackLockReset_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_LOCKOUT lockHandle);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_DictionaryAttackLockReset_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_DictionaryAttackLockReset(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_LOCKOUT lockHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_DictionaryAttackParameters_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_LOCKOUT lockHandle,
    UINT32 newMaxTries,
    UINT32 newRecoveryTime,
    UINT32 lockoutRecovery);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_DictionaryAttackParameters_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_DictionaryAttackParameters(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_LOCKOUT lockHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    UINT32 newMaxTries,
    UINT32 newRecoveryTime,
    UINT32 lockoutRecovery,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ContextSave_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_CONTEXT saveHandle);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ContextSave_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPMS_CONTEXT *context);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ContextSave(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_CONTEXT saveHandle,
    TPMS_CONTEXT *context);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ContextLoad_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMS_CONTEXT const *context);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ContextLoad_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_CONTEXT *loadedHandle);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_ContextLoad(
    TSS2_SYS_CONTEXT *sysContext,
    TPMS_CONTEXT const *context,
    TPMI_DH_CONTEXT *loadedHandle);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_FlushContext_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_CONTEXT flushHandle);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_FlushContext_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_FlushContext(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_DH_CONTEXT flushHandle);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_EvictControl_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_PROVISION auth,
    TPMI_DH_OBJECT objectHandle,
    TPMI_DH_PERSISTENT persistentHandle);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_EvictControl_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_EvictControl(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_PROVISION auth,
    TPMI_DH_OBJECT objectHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPMI_DH_PERSISTENT persistentHandle,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_GetCapability_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2_CAP capability,
    UINT32 property,
    UINT32 propertyCount);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_GetCapability_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_YES_NO *moreData,
    TPMS_CAPABILITY_DATA *capabilityData);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_GetCapability(
    TSS2_SYS_CONTEXT *sysContext,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2_CAP capability,
    UINT32 property,
    UINT32 propertyCount,
    TPMI_YES_NO *moreData,
    TPMS_CAPABILITY_DATA *capabilityData,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_TestParms_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMT_PUBLIC_PARMS const *parameters);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_TestParms_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_TestParms(
    TSS2_SYS_CONTEXT *sysContext,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPMT_PUBLIC_PARMS const *parameters,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_DefineSpace_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_PROVISION authHandle,
    TPM2B_AUTH const *auth,
    TPM2B_NV_PUBLIC const *publicInfo);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_DefineSpace_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_DefineSpace(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_PROVISION authHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_AUTH const *auth,
    TPM2B_NV_PUBLIC const *publicInfo,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_UndefineSpace_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_PROVISION authHandle,
    TPMI_RH_NV_INDEX nvIndex);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_UndefineSpace_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_UndefineSpace(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_PROVISION authHandle,
    TPMI_RH_NV_INDEX nvIndex,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_ReadPublic_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_NV_INDEX nvIndex);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_ReadPublic_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_NV_PUBLIC *nvPublic,
    TPM2B_NAME *nvName);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_ReadPublic(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_NV_INDEX nvIndex,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_NV_PUBLIC *nvPublic,
    TPM2B_NAME *nvName,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_Write_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_NV_AUTH authHandle,
    TPMI_RH_NV_INDEX nvIndex,
    TPM2B_MAX_NV_BUFFER const *data,
    UINT16 offset);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_Write_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_Write(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_NV_AUTH authHandle,
    TPMI_RH_NV_INDEX nvIndex,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_MAX_NV_BUFFER const *data,
    UINT16 offset,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_Increment_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_NV_AUTH authHandle,
    TPMI_RH_NV_INDEX nvIndex);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_Increment_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_Increment(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_NV_AUTH authHandle,
    TPMI_RH_NV_INDEX nvIndex,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_Extend_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_NV_AUTH authHandle,
    TPMI_RH_NV_INDEX nvIndex,
    TPM2B_MAX_NV_BUFFER const *data);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_Extend_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_Extend(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_NV_AUTH authHandle,
    TPMI_RH_NV_INDEX nvIndex,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_MAX_NV_BUFFER const *data,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_SetBits_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_NV_AUTH authHandle,
    TPMI_RH_NV_INDEX nvIndex,
    UINT64 bits);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_SetBits_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_SetBits(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_NV_AUTH authHandle,
    TPMI_RH_NV_INDEX nvIndex,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    UINT64 bits,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_WriteLock_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_NV_AUTH authHandle,
    TPMI_RH_NV_INDEX nvIndex);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_WriteLock_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_WriteLock(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_NV_AUTH authHandle,
    TPMI_RH_NV_INDEX nvIndex,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_GlobalWriteLock_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_PROVISION authHandle);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_GlobalWriteLock_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_GlobalWriteLock(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_PROVISION authHandle,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_Read_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_NV_AUTH authHandle,
    TPMI_RH_NV_INDEX nvIndex,
    UINT16 size,
    UINT16 offset);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_Read_Complete(
    TSS2_SYS_CONTEXT *sysContext,
    TPM2B_MAX_NV_BUFFER *data);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_Read(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_NV_AUTH authHandle,
    TPMI_RH_NV_INDEX nvIndex,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    UINT16 size,
    UINT16 offset,
    TPM2B_MAX_NV_BUFFER *data,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_ReadLock_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_NV_AUTH authHandle,
    TPMI_RH_NV_INDEX nvIndex);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_ReadLock_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_ReadLock(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_NV_AUTH authHandle,
    TPMI_RH_NV_INDEX nvIndex,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_ChangeAuth_Prepare(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_NV_INDEX nvIndex,
    TPM2B_AUTH const *newAuth);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_ChangeAuth_Complete(
    TSS2_SYS_CONTEXT *sysContext);

TSS2_DLL_EXPORT TSS2_RC Tss2_Sys_NV_ChangeAuth(
    TSS2_SYS_CONTEXT *sysContext,
    TPMI_RH_NV_INDEX nvIndex,
    TSS2L_SYS_AUTH_COMMAND const *cmdAuths,
    TPM2B_AUTH const *newAuth,
    TSS2L_SYS_AUTH_RESPONSE *rspAuths);

#ifdef __cplusplus
} /* end extern "C" */
#endif

#endif /* TSS2_SYS_H */
/** @} */