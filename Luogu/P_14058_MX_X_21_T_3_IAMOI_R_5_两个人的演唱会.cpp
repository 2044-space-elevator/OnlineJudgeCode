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

const int N = 6E7 + 5;
ll n, m;
ll arr[N];
void solve() {
	cin >> n >> m;
	ll mx = 0, mi = 1e9;
	rep(i, 1, n) {
		cin >> arr[i];
		mx = max(mx, arr[i]);
		mi = min(mi, arr[i]);
	}
	rep(i, n + 1, 2 * n) {
		arr[i] = arr[i - n];
	}
	if (mx - mi <= m) {
		cout << "1\n";
		return;
	}	
	mx = arr[1], mi = arr[1];
	int ans = 1;
	rep(i, 2, 2 * n) {
		mx = max(mx, arr[i]);
		mi = min(mi, arr[i]);
		if (mx - mi > m) {
			ans++;
			mx = mi = arr[i];
		}
	}
	cout << ans / 2 << '\n';
}


main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t; while (t--) solve();
	return 0;
}
