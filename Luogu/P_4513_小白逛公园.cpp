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

typedef unsigned long long ull;

void solve() {
	
}

const int N = 5E5 + 5;
int rl[N * 4], ll[N * 4], midval[N * 4], tr[N * 4];

struct seg {
	int rl, ll, midval, tr;
};

int n, m;
#define lc (2*p)
#define rc (2*p+1)

void pushUp(int p) {
	rl[p] = max(rl[rc], tr[rc] + rl[lc]);
	ll[p] = max(ll[lc], tr[lc] + ll[rc]);
	midval[p] = max(midval[lc], max(midval[rc], rl[lc] + ll[rc]));
	tr[p] = tr[lc] + tr[rc];
}


void modify(int p, int pl, int pr, int x, int k) {
	if (pl ==  pr) {
		rl[p] = ll[p] = midval[p] = tr[p] = k;
		return;
	}
	int mid = (pl + pr) / 2;
	if (x <= mid) modify(lc, pl, mid, x, k);
	else modify(rc, mid + 1, pr, x, k);
	pushUp(p);
}

seg query(int p, int pl, int pr, int l, int r) {
	if (l <= pl && pr <= r) {
		return {rl[p], ll[p], midval[p], tr[p]};
	}
	int mid = (pl + pr) / 2;
	seg ans = {-1005, -1005, -1005, -1005};
	seg tmp = {-1005, -1005, -1005, -1005};
	if (l <= mid) {
		ans = tmp = query(lc, pl, mid, l, r);	
	} if (r > mid) {
		seg tmp2 = query(rc, mid + 1, pr, l, r);
		ans.rl = max(tmp2.rl, tmp2.tr + tmp.rl);
		ans.ll = max(tmp.ll, tmp.tr + tmp2.ll);
		ans.midval = max(tmp.midval, max(tmp2.midval, tmp.rl + tmp2.ll));
		ans.tr = tmp.tr + tmp2.tr;
	}
	pushUp(p);
	return ans;
}

signed main() {
	cin >> n >> m;
	rep(i, 1, n) {
		int x, k;
		cin >> k;
		modify(1, 1, n, i, k);
	}
	while (m--) {
		int op, x, y;
		cin >> op >> x >> y;
		if (op == 1) {
			if (x > y) swap(x, y);
			cout << query(1, 1, n, x, y).midval << '\n';
		} else {
			modify(1, 1, n, x, y);
		}
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
