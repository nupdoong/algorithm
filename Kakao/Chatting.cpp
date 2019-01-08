#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> aaa;
    vector<string> uid;
    map<string, string> m;
    for(int i=0; i<record.size(); i++){
        string buf;
        stringstream ss(record[i]);
        vector<string> tokens;
        while (ss >> buf){
            tokens.push_back(buf);
        }
        
        if(tokens[0] == "Enter"){
            if(m.find(tokens[1]) == m.end()){
                m.insert(make_pair(tokens[1], tokens[2]));
            }
            else
                m[tokens[1]] = tokens[2];
            
            aaa.push_back(tokens[0]);
            uid.push_back(tokens[1]);
        }
        else if(tokens[0] == "Change"){
            m[tokens[1]] = tokens[2];
        }
        else{
            aaa.push_back(tokens[0]);
            uid.push_back(tokens[1]);
        }
            
    }
    for(int i=0; i<aaa.size(); i++){
        string s4;
        s4 = m[uid[i]];
        s4 += "님이 ";
        if(aaa[i] == "Enter"){
            s4 += "들어왔습니다.";
        }
        else{
            s4 += "나갔습니다.";
        }
        answer.push_back(s4);

    }
    return answer;
}
