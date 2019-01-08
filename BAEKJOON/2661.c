#include <stdio.h>

int N;
int arr[100];
int ccc=0;

int check(int a){
    int half = a/2;
    int count = 0;
    for(int i=2; i<=half; i++){
        int ii = i*2;
        count = 0;
        for(int j=1; j<=a-ii+1; j++){
            count = 0;
            for(int k=j; k<j+i; k++){
                if(arr[k] == arr[k+i]){
                    count++;
                }
            }
            if(count == i){
                 return 0;
            }
        }
    }
    return 1;
}

void dfs(int x, int sum){
    if(ccc==1){
        return;
    }
    if(sum >= N){
        ccc = 1;
        for(int i=1; i<=N; i++){
            printf("%d", arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1; i<=3; i++){
        if(i==x){
            continue;
        }
        arr[sum+1] = i;
        if(sum >= 3){
            if(check(sum+1)==0){
                continue;
            }
            else{
                dfs(i, sum+1);
            }
        }
        else
            dfs(i, sum+1);
    }
}

int main(void){
    scanf("%d", &N);
    for(int i=1; i<=3; i++){
        arr[0] = 0;
        arr[1] = i;
        dfs(i, 1);
    }
    
    return 0;
}

