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
#define lowbit(x) (x&(-x))
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
	
}

#define int ull

const int N = 2E5 + 5;
int arr[N], sum[N];

main() {
//	int t; cin >> t; while (t--) solve();
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  rep(i, 1, n) {
    cin >> arr[i];
    sum[i] = sum[i - 1] + lowbit(arr[i]);
  }
  int q;
  cin >> q;
  int i = 1;
  while (q--) {
    int ind; cin >> ind;
    for (; i <= n; i++) {
      if (sum[i] >= ind) {
        cout << arr[i] / (sum[i] - sum[i - 1])<< endl;
        break;
      }
    }
  }
	return 0;
}
