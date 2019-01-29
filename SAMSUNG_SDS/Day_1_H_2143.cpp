#include <stdio.h>
#include <algorithm> 
using namespace std;
int T,n,m;
int N[1000],M[1000];
int A[1000000],B[1000000],acnt,bcnt;
int ACNT[1000000],BCNT[1000000];

int main()
{
    acnt=bcnt=0;
    scanf("%d",&T);
    scanf("%d",&n);
    for(int i=0,sum;i<n;i++)
    {
        scanf("%d",N+i);
        A[acnt++] = sum = N[i];
        for(int j=i-1;j>=0;j--) A[acnt++] = sum += N[j];
    }
    scanf("%d",&m);
    for(int i=0,sum;i<m;i++)
    {
        scanf("%d",M+i);
        B[bcnt++] = sum = M[i];
        for(int j=i-1;j>=0;j--) B[bcnt++] = sum += M[j];
    }
    sort(A,A+acnt);
    sort(B,B+bcnt);
    ACNT[0]=1;
    int e=acnt;
    acnt=0;
    for(int i=1;i<e;i++)
    {
        if(A[acnt] == A[i]) ACNT[acnt]++;
        else 
        {
            A[++acnt] = A[i];
            ACNT[acnt] = 1;
        }
    }
    BCNT[0]=1;
    e=bcnt;
    bcnt=0;
    for(int i=1;i<e;i++)
    {
        if(B[bcnt] == B[i]) BCNT[bcnt]++;
        else 
        {
            B[++bcnt] = B[i];
            BCNT[bcnt] = 1;
        }
    }
    long long ans=0;
    int bidx = bcnt;
    for(int aidx=0;aidx<=acnt && bidx >= 0;aidx++)
    {
        int num = A[aidx]+B[bidx];
        if(num<T) continue;
        if(num > T)
        {
            while(bidx>0 && num > T) num = A[aidx]+B[--bidx];
        }
        if(num == T) ans += (long long)ACNT[aidx]*BCNT[bidx];
    }
    printf("%lld",ans);
}
