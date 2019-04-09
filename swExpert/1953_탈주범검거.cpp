#include <iostream>
#include <queue>
using namespace std;
int N, M, R, C, L;
int map[50][50];
int mask[50][50];
int ans;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int main(void){
    int tc;
    scanf("%d", &tc);
    for(int T=1; T<=tc; T++){
        ans = 0;
        scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
        queue<pair<int, int>> q;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                scanf("%d", &map[i][j]);
                mask[i][j] = 0;
            }
        }
        q.push(make_pair(R, C));
        mask[R][C] = 1;
        int Count = 1;
        while(!q.empty()){
            if(Count == L)
                break;
            int q_size = q.size();
            for(int i=0; i<q_size; i++){
                int x = q.front().first;
                int y = q.front().second;
                int p = map[x][y];
                q.pop();
                for(int j=0; j<4; j++){
                    if(p==2){
                        if(j==0 || j==1){
                            continue;
                        }
                    }
                    else if(p==3){
                        if(j==2 || j==3){
                            continue;
                        }
                    }
                    else if(p==4){
                        if(j==1 || j==2){
                            continue;
                        }
                    }
                    else if(p==5){
                        if(j==1 || j==3){
                            continue;
                        }
                    }
                    else if(p==6){
                        if(j==0 || j==3){
                            continue;
                        }
                    }
                    else if(p==7){
                        if(j==0 || j==2){
                            continue;
                        }
                    }
                    int nx = x + dir[j][0];
                    int ny = y + dir[j][1];
                    if(nx >=0 && nx <N && ny >=0 && ny < M){
                        if(mask[nx][ny]==0 && map[nx][ny] > 0){
                            if(j==1){
                                if(map[nx][ny]==1 || map[nx][ny] ==3 || map[nx][ny] == 4 || map[nx][ny] == 5){
                                    mask[nx][ny] = 1;
                                    q.push(make_pair(nx, ny));
                                }
                            }
                            else if(j==0){
                                if(map[nx][ny]==1 || map[nx][ny] ==3 || map[nx][ny] == 6 || map[nx][ny] == 7){
                                    mask[nx][ny] = 1;
                                    q.push(make_pair(nx, ny));
                                }
                            }
                            else if(j==2){
                                if(map[nx][ny]==1 || map[nx][ny] ==2 || map[nx][ny] == 4 || map[nx][ny] == 7){
                                    mask[nx][ny] = 1;
                                    q.push(make_pair(nx, ny));
                                }
                            }
                            else if(j==3){
                                if(map[nx][ny]==1 || map[nx][ny] ==2 || map[nx][ny] == 5 || map[nx][ny] == 6){
                                    mask[nx][ny] = 1;
                                    q.push(make_pair(nx, ny));
                                }
                            }
                        }
                    }
                }
            }
            Count++;
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(mask[i][j]==1){
                    ans++;
                }
            }
        }
        printf("#%d %d\n", T, ans);
            
    }
    return 0;
}
