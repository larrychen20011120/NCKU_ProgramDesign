#include <stdio.h>
int main() {
    int n, x, a, b;
    scanf("%d %d %d", &n, &x, &a);
    b = x + a;
    while (b > n - 1){
        b -= n;
    }
    printf("%d", b);
    return 0;
}
