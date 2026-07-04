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


main() {
	int x, y, l, r, a, b;
	cin >> x >> y >> l >> r >> a >> b;
	ll ans = (max(0, min(r, b) - max(l, a))) * x + (b - max(0, min(r, b) - max(l, a)) - a) * y; 	
	cout << ans;
//	int t; cin >> t; while (t--) solve();
	return 0;
}
