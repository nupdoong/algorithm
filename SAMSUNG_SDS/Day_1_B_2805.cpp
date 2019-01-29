#include <iostream>

using namespace std;

int N, M;
int T[1000000];
int Max;
long long sum;
int main(void) {
	scanf("%d %d", &N, &M);

	for (int i = 0; i<N; i++) {
		scanf("%d", &T[i]);
		if (T[i] > Max)
			Max = T[i];

	}
	int low = 0;
	int high = Max;
	int p;
	while (1) {
		sum = 0;
		p = low + (high-low) / 2;
		for (int i = 0; i < N; i++) {
			if(T[i]> p)
				sum += T[i] - p;
		}
		if (sum > M) {
			low = p;
			if (high-low==1) {
				break;
			}
		}
		else if (sum < M) {
			high = p;

		}
		else
			break;
	}

	printf("%d", p);

	return 0;
}
