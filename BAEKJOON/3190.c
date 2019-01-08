#include <stdio.h>

int N;
int K;
int L;
int map[100][100];
int time[100];
char direction[100];
int temp_x[100000];
int temp_y[100000];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int ans = 0;

void dfs(int x, int y, int t, int d, int aa, int length){
    if(t == time[aa]){
        if(direction[aa] == 'D'){
            d = (d+1)%4;
        }
        else if(direction[aa] == 'L')
            d = (d+3)%4;
        
        aa++;
    }
    int nx = x + dir[d][0];
    int ny = y + dir[d][1];
    
    if(nx < 0 || nx >= N || ny < 0 || ny >= N){
        ans = t+1;
        return;
    }
    if(map[nx][ny] == 1){
        ans = t+1;
        return;
    }
    if(map[nx][ny] == 2){
        temp_x[t+1] = nx;
        temp_y[t+1] = ny;
        map[nx][ny] = 1;
        length++;
    }
    if(map[nx][ny] == 0){
        if(length > 0){
            int xx = temp_x[t-length];
            int yy = temp_y[t-length];
            map[xx][yy] = 0;
            temp_x[t+1] = nx;
            temp_y[t+1] = ny;
            map[nx][ny] = 1;
        }
        else{
            map[x][y] = 0;
            temp_x[t+1] = nx;
            temp_y[t+1] = ny;
            map[nx][ny] = 1;
        }
    }
    dfs(nx, ny, t+1, d, aa, length);
}

int main(void){
    int a, b;
    scanf("%d", &N);
    scanf("%d", &K);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            map[i][j] = 0;
        }
    }
    for(int i=0; i<K; i++){
        scanf("%d %d", &a, &b);
        map[a-1][b-1] = 2;
    }
    scanf("%d", &L);
    for(int i=0; i<L; i++){
        scanf("%d %c", &time[i], &direction[i]);
    }
    map[0][0] = 1;
    dfs(0, 0, 0, 0, 0, 0);
    printf("%d", ans);
    return 0;
}
