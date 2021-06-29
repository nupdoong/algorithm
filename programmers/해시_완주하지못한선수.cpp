#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    for(int i=0; i<participant.size(); i++){
        string s = participant[i];
        m[s]++;
    }
    for(int i=0; i<completion.size(); i++){
        string s = completion[i];
        m[s]--;
    }
    /*for(int i=0; i<participant.size(); i++){
        string s = participant[i];
        if(m[s] > 0){
            answer += s;
            break;
        }
    }
    */
    /*for(auto it : m){
        string s = it.first;
        if(m[s]>0){
            answer += s;
            break;
        }
    }
    */
    for(auto it = m.begin(); it != m.end(); it++){
        string s = it->first;
        if(m[s] > 0){
            answer += s;
            break;
        }
    }
    return answer;
}
