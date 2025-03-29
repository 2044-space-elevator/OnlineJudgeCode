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
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int arr[N], v[N];

int quickpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res *= a;
    res %= mod;
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return res;
}
main() {
//	int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  int sum = 0;
  rep(i, 1, n) { cin >> arr[i]; sum += arr[i]; }
  rep(i, 1, n) cin >> v[i];
  int ans = 0;
  rep(i, 1, n) {
    ans += quickpow(2, sum - arr[i]) * (quickpow(v[i] + 1, arr[i]) - 1);
    ans %= mod;
  }
  cout << ans;
	return 0;
}
