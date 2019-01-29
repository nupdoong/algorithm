#include <stdio.h>
#include <vector>
using namespace std;

int N,M;
long long W[100001];
struct info{
    int node;
    long long gap;
    info(int n, long long g){
        node = n;
        gap = g;
    }
};
vector <info> adj[100001];
int root[100001], visit[100001];
int group(int node){
    if(root[node] == node) return node;
    else return root[node] = group(root[node]);
}
void join(int a, int b) 
{
    root[group(b)] = group(a);
}
int Q[100001][3];
void dfs(int node, long long w)
{
    W[node] = w;
    visit[node]=1;
    for(info e : adj[node])
        if(visit[e.node]==0) dfs(e.node,w+e.gap);
}
int main()
{
    while(1)
    {
        scanf("%d%d",&N,&M);
        if(N==0&&M==0)break;
        for(int i=0;i<=N;i++)
        {
            visit[i] = W[i] = 0;
            root[i] = i;
            adj[i].clear();
        }
        char op[5];
        int w;
        for(int i=0;i<M;i++)
        {
            scanf("%s %d %d",op,&Q[i][1],&Q[i][2]);
            if(op[0]=='!')
            {
                scanf("%d",&w);
                Q[i][0] = 0;
                adj[Q[i][1]].push_back(info(Q[i][2],w));
                adj[Q[i][2]].push_back(info(Q[i][1],-w));
            }
            else if(op[0]=='?')
            {
                Q[i][0] = 1;
            }
        }
        for(int i=1;i<=N;i++) if(visit[i]==0) dfs(i,0);
        for(int i=0;i<M;i++)
        {
            if(Q[i][0]==0) join(Q[i][1],Q[i][2]);
            else {
                if(group(Q[i][1]) != group(Q[i][2])) printf("UNKNOWN\n");
                else printf("%lld\n",W[Q[i][2]]-W[Q[i][1]]);
            }

        }
    }
}
