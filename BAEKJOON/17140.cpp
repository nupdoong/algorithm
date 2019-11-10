#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r, c, k;
int map[100][100];
int num[101];
int r_size = 3;
int Count;
int c_size = 3;
vector<pair<int, int>> v[100];
int main(void){
    scanf("%d %d %d", &r, &c, &k);
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &map[i][j]);
        }
    }
    while(1){
        if(map[r-1][c-1] == k){
            break;
        }
        if(Count > 100){
            Count = -1;
            break;
        }
        Count++;
        if(r_size >= c_size){
            for(int i=0; i<r_size; i++){
                for(int j=0; j<c_size; j++){
                    int temp = map[i][j];
                    num[temp]++;
                }
                for(int j=1; j<=100; j++){
                    if(num[j]>0){
                        v[i].push_back(make_pair(num[j]*(-1), j*(-1)));
                        num[j] = 0;
                    }
                }
                if(c_size < 2*v[i].size()){
                    c_size = 2*v[i].size();
                }
                sort(v[i].begin(), v[i].end());
                for(int j=0; j<50; j++){
                    int t = j*2;
                    if(v[i].size()>0){
                        int x = (-1)*v[i].back().second;
                        int y = (-1)*v[i].back().first;
                        v[i].pop_back();
                        map[i][t] = x;
                        map[i][t+1] = y;
                    }
                    else{
                            map[i][t] = 0;
                            map[i][t+1] = 0;
                    }
                }
                v[i].clear();
            }
        }
        else{
            for(int i=0; i<c_size; i++){
                for(int j=0; j<r_size; j++){
                    int temp = map[j][i];
                    num[temp]++;
                }
                for(int j=1; j<=100; j++){
                    if(num[j]>0){
                        v[i].push_back(make_pair(num[j]*(-1), j*(-1)));
                        num[j] = 0;
                    }
                }
                if(r_size < 2*v[i].size()){
                    r_size = 2*v[i].size();
                }
                sort(v[i].begin(), v[i].end());
                for(int j=0; j<50; j++){
                    int t = j*2;
                    if(v[i].size()>0){
                        int x = (-1)*v[i].back().second;
                        int y = (-1)*v[i].back().first;
                        v[i].pop_back();
                        map[t][i] = x;
                        map[t+1][i] = y;
                    }
                    else{
                            map[t][i] = 0;
                            map[t+1][i] = 0;
                    }
                }
                v[i].clear();
            }
        }
        
        
    }
    printf("%d", Count);
    return 0;
}
