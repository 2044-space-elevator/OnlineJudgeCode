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

bool status[105];

main() {
//	int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  cout << n << endl;
  rep(i, 1, n) {
    rep(j, 1, n) {
      status[j] = !status[j];
      if (j == i) status[j] = !status[j];
      cout << status[j];
    }
    cout << endl;
    
  }
	return 0;
}
