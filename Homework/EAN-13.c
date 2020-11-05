#include <stdio.h>
int main() {
    int one, six, five;
    scanf("%1d%6d%5d", &one, &six, &five);
    int even = one + six % 10 + six / 100 % 10 + six / 10000 % 10 + five / 10 % 10 + five / 1000 % 10;
    int odd = six / 10 % 10 + six / 1000 % 10 + six / 100000 % 10 + five % 10 + five / 100 % 10 + five / 10000 % 10;
    int sum = odd * 3 + even;
    sum = ((sum - 1) / 10 * 10 + 10) - sum;
    printf("%d", sum);
    return 0;
}
