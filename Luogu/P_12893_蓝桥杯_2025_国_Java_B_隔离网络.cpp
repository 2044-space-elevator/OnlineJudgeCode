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

int fa[(int)1e5 + 5], n, m, op[(int)1e5 + 5];
struct edge {
    int u, v;
};
vct<edge> E;
int find(int x) {
    return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    fa[find(x)] = find(y);
}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m;
    rep(i, 1, n) fa[i] = i;
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        E.push_back({u, v});
    }
    reverse(E.begin(), E.end());
    for (auto [u, v] : E) {
        int fu = find(u), fv = find(v);
        if (fu == fv) {
            op[fu]++;
        } else {
            merge(u, v);
            op[fv] = max(op[fu], op[fv]) + 1;
        }
    }
    cout << op[find(1)];
	return 0;
}
