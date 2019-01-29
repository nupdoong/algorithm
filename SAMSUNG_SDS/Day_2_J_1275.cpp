#include <stdio.h>
typedef long long ll;
int N,Q;
ll sumtree[100001*4];
ll sum(int s, int e)
{
    ll ret=0;
    while(s<=e)
    {
        if(s%2==1) ret += sumtree[s++];
        if(e%2==0) ret += sumtree[e--];
        s /= 2;
        e /= 2;
    }
    return ret;
}

void update(int idx, ll delta)
{
    while(idx>0)
    {
        sumtree[idx] += delta;
        idx /= 2;
    }
}

int main()
{
    scanf("%d%d",&N,&Q);
    int Nidx=1;
    while(Nidx<N) Nidx *= 2;
    Nidx--;
    for(int i=0;i<=(Nidx+1)*2;i++) sumtree[i]=0;
    for(int i=1;i<=N;i++) scanf("%lld",sumtree+Nidx+i);
    for(int i=Nidx;i>0;i--) sumtree[i] = sumtree[i*2]+sumtree[i*2+1];
    for(int i=0,x,y,a,b;i<Q;i++)
    {
        scanf("%d%d%d%d",&x,&y,&a,&b);
        if(x>y){int tmp=x;x=y;y=tmp;}
        printf("%lld\n",sum(Nidx+x,Nidx+y));
        update(Nidx+a,b-sumtree[Nidx+a]);
    }
}
