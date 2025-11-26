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

const int N = 1E6 + 5;
int n, L, A, B, dp[N], dif[N];

struct SegmentTree {
	int tr[N << 2];
	SegmentTree() {
		memset(tr, 63, sizeof tr);
	}
	#define lc (2 * p)
	#define rc (2 * p + 1)
	void pushUp(int p) {
		tr[p] = min(tr[lc], tr[rc]);
	}
	void update(int p, int pl, int pr, int x, int k) {
		if (pl == pr) {
			tr[p] = min(tr[p], k);
			return;
		}
		int mid = (pl + pr) / 2;
		if (x <= mid) update(lc, pl, mid, x, k);
		else update(rc, mid + 1, pr, x, k);
		pushUp(p);
	}
	int query(int p, int pl, int pr, int l, int r) {
		if (l <= pl && pr <= r) return tr[p];
		int mid = (pl + pr) / 2;
		int res = tr[0];
		if (l <= mid) res = min(res, query(lc, pl, mid, l, r));
		if (r > mid) res = min(res, query(rc, mid + 1, pr, l, r));
		pushUp(p);
		return res;
	}
	#undef lc
	#undef rc
}odd, even;

main() {
//	int t; cin >> t; while (t--) solve();
memset(dp, 63, sizeof dp);
	cin >> n >> L >> A >> B;
	rep(i, 1, n) {
		int fr, to;
		cin >> fr >> to;
		dif[fr + 1]++;
		dif[to]--;
	}
	rep(i, 1, L) dif[i] += dif[i - 1];
	even.update(1, 0, L, 0, 0);
	dp[0] = 0;
	rep(i, 0, L) {
		if (dif[i]) continue;
		if (i < 2 * A) continue;
		int lef = max(i - 2 * B, 0);
		int righ = max(i - 2 * A, 0);
		if (i % 2) {
			dp[i] = odd.query(1, 0, L, lef, righ) + 1;
			odd.update(1, 0, L, i, dp[i]);
		} else {
			dp[i] = even.query(1, 0, L, lef, righ) + 1;
			even.update(1, 0, L, i, dp[i]);
		}
	}
	if (dp[L] > L) cout << -1;
	else cout << dp[L];
	return 0;
}
