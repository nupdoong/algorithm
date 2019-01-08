#include <stdio.h>
int R, C;
char map[20][20];
char word[30];
int mask[20][20];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int b;
int ans = 0;
int check(char a){
    b=0;
    while(1){
        if(word[b] == a)
            return 0;
        if(word[b] == 0){
            word[b] = a;
            return 1;
        }
            
        b++;
    }
}

void dfs(int x, int y, int sum){
    int nx;
    int ny;
    int bb;
    
    for(int i=0; i<4; i++){
        nx = x+dir[i][0];
        ny = y+dir[i][1];
        if(nx < 0 || nx >= R || ny < 0 || ny >= C)
            continue;
        if(mask[nx][ny] == 1)
            continue;
        if(check(map[nx][ny])){
            bb = b;
            dfs(nx, ny, sum+1);
            word[bb] = 0;
        }
    }
    if(ans < sum){
        ans = sum;
    }
    return;
}
int main(void){
    scanf("%d %d", &R, &C);
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            scanf(" %1c", &map[i][j]);
            mask[i][j] = 0;
        }
    }
    mask[0][0] = 1;
    word[0] = map[0][0];
    dfs(0, 0, 1);
    printf("%d", ans);
    return 0;
}
