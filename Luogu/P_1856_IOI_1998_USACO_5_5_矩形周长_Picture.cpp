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

const int N = 5005;

struct segm {
	int x1, x2, y, opt;
	bool operator < (const segm &b) const {
		if (y == b.y) 
			return opt > b.opt;
		return y < b.y;
	}
}seg[N * 2];

int tr[N << 2], len[N << 2], cnt, x[N], n;

int find(int v) {
	return lower_bound(x + 1, x + cnt + 1, v) - x;
}

#define lc (2*p)
#define rc (2*p+1)
void pushUp(int pl, int pr, int p) {
	if (tr[p]) len[p] = x[pr + 1] - x[pl];
	else if (pl == pr) len[p] = 0;
	else len[p] = len[lc] + len[rc];
}

void update(int pl, int pr, int p, int l, int r, int k) {
	if (l <= pl && pr <= r) {
		tr[p] += k;
		pushUp(pl, pr, p);
		return;
	}
	int mid = (pl + pr) / 2;
	if (l <= mid) update(pl, mid, lc, l, r, k);	
	if (r > mid) update(mid + 1, pr, rc, l, r, k);
	pushUp(pl, pr, p);
}

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n;
	rep(i, 1, n) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += 10000, x2 += 10000, y1 += 10000, y2 += 10000;
		seg[i] = {x1, x2, y1, 1};
		seg[i + n] = {x1, x2, y2, -1};
		x[++cnt] = x1, x[++cnt] = x2;
	}
	sort(x + 1, x + cnt + 1);
	cnt = unique(x + 1, x + cnt + 1) - (x + 1);
	sort(seg + 1, seg + n * 2 + 1);
	int ans = 0, last = 0;
	for (int i = 1; i <= 2 * n; i++) {
		update(1, cnt - 1, 1, find(seg[i].x1), find(seg[i].x2) - 1, seg[i].opt);
		while (seg[i + 1].y == seg[i].y && seg[i + 1].opt == seg[i].opt) {
			i++;
			update(1, cnt - 1, 1, find(seg[i].x1), find(seg[i].x2) - 1, seg[i].opt);
		}
		ans += abs(last - len[1]);
		last = len[1];
		ans += tr[1] * 2 * (seg[i + 1].y - seg[i].y);
	}	
	cout << ans;
	return 0;
}
