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
const ll N = 10010, M = 105;

ll n, m, k, dis[N][M];
bool vis[N][M];
vct<pair<ll, ll>> E[N];
priority_queue<pair<ll, ll>, vct<pair<ll, ll>>, greater<pair<ll, ll>> > q;
void add(ll u, ll v, ll w) {
  E[u].push_back({v, w});
}

void dijkstra(ll s) {
  dis[s][0] = 0;
  q.push({0, s});
  while (!q.empty()) {
    ll p = q.top().first; ll u = q.top().second; 
    q.pop();
    if (vis[u][p % k]) {
      continue;
    } 
    vis[u][p % k] = true;
    for (auto d : E[u]) {
      ll w = d.second; ll v = d.first;
      ll t;
      if (p < w) t = ((w - p + k - 1) / k) * k + p;
      else  t = p;
      if (dis[v][(t + 1) % k] > t + 1) {
        dis[v][(t + 1) % k] = t + 1;
        q.push({t + 1, v});
      }
    
    }
  }
}


main() {
//	int t; cin >> t; while (t--) solve();
memset(dis, 0x3f, sizeof dis);
  cin >> n >> m >> k;
  rep(i, 1, m) {
    ll u, v, w; 
    cin >> u >> v >> w;
    add(u, v, w);
  } 
  dijkstra(1);
  if (!vis[n][0]) 
    cout << -1 << endl;
  else 
    cout << dis[n][0] << endl;
	return 0;
}
