#include <stdio.h>
int combination(int m, int n){
    if ((m == n) || (n == 0)){
        return 1;
    }else{
        return combination(m - 1, n) + combination(m - 1, n - 1);
    }
}
int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    printf("%d", combination(m, n));
    return 0;

}
