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

int n;
int cost[205][205], dp[205];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  repq(i, 1, n) {
    rep(j, i + 1, n) {
      cin >> cost[i][j];
    }
  }
  fill(dp + 2, dp + n + 1, INT_MAX);
  rep(i, 2, n) {
    repq(j, 1, i) {
      dp[i] = min(dp[i], dp[j] + cost[j][i]);
    }
  }
  cout << dp[n];
	return 0;

}
