#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 100

int addition(char str[]);

int main() {
    char str[N];
    scanf("%s", str);
    int sum = addition(str);
    printf("%d", sum);
    return 0;
}
// Your code goes here

int addition(char str[]){
    int sum = 0;
    char *token;
    token = strtok(str, "+");
    while (token != NULL){
        sum += atoi(token);
        token = strtok(NULL, "+");
    }
    return sum;
}
