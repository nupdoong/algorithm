#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> one_ = {1, 2, 3, 4, 5};
    vector<int> two_ = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> three_ = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int a=0;
    int b=0;
    int c=0;
    int max = 0;
    vector<int> answer;
    for(int i=0; i<answers.size(); i++){
        if(answers[i] == one_[i%5]){
            a++;
        }
        if(answers[i] == two_[i%8]){
            b++;
        }
        if(answers[i] == three_[i%10]){
            c++;
        }
    }
    if(max < a){
        max = a;
    }
    if(max < b){
        max = b;
    }
    if(max < c){
        max = c;
    }
    if(max == a){
        answer.push_back(1);
    }
    if(max == b){
        answer.push_back(2);
    }
    if(max == c){
        answer.push_back(3);
    }
    sort(answer.begin(), answer.end());
    return answer;
}
