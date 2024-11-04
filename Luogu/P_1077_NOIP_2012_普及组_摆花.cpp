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

int n, m;
const int N = 1E6 + 7;
int arr[N], dp[105][105][105];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  rep(i, 1, n) cin >> arr[i];
  rep(i, 1, n) dp[1][i][1] = 1; 
  rep(i, 1, m) {
    rep(j, 1, n) {
      // different
      repq(k, 1, j) {
        rep(l, 1, min(arr[k], i)) {
          dp[i][j][1] += dp[i - 1][k][l];
          dp[i][j][1] %= N;
        }
      }
      // same
      rep(l, 1, min(arr[j], i)) {
        dp[i][j][l] += dp[i - 1][j][l - 1];
        dp[i][j][l] %= N;
      }
    }
  }
  int sum = 0;
  rep(i, 1, n) rep(j, 1, min(m, arr[i])) {
    sum += dp[m][i][j];
    sum %= N;
   }
  cout << sum;
	return 0;
}
