#include <stdio.h>
#include <stdbool.h>
int main() {
    char word;
    bool space_or_not = false;
    while (1){
        word = getchar();
        if (word == '\n'){
            break;
        }else if (space_or_not == false && word == ' '){
            putchar(word);
            space_or_not = true;
        }else if (space_or_not == true && word == ' '){
            ;
        }else{
            putchar(word);
            space_or_not = false;
        }
    }
    return 0;
}

