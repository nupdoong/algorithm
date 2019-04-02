#include <iostream>
#include <queue>
using namespace std;
int map[15][12];
int N, W, H;
int ans;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void change(){
    for (int j = 0; j < W; j++){
        int i = H-1;
        for (int x = H-1; x >= 0; x--){
            if (map[x][j] != 0){
                int temp = map[x][j];
                map[x][j] = 0;
                map[i--][j] = temp;
            }
        }
    }
}
int solve(int x, int y){
    int sum=1;
    int xx, yy;
    queue<pair<int, int>> q;
    queue<int> q1;
    q.push(make_pair(x, y));
    q1.push(map[x][y]);
    map[x][y] = 0;
    while(!q.empty()){
        int q_size = q.size();
        for(int i=0; i<q_size; i++){
            int nx = q.front().first;
            int ny = q.front().second;
            int b_size = q1.front();
            q.pop();
            q1.pop();
            for(int i=0; i<4; i++){
                xx = nx;
                yy = ny;
                for(int j=1; j<b_size; j++){
                    xx += dir[i][0];
                    yy += dir[i][1];
                    if(xx >= 0 && xx < H && yy >= 0 && yy < W){
                        if(map[xx][yy] >= 1){
                            q.push(make_pair(xx, yy));
                            q1.push(map[xx][yy]);
                            map[xx][yy] = 0;
                            sum++;
                        }
                    }
                }
            }
        }
    }
    change();
    return sum;
}
void dfs(int num, int sum){
    int temp[15][12];
    int check;
    if(num == N){
        if(ans < sum){
            ans = sum;
        }
        return;
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            temp[i][j] = map[i][j];
        }
    }
    for(int loc =0; loc < W; loc++){
        check = 0;
        for(int i=0; i<H; i++){
            if(map[i][loc]>=1){
                check++;
                dfs(num+1, sum+solve(i, loc));
                for(int k=0; k<H; k++){
                    for(int j=0; j<W; j++){
                        map[k][j] = temp[k][j];
                    }
                }
                break;
            }
        }
    }
    if(check == 0){
            dfs(N, sum);
     }
}
int main(void){
    int tc;
    int Count;
    scanf("%d", &tc);
    for(int T=1; T<=tc; T++){
        ans = 0;
        Count = 0;
        scanf("%d %d %d", &N, &W, &H);
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                scanf("%d", &map[i][j]);
                if(map[i][j] > 0)
                    Count++;
            }
        }
        dfs(0, 0);
        printf("#%d %d\n", T, Count - ans);
    }
    return 0;
}
