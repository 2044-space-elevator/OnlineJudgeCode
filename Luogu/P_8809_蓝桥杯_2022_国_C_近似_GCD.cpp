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
#define int ll

int n, g, arr[100005], dp[100005];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> g;
  rep(i, 1, n) cin >> arr[i];
  int ans = 0;
  rep(i, 1, n) {
    dp[i] = dp[i - 1] + !!(arr[i] % g);
  }
  rep(i, 1, n) {
    int tmp = upper_bound(dp + i, dp + n + 1, dp[i - 1] + 1) -  dp;
    ans += tmp - i - 1;
  }
  cout << ans;
	return 0;
}
