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

main() {
//	int t; cin >> t; while (t--) solve();
  stg s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '2' || s[i] == '4' || s[i] == '8') {
      cnt++;
    }
  }
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == '1' && s[i + 1] == '6') {
      cnt++;
    }
  }
  cout << cnt;
	return 0;
}
