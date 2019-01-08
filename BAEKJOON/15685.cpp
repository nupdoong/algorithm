#include <iostream>
#include <vector>

using namespace std;

int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
int N;
int map[101][101];
int x, y, d, g;
int Count;

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        vector<int> v;
        scanf("%d %d %d %d", &x, &y, &d, &g);
        map[x][y] = 1;
        x = x+dir[d][0];
        y = y+dir[d][1];
        map[x][y] = 1;
        v.push_back(d);
        for(int j=0; j<g; j++){
            int a = v.size()-1;
            for(int k = a; k>=0; k--){
                int b = (v[k]+1)%4;
                x = x+dir[b][0];
                y = y+dir[b][1];
                map[x][y] = 1;
                v.push_back(b);
            }
        }
    }
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(map[i][j] == 1){
                if(map[i][j+1] == 1 && map[i+1][j] == 1 && map[i+1][j+1] == 1){
                    Count++;
                }
            }
        }
    }
    printf("%d\n", Count);

    return 0;
}
