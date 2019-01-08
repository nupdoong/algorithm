#include <stdio.h>
int N, M;
int nene[13][2];
int house[100][2];
int count;
int count2;
int ans = 1000000000;
int save[13];

void dfs(int hloc, int check){
    int x;
    int sum  = 0;
    int temp_x;
    int temp_y;
    int temp;
    int min = 1000000000;
    if(check == M){
        for(int i=0; i<count2; i++){
            min = 100000000;
            for(int j=0; j<M; j++){
                x = save[j];
                if(house[i][0] >= nene[x][0])
                    temp_x = house[i][0] - nene[x][0];
                else
                    temp_x = nene[x][0] - house[i][0];
                
                if(house[i][1] >= nene[x][1])
                    temp_y = house[i][1] - nene[x][1];
                else
                    temp_y = nene[x][1] - house[i][1];
                
                temp = temp_x + temp_y;
                if(min > temp)
                    min = temp;
            }
            sum = sum+min;
        }
        if(ans > sum){
            ans = sum;
        }
        return;
    }
    if(hloc >= count){
        return;
    }
    save[check] = hloc;
    dfs(hloc+1, check+1);
    dfs(hloc+1, check);
}

int main(void){
    int a;
    scanf("%d %d", &N, &M);
    count =0;
    count2=0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d", &a);
            if(a == 2){
                nene[count][0] = i;
                nene[count][1] = j;
                count++;
            }
            else if(a == 1){
                house[count2][0] = i;
                house[count2][1] = j;
                count2++;
            }
        }
    }
    dfs(0, 0);
    
    printf("%d", ans);
    
    return 0;
}
