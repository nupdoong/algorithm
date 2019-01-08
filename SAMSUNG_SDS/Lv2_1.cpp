#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, B;
int sum;
int power, num;
int fin;
int r[20001];
int max_r;

int main() {
    int T;
    scanf("%d", &T);
    for(int test_case=1; test_case <= T; test_case++){
        int m_num;
        sum = 0;
        fin = 0;
        max_r = 0;
        scanf("%d %d %d", &N, &M, &B);
        for(int i=0; i<M; i++){
            scanf("%d %d", &power, &num);
            r[power] = num;
            if(power > max_r){
                max_r = power;
            }
        }
        int find_in = B; 
        while(1){
            if(find_in > 20000)
                break;
            if(max_r>=B){
                for(int i=B; i<=find_in; i++){
                    if(r[i]==0){
                        continue;
                    }
                    m_num = r[i];
                    for(int j=0; j<m_num; j++){
                        N--;
                        sum += i;
                        r[i]--;
                        if(N==0){
                            fin=1;
                            break;
                        }
                    }
                    if(fin==1)
                        break;
                }
            }
            if(fin==1){
                break;
            }
            for(int i=1; i<=find_in/2; i++){
                if(r[i]==0){
                    continue;
                }
                if(r[find_in-i]==0){
                    continue;
                }
                if(i==find_in-i){
                    if(r[i] < 2){
                        continue;
                    }
                    m_num = r[i];
                    for(int j=0; j < m_num/2; j++){
                        N--;
                        sum+=find_in;
                        r[i]--;
                        r[i]--;
                        if(N==0){
                            fin=1;
                            break;
                        }
                    }
                    if(fin==1)
                        break;
                    else
                        continue;
                }
                if(r[i] >= r[find_in-i]){
                    m_num = r[find_in-i];
                }
                else{
                    m_num = r[i];
                }
                for(int j=0; j<m_num; j++){
                    N--;
                    sum+=find_in;
                    r[i]--;
                    r[find_in-i]--;
                    if(N==0){
                        fin=1;
                        break;
                    }
                }
                if(fin==1){
                    break;
                }
            }
            if(fin == 1){
                break;
            }
            find_in++;
        }
        if(fin==1){
            printf("#%d %d\n", test_case, sum);
        }
        else{
            printf("#%d -1\n", test_case);
        }
        for(int i=0; i<=max_r; i++){
            r[i] = 0;
        }
    }
    return 0;
}
