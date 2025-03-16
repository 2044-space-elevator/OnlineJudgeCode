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



#define int ll

struct Node {
  int D[6][6];
  int hash() {
    int sum = 0;
    rep(i, 1, 5) {
      rep(j, 1, 5) {
        sum = sum * 3 + D[i][j];
      }
    } 
    return sum; 
  }
}S, T;
map<int, int> dis;
map<int, int> vis;
queue<Node> q;

void solve() {
  rep(i, 1, 5) {
    rep(j, 1, 5) {
      char c;
      cin >> c;
      if (c == '1') {
        S.D[i][j] = 2;
      } else if (c == '0') {
        S.D[i][j] = 1;
      } else {
        S.D[i][j] = 0;
      }
    }
  }
  if (S.hash() == T.hash()) {
    cout << 0 << endl;
    return;
  }
  dis.clear();
  vis.clear();
  dis[S.hash()] = 0;
  dis[T.hash()] = 0;
  vis[S.hash()] = 1;
  vis[T.hash()] = 2;
  while (q.size()) q.pop();
  q.push(S);
  q.push(T);
  while (q.size()) {
    Node u = q.front(); q.pop();
    if (dis[u.hash()] >= 15) {
      cout << -1 << endl;
      return;
    }
    int zerox, zeroy;
    rep(i, 1, 5) {
      rep(j, 1, 5) {
        if (u.D[i][j] == 0) {
          zerox = i; zeroy = j;
          break;
        }
      }
    }
    int dxy[8][2] = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
    repq(i, 0, 8) {
      int dx = dxy[i][0], dy = dxy[i][1];
      int x = zerox + dx, y = zeroy + dy;
      if (x < 1 || y < 1 || x > 5 || y > 5) continue;
      Node cur = u;
      swap(u.D[zerox][zeroy], u.D[x][y]);
      if (vis[cur.hash()] == vis[u.hash()]) {
        swap(u.D[zerox][zeroy], u.D[x][y]);
        continue;
      }
      if (vis[u.hash()] + vis[cur.hash()] == 3) {
        if (dis[cur.hash()] + dis[u.hash()] + 1 <= 15)
        cout << dis[cur.hash()] + dis[u.hash()] + 1 << endl; else cout << -1 << endl;
        return;
      }
      vis[u.hash()] = vis[cur.hash()];
      dis[u.hash()] = dis[cur.hash()] + 1;
      q.push(u);
      swap(u.D[zerox][zeroy], u.D[x][y]);
    }
  }
}

main() {
  rep(i, 1, 5) T.D[1][i] = 2;
  T.D[2][1] = 1;
  rep(i, 2, 5) T.D[2][i] = 2;
  T.D[3][1] = 1, T.D[3][2] = 1, T.D[3][3] = 0, T.D[3][4] = 2, T.D[3][5] = 2;
  T.D[4][1] = 1, T.D[4][2] = 1, T.D[4][3] = 1, T.D[4][4] = 1, T.D[4][5] = 2;
  T.D[5][1] = 1, T.D[5][2] = 1, T.D[5][3] = 1, T.D[5][4] = 1, T.D[5][5] = 1;
	int t; cin >> t; while (t--) solve();
	return 0;
}
