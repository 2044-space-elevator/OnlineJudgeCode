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
const int N = 1e6 + 5;
struct edge {
  int u, v, w, next;
}E[N];
int cnt, head[N], n, dis[N];
bool vis[N];
void add(int u, int v, int w) {
  E[++cnt] = {u, v, w, head[u]};
  head[u] = cnt;
}

void spfa(int n, int s) {
  memset(dis, 127, sizeof dis);
  dis[s] = 0; vis[s] = 1;
  queue<int> q;
  q.push(s);
  while (q.size()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head[u]; i; i = E[i].next) {
      int v = E[i].v, w = E[i].w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        // 不需要判负环
        if (!vis[v]) {
          q.push(v);
          vis[v] = 1;
        }
      }
    }
  }
}

vct<int> lst;

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  rep(i,1, n) {
    int l, r;
    cin >> l >> r;
    add(i, l, -1);
    add(i, r, -1);
    if (!l && !r) {
      lst.push_back(i);
    }
  }
  int mx = 1e9;
  spfa(n, 1);
  for (int v : lst) {
    // 遍历叶节
    mx = min(mx, dis[v]);
  }
  cout << -mx + 1;
	return 0;
}
