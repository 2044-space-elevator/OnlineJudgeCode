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
int dp[(int)1e6 + 5][2], arr[(int)1e6 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  rep(i, 1, n) cin >> arr[i];
  dp[1][1] = arr[1];
  rep(i, 2, n) {
    dp[i][0] = min(dp[i - 1][1], dp[i - 2][1]);
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i];
  }
  cout << min(dp[n][0], dp[n][1]) << endl;
	return 0;
}
