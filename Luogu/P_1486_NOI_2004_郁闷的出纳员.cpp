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

const int N = 4E5 + 5;
int tr[N * 4];
int n, lm, mi;
const int delt = 2e5;

#define lc (2*p)
#define rc (2*p+1)

void update(int p, int pl, int pr, int x, int k) {
	if (pl == pr) {
		tr[p] += k;
		return;
	}
	int mid = (pl + pr) / 2;
	if (x <= mid) update(lc, pl, mid, x, k);
	else update(rc, mid + 1, pr, x, k);
	tr[p] = tr[lc] + tr[rc];
}

void clear(int p, int pl, int pr, int l, int r) {
	if (l <= pl && pr <= r) {
		tr[p] = 0;
	}
	if (pl == pr) return ;
	int mid = (pl + pr) / 2;
	if (l <= mid) clear(lc, pl, mid, l, r);
	if (r > mid) clear(rc, mid + 1, pr, l, r);
	tr[p] = tr[lc] + tr[rc];
}

int query(int p, int pl, int pr, int l, int r) {
	if (l <= pl && pr <= r) {
		return tr[p];
	}
	int mid = (pl + pr) / 2;
	ll ans = 0 ;
	if (l <= mid) ans += query(lc, pl, mid, l, r);
	if (r > mid) ans += query(rc, mid + 1, pr, l, r);
	tr[p] = tr[lc] + tr[rc];
	return ans; 
}

int rk(int p, int pl, int pr, int k) {
	if (pl == pr) {
		return pl;
	}
	int mid = (pl + pr) / 2;
	if (k <= tr[rc]) return rk(rc, mid + 1, pr, k);
	else return rk(lc, pl, mid, k - tr[rc]);
}



main() {
	cin >> n >> mi;
	lm = mi;
	mi += delt;
	int ans = 0;
	int bel = 0;
	rep(i, 1, n) {
		char c; int k;
		cin >> c >> k;
		// cout << c << ' ' << k << endl;
		if (c == 'I') {
			if (k < lm) {
				continue;
			}
			update(1, 0, N - 1, k - bel + delt, 1);
		} if (c == 'A') {
			mi -= k, bel += k;
		} if (c == 'S') {
			mi += k, bel -= k;
			if (mi >= 1 && query(1, 0, N - 1, 0, mi - 1)) {
				ans += query(1, 0, N - 1, 0, mi - 1);
				clear(1, 0, N - 1, 0, mi - 1);
			}
		} if (c == 'F') {
			if (k > query(1, 0, N - 1, mi, N - 1)) {
				cout << "-1\n";
			} else
			cout << rk(1, 0, N - 1, k) + bel - delt  << '\n';
		}	
	}
	cout << ans << '\n';
//	int t; cin >> t; while (t--) solve();
	return 0;
}
