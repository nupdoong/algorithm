#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int map[16][15];
int dir[3][2] = {{0,-1}, {-1, 0}, {0, 1}};
int A[3];
int temp[16][15];
int mask[16][15];
int ans;
int Max;
int recheck;
int N, M, D;
queue<pair<int, int>> q;
vector<pair<int, int>> v;
void back(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            map[i][j] = temp[i][j];
        }
    }
}
void walking(){
    int check = 0;
    recheck = 0;
    for(int i=N-1; i>=0; i--){
        for(int j=M-1; j>=0 ;j--){
            if(map[i][j]){
                if(i==N-1){
                    map[i][j] = 0;
                }
                else{
                    check = 1;
                    map[i+1][j] = 1;
                    map[i][j] = 0;
                }
            }
        }
    }
    if(check){
        recheck = 1;
    }
}
void backup(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            mask[i][j] = 0;
        }
    }
    int q_size = q.size();
    for(int i=0; i<q_size; i++)
        q.pop();
}
void solve(){
    for(int i=0; i<3; i++){
        int Count = 0;
        int Check = 0;
        q.push(make_pair(N, A[i]));
        while(!q.empty()){
            Count++;
            int q_size = q.size();
            for(int j=0; j<q_size; j++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k=0; k<3; k++){
                    int nx = x + dir[k][0];
                    int ny = y + dir[k][1];
                    if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                        if(mask[nx][ny] == 0){
                            if(map[nx][ny]==1){
                                v.push_back(make_pair(nx, ny));
                                Check = 1;
                                break;
                            }
                            else{
                                q.push(make_pair(nx, ny));
                                mask[nx][ny] = 1;
                            }
                        }
                    }
                }
                if(Check)
                    break;
            }
            if(Check || Count == D){
                backup();
                break;
            }
        }
    }
    for(int i=0; i<v.size(); i++){
        int xx = v[i].first;
        int yy = v[i].second;
        if(map[xx][yy]){
            Max++;
        }
        map[xx][yy] = 0;
    }
    v.clear();
    walking();
    if(recheck){
        solve();
    }
}
void dfs(int num, int sum){
    if(sum>=3){
        solve();
        if(ans < Max){
            ans = Max;
        }
        Max = 0;
        back();
        return;
    }
    if(num >= M){
        return;
    }
    A[sum] = num;
    dfs(num+1, sum+1);
    A[sum] -= num;
    dfs(num+1, sum);
}

int main(void){
    scanf("%d %d %d", &N, &M, &D);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &map[i][j]);
            temp[i][j] = map[i][j];
            mask[i][j] = 0;
        }
    }
    dfs(0, 0);
    printf("%d", ans);
    return 0;
}
