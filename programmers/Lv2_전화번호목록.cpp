#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int count = 0;
    sort(phone_book.begin(), phone_book.end());
    string s1 = phone_book[0];
    for(int i=1; i<phone_book.size(); i++){
        count = 0;
        string ss = phone_book[i];
        for(int j=0; j<ss.length(); j++){
            if(s1[j] == ss[j]){
                count ++;
            }
        }
        if(count == s1.length()){
            answer = false;
            return answer;
        }
    }
    return answer;
}
