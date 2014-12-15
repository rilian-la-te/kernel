/*
 * Common values for GOST  algorithm
 */

#ifndef _CRYPTO_GOST_H
#define _CRYPTO_GOST_H

#include <linux/types.h>
#include <linux/crypto.h>

#define GOST_MIN_KEY_SIZE	32
#define GOST_MAX_KEY_SIZE	32
#define GOST_KEYSIZE_256	32
#define GOST_BLOCK_SIZE		64
#define GOST_KEYLENGTH		32
#define GOST_KEYLENGTH_U32	(GOST_KEYLENGTH / sizeof(u32))

/*
 * Please ensure that the first two fields are 16-byte aligned
 * relative to the start of the structure, i.e., don't move them!
 */

struct crypto_gost_ctx{  
    u32 key[GOST_KEYLENGTH_U32];  
    u32 key_length;
};  

extern u8 const k8[16];
extern u8 const k7[16];
extern u8 const k6[16];
extern u8 const k5[16];
extern u8 const k4[16];
extern u8 const k3[16];
extern u8 const k2[16];
extern u8 const k1[16];

int crypto_gost_set_key(struct crypto_tfm *tfm, const u8 *in_key,
		unsigned int key_len);
#endif
