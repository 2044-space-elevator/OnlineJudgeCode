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

int arr[(int)2e5 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
  int tmp;
  cin >> tmp >> tmp;
  stg n, m;
  cin >> n >> m;
  n = ' ' + n;
  m = ' ' + m;
  repq(i, 1, m.size()) {
    if (arr[i - 1] == n.size()) {
      cout << n.size() << endl;
      return 0;
    } 
    if (m[i] == n[arr[i - 1] + 1]) {
      arr[i] = arr[i - 1] + 1;
    } else {
      arr[i] = 0;
    }
  }
  int ans = 0;
  repq(i, 0, m.size()) {
    ans = max(arr[i], ans);
  }
  cout << ans << endl;
	return 0;
}
