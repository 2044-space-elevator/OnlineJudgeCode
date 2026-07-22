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

int n; ll m;
const int N = 1E5 + 5;
ll xi[N];

main() {
	cin >> n >> m;
	ll cost = 1e18;
	rep(i, 1, n) {
		ll x, y;
		cin >> x >> y;	
		cost = min(cost, x + y);
		xi[i] = x;
	}
	sort(xi + 1, xi + n + 1);
	rep(i, 1, n) xi[i] += xi[i - 1];
	ll ans = 0;
	rep(i, 0, n) {
		if (m < xi[i]) continue;
		ans = max(ans, i + (m - xi[i]) / cost * 2ll);
	}
	cout << ans;
//	int t; cin >> t; while (t--) solve();
	return 0;
}
