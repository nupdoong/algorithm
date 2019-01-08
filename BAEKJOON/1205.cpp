#include<stdio.h>
#include<algorithm>
 
using namespace std;
 
int n,m,p;
int data[51];
 
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&data[i]);
 
	sort(data+1,data+n+1);
 
	if(n==p&&data[1]>=m)
		printf("-1");
	else
	{
		for(i=1;i<=n;i++)
		{
			if(data[n-i+1]<=m)
			{
				printf("%d",i);
				return 0;
			}
		}
		printf("%d",n+1);
	}
 
	return 0;
}
