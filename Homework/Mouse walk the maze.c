#include <stdio.h>
#include <stdbool.h>
#define n 5

bool visit(char(*)[n], int(*)[n], int, int);
int main(void) {
    char maze[n][n];
    int route[n][n];
    // initialize maze and route matrices
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            route[i][j]=0;
            scanf("%c", &maze[i][j]);
            getchar();
        }
    }
    if (visit(maze, route, 0, 0)) { // (0,0) is a starting point
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++)
                printf("%d ", route[i][j]);
            printf("\n");
        }
    } else {
        printf("Can't find the exit!");
    }
    return 0;
}
// Your code goes here

/*  fill the route matrix with 0's or 1's.
 If there isn't any route, return false; otherwise, return true. */

bool visit(char maze[][n], int route[][n], int originX, int originY) {
    if (originX == 4 && originY == 4 && maze[originX][originY] == 'r') {
        route[originX][originY] = 1;
        return true;
    }else if (originX >= n || originX < 0 || originY >= n || originY < 0){
        // out of the maze return false
        return false;
    }else if (maze[originX][originY] == 'w'){
        return false;
    }else {
        maze[originX][originY] = 'w';
        if (visit(maze, route, originX - 1, originY) || visit(maze, route, originX + 1, originY) || visit(maze, route, originX, originY - 1) || visit(maze, route, originX, originY + 1)){
            route[originX][originY] = 1;
            return true;
        }
    }
}
