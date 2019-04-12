#include <iostream>
#include <queue>
using namespace std;
int N, M;
int map[8][8];
int mask[8][8];
int temp[64][2];
int z_num;
int Count;
int ans;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void solve(){
    queue<pair<int, int>> q;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            mask[i][j] = 0;
            if(map[i][j]==2){
                q.push(make_pair(i, j));
                mask[i][j] = 1;
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x+dir[i][0];
            int ny = y+dir[i][1];
            if(nx>=0 && nx <N && ny >=0 && ny<M){
                if(map[nx][ny]==0 && mask[nx][ny] == 0){
                    q.push(make_pair(nx, ny));
                    mask[nx][ny] = 1;
                }
            }
        }
    } 
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]==0 && mask[i][j] == 0){
                Count++;
            }
        }
    }
}

void dfs(int num, int sum){
    if(sum==3){
        solve();
        if(ans < Count){
            ans = Count;
        }
        Count = 0;
        return;
    }
    if(num >= z_num){
        return;
    }
    int x = temp[num][0];
    int y = temp[num][1];
    map[x][y] = 1;
    dfs(num+1, sum+1);
    map[x][y] = 0;
    dfs(num+1, sum);
}

int main(void){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j]==0){
                temp[z_num][0] = i;
                temp[z_num][1] = j;
                z_num++;
            }
        }
    }
    dfs(0, 0);
    printf("%d", ans);
    return 0;
}
