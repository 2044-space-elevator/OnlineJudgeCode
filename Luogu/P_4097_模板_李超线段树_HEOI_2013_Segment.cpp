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

const int N = 1E5 + 5;

int cnt, n;

struct line {
	double k, b;
	double operator () (const int &val) {
		return k * val + b;
	}
} line[N];
const double eps = 1e-6;

int cmp(double x, double y) {
	if (x - y > eps) {
		return 1;
	}
	if (y - x > eps) {
		return -1;
	}
	return 0;
}

#define lc (2*p)
#define rc (2*p+1)
const int L = 40000;
int tr[L * 4];

void upd(int p, int pl, int pr, int u) {
	int &v = tr[p];
	int mid = (pl + pr) / 2;
	int cmid = cmp(line[u](mid), line[v](mid));
	if (cmid == 1 || (!cmid && u < v)) swap(u, v);
	int cl = cmp(line[u](pl), line[v](pl)), cr = cmp(line[u](pr), line[v](pr));
	if (cl == 1 || (!cl && u < v)) upd(lc, pl, mid, u);
	if (cr == 1 || (!cr && u < v)) upd(rc, mid + 1, pr, u);
}

void update(int p, int pl, int pr, int l, int r, int u) {
	if (l <= pl && pr <= r) {
		upd(p, pl, pr, u);
		return;
	}
	int mid = (pl + pr) / 2;
	if (l <= mid) update(lc, pl, mid, l, r, u);
	if (r > mid) update(rc, mid + 1, pr, l, r, u);
}

#define padi pair<double, int>

padi qmax(padi a, padi b) {
	int cm = cmp(a.first, b.first);
	if (cm == 1) {
		return a;
	} if (cm == -1) return b;
	if (a.second < b.second) return a;
	return b;
}

padi query(int p, int pl, int pr, int x) {
	int mid = (pl + pr) / 2;
	padi res = {line[tr[p]](x), tr[p]};
	if (pl == pr) return res;
	if (x <= mid) res = qmax(res, query(lc, pl, mid, x));
	else res = qmax(res, query(rc, mid + 1, pr, x));
	return res;
}
const int mod = 1e9;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int lastans = 0;
	rep(i, 1, n) {
		int op;
		cin >> op;
		if (op == 0) {
			int k;
			cin >> k;
			k = (k + lastans + 39988) % 39989 + 1;
			lastans = query(1, 1, L, k).second;
			cout << lastans << '\n';
		} else {
			int x0, y0, x1, y1;
			cin >> x0 >> y0 >> x1 >> y1;
			x0 = (x0 + lastans + 39988) % 39989 + 1;
			y0 = (y0 + lastans + mod - 1) % mod + 1;
			x1 = (x1 + lastans + 39988) % 39989 + 1;
			y1 = (y1 + lastans + mod - 1) % mod + 1;
			++cnt;
			if (x0 > x1) {
				swap(x0, x1);
				swap(y0, y1);
			}
			if (x0 == x1) {
				line[cnt].k = 0; line[cnt].b = max(y0, y1);
			} else {
				line[cnt].k = 1.0 * (y1 - y0) / (x1 - x0);
				line[cnt].b = y0 - line[cnt].k * x0;
			}
			update(1, 1, L, x0, x1, cnt);
		}
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
