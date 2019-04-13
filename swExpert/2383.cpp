#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
int N;
int map[10][10];
int p[10][2];
int p_num;
int Min;
int ans = 2e9;
int s_l[2];
int s[2][2];
int s_num;
vector<pair<int, pair<int, int>>> v1;
vector<pair<int, pair<int, int>>> v2;
queue<pair<int, pair<int, int>>> q1;
queue<pair<int, pair<int, int>>> q2;
void solve(){
    int t=0;
    int Count = 0;
    vector<pair<int, int>> v3[10];
	vector<pair<int, int>> v4[10];
    while(1){
        while(!q1.empty()){
            int st = q1.front().first;
            if(st+s_l[0]<=t){
                q1.pop();
            }
            else{
                break;
            }
        }
        for(int i=0; i<v1.size();i++){
            int x = v1[i].second.first;
            int y = v1[i].second.second;
            if(v1[i].first==t-1){
                if(q1.size()<3){
                    Count++;
                    q1.push(make_pair(t, make_pair(x, y)));
                }
                else{
                    v3[i].push_back(make_pair(i, v1[i].first));
                    v1[i].first++;
                }
            }
        }
        while(!q2.empty()){
            int st = q2.front().first;
            if(st+s_l[1]<=t){
                q2.pop();
            }
            else{
                break;
            }
        }
        for(int i=0; i<v2.size();i++){
            int x = v2[i].second.first;
            int y = v2[i].second.second;
            if(v2[i].first==t-1){
                if(q2.size()<3){
                    Count++;
                    q2.push(make_pair(t, make_pair(x, y)));
                }
                else{
                    v4[i].push_back(make_pair(i, v2[i].first));
                    v2[i].first++;
                }
            }
        }
        
        if(Count==p_num && q1.empty()==1 && q2.empty()==1){
            Min = t;
            break;
        }
        t++;
    }
    for(int i=0; i<p_num; i++){
        if(v3[i].size()>0){
        	int xx = v3[i][0].first;
        	int yy = v3[i][0].second;
        	v1[xx].first = yy;
        }
    }
    for(int i=0; i<p_num; i++){
        if(v4[i].size()>0){
        	int xx = v4[i][0].first;
        	int yy = v4[i][0].second;
        	v2[xx].first = yy;
        }
    }
}
void dfs(int num){
    if(num==p_num){
        solve();
        if(ans > Min){
            ans = Min;
        }
        return;
    }
    int x = p[num][0];
    int y = p[num][1];
    int t = abs(x-s[0][0]) + abs(y-s[0][1]);
    v1.push_back(make_pair(t, make_pair(x, y)));
    dfs(num+1);
    v1.pop_back();
    t = abs(x-s[1][0]) + abs(y-s[1][1]);
    v2.push_back(make_pair(t, make_pair(x, y)));
    dfs(num+1);
    v2.pop_back();
}
int main(void){
    int tc;
    scanf("%d", &tc);
    for(int T=1; T<=tc; T++){
        ans = 2e9;
        p_num=0;
        s_num=0;
        scanf("%d", &N);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                scanf("%d", &map[i][j]);
                if(map[i][j]==1){
                    p[p_num][0] = i;
                    p[p_num][1] = j;
                    p_num++;
                }
                if(map[i][j]>1){
                    s[s_num][0] = i;
                    s[s_num][1] = j;
                    s_l[s_num] = map[i][j];
                    s_num++;
                }
            }
        }
        dfs(0);
        printf("#%d %d\n", T, ans);
    }
    return 0;
}
