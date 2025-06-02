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
int dep[N], ans, ccolor;
bool color[N];
vct<int> E[N];

void dfs(int u, int fa) {
    for (int v : E[u]) {
        if (v == fa) continue;        
        dep[v] = dep[u] + 1;
        dfs(v, u);

    }
}

main() {
//	int t; cin >> t; while (t--) solve();
    int n;
    cin >> n;
    rep(i, 1, n) {
        cin >> color[i];
    }
    repq(i, 1, n) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1, 0) ;
    int res, maxe = 0;
    rep(i, 1, n) {
        if (dep[i] > maxe && color[i]) {
            maxe = dep[i], ans = i;
        }
    }
    dep[ans] = 0;
    dfs(ans, 0);
    maxe = 0;
    rep(i, 1, n) {
        if (dep[i] > maxe && !color[i]) {
            maxe = dep[i], res = i;
        }
    }

    dep[1] = 0;
    dfs(1, 0);
    int max1 = -1, max2 = -1, 
    maind1, maind2;
    rep(i, 1, n) {
        if (color[i] && max2 < dep[i]) {
            max2 = dep[i], maind2 = i;
        }
        if (!color[i] && max1 < dep[i]) {
            max1 = dep[i], maind1 = i;
        }
    } 
    dep[maind1] = 0;
    dfs(maind1, 0);
    int k1 = -1, k2 = -1;
    rep(i, 1, n ){
        if (color[i] && k1 < dep[i]) k1 = dep[i];
    }
    dep[maind2] = 0;
    dfs(maind2, 0);
    rep(i, 1, n ){
        if (!color[i] && k2 < dep[i]) k2 = dep[i];
    }

    cout << max(k1, k2);
	return 0;
}
