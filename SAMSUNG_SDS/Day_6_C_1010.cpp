#include <iostream>

using namespace std;


int main() {
	int n, k, dp[31][31];
	int T;
	dp[0][0] = 1;

	for (int i = 1; i <= 30; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= i; j++) {
			if (i == j) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}
	}
	scanf("%d", &T);
	for (int i = 0; i<T; i++) {
		scanf("%d %d", &k, &n);
		printf("%d\n", dp[n][k]);
	}
	return 0;
}
