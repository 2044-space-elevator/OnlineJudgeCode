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

#define y1 y111
ll ans = 0;
const int N = 1e4 + 5;
int x[N];
int x1[N], y1[N], x2[N], y2[N], cnt;
ll len[N << 4], tr[N << 4];
int n;
struct line {
	int x1, x2, y, opt;
	bool operator < (const line& b) const {
		if (y == b.y) {
			return opt > b.opt;
		}
		return y < b.y;
	}
}seg[N];

int find(int val) {
	return lower_bound(x + 1, x + cnt + 1, val) - x;
}

#define lc (2*p)
#define rc (2*p+1)

void pushUp(int p, int pl, int pr) {
	if (tr[p]) len[p] = x[pr + 1] - x[pl];
	else if (pl == pr) len[p] = 0;
	else len[p] = len[lc] + len[rc];
}

void update(int p, int pl, int pr, int l, int r, int k) {
	if (l <= pl && pr <= r) {
		tr[p] += k;
		pushUp(p, pl, pr);
		return;
	}
	int mid = (pl + pr) / 2;
	if (l <= mid) update(lc, pl, mid, l, r, k);
	if (r > mid) update(rc, mid + 1, pr, l, r, k);
	pushUp(p, pl, pr);
}

void solve() {
	memset(tr, 0, sizeof tr);
	memset(len, 0, sizeof len);
	sort(seg + 1, seg + 2 * n + 1);
	sort(x + 1, x + 2 * n + 1);
	cnt = unique(x + 1, x + 2 * n + 1) - (x + 1);
	int last = 0;
	rep(i, 1, 2 * n) {
		update(1, 1, cnt - 1, find(seg[i].x1), find(seg[i].x2) - 1, seg[i].opt);
		ans += abs(len[1] - last);
		last = len[1];
	}
}


main() {
	cin >> n;
	rep(i, 1, n) {
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	}
	rep(i, 1, n) {
		x[i] = x1[i]; x[i + n] = x2[i];
		seg[i] = {x1[i], x2[i], y1[i], 1};
		seg[i + n] = {x1[i], x2[i], y2[i], -1};
	}
	solve();
	rep(i, 1, n) {
		x[i] = y1[i]; x[i + n] = y2[i];
		seg[i] = {y1[i], y2[i], x1[i], 1};
		seg[i + n] = {y1[i], y2[i], x2[i], -1};
	}
	solve();
	cout << ans << '\n';
//	int t; cin >> t; while (t--) solve();
	return 0;
}
