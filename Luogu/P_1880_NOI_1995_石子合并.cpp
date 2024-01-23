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

int arr[205], dp[205][205], dp2[205][205], sum[205], n;

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  memset(dp, 127, sizeof dp);
  rep(i, 1, n) {
    cin >> arr[i];
    sum[i] = sum[i - 1] + arr[i];
    dp[i][i] = 0;
  }
  rep(i, n + 1, 2 * n) {
    arr[i] = arr[i - n];
    sum[i] = sum[i - 1] + arr[i];
    dp[i][i] = 0;
  }
  rep(len, 2, n) {
    rep(i, 1, 2 * n + 1 - len) {
      int j = i + len - 1;
      repq(k, i, j) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
        dp2[i][j] = max(dp2[i][j], dp2[i][k] + dp2[k + 1][j] + sum[j] - sum[i - 1]);
      }
    }
  }
  int minx = 1234567890, maxx = 0;
  rep(i, 1, n) {
    minx = min(minx, dp[i][i + n - 1]);
    maxx = max(maxx, dp2[i][i + n - 1]);
  }
  cout << minx << endl << maxx;
	return 0;
}
