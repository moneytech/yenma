/*
 * Copyright (c) 2006-2016 Internet Initiative Japan Inc. All rights reserved.
 *
 * The terms and conditions of the accompanying program
 * shall be provided separately by Internet Initiative Japan Inc.
 * Any use, reproduction or distribution of the program are permitted
 * provided that you agree to be bound to such terms and conditions.
 *
 * $Id$
 */

#ifndef __DKIM_VERIFICATION_POLICY_H__
#define __DKIM_VERIFICATION_POLICY_H__

#include <sys/types.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

struct DkimVerificationPolicy {
    // maximum number of the DKIM signature headers to verify.
    // They are evaluated from the top,
    // and the rest are ignored if the number reaches the limit.
    // 0 means unlimited.
    unsigned int sign_header_limit;
    // maximum number of the Authors to check their policy.
    // 0 for unlimited
    size_t author_limit;
    // RFC4871 compatible mode
    bool rfc4871_compatible;
    // treats expired DKIM signatures as valid
    bool accept_expired_signature;
    // treats DKIM signatures signed in the future as valid
    bool accept_future_signature;
    // turns ATPS functions on
    bool enable_atps;
    // acceptable minimum RSA key strength.
    // 0 means no limitations are applied to RSA key length.
    unsigned int min_rsa_key_length;
    // Maximum number of seconds of clock skew to validate DKIM signatures.
    time_t max_clock_skew;
};

#ifdef __cplusplus
}
#endif

#endif /* __DKIM_VERIFICATION_POLICY_H__ */
