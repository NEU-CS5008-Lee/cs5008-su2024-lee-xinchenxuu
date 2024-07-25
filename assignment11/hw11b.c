//name: Xinchen Xu
//email: xu.xinc@northeastern.edu

#include <stdio.h>

long long int d[20]; // To store intermediate results for factorial calculation

long long int dp(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return 1;
    }

    // Check if the value is already computed
    if (d[n] != 0) {
        return d[n];
    }

    // Compute the factorial using previously computed values
    d[n] = n * dp(n - 1);

    return d[n];
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));
    return 0;
}

