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
const int N = 1e5 + 7;
ll dp[N], arr[N], n, m, k;


main() {
  //  int t; cin >> t; while (t--) solve();
  cin >> n >> m >> k;
  rep(i, 1, n) cin >> arr[i];
  memset(dp, 127, sizeof(dp));
  dp[0] = 0;
  rep(i, 1, n) {
    rep(j, 1, i) {
      dp[i] = min(dp[i], dp[j - 1] + (j + i) * (i - j + 1) + abs(arr[i] - arr[j]) + k);
    }
  }
  cout << dp[n];
  return 0;
}