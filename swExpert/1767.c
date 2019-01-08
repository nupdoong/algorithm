#include <stdio.h>
int N;
int map[12][12];
int mask[12][12];
int core[12][2];
int corePtr;
int ans=10000;
int cmp;
int dir[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};

void init(){
    corePtr = 0;
    ans = 10000;
    cmp = 0;
    for(int i=0; i<N; i++){
        for(int j =0; j<N; j++){
            map[i][j] = 0;
            mask[i][j] =0;
        }
        for(int j=0; j<2; j++){
            core[i][j] = 0;
        }
    }
}

void dfs(int pos, int count, int sum){
    if(pos==corePtr){
        if(count > cmp){
            ans = sum;
            cmp = count;
        }
        else if(count == cmp){
            if(ans > sum)
                ans = sum;
        }
        return;
    }
    if(core[pos][0] == 0 || core[pos][0] == N-1 || core[pos][1] == 0 || core[pos][1] == N-1){
        dfs(pos+1, count+1, sum);
        return;
    }
    for(int i = 0; i<4; i++){
        int nx = core[pos][0];
        int ny = core[pos][1];
        int len =0;
        bool f = true;
        while(1){
            nx += dir[i][0];
            ny += dir[i][1];
            if(nx < 0 || ny < 0 || nx == N || ny == N)
                break;
            if(mask[nx][ny] == 1){
                f = false;
                break;
            }
            mask[nx][ny] = 1;
            len++;
        }
        if(f)
            dfs(pos+1, count+1, sum+len);
        while(nx - dir[i][0] != core[pos][0] || ny - dir[i][1] != core[pos][1]){
            nx -= dir[i][0];
            ny -= dir[i][1];
            mask[nx][ny]=0;
        }
            
    }
    dfs(pos+1, count, sum);
    
    
}

int main(void){
    int test_case;
    int t;
    scanf("%d", &test_case);
    for(t=1; t<=test_case; t++){
    
        scanf("%d", &N);
        for(int i = 0; i<N; i++){
            for(int j=0; j<N; j++){
                scanf("%d", &map[i][j]);
                if(map[i][j] == 1){
                    core[corePtr][0] = i;
                    core[corePtr][1] = j;
                    corePtr++;
                    mask[i][j] = 1;
                }
            }
        }
        dfs(0, 0, 0);
        printf("#%d %d\n", t, ans);
        init();
    }
    return 0;
}
