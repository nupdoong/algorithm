#include <stdio.h>
int N,M;
int I[50000][2];
int maxtree[50000*4];

int find_idx(int year)
{
    int s=0, e=N-1, m, ret=N-1;
    while(s<=e)
    {
        m = (s+e)/2;
        if(I[m][0] < year) s = m+1;
        else
        {
            ret = m;
            e = m-1;
        }
    }
    return ret;
}
int max(int a,int b){return (a>b?a:b);}
int query(int s, int e)
{
    int ret = -1;
    while(s<=e)
    {
        if(s%2==1) ret = max(ret,maxtree[s]);
        if(e%2==0) ret = max(ret,maxtree[e]);
        s = (s+1)/2;
        e = (e-1)/2;
    }
    return ret;
}
int update(int idx, int val)
{
    while(idx > 0)
    {
        if(maxtree[idx] < val)
        {
            maxtree[idx] = val;
            idx = idx/2;
        }
        else break;
    }
}
int main()
{

    scanf("%d",&N);
    for(int i=0;i<N*4;i++) maxtree[i]=0;
    int Nidx = 1;
    while(Nidx < N) Nidx*=2;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&I[i][0],&I[i][1]);
        maxtree[Nidx+i] = I[i][1];
    }
    for(int i = Nidx-1;i>0;i--) maxtree[i] = max(maxtree[i*2],maxtree[i*2+1]);
    scanf("%d",&M);
    for(int i=0,x,y;i<M;i++)
    {
        scanf("%d%d",&y,&x);
        int yi = find_idx(y);
        int xi = find_idx(x);
        //printf("y[%d] yi[%d] x[%d] xi[%d]\n",y,yi,x,xi);
        int maxv = query(Nidx+yi+(y==I[yi][0]?1:0),Nidx+xi-1);
        if(I[xi][0] == x && I[yi][0] == y)
        {
            if(I[yi][1]>=I[xi][1] && I[xi][1] > maxv)
            {
                if(x-y == xi-yi) printf("true\n");
                else printf("maybe\n");
            }
            else printf("false\n");
        }
        else if(I[xi][0] == x)
        {
            if(I[xi][1] > maxv) printf("maybe\n");
            else printf("false\n");
        }
        else if(I[yi][0] == y)
        {
            if(I[yi][1] <= maxv) printf("false\n");
            else printf("maybe\n");
        }
        else printf("maybe\n");

    }

}
