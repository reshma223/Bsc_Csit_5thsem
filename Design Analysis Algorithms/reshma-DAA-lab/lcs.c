#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) {
return (a > b) ? a : b;
}
int lcs(char* X, char* Y, int m, int n) {
int i, j;
int dp[m + 1][n + 1];
for (i = 0; i <= m; i++) {
for (j = 0; j <= n; j++) {
if (i == 0 || j == 0) {
dp[i][j] = 0;
} else if (X[i - 1] == Y[j - 1]) {
dp[i][j] = 1 + dp[i - 1][j - 1];
} else {
dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}}}
return dp[m][n];
}
int main() {
char X[] = "AGGTAB";
char Y[] = "GXTXAYB";
int m = sizeof(X) / sizeof(X[0]) - 1;
int n = sizeof(Y) / sizeof(Y[0]) - 1;
int result = lcs(X, Y, m, n);
printf("Length of Longest Common Subsequence: %d\n", result);
return 0;
}