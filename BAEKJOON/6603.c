#include <stdio.h>
int k = 1;
int num[49];
int ans[49];

void dfs(int n, int sum){
    if(n == k+1){
        return;
    }
    if(sum == 6){
        for(int i=0; i<6; i++){
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;
    }
    ans[sum] = num[n]; 
    dfs(n+1, sum+1);
    dfs(n+1, sum);
}

int main(void){
    while(k != 0){
        scanf("%d", &k);
        for(int i=0; i<k; i++){
            scanf("%d", &num[i]);
        }
        dfs(0, 0);
        printf("\n");
    }
    return 0;
}
