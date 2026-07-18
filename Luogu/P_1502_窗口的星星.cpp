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

const int N = 2E4 + 5;

#define int ll
int tr[N << 4], mx[N << 4], x[N];
int n, w, h, cnt;

#define lc (2*p)
#define rc (2*p+1)

struct line {
	int x1, x2, y, opt;
	bool operator < (const line &b) const {
		if (y == b.y) return opt > b.opt;
		return y < b.y;
	}
}seg[N];

void pushDown(int p) {
	mx[lc] += tr[p];
	mx[rc] += tr[p];
	tr[lc] += tr[p];
	tr[rc] += tr[p];
	tr[p] = 0;
}

int find (int val) {
	return lower_bound(x + 1, x + cnt + 1, val) - x;
}

void update(int p, int pl, int pr, int l, int r, int k) {
	if (l <= pl && pr <= r) {
		tr[p] += k;
		mx[p] += k;
		return;
	}
	int mid = (pl + pr) / 2;
	pushDown(p);
	if (l <= mid) update(lc, pl, mid, l, r, k);
	if (r > mid) update(rc, mid + 1, pr, l, r, k);
	mx[p] = max(mx[lc], mx[rc]);
}

void solve() {
	memset(tr, 0, sizeof tr);
	memset(mx, 0, sizeof mx);	
	cin >> n >> w >> h;
	rep(i, 1, n) {
		int xi, yi, li;
		cin >> xi >> yi >> li;
		x[i] = xi; x[i + n] = xi + w - 1;
		seg[i] = {xi, xi + w - 1, yi, li};
		seg[i + n] = {xi, xi + w - 1, yi + h - 1, -li};
	}
	sort(seg + 1, seg + 2 * n + 1);
	sort(x + 1, x + 2 * n + 1);
	cnt = unique(x + 1, x + 2 * n + 1) - x -  1;
	int ans = 0;
	rep(i, 1, 2 * n) {
		ans = max(ans, mx[1]);
		update(1, 1, cnt - 1, find(seg[i].x1), find(seg[i].x2), seg[i].opt);
	}
	cout << ans << '\n';
}


main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t; while (t--) solve();
	return 0;
}
