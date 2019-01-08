#include <iostream>
#include <algorithm>
using namespace std;
int key[9];
int ans[7];
int check=0;
void dfs(int x, int sum, int a){
    if(check){
        return;
    }
    if(a == 7 && sum == 100){
        check = 1;
        for(int i=0; i<7; i++){
            printf("%d\n", ans[i]);
        }
        return;
    }
    if(a >= 7){
        return;
    }
    if(x >= 9){
        return;
    }
    ans[a] = key[x];
    dfs(x+1, sum+ans[a], a+1);
    dfs(x+1, sum, a);
}
int main(void){
    for(int i=0; i<9; i++){
        scanf("%d", &key[i]);
    }
    sort(key, key+9);

    dfs(0, 0, 0);
    
    return 0;
}
