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

int n, m;


main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  int sum = 0, cnt = 0;
  rep(i, 1, n) {
    int x;
    cin >> x;
    if (cnt + x > m) {
      sum++;
      cnt = 0;
    }  
    cnt += x;
  }
  cout << sum + 1;
	return 0;
}
