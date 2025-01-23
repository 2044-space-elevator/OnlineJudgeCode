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

stg s[2006];

main() {
//	int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  int maxest = 0;
  rep(i, 1, n) { cin >> s[i]; maxest = max(maxest, (int)s[i].size()); }
  repq(i, 0, maxest) {
    char c = '#';
    rep(j, 1, n) {
      if (s[j].size() <= i) continue;
      if (c == '#') c = s[j][i];
      else if (c != s[j][i]) { 
        cout << i;
        return 0;
       }
    }
  }
	return 0;
}
