#include <iostream>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

int N, M, K, S;
int fin;
int sum;
int check[1001];

vector<int> d_town;
vector<int> town[1001];

int main() {
    int test_case;
    int temp_x;
    int temp_y;
    int Count;
    int temp_town;
    scanf("%d", &test_case);
    for(int T=1; T<=test_case; T++){
        for(int i=0; i<=1000; i++)
            town[i].clear();
        d_town.clear();
        sum = 0;
        scanf("%d %d %d %d", &N, &M, &K, &S);
        d_town.push_back(S);
        for(int i=0; i<K; i++){
            scanf("%d", &temp_town);
            d_town.push_back(temp_town);
        }
        d_town.push_back(S);
        for(int i=0; i<M; i++){
            scanf("%d %d", &temp_x, &temp_y);
            town[temp_x].push_back(temp_y);
            town[temp_y].push_back(temp_x);
        }
        for(int i=0; i<d_town.size()-1; i++){
            Count = 0;
            fin = 0;
            memset(check,0,sizeof(check));
            queue<int> q;
            q.push(d_town[i]);
            int as = d_town[i];
            check[as] = 1;
            while(!q.empty()){
                int a = q.size();
                Count++;
                for(int k=0; k<a; k++){
                    int x = q.front();
                    q.pop();
                    for(int j=0; j<town[x].size(); j++){
                            if(town[x][j] == d_town[i+1]){
                                fin = 1;
                                sum+=Count;
                                break;
                            }
                            int ad = town[x][j];
                            if(check[ad] == 1){
                                continue;
                            }
                            q.push(town[x][j]);
                            check[ad] = 1;
                    }
                    if(fin == 1)
                        break;
                }
                if(fin == 1)
                    break;
            }
            
        }
        printf("#%d %d\n", T, sum);
        
        
        
    }
    return 0;
}
