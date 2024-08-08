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

map<int, bool> mp1, mp2;
int S[(int)1e5 + 5], T[(int)1e5 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
  int n, m;
  cin >> n >> m;
  rep(i, 1, n) {
    cin >> S[i];
    mp1[S[i]] = true;
  }
  rep(i, 1, m) {
    cin >> T[i];
    mp2[T[i]] = true;
  }
  int ans1 = 0, ans2 = 0, ans3 = 0;
  rep(i, 1, 1e5) {
    ans1 += mp1[i] && mp2[i];
    ans2 += mp1[i] || mp2[i];
    ans3 += mp1[i] && !mp2[i];
  }
  cout << ans1 << " " << ans2 << " " << ans3;
}
