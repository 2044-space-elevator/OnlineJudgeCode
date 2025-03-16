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

int n, k;
int bit;
bool vis[1048580];
int pre[26];
void dfs(int dep) {
  if (dep == n + 1) {
    rep(i, 1, n) {
      cout <<  pre[i] << ' ';
    }
    exit(0);
  }
  repq(i, 0, n) {
    // 1110
    // 1110
    if (!vis[i] && __builtin_popcount(i ^ pre[dep - 1]) == k) {
      vis[i] = 1;
      pre[dep] = i;
      dfs(dep + 1);
      vis[i] = 0;
    }
  }
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> bit >> k;
  n = 1 << bit; 
  vis[0] = 1;
  dfs(2);
	return 0;
}
