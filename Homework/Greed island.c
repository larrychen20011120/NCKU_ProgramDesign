#include <stdio.h>

int main() {
    char card;
    for (int i = 0; i < 20; i++ ){
        card = getchar();
        switch (card) {
            case 'A': putchar('C');
                break;
            case 'B': putchar('R');
                break;
            case 'C': putchar('W');
                break;
            case 'D': putchar('Z');
                break;
            case 'E': putchar('G');
                break;
        }
    }
    return 0;
}

