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
#define int ull
const int N = 1e7 + 5;
int arr[N], brr[N]; 
void solve() {
  int n, m;
  cin >> n >> m;
  rep(i, 1, n) cin >> arr[i];
  rep(i, 1, m) {
    cin >> brr[i];
  }
  int ans = 0;
  int j = 0;
  rep(i, 1, n) {
    int tmp = 0;
    while (j + 1 <= m && brr[j + 1] <= arr[i]) {
      j++;
      if (arr[i] == brr[j]) tmp++;
    }
    ans ^= tmp;
  }
  cout << ans << '\n';
}


main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) solve(); 
	return 0;
}
