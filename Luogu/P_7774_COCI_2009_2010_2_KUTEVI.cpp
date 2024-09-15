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

const int mod = 360;
int arr[15], brr[15];
bool flg[361];

main() {
//	int t; cin >> t; while (t--) solve();
  int n, m;
  cin >> n >> m;
  rep(i, 1, n) cin >> arr[i];
  rep(i, 1, m) cin >> brr[i];
  flg[0] = 1;
  rep(i, 1, n) {
    rep(j, 0, 114514) {
      flg[j % mod] |= flg[(mod + j - arr[i]) % mod];
      flg[j % mod] |= flg[(mod + j + arr[i]) % mod];
    }
  }
  rep(i, 1, m) {
    if (flg[brr[i]])
      RTY
    else
      RTN
  }
	return 0;
}
