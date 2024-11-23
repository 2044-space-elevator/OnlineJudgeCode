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
  int t;
  cin >> s >> t;
  int pos = 0;
  while (t--) {
    char c;
    cin >> c;
    int x;
    cin >> x;
    if (c == '<') pos += x;
    else pos -= x;
  }
  pos %= s.size();
  if (pos < 0) {
    pos = s.size() + pos;
  }
  repq(i, pos, s.size()) cout << s[i];
  repq(i, 0, pos) cout << s[i];
	return 0;
}
