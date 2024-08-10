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

const ll mod = 1e9 + 7;
int C_2(int n) {
  return (n * (n - 1ll) / 2ll ) % mod;  
}

int arr[(int)7e3 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  rep(i ,1, n) {
    int x;
    cin >> x;
    arr[x]++;
  }
  int sum = 0;
  rep(i, 2, 5000) {
    if (arr[i] < 2ll) continue;
    ll tmp = C_2(arr[i]);
    rep(j, 1, i / 2ll) {
      if (arr[j] >= 2 && i == j * 2ll) sum += tmp * C_2(arr[j]) % mod;
      if (arr[i - j] && arr[j] && i != j * 2ll) sum += tmp * arr[j] * arr[i - j] % mod;
      sum %= mod;
    }
  }
  cout << sum % mod;
	return 0;
}
