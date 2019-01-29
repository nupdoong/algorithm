#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
#include<functional>

using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

int n,k;

int prime[101];

int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&prime[i]);
        q.push(prime[i]);
    }

    long long c=0;

    for(int i=1;i<=k;i++)
    {
        c = q.top();q.pop();
        for(int j=1;j<=n;j++)
        {
            if(prime[j]*c<=2147483647)
                q.push(prime[j]*c);
            if(c%prime[j]==0)break;
        }
    }
    printf("%lld",c);
    return 0;
}
