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

int n, sum, permu[100], vis[100], Yanghui[100][100];

void init() {
  Yanghui[1][1] = 1;
  rep(i, 2, n) {
    Yanghui[i][1] =1;
    rep(j, 2, i) {
      Yanghui[i][j] = Yanghui[i - 1][j] + Yanghui[i - 1][j - 1];
    }
  }
}
void dfs(int now, int dep) {
  if (now > sum) {
    return;
  }
  if (now == sum && dep == n + 1) {
    rep(i, 1, n) {
      cout << permu[i] << ' ';
    }
    exit(0);
  }
  if (dep > n) return;
  rep(i, 1, n) {
    if (!vis[i]) {
      vis[i] = 1;
      permu[dep] = i;
      dfs(now + i * Yanghui[n][dep], dep + 1);
      vis[i] = 0;
    }
  }
}


main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> sum;
  init();
  dfs(0, 1);
	return 0;
}
