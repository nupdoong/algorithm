#include <stdio.h>
int N;
int map[30][30];
int mask[30][30];
int ans;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int sum;
int temp;
int res[25] = {0};

void dfs(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        
        if(nx < 0 || nx ==N || ny <0 || ny == N)
            continue;
        
        if(mask[nx][ny]==0 && map[nx][ny]==1){
            mask[nx][ny] = 1;
            sum++;
            dfs(nx, ny);
        }
    }
}

int main(void){
    scanf("%d", &N);
    ans = 0;
    sum = 0;
    for(int i=0; i<N; i++){
        res[i]=0;
        for(int j=0; j<N; j++){
            scanf("%1d", &map[i][j]);
            mask[i][j] = 0;
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] == 1 && mask[i][j] == 0){
                mask[i][j] = 1;
                ans++;
                sum=1;
                dfs(i, j);
                res[ans-1] = sum;
            }
        }
    }
    printf("%d\n", ans);
    for(int i=0; i<ans; i++){
        for(int j=i; j<ans; j++){
            if(res[j] < res[i]){
                temp = res[i];
                res[i] = res[j];
                res[j] = temp;
            }
        }
    }
    for(int i=0; i<ans; i++){
        printf("%d\n", res[i]);
    }
    return 0;
}
