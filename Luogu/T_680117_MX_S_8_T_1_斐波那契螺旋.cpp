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

struct Rectangle {
	ll fx, fy, tx, ty;
}fib[101];


main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fib[1] = {-1, 0, 0, 1};
	fib[2] = {-1, -1, 0, 0};
	rep(i, 3, 92) {
		if ((i - 2) % 4 == 1) {
			fib[i].ty = fib[i - 2].ty;
			fib[i].fx = fib[i - 1].tx;
			fib[i].fy = fib[i - 1].fy;
			fib[i].tx = fib[i].fx + fib[i].ty - fib[i].fy;
		}
		if ((i - 2) % 4 == 2) {
			fib[i].fx = fib[i - 2].fx;
			fib[i].fy = fib[i - 1].ty;
			fib[i].tx = fib[i - 1].tx;
			fib[i].ty = fib[i].fy + fib[i].tx - fib[i].fx;
		}
		if ((i - 2) % 4 == 3) {
			fib[i].fy = fib[i - 2].fy;
			fib[i].tx = fib[i - 1].fx;
			fib[i].ty = fib[i - 1].ty;
			fib[i].fx = fib[i].tx - (fib[i].ty - fib[i].fy);
		}
		if ((i - 2) % 4 == 0) {
			fib[i].fx = fib[i - 1].fx;
			fib[i].tx = fib[i - 2].tx;
			fib[i].ty = fib[i - 1].fy;
			fib[i].fy = fib[i].ty - (fib[i].tx - fib[i].fx);
		}
	}
	int T;
	cin >> T;
	while (T--) {
		ll x, y;
		cin >> x >> y;
		rep(i, 1, 92) {
			if (fib[i].fx <= x && x <= fib[i].tx && fib[i].fy <= y && y <= fib[i].ty) {
				ll ans = fib[i].tx - fib[i].fx;
				cout << ans << '\n';
				break;
			}
		}
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
