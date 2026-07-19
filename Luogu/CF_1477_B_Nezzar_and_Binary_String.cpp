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

const int N = 2e5 + 5;
int n, q;

#define lc (2*p)
#define rc (2*p+1)
int tr[N * 4], lazy[N * 4];
stg s, t;

void pushDown(int p, int pl, int pr) {
	if (lazy[p] == -1) return;
	int mid = (pl + pr) / 2;
	lazy[lc] = lazy[p];
	lazy[rc] = lazy[p];
	tr[lc] = (mid - pl + 1) * lazy[p];
	tr[rc] = (pr - mid) * lazy[p];
	lazy[p] = -1;
}

void update(int p, int pl, int pr, int l, int r, int k) {
	if (l <= pl && pr <= r) {
		tr[p] = k * (pr - pl  + 1);
		lazy[p] = k;
		return ;
	}
	pushDown(p, pl, pr);
	int mid = (pl + pr) / 2;
	if (l <= mid) update(lc, pl, mid, l, r, k);
	if (r > mid) update(rc, mid + 1, pr, l, r, k);
	tr[p] = tr[lc] + tr[rc];
}

int query(int p, int pl, int pr, int l, int r) {
	if (l <= pl && pr <= r) {
		return tr[p];
	}
	pushDown(p, pl, pr);
	int mid = (pl + pr) / 2;
	int ans = 0;
	if (l <= mid)  ans += query(lc, pl, mid, l, r);
	if (r > mid) ans += query(rc, mid + 1, pr, l, r);
	return ans;
}

void build(int p, int pl, int pr) {
	lazy[p] = -1;
	if (pl == pr) {
		tr[p] = t[pl] - '0';
		return;
	}
	int mid = (pl + pr) / 2;
	build(lc, pl, mid);
	build(rc, mid + 1, pr);
	tr[p] = tr[lc] + tr[rc];
}

pair<int, int> qu[N];

void solve() {
	cin >> n >> q;
	cin >> s >> t;
	s = ' ' + s; t = ' ' + t;
	build(1, 1, n);
	rep(i, 1, q) cin >> qu[i].first >> qu[i].second;
	rrep(i, 1, q) {
		int num1 = query(1, 1, n, qu[i].first, qu[i].second);
		int len = qu[i].second - qu[i].first + 1;
		if (num1 * 2 == len) {
			RTN
			return;
		} else if (num1 * 2 < len) {
			update(1, 1, n, qu[i].first, qu[i].second, 0);
		} else {
			update(1, 1, n, qu[i].first, qu[i].second, 1);
		}
	}
	rep(i, 1, n) {
		if (query(1, 1, n, i, i) != s[i] - '0') {
			RTN
			return;
		}
	}
	RTY
}




main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
