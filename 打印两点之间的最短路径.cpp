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

const int N = 105;
int n, dis[N][N], cost[N], path[N][N];

void Path(int s, int t) {
  int k = path[s][t];
  if (k == -1) {
    cout << "-->" << t;
    return;
  }
  Path(s, k);
  Path(k, t);
}

main() {
  //  int t; cin >> t; while (t--) solve();
  cin >> n;
  rep(i, 1, n) {
    rep(j, 1, n) {
      cin >> dis[i][j];
      path[i][j] = -1;
      dis[j][i] = dis[i][j];
      if (dis[i][j] == -1) {
        dis[i][j] = dis[j][i] = 1e9;
      }
    }
  }
  rep(i, 1, n) {
    cin >> cost[i];
  }
  rep(k, 1, n) {
    rep(i, 1, n) {
      rep(j, 1, n) {
        ll len = dis[i][k] * 1ll + dis[k][j] + cost[k];
        if (len >= 1e9) {
          continue;
        }
        if (len < dis[i][j]) {
          dis[i][j] = len, path[i][j] = k;
        } else if (dis[i][j] == len && path[i][j] > path[i][k]) {
          path[i][j] = k;
        }
      }
    }
  }
  int s, t;
  while (cin >> s >> t) {
    if (s == -1 && t == -1) {
      break;
    }
    printf("From %d to %d:\n", s, t);
    cout << "Path: " << s;
    Path(s, t);
    cout << "\nTotal cost: " << dis[s][t] << endl << endl;
  }
  return 0;
}