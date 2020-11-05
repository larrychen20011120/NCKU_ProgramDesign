#include <stdio.h>
#include <stdbool.h>
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        for (int k = n - i - 1; k > 0; k--){
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

