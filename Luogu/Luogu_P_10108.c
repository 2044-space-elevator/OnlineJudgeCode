#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define max(a, b) ((a)>(b)?(a):(b))
#define N ((int)(1e6 + 5))
#define M N

int n, m, arr[M], brr[N], dp[2 * N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d", &arr[i]);
  for (int j = 1; j <= n; j++) scanf("%d", &brr[j]);
  for (int i = 2; i <= n * 2; i++) {
    dp[i] = INT_MIN;
  }
  for (int i = 1; i <= n * 2; i++) {
    for (int j = 1; j <= m; j++) {
      if (i > arr[j]) {
        dp[i] = max(dp[i], dp[i - arr[j]] + brr[i - arr[j]]);
      }
    }
  }
  int ans = INT_MIN;
  for (int  i = n + 1; i <= n * 2; i++) {
    ans = max(ans, dp[i]);
  }
  printf("%d", ans);
  return 0;
}