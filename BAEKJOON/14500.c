#include<stdio.h>

int N, M;
int map[505][505];
int exsum;
int max = 0;

void big(int plus) {
   if (max < exsum)
      max = exsum;
   exsum = exsum - plus;
}

void check(void) {
   for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
         //가로
         exsum = map[i][j] + map[i][j + 1] + map[i][j + 2];
         //
         exsum += map[i - 1][j];
         big(map[i - 1][j]);

         exsum += map[i - 1][j + 1];
         big(map[i - 1][j+1]);

         exsum += map[i - 1][j + 2];
         big(map[i - 1][j+2]);
         //
         exsum += map[i + 1][j];
         big(map[i + 1][j]);

         exsum += map[i + 1][j + 1];
         big(map[i + 1][j + 1]);

         exsum += map[i + 1][j + 2];
         big(map[i + 1][j + 2]);
         //
         exsum += map[i][j - 1];
         big(map[i][j - 1]);

         exsum += map[i][j + 3];
         big(map[i][j + 3]);

         //세로
         exsum = map[i][j] + map[i+1][j] + map[i+2][j];
         //
         exsum += map[i][j-1];
         big(map[i][j - 1]);

         exsum += map[i][j + 1];
         big(map[i][j + 1]);
         //
         exsum += map[i + 1][j - 1];
         big(map[i + 1][j - 1]);
         
         exsum += map[i + 1][j + 1];
         big(map[i + 1][j + 1]);
         //
         exsum += map[i + 2][j - 1];
         big(map[i + 2][j - 1]);

         exsum += map[i + 2][j + 1];
         big(map[i + 2][j + 1]);
         //
         exsum += map[i - 1][j];
         big(map[i - 1][j]);

         exsum += map[i + 3][j];
         big(map[i + 3][j]);

         exsum = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
         big(0);

         exsum = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 2][j - 1];
         big(0);

         exsum = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j - 1];
         big(0);

         exsum = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
         big(0);

         exsum = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1];
         big(0);
      }
   }
}


int main(void) {
   scanf("%d %d", &N, &M);

   for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
         scanf("%d", &map[i][j]);
      }
   }

   check();

   printf("%d", max);

   return 0;
}
