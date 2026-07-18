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

const int N = 1E5 + 5;
struct line {
	ll x1, x2, y; int opt;
	bool operator < (const line &b) const {
		if (y == b.y)
			return opt > b.opt;
		return y < b.y;
	}
}seg[2 * N];

int n;
int x[N * 2], len[N * 16], tr[N * 16];
int cnt;

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

void update(int p, int pl, int pr, int l, int r, ll k) {
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

main() {
	cin >> n;
	rep(i ,1, n) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		seg[i] = {x1, x2, y1, 1};
		seg[i + n] = {x1, x2, y2, -1};
		x[i] = x1, x[i + n] = x2;
	}
	sort(x + 1, x + 2 * n + 1);
	sort(seg + 1, seg + 2 * n + 1);
	cnt = unique(x + 1, x + 2 * n + 1) - (x + 1);
	ll ans = 0;
	rep(i, 1, 2 * n) {
		if (i != 1) {
			ans += len[1] * (seg[i].y - seg[i - 1].y);
		}
		update(1, 1, cnt - 1, find(seg[i].x1), find(seg[i].x2) - 1, seg[i].opt);
	}
	cout << ans;

//	int t; cin >> t; while (t--) solve();
	return 0;
}
