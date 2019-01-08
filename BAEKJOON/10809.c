#include <stdio.h>
#include <string.h>

int main(void){
    char input[100];
    int apb[26];
    
    scanf("%s", input);
    int input_size = strlen(input);
    for(int i=0; i<26; i++){
        apb[i] = -1;
    }
    for(int i=0; i< input_size; i++){
        int a = (int)input[i] - 97;
        if(apb[a] == -1)
            apb[a] = i;
    }
    
    for(int i=0; i<26; i++){
        printf("%d ", apb[i]);
    }
    return 0;
}
