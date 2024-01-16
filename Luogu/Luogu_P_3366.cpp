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

struct edge {
    int u, v, w;
};

vector<edge> E;
bool cmp(edge a, edge b) { return a.w < b.w; }
int fa[(int)2e5 + 5];

void add(int x, int y)  { fa[x] = y; }
int find(int x)         { return x != fa[x] ? fa[x] = find(fa[x]) : x; } 
void init()             { rep(i, 1, 2e5) fa[i] = i; }

main() {
//	int t; cin >> t; while (t--) solve();
    int n, m;
    cin >> n >> m;
    rep(i, 1, m) {
        int u, v, w; cin >> u >> v >> w;
        E.push_back({u, v, w});
    }
    init(); sort(E.begin(), E.end(), cmp);
    int cnt = n - 1;
    ll ans = 0;
    for (auto [u, v, w] : E) {
        if (cnt == 0) {
            cout << ans; return 0;
        }
        if (find(u) == find(v)) {
            continue;
        }
        if (find(u) != find(v)) {
            cnt--;
            ans += w;
            add(fa[u], fa[v]);
        }
    }
    if (!cnt) {
        cout << ans;
    } else
    cout << "orz";
    
	return 0;
}
