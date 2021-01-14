#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};
struct node* head = NULL;
struct node* tail = NULL;
void MoveToTail();

int main(void) {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        struct node* tmp = malloc(sizeof(struct node));
        scanf("%d", &tmp->val);
        tmp->next = NULL;
        if(i == 1)
            head = tmp;
        else
            tail->next = tmp;
        tail = tmp;
    }
    MoveToTail();
    for(struct node* cur = head; cur != NULL; cur = cur->next)
        printf("%d ", cur->val);
    return 0;
}
// Your code goes here
void MoveToTail() {
    // "struct node* head" and "struct node* tail" are in global
    // you can use this two pointers to do this problem
    int max = head->val;
    struct node *max_pos = head, *pre_pos = NULL;
    for (struct node *pre = NULL, *cur = head; cur != NULL; pre = cur, cur = cur->next){
        if (max < cur->val){
            max = cur->val;
            max_pos = cur;
            pre_pos = pre;
        }
    }
    // the next of pre_position point to the next of max_position
    // tail point to max_position
    // max_position point to NULL
    if (pre_pos == NULL){
        // the first_one is max
        // change head into head's next
        head = max_pos->next;
        tail->next = max_pos;
        max_pos->next = NULL;
    }else if (max_pos == tail){
        ;
    }else{
        pre_pos->next = max_pos->next;
        tail->next = max_pos;
        max_pos->next = NULL;
    }
}
