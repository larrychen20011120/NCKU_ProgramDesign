#include <stdio.h>

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    for (int i = x; i <= y; i++){
        int j = 2;
        if (i == 2)
            printf("%d ", i);
        for (;j < i ; j++){
            if (i % j == 0){
                break;
            }
            if (j == i - 1)
                printf("%d ", i);
        }
    }
    return 0;
}

