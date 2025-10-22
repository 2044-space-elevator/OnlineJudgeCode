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

const ll mod = 998244353;
const int N = 1E6 + 5;
vct<int> _[N];
vct<pair<int, int> > ord[N];
int fa[(int)1e6 + 5], dep[(int)1e6 + 5], dep_max[(int)1e6 + 5];
ll fac[(int)1e6 + 5], inv[(int)1e6 + 5];
vct<int> E[N];

void dfs(int u, int fa) {
    dep[u] = dep_max[u] = dep[fa] + 1;
    for (int v : E[u]) {
        if (v == fa) continue;
        dfs(v, u);
        dep_max[u] = max(dep_max[u], dep_max[v]);
    }
}
vector<int> t;

ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        ans %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ans;
}

ll A(ll m, ll nn) {
    if (nn < m) {
        return 0;
    }
    // ll ans = 1;
    // rep(i, 1, nn) {
    //     ans *= i;
    // }
    ll ans = fac[nn] * inv[nn - m];
    ans %= mod;
    return ans;
}


main() {
//	int t; cin >> t; while (t--) solve();
    int n, k;
    cin >> n >> k;
    rep(i, 2, n) {
        int f;
        cin >> f;
        fa[i] = f;
        E[f].push_back(i);
    }
    fac[0] = 1;
    inv[0] = 1;
    rep(i, 1, n) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= mod;
        inv[i] = qpow(fac[i], mod - 2);
    }
    dfs(1, 0);
    // cout << f_cnt;
    // cout << qpow(3152630, mod - 2) * 3 % mod;
    // cout << dep_cnt[1];
    // cout << t_cnt;
    ll ans = 0;
    rep(i, 1, n) {
        _[dep[i]].push_back(dep_max[i]);
    }
    rep(i, 1, n) {
        sort(_[i].begin(), _[i].end());
    }
    rep(i, 1, n) {
        if (_[i].size()) {
            ord[i].push_back({_[i][0], 1});
            repq(j, 1, _[i].size()) {
                if (_[i][j] == _[i][j - 1]) {
                    ord[i][ord[i].size() - 1].second++;
                } else {
                    ord[i].push_back({_[i][j], 1});
                }
            }
        }
    }
    rep(i, 2, n) {
        if (ord[i].size()) {
            reverse(ord[i].begin(), ord[i].end());
            int dayu = 0;
            for (auto v : ord[i]) {
                int times = v.second;
                if (times + dayu >= k + 1 && times >= 2) {
                    ans += (A(k - 1, dayu + times - 1) - A(k - 1, dayu) + mod) % mod * times % mod  ;
                    ans %= mod;
                }
                if (dayu == k - 1 && times >= 2) {
                    ans += (times * fac[k - 1]);
                    ans %= mod;
                }
                dayu += times;
            }
        }
    }
    cout << ans;
	return 0;
}
