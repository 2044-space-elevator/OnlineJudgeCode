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
int arr[(int)5e5 + 5], brr[(int)5e5 + 5], crr[(int)5e5 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
  int n, m;
  cin >> n >> m;
  rep(i, 1, n) cin >> arr[i];
  rep(i, 1, m) cin >> brr[i];
  int ans = 0;
  rep(i, 1, n) {
    int ind = lower_bound(brr + 1, brr + m + 1, arr[i]) - brr - 1;
    if (ind < 0) continue;
    ans += ind;
  }
  int cnt = 0;
  rep(i, 1, n) {
    crr[++cnt] = arr[i];
  }
  rep(i, 1, m) {
    crr[++cnt] = brr[i];
  }
  sort(crr + 1, crr + cnt + 1);
  rep(i, 1, cnt) {
    cout << crr[i] << " ";
  }
  cout << endl;
  cout << ans << endl;
	return 0;
}
