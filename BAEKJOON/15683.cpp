#include <iostream>
#include <vector>

using namespace std;
int N, M;
int map[8][8];
int mask[8][8];
int cctv[8][2];
int cctv_count;
int Max;
int ans;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int dir3[4][4] = {{0, 1, -1, 0}, {-1, 0, 0, -1}, {0, -1, 1, 0}, {1, 0, 0, 1}};
vector<pair<int, int>> q;

void dfs(int cc, int sum){
    if(cc == cctv_count){
        if(Max < sum){
            Max = sum;
        }
        return;
    }
    int x = cctv[cc][0];
    int y = cctv[cc][1];
    int nx = x;
    int ny = y;
    int Count = 0;
    if(map[x][y] == 1){
        for(int i=0; i<4; i++){
            nx = x;
            ny = y;
            while(1){
                nx += dir[i][0];
                ny += dir[i][1];
                if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                    if(map[nx][ny] == 0){
                        if(mask[nx][ny] == 0){
                            sum += 1;
                            mask[nx][ny] = 1;
                            q.push_back(make_pair(nx, ny));
                            Count++;
                            continue;
                        }
                        else{
                            continue;
                        }
                    }
                    if(map[nx][ny] >= 1 && map[nx][ny] <= 5){
                        continue;
                    }
                    if(map[nx][ny] == 6){
                        dfs(cc+1, sum);
                        break;
                    }
                }
                else{
                    dfs(cc+1, sum);
                    break;
                }
            }
            while(Count != 0){
                int xx = q[q.size()-1].first;
                int yy = q[q.size()-1].second;
                q.pop_back();
                mask[xx][yy] = 0;
                sum -= 1;
                Count--;
            }
        }
    }
    else if(map[x][y] == 2){
        for(int i=0; i<2; i++){
            int ad = i;
            if(i == 1){
                ad += 1;
            }
            for(int j=0; j<2; j++){
                nx = x;
                ny = y;
                while(1){
                    nx += dir[j+ad][0];
                    ny += dir[j+ad][1];
                    if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                        if(map[nx][ny] == 0){
                            if(mask[nx][ny] == 0){
                                sum += 1;
                                mask[nx][ny] = 1;
                                q.push_back(make_pair(nx, ny));
                                Count++;
                                continue;
                            }
                            else{
                                continue;
                            }
                        }
                        else if(map[nx][ny] >= 1 && map[nx][ny] <= 5){
                            continue;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
				if(j == 1){
                            dfs(cc+1, sum);
                            while(Count != 0){
                    			int xx = q[q.size()-1].first;
                    			int yy = q[q.size()-1].second;
                    			q.pop_back();
                    			mask[xx][yy] = 0;
                    			sum -= 1;
                    			Count--;
                			}
                        }
            }
        }
    }
    else if(map[x][y] == 3){
        for(int i=0; i<4; i++){
            for(int j=0; j<2; j++){
                int ad = j;
                if(j == 1){
                    ad = ad+1;
                }
                nx = x;
                ny = y;
                while(1){
                    nx += dir3[i][ad];
                    ny += dir3[i][ad+1];
                    if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                        if(map[nx][ny] == 0){
                            if(mask[nx][ny] == 0){
                                sum += 1;
                                mask[nx][ny] = 1;
                                q.push_back(make_pair(nx, ny));
                                Count++;
                                continue;
                            }
                            else{
                                continue;
                            }
                        }
                        else if(map[nx][ny] >= 1 && map[nx][ny] <= 5){
                            continue;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                if(j == 1){
                            dfs(cc+1, sum);
                            while(Count != 0){
                    			int xx = q[q.size()-1].first;
                    			int yy = q[q.size()-1].second;
                    			q.pop_back();
                    			mask[xx][yy] = 0;
                    			sum -= 1;
                    			Count--;
                			}
                        }
            }
        }
    }
    else if(map[x][y] == 4){
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                nx = x;
                ny = y;
                while(1){
                    nx += dir[(i+j)%4][0];
                    ny += dir[(i+j)%4][1];
                    if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                        if(map[nx][ny] == 0){
                            if(mask[nx][ny] == 0){
                                sum += 1;
                                mask[nx][ny] = 1;
                                q.push_back(make_pair(nx, ny));
                                Count++;
                                continue;
                            }
                            else{
                                continue;
                            }
                        }
                        else if(map[nx][ny] >= 1 && map[nx][ny] <= 5){
                            continue;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                if(j == 2){
                            dfs(cc+1, sum);
                            while(Count != 0){
                    			int xx = q[q.size()-1].first;
                    			int yy = q[q.size()-1].second;
                    			q.pop_back();
                    			mask[xx][yy] = 0;
                    			sum -= 1;
                    			Count--;
                			}
                        }
            }
        }
    }
    else{
        for(int i=0; i<4; i++){
                nx = x;
                ny = y;
                while(1){
                    nx += dir[i][0];
                    ny += dir[i][1];
                    if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                        if(map[nx][ny] == 0){
                            if(mask[nx][ny] == 0){
                                sum += 1;
                                mask[nx][ny] = 1;
                                Count++;
                                q.push_back(make_pair(nx, ny));
                                continue;
                            }
                            else{
                                continue;
                            }
                        }
                        else if(map[nx][ny] >= 1 && map[nx][ny] <= 5){
                            continue;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
            if(i == 3){
                dfs(cc+1, sum);
                while(Count != 0){
                    	int xx = q[q.size()-1].first;
                    	int yy = q[q.size()-1].second;
                    	q.pop_back();
                    	mask[xx][yy] = 0;
                    	sum -= 1;
                    	Count--;
        	 	}
            }
        }
    }
    return;
}

int main(void){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &map[i][j]);
            mask[i][j] = 0;
            if(map[i][j] >= 1 && map[i][j] <= 5){
                cctv[cctv_count][0] = i;
                cctv[cctv_count][1] = j;
                mask[i][j] = 1;
                cctv_count++;
            }
            if(map[i][j] == 6){
                mask[i][j] = 1;
            }
            if(map[i][j] == 0){
                ans++;
            }
        }
    }
    dfs(0, 0);
    ans = ans - Max;
    printf("%d", ans);
    return 0;
}
