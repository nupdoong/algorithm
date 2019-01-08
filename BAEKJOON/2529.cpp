#include <iostream>
#include <string.h>
using namespace std;
int k;
char c[9];
int mask[10] = {0};
int ans[10];
int ans2[10];
int ans3[10];
long long MAX = 0;
long long MIN = 100000000000;

void dfs(int x, int count){
    if(count == k+1){
        long long sum = 0;
        long long a = 0;
        for(int i=k; i>=0; i--){
            a = ans[k-i];
            if(i == 0){
                sum += a;
            }
            else{
                for(int j=1; j<=i; j++){
                    a *= 10;
                }
                sum += a;
                }
            
        }
        if(MAX < sum){
            MAX = sum;
            for(int i=0; i<=k; i++){
                ans2[i] = ans[i];
            }
        }
        if(MIN > sum){
            MIN = sum;
            for(int i=0; i<=k; i++)
                ans3[i] = ans[i];
        }
        return;
    }
    if(c[count-1] == '<'){
        for(int i=0; i<10; i++){
            if(mask[i] == 0 && x < i){
                mask[i] = 1;
                ans[count] = i;
                dfs(i, count+1);
                mask[i] = 0;
            }
        }
    }
    else if(c[count-1] == '>'){
        for(int i=0; i<10; i++){
            if(mask[i] == 0 && x > i){
                mask[i] = 1;
                ans[count] = i;
                dfs(i, count+1);
                mask[i] = 0;
            }
        }
    }
}
int main(void){
    scanf("%d", &k);
    for(int i=0; i<k; i++){
        scanf(" %1c", &c[i]);
    }
    for(int i=0; i<10; i++){
        mask[i] = 1;
        ans[0] = i;
        dfs(i, 1);
        mask[i] = 0;
    }
    for(int i=0; i<=k; i++){
        printf("%d", ans2[i]);
    }
    printf("\n");
    
    for(int i=0; i<=k; i++){
        printf("%d", ans3[i]);
    }
    return 0;
}
