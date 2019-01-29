#include <stdio.h>
int N;
struct info{
    int power, idx;
};
info P[500001], tmp[500001];
int A[500001];
void msort(int left, int right)
{
    if(right==left)return;
    else if(right-left==1)
    {
        if(P[left].power < P[right].power)
        {
            A[P[right].idx]--;
            info p = P[right];
            P[right] = P[left];
            P[left] = p;
        }
    }
    else
    {
        int l = left;
        int mid = (left+right)/2;
        int r = mid+1;
        msort(l,mid);
        msort(r,right);
        for(int i=left;i<=right;i++)
        {
            if(l>mid) tmp[i] = P[r++];
            else if(r>right) tmp[i] = P[l++];
            else if(P[l].power > P[r].power) tmp[i] = P[l++];
            else 
            {
                A[P[r].idx] -= (mid-l+1);
                tmp[i] = P[r++];
            }
        }
        for(int i=left;i<=right;i++) P[i] = tmp[i];
    }
}
int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&P[i].power);
        P[i].idx=A[i]=i;
    }
    msort(1,N);
    for(int i=1;i<=N;i++)printf("%d\n",A[i]);
}
