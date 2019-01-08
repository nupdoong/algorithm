#include <stdio.h>

int N, M, K;
int map[50][50];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int visit[50][50];
int ans;

void init(){
    ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            visit[i][j] = 0;
            map[i][j] = 0;
        }
    }
}

void dfs(int x, int y){

    for(int i =0; i<4; i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        
        if(nx < 0 || nx ==N || ny <0 || ny == M)
            continue;
        
        if(map[nx][ny] == 1 && visit[nx][ny] == 0){
            visit[nx][ny] = 1;
            dfs(nx, ny);
        }
    }    
}

int main(void){
    int T, test_case;
    int n, m;
    scanf("%d", &test_case);
    for(T=1; T<=test_case; T++){
        scanf("%d %d %d", &N, &M, &K);
        init();
        for(int i=0; i<K; i++){
            scanf("%d %d", &n, &m);
            map[n][m] = 1;
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(map[i][j] == 1 && visit[i][j] == 0){
                    ans++;
                    visit[i][j] = 1;
                    dfs(i, j);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
