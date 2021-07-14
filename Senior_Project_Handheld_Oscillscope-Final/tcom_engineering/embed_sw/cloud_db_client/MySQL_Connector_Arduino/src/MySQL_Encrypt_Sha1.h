/*
 * GNU GPL v3
 *
 * This file is part of the code entitled, "cryptosuite" available at
 * https://code.google.com/p/cryptosuite/. The file was copied from that
 * repository and renamed for use in Connector/Arduino to preserve
 * compatibility and protect against namespace collisions for users who
 * want to use the full cryptosuite functionality. For Connector/Arduino
 * all that is needed is this one sha1 class.
*/
#ifndef ENCRYPT_SHA1_H
#define ENCRYPT_SHA1_H

#include <stdint.h>

#define HASH_LENGTH 20
#define BLOCK_LENGTH 64

union _buffer {
  uint8_t b[BLOCK_LENGTH];
  uint32_t w[BLOCK_LENGTH/4];
};
union _state {
  uint8_t b[HASH_LENGTH];
  uint32_t w[HASH_LENGTH/4];
};

struct Encrypt_SHA1_Print
{
    _buffer buffer;
    uint8_t bufferOffset;
    _state state;
    uint32_t byteCount;
    uint8_t keyBuffer[BLOCK_LENGTH];
    uint8_t innerHash[HASH_LENGTH];
};

extern Encrypt_SHA1 Sha1;

#endif
