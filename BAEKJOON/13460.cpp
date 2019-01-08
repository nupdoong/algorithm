#include <iostream>
#include <vector>

using namespace std;

int N, M;
char map[10][10];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int r_x;
int r_y;
int b_x;
int b_y;
int check = 0;
int check2 = 0;
int Min = 11;

void blue(int d){
    int nx = b_x;
    int ny = b_y;
    while(1){
        nx += dir[d][0];
        ny += dir[d][1];
        if(nx >= 0 && nx < N && ny >= 0 && ny < M){
            if(map[nx][ny] == '.'){
                if(nx == r_x && ny == r_y){
                    b_x = nx - dir[d][0];
                    b_y = ny - dir[d][1];
                    return;
                }
                continue;
            }
            else if(map[nx][ny] == '#'){
                b_x = nx - dir[d][0];
                b_y = ny - dir[d][1];
                return;
            }
            else{
                b_x = nx;
                b_y = ny;
                check2 = 1;
                return;
            }
        }
    }
}

void red(int d){
    int nx = r_x;
    int ny = r_y;
    while(1){
        nx += dir[d][0];
        ny += dir[d][1];
        if(nx >= 0 && nx < N && ny >= 0 && ny < M){
            if(map[nx][ny] == '.'){
                if(nx == b_x && ny == b_y){
                    r_x = nx - dir[d][0];
                    r_y = ny - dir[d][1];
                    return;
                }
                continue;
            }
            else if(map[nx][ny] == '#'){
                r_x = nx - dir[d][0];
                r_y = ny - dir[d][1];
                return;
            }
            else if(map[nx][ny] == 'O'){
                r_x = nx;
                r_y = ny;
                check = 1;
                return;
            }
        }
    }
}

void dfs(int d, int sum){
    if(sum > 10){
        return;
    }
    if(d==0){
        if(r_y == b_y){
            if(r_x < b_x){
                red(d);
                blue(d);
            }
            else{
                blue(d);
                red(d);
            }
        }
        else{
            red(d);
            blue(d);
        }
    }
    else if(d==1){
        if(r_y == b_y){
            if(r_x > b_x){
                red(d);
                blue(d);
            }
            else{
                blue(d);
                red(d);
            }
        }
        else{
            red(d);
            blue(d);
        }
    }
    else if(d==2){
        if(r_x == b_x){
            if(r_y < b_y){
                red(d);
                blue(d);
            }
            else{
                blue(d);
                red(d);
            }
        }
        else{
            red(d);
            blue(d);
        }
    }
    else{
        if(r_x == b_x){
            if(r_y > b_y){
                red(d);
                blue(d);
            }
            else{
                blue(d);
                red(d);
            }
        }
        else{
            red(d);
            blue(d);
        }
    }
    if(check == 1){
        check = 0;
        if(check2 == 1){
            check2 = 0;
            return;
        }
        else{
            if(Min > sum){
                Min = sum;
            }
            return;
        }
    }
    if(check2 == 1){
        check2 = 0;
        return;
    }
    int nx = r_x;
    int ny = r_y;
    int mx = b_x;
    int my = b_y;
    for(int i=0; i<4; i++){
        if(i == d){
            continue;
        }
        dfs(i, sum+1);
        r_x = nx;
        r_y = ny;
        b_x = mx;
        b_y = my;
    }
}

int main(void){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf(" %1c", &map[i][j]);
            if(map[i][j] == 'R'){
                r_x = i;
                r_y = j;
                map[i][j] = '.';
            }
            if(map[i][j] == 'B'){
                b_x = i;
                b_y = j;
                map[i][j] = '.';
            }
        }
    }
    int nx = r_x;
    int ny = r_y;
    int mx = b_x;
    int my = b_y;
    for(int i=0; i<4; i++){
        dfs(i, 1);
        r_x = nx;
        r_y = ny;
        b_x = mx;
        b_y = my;
    }
    if(Min == 11){
        Min = -1;
    }
    printf("%d", Min);
    return 0;
}
