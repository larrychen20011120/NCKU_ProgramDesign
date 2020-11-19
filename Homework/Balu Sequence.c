#include <stdio.h>
long B(unsigned int i){
    return (i <= 2) ? 1 : (2 * B(i-1) + 3 * B(i-2)) % 1000000007;
}
int main(){
    unsigned int N;
    scanf("%u", &N);
    printf("%ld", B(N));
    return 0;

}
