#include <iostream>
#include <queue>
using namespace std;

char map[50][50];
int mask[50][50];
int N, M;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int maxx;
queue<pair<int, int>> q;
void backup(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            mask[i][j] = 0;
        }
    }
}
int bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x+dir[i][0];
            int ny = y+dir[i][1];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                if(map[nx][ny] == 'L' && mask[nx][ny] == 0){
                    mask[nx][ny] = mask[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(maxx < mask[i][j]){
                maxx = mask[i][j];
            }
        }
    }
    return maxx;
}

int main(void){
    int ans = 0;
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf(" %1c", &map[i][j]);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 'L'){
                q.push(make_pair(i, j));
                int a = bfs();
                if(ans < a){
                    ans = a;
                }
                backup();
            }
        }
    }
    printf("%d", ans);
    return 0;
}
