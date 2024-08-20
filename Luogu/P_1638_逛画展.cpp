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

int coun[(int)1e6 + 5], arr[(int)1e6 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
  int n, m;
  cin >> n >> m;
  rep(i, 1, n) cin >> arr[i];
  int l = 1, r = 1, among = 0;
  int ml = INT_MAX, mr = 0;
  int mlen = INT_MAX;
  while (l <= r && r <= n + 1) {
    if (among < m) {
      among += (++coun[arr[r++]] == 1);
    } else {
      among -= (!(--coun[arr[l++]]));
      if (r - l + 1 < mlen) {
        ml = l, mr = r, mlen = r - l + 1;
      }
    }
  }
  cout << ml - 1<< ' ' << mr - 1;
	return 0;
}
