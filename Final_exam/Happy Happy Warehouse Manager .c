#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *good_types[] = {
    "Juice",
    "Wine",
    "Laptop"
};

void *produce(void *top_of_stack, const char *good_type, size_t count);
void *consume(void *top_of_stack, size_t count);
void list_remain(void *top_of_stack);

int main(){
    char record[64], *job, *good;
    size_t count;
    void *top_of_stack = NULL;

    while(fgets(record, 64, stdin)){
        job = strtok(record, " ");
        if(!strcmp(job, "Produce")){
            good = strtok(NULL, " ");
            count = atol(strtok(NULL, " "));

            for(int i = 0; i < 3; i++){
                if(!strcmp(good, good_types[i])){
                    top_of_stack = produce(top_of_stack, good_types[i], count);
                    break;
                }
            }
        }
        else if(!strcmp(job, "Consume")){
            count = atol(strtok(NULL, " "));
            top_of_stack = consume(top_of_stack, count);
        }
    }

    list_remain(top_of_stack);

    return 0;
}
// Your code goes here
//You may need to define your own struct here.
struct good{
    char name[8];
    int remain;
    struct good* down;
};
struct good *head = NULL;
void *produce(void *top_of_stack, const char *good_type, const size_t count){
    struct good* top = ((struct good*) top_of_stack);
    if (top != NULL && strcmp(top->name, good_type) == 0){
        // the same object add onto the top
        top->remain += count;
    }else {
        struct good *node;
        node = malloc(sizeof(struct good));
        node->remain = count;
        strcpy(node->name, good_type);
        if (head == NULL) {
            head = node;
            top = node;
            node->down = NULL;
        } else {
            node->down = top;
            top = node;
        }
    }
    return top;
}

void *consume(void *top_of_stack, const size_t count){
    struct good *cur = (struct good*) top_of_stack;
    int now_count = count;
    for (; cur != NULL; cur = cur->down){
        if (cur->remain <= now_count){
            now_count -= cur->remain;
        }else{
            cur->remain -= now_count;
            return cur;
        }
    }
    return NULL;
}

void list_remain(void *top_of_stack){
    struct good *ptr = top_of_stack;
    if (ptr == NULL){
        printf("Empty\n");
        return;
    }
    for (;ptr != NULL; ptr = ptr->down){
        printf("%s x %d\n", ptr->name, ptr->remain);
    }
}