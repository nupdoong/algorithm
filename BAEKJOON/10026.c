#include <stdio.h>
int N;
char map[100][100];
char map2[100][100];
int mask[100][100];
int mask2[100][100];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int s;
int s1;
void dfs(int x, int y, char color, int check){
    int nx;
    int ny;
    for(int i=0; i<4; i++){
        nx = x+dir[i][0];
        ny = y+dir[i][1];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N){
            continue;
        }
        if(check == 0){
            if(map[nx][ny] == color && mask[nx][ny] == 0){
                mask[nx][ny] = 1;
                dfs(nx, ny, color, check);
            }   
        }
        else{
            if(map2[nx][ny] == color && mask2[nx][ny] == 0){
                mask2[nx][ny] = 1;
                dfs(nx, ny, color, check);
            }   
        }
    }
}
int main(void){
    scanf("%d", &N);
    s = 0;
    s1 = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf(" %1c", &map[i][j]);
            map2[i][j] = map[i][j];
            if(map[i][j] == 'G'){
                map2[i][j] = 'R';
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(mask[i][j] == 0){
                s++;
                mask[i][j] = 1;
                dfs(i, j, map[i][j], 0);
            }
            if(mask2[i][j] == 0){
                s1++;
                mask2[i][j] = 1;
                dfs(i, j, map2[i][j], 1);
            }
        }
    }
    printf("%d %d", s, s1);
    return 0;
}
