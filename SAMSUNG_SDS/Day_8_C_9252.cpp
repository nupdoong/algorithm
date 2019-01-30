#include <iostream> 
#include <cstring> 
#include <string> 
#include <algorithm> 
using namespace std; 
char s1_arr[1001]; 
char s2_arr[1001]; 
int memo[1001][1001]; 
int main() { 
    cin >> s1_arr >> s2_arr; 
    int s1Size = strlen(s1_arr); 
    int s2Size = strlen(s2_arr); 
    for (int i = 1; i <= s1Size; i++) { 
        for (int j = 1; j <= s2Size; j++) { 
            if (s1_arr[i - 1] == s2_arr[j - 1]) { 
                memo[i][j] = memo[i - 1][j - 1] + 1; } 
            else { 
                memo[i][j] = max(memo[i][j - 1], memo[i - 1][j]); 
            }
        }
    } 
    cout << memo[s1Size][s2Size] << endl; 
    string result; 
    int i = s1Size, j = s2Size;
    while (i > 0 && j > 0) { 
        if (memo[i][j - 1] == memo[i - 1][j] && memo[i - 1][j] == memo[i - 1][j - 1] && memo[i - 1][j - 1] == memo[i][j] - 1) { 
            result += s1_arr[i - 1]; i--; j--; 
        } else { 
            if (memo[i - 1][j] == memo[i][j]) {
                i--; 
            } else if (memo[i][j - 1] == memo[i][j]) { 
                j--; 
            } 
        } 
    } 
    reverse(result.begin(), result.end()); 
    cout << result << endl; 
    return 0; 
}
