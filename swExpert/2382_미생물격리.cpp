#include <iostream>
#include <queue>
using namespace std;
int N, M, K;
int x, y, num, d;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int map[100][100];
int mask1[100][100];
int mask2[100][100];
int ans;
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;
queue<pair<int, int>> q3;
int main(void){
    int tc;
    scanf("%d", &tc);
    for(int T=1; T<=tc; T++){
        scanf("%d %d %d", &N, &M, &K);
        ans = 0;
        for(int i=0; i<K; i++){
            scanf("%d %d %d %d", &x, &y, &num, &d);
            q1.push(make_pair(x, y));
            q2.push(make_pair(num, d));
        }
        while(M>0){
            int q_size = q1.size();
            for(int i=0; i<q_size; i++){
                int nx = q1.front().first;
                int ny = q1.front().second;
                int nn = q2.front().first;
                int dd = q2.front().second;
                q1.pop();
                q2.pop();
                nx += dir[dd-1][0];
                ny += dir[dd-1][1];
                if(map[nx][ny] == 0){
                    if(nx ==0 || ny==0 || nx == N-1 || ny ==N-1){
                        nn = nn/2;
                        if(nn==0){
                            continue;
                        }
                        map[nx][ny] = nn;
                        if(dd==1)
                            dd=2;
                        else if(dd==2)
                            dd=1;
                        else if(dd==3)
                            dd=4;
                        else
                            dd=3;
                        mask1[nx][ny] = nn;
                        mask2[nx][ny] = dd;
                    }
                    else{
                        map[nx][ny] = nn;
                        mask1[nx][ny] = nn;
                        mask2[nx][ny] = dd;
                    }
                    q3.push(make_pair(nx, ny));
                }
                else{
                    map[nx][ny] += nn;
                    if(nn > mask1[nx][ny]){
                        mask1[nx][ny] = nn;
                        mask2[nx][ny] = dd;
                    }
                    else{
                        dd = mask2[nx][ny];
                    }
                    nn = map[nx][ny];
                }
            }
            int q3_size = q3.size();
            for(int i=0; i<q3_size; i++){
                int fx = q3.front().first;
                int fy = q3.front().second;
                q3.pop();
                q1.push(make_pair(fx, fy));
                int tn = map[fx][fy];
                int td = mask2[fx][fy];
                q2.push(make_pair(tn, td));
                map[fx][fy] = 0;
                mask1[fx][fy] = 0;
                mask2[fx][fy] = 0;
            }
            M--;
        }
        int q1_size = q1.size();
        for(int i=0; i<q1_size; i++){
            ans += q2.front().first;
            x = q1.front().first;
            y = q1.front().second;
            map[x][y] = 0;
            mask1[x][y] = 0;
            mask2[x][y] = 0;
            q1.pop();
            q2.pop();
        }
        printf("#%d %d\n", T, ans);
    }
    return 0;
}
