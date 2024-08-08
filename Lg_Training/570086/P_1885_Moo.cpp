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

int len = 0, k = 2;

main() {
//	int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  while (len < n) {
    len *= 2; len += ++k;
  }
  while (len) {
    len = (len - k) >> 1;
    if (n > len) {
      if (len + k >= n) {
        if (n == len + 1) cout << 'm';
        else cout << 'o';
        return 0;
      }
      else {
        n = n - (len + k);
      }
    } 
    k--;
  }
	return 0;
}
