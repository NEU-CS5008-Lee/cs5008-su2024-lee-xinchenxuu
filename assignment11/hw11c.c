//name: Xinchen Xu
//email: xu.xinc@northeastern.edu

#include <stdio.h>

// Use a global array to store intermediate results
long long int d[20];

long long int dp(int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Check if value is already computed
    if (d[n] != 0) return d[n];

    // Compute the nth Fibonacci number using previously computed values
    d[n] = dp(n - 1) + dp(n - 2);

    return d[n];
}

int main(void) {
    int n;
    scanf("%d", &n);

    // Initialize the memoization array with 0s
    for (int i = 0; i < 20; i++) {
        d[i] = 0;
    }

    printf("%lld\n", dp(n));
    return 0;
}

