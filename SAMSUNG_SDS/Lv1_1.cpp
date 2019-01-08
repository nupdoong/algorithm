#include <iostream>
#include <deque>

using namespace std;

int N;

int main() {
    int test_case;
    scanf("%d", &test_case);
    for(int T=1; T<=test_case; T++){
        char card_i;
        deque<char> dq;
        scanf("%d", &N);
        for(int i=0; i<N; i++){
            scanf(" %c", &card_i);
            if(i==0){
                dq.push_front(card_i);
            }
            else{
                if(dq.front() > card_i){
                    dq.push_back(card_i);
                }
                else{
                    dq.push_front(card_i);
                }
            }
        }
        printf("#%d ", T);
        for(int i=0; i<N; i++){
            printf("%c", dq[i]);
        }
        printf("\n");
    }
    return 0;
}
