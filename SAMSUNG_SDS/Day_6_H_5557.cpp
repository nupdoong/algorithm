#include <iostream>
using namespace std;
 
int n, num[101], result=0;
long long dp[101][1001];
 
long long cal(int idx, int sum) {
    if (sum < 0 || sum>20) { return 0; }
    if (idx == n - 1) {
        if (sum == num[n - 1])
            dp[idx][sum] = 1;
        else
            dp[idx][sum] = 0;
        return dp[idx][sum];
    }
    if (dp[idx][sum] != -1) {
        return dp[idx][sum];
    }
    long long ret = 0;
    ret += cal(idx + 1, sum + num[idx]);
    ret += cal(idx + 1, sum - num[idx]);
    return dp[idx][sum] = ret;
}
 
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> num[i]; }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 1001; j++)
            dp[i][j] = -1;
    cout << cal(1, num[0]) << '\n';
    return 0;
}
