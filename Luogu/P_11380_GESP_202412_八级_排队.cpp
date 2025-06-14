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

int n, m;
int out[(int)2e5 + 5];
int in[(int)2e5 + 5], fa[(int)2e5 + 5];
vct<int> E[(int)2e5 + 5];
bool vis[(int)2e5 + 5];

int find (int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge (int x, int y) {
    fa[find(x)] = find(y);
}

void dfs(int u) {
    if (vis[u]) {
        cout << 0;
        exit(0);
    }
    vis[u] = 1;
    if (!out[u]) return;
    dfs(out[u]);
}
main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m;
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        out[u] = v;
        in[v]++;
    }
    int cnt = 0;
    rep(i, 1, n) {
        if (!in[i] && !vis[i]) {
            cnt++, dfs(i);
        }
    }
    if (!cnt) cout << 0;
    else {
        ll ans = 1;
        rep(i, 1, cnt) { ans *= i; ans %= (int)(1e9 + 7); }
        cout << ans;
    } 

	return 0;
}
