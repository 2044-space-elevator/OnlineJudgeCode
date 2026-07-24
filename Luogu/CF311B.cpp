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

const int N = 1e5 + 5;
int tr[N * 4], pos[N];
int n, m;
ll d[N], dp[2][N], p, a[N], h[N], t[N], s[N], dis[N], lsh[N];
int cnt;

#define lc (2*p)
#define rc (2*p+1)

int find(ll val) {
	return lower_bound(lsh + 1, lsh + cnt + 1, val) - lsh;
}

struct line {
	ll k, b;
	ll operator () (const ll &x) {
		return k * x + b;
	}
}lines[N];

void update(int p, int pl, int pr, int u) {
	int &v = tr[p];
	if (pl == pr) {
		if (lines[u](lsh[pl]) < lines[v](lsh[pl])) {
			v = u;
		}
		return;
	}
	int mid = (pl + pr) >> 1;
	ll cl = lines[u](lsh[mid]), cr = lines[v](lsh[mid]);	
	if (cl < cr) swap(u, v); 
	cl = lines[u](lsh[pl]), cr = lines[v](lsh[pl]);	
	if (cl < cr) update(lc, pl, mid, u);
	cl = lines[u](lsh[pr]), cr = lines[v](lsh[pr]);	
	if (cl < cr) update(rc, mid + 1, pr, u);
}

ll query(int p, int pl, int pr, int x) {
	ll ans = lines[tr[p]](lsh[x]);
	if (pl == pr) return ans;
	int mid = (pl + pr) >> 1;
	if (x <= mid) ans = min(ans, query(lc, pl, mid, x));
	if (x > mid) ans = min(ans, query(rc, mid + 1, pr, x));
	return ans;
}


signed main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m >> p;
	rep(i, 2, n) cin >> d[i];
	rep(i, 1, m) cin >> h[i] >> t[i];
	rep(i, 1, n) {
		dis[i] = dis[i - 1] + d[i];
	}
	rep(i, 1, m) a[i] = t[i] - dis[h[i]];
	sort(a + 1, a + m + 1);
	rep(i, 1, m) lsh[++cnt] = a[i];
	sort(lsh + 1, lsh + m + 1);
	cnt = unique(lsh + 1, lsh + m + 1) - (lsh + 1);
	rep(i, 1, m) pos[i] = find(a[i]);
	rep(i, 1, m) s[i] += s[i - 1] + a[i];
	rep(i, 1, m) {
		dp[1][i] = i  * a[i] - s[i];
	}
	rep(j, 2, p) {
		rep(i, 1, 4 * cnt) tr[i]= 0;
		rep(i, 1, m) {
			lines[i - 1].k = -(i - 1); lines[i - 1].b = s[i - 1] + dp[(j - 1) & 1][i - 1];
			update(1, 1, cnt, i - 1);
			dp[j & 1][i] = query(1, 1, cnt, pos[i]) + i * a[i] - s[i];
		}
	}
	cout << dp[p & 1][m];
//	int t; cin >> t; while (t--) solve();
	return 0;
}
