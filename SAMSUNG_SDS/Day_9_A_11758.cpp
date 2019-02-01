#include <stdio.h>
int main()
{
	int x1, y1, x2, y2, x3, y3, S, ans = 0;
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
	S = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
	if (S > 0) {
		ans = 1;
	}
	else if (S < 0) {
		ans = -1;
	}
	else {
		ans = 0;
	}
	printf("%d", ans);
	return 0;
}
