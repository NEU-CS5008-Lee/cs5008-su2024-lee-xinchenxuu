//name: Xinchen Xu
//email: xu.xinc@northeastern.edu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int getrepeat(const char *str, char ch) {
    const char *ptr = str;
    int repeat = 0;
    while (*ptr == ch) {
        ptr++;
        repeat++;
    }
    return repeat;
}

char *runlengthencoding(const char *str, char *rle) {
    const char *ptr = str;
    char encoding[100];
    int repeat;
    rle[0] = '\0';  // Start with an empty string

    while (*ptr != '\0') {
        repeat = getrepeat(ptr, *ptr);
        if (repeat > 1) {
            sprintf(encoding, "%c%d", *ptr, repeat);
        } else {
            sprintf(encoding, "%c", *ptr);
        }
        strcat(rle, encoding);
        ptr += repeat;
    }

    return rle;
}

char *decode_rle(const char *rle, char *str) {
    const char *ptr = rle;
    int count;
    int pos = 0;
    
    while (*ptr != '\0') {
        if (isdigit(*(ptr + 1))) {
            sscanf(ptr + 1, "%d", &count);  // Read the number of repetitions
            for (int i = 0; i < count; i++) {
                str[pos++] = *ptr;  // Repeat the character
            }
            ptr += 2;  // Move past the character and digits (assumes single-digit counts)
        } else {
            str[pos++] = *ptr;  // Single character, copy as is
            ptr++;
        }
    }
    str[pos] = '\0';  // Null-terminate the decoded string

    return str;
}

int main() {
    char str_org[] = "WWWWWWWWWWWWWWWWWWWWWWWWWWWWbAAAABBCBBCBBCaaa";
    char rle[100];
    runlengthencoding(str_org, rle);
    printf("str_org:[%s] => rle:[%s]\n", str_org, rle);

    char str_dec[100];
    decode_rle(rle, str_dec);
    printf("rle:[%s] => str_dec:[%s]\n", rle, str_dec);

    return 0;
}

