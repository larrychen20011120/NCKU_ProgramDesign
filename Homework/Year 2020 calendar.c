#include <stdio.h>

int main() {
    int n;
    int initial, days;
    scanf("%d", &n);
    printf("Sun Mon Tue Wed Thu Fri Sat \n");
    switch (n) {
        case 1:
            initial = 4;
            days = 31;
            break;
        case 2:
            initial = 7;
            days = 29;
            break;
        case 3:
            initial = 1;
            days = 31;
            break;
        case 4:
            initial = 4;
            days = 30;
            break;
        case 5:
            initial = 6;
            days = 31;
            break;
        case 6:
            initial = 2;
            days = 30;
            break;
        case 7:
            initial = 4;
            days = 31;
            break;
        case 8:
            initial = 7;
            days = 31;
            break;
        case 9:
            initial = 3;
            days = 30;
            break;
        case 10:
            initial = 5;
            days = 31;
            break;
        case 11:
            initial = 1;
            days = 30;
            break;
        case 12:
            initial = 3;
            days = 31;
            break;
    }
    for (int i = 1; i < initial; i++){
        printf("    ");
    }
    int j = initial;
    for (int i = 1; i <= days; i++){
        printf("%3d ", i);
        j++;
        if (j > 7 && i == days){
            break;
        }
        if (j > 7){
            printf("\n");
            j = 1;
        }
    }
    return 0;
}

