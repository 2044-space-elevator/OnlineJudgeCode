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

const int N = 1E5 + 5;
int fa[N][32], sum[N][32], w[N], n, s;
vct<int> E[N];
int ans = 0;

void dfs(int u, int sum) {
    if (!u) return;
    if (sum == s) {
        ans++;
        return;
    }
    if (sum > s) {
        return;
    }
    dfs(fa[u][0], sum + w[fa[u][0]]);
}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> s;
    rep(i, 1, n) {
        cin >> w[i];
    }
    repq(i, 1, n) {
        int u, v;
        cin >> u >> v;
        fa[v][0] = u;
    }
    rep(i, 1, n) {
        dfs(i, w[i]);
    }
    cout << ans;
	return 0;
}
