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

const int N = 2E5 + 5;
#define int ll
int fa[N], w[N], sum[N], ans = 0, mx_s[N], mx_cd[N];
const int mod = 1e4 + 7;
vct<int> E[N];

void dfs(int u, int fat) {
    fa[u] = fat;
    vct<int> tmp;
    for (int v  : E[u]) {
        if (v == fat) continue;
        sum[u] += w[v];
        tmp.push_back(w[v]);
        dfs(v, u);
    }
    sort(tmp.begin(), tmp.end());
    if (tmp.size())
        mx_s[u] = tmp.back();
    if (tmp.size() > 1)
        mx_cd[u] = tmp[tmp.size() - 2];
}

main() {
//	int t; cin >> t; while (t--) solve();
    int n;
    cin >> n;
    repq(i, 1, n) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    rep(i, 1, n) {
        cin >> w[i];
    }
    dfs(1, 0);
    int a1 = 0;
    rep(i, 1, n) {
        int d1 = fa[fa[i]];
        if (d1) {
            a1 = max(a1, w[d1] * w[i]);
            ans = ans + 2 * (w[d1] % mod * w[i]) % mod;
            ans %= mod; 
        }
        if (fa[i]) {
            if (w[i] == mx_s[fa[i]]) {
                a1 = max(a1, mx_cd[fa[i]] * w[i]);
            } else {
                a1 = max(a1, mx_s[fa[i]] * w[i]);
            }
            int s1 = sum[fa[i]] - w[i];
            s1 %= mod;
            ans = ans + (w[i] % mod * s1) % mod;
            ans %= mod;
        }
    }
    cout << a1 << ' ' << ans;
	return 0;
}
