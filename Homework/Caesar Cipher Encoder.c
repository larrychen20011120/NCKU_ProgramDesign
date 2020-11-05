#include <stdio.h>
int main() {
    int n;
    char encode;
    int encode_value;
    scanf("%d", &n);
    n = n > 26 ? n % 26 : n;
    n = n < -26 ? n % 26 : n;
    getchar();  // eat new line character
    // be careful : encode + n maybe overflowed
    while ( (encode = getchar() ) != '\n'){
        if (encode >= 'a' && encode <= 'z'){
            encode_value = encode + n;
            if (encode_value > 127){
                encode = encode - 26 + n;
            }else{
                encode += n;
            }
            encode = encode > 'z' ? encode - 26 : encode;
            encode = encode < 'a' ? encode + 26 : encode;
        }else if (encode >= 'A' && encode <= 'Z'){
            encode = encode + n;
            encode = encode > 'Z' ? encode - 26 : encode;
            encode = encode < 'A' ? encode + 26 : encode;
        }else{
            ;
        }
        putchar(encode);
    }
    return 0;
}

