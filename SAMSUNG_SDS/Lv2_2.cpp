#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N, M, K, S, Min = 1000000;
int dil[1001], check[1001];
vector<int> graph[1001];

void reset(void) {
   for (int i = 0; i <= 1000; i++) {
      dil[i] = 0, check[i] = 0, graph[i].clear();
   }
   Min = 1000000;
}

void dfs(int start,int correct, int len) {
   if (Min < len)
      return;
//   cout << start << " len is " << len << "correct "<<correct<< endl;
   for (int i = 0; i < graph[start].size(); i++) {
      if (graph[start][i] == S) {
         if (correct == K) {
            if(Min > len)
               Min = len + 1;
//            cout << "end start" << start << "len : "<<len<< " "<<out<< endl;
            return;
         }
         
      }
      if (check[graph[start][i]] == 1)
         continue;
      if (check[graph[start][i]] == 0) {
         if(graph[start][i] != S)
            check[graph[start][i]] = 1;
         if (dil[graph[start][i]] == 1)
            dfs(graph[start][i], correct + 1, len + 1);
         else
            dfs(graph[start][i], correct, len + 1);
         check[graph[start][i]] = 0;
      }
   }


}

int main() {
   int test_c;
   cin >> test_c;
   for(int t=1;t<=test_c;t++){
      cin>>N>>M>>K>>S;
      for (int i = 0; i < K; i++){
         int a;
         scanf("%d", &a);
         dil[a] = 1;
      }

      for (int i = 0; i<M; i++) {
         int u, v;
         cin >> u >> v;

         graph[u].push_back(v);
         graph[v].push_back(u);
      }

      dfs(S, 0, 0);
      printf("#%d %d\n",t , Min);
      reset();
   }
   return 0;
}
