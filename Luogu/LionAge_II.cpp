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

ll dp[700][700][128];
ll ys[128][128];

main() {
//	int t; cin >> t; while (t--) solve();
  stg s;
  int k, n;
  cin >> s >> k >> n;
  memset(ys, 0, sizeof ys);
  rep(i, 1, n) {
    char a, b;
    cin >> a >> b;
    cin >> ys[a][b];
  } 
  memset(dp, -63, sizeof dp);
  repq(i, 0, 26) 
    dp[0][(s[0] - 'a' )!= i][i] = 0;
  repq(i, 0, s.size() - 1) {
    rep(j, 0, k) {
      repq(p, 0, 26) {
        if (dp[i][j][p] > -1e9) {
          repq(q, 0, 26) {
            ll tmp = dp[i + 1][j + ((s[i + 1] - 'a') != q)][q];
            dp[i + 1][j + ((s[i + 1] - 'a') != q)][q] = max(tmp, dp[i][j][p] + ys[p + 'a'][q + 'a']);
          }
        }
      }
    }
  }
  ll ans = INT_MIN;

  rep(i, 0, k) {
    repq(j, 0, 26) {
      ans = max(ans, dp[s.size() - 1][i][j]);
    }
  }
  cout << ans;
	return 0;
}
