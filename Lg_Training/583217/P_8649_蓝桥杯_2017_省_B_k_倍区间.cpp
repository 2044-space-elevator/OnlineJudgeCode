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
int arr[(int)1e5 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
  int n, k;
  cin >> n >> k;
  arr[0]++;
  int d = 0;
  rep(i, 1, n) {
    int x;
    cin >> x;
    d += x;
    d %= k;
    arr[d]++;
  }
  int sum = 0;
  repq(i, 0, k) {
    sum += 1ll * arr[i] * (arr[i] - 1) / 2;
  }
  cout << sum;
	return 0;
}
