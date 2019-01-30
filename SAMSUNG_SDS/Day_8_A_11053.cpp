#include <cstdio>
#include <stack>
#define MAX 1001
using namespace std;

typedef pair<int, int> P;
int n, pLis = 0, pArr = 1, arr[MAX], lis[MAX];
P ans[MAX];
stack<int> s;

int _lower_bound(int start, int end, int target) {
	int mid;
	while (start < end) {
		mid = (start + end) / 2;
		if (lis[mid] < target) start = mid + 1;
		else end = mid;
	}
	return end + 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	
	lis[pLis] = arr[0], ans[0].first = 0, ans[0].second = arr[0];
	while (pArr < n) {
		if (lis[pLis] < arr[pArr])
			lis[++pLis] = arr[pArr], ans[pArr].first = pLis, ans[pArr].second = arr[pArr];
		else {
			int pos = _lower_bound(0, pLis, arr[pArr]);
			lis[pos - 1] = arr[pArr], ans[pArr].first = pos - 1, ans[pArr].second = arr[pArr];
		}
		pArr++;
	}
	printf("%d\n", pLis + 1);
}
