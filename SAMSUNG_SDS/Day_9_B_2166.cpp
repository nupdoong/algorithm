#include <cstdio>
typedef long long ll;
inline ll abs(ll x) { return x < 0 ? -x : x; }
struct point { ll x, y; };
int N;
point p[10000];
int main() {
    scanf("%d", &N);
    ll ans = 0;
    for (int n = 0;n < N;n++) scanf("%lld%lld", &p[n].x, &p[n].y);
    for (int n = 0;n < N;n++) {
        if (n == 0) ans += (p[n].x + p[N - 1].x)*(p[n].y - p[N - 1].y);
        else ans += (p[n].x + p[n - 1].x)*(p[n].y - p[n - 1].y);
    }
    printf("%.1lf\n", (double)abs(ans) / 2.0);
    return 0;
}
