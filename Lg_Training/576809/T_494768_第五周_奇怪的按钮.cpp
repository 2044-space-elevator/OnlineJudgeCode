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

bool status[10][10], vis[10][10];
int ans = INT_MAX;
bool check() {
  rep(i, 1, 3) {
    rep(j, 1, 3) {
      if (!status[i][j]) return 0;
    }
  }
  return 1;
}
void dfs(int sum) {
  if (sum > ans) return;
  if (check()) {
    ans = min(ans, sum);
    return;
  } 
  rep(i, 1, 3) {
    rep(j, 1, 3) {
      if (!vis[i][j]) {
        vis[i][j] = 1;
        int dxy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        status[i][j] = !status[i][j];
        rep(k, 0, 4) {
          int dx = dxy[k][0] + i, dy = dxy[k][1] + j;
          if (dx < 1 || dx > 3 || dy < 1 || dy > 3) continue;
          status[dx][dy] = !status[dx][dy];
        }
        dfs(sum + 1);
        status[i][j] = !status[i][j];
        rep(k, 0, 4) {
          int dx = dxy[k][0] + i, dy = dxy[k][1] + j;
          if (dx < 1 || dx > 3 || dy < 1 || dy > 3) continue;
          status[dx][dy] = !status[dx][dy];
        }
        vis[i][j] = 0;
      }
    }
  }
}
void solve() {
	
}


main() {
//	int t; cin >> t; while (t--) solve();
  rep(i, 1, 3) {
    rep(j, 1, 3) {
      cin >> status[i][j];
    }
  }
  dfs(0);
  cout << ans;
	return 0;
}
