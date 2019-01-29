#include <iostream>
#include <algorithm>
using namespace std;
int N;
int m[501][2];
int D[501][501];
int main(void) {
	scanf("%d", &N);
	for (int i = 0; i<N; i++)
		scanf("%d %d", &m[i][0], &m[i][1]);
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= N - i; j++) {
			D[j][i + j] = 2e9;
			for (int k = j + 1; k<i + j; k++)
				D[j][i + j] = min(D[j][i + j], D[j][k] + D[k][i + j] + m[j][0] * m[k][0] * m[j + i - 1][1]);
		}
	}
	printf("%d", D[0][N]);
	return 0;
}
