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

ll X, Y, arr[(int)2e5 + 5], brr[(int)2e5 + 5];
int n;

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> X >> Y;
    rep(i, 1, n) {
        cin >> arr[i];
    }
    rep(i, 1, n) cin >> brr[i];
    sort(arr + 1, arr + n + 1, greater<int>());
    sort(brr + 1, brr + n + 1, greater<int>());
    ll fstind = n, sum = 0;
    rep(i, 1, n) {
        sum += arr[i];
        if (sum > X) {
            fstind = i;
            break;
        }
    }
    ll scdind = n; sum = 0;
    rep(i, 1, n) {
        sum += brr[i];
        if (sum > Y) {
            scdind = i;
            break;
        }
    }
    cout << min(fstind, scdind);
	return 0;
}
