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

int n;
map<int, vct<int>> mp;
bool flg = 0;
void solve() {
  cin >> n;
  mp.clear();
  rep(i, 1, n) {
    int x;
    cin >> x;
    mp[x].push_back(i);
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    vector<int>::iterator left = lower_bound(mp[x].begin(), mp[x].end(), l);
    vector<int>::iterator right = (upper_bound(mp[x].begin(), mp[x].end(), r) - 1);
    cout << right - left + 1 << endl; 
  }
}


main() {
	int t; cin >> t; while (t--) solve();
  if (flg == 1) return 1;
	return 0;
}
