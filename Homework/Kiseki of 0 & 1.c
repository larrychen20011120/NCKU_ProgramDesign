#include <stdio.h>
#include <stdbool.h>
int main() {
    bool binary_num_1[32], binary_num_2[32], binary_num[32], add = 0;
    for (int i = 0; i < 32; i++)
        scanf("%d", &binary_num_1[i]);
    for (int i = 0; i < 32; i++)
        scanf("%d", &binary_num_2[i]);
    for (int i = 31; i >= 0; i--){
        if ((binary_num_1[i] & binary_num_2[i]) == 1){
            binary_num[i] = 0 + add;
            add = 1;
        }else if ((binary_num_1[i] | binary_num_2[i]) == 1){
            binary_num[i] = 1;
            if ((binary_num[i] & add) == 1){
                binary_num[i] = 0;
                add = 1;
            }else{
                binary_num[i] = 1;
                add = 0;
            }
        }else{
            binary_num[i] = 0;
            if ((binary_num[i] | add) == 1){
                binary_num[i] = 1;
                add = 0;
            }else{
                binary_num[i] = 0;
                add = 0;
            }
        }
    }
    for (int i = 0; i < 32; i++){
        printf("%d ", binary_num[i]);
    }
    return 0;
}
