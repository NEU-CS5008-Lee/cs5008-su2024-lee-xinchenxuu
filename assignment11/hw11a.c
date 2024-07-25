//name: Xinchen Xu
//email: xu.xinc@northeastern.edu

#include <stdio.h>

long long int dp(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    long long int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    return fib[n];
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));
    return 0;
}

