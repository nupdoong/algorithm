#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int N, M;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int map[100][100];
int mask[100][100];
int check;
queue<pair<int,int>> q;
int main(void){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d", &map[i][j]);
            mask[i][j] = 0;
        }
    }
    q.push(make_pair(0, 0));
    mask[0][0] = 1;
    
    while(!q.empty()){
        	int x = q.front().first;
        	int y = q.front().second;
            if(x == N-1 && y == M-1){
                break;
            }
            q.pop();
        	for(int i=0; i<4; i++){
            	int nx = x + dir[i][0];
            	int ny = y + dir[i][1];
            	if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                	if(map[nx][ny] == 1 && mask[nx][ny] == 0){
                    	mask[nx][ny] = mask[x][y] + 1;
                    	q.push(make_pair(nx, ny));
                	}
            	}
        	}
    }
    printf("%d", mask[N-1][M-1]);
    
    return 0;
}
