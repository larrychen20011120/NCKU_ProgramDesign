#include <stdio.h>

int main(){
    int x1, x2, n;
    while (1) {
        scanf("%d%d%d", &x1, &x2, &n);
        if (x1 == 0 && x2 == 0 && n == 0)
            break;
        for (int i = 3; i <= n; i++){
            int temp = x2;
            x2 += x1;
            x1 = temp;
        }
        printf("%d\n", x2);
    }
    return 0;

}
