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

ll calculate(ll x) {
    return x * (x  + 1) / 2;
}

int fa[(int)5e4 + 5], siz[(int)5e4 + 5], wei[(int)5e4 + 5], dep[(int)5e4 + 5];
vct<int> E[50005];
int ans = 114514;
int n;
void dfs(int u, int fat) {
    fa[u] = fat;
    siz[u] = 1;
    for (int v : E[u]) {
        if (v == fat) continue;
        dfs(v, u);
        siz[u] += siz[v];
        wei[u] = max(wei[u], siz[v]);
    }
    wei[u] = max(wei[u], n - siz[u]);
    if (wei[u] <= n / 2) {
        ans = min(ans, u);
    }        
}  

void ans2(int u, int fat) {
    dep[u] = dep[fat] + 1;
    for (int v : E[u]) {
        if (v== fat) continue;
        ans2(v, u);
    }
}


main() {
    cin >> n;
    repq(i, 1, n) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1, 0);
    dep[0] = -1;
    ans2(ans, 0);
    ll dis = 0;
    rep(i, 1, n) {
        dis += dep[i];
    }
    cout << ans << ' ' << dis;
//	int t; cin >> t; while (t--) solve();
	return 0;
}
