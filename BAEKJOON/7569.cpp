#include <iostream>
#include <queue>

using namespace std;
int M, N, H;
int map[100][100][100];
int mask[100][100][100];
int dir[6][3] = { { 1, 0, 0 },{ -1, 0, 0 },{ 0, -1, 0 },{ 0, 1, 0 },{ 0, 0, -1 },{ 0, 0, 1 } };
int ans;
int c;
queue<pair<int, int>> q;
queue<int> qz;
int main(void) {
   scanf("%d %d %d", &M, &N, &H);
   for (int i = 0; i<H; i++) {
      for (int j = 0; j<N; j++) {
         for (int k = 0; k<M; k++) {
            scanf("%d", &map[j][k][i]);
            mask[j][k][i] = -1;
            if (map[j][k][i] == 1) {
               q.push(make_pair(j, k));
               qz.push(i);
               mask[j][k][i] = 0;
            }
            if (map[j][k][i] == 0) {
               c++;
            }

         }
      }
   }
   while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      int z = qz.front();
      qz.pop();
      q.pop();
      for (int k = 0; k<6; k++) {
         int nx = x + dir[k][0];
         int ny = y + dir[k][1];
         int nz = z + dir[k][2];
         if (nx >= 0 && nx < N && ny >= 0 && ny < M && nz >= 0 && nz < H) {
            if (map[nx][ny][nz] == 0 && mask[nx][ny][nz] == -1) {
               map[nx][ny][nz] = 1;
               c--;
               mask[nx][ny][nz] = mask[x][y][z] + 1;
               ans = mask[nx][ny][nz];
               q.push(make_pair(nx, ny));
               qz.push(nz);
            }
         }
      }
   }
   if (c != 0)
      ans = -1;
   printf("%d", ans);
   return 0;
}
