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

const int N = 1E6 + 4;
int n, m;
int rms[N], ndrms[N], st[N], ed[N];
int sum[N];

bool check(int x) {
  memset(sum, 0, sizeof sum);
  rep(i, 1, x) {
    sum[ed[i] + 1] -= ndrms[i];
    sum[st[i]] += ndrms[i];
  }
  rep(i, 1, n) {
    sum[i] += sum[i - 1];
    if (sum[i] > rms[i]) {
      return false;
    }
  }
  return 1;
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  rep(i, 1, n) cin >> rms[i];
  rep(i, 1, m) {
    cin >> ndrms[i] >> st[i] >> ed[i];
  }
  int l = 1, r = m;
  if (check(m)) {
    cout << 0;
    return 0;
  }
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << "-1" << endl << l;
	return 0;
}
