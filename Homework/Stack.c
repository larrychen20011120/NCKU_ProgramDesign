#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct element {                        // elements of the stack
    int data;
    struct element *next;   // point to the next element in the stack
};

struct head {
    int size;                               // record the size of the stack
    struct element *next;   // point to the bottom element in the stack if there is any
    struct element *top;    // point to the top of the stack
};

void print_stack(struct head *stack_p);
void push(struct head *stack_p, int data);      // put an element to the top of the stack
struct element *pop(struct head *stack_p);      // remove an element from the top of the stack

int main(void) {
    // stack declaration
    struct head stack_head;
    stack_head.size = 0;
    stack_head.next = NULL;
    stack_head.top = NULL;

    // read instructions
    int num, data;
    char command[5];
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        scanf("%4s", command);
        if (strcmp(command, "push") == 0) {     // push command, call push()
            scanf("%d", &data);
            push(&stack_head, data);
        }
        else if (strcmp(command, "pop") == 0) { // pop command, call pop()
            struct element *e = pop(&stack_head);
            free(e);
        }
    }
    print_stack(&stack_head);
    return 0;
}

void print_stack(struct head *stack_p) {
    printf("%d\n", stack_p->size);
    for (struct element *ptr = stack_p->next; ptr != NULL; ptr = ptr->next)
        printf("%d ", ptr->data);
}

// Your code goes here
void push(struct head *stack_p, int data) {
    // create an element and push it to the top of the stack
    struct element *node;
    node = malloc(sizeof(struct element));
    node->data = data;
    if (stack_p->size == 0){
        stack_p->next = node;
    }else {
        stack_p->top->next = node;   // linked
    }
    stack_p->top = node;
    node->next = NULL;
    stack_p->size++;
}

struct element* pop(struct head *stack_p) {
    // return the element which is popped from the stack
    struct element *pre, *cur;
    for (pre = NULL, cur = stack_p->next; cur->next != NULL; pre = cur, cur = cur->next)
        ;
    if (pre == NULL){
        // delete the first element
        ;
    }else {
        stack_p->top = pre;
        pre->next = NULL;
    }
    stack_p->size--;
    return cur;
}