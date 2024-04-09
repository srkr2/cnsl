#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))
const uint32_t k[] = {0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5,
                       0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
                       0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3,
                       0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
                       0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC,
                       0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
                       0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7,
                       0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
                       0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13,
                       0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
                       0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3,
                       0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
                       0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5,
                       0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
                       0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208,
                       0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2};
const uint32_t r[] = {7, 12, 17, 22, 7, 12, 17, 22,
                       7, 12, 17, 22, 7, 12, 17, 22,
                       5, 9, 14, 20, 5, 9, 14, 20,
                       5, 9, 14, 20, 5, 9, 14, 20,
                       4, 11, 16, 23, 4, 11, 16, 23,
                       4, 11, 16, 23, 4, 11, 16, 23,
                       6, 10, 15, 21, 6, 10, 15, 21,
                       6, 10, 15, 21, 6, 10, 15, 21};

void md5(const uint8_t *initial_msg, size_t initial_len, uint8_t *digest) {
    uint32_t h0, h1, h2, h3;

    h0 = 0x67452301;
    h1 = 0xEFCDAB89;
    h2 = 0x98BADCFE;
    h3 = 0x10325476;

    size_t new_len = ((((initial_len + 8) / 64) + 1) * 64) - 8;
    uint8_t *msg = (uint8_t *)malloc(new_len + 64);
    memcpy(msg, initial_msg, initial_len);
    msg[initial_len] = 0x80;
    uint32_t bits_len = 8 * initial_len;
    memcpy(msg + new_len, &bits_len, 4);

    for (int offset = 0; offset < new_len; offset += 64) {
        uint32_t *w = (uint32_t *)(msg + offset);
        uint32_t a = h0, b = h1, c = h2, d = h3;

        for (int i = 0; i < 64; i++) {
            uint32_t f, g;

            if (i < 16) {
                f = (b & c) | ((~b) & d);
                g = i;
            } else if (i < 32) {
                f = (d & b) | ((~d) & c);
                g = (5 * i + 1) % 16;
            } else if (i < 48) {
                f = b ^ c ^ d;
                g = (3 * i + 5) % 16;
            } else {
                f = c ^ (b | (~d));
                g = (7 * i) % 16;
            }
            uint32_t temp = d;
            d = c;
            c = b;
            b = b + LEFTROTATE((a + f + k[i] + w[g]), r[i]);
            a = temp;
        }

        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
    }
    free(msg);
    memcpy(digest, &h0, sizeof(h0));
    memcpy(digest + sizeof(h0), &h1, sizeof(h1));
    memcpy(digest + sizeof(h0) + sizeof(h1), &h2, sizeof(h2));
    memcpy(digest + sizeof(h0) + sizeof(h1) + sizeof(h2), &h3, sizeof(h3));
}
int main() {
    char text[] = "Hello, world!";
    uint8_t digest[16];
    
    md5((uint8_t *)text, strlen(text), digest);
    printf("MD5 digest of '%s': ", text);
    for (int i = 0; i < 16; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
    return 0;
}


