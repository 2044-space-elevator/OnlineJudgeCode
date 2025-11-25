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

const int N = 2E5 + 5;
struct ZXTree {
	int lc, rc, val;
}tr[N << 6];

int n, rt[N], tot, len, arr[N], lsh[N], m, ql[N], qr[N], qk[N], qtyp[N];
int ltmp[N], rtmp[N], lcnt = 0, rcnt = 0;

int lowbit(int x) {
	return x & (-x);
}

int find(int val) {
	return lower_bound(lsh + 1, lsh + len + 1, val) - lsh;
}

void pushUp(int p) {
	tr[p].val = tr[tr[p].lc].val + tr[tr[p].rc].val;
}

void update(int &rt, int pl, int pr, int x, int val) {
	if (!rt) rt  = ++tot;
	if (pl == pr) {
		tr[rt].val += val;
		return;
	}
	int mid = (pl + pr) / 2;
	if (x <= mid) update(tr[rt].lc, pl, mid, x, val);
	else update(tr[rt].rc, mid + 1, pr, x, val);
	pushUp(rt);
}

void add(int x, int val) {
	for (int i = x; i <= n; i += lowbit(i)) update(rt[i], 1, len, arr[x], val);
}

int query_rnk(int l, int r, int k) {
	if (l == r) {
		return l;
	}
	int mid = (l + r) / 2;
	int sum = 0;
	rep(i, 1, rcnt) sum += tr[tr[rtmp[i]].lc].val;
	rep(i, 1, lcnt) sum -= tr[tr[ltmp[i]].lc].val;
	if (sum >= k) {
		rep(i, 1, rcnt) rtmp[i] = tr[rtmp[i]].lc;
		rep(i, 1, lcnt) ltmp[i] = tr[ltmp[i]].lc;
		return query_rnk(l, mid, k);
	} else {
		rep(i, 1, rcnt) rtmp[i] = tr[rtmp[i]].rc;
		rep(i, 1, lcnt) ltmp[i] = tr[ltmp[i]].rc;
		return query_rnk(mid + 1, r, k - sum);
	}
}

int query_num(int l, int r, int k) {
	if (l == r) {
		return 0;
	}
	int mid = (l + r) / 2;
	int sum = 0;
	rep(i, 1, rcnt) sum += tr[tr[rtmp[i]].lc].val;
	rep(i, 1, lcnt) sum -= tr[tr[ltmp[i]].lc].val;
	if (k <= mid) {
		rep(i, 1, rcnt) rtmp[i] = tr[rtmp[i]].lc;
		rep(i, 1, lcnt) ltmp[i] = tr[ltmp[i]].lc;
		return query_num(l, mid, k);
	} 
	else { 
		rep(i, 1, rcnt) rtmp[i] = tr[rtmp[i]].rc;
		rep(i, 1, lcnt) ltmp[i] = tr[ltmp[i]].rc;
		return sum + query_num(mid + 1, r, k); 
	} 
}

void init(int l, int r) {
	lcnt = rcnt = 0;
	for (int i = r; i; i -= lowbit(i)) rtmp[++rcnt] = rt[i];
	for (int i = l - 1; i; i -= lowbit(i)) ltmp[++lcnt] = rt[i];
}

int find_rnk(int l, int r, int k) {
	init(l, r);
	return query_rnk(1, len, k);
}
int find_num(int l, int r, int k) {
	init(l, r);
	return query_num(1, len, k) + 1;
}

int find_pri(int l, int r, int k) {
	int rk = find_num(l, r, k) - 1;
	if (rk == 0) return lsh[rk];
	int as = find_rnk(l, r, rk);
	return lsh[as];
}

int find_aft(int l, int r, int k) {
	if (k == len) return lsh[len + 1];
	int rk = find_num(l, r, k + 1);
	if (rk > r - l + 1) return lsh[len + 1];
	int as = find_rnk(l, r, rk);
	return lsh[as];
}

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> arr[i];
		lsh[++len] = arr[i];
	}
	rep(i, 1, m) {
		cin >> qtyp[i];
		if (qtyp[i] == 3) { cin >> ql[i] >> qk[i]; lsh[++len] = qk[i]; }
		else cin >> ql[i] >> qr[i] >> qk[i];
		if (qtyp[i] == 4 || qtyp[i] == 5) lsh[++len] = qk[i];
	}
	sort(lsh + 1, lsh + len + 1);
	len = unique(lsh + 1, lsh + len + 1) - (lsh + 1);
	rep(i, 1, n) arr[i] = find(arr[i]), add(i, 1);
	int inf = 2147483647;
	lsh[0] = -inf, lsh[len + 1] = inf;
	// cout << lsh[find_rnk(1, 3, 3)];
	rep(i, 1, m) {
		if (qtyp[i] == 1) cout << find_num(ql[i], qr[i], find(qk[i])) << '\n';
		if (qtyp[i] == 2) cout << lsh[find_rnk(ql[i], qr[i], qk[i])] << '\n';
		if (qtyp[i] == 3) {
			add(ql[i], -1);
			arr[ql[i]] = find(qk[i]);
			add(ql[i], 1);
		}
		if (qtyp[i] == 4) cout << find_pri(ql[i], qr[i], find(qk[i])) << '\n';
		if (qtyp[i] == 5) cout << find_aft(ql[i], qr[i], find(qk[i])) << '\n';
	}
	return 0;
}
