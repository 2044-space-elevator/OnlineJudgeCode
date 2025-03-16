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

int dp[32];

main() {
//	int t; cin >> t; while (t--) solve();
  int n; cin >> n;
  int ans = 0;
  rep(i, 1, n) {
    int x;
    cin >> x;
    int tmp = 1;
    rrep(k, 0, 30) {
      if ((x >> k) & 1) {
        tmp = max(tmp, dp[k] + 1);
      }
    }
    ans = max(ans, tmp);
    rep(k, 0, 30) {
      if ((x >> k) & 1) dp[k] = max(dp[k], tmp);
    }
  }
  cout << ans;
	return 0;
}
