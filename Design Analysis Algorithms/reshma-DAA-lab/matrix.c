#include <stdio.h>
#include <limits.h>
#define MAX_MATRICES 100
int matrixChainMultiplication(int dims[], int n) {
int dp[MAX_MATRICES][MAX_MATRICES];
for (int i = 1; i <= n; i++) {
for (int j = 1; j <= n; j++) {
dp[i][j] = 0;}}
for (int l = 2; l <= n; l++) {
for (int i = 1; i <= n - l + 1; i++) {
int j = i + l - 1;
dp[i][j] = INT_MAX;
for (int k = i; k < j; k++) {
int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
if (cost < dp[i][j]) {
dp[i][j] = cost;}}}}
return dp[1][n - 1];}
int main() {
int dims[MAX_MATRICES];
int n;
printf("Enter the number of matrices: ");
scanf("%d", &n);
printf("Enter the dimensions of matrices: ");
for (int i = 0; i <= n; i++) {
scanf("%d", &dims[i]);}
int minScalarMultiplications = matrixChainMultiplication(dims, n + 1);
printf("Minimum number of scalar multiplications: %d\n", minScalarMultiplications);
return 0;}