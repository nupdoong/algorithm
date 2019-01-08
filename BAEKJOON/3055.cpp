#include <iostream>
#include <queue>
using namespace std;
char map[50][50];
int mask[50][50];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int R, C;
int count;
int b;
int ans;
queue<pair<int, int>> q;
queue<pair<int, int>> q2;
int main(void){
    scanf("%d %d", &R, &C);
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            scanf(" %1c", &map[i][j]);
            if(map[i][j] == '*'){
                q.push(make_pair(i, j));
            }
            if(map[i][j] == 'S'){
                q2.push(make_pair(i, j));
                mask[i][j] = 1;
            }
        }
    }
    while(!q2.empty()){
        if(b==1){
            break;
        }
        int nx, ny, x, y;
        int a = q.size();
        int c = q2.size();
        for(int j=0; j<a; j++){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                nx = x+dir[i][0];
                ny = y+dir[i][1];
                if(nx >= 0 && nx < R && ny >= 0 && ny < C){
                    if(map[nx][ny] == '.'){
                        map[nx][ny] = '*';
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        for(int j=0; j<c; j++){
            x = q2.front().first;
        	y = q2.front().second;
        	q2.pop();
        	for(int i=0; i<4; i++){
            	nx = x+dir[i][0];
            	ny = y+dir[i][1];
            	if(nx >= 0 && nx < R && ny >= 0 && ny < C){
                	if(map[nx][ny] == '.'  && mask[nx][ny] == 0){
                        mask[nx][ny] = 1;
                    	q2.push(make_pair(nx, ny));
                	}
                	if(map[nx][ny] == 'D'){
                    	ans = count + 1;
                    	b=1;
                    	break;
                	}
            	}
        	}
        }
        count++;
    }
    if(b == 0){
        printf("KAKTUS\n");
    }
    else
        printf("%d\n", ans);
    return 0;
}
