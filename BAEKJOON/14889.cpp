#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int N;
int Min;
int ans = 2e9;
int team[21];
int map[21][21];
vector<int> v1, v2;
void solve(){
    int A=0;
    int B=0;
    for(int i=1; i<=N; i++){
        if(team[i]==0){
            v1.push_back(i);
        }
        else{
            v2.push_back(i);
        }
    }
    for(int i=0; i<v1.size()-1; i++){
        int x = v1[i];
        for(int j=i+1; j<v1.size(); j++){
            int y = v1[j];
            A+=map[x][y];
            A+=map[y][x];
        }
    }
    for(int i=0; i<v2.size()-1; i++){
        int x = v2[i];
        for(int j=i+1; j<v2.size(); j++){
            int y = v2[j];
            B+=map[x][y];
            B+=map[y][x];
        }
    }
    v1.clear();
    v2.clear();
    Min = abs(A-B);
}
void dfs(int num, int sum){
    if(sum==N/2){
        solve();
        if(ans > Min){
            ans = Min;
        }
        return;
    }
    if(num>N){
        return;
    }
    team[num] = 1;
    dfs(num+1, sum+1);
    team[num] = 0;
    dfs(num+1, sum);
}
int main(void){
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d", &map[i][j]);
        }
    }
    dfs(1, 0);
    printf("%d", ans);
    return 0;
}
