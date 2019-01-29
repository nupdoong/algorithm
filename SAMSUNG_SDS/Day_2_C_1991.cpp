#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<char, char>> v[26];

void preorder(char root) {
	char left_c = v[root - 'A'].front().first;
	char right_c = v[root - 'A'].front().second;
	printf("%c", root);
	if (left_c != '.') preorder(left_c);
	if (right_c != '.') preorder(right_c);
}
void inorder(char root) {
	char left_c = v[root - 'A'].front().first;
	char right_c = v[root - 'A'].front().second;
	if (left_c != '.') inorder(left_c);
	printf("%c", root);
	if (right_c != '.') inorder(right_c);
}
void postorder(char root) {
	char left_c = v[root - 'A'].front().first;
	char right_c = v[root - 'A'].front().second;
	if (left_c != '.') postorder(left_c);
	if (right_c != '.') postorder(right_c);
	printf("%c", root);
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i<N; i++) {
		char p, l, r;
		scanf(" %c %c %c", &p, &l, &r);
		v[p - 'A'].push_back(make_pair(l, r));
	}
	preorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');
	printf("\n");
	return 0;
}
