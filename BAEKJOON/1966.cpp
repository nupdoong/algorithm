#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int test_case;
    int N, M;
    int im;
    scanf("%d", &test_case);
    for(int i=1; i<=test_case; i++){
        int COUNT = 0;
        queue<pair<int, int>> q;
        vector<int> v;
        scanf("%d %d", &N, &M);
        for(int i=0; i<N; i++){
            scanf("%d", &im);
            v.push_back(im);
            q.push(make_pair(i, im));
        }
        sort(v.begin(), v.end());
        while(1){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(y == v[N-1]){
                N--;
                COUNT++;
                if(x == M){
                    break;
                }
            }
            else{
                q.push(make_pair(x, y));
            }
        }
        printf("%d\n", COUNT);
    }
    
    return 0;
}
