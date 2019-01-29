#include <iostream>

using namespace std;

int N;
int M;
int A[10000];
int Count;

int main(void) {
	scanf("%d %d", &N, &M);

	for (int i = 0; i<N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i<N; i++) {
		int p = i;
		int sum = 0;
		while (1) {
			sum += A[p];
			p++;
			if (sum == M) {
				Count++;
				break;
			}
			if (p >= N) {
				break;
			}
		}
	}

	printf("%d", Count);
	return 0;
}
