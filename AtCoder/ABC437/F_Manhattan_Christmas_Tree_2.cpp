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
const int N = 2E5 + 5;
ll minm[N * 4], maxm[N * 4], minp[N * 4], maxp[N * 4];
int x[N], y[N];

#define lc (2*p)
#define rc (2*p+1)
void pushUp(int p) {
	minm[p] = min(minm[lc], minm[rc]);
	minp[p] = min(minp[lc], minp[rc]);
	maxm[p] = max(maxm[lc], maxm[rc]);
	maxp[p] = max(maxp[lc], maxp[rc]);
}

void update(int p, int pl, int pr, int x, ll mval, ll pval) {
	if (x == pl && pr == x) {
		minp[p] = pval;
		maxp[p] = pval;
		minm[p] = mval;
		maxm[p] = mval;
		return;
	}
	int mid = (pl + pr) / 2;
	if (x <= mid) update(lc, pl, mid, x, mval, pval);
	if (x > mid) update(rc, mid + 1, pr, x, mval, pval);
	pushUp(p);
}

struct ans {
	ll minp = INT_MAX, maxp = INT_MIN, minm = INT_MAX, maxm = INT_MIN;
};

ans query(int p, int pl, int pr, int l, int r) {
	if (l <= pl && pr <= r) {
		return {minp[p], maxp[p], minm[p], maxm[p]};
	}
	int mid = (pl + pr) / 2;
	ans tmp;
	if (l <= mid) {
		tmp = query(lc, pl, mid, l, r);
	} if (r > mid) {
		ans tmp2 = query(rc, mid + 1, pr, l, r);
		tmp.maxp = max(tmp2.maxp, tmp.maxp);
		tmp.minm = min(tmp2.minm, tmp.minm);
		tmp.maxm = max(tmp2.maxm, tmp.maxm);
		tmp.minp = min(tmp2.minp, tmp.minp);
	}
	pushUp(p);
	return tmp;
}


main() {
	rep(i, 1, 2e5 * 4) {
		minm[i] = minp[i] = INT_MAX;
		maxm[i] = maxp[i] = INT_MIN;
	}
	int n, q;
	cin >> n >> q;
	rep(i, 1, n) {
		cin >> x[i] >> y[i];
		update(1, 1, n, i, x[i] - y[i], x[i] + y[i]);
	}
	rep(i, 1, q) {
		int typ;
		cin >> typ;
		if (typ == 1) {
			int j, xt, yt;
			cin >> j >> xt >> yt;
			update(1, 1, n, j, xt - yt, xt + yt);
			x[j] = xt, y[j] = yt;
		} else {
			ll l, r, x, y;
			cin >> l >> r >> x >> y;
			ans tmp = query(1, 1, n, l, r);
			ll res = INT_MIN;
			res = max(res, x + y - tmp.minp);
			res = max(res, tmp.maxp - x - y);
			res = max(res, y - x + tmp.maxm);
			res = max(res, x - y - tmp.minm);
			cout << res << '\n'; 
		}
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
