#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    sort(strings.begin(),strings.end());
    string temp = "";
    for(int i =0;i<strings.size();i++)
    {
        for(int j =0;j<strings.size()-1;j++)
        {
            if(strings[j][n]>strings[j+1][n])
            {
                temp = strings[j];
                strings[j] = strings[j+1];
                strings[j+1] = temp;
            }
        }
    }
    return strings;
}
