#include <iostream>
#include <algorithm>
using namespace std;
int n, m, Max, a;
int D[1000][1000];
int map[1000][1000];
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j])
				D[i][j] = 1;
			if (map[i - 1][j] && map[i - 1][j - 1] && map[i][j - 1])
				D[i][j] = min(min(D[i - 1][j], D[i - 1][j - 1]), D[i][j - 1]) + 1;
			Max = max(Max, D[i][j]);
		}
	printf("%d", Max*Max);
	return 0;
}
