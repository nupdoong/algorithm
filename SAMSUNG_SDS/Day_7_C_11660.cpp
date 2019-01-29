#include <iostream>
using namespace std;
int N, M, ans;
int num[1025][1025];
int sum[1025][1025];
int main(void) {
	int a, b, c, d;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &num[i][j]);
			sum[i][j] = sum[i][j - 1] + num[i][j];
		}
	}
	for (int i = 0; i<M; i++) {
		ans = 0;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for(int j=a; j<=c; j++)
			ans += sum[j][d] - sum[j][b - 1];
		printf("%d\n", ans);
	}
	return 0;
}
