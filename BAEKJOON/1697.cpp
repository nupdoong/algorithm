#include <iostream>
#include <queue>
using namespace std;
int visit[100001];
int N, K;

int bfs(int n){
    int time = 0;
    queue<int> q;
    q.push(n);
    
    while(1){
        int size = q.size();
        
        for(int i=0; i<size; i++){
            n = q.front();
            q.pop();
            if(n==K)
                return time;
            if(n > 0 && visit[n-1] == 0){
                q.push(n-1);
                visit[n-1] = 1;
            }
            if(n < 100000 && visit[n+1]==0){
                q.push(n+1);
                visit[n+1] = 1;
            }
            if(n*2 <= 100000 && visit[2*n] == 0){
                q.push(n*2);
                visit[n*2] = 1;
            }
        }
        time++;
    }
}

int main(void){
    cin >> N >> K;
    cout << bfs(N);
    
    return 0;
}
