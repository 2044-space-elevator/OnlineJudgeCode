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
#define int ll
void solve() {
	
}

const int N = 1005;
int n, arr[N], brr[N], crr[N], dp[N][N][3];

bool win(int x, int y) {
  if (x == 0 && y == 2) return 2;
  if (x == 1 && y == 0) return 2;
  if (x == 2 && y == 1) return 2;
  return (x == y);
} 

int dy() {
  rep(i, 1, n) {
    repq(j, 0, i) {
      repq(k, 0, 3) {
        repq(l, 0, 3) {
          dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - l == crr[i]][l]) + win(k, crr[i]) * arr[i];
        }
      }
    }
  }
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  rep(i, 1, n) {
    cin >> arr[i];
  }
  repq(i, 1, n) {
    cin >> brr[i];
    brr[i] += brr[i - 1];
  }
  rep(i, 1, n) {
    cin >> crr[i];
  }
  dy();
  int ans = 0;
  repq(j, 0, n) {
    repq(k, 0, 3) {
      ans = max(ans, dp[n][j][k] - brr[j]);
    }
  }
  cout << ans;
	return 0;
}
