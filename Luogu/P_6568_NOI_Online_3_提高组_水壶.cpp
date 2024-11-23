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

ll n, k, arr[(int)1e6 + 5];;

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> k;
  rep(i, 1, n) { cin >> arr[i]; arr[i] += arr[i - 1]; }
  ll res = 0; 
  rep(i, 1, n) {
    if (i + k > n) break;
    res = max(res, arr[i + k] - arr[i - 1]);
  }
  cout << res;
	return 0;
}
