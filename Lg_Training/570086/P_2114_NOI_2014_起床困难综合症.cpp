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

#define XOR 0
#define AND 1
#define OR 2

#define int ll
bool two_jz[(int)1e5 + 5][31];
int type[(int)1e5 + 5];
bool two_res[31];
int max_cnt = 0;

main() {
//	int t; cin >> t; while (t--) solve();
  int n, m;
  cin >> n >> m;
  rep(i, 1, n) {
    stg typ; int sz;
    cin >> typ >> sz;
    int cnt = 0;
    switch (typ[0]) {
      case 'X':
        type[i] = XOR;
        break;
      case 'A':
        type[i] = AND;
        break;
      case 'O':
        type[i] = OR;
        break;
    }
    while (sz) {
      two_jz[i][++cnt] = sz & 1ll;
      sz >>= 1ll;
    }
    max_cnt = max(max_cnt, cnt);
  }

  int jz_cnt = max_cnt;
  while (1ll << jz_cnt > m) {
    jz_cnt--;
  }
  rrep(i, 1, max_cnt) {
    bool zero = 0;
    bool one = 0;
    rep(j, 1, n) {
      if (type[j] == XOR) { zero ^= two_jz[j][i]; } 
      if (type[j] == AND) { zero &= two_jz[j][i]; }
      if (type[j] == OR)  { zero |= two_jz[j][i]; }
      if (jz_cnt >= i) {
        if (type[j] == XOR) { one ^= two_jz[j][i]; }
        if (type[j] == AND) { one &= two_jz[j][i]; }
        if (type[j] == OR)  { one |= two_jz[j][i]; }
      }
    }
    two_res[i] = zero | one;
  }
  int res = 0;
  rep(i, 1, max_cnt) {
    res += (1ll << (i - 1ll)) * two_res[i];
  }
  cout << res;
	return 0;
}
