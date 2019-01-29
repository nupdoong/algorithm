#include <iostream>
#include <algorithm>

using namespace std;
int D[501][501];
int n;
int Max;
int main(void){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            scanf("%d", &D[i][j]);
        }
    }
    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(j==1) D[i][j] += D[i-1][j];
            else if(j==n) D[i][j] += D[i-1][j-1];
            else D[i][j] += max(D[i-1][j-1], D[i-1][j]);
        }
    }
    for(int i=1; i<=n; i++){
        if(D[n][i] > Max) Max = D[n][i];
    }
    printf("%d", Max);
    return 0;
}
