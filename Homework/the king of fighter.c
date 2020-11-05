#include <stdio.h>
#include <stdbool.h>
int main() {
    int A, B;
    int atk;
    scanf("%d%d", &A, &B);
    bool turns = true;  //true is A's turns
    while (A >= 0 && B >= 0){
        scanf("%d", &atk);
        if (turns == true){
            B -= atk;
        }else{
            A -= atk;
        }
        turns = !turns;
    }
    turns == true ? printf("B") : printf("A");
    return 0;
}

