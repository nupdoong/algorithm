#include <iostream>
#include <algorithm>
using namespace std;
int N;
int stair[301];
int D[301];
int main(void) {
	scanf("%d", &N);
	for (int i = 0; i<N; i++) {
		scanf("%d", &stair[i]);
	}
    D[0] = stair[0];
	D[1] = max(stair[0] + stair[1], stair[1]);
	D[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
	for (int i = 3; i<N; i++) {
		D[i] = max(D[i - 2] + stair[i], stair[i - 1] + stair[i] + D[i - 3]);
	}
	printf("%d", D[N - 1]);
	return 0;
}
