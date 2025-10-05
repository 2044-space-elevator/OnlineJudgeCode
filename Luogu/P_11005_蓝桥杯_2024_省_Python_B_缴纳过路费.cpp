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
int fa[N], siz[N];

struct edge {
    int u, v, w;
};

vct<edge> E;
ll ans = 0;

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

main() {
//	int t; cin >> t; while (t--) solve();
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    rep(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        E.push_back({u, v, w});
    }
    rep(i, 1, n) {
        fa[i] = i;
        siz[i] = 1;
    }
    sort(E.begin(), E.end(), cmp);
    for (auto tmp : E) {
        int u = tmp.u, v = tmp.v, w = tmp.w;
        int fu = find(u), fv = find(v);
        if (fu == fv) {
            continue;
        }
        if (l <= w && w <= r) {
            ans = ans + (siz[fu] * siz[fv]);
        }
        siz[fv] += siz[fu];
        fa[fu] = fv;
    }
    cout << ans;
	return 0;
}
