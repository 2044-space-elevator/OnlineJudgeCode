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

const int N = 305;
int dp[N][N];
int n, m;
vct<int> E[N];

void dfs(int u) {
  for (int v : E[u]) {
    dfs(v);
    rrep(j, 0, m) {
      repq(k, 0, j) {
        dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
      }
    }
  }
  
}
main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  m++;
  rep(i, 1, n) {
    int fa;
    cin >> fa >> dp[i][1];
    E[fa].push_back(i);
  } 
  dfs(0);
  cout << dp[0][m];
	return 0;
}
