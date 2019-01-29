#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
vector<int> v;

int main(void) {
	int v_size;
	scanf("%d", &N);

	for (int i = 0; i<N; i++) {
		char comm[10];
		scanf("%s", comm);
		if (strcmp(comm, "push") == 0) {
			int a;
			scanf("%d", &a);
			v.push_back(a);
		}
		else if (strcmp(comm, "top") == 0) {
			v_size = v.size();
			if (v_size == 0) {
				printf("-1\n");
			}
			else
				printf("%d\n", v[v_size - 1]);
		}
		else if (strcmp(comm, "size") == 0) {
			v_size = v.size();
			printf("%d\n", v_size);
		}
		else if (strcmp(comm, "empty") == 0) {
			if (v.size()==0) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (strcmp(comm, "pop") == 0) {
			v_size = v.size();
			if (v.size() == 0)
				printf("-1\n");
			else {
				printf("%d\n", v[v_size - 1]);
				v.pop_back();
			}
		}
	}

	return 0;
}
