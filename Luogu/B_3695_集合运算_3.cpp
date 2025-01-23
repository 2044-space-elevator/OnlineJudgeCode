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


const int N = 3E4 + 5;
bitset<N> arr[N];


main() {
//	int t; cin >> t; while (t--) solve();
  int n, m, q;
  cin >> n >> m >> q;
  rep(i, 1, n) {
    int k;
    cin >> k;
    while (k--) {
      int tmp;
      cin >> tmp;
      arr[i][tmp - 1] = 1;
    }
  }
  repq(i, 0, m) arr[N - 1][i] = 1;
  while (q--) {
    int op, x, y;
    cin >> op >> x >> y;
    if (op == 1) {
      arr[x] <<= y;
      arr[x] &= arr[N - 1];
    }
    if (op == 2) {
      arr[x] >>= y;
    }
    if (op == 3) {
      cout << (arr[x] & arr[y]).count() << endl;
    }
    if (op == 4) {
      cout << (arr[x] | arr[y]).count() << endl;
    }
    if (op == 5) {
      cout << (arr[x] ^ arr[y]).count() << endl;
    }
  }
	return 0;
}
