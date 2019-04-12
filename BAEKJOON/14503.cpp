#include <iostream>

using namespace std;
int N, M;
int map[50][50];
int mask[50][50];
int i_x;
int i_y;
int i_d;
int ans = 1;
int dir[4][2] = {{-1, 0}, {0,1}, {1, 0}, {0,-1}};
void solve(int x, int y, int d, int num){
    int nd, nx, ny;
    if(num==4){
        nd = (d+2)%4;
        nx = x + dir[nd][0];
        ny = y + dir[nd][1];
        if(nx >=0 && nx < N && ny >=0 && ny <M){
            if(map[nx][ny]==0){
                solve(nx, ny, d, 0);
            }
            return;
        }
        return;
    }
    nd = (d+3)%4;
    nx = x+dir[nd][0];
    ny = y+dir[nd][1];
    if(nx >= 0 && nx < N && ny >=0 && ny < M){
        if(map[nx][ny]==0 && mask[nx][ny]==0){
            mask[nx][ny] = 1;
            ans++;
            solve(nx, ny, nd, 0);
        }
        else{
            solve(x, y, nd, num+1);
        }
    }
}
int main(void){
    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &i_x, &i_y, &i_d);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &map[i][j]);
        }
    }
    mask[i_x][i_y] = 1;
    solve(i_x, i_y, i_d, 0);
    printf("%d", ans);
    return 0;
}
