#include <iostream>
using namespace std;
int map[10][10];
int mask[10][10];
int Max = 2e9;
int ans;
int check(int x, int y, int num){
    if(x+num-1 < 10 && y+num-1 < 10){
        for(int i=x; i<x+num; i++){
            for(int j=y; j<y+num; j++){
                if(map[i][j]==0 || mask[i][j]){
                    return 0;
                }
            }
        }
        return 1;
    }
    return 0;
}
void dfs(int A1, int A2, int A3, int A4, int A5, int sum){
    int Check = 0;
    int x, y;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(map[i][j]==1 && mask[i][j] == 0){
                x = i;
                y = j;
                Check = 1;
                break;
            }
        }
        if(Check)
            break;
    }
    if(Check==0){
        if(Max > sum){
            Max = sum;
        }
        return;
    }
    if(check(x, y, 1) && A1 > 0){
        mask[x][y] = 1;
        dfs(A1-1, A2, A3, A4, A5, sum+1);
        mask[x][y] = 0;
    }
    if(check(x, y, 2) && A2 > 0){
        for(int i=x; i<x+2; i++){
            for(int j=y; j<y+2; j++){
                mask[i][j] = 1;
            }
        }
        dfs(A1, A2-1, A3, A4, A5, sum+1);
        for(int i=x; i<x+2; i++){
            for(int j=y; j<y+2; j++){
                mask[i][j] = 0;
            }
        }
    }
    if(check(x, y, 3) && A3 > 0){
        for(int i=x; i<x+3; i++){
            for(int j=y; j<y+3; j++){
                mask[i][j] = 1;
            }
        }
        dfs(A1, A2, A3-1, A4, A5, sum+1);
        for(int i=x; i<x+3; i++){
            for(int j=y; j<y+3; j++){
                mask[i][j] = 0;
            }
        }
    }
    if(check(x, y, 4) && A4 > 0){
        for(int i=x; i<x+4; i++){
            for(int j=y; j<y+4; j++){
                mask[i][j] = 1;
            }
        }
        dfs(A1, A2, A3, A4-1, A5, sum+1);
        for(int i=x; i<x+4; i++){
            for(int j=y; j<y+4; j++){
                mask[i][j] = 0;
            }
        }
    }
    if(check(x, y, 5) && A5 > 0){
        for(int i=x; i<x+5; i++){
            for(int j=y; j<y+5; j++){
                mask[i][j] = 1;
            }
        }
        dfs(A1, A2, A3, A4, A5-1, sum+1);
        for(int i=x; i<x+5; i++){
            for(int j=y; j<y+5; j++){
                mask[i][j] = 0;
            }
        }
    }
    if(sum > ans){
        ans = sum;
    }
}
int main(void){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            scanf("%d", &map[i][j]);
            mask[i][j] = 0;
        }
    }
    dfs(5, 5, 5, 5, 5, 0);
    if(Max > 25){
        if(ans == 0)
            printf("0");
        else
            printf("-1");
    }else{
        printf("%d", Max);
    }
    return 0;
}
