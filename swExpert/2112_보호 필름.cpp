#include <iostream>
using namespace std;
int map[13][20];
int back[13][20];
int D, W, K;
int ans;
int Max = 2e9;

int testing(){
    int A=0;
    int B=0;
    int Count=0;
    for(int i=0; i<W; i++){
        if(Count != i){
            return 0;
        }
        for(int j=0; j<D; j++){
            if(map[j][i] == 0){
                B=0;
                A++;
            }
            else{
                A=0;
                B++;
            }
            if(A==K || B==K){
                Count++;
                A=0;
                B=0;
                break;
            }
        }
        if(Count == W){
            return 1;
        }
    }
}
void backup(int num){
    for(int i=0; i<W; i++){
         map[num][i] = back[num][i];
    }
}
void repair(int num, int m_type){
    for(int i=0; i<W; i++){
        if(m_type == 0){
            map[num][i] = 0;
        }
        else{
            map[num][i] = 1;
        }
    }
}
void dfs(int num, int sum){
    if(num >= D || sum >= K){
        return;
    }
    
    repair(num, 0);
    if(testing()==1){
        if(Max >= sum){
            Max = sum;
        }
        backup(num);
        return;
    }
    dfs(num+1, sum+1);
    repair(num, 1);
    if(testing()==1){
        if(Max >= sum){
            Max = sum;
        }
        backup(num);
        return;
    }
    dfs(num+1, sum+1);
    backup(num);
    dfs(num+1, sum);
}
int main(void){
    int tc;
    scanf("%d", &tc);
    for(int T=1; T<=tc; T++){
        scanf("%d %d %d", &D, &W, &K);
        Max = K;
        
        for(int i=0; i<D; i++){
            for(int j=0; j<W; j++){
                scanf("%d", &map[i][j]);
                back[i][j] = map[i][j];
            }
        }
        if(testing()==1){
        	ans = 0;
        }
        else{
            dfs(0, 1);
            ans = Max;
        } 
        printf("#%d %d\n", T, ans);
    }
    
    return 0;
}
