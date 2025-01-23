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

int n, arr[125][125];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  rep(i, 1, n) rep(j, 1, n) {
    cin >> arr[i][j];
    arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
  }
  int maxest = INT_MIN;
  rep(stx, 1, n) {
    rep(sty, 1, n) {
      rep(edx, stx, n) {
        rep(edy, sty, n) {
          maxest = max(maxest, arr[edx][edy] - arr[stx - 1][edy] - arr[edx][sty - 1] + arr[stx - 1][sty - 1]);
        }
      }
    } 
  }
  cout << maxest;
	return 0;
}
