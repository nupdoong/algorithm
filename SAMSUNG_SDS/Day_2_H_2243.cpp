#include <stdio.h>
int N;
int sumtree[1000001*4], Nidx;
void update(int idx, int delta)
{
    while(idx>0) 
    {
        sumtree[idx] += delta;
        idx /= 2;
    }
}
int get_kth(int k)
{
    int cur = 1;
    while(cur <= Nidx)
    {
        if(sumtree[cur*2] < k)
        {
            k -= sumtree[cur*2];
            cur = cur*2 + 1;
        }
        else cur = cur*2;
    }
    update(cur,-1);
    return cur-Nidx;
}
int main()
{
    scanf("%d",&N);
    Nidx=1;
    while(Nidx<1000000) Nidx *= 2;
    Nidx--;
    for(int i=0;i<Nidx*2;i++) sumtree[i]=0;
    for(int i=0,a,b,c;i<N;i++)
    {
        scanf("%d",&a);
        if(a==1)
        {
            scanf("%d",&b);
            printf("%d\n",get_kth(b));
        }
        else if(a==2)
        {
            scanf("%d%d",&b,&c);
            update(b+Nidx,c);
        }
    }
}
