#include <stdio.h>
int N;
int map[15][2];
int ans = 0;

void dfs(int x, int sum){
    int len = map[x][0];
    int cost = map[x][1];
    if(x >= N){
        if(ans < sum)
            ans = sum;
        return;
    }
    if(x+len <= N)
        dfs(x+len, sum+cost);  
    dfs(x+1, sum);
}
int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d %d", &map[i][0], &map[i][1]);
    dfs(0, 0);
    printf("%d", ans);
    return 0;
}
