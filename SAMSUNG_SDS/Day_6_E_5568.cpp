#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int card[10];
int visit[10];
int n, k;
int Count;
vector<int> v;

void back(int K, int sum) {
	if (K == k) {
		v.push_back(sum);
		return;
	}
	for (int i = 0; i<n; i++) {
		if (visit[i] == 0) {
			int a=0;
			visit[i] = 1;
			if (K == 0) {
				a = card[i];
			}
			else {
				if (card[i] > 9)
					a = sum * 100;
				else
					a = sum * 10;
				a += card[i];
			}
			back(K + 1, a);
			visit[i] = 0;
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &k);
	for (int i = 0; i<n; i++) {
		scanf("%d", &card[i]);
	}
	back(0, 0);
	sort(v.begin(), v.end());
	for (int i = 0; i<v.size(); i++) {
		if (i == 0) {
			Count++;
		}
		else {
			if (v[i - 1] == v[i]) {
				continue;
			}
			else {
				Count++;
			}
		}
	}
	printf("%d", Count);
	return 0;
}
