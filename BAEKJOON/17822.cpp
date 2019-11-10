#include <iostream>
#include <deque>
#include <queue>
using namespace std;
deque<int> dq[51];
queue<pair<int, int>> q;
int N, M, T;
int Check;
int comp_num;
int sum;
int mask[51][50];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void reset(){
    for(int i=0; i<=N; i++){
        for(int j=0; j<M; j++){
            mask[i][j] = 0;
        }
    }
}
void bfs(){
    while(!q.empty()){
        int q_size = q.size();
        for(int i=0; i<q_size; i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int d=0; d<4; d++){
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];
                if(nx <= N && nx > 0){
                    if(ny == -1){
                        ny = M-1;
                    }
                    if(ny == M){
                        ny = 0;
                    }
                    if(mask[nx][ny]==0 && dq[nx][ny] != -1){
                        if(comp_num==dq[nx][ny]){
                            dq[x][y] = -1;
                            dq[nx][ny] = -1;
                            Check = 1;
                            q.push(make_pair(nx, ny));
                            mask[nx][ny] = 1;
                        }
                    }
                }
            }
        }
    }
}
void solve(){
    Check = 0;
    for(int j=1; j<=N; j++){
        for(int k=0; k<M; k++){
            if(mask[j][k]==0 && dq[j][k] > 0){
                mask[j][k] = 1;
                q.push(make_pair(j, k));
                comp_num = dq[j][k];
                bfs();
            }
        }
    }
    if(Check==0){
        sum = 0;
        int s_num = 0;
        for(int i=1; i<=N; i++){
            for(int j=0; j<M; j++){
                if(dq[i][j] != -1){
                	sum += dq[i][j];
                    s_num++;
                }
            }
        }
        float average = (float)sum / (float)s_num;
        for(int i=1; i<=N; i++){
            for(int j=0; j<M; j++){
                if(dq[i][j] != -1){
                    if((float)dq[i][j] > average){
                    	dq[i][j]--;
                	}
                	else if((float)dq[i][j] < average){
                    	dq[i][j]++;
                	}
                }
            }
        }
    }
    reset();
}
int main(void){
    scanf("%d %d %d", &N, &M, &T);
    for(int i=1; i<=N; i++){
        for(int j=0; j<M; j++){
            int temp;
            scanf("%d", &temp);
            dq[i].push_back(temp);
        }
    }
    for(int i=0; i<T; i++){
        int x, d, k;
        scanf("%d %d %d", &x, &d, &k);
        for(int j=1; (j*x)<=N; j++){
           int temp = j*x;
            if(temp> N){
                break;
            }
            if(d==0){
                for(int jj=0; jj<k; jj++){
                    int num = dq[temp][M-1];
                    dq[temp].pop_back();
                    dq[temp].push_front(num);
                }
            }
            else{
                for(int jj=0; jj<k; jj++){
                    int num = dq[temp][0];
                    dq[temp].pop_front();
                    dq[temp].push_back(num);
                }
            }
        }
        solve();
    }
    sum = 0;
    for(int i=1; i<=N; i++){
        for(int j=0; j<M; j++){
            if(dq[i][j] != -1)
            sum += dq[i][j];
        }
    }
    printf("%d", sum);
    return 0;
}
