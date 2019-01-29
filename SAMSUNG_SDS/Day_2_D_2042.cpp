#include <cstdio>
#define MAX 1000002

long long N, M, K;
long long start;
long long tree[MAX * 2+100000];

void make_tree() {
	long long temp = start + N - 1;
	temp /= 2;
	while (temp > 0) {
		tree[temp] = tree[temp * 2] + tree[temp * 2 + 1];
		temp--;
	}
    return;
}
void update(long long b, long long c) {
	long long temp = start + b - 1;
	tree[temp] = c;
	temp /= 2;
	while (temp > 0) {
		tree[temp] = tree[temp * 2] + tree[temp * 2 + 1];
		temp /= 2;
	}
    return;
}
long long sum(long long l, long long r) {
	l += start - 1;
	r += start - 1;
	long long s = 0;
	while (l <= r) {
		if (l % 2 == 1) {
			s += tree[l];
			l++;
		}
		if (r % 2 == 0) {
			s += tree[r];
			r--;
		}
		l /= 2;
        r /= 2;
	}
	return s;
}

int main() {
	scanf("%lld %lld %lld", &N, &M, &K);
	M += K;
	for (start = 1; start<N; start *= 2);
	for (int i = 0; i<N; i++)
		scanf("%lld", &tree[start + i]);
	make_tree();
	long long a, b, c;
	for (int i = 0; i<M; i++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1)
			update(b, c);
		else
			printf("%lld\n", sum(b, c));
	}
	return 0;
}
