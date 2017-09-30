#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

void calcMD5(const uint8_t *data, int length, uint8_t md5[16])
{
    const static int s[64] =
    {
         7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
         5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
         4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
         6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,
    };

    const static uint32_t K[64] =
    {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
        0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391,
    };

    uint32_t a0 = 0x67452301;
    uint32_t b0 = 0xefcdab89;
    uint32_t c0 = 0x98badcfe;
    uint32_t d0 = 0x10325476;

    int blockNumber = (length*8+1+64+511)/512;

    for (int block=0; block<blockNumber; block++)
    {
        uint32_t M[16];
        for (int i=0; i<64; i++)
            if (block*64+i < length)
                ((uint8_t *)M)[i] = data[block*64+i];
            else if (block*64+i == length)
                ((uint8_t *)M)[i] = 0x80;
            else
                ((uint8_t *)M)[i] = 0x00;
        if (block == blockNumber-1)
            M[14] = (uint32_t)(length*8);

        uint32_t A = a0;
        uint32_t B = b0;
        uint32_t C = c0;
        uint32_t D = d0;
        for (int i=0; i<64; i++)
        {
            uint32_t F;
            int g;
            if (i<16)      F = (B&C)|(~B&D), g = i;
            else if (i<32) F = (D&B)|(~D&C), g = (5*i+1)%16;
            else if (i<48) F = B^C^D,        g = (3*i+5)%16;
            else           F = C^(B|~D),     g = 7*i%16;

            uint32_t temp = D;
            D = C;
            C = B;
            uint32_t t = A+F+K[i]+M[g];
            B += t<<s[i] | t>>(32-s[i]);
            A = temp;
        }
        a0 += A;
        b0 += B;
        c0 += C;
        d0 += D;
    }

    ((uint32_t *)md5)[0] = a0;
    ((uint32_t *)md5)[1] = b0;
    ((uint32_t *)md5)[2] = c0;
    ((uint32_t *)md5)[3] = d0;
}

int main()
{
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);

    printf("Wait...\n");
    sleep(3);
    alarm(180);

    const int flaglen = 22;
    int length;
    uint8_t data[32];
    uint8_t flag[flaglen];

    FILE *f = fopen("flag.txt", "rb");
    if (f == NULL)
    {
        printf("Failed to open flag.txt\n");
        return -1;
    }
    if (fread(flag, 1, flaglen, f) != flaglen)
    {
        printf("Failed to read flag.txt\n");
        return -1;
    }
    fclose(f);

    while (true)
    {
        printf("Input data length: ");
        scanf("%d", &length);
        printf("Input data: ");
        getc(stdin);    //  read \n
        fread(data, 1, length, stdin);

        uint8_t md5[16];
        calcMD5(data, length, md5);
        printf("MD5(your data): ");
        for (int i=0; i<16; i++)
            printf("%02x", md5[i]);
        printf("\n");

        const static uint8_t exit[16] =
        {
            0xf2, 0x4f, 0x62, 0xee, 0xb7, 0x89, 0x19, 0x9b,
            0x9b, 0x2e, 0x46, 0x7d, 0xf3, 0xb1, 0x87, 0x6b,
        };
        if (memcmp(md5, exit, 16) == 0)
            break;

        calcMD5(flag, flaglen, md5);
        printf("MD5(flag): ");
        for (int i=0; i<16; i++)
            printf("%02x", md5[i]);
        printf("\n");
    }
}
