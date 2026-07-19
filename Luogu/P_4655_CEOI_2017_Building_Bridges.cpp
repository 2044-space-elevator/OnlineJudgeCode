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

#define int ll
int n;
const int N = 1E5 + 5, M = 1E6 + 5;	
int h[N], s[N], tr[M * 4];

struct line {
	int k, b;
	int operator () (const int &x) {
		return k * x + b; 
	}
}lines[N];


int cmp(int a, int b) {
	if (a - b > 0) return 1;
	if (b - a > 0) return -1;
	return 0;
}

#define lc (2*p)
#define rc (2*p+1)
void upd(int p, int pl, int pr, int u) {
	int &v = tr[p];
	int mid = (pl + pr) >> 1;
	int cm1 = cmp(lines[u](mid), lines[v](mid));
	if (cm1 == -1 || (!cm1 && u < v)) swap(u, v);
	int cl = cmp(lines[u](pl), lines[v](pl));
	if (cl == -1 || (!cl && u < v)) upd(lc, pl, mid, u);
	int cr = cmp(lines[u](pr), lines[v](pr));
	if (cr == -1 || (!cr && u < v)) upd(rc, mid + 1, pr, u);
}

void update(int p, int pl, int pr, int l, int r, int u) {
	if (l <= pl && pr <= r) {
		upd(p, pl, pr, u);
		return ;
	}
	int mid = (pl + pr) >> 1;
	if (l <= mid) update(lc, pl, mid, l, r, u);
	if (r > mid) update(rc, mid + 1, pr, l, r, u);
}

int query(int p, int pl, int pr, int x) {
	int res = lines[tr[p]](x) ;
	if (pl == pr) return res;
	int mid = (pl + pr) >> 1;
	if (x <= mid) res = min(res, query(lc, pl, mid, x));
	if (x > mid) res = min(res, query(rc, mid + 1, pr, x));
	return res;	
}

int dp[N];

main() {
	lines[0].b = 1e18;
	cin >> n;
	rep(i, 1, n) {
		cin >> h[i];
	}
	rep(i, 1, n) {
		cin >> s[i];
		s[i] += s[i - 1];
	}
	lines[1].k = -2ll * h[1];
	lines[1].b = h[1] * h[1] - s[1];
	update(1, 0, M, 0, M, 1);
	rep(i, 2, n) {
		dp[i] = h[i] * h[i] + s[i - 1] + query(1, 0, M, h[i]);
		lines[i].k = -2ll * h[i];
		lines[i].b = h[i] * h[i] - s[i] + dp[i];
		update(1, 0, M, 0, M, i);
	}
	cout << dp[n];
//	int t; cin >> t; while (t--) solve();
	return 0;
}