#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int matrix[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
    for(int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (matrix[i][j] != matrix[j][i]){
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    return 0;
}
