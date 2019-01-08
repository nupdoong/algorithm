#include <stdio.h>

int N;
int A[1000000];
int B, C;
long long sum;
long long ans;

int main(void){
    int p;
    int temp;
    int pp;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    scanf("%d %d", &B, &C);
    sum = sum+N;
    
    for(int i=0; i<N; i++){
        if(A[i]-B <= 0){
            continue;
        }
        p = (A[i]-B)/C;
        temp = (A[i]-B)%C;
        if(temp > 0){
            pp = p+1;
        }
        else
            pp = p;

        sum += pp;
    }
    ans = sum;
    printf("%lld", ans);
    return 0;
}
