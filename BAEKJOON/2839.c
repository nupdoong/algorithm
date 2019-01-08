#include <stdio.h>
int N;

int main(void){
    
    scanf("%d", &N);
    int x = N%5;
    int xx = N/5;
    int ans;

    
    if(x==0){
        ans = xx;
    }
    else if(x==1){
        ans = xx+1;
    }
    else if(x==2){
        if(N>10){
            ans = xx+2;
        }
        else
            ans = -1;
    }
    else if(x==3){
        ans = xx+1;
    }
    else if(x==4){
        if(N>5)
            ans = xx+2;
        else
            ans = -1;
    }
    
    printf("%d", ans);
    
    return 0;
}
