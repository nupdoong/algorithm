#include <iostream>

using namespace std;
double ans[50];
double sum;
int N, K;
int stone[50];
double s_num = 0;
int main(void) {

	scanf("%d", &N);
	for (int i = 0; i<N; i++) {
		scanf("%d", &stone[i]);
		s_num += stone[i];
	}
	scanf("%d", &K);

	for (int i = 0; i<N; i++) {
		if (stone[i] >= K) {
			ans[i] = 1;
			for (int j = 0; j < K; j++) {
				ans[i] *= (stone[i] - j) / (s_num - j);
			}
		}
	}
	for (int i = 0; i<N; i++) {
		if (ans[i]>0) {
			sum += ans[i];
		}
	}
	printf("%.9f", sum);

	return 0;
}
