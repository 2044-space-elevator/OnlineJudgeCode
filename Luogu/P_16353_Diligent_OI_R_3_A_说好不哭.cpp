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
	ll n, x, y;
	cin >> n >> x >> y;
	if (n == 1) {
		if (x != y) {
			RTN return;
		} else { RTY return; }
	}
	if (x * y > 0 && x < 0) {
		x = abs(x), y = abs(y);
		swap(x, y);
	}
	if (x >= n * y) {
		RTY return;
	}
	RTN return;
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
