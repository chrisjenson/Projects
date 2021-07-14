#ifndef TCOM_MYSQL_ENCRYPT_SHA1_H
#define TCOM_MYSQL_ENCRYPT_SHA1_H

#include <inttypes.h>
//#include "Print.h"

#define HASH_LENGTH 20
#define BLOCK_LENGTH 64

union _buf {
  uint8_t b[BLOCK_LENGTH];
  uint32_t w[BLOCK_LENGTH/4];
};
union _state {
  uint8_t b[HASH_LENGTH];
  uint32_t w[HASH_LENGTH/4];
};

void sha1_init(void);
void sha1_hashBlock();
void sha1_addUncounted(uint8_t data);
void sha1_pad();
void sha1_write_1(uint8_t data);
void sha1_write_2(uint8_t* data, int length);

uint8_t* sha1_result(void);


//extern Encrypt_SHA1 Sha1;

#endif