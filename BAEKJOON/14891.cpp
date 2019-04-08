#include <iostream>
#include <deque>
#include <math.h>
using namespace std;
int state[4];
int K;
int ans;
int num, dir;
deque<int> dq[4];
int main(void){
    int t;
    for(int i=0; i<4; i++){
        for(int j=0; j<8; j++){
            scanf("%1d", &t);
            dq[i].push_back(t);
        }
    }
    scanf("%d", &K);
    for(int i=0; i<K; i++){
        int temp;
        scanf("%d %d", &num, &dir);
        //2번, 6번 인덱스 비교
        if(num==1){
            state[0] = dir;
            if(dq[0][2] == dq[1][6]){
                state[1] = 0;
                state[2] = 0;
                state[3] = 0;
            }
            else{
                state[1] = dir*(-1);
                if(dq[1][2] == dq[2][6]){
                    state[2] = 0;
                    state[3] = 0;
                }
                else{
                    state[2] = dir;
                    if(dq[2][2] == dq[3][6]){
                        state[3] = 0;
                    }
                    else{
                        state[3] = dir*(-1);
                    }
                }
            }
        }
        else if(num==2){
            state[1] = dir;
            if(dq[0][2] == dq[1][6]){
                state[0] = 0;
            }
            else{
                state[0] = dir*(-1);
            }
            
            if(dq[1][2] == dq[2][6]){
                state[2] = 0;
                state[3] = 0;
            }
            else{
                state[2] = dir*(-1);
                if(dq[2][2] == dq[3][6]){
                    state[3] = 0;
                }
                else{
                    state[3] = dir;
                }
            }
        }
        else if(num==3){
            state[2] = dir;
            if(dq[2][2] == dq[3][6]){
                state[3] = 0;
            }
            else{
                state[3] = dir*(-1);
            }
            if(dq[1][2] == dq[2][6]){
                state[1] = 0;
                state[0] = 0;
            }
            else{
                state[1] = dir*(-1);
                if(dq[1][6] == dq[0][2]){
                    state[0] = 0;
                }
                else{
                    state[0] = dir;
                }
            }
        }
        else{
            state[3] = dir;
            if(dq[2][2] == dq[3][6]){
                state[0] = 0;
                state[1] = 0;
                state[2] = 0;
            }
            else{
                state[2] = dir*(-1);
                if(dq[2][6] == dq[1][2]){
                    state[0] = 0;
                    state[1] = 0;
                }
                else{
                    state[1] = dir;
                    if(dq[0][2] == dq[1][6]){
                        state[0] = 0;
                    }
                    else{
                        state[0] = dir*(-1);
                    }
                }
            }
            
        }
        //if dir==1 pop_back -> push_front
        //if dir==-1 pop_front -> push_back
        for(int j=0; j<4; j++){
            if(state[j]==0)
                continue;
            else if(state[j]==1){
                temp = dq[j][7];
                dq[j].pop_back();
                dq[j].push_front(temp);
            }
            else{
                temp = dq[j][0];
                dq[j].pop_front();
                dq[j].push_back(temp);
            }
        }
        
    }
    
    for(int i=0; i<4; i++){
        if(dq[i][0] == 0){
            continue;
        }
        else{
            ans+=pow(2, i);
        }
    }
    printf("%d", ans);
    return 0;
}
