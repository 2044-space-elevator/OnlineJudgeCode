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
const int N = 105, M = 4550;
int n, m, head[N], cnt;
bool dp[N][N];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  rep(i, 1, m) {
    int u, v;
    cin >> u >> v;
    dp[u][v] = 1;
  }
  rep(k, 1, n) {
    rep(i, 1, n) {
      rep(j, 1, n) {
        dp[i][j] |= dp[i][k] & dp[k][j];
      }
    }
  }
  int ans = 0;
  rep(i, 1, n) {
    int cnt = 0;
    rep(j, 1, n) {
      if (i == j) continue;
      cnt += dp[i][j] || dp[j][i]; 
    }
    ans += cnt == n - 1;
  }
  cout << ans;
	return 0;
}
