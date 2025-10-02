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
 * TCG TSS 2.0 TPM Command Transmission Interface (TCTI) API Specification, Version 1.0 Revision 18, 24 January 2020
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
 * @file tss2_tctildr.h
 *
 * @brief Defines tctildr APIs for tss2.
 *
 * Allows you to call TPM command.
 *
 * @library libtss2-tctildr.so
 * @since 6.0.0(20)
 */

#ifndef TSS2_TCTILDR_H
#define TSS2_TCTILDR_H

#include "tss2_common.h"
#include "tss2_tcti.h"

#ifdef __cplusplus
extern "C" {
#endif

TSS2_RC Tss2_TctiLdr_Initialize(
    const char *nameConf,
    TSS2_TCTI_CONTEXT **tctiContext);

TSS2_RC Tss2_TctiLdr_Initialize_Ex(
    const char *name,
    const char *conf,
    TSS2_TCTI_CONTEXT **tctiContext);

void Tss2_TctiLdr_Finalize(
    TSS2_TCTI_CONTEXT **tctiContext);

TSS2_RC Tss2_TctiLdr_GetInfo(
    const char *name,
    TSS2_TCTI_INFO **info);

void Tss2_TctiLdr_FreeInfo(
    TSS2_TCTI_INFO **info);

#ifdef __cplusplus
} /* end extern "C" */
#endif

#endif /* TSS2_TCTILDR_H */
/** @} */