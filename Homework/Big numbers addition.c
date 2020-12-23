#include<stdio.h>
#include<string.h>

void add(char a[], char b[], char res[]);

int main(){
    char a[100], b[100], res[105];
    scanf("%s %s", a, b);
    add(a, b, res);
    printf("%s", res);
    return 0;
}

// Your code goes here
void add(char a[], char b[], char res[]){
    int length_a = strlen(a), length_b = strlen(b);
    _Bool a_is_small = (length_a < length_b) ? 1 : 0;
    int diff = (a_is_small == 1) ? length_b - length_a : length_a - length_b;
    char zero_factor[100];
    for (int i = 0; i < diff; i++)
        zero_factor[i] = '0';
    int add = 0;
    if (a_is_small) {
        for (int i = diff; i < length_b; i++)
            zero_factor[i] = a[i - diff];
        for (int i = length_b - 1; i > 0; i--){
            if (((b[i] - '0') + (zero_factor[i] - '0') + add ) >= 10){
                res[i] = (b[i] - '0') + (zero_factor[i] - '0') + add - 10 + '0';
                add = 1;
            }else{
                res[i] = (b[i] - '0') + (zero_factor[i] - '0') + add + '0';
                add = 0;
            }
        }
        if (((b[0] - '0') + (zero_factor[0] - '0') + add >= 10 )){
            printf("1");
            res[0] = (b[0] - '0') + (zero_factor[0] - '0') + add - 10 + '0';
        }else{
            res[0] = (b[0] - '0') + (zero_factor[0] - '0') + add + '0';
        }
        res[length_b] = '\0';
    }else{
        for (int i = diff; i < length_a; i++)
            zero_factor[i] = b[i - diff];
        for (int i = length_a - 1; i > 0; i--){
            if (((a[i] - '0') + (zero_factor[i] - '0') + add) >= 10){
                res[i] = (a[i] - '0') + (zero_factor[i] - '0') + add - 10 + '0';
                add = 1;
            }else{
                res[i] = (a[i] - '0') + (zero_factor[i] - '0') + add + '0';
                add = 0;
            }
        }
        if (((a[0] - '0') + (zero_factor[0] - '0') + add >= 10 )){
            printf("1");
            res[0] = (a[0] - '0') + (zero_factor[0] - '0') + add - 10 + '0';
        }else{
            res[0] = (a[0] - '0') + (zero_factor[0] - '0') + add + '0';
        }
        res[length_a] = '\0';
    }
}
