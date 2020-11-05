#include <stdio.h>

int main() {
    int m, n;
    long long int stair = 1;
    scanf("%d %d", &m, &n);
    n = n > m / 2 ? m - n : n;
    for (int i = m; i > m - n; i-- ){
        stair *= i;
    }
    for (int i = 1; i <= n; i++){
        stair /= i;
    }
    printf("%lld", stair);
    return 0;
}

