#include <bits/stdc++.h>
#define rty printf("Yes\n");
#define RTY printf("YES\n");
#define rtn printf("No\n");
#define RTN printf("NO\n");
#define rep(v,b,e) for(int v=b;v<=e;v++)
#define repq(v,b,e) for(int v=b;v<e;v++)
#define rrep(v,e,b) for(int v=b;v>=e;v--)
#define rrepq(v,e,b) for(int v=b;v>e;v--)
#define stg string
#define vct vector
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  
}

const int N = 5e3;
int n, dp[N][N], arr[N], sum[N][N];


main() {
  //  int t; cin >> t; while (t--) solve();
  cin >> n;
  rep(i, 1, n) cin >> arr[i];
  rep(i, 1, n) {
    dp[i][i] = arr[i];
  }
  rep(i, 1, n) {
    sum[i][i] = arr[i];
    rep(j, i + 1, n) {
      sum[i][j] = sum[i][j - 1] + arr[j];
    }
  }
  rep(d, 1, n) {
    rep(i, 1, n - d) {
      dp[i][i + d] = sum[i][i + d] - min(dp[i][i + d - 1], dp[i + 1][i + d]);
    }
  }
  cout << dp[1][n];
  return 0;
}