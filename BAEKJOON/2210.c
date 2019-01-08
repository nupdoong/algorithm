#include <stdio.h>

int map[5][5];
int mask[1000000];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int count=0;

void dfs(int x, int y, int d, int sum){
    int nx, ny;
    int a;
    if(d < 0){
        mask[sum]++;
        return;
    }
    for(int i=0; i<4; i++){
        nx = x + dir[i][0];
        ny = y + dir[i][1];
        
        if(nx < 0 || nx >=5 || ny < 0 || ny >=5){
            continue;
        }
        a = map[nx][ny];
        for(int j=0; j<d; j++){
            a *= 10;
        }
        dfs(nx, ny, d-1, sum+a);
    }
}
int main(void){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            scanf("%d", &map[i][j]);
        }
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            dfs(i, j, 5, 0);
        }
    }
    for(int i=0; i<1000000; i++){
        if(mask[i] > 0){
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
