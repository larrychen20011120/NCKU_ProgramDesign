#include <stdio.h>
#define M 5
#define N 8
char colors[4] = {'R', 'G', 'B', 'X'};   // Red, Green, Blue, Empty

void spread(char*, int, int);

int main(void) {
    char graph[M][N];
    int row, col;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            scanf("%c", &graph[i][j]);
        getchar();      // Ignore '\n'
    }
    scanf("%d %d", &row, &col);    // Starting position

    spread(&graph[0][0], row, col);

    // Print out the spreading result
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            printf("%c", graph[i][j]);
        printf("\n");
    }
    return 0;
}
// Your code goes here
void spread(char* graph, int row, int col) {
    char color = *(graph + row * N + col);
    char *p = graph + row * N + col;
    for (int i = 1; i < N - col; i++){
        if (*(p + i ) == 'X' || *(p + i) == color){
            *(p + i) = color;
        }else{
            break;
        }
    }
    for (int i = 1; i <= col; i++){
        if (*(p - i) == 'X' || *(p - i) == color){
            *(p - i) = color;
        }else{
            break;
        }
    }
    for (int i = 1; i < M - row; i++){
        if (*(p + N * i) == 'X' || *(p + N * i) == color){
            *(p + N * i) = color;
        }else{
            break;
        }
    }
    for (int i = 1; i <= row; i++){
        if (*(p - N * i) == 'X' || *(p - N * i) == color){
            *(p - N * i) = color;
        }else{
            break;
        }
    }
}