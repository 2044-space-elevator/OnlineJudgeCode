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
const int N = 1E6 + 8;
const int MOD = 1E9 + 7;

int A[N], B[N], C[N];

main() {
//	int t; cin >> t; while (t--) solve();
  ll n;
  cin >> n;
  rep(i, 1, n) {
    cin >> A[i];
    B[i] = C[i] = A[i];
  }
  rrep(i, 1, n) {
    A[i] += A[i + 1];
    A[i] %= MOD;
    B[i] = B[i] * A[i + 1] + B[i + 1]; 
    B[i] %= MOD;
    C[i] = C[i] * B[i + 1] + C[i + 1];
    C[i] %= MOD;
  }
  cout << 6 * C[1] % MOD;
	return 0;
}
