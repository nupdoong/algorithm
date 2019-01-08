#include <stdio.h>

int N, M;
int map[300][300];
int map2[300][300];
int map3[300][300];
int map4[300][300];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int max = 0;
int part = 0;
int nx, ny;

void newIce(int x, int y){
    for(int i=0; i<4; i++){
        nx = x + dir[i][0];
        ny = y + dir[i][1];
        
        if(nx < 0 || nx == N || ny < 0 || ny == M)
            continue;
        
        if(map[nx][ny] == 0 || map4[nx][ny] == 0){
            map3[x][y]--;
            
            if(map3[x][y] == 0)
                break;
        }
    }
}

void dfs(int x, int y){
    for(int i=0; i<4; i++){
        nx = x + dir[i][0];
        ny = y + dir[i][1];
        
        if(nx < 0 || nx == N || ny < 0 || ny == M)
            continue;
        
        if(map2[nx][ny] == 0 && map3[nx][ny] > 0)
        {
            map2[nx][ny] = 1;
            dfs(nx, ny);
        }
    }
}

int main(void){
    scanf("%d %d", &N, &M);
    max = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &map[i][j]);
            map2[i][j] = 0;
            map4[i][j] = 0;
            map3[i][j] = map[i][j];
        }
    }
    for(int y=0; y <= 100000; y++){
        part = 0;
        max = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(map3[i][j] > 0)
                    map4[i][j] = 1;
                else
                    map4[i][j] = 0;
                
                if(map3[i][j] > 0 && map2[i][j] == 0){
                    part++;
                    map2[i][j] = 1;
                    if(part == 2){
                        printf("%d", y);
                        return 0;
                    }
                    dfs(i, j);
                }

            }
        }
        for(int i=0; i<N; i++){
            for(int j=0 ;j<M;j++){
                map2[i][j] = 0;
                if(map3[i][j] > 0){
                    newIce(i, j);
                    max++;
                }
            }
        }

        if(max == 0){
            printf("0");
            return 0;
        }
    }
}
