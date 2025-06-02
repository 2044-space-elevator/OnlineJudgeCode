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

const int mod = 1e9 + 7;

ll n, k, h[505], fac[(int)1e6 + 5], inv[(int)1e6 + 5], hei[505], wei[505], dp[505][505], f[505][505];
ll qpow(ll base, ll exp) {
    ll ans = 1;
    while (exp) {
        if (exp & 1) ans *= base;
        ans %= mod;
        exp >>= 1;
        base *= base;
        base %= mod;
    }
    return ans;
}

struct tree {
    int l = 0, r = 0;
}T[505];
#define lc T[u].l
#define rc T[u].r
int build(int l, int r) {
    if (l > r) return 0;
    int u = min_element(h + l, h + r + 1) - h;
    lc = build(l, u - 1);
    rc = build(u + 1, r);
    hei[lc] = h[lc] - h[u];
    hei[rc] = h[rc] - h[u];
    wei[u] = r - l + 1;
    return u;
}

ll C(ll x, ll y) {
    if (x < 0 || y < 0 || x < y) return 0;
    return fac[x] * inv[y] % mod * inv[x - y] % mod;
}

void dfs(int u) {
    f[u][0] = dp[u][0] = 1;
    if (!u) return;
    dfs(lc);
    dfs(rc);
    rep(i, 1, k) {
        rep(j, 0, i) {
            dp[u][i] += f[lc][j] * f[rc][i - j] % mod;
            dp[u][i] %= mod;
        }
    }
    rep(i, 1, k) {
        rep(j, 0, i) {
            f[u][i] += C(hei[u], i - j) * C(wei[u] - j, i - j) % mod * fac[i - j] % mod * dp[u][j] % mod;
            f[u][i] %= mod;
        }
    }
}
main() {
//	int t; cin >> t; while (t--) solve();
    // memset(dp, 1, sizeof dp);
    // memset(f, 1, sizeof f);
    cin >> n >> k;
    rep(i, 1, n) {
        cin >> h[i];
    }
    fac[0] = 1;
    inv[0] = 1;
    rep(i, 1, 1e6) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= mod;
        inv[i] = qpow(fac[i], mod - 2);
    }
    // rep(i, 1, )
    int root = build(1, n);
    hei[root] = h[root];
    //cout << wei[root];
    dfs(root);
    cout << f[root][k];
	return 0;
}
