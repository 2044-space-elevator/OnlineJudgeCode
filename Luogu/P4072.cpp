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

const int N = 3005;
int tr[N * 40];
int n, m;
int arr[N], dp[N];

#define lc (2*p)
#define rc (2*p+1)

struct line {
	int k, b;
	int operator () (const int &x) {
		return k * x + b;
	}
}lines[N];

void update(int p, int pl, int pr, int u) {
	int &v = tr[p];
	int mid = (pl + pr) >> 1;
	int cl = lines[u](mid), cr = lines[v](mid);	
	if (cl < cr) swap(u, v); 
	cl = lines[u](pl), cr = lines[v](pl);	
	if (cl < cr) update(lc, pl, mid, u);
	cl = lines[u](pr), cr = lines[v](pr);	
	if (cl < cr) update(rc, mid + 1, pr, u);
}

int query(int p, int pl, int pr, int x) {
	int ans = lines[tr[p]](x);
	if (pl == pr) return ans;
	int mid = (pl + pr) >> 1;
	if (x <= mid) ans = min(ans, query(lc, pl, mid, x));
	if (x > mid) ans = min(ans, query(rc, mid + 1, pr, x));
	return ans;
}


main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
		dp[i] = arr[i] * arr[i];
	}	
	lines[0].b = 2e9;
	rep(j, 2, m) {
		rep(i, 1, 4 * n) {
			tr[i] = 0;
		}
		rep(i, 1, n) {
			lines[i].k = -2ll * arr[i];
			lines[i].b = arr[i] * arr[i] + dp[i];	
			update(1, 1, arr[n], i);
			dp[i] = query(1, 1, arr[n], arr[i]) + arr[i] * arr[i];
		}
	}
	cout << m * dp[n] - arr[n] * arr[n];
//	int t; cin >> t; while (t--) solve();
	return 0;
}
