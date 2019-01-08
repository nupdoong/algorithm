#include <iostream>

using namespace std;
int list[1050];
int cp[70];
int info[70];
int result;
int num;
int T;
int n,m;

int main() {

    cin >> T;
    
    for(int c = 1 ; c <= T ; c++){
        result = 0;
        num = 0;
        cin >> n >> m;
        for(int i = 1 ; i <= m ; i++){
            cin >> info[i];
            num += info[i];
        }
        
        for(int i = 1; i <= n ; i++){
            cin >> list[i];
        }
        
        for(int i = 1; i <= n ; i++){
        
            if(info[list[i]]){
                bool ver = true;
                
                for(int j = 1; j <= m ; j++){
                    cp[j] = info[j];
                }
                
                for(int j = i; j < i+num ; j++){
                    if(cp[list[j]]>0){
                        cp[list[j]]--;
                    }else{
                        ver = false;
                        break;
                    }
                    
                }
                
                if(ver){
                    result = i;
                    break;
                }
                
            }
        
        }
        
        
        cout << "#" << c << " " << result << endl;
    }

    return 0;
}
