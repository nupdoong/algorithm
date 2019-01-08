#include <stdio.h>

int N;
int fresh[100000];
int main(void){
    int test_case, T;
    int count = 0;
    int a;
    int aa, bb;
    scanf(" %d", &test_case);
    for(T=1; T<=test_case; T++){
        scanf(" %d", &N);
        count = 0;
        for(int i=0; i<N; i++){
            scanf("%d %d", &aa, &bb);
            a = aa - 1;
            fresh[a] = bb;
        }
        int min = fresh[0]+1;
        for(int i=0; i<N; i++){
            if(fresh[i] < min){
                min = fresh[i];
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
