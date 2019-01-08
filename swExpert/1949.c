#include <stdio.h>
int N, K;
int map[8][8];
int mask[8][8];
int max;
int sum;
int dir[4][2] = {{-1,0},{1,0}, {0,-1}, {0,1}};

void dfs(int x, int y, int h, int len, int used){
    if (len > sum){
        sum = len;
    }
    
    int nx;
    int ny;
    
    for(int i=0; i<4; i++){
        nx = x+dir[i][0];
        ny = y+dir[i][1];
        if(mask[nx][ny] == 0 && nx >= 0 && nx < N && ny >= 0 && ny < N){
            if(map[nx][ny] < h){
                 mask[nx][ny] = 1;
               dfs(nx, ny, map[nx][ny], len+1, used);
                mask[nx][ny] = 0;
            }
            else{
                if(used == 0 && map[nx][ny] - K < h){
                    mask[nx][ny] = 1;
                    dfs(nx, ny, h - 1, len+1, 1);
                    mask[nx][ny] = 0;
                }
            }
        }
    }
    
}

int main(void){
    int T, test_case;
    scanf("%d", &test_case);
    for(T=1; T<= test_case; T++){
        max = 0;
        sum = 0;
        scanf("%d %d", &N, &K);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                scanf("%d", &map[i][j]);
                mask[i][j] = 0;
                if(map[i][j]>max)
                    max = map[i][j];
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[i][j] == max){
                    mask[i][j] =1;
                    dfs(i, j, max, 1, 0);
                    mask[i][j] = 0;
                }
            }
        }
        printf("#%d %d\n", T, sum);
    }
    return 0;
}
