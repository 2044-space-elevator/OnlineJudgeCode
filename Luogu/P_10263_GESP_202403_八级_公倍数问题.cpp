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
ll ans, n, m, k;

ll sn[(int)1e6 + 5], sm[(int)1e6 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m >> k;
  rep(i, 1, n) {
    rep(j, 1, k / i) {
      sn[i * j]++;
    }
  }
  rep(i, 1, m) {
    rep(j, 1, k / i) {
      sm[i * j]++;
    }
  }
  rep(i, 1, k) {
    ans += sn[i] * sm[i] * i;
  }
  cout << ans;
	return 0;
}
