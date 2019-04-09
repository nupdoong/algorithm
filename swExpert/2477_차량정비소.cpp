#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, K, A, B;
int rec[21];
int rec_s[21][2];
int rep[21];
int rep_s[21][2];
int t[1001];
int ans;
vector<int> v1[21];
vector<int> v2[21];
queue<int> rec_q;
queue<int> rep_q;
vector<pair<int, int>> v;

void solve(){
    int count=0;
    int check=0;
    while(1){
        if(check==K){
            break;
        }
        for(int i=1; i<=K; i++){
            if(t[i]==count){
                rec_q.push(i);
            }
        }
        for(int i=1; i<=N; i++){
            if(rec_s[i][0]>0){
                rec_s[i][0]--;
                if(rec_s[i][0]==0){
                    v.push_back(make_pair(i ,rec_s[i][1]));
                }
            }
            if(rec_q.empty()==0){
                if(rec_s[i][0]==0){
                     int x = rec_q.front();
                     v1[i].push_back(x);
                     rec_s[i][0] = rec[i];
                     rec_s[i][1] = x;
                     rec_q.pop();
                }
            }
        }
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++){
                rep_q.push(v[i].second);
        }
        v.clear();
        
        
        for(int i=1; i<=M; i++){
            if(rep_s[i][0]>0){
                rep_s[i][0]--;
                if(rep_s[i][0]==0){
                    check++;
                }
            }
            if(rep_q.empty()==0){
                if(rep_s[i][0]==0){
                     int x2 = rep_q.front();
                     v2[i].push_back(x2);
                     rep_s[i][0] = rep[i];
                     rep_s[i][1] = x2;
                     rep_q.pop();
                }
            }
        }
        count++;
    }
}

int main(void){
    int tc;
    scanf("%d", &tc);
    for(int T=1; T<=tc; T++){
        ans = 0;
        scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
        for(int i=1; i<=N; i++){
            scanf("%d", &rec[i]);
        }
        for(int i=1; i<=M; i++){
            scanf("%d", &rep[i]);
        }
        for(int i=1; i<=K; i++){
            scanf("%d", &t[i]);
        }
        
        solve();
        
        for(int i=0; i<v1[A].size(); i++){
            for(int j=0; j<v2[B].size(); j++){
                if(v2[B][j]==v1[A][i])
                    ans+=v1[A][i];
            }
        }
        if(ans==0){
            ans = -1;
        }
        printf("#%d %d\n", T, ans);
        for(int i=1; i<=N; i++){
            v1[i].clear();
        }
        for(int i=1; i<=M; i++){
            v2[i].clear();
        }
    }
    return 0;
}
