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

int dfn[100006], arr[100006], c[100005], siz[100005];
int n;
vct<int> E[100005];
int cnt = 0;

int lowbit(int x) { return x & -x; }

void update(int x, int val) {
    for (int i = x; i <= n; i += lowbit(i)) c[i] ^= val;
}

int query(int ind) {
    int ans = 0;
    for (int i = ind; i; i -= lowbit(i)) ans ^= c[i];
    return ans;
}

void dfs(int u, int fa) {
    dfn[u] = ++cnt;
    siz[u] = 1;
    for (int v : E[u]) {
        if (v == fa) continue;
        dfs(v, u);
        siz[u] += siz[v];
    }
}

main() {
//	int t; cin >> t; while (t--) solve();
    int q;
    cin >> n >> q;
    rep(i, 1, n) cin >> arr[i];
    repq(i, 1, n) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1, 0);
    rep(i, 1, n) {
        update(dfn[i], arr[i]);
    }
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            update(dfn[x], arr[x]);
            update(dfn[x], y);
            arr[x] = y;
        } else {
            int x;
            cin >> x;
            cout << (query(dfn[x] + siz[x] - 1) ^ query(dfn[x] - 1)) << endl;
        }
    }
	return 0;
}
