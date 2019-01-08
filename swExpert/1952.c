#include <stdio.h>
int d, m, tm, y;
int table[12];
int min;

void dfs(int mm, int sum){
    if(mm > 11){
        if(min > sum){
            min = sum;
        }
        return;
    }
    if(table[mm] > 0){
        dfs(mm+1, sum+table[mm]*d);
        dfs(mm+1, sum+m);
        dfs(mm+3, sum+tm);
    }
    else
        dfs(mm+1, sum);
}

int main(void){
    int T, test_case;
    scanf("%d", &T);
    for(test_case=1; test_case<=T; test_case++){
        scanf("%d %d %d %d", &d, &m, &tm, &y);
        for(int i=0; i<12; i++){
            scanf("%d", &table[i]);
        }
        min = y;
        dfs(0, 0);
        printf("#%d %d\n", test_case, min);
    }
    return 0;
}
