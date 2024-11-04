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

const int N = 1E3 + 5;

#define int ll
int n, h, r;
struct node {
  int x, y, z;
}xyz[N];
bool vis[N];

bool flg = 0;

int dist(int x1, int y1, int z1, int x2, int y2, int z2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
}

void dfs(int now) {
  if (flg) return;
  if (xyz[now].z + r >= h) {
    flg = 1;
    return;
  }
  rep(i, 1, n) {
    if (i == now) continue;
    if (vis[i]) continue;
    int nx = xyz[now].x, ny = xyz[now].y, nz = xyz[now].z;
    int px = xyz[i].x, py = xyz[i].y, pz = xyz[i].z;
    int tmp = dist(nx, ny, nz, px, py, pz);
    if (tmp <= 4 * r * r) {
      vis[i] = 1;
      dfs(i);
    } 
  }
}

void solve() {
  flg = 0;
  cin >> n >> h >> r;
  rep(i, 1, n) {
    cin >> xyz[i].x >> xyz[i].y >> xyz[i].z;
  }
  rep(i, 1, n) {
    if (xyz[i].z - r > 0) continue;
    memset(vis, 0, sizeof vis);
    vis[i] = 1;
    dfs(i);
    if (flg) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
}

main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
