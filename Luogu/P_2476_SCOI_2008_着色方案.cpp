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
#define int ll
const int MOD = 1e9 + 7;

int dp[16][16][16][16][16][6];
#define valv dp[a][b][c][d][e][last]

int dfs(int a, int b, int c, int d, int e, int last) {
  if (valv != -1) return valv;
  if (a + b + c + d + e == 0) return 1;
  int res = 0;
  if (a > 0) res += (a - (last == 1ll)) % MOD * (dfs(a - 1, b, c, d, e, 0) % MOD) % MOD;
  res %= MOD;
  if (b > 0) res += (b - (last == 2ll)) % MOD * (dfs(a + 1, b - 1, c, d, e, 1) % MOD) % MOD;
  res %= MOD;
  if (c > 0) res += (c - (last == 3ll)) % MOD * (dfs(a, b + 1, c - 1, d, e, 2) % MOD) % MOD;
  res %= MOD;
  if (d > 0) res += (d - (last == 4ll)) % MOD * (dfs(a, b, c + 1, d - 1, e, 3) % MOD) % MOD;
  res %= MOD;
  if (e > 0) res += (e - (last == 5ll)) % MOD * (dfs(a, b, c, d + 1, e - 1, 4) % MOD) % MOD;
  res %= MOD;
  return valv = res;
}
main() {
//	int t; cin >> t; while (t--) solve();
  int n;
  memset(dp, -1, sizeof dp);
  int a = 0, b = 0, c = 0, d = 0, e = 0;
  cin >> n;
  rep(i, 1, n) {
    int x;
    cin >> x;
    if (x == 1) a++;
    if (x == 2) b++;
    if (x == 3) c++;
    if (x == 4) d++;
    if (x == 5) e++;
  }
  cout << dfs(a, b, c, d, e, 0);
	return 0;
}
