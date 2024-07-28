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

map<char, char> ys;

main() {
//	int t; cin >> t; while (t--) solve();
  stg st;
  cin >> st;
  int ans = 0;
  ys[')'] = '(';
  ys[']'] = '[';
  ys['}'] = '{';
  repq(i, 0, st.size()) {
    stack<char> s;
    repq(j, i, st.size()) {
      if (st[j] == '(' || st[j] == '[' || st[j] == '{') {
        s.push(st[j]);
      } else {
        if (!s.size()) {
          break;
        }
        if (ys[st[j]] == s.top()) {
          s.pop();
        } else s.push(st[j]);
        if (s.empty()) ans = max(ans, j - i + 1);
      }
    }
  }
  cout << ans;
	return 0;
}
