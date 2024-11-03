# sha1.h: A SHA-1 stb-style header only library

[![patreon](https://img.shields.io/badge/patreon-FF5441?style=for-the-badge&logo=Patreon)](https://www.patreon.com/hughdavenport)
[![youtube](https://img.shields.io/badge/youtube-FF0000?style=for-the-badge&logo=youtube)](https://www.youtube.com/watch?v=dqw7B6eR9P8&list=PL5r5Q39GjMDfetFdGmnhjw1svsALW1HIY)

This repo contains a [stb-style](https://github.com/nothings/stb/blob/master/docs/stb_howto.txt) header only library. You only need the [sha1.h](https://github.com/hughdavenport/sha1.h/raw/refs/heads/main/sha1.h) file.

SHA1 is defined in [RFC 3174](https://datatracker.ietf.org/doc/html/rfc3174).

This library was developed during a [YouTube series](https://www.youtube.com/watch?v=dqw7B6eR9P8&list=PL5r5Q39GjMDfetFdGmnhjw1svsALW1HIY) where I implement [bittorrent from scratch](https://github.com/hughdavenport/codecrafters-bittorrent-c), which drove me to create the following libraries:
- Bencode decoding in [bencode.h](https://github.com/hughdavenport/bencode.h)
- SHA-1 hashing in [sha1.h](https://github.com/hughdavenport/sha1.h)
- URL parsing in [url.h](https://github.com/hughdavenport/url.h)
- HTTP communication in [http.h](https://github.com/hughdavenport/http.h)

To use the library, `#define SHA1_IMPLEMENTATION` exactly once (in your main.c may be a good place). You can `#include` the file as many times as you like.

An example file is shown below.
```c
#define SHA1_IMPLEMENTATION
#include "sha1.h"

#include <stdio.h>
#include <string.h>

int main() {
    const char *test = "Hello, SHA1\n";
    uint8_t result[SHA1_DIGEST_BYTE_LENGTH];

    if (sha1_digest(test, strlen(test), result)) {
        for (int idx = 0; idx < SHA1_DIGEST_BYTE_LENGTH; idx ++) {
            printf("%02x", result[idx]);
        }
        printf("\n");
        return 0;
    }
    fprintf(stderr, "Unexpected error\n");
    return 1;
}
```

Test by saving the above to a file `example.c` and then running this
```sh
cc example.c
./a.out
```

Expected output: `9060788a02c4ee3f9f3c213f201d00c0975fc4a7`

Please leave any comments about what you liked. Feel free to suggest any features or improvements.

You are welcome to support me financially if you would like on my [patreon](https://www.patreon.com/hughdavenport).
