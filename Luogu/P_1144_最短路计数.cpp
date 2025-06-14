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

const int N = 1e6 + 6;
int coun[N], dis[N];
bool vis[N];
vct<int> E[N];
const int mod = 1e5 + 3;

struct node {
    int u, dis;
    bool operator > (const node &b) const {
        return dis > b.dis;
    } 
};

priority_queue<node, vector<node>, greater<node> > q;

void dijkstra() {
    memset(dis, 127, sizeof dis);
    q.push({1, 0});
    dis[1] = 0;
    coun[1] =1;
    while (q.size()) {
        int u = q.top().u, d = q.top().dis;
        q.pop();
        for (int v : E[u]) {
            if (dis[v] > d + 1) {
                dis[v] = d + 1;
                coun[v] = (coun[u]);
                q.push({v, d + 1});
            } else if (dis[v] == d + 1) coun[v] = (coun[u] + coun[v]) % mod;
        }
    }
}

main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dijkstra();
    rep(i, 1, n) {
        cout << coun[i] << '\n';
    }
//	int t; cin >> t; while (t--) solve();
	return 0;
}
