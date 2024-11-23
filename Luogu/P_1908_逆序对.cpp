#include <bits/stdc++.h>
#define rty printf("Yes\n");
#define RTY printf("YES\n");
#define rtn printf("No\n");
#define RTN printf("NO\n");
#define int ll
#define rep(v,b,e) for(int v=b;v<=e;v++)
#define repq(v,b,e) for(int v=b;v<e;v++)
#define rrep(v,e,b) for(int v=b;v>=e;v--)
#define rrepq(v,e,b) for(int v=b;v>e;v--)
#define stg string
#define vct vector
using namespace std;

typedef long long ll;
typedef unsigned long long ull;


int n, arr[(int)5e5 + 5], tmp[(int)5e5 + 5];
int lowbit (int x) { return x & -x; }
int c[(int)5e5 + 5];
void add(int x, int v) {
  for (int i = x; i <= n; i += lowbit(i)) c[i] += v;
}

int query(int x) {
  int ans = 0;
  for (int i = x; i; i -= lowbit(i)) ans += c[i];
  return ans;
}


void solve() {
	
}


main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  rep(i, 1, n) cin >> arr[i];
  rep(i, 1, n) tmp[i] = arr[i];
  sort(tmp + 1, tmp + n + 1);
  unique(tmp + 1, tmp + n + 1);
  rep(i, 1, n) {
    arr[i] = lower_bound(tmp, tmp + n + 1, arr[i]) - tmp;
  }
  int cnt = *max_element(arr + 1, arr + n + 1);
  int ans = 0;
  rep(i, 1, n) {
    ans += query(cnt) - query(arr[i]);
    add(arr[i], 1);
  } 
  cout << ans;
	return 0;
}
