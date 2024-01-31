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

int n, m, r, dp[(int)1e6 + 5];
struct edge {
  int st,en, eff;
}TM[(int)1e6 + 5];
bool cmp(edge a, edge b) { return a.st < b.st; }

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m >> r;
  rep(i, 1, m) {
    cin >> TM[i].st >> TM[i].en >> TM[i].eff;
  }
  sort(TM + 1, TM + m + 1, cmp);
  int ans = 0;
  rep(i, 1, m) {
    rrep(j, 1, i - 1) {
      if (TM[i].st >= TM[j].en + r) {
        dp[i] = max(dp[i], dp[j]);
      }
    } 
    dp[i] += TM[i].eff;
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
	return 0;
}
