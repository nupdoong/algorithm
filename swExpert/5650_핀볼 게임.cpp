#include <iostream>
using namespace std;
int N;
int map[100][100];
int start_x, start_y;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int block_dir[6][4] = {{0, 1, 2, 3}, {1, 3, 0, 2}, {1, 2, 3, 0}, {2, 0, 3, 1}, {3, 0, 1, 2}, {1, 0, 3, 2}};
int ans;
int score;
int c_hall;
int b_check[5];
int w_hall[5][4];
int block_num;

void solve(int x, int y, int d){
    int nx = x + dir[d][0];
    int ny = y + dir[d][1];
    while(1){
        if(nx < 0 || ny < 0 || nx >= N || ny >=N){
            score++;
            d = block_dir[5][d];
            nx += dir[d][0];
            ny += dir[d][1];
            continue;
        }
        if(nx == start_x && ny == start_y)
            break;
        if(map[nx][ny] == -1)
            break;
        if(map[nx][ny] >= 0 && map[nx][ny] <= 5){
            if(map[nx][ny] != 0)
                score++;
            block_num = map[nx][ny];
            d = block_dir[block_num][d];
            nx += dir[d][0];
            ny += dir[d][1];
            continue;
        }
        if(map[nx][ny] > 5){
            c_hall = map[nx][ny] - 6;
            if(nx == w_hall[c_hall][0] && ny == w_hall[c_hall][1]){
                nx = w_hall[c_hall][2];
                ny = w_hall[c_hall][3];
            }
            else{
                nx = w_hall[c_hall][0];
                ny = w_hall[c_hall][1];
            }
            nx += dir[d][0];
            ny += dir[d][1];
            continue;
        }
    }
    return;
    
}

int main(void){
    int tc;
    scanf("%d", &tc);
    for(int T=1; T<=tc; T++){
        ans = 0;
        score = 0;
        scanf("%d", &N);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                scanf("%d", &map[i][j]);
                if(map[i][j] > 5){
                    c_hall = map[i][j]-6;
                    if(b_check[c_hall] == 0){
                        b_check[c_hall]++;
                        w_hall[c_hall][0] = i;
                        w_hall[c_hall][1] = j;
                    }
                    else{
                        b_check[c_hall] = 0;
                        w_hall[c_hall][2] = i;
                        w_hall[c_hall][3] = j;
                    }
                }
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[i][j] == 0){
                    start_x = i;
                    start_y = j;
                    for(int i=0; i<4; i++){
                        solve(start_x, start_y, i);
                        if(ans < score){
                            ans = score;
                        }
                        score = 0;
                    }
                }
            }
        }
        printf("#%d %d\n", T, ans);
    }
    return 0 ;
}
