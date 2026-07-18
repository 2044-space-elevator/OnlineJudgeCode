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
const int N = 1e5 + 5;
ll tr[N * 4], ma[N * 4], arr[N]; 

#define lc (2 * p)
#define rc (2 * p + 1)

void pushUp(int p) {
	tr[p] = tr[lc] + tr[rc];
	ma[p] = max(ma[lc], ma[rc]);
}

void build(int p, int pl, int pr) {
	if (pl == pr) {
		tr[p] = ma[p] = arr[pl];
		return;
	}
	int mid = (pl + pr) / 2;
	build(lc, pl, mid);
	build(rc, mid + 1, pr);
    pushUp(p);
}

void update(int p, int pl, int pr, int l, int r) {
	if (pl == pr) {
		tr[p] = sqrt(tr[p]);
		ma[p] = sqrt(ma[p]);
		return ;
	}
	int mid = (pl + pr) / 2;
	if (l <= mid && ma[lc] > 1)
		update(lc, pl, mid, l, r);
	if (r > mid && ma[rc] > 1)
		update(rc, mid + 1, pr, l, r);
	pushUp(p);
}

ll query(int p, int pl, int pr, int l, int r) {
    if (l <= pl && pr <= r) return tr[p];
	int mid = (pl + pr) / 2;
	ll ans = 0;
	if (l <= mid) {
		ans += query(lc, pl, mid, l, r);
	}
	if (r > mid) {
		ans += query(rc, mid + 1, pr, l, r);
	};
	pushUp(p);
	return ans;
}


main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n) {
		cin >> arr[i];	
	}
	build(1, 1, n);
	int m; cin >> m;
	while (m--) {
		int op, x, y;
		cin >> op >> x >> y;
		if (x > y) swap(x, y);
		if (op == 0) {
			update(1, 1, n, x, y);	
		} else {
			cout << query(1, 1, n, x, y) << '\n';
		}
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
