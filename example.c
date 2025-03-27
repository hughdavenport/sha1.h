#define SHA1_IMPLEMENTATION
#include "sha1.h"

#include <stdio.h>
#include <string.h>

int main(void) {
    const unsigned char test[] = "blob 47\00apple blueberry pineapple pear strawberry grape";
    uint8_t result[SHA1_DIGEST_BYTE_LENGTH];

    if (sha1_digest(test, sizeof(test) - 1, result)) {
        SHA1_PRINTF_HEX(result);
        printf("\n");
        return 0;
    }
    fprintf(stderr, "Unexpected error\n");
    return 1;
}
