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

int n, arr[1005], dp[1005][1005], sum[1005];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  memset(dp, 127, sizeof dp);
  rep(i, 1, n) {
    cin >> arr[i];
    sum[i] = sum[i - 1] + arr[i]; 
    dp[i][i] = 0;
  }
  rep(len, 2, n) {
    rep(l, 1, n - len + 1) {
      int q = l + len - 1;
      repq(r, l, q) {
        dp[l][q] = min(dp[l][q], dp[l][r] + dp[r + 1][q] + sum[q] - sum[l - 1]);
      }
    }
  }
  cout << dp[1][n];
	return 0;
}
