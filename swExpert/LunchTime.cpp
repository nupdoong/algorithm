#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int map[10][10];
int p[10][2];
int s[2][2];
int sx1, sy1;
int sx2, sy2;
int p_count;
int s_count;
int Min = 1e9;
vector<int> v1;
vector<int> v2;

int solve(){
	int Count = 0;
	int v1_count = 0;
	int v2_count = 0;
    queue<int> q1;
	queue<int> q2;
    vector<int> v3 = v1;
    vector<int> v4 = v2;
	sort(v3.begin(), v3.end());
	sort(v4.begin(), v4.end());
	while(1){
		while(!q1.empty()){
			int t = q1.front();
			if(t + map[sx1][sy1] <= Count){
				q1.pop();
				continue;
			}
			else{
				break;
			}
		}
        while(1){
            if(v1_count < v3.size()){
				if(Count >= v3[v1_count]){
					if(q1.size() < 3){
                    	if(Count == v3[v1_count]){
							q1.push(Count+1);
							v1_count++;
                    	}
                    	else{
                        	q1.push(Count);
                        	v1_count++;
                    	}
					}
                    else
                        break;
				}
                else
                    break;
            }
            else
                break;
		}
		while(!q2.empty()){
			int t2 = q2.front();
			if(t2 + map[sx2][sy2] <= Count){
				q2.pop();
				continue;
			}
			else{
				break;
			}
		}
        while(1){
            if(v2_count < v4.size()){
				if(Count >= v4[v2_count]){
					if(q2.size() < 3){
                    	if(Count == v4[v2_count]){
							q2.push(Count+1);
							v2_count++;
                    	}
                    	else{
                        	q2.push(Count);
                        	v2_count++;
                    	}
					}
                    else
                        break;
				}
                else
                    break;
            }
            else
                break;
		}
		if(v1_count == v3.size() && v2_count == v4.size() && q1.empty() == 1 && q2.empty() == 1){
			break;
		}
		Count++;
	}
	return Count;
}

void dfs(int p_num){
	if(p_num == p_count){
		int tt = solve();
		if(Min > tt){
			Min = tt;
		}
		return;
	}
	int sum = 0;
	int x = p[p_num][0];
	int y = p[p_num][1];
	
	if(sx1- x < 0){
		sum += x - sx1;
	}
	else{
		sum += sx1 -x;
	}
	if(sy1 - y < 0){
		sum += y - sy1;
	}
	else{
		sum += sy1 - y;
	}
	v1.push_back(sum);
	dfs(p_num+1);
	v1.pop_back();
	sum = 0;
	if(sx2- x < 0){
		sum += x - sx2;
	}
	else{
		sum += sx2 -x;
	}
	if(sy2 - y < 0){
		sum += y - sy2;
	}
	else{
		sum += sy2 - y;
	}
	v2.push_back(sum);
	dfs(p_num+1);
	v2.pop_back();
}

int main(void){
	int T, test_case;
	scanf("%d", &test_case);
	for(T=1; T<=test_case; T++){
        Min = 1e9;
        v1.clear();
        v2.clear();
		p_count = 0;
		s_count = 0;
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				scanf("%d", &map[i][j]);
				if(map[i][j] == 1){
					p[p_count][0] = i;
					p[p_count][1] = j;
					p_count++;
				}
				if(map[i][j] > 1){
					s[s_count][0] = i;
					s[s_count][1] = j;
					s_count++;
				}
			}
		}
		sx1 = s[0][0];
		sy1 = s[0][1];
		sx2 = s[1][0];
		sy2 = s[1][1];
		dfs(0);
        printf("#%d %d\n", T, Min);
	}
	return 0;
}
