#include <stdio.h>

int main() {
    int odd;
    scanf("%d", &odd);
    int square[odd][odd];
    for (int i = 0; i < odd; i++)
        for (int j = 0; j < odd; j++)
            square[i][j] = 0;
    int now_raw = 0, now_column = odd / 2;
    square[now_raw][now_column] = 1;
    for (int value = 2; value <= odd * odd; value++){
        if (now_raw - 1 >= 0 && now_column + 1 < odd ){
            if (square[now_raw - 1][now_column + 1] == 0){
                square[--now_raw][++now_column] = value;
            } else{
                square[++now_raw][now_column] = value;
            }
        }else if (now_raw - 1 < 0 && now_column + 1 >= odd){
            square[++now_raw][now_column] = value;
        }else if (now_raw - 1 < 0){
            square[now_raw = now_raw - 1 + odd][++now_column] = value;
        }else if (now_column + 1 >= odd){
            square[--now_raw][now_column = now_column + 1 - odd] = value;
        }
    }
    for (int i = 0; i < odd; i++) {
        for (int j = 0; j < odd; j++) {
            printf("%d\t", square[i][j]);
        }
        printf("\n");
    }
    return 0;
}
