//name: Xinchen Xu
//email: xu.xinc@northeastern.edu
#include <stdio.h>
#include <string.h>

int compression(char arr[], int n, char res[]) {
    int count = 0;
    int resIndex = 0;
    for (int i = 0; i < n; i++) {
        count = 1;
        while (i < n - 1 && arr[i] == arr[i + 1]) {
            count++;
            i++;
        }
        // Append character and its count to result
        resIndex += sprintf(res + resIndex, "%c%d", arr[i], count);
    }
    res[resIndex] = '\0'; // Null-terminate the result string
    return resIndex; // Return the length of the compressed string
}

int main() {
    char a[] = "aaaaaaaaaaaaaabbbbcccd";
    char res[50];
    int r, n = strlen(a); // n is the size of input array
    r = compression(a, n, res);
    printf("Compressed string: %s\n", res);
    printf("Length of the compressed string: %d\n", r);
    return 0;
}

