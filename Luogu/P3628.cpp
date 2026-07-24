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

struct line {
	int k; ll b;
	ll operator	() (const ll & x) {
		return k * x + b;
	}
}lines[N];


int n, tr[N * 4], pos[N];
ll lsh[N], dp[N];
ll a, b, c;
ll arr[N];
int cnt ;

#define lc ((p<<1))
#define rc ((p<<1)|1)
void update(int p, int pl, int pr, int u) {
	int &v = tr[p];
	int mid = (pl + pr) >> 1;
	ll mcu = lines[u](lsh[mid]), mcv = lines[v](lsh[mid]);
	if (mcu > mcv || (mcu == mcv && u < v)) swap(u, v);
	mcu = lines[u](lsh[pl]), mcv = lines[v](lsh[pl]);
	if (mcu > mcv || (mcu == mcv && u < v)) update(lc, pl, mid, u);
	mcu = lines[u](lsh[pr]), mcv = lines[v](lsh[pr]);
	if (mcu > mcv || (mcu == mcv && u < v)) update(rc, mid + 1, pr, u);
}

ll query(int p, int pl, int pr, int x) {
	ll ans = lines[tr[p]](lsh[x]);
	int mid = (pl + pr) >> 1;
	if (pl == pr) return ans;
	if (x <= mid) ans = max(ans, query(lc, pl, mid, x));
	else ans = max(ans, query(rc, mid + 1, pr, x));
	return ans;
}



main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> a >> b >> c;
	rep(i, 1, n) {
		cin >> arr[i];	
		arr[i] += arr[i - 1];
		lsh[i] = arr[i]; 
	}
	sort(lsh + 1, lsh + n + 1);
	cnt = unique(lsh + 1, lsh + n + 1) - (lsh + 1);
	rep(i, 1, n) {
		pos[i] = lower_bound(lsh + 1, lsh + cnt + 1, arr[i]) - lsh;
	}
	lines[0] = {0, 0};
	update(1, 0, cnt, 0);
	rep(i, 1, n) {
		dp[i] = query(1, 0, cnt, pos[i]) + b * arr[i] + a * arr[i] * arr[i] + c;
		lines[i].k = -2ll * a * arr[i];
		lines[i].b = a * arr[i] * arr[i] + dp[i] - b * arr[i];
		update(1, 0, cnt, i);
	}
	cout << dp[n];
	//	int t; cin >> t; while (t--) solve();
	return 0;
}
