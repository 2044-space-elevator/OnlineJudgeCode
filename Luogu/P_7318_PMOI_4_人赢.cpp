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

int arr[9];

main() {
//	int t; cin >> t; while (t--) solve();
    int n, m;
    ll k;
    cin >> n >> m >> k;
    if (k == 1) { cout << n; return 0; } 
    if (k == 2) { cout << m; return 0; }
    arr[1] = n, arr[2] = m;
    rep(i, 3, 8) {
        arr[i] = arr[i - 1] * arr[i - 2] % 10;
    }
    k -= 2;
    k %= 6;
    if (k == 0) k = 6;
    cout << arr[k + 2];
	return 0;
}
