#include <stdio.h>
int n;
int a, b;
int m;
int map[101][2];
int ans=10000000;
int fsum=0;

int check(int xx){
    for(int i=0; i<m; i++){
        if(map[i][1] == xx){
            return 1;
        }
    }
    return 0;
}
void dfs(int x, int y, int sum){
    int aa=0;
    int bb=0;
    int temp=x;
    int temp2=y;
    int con=0;
    if(x == y){
        ans = sum;
        return;
    }
    
    aa = check(x);
    bb = check(y);

    if(aa == 0 && bb == 0){
        return;
    }
    for(int i=0; i<m; i++){
        if(map[i][1] == x){
            temp = map[i][0];
            dfs(temp, temp2, sum+1);
            temp = x;
        }
        if(map[i][1] == y){
            temp2 = map[i][0];
            dfs(temp, temp2, sum+1);
            temp2 = y;
        }
        
    }
    
}

int main(void){
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &map[i][0], &map[i][1]);
    }
    dfs(a, b, 0);
    
    if(ans != 10000000)
        printf("%d", ans);
    else
        printf("-1");
    
    return 0;
}
