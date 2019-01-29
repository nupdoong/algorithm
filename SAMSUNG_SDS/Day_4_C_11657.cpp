#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX_NODE 501
 
using namespace std;
 
typedef struct EDGE {
    int dest;
    int val;
};
 
// 0번 인덱스는 버린다. 
vector<EDGE> edge_vec[MAX_NODE];
int value_arr[MAX_NODE] = { 0 };
int N, M;
 
int bellman_ford(int excute_num) {
    int isChanged = 0;
    // 벨만 포드 알고리즘을 수행한다. 
    // 모든 VERTEX 에서 연결된 EDGE 를 확인해야 한다.
    // i가 시작점  edge_vec[i][k].dest 가 도착점
    // 각 노드마다 한 번씩 수행한다.
    for (int t = 1; t <= N; t++) {
        // 각 노드마다 모든 엣지에 대하여 
        for (int i = 1; i <= N; i++) {
            for (int k = 0; k < edge_vec[i].size(); k++) {
                // 현재 목적지에 가는 노드의 가중치와, 출발 노드에서 목적지 까지 가는 노드의 가중치를 각각 구한다. 
                int new_val = (value_arr[i] + edge_vec[i][k].val);
                int before_val = (value_arr[edge_vec[i][k].dest]);
                // 노드 값이 지금 값 보다 크면 갱신한다.
                if ((value_arr[i] != INF) && (new_val < before_val)) {
                    isChanged = 1;
                    // 만약 2번째 수행 후라면 바로 함수를 종료한다. 
                    if (isChanged * excute_num) return isChanged;
                    value_arr[edge_vec[i][k].dest] = new_val;
                }
            }
        }
    }
 
    return isChanged;
}
 
int main() {
    cin >> N >> M;
 
    // EDGE 입력받기 
    int from, to, val;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &from, &to, &val );
        edge_vec[from].push_back(EDGE{to, val}); 
    }
 
    // 초기 도달 가능한 시간을 INF 으로 초기화 
    for (int i = 2; i <= N; i++) value_arr[i] = INF;
    
    // 벨만 포드 알고리즘 수행
    bellman_ford(0);
    
    // 두 번째 수행해서 만약 변경되는 값이 있으면, 함수에서 1이 리턴된다. 
    if (bellman_ford(1) == 1) {
        cout << -1;
    }
    // 함수 리턴 값이 0이면 변한 값이 없기 때문에, 바로 값을 출력한다. 
    else {
        for (int i = 2; i <= N; i++)
            printf("%d\n", (value_arr[i]!=INF ? value_arr[i] : -1) );
    }
 
    return 0;
}
