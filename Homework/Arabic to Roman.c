#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    int times;
    if (a / 1000 != 0){
        times = a / 1000;
        a %= 1000;
        while (times != 0){
            printf("M");
            times--;
        }
    }
    if (a / 100 != 0){
        times = a / 100 ;
        a %= 100;
        while (times != 0){
            if (times >= 9) {
                printf("CM");
                times -= 9;
            }else if(times >= 5){
                printf("D");
                times -= 5;
            }
            else if (times >= 4){
                printf("CD");
                times -= 4;
            }else {
                printf("C");
                times--;
            }
        }
    }
    if (a / 10 != 0){
        times = a / 10;
        a %= 10;
        while (times != 0){
            if (times >= 9) {
                printf("XC");
                times -= 9;
            }else if(times >= 5){
                printf("L");
                times -= 5;
            }
            else if (times >= 4){
                printf("XL");
                times -= 4;
            }else {
                printf("X");
                times--;
            }
        }
    }
    if (a != 0){
        times = a ;
        while (times != 0){
            if (times >= 9) {
                printf("IX");
                times -= 9;
            }else if(times >= 5){
                printf("V");
                times -= 5;
            }
            else if (times >= 4){
                printf("IV");
                times -= 4;
            }else {
                printf("I");
                times--;
            }
        }
    }
    return 0;
}

