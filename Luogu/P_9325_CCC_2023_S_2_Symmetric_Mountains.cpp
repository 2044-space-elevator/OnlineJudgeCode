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
const int N = 5e3 + 5;

int n, dp[N][N], arr[N];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  rep(i, 1, n ) {
    cin >> arr[i];
  }
  repq(i, 0, n) {
    int mn = INT_MAX;
    rep(j, 1, n - i) {
      int len = i + j;
      dp[j][len] = dp[j + 1][len - 1] + abs(arr[len] - arr[j]);
      mn = min(mn, dp[j][len]);
    }
    cout << mn << ' ';
  }
	return 0;
}
