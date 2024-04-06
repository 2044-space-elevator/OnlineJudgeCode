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

const int N = 305;

int n, fa[N], arr[N], m, ans, sum;
bool vis[N][N], flg;
vct<int> Map[N];

void dfs(int id, int x) {
  for (int v : Map[x]) {
    vis[id][v] = 1;
  }
  for (int v : Map[x]) {
    dfs(id, v);\
  }
}

main() {
  cin >> n;
  repq(i, 1, n) {
    cin >> fa[i];
    Map[fa[i]].push_back(i);
  }
  repq(i, 0, n) {
    dfs(i, i);
  }
  repq(i, 0, n) {
    vis[i][i] = 1;
  }  
  int t;
  cin >> t; 
  while (t--) {
    ans = 0;
    cin >> m;
    rep(i, 1, m) {
      cin >> arr[i];
    }
    repq(i, 0, n) {
      flg = 1;
      rep(j, 1, m) {
        if (!vis[i][arr[j]]) {
          flg = 0;
        }
      }
      if (flg) ans = max(ans, i);
    }
    cout << ans << endl;
  }
	return 0;
}
