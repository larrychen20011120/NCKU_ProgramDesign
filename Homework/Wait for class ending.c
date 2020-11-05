#include <stdio.h>

int main() {
    int H, M;
    scanf("%d%d", &H, &M);
    if (M < 10){
        printf("%.2d:%.2d\n", H, M + 50);
    }else if (H == 23){
        printf("00:%.2d\n", M - 10);
    }else{
        printf("%.2d:%.2d\n", H + 1, M - 10);
    }
    return 0;
}
