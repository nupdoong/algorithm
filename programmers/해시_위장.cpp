#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<int> price) {
    
    map<int, vector<int>> m;
    int N = price.size();
    vector<int> answer(N, -1);
    for(int i=0; i<price.size(); i++){
        int temp = price[i];
        m[temp].push_back(i);
    }
    vector<int> temp_v;
    for(auto it=m.begin(); it != m.end(); it++){
        for(int i=0; i<temp_v.size(); i++){
            int temp_x = temp_v[i];
            for(int j=0; j<m[it].size(); j++){
                if(m[it][j] > temp_x){
                    answer[temp_x] = m[it][j] - temp_x;
                    break;
                }
            }
        }
        temp_v.assign(m[it].begin(), m[it].end());
        
    }
    return answer;
}
