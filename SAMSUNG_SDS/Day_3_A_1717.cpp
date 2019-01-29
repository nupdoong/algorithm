#include <stdio.h>
using namespace std;

int n, m, i, a, b, c;
int parent[1000001];

int find(int x) {
	if (x == parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	parent[x] = y;
}

int main() {
	scanf("%d %d", &n, &m);
	for (i = 0; i <= n; ++i)
		parent[i] = i;

	while (m--) {
		scanf("%d %d %d", &c, &a, &b);

		if (!c)
			unite(a, b);
		else
			if (find(a) == find(b))
				puts("YES");
			else
				puts("NO");
	}
	return 0;
}
