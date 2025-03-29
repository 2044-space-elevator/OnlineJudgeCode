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

const int MAXN = 1 << 9;
int valid[MAXN];
ll dp[10][MAXN][1145];
main() {
  //  int t; cin >> t; while (t--) solve();
  int n, m;
  cin >> n >> m;
  int cnt = 0;
  int MAX = (1 << n) - 1;
  rep(i, 0, MAX) {
    if (i & (i << 1)) continue;
    valid[++cnt] = i;
    dp[1][cnt][__builtin_popcount(i)] = 1;
  }
  
  int fir, sec;
  rep(i, 2, n) {
    rep(j, 1, cnt) {
      fir = valid[j];
      rep(k, 1, cnt) {
        sec = valid[k];
        if ((fir & sec) || (fir & (sec << 1)) || (fir & (sec >> 1))) continue;
        rep(l, 0, m) {
          dp[i][j][__builtin_popcount(fir) + l] += dp[i - 1][k][l];
        }
        
      }
    }
  }
  //cout << __builtin_popcount(10);
  ll ans = 0;
  rep(i, 1, cnt) ans += dp[n][i][m];
  cout << ans;
  return 0;
}