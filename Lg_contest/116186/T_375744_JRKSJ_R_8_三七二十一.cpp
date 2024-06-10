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
  int len = s.size();
  int cnt = 0;
  for (int i = 0; i < len; i++) {
    if (s[i] == '1' || s[i] == '2' || s[i] == '4' || s[i] == '8') {
      cnt++;
      s[i] = '@';
    }
  }
  
  for (int i = 0; i < len - 4; i++) {
    if (s[i] == '6' && s[i + 1] == '5' && s[i + 2] == '5' && s[i + 3] == '3' && s[i + 4] == '6') {
      cnt++;
      s[i + 4] = '@';
    }
  }
  cout << cnt;
	return 0;
}
