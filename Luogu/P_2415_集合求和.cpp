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

#define int long long
vct<int> arr;
int ans = 0;

void dfs(int max, int sum) {
  ans += sum;
  if (arr.size() - 1 == max) {
    return;
  }
  repq(i, max + 1, arr.size()) {
    dfs(i, sum + arr[i]);
  }
}

main() {
//	int t; cin >> t; while (t--) solve();
  int x;
  while (cin >> x) arr.push_back(x);
  sort(arr.begin(), arr.end());
  unique(arr.begin(), arr.end());
  for (int v : arr) {
    ans += v * (1 << (arr.size() - 1));
  }
  cout << ans;
	return 0;
}
