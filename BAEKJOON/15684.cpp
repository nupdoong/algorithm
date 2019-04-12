#include <iostream>
using namespace std;
int N, M, H;
int map[32][12];
int can[300][2];
int can_num;
int ans=-1;
int Check;
int check(){
    int temp_x;
    for(int i=1; i<=N; i++){
        temp_x = i;
        for(int j=1; j<=H; j++){
            if(map[j][temp_x]==1){
                temp_x+=1;
            }
            else if(map[j][temp_x-1]==1){
                temp_x-=1;
            }
        }
        if(temp_x!=i){
            return 0;
        }
    }
    return 1;
}
void dfs(int num, int sum, int d){
    if(sum==d){
        if(check()){
            ans = d;
            Check=1;
        }
        return;
    }
    // 사다리 설치 가능지역인지 확인
    for(int i=num; i<can_num; i++){
        int x = can[i][0];
        int y = can[i][1];
        if(map[x][y-1]==0 && map[x][y+1]==0){
            map[x][y] = 1;
            dfs(i+1, sum+1, d);
            if(Check){
                return;
            }
            map[x][y] = 0;
        }
    }
}
int main(void){
    scanf("%d %d %d", &N, &M, &H);
    int x, y;
    for(int i=1; i<=M; i++){
        scanf("%d %d", &x, &y);
        map[x][y] = 1;
    }
    // 사다리 놓을 수 있는 위치 can 배열에 저장
    for(int i=1; i<=H; i++){
        for(int j=1; j<N; j++){
            if(map[i][j]==0){
                    if(map[i][j-1]==0 && map[i][j+1]==0){
                        can[can_num][0] = i;
                        can[can_num][1] = j;
                        can_num++;
                    }

            }
        }
    }
    // 사다리 새로 설치 않해도 되는지 확인
    if(check()){
        printf("0");
        return 0;
    }
    // 사다리 설치 재귀 들어가는 부분
    for(int i =1; i<=3; i++){
        dfs(0, 0, i);
        if(Check){
            break;
        }
    }
    printf("%d", ans);
    return 0;
}
