#include <stdio.h>

int main() {
    float x;
    scanf("%f", &x);
    float ans;
    ans = 7 * x * x * x * x - 8 * x * x * x - x * x + 6 * x - 22;
    printf ("%.1f", ans);
    return 0;
}
