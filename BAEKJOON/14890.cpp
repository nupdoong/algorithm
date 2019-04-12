#include <iostream>
#include <math.h>
using namespace std;
int N, L;
int ans;
int map[100][100];
int mask[100][100];
int check(int x, int y, int temp, int Check){
    if(y-L>=0 && Check==0){
        for(int i=1; i<=L; i++){
            if(mask[x][y-i]==1 || map[x][y-i] != temp){
                return 0;
            }
        }
        for(int i=1; i<=L; i++){
            mask[x][y-i] = 1;
        }
        return 1;
    }
    if(y+L-1<N && Check==1){
        temp = map[x][y];
        for(int i=0; i<L; i++){
            if(mask[x][y+i]==1 || map[x][y+i] != temp){
                return 0;
            }
        }
        for(int i=0; i<L; i++){
            mask[x][y+i] = 1;
        }
        return 1;
    }
    
    return 0;
}
int check2(int x, int y, int temp, int Check){
    if(x-L>=0 && Check ==0){
        for(int i=1; i<=L; i++){
            if(mask[x-i][y]==1 || map[x-i][y] != temp){
                return 0;
            }
        }
        for(int i=1; i<=L; i++){
            mask[x-i][y] = 1;
        }
        return 1;
    }
    if(x+L-1<N && Check==1){
        temp = map[x][y];
        for(int i=0; i<L; i++){
            if(mask[x+i][y]==1 || map[x+i][y] != temp){
                return 0;
            }
        }
        for(int i=0; i<L; i++){
            mask[x+i][y] = 1;
        }
        return 1;
    }
    return 0;
}
int main(void){
    scanf("%d %d", &N, &L);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &map[i][j]);
        }
    }
    for(int i=0; i<N; i++){
        int temp = map[i][0];
        int Check=0;
        for(int j=0; j<N; j++){
            Check=0;
            if(abs(temp-map[i][j])==1){
                if(temp>map[i][j]){
                    Check=1;
                }
                if(check(i, j, temp, Check)){
                    temp = map[i][j];
                }
                else{
                    break;
                }
            }
            else if(temp == map[i][j])
                temp = map[i][j];
            else{
                break;
            }
            if(j==N-1){
                ans++;
            }
        }
        for(int j=0; j<N; j++){
            mask[i][j] = 0;
        }
    }
    for(int i=0; i<N; i++){
        int temp = map[0][i];
        int Check = 0;
        for(int j=0; j<N; j++){
            Check =0;
            if(abs(temp-map[j][i])==1){
                if(temp > map[j][i]){
                    Check=1;
                }
                if(check2(j, i, temp, Check)){
                    temp = map[j][i];
                }
                else{
                    break;
                }
            }
            else if(temp == map[j][i])
                temp = map[j][i];
            else{
                break;
            }
            if(j==N-1){
                ans++;
            }
        }
        for(int j=0; j<N; j++){
            mask[j][i] = 0;
        }
    }
    printf("%d", ans);
    return 0;
}
