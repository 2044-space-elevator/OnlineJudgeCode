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

const int N = 2e5 + 5;

struct segment {
	ll x1, x2, y, opt;
	bool operator < (const segment &b) const {
		if (y == b.y) 
			return opt > b.opt;
		return y < b.y;
	}
}seg[(int)2e5 + 5];

#define lc (2*p)
#define rc (2*p+1)

ll cnt, tr[N << 4], n, len[N << 4], x[N];
ll ans = 0;

int find(ll v) {
	return lower_bound(x + 1, x + cnt + 1, v) - x;
}

void pushUp(int pl, int pr, int p) {
	if (tr[p]) len[p] = x[pr + 1] - x[pl];
	else if (pl == pr) len[p] = 0;
	else len[p] = len[lc] + len[rc];
}

void update(int pl, int pr, int l, int r, int p, int k) {
	if (l <= pl && pr <= r) {
		tr[p] += k;
		pushUp(pl, pr, p);
		return;
	}
	int mid = (pl + pr) / 2;
	if (l <= mid) update(pl, mid, l, r, lc, k);
	if (r > mid) update(mid + 1, pr, l, r, rc, k);
	pushUp(pl, pr, p);
}

main() {
	//	int t; cin >> t; while (t--) solve();
	cin >> n;
	rep(i, 1, n) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		seg[i] = {x1, x2, y1, 1};
		seg[i + n] = {x1, x2, y2, -1};
		x[++cnt] = 	x1, x[++cnt] = x2;
	}
	sort(seg + 1, seg + 2 * n + 1);
	sort(x + 1, x + cnt + 1);
	cnt = unique(x + 1, x + cnt + 1) - (x + 1);
	rep(i, 1, 2 * n) {
		if (i != 1) {
			ans += len[1] * (seg[i].y - seg[i - 1].y);
		}
		update(1, cnt - 1, find(seg[i].x1), find(seg[i].x2) - 1, 1, seg[i].opt);	
	}
	cout << ans;
	return 0;
}
