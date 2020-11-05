#include <stdio.h>
int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int max = a > b ? a : b;
    int min = a < b ? a : b;
    int medium = c > max ? max : c > min ? c : min ;
    printf("%d",medium);
    return 0;
}

