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

int n, arr[(int)1e6 + 5], brr[(int)1e6 + 5];
void solve() {
  cin >> n;
  rep(i, 1, n) cin >> arr[i];
  rep(i, 1, n) brr[i] = arr[i];
  sort(brr + 1, brr + n + 1);
  int cnt = unique(brr + 1, brr + n + 1) - brr;
  rep(i, 1, n) {
    arr[i] = lower_bound(brr + 1, brr + cnt, arr[i]) - brr;
    cout << arr[i] << " ";

  }
  cout << "\n";
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
