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


#define int ll
const int N = 1E5 + 5;
bool vis[N];
int fa[N];

int find(int x) {
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    fa[fx] = fy;
}

struct edge {
    int u, v, w;
};

vct<edge> E;

bool cmp(edge a, edge b) {
    return a.w > b.w;
}

main() {
//	int t; cin >> t; while (t--) solve();
    int n, k;
    cin >> n >> k;
    rep(i, 1, k) {
        int x;
        cin >> x;
        vis[x] = 1;
    }
    rep(i, 1, n) fa[i] = i;
    ll ans = 0;
    repq(i, 1, n) {
        int u, v, w;
        cin >> u >> v >> w;
        ans += w;
        E.push_back({u, v, w});
    }
    sort(E.begin(), E.end(), cmp);

    for (auto tmp : E) {
        int u = tmp.u, v = tmp.v, w = tmp.w;
        int fu = find(u), fv = find(v);
        if (fu == fv) continue ;
        if (vis[fu] && vis[fv]) continue;
        if (vis[fu] || vis[fv]) {
            vis[fu] = 1, vis[fv] = 1;
        }
        ans -= w;
        merge(u, v);
    }
    cout << ans;
	return 0;
}
