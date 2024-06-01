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

const int N = 5E3 + 5, M = 2 * N * N;
int n, m;
vct<int> E[N];
int indegree[N], dp[N];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  rep(i, 1, m) {
    int u, v;
    cin >> u >> v;
    E[u].push_back(v);
    indegree[v]++;
  }
  queue<int> q;
  rep(i, 1, n) {
    if (!indegree[i]) {
      q.push(i);
      dp[i] = 1; // Multiple points that indegree = 0, so multiple points need to be inited.
    }
  }
  while (q.size()) { // Topo Sort
    int frt = q.front();
    q.pop();
    for (int v : E[frt]) {
      dp[v] += dp[frt];
      dp[v] %= 80112002; // Sum
      if (!--indegree[v]) {
        q.push(v);
      }
    }
  } 
  ll ans = 0;
  rep(i, 1, n) {
    if (!E[i].size()) {
      ans += dp[i]; // Sum
      ans %= 80112002;
    }
  }
  cout << ans;
	return 0;
}
