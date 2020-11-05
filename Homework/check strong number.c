#include <stdio.h>
int stair(int x){
    if (x == 1 || x == 0){
        return 1;
    }else{
        return x * stair(x - 1);
    }
}
int main() {
    int n, true_n;
    int sum = 0;
    scanf("%d", &n);
    true_n = n;
    while (n * 10 / 10 != 0) {
        sum += stair(n % 10);
        n /= 10;
    }
    if (sum == true_n){
        printf("%d is a strong number.", true_n);
    }else {
        printf("%d is not a strong number.", true_n);
    }
    return 0;
}

