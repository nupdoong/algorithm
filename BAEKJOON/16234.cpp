#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

int N, L, R;
int map[50][50];
int mask[50][50];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int temp;
int check;
int Move;
int temp_x;
queue<pair<int, int>> q;
vector<pair<int,int>> v[2500];

void reset(){
    Move++;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            mask[i][j] = -1;
        }
    }

    temp = 0;
    temp_x = 0;
    mask[0][0] = 0;
    q.push(make_pair(0,0));
    v[0].push_back(make_pair(0, 0));
}

void solve(){
    check = 0;
    for(int i=0; i<2500; i++){
        int v_size = v[i].size();
        if(v_size==1 || v_size == 0){
            v[i].clear();
            continue;
        }
        int sum = 0;
        check++;
        for(int j=0; j<v_size; j++){
            int x = v[i][j].first;
            int y = v[i][j].second;
            sum+=map[x][y];
        }
        for(int j=0; j<v_size; j++){
            int x = v[i][j].first;
            int y = v[i][j].second;
            map[x][y] = sum/v_size;
        }
        v[i].clear();
    }
}

int main(void){
    scanf("%d %d %d", &N, &L, &R);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &map[i][j]);
            mask[i][j] = -1;
        }
    }
    q.push(make_pair(0, 0));
    mask[0][0] = 0;
    v[0].push_back(make_pair(0, 0));
    while(1){
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
        
            for(int i=0; i<4; i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
            
                if(nx >= 0 && nx < N && ny >= 0 && ny < N){
                    if(mask[nx][ny] == -1 || mask[nx][ny] > mask[x][y]){
                        if(abs(map[nx][ny]-map[x][y]) >= L && abs(map[nx][ny]-map[x][y]) <= R){
                            if(mask[nx][ny] > mask[x][y]){
                                int xx = mask[nx][ny];
                                v[xx].pop_back();
                            }
                            mask[nx][ny] = mask[x][y];
                        }
                        else{
                            if(mask[nx][ny] > mask[x][y]){
                                continue;
                            }
                            mask[nx][ny] = temp_x + 1;
                            temp_x = mask[nx][ny];
                        }
                        temp = mask[nx][ny];
                        v[temp].push_back(make_pair(nx, ny));
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }

        solve();
        
        if(check == 0){
            break;
        }
        reset();
    }
    
    printf("%d", Move);
    
    return 0;
}
