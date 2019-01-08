#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int sum = 0;
    string answer;
    for(int i=1; i<a; i++){
        if(i==2){
            sum += 29;
        }
        else if(i==1 || i==3 || i== 5 || i==7 || i== 8 || i==10 || i==12)
            sum += 31;
        else
            sum += 30;
    }
    sum += b;
    if(sum%7 == 1){
        answer = "FRI";
    }
    else if(sum%7 == 2){
        answer = "SAT";
    }
    else if(sum%7 == 3){
        answer = "SUN";
    }
    else if(sum%7 == 4){
        answer = "MON";
    }
    else if(sum%7 == 5){
        answer = "TUE";
    }
    else if(sum%7 == 6){
        answer = "WED";
    }
    else if(sum%7 == 0){
        answer = "THU";
    }
    return answer;
}

int main(void){
    int a, b;
    scanf("%d %d", &a, &b);
    cout << solution(a, b);
    return 0;
}
