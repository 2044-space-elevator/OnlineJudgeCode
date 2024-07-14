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

char M[1005][1005];
int endX, endY, suma[1005][1005], sumb[1005][1005];
bool vis[1005][1005];

main() {
  int n, m;
  cin >> n >> m;
  rep(i, 1, n) {
    rep(j, 1, m) {
      cin >> M[i][j];
      if (M[i][j] == '#') {
        endX = i, endY = j;
      }
      suma[i][j] = (M[i][j] == 'X') + suma[i][j - 1];
      sumb[i][j] = (M[i][j] == 'X') + sumb[i - 1][j];
    }
  }
  queue<int> q1, q2, q3;
  q1.push(1); 
  q2.push(1);
  q3.push(0);
  vis[1][1] = 1;
  while (q1.size()) {
    int x = q1.front(), y = q2.front(), k = q3.front();
    q1.pop(); q2.pop(); q3.pop();
    if (x == endX && y == endY) {
      cout << k;
      return 0;
    }
    int dd[2] = {1, -1};
    repq(i, 0, 2) {
      repq(j, 0, 10) {
        int dx = x + dd[i] * pow(2, j), dy = y;
        if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && !vis[dx][dy] && M[dx][dy] != 'X' && !(sumb[dx][dy] - sumb[x][y])) {
          vis[dx][dy] = 1; q1.push(dx), q2.push(dy), q3.push(k + 1);
        }
        dx = x; dy = y + dd[i] * pow(2, j);
        if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && !vis[dx][dy] && M[dx][dy] != 'X' && !(suma[dx][dy] - suma[x][y])) {
          vis[dx][dy] = 1; q1.push(dx), q2.push(dy), q3.push(k + 1);
        }
      }
    }
  }
//	int t; cin >> t; while (t--) solve();
cout << "-1\n";
	return 0;
}
