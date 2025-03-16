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

struct Node {
  int D[4][4];
  ll hash() {
    ll sum = 0;
    rep(i, 1, 3) {
      rep(j, 1, 3) {
        sum = sum * 10 + D[i][j];
      }
    }
    return sum;
  }
}S, T;

stg tmp;
int pos = 1;
map<int, int> vis;
map<int, int> dis;
queue<pair<Node, int> > q;

main() {
//	int t; cin >> t; while (t--) solve();
cin >> tmp; tmp = " " + tmp;
  rep(i, 1, 3) {
    rep(j, 1, 3) {
      S.D[i][j] = tmp[pos] - '0';
      pos++;
    }
  }
  pos = 1;
  tmp = " 123804765";
  rep(i, 1, 3) {
    rep(j, 1, 3) {
      T.D[i][j] = tmp[pos] - '0';
      pos++;
    }
  }
  if (S.hash() == T.hash()) {
    cout << 0;
    return 0;
  }
  q.push({S, 0}); q.push({T, 0});
  vis[S.hash()] = 1;
  vis[T.hash()] = 2;
  while (q.size()) {
    auto u = q.front(); q.pop();
    int zerox = 0, zeroy = 0;
    rep(i, 1, 3) {
      rep(j, 1, 3) {
        if (u.first.D[i][j] == 0) {
          zerox = i, zeroy = j;
          break;
        }
      }
    }
    int dxy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    repq(i, 0, 4) {
      int x = zerox + dxy[i][0], y = zeroy + dxy[i][1];
      if (x < 1 || x > 3 || y < 1 || y > 3) continue;
      pair<Node, int> cur = u;  
      swap(u.first.D[zerox][zeroy], u.first.D[x][y]);
      if (vis[u.first.hash()] == vis[cur.first.hash()]) {
        swap(u.first.D[zerox][zeroy], u.first.D[x][y]);
        continue;
      }
      if (vis[u.first.hash()] + vis[cur.first.hash()] == 3) {
        cout << dis[cur.first.hash()] + dis[u.first.hash()] + 1 << endl;
        return 0;
      }
      vis[u.first.hash()] = vis[cur.first.hash()];
      dis[u.first.hash()] = dis[cur.first.hash()] + 1;
      q.push({u.first, u.second + 1});
      swap(u.first.D[zerox][zeroy], u.first.D[x][y]);
    }
  }
	return 0;
}
