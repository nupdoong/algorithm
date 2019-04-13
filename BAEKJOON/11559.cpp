#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[12][6];
int mask[12][6];
int Check;
int ans;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<pair<int, int>> v;
vector<int> v2;
queue<pair<int, int>> q;
void bfs(){
    while(!q.empty()){
        int q_size = q.size();
        for(int i=0; i<q_size; i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int d=0; d<4; d++){
                int nx = x +dir[d][0];
                int ny = y +dir[d][1];
                if(nx>=0 && nx<12 && ny >=0 && ny<6){
                    if(mask[nx][ny]==0 && map[nx][ny]==map[x][y]){
                        q.push(make_pair(nx, ny));
                        v.push_back(make_pair(nx, ny));
                        mask[nx][ny] = 1;
                    }
                }
            }
        }
    }
    if(v.size()>=4){
        Check = 1;
        for(int i=0; i<v.size(); i++){
            int xx = v[i].first;
            int yy = v[i].second;
            map[xx][yy] = 0;
        }
    }
    v.clear();
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            mask[i][j] = 0;
        }
    }
}
void down(){
    for(int j=0; j<6; j++){
        for(int i=0; i<12; i++){
            if(map[i][j]>0){
                v2.push_back(map[i][j]);
                map[i][j] = 0;
            }
        }
        int cc=0;
        for(int i=v2.size()-1; i>=0; i--){
            map[11-cc][j] = v2[i];
            cc++;
        }
        v2.clear();
    }
}
void solve(){
    Check = 0;
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            if(map[i][j] > 0 && mask[i][j]==0){
                mask[i][j] = 1;
                v.push_back(make_pair(i, j));
                q.push(make_pair(i, j));
                bfs();
            }
        }
    }
    if(Check){
        ans++;
        down();
        solve();
    }
}
int main(void){
    char c;
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            scanf(" %1c", &c);
            if(c=='.'){
                map[i][j] = 0;
            }
            else if(c=='R'){
                map[i][j] = 1;
            }
            else if(c=='G'){
                map[i][j] = 2;
            }
            else if(c=='B'){
                map[i][j] = 3;
            }
            else if(c=='P'){
                map[i][j] = 4;
            }
            else if(c=='Y'){
                map[i][j] = 5;
            }
        }
    }
    solve();
    printf("%d", ans);
    return 0;
}
