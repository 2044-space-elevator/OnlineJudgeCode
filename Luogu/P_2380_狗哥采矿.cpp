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

int n, m, dp[505][505], arr[505][505], brr[505][505];

main() {
//	int t; cin >> t; while (t--) solve();
  while (cin >> n >> m) {
    if (n == 0 && m == 0) {
      return 0;
    }
    rep(i, 1, n ) {
      rep(j, 1, m) {
        cin >> arr[i][j];
        arr[i][j] += arr[i][j - 1];
      }
    }
    rep(i, 1, n) {
      rep(j, 1, m) {
        cin >> brr[i][j];
        brr[i][j] += brr[i - 1][j];
      }
    }
    rep(i, 1, n) {
      rep(j, 1, m) {
        dp[i][j] = max(dp[i][j - 1] + brr[i][j], dp[i - 1][j] + arr[i][j]);
      }
    }
    cout << dp[n][m] << endl;
  }
	return 0;
}
