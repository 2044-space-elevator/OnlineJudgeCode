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

stg cards[205];
stg S;
bool dp[(int)2e5 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
  stg tmp;
  int n = 0;
  while (1) {
    cin >> tmp;
    if (tmp == ".") {
      while (cin >> tmp) {
        S += tmp;
      }
      break;
    }
    cards[++n] = tmp;
  }
  rep(i, 1, n) {
    if (dp[cards[i].size() - 1]) continue;
    if (cards[i] == S.substr(0, cards[i].size())) {
      dp[cards[i].size() - 1] = 1;
    }
  }
  repq(i, 0, S.size()) {
    if (!dp[i]) continue;
    rep(j, 1, n) {
      if (i + cards[j].size() >= S.size()) continue;
      if (S.substr(i + 1, cards[j].size()) == cards[j]) {
        dp[i + cards[j].size()] = 1;
      }
    }
  }
  rrepq(i, 0, S.size()) {
    if (dp[i]) {cout << i + 1; return 0;}
  }
  cout << 0;
	return 0;
}
