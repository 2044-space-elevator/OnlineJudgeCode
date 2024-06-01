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
const int N = 1505, M = 5e4 + 5;
int head[N], cnt, indegree[N];
struct edge {
  int u, v, w, next;
}E[M];
void add(int u, int v, int w) {
  E[++cnt] = {u, v, w, head[u]};
  head[u] = cnt;
}

main() {
//	int t; cin >> t; while (t--) solve();
  int n, m;
  cin >> n >> m;
  rep(i, 1, m) {
    int u, v, w;
    cin >> u >> v >> w;
    add(u, v, w);
    indegree[v]++;
  }
  queue<int> q;
  q.push(1);
  int sum = 0;
  while (q.size()) {
    int u = q.front(); q.pop();
    for (int i = head[u]; i; i = E[i].next) {
      int v = E[i].v;
      sum += E[i].w;
      if (!--indegree[v]) {
        q.push(v);
      } 
    }
  }
  cout << sum;
	return 0;
}
