// name: Xinchen Xu
// email: xu.xinc@northeastern.edu
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int arr[10], temp;
    int count = 0, i, j;

    /* read the file */
    fp = fopen("input1.txt", "r"); // Ensure the correct path to input1.txt
    if (fp == NULL) {
        // if file returns NULL then can't open the file
        printf("\n Cannot open the file \n");
        exit(0);
    }

    // Read integers from the file into the array
    while (fscanf(fp, "%d", &arr[count]) != EOF && count < 10) {
        count++;
    }

    // Close the file
    fclose(fp);

    // Bubble sort to sort the array
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

