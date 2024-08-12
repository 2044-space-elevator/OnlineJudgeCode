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

int n, m, k, arr[1005][1005], ans = 0, starti, startj;
bool vis[1005][1005];

struct node {
  int x, y, step;
};

void bfs(int end, int sa, int sb) {
  queue<node> q;
  q.push((node){sa, sb, 0});
  while (q.size()) {
    node now = q.front();
    q.pop();
    int x = now.x, y = now.y, dep = now.step;
    if (arr[x][y] == end) {
      ans += dep;
      starti = x;
      startj = y;
      return;
    }
    int dxy[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    repq(i, 0, 4) {
      int dx = x + dxy[i][0], dy = y + dxy[i][1];
      if (dx < 1 || dx > n || dy < 1 || dy > m || vis[dx][dy] || arr[dx][dy] == -1) continue;
      vis[dx][dy] = true;
      q.push((node){dx, dy, dep + 1});
    }
  }
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m >> k;
  rep(i, 1, n) {
    rep(j, 1, m) {
      char x;
      cin >> x;
      if (x == 'X') {
        arr[i][j] = -1;
      }
      if (x == 'S') {
        starti = i; startj = j;
      }
      if (x >= '1' && x <= '9')  {
        arr[i][j] = x - '0';
      }
    }
  }
  rep(i, 1, k) {
    memset(vis, 0, sizeof vis);
    bfs(i, starti, startj);
  }
  cout << ans << endl;
}
