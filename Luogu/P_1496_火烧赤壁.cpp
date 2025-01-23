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

int arr[(int)5e4 + 5], l[(int)5e4 + 5], r[(int)5e4 + 5], brr[(int)5e4 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  rep(i, 1, n) cin >> l[i] >> r[i];
  rep(i, 1, n) arr[i] = l[i];
  rep(i, n + 1, 2 * n) arr[i] = r[i - n];
  sort(arr + 1, arr + 2 * n + 1);
  int cnt = unique(arr + 1, arr + 2 * n + 1) - arr;
  rep(i, 1, n) {
    l[i] = lower_bound(arr + 1, arr + cnt, l[i]) - arr;
    r[i] = lower_bound(arr + 1, arr + cnt, r[i]) - arr;
    brr[l[i]]++; brr[r[i]]--;
  }
  rep(i, 1, cnt) brr[i] += brr[i - 1];
  int ans = 0;
  repq(i, 1, cnt) {
    if (brr[i] >= 1) { 
      ans += arr[i + 1] - arr[i];
    }
  }
  cout << ans; 
	return 0;
}
