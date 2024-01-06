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

int arr[1005][1005], fa[10005];

namespace BingChaJi {
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    void merge(int x, int y) {
        fa[find(x)] = find(y);
    }
}

using namespace BingChaJi;

struct edge {
    int u, v, w;
};

vector<edge> E;

bool cmp(edge a, edge b) { return a.w < b.w; }

main() {
//	int t; cin >> t; while (t--) solve();
    int n;
    cin >> n;
    rep(i, 1, n) {
        rep(j, 1, n) {
            int x;
            cin >> x;
            E.push_back({i, j, x});
        }
    } 
    rep(i, 1, n * n) { fa[i] = i; }
    sort(E.begin(), E.end(), cmp);
    int cnt = n - 1;
    int ans = 0;
    for (auto [u, v, w] : E) {
        if (cnt == 0) {
            cout << ans;
            return 0;
        }
        if (find(u) != find(v)) {
            merge(u, v);
            cnt--;
            ans += w;
        }
    }
	return 0;
}
