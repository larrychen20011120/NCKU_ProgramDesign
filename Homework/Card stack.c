#include<stdio.h>
#include <stdlib.h>
struct stack {
    int value;
    struct stack *up;
};

struct stack *lower(int n){
    struct stack *down, *follow ;
    for (int i = n; i >= 1; i--){
        struct stack *node = malloc(sizeof(struct stack));
        node->value = i;
        if (i == n){
            down = node;
            follow = node;
            node->up = NULL;
        }
        follow->up = node;
        node->up = NULL;
        follow = node;
    }
    return down;
}

int delete(struct stack *lower){
    // delete
    struct stack *pre = NULL, *cur = lower;
    for (; cur->up != NULL; pre = cur, cur = cur->up)
        ;
    int return_value;
    if (pre == NULL){
        return_value = lower->value;
        free(cur);
    } else {
        pre->up = NULL;
        return_value = cur->value;
        free(cur);
    }
    return return_value;
}
struct stack *change(struct stack * lower){
    struct stack *pre = NULL, *cur = lower;
    if (cur == NULL) // delete to the NULL list
        return NULL;
    for (; cur->up != NULL; pre = cur, cur = cur->up)
        ;
    if (pre == NULL) // the only one in list
        return cur;
    pre->up = NULL;
    cur->up = lower;
    return cur;
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    // create the list
    struct stack *cards = lower(n);
    for (int i = 0; i < m; i++) {
        printf("%d ", delete(cards));
        cards = change(cards);
    }
    return 0;
}
