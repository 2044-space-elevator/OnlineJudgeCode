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

#define int ll
const int N = 4E5 + 5;
int catalan[N];
const int mod = 100;

main() {
//	int t; cin >> t; while (t--) solve()
  int n;
  cin >> n;
  catalan[0] = catalan[1] =  1;
  rep(i, 2, n) {
    rep(j, 1, i) {
      catalan[i] += catalan[j - 1] * catalan[i - j];
      catalan[i] %= mod;
    }
  }
  cout << catalan[n];
	return 0;
}
