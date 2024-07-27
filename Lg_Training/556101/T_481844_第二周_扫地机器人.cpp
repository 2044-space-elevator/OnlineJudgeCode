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

int n, k, arr[(int)1e6 + 5], ans;

bool check(int x) {
  int r = x / 2, last = arr[1] - 1;
  rep(i, 1, k) {
    int tmp = r;
    if (tmp < last) return 0;
    tmp -= last;
    if (i < k) last = max(arr[i + 1] - arr[i] - 1 - tmp, 0ll);
    else {
      if (tmp < n - arr[k]) return 0;
    }
  }
  return 1;
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> k;
  rep(i, 1, k) cin >> arr[i];
  sort(arr + 1, arr + k + 1);
  int l = 0, r = 2 * n;
  while (l <= r) {
    int mid = l + ((r - l) >> 1);
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid  + 1;
    }
  }
  cout << ans;
	return 0;
}
