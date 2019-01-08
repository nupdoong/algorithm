#include <stdio.h>

int main(void){
    int test_case;
    int N;
    scanf("%d", &test_case);
    
    for(int T=1; T<=test_case; T++){
        int Dp[11]={0};
        Dp[0] = 1;
        scanf("%d", &N);
        for(int i=1; i<=N; i++){
            
            if(i>=1){
                Dp[i] += Dp[i-1];
            }
            if(i>=2){
                Dp[i] += Dp[i-2];
            }
            if(i>=3){
                Dp[i] += Dp[i-3];
            }
        }
        printf("%d\n", Dp[N]);
    }
    return 0;
}
