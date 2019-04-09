#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
int N, M;
int ans=1;
int map[20][20];
int mask[20][20];
int dir[4][2] = {{-1, 0}, {1, 0}, {0,-1}, {0, 1}};
queue<pair<int, int>> q;
void reset(){
    while(!q.empty()){
        q.pop();
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            mask[i][j] = 0;
        }
    }
}
void solve(int x, int y){
    q.push(make_pair(x, y));
    int time=1;
    int Count=0;
    int cost =0;
    if(map[x][y]==1){
        Count++;
    }
    while(!q.empty()){
        int q_size = q.size();
        cost = time*time+(time-1)*(time-1);
        if(cost <= Count*M){
            if(ans < Count){
                ans = Count;
            }
        }
        for(int i=0; i<q_size; i++){
            int xx = q.front().first;
            int yy = q.front().second;
            q.pop();
            for(int j=0; j<4; j++){
                int nx = xx + dir[j][0];
                int ny = yy + dir[j][1];
                if(nx>=0 && nx < N && ny >=0 && ny < N){
                    if(mask[nx][ny]==0){
                        if(map[nx][ny]){
                            Count++;
                        }
                        mask[nx][ny] = 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        time++;
    }
}
int main(void){
    int tc;
    scanf("%d", &tc);
    for(int T=1; T<=tc; T++){
        ans = 1;
        scanf("%d %d", &N, &M);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                scanf("%d", &map[i][j]);
                mask[i][j] = 0;
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                reset();
                mask[i][j] = 1;
                solve(i, j);
            }
        }
        printf("#%d %d\n", T, ans);
    }
    return 0;
}
