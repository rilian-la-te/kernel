/*
 * Copyright (c) 2014, Konstantin Pugin. 
 * Based on Alexey Degtyarev`s implementation.
 * All rights reserved.
 *
 * GOST main header.
 *
 */
 
#ifndef _CRYPTO_STRIBOG_H
#define _CRYPTO_STRIBOG_H
 
#include <linux/types.h>

#define STRIBOG256_DIGEST_SIZE      32

#define STRIBOG512_DIGEST_SIZE      64

#define STRIBOG_BLOCK_SIZE       64

union uint512_u {
    u64 QWORD[8];
};

struct stribog_state {
    union uint512_u hash;
    union uint512_u h;
    union uint512_u N;
    union uint512_u Sigma;
    size_t bufsize;
    u8 buf[STRIBOG_BLOCK_SIZE];
};

struct shash_desc;

extern int crypto_stribog_update(struct shash_desc *desc, const u8* data,
			      unsigned int len);

#endif
