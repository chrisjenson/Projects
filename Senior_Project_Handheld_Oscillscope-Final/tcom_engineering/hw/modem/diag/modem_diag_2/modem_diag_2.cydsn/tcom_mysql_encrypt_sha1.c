/*
 * GNU GPL v3
 *
 * This file is part of the code entitled, "cryptosuite" available at
 * https://code.google.com/p/cryptosuite/. The file was copied from that
 * repository and renamed for use in Connector/Arduino to preserve
 * compatibility and protect against namespace collisions for users who
 * want to use the full cryptosuite functionality. For Connector/Arduino
 * all that is needed is this one sha1 class.
 *
 * Note: #defines renamed to prevent collisions
*/
#include <string.h>
#include "tcom_mysql_encrypt_sha1.h"

#define MYSQL_sha1_K0 0x5a827999
#define MYSQL_sha1_K20 0x6ed9eba1
#define MYSQL_sha1_K40 0x8f1bbcdc
#define MYSQL_sha1_K60 0xca62c1d6

static union _buf buf;
static uint8_t buf_offset;
static union _state state;
static uint32_t byteCount;

const uint8_t sha1InitState[] = {
  0x01,0x23,0x45,0x67, // H0
  0x89,0xab,0xcd,0xef, // H1
  0xfe,0xdc,0xba,0x98, // H2
  0x76,0x54,0x32,0x10, // H3
  0xf0,0xe1,0xd2,0xc3  // H4
};

void sha1_init(void) {
  memcpy(state.b,sha1InitState,HASH_LENGTH);
  byteCount = 0;
  buf_offset = 0;
}

uint32_t sha1_rol32(uint32_t number, uint8_t bits) {
  return ((number << bits) | (number >> (32-bits)));
}

void sha1_hashBlock() {
  // sha1 only for now
  uint8_t i;
  uint32_t a,b,c,d,e,t;

  a=state.w[0];
  b=state.w[1];
  c=state.w[2];
  d=state.w[3];
  e=state.w[4];
  for (i=0; i<80; i++) {
    if (i>=16) {
      t = buf.w[(i+13)&15] ^ buf.w[(i+8)&15] ^ buf.w[(i+2)&15] ^ buf.w[i&15];
      buf.w[i&15] = sha1_rol32(t,1);
    }
    if (i<20) {
      t = (d ^ (b & (c ^ d))) + MYSQL_sha1_K0;
    } else if (i<40) {
      t = (b ^ c ^ d) + MYSQL_sha1_K20;
    } else if (i<60) {
      t = ((b & c) | (d & (b | c))) + MYSQL_sha1_K40;
    } else {
      t = (b ^ c ^ d) + MYSQL_sha1_K60;
    }
    t+= sha1_rol32(a,5) + e + buf.w[i&15];
    e=d;
    d=c;
    c= sha1_rol32(b,30);
    b=a;
    a=t;
  }
  state.w[0] += a;
  state.w[1] += b;
  state.w[2] += c;
  state.w[3] += d;
  state.w[4] += e;
}

void sha1_addUncounted(uint8_t data) {
  buf.b[buf_offset ^ 3] = data;
  buf_offset++;
  if (buf_offset == BLOCK_LENGTH) {
    sha1_hashBlock();
    buf_offset = 0;
  }
}

void sha1_write_1(uint8_t data) {
    ++byteCount;
    sha1_addUncounted(data);
}

void sha1_write_2(uint8_t* data, int length) {
    for (int i=0; i<length; i++) {
        sha1_write_1(data[i]);
    }
}

void 
sha1_pad() {
    // Implement sha-1 padding (fips180-2 §5.1.1)

    // Pad with 0x80 followed by 0x00 until the end of the block
    sha1_addUncounted(0x80);
    while (buf_offset != 56) sha1_addUncounted(0x00);

    // Append length in the last 8 bytes
    sha1_addUncounted(0); // We're only using 32 bit lengths
    sha1_addUncounted(0); // But sha-1 supports 64 bit lengths
    sha1_addUncounted(0); // So zero pad the top bits
    sha1_addUncounted(byteCount >> 29); // Shifting to multiply by 8
    sha1_addUncounted(byteCount >> 21); // as sha-1 supports bitstreams as well as
    sha1_addUncounted(byteCount >> 13); // byte.
    sha1_addUncounted(byteCount >> 5);
    sha1_addUncounted(byteCount << 3);
}


uint8_t* sha1_result(void) {
  // Pad to complete the last block
  sha1_pad();

  // Swap byte order back
  for (int i=0; i<5; i++) {
    uint32_t a,b;
    a=state.w[i];
    b=a<<24;
    b|=(a<<8) & 0x00ff0000;
    b|=(a>>8) & 0x0000ff00;
    b|=a>>24;
    state.w[i]=b;
  }

  // Return pointer to hash (20 characters)
  return state.b;
}


#define HMAC_IPAD 0x36
#define HMAC_OPAD 0x5c
