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
#define int ll
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int cas = 0;

void solve() {
  cas++;
  int n;
  int q = 0, p = 1;
  // 分母设 1 分子设 0
  cin >> n;
  rep(i, 1, n) {
    int x;
    cin >> x;
    q = p + q * x;
    p *= x;
    // 通分
    int tmp = __gcd(p, q);
    p /= tmp; q/= tmp;
  }
  int tmp = __gcd(p * n, q); 
  // 最后要通分
  // 不要写 %d！！
  printf("Case %lld: %lld/%lld\n", cas, p * n / tmp, q/ tmp);
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
