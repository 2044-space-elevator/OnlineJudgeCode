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
int n, m;
const int N = 1e7 + 5;
int cfst[N], cfd[N], cfdl[N];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  rep(i, 1, m) {
    int l, r, s, e;
    cin >> l >> r >> s >> e;
    int d = (s - e) / (r - l);
    cfst[l] += s, cfst[r + 1] -= s;
    cfd[l] += d, cfd[r + 1] -= d;
    cfdl[l] += d * l, cfdl[r + 1] -= d * l;
  }
  // ai = first + sigma dj(i - lj)
  // ai = first + sigma i dj - sigma lj dj
  // ai = first + i sigma dj - sigma lj dj
  int ans1 = 0, ans2 = 0;
  rep(i,1, n) {
    cfst[i] += cfst[i - 1];
    cfd[i] += cfd[i - 1];
    cfdl[i] += cfdl[i - 1];
    int tmp = cfst[i] + abs(cfd[i] * i - cfdl[i]);
    #ifndef ONLINE_JUDGE
    cout << cfd[i] * i - cfdl[i] << ' ';
    #endif
    ans1 ^= tmp;
    ans2 = max(ans2, tmp);
  }
  #ifndef ONLINE_JUDGE
  cout << endl;
  #endif

  cout << ans1 << ' ' << ans2;
	return 0;
}
