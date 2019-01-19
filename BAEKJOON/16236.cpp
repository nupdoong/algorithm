#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int map[20][20];
int mask[20][20];
int shark_x;
int shark_y;
int shark_size;
int temp_count;
int Count;
int eaten;
int check;
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

queue<pair<int, int>> q;
vector<pair<int, int>> v;

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

void reset(){
    int q_size = q.size();
    for(int i=0; i<q_size; i++){
        q.pop();
    }
    for(int i=0 ; i<N; i++){
        for(int j=0; j<N; j++){
            mask[i][j] = 0;
        }
    }
    v.clear();
}

void solve(){
    sort(v.begin(), v.end(), comp);
    int x = v[0].first;
    int y = v[0].second;
    map[x][y] = 0;
    eaten++;
    if(eaten == shark_size){
                                    shark_size++;
                                    eaten = 0;
    }
    reset();
    mask[x][y] = 1;
    q.push(make_pair(x, y));
}

int main(void){
    scanf("%d", &N);
    shark_size = 2;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 9){
                mask[i][j] = 1;
                shark_x = i;
                shark_y = j;
                map[i][j] = 0;
            }
        }
    }
    q.push(make_pair(shark_x, shark_y));
    while(!q.empty()){
        check = 0;
        int q_size = q.size();
        for(int i=0; i<q_size; i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(nx >= 0 && nx < N && ny >= 0 && ny < N){
                    if(map[nx][ny] <= shark_size){
                        if(mask[nx][ny] == 0){
                            if(map[nx][ny] >= 1 && map[nx][ny] < shark_size){
                       
                                v.push_back(make_pair(nx, ny));
                                mask[nx][ny] = 1;
                                check = 1;
                            }
                            else{
                                q.push(make_pair(nx, ny));
                                mask[nx][ny] = 1;
                            }
                        }
                    }
                }
            }
        }
        Count++;
        if(check==1){
            temp_count = Count;
            solve();
        }
    }
    printf("%d", temp_count);
    return 0;
}
