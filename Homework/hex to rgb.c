#include <stdio.h>

int main() {
    char color;
    int color_value = 0;
    color = getchar();
    int red, green, blue;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            color = getchar();
            if (j == 0){
                if (color >= '0' && color <= '9'){
                    color_value += (color - '0') * 16;
                }else{
                    color_value += (color - 'A' + 10) * 16;
                }
            }else{
                if (color >= '0' && color <= '9'){
                    color_value += (color - '0');
                }else{
                    color_value += (color - 'A' + 10);
                }
            }
        }
        switch (i) {
            case 0: red = color_value;
                break;
            case 1: green = color_value;
                break;
            case 2: blue = color_value;
                break;
        }
        color_value = 0;
    }
    printf("rgb(%d,%d,%d)", red, green, blue);
    return 0;
}

