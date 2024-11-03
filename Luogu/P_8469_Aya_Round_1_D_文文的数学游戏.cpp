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

#define int long long

const int N = 1e5 + 5;
int n, arr[N];

main() {
//	int t; cinkk>> t; while (t--) solve();
  cin >> n;
  rep(i, 1, n) cin >> arr[i];
  int ans1;
  cout << (ans1 = *min_element(arr + 1, arr + n + 1)) << ' ' ;
  int ans2 = 1;
  rep(i, 1, n) {
    ans2 *= arr[i] / ans1;
    ans2 %= (int)(1e9 + 7);
  }
  cout << ans2;
	return 0;
}
