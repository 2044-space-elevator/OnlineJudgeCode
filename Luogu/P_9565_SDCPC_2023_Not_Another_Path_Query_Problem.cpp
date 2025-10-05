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
const int N = 1e5 + 5;
int fa[N][62];
bool V_bit[N];

int find(int x, int j) {
    return fa[x][j] == x ? x : fa[x][j] = find(fa[x][j], j);
}

main() {
//	int t; cin >> t; while (t--) solve();
    int n, m, q, V;
    cin >> n >> m >> q >> V;
    rep(i, 0, 60) {
        if (V & (1ll << i)) {
            V_bit[i] = 1;
        }
    }
    rep(i, 1, n) {
        rep(j, 0, 61) {
            fa[i][j] = i;
        }
    }
    rep(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        rrep(j, 0, 60) {
            if (V_bit[j] && !(w & (1ll << j))) {
                break;
            }
            if (!V_bit[j] && (w & (1ll << j))) {
                fa[find(u, j)][j] = find(v, j);
            }
        }
        if ((w & V) >= V) {
            fa[find(u, 61)][61] = find(v, 61);
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        rrep(j, 0, 61) {
            if (find(u, j) == find(v, j)) {
                cout << "Yes\n";
                goto _;
            }
        } 
        cout << "No\n";
        _:;
    }
	return 0;
}
