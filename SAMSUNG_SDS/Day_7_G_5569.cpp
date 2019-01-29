#include <iostream>
using namespace std;
int w, h, dp[100][100][4], ans;
int main() {
	scanf("%d %d", &w, &h);
	for (int i = 1; i < w; i++)
		dp[i][0][1] = 1;
	for (int i = 1; i < h; i++)
		dp[0][i][3] = 1;
	for (int i = 1; i < w; i++) {
		for (int j = 1; j < h; j++) {
			dp[i][j][0] = dp[i - 1][j][3],
				dp[i][j][1] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % 100000,
				dp[i][j][2] = dp[i][j - 1][1],
				dp[i][j][3] = (dp[i][j - 1][2] + dp[i][j - 1][3]) % 100000;
		}
	}
	ans = (dp[w - 1][h - 1][0] + dp[w - 1][h - 1][1] + dp[w - 1][h - 1][2] + dp[w-1][h-1][3]) % 100000;
	printf("%d", ans);
	return 0;
}
