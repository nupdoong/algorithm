#include <stdio.h>
int N;
int map[1000][3];
int min_v[1000][3];
int min = 1000000;

void dfs(int x, int rgb, int sum){
    if(x == N){
        if(sum < min)
            min = sum;
        return;
    }
    
    for(int i=0; i<3; i++){
        if(i == rgb)
            continue;
       
        if(min_v[x][i] <= sum + map[x][i])
            continue;
        else
            min_v[x][i] = sum + map[x][i];
        dfs(x+1, i, min_v[x][i]);
    }
}
int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &map[i][j]);
            min_v[i][j] = 100000;
        }
    }
    for(int i=0; i<3; i++){
        min_v[0][i] = map[0][i];
        dfs(1, i, map[0][i]);
    }
    printf("%d", min);
    return 0;
}
