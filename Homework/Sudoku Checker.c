#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]);

int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}
// Your code goes here
void check_sudoku(int (*grid_p)[NUM]) {
    _Bool have_seen[NUM], have_print[NUM][NUM] = {0};
    int error;
    for (int row = 0; row < NUM; row++) {
        for (int k = 0; k < NUM; k++)
            have_seen[k] = 0;
        for (int i = 0; i < NUM; i++) {
            if (have_seen[(*(grid_p + row))[i] - 1] == 0) {
                have_seen[(*(grid_p + row))[i] - 1] = 1;
            } else {
                error = (*(grid_p + row))[i];
                for (int j = 0; j < NUM; j++) {
                    if ((*(grid_p + row))[j] == error && have_print[row][j] == 0) {
                        have_print[row][j] = 1;
                    }
                }

            }
        }
    }
    for (int col = 0; col < NUM; col++) {
        for (int k = 0; k < NUM; k++)
            have_seen[k] = 0;
        for (int i = 0; i < NUM; i++) {
            if (have_seen[(*(grid_p + i))[col] - 1] == 0) {
                have_seen[(*(grid_p + i))[col] - 1] = 1;
            } else {
                error = (*(grid_p + i))[col];
                for (int j = 0; j < NUM; j++) {
                    if ((*(grid_p + j))[col] == error && have_print[j][col] == 0) {
                        have_print[j][col] = 1;
                    }
                }

            }
        }
    }
    for (int row = 0; row < 9; row += 3) {
        for (int col = 0; col < 9; col += 3) {
            for (int k = 0; k < NUM; k++)
                have_seen[k] = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (have_seen[(*(grid_p + row + i))[col + j] - 1] == 0) {
                        have_seen[(*(grid_p + row + i))[col + j] - 1] = 1;
                    } else {
                        error = (*(grid_p + row + i))[col + j];
                        for (int l = 0; l < 3; l++) {
                            for (int m = 0; m < 3; m++) {
                                if ((*(grid_p + row + l))[col + m] == error && have_print[row + l][col + m] == 0)
                                    have_print[row + l][col + m] = 1;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < NUM; i++) {
        for(int j = 0; j < NUM; j++){
            if (have_print[i][j] == 1){
                printf("(%d,%d)\n", i, j);
            }
        }
    }
}