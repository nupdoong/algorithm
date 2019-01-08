#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int N, M;
int map[8][8];
int temp[8][8];
int ze[64][2];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int maxx;
int c;
queue<pair<int, int>> q;
void backup(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(temp[i][j] == 3)
                temp[i][j] = 0;
        }
    }
    return;
}

int bfs(){
    int count = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(temp[i][j] == 2){
                q.push(make_pair(i, j));
            }
        }
    }
    while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int j=0; j<4; j++){
                int nx = x + dir[j][0];
                int ny = y + dir[j][1];
                if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                    if(temp[nx][ny] == 0){
                        temp[nx][ny] = 3;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(temp[i][j] == 0)
                count++;
        }
    }
    backup();
    return count;
}
void dfs(int x, int sum){
    int b;
    if(sum == 3){
        b = bfs();
        if(b > maxx){
            maxx = b;
        }
        return;
    }
    if(x==c)
        return;
    int nx = ze[x][0];
    int ny = ze[x][1];
    temp[nx][ny] = 1;
    dfs(x+1, sum+1);
    temp[nx][ny] = 0;
    dfs(x+1, sum);
    
}

int main(void){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &map[i][j]);
            temp[i][j] = map[i][j];
            if(map[i][j] == 0){
                ze[c][0] = i;
                ze[c][1] = j;
                c++;
            }
        }
    }
    dfs(0, 0);
    printf("%d", maxx);
    return 0;
}
