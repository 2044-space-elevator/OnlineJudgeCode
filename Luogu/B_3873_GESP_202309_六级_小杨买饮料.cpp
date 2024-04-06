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

const int N = 505, L = 1e6 + 5;
int crr[L], lrr[L], n, l, dp[L];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> l;
  int sum = 0;
  rep(i, 1, n) {
    cin >> crr[i] >> lrr[i];
    sum += crr[i];
  }
  rep(k, 0, sum) {
    rep(i, 1, n) {
      rrep(j, crr[i], k) {
        dp[j] = max(dp[j], dp[j - crr[i]] + lrr[i]);
      }
      if (dp[k] >= l) {
        cout << k << endl;
        return 0;
      }
    } 
  }
	return 0;
}
