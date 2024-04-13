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

const int MAXN = 1e5 + 5, MAXM = MAXN;

struct edge {
  int u, v, w, next;
}E[MAXM];
int head[MAXN], n, cnt, sum[MAXN], vis[MAXN];
void add(int u, int v, int w) {
  E[++cnt] = {u, v, w, head[u]};
  head[u] = cnt;
}
void dfs(int id, int val) {
  sum[id] = val;
  vis[id] = 1;
  for (int i = head[id]; i; i = E[i].next) {
    int v = E[i].v;
    if (vis[v]) {
      continue;
    }
    dfs(v, E[i].w ^ val);
  }
}

void input() {
  cin >> n;
  repq(i, 1, n) {
    int u, v, w;
    cin >> u >> v >> w;
    add(u, v, w);
    add(v, u, w);
  } 
  dfs(1, 0);
  int t;
  cin >> t;
  while (t--) {
    int u, v;
    cin >> u >> v;
    cout << (sum[u] ^ sum[v]) << endl;
  }

}

void solve() {
	
}


main() {
//	int t; cin >> t; while (t--) solve();
  input();
	return 0;
}
