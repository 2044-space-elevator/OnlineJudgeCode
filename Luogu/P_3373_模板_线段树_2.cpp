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

int n, q;
ll m;
const int N = 1e5 + 5;
ll mul[N * 4], add[N * 4], tr[N * 4];

#define lc (2*p)
#define rc (2*p+1)

void pushUp(int p) {
	tr[p] = tr[lc] + tr[rc];
}

void pushDown(int p, int pl, int pr) {
	int mid = (pl + pr) >> 1;
	tr[lc] = (tr[lc] * mul[p] % m + add[p] * (mid - pl + 1) % m) % m;
	add[lc] = (add[lc] * mul[p] % m + add[p]) % m;
	mul[lc] = mul[lc] * mul[p] % m;

	tr[rc] = (tr[rc] * mul[p] % m + add[p] * (pr - mid) % m) % m;
	add[rc] = (add[rc] * mul[p] % m + add[p]) % m;
	mul[rc] = mul[rc] * mul[p] % m;

	add[p] = 0;
	mul[p] = 1;
}

void updadd(int p, int pl, int pr, int l, int r, ll k) {
	if (l <= pl && pr <= r) {
		tr[p] = (tr[p] + (pr - pl + 1) * k) % m;
		add[p] = (add[p] + k) % m;
		return;
	}
	int mid = (pl + pr) >> 1;
	pushDown(p, pl, pr);
	if (l <= mid) updadd(lc, pl, mid, l, r, k);
	if (r > mid) updadd(rc, mid + 1, pr, l, r, k);
	pushUp(p);
	
}

void updmul(int p, int pl, int pr, int l, int r, ll k) {
	if (l <= pl && pr <= r) {
		add[p] = add[p] * k % m;
		mul[p] = mul[p] * k % m; 
		tr[p] = tr[p] * k % m;
		return; 
	}
	int mid = (pl + pr) >> 1;
	pushDown(p, pl, pr);
	if (l <= mid) updmul(lc, pl, mid, l, r, k);
	if (r > mid) updmul(rc, mid + 1, pr, l, r, k);
	pushUp(p);
}

ll query(int p, int pl, int pr, int l, int r) {
	if (l <= pl && pr <= r) {
		return tr[p];
	}
	int mid = (pl + pr) >> 1;
	pushDown(p, pl, pr);
	ll ans = 0;
	if (l <= mid) ans = (ans + query(lc, pl, mid, l, r)) % m;
	if (r > mid) ans = (ans + query(rc, mid + 1, pr, l, r)) % m;
	pushUp(p);
	return ans;
}

main() {
	cin >> n >> q >> m;
	rep(i, 1, n) {
		ll x;
		cin >> x;
		x %= m;
		updadd(1, 1, n, i, i, x);
	}
	rep(i, 1, n * 4) {
		mul[i] = 1;
	}

	while (q--) {
		int op, x, y;
		cin >> op >> x >> y;
		if (op == 1) {
			ll k;
			cin >> k;
			k %= m;
			updmul(1, 1, n, x, y, k);
		} if (op == 2) {
			ll k;
			cin >> k;
			k %= m;
			updadd(1, 1, n, x, y, k);
		} if (op == 3) {
			cout << query(1, 1, n, x, y) << '\n';
		}
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
