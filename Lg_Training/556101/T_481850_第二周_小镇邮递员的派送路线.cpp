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

int arr[100005], brr[100006];

main() {
//	int t; cin >> t; while (t--) solve();
  int n, m;
  cin >> n >> m;
  rep(i, 1, n) { cin >> arr[i]; }
  rep(i, 1, m) cin >> brr[i];
  sort(arr + 1, arr + n + 1);
  long long ans = 0;
  rep(i, 1, m) {
    int *val1 = lower_bound(arr + 1, arr + n + 1, brr[i]);
    int *val2 = val1 - 1;
    if (val1 == arr + n + 1) *val1 = INT_MAX;
    if (val2 == arr) *val2 = INT_MAX;
    ans += min(abs(*val1 - brr[i]), abs(*val2 - brr[i]));
  }
  cout << ans << endl;
	return 0;
}
