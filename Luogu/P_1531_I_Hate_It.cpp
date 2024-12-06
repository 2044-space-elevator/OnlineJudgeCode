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

int c[(int)2e5 + 5], arr[(int)2e5 + 5];
int lowbit(int x) { return x & -x; }
void update(int x, int v) {
	for (; x <= 2e5; x += (x & -x)) c[x] = max(c[x], v);
}

int query(int l, int r) {
	int mx = 0;
	while (l <= r) {
		while (r - lowbit(r) >= l) {
			mx = max(mx, c[r]);
			r -= lowbit(r);
		}
		int t = r;
		mx = max(mx, arr[r]);
		r--;
	}
	return mx;
}

main() {
//	int t; cin >> t; while (t--) solve();
	int n, m; cin >> n >> m;
	rep(i, 1, n) {int x; cin >> x; arr[i] = x; update(i, x);}
	while (m--) {
		char ch; cin >> ch;
		if (ch == 'Q') {
			int l, r; cin >> l >> r;
			cout << query(l, r) << endl;
		}
		else {
			int x, v; cin >> x >> v;
			arr[x] = max(arr[x], v);
			update(x, v);
		}
	}
	
	return 0;
}
