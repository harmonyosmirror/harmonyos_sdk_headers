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
 * TCG TSS 2.0 TPM Command Transmission Interface (TCTI) API Specification Version 1.0 Revision 18, 24 January 2020
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
 * @file tss2_tcti.h
 *
 * @brief Defines tcti APIs for tss2.
 *
 * Allows you to call TPM command.
 *
 * @since 6.0.0(20)
 */

#ifndef TSS2_TCTI_H
#define TSS2_TCTI_H

#include <stdint.h>
#include <stddef.h>
#include "tss2_common.h"
#include "tss2_tpm2_types.h"

#ifndef TSS2_API_VERSION_1_2_1_108
#error Version mismatch among TSS2 header files.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
* "Public" TCTI definitions and operations.
*/

/* Define OS-specific TSS2_TCTI_POLL_HANDLE */
#if defined(_POSIX_C_SOURCE)
#include <poll.h>
typedef struct pollfd TSS2_TCTI_POLL_HANDLE;
#else
typedef void TSS2_TCTI_POLL_HANDLE;
#ifndef TSS2_TCTI_SUPPRESS_POLL_WARNINGS
#pragma message "Info: Platform not suported for TCTI_POLL_HANDLES"
#endif /* TSS2_TCTI_SUPPRESS_POLL_WARNINGS */
#endif /* OS selection */

/* Constants used to control timeout behavior */
#define TSS2_TCTI_TIMEOUT_BLOCK -1
#define TSS2_TCTI_TIMEOUT_NONE 0
#define TSS2_TCTI_INFO_SYMBOL "Tss2_Tcti_Info"

/* TSS2_TCTI_CONTEXT is a data structure opaque to the caller. */
typedef struct TSS2_TCTI_OPAQUE_CONTEXT_BLOB TSS2_TCTI_CONTEXT;

/* Type of TCTI initialization function. */
typedef TSS2_RC (*TSS2_TCTI_INIT_FCN)(
    TSS2_TCTI_CONTEXT *tctiContext,
    size_t *size,
    const char *conf);

/* Descriptive data for a TCTI library and its init function */
typedef struct {
    uint32_t version;
    const char *name;
    const char *description;
    const char *conf_help;
    TSS2_TCTI_INIT_FCN init;
} TSS2_TCTI_INFO;

/* Function to expose TCTI library TSS2_TCTI_INFO structure */
typedef const TSS2_TCTI_INFO* (*TSS2_TCTI_INFO_FCN)(void);

/* Macros to simplify invocation of functions from the common TCTI structure */
#define Tss2_Tcti_Transmit(tctiContext, size, command)                        \
        ((tctiContext == NULL) ? TSS2_TCTI_RC_BAD_CONTEXT :                   \
        (TSS2_TCTI_VERSION(tctiContext) < 1) ?                                \
        TSS2_TCTI_RC_ABI_MISMATCH :                                           \
        (TSS2_TCTI_TRANSMIT(tctiContext) == NULL) ?                           \
        TSS2_TCTI_RC_NOT_IMPLEMENTED :                                        \
        TSS2_TCTI_TRANSMIT(tctiContext)(tctiContext, size, command))

#define Tss2_Tcti_Receive(tctiContext, size, response, timeout)               \
    ((tctiContext == NULL) ? TSS2_TCTI_RC_BAD_CONTEXT :                       \
    (TSS2_TCTI_VERSION(tctiContext) < 1) ?                                    \
    TSS2_TCTI_RC_ABI_MISMATCH :                                               \
    (TSS2_TCTI_RECEIVE(tctiContext) == NULL) ?                                \
    TSS2_TCTI_RC_NOT_IMPLEMENTED :                                            \
    TSS2_TCTI_RECEIVE(tctiContext)(tctiContext, size, response, timeout))

#define Tss2_Tcti_Finalize(tctiContext)                                       \
    do {                                                                      \
        if ((tctiContext != NULL) &&                                          \
            (TSS2_TCTI_VERSION(tctiContext) >= 1) &&                          \
            (TSS2_TCTI_FINALIZE(tctiContext) != NULL))                        \
        {                                                                     \
            TSS2_TCTI_FINALIZE(tctiContext)(tctiContext);                     \
        }                                                                     \
    } while (0)

#define Tss2_Tcti_Cancel(tctiContext)                                         \
    ((tctiContext == NULL) ? TSS2_TCTI_RC_BAD_CONTEXT :                       \
    (TSS2_TCTI_VERSION(tctiContext) < 1) ?                                    \
    TSS2_TCTI_RC_ABI_MISMATCH :                                               \
    (TSS2_TCTI_CANCEL(tctiContext) == NULL) ?                                 \
    TSS2_TCTI_RC_NOT_IMPLEMENTED :                                            \
    TSS2_TCTI_CANCEL(tctiContext)(tctiContext))

#define Tss2_Tcti_GetPollHandles(tctiContext, handles, num_handles)           \
    ((tctiContext == NULL) ? TSS2_TCTI_RC_BAD_CONTEXT :                       \
    (TSS2_TCTI_VERSION(tctiContext) < 1) ?                                    \
    TSS2_TCTI_RC_ABI_MISMATCH :                                               \
    (TSS2_TCTI_GET_POLL_HANDLES(tctiContext) == NULL) ?                       \
    TSS2_TCTI_RC_NOT_IMPLEMENTED :                                            \
    TSS2_TCTI_GET_POLL_HANDLES(tctiContext)(tctiContext, handles, num_handles))

#define Tss2_Tcti_SetLocality(tctiContext, locality)                          \
    ((tctiContext == NULL) ? TSS2_TCTI_RC_BAD_CONTEXT :                       \
    (TSS2_TCTI_VERSION(tctiContext) < 1) ?                                    \
    TSS2_TCTI_RC_ABI_MISMATCH :                                               \
    (TSS2_TCTI_SET_LOCALITY(tctiContext) == NULL) ?                           \
    TSS2_TCTI_RC_NOT_IMPLEMENTED :                                            \
    TSS2_TCTI_SET_LOCALITY(tctiContext)(tctiContext, locality))

#define Tss2_Tcti_MakeSticky(tctiContext, handle, sticky)                     \
    ((tctiContext == NULL) ? TSS2_TCTI_RC_BAD_CONTEXT :                       \
    (TSS2_TCTI_VERSION(tctiContext) < 2) ?                                    \
    TSS2_TCTI_RC_ABI_MISMATCH :                                               \
    (TSS2_TCTI_MAKE_STICKY(tctiContext) == NULL) ?                            \
    TSS2_TCTI_RC_NOT_IMPLEMENTED :                                            \
    TSS2_TCTI_MAKE_STICKY(tctiContext)(tctiContext, handle, sticky))

/*
* "Private" TCTI definitions.
*
* All TCTI features can be accessed via the definitions above. It is
* strongly recommended that the following definitions not be used
* directly by callers. These are made public in order to enable
* implementation of the macros above.
*/

/* Function pointer types for the TCTI operations. */
typedef TSS2_RC (*TSS2_TCTI_TRANSMIT_FCN)(
    TSS2_TCTI_CONTEXT *tctiContext,
    size_t size,
    uint8_t const *command);

typedef TSS2_RC (*TSS2_TCTI_RECEIVE_FCN)(
    TSS2_TCTI_CONTEXT *tctiContext,
    size_t *size,
    uint8_t *response,
    int32_t timeout);

typedef void (*TSS2_TCTI_FINALIZE_FCN)(
    TSS2_TCTI_CONTEXT *tctiContext);

typedef TSS2_RC (*TSS2_TCTI_CANCEL_FCN)(
    TSS2_TCTI_CONTEXT *tctiContext);

typedef TSS2_RC (*TSS2_TCTI_GET_POLL_HANDLES_FCN)(
    TSS2_TCTI_CONTEXT *tctiContext,
    TSS2_TCTI_POLL_HANDLE *handles,
    size_t *numHandles);

typedef TSS2_RC (*TSS2_TCTI_SET_LOCALITY_FCN)(
    TSS2_TCTI_CONTEXT *tctiContext,
    uint8_t locality);

typedef TSS2_RC (*TSS2_TCTI_MAKE_STICKY_FCN)(
    TSS2_TCTI_CONTEXT *tctiContext,
    TPM2_HANDLE *handle,
    uint8_t sticky);

typedef struct {
    uint64_t magic;
    uint32_t version;
    TSS2_TCTI_TRANSMIT_FCN transmit;
    TSS2_TCTI_RECEIVE_FCN receive;
    TSS2_TCTI_FINALIZE_FCN finalize;
    TSS2_TCTI_CANCEL_FCN cancel;
    TSS2_TCTI_GET_POLL_HANDLES_FCN getPollHandles;
    TSS2_TCTI_SET_LOCALITY_FCN setLocality;
} TSS2_TCTI_CONTEXT_COMMON_V1;

typedef struct {
    TSS2_TCTI_CONTEXT_COMMON_V1 v1;
    TSS2_TCTI_MAKE_STICKY_FCN makeSticky;
} TSS2_TCTI_CONTEXT_COMMON_V2;

typedef TSS2_TCTI_CONTEXT_COMMON_V2 TSS2_TCTI_CONTEXT_COMMON_CURRENT;

/* Macros to simplify access to values in common TCTI structure */
#define TSS2_TCTI_MAGIC(tctiContext) \
    ((TSS2_TCTI_CONTEXT_COMMON_V1*)tctiContext)->magic

#define TSS2_TCTI_VERSION(tctiContext) \
    ((TSS2_TCTI_CONTEXT_COMMON_V1*)tctiContext)->version

#define TSS2_TCTI_TRANSMIT(tctiContext) \
    ((TSS2_TCTI_CONTEXT_COMMON_V1*)tctiContext)->transmit

#define TSS2_TCTI_RECEIVE(tctiContext) \
    ((TSS2_TCTI_CONTEXT_COMMON_V1*)tctiContext)->receive

#define TSS2_TCTI_FINALIZE(tctiContext) \
    ((TSS2_TCTI_CONTEXT_COMMON_V1*)tctiContext)->finalize

#define TSS2_TCTI_CANCEL(tctiContext) \
    ((TSS2_TCTI_CONTEXT_COMMON_V1*)tctiContext)->cancel

#define TSS2_TCTI_GET_POLL_HANDLES(tctiContext) \
    ((TSS2_TCTI_CONTEXT_COMMON_V1*)tctiContext)->getPollHandles

#define TSS2_TCTI_SET_LOCALITY(tctiContext) \
    ((TSS2_TCTI_CONTEXT_COMMON_V1*)tctiContext)->setLocality

#define TSS2_TCTI_MAKE_STICKY(tctiContext) \
    ((TSS2_TCTI_CONTEXT_COMMON_V2*)tctiContext)->makeSticky

#ifdef __cplusplus
} /* end extern "C" */
#endif

#endif /* TSS2_TCTI_H */
/** @} */