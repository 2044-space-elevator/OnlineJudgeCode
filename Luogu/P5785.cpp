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

int n, s;
const int N = 3E5 + 5;
ll sumt[N], sumv[N], lasv[N], dp[N], lsh[N];
int tr[N * 4], pos[N];
struct line {
	ll k, b;
	ll operator () (const ll &x) {
		return k * x + b;
	}	
}lines[N];
int cnt;

int cmp(ll a, ll b) {
	if (a > b) return 1;
	if (a == b) return 0;
	return -1;
}

#define lc (2*p)
#define rc (2*p+1)

void upd(int p, int pl, int pr, int u) {
	int &v = tr[p];
	int mid = (pl + pr) >> 1;
	ll cmid = cmp(lines[u](lsh[mid]), lines[v](lsh[mid]));
	if (cmid == -1 || (cmid == 0 && u < v)) swap(u, v);
	ll cl = cmp(lines[u](lsh[pl]), lines[v](lsh[pl])), cr = cmp(lines[u](lsh[pr]), lines[v](lsh[pr]));
	if (cl == -1 || (cl == 0 && u < v)) upd(lc, pl, mid, u);
	if (cr == -1 || (cr == 0 && u < v)) upd(rc, mid + 1, pr, u);
}

ll query(int p, int pl, int pr, ll x) {
	if (pl == pr) return lines[tr[p]](lsh[x]);
	ll ans = lines[tr[p]](lsh[x]);
	int mid = (pl + pr) >> 1;
	if (x <= mid) ans = min(ans, query(lc, pl, mid, x));
	else ans = min(ans, query(rc, mid + 1, pr, x));
	return ans;
}

main() {
	cin >> n >> s;
	rep(i, 1, n) {
		int t, c;
		cin >> t >> c;
		sumt[i] = sumt[i - 1] + t;
		sumv[i] = sumv[i - 1] + c;
		lsh[i] = sumt[i];
	}
	sort(lsh + 1, lsh + n + 1);
	cnt = unique(lsh + 1, lsh + n + 1) - (lsh + 1);
	rep(i, 1, n) lasv[i] = sumv[n] - sumv[i];
	lines[0] = {0, 1000000000000000000};
	upd(1, 1, cnt, 0);
	dp[1] = sumv[1] * sumt[1] + s * sumv[n]; lines[1] = {-sumv[1], dp[1] + s * lasv[1]};
	rep(i, 1, n) pos[i] = lower_bound(lsh + 1, lsh + cnt + 1, sumt[i]) - lsh;
	upd(1, 1, cnt, 1);
	rep(i, 2, n) {
		dp[i] = min(sumt[i] * sumv[i] + s * sumv[n], query(1, 1, cnt, pos[i]) + sumt[i] * sumv[i]);
		lines[i] = {-sumv[i], dp[i] + s * lasv[i]};
		upd(1, 1, cnt, i);
	}
	cout << dp[n];
//	int t; cin >> t; while (t--) solve();
	return 0;
}
