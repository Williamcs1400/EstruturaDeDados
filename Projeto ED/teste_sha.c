#include <stdio.h>
#include <string.h>
#include "sha256.h"

int main(){
    BYTE buf[SHA256_BLOCK_SIZE];
    SHA256_CTX ctx;
    char string[7];
    int i;

    BYTE hash1[SHA256_BLOCK_SIZE] = {0xba,0x78,0x16,0xbf,0x8f,0x01,0xcf,0xea,0x41,0x41,0x40,0xde,0x5d,0xae,0x22,0x23,
	                                 0xb0,0x03,0x61,0xa3,0x96,0x17,0x7a,0x9c,0xb4,0x10,0xff,0x61,0xf2,0x00,0x15,0xad};

    scanf("%s", string);

    sha256_init(&ctx);
    sha256_update(&ctx, string, strlen(string));
    sha256_final(&ctx, buf);

    for(i = 0; i < SHA256_BLOCK_SIZE; i++){
        printf("%x", buf[i]);
    }

    //printf("%x\n %d\n %s\n", buf, buf,buf);
    return 0;
}