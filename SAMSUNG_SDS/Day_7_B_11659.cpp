#include <iostream>
using namespace std;
int N, M, ans;
int num[100001];
int sum[100001];
int main(void){
    int a, b;
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++){
        scanf("%d", &num[i]);
        sum[i] = sum[i-1] + num[i];
    }
    for(int i=0; i<M; i++){
        scanf("%d %d", &a, &b);
        ans = sum[b] - sum[a-1];
        printf("%d\n", ans);
    }
    return 0;
}
