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

int n, m;
bool vis[1605][1605];
ll tj[(int)1e5 + 5];

void bfs(int x, int y) {
  queue<pair<int, int>> q;
  q.push({x, y});
  vis[x][y] = 1;
  int cnt = 0;
  while (q.size()) {
    pair<int, int> tmp = q.front();
    x = tmp.first, y = tmp.second;
    cnt++;
    q.pop();
    int dxy[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 
    1}, {1, -1}, {1, 1}};
    repq(i, 0, 8) {
      int dx = x + dxy[i][0];
      int dy = y + dxy[i][1];
      if (vis[dx][dy] || dx > n || dy > m || dx < 1 || dy < 1) continue;
      vis[dx][dy] = 1;
      q.push({dx, dy});
    }
  }
  tj[cnt] += cnt;
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  rep(i, 1, n) {
    rep(j, 1, m) {
      char c;
      cin >> c;
      vis[i][j] = (c == '.');
    }
  }
  rep(i, 1, n) {
    rep(j, 1, m) {
      if (!vis[i][j]) {
        bfs(i, j);
      }
    }
  }
  ll cnt = 0, res = 0;
  rep(i, 1, 1e5) {
    cnt += !!tj[i];
    res = max( res, tj[i]);
  } 
  cout << cnt << " " << res;
	return 0;
}
