#include <iostream>
#include <vector>
using namespace std;
struct SHARK{
  int r, c, s, d, z, num;  
};
int R, C, M;
int ans;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<SHARK> v;
vector<int> map[101][101];
void fishing(int loc){
    for(int i=1; i<=R; i++){
        if(map[i][loc].size()>0){
            ans += v[map[i][loc][0]].z;
            v[map[i][loc][0]].z = 0;
            map[i][loc].pop_back();
            break;
        }
    }
}
void move(){
    for(int i=0; i<v.size();i++){
        if(v[i].z == 0) continue;
        int x = v[i].r;
        int y = v[i].c;
        map[x][y].clear();
    }
    for(int i=0; i<v.size();i++){
        if(v[i].z == 0) continue;
        int x = v[i].r;
        int y = v[i].c;
        int direction = v[i].d;
        int speed = v[i].s;
        if (direction == 0 || direction == 1){
            int Rotate = (R - 1) * 2;
            if (speed >= Rotate) speed = speed % Rotate;
            for (int j = 0; j < speed; j++){
                int nx = x + dir[direction][0];
                int ny = y + dir[direction][1];
                if (nx < 1){
                    direction = 1;
                    nx = nx + 2;
                }
                if (nx > R){
                    direction = 0;
                    nx = nx - 2;
                }
                x = nx;
                y = ny;
            }
        }
        else{
            int Rotate = (C - 1) * 2;
            if (speed >= Rotate) speed = speed % Rotate;
 
            for (int j = 0; j < speed; j++){
                int nx = x + dir[direction][0];
                int ny = y + dir[direction][1];
                if (ny < 1){
                    direction = 2;
                    ny = ny + 2;
                }
                if (ny > C){
                    direction = 3;
                    ny = ny - 2;
                }
                x = nx;
                y = ny;
            }
        }
        v[i].r = x;
        v[i].c = y;
        v[i].d = direction;
        map[x][y].push_back(i);
    }
}
void kill(){
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(map[i][j].size()>1){
                int MAX = -1;
                int temp;
                for(int t=0; t<map[i][j].size(); t++){
                    int s_num = map[i][j][t];
                    if(t==0){
                        MAX = v[s_num].z;
                        temp = s_num;
                    }
                    else{
                    	if(MAX < v[s_num].z){
                        	MAX = v[s_num].z;
                            v[temp].z = 0;
                        	temp = s_num;
                    	}
                        else{
                            v[s_num].z = 0;
                        }
                    }
                }
                map[i][j].clear();
                map[i][j].push_back(temp);
            }
        }
    }
}
int main(void){
    scanf("%d %d %d", &R, &C, &M);
    for(int i=0; i<M; i++){
        SHARK x;
        scanf("%d %d %d %d %d", &x.r, &x.c, &x.s, &x.d, &x.z);
        x.num = i;
        x.d = x.d-1;
        v.push_back(x);
        map[x.r][x.c].push_back(i);
    }
    for(int i=1; i<=C; i++){
        fishing(i);
        move();
        kill();
    }
    printf("%d", ans);
    return 0;
}
