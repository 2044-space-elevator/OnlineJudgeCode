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

const int INF = 1e9;
const int N = 5550, M = 2E5 + 6;

int n, m, head[N], gap[N], dep[N], cnt = 0, s, t;
bool vis[N];
int ans = 0;
struct edge {
  int u, v, w, next;
}E[M], EOP[M - 1];
void add_init(int u, int v, int w) {
  E[++cnt] = {u, v, w, head[u]};
  head[u] = cnt;
}

void add(int u, int v, int w) {
  add_init(u, v, w);
  add_init(v, u, 0);
}

namespace Dinic_Space {
  #define E EOP
  bool bfs() {
    queue<int> q;
    memset(dep, 0, sizeof dep);
    dep[s] = 1;
    q.push(s);
    vis[s] = 1;
    while (q.size()) {
      int u = q.front(); q.pop();
      vis[u] = 0;
      for (int i = head[u]; i; i = E[i].next) {
        if (E[i].w && dep[E[i].v] == 0) {
          dep[E[i].v] = dep[u] + 1;
          if (vis[E[i].v]) continue;
          q.push(E[i].v);
          if (E[i].v == t) {
            return 1;
          }
        }
      }
    }
    return 0;
  }
  int dfs(int u, int dis) {
    if (u == t) {
      return dis;
    }
    for (int i = head[u]; i; i = E[i].next) {
      if (dep[E[i].v] == dep[u] + 1 && E[i].w) {
        int mi = dfs(E[i].v, min(dis, E[i].w));
        if (mi > 0) {
          E[i].w -= mi;
          E[i ^ 1].w += mi;
          return mi;
        }
      }
    }
    return 0;
  }
  int Dinic() {
    int ans = 0;
    while (bfs()) {
      int tmp;
      while (tmp = dfs(s, INF)) {
        ans += tmp;
      }
    }
    return ans;
  }
  #undef E
}
using namespace Dinic_Space;
void solve() {
  
}


main() {
  while (cin >> n >> m) {
    cnt = 1; memset(head, 0, sizeof head);
    ans = n; // 答案最多只有 n 个 
    for (int i = 1; i <= m; i++) {
      int u, v;
      char ch;
      cin >> ch >> u >> ch >> v >> ch;
      // 恶心的UVA式输入
      // 0 开始真的很难受……
      u++;
      v++;
      add(u + n, v, INF);
      add(v + n, u, INF);
      // +n 以区分出点、入点
    }
    rep (i, 1, n) {
      add(i, i + n, 1);
    }
    for (int i = 2; i <= n; i++) {
      s = i  +n; t = 1;
      memcpy(EOP, E, sizeof EOP);
      ans = min(ans, Dinic());
    }
    cout << ans << endl;
  }
	return 0;
}
