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

const int N = (1 << 20) + 3;
#define int int64_t 
int arr[45], lef[N], righ[N], m;
int fsc, scc;
void dfs(int l, int r, int &cnt, int ways[], int w) {
  if (w > m) return;
  if (l > r) {
  ways[++cnt] = w; return;}
    dfs(l + 1, r,cnt, ways, w + arr[l]);
    dfs(l + 1, r, cnt, ways, w);
  }
main() {
//	int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  cin >> m;
  rep(i, 1, n) cin >> arr[i];
  dfs(1, n / 2, fsc, lef, 0);
  dfs(n / 2 + 1, n, scc, righ, 0);
  sort(lef + 1, lef + fsc + 1);
  int ans = 0;
  rep(i, 1, scc) {
    ans += upper_bound(lef + 1, lef + fsc + 1, m - righ[i]) - lef - 1;
  }
  cout << ans;
	return 0;
}
