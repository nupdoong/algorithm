#include <iostream>
#include <math.h>
using namespace std;

int N;
int arr[8];
int mask[8];
int ans = 0;

void dfs(int x, int count, int sum){
    int sum2;
    if(count == N-1){
        if(ans < sum){
            ans = sum;
        }
        return;
    }
    for(int i=0; i<N; i++){
        if(mask[i] == 0){
            sum2 = abs(arr[x] - arr[i]);
            mask[i] = 1;
            dfs(i, count+1, sum + sum2);
            mask[i] = 0;
        }
    }
}

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
        mask[i] = 0;
    }

    for(int i=0; i<N; i++){
        mask[i] = 1;
        dfs(i, 0, 0);
        mask[i] = 0;
    }
    printf("%d", ans);
    
    
    return 0;
}
