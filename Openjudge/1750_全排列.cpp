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

int arr[500], n, vis[500];
stg a;

void dfs(int dep) {
  if (dep == n + 1) {
    rep(i, 1, n) {
      cout << a[arr[i]];
    }
    cout << endl;
  }
  rep(i, 1, n) {
    if (!vis[i]) {
      vis[i] = 1;
      arr[dep] = i;
      dfs(dep + 1);
      arr[dep] = 0;
      vis[i] = 0;
    }
  }
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> a;
  n = a.size();
  a = " " + a;
  dfs(1);
	return 0;
}
