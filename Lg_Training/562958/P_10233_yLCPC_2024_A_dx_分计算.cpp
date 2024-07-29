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

int sum[(int)1e7 + 5];
void solve() {
  sum[0] = 0;
	stg s;
  cin >> s;
  s = ' ' + s;
  repq(i, 1, s.size()) {
    int score = 0;
    switch(s[i]) {
      case 'P':
        score = 3;
        break;
      case 'p':
        score = 2;
        break;
      case 'G':
        score = 1;
        break;
    }
    sum[i] = sum[i - 1] + score;
  }
  int n; cin >> n;
  rep(i, 1, n) {
    int l, r; cin >> l >> r;
    int ans = sum[r] - sum[l - 1];
    cout << ans << '\n';
  }
}

main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
