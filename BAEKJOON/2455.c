#include <stdio.h>
int sum;
int a;
int b;
int max;
int main(void){
    for(int i=0; i<4; i++){
        scanf("%d %d", &a, &b);
        sum = sum + b - a;
        if(max < sum){
            max = sum;
        }
    }
    printf("%d", max);
    return 0;
}
