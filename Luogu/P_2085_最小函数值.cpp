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

const int N = 1E4 + 5;
int n, m, arr[N], brr[N], crr[N];
int minest = INT_MAX, maxest = 0;
vector<int> tmp;

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  rep(i, 1, n) {
    cin >> arr[i] >> brr[i] >> crr[i];
    int tmp = -brr[i] / (2 * arr[i]);
    minest = min(minest, tmp);
    maxest = max(maxest, tmp);
  }
  rep(i, max(1, minest - m), maxest + 2 * m) {
    int mine = INT_MAX;
    rep(j, 1, n) {
      mine = min(mine, arr[j] * arr[j] * i + brr[j] * i + crr[j]);
    }
    tmp.push_back(mine);
  }
  sort(tmp.begin(), tmp.end());
  repq(i, 0, m) cout << tmp[i] << ' ';

	return 0;
}
