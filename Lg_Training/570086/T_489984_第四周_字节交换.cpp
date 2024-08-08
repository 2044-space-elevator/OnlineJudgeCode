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
#define int unsigned int 
int two_jz_res[36], n, cnt = 0;

void ten_to_two() {
  while (n) {
    two_jz_res[++cnt] = n % 2;
    n /= 2;
  }
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  int swa, swb;
  cin >> swa >> swb;
  ten_to_two();
  
  rep(i, 1, 8) {
    swap(two_jz_res[8 * swa + i], two_jz_res[8 * swb + i]);
  }
  int res = 0;
  int tmp = 1;
  rep(i, 1, cnt) {
    res += tmp * two_jz_res[i];
    tmp *= 2ll;
  }
  cout << res;
	return 0;
}
