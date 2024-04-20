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

const int N = 510, M = 10010;
struct edge {
  int u, v, w;
}E[M];
int n, m, k;
int dis[N];
int path[N];

int bellman_ford() {
  memset(dis, 63, sizeof dis);
  dis[1] = 0;
  repq(i, 0, k) {
    memcpy(path, dis, sizeof dis);
    repq(j, 0, m) {
      auto e = E[j];
      dis[e.v] = min(dis[e.v], path[e.u] + e.v);
    }
  }
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m >> k;
  repq(i, 0, m) {
    int u, v, w;
    cin >> u >> v >> w;
    E[i] = {u, v, w};
  }
  bellman_ford();
  if (dis[n] > dis[505]) {
    cout << "impossible" << endl;
  } else
  cout << dis[n];
	return 0;
}
