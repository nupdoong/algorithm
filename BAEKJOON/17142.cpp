#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int a, b;
int map[50][50];
int mask[50][50];
int Count;
int ans = 2e9;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<pair<int, int>> v;
vector<pair<int, int>> v2;
queue<pair<int, int>> q;
void solve(){
    Count = 0;
    b = 0;
    for(int i=0; i<v2.size(); i++){
        int x = v2[i].first;
        int y = v2[i].second;
        q.push(make_pair(x, y));
    }
    while(!q.empty()){
        Count++;
        int q_size = q.size();
        for(int i=0; i<q_size; i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int d=0; d<4; d++){
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];
                if(nx >= 0 && nx < N && ny >= 0 && ny < N){
                    if(map[nx][ny]==0 && mask[nx][ny]==0){
                        mask[nx][ny] = 1;
                        b++;
                        q.push(make_pair(nx, ny));
                    }
                    else if(map[nx][ny] == 2 && mask[nx][ny] == 0){
                        mask[nx][ny] = 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        if(a==b)
            break;
    }
    while(!q.empty())
        q.pop();
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            mask[i][j] = 0;
        }
    }
    if(a!=b)
        Count = 2e9;
}
void dfs(int num, int sum){
    if(sum==M){
        solve();
        if(ans > Count)
            ans = Count;
        return;
    }
    if(num >= v.size())
        return;
    int x = v[num].first;
    int y = v[num].second;
    v2.push_back(make_pair(x, y));
    dfs(num+1, sum+1);
    v2.pop_back();
    dfs(num+1, sum);
}
int main(void){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j]==2)
                v.push_back(make_pair(i, j));
            if(map[i][j]==0)
                a++;
        }
    }
    if(a==0)
        ans = 0;
    else
        dfs(0, 0);
    if(ans == 2e9)
        printf("-1");
    else
        printf("%d", ans);
    return 0;
}
