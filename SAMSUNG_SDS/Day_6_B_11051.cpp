#include <iostream>

using namespace std;

 
int main() {
    int n, k, dp[1001][1001];
    scanf("%d %d", &n, &k);
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == j) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%10007;
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}
