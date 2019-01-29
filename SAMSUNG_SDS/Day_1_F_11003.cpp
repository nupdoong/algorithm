#include <stdio.h>
#include <deque>
using namespace std;
int N, L;
struct info {
	int num, idx;
};
int main(){
	deque<info> que;
	scanf("%d %d", &N, &L);
	for (int i = 0, a; i<N; i++){
		scanf("%d", &a);
		while (!que.empty() && que.back().num > a) que.pop_back();
		que.push_back({ a,i });
		if (i - L + 1 >= 0 && que.front().idx < i - L + 1)  que.pop_front();
		printf("%d ", que.front().num);
	}
}
