#include <iostream>

using namespace std;

int N;

int main(void) {
	scanf("%d", &N);
	long long a = 1;
	long long b = 1;
	long long c = 1;
	for (int i = 3; i<=N; i++) {
		c = a + b;
		a = b;
		b = c;
	}

	printf("%lld", c);

	return 0;
}
