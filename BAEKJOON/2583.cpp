#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
int K;
int s;
int s1;
int rec[100][4];
int mask[100][100] = {0};
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int ans[100];

void sketch(int x, int y, int xx, int yy){
    for(int i=x; i<xx; i++){
        for(int j=y; j<yy; j++){
            mask[i][j] = 1;
        }
    }
}

void dfs(int x, int y, int sum){
    int nx, ny;
    s1++;
    for(int i=0; i<4; i++){
        nx = x+dir[i][0];
        ny = y+dir[i][1];
        if(nx >= N || nx < 0 || ny >= M || ny < 0 || mask[nx][ny] == 1){
            continue;
        }
        if(mask[nx][ny] == 0){
            mask[nx][ny] = 1;
            dfs(nx, ny, sum+1);
        }
    }
}

int main(void){
    scanf("%d %d %d", &M, &N, &K);
    s = 0;
    for(int i=0; i<K; i++){
        for(int j=0; j<4; j++){
            scanf(" %d", &rec[i][j]);
        }
        sketch(rec[i][0], rec[i][1], rec[i][2], rec[i][3]);
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(mask[i][j] == 0){
                s1 = 0;
                s++;
                mask[i][j] = 1;
                dfs(i, j, 1);
                ans[s-1] = s1;
            }
        }
    }

    sort(ans, ans+s);
    printf("%d\n", s);
    for(int i=0; i<s; i++){
        printf("%d ", ans[i]);
    }

    return 0;
}
