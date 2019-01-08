#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
queue<int> q;
int b[1000001];
int button[2];
int F, S, G, U, D;
int ans;
int main(void){
    int a = 0;
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    q.push(S);
    b[S] = 0;
    button[0] = U;
    button[1] = (-1)*D;
    while(!q.empty()){
        int x = q.front();
        if(x == G){
            printf("%d", ans);
            return 0;
        }
        q.pop();
        for(int i=0; i<2; i++){
            int nx = x + button[i];
            if(nx >= 1 && nx <= F && nx != S){
                if(b[nx] == 0){
                    b[nx] = b[x]+1;
                    q.push(nx);
                    if(nx==G){
            			ans = b[nx];
            			a = 1;
            			break;
        			}
                }
            }
        }
        if(a == 1){
            break;
        }
    }
    if(a == 0){
        printf("use the stairs\n");
    }
    else
        printf("%d\n", ans);
    
    return 0;
}
