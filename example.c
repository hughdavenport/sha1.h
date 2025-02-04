#define SHA1_IMPLEMENTATION
#include "sha1.h"

#include <stdio.h>
#include <string.h>

int main() {
    const char test[] = "blob 47\00apple blueberry pineapple pear strawberry grape";
    uint8_t result[SHA1_DIGEST_BYTE_LENGTH];

    if (sha1_digest(test, sizeof(test) - 1, result)) {
        for (int idx = 0; idx < SHA1_DIGEST_BYTE_LENGTH; idx ++) {
            printf("%02x", result[idx]);
        }
        printf("\n");
        return 0;
    }
    fprintf(stderr, "Unexpected error\n");
    return 1;
}
