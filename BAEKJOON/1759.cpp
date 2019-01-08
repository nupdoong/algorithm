#include <iostream>
#include <algorithm>
using namespace std;
int L, C;
char word[15];
char cord[15];
void dfs(int w, int sum, int mo, int ja){
    if(sum == L && mo  > 0 && ja > 1){
        for(int i=0; i<L; i++){
            printf("%c", cord[i]);
        }
        printf("\n");
        return;
    }
    if(w >= C){
        return;
    }
    if(word[w] == 'a' || word[w] == 'e' || word[w] == 'i' || word[w] == 'o' || word[w] == 'u'){
        cord[sum] = word[w];
        dfs(w+1, sum+1, mo+1, ja);
    }
    else{
        cord[sum] = word[w];
        dfs(w+1, sum+1, mo, ja+1);
    }
    
    dfs(w+1, sum, mo, ja);
    
}
int main(void){
    scanf("%d %d", &L, &C);
    for(int i=0; i<C; i++){
        scanf(" %1c", &word[i]);
    }
    sort(word, word+C);

    dfs(0, 0, 0, 0);
    return 0;
}
