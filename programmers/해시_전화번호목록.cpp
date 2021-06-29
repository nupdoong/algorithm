#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, int> m;
    sort(phone_book.begin(), phone_book.end());
    for(int i=0; i<phone_book.size(); i++){
        string s = phone_book[i];
        string temp_s = "";
        for(int j=0; j<s.length(); j++){
            temp_s += s[j];
            if(m[temp_s] > 0){
                answer = false;
                return answer;
            }
        }
        m[s]++;
    }
    return answer;
}
