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

int siz[(int)1e6 + 5], n, fat[(int)1e6 + 4];
vct<int> E[(int)1e6 + 5];
void dfs(int u, int fa) {
  for (int v : E[u]) {
    if (v == fa) continue;
    dfs(v, u);
    siz[u] += siz[v];
    fat[v] = u;
  }
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  repq(i, 1, n) {
    int a, b;
    cin >> a >> b;
    E[a].push_back(b);
    E[b].push_back(a);
    siz[i] = 1;
  }
  siz[n] = 1;
  dfs(1, 0);
  repq(i, 1, E[1].size()) {
    if (siz[E[1][i]] != siz[E[1][i - 1]]) goto __;
  }
  cout << "1 ";
  __:;
  rep(i, 2, n) {
    int fst = siz[1] - siz[i];
    repq(j, 0, E[i].size()) {
      if (E[i][j] != fat[i]) {
        if (siz[E[i][j]] != fst) goto _;
      }
    }
    cout << i << ' '; 
    _:;
  }
	return 0;
}
