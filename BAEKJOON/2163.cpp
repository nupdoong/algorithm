#include <stdio.h>

int N, M, dp[301];

int main() {
	scanf("%d %d", &N, &M);
	dp[1] = N-1;
	for (int i = 2; i <= M; ++i) {
		dp[i] = dp[i - 1] + N;
	}

	printf("%d", dp[M]);

}
