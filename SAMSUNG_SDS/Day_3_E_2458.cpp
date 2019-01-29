#include <bits/stdc++.h>
using namespace std;

int n, m, t, vst[2][501];
vector<int> gph[2][501];

int dfs(int now) {
	int ret = 1; vst[t][now] = 1;
	for (int nxt : gph[t][now]) if (!vst[t][nxt]) ret += dfs(nxt);
	return ret;
}

int main() {
	int u, v;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		gph[0][u].push_back(v), gph[1][v].push_back(u);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		memset(vst, 0, sizeof(vst));
		t = 0, u = dfs(i);
		t = 1, v = dfs(i);
		if (u + v - 1 == n) cnt++;
	}

	printf("%d", cnt);

	return 0;
}
