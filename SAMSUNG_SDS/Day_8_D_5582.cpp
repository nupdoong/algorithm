#include <stdio.h>
int Dp[4001][4001];
int main()
{
    int max = 0;
    char A[4001];
    char B[4001];
    scanf("%s", A);
    scanf("%s", B);
    for (int i = 0; A[i] != 0; i++)
        for (int j = 0; B[j] != 0; j++)
        {
            if (A[i] == B[j]) {
                if (i == 0 || j == 0)
                    Dp[i][j] = 1;
                else
                    Dp[i][j] = Dp[i - 1][j - 1] + 1;
 
                if (max<Dp[i][j])
                    max = Dp[i][j];
            }
        }
    printf("%d\n", max);
    return 0;
}
