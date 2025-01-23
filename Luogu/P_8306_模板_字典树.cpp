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

int trie[(int)3e6 + 5][80];
int cnt = 0;
int tot[(int)3e6 + 5];

void solve() {
  rep(i, 0, cnt + 1) 
    rep(j, '0', 'z') {
      trie[i][j - '0' + 1] = 0;
      tot[i] = 0;
    }
  cnt = 0;
  int n, q;
  cin >> n >> q;
  while (n--) {
    stg s;
    cin >> s;
    int u = 0;
    for (char v : s) {
      if (!trie[u][v - '0' + 1]) {
        trie[u][v - '0' + 1] = ++cnt;
      }
      u = trie[u][v - '0' + 1];
      tot[u]++;
    }
  }
  while (q--) {
    stg t;
    cin >> t;
    int u = 0;
    for (char v : t) {
      if (!trie[u][v - '0' + 1]) {
        cout << 0 << '\n';
        goto _;
      } 
      u = trie[u][v - '0' + 1];
    }
    cout << tot[u] << '\n';
    _:;
  }
}

main() {
  ios::sync_with_stdio(false);
	int t; cin >> t; while (t--) solve();
	return 0;
}
