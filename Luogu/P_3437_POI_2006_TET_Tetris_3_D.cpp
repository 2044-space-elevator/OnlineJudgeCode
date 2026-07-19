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

#define lu ((p << 2) + 1)
#define ld ((p << 2) + 2)
#define ru ((p << 2) + 3)
#define rd ((p << 2) + 4)

const int N = 1e3 + 5;
int tr[N * N * 16], lazy[N * N * 16];
int D, S, n;

void pushdown(int p, int pl, int pr, int pu, int pd) {
	if (lazy[p] == 0) return;
	tr[lu] = lazy[p];
	lazy[lu] = lazy[p];
	if (pl != pr) {
		tr[ru] = lazy[p];
		lazy[ru] = lazy[p];
		if (pu != pd) {
			tr[rd] = lazy[p];
			lazy[rd] = lazy[p];
		}
	}
	if (pu != pd) {
		tr[ld] = lazy[p] ;
		lazy[ld] = lazy[p];
	}
	lazy[p] = 0;
}

int query(int p, int pl, int pr, int pu, int pd, int l, int r, int u, int d) {
	if (l <= pl && pr <= r && u <= pu && pd <= d) {
		return tr[p];
	}
	pushdown(p, pl, pr, pu, pd);
	int ans = 0;
	int midx = (pl + pr) / 2, midy = (pu + pd) / 2;
	if (l <= midx) {
		if (u <= midy)
			ans = max(ans, query(lu, pl, midx, pu, midy, l, r, u, d));	
		if (d > midy && pu != pd)
			ans = max(ans, query(ld, pl, midx, midy + 1, pd, l, r, u, d));
	}
	if (r > midx && pl != pr) {
		if (u <= midy)
			ans = max(ans, query(ru, midx + 1, pr, pu, midy, l, r, u, d));
		if (d > midy && pu != pd)
			ans = max(ans, query(rd, midx + 1, pr, midy + 1, pd, l, r, u, d));
	}
	return ans;
}

void update(int p, int pl, int pr, int pu, int pd, int l, int r, int u, int d, int v) {
	if (l <= pl && pr <= r && u <= pu && pd <= d) { 
		tr[p] = v;
		lazy[p] = v;
		return;
	}
	pushdown(p, pl, pr, pu, pd);
	int midx = (pl + pr) / 2, midy = (pu + pd) / 2;
	if (l <= midx) {
		if (u <= midy) {
			update(lu, pl, midx, pu, midy, l, r, u, d, v);
			tr[p] = max(tr[lu], tr[p]);
		}
		if (d > midy && pu != pd) {
			update(ld, pl, midx, midy + 1, pd, l, r, u, d, v);
			tr[p] = max(tr[ld], tr[p]);
		}
	}
	if (r > midx && pl != pr) {
		if (u <= midy) {
			update(ru, midx + 1, pr, pu, midy, l, r, u, d, v);
			tr[p] = max(tr[ru], tr[p]);
		}
		if(d > midy && pu != pd) {
			update(rd, midx + 1, pr, midy + 1, pd, l, r, u, d, v);
			tr[p] = max(tr[rd], tr[p]);
		}
	}
}

main() {
//	int t; cin >> t; while (t--) solve();
scanf("%d%d%d", &D, &S, &n);
	rep(i, 1, n) {
		int d, s, h, x, y;
		scanf("%d%d%d%d%d", &d, &s, &h, &x, &y);
		int orig = query(1, 1, D, 1, S, x + 1, x + d, y + 1, y + s);
		orig += h;
		update(1, 1, D, 1, S, x + 1, x + d, y + 1, y + s, orig);
	}
	printf("%d\n", query(1, 1, D, 1, S, 1, D, 1, S));
	return 0;
}
