#include <stdio.h>

int N;
int map[100][100];
int map2[100][100];
int mask[100][100];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int min, max;
int ans, sum;

void dfs(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        
        if(nx < 0 || nx == N || ny < 0 || ny == N)
            continue;
        
        if(map2[nx][ny] == 1 && mask[nx][ny] == 0){
            mask[nx][ny] = 1;
            dfs(nx, ny);
        }
        
    }
}

int main(void){
    scanf("%d", &N);
    ans = 0;
    min = 100;
    max = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j< N; j++){
            scanf("%d", &map[i][j]);
            map2[i][j] = 0;
            mask[i][j] = 0;
            if(map[i][j] < min)
                min = map[i][j];
            if(map[i][j] > max)
                max = map[i][j];
        }
    }
    for(int i=min-1; i<max; i++){
        sum = 0;
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                mask[j][k] = 0;
                if(map[j][k] <= i)
                    map2[j][k] = 0;
                else
                    map2[j][k] = 1;
            }
        }
        for(int m=0; m<N; m++){
            for(int n=0; n<N; n++){
                if(map2[m][n] == 1 && mask[m][n] == 0){
                    sum++;
                    mask[m][n] = 1;
                    dfs(m, n);
                }
            }
        }
        if(ans < sum)
            ans = sum;
    }
    
    printf("%d", ans);
    
    return 0;
}
