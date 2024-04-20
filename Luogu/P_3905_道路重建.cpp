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
const int N = 105, M = N * N * 2;

struct edge {
  int u, v, w, next;
}E[M];
int head[M], cnt, n, m, dis[M], s, t, sum[M], f[N][N];
bool vis[M];
bool allof[N][N];
void add(int u, int v, int w) {
  E[++cnt] = {u, v, w, head[u]};
  head[u] = cnt;
}
void spfa() {
  memset(dis, 63, sizeof dis);
  dis[s] = 0;
  vis[s] = 1;
  queue<int> q;
  q.push(s);
  while (q.size()) {
    int u = q.front(); q.pop();
    vis[u] = 0;
    for (int i = head[u]; i; i = E[i].next) {
      int v = E[i].v;
      if (dis[v] > dis[u] + E[i].w) {
        dis[v] = dis[u] + E[i].w;
        if (!vis[v]) {
          vis[v] = 1;
          q.push(v);
        }
      }
    }
  } 
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  rep(i, 1, m) {
    int u, v, w;
    cin >> u >> v >> w;
    f[u][v] = f[v][u] = w;
  }
  int t;
  cin >> t;
  while (t--) {
    int i, j;
    cin >> i >> j;
    allof[i][j] = allof[j][i] = 1;
  }
  rep(i, 1, n) {
    rep(j, 1, n) {
      if (allof[i][j]) {
        add(i, j, f[i][j]);
        add(j, i, f[i][j]);
        continue;
      }
      add(i, j, 0);
      add(j, i, 0);
    }
  }
  cin >> s >> t;
  spfa();
  cout << dis[t];
	return 0;
}
