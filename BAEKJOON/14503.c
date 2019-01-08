#include <stdio.h>
int N, M;
int direction;
int map[50][50];
int mask[50][50];
int xx, yy;
int ans = 0;
int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

void dfs(int x, int y, int d, int sum){
    int nx, ny;
    for(int i=d; i<d+4; i++){
        int k = i%4;
        nx = x+dir[k][0];
        ny = y+dir[k][1];
        
        if(map[nx][ny] == 0 && mask[nx][ny] == 0){
            mask[nx][ny] = 1;
            dfs(nx, ny, (k+1)%4, sum+1);
            break;
        }
        if(mask[nx][ny] == 1 || map[nx][ny] == 1){
            if(i==d+3){
                nx = x+dir[(d+1)%4][0];
                ny = y+dir[(d+1)%4][1];
                if(map[nx][ny] == 0){
                    dfs(nx, ny, d, sum);
                    break;
                }
                else{
                    if(ans < sum){
                        ans = sum;
                    }
                    return;
                }
            }
            else
                continue;
        }
    }
    
}

int main(void){
    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &xx, &yy, &direction);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1){
                mask[i][j] = 1;
            }
            else
                mask[i][j] = 0;
        }
    }
    direction = (4 - direction)%4;
    mask[xx][yy] = 1;
    dfs(xx, yy, direction, 1);
    printf("%d", ans);
    return 0;
}
