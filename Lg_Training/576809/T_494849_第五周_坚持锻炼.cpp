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


int x[100005], y[100005];
int sum[7][100005];
main() {
//	int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  rep(i, 1, n) {
    cin >> x[i] >> y[i];
  }
  int maxx = 0, minn = 7;
  rep(i, 1, 5) {
    rep(j, 1, n) {
      if (x[j] == i || y[j] == i) {
        sum[i][j] = sum[i][j - 1] + 1;
      }
    }
  }
  rrep(i, 1, 5) {
    rep(j, 1, n) {
      if (sum[i][j] >= maxx) {
        maxx = sum[i][j];
        minn = i;
      }
    }
  }
  cout << maxx << ' ' << minn << endl;
	return 0;
}
