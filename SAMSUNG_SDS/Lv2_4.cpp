#include <iostream> 
#include <vector>

using namespace std;

const int N=6, M=4;
int map[6][4], visit[6][4], Max = 0, hc;
int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

vector<pair<int, int>> store_xy;
vector<pair<int, int>> shape_1 = { { 0,0 },{ 1,0 },{ 2,0 },{ 2,1 } };
vector<pair<int, int>> shape_2 = { { 0,0 },{ 1,0 },{ 2,0 },{ 1,1 } };
vector<pair<int, int>> shape_3 = { { 0,0 },{ 0,1 },{ 1,1 },{ 1,2 } };
vector<pair<int, int>> shape_4 = { { 0,0 },{ 0,1 },{ 1,0 },{ 1,1 } };
vector<pair<int, int>> shape_5 = { { 0,0 },{ 1,0 },{ 1,1 },{ 1,2 },{ 2,2 } };
vector<pair<int, int>> shape_6 = { { 0,0 },{ 1,0 },{ 1,1 },{ 1,2 },{ 2,0 } };
vector<pair<int, int>> shape_7 = { { 0,0 },{ 1,0 },{ 1,1 },{ 1,2 },{ 0,1 } };
vector<pair<int, int>> shape_8 = { { 0,0 },{ 1,0 },{ 2,0 },{ 2,1 },{ 2,2 } };
vector<vector<pair<int, int>>> shape_vec = { shape_1 , shape_2 , shape_3 , shape_4 , shape_5 , shape_6 , shape_7 , shape_8 };

void reset(void) {
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         map[i][j] = 0, visit[i][j] = 0;
      }
   }
   Max = 0, hc = 0;
}

// 도형 회전 
vector<pair<int, int>> rotate(int degree, vector<pair<int, int>> shape) {
   vector<pair<int, int>> _shape = shape;
   int shape_size = _shape.size();

   switch (degree) {
   case 0:
      break;
   case 90:
      for (int shp_idx = 0; shp_idx < shape_size; shp_idx++)
         _shape.at(shp_idx) = { ((0)*_shape.at(shp_idx).first + (-1)* _shape.at(shp_idx).second),
         ((1)*_shape.at(shp_idx).first + (0)* _shape.at(shp_idx).second) };
      break;
   case 180:
      for (int shp_idx = 0; shp_idx < shape_size; shp_idx++)
         _shape.at(shp_idx) = { ((-1)*_shape.at(shp_idx).first + (0)*_shape.at(shp_idx).second),
         ((0)*_shape.at(shp_idx).first + (-1)*_shape.at(shp_idx).second) };
      break;
   case 270:
      for (int shp_idx = 0; shp_idx < shape_size; shp_idx++)
         _shape.at(shp_idx) = { ((0)*_shape.at(shp_idx).first + (1)*_shape.at(shp_idx).second),
         ((-1)*_shape.at(shp_idx).first + (0)* _shape.at(shp_idx).second) };
      break;
   default:
      printf("error");
      exit(9);
      break;
   }

   return _shape;
}

// 도형 뒤집기 
vector<pair<int, int>> flip(vector<pair<int, int>> shape) {
   vector<pair<int, int>> _shape = shape;
   int shape_size = _shape.size();

   for (int shp_idx = 0; shp_idx < shape_size; shp_idx++)
      _shape.at(shp_idx) = { -(_shape.at(shp_idx).first), (_shape.at(shp_idx).second) };

   return _shape;
}

// 합 구하기
int shape_sum(vector<pair<int, int>> shape, int row, int col, int shp_num) {
   int sum = 0,check = 0;
   int shape_size = shape.size();
   for (int shp_idx = 0; shp_idx < shape_size; shp_idx++) {
      int now_row = row + shape.at(shp_idx).first;
      int now_col = col + shape.at(shp_idx).second;
      store_xy.push_back(pair<int, int>(now_row, now_col));
      // 인덱스 범위 체크한다. 
      if (now_row < 0 || now_row > N - 1 || now_col < 0 || now_col > M - 1 || visit[now_row][now_col] == 1 || map[now_row][now_col] == 0) {
         check = 1;
         break;
      }

      if (map[now_row][now_col] == shp_num + 1) {
         sum += 1;
      }
   }
   if (check == 0) {
      for (int i = 0; i < store_xy.size(); i++) {
         visit[store_xy[i].first][store_xy[i].second] = 1;
      }
      store_xy.clear();
      return sum;
   }
   else {
      store_xy.clear();
      return -1;
   }
}

void make_zero(vector<pair<int, int>> shape, int row, int col) {
   int shape_size = shape.size();
   for (int shp_idx = 0; shp_idx < shape_size; shp_idx++) {
      int now_row = row + shape.at(shp_idx).first;
      int now_col = col + shape.at(shp_idx).second;
      visit[now_row][now_col] = 0;
   }
}

int check_map(void) {
   int count = 0;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         if (visit[i][j] == 1 && map[i][j] != 0) {
            count++;
         }
      }
   }
   if (count == hc)
      return 0;
   else
      return hc-count;
}

void func(int sum) {
   /*
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         printf("%d ", visit[i][j]);
      }
      printf("\n");
   }
   printf("sum %d\n", sum);
   */
   int sum_ex,check_stop;
   check_stop = check_map();
   if (check_stop == 0) {
      if (Max < sum)
         Max = sum;
      return;
   }
   else if (check_stop < 4)
      return;


   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         if (map[i][j] != 0 && visit[i][j] == 0) {
//            printf("x y is %d %d\n", i, j);
            int shape_vec_size = shape_vec.size();
            for (int idx = 0; idx < shape_vec_size; idx++) {
               // flip 하기 전 
               for (int chg_idx = 0; chg_idx < 4; chg_idx++) {
                  vector<pair<int, int>> _shape = rotate(chg_idx * 90, shape_vec.at(idx));
                  sum_ex = shape_sum(_shape, i, j, idx);
                  if (sum_ex == -1)
                     continue;
                  func(sum + sum_ex);
                  make_zero(_shape, i, j);
               }

               // flip 한 후  
               for (int chg_idx = 0; chg_idx < 4; chg_idx++) {
                  vector<pair<int, int>> _shape = flip(shape_vec.at(idx));
                  _shape = rotate(chg_idx * 90, _shape);
                  sum_ex = shape_sum(_shape, i, j, idx);
                  if (sum_ex == -1)
                     continue;
                  func(sum + sum_ex);
                  make_zero(_shape, i, j);
               }
            }
         }
      }
   }



}

///////////////
// 메인 함수 //
//////////////
int main() {
   int test_c;
   cin >> test_c;
   for(int t=1;t<=test_c;t++){
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         scanf("%d", &map[i][j]);
         if (map[i][j] != 0)
            hc++;
      }
   }

   func(0);

   printf("#%d %d\n", t, Max);
   reset();
   }
   return 0;
}
