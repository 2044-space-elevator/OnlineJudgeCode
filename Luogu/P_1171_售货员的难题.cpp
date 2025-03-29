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

int dp[1048580][21];
int s[21][21];
int n;

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  int m = (1 << n) - 1;
  repq(i, 0, n) {
    repq(j ,0, n) {
      cin >> s[i][j];
    }
  }
  memset(dp, 127, sizeof dp);
  dp[m][0] = 0;
  rrep(S, 0, m - 1) {
    repq(j, 0, n) {
      repq(i, 0, n) {
        if ((S >> i) & 1) continue;
        dp[S][j] = min(dp[S | (1 << i)][i] + s[j][i], dp[S][j]);
      } 
    }
  }
  cout << dp[0][0];
	return 0;
}
