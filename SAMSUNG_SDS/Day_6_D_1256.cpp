#include <iostream>

#include <string>

#include <algorithm>

#include <cstring>

using namespace std;

 

const int MAX = 100 + 1;

 

int N, M, K;

string word;

bool noWord;

int cache[MAX][MAX];

 

int possibleNumOfWord(int A, int Z)

{

        //기저 사례

        if (A == 0 || Z == 0)

                 return 1;

 

        int &result = cache[A][Z];

        if (result != -1)

                 return result;

 

        //a를 택할 경우와 z를 택할 경우 모두 고려

        //1,000,000,000을 넘으면 조건 충족하는 단어 X

        result = min(possibleNumOfWord(A - 1, Z) + possibleNumOfWord(A, Z - 1), 1000000000 + 1);

        return result;

}

 

void getWord(int A, int Z, int skip)

{

        //z만 남았을 경우

        if (A == 0)

        {

                 for (int i = 0; i < Z; i++)

                         word += 'z';

                 return;

        }

        //a만 남았을 경우

        if (Z == 0)

        {

                 for (int i = 0; i < A; i++)

                         word += 'a';

                 return;

        }

 

        int idx = possibleNumOfWord(A - 1, Z); //a를 맨 앞에 택하였을 경우 가능한 조합의 수

        //그 경우의 수보다 건너뛰어야할 수가 적다면 a 추가

        if (skip < idx)

        {

                 word += 'a';

                 getWord(A - 1, Z, skip);

        }

        //그 경우의 수보다 건너뛰어야할 수가 크고 1,000,000,000보다 같거나 작다면 z 추가

        else  if (skip <= 1000000000)

        {

                 word += 'z';

                 getWord(A, Z - 1, skip - idx);

        }

        else //a와 z 모두 추가 불가능하므로 조건 성립하는 단어가 없다

                 noWord = true;

}

 

int main(void)

{

        cin >> N >> M >> K;

       

        noWord = false;

        memset(cache, -1, sizeof(cache));

 

        if (K > possibleNumOfWord(N, M)) //조건을 만족하는 단어들의 개수보다 큰 K번째 단어를 구할 수 없다

                 noWord = true; //조건 성립하는 단어가 없다

        else

                 getWord(N, M, K - 1); //K - 1번 건너 뛴 단어를 구한다

 

        if (noWord) //조건 성립하는 단어가 없을 경우

                 cout << -1 << endl;

        else

                 cout << word << endl;

 

        return 0;

}
