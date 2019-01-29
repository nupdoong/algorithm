#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N;
queue<int> v;

int main(void) {
	scanf("%d", &N);
	int v_size;

	for (int i = 0; i<N; i++) {
		char comm[10];
		scanf("%s", comm);
		if (strcmp(comm, "push") == 0) {
			int a;
			scanf("%d", &a);
			v.push(a);
		}
		else if (strcmp(comm, "size") == 0) {
			printf("%d\n", v.size());
		}
		else if (strcmp(comm, "empty") == 0) {
			if (v.empty()) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (strcmp(comm, "pop") == 0) {
			if (v.empty())
				printf("-1\n");
			else {
				printf("%d\n", v.front());
				v.pop();
			}
		}
		else if (strcmp(comm, "front") == 0) {
			if (v.empty())
				printf("-1\n");
			else {
				printf("%d\n", v.front());
			}
		}
		else if (strcmp(comm, "back") == 0) {
			v_size = v.size();
			if (v.empty())
				printf("-1\n");
			else {
				printf("%d\n", v.back());
			}
		}
	}

	return 0;
}
