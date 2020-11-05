#include <stdio.h>
int main() {
    int N;
    scanf("%d", &N);
    if (N < 1){
        printf("Calm");
    }else if (N < 4){
        printf("Light air");
    }else if (N < 28){
        printf("Breeze");
    }else if (N < 48){
        printf("Gale");
    }else if (N < 64){
        printf("Storm");
    }else{
        printf("Hurricane");
    }
    return 0;
}

