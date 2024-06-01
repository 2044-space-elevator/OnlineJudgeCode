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

stg a, b;
int dp[2005][2005];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> a >> b;
  a = ' ' + a, b = ' ' + b;
  rep(i, 1, 2000) dp[0][i] = dp[i][0] = i;
  rep(i, 1, a.size()) {
    rep(j, 1, b.size()) {
      if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1];
      else dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
    }
  } 
  cout << dp[a.size()][b.size()];
	return 0;
}
