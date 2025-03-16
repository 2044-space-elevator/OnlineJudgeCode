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
pair<int, int> arr[100005];

main() {
//	int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  int a, b;
  cin >> a >> b;
  rep(i, 1, n) cin >> arr[i].first >> arr[i].second;


  
  int ans = 0;
  rep(i, 1, n) {
    ans = max(ans, a / arr[i].second);
    a *= arr[i].first;
  }
  cout << ans;
	return 0;
}
