#include <stdio.h>
#include <string.h>

int main(void){
    char input[1000000];
    int count = 1;
    scanf("%[^\n]s", input);
    int a;
    a = strlen(input);
    for(int i=0; i<a; i++){
        if(i == 0 && (int)input[i] == 32)
            count--;
        
        if(i == a-1 && (int)input[i] == 32)
            count--;
        
        if((int)input[i] == 32)
            count++;
    }
    
    printf("%d", count);
    
    return 0;
}
