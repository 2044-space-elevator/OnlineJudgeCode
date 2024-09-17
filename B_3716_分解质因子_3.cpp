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



const int N = 1E8 + 5;
bitset<N> vis;
int prime[N / 10], mn[N], T, cnt;
void init() {
  for (int i = 2; i < N; i++) {
    if (!vis[i]) prime[++cnt] = i, mn[i] = i;
    for (int j = 1; j <= cnt && i * prime[j] < N; j++) {
      vis[i * prime[j]] = 1;
      mn[i * prime[j]] = prime[j];
      if (i % prime[j] == 0) break;

    }
  }
}
void solve() {
  int n;
  cin >> n;
  int ans = 0;
  while (n > 1) {
    ans ^= mn[n], n /= mn[n];
  }
  cout << ans << endl;
}


main() {
  init();
	int t; cin >> t; while (t--) solve();
	return 0;
}
