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
bool row[10][10];
bool col[10][10];
bool gg[10][10];
char lrc[10][10];
char udc[10][10];
int sd[10][10];

void dfs(int x, int y, int spare) {
  if (spare == 0) {
    rep(i, 1, 9) {
      rep(j, 1, 9) {
        cout << sd[i][j] << ' ';
      }
      cout << endl;
    }
    exit(0);
  }
  if (x > 9 || y > 9) return;
  if (sd[x][y]) {
    if (y == 9) dfs(x + 1, y, spare - 1);
    else dfs(x, y + 1, spare - 1);
    return;
  }
  rep(sz, 1, 9) {
    if (row[x][sz] || col[y][sz]) continue;
    int ggs = (x - 1) / 3 * 3 + (y - 1) / 3;
    if (gg[ggs][sz]) continue;
    if ((y - 1) % 3) {
      if (lrc[x][y - 1] == '<') {
        if (sd[x][y - 1] >= sz) continue;
      }
      if (lrc[x][y - 1] == '>') {
        if (sd[x][y - 1] <= sz) continue;
      }
    }
    if ((x - 1) % 3) {
      if (udc[x - 1][y] == '^') {
        if (sd[x - 1][y] >= sz) continue;
      }
      if (udc[x - 1][y] == 'v') {
        if (sd[x - 1][y] <= sz) continue;
      }
    }
    row[x][sz] = col[y][sz] = gg[ggs][sz] = true;
    sd[x][y] = sz;
    if (y < 9) dfs(x, y + 1, spare - 1);
    else dfs(x + 1, 1, spare - 1);
    row[x][sz] = col[y][sz] = gg[ggs][sz] = false;
    sd[x][y] = 0;
  } 
  #ifndef ONLINE_JUDGE
  if (clock() / CLOCKS_PER_SEC > 1) exit(0);
  if (spare % 9) return;
  rep(i, 1, 9) {
    rep(j, 1, 9) {
      cout << sd[i][j] << ' ';
    }
    cout << endl;
  }
  #endif
}

main() {
//	int t; cin >> t; while (t--) solve();
  rep(i, 1, 9) {
    rep(j, 1, 9) {
      if (j % 3) cin >> lrc[i][j];
    }
    rep(j, 1, 9) {
      if (i % 3) cin >> udc[i][j];
    }
  }
  dfs(1, 1, 81);
	return 0;
}
