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

#define int ull

int n, m, c, k;
int typeAni = 0, typeFoo = 0;

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m >> c >> k;
  rep(i, 1, n) {
    int tmp;
    cin >> tmp;
    typeAni |= tmp;
  }
  rep(i, 1, m) {
    int tmp;
    cin >> tmp;
    typeFoo |= (1ull << tmp);
    cin >> tmp;
  }
  typeAni &= typeFoo;
  int ans = 0;
  repq(i, 0, k) {
    ans += !(((typeAni >> i) & 1ull) ^ ((typeFoo >> i) & 1ull));
  }
  if (ans == 0 && n == 0) {
    puts("18446744073709551616");
    return 0;
  }
  cout << (1ull << ans) - n;
	return 0;
}
