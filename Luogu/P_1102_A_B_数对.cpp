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
int arr[(int)2e5 + 5], C;

main() {
//	int t; cin >> t; while (t--) solve();
  int n;
  cin >> n >> C;
  rep(i, 1, n) cin >> arr[i];
  sort(arr + 1, arr + n + 1);
  int j =0;
  int ans = 0, tmp = 0;
  rep(i, 1, n) {
    //cout << ans << ' ';
    if (arr[i] == arr[i - 1]) {
      ans += tmp;
      continue;
    }
    tmp = 0;
    while (j + 1 <= n && arr[j + 1] - arr[i] <= C)  {
      j++;
      if (arr[j] - arr[i] == C) tmp++;
    }
    ans += tmp;
  }
  cout << ans;
	return 0;
}
