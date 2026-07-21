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
int n, k, siz[N];
int dp[N][105][2][2], g[105][2][2];
vct<int> E[N];

const int mod = 1e9 + 7;

int add(ll a, ll b) {
	ll tmp = a + b;
	tmp %= mod;
	return tmp;
}

void dfs(int u, int fat) {
	siz[u] = 1;
	dp[u][0][0][0] = dp[u][1][1][0] = 1;
	for (int v : E[u]) {
		if (v == fat) continue;
		dfs(v, u);
		rep(i, 0, (min(siz[u], k))) {
			repq(j, 0, 2) {
				repq(l, 0, 2) {
					g[i][j][l] = dp[u][i][j][l];
					dp[u][i][j][l] = 0;
				}
			}
		}
		rep(i, 0, min(siz[u], k)) {
			rep(j, 0, min(siz[v], k - i)) {
				dp[u][i + j][0][0] = add(g[i][0][0] * 1ll * dp[v][j][0][1] % mod, dp[u][i + j][0][0]);
				dp[u][i + j][1][0] = add(dp[u][i + j][1][0], 1ll * g[i][1][0] * add(dp[v][j][0][0], dp[v][j][0][1]) % mod);
				dp[u][i + j][0][1] = add(dp[u][i + j][0][1], add(g[i][0][1] * 1ll * add(dp[v][j][0][1], dp[v][j][1][1]) % mod, 
				g[i][0][0] * 1ll * dp[v][j][1][1] % mod));
				dp[u][i + j][1][1] = add(dp[u][i + j][1][1], 
    1ll * g[i][1][0] * add(dp[v][j][1][0], dp[v][j][1][1]) % mod);
dp[u][i + j][1][1] = add(dp[u][i + j][1][1], 
    1ll * g[i][1][1] * add(add(dp[v][j][0][0], dp[v][j][0][1]), add(dp[v][j][1][0], dp[v][j][1][1])) % mod);
			}
			siz[u] += siz[v];
		}
	}
}

main() {
	cin >> n >> k;
	repq(i, 1, n) {
		int x, y;
		cin >> x >> y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs(1, 0);
	cout << add(dp[1][k][0][1], dp[1][k][1][1]) << '\n';
	//	int t; cin >> t; while (t--) solve();
	return 0;
}
