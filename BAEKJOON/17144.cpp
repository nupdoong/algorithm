#include <iostream>

using namespace std;
int R, C, T;
int Air_cord[2][2];
int Count;
int ans;
int A[51][51];
int B[51][51];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void solve(){
    Count++;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(A[i][j] >= 5){
                B[i][j] = A[i][j] / 5;
            }
        }
    }
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(B[i][j]>0){
                int d_count = 0;
                for(int d=0; d<4; d++){
                    int nx = i + dir[d][0];
                    int ny = j + dir[d][1];
                    if(nx >= 0 && nx < R && ny >= 0 && ny < C){
                        if(A[nx][ny]!=-1){
                            A[nx][ny] += B[i][j];
                            d_count++;
                        }
                    }
                }
                if(d_count > 0){
                    A[i][j] -= B[i][j]*d_count;
                }
                B[i][j] = 0;
            }
        }
    }
    int x = Air_cord[0][0];
    int y = Air_cord[0][1];
    int temp1;
    int temp2=0;
    for(int i=1; i<C; i++){
        temp1 = A[x][i];
        A[x][i] = temp2;
        temp2 = temp1;
    }
    for(int i=x-1; i>=0; i--){
        temp1 = A[i][C-1];
        A[i][C-1] = temp2;
        temp2 = temp1;
    }
    for(int i=C-2; i>=0; i--){
        temp1 = A[0][i];
        A[0][i] = temp2;
        temp2 = temp1;
    }
    for(int i=1; i<x; i++){
        temp1 = A[i][0];
        A[i][0] = temp2;
        temp2 = temp1;
    }
    x = Air_cord[1][0];
    y = Air_cord[1][1];
    temp2 = 0;
    for(int i=1; i<C; i++){
        temp1 = A[x][i];
        A[x][i] = temp2;
        temp2 = temp1;
    }
    for(int i=x+1; i<R; i++){
        temp1 = A[i][C-1];
        A[i][C-1] = temp2;
        temp2 = temp1;
    }
    for(int i=C-2; i>=0; i--){
        temp1 = A[R-1][i];
        A[R-1][i] = temp2;
        temp2 = temp1;
    }
    for(int i=R-2; i>x; i--){
        temp1 = A[i][0];
        A[i][0] = temp2;
        temp2 = temp1;
    }
    
    if(Count == T){
        return;
    }
    else{
        solve();
    }
    
}
int main(void){
    int a_count = 0;
    scanf("%d %d %d", &R, &C, &T);
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            scanf("%d", &A[i][j]);
            if(A[i][j]== -1){
                Air_cord[a_count][0]=i;
                Air_cord[a_count][1]=j;
                a_count++;
            }
        }
    }
    solve();
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(A[i][j] > 0){
                ans += A[i][j];
            }
        }
    }
    printf("%d", ans);
    return 0;
}
