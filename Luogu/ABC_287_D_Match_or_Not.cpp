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

const int N = 3E5 + 5;

stg s, t;
int pre[N], suf[N];
main() {
//	int t; cin >> t; while (t--) solve();
  cin >> s >> t;
  int n, m;
  s = " "  + s; t = " " + t;
  n = s.size(); m = t.size();
  pre[1] = 1, suf[m] = 1;
  rep(i, 1, m) {
    pre[i + 1] = s[i] == t[i] || s[i] == '?' || t[i] == '?';
    if (!pre[i + 1]) break;
  }
  rrep(i, 1, m) {
    suf[i] = s[i + n - m] == t[i] || s[i + n - m] == '?' || t[i] == '?';
    if (!suf[i]) break;
  }
  rep(i, 1, m) {
    if (pre[i] && suf[i]) {
      rty
    }
    else rtn
  }
	return 0;
}
