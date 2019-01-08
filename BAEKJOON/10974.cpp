#include <iostream>
#include <algorithm>
using namespace std;
int N;
int map[9];
int mask[9] = {0};
void dfs(int x, int count){
    if(count==N){
        for(int i=1; i<=N; i++){
            printf("%d ", map[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1; i<=N; i++){
        if(mask[i] == 0){
            mask[i] = 1;
            map[count+1] = i;
            dfs(i, count+1);
            mask[i] = 0;
        }
    }
}
int main(void){
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        mask[i] = 1;
        map[1] = i;
        dfs(i, 1);
        mask[i] = 0;
    }
    return 0;
}
