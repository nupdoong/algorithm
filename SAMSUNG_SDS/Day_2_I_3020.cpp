#include <cstdio>

#include <vector>

#include <algorithm>

using namespace std;

int N, M;

vector<int> up, down;

int main() {

    scanf("%d%d", &N, &M);

    for (int n = 1;n <= N;n++) {

        int u;

        scanf("%d", &u);

        if (n & 1) down.push_back(u);

        else up.push_back(u);

    }

    sort(up.begin(), up.end());

    sort(down.begin(), down.end());

    int ans = 987654321, half_N = N / 2;

    int cnt = 0;

    for (int m = 1;m <= M;m++) {

        int down_iter = lower_bound(down.begin(), down.end(), m) - down.begin();

        int up_iter = upper_bound(up.begin(), up.end(), M - m) - up.begin();

        int ret = half_N - down_iter + half_N - up_iter;

        if (ans > ret) ans = ret, cnt = 1;

        else if (ans == ret) cnt++;

    }

    printf("%d %d\n", ans, cnt);

    return 0;

}
